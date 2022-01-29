#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

#include "node.h"
#include "basilisk.h"
#include "symbols.h"

struct _Allocator {
  void * m;
  long len, maxlen;
  Allocator * next;
};

Allocator * new_allocator()
{
  Allocator * a = calloc (1, sizeof (Allocator));
  a->maxlen = 1 << 22;
  a->m = calloc (a->maxlen, 1);
  return a;
}

void * allocate (Allocator * a, long size)
{
  Allocator * last = a;
  while (a && a->len + size >= a->maxlen)
    last = a, a = a->next;
  if (a == NULL)
    a = last->next = new_allocator();
  assert (a->len + size < a->maxlen);
  void * p = (void *)(((char *)a->m) + a->len);
  a->len += size;
  return p;
}

void free_allocator (Allocator * a)
{
  free (a->m);
  if (a->next) free_allocator (a->next);
  free (a);
}

void free_node (Node * n)
{
  if (n->child) {
    for (Node ** c = n->child; *c; c++)
      free_node (*c);
    free (n->child);
  }
  free (n->before);
  free (n->start);
  free (n->after);
  free (n);
}

char * node_line (Node * n)
{
  static char s[20];
  snprintf (s, 19, "%d", n->line);
  return s;
}

void print_node (Node * n, FILE * fp, bool kind)
{
  if (n->before)
    fputs (n->before, fp);

  if (n->start) {
    if (kind) {
      fputc ('|', fp);
      fputs (symbol_name (n->kind), fp);
      fputc ('|', fp);
    }
    fputs (n->start, fp);
    if (kind)
      fputc ('/', fp);
  }

  if (n->child)
    for (Node ** c = n->child; *c; c++)
      print_node (*c, fp, kind);

  if (n->after)
    fputs (n->after, fp);
}

Node * node_schema_internal (Node * n, ...)
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
    int kind = va_arg(ap, int);
    if (n->kind != kind)
      return NULL;
    c = va_arg(ap, int);
  }
  va_end (ap);
  return n;
}

Node * declarator_identifier (Node * declarator)
{
  while (declarator->child) {
    Node * c = declarator->child[0];
    if (c->kind != sym_init_declarator_list &&
	c->kind != sym_init_declarator &&
	c->kind != sym_declarator &&
	c->kind != sym_direct_declarator &&
	c->kind != sym_generic_identifier &&
	c->kind != sym_IDENTIFIER)
      c = declarator->child[1];
    declarator = c;
  }
  assert (declarator->kind == sym_IDENTIFIER);
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

