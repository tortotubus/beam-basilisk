#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "node.h"
#include "symbols.h"

static void no_nested_foreach (Node * n, int parent)
{
  if (n->kind == sym_foreach_statement) {
    fprintf (stderr, "%d: error: foreach*() iterators cannot be nested \n",
	     n->line);
    fprintf (stderr, "%d: error: parent foreach*() is at line %d\n",
	     n->line, parent);
    exit (1);
  }
  if (n->child)
    for (Node ** c = n->child; *c; c++)
      no_nested_foreach (*c, parent);
}

static void foreach_statement (Node * n)
{
  if (n->kind == sym_foreach_statement) {
    Node * statement = node_last_child (n);
    if (statement->child[0]->kind == sym_compound_statement)
      str_prepend (statement->after, " end_", n->child[0]->start, "();");
    else {
      str_append (statement->before, "{");
      str_prepend (statement->after, "} end_", n->child[0]->start, "();");
    }
    no_nested_foreach (statement, n->line);
  }
  else if (n->child)
    for (Node ** c = n->child; *c; c++)
      foreach_statement (*c);
}

typedef struct {
  char * target, * replacement;
} Replacement;

static void various_transforms (Node * n)
{
  switch (n->kind) {

  /**
  ## Foreach inner statements
  */
    
  case sym_foreach_inner_statement: {
    Node * statement = node_last_child (n);
    if (statement->child[0]->kind == sym_compound_statement)
      str_prepend (statement->after, " end_", n->child[0]->start, "();");
    else {
      str_append (statement->before, "{");
      str_prepend (statement->after, "} end_", n->child[0]->start, "();");
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
    Node * identifier = n->child[0];
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
    Node * identifier = node_schema (n,
				     0, sym_postfix_expression,
				     0, sym_primary_expression,
				     0, sym_generic_identifier,
				     0, sym_IDENTIFIER,
				     -1);
    if (identifier) {
      static Replacement replacements[] = {
	{ "malloc",  "pmalloc" },
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
	  str_append (n->child[3]->before, ",__func__,__FILE__,__LINE__");
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
    Node * trace = node_schema (n,
				0, sym_declaration_specifiers,
				0, sym_storage_class_specifier,
				0, sym_TRACE,
				-1);
    if (trace) {
      for (char * s = trace->start; *s != '\0'; s++)
	*s = ' ';
      Node * identifier = declarator_identifier (n->child[1]);
      Node * compound_statement = node_last_child (n);
      char line[10]; snprintf (line, 9, "%d", identifier->line);
      str_prepend (compound_statement->child[0]->after,
		   " trace (\"", identifier->start, "\", \"file\", ",
		   line, ");");
      Node * end = node_last_child (compound_statement);
      snprintf (line, 9, "%d", end->line);
      str_append (end->before,
		  " end_trace (\"", identifier->start,
		  "\", \"file\", ", line, ");");
    }
    break;
  }
    
  }
  if (n->child)
    for (Node ** c = n->child; *c; c++)
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
  
  Node * root = parse_node (buffer);
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
