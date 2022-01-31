#include <assert.h>
#include "parser.h"
#include "basilisk.h"
#include "symbols.h"

#include "khash.h"

const int khStrNode = 33;
KHASH_MAP_INIT_STR(khStrNode, Ast *)

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

static char * get_node_value (Allocator * alloc, AstTerminal * n)
{
  char * name = allocate (alloc, (n->after - n->start + 2)*sizeof (char));
  char * s = name;
  for (char * i = n->start; i <= n->after; i++, s++)
    *s = *i;
  *s = '\0';
  return name;
}

void type_definition (Allocator * alloc, Ast * declaration)
{
  Ast * specifiers = declaration->child[0],
    * declarator = declaration->child[1];
  if (ast_schema (specifiers, sym_declaration_specifiers,
		  0, sym_storage_class_specifier,
		  0, sym_TYPEDEF)) {
    declarator = ast_declarator_identifier (declarator);
#if 0
    fprintf (stderr, "%d: typedef ", declarator->line);
    print_node_value (declarator, stderr);
    fputc ('\n', stderr);
#endif
    init_types();
    
    char * name = get_node_value (alloc, ast_terminal (declarator));
    int ret;
    khiter_t k = kh_put(khStrNode, types, name, &ret);
    kh_value (types, k) = declaration;
  }
}

int sym_type (const char * name)
{
  init_types();  
  khiter_t k = kh_get (khStrNode, types, name);
  if (k != kh_end (types))
    return TYPEDEF_NAME;
  return IDENTIFIER;
}

void typedef_cleanup()
{
  if (types) {
    kh_destroy (khStrNode, types);
    types = NULL;
  }
}
