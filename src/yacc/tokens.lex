%option bison-bridge
%option nounput
%option noyywrap
%option yylineno

%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%{
#include <stdio.h>
#include <assert.h>
#include "node.h"
#include "basilisk.h"

#define YYSTYPE Node *
#define YY_DECL int yylex (YYSTYPE * yylval_param, Allocator * alloc)

extern void yyerror (const char * s);
extern int token_symbol (int token);
extern int sym_type (const char * name);
 
static void comment (void);
static void preproc (void);
static void bpreproc (void);
static void ompreproc (void);
static int check_type(void);

static Node * new_node (Allocator * alloc,
			int token, int line, char * start, char * end)
{
  Node * n = allocate (alloc, sizeof(Node));
  memset (n, 0, sizeof(Node));
  n->kind = token_symbol (token);
  n->line = line;
  n->start = start;
  n->after = end;
  return n;
}

#define CNODE()								\
  *yylval = new_node (alloc, yytext[0], yylineno, yytext, yytext);	\
  return yytext[0];
  
#define SNODE(t) 							\
  *yylval = new_node (alloc, t, yylineno, yytext, yytext + strlen(yytext) - 1);	\
  return t;

%}
	 
%%

"/*"                                    { comment(); }
"//".*                                  { /* consume //-comment */ }
^[ \t]*#	                        { preproc(); }
^[ \t]*@[ \t]*def[ \t].*                { bpreproc(); }
^[ \t]*@.*
^[ \t]*OMP[ \t]*\(	                { ompreproc(); }
	 
"auto"					{ SNODE(AUTO); }
"break"					{ SNODE(BREAK); }
"case"					{ SNODE(CASE); }
"char"					{ SNODE(CHAR); }
"const"					{ SNODE(CONST); }
"continue"				{ SNODE(CONTINUE); }
"default"				{ SNODE(DEFAULT); }
"do"					{ SNODE(DO); }
"double"				{ SNODE(DOUBLE); }
"else"					{ SNODE(ELSE); }
"enum"					{ SNODE(ENUM); }
"extern"				{ SNODE(EXTERN); }
"float"					{ SNODE(FLOAT); }
"for"					{ SNODE(FOR); }
"goto"					{ SNODE(GOTO); }
"if"					{ SNODE(IF); }
"inline"				{ SNODE(INLINE); }
"int"					{ SNODE(INT); }
"long"					{ SNODE(LONG); }
"register"				{ SNODE(REGISTER); }
"restrict"				{ SNODE(RESTRICT); }
"return"				{ SNODE(RETURN); }
"short"					{ SNODE(SHORT); }
"signed"				{ SNODE(SIGNED); }
"sizeof"				{ SNODE(SIZEOF); }
"static"				{ SNODE(STATIC); }
"struct"				{ SNODE(STRUCT); }
"switch"				{ SNODE(SWITCH); }
"typedef"				{ SNODE(TYPEDEF); }
"union"					{ SNODE(UNION); }
"unsigned"				{ SNODE(UNSIGNED); }
"void"					{ SNODE(VOID); }
"volatile"				{ SNODE(VOLATILE); }
"while"					{ SNODE(WHILE); }
"_Alignas"                              { SNODE(ALIGNAS); }
"_Alignof"                              { SNODE(ALIGNOF); }
"_Atomic"                               { SNODE(ATOMIC); }
"_Bool"                                 { SNODE(BOOL); }
"_Complex"                              { SNODE(COMPLEX); }
"_Generic"                              { SNODE(GENERIC); }
"_Imaginary"                            { SNODE(IMAGINARY); }
"_Noreturn"                             { SNODE(NORETURN); }
"_Static_assert"                        { SNODE(STATIC_ASSERT); }
"_Thread_local"                         { SNODE(THREAD_LOCAL); }
"__func__"                              { SNODE(FUNC_NAME); }

                    /* Basilisk C tokens */

"new"{WS}+("vertex"{WS}+)?"scalar"      { SNODE(NEW_FIELD); }
"new"{WS}+("face"{WS}+)?"vector"        { SNODE(NEW_FIELD); }
"new"{WS}+"tensor"                      { SNODE(NEW_FIELD); }
"face"{WS}+"vector"                     { SNODE(TYPEDEF_NAME); }
"vertex"{WS}+"scalar"                   { SNODE(TYPEDEF_NAME); }
"(const)"                               { SNODE(MAYBECONST); }
"in"			                { SNODE(IN); }
"trace"			                { SNODE(TRACE); }
"reduction"			        { SNODE(REDUCTION); }

"foreach_child" |
"foreach_neighbor"                      { SNODE(FOREACH_INNER); }

"foreach_dimension"			{ SNODE(FOREACH_DIMENSION); }

"foreach" |
"foreach_"{L}{A}*                       { SNODE(FOREACH); }

                    /* End of Basilisk C tokens */

{L}{A}*					{ SNODE(check_type()); }

{HP}{H}+{IS}?				{ SNODE(I_CONSTANT); }
{NZ}{D}*{IS}?				{ SNODE(I_CONSTANT); }
"0"{O}*{IS}?				{ SNODE(I_CONSTANT); }
{CP}?"'"([^'\\\n]|{ES})+"'"		{ SNODE(I_CONSTANT); }

{D}+{E}{FS}?				{ SNODE(F_CONSTANT); }
{D}*"."{D}+{E}?{FS}?			{ SNODE(F_CONSTANT); }
{D}+"."{E}?{FS}?			{ SNODE(F_CONSTANT); }
{HP}{H}+{P}{FS}?			{ SNODE(F_CONSTANT); }
{HP}{H}*"."{H}+{P}{FS}?			{ SNODE(F_CONSTANT); }
{HP}{H}+"."{P}{FS}?			{ SNODE(F_CONSTANT); }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{ SNODE(STRING_LITERAL); }

"..."					{ SNODE(ELLIPSIS); }
">>="					{ SNODE(RIGHT_ASSIGN); }
"<<="					{ SNODE(LEFT_ASSIGN); }
"+="					{ SNODE(ADD_ASSIGN); }
"-="					{ SNODE(SUB_ASSIGN); }
"*="					{ SNODE(MUL_ASSIGN); }
"/="					{ SNODE(DIV_ASSIGN); }
"%="					{ SNODE(MOD_ASSIGN); }
"&="					{ SNODE(AND_ASSIGN); }
"^="					{ SNODE(XOR_ASSIGN); }
"|="					{ SNODE(OR_ASSIGN); }
">>"					{ SNODE(RIGHT_OP); }
"<<"					{ SNODE(LEFT_OP); }
"++"					{ SNODE(INC_OP); }
"--"					{ SNODE(DEC_OP); }
"->"					{ SNODE(PTR_OP); }
"&&"					{ SNODE(AND_OP); }
"||"					{ SNODE(OR_OP); }
"<="					{ SNODE(LE_OP); }
">="					{ SNODE(GE_OP); }
"=="					{ SNODE(EQ_OP); }
"!="					{ SNODE(NE_OP); }
";"					{ CNODE(); }
("{"|"<%")				{ CNODE(); }
("}"|"%>")				{ CNODE(); }
","					{ CNODE(); }
":"					{ CNODE(); }
"="					{ CNODE(); }
"("					{ CNODE(); }
")"					{ CNODE(); }
("["|"<:")				{ CNODE(); }
("]"|":>")				{ CNODE(); }
"."					{ CNODE(); }
"&"					{ CNODE(); }
"!"					{ CNODE(); }
"~"					{ CNODE(); }
"-"					{ CNODE(); }
"+"					{ CNODE(); }
"*"					{ CNODE(); }
"/"					{ CNODE(); }
"%"					{ CNODE(); }
"<"					{ CNODE(); }
">"					{ CNODE(); }
"^"					{ CNODE(); }
"|"					{ CNODE(); }
"?"					{ CNODE(); }

{WS}					{ /* whitespace separates tokens */ }
.					{ /* discard bad characters */ }
	 
%%

static void comment (void)
{
  int c;  
  while ((c = input()) != 0)
    if (c == '*') {
      while ((c = input()) == '*')
	;
      
      if (c == '/')
	return;
      
      if (c == 0)
	break;
    }
  yyerror ("unterminated comment");
}

static void preproc (void)
{
  int c, c1 = 0;
  while ((c = input()) != 0) {
    if (c == '\n' && c1 != '\\')      
      return;
    c1 = c;
  }
  yyerror ("unterminated preprocessor directive");
}

static void bpreproc (void)
{
  int c;
  while ((c = input()) != 0)
    if (c == '@')
      return;
  yyerror ("unterminated @def");
}

static void ompreproc (void)
{
  int c, scope = 1;
  while ((c = input()) != 0) {
    if (c == '(')
      scope++;
    else if (c == ')') {
      scope--;
      if (scope == 0)
	return;
    }
  }
  yyerror ("unterminated OMP");
}

static int check_type (void)
{
  switch (sym_type (yytext)) {
  case TYPEDEF_NAME:                /* previously defined */
    return TYPEDEF_NAME;
  case ENUMERATION_CONSTANT:        /* previously defined */
    return ENUMERATION_CONSTANT;
  default:                          /* includes undefined */
    return IDENTIFIER;
  }
}

void lexer_setup (char * buffer, size_t len)
{
  yylineno = 1;
  yy_scan_buffer (buffer, len);
}
