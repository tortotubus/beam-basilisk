/**
# Automatic boundary conditions */

#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "symbols.h"

#if 0 // for debugging
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

static Ast * function_call_identifier (Ast * n)
{
  return ast_schema (n, sym_function_call,
		     0, sym_postfix_expression,
		     0, sym_primary_expression,
		     0, sym_IDENTIFIER);
}

static bool is_scalar (Ast * n, Stack * stack)
{
  const char * typename =
    ast_typedef_name (ast_expression_type (n, stack, true));
  return (typename &&
	  (!strcmp (typename, "scalar") ||
	   !strcmp (typename, "vertex scalar")));    
}

static Ast * is_point_function_call (Ast * n)
{  
  Ast * arguments = ast_child (n, sym_argument_expression_list);
  if (!arguments)
    return NULL;
  foreach_item (arguments, 2, argument)
    if (argument != ast_placeholder) {
      Ast * identifier = ast_is_identifier_expression (argument->child[0]);
      if (identifier && !strcmp (ast_terminal(identifier)->start, "point"))
	return argument;
    }
  return NULL;
}

static bool is_field_access (Ast * n, Stack * stack)
{  
  switch (n->sym) {

  case sym_array_access: {
    if (is_scalar (n->child[0], stack))
      return true;
    break;
  }

  case sym_function_call: {
    Ast * identifier = function_call_identifier (n);
    AstTerminal * t;
    if (identifier && (t = ast_terminal (identifier)) &&
	(!strcmp (t->start, "val") ||
	 !strcmp (t->start, "fine") ||
	 !strcmp (t->start, "coarse") ||
	 !strcmp (t->start, "allocated") ||
	 !strcmp (t->start, "allocated_child") ||
	 !strcmp (t->start, "neighbor") ||
	 !strcmp (t->start, "neighborp") ||
	 !strcmp (t->start, "aparent") ||
	 !strcmp (t->start, "child") ||
	 !strcmp (t->start, "_assign") ||
	 !strcmp (t->start, "r_assign")))
      return true;
    if (is_point_function_call (n))
      return true;
    break;
  }

  }

  return false;
}

static Ast * block_list_append (Ast * list, Ast * item)
{
  return !list->child ? ast_new_children (list, item) :
    ast_new_children (ast_new (item, list->sym), list, item);
}

static
Ast * move_field_access (Ast * parent, Ast * n, bool after)
{
  Ast * assignment = ast_parent (n, sym_assignment_expression);
  Ast * op = ast_child (assignment, sym_assignment_operator);
  if (!op && ast_ancestor (assignment, 2)->sym == sym_expression_statement)
    return NULL; // already on its own in an expression statement
  Ast * item = ast_block_list_get_item (parent);
  Ast * postfix = n->parent;
  if (op) {
    Ast * assign = ast_attach (ast_new_unary_expression (parent),
			       postfix);
    AstTerminal * func = NB(assign, sym_IDENTIFIER,
			    op->child[0]->sym == token_symbol('=') ?
			    "_assign" : "r_assign");
    postfix = NN(parent, sym_postfix_expression,
		 NN(parent, sym_function_call,
		    NN(parent, sym_postfix_expression,
		       NN(parent, sym_primary_expression,
			  func)),
		    NCB(assign, "("),
		    NN(parent, sym_argument_expression_list,
		       NN(parent, sym_argument_expression_list_item,
			  assign)),
		    NCA(assign, ")")));
  }
  Ast * assign = ast_attach (ast_new_unary_expression (parent),
			     postfix);
  Ast * statement = NN(parent, sym_statement,
		       NN(parent, sym_expression_statement,
			  NN(parent, sym_expression,
			     assign),
			  NCA(assign, ";")));
  if (after)
    return ast_block_list_append (item->parent, item->sym, statement);
  else
    return ast_block_list_insert_before2 (item, statement);
}

/**
Move field accesses into their own expression statement, before their
parent statement or declaration. */

void move_field_accesses (Ast * n, Stack * stack, void * scope)
{
  if (is_field_access (n, stack)) {
    Ast * parent = n->parent;
    while (parent &&
	   parent->sym != sym_statement &&
	   parent->sym != sym_declaration)
      parent = parent->parent;
    assert (parent);
    if (parent->sym == sym_statement) {
      switch (parent->child[0]->sym) {

      case sym_jump_statement:
      case sym_selection_statement:
      case sym_expression_statement: {
	move_field_access (parent, n, false);
	break;
      }
	
      default:  // fixme: deal with other statements
	ast_print_tree (parent->child[0], stderr, 0, 0, 1);
	abort();
      }
    }
    else {
      assert (parent->sym == sym_declaration);
      move_field_access (parent, n, true);
    }    
  }
}

static
Ast * get_local_variable_reference (Ast * n, Stack * stack, Ast * scope)
{
  Ast * identifier = ast_child (ast_find (n, sym_postfix_expression,
					  0, sym_primary_expression),
				sym_IDENTIFIER);
  if (!identifier || ast_ancestor (identifier, 3)->sym == sym_function_call)
    return NULL;
  return ast_identifier_declaration_from_to
    (stack, ast_terminal (identifier)->start, NULL, scope);
}

static
void set_conditionals (Ast * n, Stack * stack, void * scope)
{
  switch (n->sym) {

  case sym_jump_statement:
    ast_destroy (n);
    break;

  case sym_postfix_expression:
    if (n->child[1] && (n->child[1]->sym == sym_INC_OP ||
			n->child[1]->sym == sym_DEC_OP) &&
	!get_local_variable_reference (n, stack, scope)) {
      Ast * parent = n->parent;
      int index = ast_child_index (n);
      AstTerminal * t = ast_terminal_new (n, sym_ADD_ASSIGN, "+=");
      Ast * assign = NN (n, sym_assignment_expression,
			 NN (n, sym_unary_expression, n->child[0]),
			 NN (n, sym_assignment_operator, t),
			 ast_placeholder);
      ast_destroy (n->child[1]);
      ast_set_child (parent, index, assign);
    }
    break;
    
  case sym_assignment_expression:
    if (n->child[1] && n->child[2] != ast_placeholder &&
	!get_local_variable_reference (n, stack, scope))
      ast_destroy (n->child[2]);
    break;
    
  }
}

static inline Ast * o_stencil (Ast * n)
{
  return ast_attach (ast_new_unary_expression (n),
		     NN (n, sym_postfix_expression,
			 NN (n, sym_primary_expression,
			     NB (n, sym_IDENTIFIER, "o_stencil"))));
}

/**
Fix successive (symbolically) identical parent / child. */

void ast_shift_children (Ast * n)
{
  while (n->child && !n->child[1] && n->child[0] != ast_placeholder &&
	 n->child[0]->sym == n->sym) {
    n->child = n->child[0]->child;
    for (Ast ** c = n->child; *c; c++)
      if (*c != ast_placeholder)
	(*c)->parent = n;
  }
}

static Ast * is_field (Ast * n, Stack * stack)
{
  Ast * type = ast_expression_type (n, stack, true);
  const char * typename = ast_typedef_name (type);
  return typename && (!strcmp (typename, "scalar") ||
		      !strcmp (typename, "vertex scalar") ||
		      !strcmp (typename, "vector") ||
		      !strcmp (typename, "face vector") ||
		      !strcmp (typename, "tensor") ||
		      !strcmp (typename, "symmetric tensor")) ?
    type : NULL;
}

static
bool has_field_arguments (Ast * function_call, Stack * stack)
{
  Ast * arguments = ast_child (function_call, sym_argument_expression_list);
  foreach_item (arguments, 2, argument)
    if (is_field (argument, stack))
      return true;
  return false;
}

/**
Clean up placeholders. */

void ast_cleanup (Ast * n, Stack * stack, void * scope)
{
  if (!n->child) // terminals are clean
    return;
  
  int nc = 0, np = 0;
  for (Ast ** c = n->child; *c; c++)
    if (*c != ast_placeholder)
      nc++;
    else
      np++;
  if (!nc) {
    // all children are destroyed, destroy parent
    if (n->sym != sym_argument_expression_list)
      ast_destroy (n);
    else {
      Ast * function_call = ast_parent (n, sym_function_call);      
      if (!is_point_function_call (function_call) &&
	  is_field_access (function_call, stack))
	ast_set_child (n, 0, NN (n, sym_argument_expression_list_item,
				 o_stencil (function_call)));
    }
    return;
  }
  
  if (!np) { // clean
    ast_shift_children (n);

    switch (n->sym) {
    
    /**
    Remove function calls which do not reference fields. */

    case sym_function_call:
      if (n->sym == sym_function_call && !is_point_function_call (n) &&
	  !is_field_access (n, stack) && !has_field_arguments (n, stack))
	ast_destroy (n);
      break;

    /**
    Remove values from return statements in point functions. */

    case sym_jump_statement:
      if (n->child[0]->sym == sym_RETURN && n->child[2] &&
	  ((Ast *) scope)->sym == sym_function_definition) {
	ast_destroy (n->child[1]);
	n->child[1] = n->child[2];
	n->child[2] = NULL;
      }
      break;
      
    }
      
    return;
  }

  /**
  Fix placeholders. */
  
  switch (n->sym) {

  case sym_selection_statement:
    if (n->child[0]->sym == sym_IF) {
      if (n->child[4] == ast_placeholder &&
	  (!n->child[5] || n->child[6] == ast_placeholder)) {
	ast_destroy (n);
	return;
      }
      else if (n->child[2] == ast_placeholder) {
	Ast * list = ast_new (n, sym_block_item_list);
	int ns = 0;
	for (int i = 4; i <= 6 && n->child[i-1]; i += 2)
	  if (n->child[i] != ast_placeholder) {
	    Ast * item = NN (n, sym_block_item, n->child[i]);
	    list = block_list_append (list, item);
	    ns++;
	  }
	if (!ns) {
	  ast_destroy (list);
	  ast_destroy (n);
	  return;
	}
	ast_destroy (n->child[1]);
	ast_destroy (n->child[3]);
	if (n->child[5])
	  ast_destroy (n->child[5]);
	n->sym = sym_statement;
	if (ns == 1) {
	  ast_destroy (n->child[0]);
	  ast_set_child (n, 0, ast_schema (list, sym_block_item_list,
					   0, sym_block_item,
					   0, sym_statement)->child[0]);
	}
	else {
	  Ast * open = ast_terminal_new_char (n, "{");
	  Ast * close = ast_terminal_new_char (n, "}");
	  ast_right_terminal(close)->line = ast_right_terminal(list)->line;
	  ast_destroy (n->child[0]);
	  ast_set_child (n, 0, NN (n, sym_compound_statement,
				   open, list, close));
	}
	n->child[1] = NULL;
	stack_push (stack, &n);
	ast_traverse (n, stack, set_conditionals, n);
	ast_pop_scope (stack, n);
	return;
      }
      else if (n->child[4] != ast_placeholder &&
	       n->child[5] &&
	       n->child[6] == ast_placeholder) {
	// IF '(' expression_error ')' statement ELSE _placeholder_
	ast_destroy (n->child[5]);
	n->child[5] = NULL;
	return;
      }
      else if (n->child[4] == ast_placeholder) {
	n->child[4] = NN (n, sym_statement,
			  NN (n, sym_expression_statement,
			      NCB (n->child[5], ";")));
	return;
      }
      else
	// fixme: deal with other cases
	assert (false);
    }
    // fixme: deal with other selection statements (switch etc.)
    assert (false);    
    break;
    
  case sym_iteration_statement:
  case sym_for_declaration_statement:
    if (!ast_child (n, sym_statement)) {
      ast_destroy (n);
      return;
    }
    break;

  case sym_foreach_inner_statement:
    assert (!ast_child (n, sym_statement));
    ast_destroy (n);
    break;
    
  case sym_argument_expression_list: {
    Ast * function_call = ast_parent (n, sym_function_call);
    if (is_point_function_call (function_call)) {
      // fixme: undefined function call argument
    }
    else if (is_field_access (function_call, stack)) {
      if (n->child[0] == ast_placeholder) {
	if (!n->child[1])
	  ast_set_child (n, 0, NN (n, sym_argument_expression_list_item,
				   o_stencil (n)));
	else
	  ast_set_child (n, 0, NN (n, sym_argument_expression_list,
				   NN (n, sym_argument_expression_list_item,
				       o_stencil (n->child[1]))));
      }
      if (n->child[1] && n->child[2] == ast_placeholder)
	ast_set_child (n, 2, NN (n, sym_argument_expression_list_item,
				 o_stencil (n->child[1])));
    }
    else
      ast_destroy (n);
    return;
  }

  case sym_jump_statement:
    assert (n->child[0]->sym == sym_RETURN);
    n->child[1] = n->child[2];
    n->child[2] = NULL;
    break;
    
  case sym_expression: {
    Ast * parent = n->parent;
    while (parent->sym == sym_expression)
      parent = parent->parent;
    if (is_field_access (parent, stack)) {
      assert (n->child[1]);
      if (n->child[0] == ast_placeholder)
	ast_set_child (n, 0, NN (n, sym_expression, o_stencil (n->child[1])));
      if (n->child[2] == ast_placeholder)
	ast_set_child (n, 2, o_stencil (n->child[1]));
      return;
    }
    if (n->child[0] == ast_placeholder) {
      if (!n->child[2] || n->child[2] == ast_placeholder) {
	ast_destroy (n);
	return;
      }
      n->child[0] = n->child[2];
    }
    ast_destroy (n->child[1]);
    n->child[1] = NULL;
    break;
  }
    
  case sym_block_item_list:
    if (n->child[0] == ast_placeholder)
      n->child[0] = n->child[1];
    n->child[1] = NULL;
    ast_shift_children (n);
    break;

  case sym_array_access:
    if (!is_field_access (n, stack))
      ast_destroy (n);
    else {
      assert (n->child[2] == ast_placeholder);
      ast_set_child (n, 2, NN (n, sym_expression, o_stencil (n)));
    }      
    break;

  case sym_function_call:
    if (n->child[0] != ast_placeholder)
      assert (!is_field_access (n, stack));
    ast_destroy (n);    
    break;

  case sym_labeled_statement:
  case sym_cast_expression:
  case sym_compound_statement:
  case sym_initializer:
  case sym_postfix_initializer:
  case sym_initializer_list:
  case sym_foreach_dimension_statement:
  case sym_postfix_expression:
  case sym_conditional_expression:
  case sym_relational_expression:
  case sym_equality_expression:
  case sym_and_expression:
  case sym_exclusive_or_expression:
  case sym_inclusive_or_expression:
  case sym_logical_and_expression:
  case sym_logical_or_expression:    
  case sym_primary_expression:
  case sym_unary_expression:
  case sym_expression_statement:
  case sym_additive_expression:
  case sym_shift_expression:
  case sym_multiplicative_expression:
    assert (!is_field_access (n, stack));
    ast_destroy (n);
    return;

  /**
  We need to keep incomplete init declarators for the
  undefined_variables() function below. */
    
  case sym_init_declarator:
    break;
    
  case sym_assignment_expression:
    if (n->child[0] == ast_placeholder) {
      ast_destroy (n);
      return;
    }

    /**
    Same as above for incomplete assignments. */
    
    break;
    
  default:
    //    ast_print_tree (n, stderr, 0, 0, 1);
    //abort();
    //    ast_print (n, stderr, 0);
    ;

  }
}

typedef struct {
  Ast * scope;
  bool undefined;
} Undefined;

static inline void set_undefined (Ast * n, Ast * scope)
{
  ast_terminal (n)->value = scope;
}

static inline bool is_undefined (Ast * n, Ast * scope)
{
  return ast_terminal (n)->value == scope;
}

static Ast * get_variable_reference (Ast * n, Stack * stack)
{
  Ast * identifier = ast_find (n, sym_postfix_expression,
			       0, sym_primary_expression);
  if (identifier->child[0] == ast_placeholder)
    return NULL;
  identifier = ast_find (n, sym_postfix_expression,
			 0, sym_primary_expression,
			 0, sym_IDENTIFIER);
  if (!identifier || ast_ancestor (identifier, 3)->sym == sym_function_call)
    return NULL;
  Ast * ref = ast_identifier_declaration (stack,
					  ast_terminal (identifier)->start);
  if (!ref) {
    fprintf (stderr, "%s:%d: error: undeclared identifier '%s'\n",
	     ast_terminal (identifier)->file,
	     ast_terminal (identifier)->line,
	     ast_terminal (identifier)->start);
    abort();
  }
  return ref;
}

static
void undefined_iterators (Ast * n, Stack * stack, void * data)
{
  Undefined * undef = data;

  switch (n->sym) {

  case sym_postfix_expression:
    if (n->child[1] && (n->child[1]->sym == sym_INC_OP ||
			n->child[1]->sym == sym_DEC_OP)) {
      Ast * ref = get_variable_reference (n, stack);
      if (!ref)
	return;
      set_undefined (ref, undef->scope);
    }
    break;

  case sym_assignment_expression:
    if (n->child[1]) {
      Ast * ref = get_variable_reference (n, stack);
      if (!ref)
	return;
      if (n->child[1]->child[0]->sym != token_symbol('='))
	set_undefined (ref, undef->scope);
    }
    return;
    
  }
}

static Ast * is_undefined_parameter (const Ast * n)
{
  Ast * identifier;
  if ((identifier = ast_schema (n, sym_parameter_declaration,
				0, sym_declaration_specifiers,
				0, sym_type_specifier,
				0, sym_types,
				0, sym_TYPEDEF_NAME)) &&
      !strcmp (ast_terminal (identifier)->start, "_stencil_undefined"))
    return identifier;
  return NULL;
}

static
bool is_local_declaration (Ast * n, Stack * stack, Ast * scope)
{
  Ast ** d;
  for (int i = 0; (d = stack_index (stack, i)); i++)
    if (*d == n)
      return true;
    else if (*d == scope)
      return false;
  return false;
}

static
void undefined_variables (Ast * n, Stack * stack, void * data)
{
  Undefined * undef = data;
  
  switch (n->sym) {

  case sym_IDENTIFIER: {
    Ast * ref = ast_identifier_declaration (stack, ast_terminal (n)->start);

    /**
    Reset state when the variable is declared. */
    
    if (ref == n) {
      if (is_undefined_parameter (ast_parent (n, sym_parameter_declaration)))
	set_undefined (ref, undef->scope);
      else
	set_undefined (ref, NULL);
      return;
    }

    /**
    Only consider variable identifiers i.e. not struct members and
    function identifiers. */
    
    if (n->parent->sym != sym_primary_expression ||
	ast_ancestor (n, 3)->sym == sym_function_call)
      return;

    /**
    If the variable is undeclared or marked as undefined, we remove it. */
    
    if (!ref || is_undefined (ref, undef->scope)) {
      ast_destroy (n);
      undef->undefined = true;
      return;
    }
    
    return;
  }
    
  case sym_init_declarator: {
    if (n->child[1] && n->child[2] == ast_placeholder) {
      Ast * ref = ast_find (n->child[0], sym_direct_declarator,
			    0, sym_generic_identifier,
			    0, sym_IDENTIFIER);
      set_undefined (ref, undef->scope);
      ast_destroy (n->child[1]);
      n->child[1] = NULL;
    }
    return;
  }

  /**
  Incremented non-local variables must be removed. */
    
  case sym_postfix_expression: {
    Ast * ref;
    if (n->child[1] && (n->child[1]->sym == sym_INC_OP ||
			n->child[1]->sym == sym_DEC_OP) &&
	(ref = get_variable_reference (n, stack)) &&
	!is_local_declaration (ref, stack, undef->scope)) {
      set_undefined (ref, undef->scope);
      ast_destroy (n);
      undef->undefined = true;
    }
    return;
  }

  case sym_assignment_expression:
    if (n->child[1]) {
      Ast * ref = get_variable_reference (n, stack);
      if (!ref)
	return;
      if (!is_local_declaration (ref, stack, undef->scope) ||
	  n->child[2] == ast_placeholder) {
	set_undefined (ref, undef->scope);
	ast_destroy (n);
	undef->undefined = true;
      }
      else if (is_undefined (ref, undef->scope) &&
	       n->child[1]->child[0]->sym == token_symbol('='))
	set_undefined (ref, NULL);
    }
    return;

  /**
  Point function calls which take the address of a variable as
  argument: we assume the point function modifies the variable. */

  case sym_function_call:
    if (is_point_function_call (n)) {
      Ast * arguments = ast_child (n, sym_argument_expression_list);
      foreach_item (arguments, 2, argument)
	if (ast_schema (argument, sym_argument_expression_list_item,
			0, sym_assignment_expression,
			0, sym_conditional_expression) &&
	    ast_find (argument, sym_unary_expression,
		      0, sym_unary_operator,
		      0, token_symbol ('&'))) {
	  Ast * ref = get_variable_reference (argument, stack);
	  if (!ref)
	    return;
	  set_undefined (ref, undef->scope);
	  ast_destroy (argument);
	  undef->undefined = true;
	}
    }
    return;
    
    
  /**
  For loops where the condition is undefined. We need to set all the
  corresponding iterative variables to undefined. */
    
  case sym_expression:
    if ((n->parent->sym == sym_for_declaration_statement ||
	 n->parent->sym == sym_iteration_statement) &&
	n->parent->child[3] == ast_placeholder)
      ast_traverse (n, stack, undefined_iterators, undef);
    break;

  /**
  Cleanup of incomplete for loops. */

  case sym_for_declaration_statement:
  case sym_iteration_statement: {
    Ast ** c;
    for (c = n->child; *c; c++)
      if (*c == ast_placeholder)
	break;
    if (!*c)
      return;
    Ast * statement = ast_child (n, sym_statement);
    for (c = n->child; *c; c++)
      if (*c != ast_placeholder && *c != statement)
	ast_destroy (*c);
    if (n->sym == sym_for_declaration_statement)
      n = n->parent;
    ast_set_child (n->parent, ast_child_index (n), statement->child[0]);
    break;
  }
    
  }
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

/**
Returns a function declaration or NULL, taking into account potential
x,y,z name rotations. */

static
Ast * identifier_function_declaration (Stack * stack, char * name,
				       Ast * from, Ast * to)
{
  Ast * n = ast_identifier_declaration_from_to (stack, name, from, to);
  int len;
  if (!n && (len = strlen(name)) > 2 &&
      name[len - 2] == '_' && strchr ("xyz", name[len - 1])) {
    char o = name[len - 1], c = 'x';
    while (!n && c <= 'z') {
      name[len - 1] = c++;
      n = ast_identifier_declaration_from_to (stack, name, from, to);
    }
    name[len - 1] = o;
  }
  return n;
}

static
Ast * get_function_definition (Stack * stack, Ast * identifier,
			       Ast * declaration)
{
  declaration = identifier_function_declaration
    (stack, ast_terminal (identifier)->start, declaration, NULL);
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

static void default_stencil (Ast * n, Stack * stack, void * scope)
{
  AstTerminal * open = NCA (n, "{"), * close = NCA (n, "}");
  ast_replace_child (n, 0,
		     NN (n, sym_postfix_expression,
			 NN (n, sym_primary_expression,
			     NB (n, sym_IDENTIFIER, "default_stencil"))));
  Ast * arguments = ast_child (n, sym_argument_expression_list);
  Ast * list = ast_new (n, sym_initializer_list);
  Ast * args = NN (n, sym_argument_expression_list,
		   NN (n, sym_argument_expression_list_item,
		       ast_attach (ast_new_unary_expression (n),
				   NN (n, sym_postfix_expression,
				       NN (n, sym_primary_expression,
					   NB (n, sym_IDENTIFIER, "point"))))));
  ast_set_child (n, 2, args);
  args = ast_list_append (args, sym_argument_expression_list_item,
			  NN (n, sym_postfix_initializer,
			      open, list, close));
  foreach_item (arguments, 2, argument)
    if (argument != ast_placeholder && is_field (argument, stack)) {
      if (!list->child)
	ast_attach (list, NN (list, sym_initializer, argument->child[0]));
      else
	list = ast_list_append (list, sym_initializer, argument->child[0]);	
    }
  if (!list->child) { // no field arguments
    list->child = allocate (ast_get_root(n)->alloc, sizeof (Ast *));
    list->child[0] = NULL;
    ast_destroy (n);
  }
}

static
Ast * null_expression (Ast * n)
{		     
  return ast_attach (ast_new_unary_expression (n),
		     NN (n, sym_postfix_expression,
			 NN (n, sym_primary_expression,
			     NA (n, sym_IDENTIFIER, "NULL"))));
}

static void point_function_calls (Ast * n, Stack * stack, void * scope)
{
  if (n->sym != sym_function_call || !is_point_function_call (n))
    return;

  Ast * identifier = function_call_identifier (n);
  if (!identifier) {
    fprintf (stderr,
	     "%s:%d: warning: stencils: "
	     "cannot analyze point function pointers\n",
	     ast_left_terminal (n)->file, ast_left_terminal (n)->line);
    default_stencil (n, stack, scope);
    return;
  }

  Ast * function_declaration = NULL;
  Ast * function_definition = get_function_definition (stack, identifier, NULL);
  if (function_definition) {
    function_declaration =
      identifier_function_declaration (stack, ast_terminal (identifier)->start,
				       NULL, NULL);
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
    default_stencil (n, stack, scope);
    return;
  }

  assert (!ast_is_stencil_function (function_definition));

  str_prepend (ast_terminal (identifier)->start, "_stencil_");
  
  if (function_definition == scope)
    return; // recursive function call
	
  /**
  Look for a previously-defined stencil function, otherwise copy the
  function definition. */

  Ast * new_stencil = NULL;
  Ast * stencil = get_stencil_function (function_definition);
  if (!stencil)
    stencil = ast_copy (function_definition), new_stencil = stencil;

  /**
  We either set undefined function parameters based on undefined
  function call arguments, or check that the undefined function call
  arguments match undefined function parameters. */
  
  Ast * arguments = ast_schema (n, sym_function_call,
				2, sym_argument_expression_list);
  Ast * parameters = ast_find (stencil, sym_direct_declarator,
			       2, sym_parameter_type_list,
			       0, sym_parameter_list);
  Ast * parameter = parameters ?
    (parameters->child[1] ? parameters->child[2] :
     parameters->child[0]) : NULL;
  foreach_item (arguments, 2, argument) {
    if (!parameter) {
      fprintf (stderr, "%s:%d: error: too many arguments in function call\n",
	       ast_left_terminal (n)->file, ast_left_terminal (n)->line);
      exit (1);
    }
    if (argument == ast_placeholder) {
      if (new_stencil) {
	
	/**
	This is a new stencil, we replace the parameter with an
	undefined type. */

	AstTerminal * pointer = NCB (parameter->child[1], "*");
	Ast * undefined = 
	  NN (parameter, sym_declaration_specifiers,
	      NN (parameter, sym_type_specifier,
		  NN (parameter, sym_types,
		      NA (parameter->child[1], sym_TYPEDEF_NAME,
			  "_stencil_undefined"))));
	ast_destroy (parameter->child[0]);
	ast_set_child (parameter, 0, undefined);
	ast_set_child (parameter, 1,
		       NN (parameter, sym_declarator,
			   NN (parameter, sym_pointer,
			       pointer),
			   NN (parameter, sym_direct_declarator,
			       NN (parameter, sym_generic_identifier,
				   ast_find (parameter->child[1],
					     sym_direct_declarator,
					     0, sym_generic_identifier,
					     0, sym_IDENTIFIER)))));
      }
      else {

	/**
	This is not a new stencil, we check that the undefined
	argument corresponds with an undefined parameter. */

	if (!is_undefined_parameter (parameter)) {
	  fprintf (stderr, "%s:%d: error: stencils: not expecting an undefined "
		   "argument for '%s'\n",
		   ast_left_terminal (n)->file, ast_left_terminal (n)->line,
		   ast_terminal (ast_find (parameter->child[1],
					   sym_IDENTIFIER))->start);
	  exit (1);
	}
      }

      /**
      We replace the undefined argument with a NULL value. */
      
      int index = arguments->child[1] ? 2 : 0;
      ast_set_child (arguments, index, NN (n, sym_argument_expression_list_item,
					   null_expression (n)));
    }

    /**
    If the parameter is undefined with replace the argument with a
    NULL value. */
    
    else if (is_undefined_parameter (parameter))
      ast_replace_child (argument, 0, null_expression (argument));
      
    parameters = parameters && parameters != ast_placeholder &&
      parameters->child[1] ? parameters->child[0] : NULL;
    parameter = parameters ?
      (parameters->child[1] ? parameters->child[2] :
       parameters->child[0]) : NULL;
    arguments = _list;
  }
  
  /**
  We create the new stencil function (if necessary). */  

  if (!new_stencil)
    return;
  stencil = ast_stencil (stencil);
  if (!stencil) {
    ast_destroy (new_stencil);
    ast_destroy (n);
  }
  else {
    Ast * m = function_definition;
    AstTerminal * t = ast_terminal_new (m, sym_VOID, "void");
    str_append (t->before, " ");
    Ast * specifiers = NN (m, sym_declaration_specifiers,
			   NN (m, sym_storage_class_specifier,
			       ast_terminal_new (m, sym_STATIC, "static")),
			   NN (m, sym_declaration_specifiers,
			       NN (m, sym_type_specifier,
				   NN (m, sym_types, t))));
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
      Ast * declaration = NN (n, sym_declaration,
			      specifiers,
			      NN (n, sym_init_declarator_list,
				  NN (n, sym_init_declarator,
				      declarator)),
			      semicolumn);
      append_function_declaration (function_declaration, declaration);
    }
  }
}

Ast * ast_stencil (Ast * n)
{
  AstRoot * root = ast_get_root (n);
  Stack * stack = root->stack;
  stack_push (stack, &n);
  ast_traverse (n, stack, move_field_accesses, n);
  Undefined u = {n};
  Ast * m = n->sym == sym_foreach_statement ? ast_child (n, sym_statement) : n;
  do {
    ast_traverse (m, stack, ast_cleanup, n);
    u.undefined = false;
    ast_traverse (m, stack, undefined_variables, &u);
  } while (u.undefined);
  ast_traverse (m, stack, ast_cleanup, n);
  ast_traverse (m, stack, point_function_calls, n);
  ast_traverse (m, stack, ast_cleanup, n);
  ast_pop_scope (stack, n);
  if (n->sym == sym_foreach_statement && !ast_child (n, sym_statement))
    return NULL;
  if (n->sym == sym_function_definition &&
      !ast_child (n, sym_compound_statement))
    return NULL;
  return CHECK (n);
}
