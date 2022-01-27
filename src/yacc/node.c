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
  a->maxlen = 1 << 16;
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
  
void node_append (Node * n, Node * m)
{
  Node * i = n;
  while (i->next)
    i = i->next;
  i->next = m;
}

Node * copy_node (Node * n)
{
  Node * a = malloc (sizeof (Node));
  memcpy (a, n, sizeof (Node));
  for (int i = 0; n->child[i]; i++)
    a->child[i] = copy_node (n->child[i]);
  if (n->next)
    a->next = copy_node (n->next);
  return a;
}

void free_node (Node * n)
{
  free (n->before);
  free (n->after);
  for (Node ** c = n->child; *c; c++)
    free_node (*c);
  if (n->next)
    free_node (n->next);
  free (n);
}

void graph_node (Node * n, FILE * fp)
{
  fprintf (fp, "n%p ", n);
#if 0
  if (n->type == TEXT)
    fprintf (fp, "[label=\"TEXT\"];\n");
  else
    fprintf (fp, "[label=\"%c\", shape=box];\n", n->type);
  int i;
  for (i = 0; i < 3; i++)
    if (n->e[i])
      fprintf (fp, "n%p -> n%p;\n", n, n->e[i]);
  for (i = 0; i < 3; i++)
    if (n->e[i])
      print_node (n->e[i], fp);
#endif
}

void print_node (Node * n, FILE * fp, bool kind)
{
  if (kind) {
    fputc ('|', fp);
    fputs (yytname[n->kind], fp);
    fputc ('|', fp);
  }
  if (*n->child && n->before)
    fputs (n->before, fp);
  for (Node ** c = n->child; *c; c++)
    print_node (*c, fp, kind);
  if (n->after)
    fputs (n->after, fp);
  if (n->next)
    print_node (n->next, fp, kind);
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

char * strcpy_range (const char * start, const char * end)
{
  int len = end - start + 1;
  if (len <= 1)
    return NULL;
  else {
    char * dst = malloc (len);
    strncpy (dst, start, len - 1);
    dst[len - 1] = '\0';
    return dst;
  }
}

#include "khash.h"

const int khStrNode = 33;
KHASH_MAP_INIT_STR(khStrNode, Node *)

static khash_t (khStrNode) * types = NULL;

#define kh_set(t,h,s,p) do {				\
    int ret;						\
    khiter_t k = kh_put(t, h, s, &ret);			\
    kh_value (h, k) = p;				\
  } while(0)

static void init_types()
{
  if (types == NULL) {
    types = kh_init (khStrNode);
    kh_set (khStrNode, types, "FILE", NULL);
    kh_set (khStrNode, types, "size_t", NULL);
    kh_set (khStrNode, types, "bool", NULL);
    kh_set (khStrNode, types, "_Attributes", NULL);
  }  
}

void type_definition (Node * n)
{
  init_types();
  
  char * name = calloc (n->after - n->before + 2, sizeof (char));
  for (char * i = n->before, * s = name; i <= n->after; i++, s++)
    *s = *i;

  int ret;
  khiter_t k = kh_put(khStrNode, types, name, &ret);
  kh_value (types, k) = n;
}

int sym_type (const char * name)
{
  init_types();  
  khiter_t k = kh_get (khStrNode, types, name);
  if (k != kh_end (types))
    return TYPEDEF_NAME;
  return IDENTIFIER;
}
