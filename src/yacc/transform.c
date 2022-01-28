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
}

static void foreach_inner_statement (Node * n)
{
  if (n->kind == sym_foreach_inner_statement) {
    str_prepend (n->after, "}end_", strstr (n->before, "foreach"), ";");
    str_append (n->before, "{");
  }
}

static void variables (Node * n)
{
  if (n->kind == sym_generic_identifier) {
    fprintf (stderr, ".endfor.out:%d: %s\n", n->line, n->after);
  }
}

static void do_transform (Node * n, void transform (Node * n))
{
  transform (n);
  for (Node ** c = n->child; *c; c++)
    do_transform (*c, transform);
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
  free (buffer);
  
  print_node (root, stdout, true);
  free_node (root);
  exit (0);
  
  if (root) {

    foreach_statement (root);
    do_transform (root, foreach_inner_statement);
    do_transform (root, variables);
    print_node (root, fout, false);

#if 1
    FILE * fp = fopen (".endfor.out", "w");
    print_node (root, fp, true);
    fclose (fp);
#endif
    
    free_node (root);
  }
  
  free (buffer);
}
