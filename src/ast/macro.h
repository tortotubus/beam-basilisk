/**
# Macros

The [C preprocessor](https://gcc.gnu.org/onlinedocs/cpp/Macros.html)
macros are familiar to C programmers (and are briefly introduced in
the [Tutorial](/Tutorial#using-macros)). While they are very useful,
their shortcomings are also well-known, for example:

* multiline macros are hard to write, read and debug,
* macros only deal with text i.e. they do not enforce the C syntax/grammar 
  (which also makes them hard to write and debug),
* while macros can be used to implement simple iterators, the syntax is cumbersome.

As an illustration, consider the following simple iteration macro

~~~c
#define iterator(start, end, index, expr) do {    \
  for (int index = start; index <= end; index++)  \
    expr                                          \
} while(0)

int main() {
  iterator (0, 10, i, { printf ("%d\n", i); });
}
~~~

Using Basilisk macros, this would be written

~~~literatec
macro iterator (int start, int end, int index) {
  for (int index = start; index <= end; index++)
    {...}
}

int main() {
  iterator (0, 10, i)
    printf ("%d\n", i);
}
~~~

The syntax/grammar of the macro definition is now almost identical to
the definition of a standard C function and is checked as such by the
compiler. Using the macro also respects the C grammar (i.e. that of
standard C iterators: `for`, `while` etc.).

Two new reserved keywords have been introduced: 

* `macro` which indicates that what follows is a macro definition, and 
* `{...}` which is expanded to the statement used when the macro is
  called (i.e. to `printf ("%d\n", i);` in this example).

## Macro expansion

The expansion of the arguments passed to Basilisk macros is what
makes them different from functions. To illustrate this, consider the
following example

~~~literatec
macro initialize (scalar s, double expr)
{
  foreach()
    s[] = expr;
}

int main() {
  init_grid (16);
  scalar a[];
  initialize (a, sqrt (x*x + y*y));
}
~~~

It is clear that if `initialize` was a function (i.e. `macro
initialize...` would just be replaced by `void initialize...`), this
would not compile, because `x` and `y` are not defined when
`initialize` is called in `main`. This works because Basilisk macros
are expanded before compilation (like their C counterpart). After
macro expansion the code would read

~~~literatec
...
int main() {
  init_grid (16);
  scalar a[];
  {
    foreach()
      a[] = sqrt (x*x + y*y);
  }
}
~~~

## Macros returning a value

* return type (non)-casting

## Optional arguments

Since macros share their syntax with that of functions, they can also
define [optional arguments](/Basilisk
C#namedoptional-arguments-in-function-calls). The default value `None`
is specific to macros and will be expanded to nothing.

## Breaking out of macro iterators

By default trying to `break` out of a macro iterator (like the
`iterator` example above) will cause an error. Breaking must
explicitly be set when defining the macro, for example

~~~literatec
macro iterator (int start, int end, int index, break = break) {
  ...
}
~~~

where breaking uses the standard `break` statement, or

~~~literatec
macro iterator (int start, int end, int index, break = (index = end + 1)) {
  ...
}
~~~

where the given expression will be expanded in replacement of the
`break` statement.

## Postmacros

Macros defined using the `postmacro` reserved keyword will be expanded
after preprocessing by [qcc](/src/qcc.c). They will thus not be seen
by the [interpreter](interpreter/interpreter.c) or by [computation
kernels](kernels.c). 

*This is a low-level functionality which should not be used for "user"
macros.*

## See also

* [Macro tests](/src/test/macro.c)

# Implementation */

typedef struct {
  Ast * statement, * arguments, * parameters, * call;
  bool in_a_macro_definition, nolineno;
  int * complex_call;
} MacroReplacement;

static Ast * argument_value (Ast * identifier, Stack * stack, const MacroReplacement * r)
{
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
	  For complex return macros, only substitute parameters marked 'auto'. */

	  if (r->complex_call && !ast_schema (parameter, sym_parameter_declaration,
					      0, sym_declaration_specifiers,
					      0, sym_storage_class_specifier,
					      0, sym_AUTO))
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

Ast * ast_is_macro_declaration (const Ast * function_declaration)
{
  return ast_find (ast_schema (function_declaration, sym_function_declaration,
			       0, sym_declaration_specifiers),
		   sym_declaration_specifiers,
		   0, sym_storage_class_specifier,
		   0, sym_MACRODEF) ?
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

static void macro_replacement (Ast * statement, Stack * stack, bool nolineno, bool postmacros,
			       int * return_macro_index)
{
  Ast * identifier, * macro_statement = ast_schema (statement, sym_statement,
						    0, sym_basilisk_statements,
						    0, sym_macro_statement);
  if (macro_statement)
    identifier = ast_child (macro_statement, sym_MACRO);
  else if ((identifier = ast_schema (statement, sym_function_call,
				     0, sym_postfix_expression,
				     0, sym_primary_expression,
				     0, sym_MACRO)))
    macro_statement = statement;
  if (!macro_statement)
    return;

  if (!strcmp (ast_terminal (identifier)->start, "OMP_PARALLEL"))
    return;
  
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

  if (!postmacros) {
    Ast * macrodef = ast_find (ast_schema (macro_definition, sym_function_definition,
					   0, sym_function_declaration),
			       sym_declaration_specifiers,
			       0, sym_storage_class_specifier,
			       0, sym_MACRODEF);
    assert (macrodef);
    if (!strcmp (ast_terminal (macrodef)->start, "postmacro"))
      return;
  }
  
  optional_arguments (macro_statement, stack);

  MacroReplacement r = {
    .statement = ast_child (macro_statement, sym_statement),
    .arguments = ast_child (macro_statement, sym_argument_expression_list),
    .parameters = ast_schema (macro_definition, sym_function_definition,
			      0, sym_function_declaration,
			      1, sym_declarator,
			      0, sym_direct_declarator,
			      2, sym_parameter_type_list),
    .call = macro_statement,
    .nolineno = nolineno,
    .complex_call = (statement->sym == sym_function_call &&
		     !ast_schema (ast_find (macro_definition, sym_compound_statement),
				  sym_compound_statement,
				  1, sym_block_item_list,
				  0, sym_block_item,
				  0, sym_statement,
				  0, sym_jump_statement,
				  0, sym_RETURN)) ? return_macro_index : NULL
  };

  Ast * definition = ast_parent (statement, sym_function_definition);
  if (definition && ast_is_macro_declaration (definition->child[0]))
    r.in_a_macro_definition = true;

  int na = 0;
  if (r.arguments)
    foreach_item (r.arguments, 2, argument) na++;
  int np = 0;
  if (r.parameters) {
    Ast * list = r.parameters->child[0];
    foreach_item (list, 2, parameter)
      if (!ast_schema (parameter, sym_parameter_declaration,
		       0, sym_BREAK))
	np++;
  }

  if (na != np) {
    AstTerminal * t = ast_terminal (identifier);
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

  if (r.statement) {
    Ast * breaking = NULL;
    if (r.parameters && !(breaking = ast_find (r.parameters, sym_parameter_declaration,
					       2, sym_initializer,
					       0, sym_assignment_expression)))
      breaking = ast_find (r.parameters, sym_parameter_declaration,
			   2, sym_BREAK);
    Ast * copy = breaking;
    if (breaking) {
      if (r.parameters) {
	copy = ast_copy (breaking);
	stack_push (stack, &copy);
	ast_push_function_definition (stack, ast_find (macro_definition, sym_direct_declarator));
	if (r.statement)
	  stack_push (stack, &r.statement);
	ast_traverse (copy, stack, replace_arguments, &r);
	ast_pop_scope (stack, copy);
      }
    }
    replace_break (r.statement, copy, r.statement);
    if (copy != breaking)
      ast_destroy (copy);
  }

  Ast * defcopy = ast_copy (macro_definition);
  Ast * copy = ast_find (defcopy, sym_compound_statement);
  stack_push (stack, &copy);
  ast_push_function_definition (stack, ast_find (macro_definition, sym_direct_declarator));
  if (r.statement)
    stack_push (stack, &r.statement);
  if (r.parameters)
    ast_traverse (copy, stack, replace_arguments, &r);
  if (r.statement)
    ast_traverse (copy, stack, replace_ellipsis, &r);
  ast_pop_scope (stack, copy);
  str_prepend (ast_left_terminal (copy)->before, ast_left_terminal (macro_statement)->before);

  /**
  Statement */
  
  if (statement->sym == sym_statement) {
    ast_set_child (statement, 0, copy);
    ast_destroy (macro_statement);
  }
  
  /**
  Function call */
  
  else {
    assert (statement->sym == sym_function_call);
    Ast * jump = ast_schema (copy, sym_compound_statement,
			     1, sym_block_item_list,
			     0, sym_block_item,
			     0, sym_statement,
			     0, sym_jump_statement);
    if (ast_schema (jump, sym_jump_statement,
		    0, sym_RETURN)) {
      assert (!r.complex_call);

      Ast * autoparam = ast_find (r.parameters, sym_AUTO);
      if (autoparam)
	fprintf (stderr, "%s:%d: warning: 'auto' declaration is useless for simple return macros\n",
		 ast_terminal (autoparam)->file, ast_terminal (autoparam)->line);
      
      /**
      This a simple return macro i.e. 'macro int func(...){ return ...; }'. */
      Ast * expr = ast_schema (jump, sym_jump_statement,
			       1, sym_expression);
      if (!expr) {
	AstTerminal * t = ast_terminal (identifier);
	fprintf (stderr, "%s:%d: error: using value of macro '%s' returning void\n",
		 t->file, t->line, ast_terminal (identifier)->start);
	t = ast_terminal (ast_schema (jump, sym_jump_statement,
				      0, sym_RETURN));
	fprintf (stderr, "%s:%d: error: return value is defined here\n", t->file, t->line);
	exit (1);
      }
      AstTerminal * o = NCB(statement, "("), * c = NCB(statement, ")");
      statement->sym = sym_primary_expression;
      for (Ast ** c = statement->child; *c; c++)
	ast_destroy (*c);
      ast_set_line (expr, o, true);
      ast_new_children (statement, o,
			NN(expr, sym_expression_error,
			   expr), c);
      ast_destroy (copy);
    }
    else {
      assert (r.complex_call);
      
      /**
      This is a "complex" return macro. We first remove the 'auto'
      parameters from the macro definition and the corresponding
      arguments in the function call. */
      
      if (r.arguments) {
	Ast * parameters = ast_schema (defcopy, sym_function_definition,
				       0, sym_function_declaration,
				       1, sym_declarator,
				       0, sym_direct_declarator,
				       2, sym_parameter_type_list,
				       0, sym_parameter_list);
	Ast * arguments = r.arguments, * aparent = arguments->parent;
	Ast * _list1 = parameters, * parameter = _list1->child[1] ? _list1->child[2] : _list1->child[0];
	foreach_item (arguments, 2, argument) {
	  if (ast_schema (parameter, sym_parameter_declaration,
			  0, sym_declaration_specifiers,
			  0, sym_storage_class_specifier,
			  0, sym_AUTO)) {
	    arguments = ast_list_remove (arguments, argument);
	    parameters = ast_list_remove (parameters, parameter);
	    if (arguments == NULL) {
	      assert (parameters == NULL);
	      ast_destroy (aparent->child[2]);
	      for (Ast ** c = aparent->child + 2; *c; c++)
		*c = *(c + 1);
	      aparent = ast_schema (defcopy, sym_function_definition,
				    0, sym_function_declaration,
				    1, sym_declarator,
				    0, sym_direct_declarator);
	      ast_destroy (aparent->child[2]);
	      for (Ast ** c = aparent->child + 2; *c; c++)
		*c = *(c + 1);
	      break;
	    }
	  }
	  if (!((_list1 = _list1 && _list1 != ast_placeholder &&
		 _list1->child[1] ? _list1->child[0] : NULL), parameter))
	    break;
	  parameter = _list1 && _list1 != ast_placeholder ?
	    (_list1->child[1] ? _list1->child[2] : _list1->child[0]) : NULL;
	}
      }

      /**
      We then turn the macro into a (unique) function. */

      Ast * macrodef = ast_schema (statement, sym_function_call,
				   0, sym_postfix_expression,
				   0, sym_primary_expression,
				   0, sym_MACRO);
      macrodef->sym = sym_IDENTIFIER;
      char s[20]; snprintf (s, 19, "_%d", (*r.complex_call)++);
      str_append (ast_terminal (macrodef)->start, s);
      macrodef = ast_find (defcopy->child[0], sym_IDENTIFIER);
      str_append (ast_terminal (macrodef)->start, s);
      macrodef = ast_find (defcopy->child[0], sym_MACRODEF);
      macrodef->sym = sym_STATIC;
      free (ast_terminal (macrodef)->start);
      ast_terminal (macrodef)->start = strdup ("static");

      /**
      We append the new function after the existing one. */

      ast_block_list_append (ast_parent (macro_definition, sym_translation_unit),
			     sym_external_declaration, defcopy);
      defcopy = NULL;
    }
  }

  ast_destroy (defcopy);
}
