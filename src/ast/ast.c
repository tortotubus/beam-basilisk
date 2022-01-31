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

Ast * ast_parse_expression (const char * expr)
{
  char * s = NULL;
  str_append (s, "void main() {", expr, "}");
  Ast * n = ast_parse (s);  
  free (s);
  Ast * c = ast_schema (n,
			0, sym_translation_unit,
			0, sym_external_declaration,
			0, sym_function_definition,
			2, sym_compound_statement,
			1, sym_block_item_list,
			0, sym_block_item,
			0, sym_statement);
  c = c->child[0];
  ast_detach (c);
  ast_print_graph (n, stderr, 0);
  ast_destroy (n);
  return c;
}

void ast_destroy (Ast * n)
{
  AstRoot * r = ast_root (n);
  if (r) {
    for (int i = 0; i < r->nf; i++)
      free (r->file[i]);
    free (r->file);
  }
  if (n->child) {
    for (Ast ** c = n->child; *c; c++)
      ast_destroy (*c);
    free (n->child);
  }
  else {
    AstTerminal * t = ast_terminal (n);
    free (t->before);
    free (t->start);
    free (t->after);
  }
  free (n);
}

char * ast_line (AstTerminal * t)
{
  static char s[20];
  snprintf (s, 19, "%d", t->line);
  return s;
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

void ast_print_graph (Ast * n, FILE * fp, int indent)
{
  for (int i = 0; i < indent; i++)
    fputc (' ', fp);
  fprintf (fp, "|%s|", symbol_name(n->sym));
  AstTerminal * t = ast_terminal (n);
  if (t)
    fprintf (fp, "%s>\n", t->start);
  else {
    fputc ('\n', fp);
    for (Ast ** c = n->child; *c; c++)
      ast_print_graph (*c, fp, indent + 3);
  }
}

static Ast * vast_schema_internal (Ast * n, va_list ap)
{
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

Ast * ast_declarator_identifier (Ast * declarator)
{
  while (declarator->child) {
    Ast * c = declarator->child[0];
    if (c->sym != sym_init_declarator_list &&
	c->sym != sym_init_declarator &&
	c->sym != sym_declarator &&
	c->sym != sym_direct_declarator &&
	c->sym != sym_generic_identifier &&
	c->sym != sym_IDENTIFIER)
      c = declarator->child[1];
    declarator = c;
  }
  assert (declarator->sym == sym_IDENTIFIER);
  return declarator;
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

