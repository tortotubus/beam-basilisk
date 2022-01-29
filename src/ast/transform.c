#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ast.h"
#include "symbols.h"

static void no_nested_foreach (Ast * n, int parent)
{
  if (n->sym == sym_foreach_statement) {
    fprintf (stderr, "%d: error: foreach*() iterators cannot be nested \n",
	     n->line);
    fprintf (stderr, "%d: error: parent foreach*() is at line %d\n",
	     n->line, parent);
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
      ast_after (statement, " end_", n->child[0]->start, "();");
    else {
      ast_before (statement, "{");
      ast_after (statement, "} end_", n->child[0]->start, "();");
    }
    no_nested_foreach (statement, n->line);
  }
  else if (n->child)
    for (Ast ** c = n->child; *c; c++)
      foreach_statement (*c);
}

static void trace_return (Ast * n, Ast * identifier)
{
  if (n->sym == sym_jump_statement && n->child[0]->sym == sym_RETURN) {
    Ast * ret = n->child[0];
    if (!n->child[2]) {
      ast_before (ret,
		  "{ end_trace (\"", identifier->start, "\", ",
		  ast_file_line (ret), "); ");
      ast_after (n->child[1], " }");
    }
    // else ... // fixme
  }
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      trace_return (*c, identifier);
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
      ast_after (statement, " end_", n->child[0]->start, "();");
    else {
      ast_before (statement, "{");
      ast_after (statement, "} end_", n->child[0]->start, "();");
    }
    break;
  }
    
  /**
  ## Identifiers
  */

  case sym_generic_identifier: {
    static Replacement replacements[] = {
      { "stderr", "ferr" },
      { NULL, NULL }
    };
    Replacement * i = replacements;
    Ast * identifier = n->child[0];
    while (i->target) {
      if (!strcmp (identifier->start, i->target)) {
	free (identifier->start);
	identifier->start = strdup (i->replacement);
      }
      i++;
    }
    break;
  }

  /**
  ## Memory allocation tracing
  */

  case sym_function_call: {
    Ast * identifier = ast_schema (n,
				   0, sym_postfix_expression,
				   0, sym_primary_expression,
				   0, sym_generic_identifier,
				   0, sym_IDENTIFIER,
				   -1);
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
      while (i->target) {
	if (!strcmp (identifier->start, i->target)) {
	  free (identifier->start);
	  identifier->start = strdup (i->replacement);
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
    Ast * trace = ast_schema (n,
			      0, sym_declaration_specifiers,
			      0, sym_storage_class_specifier,
			      0, sym_TRACE,
			      -1);
    if (trace) {
      ast_hide (trace);
      Ast * identifier = ast_declarator_identifier (n->child[1]);
      Ast * compound_statement = ast_last_child (n);
      ast_after (compound_statement->child[0],
		 " trace (\"", identifier->start, "\", ",
		 ast_file_line (identifier), "); ");
      Ast * end = ast_last_child (compound_statement);
      ast_before (end,
		  " end_trace (\"", identifier->start, "\", ",
		  ast_file_line (end), "); ");
      if (compound_statement->child[1]->sym == sym_block_item_list)
	trace_return (compound_statement->child[1], identifier);
    }
    break;
  }
    
  }
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      various_transforms (*c);
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

#if 0
  FILE * fp = fopen (".endfor", "w");
  fputs (buffer, fp);
  fclose (fp);
#endif
  
  Ast * root = parse_node (buffer);
  free (buffer);
  
  if (root) {
    foreach_statement (root);
    various_transforms (root);
    print_node (root, fout, false);
#if 0
    FILE * fp = fopen (".endfor.out", "w");
    print_node (root, fp, false);
    fclose (fp);
#endif
    
    free_node (root);
  }
}
