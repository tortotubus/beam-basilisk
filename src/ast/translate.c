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

// fixme: replace with scope lookup
static void no_nested_foreach (Ast * n, int parent)
{
  if (n->sym == sym_foreach_statement) {
    int line = ast_terminal(n->child[0])->line;
    fprintf (stderr, "%d: error: foreach*() iterators cannot be nested \n",
	     line);
    fprintf (stderr, "%d: error: parent foreach*() is at line %d\n",
	     line, parent);
    exit (1);
  }
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      no_nested_foreach (*c, parent);
}

static void trace_return (Ast * n,
			  Ast * function_definition,
			  AstTerminal * function_identifier)
{
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
			      ast_get_root(function_definition)->alloc);
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
  else
    if (n->child)
      for (Ast ** c = n->child; *c; c++)
	trace_return (*c, function_definition, function_identifier);
}

typedef struct {
  char * target, * replacement;
} Replacement;

static void translate (Ast * n, Stack * stack)
{
  switch (n->sym) {

  /**
  ## Foreach statements */

  case sym_foreach_statement: {
    Ast * statement = ast_last_child (n);
    if (statement->child[0]->sym == sym_compound_statement)
      ast_after (statement, " end_", ast_left_terminal(n)->start, "();");
    else {
      ast_before (statement, "{");
      ast_after (statement, "} end_", ast_left_terminal(n)->start, "();");
    }
    no_nested_foreach (statement, ast_terminal(n->child[0])->line);
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
      if (compound_statement->child[1]->sym == sym_block_item_list)
	trace_return (compound_statement->child[1], n,
		      ast_terminal (identifier));
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
    fputs ("  pop: ", stderr);
    ast_print_file_line (n, stderr);
#endif
  }
#if 0
  fputs ("scope: ", stderr);
  ast_print_file_line (n, stderr);
#endif
}

Ast * ast_push_function_definition (Stack * stack, Ast * declarator)
{
  stack_push (stack, &declarator);
  Ast * identifier = ast_find (declarator, sym_direct_declarator,
			       0, sym_generic_identifier,
			       0, sym_IDENTIFIER);
  stack_push (stack, &identifier);
  Ast * parameters = ast_find (declarator, sym_parameter_list);
  if (parameters)
    ast_push_declaration (stack, parameters);
  return identifier;
}

void ast_traverse (Ast * n, Stack * stack, void func (Ast *, Stack *))
{
  func (n, stack);

  switch (n->sym) {

  /**
  These should match the corresponding mid-action rules in
  [basilisk.yacc](). */
    
  case sym_function_definition: {
    // fixme: use ast_push_function_definition
    Ast * identifier = ast_find (n, sym_direct_declarator,
				 0, sym_generic_identifier,
				 0, sym_IDENTIFIER);
    stack_push (stack, &identifier);
    stack_push (stack, &identifier);
    Ast * parameters = ast_find (n, sym_parameter_list);
    if (parameters)
      ast_push_declaration (stack, parameters);
    for (Ast ** c = n->child; *c; c++)
      ast_traverse (*c, stack, func);
    ast_pop_scope (stack, identifier);
    return;
  }
    
  case sym_compound_statement:
  case sym_for_declaration_statement: {
    stack_push (stack, &n);
    for (Ast ** c = n->child; *c; c++)
      ast_traverse (*c, stack, func);
    ast_pop_scope (stack, n);
    return;
  }
    
  case sym_forin_declaration_statement: {
    stack_push (stack, &n);
    ast_push_declaration (stack, n->child[3]);
    for (Ast ** c = n->child; *c; c++)
      ast_traverse (*c, stack, func);
    ast_pop_scope (stack, n);
    return;
  }

  case sym_declaration:
    ast_push_declaration (stack, n);

  default:
    if (n->child)
      for (Ast ** c = n->child; *c; c++)
	ast_traverse (*c, stack, func);
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
  
  Ast * root = ast_parse (buffer, NULL);
  free (buffer);
  
  Stack * stack = stack_new (sizeof (Ast *));
  fp = fopen (BASILISK "/ast/defaults.h", "r");
  assert (fp);
  Ast * d = ast_parse_file (fp, NULL);
  fclose (fp);
  ast_push_declaration (stack, d);
  ast_traverse (root, stack, translate);
#if 0
  { // list global declarations
    Ast ** n;
    for (int i = 0; (n = stack_index (stack, i)); i++)
      fprintf (stderr, "global: "), ast_print_file_line (*n, stderr);
  }
#endif
  stack_destroy (stack);
  ast_destroy (d);

  ast_print (root, fout, false);
#if 1
  fp = fopen (".endfor.out", "w");
  ast_print (root, fp, true);
  fclose (fp);
#endif

#if 1
  Ast * main = ast_find_function (root, "main");
  if (main) {
    fp = fopen (".endfor.main", "w");
    ast_print_tree (main, fp, 0);
    fclose (fp);
  }
#endif
  
  ast_destroy (root);
}
