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
  Ast * statement, * arguments, * parameters;
} MacroReplacement;

static Ast * argument_value (Ast * identifier, Stack * stack, MacroReplacement * r)
{
  Ast * decl = ast_identifier_declaration_from_to (stack, ast_terminal (identifier)->start,
						   r->statement, NULL);
  if (decl && ast_parent (decl, sym_parameter_type_list) == r->parameters) {
    Ast * parent = ast_parent (decl, sym_parameter_declaration);
    Ast * parameters = r->parameters->child[0], * value = NULL;
    while (parameters && parameters->child[0]->sym == parameters->sym)
      parameters = parameters->child[0];
    foreach_item_r (r->arguments, sym_argument_expression_list_item, argument) {
      Ast * parameter = ast_child (parameters, sym_parameter_declaration);
      parameters = parameters->parent;
      assert (parameter);
      if (parameter == parent) {
	value = argument;
	break;
      }
    }
    if (!value) {
      AstTerminal * t = ast_left_terminal (r->arguments);
      fprintf (stderr, "%s:%d: error: missing '%s' macro parameter\n",
	       t->file, t->line, ast_terminal (identifier)->start);
      exit (1);
    }
    assert (value->child[0]->sym == sym_assignment_expression); // cannot deal with the postfix_initializer Basilisk C extension
    return value;
  }
  return NULL;
}
			     
static void replace_arguments (Ast * n, Stack * stack, void * data)
{
  MacroReplacement * r = data;
  Ast * identifier;  
  if ((identifier = ast_schema (n, sym_postfix_expression,
				0, sym_primary_expression,
				0, sym_IDENTIFIER))) {
    Ast * value = argument_value (identifier, stack, r);
    if (value) {
      Ast * primary = NN(n, sym_primary_expression,
			 NCA(n, "("),
			 NN(n, sym_expression_error,
			    NN(n, sym_expression,
			       ast_copy (value->child[0]))),
			 NCA(n, ")"));
      ast_set_line (primary, ast_terminal (identifier), true);
      ast_replace_child (n, 0, primary);
    }
  }
  else if ((identifier = ast_schema (n, sym_direct_declarator,
				     0, sym_generic_identifier,
				     0, sym_IDENTIFIER))) {      
    Ast * value = argument_value (identifier, stack, r);
    if (value) {
      Ast * replacement = ast_is_identifier_expression (ast_schema (value, sym_argument_expression_list_item,
								    0, sym_assignment_expression));
      if (!replacement) {
	AstTerminal * t = ast_left_terminal (value);
	fprintf (stderr, "%s:%d: error: macro argument '%s' must be a simple identifier\n",
		 t->file, t->line, ast_terminal (identifier)->start);
	t = ast_terminal (identifier);
	fprintf (stderr, "%s:%d: error: because it is used here as a declarator\n",
		 t->file, t->line);
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

bool ast_is_macro_definition (const Ast * function_definition, const char * macro_type)
{
  Ast * type = ast_schema (function_definition, sym_function_definition,
			   0, sym_function_declaration,
			   0, sym_declaration_specifiers,
			   0, sym_type_specifier,
			   0, sym_types,
			   0, sym_TYPEDEF_NAME);
  return (type && !strcmp (ast_terminal (type)->start, macro_type));
}

static void replace_break (Ast * n, Ast * breaking, Ast * parent)
{
  if (ast_schema (n, sym_statement,
		  0, sym_jump_statement,
		  0, sym_BREAK)) {
    Ast * loop = n->parent;
    while (loop != parent &&
	   loop->sym != sym_foreach_inner_statement && // fixme: obsolete
	   loop->sym != sym_foreach_statement &&
	   loop->sym != sym_forin_declaration_statement &&
	   loop->sym != sym_forin_statement &&
	   loop->sym != sym_iteration_statement &&
	   (loop->sym != sym_selection_statement ||
	    loop->child[0]->sym != sym_SWITCH))
      loop = loop->parent;
    if (loop == parent) {
      n->child[0]->sym = sym_expression_statement;
      ast_replace_child (n->child[0], 0,
			 NN(n, sym_expression,
			    ast_copy (breaking)));
    }
  }
  else if (n->child)
    for (Ast ** c = n->child; *c; c++)
      replace_break (*c, breaking, parent);
}

static void macro_replacement (Ast * statement, Stack * stack, const char * macro_type)
{
  Ast * macro_call = ast_schema (statement, sym_statement,
				 0, sym_basilisk_statements,
				 0, sym_macro_statement,
				 0, sym_macro_call);
  if (!macro_call)
    return;
  Ast * identifier = ast_schema (macro_call, sym_macro_call,
				 0, sym_MACRO);
  Ast * macro_definition = ast_schema (ast_ancestor (ast_identifier_declaration (stack, ast_terminal (identifier)->start), 6),
				       sym_function_definition);
  if (!ast_is_macro_definition (macro_definition, macro_type))
    return;
  
  optional_arguments (macro_call, stack);

  MacroReplacement r = {
    ast_child (macro_call->parent, sym_statement),
    ast_schema (macro_call, sym_macro_call,
		2, sym_argument_expression_list),
    ast_schema (macro_definition, sym_function_definition,
		0, sym_function_declaration,
		1, sym_declarator,
		0, sym_direct_declarator,
		2, sym_parameter_type_list)
  };
  
  /**
  Replace 'break' with its macro definition (if it exists). */

  if (r.parameters) {
    Ast * breaking = NULL;
    foreach_item (r.parameters, 2, parameter)
      if ((breaking = ast_schema (parameter, sym_parameter_list,
				  0, sym_parameter_declaration,
				  2, sym_initializer,
				  0, sym_assignment_expression)))
	break;
    if (breaking)
      replace_break (r.statement, breaking, r.statement);
  }

  Ast * copy = ast_copy (ast_find (macro_definition, sym_compound_statement));
  stack_push (stack, &copy);
  ast_push_function_definition (stack, ast_find (macro_definition, sym_direct_declarator));
  stack_push (stack, &r.statement);
  if (r.parameters)
    ast_traverse (copy, stack, replace_arguments, &r);
  ast_traverse (copy, stack, replace_ellipsis, &r);
  ast_pop_scope (stack, copy);
  ast_set_child (statement, 0, copy);
  
  ast_destroy (macro_call);
}
