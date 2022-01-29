#include <stdio.h>
#include <stdbool.h>

typedef struct _Node Node;
struct _Node {
  int kind, line;
  char * before, * start, * after, * file;
  Node ** child, * parent;
  void * data;
};

Node * parse_node   (const char * code);
void   free_node    (Node * n);
void   print_node   (Node * n, FILE * fp, bool kind);

static inline Node * node_last_child (Node * n)
{
  Node ** c = n->child;
  if (!c)
    return NULL;
  while (*(c + 1)) c++;
  return *c;
}

Node * declarator_identifier (Node * declarator);

Node * node_schema_internal (Node * n, ...);
#define node_schema(n,...) node_schema_internal (n, __VA_ARGS__, -1)

char * str_append_realloc (char * dst, ...);
#define str_append(dst, ...)						\
  do { dst = str_append_realloc (dst, __VA_ARGS__, NULL); } while(0)
char * str_prepend_realloc (char * dst, ...);
#define str_prepend(dst, ...)						\
  do { dst = str_prepend_realloc (dst, __VA_ARGS__, NULL); } while(0)

#define node_before(n,...) str_append((n)->before, __VA_ARGS__)
#define node_after(n,...) str_prepend((n)->after, __VA_ARGS__)

static inline void node_hide (Node * n)
{
  for (char * s = n->start; *s != '\0'; s++)
    *s = ' ';
}

char * node_line (Node * n);
#define node_file_line(n) "\"", n->file, "\", ", node_line(n)
