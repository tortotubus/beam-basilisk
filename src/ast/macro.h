/**
# Macros

This implements the macro replacement of the form

~~~c
macro func (double a) {
  do_something (a);
  {...}
  do_something_else();
}
...
  func (pi)
    do_yet_another_thing();
~~~

into

~~~c
macro func (double a) {
  do_something (a);

  do_something_else();
}
...
  {
    do_something (pi);
    do_yet_another_thing();
    do_something_else();
  }
~~~
*/

typedef struct {
  Ast * statement, * arguments, * parameters, * call;
  bool in_a_macro_definition, nolineno;
} MacroReplacement;

static Ast * argument_value (Ast * identifier, Stack * stack, const MacroReplacement * r)
{

  /**
  The parameters are just a list of identifiers. */
  
  if (r->parameters->sym == sym_identifier_list) {
    Ast * parameters = r->parameters;
    while (parameters && parameters->child[0]->sym == parameters->sym)
      parameters = parameters->child[0];
    Ast * arguments = r->arguments;
    foreach_item_r (arguments, sym_argument_expression_list_item, argument) {
      Ast * parameter = ast_child (parameters, sym_IDENTIFIER);
      parameters = parameters->parent;
      assert (parameter);
      if (!strcmp (ast_terminal (parameter)->start, ast_terminal (identifier)->start))
	return argument;
    }
    return NULL;
  }

  /**
  The parameters are a list of declarations. */
  
  Ast * decl = ast_identifier_declaration_from_to (stack, ast_terminal (identifier)->start,
						   r->statement, NULL);
  if (decl && ast_parent (decl, sym_parameter_type_list) == r->parameters) {
    Ast * value = NULL;
    if (r->arguments) {
      Ast * parent = ast_parent (decl, sym_parameter_declaration);
      Ast * parameters = r->parameters->child[0];
      while (parameters && parameters->child[0]->sym == parameters->sym)
      parameters = parameters->child[0];
      Ast * arguments = r->arguments;
      foreach_item_r (arguments, sym_argument_expression_list_item, argument) {
	Ast * parameter = ast_child (parameters, sym_parameter_declaration);
	parameters = parameters->parent;
	assert (parameter);
	if (parameter == parent) {

	  /**
	  Structure members can only be substituted with 'void' parameters. */

	  if (ast_ancestor (identifier, 2)->sym == sym_member_identifier &&
	      !ast_schema (parameter, sym_parameter_declaration,
			   0, sym_declaration_specifiers,
			   0, sym_type_specifier,
			   0, sym_types,
			   0, sym_VOID))
	    return NULL;

	  value = argument;
	  break;
	}
      }
    }
    if (!value) {
      AstTerminal * t = ast_left_terminal (r->call);
      fprintf (stderr, "%s:%d: error: missing '%s' macro parameter\n",
	       t->file, t->line, ast_terminal (identifier)->start);
      exit (1);
    }
    return value;
  }
  return NULL;
}
			     
static void replace_arguments (Ast * n, Stack * stack, void * data)
{
  const MacroReplacement * r = data;
  Ast * identifier;
  if ((identifier = ast_schema (n, sym_postfix_expression,
				0, sym_primary_expression,
				0, sym_IDENTIFIER))) {
    Ast * value = argument_value (identifier, stack, r);
    if (value) {
      if (value->child[0]->sym == sym_assignment_expression) {
	Ast * primary = ast_is_simple_expression (value->child[0]);
	if (primary) {
	  primary = ast_copy (primary->parent);
	  ast_set_line (primary, ast_terminal (identifier), true);
	  Ast * identifier = ast_schema (primary, sym_primary_expression,
					 0, sym_IDENTIFIER);
	  if (identifier && !strcmp (ast_terminal (identifier)->start, "None"))
	    ast_terminal (identifier)->start[0] = '\0';
	}
	else
	  primary = NN(n, sym_primary_expression,
		       NCA(n, "("),
		       NN(n, sym_expression_error,
			  NN(n, sym_expression,
			     ast_copy (value->child[0]))),
		       NCA(n, ")"));
	ast_replace_child (n, 0, primary);
      }
      else { // postfix_initializer
	assert (value->child[0]->sym == sym_postfix_initializer);
	Ast * parent = ast_ancestor (n, 3);
	assert (ast_schema (parent, sym_cast_expression,
			    1, sym_type_name));
	parent->sym = sym_postfix_expression;
	ast_replace_child (parent, 3, value->child[0]);
	int index = ast_child_index (parent);
	Ast * grandparent = parent->parent;
	ast_set_child (grandparent, index,
		       NN(grandparent, sym_cast_expression,
			  NN(grandparent, sym_unary_expression,
			     parent)));
      }
    }
    else if (!r->in_a_macro_definition) {
      if (!strcmp (ast_terminal (identifier)->start, "S__FILE__")) {
	char * filename = NULL;
	str_append (filename, "\"", ast_left_terminal (r->call)->file, "\"");
	ast_replace_child (identifier->parent, 0, NN(n, sym_string,
						     NB(n, sym_STRING_LITERAL, filename)));
	free (filename);
      }
      else if (!strcmp (ast_terminal (identifier)->start, "S_LINENO")) {
	int line = r->nolineno ? 0 : ast_left_terminal (r->call)->line;
	char sline[20];
	snprintf (sline, 19, "%d", line);
	ast_replace_child (identifier->parent, 0, NN(n, sym_constant,
						     NB(n, sym_I_CONSTANT, sline)));
      }
    }
  }
  else if ((identifier = ast_schema (n, sym_direct_declarator,
				     0, sym_generic_identifier,
				     0, sym_IDENTIFIER)) ||
	   (identifier = ast_schema (n, sym_member_identifier,
				     0, sym_generic_identifier,
				     0, sym_IDENTIFIER))) {
    Ast * value = argument_value (identifier, stack, r);
    if (value) {
      assert (value->child[0]->sym == sym_assignment_expression); // does not know yet how to deal with postfix_initializer
      Ast * replacement = ast_is_identifier_expression (ast_schema (value, sym_argument_expression_list_item,
								    0, sym_assignment_expression));
      if (!replacement) {
	AstTerminal * t = ast_left_terminal (value);
	fprintf (stderr, "%s:%d: error: macro argument '%s' must be a simple identifier\n",
		 t->file, t->line, ast_terminal (identifier)->start);
	t = ast_terminal (identifier);
	fprintf (stderr, "%s:%d: error: because it is used here as a %s\n",
		 t->file, t->line, n->sym == sym_direct_declarator ? "declarator" : "structure member");
	exit (1);
      }
      free (ast_terminal (identifier)->start);
      ast_terminal (identifier)->start = strdup (ast_terminal (replacement)->start);
    }
  }
}

static void replace_ellipsis (Ast * n, Stack * stack, void * data)
{
  if (ast_schema (ast_child (n, sym_statement), sym_statement,
		  0, sym_basilisk_statements,
		  0, sym_ELLIPSIS_MACRO)) {
    Ast * child = ast_child (n, sym_statement);
    MacroReplacement * r = data;
    ast_set_child (n, ast_child_index (child), ast_copy (r->statement));
    ast_destroy (child);
  }
}

Ast * ast_is_macro_declaration (const Ast * function_declaration, const char * macro_type)
{
  Ast * type = ast_find (ast_schema (function_declaration, sym_function_declaration,
				     0, sym_declaration_specifiers),
			 sym_declaration_specifiers,
			 0, sym_type_specifier,
			 0, sym_types,
			 0, sym_TYPEDEF_NAME);
  return (type && !strcmp (ast_terminal (type)->start, macro_type)) ?
    ast_schema (function_declaration, sym_function_declaration,
		1, sym_declarator,
		0, sym_direct_declarator,
		0, sym_direct_declarator,
		0, sym_generic_identifier,
		0, sym_IDENTIFIER) : NULL;
}

static void replace_break (Ast * n, Ast * breaking, Ast * parent)
{
  if (ast_schema (n, sym_statement,
		  0, sym_jump_statement,
		  0, sym_BREAK)) {
    Ast * loop = n->parent;
    while (loop != parent &&
	   loop->sym != sym_forin_declaration_statement &&
	   loop->sym != sym_forin_statement &&
	   loop->sym != sym_iteration_statement &&
	   (loop->sym != sym_selection_statement ||
	    loop->child[0]->sym != sym_SWITCH) &&
	   !ast_is_foreach_statement (loop))
      loop = loop->parent;
    if (loop == parent) {
      if (breaking) {
	if (breaking->sym == sym_BREAK)
	  ; // do nothing
	else {
	  assert (breaking->sym == sym_assignment_expression);
	  n->child[0]->sym = sym_expression_statement;
	  ast_replace_child (n->child[0], 0,
			     NN(n, sym_expression,
				ast_copy (breaking)));
	}
      }
      else {
	Ast * breaking = ast_schema (n, sym_statement,
				     0, sym_jump_statement,
				     0, sym_BREAK);
	Ast * identifier = ast_schema (ast_parent (breaking, sym_macro_statement), sym_macro_statement,
				       0, sym_MACRO);
	fprintf (stderr, "%s:%d: error: cannot break out of macro '%s'\n",
		 ast_terminal (breaking)->file, ast_terminal (breaking)->line,
		 ast_terminal (identifier)->start);
	exit (1);
      }
    }
  }
  else if (n->child)
    for (Ast ** c = n->child; *c; c++)
      replace_break (*c, breaking, parent);
}

static void macro_replacement (Ast * statement, Stack * stack, const char * exclude[], bool nolineno)
{
  Ast * macro_statement = ast_schema (statement, sym_statement,
				      0, sym_basilisk_statements,
				      0, sym_macro_statement);
  if (!macro_statement)
    return;
  Ast * identifier = ast_schema (macro_statement, sym_macro_statement,
				 0, sym_MACRO);
  if (!strcmp (ast_terminal (identifier)->start, "foreach_block") &&
      (inforeach (statement) || point_declaration (stack)))
    str_append (ast_terminal (identifier)->start, "_inner");
  Ast * macro_definition =
    ast_schema (ast_ancestor (ast_identifier_declaration (stack, ast_terminal (identifier)->start), 6),
		sym_function_definition);

  if (!macro_definition) {
    fprintf (stderr, "%s:%d: error: undefined macro '%s'\n",
	     ast_terminal (identifier)->file, ast_terminal (identifier)->line, ast_terminal (identifier)->start);
    exit (1);
  }
  
  // fixme: should just be based on the names for "diagonalize" and "einstein_sum"
  if (!ast_is_macro_declaration (macro_definition->child[0], "macro"))
    return;

  if (exclude)
    for (const char ** s = exclude; *s; s++)
      if (((*s)[strlen(*s) - 1] == '*' &&
	   !strncmp(ast_terminal (identifier)->start, *s, strlen(*s) - 1)) ||
	  !strcmp (ast_terminal (identifier)->start, *s))
	return;
  
  optional_arguments (macro_statement, stack);

  MacroReplacement r = {
    .statement = ast_child (macro_statement, sym_statement),
    .arguments = ast_schema (macro_statement, sym_macro_statement,
			     2, sym_argument_expression_list),
    .parameters = ast_schema (macro_definition, sym_function_definition,
			      0, sym_function_declaration,
			      1, sym_declarator,
			      0, sym_direct_declarator,
			      2, sym_parameter_type_list),
    .call = macro_statement,
    .nolineno = nolineno
  };

  Ast * definition = ast_parent (statement, sym_function_definition);
  if (definition && ast_is_macro_declaration (definition->child[0], "macro"))
    r.in_a_macro_definition = true;

  if (!r.parameters)
    r.parameters = ast_schema (macro_definition, sym_function_definition,
			       0, sym_function_declaration,
			       1, sym_declarator,
			       0, sym_direct_declarator,
			       2, sym_identifier_list);

  int na = 0;
  if (r.arguments)
    foreach_item (r.arguments, 2, argument) na++;
  int np = 0;
  if (r.parameters) {
    Ast * list = r.parameters->sym == sym_identifier_list ? r.parameters : r.parameters->child[0];
    foreach_item (list, 2, parameter)
      if (!ast_schema (parameter, sym_parameter_declaration,
		       0, sym_BREAK))
	np++;
  }

  if (na != np) {
    AstTerminal * t = ast_left_terminal (macro_statement);
    fprintf (stderr, "%s:%d: error: too %s arguments for macro '%s'\n",
	     t->file, t->line, na > np ? "many" : "few", ast_terminal (identifier)->start);
    t = ast_left_terminal (macro_definition);
    fprintf (stderr, "%s:%d: error: macro '%s' is defined here\n", t->file, t->line, ast_terminal (identifier)->start);
#if 0
    ast_print_tree (macro_definition->child[0], stderr, 0, 0, -1);
    ast_print (r.call, stderr, 0);
#endif
    exit (1);
  }
  
#if 0
  fprintf (stderr, "***** replacing macro: \n");
  ast_print (macro_statement, stderr, 0);
  fprintf (stderr, "\n===== with: \n");
  ast_print (ast_child (macro_definition, sym_function_declaration), stderr, 0);
  ast_print (ast_child (macro_definition, sym_compound_statement), stderr, 0);
  fputc ('\n', stderr);
#endif
  
  /**
  Replace 'break' with its macro definition (if it exists). */

  Ast * breaking = NULL;
  if (r.parameters &&
      !(breaking = ast_find (r.parameters, sym_parameter_declaration,
			     2, sym_initializer,
			     0, sym_assignment_expression)))
    breaking = ast_find (r.parameters, sym_parameter_declaration,
			 2, sym_BREAK);
  replace_break (r.statement, breaking, r.statement);
  
  Ast * copy = ast_copy (ast_find (macro_definition, sym_compound_statement));
  stack_push (stack, &copy);
  ast_push_function_definition (stack, ast_find (macro_definition, sym_direct_declarator));
  stack_push (stack, &r.statement);
  if (r.parameters)
    ast_traverse (copy, stack, replace_arguments, &r);
  ast_traverse (copy, stack, replace_ellipsis, &r);
  ast_pop_scope (stack, copy);
  str_prepend (ast_left_terminal (copy)->before, ast_left_terminal (macro_statement)->before);
  ast_set_child (statement, 0, copy);  
  ast_destroy (macro_statement);
}
