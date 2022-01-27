%{
#include <string.h>
#include <assert.h>
#include <stdlib.h>
  
#include "node.h"

#define SYMBOL(n) n->kind = yyr1[yyn]
#define YY_REDUCE_PRINT(yyn) \
  if (yyn <= YYSYMBOL_root && !yyval->kind) yyval->kind = yyr1[yyn] // fixme

static int yyparse (Allocator * alloc, char ** input, int * line, Node ** root);
int yylex (Node ** lvalp, Allocator * alloc, char ** input, int * line);
void yyerror (Allocator * alloc, char ** input, int * line,
	      Node ** root, char const *);
void yylex_destroy();

static void node_child (Node * n, Node * c)
{
  int i;
  for (i = 0; n->child[i]; i++);
  assert (i < CMAX);
  n->child[i] = c;
  if (i > 0)
    n->child[i - 1]->after = c->before - 1;
}

%}

%param { Allocator * alloc }
%param { char ** input }
%param { int * line }
%parse-param { Node ** root }
%define api.pure full
%define api.value.type { Node * }

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

translation_unit /* Must be first */
        : external_declaration
	| translation_unit external_declaration           { node_append ($$, $2); }
        | translation_unit error ';'            { node_append ($$, $2), $2->kind = 1; }
        | translation_unit error '}'            { node_append ($$, $2), $2->kind = 1; }
        | translation_unit error ')'            { node_append ($$, $2), $2->kind = 1; }
        ;

primary_expression
        : generic_identifier          { SYMBOL($$); }
	| constant
	| string
	| '(' expression_error ')'    { node_child ($$, $2); }
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
	| postfix_expression '[' ']' /* Basilisk C extension */
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' generic_identifier
	| postfix_expression PTR_OP generic_identifier
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'
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
	| unary_expression assignment_operator initializer              /* Basilisk C extension */
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
	| declaration_specifiers init_declarator_list ';'         { if ($$->type == TYPEDEF) type_definition ($2); }
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
        : pointer direct_declarator { $$ = $2; }
	| direct_declarator
	;

direct_declarator
	: generic_identifier
	| '(' declarator ')'  { $$ = $2; }
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
	: '{' '}'                           { SYMBOL($$), $$->after = $2->after; }
	| '{'  block_item_list '}'          { SYMBOL($$), $$->after = $3->after, node_child ($$, $2); }
	;

block_item_list
	: block_item
	| block_item_list block_item        { node_append ($$, $2); }
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'
	| expression ';'                    { SYMBOL($$), $$->after = $2->before; }
        | expression compound_statement     { SYMBOL($$), node_child($$, $2); } /* Basilisk C extension */
	;

selection_statement
        : IF '(' expression_error ')' statement ELSE statement            { SYMBOL($$), node_child ($$, $5), node_child ($$, $7); }
        | IF '(' expression_error ')' statement                           { SYMBOL($$), node_child ($$, $5); }
	| SWITCH '(' expression_error ')' statement                       { SYMBOL($$), node_child ($$, $5); }
	;

iteration_statement
        : WHILE '(' expression ')' statement                                            { SYMBOL($$), node_child ($$, $5); }
	| DO statement WHILE '(' expression ')' ';'                                     { SYMBOL($$), node_child ($$, $2); }
	| FOR '(' expression_statement expression_statement ')' statement               { SYMBOL($$), node_child ($$, $6); }
	| FOR '(' expression_statement expression_statement expression ')' statement    { SYMBOL($$), node_child ($$, $7); }
	| FOR '(' declaration expression_statement ')' statement                        { SYMBOL($$), node_child ($$, $6); }
	| FOR '(' declaration expression_statement expression ')' statement             { SYMBOL($$), node_child ($$, $7); }
	;

jump_statement
        : GOTO generic_identifier ';'    { SYMBOL($$), $$->after = $2->before; }
	| CONTINUE ';'           { SYMBOL($$), $$->after = $2->before; }
	| BREAK ';'              { SYMBOL($$), $$->after = $2->before; }
	| RETURN ';'             { SYMBOL($$), $$->after = $2->before; }
	| RETURN expression ';'  { SYMBOL($$), $$->after = $3->before; }
	;

external_declaration
	: function_definition
	| declaration
	| event_definition /* Basilisk C extension */
	| boundary_definition /* Basilisk C extension */
	| external_foreach_dimension /* Basilisk C extension */
	| attribute /* Basilisk C extension */
	| error compound_statement { $$ = $2, $$->before = $1->before; }
	;

function_definition
        : declaration_specifiers declarator declaration_list compound_statement { $$ = $4; SYMBOL($$); $$->before = $1->before; }
	| declaration_specifiers declarator compound_statement                  { $$ = $3; SYMBOL($$); $$->before = $1->before; }
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
        : FOREACH '(' ')' statement                       { SYMBOL($$), $4->before = $3->after + 1, node_child ($$, $4); }
        | FOREACH '(' foreach_parameters ')' statement    { SYMBOL($$), $5->before = $4->after + 1, node_child ($$, $5); }
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
        : FOREACH_INNER '(' ')' statement               { SYMBOL($$), $4->before = $3->after + 1, node_child ($$, $4); }
	| FOREACH_INNER '(' expression ')' statement    { SYMBOL($$), $5->before = $4->after + 1, node_child ($$, $5); }
	;

foreach_dimension_statement
        : FOREACH_DIMENSION '(' ')' statement               { SYMBOL($$), $4->before = $3->after + 1, node_child ($$, $4); }
        | FOREACH_DIMENSION '(' expression ')' statement    { SYMBOL($$), $5->before = $4->after + 1, node_child ($$, $5); }
	;

forin_statement
        : FOR '(' TYPEDEF_NAME generic_identifier IN field_list ')' statement  { SYMBOL($$); $8->before = $7->after + 1, node_child ($$, $8); }
        | FOR '(' expression IN field_list ')' statement                 { SYMBOL($$); $7->before = $6->after + 1, node_child ($$, $7); }
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
        : generic_identifier generic_identifier '(' event_parameters ')' statement { $$ = $6; SYMBOL($$); $$->before = $1->before; }
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
        : generic_identifier '{' struct_declaration_list '}' { SYMBOL($$), node_child($$, $3); }
	;

root /* Must be last */
        : translation_unit {
	  $$ = *root = allocate (alloc, sizeof(Node));
	  memset ($$, 0, sizeof(Node));
	  $$->type = -1;
	  SYMBOL($$);
	  $$->child[0] = $1;
        }
        ;

%%

static const char * globalfname = NULL; // fixme

/* Called by yyparse on error.  */
void
yyerror (Allocator * alloc,
	 char ** input, int * line,
	 Node ** root, char const *s)
{
#if 1
  fprintf (stderr, "%s:%d: %s\n", globalfname, *line, s);
#endif
}

static char * recopy_node (Node * n)
{
  char * i = n->before;
  n->before = !(*n->child) ? NULL: strcpy_range (i, (*n->child)->before);
  for (Node ** c = n->child; *c; c++)
    i = recopy_node (*c);
  char * after = n->after;
  n->after = NULL;
  if (n->next) {
    n->after = strcpy_range (i, n->next->before);
    return recopy_node (n->next);
  }
  n->after = strcpy_range (i, after + 1);
  return i > after ? i : after + 1;
}

Node * parse_node (char * code, const char * fname)
{
  Node * root = NULL;
  Allocator * alloc = new_allocator();
  int line = 1;
  char * code1 = code;
  globalfname = fname;
  //  yydebug = 1;
  yyparse (alloc, &code1, &line, &root);
  assert (root);
  yylex_destroy();
  root = copy_node (root);
  root->before = code;
  root->after = code + strlen(code) - 1;
  recopy_node (root);
  free_allocator (alloc);
  return root;
}
