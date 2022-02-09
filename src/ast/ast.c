#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

#include "parser.h"
#include "basilisk.h"
#include "symbols.h"

static void cancel_file_line (Ast * n)
{
  AstTerminal * t = ast_terminal(n);
  if (t)
    t->file = NULL, t->line = 0;
  else
    for (Ast ** c = n->child; *c; c++)
      cancel_file_line (*c);
}

void ast_detach (Ast * n)
{
  assert (n->parent);
  Ast ** c;
  for (c = n->parent->child; *c && *c != n; c++);
  assert (*c == n);
  for (; *c; c++)
    *c = *(c + 1);
  n->parent = n;
  cancel_file_line (n);
}

void ast_destroy (Ast * n)
{
  if (n->child)
    for (Ast ** c = n->child; *c; c++)
      ast_destroy (*c);
  else {
    AstTerminal * t = ast_terminal (n);
    free (t->before);
    free (t->start);
    free (t->after);
  }
  AstRoot * r = ast_root (n);
  if (r) {
    stack_destroy (r->stack);
    for (int i = 0; i < r->nf; i++)
      free (r->file[i]);
    free (r->file);
    if (r->alloc)
      free_allocator (r->alloc);
  }
}

char * ast_line (AstTerminal * t)
{
  static char s[20];
  snprintf (s, 19, "%d", t->line);
  return s;
}

AstRoot * ast_get_root (Ast * n)
{
  Ast * root = n;
  while (root->parent)
    root = root->parent;
  return ast_root (root);
}

void ast_print (Ast * n, FILE * fp, bool sym)
{
  AstTerminal * t = ast_terminal (n);
  if (t) {
    if (t->before)
      fputs (t->before, fp);
    if (sym) {
      fputc ('|', fp);
      fputs (symbol_name (n->sym), fp);
      fputc ('|', fp);
    }
    fputs (t->start, fp);
    if (sym)
      fputc ('/', fp);
    if (t->after)
      fputs (t->after, fp);
  }
  else {
    AstRoot * r = ast_root (n);
    if (r && r->before)
      fputs (r->before, fp);    
    for (Ast ** c = n->child; *c; c++)
      ast_print (*c, fp, sym);
    if (r && r->after)
      fputs (r->after, fp);
  }
}

void ast_print_file_line (Ast * n, FILE * fp)
{
  assert (n);
  AstTerminal * t = ast_left_terminal (n);
  assert (t);
  fprintf (fp, "%s:%d: %s\n", t->file, t->line,
	   ast_terminal(n) ? t->start : symbol_name (n->sym));
}

static void print_child_tree (Ast * n, FILE * fp,
			      const char * indent, bool isLast)
{
  char * ind;
  if (indent) {
    fputs (indent, fp);
    ind = strdup (indent);
  }
  else
    ind = strdup ("");
    
  if (isLast) {
    fputs ("└─", fp);
    str_append (ind, "  ");
  }
  else {
    fputs ("├─", fp);
    str_append (ind, "│ ");
  }
  ast_print_tree (n, fp, ind);
  free (ind);
}

void ast_print_tree (Ast * n, FILE * fp, const char * indent)
{
  fprintf (fp, "%s", symbol_name (n->sym));
  AstTerminal * t = ast_terminal (n);
  if (t)
    fprintf (fp, " %s\n", t->start);
  else {
    fputc ('\n', fp);
    for (Ast **c = n->child; *c; c++)
      print_child_tree (*c, fp, indent, *(c + 1) == NULL);
  }
}

static Ast * vast_schema_internal (Ast * n, va_list ap)
{
  int sym = va_arg(ap, int);
  if (n->sym != sym)
    return NULL;
  int c = va_arg(ap, int);
  while (c >= 0) {
    if (!n->child)
      return NULL;
    int i;
    for (i = 0; i <= c && n->child[i]; i++);
    if (i <= c)
      return NULL;
    n = n->child[c];
    int sym = va_arg(ap, int);
    if (n->sym != sym)
      return NULL;
    c = va_arg(ap, int);
  }
  return n;
}

Ast * ast_schema_internal (Ast * n, ...)
{
  va_list ap;
  va_start (ap, n);
  n = vast_schema_internal (n, ap);
  va_end (ap);
  return n;
}

static Ast * vast_find_internal (Ast * n, va_list ap)
{
  va_list bp;
  va_copy (bp, ap);
  Ast * found = vast_schema_internal (n, bp);
  va_end (bp);
  if (found)
    return found;
  if (!ast_terminal(n))
    for (Ast ** c = n->child; *c; c++)
      if ((found = vast_find_internal (*c, ap)))
	return found;
  return NULL;
}

Ast * ast_find_internal (Ast * n, ...)
{
  va_list ap;
  va_start (ap, n);
  n = vast_find_internal (n, ap);
  va_end (ap);
  return n;
}

static Ast * copy_ast (Ast * dst, const Ast * src)
{
  dst->sym = src->sym;
  dst->child = NULL;
  dst->parent = dst;
  return dst;
}

static Ast * terminal_copy (const AstTerminal * src,
			    const AstRoot * dst_root, const AstRoot * src_root)
{
  AstTerminal * dst =
    (AstTerminal *) copy_ast (allocate (dst_root->alloc, sizeof (AstTerminal)),
			      (Ast *)src);
  dst->before = src->before ? strdup (src->before) : NULL;
  dst->start = strdup (src->start);
  dst->after = src->after ? strdup (src->after) : NULL;
  dst->line = src->line;
  if (dst_root) {
    int i;
    for (i = 0; i < src_root->nf && src->file != src_root->file[i]; i++);
    assert (src->file == src_root->file[i]);
    dst->file = dst_root->file[i];
  }
  return (Ast *)dst;
}

static Ast * root_copy (const AstRoot * src)
{
  Allocator * alloc = new_allocator();
  AstRoot * dst = (AstRoot *) copy_ast (allocate (alloc, sizeof (AstRoot)),
					(Ast *)src);
  dst->alloc = alloc;
  dst->before = src->before ? strdup (src->before) : NULL;
  dst->after = src->after ? strdup (src->after) : NULL;
  if (src->nf) {
    dst->file = malloc (src->nf*sizeof(char *));
    dst->nf = src->nf;
    for (int i = 0; i < dst->nf; i++)
      dst->file[i] = strdup (src->file[i]);
  }
  else
    dst->file = NULL, dst->nf = 0;
  dst->stack = NULL;
  ((Ast *)dst)->parent = NULL;
  return (Ast *)dst;
}

static Ast * vast_copy_internal (Ast * n, va_list ap, bool * found,
				 AstRoot * dst_root, const AstRoot * src_root)
{
  Ast * c = NULL;
  AstRoot * r = ast_root (n);
  if (r) {
    c = root_copy (r);
    src_root = r;
    dst_root = ast_root (c);
  }
  AstTerminal * t = ast_terminal (n);
  if (t)
    c = terminal_copy (t, dst_root, src_root);
  else if (!c)
    c = copy_ast (allocate (dst_root->alloc, sizeof (Ast)), n);

  va_list cp;
  va_copy (cp, ap);
  if (vast_schema_internal (n, cp))
    *found = true;
  va_end (cp);

  if (!t) {
    int len = 0;
    for (Ast ** i = n->child; *i; i++, len++);
    c->child = allocate (dst_root->alloc, (len + 1)*sizeof (Ast *));
    len = 0;
    for (Ast ** i = n->child, ** j = c->child;
	 *i && !(*found); i++, j++, len++) {
      *j = vast_copy_internal (*i, ap, found, dst_root, src_root);
      (*j)->parent = c;
    }
    c->child[len] = NULL;
  }
  return c;
}

Ast * ast_copy_internal (Ast * n, ...)
{
  va_list ap;
  va_start (ap, n);
  bool found = false;
  AstRoot * src_root = ast_get_root (n);
  n = vast_copy_internal (n, ap, &found, src_root, src_root);
  va_end (ap);
  return n;
}

void ast_replace (Ast * dst, Ast * src)
{
  assert (dst->parent);
  if (src->parent && src->parent != src)
    ast_detach (src);
  Ast ** c;
  for (c = dst->parent->child; *c && *c != dst; c++);
  assert (*c == dst);
  *c = src;
  src->parent = dst->parent;
  dst->parent = dst;
  ast_destroy (dst);
}

Ast * ast_parse_expression (const char * expr, Allocator * alloc)
{
  char * s = NULL;
  str_append (s, "void main() {", expr, "}");
  Ast * n = ast_parse (s, alloc);
  free (s);
  if (n) {
    Ast * c = ast_find (n, sym_statement)->child[0];
    ast_detach (c);
    ast_destroy (n);
    n = c;
  }
  return n;
}

Ast * ast_parse_file (FILE * fp, Allocator * alloc)
{
  char * buffer = NULL;
  size_t len = 0, maxlen = 0;
  int c;
  while ((c = fgetc (fp)) != EOF) {
    if (len >= maxlen) {
      maxlen += 4096;
      buffer = realloc (buffer, maxlen);      
    }
    buffer[len++] = c;
  }
  if (len >= maxlen) {
    maxlen++;
    buffer = realloc (buffer, maxlen);      
  }
  buffer[len++] = '\0';
  Ast * root = ast_parse (buffer, alloc);
  free (buffer);
  return root;
}

Ast * ast_identifier_declaration (Stack * stack, const char * identifier)
{
  Ast ** d;
  for (int i = 0; (d = stack_index (stack, i)); i++)
    if (*d && (*d)->sym == sym_IDENTIFIER) {

      /**
      WARNING: this assumes that the "after" string is never modified
      for the declaration identifiers stored in the stack. */

      if (!ast_terminal(*d)->after) {
	if (!strcmp (ast_terminal(*d)->start, identifier))
	  return *d;
      }

      /**
      If 'after' is defined, we assume that the function is called
      from the [lexer](tokens.lex) and that 'after' is the last
      character of the declaration identifier (as set by the
      lexer). */
      
      else {
	char * s = ast_terminal(*d)->start, * end = ast_terminal(*d)->after;
	const char * i = identifier;
	for (; *i != '\0' && s <= end && *s == *i; s++, i++);
	if (*i == '\0' && s == end + 1)
	  return *d;
      }
    }
  return NULL;
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
  if (!src)
    dst[0] = '\0';
  
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
