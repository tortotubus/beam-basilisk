#include <stdio.h>
#include <stdbool.h>

typedef struct _Ast Ast;
struct _Ast {
  int sym, line;
  char * before, * start, * after, * file;
  Ast ** child, * parent;
  void * data;
};

Ast * ast_parse   (const char * code);
void  ast_destroy (Ast * n);
void  ast_print   (Ast * n, FILE * fp, bool kind);

static inline Ast * ast_last_child (Ast * n)
{
  Ast ** c = n->child;
  if (!c)
    return NULL;
  while (*(c + 1)) c++;
  return *c;
}

Ast * ast_declarator_identifier (Ast * declarator);

Ast * ast_schema_internal (Ast * n, ...);
#define ast_schema(n,...) ast_schema_internal (n, __VA_ARGS__, -1)

char * str_append_realloc (char * dst, ...);
#define str_append(dst, ...)						\
  do { dst = str_append_realloc (dst, __VA_ARGS__, NULL); } while(0)
char * str_prepend_realloc (char * dst, ...);
#define str_prepend(dst, ...)						\
  do { dst = str_prepend_realloc (dst, __VA_ARGS__, NULL); } while(0)

#define ast_before(n,...) str_append((n)->before, __VA_ARGS__)
#define ast_after(n,...) str_prepend((n)->after, __VA_ARGS__)

static inline void ast_hide (Ast * n)
{
  for (char * s = n->start; *s != '\0'; s++)
    *s = ' ';
}

char * ast_line (Ast * n);
#define ast_file_line(n) "\"", n->file, "\", ", ast_line(n)
