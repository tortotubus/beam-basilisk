%param { Allocator * alloc }
%parse-param { Node ** root }
%define api.pure full
%define api.value.type { Node * }

%{
#include <string.h>
#include <assert.h>
#include <stdlib.h>
  
#include "node.h"

static Node * reduce_node (Allocator * alloc, Node ** children, int yyn);
#define YY_REDUCE_PRINT(yyn) yyval = reduce_node (alloc, yyvsp, yyn)
  
static int yyparse (Allocator * alloc, Node ** root);
int yylex (Node ** lvalp, Allocator * alloc);
void yyerror (Allocator * alloc, Node ** root, char const *);
void yylex_destroy();

const char * symbol_name (int sym);
void type_definition (Allocator * alloc, Node * declaration);
void typedef_cleanup(); 
%}

%token	IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	TYPEDEF_NAME ENUMERATION_CONSTANT

%token	TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	COMPLEX IMAGINARY 
%token	STRUCT UNION ENUM ELLIPSIS

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

 /* Basilisk C tokens */

%token MAYBECONST IN NEW_FIELD TRACE
%token FOREACH FOREACH_INNER FOREACH_DIMENSION
%token REDUCTION

 /* End of Basilisk C tokens */

%start root

%%

translation_unit
        : external_declaration
	| translation_unit external_declaration
        | translation_unit error ';'
        | translation_unit error '}'
        | translation_unit error ')'
        ;

primary_expression
        : generic_identifier
	| constant
	| string
	| '(' expression_error ')'
	| generic_selection
	;

expression_error
        : expression
	| error
	;

constant
	: I_CONSTANT		/* includes character_constant */
	| F_CONSTANT
	| ENUMERATION_CONSTANT	/* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: generic_identifier
	;

string
	: STRING_LITERAL
	| FUNC_NAME
	;

generic_selection
        : GENERIC '(' assignment_expression ',' generic_assoc_list ')'
	;

generic_assoc_list
	: generic_association
	| generic_assoc_list ',' generic_association
	;

generic_association
	: type_name ':' assignment_expression
	| DEFAULT ':' assignment_expression
	;

postfix_expression
	: primary_expression
	| function_call
	| array_access
        | postfix_expression '.' member_identifier
        | postfix_expression PTR_OP member_identifier
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'
	;

array_access
        : postfix_expression '[' ']' /* Basilisk C extension */
        | postfix_expression '[' expression ']'
	;
	
function_call
        : postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
        ;

member_identifier
        : generic_identifier
	;

argument_expression_list
	: argument_expression_list_item
	| argument_expression_list ',' argument_expression_list_item
	;

argument_expression_list_item
        : assignment_expression
	| field_list /* Basilisk C extension */
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	| ALIGNOF '(' type_name ')'
	| NEW_FIELD /* Basilisk C extension */
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	   /* Basilisk C extension */
	| unary_expression assignment_operator initializer
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression	/* with constraints */
	;

declaration
        : declaration_specifiers ';' 
	| declaration_specifiers init_declarator_list ';' {
	      type_definition (alloc, $$);
        }
	| static_assert_declaration
	;

declaration_specifiers
        : storage_class_specifier declaration_specifiers
	| storage_class_specifier
	| type_specifier declaration_specifiers
	| type_specifier
	| type_qualifier declaration_specifiers
	| type_qualifier
	| function_specifier declaration_specifiers
	| function_specifier
	| alignment_specifier declaration_specifiers
	| alignment_specifier
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator '=' initializer
	| declarator
	;

storage_class_specifier
	: TYPEDEF	/* identifiers must be flagged as TYPEDEF_NAME */
	| EXTERN
	| STATIC
	| THREAD_LOCAL
	| AUTO
	| REGISTER
	| TRACE
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| BOOL
	| COMPLEX
	| IMAGINARY /* non-mandated extension */
	| atomic_type_specifier
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME		/* after it has been defined as such */
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	| struct_or_union generic_identifier '{' struct_declaration_list '}'
	| struct_or_union generic_identifier
	| struct_or_union '{' error '}'
	| struct_or_union generic_identifier '{' error '}'
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list ';'	/* for anonymous struct/union */
	| specifier_qualifier_list struct_declarator_list ';'
	| static_assert_declaration
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: ':' constant_expression
	| declarator ':' constant_expression
	| declarator
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM generic_identifier '{' enumerator_list '}'
	| ENUM generic_identifier '{' enumerator_list ',' '}'
	| ENUM generic_identifier
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant '=' constant_expression
	| enumeration_constant
	;

atomic_type_specifier
	: ATOMIC '(' type_name ')'
	;

type_qualifier
	: CONST
	| RESTRICT
	| VOLATILE
	| ATOMIC
	| MAYBECONST
	;

function_specifier
	: INLINE
	| NORETURN
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'
	| ALIGNAS '(' constant_expression ')'
	;

declarator
        : pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: generic_identifier
	| '(' declarator ')'
	| direct_declarator '[' ']'
	| direct_declarator '[' '*' ']'
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_declarator '[' STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' assignment_expression ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' error ')'
	| direct_declarator '(' ')'
	| direct_declarator '(' identifier_list ')'
	;

generic_identifier
        : IDENTIFIER
	| TYPEDEF_NAME  /* workaround when variable name = type name */
	;

pointer
	: '*' type_qualifier_list pointer
	| '*' type_qualifier_list
	| '*' pointer
	| '*'
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list ',' ELLIPSIS
	| parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: generic_identifier
	| identifier_list ',' generic_identifier
	;

type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list
	;

abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' '*' ']'
	| '[' STATIC type_qualifier_list assignment_expression ']'
	| '[' STATIC assignment_expression ']'
	| '[' type_qualifier_list STATIC assignment_expression ']'
	| '[' type_qualifier_list assignment_expression ']'
	| '[' type_qualifier_list ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' '*' ']'
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	| assignment_expression
	;

initializer_list
	: designation initializer
	| initializer
	| initializer_list ',' designation initializer
	| initializer_list ',' initializer
	;

designation
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constant_expression ']'
	| '.' generic_identifier
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	| basilisk_statements /* Basilisk C extension */
	| error ';'
	;

labeled_statement
	: generic_identifier ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{'  block_item_list '}'
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'
	| expression ';'
        | expression compound_statement
	;

selection_statement
        : IF '(' expression_error ')' statement ELSE statement
        | IF '(' expression_error ')' statement
	| SWITCH '(' expression_error ')' statement
	;

iteration_statement
        : WHILE '(' expression ')' statement                                            
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	| FOR '(' declaration expression_statement ')' statement
	| FOR '(' declaration expression_statement expression ')' statement
	;

jump_statement
        : GOTO generic_identifier ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

external_declaration
	: function_definition
	| declaration
	| event_definition /* Basilisk C extension */
	| boundary_definition /* Basilisk C extension */
	| external_foreach_dimension /* Basilisk C extension */
	| attribute /* Basilisk C extension */
	| error compound_statement
	;

function_definition
        : declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

/************************* Basilisk C extensions ******************************/

basilisk_statements
        : foreach_statement
	| foreach_inner_statement
        | foreach_dimension_statement
	| forin_statement
	;

foreach_statement
        : FOREACH '(' ')' statement
        | FOREACH '(' foreach_parameters ')' statement
	;

foreach_parameters
        : foreach_parameter
	| foreach_parameters foreach_parameter
	;

foreach_parameter
        : expression
        | reduction
	;

reduction
        : REDUCTION '(' reduction_operator  ':' generic_identifier ')'
	;

reduction_operator
        : generic_identifier
	| '+'
	;

foreach_inner_statement
        : FOREACH_INNER '(' ')' statement
	| FOREACH_INNER '(' expression ')' statement
	;

foreach_dimension_statement
        : FOREACH_DIMENSION '(' ')' statement
        | FOREACH_DIMENSION '(' expression ')' statement
	;

forin_statement
        : FOR '(' TYPEDEF_NAME generic_identifier IN field_list ')' statement
        | FOR '(' expression IN field_list ')' statement
	;

field_list
        : expression
	| '{' field_item_list '}'
	;

field_item_list
        : generic_identifier
	| field_item_list ',' generic_identifier
	;

event_definition
        : generic_identifier generic_identifier '(' event_parameters ')' statement
	;

event_parameter
        : expression
	| generic_identifier '=' initializer
	| generic_identifier '=' expression
        ;

event_parameters
        : event_parameter
	| event_parameters ',' event_parameter
	| event_parameters ';' event_parameter
        ;

boundary_definition
        : assignment_expression ';'
	;

external_foreach_dimension
        : FOREACH_DIMENSION '(' ')' function_definition
        | FOREACH_DIMENSION '(' I_CONSTANT ')' function_definition
	;

attribute
        : generic_identifier '{' struct_declaration_list '}'
	;

root
        : translation_unit {
	  $$ = *root = allocate (alloc, sizeof(Node));
	  memset ($$, 0, sizeof(Node));
	  $$->kind = yyr1[yyn];
	  $$->child = allocate (alloc, 2*sizeof(Node *));
	  $$->child[0] = $1;
	  $$->child[1] = NULL;
        }
        ;

%%

/* Called by yyparse on error.  */
void
yyerror (Allocator * alloc, Node ** root, char const *s)
{
#if 0
  fprintf (stderr, "%d: %s near '", *line, s);
  char * s1 = *input - 1;
  while (!strchr("}{;\n", *s1)) s1--;
  s1++;
  while (strchr(" \t", *s1)) s1++;
  for (; s1 < *input; s1++)
    fputc (*s1, stderr);
  fputs ("'\n", stderr);
#endif
}

static char * copy_range (const char * start, const char * end, size_t offset)
{
  char * c = NULL;
  int len = end - start;
  if (len > 0) {
    char * s = c = malloc (len + 1);
    for (const char * i = start; i < end; i++, s++)
      *s = *(i + offset);
    *s = '\0';
  }
  return c;
}

static const char * copy_strings (const char * i, Node * n, size_t offset)
{
  if (n->start) {
    n->before = copy_range (i, n->start, offset);
    if (n->start > i)
      i = n->start;

    n->start = copy_range (i, n->after + 1, offset);
    if (n->after + 1 > i)
      i = n->after + 1;
    n->after = NULL;
  }
    
  if (n->child && n->child[0])
    for (Node ** c = n->child; *c; c++)
      i = copy_strings (i, *c, offset);
  return i;
}

static Node * recopy_node (Node * n)
{
  Node * c = malloc (sizeof (Node));
  memcpy (c, n, sizeof (Node));
  n->before = NULL;
  n->start = NULL;
  if (n->child) {
    int len = 0;
    for (Node ** i = n->child; *i; i++, len++);
    c->child = malloc ((len + 1)*sizeof (Node *));
    c->child[len] = NULL;
    for (Node ** i = n->child, ** j = c->child; *i; i++, j++) {
      *j = recopy_node (*i);
      (*j)->parent = c;
    }
  }
  return c;
}

static void remove_child (Node * c)
{
  if (!c->parent)
    return;
  Node ** i = c->parent->child;
  for (; *i && *i != c; i++);
  assert (*i == c);
  for (; *i; i++)
    *i = *(i + 1);
  c->parent = NULL;
}

static Node * reduce_node (Allocator * alloc, Node ** children, int yyn)
{
  Node * node = allocate (alloc, sizeof(Node));
  memset (node, 0, sizeof(Node));
  node->kind = yyr1[yyn];
  int n = yyr2[yyn];
  node->child = allocate (alloc, (n + 1)*sizeof(Node *));
  for (int i = 0; i < n; i++) {
    Node * c = children[i + 1 - n];
    if (c->parent)
      remove_child (c);
    c->parent = node;
    node->child[i] = c;
    node->child[i + 1] = NULL;
  }
  node->line = node->child[0]->line;
  return node;
}

Node * parse_node (const char * code)
{
  Node * root = NULL;
  Allocator * alloc = new_allocator();
  extern void lexer_setup (char * buffer, size_t len);
  size_t len = strlen (code) + 1;
  char * buffer = malloc (len + 1);
  memcpy (buffer, code, len);
  buffer[len] = '\0';
  lexer_setup (buffer, len + 1);
  //  yydebug = 1;
  yyparse (alloc, &root);
  assert (root);
  const char * i = copy_strings (buffer, root, code - buffer);
  root = recopy_node (root);
  const char * end = i; while (*end != '\0') end++;
  root->after = copy_range (i, end, code - buffer);
  free (buffer);
  free_allocator (alloc);
  typedef_cleanup();
  yylex_destroy();
  return root;
}

int token_symbol (int token)
{
   // just to avoid unused warning
  if (0) yy_reduce_print (NULL, NULL, 0, NULL, NULL);
  return YYTRANSLATE (token);
}

const char * symbol_name (int sym)
{
  return yytname[sym];
}
