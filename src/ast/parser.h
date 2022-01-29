#include <string.h>
#include <assert.h>
#include <stdlib.h>
  
#include "ast.h"
#include "allocator.h"

typedef struct {
  char ** file;
  int nf;
  Allocator * alloc;
} AstRoot;

void type_definition (Allocator * alloc, Ast * declaration);
void typedef_cleanup(); 
int  yylex (Ast ** lvalp, AstRoot * parse);
void yyerror (AstRoot * parse, Ast ** root, char const *);
int  yylex_destroy();
int  token_symbol (int token);
int  sym_type (const char * name);
