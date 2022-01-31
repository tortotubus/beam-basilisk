#include <stdio.h>
#include <stdbool.h>

typedef struct _Ast Ast;
struct _Ast {
  int sym;
  Ast ** child, * parent;
};

typedef struct {
  Ast ast;
  char * before, * start, * after;
  char * file;
  int line;
} AstTerminal;

typedef struct {
  Ast ast;
  char * before, * after;
  char ** file;
  int nf;
  void * data;
} AstRoot;

Ast * ast_parse            (const char * code);
void  ast_destroy          (Ast * n);
Ast * ast_parse_expression (const char * expr);
void  ast_replace          (Ast * dst, Ast * src);
void  ast_print            (Ast * n, FILE * fp, bool kind);
void  ast_print_tree       (Ast * n, FILE * fp, const char * indent);

static inline Ast * ast_last_child (Ast * n)
{
  Ast ** c = n->child;
  if (!c)
    return NULL;
  while (*(c + 1)) c++;
  return *c;
}

static inline AstTerminal * ast_left_terminal (Ast * n)
{
  while (n->child)
    n = n->child[0];
  return (AstTerminal *) n;
}

static inline AstTerminal * ast_right_terminal (Ast * n)
{
  while (n->child)
    n = ast_last_child (n);
  return (AstTerminal *) n;
}

Ast * ast_declarator_identifier (Ast * declarator);

Ast * ast_schema_internal (Ast * n, ...);
#define ast_schema(n,...) ast_schema_internal (n, __VA_ARGS__, -1)
Ast * ast_find_internal (Ast * n, ...);
#define ast_find(n,...) ast_find_internal (n, __VA_ARGS__, -1)
Ast * ast_copy_internal (Ast * n, ...);
#define ast_copy(n,...) ast_copy_internal (n, __VA_ARGS__ + 0, -1)

char * str_append_realloc (char * dst, ...);
#define str_append(dst, ...)						\
  do { dst = str_append_realloc (dst, __VA_ARGS__, NULL); } while(0)
char * str_prepend_realloc (char * dst, ...);
#define str_prepend(dst, ...)						\
  do { dst = str_prepend_realloc (dst, __VA_ARGS__, NULL); } while(0)

#define ast_before(n,...) str_append(ast_left_terminal (n)->before, __VA_ARGS__)
#define ast_after(n,...)  str_prepend(ast_right_terminal (n)->after, __VA_ARGS__)
#define ast_terminal(n) ((n)->child ? NULL : (AstTerminal *)(n))
#define ast_root(n) ((n)->parent ? NULL : (AstRoot *)(n))

static inline void ast_hide (AstTerminal * n)
{
  for (char * s = n->start; *s != '\0'; s++)
    *s = ' ';
}

char * ast_line (AstTerminal * t);
#define ast_file_line(n) "\"", ast_terminal(n)->file, \
    "\", ", ast_line(ast_terminal(n))
