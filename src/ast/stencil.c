/**
# Automatic boundary conditions */

#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "symbols.h"

#if 1 // for debugging
# define CHECK(x) ast_check_grammar(x, true)
#else
# define CHECK(x) (x)
#endif

bool ast_is_stencil_function (Ast * n)
{
  Ast * identifier = ast_function_identifier (n);
  if (!identifier)
    return false;
  int len = strlen (ast_terminal (identifier)->start) - 9;
  return len > 0 && !strncmp (ast_terminal (identifier)->start, "_stencil_", 9);
}

static Ast * point_function_call (Ast * n)
{  
  Ast * list = ast_child (n, sym_argument_expression_list);
  if (!list)
    return NULL;
  foreach_item (list, 2, item) {
    Ast * identifier = ast_is_identifier_expression (item->child[0]);
    if (identifier && !strcmp (ast_terminal(identifier)->start, "point"))
      return item;
  }
  return NULL;
}

static Ast * function_call_identifier (Ast * n)
{
  return ast_schema (n, sym_function_call,
		     0, sym_postfix_expression,
		     0, sym_primary_expression,
		     0, sym_IDENTIFIER);
}

/**
Return a previously defined stencil function matching
*function_definition* or NULL if none can be found. */

static Ast * get_stencil_function (Ast * function_definition)
{
  Ast * identifier = ast_function_identifier (function_definition);
  if (!identifier)
    return NULL;
  char * stencil_name = NULL;
  str_append (stencil_name, "_stencil_", ast_terminal (identifier)->start);
  Ast * stencil;
  if (((stencil = ast_schema (ast_ancestor (function_definition, 3),
			      sym_translation_unit,
			      1, sym_external_declaration,
			      0, sym_function_definition)) ||
       ((stencil = ast_schema (ast_ancestor (function_definition, 4),
			       sym_translation_unit,
			       1, sym_external_declaration,
			       0, sym_external_foreach_dimension)) &&
	(stencil = ast_child (stencil, sym_function_definition)))) &&
      (identifier = ast_function_identifier (stencil)) &&
      !strcmp (ast_terminal (identifier)->start, stencil_name)) {
    free (stencil_name);
    return stencil;
  }
  free (stencil_name);
  return NULL;
}

static Ast * get_function_definition (Stack * stack, Ast * identifier,
				      Ast * declaration)
{
  declaration =
    ast_identifier_declaration_from (stack, ast_terminal (identifier)->start,
				     declaration);
  Ast * function_definition = declaration;
  while (function_definition &&
	 function_definition->sym != sym_declaration &&
	 function_definition->sym != sym_function_definition)
    function_definition = function_definition->parent;
  if (!function_definition)
    return NULL;
  if (function_definition->sym == sym_function_definition)
    return function_definition;
  if (!ast_schema (function_definition, sym_declaration,
		   1, sym_init_declarator_list,
		   0, sym_init_declarator,
		   0, sym_declarator,
		   0, sym_direct_declarator,
		   0, sym_direct_declarator,
		   0, sym_generic_identifier,
		   0, sym_IDENTIFIER))
    return NULL;
  return get_function_definition (stack, identifier, declaration);
}

static void append_function_declaration (Ast * parent, Ast * declaration)
{
  if (parent->parent->sym == sym_external_declaration)
    ast_block_list_append (ast_ancestor (parent, 2),
			   sym_external_declaration, declaration);
  else if (parent->parent->sym ==
	   sym_external_foreach_dimension) {
    int index = ast_child_index (parent);
    parent->parent->child[index] = ast_placeholder;
    Ast * foreach_dimension = ast_copy (parent->parent);
    parent->parent->child[index] = parent;
    ast_set_child (foreach_dimension, index, declaration);
    ast_block_list_append (ast_ancestor (parent, 3),
			   sym_external_declaration, foreach_dimension);
  }
  else
    assert (false);
}

static Ast * make_stencil_function (Ast * n, Stack * stack, void * scope)
{
  Ast * identifier = function_call_identifier (n);
  if (!identifier) {
    fprintf (stderr,
	     "%s:%d: warning: stencils: "
	     "cannot analyze point function pointers\n",
	     ast_left_terminal (n)->file, ast_left_terminal (n)->line);
    identifier = ast_identifier_declaration (stack, "default_stencil");
  }
  Ast * function_declaration = NULL;
  Ast * function_definition = get_function_definition (stack, identifier, NULL);
  if (function_definition) {
    function_declaration =
      ast_identifier_declaration (stack, ast_terminal (identifier)->start);
    while (function_declaration &&
	   function_declaration->sym != sym_declaration &&
	   function_declaration->sym != sym_function_definition)
    function_declaration = function_declaration->parent;
    if (function_declaration->sym != sym_declaration)
      function_declaration = NULL;
  }
  else {
    fprintf (stderr,
	     "%s:%d: warning: stencils: point function '%s' is not defined\n",
	     ast_left_terminal (n)->file, ast_left_terminal (n)->line,
	     ast_terminal (identifier)->start);
    identifier = ast_identifier_declaration (stack, "default_stencil");
    function_definition =
      ast_identifier_declaration (stack, ast_terminal (identifier)->start);
    while (function_definition &&
	   function_definition->sym != sym_declaration &&
	   function_definition->sym != sym_function_definition)
      function_definition = function_definition->parent;
  }

  assert (!ast_is_stencil_function (function_definition));
	
  /**
  Look for a previously-defined stencil function. */

  Ast * stencil = get_stencil_function (function_definition);
  if (stencil)
    return stencil;
  
  if (function_definition == scope)
    return NULL; // fixme: recursive function call
  
  /**
  We create the new stencil function. */
      
  stencil = ast_stencil (function_definition);
  if (stencil) {
    Ast * m = function_definition;
    AstTerminal * t = ast_terminal_new (m, sym_VOID, "void");
    str_append (t->before, " ");
    Ast * specifiers =
      ast_new_children
      (ast_new (m, sym_declaration_specifiers),
       ast_new_children
       (ast_new (m, sym_storage_class_specifier),
	ast_terminal_new (m, sym_STATIC, "static")),
       ast_new_children
       (ast_new (m, sym_declaration_specifiers),
	ast_new_children
	(ast_new (m, sym_type_specifier),
	 ast_new_children (ast_new (m, sym_types), t))));
    ast_replace_child (ast_schema (stencil, sym_function_definition,
				   0, sym_function_declaration),
		       0,
		       specifiers);
    str_prepend (ast_terminal (ast_function_identifier (stencil))->start,
		 "_stencil_");
    append_function_declaration (function_definition, stencil);
    
    /**
    We also create the corresponding declaration if necessary. */

    if (function_declaration) {
      Ast * semicolumn =
	ast_terminal_new_char ((Ast *) ast_right_terminal (stencil->child[0]),
			       ";");
      Ast * specifiers = ast_copy (ast_schema (stencil, sym_function_definition,
					       0, sym_function_declaration,
					       0, sym_declaration_specifiers));
      Ast * declarator = ast_copy (ast_schema (stencil, sym_function_definition,
					       0, sym_function_declaration,
					       1, sym_declarator));
      Ast * declaration =
	ast_new_children
	(ast_new (n, sym_declaration),
	 specifiers,
	 ast_new_children (ast_new (n, sym_init_declarator_list),
			   ast_new_children (ast_new (n, sym_init_declarator),
					     declarator)),
	 semicolumn);
      append_function_declaration (function_declaration, declaration);
    }
  }
  return stencil;
}

static void referenced (Ast * n, Stack * stack, void * scope)
{
  if (n->sym == sym_IDENTIFIER &&
      n->parent->parent->sym != sym_member_identifier) {
    Ast * ref = ast_identifier_declaration (stack, ast_terminal(n)->start);
    if (ref)
      ast_terminal (ref)->value = scope;
  }
  if (ast_terminal (n))
    ast_terminal (n)->value = scope;
  else
    for (Ast ** c = n->child; *c; c++)
      referenced (*c, stack, scope);
}

static Ast * matching_parameter (Ast * parameter_list, Ast * argument,
				 Stack * stack)
{
  Ast * type = ast_expression_type (argument, stack, false);
  if (type) {    
    Ast * declarator = type;
    while (declarator && declarator->sym != sym_declarator)
      declarator = declarator->parent;
    assert (declarator);    

    while (type &&
	   type->sym != sym_declaration &&
	   type->sym != sym_struct_declaration &&
	   type->sym != sym_parameter_declaration)
      type = type->parent;
    assert (type);
    Ast * type_specifier = ast_find (type, sym_type_specifier);
    assert (type_specifier);
    
    foreach_item (parameter_list, 2, parameter)
      if (ast_are_identical (type_specifier,
			     ast_find (parameter, sym_declaration_specifiers,
				       0, sym_type_specifier)) &&
	  ast_are_identical (ast_schema (declarator, sym_declarator,
					 0, sym_pointer),
			     ast_find (parameter, sym_declarator,
				       0, sym_pointer)))
	return parameter;
  }
  return NULL;
}

static bool terminal_is_referenced (Ast * n, Stack * stack, Ast * scope)
{
  Ast * ref;
  return (n->sym == sym_IDENTIFIER &&
	  ast_ancestor (n, 2)->sym != sym_member_identifier &&
	  (ref = ast_terminal(n)->value == scope ? n :
	   ast_identifier_declaration (stack, ast_terminal(n)->start)) &&
	  ast_terminal (ref)->value == scope);
}

static bool is_referenced (Ast * n, Stack * stack, Ast * scope)
{
  if (!n)
    return false;
  if (n->sym == sym_array_access &&
      !is_referenced (n->child[0], stack, scope))
    return false;
  if (terminal_is_referenced (n, stack, scope))
    return true;
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      if (is_referenced (*c, stack, scope))
	return true;
  return false;
}

static bool is_scalar (Ast * n, Stack * stack)
{
  const char * typename =
    ast_typedef_name (ast_expression_type (n, stack, true));
  return (typename &&
	  (!strcmp (typename, "scalar") ||
	   !strcmp (typename, "vertex scalar")));    
}

static bool is_field (Ast * n, Stack * stack)
{
  const char * typename =
    ast_typedef_name (ast_expression_type (n, stack, true));
  return typename && (!strcmp (typename, "scalar") ||
		      !strcmp (typename, "vertex scalar") ||
		      !strcmp (typename, "vector") ||
		      !strcmp (typename, "face vector") ||
		      !strcmp (typename, "tensor") ||
		      !strcmp (typename, "symmetric tensor"));
}

static void field_references (Ast * n, Stack * stack, void * scope)
{
  switch (n->sym) {

  case sym_array_access: {
    if (is_scalar (n->child[0], stack)) {
      referenced (n->child[0], stack, scope);
      AstTerminal * t = ast_right_terminal (n);
      t->value = t;
    }
    break;
  }

  case sym_function_call: {
    Ast * identifier;
    if (point_function_call (n)) {
      Ast * stencil = make_stencil_function (n, stack, scope);
      if (stencil) {
	Ast * arguments = ast_schema (n, sym_function_call,
				      2, sym_argument_expression_list);
	if (!strcmp (ast_terminal (ast_function_identifier (stencil))->start,
		     "_stencil_default_stencil")) {
	  foreach_item (arguments, 2, argument)
	    if (is_field (argument, stack))
	      referenced (argument, stack, scope);
	}
	else { // standard stencil point function
	  Ast * parameters = ast_find (stencil, sym_direct_declarator,
				       2, sym_parameter_type_list,
				       0, sym_parameter_list);
	  foreach_item (arguments, 2, argument) {
	    Ast * parameter = matching_parameter (parameters, argument, stack);
	    if (parameter) {
	      referenced (argument, stack, scope);
	      if (parameter->parent->child[1])
		parameters = parameter->parent->child[0];
	    }
	  }
	}
	AstTerminal * t = ast_right_terminal (n);
	t->value = t;
      }
    }
    else if ((identifier = function_call_identifier (n))) {
      const char * name = ast_terminal (identifier)->start;
      if (!strcmp (name, "val") ||
	  !strcmp (name, "fine") ||
	  !strcmp (name, "coarse")) {
	Ast * argument = ast_schema (n, sym_function_call,
				     2, sym_argument_expression_list);
	while (argument->child[1])
	  argument = argument->child[0];
	assert (argument->child[0]->sym == sym_argument_expression_list_item);
	referenced (argument, stack, scope);
	AstTerminal * t = ast_right_terminal (n);
	t->value = t;
      }
    }
    break;
  }

  }
}

static bool is_field_reference (Ast * n)
{
  if (!n || (n->sym != sym_array_access &&
	     n->sym != sym_function_call))
    return false;
  AstTerminal * t = ast_right_terminal(n);
  return t->value == t;
}

static void assigned (Ast * n, Stack * stack, void * scope)
{
  if ((ast_schema (n, sym_assignment_expression,
		   1, sym_assignment_operator) ||
       ast_schema (n, sym_init_declarator,
		   1, token_symbol('='))) &&
      is_referenced (n->child[0], stack, scope) &&
      !is_field_reference (ast_schema (n->child[0], sym_unary_expression,
				       0, sym_postfix_expression,
				       0, sym_array_access)) &&
      !is_field_reference (ast_schema (n->child[0], sym_unary_expression,
				       0, sym_postfix_expression,
				       0, sym_function_call)))
    referenced (n->child[2], stack, scope);
  else if (is_referenced (ast_schema (n, sym_forin_declaration_statement,
				      3, sym_declarator), stack, scope) ||
	   is_referenced (ast_schema (n, sym_forin_statement,
				      2, sym_expression), stack, scope))
    referenced (ast_child (n, sym_forin_arguments), stack, scope);
}

static void mark_referenced (Ast * n, Stack * stack, void * scope)
{
  if (terminal_is_referenced (n, stack, scope))
    ast_terminal (n)->value = scope;
}

static Ast * copy_marked (Ast * n, Ast * scope, AstRoot * root);

static Ast * copy_only_array_references (Ast * n, Ast * list,
					 Ast * scope, AstRoot * root)
{
  if (is_field_reference (n)) {
    Ast * copy = point_function_call (n) ? copy_marked (n, scope, root) :
      ast_copy (n);
    Ast * assignment =
      ast_attach (ast_new_unary_expression (n),
		  ast_attach (ast_new (n, sym_postfix_expression),
			      copy));
    return !list->child ?
      ast_new_children (list, assignment) :
      ast_new_children (ast_new (n, list->sym),
			list, 
			ast_terminal_new_char (assignment, ","),
			assignment);
  }
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      list = copy_only_array_references (*c, list, scope, root);
  return list;
}

static Ast * block_list_append (Ast * list, Ast * item)
{
  return !list->child ? ast_new_children (list, item) :
    ast_new_children (ast_new (item, list->sym), list, item);
}

static bool is_marked (Ast * n, Ast * scope, bool noarray)
{
  if (is_field_reference (n))
    return !noarray;
  if (n->sym == sym_array_access && !is_field_reference (n) &&
      !is_marked (n->child[0], scope, noarray))
    return false;
  if (ast_terminal (n) && ast_terminal (n)->value == scope)
    return true;
  else if (n->child)
    for (Ast ** c = n->child; *c; c++)
      if (is_marked (*c, scope, noarray))
	return true;
  return false;
}

static Ast * expression_from_item (Ast * item)
{
  if (item->sym == sym_expression)
    return item;
  assert (item->child[0]->sym == sym_assignment_expression);
  Ast * n = item->parent;
  Ast * expr = ast_new_children (ast_new (n, sym_expression),
				 item->child[0]);
  Ast * unary = ast_new_unary_expression (n);
  ast_attach (unary, ast_new (n, sym_postfix_expression));
  ast_attach (unary,
	      ast_new_children
	      (ast_new (n, sym_primary_expression),
	       ast_terminal_new_char (expr, "("),
	       ast_new_children (ast_new (n, sym_expression_error),
				 expr),
	       ast_terminal_new_char (expr, ")")));
  ast_set_child (item, 0, unary);
  return expr;
}

static Ast * copy_marked (Ast * n, Ast * scope, AstRoot * root)
{
  switch (n->sym) {

  case sym_jump_statement: {
    if (n->child[0]->sym == sym_RETURN) {
      Ast * expression =
	copy_only_array_references (n, ast_new (n, sym_expression), scope, root);
      return !expression->child ? NULL :
	ast_new_children (ast_new (n, sym_expression_statement),
			  expression, ast_copy (n->child[2]));
    }
    break;
  }
    
  case sym_selection_statement: {
    if (is_marked (n->child[2], scope, true)) {
      if (!is_marked (n->child[4], scope, false) &&
	  (!n->child[5] || !is_marked (n->child[6], scope, false)))
	return NULL; // fixme: this will break if the condition (n->child[2]) has side effects
    }
    else { // condition does not involve an array reference
      Ast * list = ast_new (n, sym_block_item_list);
      Ast * expression =
	copy_only_array_references (n->child[2], ast_new (n, sym_expression),
				    scope, root);
      int ns = 0;
      if (expression->child) {
	Ast * item = ast_new (n,
			      sym_block_item,
			      sym_statement,
			      sym_expression_statement);
	Ast * last = item;
	while (last->child) last = last->child[0];
	ast_new_children (last,
			  expression,
			  ast_terminal_new_char (n->child[3], ";"));
	list = block_list_append (list, item);
	ns++;
      }
      Ast * statement = copy_marked (n->child[4], scope, root);
      if (statement) {
	Ast * item = ast_new_children (ast_new (n, sym_block_item), statement);
	list = block_list_append (list, item);
	ns++;
      }
      if (n->child[5] && (statement = copy_marked (n->child[6], scope, root))) {
	Ast * item = ast_new_children (ast_new (n, sym_block_item), statement);
	list = block_list_append (list, item);
	ns++;
      }
      if (ns == 0)
	return NULL;
      if (ns == 1)
	return CHECK (ast_schema (list, sym_block_item_list,
				  0, sym_block_item,
				  0, sym_statement)->child[0]);
      else
	return
	  CHECK (ast_new_children (ast_new (n, sym_compound_statement),
				   ast_terminal_new_char (n, "{"),
				   list,
				   ast_terminal_new_char ((Ast *)
							  ast_right_terminal (n),
							  "}")));
    }
    break;
  }
    
  case sym_iteration_statement: case sym_for_declaration_statement: {
    Ast * statement = ast_child (n, sym_statement);
    if (statement) {
      bool marked = false;
      for (Ast ** c = n->child; *c && !marked; c++)
	if (*c != statement && is_marked (*c, scope, false))
	  marked = true;
      if (!marked)
	return CHECK (copy_marked (statement, scope, root));
    }
    break;
  }
    
  case sym_assignment_expression: {
    if (n->child[1]) {
      Ast * expression = NULL;
      if (!is_marked (n->child[0], scope, false))
	expression =
	  copy_only_array_references (n->child[2], ast_new (n, sym_expression),
				      scope, root);
      else if (is_field_reference (ast_schema (n->child[0], sym_unary_expression,
					    0, sym_postfix_expression,
					    0, sym_array_access)) ||
	       is_field_reference (ast_schema (n->child[0], sym_unary_expression,
					    0, sym_postfix_expression,
					    0, sym_function_call))) {
	expression =
	  copy_only_array_references (n->child[0], ast_new (n, sym_expression),
				      scope, root);
	expression = copy_only_array_references (n->child[2], expression,
						 scope, root);
      }
      if (expression)
	return expression->child ? CHECK (expression) : NULL;
    }
    break;
  }

  case sym_direct_declarator: {
    if (ast_schema (n, sym_direct_declarator,
		    1, token_symbol ('[')) &&
	!is_marked (n->child[0], scope, false))
      return NULL;
    break;
  }
    
  case sym_init_declarator: {
    if (!is_marked (n, scope, false))
      return NULL;
    if (n->child[1] && !is_marked (n->child[0], scope, false)) {
      Ast * expression =
	copy_only_array_references (n->child[2], ast_new (n, sym_expression),
				    scope, root);
      return expression->child ? CHECK (expression) : NULL;
    }
    break;
  }

  case sym_declaration: {
    if (!is_marked (n, scope, false))
      return NULL;
    if (n->child[1]->sym == sym_init_declarator_list) {
      bool marked = false;
      foreach_item (n->child[1], 2, init_declarator)
	if (is_marked (init_declarator->child[0], scope, false))
	  marked = true;
      if (!marked) {
	Ast * expression = copy_marked (n->child[1], scope, root);
	if (!expression)
	  return NULL;
	return
	  CHECK (ast_new_children (ast_new (n, sym_expression_statement),
				   expression,
				   ast_terminal_new_char (n->child[2], ";")));
      }
    }
    break;    
  }

  case sym_function_call: {
    if (is_field_reference (n) && point_function_call (n)) {
      Ast * c = ast_copy_single (n, &root, &root);
      c->parent = (Ast *) root;
      ast_set_child (c, 0, copy_marked (n->child[0], scope, root));
      ast_set_child (c, 1, ast_copy (n->child[1]));
      Ast * identifier = function_call_identifier (c);
      if (identifier) {
	Ast * function_definition =
	  get_function_definition (root->stack, identifier, NULL);
	if (function_definition && get_stencil_function (function_definition))
	  str_prepend (ast_terminal (identifier)->start, "_stencil_");
	else
	  identifier = NULL;
      }
      if (!identifier)
	ast_replace_child
	  (c, 0,
	   ast_new_children
	   (ast_new (n, sym_postfix_expression),
	    ast_new_children
	    (ast_new (n, sym_primary_expression),
	     ast_terminal_new (n, sym_IDENTIFIER, "_stencil_default_stencil"))));
      Ast * arguments = copy_marked (ast_child (n, sym_argument_expression_list),
				     scope, root);
      if (!arguments) {
	ast_set_child (c, 2, ast_copy (n->child[3]));
	c->child[3] = NULL;
      }
      else {
	ast_set_child (c, 2, arguments);
	ast_set_child (c, 3, ast_copy (n->child[3]));
	c->child[4] = NULL;

	/**
	Deal with function call arguments which are also field references. */

	Ast * item = NULL, * expr = NULL;
	foreach_item (arguments, 2, argument)
	  if (!is_field_reference (ast_find (argument, sym_array_access)) &&
	      !is_field_reference (ast_find (argument, sym_function_call))) {
	    item = argument;
	    break;
	  }
	assert (item);

	foreach_item (arguments, 2, argument)
	  if (argument != item &&
	      (is_field_reference (ast_find (argument, sym_array_access)) ||
	       is_field_reference (ast_find (argument, sym_function_call)))) {
	    Ast * assign_expr = argument->child[0];
	    argument->child[0] = ast_placeholder;
	    arguments = ast_list_remove (arguments, argument);
	    if (!expr)
	      expr = expression_from_item (item);
	    while (expr->child[0]->sym == sym_expression)
	      expr = expr->child[0];
	    ast_new_children (expr,
			      ast_new_children (ast_new (n, sym_expression),
						assign_expr),
			      ast_terminal_new_char (assign_expr, ","),
			      expr->child[0]);
	  }
      }
      return CHECK (c);
    }
    if (!is_marked (n->child[0], scope, false)) {
      Ast * arguments = ast_child (n, sym_argument_expression_list);
      assert (arguments);
      Ast * parent = n->parent;
      while (parent->sym != sym_statement)
	parent = parent->parent;
      if (parent->child[0]->sym == sym_expression_statement) {
	Ast * expression =
	  copy_only_array_references (arguments, ast_new (n, sym_expression),
				      scope, root);
	return expression->child ? CHECK (expression) : NULL;
      }
    }
    break;
  }

  case sym_block_item_list: {
    if (!is_marked (n, scope, false))
      return NULL;
    if (n->child[1]) {
      Ast * item = copy_marked (n->child[1], scope, root);
      Ast * list = copy_marked (n->child[0], scope, root);
      if (!item)
	return list;
      if (!list)
	return CHECK (ast_new_children (ast_new (n, n->sym), item));
      return CHECK (ast_new_children (ast_new (n, n->sym), list, item));
    }
    break;
  }

  case sym_parameter_list: case sym_argument_expression_list: {
    if (!is_marked (n, scope, false))
      return NULL;
    if (n->child[1]) {
      Ast * item = is_marked (n->child[2], scope, false) ?
	copy_marked (n->child[2], scope, root) : NULL;
      Ast * list = is_marked (n->child[0], scope, false) ?
	copy_marked (n->child[0], scope, root) : NULL;
      if (!item)
	return CHECK (list);
      if (is_field_reference (ast_find (n->child[2], sym_array_access)) ||
	  is_field_reference (ast_find (n->child[2], sym_function_call))) {
	AstTerminal * t = ast_right_terminal (item);
	t->value = t;
      }
      if (!list)
	return item->sym == n->sym ? CHECK (item) :
	  CHECK (ast_new_children (ast_new (n, n->sym), item));
      while (item->sym == n->sym)
	item = item->child[0];
      return
	CHECK (ast_new_children (ast_new (n, n->sym),
				 list,
				 ast_copy (n->child[1]),
				 item));
    }
    break;
  }
    
  case sym_init_declarator_list: case sym_expression: {
    if (n->parent->sym != sym_foreach_inner_statement &&
	n->parent->sym != sym_array_access) {
      if (!is_marked (n, scope, false))
	return NULL;
      if (n->child[1]) {
	Ast * item = is_marked (n->child[2], scope, false) ?
	  copy_marked (n->child[2], scope, root) : NULL;
	Ast * list = is_marked (n->child[0], scope, false) ?
	  copy_marked (n->child[0], scope, root) : NULL;
	if (!item)
	  return CHECK (list);
	if (!list)
	  return item->sym == sym_expression ? CHECK (item) :
	    CHECK (ast_new_children (ast_new (n, n->sym), item));
	while (item->sym == sym_expression)
	  item = item->child[0];
	return
	  CHECK (ast_new_children
		 (ast_new (n, item->sym == sym_assignment_expression ?
			   sym_expression : n->sym),
		  list,
		  ast_copy (n->child[1]),
		  item));
      }
    }
    break;
  }

  case sym_logical_and_expression: case sym_logical_or_expression: {
    if (n->child[1] && (!is_marked (n->child[0], scope, false) ||
			!is_marked (n->child[2], scope, false)))
      return is_marked (n->child[0], scope, false) ?
	copy_marked (n->child[0], scope, root) :
	ast_new_children (ast_new (n, n->sym),
			  copy_marked (n->child[2], scope, root));
    break;
  }
    
  case sym_expression_statement: {
    if (!n->child[1])
      return NULL;
    Ast * expression = copy_marked (n->child[0], scope, root);
    if (!expression)
      return NULL;
    return CHECK (ast_new_children (ast_new (n, sym_expression_statement),
				    expression, ast_copy (n->child[1])));
    break;
  }
    
  case sym_statement: {
    if (!is_marked (n, scope, false))
      return NULL;
    break;
  }

  case sym_foreach_statement: {
    Ast * statement = ast_last_child (n);
    Ast * copy = copy_marked (statement, scope, root);
    if (!copy)
      return NULL;
    Ast * c = ast_copy_single (n, &root, &root), ** j = c->child;
    for (Ast ** i = n->child; *i != statement; i++, j++)
      *j = ast_copy (*i), (*j)->parent = c;
    *j = copy, (*j)->parent = c;
    return CHECK (c);
    break;
  }
    
  }

  Ast * c = ast_copy_single (n, &root, &root);
  if (n->child) {
    int nc = 0, np = 0;
    for (Ast ** i = n->child, ** j = c->child; *i; i++, j++) {
      *j = copy_marked (*i, scope, root);
      if (!(*j))
	*j = ast_placeholder, np++;
      else
	(*j)->parent = c, nc++;
    }
    if (nc == 0) {
      ast_destroy (c);
      return NULL;
    }

    if (c->child[0] != ast_placeholder) {
      if (!c->child[1] && c->child[0]->sym == c->sym)
	c = c->child[0];

      if (c->sym != sym_forin_arguments &&
	  c->sym != sym_expression_error &&
	  c->child[0]->sym == sym_expression && !c->child[1])
	c = c->child[0];
    
      if (c->sym != sym_block_item &&	
	  c->child[0]->sym == sym_statement && !c->child[1])
	c = c->child[0];
    }
    
    switch (c->sym) {
      
    case sym_direct_declarator: {
      if (ast_schema (c, sym_direct_declarator,
		      1, token_symbol ('(')) &&
	  c->child[2] == ast_placeholder) {
	assert (c->child[4] == NULL);
	c->child[2] = c->child[3];
	c->child[3] = NULL;
      }
      break;
    }
      
    case sym_block_item: {
      if (c->child[0]->sym == sym_expression_statement)
	ast_set_child (c, 0,
		       ast_new_children (ast_new (n, sym_statement),
					 c->child[0]));
      break;
    }

    }
  }
  return CHECK (c);
}

Ast * ast_stencil (Ast * n)
{
  AstRoot * root = ast_get_root (n);
  Stack * stack = root->stack;
  stack_push (stack, &n);
  ast_traverse (n, stack, field_references, n);
  ast_traverse (n, stack, assigned, n);
  ast_traverse (n, stack, mark_referenced, n);
  ast_pop_scope (stack, n);
  return CHECK (copy_marked (n, n, root));
}
