/**
# Automatic boundary conditions */

#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "symbols.h"

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

static void field_references (Ast * n, Stack * stack, void * scope)
{
  Ast * reference = NULL;
  
  switch (n->sym) {

  case sym_array_access: {
    const char * typename =
      ast_typedef_name (ast_expression_type (n->child[0], stack, true));
    if (typename &&
	(!strcmp (typename, "scalar") ||
	 !strcmp (typename, "vertex scalar")))
      reference = n;
    break;
  }

  case sym_function_call: {
    Ast * identifier = ast_schema (n, sym_function_call,
				   0, sym_postfix_expression,
				   0, sym_primary_expression,
				   0, sym_IDENTIFIER);
    if (identifier) {
      const char * name = ast_terminal (identifier)->start;
      if (!strcmp (name, "val") ||
	  !strcmp (name, "fine") ||
	  !strcmp (name, "coarse"))
	reference = n;
    }
    break;
  }

  }

  if (reference) {
    if (reference->sym == sym_array_access)
      referenced (reference->child[0], stack, scope);
    else {
      assert (reference->sym == sym_function_call);
      Ast * argument = ast_schema (reference, sym_function_call,
				   2, sym_argument_expression_list);
      while (argument->child[1])
	argument = argument->child[0];
      assert (argument->child[0]->sym == sym_argument_expression_list_item);
      referenced (argument, stack, scope);
    }
    AstTerminal * t = ast_right_terminal (reference);
    t->value = t;
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
  if (terminal_is_referenced (n, stack, scope))
    return true;
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      if (is_referenced (*c, stack, scope))
	return true;
  return false;
}

static bool is_marked (Ast * n, Ast * scope, bool noarray)
{
  if (noarray && is_field_reference (n))
    return false;
  if (ast_terminal (n) &&
      ast_terminal (n)->value == scope)
    return true;
  else if (n->child)
    for (Ast ** c = n->child; *c; c++)
      if (is_marked (*c, scope, noarray))
	return true;
  return false;
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

static Ast * copy_only_array_references (Ast * n, Ast * list)
{
  if (is_field_reference (n)) {
    Ast * assignment =
      ast_attach (ast_new_unary_expression (n),
		  ast_attach (ast_new (n, sym_postfix_expression),
			      ast_copy (n)));
    return !list->child ?
      ast_new_children (list, assignment) :
      ast_new_children (ast_new (n, list->sym),
			list, 
			ast_terminal_new_char (assignment, ","),
			assignment);
  }
  
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      list = copy_only_array_references (*c, list);
  return list;
}

static Ast * block_list_append (Ast * list, Ast * item)
{
  return !list->child ? ast_new_children (list, item) :
    ast_new_children (ast_new (item, list->sym), list, item);
}

#define CHECK(x) ast_check_grammar(x)

static Ast * copy_marked (Ast * n, Ast * scope, AstRoot * root)
{
  switch (n->sym) {

  case sym_selection_statement: {
    if (is_marked (n->child[2], scope, true)) {
      if (!is_marked (n->child[4], scope, false) &&
	  (!n->child[5] || !is_marked (n->child[6], scope, false)))
	return NULL; // fixme: this will break if the condition (n->child[2]) has side effects
    }
    else { // condition does not involve an array reference
      Ast * list = ast_new (n, sym_block_item_list);
      Ast * expression =
	copy_only_array_references (n->child[2], ast_new (n, sym_expression));
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
	  copy_only_array_references (n->child[2], ast_new (n, sym_expression));
      else if (is_field_reference (ast_schema (n->child[0], sym_unary_expression,
					    0, sym_postfix_expression,
					    0, sym_array_access)) ||
	       is_field_reference (ast_schema (n->child[0], sym_unary_expression,
					    0, sym_postfix_expression,
					    0, sym_function_call))) {
	expression =
	  copy_only_array_references (n->child[0], ast_new (n, sym_expression));
	expression = copy_only_array_references (n->child[2], expression);
      }
      if (expression)
	return expression->child ? CHECK (expression) : NULL;
    }
    break;
  }

  case sym_init_declarator: {
    if (!is_marked (n, scope, false))
      return NULL;
    if (n->child[1] && !is_marked (n->child[0], scope, false)) {
      Ast * expression =
	copy_only_array_references (n->child[2], ast_new (n, sym_expression));
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
    Ast * list = ast_child (n, sym_argument_expression_list);
    assert (list);    
#if 0
    Ast * point = NULL;
    foreach_item (list, 2, item) {
      Ast * identifier = ast_is_identifier_expression (item->child[0]);
      if (identifier && !strcmp (ast_terminal(identifier)->start, "point"))
	point = item;
    }
    if (point) // point function call
      ast_print (n, stdout, 0);
    else
#endif
    if (!is_marked (n, scope, true)) {
      Ast * expression =
	copy_only_array_references (list, ast_new (n, sym_expression));
      return expression->child ? CHECK (expression) : NULL;
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

  case sym_init_declarator_list: case sym_expression: {
    if (n->parent->sym != sym_foreach_inner_statement) {
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
    
  }

  Ast * c = ast_copy_single (n, &root, &root);
  if (n->child) {
    int len = 0, nc = 0, np = 0;
    for (Ast ** i = n->child, ** j = c->child; *i; i++, j++, len++) {
      *j = copy_marked (*i, scope, root);
      if (!(*j))
	*j = ast_placeholder, np++;
      else
	(*j)->parent = c, nc++;
    }
    if (nc == 0)
      return NULL;
    c->child[len] = NULL;
    assert (!np);
    if (!c->child[1] && c->child[0]->sym == c->sym)
      c = c->child[0];

    if (c->sym != sym_forin_arguments &&
	c->sym != sym_expression_error &&
	c->child[0]->sym == sym_expression && !c->child[1])
      c = c->child[0];
    
    if (c->sym != sym_block_item &&
	c->child[0]->sym == sym_statement && !c->child[1])
      c = c->child[0];
    
    switch (c->sym) {

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

Ast * ast_stencil (Ast * foreach, Stack * stack)
{
  assert (foreach->sym == sym_foreach_statement &&
	  (!strcmp (ast_terminal (foreach->child[0])->start, "foreach") ||
	   !strcmp (ast_terminal (foreach->child[0])->start, "foreach_vertex") ||
	   !strcmp (ast_terminal (foreach->child[0])->start, "foreach_face")));
  Ast * statement = ast_last_child (foreach);
  stack_push (stack, &foreach);
  ast_traverse (statement, stack, field_references, foreach);
  ast_traverse (statement, stack, assigned, foreach);
  ast_traverse (statement, stack, mark_referenced, foreach);
  ast_pop_scope (stack, foreach);
  Ast * copy = copy_marked (statement, foreach, ast_get_root (foreach));
  if (!copy)
    return NULL;
  
  int index = ast_child_index (statement);
  foreach->child[index] = ast_placeholder;
  Ast * stencil = ast_copy (foreach);
  foreach->child[index] = statement;
  ast_set_child (stencil, index, copy);  
  
  return stencil;
}
