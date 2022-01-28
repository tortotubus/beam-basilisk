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
  //  free (n->before);
  //  free (n->after);
  free (n);
}

char * print_node (char * i, Node * n, FILE * fp)
{
  if (n->start) {
    for (; i < n->start; i++)
      fputc (*i, fp);

#if 1
    fputc ('|', fp);
    fputs (symbol_name (n->kind), fp);
    fputc ('|', fp);
#endif
  
    for (; i <= n->end; i++)
      fputc (*i, fp);

    fputc ('/', fp);
  }
    
  if (n->child && n->child[0]) {
    for (; i < n->child[0]->start; i++)
      fputc (*i, fp);
    for (Node ** c = n->child; *c; c++)
      i = print_node (i, *c, fp);
  }
  return i;
}

void print_node_value (Node * n, FILE * fp)
{  
  for (char * s = n->start; s <= n->end; s++)
    fputc (*s, fp);
}

char * get_node_value (Allocator * alloc, Node * n)
{
  char * name = allocate (alloc, (n->end - n->start + 2)*sizeof (char));
  char * s = name;
  for (char * i = n->start; i <= n->end; i++, s++)
    *s = *i;
  *s = '\0';
  return name;
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

