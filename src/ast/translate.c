#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ast.h"
#include "symbols.h"
#include "stack.h"

Ast * ast_is_enumeration_constant (Ast * identifier)
{
  if (identifier->parent->parent->sym == sym_enumeration_constant)
    return identifier->parent->parent;
  return NULL;
}

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

static void trace_return (Ast * n, Stack * stack, AstFile * file, void * data)
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
	ast_parse_expression ("{ void ret = val; return ret; }",
			      ast_get_root (function_definition));
      Ast * type_specifier =
	ast_copy (ast_find (function_definition, sym_declaration_specifiers,
			    0, sym_type_specifier));
      Ast * declarator =
	ast_copy (ast_find (function_definition, sym_declarator),
		  sym_IDENTIFIER);
      AstTerminal * identifier =
	ast_terminal (ast_find (declarator, sym_IDENTIFIER));
      free (identifier->start);
      identifier->start = strdup ("ret");
      ast_replace (ast_find (compound, sym_type_specifier), type_specifier);
      ast_replace (ast_find (compound, sym_declarator), declarator);
      ast_replace (ast_find (compound, sym_assignment_expression),
		   ast_find (n, sym_assignment_expression));
      ast_before (ast_find (compound, sym_RETURN),
		  "end_trace (\"", function_identifier->start, "\", ",
		  ast_file_line (ret), "); ");
      // fixme: file, line of compound terminals are not initialized
      ast_replace (n, compound);
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

static bool type_is_typedef (Ast * type, const char * typedef_name)
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
    return false; // this is a pointer

  Ast * declaration = ast_find (declaration_from_type (type), sym_types), * n;
  if ((n = ast_schema (declaration, sym_types, 0, sym_TYPEDEF_NAME)) &&
      !strcmp (ast_terminal(n)->start, typedef_name))
    return true;
  
  return false;
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
Appends (block) list `list1` to (block) list `list`. */

Ast * ast_list_append_list (Ast * list, Ast * list1)
{
  assert (list->sym == list1->sym);
  assert (list->sym == sym_block_item_list);
  Ast * parent = list1;
  while (parent->child[1])
    parent = parent->child[0];
  Ast * item = parent->child[0];
  assert (item->sym == sym_block_item);
  ast_new_children (parent, list, item);
  return list1;
}

/**
Appends `item` to (block) `list`. The list item symbol is `item_sym`. */

Ast * ast_block_list_append (Ast * list, int item_sym, Ast * item)
{
  Ast ** c;
  for (c = list->parent->child; *c && *c != list; c++);
  assert (*c == list);
  Ast * l = ast_new_children (ast_new (list->parent, list->sym),
			      list, 
			      ast_attach (ast_new (item, item_sym), item));
  *c = l;
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

static void rotate (Ast * n, int dimension, bool inforeach)
{
  switch (n->sym) {

  case sym_IDENTIFIER: {
    AstTerminal * t = ast_terminal (n);
    int len = strlen (t->start);
    if (len >= 2 && t->start[len - 2] == '_' &&
	strchr ("xyz", t->start[len - 1]))
      t->start[len - 1] = 'x' + (t->start[len - 1] + 1 - 'x') % dimension;
    break;
  }

  case sym_member_identifier: {
    AstTerminal * t = ast_terminal (ast_schema (n, sym_member_identifier,
						0, sym_generic_identifier,
						0, sym_IDENTIFIER));
    if (t->start[1] == '\0' && strchr ("xyz", *t->start))
      *t->start = 'x' + (*t->start + 1 - 'x') % dimension;
    break;
  }

  case sym_function_call: {
    Ast * identifier;
    if (inforeach && (identifier = ast_schema (n, sym_function_call,
					       0, sym_postfix_expression,
					       0, sym_primary_expression,
					       0, sym_IDENTIFIER))) {
      const char * name = ast_terminal (identifier)->start;
      if (!strcmp (name, "val") ||
	  !strcmp (name, "fine") ||
	  !strcmp (name, "coarse") ||
	  !strcmp (name, "allocated") ||
	  !strcmp (name, "allocated_child") ||
	  !strcmp (name, "neighbor") ||
	  !strcmp (name, "neighborp") ||
	  !strcmp (name, "aparent"))
	rotate_arguments (n->child[2], dimension);
    }
    break;
  }

  }

  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      rotate (*c, dimension, inforeach);
}

Ast * ast_replace_identifier (Ast * n, const char * identifier, Ast * with)
{
  AstTerminal * t = ast_terminal (n);
  if (t && !t->file) {
    AstTerminal * left = ast_left_terminal (with);
    t->file = left->file, t->line = left->line;
    if (left->before) {
      assert (!t->before);
      t->before = left->before;
      left->before = NULL;
    }
  }
  if (n->sym == sym_IDENTIFIER &&
      !strcmp (ast_terminal(n)->start, identifier)) {
    while (n && n->sym != with->sym)
      n = n->parent;
    if (n) {
      assert (n->parent);
      Ast ** c;
      int index = 0;
      for (c = n->parent->child; *c && *c != n; c++, index++);
      assert (*c == n);
      ast_set_child (n->parent, index, with);
      ast_destroy (n);
    }
    return n;
  }
  if (n->child)
    for (Ast ** c = n->child; *c; c++) {
      Ast * r = ast_replace_identifier (*c, identifier, with);
      if (r)
	return r;
    }
  return NULL;
}

void ast_set_file_line (Ast * n, AstTerminal * l)
{
  AstTerminal * t = ast_terminal (n);
  if (t && !t->file) {
    t->file = l->file;
    t->line = l->line;
  }
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      ast_set_file_line (*c, l);
}

typedef struct {
  int dimension;
} TranslateData;

static void translate (Ast * n, Stack * stack, AstFile * file, void * data)
{
#if 0
  AstTerminal * t = ast_terminal (n);
  if (t) {
    assert (t->line == file->line);
    assert (!strncmp (t->file, file->name, strlen(t->file)) &&
	    file->name[strlen(t->file)] == '"');
  }
#endif
  
  typedef struct {
    char * target, * replacement;
  } Replacement;
  
  switch (n->sym) {

  /**
  ## foreach_dimension() */

  case sym_foreach_dimension_statement: {
    Ast * statement = n->parent->parent, * item = statement->parent;
    if (item->sym != sym_block_item) {
      AstTerminal
	* left = ast_left_terminal (n),
	* right = ast_right_terminal (n);
      Ast * parent = item, ** c;
      int index = 0;
      for (c = parent->child; *c && *c != statement; c++, index++);
      assert (*c == statement);
      item = ast_new_children (ast_new (parent, sym_block_item),
			       statement);
      Ast * list = ast_new_children (ast_new (parent, sym_block_item_list),
				     item);
      Ast * compound =
	ast_new_children (ast_new (parent, sym_compound_statement),
			  ast_terminal_new_char ((Ast *) left, "{"),
			  list,
			  ast_terminal_new_char ((Ast *) right, "}"));
      ast_set_child (parent, index, compound);
    }
    Ast * list = item->parent;
    Ast * body = ast_last_child (n), * copy = body;
    TranslateData * d = data;
    for (int i = 1; i < d->dimension; i++) {
      copy = ast_copy (copy);
      rotate (copy, d->dimension,
	      inforeach (n) || point_declaration (stack));
      list = ast_block_list_append (list, sym_block_item, copy);
    }
    ast_set_child (item, 0, body);
    AstTerminal * t = ast_left_terminal (body);
    ast_remove (n, t);
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
	  ast_replace_identifier (expr, "s", scalar);
	  ast_set_file_line (expr, ast_right_terminal (scalar));
	  ast_set_child (n, 0, ast_find (expr, sym_postfix_expression));
	  ast_destroy (expr);
	}
      }
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
#if 0
      Ast * found = ast_identifier_declaration (stack, identifier);
      if (found) {
#if 1
	fprintf (stderr, "%s:%d: ‘%s’ identifier declared at %s:%d\n",
		 identifier->file, identifier->line, identifier->start,
		 ast_terminal (found)->file, ast_terminal (found)->line);
#endif
      }
      else if (1)
	fprintf (stderr, "%s:%d: error: ‘%s’ identifier undeclared\n",
		 identifier->file, identifier->line, identifier->start);
#endif      
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
    }
    break;
  }

  }
}

static void macros (Ast * n, Stack * stack, AstFile * file, void * data)
{
#if 0
  AstTerminal * t = ast_terminal (n);
  if (t) {
    assert (t->line == file->line);
    assert (!strncmp (t->file, file->name, strlen(t->file)) &&
	    file->name[strlen(t->file)] == '"');
  }
#endif
  
  switch (n->sym) {

  /**
  ## Foreach statements */

  case sym_foreach_statement: {
    Ast * foreach = inforeach (n);
    if (foreach) {
      AstTerminal * t = ast_terminal (n->child[0]);
      AstTerminal * p = ast_terminal (foreach->child[0]);
      fprintf (stderr,
	       "%s:%d: error: foreach*() iterators cannot be nested \n",
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
	ast_traverse (compound_statement, stack, file, trace_return, data);
      }
    }
    break;
  }

  }
}

#if 0
#define stack_push(a,b)							\
  do {									\
    AstTerminal * t = ast_left_terminal(*(b));				\
    fprintf (stderr, "%s:%d: push: %s\n",				\
	     t->file, t->line,						\
	     ast_terminal (*(b)) ? t->start :				\
	     symbol_name ((*(b))->sym));				\
    stack_push(a,b);							\
  }									\
  while (0)
#endif

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
  if (identifier) {
    stack_push (stack, &identifier);
#if 0  
    fputs ("push ", stderr);
    ast_print_file_line (identifier, stderr);
#endif
  }
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

static void update_line (AstFile * file, const char * s)
{
  if (s)
    while (*s != '\0') {
      if (*s == '\n')
	file->line++;
      s++;
    }
}

void ast_traverse (Ast * n, Stack * stack, AstFile * file,
		   void func (Ast *, Stack *, AstFile *, void *),
		   void * data)
{
  if (ast_root (n)) {
    ast_pop_scope (stack, n);
    stack_push (stack, &n);
  }

#if 0 
  AstTerminal * t = ast_terminal (n);
  if (t) {
    char * s = t->before;
    if (s)
      while (*s != '\0') {
	if (*s == '#') {
	  char * u = s - 1;
	  while (u != t->before && !strchr ("\n\r", *u) && strchr (" \t", *u))
	    u--;
	  if (u == t->before || strchr ("\n\r", *u)) {
	    file->line = atoi (s + 1) - 1;
	    file->name = strchr (s, '"');
	    assert (file->name); file->name++;
	  }
	}
	else if (*s == '\n')
	  file->line++;
	s++;
      }
    update_line (file, t->start);
    update_line (file, t->after);
  }
#endif
  AstFile f = *file;
  
  switch (n->sym) {

  /**
  These should match the corresponding action/mid-action rules in
  [basilisk.yacc](). */
    
  case sym_function_definition: {
    Ast * declarator = ast_find (n, sym_direct_declarator);
    ast_push_function_definition (stack, declarator);
    for (Ast ** c = n->child; *c; c++)
      ast_traverse (*c, stack, file, func, data);
    ast_pop_scope (stack, declarator);
    break;
  }
    
  case sym_compound_statement:
  case sym_for_declaration_statement: {
    stack_push (stack, &n);
    for (Ast ** c = n->child; *c; c++)
      ast_traverse (*c, stack, file, func, data);
    ast_pop_scope (stack, n);
    break;
  }
    
  case sym_forin_declaration_statement: {
    stack_push (stack, &n);
    ast_push_declaration (stack, n->child[3]);
    for (Ast ** c = n->child; *c; c++)
      ast_traverse (*c, stack, file, func, data);
    ast_pop_scope (stack, n);
    break;
  }

  case sym_declaration:
    ast_push_declaration (stack, n);
    // fall through
    
  default:
    if (n->child)
      for (Ast ** c = n->child; *c; c++)
	ast_traverse (*c, stack, file, func, data);
    break;
  }
  
  func (n, stack, &f, data);
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
  AstFile file = {0};
  ast_traverse ((Ast *) root, root->stack, &file, translate, &data);
  ast_traverse ((Ast *) root, root->stack, &file, macros, &data);

  //  ast_stack_print (root->stack, stderr);

  ast_print ((Ast *) root, fout, false);
#if 1
  fp = fopen (".endfor.out", "w");
  ast_print ((Ast *) root, fp, true);
  fclose (fp);
#endif

#if 1
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
