#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

#include "parser.h"
#include "basilisk.h"
#include "symbols.h"

static void free_children (Ast * n)
{
  if (n->child) {
    for (Ast ** c = n->child; *c; c++)
      free_children (*c);
    free (n->child);
  }
  free (n->before);
  free (n->start);
  free (n->after);
  free (n);
}

void ast_destroy (Ast * root)
{
  AstRoot * r = root->data;
  if (r) {
    for (int i = 0; i < r->nf; i++)
      free (r->file[i]);
    free (r->file);
    free (r);
  }
  free_children (root);
}

char * ast_line (Ast * n)
{
  static char s[20];
  snprintf (s, 19, "%d", n->line);
  return s;
}

void ast_print (Ast * n, FILE * fp, bool sym)
{
  if (n->before)
    fputs (n->before, fp);

  if (n->start) {
    if (sym) {
      fputc ('|', fp);
      fputs (symbol_name (n->sym), fp);
      fputc ('|', fp);
    }
    fputs (n->start, fp);
    if (sym)
      fputc ('/', fp);
  }

  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      ast_print (*c, fp, sym);

  if (n->after)
    fputs (n->after, fp);
}

Ast * ast_schema_internal (Ast * n, ...)
{
  va_list ap;
  va_start (ap, n);
  int c = va_arg(ap, int);
  while (c >= 0) {
    if (!n->child)
      return NULL;
    int i;
    for (i = 0; i <= c && n->child[i]; i++);
    if (i <= c)
      return NULL;
    n = n->child[c];
    int sym = va_arg(ap, int);
    if (n->sym != sym)
      return NULL;
    c = va_arg(ap, int);
  }
  va_end (ap);
  return n;
}

Ast * ast_declarator_identifier (Ast * declarator)
{
  while (declarator->child) {
    Ast * c = declarator->child[0];
    if (c->sym != sym_init_declarator_list &&
	c->sym != sym_init_declarator &&
	c->sym != sym_declarator &&
	c->sym != sym_direct_declarator &&
	c->sym != sym_generic_identifier &&
	c->sym != sym_IDENTIFIER)
      c = declarator->child[1];
    declarator = c;
  }
  assert (declarator->sym == sym_IDENTIFIER);
  return declarator;
}
    
char * str_append_realloc (char * src, ...)
{
  va_list ap;
  va_start (ap, src);
  char * i = va_arg(ap, char *);
  int len = src ? strlen(src) : 0;
  while (i) {
    len += strlen (i);
    i = va_arg(ap, char *);
  }
  va_end (ap);

  if (len < 1)
    return NULL;
  
  char * dst = realloc (src, len + 1);
  if (!src)
    dst[0] = '\0';
  
  va_start (ap, src);
  i = va_arg(ap, char *);
  while (i) {
    strcat (dst, i);
    i = va_arg(ap, char *);
  }
  va_end (ap);

  return dst;
}

char * str_prepend_realloc (char * src, ...)
{
  va_list ap;
  va_start (ap, src);
  char * i = va_arg(ap, char *);
  int len = src ? strlen(src) : 0;
  while (i) {
    len += strlen (i);
    i = va_arg(ap, char *);
  }
  va_end (ap);

  if (len < 1)
    return NULL;
  
  char * dst = malloc (len + 1);
  dst[0] = '\0';

  va_start (ap, src);
  i = va_arg(ap, char *);
  while (i) {
    strcat (dst, i);
    i = va_arg(ap, char *);
  }
  va_end (ap);

  if (src)
    strcat (dst, src);

  free (src);
  return dst;
}

