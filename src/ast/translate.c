#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ast.h"
#include "symbols.h"
#include "stack.h"

Ast * ast_is_typedef (Ast * identifier)
{
  Ast * declaration = identifier;
  while (declaration && declaration->sym != sym_declaration)
    declaration = declaration->parent;
  if (declaration)
    return ast_schema (declaration, sym_declaration,
		       0, sym_declaration_specifiers,
		       0, sym_storage_class_specifier,
		       0, sym_TYPEDEF);
  return NULL;
}

Ast * ast_find_function (Ast * n, const char * name)
{
  Ast * found = NULL;
  if (n->sym == sym_function_definition) {
    Ast * identifier = ast_find (n, sym_direct_declarator,
				 0, sym_generic_identifier,
				 0, sym_IDENTIFIER);
    if (!strcmp (ast_terminal(identifier)->start, name))
      found = n;
  }
  if (n->child)
    for (Ast ** c = n->child; *c && !found; c++)
      found = ast_find_function (*c, name);
  return found;
}

/**
Appends (block) list `list1` to (block) list `list`. */

Ast * ast_list_append_list (Ast * list, Ast * list1)
{
  assert (list->sym == list1->sym);
  Ast * oldparent = list->parent;
  int index = ast_child_index (list);
  Ast * parent = list1;
  while (parent->child[1])
    parent = parent->child[0];
  Ast * item = parent->child[0];
  ast_new_children (parent, list, item);
  ast_set_child (oldparent, index, list1);
  return list1;
}

/**
Appends `item` to (block) `list`. The list item symbol is `item_sym`. */

Ast * ast_block_list_append (Ast * list, int item_sym, Ast * item)
{
  Ast ** c, * parent = list->parent;
  for (c = parent->child; *c && *c != list; c++);
  assert (*c == list);
  Ast * l = ast_new_children (ast_new (list->parent, list->sym),
			      list, 
			      ast_attach (ast_new (list, item_sym), item));
  *c = l;
  l->parent = parent;
  return l;
}

/**
Appends `item` to (comma-separated) `list`. The list item symbol is
`item_sym`. */

Ast * ast_list_append (Ast * list, int item_sym, Ast * item)
{
  Ast ** c;
  for (c = list->parent->child; *c && *c != list; c++);
  assert (*c == list);
  Ast * l =  ast_new_children (ast_new (list->parent, list->sym),
			       list, 
			       ast_terminal_new_char (item, ","),
			       ast_new (item, item_sym));
  ast_attach (l->child[2], item);
  *c = l;
  return l;
}

/**
Prepends `item` to (comma-separated) `list`. The list item symbol is
`item_sym`. */

Ast * ast_list_prepend (Ast * list, int item_sym, Ast * item)
{
  Ast * r = list;
  while (r->child[0]->sym != item_sym)
    r = r->child[0];
  Ast * l = ast_list_append (r, item_sym, item), * tmp = r->child[0];
  ast_set_child (r, 0, l->child[2]);
  ast_set_child (l, 2, tmp);
  return r != list ? list : l;
}

/**
Transforms a list of expressions into a list of arguments. */

void ast_argument_list (Ast * expression)
{
  while (expression->sym == sym_expression) {
    int child = expression->child[1] ? 2 : 0;
    expression->sym = sym_argument_expression_list;
    Ast * item = ast_new (expression, sym_argument_expression_list_item);
    ast_new_children (item, expression->child[child]);
    ast_set_child (expression, child, item);
    expression = expression->child[0];
  }
}

/**
Transforms a list of arguments ('argument_expression_list') into a
list of initializers ('initializer_list'). */

Ast * ast_initializer_list (Ast * list)
{
  Ast * start = list;
  while (list->sym == sym_argument_expression_list) {
    list->sym = sym_initializer_list;
    Ast * initializer = list->child[1] ? list->child[2] : list->child[0];
    initializer->sym = sym_initializer;
    if (initializer->child[1]) {
      Ast * designator = ast_new (initializer, sym_designator);
      Ast * identifier = ast_new (initializer, sym_generic_identifier);
      Ast * dot = ast_terminal_new_char (initializer, ".");
      ast_new_children (designator, dot, identifier);
      ast_new_children (identifier, initializer->child[0]);
      AstTerminal * left = ast_left_terminal (identifier);
      ast_terminal (dot)->line = left->line;
      ast_terminal (dot)->before = left->before; left->before = NULL;      
      Ast * designator_list =
	ast_new_children (ast_new (initializer, sym_designator_list),
			  designator);
      Ast * designation =
	ast_new_children (ast_new (initializer, sym_designation),
			  designator_list,
			  initializer->child[1]);
      if (list->child[1])
	ast_new_children (list,
			  list->child[0], list->child[1],
			  designation, initializer->child[2]);
      else
	ast_new_children (list,
			  designation, initializer->child[2]);
    }
    list = list->child[0];    
  }
  return start;
}

Ast * ast_new_unary_expression (Ast * parent)
{
  return ast_new (parent,
		  sym_assignment_expression,
		  sym_conditional_expression,
		  sym_logical_or_expression,
		  sym_logical_and_expression,
		  sym_inclusive_or_expression,
		  sym_exclusive_or_expression,
		  sym_and_expression,
		  sym_equality_expression,
		  sym_relational_expression,
		  sym_shift_expression,
		  sym_additive_expression,
		  sym_multiplicative_expression,
		  sym_cast_expression,
		  sym_unary_expression);
}

Ast * ast_is_unary_expression (Ast * n)
{
  return ast_schema (n, sym_assignment_expression,
		     0, sym_conditional_expression,
		     0, sym_logical_or_expression,
		     0, sym_logical_and_expression,
		     0, sym_inclusive_or_expression,
		     0, sym_exclusive_or_expression,
		     0, sym_and_expression,
		     0, sym_equality_expression,
		     0, sym_relational_expression,
		     0, sym_shift_expression,
		     0, sym_additive_expression,
		     0, sym_multiplicative_expression,
		     0, sym_cast_expression,
		     0, sym_unary_expression);  
}

Ast * ast_is_identifier_expression (Ast * n)
{
  n = ast_is_unary_expression (n);
  if (n)
    n = ast_schema (n, sym_unary_expression,
		    0, sym_postfix_expression,
		    0, sym_primary_expression,
		    0, sym_IDENTIFIER);
  return n;
}

Ast * ast_new_constant (Ast * parent, int symbol, const char * value)
{
  return ast_attach (ast_new_unary_expression (parent),
		     ast_new (parent,
			      sym_postfix_expression,
			      sym_primary_expression,
			      sym_constant),
		     ast_terminal_new (parent, symbol, value));
}

Ast * ast_new_identifier (Ast * parent, const char * name)
{
  return ast_attach (ast_new (parent,
			      sym_postfix_expression,
			      sym_primary_expression),
		     ast_terminal_new (parent, sym_IDENTIFIER, name));
}

Ast * ast_new_member_identifier (Ast * parent, const char * name)
{
  return ast_attach (ast_new (parent,
			      sym_member_identifier,
			      sym_generic_identifier),
		     ast_terminal_new (parent, sym_IDENTIFIER, name));
}

Ast * ast_get_struct_name (Ast * declaration_specifiers)
{
  return ast_schema (declaration_specifiers, sym_declaration_specifiers,
		     0, sym_type_specifier,
		     0, sym_types,
		     0, sym_struct_or_union_specifier,
		     1, sym_generic_identifier,
		     0, sym_IDENTIFIER);
}

static void trace_return (Ast * n, Stack * stack, void * data)
{
  Ast * function_definition = ((void **)data)[0];
  AstTerminal * function_identifier = ((void **)data)[1];
  if (ast_schema (n, sym_jump_statement, 0, sym_RETURN)) {
    Ast * ret = n->child[0];
    if (!n->child[2]) { // return ;
      ast_before (ret,
		  "{ end_trace (\"", function_identifier->start, "\", ",
		  ast_file_line (ret), "); ");
      ast_after (n->child[1], " }");
    }
    else { // return sthg;
      Ast * compound =
	ast_parse_expression ("{ void _ret = val; return _ret; }",
			      ast_get_root (n));
      ast_replace (compound, "val", ast_find (n, sym_assignment_expression),
		   false);

      Ast * declarator =
	ast_flatten (ast_copy (ast_find (function_definition, sym_declarator),
			       sym_IDENTIFIER),
		     ast_left_terminal (n));
      AstTerminal * t = ast_terminal (ast_find (declarator, sym_IDENTIFIER));
      free (t->start); t->start = strdup ("_ret");
      ast_replace (compound, "_ret", declarator, false);
      
      Ast * type_specifier =
	ast_flatten (ast_copy (ast_find (function_definition,
					 sym_declaration_specifiers,
					 0, sym_type_specifier)),
		     ast_left_terminal (n));
      ast_replace (compound, "void", type_specifier, false);
      ast_set_file_line (compound, ast_right_terminal (n));
      ast_before (ast_find (compound, sym_RETURN),
		  "end_trace (\"", function_identifier->start, "\", ",
		  ast_file_line (ret), "); ");
      ast_set_child (n->parent, 0, compound);
      str_prepend (ast_left_terminal (compound)->before,
		   ast_left_terminal (n)->before);
      ast_destroy (n);
    }
  }
}

static Ast * find_struct_member (Ast * n, Ast * member)
{
  Ast * identifier = ast_schema (n, sym_struct_declarator,
				 0, sym_declarator,
				 0, sym_direct_declarator,
				 0, sym_generic_identifier,
				 0, sym_IDENTIFIER);
  if (identifier && !strcmp (ast_terminal (identifier)->start,
			     ast_terminal (member)->start))
    return identifier;
  if (n->child)
    for (Ast ** c = n->child; *c; c++) {
      Ast * found = find_struct_member (*c, member);
      if (found)
	return found;
    }
  return NULL;
}

static Ast * declaration_from_type (Ast * type)
{
  while (type->sym != sym_declaration &&
	 type->sym != sym_parameter_declaration &&
	 type->sym != sym_struct_declaration &&
	 type->sym != sym_forin_declaration_statement)
    type = type->parent;
  assert (type);
  return type;
}

static Ast * expression_type (Ast * expr, Stack * stack)
{
  switch (expr->sym) {

  case sym_primary_expression:
    if (expr->child[0]->sym == sym_IDENTIFIER)
      return ast_identifier_declaration (stack,
					 ast_terminal (expr->child[0])->start);
    break;
    
  case sym_postfix_expression:
    assert (expr->child && expr->child[0]);
    if (expr->child[1] == NULL || expr->child[2] == NULL)
      return expression_type (expr->child[0], stack);
    if (expr->child[1]->sym == token_symbol('.')) {
      // struct member access
      Ast * str = expression_type (expr->child[0], stack);
      if (str) {
	Ast * member = ast_find (expr->child[2], sym_member_identifier,
				 0, sym_generic_identifier,
				 0, sym_IDENTIFIER);
	Ast * declaration = ast_find (declaration_from_type (str), sym_types);
	assert (declaration);
	AstTerminal * typename =
	  (AstTerminal *) ast_schema (declaration, sym_types,
				      0, sym_TYPEDEF_NAME);
	if (typename) {
	  Ast * type = ast_identifier_declaration (stack, typename->start);
	  if (!type) {
	    fprintf (stderr, "%s:%d: warning: unknown type name '%s'\n",
		     typename->file, typename->line, typename->start);
	    return NULL;
	  }
	  while (type->sym != sym_declaration)
	    type = type->parent;
	  return
	    find_struct_member (ast_find (type, sym_struct_declaration_list),
				member);
	}
	else if ((str = ast_schema (declaration, sym_types,
				    0, sym_struct_or_union_specifier,
				    2, sym_struct_declaration_list)))
	  return find_struct_member (str, member);
      }
    }
    else if (expr->child[1]->sym == sym_PTR_OP) {
      // struct member pointer access
      //      ast_print_tree (expr, stderr, 0);
    }
    break;
    
  }  
  return NULL;
}

static char * type_typedef (Ast * type)
{
  Ast * declarator = type;
  while (declarator->sym != sym_declarator)
    declarator = declarator->parent;
  
  if (!ast_schema (declarator, sym_declarator,
		   0, sym_direct_declarator,
		   0, sym_generic_identifier,
		   0, sym_IDENTIFIER) &&
      !ast_schema (declarator, sym_declarator,
		   0, sym_direct_declarator,
		   0, sym_direct_declarator,
		   0, sym_generic_identifier,
		   0, sym_IDENTIFIER))
    return NULL; // this is a pointer

  Ast * declaration = ast_find (declaration_from_type (type), sym_types), * n;
  if ((n = ast_schema (declaration, sym_types, 0, sym_TYPEDEF_NAME)))
    return ast_terminal(n)->start;
  
  return NULL;
}

static bool type_is_typedef (Ast * type, const char * typedef_name)
{
  char * name = type_typedef (type);
  return name && !strcmp (name, typedef_name);
}

static Ast * inforeach (Ast * n)
{
  Ast * parent = n->parent;
  while (parent) {
    if (parent->sym == sym_foreach_statement)
      return parent;
    parent = parent->parent;
  }
  return NULL;
}

static bool point_declaration (Stack * stack)
{
  Ast * type = ast_identifier_declaration (stack, "point");
  return type && type_is_typedef (type, "Point");
}

/**
Add arguments ('0') to `function_call` so that the call has exactly
`n` arguments. */

static void complete_arguments (Ast * function_call, int n)
{
  if (!function_call->child[3]) // function call without arguments
    ast_new_children (function_call,
		      function_call->child[0],
		      function_call->child[1],
		      ast_attach (ast_new (function_call,
					   sym_argument_expression_list,
					   sym_argument_expression_list_item),
				  ast_new_constant (function_call->child[1],
						    sym_I_CONSTANT, "0")),
		      function_call->child[2]);
  
  Ast * args = function_call->child[2];
  int i = 0;
  foreach_item (args, 2, item)
    i++;
  for (; i < n; i++) {
    args = ast_list_append (args,
			    sym_argument_expression_list_item,
			    ast_new_constant (function_call->child[3],
					      sym_I_CONSTANT, "0"));
    ast_set_child (function_call, 2, args);
  }
}

static Ast * rotate_arguments (Ast * list, int dimension)
{
  Ast * next = list->child[0], * item = list->child[2];
  for (int i = 1; i < dimension && next; i++) {
    if (next->child[1]) {
      list->child[2] = next->child[2];
      list = next;
      next = list->child[0];
    }
    else {
      list->child[2] = next->child[0];
      list = next;
      next = NULL;
    }	    
  }
  if (list->child[1])
    list->child[2] = item;
  else
    list->child[0] = item;
  return list;
}

typedef struct {
  int dimension;
} TranslateData;

static void rotate (Ast * n, Stack * stack, void * data)
{
  switch (n->sym) {

  case sym_IDENTIFIER: {
    AstTerminal * t = ast_terminal (n);
    int len = strlen (t->start);
    if (len >= 2 && t->start[len - 2] == '_' &&
	strchr ("xyz", t->start[len - 1])) {
      TranslateData * d = data;  
      t->start[len - 1] = 'x' + (t->start[len - 1] + 1 - 'x') % d->dimension;
    }
    break;
  }

  case sym_member_identifier: {
    AstTerminal * t = ast_terminal (ast_schema (n, sym_member_identifier,
						0, sym_generic_identifier,
						0, sym_IDENTIFIER));
    if (t->start[1] == '\0' && strchr ("xyz", *t->start)) {
      TranslateData * d = data;
      *t->start = 'x' + (*t->start + 1 - 'x') % d->dimension;
    }
    break;
  }

  case sym_function_call: {
    Ast * identifier = ast_schema (n, sym_function_call,
				   0, sym_postfix_expression,
				   0, sym_primary_expression,
				   0, sym_IDENTIFIER);
    if (identifier) {
      const char * name = ast_terminal (identifier)->start;
      if ((!strcmp (name, "val") ||
	   !strcmp (name, "fine") ||
	   !strcmp (name, "coarse") ||
	   !strcmp (name, "allocated") ||
	   !strcmp (name, "allocated_child") ||
	   !strcmp (name, "neighbor") ||
	   !strcmp (name, "neighborp") ||
	   !strcmp (name, "aparent"))
	  &&
	  (inforeach (n) || point_declaration (stack))) {
	TranslateData * d = data;  
	rotate_arguments (n->child[2], d->dimension);
      }
    }
    break;
  }
    
  }
}

static void rotate_list_item (Ast * item, Ast * n,
			      Stack * stack, TranslateData * d)
{
  int dimension = d->dimension;
  if (n->child[4]) {
    d->dimension = atoi (ast_terminal (n->child[2])->start);
    if (d->dimension > dimension)
      d->dimension = dimension;
  }
  
  Ast * list = item->parent;
  Ast * body = ast_last_child (n), * copy = body;
  for (int i = 1; i < d->dimension; i++) {
    copy = ast_copy (copy);
    stack_push (stack, &copy);
    ast_traverse (copy, stack, rotate, d);
    ast_pop_scope (stack, copy);
    list = ast_block_list_append (list, item->sym, copy);
  }
  ast_set_child (item, 0, body);
  AstTerminal * t = ast_left_terminal (body);
  ast_remove (n, t);

  d->dimension = dimension;
}

/**
This function returns a block_item containing *statement*. */

static Ast * get_block_list_item (Ast * statement)
{
  Ast * item = statement->parent;

  /**
  if *item* is not already a block item we need to replace it with a
  compound statement containing a new block_item_list. */
  
  if (item->sym != sym_block_item) {
    AstTerminal * l = ast_left_terminal (statement);
    Ast * left = ast_terminal_new_char ((Ast *) l, "{"),
      * right =
      ast_terminal_new_char ((Ast *) ast_right_terminal (statement), "}");
    ast_terminal (left)->before = l->before, l->before = NULL;
    Ast * parent = item;
    int index = ast_child_index (statement);
    item = ast_new_children (ast_new (parent, sym_block_item), statement);
    Ast * list = ast_new_children (ast_new (parent, sym_block_item_list),
				   item);
    Ast * compound =
      ast_new_children (ast_new (parent, sym_compound_statement),
			left, list, right);
    ast_set_child (parent, index, compound);
  }
  
  return item;
}

static
void maybeconstfield (Ast * n, Stack * stack,
		      void func (Ast * n, Ast * type, void * data),
		      void * data)
{
  Ast * identifier = ast_schema (n, sym_primary_expression,
				 0, sym_IDENTIFIER);
  if (identifier) {
    Ast * type = ast_identifier_declaration (stack,
					     ast_terminal (identifier)->start);
    if (type) {
      Ast * declaration = type;
      while (declaration->sym != sym_declaration &&
	     declaration->sym != sym_parameter_declaration)
	declaration = declaration->parent;
      if (ast_schema (declaration->child[0], sym_declaration_specifiers,
		      0, sym_type_qualifier,
		      0, sym_MAYBECONST))
	func (n, type, data);
    }
  }
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      maybeconstfield (*c, stack, func, data);  
}

static
void maybeconst (Ast * n, Stack * stack,
		 void func (Ast * n, Ast * type, void * data),
		 void * data)
{
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      maybeconst (*c, stack, func, data);  
  
  Ast * identifier = ast_schema (n, sym_function_call,
				 0, sym_postfix_expression,
				 0, sym_primary_expression,
				 0, sym_IDENTIFIER);
  if (identifier) {
    const char * name = ast_terminal (identifier)->start;
    if (!strcmp (name, "val") || !strcmp (name, "fine") ||
	!strcmp (name, "coarse"))
      maybeconstfield (ast_find (n->child[2], sym_argument_expression_list_item),
		       stack, func, data);
  }
}

static
void append_const (Ast * n, Ast * type, void * data)
{
  Ast *** m = data;
  if (!*m) {
    *m = malloc (2*sizeof (Ast *));
    (*m)[0] = type;
    (*m)[1] = NULL;
  }
  else {
    int size = 0;
    Ast ** c;
    for (c = *m; *c && *c != type; c++, size++);
    if (*c != type) {
      *m = realloc (*m, (size + 2)*sizeof (Ast *));
      (*m)[size] = type;
      (*m)[size + 1] = NULL;
    }
  }
}

/**
Replaces child at `index` of `parent` with `replacement` or with a
parent of `replacement` of the same symbol as the child. */

void ast_replace_child (Ast * parent, int index, Ast * replacement)
{
  while (replacement && replacement->sym != parent->child[index]->sym)
    replacement = replacement->parent;
  assert (replacement);
  Ast * child = parent->child[index];
  AstTerminal * left = ast_left_terminal (child);
  ast_left_terminal (replacement)->before = left->before, left->before = NULL;
  ast_set_child (parent, index, replacement);
  ast_destroy (child);
}

typedef struct {
  Ast ** consts;
  int bits;
} ReplaceConst;

static
void replace_const (Ast * n, Ast * type, void * data)
{
  ReplaceConst * r = data;
  int index = 0;
  Ast ** c;
  for (c = r->consts; *c && *c != type; c++, index++);
  assert (*c == type);
  if (r->bits & (1 << index)) {
    str_prepend (ast_terminal (n->child[0])->start, "_const_");
    Ast * unary = n;
    while (unary->sym != sym_unary_expression)
      unary = unary->parent;
    unary = unary->parent;
    while (unary->sym != sym_unary_expression)
      unary = unary->parent;
    unary = unary->parent;
    ast_replace_child (unary, 0, n);
  }
}

static void translate (Ast * n, Stack * stack, void * data)
{
  typedef struct {
    char * target, * replacement;
  } Replacement;
  
  switch (n->sym) {

  /**
  ## foreach_dimension() */

  case sym_foreach_dimension_statement: {
    Ast * item = get_block_list_item (n->parent->parent);
    rotate_list_item (item, n, stack, data);
    break;
  }

  /**
  ## External foreach_dimension() */

  case sym_external_foreach_dimension: {
    rotate_list_item (n->parent, n, stack, data);
    break;
  }
    
  /**
  ## Foreach statements */

  case sym_foreach_statement: {

    /**
    ### foreach_face() statements */
    
    if (!strcmp (ast_terminal (n->child[0])->start, "foreach_face")) {
      char order[] = "xyz";

      /**
      The complicated stuff below is just to read each (optional) x, y
      and z arguments, in the correct order, and update the *order*
      string. */
      
      if (n->child[4]) {
	char * s = order + 2;
	Ast * parameters = n->child[2];
	foreach_item (parameters, 2, param)
	  if (param->child[0]->sym == sym_assignment_expression) {
	    Ast * identifier = ast_find (param, sym_postfix_expression,
					 0, sym_primary_expression,
					 0, sym_IDENTIFIER);
	    if (identifier && ast_terminal (identifier)->start[1] == '\0' &&
		strchr ("xyz", ast_terminal (identifier)->start[0]))
	      *s-- = ast_terminal (identifier)->start[0];
	  }
	if (s != order + 2)
	  memmove (order, s + 1, strlen(s));
      }

      /**
      Here we add the `if (is_face_x())` condition to the loop
      statement. */

      AstTerminal * right = ast_right_terminal (n);
      Ast * expr = ast_parse_expression ("{if (is_face_x()){;}}",
					 ast_get_root (n));
      Ast * conditional = ast_find (expr, sym_statement);
      Ast * cond = ast_find (conditional, sym_IDENTIFIER);
      ast_terminal (cond)->start[strlen(ast_terminal (cond)->start) - 1] =
	order[0];
      ast_replace (conditional, ";", ast_last_child (n), true);
      ast_set_file_line (conditional, right);
      ast_set_child (n, n->child[4] ? 4 : 3, conditional);
      ast_destroy (expr);

      /**
      Finally, we "dimension-rotate" the statement. */
      
      if (strlen (order) > 1) {
	Ast * statement = ast_last_child (n);
	Ast * item = get_block_list_item (statement);
	TranslateData * d = data;
	int dimension = d->dimension;
	d->dimension = strlen (order);
	if (d->dimension > dimension) d->dimension = dimension;
	
	Ast * list = item->parent, * copy = statement;
	for (int i = 1; i < d->dimension; i++) {
	  copy = ast_copy (copy);
	  stack_push (stack, &copy);
	  ast_traverse (copy, stack, rotate, d);
	  ast_pop_scope (stack, copy);
	  Ast * cond = ast_find (copy, sym_IDENTIFIER);
	  ast_terminal (cond)->start[strlen(ast_terminal (cond)->start) - 1] =
	    order[i];
	  list = ast_block_list_append (list, item->sym, copy);
	}
	ast_set_child (item, 0, statement);

	d->dimension = dimension;
      }
    }

    /**
    ### (const) fields combinations */

    Ast ** consts = NULL;
    maybeconst (n, stack, append_const, &consts);
    if (consts) {
      Ast * item = get_block_list_item (n->parent->parent);
      Ast * list = item->parent;
      int nmaybeconst = 0;
      for (Ast ** c = consts; *c; c++, nmaybeconst++);
      int n2 = 1 << nmaybeconst;
      for (int bits = 0; bits < n2; bits++) {
	char * condition = strdup ("if (");
	for (int i = 0; i < nmaybeconst; i++) {
	  str_append (condition,
		      (bits & (1 << i)) ? "" : "!",
		      "is_constant(",
		      ast_terminal (consts[i])->start,
		      ")");
	  if (i < nmaybeconst - 1)
	    str_append (condition, " && ");
	}
	str_append (condition, "){");
	for (int i = 0; i < nmaybeconst; i++)
	  if (bits & (1 << i)) {
	    const char * name = ast_terminal (consts[i])->start;
	    if (type_is_typedef (consts[i], "vector") ||
		type_is_typedef (consts[i], "face vector")) {
	      str_append (condition,
			  "const struct { double x");
	      TranslateData * d = data;
	      for (int j = 1; j < d->dimension; j++) {
		char s[] = ", y"; s[2] = 'x' + j;
		str_append (condition, s);
	      }
	      str_append (condition, "; } _const_", name, " = {_constant[",
			  name,  ".x.i - _NVARMAX]");
	      for (int j = 1; j < d->dimension; j++) {
		char s[] = ".x.i - _NVARMAX]"; s[1] = 'x' + j;
		str_append (condition, ", _constant[", name, s);
	      }
	      str_append (condition, "};");
	    }
	    else
	      str_append (condition,
			  " const double _const_", name, " = _constant[",
			  name, ".i - _NVARMAX];");
	  }
	str_append (condition, "foreach();}");
	Ast * copy = bits ? ast_copy (n) : n;
	if (bits)
	  maybeconst (copy, stack, replace_const, &(ReplaceConst){consts, bits});
	Ast * conditional = ast_parse_expression (condition,
						  ast_get_root (copy));
	free (condition);
	ast_replace (conditional, ";", copy, true);
	ast_set_file_line (conditional, ast_right_terminal (copy));
	if (bits)
	  list = ast_block_list_append (list, item->sym, conditional);
	else
	  ast_set_child (item, 0, conditional);
      }
      free (consts);
    }
    
    break;
  }

  /**
  ## Stencil access 

  This transforms stencil accesses of the form `s[i,j]` into the
  function call `val(s,i,j,0)`. */

  case sym_array_access: {
    Ast * type = expression_type (n->child[0], stack);
    if (type && type_is_typedef (type, "scalar") &&
	(inforeach (n) || point_declaration (stack))) {
      n->sym = sym_function_call;
      ast_set_char (n->child[1], '(');

      if (n->child[3])
	ast_argument_list (n->child[2]);
      complete_arguments (n, 3);
      
      ast_set_child (n, 2,
		     ast_list_prepend (n->child[2],
				       sym_argument_expression_list_item,
				       ast_attach (ast_new_unary_expression (n),
						   n->child[0])));
      ast_set_char (n->child[3], ')');
		     
      char * before = ast_left_terminal (n)->before;
      ast_left_terminal (n)->before = NULL;      
      n->child[0] = ast_new_identifier (n, "val");
      ast_left_terminal (n)->before = before;
    }
    break;
  }

  /**
  ## Attribute access */

  case sym_postfix_expression: {
    if (n->child[1] && n->child[1]->sym == token_symbol('.')) {
      Ast * type = expression_type (n->child[0], stack);
      if (type && type_is_typedef (type, "scalar")) {
	Ast * member = ast_find (n->child[2], sym_member_identifier,
				 0, sym_generic_identifier,
				 0, sym_IDENTIFIER);
	type = ast_identifier_declaration (stack, "scalar");
	while (type->sym != sym_declaration)
	  type = type->parent;
	assert (type);
	if (!find_struct_member (ast_find (type, sym_struct_declaration_list),
				 member)) {
	  Ast * scalar = n->child[0];
	  Ast * expr =
	    ast_parse_expression ("_attribute[s.i];", ast_get_root (n));
	  ast_replace (expr, "s", scalar, false);
	  ast_set_file_line (expr, ast_right_terminal (scalar));
	  ast_set_child (n, 0, ast_find (expr, sym_postfix_expression));
	  ast_destroy (expr);
	}
      }
    }
    break;
  }

  /**
  ## Attribute declaration */

  case sym_attribute: {
    Ast * identifier = ast_schema (n, sym_attribute,
				   0, sym_generic_identifier,
				   0, sym_IDENTIFIER);
    if (identifier &&
	!strcmp (ast_terminal (identifier)->start, "attribute")) {

      /**
      Remove 'attribute' from external declarations. */

      Ast * translation = n->parent->parent;
      assert (translation->child[1]);
      Ast * next = translation->child[0];
      assert (translation->parent->child[1]);
      ast_set_child (translation->parent, 0, next);
      assert (next->child[1]);
      str_prepend (ast_left_terminal (translation->parent->child[1])->before,
		   ast_left_terminal (n)->before);

      /**
      Add attributes to typedef '_Attributes'. */
      
      Ast * attr = ast_identifier_declaration (stack, "_Attributes");
      while (attr->sym != sym_declaration)
	attr = attr->parent;
      ast_list_append_list (ast_find (attr, sym_struct_declaration_list),
			    n->child[2]);

      /**
      Cleanup. */
      
      ast_destroy (translation);
    }
    break;
  }
  
  /**
  ## Identifiers */
  
  case sym_IDENTIFIER: {
    if (n->parent->sym == sym_primary_expression) {
      static Replacement replacements[] = {
	{ "stderr", "ferr" },
	{ NULL, NULL }
      };
      Replacement * i = replacements;
      AstTerminal * identifier = ast_terminal (n);
      while (i->target) {
	if (!strcmp (identifier->start, i->target)) {
	  free (identifier->start);
	  identifier->start = strdup (i->replacement);
	}
	i++;
      }
    }
    break;
  }

  /**
  ## Function calls */

  case sym_function_call: {
    Ast * identifier = ast_schema (n, sym_function_call,
				   0, sym_postfix_expression,
				   0, sym_primary_expression,
				   0, sym_IDENTIFIER);
    if (identifier) {
      AstTerminal * t = ast_terminal (identifier);

      /**
      ### Memory allocation tracing */

      static Replacement replacements[] = {
	{ "malloc",  "pmalloc" },
	{ "calloc",  "pcalloc" },
	{ "realloc", "prealloc" },
	{ "free",    "pfree" },
	{ "strdup",  "pstrdup" },
	{ NULL, NULL }
      };
      Replacement * i = replacements;
      while (i->target) {
	if (!strcmp (t->start, i->target)) {
	  free (t->start);
	  t->start = strdup (i->replacement);
	  assert (n->child[3]);
	  ast_before (n->child[3], ",__func__,__FILE__,__LINE__");
	}
	i++;
      }

      /**
      ### Stencil functions */

      if (inforeach (n) || point_declaration (stack)) {
	if (!strcmp (t->start, "val") || !strcmp (t->start, "fine") ||
	    !strcmp (t->start, "coarse"))
	  complete_arguments (n, 4);
	else if (!strcmp (t->start, "allocated") ||
		 !strcmp (t->start, "allocated_child") ||
		 !strcmp (t->start, "neighbor") ||
		 !strcmp (t->start, "neighborp") ||
		 !strcmp (t->start, "aparent"))
	  complete_arguments (n, 3);
      }

      /**
      ### Functions with optional arguments */

      Ast * type = ast_identifier_declaration (stack, t->start);
      if (type) {
	while (type->sym != sym_declaration &&
	       type->sym != sym_function_definition)
	  type = type->parent;
	assert (type);
	Ast * parameters = ast_find (type, sym_parameter_list);
	if (parameters && !parameters->child[1]) {
	  Ast * struct_name =
	    ast_get_struct_name (ast_schema (parameters, sym_parameter_list,
					     0, sym_parameter_declaration,
					     0, sym_declaration_specifiers));
	  if (struct_name &&
	      ast_schema (parameters, sym_parameter_list,
			  0, sym_parameter_declaration,
			  1, sym_declarator,
			  0, sym_direct_declarator,
			  0, sym_generic_identifier,
			  0, sym_IDENTIFIER)) {
	    Ast * arguments = ast_find (n, sym_argument_expression_list);
	    Ast * struct_arg = arguments->child[1] ? NULL :
	      ast_is_identifier_expression (arguments->child[0]->child[0]);
	    if (struct_arg) {
	      Ast * type =
		ast_identifier_declaration (stack,
					    ast_terminal (struct_arg)->start);
	      while (type->sym != sym_declaration)
		type = type->parent;
	      Ast * struct_namep =
		ast_get_struct_name (ast_schema (type, sym_declaration,
						 0, sym_declaration_specifiers));
	      if (!struct_namep ||
		  strcmp (ast_terminal (struct_namep)->start,
			  ast_terminal (struct_name)->start))
		struct_arg = NULL;
	    }
	    if (!struct_arg) {
	      Ast * expr = ast_parse_expression ("func((struct Name){a});",
						 ast_get_root (n));
	      Ast * list = ast_find (expr, sym_argument_expression_list);
	      AstTerminal * t = ast_terminal (ast_find (list, sym_IDENTIFIER));
	      free (t->start);
	      t->start = strdup (ast_terminal (struct_name)->start);
	      ast_replace (list, "a", ast_initializer_list (arguments), false);
	      ast_set_file_line (list, ast_right_terminal (n));
	      ast_set_child (n, 2, list);
	      ast_destroy (expr);
	    }
	  }
	}
      }
      
    }
    break;
  }

  }
}

static void macros (Ast * n, Stack * stack, void * data)
{
  switch (n->sym) {

  /**
  ## Foreach statements */

  case sym_foreach_statement: {
    Ast * foreach = inforeach (n);
    if (foreach) {
      AstTerminal * t = ast_terminal (n->child[0]);
      AstTerminal * p = ast_terminal (foreach->child[0]);
      fprintf (stderr,
	       "%s:%d: error: foreach*() iterators cannot be nested\n",
	       t->file, t->line);      
      fprintf (stderr,
	       "%s:%d: error: this is the location of the parent %s\n",
	       p->file, p->line,
	       foreach->sym == sym_foreach_statement ?
	       "foreach*()" : "point function");
      exit (1);
    }
    
    Ast * statement = ast_last_child (n);
    if (statement->child[0]->sym == sym_compound_statement)
      ast_after (statement, " end_", ast_left_terminal(n)->start, "();");
    else {
      ast_before (statement, "{");
      ast_after (statement, "} end_", ast_left_terminal(n)->start, "();");
    }
    break;
  }

  /**
  ## Foreach inner statements */
    
  case sym_foreach_inner_statement: {
    Ast * statement = ast_last_child (n);
    if (statement->child[0]->sym == sym_compound_statement)
      ast_after (statement, " end_", ast_left_terminal(n)->start, "();");
    else {
      ast_before (statement, "{");
      ast_after (statement, "} end_", ast_left_terminal(n)->start, "();");
    }
    break;
  }

  /**
  ## forin_declaration_statement */

  case sym_forin_declaration_statement: {
    Ast * declarator = n->child[3];
    Ast * identifier = ast_schema (declarator, sym_declarator,
				   0, sym_direct_declarator,
				   0, sym_generic_identifier,
				   0, sym_IDENTIFIER);
    if (!identifier) {
      AstTerminal * t = ast_left_terminal (n);
      fprintf (stderr,
	       "%s:%d: error: incorrect declaration\n",
	       t->file, t->line);
      exit (1);
    }
    char * name = ast_terminal(identifier)->start;
    Ast * declaration = ast_find (n->child[2], sym_types), * type;
    const char * typename =
      (type = ast_schema (declaration, sym_types, 0, sym_TYPEDEF_NAME)) ?
      ast_terminal(type)->start : NULL;
    if (!typename || (strcmp (typename, "scalar") &&
		      strcmp (typename, "vector") &&
		      strcmp (typename, "tensor"))) {
      AstTerminal * t = ast_left_terminal (n);
      fprintf (stderr,
	       "%s:%d: error: '%s' is not a scalar, vector or tensor\n",
	       t->file, t->line, name);
      exit (1);
    }
    char * src = NULL;
    str_append (src, "{", typename, "*_i=list;if(_i)"
		"for(", typename, " ", name, "=*_i;_i",
		!strcmp (typename, "scalar") ? "->i" :
		!strcmp (typename, "vector") ? "->x.i" :
		"->x.x.i",
		">=0;", name, "=*++_i){_statement_;}}");
    Ast * expr = ast_parse_expression (src, ast_get_root (n));
    free (src);
    AstTerminal * right = ast_right_terminal (n);
    Ast * parent = n->parent;
    Ast * initializer = ast_find (expr, sym_initializer);
    ast_destroy (initializer->child[0]);
    ast_set_child (initializer, 0, n->child[5]->child[0]);
    assert (ast_replace (expr, "_statement_", ast_last_child (n), true));
    ast_left_terminal (expr)->before = ast_left_terminal (n)->before,
      ast_left_terminal (n)->before = NULL;
    ast_set_file_line (expr, right);
    ast_set_child (parent->parent, ast_child_index (parent), expr);
    ast_destroy (parent);
    break;
  }

  /**
  ## forin_statement */

  case sym_forin_statement: {
    Ast * arg = n->child[4]->child[0];
    char * decl = strdup ("{"), * fors = strdup ("if(_i0)for("), * fore = NULL;
    int index = 0;
    foreach_item (n->child[2], 2, expr) {
      Ast * identifier = ast_is_identifier_expression (expr);
      if (!identifier) {
	AstTerminal * t = ast_left_terminal (expr);
	fprintf (stderr,
		 "%s:%d: error: not a scalar, vector or tensor\n",
		 t->file, t->line);
	exit (1);
      }
      AstTerminal * t = ast_terminal (identifier);
      Ast * type = ast_identifier_declaration (stack, t->start);
      if (!type || (!type_is_typedef (type, "scalar") &&
		    !type_is_typedef (type, "vector") &&
		    !type_is_typedef (type, "tensor"))) {
	fprintf (stderr,
		 "%s:%d: error: `%s' is not a scalar, vector or tensor\n",
		 t->file, t->line, t->start);
	exit (1);
      }
      if (!arg) {
	fprintf (stderr,
		 "%s:%d: error: lists must have the same size\n",
		 t->file, t->line);
	exit (1);
      }
      Ast * l;
      if (arg->sym == sym_field_list || !arg->child[1]) {
	l = arg;
	arg = NULL;
      }
      else {
	l = arg->child[2];
	arg = arg->child[0];
      }
      char ind[10];
      snprintf (ind, 9, "%d", index);
      str_append (decl, type_typedef (type), "*_i", ind, "=");
      decl = ast_str_append (l, decl);
      str_append (decl, ";");
      str_append (fors, index > 0 ? "," : "", t->start, "=*_i", ind);
      if (!fore)
	str_append (fore, "_i", ind,
		    type_is_typedef (type, "scalar") ? "->i" :
		    type_is_typedef (type, "vector") ? "->x.i" :
		    "->x.x.i",
		    ">= 0;");
      str_append (fore, index > 0 ? "," : "", t->start, "=*++_i", ind);
      index++;
    }
    str_append (decl, fors, ";", fore, "){_statement_;}}");
    Ast * expr = ast_parse_expression (decl, ast_get_root (n));
    free (decl); free (fors); free (fore);
    AstTerminal * right = ast_right_terminal (n);
    Ast * parent = n->parent;
    assert (ast_replace (expr, "_statement_", ast_last_child (n), true));
    ast_left_terminal (expr)->before = ast_left_terminal (n)->before,
      ast_left_terminal (n)->before = NULL;
    ast_set_file_line (expr, right);
    ast_set_child (parent->parent, ast_child_index (parent), expr);
    ast_destroy (parent);
    break;
  }

  /**
  ## Function profiling with `trace` */

  case sym_function_definition: {
    Ast * trace = ast_schema (n, sym_function_definition,
			      0, sym_function_declaration,
			      0, sym_declaration_specifiers,
			      0, sym_storage_class_specifier,
			      0, sym_TRACE);
    if (trace) {
      ast_hide (ast_terminal (trace));
      Ast * identifier = ast_find (n, sym_direct_declarator,
				   0, sym_generic_identifier,
				   0, sym_IDENTIFIER);
      Ast * compound_statement = ast_last_child (n);
      ast_after (compound_statement->child[0],
		 " trace (\"", ast_terminal (identifier)->start, "\", ",
		 ast_file_line (identifier), "); ");
      Ast * end = ast_last_child (compound_statement);
       ast_before (end,
		  " end_trace (\"", ast_terminal (identifier)->start, "\", ",
		  ast_file_line (end), "); ");
      if (compound_statement->child[1]->sym == sym_block_item_list) {
	void * data[] = { n, identifier };
	ast_traverse (compound_statement, stack, trace_return, data);
      }
    }
    break;
  }

  }
}

void ast_push_declaration (Stack * stack, Ast * n)
{
  if (n->sym == sym_parameter_type_list ||
      n->sym == sym_struct_declaration_list)
    return; // skip function arguments and struct members
  Ast * identifier = ast_schema (n, sym_direct_declarator,
				 0, sym_generic_identifier,
				 0, sym_IDENTIFIER);
  if (!identifier)
    identifier = ast_schema (n, sym_enumeration_constant,
			     0, sym_generic_identifier,
			     0, sym_IDENTIFIER);
  if (identifier)
    stack_push (stack, &identifier);
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      ast_push_declaration (stack, *c);
}

void ast_pop_scope (Stack * stack, Ast * scope)
{
  Ast * n;
  while ((n = *((Ast **)stack_pop (stack))) != scope) {
#if 0
    if (n->sym == sym_IDENTIFIER) {
      fputs ("  pop: ", stderr);
      ast_identifier_print (n, stderr);
    }
#endif
  }
#if 0
  fputs ("scope: ", stderr);
  ast_print_file_line (n, stderr);
#endif
}

Ast * ast_push_function_definition (Stack * stack, Ast * declarator)
{
  Ast * identifier = ast_find (declarator, sym_direct_declarator,
			       0, sym_generic_identifier,
			       0, sym_IDENTIFIER);
  stack_push (stack, &identifier);
  stack_push (stack, &declarator);
  Ast * parameters = ast_find (declarator, sym_parameter_list);
  if (parameters)
    ast_push_declaration (stack, parameters);
  return identifier;
}

void ast_traverse (Ast * n, Stack * stack,
		   void func (Ast *, Stack *, void *),
		   void * data)
{
  if (ast_root (n)) {
    ast_pop_scope (stack, n);
    stack_push (stack, &n);
  }
  
  switch (n->sym) {

  /**
  These should match the corresponding action/mid-action rules in
  [basilisk.yacc](). */
    
  case sym_function_definition: {
    Ast * declarator = ast_find (n, sym_direct_declarator);
    ast_push_function_definition (stack, declarator);
    for (Ast ** c = n->child; *c; c++)
      ast_traverse (*c, stack, func, data);
    ast_pop_scope (stack, declarator);
    break;
  }
    
  case sym_compound_statement:
  case sym_for_declaration_statement: {
    stack_push (stack, &n);
    for (Ast ** c = n->child; *c; c++)
      ast_traverse (*c, stack, func, data);
    ast_pop_scope (stack, n);
    break;
  }
    
  case sym_forin_declaration_statement: {
    stack_push (stack, &n);
    ast_push_declaration (stack, n->child[3]);
    for (Ast ** c = n->child; *c; c++)
      ast_traverse (*c, stack, func, data);
    ast_pop_scope (stack, n);
    break;
  }

  case sym_declaration:
    ast_push_declaration (stack, n);
    // fall through
    
  default:
    if (n->child)
      for (Ast ** c = n->child; *c; c++)
	ast_traverse (*c, stack, func, data);
    break;
  }
  
  func (n, stack, data);
}

void endfor (FILE * fin, FILE * fout)
{
  char * buffer = NULL;
  size_t len = 0, maxlen = 0;
  int c;
  while ((c = fgetc (fin)) != EOF) {
    if (len >= maxlen) {
      maxlen += 4096;
      buffer = realloc (buffer, maxlen);      
    }
    buffer[len++] = c;
  }
  if (len >= maxlen) {
    maxlen++;
    buffer = realloc (buffer, maxlen);      
  }
  buffer[len++] = '\0';

#if 1
  FILE * fp = fopen (".endfor", "w");
  fputs (buffer, fp);
  fclose (fp);
#endif

  fp = fopen (BASILISK "/ast/defaults.h", "r");
  assert (fp);
  AstRoot * d = ast_parse_file (fp, NULL);
  fclose (fp);
  
  AstRoot * root = ast_parse (buffer, d);
  free (buffer);
  root->stack = d->stack; d->stack = NULL;
  root->alloc = d->alloc; d->alloc = NULL;
  
  //  ast_stack_print (root->stack, stderr);

  TranslateData data = { .dimension = 3 };
  ast_traverse ((Ast *) root, root->stack, translate, &data);
  ast_traverse ((Ast *) root, root->stack, macros, &data);

  //  ast_stack_print (root->stack, stderr);

  ast_print ((Ast *) root, fout, false);
#if 1
  fp = fopen (".endfor.out", "w");
  ast_print ((Ast *) root, fp, false);
  fclose (fp);
#endif

#if 0
  Ast * main = ast_find_function ((Ast *) root, "main");
  if (main) {
    fp = fopen (".endfor.main", "w");
    ast_print_tree (main, fp, 0);
    fclose (fp);
  }
#endif
  
  ast_destroy ((Ast *) d);
  ast_destroy ((Ast *) root);
}
