#include <stdio.h>

typedef struct _Allocator Allocator;  
  
Allocator * new_allocator();
void * allocate (Allocator * a, long size);
void free_allocator (Allocator * a);

#define CMAX 5  
typedef struct _Node Node;
struct _Node {
  int type, kind, line;
  char * before, * after;
  Node * next, * child[CMAX + 1];
};

void node_append (Node * n, Node * m);
Node * copy_node (Node * n);
void free_node (Node * n);
void graph_node (Node * n, FILE * fp);
void print_node (Node * n, FILE * fp);
void print_graph (Node * n, FILE * fp, int indent);

Node * parse_node (char * code, const char * fname);

char * str_append_realloc (char * dst, ...);
#define str_append(dst, ...)						\
  do { dst = str_append_realloc (dst, __VA_ARGS__, NULL); } while(0)
char * str_prepend_realloc (char * dst, ...);
#define str_prepend(dst, ...)						\
  do { dst = str_prepend_realloc (dst, __VA_ARGS__, NULL); } while(0)
char * strcpy_range (const char * start, const char * end);
