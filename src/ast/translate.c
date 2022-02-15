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

static void ast_rotate (Ast * n, int dimension)
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
    
  }

  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      ast_rotate (*c, dimension);
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
Append to `dst` the elements of a list following the standard list grammar:

~~~c
list
    : list_item
    | list ',' list_item
    ;
~~~
*/

static Ast ** append_list (Ast ** dst, Ast * list)
{
  if (list->child[1]) {
    dst = append_list (dst, list->child[0]);
    list = list->child[2];
  }
  else
    list = list->child[0];
  int len = 0;
  for (Ast ** i = dst; i && *i; i++, len++);
  dst = realloc (dst, (len + 2)*sizeof (Ast *));
  dst[len] = list;
  dst[len + 1] = NULL;
  return dst;
}

typedef struct {
  char * target, * replacement;
} Replacement;

static void translate (Ast * n, Stack * stack, void * data)
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
  ## foreach_dimension() */
#if 0
  case sym_foreach_dimension_statement: {
    Ast * body = ast_copy (ast_last_child (n));
    ast_print (body, stderr, 0);
    fputc ('\n', stderr);
    ast_rotate (body, 2);
    ast_print (body, stderr, 0);
    fprintf (stderr, "\n---------------------------\n");    
    ast_destroy (body);
    break;
  }
#endif
  /**
  ## Stencil access */

  case sym_array_access: {
    Ast * type = expression_type (n->child[0], stack);
#if 0
    if (type/* && type_is_typedef (type, "scalar")*/) {      
      AstTerminal * t = ast_terminal (ast_find (n, token_symbol('[')));
      fprintf (stderr, "%s:%d: array access\n", t->file, t->line);
      ast_print (n->child[0], stderr, 0);
      //      ast_print_tree (n, stderr, 0);
      fputc ('\n', stderr);

      Ast * declarator = type;
      while (declarator->sym != sym_declarator)
	declarator = declarator->parent;
      ast_print_tree (declarator, stderr, 0);
    }
#endif
    if (type && type_is_typedef (type, "scalar") &&
	(inforeach (n) || point_declaration (stack))) {
      Ast * expr = ast_parse_expression ("val(a,0,0,0);", ast_get_root (n));
      Ast * call = ast_find (expr, sym_function_call);
      ast_detach (call);
      ast_destroy (expr);
      AstTerminal * left = ast_left_terminal (n);
      ast_left_terminal (call)->before = left->before;
      left->before = NULL;
      ast_replace (ast_find (call->child[2], sym_postfix_expression),
		   n->child[0]);
      if (n->child[2]) {
	Ast ** expr = append_list (NULL, n->child[1]);
	Ast ** args =
	  append_list (NULL, ast_find (call, sym_argument_expression_list));
	for (Ast ** i = expr, ** j = args + 1; *i && *j; i++, j++)
	  ast_replace (*j, *i);
	free (expr);
	free (args);
      }
      ast_replace (n, call);
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
  ## Memory allocation tracing */

  case sym_function_call: {
    Ast * identifier = ast_schema (n, sym_function_call,
				   0, sym_postfix_expression,
				   0, sym_primary_expression,
				   0, sym_IDENTIFIER);
    if (identifier) {
      static Replacement replacements[] = {
	{ "malloc",  "pmalloc" },
	{ "calloc",  "pcalloc" },
	{ "realloc", "prealloc" },
	{ "free",    "pfree" },
	{ "strdup",  "pstrdup" },
	{ NULL, NULL }
      };
      Replacement * i = replacements;
      AstTerminal * t = ast_terminal (identifier);
      while (i->target) {
	if (!strcmp (t->start, i->target)) {
	  free (t->start);
	  t->start = strdup (i->replacement);
	  assert (n->child[3]);
	  ast_before (n->child[3], ",__func__,__FILE__,__LINE__");
	}
	i++;
      }
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
	ast_traverse (compound_statement, stack, trace_return, data);
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

void ast_traverse (Ast * n, Stack * stack,
		   void func (Ast *, Stack *, void *), void * data)
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
    func (n, stack, data);
    return;
  }
    
  case sym_compound_statement:
  case sym_for_declaration_statement: {
    stack_push (stack, &n);
    for (Ast ** c = n->child; *c; c++)
      ast_traverse (*c, stack, func, data);
    ast_pop_scope (stack, n);
    func (n, stack, data);
    return;
  }
    
  case sym_forin_declaration_statement: {
    stack_push (stack, &n);
    ast_push_declaration (stack, n->child[3]);
    for (Ast ** c = n->child; *c; c++)
      ast_traverse (*c, stack, func, data);
    ast_pop_scope (stack, n);
    func (n, stack, data);
    return;
  }

  case sym_declaration:
    ast_push_declaration (stack, n);

  default:
    if (n->child)
      for (Ast ** c = n->child; *c; c++)
	ast_traverse (*c, stack, func, data);
    func (n, stack, data);
  }
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
  
  ast_traverse ((Ast *) root, root->stack, translate, NULL);

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
