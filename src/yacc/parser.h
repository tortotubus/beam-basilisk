#include <string.h>
#include <assert.h>
#include <stdlib.h>
  
#include "node.h"
#include "allocator.h"

typedef struct {
  char ** file;
  int nf;
  Allocator * alloc;
} NodeRoot;

void type_definition (Allocator * alloc, Node * declaration);
void typedef_cleanup(); 
int  yylex (Node ** lvalp, NodeRoot * parse);
void yyerror (NodeRoot * parse, Node ** root, char const *);
int  yylex_destroy();
int  token_symbol (int token);
int  sym_type (const char * name);
