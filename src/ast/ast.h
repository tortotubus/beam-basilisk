#include <stdio.h>
#include <stdbool.h>
#include "allocator.h"
#include "stack.h"

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
  Allocator * alloc;
  Stack * stack;
  bool type_already_specified;
} AstRoot;

AstRoot * ast_parse            (const char * code, AstRoot * parent);
Ast *     ast_parse_expression (const char * expr, AstRoot * parent);
void      ast_destroy          (Ast * n);
AstRoot * ast_parse_file       (FILE * fp, AstRoot * parent);
void      ast_replace          (Ast * dst, Ast * src);
void      ast_print            (Ast * n, FILE * fp, bool kind);
void      ast_print_tree       (Ast * n, FILE * fp, const char * indent);
void      ast_print_file_line  (Ast * n, FILE * fp);
AstRoot * ast_get_root         (Ast * n);
void      ast_identifier_print (Ast * identifier, FILE * fp);
void      ast_stack_print      (Stack * stack, FILE * fp);

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

Ast * ast_is_enumeration_constant (Ast * identifier); // fixme: not used?
Ast * ast_is_typedef              (Ast * identifier);
Ast * ast_identifier_declaration (Stack * stack, const char * identifier);

AstTerminal * ast_terminal_new (Ast * parent, int symbol, const char * start);
#define ast_terminal_new_char(p,s)			\
  (Ast *) ast_terminal_new (p, token_symbol((s)[0]), s)

Ast * ast_new_internal (Ast * parent, ...);
#define ast_new(parent,...) ast_new_internal (parent, __VA_ARGS__, -1)
Ast * ast_schema_internal (Ast * n, ...);
#define ast_schema(n,...) ast_schema_internal (n, __VA_ARGS__, -1)
Ast * ast_find_internal (Ast * n, ...);
#define ast_find(n,...) ast_find_internal (n, __VA_ARGS__, -1)
Ast * ast_copy_internal (Ast * n, ...);
#define ast_copy(n,...) ast_copy_internal (n, __VA_ARGS__ + 0, -1)
Ast * ast_attach_internal (Ast * parent, ...);
#define ast_attach(p,...) ast_attach_internal (p, __VA_ARGS__, NULL)
Ast * ast_new_children_internal (Ast * parent, ...);
#define ast_new_children(p,...) ast_new_children_internal (p, __VA_ARGS__, NULL)

extern Ast * const ast_placeholder;

static inline void ast_set_child (Ast * parent, int index, Ast * child)
{
  if (child->parent && child->parent != parent) {
    Ast * oldparent = child->parent;
    if (oldparent->child) {
      Ast ** c;
      for (c = oldparent->child; *c && *c != child; c++);
      if (*c == child)
	*c = ast_placeholder;
    }
  }  
  parent->child[index] = child;
  child->parent = parent;
}

char * str_append_realloc (char * dst, ...);
#define str_append(dst, ...)						\
  do { dst = str_append_realloc (dst, __VA_ARGS__, NULL); } while(0)
char * str_prepend_realloc (char * dst, ...);
#define str_prepend(dst, ...)						\
  do { dst = str_prepend_realloc (dst, __VA_ARGS__, NULL); } while(0)

#define ast_before(n,...) str_append(ast_left_terminal (n)->before, __VA_ARGS__)
#define ast_after(n,...)  str_append(ast_right_terminal (n)->after, __VA_ARGS__)
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

/**
# Grammar-specific functions */

void  ast_push_declaration         (Stack * stack, Ast * declaration);
Ast * ast_push_function_definition (Stack * stack, Ast * declarator);
void  ast_pop_scope                (Stack * stack, Ast * scope);

typedef struct {
  const char * name;
  int line;
} AstFile;

void  ast_traverse (Ast * n, Stack * stack, AstFile * file,
		    void func (Ast *, Stack *, AstFile *, void *),
		    void * data);
#define foreach_item(list, index, item)					\
  for (Ast * _list = list, * item = _list ?				\
	 (_list->child[1] ? _list->child[index] : _list->child[0]) : NULL; \
       item;								\
       _list = _list->child[1] ? _list->child[0] : NULL,		\
	 item = _list ? (_list->child[1] ? _list->child[index] :	\
			 _list->child[0]) : NULL			\
       )
void ast_set_char (Ast * n, int c);
void ast_remove (Ast * n, AstTerminal * before);
void ast_check (Ast * n);
