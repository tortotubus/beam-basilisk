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
  for (Node ** c = n->child; *c; c++)
    no_nested_foreach (*c, parent);
  if (n->next)
    no_nested_foreach (n->next, parent);
}

static void foreach_statement (Node * n)
{
  if (n->kind == sym_foreach_statement) {
    str_prepend (n->after, "}end_", strstr (n->before, "foreach"), ";");
    str_append (n->before, "{");    
    for (Node ** c = n->child; *c; c++)
      no_nested_foreach (*c, n->line);
  }
  else
    for (Node ** c = n->child; *c; c++)
      foreach_statement (*c);
  if (n->next)
    foreach_statement (n->next);
}

static void foreach_inner_statement (Node * n)
{
  if (n->kind == sym_foreach_inner_statement) {
    str_prepend (n->after, "}end_", strstr (n->before, "foreach"), ";");
    str_append (n->before, "{");
  }
  for (Node ** c = n->child; *c; c++)
    foreach_inner_statement (*c);
  if (n->next)
    foreach_inner_statement (n->next);
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
  
  Node * root = parse_node (buffer, "");
  if (root) {
    foreach_statement (root);
    foreach_inner_statement (root);
    print_node (root, stdout);
    free_node (root);
  }
  
  free (buffer);
}
