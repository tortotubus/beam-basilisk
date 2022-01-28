#include <stdio.h>
#include <stdbool.h>

typedef struct _Allocator Allocator;  
  
Allocator * new_allocator();
void * allocate (Allocator * a, long size);
void free_allocator (Allocator * a);

#define CMAX 5  
typedef struct _Node Node;
struct _Node {
  int kind, line;
  char * start, * end;
  char * before, * after;
  Node ** child, * parent;
};

void free_node (Node * n);
char * print_node (char * i, Node * n, FILE * fp);
void print_node_value (Node * n, FILE * fp);
char * get_node_value (Allocator * alloc, Node * n);

Node * parse_node (char * code, const char * fname);

char * str_append_realloc (char * dst, ...);
#define str_append(dst, ...)						\
  do { dst = str_append_realloc (dst, __VA_ARGS__, NULL); } while(0)
char * str_prepend_realloc (char * dst, ...);
#define str_prepend(dst, ...)						\
  do { dst = str_prepend_realloc (dst, __VA_ARGS__, NULL); } while(0)

