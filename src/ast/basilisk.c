/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 59 "basilisk.yacc"

#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "parser.h"

static Ast * ast_reduce (Allocator * alloc, int sym, Ast ** children, int n);
#define DEFAULT_ACTION(yyn)					\
  yyval = ast_reduce ((Allocator *)parse->alloc, yyr1[yyn], yyvsp, yyr2[yyn])
static int yyparse (AstRoot * parse, Ast * root);

#line 84 "basilisk.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "basilisk.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_I_CONSTANT = 4,                 /* I_CONSTANT  */
  YYSYMBOL_F_CONSTANT = 5,                 /* F_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_FUNC_NAME = 7,                  /* FUNC_NAME  */
  YYSYMBOL_SIZEOF = 8,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 9,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 10,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 11,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 12,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 13,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 14,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 15,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 16,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 17,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 18,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 19,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 20,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 21,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 22,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 23,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 24,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 25,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 26,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 27,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 28,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 29,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPEDEF_NAME = 30,              /* TYPEDEF_NAME  */
  YYSYMBOL_ENUMERATION_CONSTANT = 31,      /* ENUMERATION_CONSTANT  */
  YYSYMBOL_TYPEDEF = 32,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 33,                    /* EXTERN  */
  YYSYMBOL_STATIC = 34,                    /* STATIC  */
  YYSYMBOL_AUTO = 35,                      /* AUTO  */
  YYSYMBOL_REGISTER = 36,                  /* REGISTER  */
  YYSYMBOL_INLINE = 37,                    /* INLINE  */
  YYSYMBOL_CONST = 38,                     /* CONST  */
  YYSYMBOL_RESTRICT = 39,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 40,                  /* VOLATILE  */
  YYSYMBOL_BOOL = 41,                      /* BOOL  */
  YYSYMBOL_CHAR = 42,                      /* CHAR  */
  YYSYMBOL_SHORT = 43,                     /* SHORT  */
  YYSYMBOL_INT = 44,                       /* INT  */
  YYSYMBOL_LONG = 45,                      /* LONG  */
  YYSYMBOL_SIGNED = 46,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 47,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 48,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 49,                    /* DOUBLE  */
  YYSYMBOL_VOID = 50,                      /* VOID  */
  YYSYMBOL_COMPLEX = 51,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 52,                 /* IMAGINARY  */
  YYSYMBOL_STRUCT = 53,                    /* STRUCT  */
  YYSYMBOL_UNION = 54,                     /* UNION  */
  YYSYMBOL_ENUM = 55,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 56,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 57,                      /* CASE  */
  YYSYMBOL_DEFAULT = 58,                   /* DEFAULT  */
  YYSYMBOL_IF = 59,                        /* IF  */
  YYSYMBOL_ELSE = 60,                      /* ELSE  */
  YYSYMBOL_SWITCH = 61,                    /* SWITCH  */
  YYSYMBOL_WHILE = 62,                     /* WHILE  */
  YYSYMBOL_DO = 63,                        /* DO  */
  YYSYMBOL_FOR = 64,                       /* FOR  */
  YYSYMBOL_GOTO = 65,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 66,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 67,                     /* BREAK  */
  YYSYMBOL_RETURN = 68,                    /* RETURN  */
  YYSYMBOL_ALIGNAS = 69,                   /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 70,                   /* ALIGNOF  */
  YYSYMBOL_ATOMIC = 71,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 72,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 73,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 74,             /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 75,              /* THREAD_LOCAL  */
  YYSYMBOL_MAYBECONST = 76,                /* MAYBECONST  */
  YYSYMBOL_NEW_FIELD = 77,                 /* NEW_FIELD  */
  YYSYMBOL_TRACE = 78,                     /* TRACE  */
  YYSYMBOL_FOREACH = 79,                   /* FOREACH  */
  YYSYMBOL_FOREACH_INNER = 80,             /* FOREACH_INNER  */
  YYSYMBOL_FOREACH_DIMENSION = 81,         /* FOREACH_DIMENSION  */
  YYSYMBOL_REDUCTION = 82,                 /* REDUCTION  */
  YYSYMBOL_MACRO = 83,                     /* MACRO  */
  YYSYMBOL_ELLIPSIS_MACRO = 84,            /* ELLIPSIS_MACRO  */
  YYSYMBOL_85_ = 85,                       /* ';'  */
  YYSYMBOL_86_ = 86,                       /* '}'  */
  YYSYMBOL_87_ = 87,                       /* ')'  */
  YYSYMBOL_88_ = 88,                       /* '('  */
  YYSYMBOL_89_ = 89,                       /* ','  */
  YYSYMBOL_90_ = 90,                       /* ':'  */
  YYSYMBOL_91_ = 91,                       /* '.'  */
  YYSYMBOL_92_ = 92,                       /* '{'  */
  YYSYMBOL_93_ = 93,                       /* '['  */
  YYSYMBOL_94_ = 94,                       /* ']'  */
  YYSYMBOL_95_ = 95,                       /* '*'  */
  YYSYMBOL_96_ = 96,                       /* '&'  */
  YYSYMBOL_97_ = 97,                       /* '+'  */
  YYSYMBOL_98_ = 98,                       /* '-'  */
  YYSYMBOL_99_ = 99,                       /* '~'  */
  YYSYMBOL_100_ = 100,                     /* '!'  */
  YYSYMBOL_101_ = 101,                     /* '/'  */
  YYSYMBOL_102_ = 102,                     /* '%'  */
  YYSYMBOL_103_ = 103,                     /* '<'  */
  YYSYMBOL_104_ = 104,                     /* '>'  */
  YYSYMBOL_105_ = 105,                     /* '^'  */
  YYSYMBOL_106_ = 106,                     /* '|'  */
  YYSYMBOL_107_ = 107,                     /* '?'  */
  YYSYMBOL_108_ = 108,                     /* '='  */
  YYSYMBOL_YYACCEPT = 109,                 /* $accept  */
  YYSYMBOL_translation_unit = 110,         /* translation_unit  */
  YYSYMBOL_primary_expression = 111,       /* primary_expression  */
  YYSYMBOL_expression_error = 112,         /* expression_error  */
  YYSYMBOL_constant = 113,                 /* constant  */
  YYSYMBOL_enumeration_constant = 114,     /* enumeration_constant  */
  YYSYMBOL_string = 115,                   /* string  */
  YYSYMBOL_generic_selection = 116,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 117,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 118,      /* generic_association  */
  YYSYMBOL_postfix_expression = 119,       /* postfix_expression  */
  YYSYMBOL_postfix_initializer = 120,      /* postfix_initializer  */
  YYSYMBOL_array_access = 121,             /* array_access  */
  YYSYMBOL_function_call = 122,            /* function_call  */
  YYSYMBOL_member_identifier = 123,        /* member_identifier  */
  YYSYMBOL_argument_expression_list = 124, /* argument_expression_list  */
  YYSYMBOL_argument_expression_list_item = 125, /* argument_expression_list_item  */
  YYSYMBOL_unary_expression = 126,         /* unary_expression  */
  YYSYMBOL_unary_operator = 127,           /* unary_operator  */
  YYSYMBOL_cast_expression = 128,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 129, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 130,      /* additive_expression  */
  YYSYMBOL_shift_expression = 131,         /* shift_expression  */
  YYSYMBOL_relational_expression = 132,    /* relational_expression  */
  YYSYMBOL_equality_expression = 133,      /* equality_expression  */
  YYSYMBOL_and_expression = 134,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 135,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 136,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 137,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 138,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 139,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 140,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 141,      /* assignment_operator  */
  YYSYMBOL_expression = 142,               /* expression  */
  YYSYMBOL_constant_expression = 143,      /* constant_expression  */
  YYSYMBOL_declaration = 144,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 145,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 146,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 147,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 148,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 149,           /* type_specifier  */
  YYSYMBOL_types = 150,                    /* types  */
  YYSYMBOL_struct_or_union_specifier = 151, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 152,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 153,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 154,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 155, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 156,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 157,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 158,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 159,          /* enumerator_list  */
  YYSYMBOL_enumerator = 160,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 161,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 162,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 163,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 164,      /* alignment_specifier  */
  YYSYMBOL_declarator = 165,               /* declarator  */
  YYSYMBOL_direct_declarator = 166,        /* direct_declarator  */
  YYSYMBOL_generic_identifier = 167,       /* generic_identifier  */
  YYSYMBOL_pointer = 168,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 169,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 170,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 171,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 172,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 173,          /* identifier_list  */
  YYSYMBOL_type_name = 174,                /* type_name  */
  YYSYMBOL_abstract_declarator = 175,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 176, /* direct_abstract_declarator  */
  YYSYMBOL_type_not_specified = 177,       /* type_not_specified  */
  YYSYMBOL_initializer = 178,              /* initializer  */
  YYSYMBOL_initializer_list = 179,         /* initializer_list  */
  YYSYMBOL_designation = 180,              /* designation  */
  YYSYMBOL_designator_list = 181,          /* designator_list  */
  YYSYMBOL_designator = 182,               /* designator  */
  YYSYMBOL_static_assert_declaration = 183, /* static_assert_declaration  */
  YYSYMBOL_statement = 184,                /* statement  */
  YYSYMBOL_labeled_statement = 185,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 186,       /* compound_statement  */
  YYSYMBOL_187_1 = 187,                    /* @1  */
  YYSYMBOL_block_item_list = 188,          /* block_item_list  */
  YYSYMBOL_block_item = 189,               /* block_item  */
  YYSYMBOL_expression_statement = 190,     /* expression_statement  */
  YYSYMBOL_selection_statement = 191,      /* selection_statement  */
  YYSYMBOL_for_scope = 192,                /* for_scope  */
  YYSYMBOL_iteration_statement = 193,      /* iteration_statement  */
  YYSYMBOL_for_declaration_statement = 194, /* for_declaration_statement  */
  YYSYMBOL_jump_statement = 195,           /* jump_statement  */
  YYSYMBOL_external_declaration = 196,     /* external_declaration  */
  YYSYMBOL_function_declaration = 197,     /* function_declaration  */
  YYSYMBOL_function_definition = 198,      /* function_definition  */
  YYSYMBOL_declaration_list = 199,         /* declaration_list  */
  YYSYMBOL_basilisk_statements = 200,      /* basilisk_statements  */
  YYSYMBOL_macro_call = 201,               /* macro_call  */
  YYSYMBOL_macro_statement = 202,          /* macro_statement  */
  YYSYMBOL_foreach_statement = 203,        /* foreach_statement  */
  YYSYMBOL_foreach_parameters = 204,       /* foreach_parameters  */
  YYSYMBOL_foreach_parameter = 205,        /* foreach_parameter  */
  YYSYMBOL_reduction_list = 206,           /* reduction_list  */
  YYSYMBOL_reduction = 207,                /* reduction  */
  YYSYMBOL_reduction_operator = 208,       /* reduction_operator  */
  YYSYMBOL_reduction_array = 209,          /* reduction_array  */
  YYSYMBOL_foreach_inner_statement = 210,  /* foreach_inner_statement  */
  YYSYMBOL_foreach_dimension_statement = 211, /* foreach_dimension_statement  */
  YYSYMBOL_forin_declaration_statement = 212, /* forin_declaration_statement  */
  YYSYMBOL_forin_statement = 213,          /* forin_statement  */
  YYSYMBOL_forin_arguments = 214,          /* forin_arguments  */
  YYSYMBOL_event_definition = 215,         /* event_definition  */
  YYSYMBOL_event_parameters = 216,         /* event_parameters  */
  YYSYMBOL_event_parameter = 217,          /* event_parameter  */
  YYSYMBOL_boundary_definition = 218,      /* boundary_definition  */
  YYSYMBOL_external_foreach_dimension = 219, /* external_foreach_dimension  */
  YYSYMBOL_attribute = 220,                /* attribute  */
  YYSYMBOL_new_field = 221,                /* new_field  */
  YYSYMBOL_root = 222                      /* root  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  236
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3450

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  109
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  363
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  654

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   339


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,     2,     2,     2,   102,    96,     2,
      88,    87,    95,    97,    89,    98,    91,   101,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    90,    85,
     103,   108,   104,   107,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    93,     2,    94,   105,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    92,   106,    86,    99,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   110,   110,   111,   112,   113,   114,   118,   119,   120,
     121,   122,   126,   127,   131,   132,   133,   137,   141,   142,
     146,   150,   151,   155,   156,   160,   161,   162,   163,   164,
     165,   166,   167,   171,   172,   176,   177,   178,   182,   183,
     187,   191,   192,   193,   197,   198,   202,   203,   204,   205,
     206,   207,   208,   209,   213,   214,   215,   216,   217,   218,
     222,   223,   229,   230,   231,   232,   236,   237,   238,   242,
     243,   244,   248,   249,   250,   251,   252,   256,   257,   258,
     262,   263,   267,   268,   272,   273,   277,   278,   282,   283,
     287,   288,   292,   293,   294,   295,   296,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   314,   315,
     319,   323,   324,   325,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   342,   343,   347,   348,   352,   353,
     354,   355,   356,   357,   358,   362,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   385,   386,   387,   388,   389,   393,   394,   398,
     399,   403,   404,   405,   409,   410,   411,   412,   416,   417,
     421,   422,   423,   427,   428,   429,   430,   431,   435,   436,
     440,   441,   445,   449,   450,   451,   452,   453,   457,   458,
     462,   463,   467,   468,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   490,
     491,   495,   496,   497,   498,   502,   503,   507,   508,   512,
     513,   517,   518,   519,   520,   521,   525,   526,   530,   531,
     535,   536,   537,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   565,   569,   570,   571,   575,   576,
     577,   578,   582,   586,   587,   591,   592,   596,   600,   601,
     602,   603,   604,   605,   606,   607,   611,   612,   613,   617,
     619,   619,   625,   626,   630,   631,   635,   636,   640,   641,
     642,   646,   650,   651,   652,   654,   656,   660,   662,   667,
     668,   669,   670,   671,   675,   676,   677,   678,   679,   680,
     681,   682,   686,   690,   692,   697,   698,   705,   706,   707,
     708,   709,   710,   711,   715,   716,   720,   721,   725,   726,
     730,   731,   735,   736,   740,   741,   745,   749,   750,   751,
     755,   756,   760,   761,   765,   766,   770,   775,   780,   781,
     785,   789,   790,   791,   795,   796,   797,   801,   805,   806,
     810,   814,   815,   819
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "I_CONSTANT", "F_CONSTANT", "STRING_LITERAL", "FUNC_NAME", "SIZEOF",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF_NAME",
  "ENUMERATION_CONSTANT", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE", "BOOL", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID",
  "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC",
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "MAYBECONST", "NEW_FIELD",
  "TRACE", "FOREACH", "FOREACH_INNER", "FOREACH_DIMENSION", "REDUCTION",
  "MACRO", "ELLIPSIS_MACRO", "';'", "'}'", "')'", "'('", "','", "':'",
  "'.'", "'{'", "'['", "']'", "'*'", "'&'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "$accept",
  "translation_unit", "primary_expression", "expression_error", "constant",
  "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "postfix_initializer", "array_access", "function_call",
  "member_identifier", "argument_expression_list",
  "argument_expression_list_item", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "types",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator",
  "generic_identifier", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "type_not_specified", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "@1", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "for_scope",
  "iteration_statement", "for_declaration_statement", "jump_statement",
  "external_declaration", "function_declaration", "function_definition",
  "declaration_list", "basilisk_statements", "macro_call",
  "macro_statement", "foreach_statement", "foreach_parameters",
  "foreach_parameter", "reduction_list", "reduction", "reduction_operator",
  "reduction_array", "foreach_inner_statement",
  "foreach_dimension_statement", "forin_declaration_statement",
  "forin_statement", "forin_arguments", "event_definition",
  "event_parameters", "event_parameter", "boundary_definition",
  "external_foreach_dimension", "attribute", "new_field", "root", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,    59,   125,    41,    40,    44,
      58,    46,   123,    91,    93,    42,    38,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63,    61
};
#endif

#define YYPACT_NINF (-388)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-364)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1119,   -35,    34,  -388,  -388,  -388,  -388,   543,  2571,  2571,
     725,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,   137,    -9,    -2,    22,    32,
    -388,    48,  -388,  -388,    79,  -388,    87,   136,  1219,  -388,
    -388,  -388,  -388,  -388,  -388,   731,  -388,  -388,  -388,  -388,
     315,  -388,   -35,   679,  2585,  -388,   -21,   -49,   224,   163,
     254,    94,   110,   154,   225,    24,  -388,   201,  -388,    86,
    3254,  3254,  -388,  -388,   170,  -388,  -388,  3254,  3254,  3254,
     184,  -388,  -388,  2943,  -388,  1274,  -388,  -388,  -388,  -388,
    -388,  -388,   296,   235,  -388,  -388,  1219,  -388,  -388,  1219,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  2126,  -388,  -388,   298,   216,  1448,  3374,
    3374,  2527,  2585,   352,    58,  2001,  -388,   679,   246,  -388,
     223,  3374,   130,  3374,   255,   -41,  -388,    26,  -388,  -388,
    2015,    26,  2157,  -388,  2126,  -388,  -388,  2585,  2585,  2585,
    2585,  2585,  2585,  2585,  2585,  2585,  2585,  2585,  2585,  2585,
    2585,  2585,  2585,  2585,  2585,  2527,  -388,  -388,   173,   259,
     119,  -388,   -31,   -28,  -388,    68,  -388,  -388,  -388,  2779,
     237,  -388,  -388,  -388,  3296,   258,  -388,    86,  -388,  2943,
     265,   679,  2585,   272,   292,   307,   312,  1274,  -388,    26,
     289,   322,  2232,   324,   326,   330,  -388,  -388,   120,   320,
    -388,  -388,  -388,  -388,  -388,   333,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  1019,   336,
     338,   679,  1984,  -388,  -388,  -388,   318,   -53,  -388,   298,
    -388,   341,   342,   343,   349,   348,   350,   424,   351,  3254,
    -388,  -388,   193,  -388,  -388,  -388,  2527,  -388,  2879,  1501,
     -18,  -388,    -3,  -388,  -388,  2540,  -388,  -388,  -388,  -388,
    -388,  -388,   222,  -388,  -388,   355,   102,  -388,  -388,  -388,
    -388,  -388,   -21,   -21,   -49,   -49,   224,   224,   224,   224,
     163,   163,   254,    94,   110,   154,   225,   215,  -388,   359,
    -388,  -388,  -388,   259,  -388,   173,  2263,  -388,  1552,  -388,
     -28,   356,  3054,  -388,    17,  -388,  2834,  3103,  2585,   346,
    -388,  -388,  -388,   365,  1274,   842,   842,  2527,   398,   380,
    -388,  -388,  -388,   127,  2113,  2277,    92,  -388,  1274,  1372,
    -388,  -388,   917,  -388,   375,   375,    26,  1984,  2585,  -388,
    -388,   192,  2263,   165,  -388,  2585,  -388,    97,   198,  -388,
    -388,  -388,  -388,  3335,   460,  -388,  3254,   173,  -388,  -388,
    2126,  -388,   361,  -388,   100,   383,   382,  -388,   387,  1807,
    -388,   381,   384,  1603,    -3,  -388,  -388,  1654,  -388,  -388,
    -388,  -388,  -388,  2585,  -388,  -388,  -388,  -388,  -388,  -388,
    2724,  1807,  -388,   388,   391,  1705,  -388,  -388,  -388,  -388,
    -388,  2585,   142,  -388,   386,   395,  3152,  -388,   679,  -388,
     159,  -388,  1274,  -388,   390,   402,   226,   403,  -388,  -388,
     405,  1274,  -388,   233,  -388,   408,  -388,  1274,   251,   412,
    1274,  -388,    64,  2308,    86,  2308,  -388,  -388,  -388,   202,
     413,  -388,  1855,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
     112,   416,   256,  -388,   418,   422,  -388,  -388,  -388,  2263,
    2657,   411,   140,  -388,  -388,  3207,  -388,  -388,   417,  1807,
    -388,  -388,  2527,  -388,   426,  3004,  1807,  -388,   427,   429,
    1756,  -388,   438,  -388,  -388,   439,   262,   440,  1807,  -388,
    -388,  2527,  -388,   442,   445,  -388,  -388,  -388,   249,  2585,
    -388,  -388,  2540,  2585,  1274,  2585,  -388,  1274,  1274,  1274,
    2527,    31,  -388,  1274,  2384,  -388,  -388,  1274,  1274,  -388,
    2126,  2415,    29,  2429,  -388,  1886,  -388,  -388,  -388,  2263,
    -388,  2527,  -388,  3335,  2527,   455,  -388,  -388,  2263,  -388,
    -388,  -388,   448,   449,  -388,  -388,   458,   461,  1807,  -388,
    -388,  2527,  -388,   462,  -388,  -388,  -388,   549,  -388,   463,
     465,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,   500,  -388,  -388,   274,  -388,  -388,  -388,   472,  -388,
    -388,  -388,  -388,  -388,   223,   479,  1274,   286,  2126,  1274,
     290,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,   474,   476,  -388,  -388,  -388,  -388,  1274,
     486,    26,  1274,  -388,  1274,   488,  -388,  1274,  -388,  -388,
    -388,  -388,   483,   490,  -388,  -388,  1274,  -388,   489,  -388,
    -388,  2527,   103,  -388
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     7,    14,    15,    18,    19,     0,     0,     0,
     151,    16,   128,   129,   130,   132,   133,   188,   183,   184,
     185,   145,   137,   138,   139,   140,   143,   144,   141,   142,
     136,   146,   147,   157,   158,     0,     0,     0,   186,     0,
     189,     0,   131,   187,   361,   134,     0,     0,     0,    55,
      54,    56,    57,    58,    59,     0,    25,     8,     9,    11,
      46,    27,    26,    60,     0,    62,    66,    69,    72,    77,
      80,    82,    84,    86,    88,    90,    92,     0,   305,     0,
     115,   117,   135,   149,     0,   150,   148,   119,   121,   123,
       0,   113,     2,     0,   304,     0,   306,   307,   308,   309,
     310,    53,     0,   280,   311,     7,     0,    26,    50,     0,
      47,    48,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,    97,     0,   209,   210,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,    13,   151,     0,   108,
      12,   165,   254,   167,     0,     0,     3,     0,    30,    31,
       0,     0,     0,   327,     0,    60,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   357,   254,     0,   214,
       0,   124,   312,   254,   194,     0,   151,   114,   116,     0,
     154,   118,   120,   122,     0,     0,   315,     0,   314,     0,
       0,   210,     0,     0,     0,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,     0,   317,   286,     0,     0,
     326,   268,   269,   270,   271,     0,   272,   296,   273,   274,
     318,   319,   320,   321,   322,   323,     1,   279,     0,     0,
       0,     0,     0,    96,    95,    17,   181,     0,   178,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     324,    45,     0,    41,    44,    10,     0,   164,     0,     0,
     231,   254,   232,   229,   166,     0,     4,     5,     6,    29,
      40,    38,     0,    28,    35,    55,     0,    94,    93,    63,
      64,    65,    67,    68,    70,    71,    75,    76,    73,    74,
      78,    79,    81,    83,    85,    87,    89,     0,   111,     0,
     186,   215,   213,   212,   254,     0,     0,   254,     0,   193,
     254,     0,     0,   159,     0,   163,     0,     0,     0,   127,
     316,   313,   275,     0,     0,     0,     0,     0,     0,     0,
     300,   301,   302,     0,     0,     0,     0,   287,     0,     0,
     284,   285,     0,   282,    51,     0,     0,     0,     0,   257,
     259,     0,     0,     0,   263,     0,   173,     0,     0,   191,
     190,    52,   182,     0,     0,   362,     0,     0,   358,   325,
      43,   109,     0,   250,   224,     0,   218,   254,     0,     0,
     234,    55,     0,     0,   230,   228,   254,     0,    32,    61,
      39,    36,    37,     0,   195,   216,   211,   112,   125,   126,
       0,     0,   196,    55,     0,     0,   192,   155,   152,   160,
     254,     0,     0,   168,   172,     0,     0,   360,    60,   354,
       0,   351,     0,   278,     0,     0,     0,     0,   299,   303,
       0,     0,   332,     0,   330,   333,   334,     0,     0,     0,
       0,   276,     0,     0,     0,     0,   281,   283,   266,     0,
       0,    33,     0,   258,   262,   264,   180,   174,   179,   175,
       0,     0,     0,    21,     0,     0,   359,   312,    42,     0,
       0,   221,   231,   223,   251,     0,   219,   233,     0,     0,
     235,   241,     0,   240,     0,     0,     0,   242,    55,     0,
       0,    91,     0,   226,   207,     0,     0,     0,     0,   197,
     204,     0,   203,    55,     0,   161,   170,   254,     0,     0,
     156,   153,     0,     0,     0,     0,   277,     0,     0,     0,
       0,     0,   328,     0,     0,   335,   342,     0,     0,   344,
       0,     0,   127,     0,   255,     0,   265,    34,   261,     0,
     176,     0,    20,     0,     0,     0,   225,   151,     0,   217,
     254,   237,     0,     0,   239,   252,     0,     0,     0,   243,
     249,     0,   248,     0,   206,   205,   208,     0,   199,     0,
       0,   200,   202,   162,   169,   171,   356,   355,   353,   350,
     352,   289,   290,   292,     0,   339,   338,   337,     0,   329,
     331,   343,   345,   349,   348,     0,     0,     0,     0,     0,
       0,   256,   260,    24,    22,    23,   267,   222,   220,   236,
     238,   253,   245,     0,     0,   246,   227,   198,   201,     0,
       0,     0,     0,   297,     0,     0,   294,     0,   244,   247,
     288,   293,   340,     0,   347,   298,     0,   295,     0,   336,
     346,     0,     0,   341
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -388,  -388,  -388,   -19,  -388,  -388,  -388,  -388,  -388,    27,
     450,  -113,  -388,     0,   431,   434,   206,   523,  -388,   -40,
     231,   242,   205,   218,   415,   419,   420,   421,   423,  -388,
    -126,    99,   -62,   -43,  -118,   -77,   364,  -388,   278,  -388,
     -37,  -388,  -388,  -388,  -166,  -287,  -116,  -388,    71,  -388,
     347,  -349,  -388,     5,  -388,  -388,   -70,  -182,     4,  -127,
    -231,  -387,  -388,   113,  -388,   374,  -125,  -262,  -170,  -294,
     243,  -324,  -388,   238,  -163,   -65,  -388,    20,  -388,  -388,
     252,  -330,  -388,  -388,  -388,  -388,  -388,   548,  -388,  -247,
    -388,  -388,  -388,    42,  -388,  -388,    77,  -388,   160,  -388,
    -388,  -388,  -388,  -388,  -388,     6,  -388,  -388,  -112,  -388,
    -388,  -388,  -388,  -388
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    55,    56,   138,    57,   246,    58,    59,   472,   473,
      60,   261,    61,   107,   279,   262,   263,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,   139,   123,   218,   251,    78,   384,   180,   181,    80,
      81,    82,    83,    84,   322,   323,   142,   422,   423,    85,
     247,   248,    86,    87,    88,    89,   309,   183,   219,   185,
     313,   385,   386,   387,   506,   474,   388,   272,   273,   360,
     361,   362,   363,   364,    91,   351,   221,   222,   238,   352,
     353,   223,   224,   225,   226,   227,   228,    92,    93,    94,
     199,   229,    95,   230,   231,   443,   444,   445,   446,   598,
     643,   232,   233,   234,   235,   605,    97,   430,   431,    98,
      99,   100,   101,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,   154,   250,   320,    90,   140,   250,   308,   394,   182,
     243,   141,   378,   319,   256,   270,   196,   271,   468,   455,
     124,   104,   409,   505,   156,   267,   325,   274,   327,   124,
     220,   325,   608,   366,   124,   419,   367,  -209,   393,   127,
     419,   287,    96,   174,   276,   277,   278,   125,   160,   161,
     595,   103,   312,   143,  -127,    62,   125,   103,  -127,    90,
     317,   125,   258,   140,  -209,   318,   140,   540,   463,   141,
     268,   124,   141,   324,   157,   269,   250,   316,   324,   128,
     158,   159,   153,   184,   333,   396,   129,   415,   190,   124,
     397,   141,   141,   141,   195,    62,   449,    96,   125,    77,
     245,   395,   420,   124,   141,   178,   141,   421,   566,   286,
     130,   143,   179,   198,   143,   245,   125,   289,   290,   291,
     131,   468,   330,   541,  -209,   543,  -209,   329,   596,   476,
     125,   175,   307,   143,   143,   143,   132,   316,   549,   419,
     124,   270,   338,   124,   407,   259,   143,   410,   143,   347,
     416,   280,   141,   266,    77,   280,   178,   141,   489,   325,
     426,   350,   398,   325,   325,   104,   500,   125,   548,   343,
     125,   177,   133,   124,   178,   134,   124,   164,   165,   450,
     508,   179,   184,   467,   311,   556,   406,   124,   480,   184,
     170,   266,   266,   269,   143,   179,   402,   653,   550,   143,
     125,   184,   429,   125,   314,   347,   324,    62,   315,   266,
     324,   324,   439,   339,   125,   171,   266,   486,   268,   331,
     394,   549,   244,   269,   135,   179,   495,   517,   480,   126,
     255,   518,   250,   269,   264,   399,   162,   163,    62,   250,
     460,   398,   398,   173,   523,   329,   524,   466,   525,   264,
     515,   548,   124,   288,   424,   612,   356,   482,   358,   483,
     172,   178,   189,   325,   617,   568,   166,   167,   179,   433,
     168,   169,   453,   464,   311,   350,   194,   501,   461,   125,
     379,   462,   380,   451,   469,   141,   176,   470,   544,   141,
     141,   545,   140,   140,   436,   250,   236,    18,    19,    20,
     320,   245,   448,   516,   266,   403,   452,   477,   249,   400,
     324,   380,   266,   529,   481,   266,   434,   435,   405,   184,
     533,   237,   534,   311,   147,   148,   149,   143,   184,   326,
     310,   143,   143,   265,    62,    43,   141,   178,   537,   421,
     266,   359,   275,   552,   179,   553,   328,   583,    62,   576,
     332,   577,    62,   482,   179,   105,     3,     4,     5,     6,
     458,   630,   334,   266,    79,   381,   522,   526,   392,   296,
     297,   298,   299,   634,   340,   266,   532,   637,   143,   266,
     335,   184,   536,    11,   542,   539,   300,   301,   184,   141,
     618,   292,   293,   250,   311,   336,   587,   429,   405,   429,
     337,   585,   311,   150,   294,   295,   151,   341,   152,   586,
     348,   588,   344,   590,   345,   359,   311,   414,   346,    79,
     405,   349,   144,   354,    39,   355,   365,   603,   369,   370,
     371,   143,    62,   147,   148,   149,   372,   373,   376,   374,
     109,    62,   417,   442,   187,   188,   404,    62,   424,   401,
      62,   191,   192,   193,   316,   432,   359,   197,   184,   589,
     437,   359,   591,   592,   593,   438,   475,   242,   599,   479,
     484,   485,   601,   602,   487,   490,   519,   527,   491,   264,
     239,   520,   509,   240,   184,   510,   184,   594,   488,   528,
     440,   530,   494,   531,   405,   603,   499,   604,   607,   538,
     610,   311,   252,   253,   254,   405,   551,   546,   554,   555,
     507,   561,   150,   405,   514,   151,   141,   152,   375,   558,
     564,   569,   184,   570,    62,   574,   575,    62,    62,    62,
     108,   110,   111,    62,   578,   597,   581,    62,    62,   582,
     616,   633,   619,   620,   636,   621,   105,     3,     4,     5,
       6,     7,   626,     8,     9,   622,   625,   627,   143,   628,
     629,   359,   631,   197,   640,   604,   632,   644,   638,   645,
     639,   641,   647,   405,    11,   646,   648,   649,   359,   651,
     614,   650,   283,   257,   282,   302,   478,   155,   562,   584,
     303,   563,   304,   408,   305,   567,   368,   306,   560,   573,
     459,   465,   197,   146,   457,   535,    62,   579,   652,    62,
     580,   600,     0,    37,   635,    39,     0,     0,     0,     0,
      44,     0,     0,   377,     0,     0,     0,     0,     0,    62,
       0,   106,    62,   442,    62,   642,     0,    62,    49,    50,
      51,    52,    53,    54,   359,     0,    62,     0,   359,     0,
     613,   155,     0,   615,     0,   155,     0,   359,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   623,     0,     0,
     624,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,     0,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,     0,
       0,     0,     0,   454,     0,     0,   197,     0,     0,     0,
       0,     0,     0,     0,     0,   155,     0,     0,     0,     0,
       0,  -363,   145,     0,     2,     3,     4,     5,     6,     7,
     377,     8,     9,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,     0,    46,     0,    47,  -210,     0,  -210,     0,    48,
       0,     0,     0,     0,     0,     0,    49,    50,    51,    52,
      53,    54,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,     0,   105,     3,     4,     5,     6,
       7,   428,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   241,    11,     0,     0,     0,     0,     0,     0,
       0,   155,     0,     0,     0,     0,     0,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,   200,    44,
       2,     3,     4,     5,     6,     7,   155,     8,     9,     0,
      48,     0,     0,     0,     0,     0,     0,    49,    50,    51,
      52,    53,    54,     0,   155,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,   202,   203,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,   213,   214,   215,     0,
      47,   216,   217,   456,     0,    48,     0,     0,     0,   103,
       0,     0,    49,    50,    51,    52,    53,    54,     0,     0,
     200,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,     0,     0,   155,   428,     0,   428,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,   202,   203,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,   213,   214,
     215,     0,    47,   216,   217,     0,     0,    48,     0,     0,
       0,   103,     0,     0,    49,    50,    51,    52,    53,    54,
       1,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,     0,
      46,     0,    47,     0,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
     136,     0,   105,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
      11,     0,     0,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   200,     0,     2,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,    37,
      38,    39,     0,     0,     0,    43,    44,     0,     0,     0,
       0,     0,     0,     0,   201,    11,     0,    48,     0,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,     0,    37,     0,    39,     0,     0,     0,
       0,    44,     0,   213,   214,   215,     0,    47,   216,   217,
       0,     0,    48,     0,     0,     0,   103,     0,     0,    49,
      50,    51,    52,    53,    54,   105,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,   105,     3,     4,     5,     6,     7,   217,     8,     9,
      48,     0,     0,     0,     0,     0,     0,    49,    50,    51,
      52,    53,    54,     0,     0,     0,     0,     0,   186,    11,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   105,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,    37,    38,
      39,     0,     0,     0,    43,    44,     0,     0,     0,     0,
       0,   241,    11,     0,     0,   389,    48,     0,     0,    18,
      19,    20,     0,    49,    50,    51,    52,    53,    54,     0,
       0,     0,     0,     0,     0,   105,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,    37,   310,    39,     0,     0,     0,    43,    44,     0,
       0,     0,   241,    11,     0,     0,   411,     0,     0,    48,
      18,    19,    20,     0,     0,   390,   391,    50,    51,    52,
      53,    54,     0,     0,     0,     0,   105,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    37,   310,    39,     0,     0,     0,    43,    44,
       0,     0,     0,   241,    11,     0,     0,   492,     0,     0,
      48,    18,    19,    20,     0,     0,   412,   413,    50,    51,
      52,    53,    54,     0,     0,     0,     0,   105,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,    37,   310,    39,     0,     0,     0,    43,
      44,     0,     0,     0,   241,    11,     0,     0,   496,     0,
       0,    48,    18,    19,    20,     0,     0,   493,    49,    50,
      51,    52,    53,    54,     0,     0,     0,     0,   105,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,    37,   310,    39,     0,     0,     0,
      43,    44,     0,     0,     0,   241,    11,     0,     0,   511,
       0,     0,    48,    18,    19,    20,     0,     0,   497,   498,
      50,    51,    52,    53,    54,     0,     0,     0,     0,   105,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,    37,   310,    39,     0,     0,
       0,    43,    44,     0,     0,     0,   241,    11,     0,     0,
     571,     0,     0,    48,    18,    19,    20,     0,     0,   512,
     513,    50,    51,    52,    53,    54,     0,     0,     0,     0,
     105,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,    37,   310,    39,     0,
       0,     0,    43,    44,     0,     0,     0,   241,    11,     0,
       0,     0,     0,     0,    48,    18,    19,    20,     0,     0,
     572,    49,    50,    51,    52,    53,    54,     0,   105,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,   310,    39,
       0,     0,     0,    43,    44,   241,    11,     0,     0,   105,
       3,     4,     5,     6,     7,    48,     8,     9,     0,     0,
       0,     0,    49,    50,    51,    52,    53,    54,     0,     0,
       0,     0,     0,     0,     0,     0,   241,    11,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,   547,     0,    48,     0,     0,   356,   357,   358,     0,
      49,    50,    51,    52,    53,    54,    37,     0,    39,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       0,     0,   611,     0,    48,     0,     0,   356,   357,   358,
       0,    49,    50,    51,    52,    53,    54,   105,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     3,     4,     5,     6,     7,
       0,     8,     9,     0,   241,    11,     0,     0,   105,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,   241,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,    11,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    48,    39,     0,   356,   357,   358,    44,    49,
      50,    51,    52,    53,    54,    37,     0,    39,   260,    48,
       0,     0,    44,   242,     0,     0,    49,    50,    51,    52,
      53,    54,   281,    48,     0,     0,     0,   242,     0,     0,
      49,    50,    51,    52,    53,    54,   105,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,   105,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,   241,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   241,    11,     0,     0,
     105,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    39,     0,   241,    11,     0,
      44,     0,     0,     0,     0,   440,    37,     0,    39,     0,
     441,    48,     0,    44,     0,     0,     0,     0,    49,    50,
      51,    52,    53,    54,    48,     0,     0,     0,   242,     0,
       0,    49,    50,    51,    52,    53,    54,    37,     0,    39,
       0,     0,     0,     0,    44,   105,     3,     4,     5,     6,
       7,     0,     8,     9,     0,    48,     0,     0,     0,     0,
       0,   284,   285,    50,    51,    52,    53,    54,     0,     0,
       0,     0,   241,    11,     0,     0,   105,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
     105,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,   241,    11,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    39,     0,     0,   241,    11,    44,
       0,   105,     3,     4,     5,     6,     7,   342,     8,     9,
      48,     0,     0,     0,     0,     0,     0,    49,    50,    51,
      52,    53,    54,    37,     0,    39,     0,     0,   241,    11,
      44,     0,     0,     0,     0,     0,     0,    37,     0,    39,
       0,    48,     0,     0,    44,   357,     0,     0,    49,    50,
      51,    52,    53,    54,   447,    48,     0,     0,     0,     0,
       0,     0,    49,    50,    51,    52,    53,    54,    37,     0,
      39,     0,     0,     0,     0,    44,     0,   105,     3,     4,
       5,     6,     7,   217,     8,     9,    48,     0,     0,     0,
       0,     0,     0,    49,    50,    51,    52,    53,    54,     0,
       0,     0,     0,     0,   241,    11,     0,     0,   105,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,   105,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,   241,    11,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    39,     0,     0,   241,
      11,    44,     0,     0,     0,     0,   440,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,    49,
      50,    51,    52,    53,    54,    37,     0,    39,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,    37,
       0,    39,   606,    48,     0,     0,    44,     0,     0,     0,
      49,    50,    51,    52,    53,    54,   609,    48,     0,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
     105,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,   105,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,   241,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,   105,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,   105,     3,
       4,     5,     6,     7,     0,     8,     9,    37,     0,    39,
       0,     0,    11,     0,    44,     0,     0,     0,     0,     0,
      37,     0,    39,     0,     0,    48,    11,    44,     0,     0,
       0,     0,    49,    50,    51,    52,    53,    54,    48,     0,
       0,     0,   242,     0,     0,    49,    50,    51,    52,    53,
      54,    37,     0,    39,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,    37,     0,    39,     0,   109,
     124,     0,    44,     0,     0,     0,    49,    50,    51,    52,
      53,    54,     0,    48,     0,     0,     0,     0,     0,     0,
      49,    50,    51,    52,    53,    54,     0,   557,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,   502,    36,   503,    38,     0,
      40,     0,    42,    43,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,   383,   480,     0,     0,     0,     0,
     269,     0,   179,     0,   186,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     321,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,     0,    36,     0,    38,     0,    40,     0,    42,
      43,     0,    45,     0,     0,     0,     0,     0,     0,   186,
       0,   504,     0,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   425,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,    41,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,   186,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    41,   186,
      43,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   382,     0,    36,     0,
      38,     0,    40,     0,    42,    43,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,   383,   268,     0,     0,
       0,     0,   269,   186,   179,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,     0,    38,     0,    40,    41,    42,    43,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,   103,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,     0,    36,     0,    38,     0,    40,     0,    42,
      43,     0,    45,     0,   186,     0,     0,     0,     0,     0,
       0,   565,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    41,     0,
      43,     0,     0,   186,     0,     0,     0,     0,     0,     0,
     418,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    41,     0,    43,
       0,     0,   186,     0,     0,     0,     0,     0,     0,   427,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,    41,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,   186,   521,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   559,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,     0,    36,     0,    38,     0,
      40,     0,    42,    43,   186,    45,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,    38,   186,    40,     0,    42,
      43,     0,    45,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,     0,    38,     0,     0,
      41,     0,    43,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,     0,    38,     0,     0,     0,
       0,    43,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
      43
};

static const yytype_int16 yycheck[] =
{
       0,    63,   128,   185,     0,    48,   132,   177,   270,    79,
     123,    48,   259,   183,   132,   142,    93,   142,   367,   349,
       3,     1,   316,   410,    64,   141,   189,   143,   194,     3,
      95,   194,     3,    86,     3,   322,    89,     3,   269,    35,
     327,   154,     0,    19,    85,    86,    87,    30,    97,    98,
      19,    92,   179,    48,    85,    55,    30,    92,    89,    55,
      88,    30,     4,   106,    30,    93,   109,     3,   362,   106,
      88,     3,   109,   189,    95,    93,   202,   108,   194,    88,
     101,   102,    62,    79,   202,    88,    88,   318,    84,     3,
      93,   128,   129,   130,    90,    95,     4,    55,    30,     0,
       3,   271,    85,     3,   141,    88,   143,    90,   495,   152,
      88,   106,    95,    93,   109,     3,    30,   157,   158,   159,
      88,   470,   199,   453,    90,   455,    92,   197,    97,   376,
      30,   107,   175,   128,   129,   130,    88,   108,   462,   426,
       3,   268,   207,     3,   314,    87,   141,   317,   143,    85,
     320,   147,   189,    89,    55,   151,    88,   194,   389,   322,
     326,   238,   275,   326,   327,   145,   397,    30,   462,   212,
      30,    85,    93,     3,    88,    88,     3,    14,    15,    87,
     411,    95,   178,    86,   179,   479,   313,     3,    88,   185,
      96,    89,    89,    93,   189,    95,    94,    94,    86,   194,
      30,   197,   328,    30,    85,    85,   322,   207,    89,    89,
     326,   327,    85,   209,    30,   105,    89,   387,    88,   199,
     482,   545,   123,    93,    88,    95,   396,    85,    88,    92,
     131,    89,   358,    93,   135,   275,    12,    13,   238,   365,
     358,   354,   355,    18,    85,   315,    87,   365,    89,   150,
     420,   545,     3,   154,   324,   549,    91,   384,    93,   384,
     106,    88,    92,   426,   558,   496,   103,   104,    95,   334,
      16,    17,   349,   108,   269,   352,    92,   403,    86,    30,
      87,    89,    89,   348,    86,   322,    85,    89,    86,   326,
     327,    89,   335,   336,   337,   421,     0,    38,    39,    40,
     482,     3,   345,   421,    89,    90,   349,   377,    92,    87,
     426,    89,    89,    87,   384,    89,   335,   336,   313,   315,
      87,    86,    89,   318,     9,    10,    11,   322,   324,    92,
      71,   326,   327,    87,   334,    76,   373,    88,    87,    90,
      89,   242,    87,    87,    95,    89,    88,   517,   348,    87,
      85,    89,   352,   480,    95,     3,     4,     5,     6,     7,
     356,    87,    90,    89,     0,   266,   428,   432,   269,   164,
     165,   166,   167,    87,    85,    89,   441,    87,   373,    89,
      88,   377,   447,    31,   454,   450,   168,   169,   384,   426,
     560,   160,   161,   519,   389,    88,   522,   523,   393,   525,
      88,   519,   397,    88,   162,   163,    91,    85,    93,   522,
      90,   523,    88,   525,    88,   316,   411,   318,    88,    55,
     415,    88,    48,    87,    72,    87,   108,   540,    87,    87,
      87,   426,   432,     9,    10,    11,    87,    89,    87,    89,
      88,   441,    86,   344,    80,    81,    87,   447,   518,    94,
     450,    87,    88,    89,   108,    90,   357,    93,   454,   524,
      62,   362,   527,   528,   529,    85,     6,    92,   533,   108,
      87,    89,   537,   538,    87,    94,    90,    87,    94,   380,
     106,    86,    94,   109,   480,    94,   482,   530,   389,    87,
      82,    88,   393,    88,   489,   608,   397,   540,   541,    87,
     543,   496,   128,   129,   130,   500,    90,    94,    90,    87,
     411,    94,    88,   508,   415,    91,   553,    93,    94,   108,
      94,    94,   518,    94,   524,    87,    87,   527,   528,   529,
       7,     8,     9,   533,    94,   531,    94,   537,   538,    94,
      85,   606,    94,    94,   609,    87,     3,     4,     5,     6,
       7,     8,     3,    10,    11,    94,    94,    94,   553,    94,
      60,   462,    90,   199,   629,   608,    87,   632,    94,   634,
      94,    85,   637,   568,    31,    87,    93,    87,   479,    90,
     553,   646,   151,   133,   150,   170,   380,    64,   489,   518,
     171,   492,   172,   315,   173,   496,   249,   174,   485,   500,
     357,   363,   238,    55,   352,   445,   606,   508,   651,   609,
     511,   534,    -1,    70,   608,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,   629,
      -1,    88,   632,   534,   634,   631,    -1,   637,    95,    96,
      97,    98,    99,   100,   545,    -1,   646,    -1,   549,    -1,
     551,   128,    -1,   554,    -1,   132,    -1,   558,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   568,    -1,    -1,
     571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,   349,    -1,    -1,   352,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
     376,    10,    11,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    -1,    81,    -1,    83,    90,    -1,    92,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,   328,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   358,    -1,    -1,    -1,    -1,    -1,    -1,   365,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,     1,    77,
       3,     4,     5,     6,     7,     8,   403,    10,    11,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    -1,   421,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,
      -1,    -1,    95,    96,    97,    98,    99,   100,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   519,    -1,    -1,   522,   523,    -1,   525,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    83,    84,    85,    -1,    -1,    88,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    97,    98,    99,   100,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    -1,
      81,    -1,    83,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    77,    -1,    79,    80,    81,    -1,    83,    84,    85,
      -1,    -1,    88,    -1,    -1,    -1,    92,    -1,    -1,    95,
      96,    97,    98,    99,   100,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     3,     4,     5,     6,     7,     8,    85,    10,    11,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    34,    88,    -1,    -1,    38,
      39,    40,    -1,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    30,    31,    -1,    -1,    34,    -1,    -1,    88,
      38,    39,    40,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    77,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,    -1,
      88,    38,    39,    40,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
      77,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,
      -1,    88,    38,    39,    40,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    77,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,
      -1,    -1,    88,    38,    39,    40,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    30,    31,    -1,    -1,
      34,    -1,    -1,    88,    38,    39,    40,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    77,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    88,    38,    39,    40,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    77,    30,    31,    -1,    -1,     3,
       4,     5,     6,     7,     8,    88,    10,    11,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    88,    -1,    -1,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,   100,    70,    -1,    72,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    88,    -1,    -1,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,   100,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    30,    31,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    88,    72,    -1,    91,    92,    93,    77,    95,
      96,    97,    98,    99,   100,    70,    -1,    72,    87,    88,
      -1,    -1,    77,    92,    -1,    -1,    95,    96,    97,    98,
      99,   100,    87,    88,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    97,    98,    99,   100,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    30,    31,    -1,
      77,    -1,    -1,    -1,    -1,    82,    70,    -1,    72,    -1,
      87,    88,    -1,    77,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    88,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    97,    98,    99,   100,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    30,    31,    77,
      -1,     3,     4,     5,     6,     7,     8,    85,    10,    11,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    70,    -1,    72,    -1,    -1,    30,    31,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    88,    -1,    -1,    77,    92,    -1,    -1,    95,    96,
      97,    98,    99,   100,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,    70,    -1,
      72,    -1,    -1,    -1,    -1,    77,    -1,     3,     4,     5,
       6,     7,     8,    85,    10,    11,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    30,
      31,    77,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    87,    88,    -1,    -1,    77,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,    87,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    70,    -1,    72,
      -1,    -1,    31,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    88,    31,    77,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,    88,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    97,    98,    99,
     100,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    88,
       3,    -1,    77,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,     1,    69,     3,    71,    -1,
      73,    -1,    75,    76,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,
      93,    -1,    95,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    -1,    71,    -1,    73,    -1,    75,
      76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    30,
      76,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    -1,    73,    -1,    75,    76,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,
      -1,    -1,    93,    30,    95,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    -1,    73,    74,    75,    76,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    92,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    -1,    71,    -1,    73,    -1,    75,
      76,    -1,    78,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      76,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    86,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,
      73,    -1,    75,    76,    30,    78,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    30,    73,    -1,    75,
      76,    -1,    78,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    71,    -1,    -1,
      74,    -1,    76,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    71,    -1,    -1,    -1,
      -1,    76,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    10,    11,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    81,    83,    88,    95,
      96,    97,    98,    99,   100,   110,   111,   113,   115,   116,
     119,   121,   122,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   144,   145,
     148,   149,   150,   151,   152,   158,   161,   162,   163,   164,
     167,   183,   196,   197,   198,   201,   202,   215,   218,   219,
     220,   221,   222,    92,   186,     3,    88,   122,   126,    88,
     126,   126,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,   108,   141,     3,    30,    92,   167,    88,    88,
      88,    88,    88,    93,    88,    88,     1,    30,   112,   140,
     142,   149,   155,   162,   174,     1,   196,     9,    10,    11,
      88,    91,    93,   186,   141,   126,   128,    95,   101,   102,
      97,    98,    12,    13,    14,    15,   103,   104,    16,    17,
      96,   105,   106,    18,    19,   107,    85,    85,    88,    95,
     146,   147,   165,   166,   167,   168,    30,   145,   145,    92,
     167,   145,   145,   145,    92,   167,   144,   145,   186,   199,
       1,    30,    57,    58,    59,    61,    62,    63,    64,    65,
      66,    67,    68,    79,    80,    81,    84,    85,   142,   167,
     184,   185,   186,   190,   191,   192,   193,   194,   195,   200,
     202,   203,   210,   211,   212,   213,     0,    86,   187,   174,
     174,    30,    92,   120,   140,     3,   114,   159,   160,    92,
     139,   143,   174,   174,   174,   140,   143,   119,     4,    87,
      87,   120,   124,   125,   140,    87,    89,   155,    88,    93,
     168,   175,   176,   177,   155,    87,    85,    86,    87,   123,
     167,    87,   124,   123,    94,    95,   142,   120,   140,   128,
     128,   128,   129,   129,   130,   130,   131,   131,   131,   131,
     132,   132,   133,   134,   135,   136,   137,   142,   177,   165,
      71,   162,   168,   169,    85,    89,   108,    88,    93,   177,
     166,     1,   153,   154,   155,   183,    92,   153,    88,   165,
     144,   186,    85,   143,    90,    88,    88,    88,   184,   167,
      85,    85,    85,   142,    88,    88,    88,    85,    90,    88,
     144,   184,   188,   189,    87,    87,    91,    92,    93,   140,
     178,   179,   180,   181,   182,   108,    86,    89,   159,    87,
      87,    87,    87,    89,    89,    94,    87,   145,   198,    87,
      89,   140,    67,    87,   145,   170,   171,   172,   175,    34,
      94,    95,   140,   169,   176,   177,    88,    93,   120,   128,
      87,    94,    94,    90,    87,   162,   168,   177,   147,   178,
     177,    34,    94,    95,   140,   169,   177,    86,    86,   154,
      85,    90,   156,   157,   165,     1,   153,    86,   126,   139,
     216,   217,    90,   184,   112,   112,   142,    62,    85,    85,
      82,    87,   140,   204,   205,   206,   207,    87,   142,     4,
      87,   184,   142,   144,   145,   190,    86,   189,   167,   179,
     143,    86,    89,   178,   108,   182,   143,    86,   160,    86,
      89,    58,   117,   118,   174,     6,   198,   165,   125,   108,
      88,   165,   168,   175,    87,    89,   177,    87,   140,   169,
      94,    94,    34,    94,   140,   177,    34,    94,    95,   140,
     169,   139,     1,     3,    87,   170,   173,   140,   169,    94,
      94,    34,    94,    95,   140,   177,   143,    85,    89,    90,
      86,    86,   141,    85,    87,    89,   184,    87,    87,    87,
      88,    88,   184,    87,    89,   207,   184,    87,    87,   184,
       3,   190,   165,   190,    86,    89,    94,    86,   178,   180,
      86,    90,    87,    89,    90,    87,   178,    30,   108,    56,
     172,    94,   140,   140,    94,    87,   170,   140,   169,    94,
      94,    34,    94,   140,    87,    87,    87,    89,    94,   140,
     140,    94,    94,   177,   157,   143,   120,   139,   217,   184,
     217,   184,   184,   184,   142,    19,    97,   167,   208,   184,
     205,   184,   184,   120,   142,   214,    87,   142,     3,    87,
     142,    86,   178,   140,   118,   140,    85,   178,   177,    94,
      94,    87,    94,   140,   140,    94,     3,    94,    94,    60,
      87,    90,    87,   184,    87,   214,   184,    87,    94,    94,
     184,    85,   167,   209,   184,   184,    87,   184,    93,    87,
     184,    90,   142,    94
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   109,   110,   110,   110,   110,   110,   111,   111,   111,
     111,   111,   112,   112,   113,   113,   113,   114,   115,   115,
     116,   117,   117,   118,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   121,   121,   121,   122,   122,
     123,   124,   124,   124,   125,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   127,   127,   127,   127,   127,   127,
     128,   128,   129,   129,   129,   129,   130,   130,   130,   131,
     131,   131,   132,   132,   132,   132,   132,   133,   133,   133,
     134,   134,   135,   135,   136,   136,   137,   137,   138,   138,
     139,   139,   140,   140,   140,   140,   140,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   142,   142,
     143,   144,   144,   144,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   146,   146,   147,   147,   148,   148,
     148,   148,   148,   148,   148,   149,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   151,   151,   151,   151,   151,   152,   152,   153,
     153,   154,   154,   154,   155,   155,   155,   155,   156,   156,
     157,   157,   157,   158,   158,   158,   158,   158,   159,   159,
     160,   160,   161,   162,   162,   162,   162,   162,   163,   163,
     164,   164,   165,   165,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   167,
     167,   168,   168,   168,   168,   169,   169,   170,   170,   171,
     171,   172,   172,   172,   172,   172,   173,   173,   174,   174,
     175,   175,   175,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   177,   178,   178,   178,   179,   179,
     179,   179,   180,   181,   181,   182,   182,   183,   184,   184,
     184,   184,   184,   184,   184,   184,   185,   185,   185,   186,
     187,   186,   188,   188,   189,   189,   190,   190,   191,   191,
     191,   192,   193,   193,   193,   193,   193,   194,   194,   195,
     195,   195,   195,   195,   196,   196,   196,   196,   196,   196,
     196,   196,   197,   198,   198,   199,   199,   200,   200,   200,
     200,   200,   200,   200,   201,   201,   202,   202,   203,   203,
     204,   204,   205,   205,   206,   206,   207,   208,   208,   208,
     209,   209,   210,   210,   211,   211,   212,   213,   214,   214,
     215,   216,   216,   216,   217,   217,   217,   218,   219,   219,
     220,   221,   221,   222
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       2,     2,     4,     3,     4,     3,     4,     4,     3,     4,
       1,     1,     3,     2,     1,     1,     1,     2,     2,     2,
       2,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     4,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     2,     4,     5,     1,     1,     1,
       2,     3,     4,     1,     2,     1,     2,     1,     1,     3,
       2,     3,     1,     4,     5,     5,     6,     2,     1,     3,
       3,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     3,     2,     1,     3,     3,     4,     6,     5,
       5,     6,     5,     4,     4,     5,     5,     4,     5,     1,
       1,     3,     2,     2,     1,     1,     2,     3,     1,     2,
       4,     2,     4,     2,     1,     3,     1,     3,     3,     2,
       2,     1,     1,     3,     2,     3,     5,     4,     5,     4,
       3,     3,     3,     4,     6,     5,     5,     6,     4,     4,
       2,     3,     4,     5,     0,     3,     4,     1,     2,     1,
       4,     3,     2,     1,     2,     3,     2,     7,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     3,     2,
       0,     4,     1,     2,     1,     1,     1,     2,     7,     5,
       5,     1,     5,     7,     6,     7,     1,     6,     7,     3,
       2,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     2,     2,     4,     5,
       1,     3,     1,     1,     1,     2,     6,     1,     1,     1,
       1,     5,     4,     5,     4,     5,     8,     7,     1,     1,
       6,     1,     3,     3,     1,     3,     3,     2,     4,     5,
       4,     1,     4,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (parse, root, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, parse, root); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, AstRoot * parse, Ast * root)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (parse);
  YY_USE (root);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_IDENTIFIER: /* IDENTIFIER  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 1999 "basilisk.c"
        break;

    case YYSYMBOL_I_CONSTANT: /* I_CONSTANT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2008 "basilisk.c"
        break;

    case YYSYMBOL_F_CONSTANT: /* F_CONSTANT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2017 "basilisk.c"
        break;

    case YYSYMBOL_STRING_LITERAL: /* STRING_LITERAL  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2026 "basilisk.c"
        break;

    case YYSYMBOL_FUNC_NAME: /* FUNC_NAME  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2035 "basilisk.c"
        break;

    case YYSYMBOL_SIZEOF: /* SIZEOF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2044 "basilisk.c"
        break;

    case YYSYMBOL_PTR_OP: /* PTR_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2053 "basilisk.c"
        break;

    case YYSYMBOL_INC_OP: /* INC_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2062 "basilisk.c"
        break;

    case YYSYMBOL_DEC_OP: /* DEC_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2071 "basilisk.c"
        break;

    case YYSYMBOL_LEFT_OP: /* LEFT_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2080 "basilisk.c"
        break;

    case YYSYMBOL_RIGHT_OP: /* RIGHT_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2089 "basilisk.c"
        break;

    case YYSYMBOL_LE_OP: /* LE_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2098 "basilisk.c"
        break;

    case YYSYMBOL_GE_OP: /* GE_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2107 "basilisk.c"
        break;

    case YYSYMBOL_EQ_OP: /* EQ_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2116 "basilisk.c"
        break;

    case YYSYMBOL_NE_OP: /* NE_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2125 "basilisk.c"
        break;

    case YYSYMBOL_AND_OP: /* AND_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2134 "basilisk.c"
        break;

    case YYSYMBOL_OR_OP: /* OR_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2143 "basilisk.c"
        break;

    case YYSYMBOL_MUL_ASSIGN: /* MUL_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2152 "basilisk.c"
        break;

    case YYSYMBOL_DIV_ASSIGN: /* DIV_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2161 "basilisk.c"
        break;

    case YYSYMBOL_MOD_ASSIGN: /* MOD_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2170 "basilisk.c"
        break;

    case YYSYMBOL_ADD_ASSIGN: /* ADD_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2179 "basilisk.c"
        break;

    case YYSYMBOL_SUB_ASSIGN: /* SUB_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2188 "basilisk.c"
        break;

    case YYSYMBOL_LEFT_ASSIGN: /* LEFT_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2197 "basilisk.c"
        break;

    case YYSYMBOL_RIGHT_ASSIGN: /* RIGHT_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2206 "basilisk.c"
        break;

    case YYSYMBOL_AND_ASSIGN: /* AND_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2215 "basilisk.c"
        break;

    case YYSYMBOL_XOR_ASSIGN: /* XOR_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2224 "basilisk.c"
        break;

    case YYSYMBOL_OR_ASSIGN: /* OR_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2233 "basilisk.c"
        break;

    case YYSYMBOL_TYPEDEF_NAME: /* TYPEDEF_NAME  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2242 "basilisk.c"
        break;

    case YYSYMBOL_ENUMERATION_CONSTANT: /* ENUMERATION_CONSTANT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2251 "basilisk.c"
        break;

    case YYSYMBOL_TYPEDEF: /* TYPEDEF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2260 "basilisk.c"
        break;

    case YYSYMBOL_EXTERN: /* EXTERN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2269 "basilisk.c"
        break;

    case YYSYMBOL_STATIC: /* STATIC  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2278 "basilisk.c"
        break;

    case YYSYMBOL_AUTO: /* AUTO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2287 "basilisk.c"
        break;

    case YYSYMBOL_REGISTER: /* REGISTER  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2296 "basilisk.c"
        break;

    case YYSYMBOL_INLINE: /* INLINE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2305 "basilisk.c"
        break;

    case YYSYMBOL_CONST: /* CONST  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2314 "basilisk.c"
        break;

    case YYSYMBOL_RESTRICT: /* RESTRICT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2323 "basilisk.c"
        break;

    case YYSYMBOL_VOLATILE: /* VOLATILE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2332 "basilisk.c"
        break;

    case YYSYMBOL_BOOL: /* BOOL  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2341 "basilisk.c"
        break;

    case YYSYMBOL_CHAR: /* CHAR  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2350 "basilisk.c"
        break;

    case YYSYMBOL_SHORT: /* SHORT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2359 "basilisk.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2368 "basilisk.c"
        break;

    case YYSYMBOL_LONG: /* LONG  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2377 "basilisk.c"
        break;

    case YYSYMBOL_SIGNED: /* SIGNED  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2386 "basilisk.c"
        break;

    case YYSYMBOL_UNSIGNED: /* UNSIGNED  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2395 "basilisk.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2404 "basilisk.c"
        break;

    case YYSYMBOL_DOUBLE: /* DOUBLE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2413 "basilisk.c"
        break;

    case YYSYMBOL_VOID: /* VOID  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2422 "basilisk.c"
        break;

    case YYSYMBOL_COMPLEX: /* COMPLEX  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2431 "basilisk.c"
        break;

    case YYSYMBOL_IMAGINARY: /* IMAGINARY  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2440 "basilisk.c"
        break;

    case YYSYMBOL_STRUCT: /* STRUCT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2449 "basilisk.c"
        break;

    case YYSYMBOL_UNION: /* UNION  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2458 "basilisk.c"
        break;

    case YYSYMBOL_ENUM: /* ENUM  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2467 "basilisk.c"
        break;

    case YYSYMBOL_ELLIPSIS: /* ELLIPSIS  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2476 "basilisk.c"
        break;

    case YYSYMBOL_CASE: /* CASE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2485 "basilisk.c"
        break;

    case YYSYMBOL_DEFAULT: /* DEFAULT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2494 "basilisk.c"
        break;

    case YYSYMBOL_IF: /* IF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2503 "basilisk.c"
        break;

    case YYSYMBOL_ELSE: /* ELSE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2512 "basilisk.c"
        break;

    case YYSYMBOL_SWITCH: /* SWITCH  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2521 "basilisk.c"
        break;

    case YYSYMBOL_WHILE: /* WHILE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2530 "basilisk.c"
        break;

    case YYSYMBOL_DO: /* DO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2539 "basilisk.c"
        break;

    case YYSYMBOL_FOR: /* FOR  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2548 "basilisk.c"
        break;

    case YYSYMBOL_GOTO: /* GOTO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2557 "basilisk.c"
        break;

    case YYSYMBOL_CONTINUE: /* CONTINUE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2566 "basilisk.c"
        break;

    case YYSYMBOL_BREAK: /* BREAK  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2575 "basilisk.c"
        break;

    case YYSYMBOL_RETURN: /* RETURN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2584 "basilisk.c"
        break;

    case YYSYMBOL_ALIGNAS: /* ALIGNAS  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2593 "basilisk.c"
        break;

    case YYSYMBOL_ALIGNOF: /* ALIGNOF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2602 "basilisk.c"
        break;

    case YYSYMBOL_ATOMIC: /* ATOMIC  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2611 "basilisk.c"
        break;

    case YYSYMBOL_GENERIC: /* GENERIC  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2620 "basilisk.c"
        break;

    case YYSYMBOL_NORETURN: /* NORETURN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2629 "basilisk.c"
        break;

    case YYSYMBOL_STATIC_ASSERT: /* STATIC_ASSERT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2638 "basilisk.c"
        break;

    case YYSYMBOL_THREAD_LOCAL: /* THREAD_LOCAL  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2647 "basilisk.c"
        break;

    case YYSYMBOL_MAYBECONST: /* MAYBECONST  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2656 "basilisk.c"
        break;

    case YYSYMBOL_NEW_FIELD: /* NEW_FIELD  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2665 "basilisk.c"
        break;

    case YYSYMBOL_TRACE: /* TRACE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2674 "basilisk.c"
        break;

    case YYSYMBOL_FOREACH: /* FOREACH  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2683 "basilisk.c"
        break;

    case YYSYMBOL_FOREACH_INNER: /* FOREACH_INNER  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2692 "basilisk.c"
        break;

    case YYSYMBOL_FOREACH_DIMENSION: /* FOREACH_DIMENSION  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2701 "basilisk.c"
        break;

    case YYSYMBOL_REDUCTION: /* REDUCTION  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2710 "basilisk.c"
        break;

    case YYSYMBOL_MACRO: /* MACRO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2719 "basilisk.c"
        break;

    case YYSYMBOL_ELLIPSIS_MACRO: /* ELLIPSIS_MACRO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2728 "basilisk.c"
        break;

    case YYSYMBOL_85_: /* ';'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2737 "basilisk.c"
        break;

    case YYSYMBOL_86_: /* '}'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2746 "basilisk.c"
        break;

    case YYSYMBOL_87_: /* ')'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2755 "basilisk.c"
        break;

    case YYSYMBOL_88_: /* '('  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2764 "basilisk.c"
        break;

    case YYSYMBOL_89_: /* ','  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2773 "basilisk.c"
        break;

    case YYSYMBOL_90_: /* ':'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2782 "basilisk.c"
        break;

    case YYSYMBOL_91_: /* '.'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2791 "basilisk.c"
        break;

    case YYSYMBOL_92_: /* '{'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2800 "basilisk.c"
        break;

    case YYSYMBOL_93_: /* '['  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2809 "basilisk.c"
        break;

    case YYSYMBOL_94_: /* ']'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2818 "basilisk.c"
        break;

    case YYSYMBOL_95_: /* '*'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2827 "basilisk.c"
        break;

    case YYSYMBOL_96_: /* '&'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2836 "basilisk.c"
        break;

    case YYSYMBOL_97_: /* '+'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2845 "basilisk.c"
        break;

    case YYSYMBOL_98_: /* '-'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2854 "basilisk.c"
        break;

    case YYSYMBOL_99_: /* '~'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2863 "basilisk.c"
        break;

    case YYSYMBOL_100_: /* '!'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2872 "basilisk.c"
        break;

    case YYSYMBOL_101_: /* '/'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2881 "basilisk.c"
        break;

    case YYSYMBOL_102_: /* '%'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2890 "basilisk.c"
        break;

    case YYSYMBOL_103_: /* '<'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2899 "basilisk.c"
        break;

    case YYSYMBOL_104_: /* '>'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2908 "basilisk.c"
        break;

    case YYSYMBOL_105_: /* '^'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2917 "basilisk.c"
        break;

    case YYSYMBOL_106_: /* '|'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2926 "basilisk.c"
        break;

    case YYSYMBOL_107_: /* '?'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2935 "basilisk.c"
        break;

    case YYSYMBOL_108_: /* '='  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2944 "basilisk.c"
        break;

    case YYSYMBOL_translation_unit: /* translation_unit  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2953 "basilisk.c"
        break;

    case YYSYMBOL_primary_expression: /* primary_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2962 "basilisk.c"
        break;

    case YYSYMBOL_expression_error: /* expression_error  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2971 "basilisk.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2980 "basilisk.c"
        break;

    case YYSYMBOL_enumeration_constant: /* enumeration_constant  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2989 "basilisk.c"
        break;

    case YYSYMBOL_string: /* string  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2998 "basilisk.c"
        break;

    case YYSYMBOL_generic_selection: /* generic_selection  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3007 "basilisk.c"
        break;

    case YYSYMBOL_generic_assoc_list: /* generic_assoc_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3016 "basilisk.c"
        break;

    case YYSYMBOL_generic_association: /* generic_association  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3025 "basilisk.c"
        break;

    case YYSYMBOL_postfix_expression: /* postfix_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3034 "basilisk.c"
        break;

    case YYSYMBOL_postfix_initializer: /* postfix_initializer  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3043 "basilisk.c"
        break;

    case YYSYMBOL_array_access: /* array_access  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3052 "basilisk.c"
        break;

    case YYSYMBOL_function_call: /* function_call  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3061 "basilisk.c"
        break;

    case YYSYMBOL_member_identifier: /* member_identifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3070 "basilisk.c"
        break;

    case YYSYMBOL_argument_expression_list: /* argument_expression_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3079 "basilisk.c"
        break;

    case YYSYMBOL_argument_expression_list_item: /* argument_expression_list_item  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3088 "basilisk.c"
        break;

    case YYSYMBOL_unary_expression: /* unary_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3097 "basilisk.c"
        break;

    case YYSYMBOL_unary_operator: /* unary_operator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3106 "basilisk.c"
        break;

    case YYSYMBOL_cast_expression: /* cast_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3115 "basilisk.c"
        break;

    case YYSYMBOL_multiplicative_expression: /* multiplicative_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3124 "basilisk.c"
        break;

    case YYSYMBOL_additive_expression: /* additive_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3133 "basilisk.c"
        break;

    case YYSYMBOL_shift_expression: /* shift_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3142 "basilisk.c"
        break;

    case YYSYMBOL_relational_expression: /* relational_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3151 "basilisk.c"
        break;

    case YYSYMBOL_equality_expression: /* equality_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3160 "basilisk.c"
        break;

    case YYSYMBOL_and_expression: /* and_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3169 "basilisk.c"
        break;

    case YYSYMBOL_exclusive_or_expression: /* exclusive_or_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3178 "basilisk.c"
        break;

    case YYSYMBOL_inclusive_or_expression: /* inclusive_or_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3187 "basilisk.c"
        break;

    case YYSYMBOL_logical_and_expression: /* logical_and_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3196 "basilisk.c"
        break;

    case YYSYMBOL_logical_or_expression: /* logical_or_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3205 "basilisk.c"
        break;

    case YYSYMBOL_conditional_expression: /* conditional_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3214 "basilisk.c"
        break;

    case YYSYMBOL_assignment_expression: /* assignment_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3223 "basilisk.c"
        break;

    case YYSYMBOL_assignment_operator: /* assignment_operator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3232 "basilisk.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3241 "basilisk.c"
        break;

    case YYSYMBOL_constant_expression: /* constant_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3250 "basilisk.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3259 "basilisk.c"
        break;

    case YYSYMBOL_declaration_specifiers: /* declaration_specifiers  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3268 "basilisk.c"
        break;

    case YYSYMBOL_init_declarator_list: /* init_declarator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3277 "basilisk.c"
        break;

    case YYSYMBOL_init_declarator: /* init_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3286 "basilisk.c"
        break;

    case YYSYMBOL_storage_class_specifier: /* storage_class_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3295 "basilisk.c"
        break;

    case YYSYMBOL_type_specifier: /* type_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3304 "basilisk.c"
        break;

    case YYSYMBOL_types: /* types  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3313 "basilisk.c"
        break;

    case YYSYMBOL_struct_or_union_specifier: /* struct_or_union_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3322 "basilisk.c"
        break;

    case YYSYMBOL_struct_or_union: /* struct_or_union  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3331 "basilisk.c"
        break;

    case YYSYMBOL_struct_declaration_list: /* struct_declaration_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3340 "basilisk.c"
        break;

    case YYSYMBOL_struct_declaration: /* struct_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3349 "basilisk.c"
        break;

    case YYSYMBOL_specifier_qualifier_list: /* specifier_qualifier_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3358 "basilisk.c"
        break;

    case YYSYMBOL_struct_declarator_list: /* struct_declarator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3367 "basilisk.c"
        break;

    case YYSYMBOL_struct_declarator: /* struct_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3376 "basilisk.c"
        break;

    case YYSYMBOL_enum_specifier: /* enum_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3385 "basilisk.c"
        break;

    case YYSYMBOL_enumerator_list: /* enumerator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3394 "basilisk.c"
        break;

    case YYSYMBOL_enumerator: /* enumerator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3403 "basilisk.c"
        break;

    case YYSYMBOL_atomic_type_specifier: /* atomic_type_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3412 "basilisk.c"
        break;

    case YYSYMBOL_type_qualifier: /* type_qualifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3421 "basilisk.c"
        break;

    case YYSYMBOL_function_specifier: /* function_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3430 "basilisk.c"
        break;

    case YYSYMBOL_alignment_specifier: /* alignment_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3439 "basilisk.c"
        break;

    case YYSYMBOL_declarator: /* declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3448 "basilisk.c"
        break;

    case YYSYMBOL_direct_declarator: /* direct_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3457 "basilisk.c"
        break;

    case YYSYMBOL_generic_identifier: /* generic_identifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3466 "basilisk.c"
        break;

    case YYSYMBOL_pointer: /* pointer  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3475 "basilisk.c"
        break;

    case YYSYMBOL_type_qualifier_list: /* type_qualifier_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3484 "basilisk.c"
        break;

    case YYSYMBOL_parameter_type_list: /* parameter_type_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3493 "basilisk.c"
        break;

    case YYSYMBOL_parameter_list: /* parameter_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3502 "basilisk.c"
        break;

    case YYSYMBOL_parameter_declaration: /* parameter_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3511 "basilisk.c"
        break;

    case YYSYMBOL_identifier_list: /* identifier_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3520 "basilisk.c"
        break;

    case YYSYMBOL_type_name: /* type_name  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3529 "basilisk.c"
        break;

    case YYSYMBOL_abstract_declarator: /* abstract_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3538 "basilisk.c"
        break;

    case YYSYMBOL_direct_abstract_declarator: /* direct_abstract_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3547 "basilisk.c"
        break;

    case YYSYMBOL_type_not_specified: /* type_not_specified  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3556 "basilisk.c"
        break;

    case YYSYMBOL_initializer: /* initializer  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3565 "basilisk.c"
        break;

    case YYSYMBOL_initializer_list: /* initializer_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3574 "basilisk.c"
        break;

    case YYSYMBOL_designation: /* designation  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3583 "basilisk.c"
        break;

    case YYSYMBOL_designator_list: /* designator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3592 "basilisk.c"
        break;

    case YYSYMBOL_designator: /* designator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3601 "basilisk.c"
        break;

    case YYSYMBOL_static_assert_declaration: /* static_assert_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3610 "basilisk.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3619 "basilisk.c"
        break;

    case YYSYMBOL_labeled_statement: /* labeled_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3628 "basilisk.c"
        break;

    case YYSYMBOL_compound_statement: /* compound_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3637 "basilisk.c"
        break;

    case YYSYMBOL_187_1: /* @1  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3646 "basilisk.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3655 "basilisk.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3664 "basilisk.c"
        break;

    case YYSYMBOL_expression_statement: /* expression_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3673 "basilisk.c"
        break;

    case YYSYMBOL_selection_statement: /* selection_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3682 "basilisk.c"
        break;

    case YYSYMBOL_for_scope: /* for_scope  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3691 "basilisk.c"
        break;

    case YYSYMBOL_iteration_statement: /* iteration_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3700 "basilisk.c"
        break;

    case YYSYMBOL_for_declaration_statement: /* for_declaration_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3709 "basilisk.c"
        break;

    case YYSYMBOL_jump_statement: /* jump_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3718 "basilisk.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3727 "basilisk.c"
        break;

    case YYSYMBOL_function_declaration: /* function_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3736 "basilisk.c"
        break;

    case YYSYMBOL_function_definition: /* function_definition  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3745 "basilisk.c"
        break;

    case YYSYMBOL_declaration_list: /* declaration_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3754 "basilisk.c"
        break;

    case YYSYMBOL_basilisk_statements: /* basilisk_statements  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3763 "basilisk.c"
        break;

    case YYSYMBOL_macro_call: /* macro_call  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3772 "basilisk.c"
        break;

    case YYSYMBOL_macro_statement: /* macro_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3781 "basilisk.c"
        break;

    case YYSYMBOL_foreach_statement: /* foreach_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3790 "basilisk.c"
        break;

    case YYSYMBOL_foreach_parameters: /* foreach_parameters  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3799 "basilisk.c"
        break;

    case YYSYMBOL_foreach_parameter: /* foreach_parameter  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3808 "basilisk.c"
        break;

    case YYSYMBOL_reduction_list: /* reduction_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3817 "basilisk.c"
        break;

    case YYSYMBOL_reduction: /* reduction  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3826 "basilisk.c"
        break;

    case YYSYMBOL_reduction_operator: /* reduction_operator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3835 "basilisk.c"
        break;

    case YYSYMBOL_reduction_array: /* reduction_array  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3844 "basilisk.c"
        break;

    case YYSYMBOL_foreach_inner_statement: /* foreach_inner_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3853 "basilisk.c"
        break;

    case YYSYMBOL_foreach_dimension_statement: /* foreach_dimension_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3862 "basilisk.c"
        break;

    case YYSYMBOL_forin_declaration_statement: /* forin_declaration_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3871 "basilisk.c"
        break;

    case YYSYMBOL_forin_statement: /* forin_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3880 "basilisk.c"
        break;

    case YYSYMBOL_forin_arguments: /* forin_arguments  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3889 "basilisk.c"
        break;

    case YYSYMBOL_event_definition: /* event_definition  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3898 "basilisk.c"
        break;

    case YYSYMBOL_event_parameters: /* event_parameters  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3907 "basilisk.c"
        break;

    case YYSYMBOL_event_parameter: /* event_parameter  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3916 "basilisk.c"
        break;

    case YYSYMBOL_boundary_definition: /* boundary_definition  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3925 "basilisk.c"
        break;

    case YYSYMBOL_external_foreach_dimension: /* external_foreach_dimension  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3934 "basilisk.c"
        break;

    case YYSYMBOL_attribute: /* attribute  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3943 "basilisk.c"
        break;

    case YYSYMBOL_new_field: /* new_field  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3952 "basilisk.c"
        break;

    case YYSYMBOL_root: /* root  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3961 "basilisk.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, AstRoot * parse, Ast * root)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, parse, root);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, AstRoot * parse, Ast * root)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], parse, root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parse, root); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, AstRoot * parse, Ast * root)
{
  YY_USE (yyvaluep);
  YY_USE (parse);
  YY_USE (root);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (AstRoot * parse, Ast * root)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, parse);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


 YY_REDUCE_PRINT (yyn); DEFAULT_ACTION (yyn);
  switch (yyn)
    {
  case 4: /* translation_unit: translation_unit error ';'  */
#line 112 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4357 "basilisk.c"
    break;

  case 5: /* translation_unit: translation_unit error '}'  */
#line 113 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4363 "basilisk.c"
    break;

  case 6: /* translation_unit: translation_unit error ')'  */
#line 114 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4369 "basilisk.c"
    break;

  case 13: /* expression_error: error  */
#line 127 "basilisk.yacc"
                        { yyvsp[0]->sym = YYSYMBOL_YYerror; }
#line 4375 "basilisk.c"
    break;

  case 111: /* declaration: declaration_specifiers ';' type_not_specified  */
#line 323 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 4381 "basilisk.c"
    break;

  case 112: /* declaration: declaration_specifiers init_declarator_list ';' type_not_specified  */
#line 324 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 4387 "basilisk.c"
    break;

  case 135: /* type_specifier: types  */
#line 362 "basilisk.yacc"
                   { parse->type_already_specified = true; }
#line 4393 "basilisk.c"
    break;

  case 155: /* struct_or_union_specifier: struct_or_union '{' error '}'  */
#line 388 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4399 "basilisk.c"
    break;

  case 156: /* struct_or_union_specifier: struct_or_union generic_identifier '{' error '}'  */
#line 389 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4405 "basilisk.c"
    break;

  case 206: /* direct_declarator: direct_declarator '(' type_not_specified error ')'  */
#line 484 "basilisk.yacc"
                                                                                           { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4411 "basilisk.c"
    break;

  case 254: /* type_not_specified: %empty  */
#line 565 "basilisk.yacc"
           { parse->type_already_specified = false; }
#line 4417 "basilisk.c"
    break;

  case 275: /* statement: error ';'  */
#line 607 "basilisk.yacc"
                     { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4423 "basilisk.c"
    break;

  case 280: /* @1: %empty  */
#line 619 "basilisk.yacc"
                           { stack_push (parse->stack, &(yyvsp[0])); yyval->sym = YYSYMBOL_YYUNDEF; }
#line 4429 "basilisk.c"
    break;

  case 281: /* compound_statement: '{' @1 block_item_list '}'  */
#line 621 "basilisk.yacc"
                           { ast_pop_scope (parse->stack, yyvsp[-3]); }
#line 4435 "basilisk.c"
    break;

  case 291: /* for_scope: FOR  */
#line 646 "basilisk.yacc"
              { stack_push (parse->stack, &(yyval)); }
#line 4441 "basilisk.c"
    break;

  case 294: /* iteration_statement: for_scope '(' expression_statement expression_statement ')' statement  */
#line 653 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 4447 "basilisk.c"
    break;

  case 295: /* iteration_statement: for_scope '(' expression_statement expression_statement expression ')' statement  */
#line 655 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 4453 "basilisk.c"
    break;

  case 297: /* for_declaration_statement: for_scope '(' declaration expression_statement ')' statement  */
#line 661 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 4459 "basilisk.c"
    break;

  case 298: /* for_declaration_statement: for_scope '(' declaration expression_statement expression ')' statement  */
#line 663 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 4465 "basilisk.c"
    break;

  case 311: /* external_declaration: error compound_statement  */
#line 682 "basilisk.yacc"
                                                { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4471 "basilisk.c"
    break;

  case 312: /* function_declaration: declaration_specifiers declarator  */
#line 686 "basilisk.yacc"
                                            { ast_push_function_definition (parse->stack, yyvsp[0]);  }
#line 4477 "basilisk.c"
    break;

  case 313: /* function_definition: function_declaration declaration_list compound_statement  */
#line 691 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-2]->child[1]); }
#line 4483 "basilisk.c"
    break;

  case 314: /* function_definition: function_declaration compound_statement  */
#line 693 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-1]->child[1]); }
#line 4489 "basilisk.c"
    break;

  case 346: /* forin_declaration_statement: for_scope '(' declaration_specifiers declarator IDENTIFIER forin_arguments ')' statement  */
#line 771 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-7]); }
#line 4495 "basilisk.c"
    break;

  case 347: /* forin_statement: for_scope '(' expression IDENTIFIER forin_arguments ')' statement  */
#line 776 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 4501 "basilisk.c"
    break;

  case 363: /* root: translation_unit  */
#line 819 "basilisk.yacc"
                           {
	  yyval = root;
	  yyval->sym = yyr1[yyn];
	  yyval->child = allocate ((Allocator *)parse->alloc, 2*sizeof(Ast *));
	  yyval->child[0] = yyvsp[0];
	  yyvsp[0]->parent = yyval;
	  yyval->child[1] = NULL;
        }
#line 4514 "basilisk.c"
    break;


#line 4518 "basilisk.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (parse, root, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, parse, root);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, parse, root);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (parse, root, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parse, root);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, parse, root);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 829 "basilisk.yacc"


/**
# Parsing functions */

/* Called by yyparse on error.  */
void
yyerror (AstRoot * parse, Ast * root, char const *s)
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

static char * copy_range (const char * start, const char * end, long offset)
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

static const char * copy_strings (const char * i, Ast * n, long offset)
{
  AstTerminal * t = ast_terminal (n);
  if (t) {
    t->before = copy_range (i, t->start, offset);
    if (t->start > i)
      i = t->start;

    t->start = copy_range (i, t->after + 1, offset);
    if (t->after + 1 > i)
      i = t->after + 1;
    t->after = NULL;
  }
  else
    for (Ast ** c = n->child; *c; c++)
      i = copy_strings (i, *c, offset);
  return i;
}

static void remove_child (Ast * c)
{
  if (!c->parent)
    return;
  Ast ** i = c->parent->child;
  for (; *i && *i != c; i++);
  assert (*i == c);
  for (; *i; i++)
    *i = *(i + 1);
  c->parent = NULL;
}

static Ast * ast_reduce (Allocator * alloc, int sym, Ast ** children, int n)
{
  Ast * ast = allocate (alloc, sizeof(Ast));
  memset (ast, 0, sizeof(Ast));
  ast->sym = sym;
  int ndef = 0;
  for (int i = 0; i < n; i++) {
    Ast * c = children[i + 1 - n];
    if (c->sym != YYSYMBOL_YYUNDEF && c->sym != YYSYMBOL_type_not_specified)
      ndef++;
  }
  ast->child = allocate (alloc, (ndef + 1)*sizeof(Ast *));
  ndef = 0;
  for (int i = 0; i < n; i++) {
    Ast * c = children[i + 1 - n];
    if (c->sym != YYSYMBOL_YYUNDEF && c->sym != YYSYMBOL_type_not_specified) {
      if (c->parent)
	remove_child (c);
      c->parent = ast;
      ast->child[ndef++] = c;
    }
    else
      assert (!c->parent);
  }
  ast->child[ndef] = NULL;
  return ast;
}

static Stack * stack_internalize (Stack * stack)
{
  Ast ** n;
  for (int i = 0; (n = stack_index (stack, i)); i++)
    if ((*n)->sym == YYSYMBOL_IDENTIFIER) {
      AstTerminal * t = ast_terminal (*n);
      char * after = t->start + strlen (t->start) - 1;
      if (t->after != NULL && t->after != after) {
	fprintf (stderr, "%s:%d: %s after: %s\n",
		 t->file, t->line, t->start, t->after);
	abort();
      }
      t->after = after;
    }
  return stack;
}

static void stack_externalize (Stack * stack)
{
  Ast ** n;
  for (int i = 0; (n = stack_index (stack, i)); i++)
    if ((*n)->sym == YYSYMBOL_IDENTIFIER) {
      AstTerminal * t = ast_terminal(*n);
      if (t->after != NULL) {
	if (t->after[1] != '\0') {
	  
	  /**
	  This is a declaration which has not been through
	  copy_strings() i.e. which is not connected to the root, due
	  to a syntax error which lead to the corresponding branch being
	  discarded. We set the symbol to UNDEF. */

	  t->start = t->before = NULL;
	  (*n)->sym = YYSYMBOL_YYUNDEF;
	}
	t->after = NULL;
      }
    }
}

AstRoot * ast_parse (const char * code, AstRoot * parent)
{
  AstRoot parse;
  parse.alloc = parent ? parent->alloc : new_allocator();
  parse.stack = parent ? parent->stack : stack_new (sizeof (Ast *));
  parse.file = allocate (parse.alloc, strlen ("<basilisk>") + 1);
  strcpy ((char *) parse.file, "<basilisk>");
  stack_internalize (parse.stack);
  parse.type_already_specified = false;
  extern void lexer_setup (char * buffer, size_t len);
  size_t len = strlen (code) + 1;
  char * buffer = malloc (len + 1);
  memcpy (buffer, code, len);
  buffer[len] = '\0';
  lexer_setup (buffer, len + 1);
  //  yydebug = 1;
  AstRoot * root = allocate ((Allocator *)parse.alloc, sizeof(AstRoot));
  memset (root, 0, sizeof(AstRoot));
  stack_push (parse.stack, &root);
  yyparse (&parse, (Ast *) root);
  if (((Ast *)root)->child) {
    const char * i = copy_strings (buffer, (Ast *) root, code - buffer);
    const char * end = i; while (*end != '\0') end++;
    root->after = copy_range (i, end, code - buffer);
    root->alloc = parent ? NULL : parse.alloc;
    root->stack = parent ? NULL : parse.stack;
    stack_externalize (parse.stack);
  }
  else {
    root = NULL;
    if (parent)
      stack_externalize (parse.stack);
    else {
      free_allocator (parse.alloc);
      stack_destroy (parse.stack);
    }
  }
  free (buffer);
  yylex_destroy();
  return root;
}

int token_symbol (int token)
{
  return YYTRANSLATE (token);
}

const char * symbol_name (int sym)
{
  return yytname[sym];
}
