#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ast.h"
#include "symbols.h"

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

static void foreach_statement (Ast * n)
{
  if (n->sym == sym_foreach_statement) {
    Ast * statement = ast_last_child (n);
    if (statement->child[0]->sym == sym_compound_statement)
      ast_after (statement, " end_", ast_left_terminal(n)->start, "();");
    else {
      ast_before (statement, "{");
      ast_after (statement, "} end_", ast_left_terminal(n)->start, "();");
    }
    no_nested_foreach (statement, ast_terminal(n->child[0])->line);
  }
  else if (n->child)
    for (Ast ** c = n->child; *c; c++)
      foreach_statement (*c);
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
	ast_parse_expression ("{ void ret = val; return ret; }");
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

static void various_transforms (Ast * n)
{
  switch (n->sym) {

  /**
  ## Foreach inner statements
  */
    
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
  ## Identifiers
  */

  case sym_generic_identifier: {
    if (n->parent->sym == sym_primary_expression) {
      static Replacement replacements[] = {
	{ "stderr", "ferr" },
	{ NULL, NULL }
      };
      Replacement * i = replacements;
      AstTerminal * identifier = ast_terminal (n->child[0]);
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
  ## Memory allocation tracing
  */

  case sym_function_call: {
    Ast * identifier = ast_schema (n, sym_function_call,
				   0, sym_postfix_expression,
				   0, sym_primary_expression,
				   0, sym_generic_identifier,
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
  ## Function profiling with `trace`
  */

  case sym_function_definition: {
    Ast * trace = ast_schema (n, sym_function_definition,
			      0, sym_declaration_specifiers,
			      0, sym_storage_class_specifier,
			      0, sym_TRACE);
    if (trace) {
      ast_hide (ast_terminal (trace));
      Ast * identifier = ast_declarator_identifier (n->child[1]);
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
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      various_transforms (*c);
}

void ast_symbols (Ast * n)
{
  
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
  
  Ast * root = ast_parse (buffer);

#if 0
  Ast * copy = ast_copy (root, -1);
  ast_destroy (root);
  root = copy;
#endif

  
#if 0
  fp = fopen (".endfor.after", "w");
  fputs (buffer, fp);
  fclose (fp);
#endif
  
  free (buffer);
  
  if (root) {
#if 1
    foreach_statement (root);
    various_transforms (root);
#endif
    ast_print (root, fout, false);
#if 1
    FILE * fp = fopen (".endfor.out", "w");
    ast_print (root, fp, true);
    fclose (fp);
#endif
    
    ast_destroy (root);
  }
}
