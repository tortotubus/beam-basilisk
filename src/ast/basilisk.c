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
  YYSYMBOL_FOREACH_DIMENSION = 80,         /* FOREACH_DIMENSION  */
  YYSYMBOL_REDUCTION = 81,                 /* REDUCTION  */
  YYSYMBOL_MACRO = 82,                     /* MACRO  */
  YYSYMBOL_ELLIPSIS_MACRO = 83,            /* ELLIPSIS_MACRO  */
  YYSYMBOL_84_ = 84,                       /* ';'  */
  YYSYMBOL_85_ = 85,                       /* '}'  */
  YYSYMBOL_86_ = 86,                       /* ')'  */
  YYSYMBOL_87_ = 87,                       /* '('  */
  YYSYMBOL_88_ = 88,                       /* ','  */
  YYSYMBOL_89_ = 89,                       /* ':'  */
  YYSYMBOL_90_ = 90,                       /* '.'  */
  YYSYMBOL_91_ = 91,                       /* '{'  */
  YYSYMBOL_92_ = 92,                       /* '['  */
  YYSYMBOL_93_ = 93,                       /* ']'  */
  YYSYMBOL_94_ = 94,                       /* '*'  */
  YYSYMBOL_95_ = 95,                       /* '&'  */
  YYSYMBOL_96_ = 96,                       /* '+'  */
  YYSYMBOL_97_ = 97,                       /* '-'  */
  YYSYMBOL_98_ = 98,                       /* '~'  */
  YYSYMBOL_99_ = 99,                       /* '!'  */
  YYSYMBOL_100_ = 100,                     /* '/'  */
  YYSYMBOL_101_ = 101,                     /* '%'  */
  YYSYMBOL_102_ = 102,                     /* '<'  */
  YYSYMBOL_103_ = 103,                     /* '>'  */
  YYSYMBOL_104_ = 104,                     /* '^'  */
  YYSYMBOL_105_ = 105,                     /* '|'  */
  YYSYMBOL_106_ = 106,                     /* '?'  */
  YYSYMBOL_107_ = 107,                     /* '='  */
  YYSYMBOL_YYACCEPT = 108,                 /* $accept  */
  YYSYMBOL_translation_unit = 109,         /* translation_unit  */
  YYSYMBOL_primary_expression = 110,       /* primary_expression  */
  YYSYMBOL_expression_error = 111,         /* expression_error  */
  YYSYMBOL_constant = 112,                 /* constant  */
  YYSYMBOL_enumeration_constant = 113,     /* enumeration_constant  */
  YYSYMBOL_string = 114,                   /* string  */
  YYSYMBOL_generic_selection = 115,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 116,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 117,      /* generic_association  */
  YYSYMBOL_postfix_expression = 118,       /* postfix_expression  */
  YYSYMBOL_postfix_initializer = 119,      /* postfix_initializer  */
  YYSYMBOL_array_access = 120,             /* array_access  */
  YYSYMBOL_function_call = 121,            /* function_call  */
  YYSYMBOL_member_identifier = 122,        /* member_identifier  */
  YYSYMBOL_argument_expression_list = 123, /* argument_expression_list  */
  YYSYMBOL_argument_expression_list_item = 124, /* argument_expression_list_item  */
  YYSYMBOL_unary_expression = 125,         /* unary_expression  */
  YYSYMBOL_unary_operator = 126,           /* unary_operator  */
  YYSYMBOL_cast_expression = 127,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 128, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 129,      /* additive_expression  */
  YYSYMBOL_shift_expression = 130,         /* shift_expression  */
  YYSYMBOL_relational_expression = 131,    /* relational_expression  */
  YYSYMBOL_equality_expression = 132,      /* equality_expression  */
  YYSYMBOL_and_expression = 133,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 134,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 135,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 136,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 137,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 138,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 139,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 140,      /* assignment_operator  */
  YYSYMBOL_expression = 141,               /* expression  */
  YYSYMBOL_constant_expression = 142,      /* constant_expression  */
  YYSYMBOL_declaration = 143,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 144,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 145,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 146,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 147,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 148,           /* type_specifier  */
  YYSYMBOL_types = 149,                    /* types  */
  YYSYMBOL_struct_or_union_specifier = 150, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 151,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 152,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 153,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 154, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 155,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 156,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 157,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 158,          /* enumerator_list  */
  YYSYMBOL_enumerator = 159,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 160,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 161,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 162,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 163,      /* alignment_specifier  */
  YYSYMBOL_declarator = 164,               /* declarator  */
  YYSYMBOL_direct_declarator = 165,        /* direct_declarator  */
  YYSYMBOL_generic_identifier = 166,       /* generic_identifier  */
  YYSYMBOL_pointer = 167,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 168,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 169,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 170,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 171,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 172,          /* identifier_list  */
  YYSYMBOL_type_name = 173,                /* type_name  */
  YYSYMBOL_abstract_declarator = 174,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 175, /* direct_abstract_declarator  */
  YYSYMBOL_type_not_specified = 176,       /* type_not_specified  */
  YYSYMBOL_initializer = 177,              /* initializer  */
  YYSYMBOL_initializer_list = 178,         /* initializer_list  */
  YYSYMBOL_designation = 179,              /* designation  */
  YYSYMBOL_designator_list = 180,          /* designator_list  */
  YYSYMBOL_designator = 181,               /* designator  */
  YYSYMBOL_static_assert_declaration = 182, /* static_assert_declaration  */
  YYSYMBOL_statement = 183,                /* statement  */
  YYSYMBOL_labeled_statement = 184,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 185,       /* compound_statement  */
  YYSYMBOL_186_1 = 186,                    /* @1  */
  YYSYMBOL_block_item_list = 187,          /* block_item_list  */
  YYSYMBOL_block_item = 188,               /* block_item  */
  YYSYMBOL_expression_statement = 189,     /* expression_statement  */
  YYSYMBOL_selection_statement = 190,      /* selection_statement  */
  YYSYMBOL_for_scope = 191,                /* for_scope  */
  YYSYMBOL_iteration_statement = 192,      /* iteration_statement  */
  YYSYMBOL_for_declaration_statement = 193, /* for_declaration_statement  */
  YYSYMBOL_jump_statement = 194,           /* jump_statement  */
  YYSYMBOL_external_declaration = 195,     /* external_declaration  */
  YYSYMBOL_function_declaration = 196,     /* function_declaration  */
  YYSYMBOL_function_definition = 197,      /* function_definition  */
  YYSYMBOL_declaration_list = 198,         /* declaration_list  */
  YYSYMBOL_basilisk_statements = 199,      /* basilisk_statements  */
  YYSYMBOL_macro_call = 200,               /* macro_call  */
  YYSYMBOL_macro_statement = 201,          /* macro_statement  */
  YYSYMBOL_foreach_statement = 202,        /* foreach_statement  */
  YYSYMBOL_foreach_parameters = 203,       /* foreach_parameters  */
  YYSYMBOL_foreach_parameter = 204,        /* foreach_parameter  */
  YYSYMBOL_reduction_list = 205,           /* reduction_list  */
  YYSYMBOL_reduction = 206,                /* reduction  */
  YYSYMBOL_reduction_operator = 207,       /* reduction_operator  */
  YYSYMBOL_reduction_array = 208,          /* reduction_array  */
  YYSYMBOL_foreach_dimension_statement = 209, /* foreach_dimension_statement  */
  YYSYMBOL_forin_declaration_statement = 210, /* forin_declaration_statement  */
  YYSYMBOL_forin_statement = 211,          /* forin_statement  */
  YYSYMBOL_forin_arguments = 212,          /* forin_arguments  */
  YYSYMBOL_event_definition = 213,         /* event_definition  */
  YYSYMBOL_event_parameters = 214,         /* event_parameters  */
  YYSYMBOL_event_parameter = 215,          /* event_parameter  */
  YYSYMBOL_boundary_definition = 216,      /* boundary_definition  */
  YYSYMBOL_external_foreach_dimension = 217, /* external_foreach_dimension  */
  YYSYMBOL_attribute = 218,                /* attribute  */
  YYSYMBOL_new_field = 219,                /* new_field  */
  YYSYMBOL_root = 220                      /* root  */
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
#define YYFINAL  234
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3587

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  360
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  646

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   338


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
       2,     2,     2,    99,     2,     2,     2,   101,    95,     2,
      87,    86,    94,    96,    88,    97,    90,   100,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    89,    84,
     102,   107,   103,   106,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    92,     2,    93,   104,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,   105,    85,    98,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83
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
     708,   709,   710,   714,   715,   719,   720,   724,   725,   729,
     730,   734,   735,   739,   740,   744,   748,   749,   750,   754,
     755,   759,   760,   764,   769,   774,   775,   779,   783,   784,
     785,   789,   790,   791,   795,   799,   800,   804,   808,   809,
     813
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
  "TRACE", "FOREACH", "FOREACH_DIMENSION", "REDUCTION", "MACRO",
  "ELLIPSIS_MACRO", "';'", "'}'", "')'", "'('", "','", "':'", "'.'", "'{'",
  "'['", "']'", "'*'", "'&'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "$accept", "translation_unit",
  "primary_expression", "expression_error", "constant",
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
  "reduction_array", "foreach_dimension_statement",
  "forin_declaration_statement", "forin_statement", "forin_arguments",
  "event_definition", "event_parameters", "event_parameter",
  "boundary_definition", "external_foreach_dimension", "attribute",
  "new_field", "root", YY_NULLPTR
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
     335,   336,   337,   338,    59,   125,    41,    40,    44,    58,
      46,   123,    91,    93,    42,    38,    43,    45,   126,    33,
      47,    37,    60,    62,    94,   124,    63,    61
};
#endif

#define YYPACT_NINF (-368)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-361)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1264,   -60,    21,  -368,  -368,  -368,  -368,  2637,  2694,  2694,
     481,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,    32,   -26,    24,    60,    80,
    -368,    83,  -368,  -368,    -1,  -368,   110,   124,   944,  -368,
    -368,  -368,  -368,  -368,  -368,   699,  -368,  -368,  -368,  -368,
     352,  -368,   -60,   658,  2734,  -368,   115,   -50,   286,    23,
     327,     7,    72,    81,   224,    10,  -368,   179,  -368,   130,
    3391,  3391,  -368,  -368,    70,  -368,  -368,  3391,  3391,  3391,
      75,  -368,  -368,  3085,  -368,   816,  -368,  -368,  -368,  -368,
    -368,  -368,   258,   181,  -368,  -368,   944,  -368,  -368,   944,
    -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  2232,  -368,  -368,   273,   217,  1491,  3511,
    3511,  2584,  2734,   282,    54,  2090,  -368,   658,   229,  -368,
     231,  3511,    14,  3511,   238,   189,  -368,    45,  -368,  -368,
    2122,    45,  2262,  -368,  2232,  -368,  -368,  2734,  2734,  2734,
    2734,  2734,  2734,  2734,  2734,  2734,  2734,  2734,  2734,  2734,
    2734,  2734,  2734,  2734,  2734,  2584,  -368,  -368,   178,   208,
     -35,  -368,   -14,   -42,  -368,    51,  -368,  -368,  -368,  2922,
     236,  -368,  -368,  -368,  3433,   268,  -368,   130,  -368,  3085,
     293,   658,  2734,   292,   299,   301,   308,   816,  -368,    45,
     314,   315,  2337,   313,   316,  -368,  -368,   -24,   317,  -368,
    -368,  -368,  -368,  -368,   318,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,  -368,  1165,   321,   323,   658,
    2074,  -368,  -368,  -368,   295,    99,  -368,   273,  -368,   324,
     329,   330,   336,   337,   338,   331,   341,  3391,  -368,  -368,
     209,  -368,  -368,  -368,  2584,  -368,  3022,  1566,   -16,  -368,
      -5,  -368,  -368,  2597,  -368,  -368,  -368,  -368,  -368,  -368,
     219,  -368,  -368,   311,   106,  -368,  -368,  -368,  -368,  -368,
     115,   115,   -50,   -50,   286,   286,   286,   286,    23,    23,
     327,     7,    72,    81,   224,   259,  -368,   344,  -368,  -368,
    -368,   208,  -368,   178,  2367,  -368,  1610,  -368,   -42,   332,
    3194,  -368,   101,  -368,  2977,  3242,  2734,   326,  -368,  -368,
    -368,   342,   816,  1319,  1319,  2584,   372,   351,  -368,  -368,
    -368,    -4,  2219,    82,  -368,   816,  1394,  -368,  -368,  1066,
    -368,   346,   346,    45,  2074,  2734,  -368,  -368,   137,  2367,
     143,  -368,  2734,  -368,    33,   174,  -368,  -368,  -368,  -368,
    3472,   435,  -368,  3391,   178,  -368,  -368,  2232,  -368,   339,
    -368,   118,   361,   360,  -368,   363,  1923,  -368,   358,   359,
    1685,    -5,  -368,  -368,  1729,  -368,  -368,  -368,  -368,  -368,
    2734,  -368,  -368,  -368,  -368,  -368,  -368,  2867,  1923,  -368,
     362,   365,  1804,  -368,  -368,  -368,  -368,  -368,  2734,   150,
    -368,   367,   374,  3290,  -368,   658,  -368,   183,  -368,   816,
    -368,   377,   378,   228,   380,  -368,  -368,   381,   816,  -368,
     232,  -368,   384,  -368,   385,   816,  -368,    66,  2412,   130,
    2412,  -368,  -368,  -368,   193,   379,  -368,  1961,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,    89,   386,   237,  -368,   387,
     388,  -368,  -368,  -368,  2367,  2804,   371,    49,  -368,  -368,
    3344,  -368,  -368,   390,  1923,  -368,  -368,  2584,  -368,   391,
    3145,  1923,  -368,   392,   393,  1848,  -368,   401,  -368,  -368,
     402,   245,   396,  1923,  -368,  -368,  2584,  -368,   399,   404,
    -368,  -368,  -368,   134,  2734,  -368,  -368,  2597,  2734,   816,
    2734,  -368,   816,   816,   816,  2584,    38,  -368,   816,  2442,
    -368,   816,  -368,  2232,  2487,    15,  2539,  -368,  1977,  -368,
    -368,  -368,  2367,  -368,  2584,  -368,  3472,  2584,   416,  -368,
    -368,  2367,  -368,  -368,  -368,   418,   419,  -368,  -368,   427,
     421,  1923,  -368,  -368,  2584,  -368,   422,  -368,  -368,  -368,
     467,  -368,   425,   428,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,   460,  -368,  -368,   264,  -368,  -368,
    -368,   436,  -368,  -368,  -368,  -368,   231,   441,   816,   265,
    2232,   816,   294,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,  -368,  -368,   439,   442,  -368,  -368,  -368,
    -368,   816,   450,    45,   816,  -368,   816,   452,  -368,   816,
    -368,  -368,  -368,  -368,   448,   455,  -368,  -368,   816,  -368,
     453,  -368,  -368,  2584,   167,  -368
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
     189,     0,   131,   187,   358,   134,     0,     0,     0,    55,
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
       0,     0,     0,   326,     0,    60,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   354,   254,     0,   214,
       0,   124,   312,   254,   194,     0,   151,   114,   116,     0,
     154,   118,   120,   122,     0,     0,   315,     0,   314,     0,
       0,   210,     0,     0,     0,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,   317,   286,     0,     0,   325,
     268,   269,   270,   271,     0,   272,   296,   273,   274,   318,
     319,   320,   321,   322,     1,   279,     0,     0,     0,     0,
       0,    96,    95,    17,   181,     0,   178,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   323,    45,
       0,    41,    44,    10,     0,   164,     0,     0,   231,   254,
     232,   229,   166,     0,     4,     5,     6,    29,    40,    38,
       0,    28,    35,    55,     0,    94,    93,    63,    64,    65,
      67,    68,    70,    71,    75,    76,    73,    74,    78,    79,
      81,    83,    85,    87,    89,     0,   111,     0,   186,   215,
     213,   212,   254,     0,     0,   254,     0,   193,   254,     0,
       0,   159,     0,   163,     0,     0,     0,   127,   316,   313,
     275,     0,     0,     0,     0,     0,     0,     0,   300,   301,
     302,     0,     0,     0,   287,     0,     0,   284,   285,     0,
     282,    51,     0,     0,     0,     0,   257,   259,     0,     0,
       0,   263,     0,   173,     0,     0,   191,   190,    52,   182,
       0,     0,   359,     0,     0,   355,   324,    43,   109,     0,
     250,   224,     0,   218,   254,     0,     0,   234,    55,     0,
       0,   230,   228,   254,     0,    32,    61,    39,    36,    37,
       0,   195,   216,   211,   112,   125,   126,     0,     0,   196,
      55,     0,     0,   192,   155,   152,   160,   254,     0,     0,
     168,   172,     0,     0,   357,    60,   351,     0,   348,     0,
     278,     0,     0,     0,     0,   299,   303,     0,     0,   331,
       0,   329,   332,   333,     0,     0,   276,     0,     0,     0,
       0,   281,   283,   266,     0,     0,    33,     0,   258,   262,
     264,   180,   174,   179,   175,     0,     0,     0,    21,     0,
       0,   356,   312,    42,     0,     0,   221,   231,   223,   251,
       0,   219,   233,     0,     0,   235,   241,     0,   240,     0,
       0,     0,   242,    55,     0,     0,    91,     0,   226,   207,
       0,     0,     0,     0,   197,   204,     0,   203,    55,     0,
     161,   170,   254,     0,     0,   156,   153,     0,     0,     0,
       0,   277,     0,     0,     0,     0,     0,   327,     0,     0,
     334,     0,   341,     0,     0,   127,     0,   255,     0,   265,
      34,   261,     0,   176,     0,    20,     0,     0,     0,   225,
     151,     0,   217,   254,   237,     0,     0,   239,   252,     0,
       0,     0,   243,   249,     0,   248,     0,   206,   205,   208,
       0,   199,     0,     0,   200,   202,   162,   169,   171,   353,
     352,   350,   347,   349,   289,   290,   292,     0,   338,   337,
     336,     0,   328,   330,   342,   346,   345,     0,     0,     0,
       0,     0,     0,   256,   260,    24,    22,    23,   267,   222,
     220,   236,   238,   253,   245,     0,     0,   246,   227,   198,
     201,     0,     0,     0,     0,   297,     0,     0,   294,     0,
     244,   247,   288,   293,   339,     0,   344,   298,     0,   295,
       0,   335,   343,     0,     0,   340
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -368,  -368,  -368,    26,  -368,  -368,  -368,  -368,  -368,    -3,
     411,  -120,  -368,     0,   395,   397,   172,   487,  -368,   -44,
     205,   210,   171,   225,   382,   383,   389,   400,   376,  -368,
    -106,    42,   -61,   -43,  -125,   -92,   241,  -368,   240,  -368,
      50,  -368,  -368,  -368,  -182,  -295,  -122,  -368,    43,  -368,
     319,  -341,  -368,   534,  -368,  -368,   -70,  -177,     4,  -136,
    -251,  -351,  -368,    78,  -368,   262,  -128,  -258,  -166,  -274,
     201,  -367,  -368,   200,  -162,   -62,  -368,    27,  -368,  -368,
     214,  -331,  -368,  -368,  -368,  -368,  -368,   510,  -368,  -244,
    -368,  -368,  -368,    44,  -368,  -368,    39,  -368,   127,  -368,
    -368,  -368,  -368,  -368,   -25,  -368,  -368,  -314,  -368,  -368,
    -368,  -368,  -368
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    55,    56,   138,    57,   244,    58,    59,   467,   468,
      60,   259,    61,   107,   277,   260,   261,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,   139,   123,   217,   249,    78,   381,   180,   181,    80,
      81,    82,    83,    84,   320,   321,   142,   419,   420,    85,
     245,   246,    86,    87,    88,    89,   307,   183,   218,   185,
     311,   382,   383,   384,   501,   469,   385,   270,   271,   357,
     358,   359,   360,   361,    91,   348,   220,   221,   236,   349,
     350,   222,   223,   224,   225,   226,   227,    92,    93,    94,
     199,   228,    95,   229,   230,   440,   441,   442,   443,   591,
     635,   231,   232,   233,   597,    97,   427,   428,    98,    99,
     100,   101,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,   196,   154,   241,    90,   140,   268,   254,   318,   182,
     391,   306,   325,   375,   269,   450,   390,   317,   600,   265,
     156,   272,   248,   463,  -209,   416,   248,   323,   104,   174,
     416,   103,   323,   219,   285,   124,   243,   164,   165,   127,
     406,   124,    77,   310,    96,   315,   160,   161,   124,   312,
     316,  -209,   124,   313,   124,    62,   500,   588,   256,    90,
     344,   128,   125,   140,   264,   412,   140,   322,   125,   533,
    -127,   266,   322,   124,  -127,   125,   267,   331,   124,   125,
     436,   125,   393,   184,   264,   458,   444,   394,   190,   153,
     542,   133,   243,   314,   195,    62,   248,    77,   141,    96,
     125,   266,   170,   392,   124,   125,   267,   328,   179,   284,
    -209,   129,  -209,   287,   288,   289,   175,   534,   462,   536,
     198,   124,   314,   126,   463,   166,   167,   327,   416,   471,
     268,   125,   305,   124,   589,   484,   475,   124,   178,   559,
     257,   267,   423,   495,   347,   336,   404,   130,   125,   407,
     344,   278,   413,   395,   264,   278,   141,   503,   323,   141,
     125,   189,   323,   323,   125,   242,   194,   131,   445,   341,
     132,   542,   104,   253,   543,   403,   171,   262,   141,   141,
     141,   124,   184,   541,   363,   417,   172,   364,   178,   184,
     418,   141,   262,   141,   264,   179,   286,   134,   322,   399,
     549,   184,   322,   322,   581,   475,   583,    62,   125,   157,
     267,   135,   179,   337,   177,   158,   159,   178,   481,   391,
     426,   178,   456,   418,   179,   457,   329,   490,   179,   396,
     455,   395,   395,   353,   512,   355,    62,   461,   513,   141,
     561,    79,   173,   327,   141,   477,    18,    19,    20,   248,
     459,   510,   421,   478,   448,   264,   248,   347,   234,   464,
     645,   323,   465,   176,   541,   178,   235,   518,   604,   519,
     430,   520,   179,   274,   275,   276,   243,   609,   537,   308,
     103,   538,   356,   446,    43,   105,     3,     4,     5,     6,
     140,   140,   433,   511,   496,   376,    79,   377,   162,   163,
     318,   322,   179,   447,   472,   397,   378,   377,   247,   389,
     144,   476,   248,    11,   524,   263,   264,   184,   528,   264,
     529,   187,   188,   545,   273,   546,   184,   324,   191,   192,
     193,   569,    62,   570,   197,   294,   295,   296,   297,   477,
     147,   148,   149,   168,   169,    62,   576,   264,   400,    62,
     622,   626,   264,   264,    39,   326,   356,   453,   411,   431,
     432,   147,   148,   149,   517,   290,   291,   521,   237,   109,
     141,   238,   292,   293,   141,   141,   527,   330,   184,   535,
     629,   332,   264,   532,   439,   184,   333,   610,   334,   578,
     250,   251,   252,   298,   299,   335,   356,   579,   338,   339,
     342,   356,   362,   343,   398,   346,   345,   351,   248,   352,
     366,   580,   426,   595,   426,   367,   368,   414,   150,   262,
     141,   151,   369,   152,   372,   370,   371,   373,   483,    62,
     401,   429,   489,   314,   434,   435,   494,   240,    62,   150,
     197,   470,   151,   421,   152,    62,   474,   479,   480,   482,
     502,   485,   486,   184,   509,   504,   514,   582,   505,   515,
     584,   585,   586,   522,   523,   437,   592,   525,   526,   594,
     618,   531,   539,   141,   548,   544,   547,   197,   551,   184,
     595,   184,   587,   554,   557,   562,   563,   567,   568,   571,
     596,   599,   574,   602,   108,   110,   111,   575,   374,   356,
     608,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   611,   612,   613,   614,   617,   356,   184,   619,    62,
     621,   620,    62,    62,    62,   623,   555,   624,    62,   556,
     590,    62,   630,   560,   633,   631,   625,   566,   638,   628,
     640,   641,   643,   606,   255,   572,   281,   280,   573,   473,
     304,   155,   300,   405,   301,   454,   577,   596,   553,   632,
     460,   302,   636,   452,   637,   146,   365,   639,   593,   530,
    -210,   439,  -210,   303,     0,   627,   642,     0,     0,     0,
     356,     0,   143,     0,   356,     0,   605,   449,   122,   607,
     197,     0,     0,   356,     0,     0,   141,     0,    62,     0,
     644,    62,     0,   615,     0,     0,   616,     0,     0,     0,
       0,     0,     0,     0,   374,   155,     0,     0,     0,   155,
       0,    62,     0,     0,    62,     0,    62,   634,     0,    62,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
     143,     0,     0,   143,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   143,   143,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,     0,   143,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -360,
     145,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,   309,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,     0,     0,     0,     0,   143,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
     155,     0,     0,     0,     0,   122,     0,     0,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,    46,
       0,    47,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,    49,    50,    51,    52,    53,    54,     0,
       0,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   425,     0,     0,     0,   200,     0,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,     0,     0,   402,   201,    11,     0,   155,
     309,     0,     0,     0,   143,     0,     0,     0,   143,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,     0,    37,   155,    39,     0,
       0,     0,     0,    44,     0,   213,   214,     0,    47,   215,
     216,     0,     0,    48,   143,   155,     0,   103,     0,     0,
      49,    50,    51,    52,    53,    54,     0,     0,     0,     0,
     309,     0,     0,     0,   402,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,     0,   136,   402,   105,     3,     4,
       5,     6,     7,     0,     8,     9,     0,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,    11,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,   155,     0,     0,   155,   425,     0,   425,     0,     0,
       0,     0,     0,     0,    37,    38,    39,     0,   402,     0,
      43,    44,     0,     0,     0,   309,     0,     0,     0,   402,
       0,    48,     0,     0,     0,     0,     0,   402,    49,    50,
      51,    52,    53,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,   213,   214,     0,    47,   215,
     216,   451,     0,    48,     0,     0,     0,   103,     0,     0,
      49,    50,    51,    52,    53,    54,   200,     0,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,   202,   203,   204,     0,   205,   206,   207,   208,
     209,   210,   211,   212,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,   213,   214,     0,    47,   215,   216,
       0,     0,    48,     0,     0,     0,   103,     0,     0,    49,
      50,    51,    52,    53,    54,     1,     0,     2,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     136,     0,   105,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,    46,     0,    47,     0,     0,   239,
      11,    48,     0,     0,     0,     0,     0,     0,    49,    50,
      51,    52,    53,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,    44,   105,     3,     4,
       5,     6,     7,     0,     8,     9,    48,     0,     0,     0,
       0,     0,     0,    49,    50,    51,    52,    53,    54,     0,
       0,     0,     0,     0,   137,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,     0,     0,     0,     0,   216,     0,
       0,    48,     0,     0,     0,     0,     0,     0,    49,    50,
      51,    52,    53,    54,   105,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,    11,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    38,    39,     0,     0,     0,    43,    44,   105,
       3,     4,     5,     6,     7,     0,     8,     9,    48,     0,
       0,     0,     0,     0,     0,    49,    50,    51,    52,    53,
      54,     0,     0,     0,     0,     0,   239,    11,     0,     0,
     386,     0,     0,     0,    18,    19,    20,     0,     0,     0,
       0,     0,     0,   105,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,   308,    39,     0,
     239,    11,    43,    44,   408,     0,     0,     0,    18,    19,
      20,     0,     0,    48,     0,     0,     0,     0,     0,   387,
     388,    50,    51,    52,    53,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,   308,    39,     0,     0,     0,    43,    44,   105,     3,
       4,     5,     6,     7,     0,     8,     9,    48,     0,     0,
       0,     0,     0,   409,   410,    50,    51,    52,    53,    54,
       0,     0,     0,     0,     0,   239,    11,     0,     0,   487,
       0,     0,     0,    18,    19,    20,     0,     0,     0,     0,
       0,     0,   105,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,   308,    39,     0,   239,
      11,    43,    44,   491,     0,     0,     0,    18,    19,    20,
       0,     0,    48,     0,     0,     0,     0,     0,   488,    49,
      50,    51,    52,    53,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
     308,    39,     0,     0,     0,    43,    44,   105,     3,     4,
       5,     6,     7,     0,     8,     9,    48,     0,     0,     0,
       0,     0,   492,   493,    50,    51,    52,    53,    54,     0,
       0,     0,     0,     0,   239,    11,     0,     0,   506,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       0,   105,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,   308,    39,     0,   239,    11,
      43,    44,   564,     0,     0,     0,    18,    19,    20,     0,
       0,    48,     0,     0,     0,     0,     0,   507,   508,    50,
      51,    52,    53,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,   308,
      39,     0,     0,     0,    43,    44,   105,     3,     4,     5,
       6,     7,     0,     8,     9,    48,     0,     0,     0,     0,
       0,   565,    49,    50,    51,    52,    53,    54,     0,     0,
       0,     0,     0,   239,    11,     0,     0,     0,     0,     0,
       0,    18,    19,    20,   105,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
     105,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,   239,    11,    37,   308,    39,     0,     0,     0,    43,
      44,     0,     0,     0,     0,     0,     0,   239,    11,     0,
      48,     0,     0,     0,     0,     0,     0,    49,    50,    51,
      52,    53,    54,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,     0,   540,    37,    48,    39,
       0,   353,   354,   355,    44,    49,    50,    51,    52,    53,
      54,     0,   603,     0,    48,     0,     0,   353,   354,   355,
       0,    49,    50,    51,    52,    53,    54,   105,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,   105,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,   239,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,    11,     0,     0,     0,   105,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
       0,    44,   239,    11,     0,     0,     0,     0,     0,     0,
      37,    48,    39,     0,   353,   354,   355,    44,    49,    50,
      51,    52,    53,    54,     0,     0,   258,    48,     0,     0,
       0,   240,     0,     0,    49,    50,    51,    52,    53,    54,
       0,     0,    37,     0,    39,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,   279,    48,
       0,     0,     0,   240,     0,     0,    49,    50,    51,    52,
      53,    54,   105,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,   105,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,   239,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,    11,     0,   105,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    39,   239,    11,     0,     0,    44,     0,     0,     0,
     437,     0,    37,     0,    39,   438,    48,     0,     0,    44,
       0,     0,     0,    49,    50,    51,    52,    53,    54,    48,
       0,     0,     0,   240,     0,     0,    49,    50,    51,    52,
      53,    54,    37,     0,    39,     0,     0,     0,     0,    44,
     105,     3,     4,     5,     6,     7,     0,     8,     9,    48,
       0,     0,     0,     0,     0,   282,   283,    50,    51,    52,
      53,    54,     0,     0,     0,     0,     0,   239,    11,     0,
     105,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,    11,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,    44,   105,     3,     4,     5,     6,
       7,   340,     8,     9,    48,     0,     0,     0,     0,     0,
       0,    49,    50,    51,    52,    53,    54,    37,     0,    39,
       0,     0,   239,    11,    44,   105,     3,     4,     5,     6,
       7,     0,     8,     9,    48,     0,     0,     0,   354,     0,
       0,    49,    50,    51,    52,    53,    54,     0,     0,     0,
       0,     0,   239,    11,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,     0,    44,
     105,     3,     4,     5,     6,     7,   216,     8,     9,    48,
       0,     0,     0,     0,     0,     0,    49,    50,    51,    52,
      53,    54,    37,     0,    39,     0,     0,   239,    11,    44,
       0,     0,     0,   437,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,    49,    50,    51,    52,
      53,    54,   105,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,    44,     0,     0,     0,     0,   239,
      11,     0,     0,   598,    48,     0,     0,     0,     0,     0,
       0,    49,    50,    51,    52,    53,    54,   105,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
     105,     3,     4,     5,     6,     7,     0,     8,     9,    37,
       0,    39,     0,     0,   239,    11,    44,     0,     0,     0,
       0,     0,     0,     0,     0,   601,    48,     0,    11,     0,
       0,     0,     0,    49,    50,    51,    52,    53,    54,     0,
     105,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,    37,    11,    39,
       0,    48,     0,     0,    44,     0,     0,     0,    49,    50,
      51,    52,    53,    54,    48,     0,     0,     0,   240,     0,
       0,    49,    50,    51,    52,    53,    54,   105,     3,     4,
       5,     6,     7,     0,     8,     9,     0,    37,     0,    39,
       0,     0,     0,     0,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,    11,     0,     0,     0,     0,
       0,    49,    50,    51,    52,    53,    54,   105,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    11,    39,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,     0,     0,     0,     0,     0,     0,    49,    50,
      51,    52,    53,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    39,   124,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,    49,    50,
      51,    52,    53,    54,   550,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,   497,     0,
     498,   379,     0,    36,     0,    38,     0,    40,     0,    42,
      43,     0,    45,     0,     0,     0,     0,     0,     0,     0,
     380,   475,     0,     0,     0,     0,   267,   186,   179,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   379,     0,    36,     0,    38,     0,
      40,     0,    42,    43,     0,    45,     0,     0,     0,     0,
       0,     0,   186,   499,     0,     0,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   422,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,    41,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,   186,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    41,   186,    43,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   379,
       0,    36,     0,    38,     0,    40,     0,    42,    43,     0,
      45,     0,     0,     0,     0,     0,     0,     0,   380,   266,
       0,     0,     0,     0,   267,   186,   179,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,     0,    38,     0,    40,    41,
      42,    43,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,   103,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   379,     0,    36,     0,    38,     0,    40,     0,
      42,    43,     0,    45,   186,     0,     0,     0,     0,     0,
       0,   558,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    41,     0,
      43,     0,   186,     0,     0,     0,     0,     0,     0,   415,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,    41,     0,    43,     0,
     186,     0,     0,     0,     0,     0,     0,   424,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,    41,     0,    43,     0,     0,     0,
       0,     0,     0,     0,   186,   516,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   379,     0,    36,     0,    38,     0,    40,     0,    42,
      43,   186,    45,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,    38,   186,    40,     0,    42,    43,     0,    45,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,     0,    38,     0,     0,    41,     0,    43,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
     466,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,     0,    38,     0,     0,     0,     0,    43,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
       0,    93,    63,   123,     0,    48,   142,   132,   185,    79,
     268,   177,   194,   257,   142,   346,   267,   183,     3,   141,
      64,   143,   128,   364,     3,   320,   132,   189,     1,    19,
     325,    91,   194,    95,   154,     3,     3,    14,    15,    35,
     314,     3,     0,   179,     0,    87,    96,    97,     3,    84,
      92,    30,     3,    88,     3,    55,   407,    19,     4,    55,
      84,    87,    30,   106,    88,   316,   109,   189,    30,     3,
      84,    87,   194,     3,    88,    30,    92,   202,     3,    30,
      84,    30,    87,    79,    88,   359,     4,    92,    84,    62,
     457,    92,     3,   107,    90,    95,   202,    55,    48,    55,
      30,    87,    95,   269,     3,    30,    92,   199,    94,   152,
      89,    87,    91,   157,   158,   159,   106,   448,    85,   450,
      93,     3,   107,    91,   465,   102,   103,   197,   423,   373,
     266,    30,   175,     3,    96,   386,    87,     3,    87,   490,
      86,    92,   324,   394,   236,   207,   312,    87,    30,   315,
      84,   147,   318,   273,    88,   151,   106,   408,   320,   109,
      30,    91,   324,   325,    30,   123,    91,    87,    86,   212,
      87,   538,   145,   131,    85,   311,   104,   135,   128,   129,
     130,     3,   178,   457,    85,    84,   105,    88,    87,   185,
      89,   141,   150,   143,    88,    94,   154,    87,   320,    93,
     474,   197,   324,   325,   518,    87,   520,   207,    30,    94,
      92,    87,    94,   209,    84,   100,   101,    87,   384,   477,
     326,    87,    85,    89,    94,    88,   199,   393,    94,   273,
     355,   351,   352,    90,    84,    92,   236,   362,    88,   189,
     491,     0,    18,   313,   194,   381,    38,    39,    40,   355,
     107,   417,   322,   381,   346,    88,   362,   349,     0,    85,
      93,   423,    88,    84,   538,    87,    85,    84,   542,    86,
     332,    88,    94,    84,    85,    86,     3,   551,    85,    71,
      91,    88,   240,   345,    76,     3,     4,     5,     6,     7,
     333,   334,   335,   418,   400,    86,    55,    88,    12,    13,
     477,   423,    94,   346,   374,    86,   264,    88,    91,   267,
      48,   381,   418,    31,    86,    86,    88,   313,    86,    88,
      88,    80,    81,    86,    86,    88,   322,    91,    87,    88,
      89,    86,   332,    88,    93,   164,   165,   166,   167,   475,
       9,    10,    11,    16,    17,   345,   512,    88,    89,   349,
      86,    86,    88,    88,    72,    87,   314,   353,   316,   333,
     334,     9,    10,    11,   425,   160,   161,   429,   106,    87,
     320,   109,   162,   163,   324,   325,   438,    84,   374,   449,
      86,    89,    88,   445,   342,   381,    87,   553,    87,   514,
     128,   129,   130,   168,   169,    87,   354,   517,    84,    84,
      87,   359,   107,    87,    93,    87,    89,    86,   514,    86,
      86,   517,   518,   533,   520,    86,    86,    85,    87,   377,
     370,    90,    86,    92,    93,    88,    88,    86,   386,   429,
      86,    89,   390,   107,    62,    84,   394,    91,   438,    87,
     199,     6,    90,   513,    92,   445,   107,    86,    88,    86,
     408,    93,    93,   449,   412,    93,    89,   519,    93,    85,
     522,   523,   524,    86,    86,    81,   528,    87,    87,   531,
       3,    86,    93,   423,    86,    89,    89,   236,   107,   475,
     600,   477,   525,    93,    93,    93,    93,    86,    86,    93,
     533,   534,    93,   536,     7,     8,     9,    93,   257,   457,
      84,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    93,    93,    86,    93,    93,   474,   513,    93,   519,
      60,    93,   522,   523,   524,    89,   484,    86,   528,   487,
     526,   531,    93,   491,    84,    93,   598,   495,    86,   601,
      92,    86,    89,   546,   133,   503,   151,   150,   506,   377,
     174,    64,   170,   313,   171,   354,   513,   600,   480,   621,
     360,   172,   624,   349,   626,    55,   247,   629,   529,   442,
      89,   529,    91,   173,    -1,   600,   638,    -1,    -1,    -1,
     538,    -1,    48,    -1,   542,    -1,   544,   346,   107,   547,
     349,    -1,    -1,   551,    -1,    -1,   546,    -1,   598,    -1,
     643,   601,    -1,   561,    -1,    -1,   564,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   373,   128,    -1,    -1,    -1,   132,
      -1,   621,    -1,    -1,   624,    -1,   626,   623,    -1,   629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   638,    -1,
     106,    -1,    -1,   109,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   141,    -1,   143,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,   194,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
     273,    -1,    -1,    -1,    -1,   107,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    -1,
      -1,   267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   326,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   355,    -1,    -1,   311,    30,    31,    -1,   362,
     316,    -1,    -1,    -1,   320,    -1,    -1,    -1,   324,   325,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,   400,    72,    -1,
      -1,    -1,    -1,    77,    -1,    79,    80,    -1,    82,    83,
      84,    -1,    -1,    87,   370,   418,    -1,    91,    -1,    -1,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
     386,    -1,    -1,    -1,   390,    -1,    -1,    -1,   394,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   408,    -1,    -1,     1,   412,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,   423,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,   514,    -1,    -1,   517,   518,    -1,   520,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,   484,    -1,
      76,    77,    -1,    -1,    -1,   491,    -1,    -1,    -1,   495,
      -1,    87,    -1,    -1,    -1,    -1,    -1,   503,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
     546,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   561,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    82,    83,
      84,    85,    -1,    87,    -1,    -1,    -1,    91,    -1,    -1,
      94,    95,    96,    97,    98,    99,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    82,    83,    84,
      -1,    -1,    87,    -1,    -1,    -1,    91,    -1,    -1,    94,
      95,    96,    97,    98,    99,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    -1,    82,    -1,    -1,    30,
      31,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    77,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      30,    31,    76,    77,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    77,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    87,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    30,
      31,    76,    77,    34,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    77,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    87,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    30,    31,
      76,    77,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    77,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    87,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    30,    31,    70,    71,    72,    -1,    -1,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    70,    87,    72,
      -1,    90,    91,    92,    77,    94,    95,    96,    97,    98,
      99,    -1,    85,    -1,    87,    -1,    -1,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    77,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    87,    72,    -1,    90,    91,    92,    77,    94,    95,
      96,    97,    98,    99,    -1,    -1,    86,    87,    -1,    -1,
      -1,    91,    -1,    -1,    94,    95,    96,    97,    98,    99,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    91,    -1,    -1,    94,    95,    96,    97,
      98,    99,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    30,    31,    -1,    -1,    77,    -1,    -1,    -1,
      81,    -1,    70,    -1,    72,    86,    87,    -1,    -1,    77,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    87,
      -1,    -1,    -1,    91,    -1,    -1,    94,    95,    96,    97,
      98,    99,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    87,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,     3,     4,     5,     6,     7,
       8,    84,    10,    11,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,    70,    -1,    72,
      -1,    -1,    30,    31,    77,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    87,    -1,    -1,    -1,    91,    -1,
      -1,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,
       3,     4,     5,     6,     7,     8,    84,    10,    11,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,    70,    -1,    72,    -1,    -1,    30,    31,    77,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    70,
      -1,    72,    -1,    -1,    30,    31,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    31,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    70,    31,    72,
      -1,    87,    -1,    -1,    77,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,    87,    -1,    -1,    -1,    91,    -1,
      -1,    94,    95,    96,    97,    98,    99,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    31,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    31,    72,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,     3,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,    67,    -1,    69,    -1,    71,    -1,    73,    -1,    75,
      76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    92,    30,    94,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,
      73,    -1,    75,    76,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    30,    76,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    92,    30,    94,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    74,
      75,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    91,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    -1,    71,    -1,    73,    -1,
      75,    76,    -1,    78,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      76,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    85,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    85,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    -1,    71,    -1,    73,    -1,    75,
      76,    30,    78,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    30,    73,    -1,    75,    76,    -1,    78,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    71,    -1,    -1,    74,    -1,    76,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    71,    -1,    -1,    -1,    -1,    76,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    10,    11,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    80,    82,    87,    94,
      95,    96,    97,    98,    99,   109,   110,   112,   114,   115,
     118,   120,   121,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   143,   144,
     147,   148,   149,   150,   151,   157,   160,   161,   162,   163,
     166,   182,   195,   196,   197,   200,   201,   213,   216,   217,
     218,   219,   220,    91,   185,     3,    87,   121,   125,    87,
     125,   125,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,   107,   140,     3,    30,    91,   166,    87,    87,
      87,    87,    87,    92,    87,    87,     1,    30,   111,   139,
     141,   148,   154,   161,   173,     1,   195,     9,    10,    11,
      87,    90,    92,   185,   140,   125,   127,    94,   100,   101,
      96,    97,    12,    13,    14,    15,   102,   103,    16,    17,
      95,   104,   105,    18,    19,   106,    84,    84,    87,    94,
     145,   146,   164,   165,   166,   167,    30,   144,   144,    91,
     166,   144,   144,   144,    91,   166,   143,   144,   185,   198,
       1,    30,    57,    58,    59,    61,    62,    63,    64,    65,
      66,    67,    68,    79,    80,    83,    84,   141,   166,   183,
     184,   185,   189,   190,   191,   192,   193,   194,   199,   201,
     202,   209,   210,   211,     0,    85,   186,   173,   173,    30,
      91,   119,   139,     3,   113,   158,   159,    91,   138,   142,
     173,   173,   173,   139,   142,   118,     4,    86,    86,   119,
     123,   124,   139,    86,    88,   154,    87,    92,   167,   174,
     175,   176,   154,    86,    84,    85,    86,   122,   166,    86,
     123,   122,    93,    94,   141,   119,   139,   127,   127,   127,
     128,   128,   129,   129,   130,   130,   130,   130,   131,   131,
     132,   133,   134,   135,   136,   141,   176,   164,    71,   161,
     167,   168,    84,    88,   107,    87,    92,   176,   165,     1,
     152,   153,   154,   182,    91,   152,    87,   164,   143,   185,
      84,   142,    89,    87,    87,    87,   183,   166,    84,    84,
      84,   141,    87,    87,    84,    89,    87,   143,   183,   187,
     188,    86,    86,    90,    91,    92,   139,   177,   178,   179,
     180,   181,   107,    85,    88,   158,    86,    86,    86,    86,
      88,    88,    93,    86,   144,   197,    86,    88,   139,    67,
      86,   144,   169,   170,   171,   174,    34,    93,    94,   139,
     168,   175,   176,    87,    92,   119,   127,    86,    93,    93,
      89,    86,   161,   167,   176,   146,   177,   176,    34,    93,
      94,   139,   168,   176,    85,    85,   153,    84,    89,   155,
     156,   164,     1,   152,    85,   125,   138,   214,   215,    89,
     183,   111,   111,   141,    62,    84,    84,    81,    86,   139,
     203,   204,   205,   206,     4,    86,   183,   141,   143,   144,
     189,    85,   188,   166,   178,   142,    85,    88,   177,   107,
     181,   142,    85,   159,    85,    88,    58,   116,   117,   173,
       6,   197,   164,   124,   107,    87,   164,   167,   174,    86,
      88,   176,    86,   139,   168,    93,    93,    34,    93,   139,
     176,    34,    93,    94,   139,   168,   138,     1,     3,    86,
     169,   172,   139,   168,    93,    93,    34,    93,    94,   139,
     176,   142,    84,    88,    89,    85,    85,   140,    84,    86,
      88,   183,    86,    86,    86,    87,    87,   183,    86,    88,
     206,    86,   183,     3,   189,   164,   189,    85,    88,    93,
      85,   177,   179,    85,    89,    86,    88,    89,    86,   177,
      30,   107,    56,   171,    93,   139,   139,    93,    86,   169,
     139,   168,    93,    93,    34,    93,   139,    86,    86,    86,
      88,    93,   139,   139,    93,    93,   176,   156,   142,   119,
     138,   215,   183,   215,   183,   183,   183,   141,    19,    96,
     166,   207,   183,   204,   183,   119,   141,   212,    86,   141,
       3,    86,   141,    85,   177,   139,   117,   139,    84,   177,
     176,    93,    93,    86,    93,   139,   139,    93,     3,    93,
      93,    60,    86,    89,    86,   183,    86,   212,   183,    86,
      93,    93,   183,    84,   166,   208,   183,   183,    86,   183,
      92,    86,   183,    89,   141,    93
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   112,   113,   114,   114,
     115,   116,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   120,   120,   120,   121,   121,
     122,   123,   123,   123,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   126,   126,   126,   126,
     127,   127,   128,   128,   128,   128,   129,   129,   129,   130,
     130,   130,   131,   131,   131,   131,   131,   132,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   139,   139,   139,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   141,   141,
     142,   143,   143,   143,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   145,   145,   146,   146,   147,   147,
     147,   147,   147,   147,   147,   148,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   150,   150,   150,   150,   150,   151,   151,   152,
     152,   153,   153,   153,   154,   154,   154,   154,   155,   155,
     156,   156,   156,   157,   157,   157,   157,   157,   158,   158,
     159,   159,   160,   161,   161,   161,   161,   161,   162,   162,
     163,   163,   164,   164,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   166,
     166,   167,   167,   167,   167,   168,   168,   169,   169,   170,
     170,   171,   171,   171,   171,   171,   172,   172,   173,   173,
     174,   174,   174,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   176,   177,   177,   177,   178,   178,
     178,   178,   179,   180,   180,   181,   181,   182,   183,   183,
     183,   183,   183,   183,   183,   183,   184,   184,   184,   185,
     186,   185,   187,   187,   188,   188,   189,   189,   190,   190,
     190,   191,   192,   192,   192,   192,   192,   193,   193,   194,
     194,   194,   194,   194,   195,   195,   195,   195,   195,   195,
     195,   195,   196,   197,   197,   198,   198,   199,   199,   199,
     199,   199,   199,   200,   200,   201,   201,   202,   202,   203,
     203,   204,   204,   205,   205,   206,   207,   207,   207,   208,
     208,   209,   209,   210,   211,   212,   212,   213,   214,   214,
     214,   215,   215,   215,   216,   217,   217,   218,   219,   219,
     220
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
       1,     1,     1,     3,     4,     2,     2,     4,     5,     1,
       3,     1,     1,     1,     2,     6,     1,     1,     1,     1,
       5,     4,     5,     8,     7,     1,     1,     6,     1,     3,
       3,     1,     3,     3,     2,     4,     5,     4,     1,     4,
       1
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
#line 2020 "basilisk.c"
        break;

    case YYSYMBOL_I_CONSTANT: /* I_CONSTANT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2029 "basilisk.c"
        break;

    case YYSYMBOL_F_CONSTANT: /* F_CONSTANT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2038 "basilisk.c"
        break;

    case YYSYMBOL_STRING_LITERAL: /* STRING_LITERAL  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2047 "basilisk.c"
        break;

    case YYSYMBOL_FUNC_NAME: /* FUNC_NAME  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2056 "basilisk.c"
        break;

    case YYSYMBOL_SIZEOF: /* SIZEOF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2065 "basilisk.c"
        break;

    case YYSYMBOL_PTR_OP: /* PTR_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2074 "basilisk.c"
        break;

    case YYSYMBOL_INC_OP: /* INC_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2083 "basilisk.c"
        break;

    case YYSYMBOL_DEC_OP: /* DEC_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2092 "basilisk.c"
        break;

    case YYSYMBOL_LEFT_OP: /* LEFT_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2101 "basilisk.c"
        break;

    case YYSYMBOL_RIGHT_OP: /* RIGHT_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2110 "basilisk.c"
        break;

    case YYSYMBOL_LE_OP: /* LE_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2119 "basilisk.c"
        break;

    case YYSYMBOL_GE_OP: /* GE_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2128 "basilisk.c"
        break;

    case YYSYMBOL_EQ_OP: /* EQ_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2137 "basilisk.c"
        break;

    case YYSYMBOL_NE_OP: /* NE_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2146 "basilisk.c"
        break;

    case YYSYMBOL_AND_OP: /* AND_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2155 "basilisk.c"
        break;

    case YYSYMBOL_OR_OP: /* OR_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2164 "basilisk.c"
        break;

    case YYSYMBOL_MUL_ASSIGN: /* MUL_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2173 "basilisk.c"
        break;

    case YYSYMBOL_DIV_ASSIGN: /* DIV_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2182 "basilisk.c"
        break;

    case YYSYMBOL_MOD_ASSIGN: /* MOD_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2191 "basilisk.c"
        break;

    case YYSYMBOL_ADD_ASSIGN: /* ADD_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2200 "basilisk.c"
        break;

    case YYSYMBOL_SUB_ASSIGN: /* SUB_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2209 "basilisk.c"
        break;

    case YYSYMBOL_LEFT_ASSIGN: /* LEFT_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2218 "basilisk.c"
        break;

    case YYSYMBOL_RIGHT_ASSIGN: /* RIGHT_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2227 "basilisk.c"
        break;

    case YYSYMBOL_AND_ASSIGN: /* AND_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2236 "basilisk.c"
        break;

    case YYSYMBOL_XOR_ASSIGN: /* XOR_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2245 "basilisk.c"
        break;

    case YYSYMBOL_OR_ASSIGN: /* OR_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2254 "basilisk.c"
        break;

    case YYSYMBOL_TYPEDEF_NAME: /* TYPEDEF_NAME  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2263 "basilisk.c"
        break;

    case YYSYMBOL_ENUMERATION_CONSTANT: /* ENUMERATION_CONSTANT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2272 "basilisk.c"
        break;

    case YYSYMBOL_TYPEDEF: /* TYPEDEF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2281 "basilisk.c"
        break;

    case YYSYMBOL_EXTERN: /* EXTERN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2290 "basilisk.c"
        break;

    case YYSYMBOL_STATIC: /* STATIC  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2299 "basilisk.c"
        break;

    case YYSYMBOL_AUTO: /* AUTO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2308 "basilisk.c"
        break;

    case YYSYMBOL_REGISTER: /* REGISTER  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2317 "basilisk.c"
        break;

    case YYSYMBOL_INLINE: /* INLINE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2326 "basilisk.c"
        break;

    case YYSYMBOL_CONST: /* CONST  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2335 "basilisk.c"
        break;

    case YYSYMBOL_RESTRICT: /* RESTRICT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2344 "basilisk.c"
        break;

    case YYSYMBOL_VOLATILE: /* VOLATILE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2353 "basilisk.c"
        break;

    case YYSYMBOL_BOOL: /* BOOL  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2362 "basilisk.c"
        break;

    case YYSYMBOL_CHAR: /* CHAR  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2371 "basilisk.c"
        break;

    case YYSYMBOL_SHORT: /* SHORT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2380 "basilisk.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2389 "basilisk.c"
        break;

    case YYSYMBOL_LONG: /* LONG  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2398 "basilisk.c"
        break;

    case YYSYMBOL_SIGNED: /* SIGNED  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2407 "basilisk.c"
        break;

    case YYSYMBOL_UNSIGNED: /* UNSIGNED  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2416 "basilisk.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2425 "basilisk.c"
        break;

    case YYSYMBOL_DOUBLE: /* DOUBLE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2434 "basilisk.c"
        break;

    case YYSYMBOL_VOID: /* VOID  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2443 "basilisk.c"
        break;

    case YYSYMBOL_COMPLEX: /* COMPLEX  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2452 "basilisk.c"
        break;

    case YYSYMBOL_IMAGINARY: /* IMAGINARY  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2461 "basilisk.c"
        break;

    case YYSYMBOL_STRUCT: /* STRUCT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2470 "basilisk.c"
        break;

    case YYSYMBOL_UNION: /* UNION  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2479 "basilisk.c"
        break;

    case YYSYMBOL_ENUM: /* ENUM  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2488 "basilisk.c"
        break;

    case YYSYMBOL_ELLIPSIS: /* ELLIPSIS  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2497 "basilisk.c"
        break;

    case YYSYMBOL_CASE: /* CASE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2506 "basilisk.c"
        break;

    case YYSYMBOL_DEFAULT: /* DEFAULT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2515 "basilisk.c"
        break;

    case YYSYMBOL_IF: /* IF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2524 "basilisk.c"
        break;

    case YYSYMBOL_ELSE: /* ELSE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2533 "basilisk.c"
        break;

    case YYSYMBOL_SWITCH: /* SWITCH  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2542 "basilisk.c"
        break;

    case YYSYMBOL_WHILE: /* WHILE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2551 "basilisk.c"
        break;

    case YYSYMBOL_DO: /* DO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2560 "basilisk.c"
        break;

    case YYSYMBOL_FOR: /* FOR  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2569 "basilisk.c"
        break;

    case YYSYMBOL_GOTO: /* GOTO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2578 "basilisk.c"
        break;

    case YYSYMBOL_CONTINUE: /* CONTINUE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2587 "basilisk.c"
        break;

    case YYSYMBOL_BREAK: /* BREAK  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2596 "basilisk.c"
        break;

    case YYSYMBOL_RETURN: /* RETURN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2605 "basilisk.c"
        break;

    case YYSYMBOL_ALIGNAS: /* ALIGNAS  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2614 "basilisk.c"
        break;

    case YYSYMBOL_ALIGNOF: /* ALIGNOF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2623 "basilisk.c"
        break;

    case YYSYMBOL_ATOMIC: /* ATOMIC  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2632 "basilisk.c"
        break;

    case YYSYMBOL_GENERIC: /* GENERIC  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2641 "basilisk.c"
        break;

    case YYSYMBOL_NORETURN: /* NORETURN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2650 "basilisk.c"
        break;

    case YYSYMBOL_STATIC_ASSERT: /* STATIC_ASSERT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2659 "basilisk.c"
        break;

    case YYSYMBOL_THREAD_LOCAL: /* THREAD_LOCAL  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2668 "basilisk.c"
        break;

    case YYSYMBOL_MAYBECONST: /* MAYBECONST  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2677 "basilisk.c"
        break;

    case YYSYMBOL_NEW_FIELD: /* NEW_FIELD  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2686 "basilisk.c"
        break;

    case YYSYMBOL_TRACE: /* TRACE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2695 "basilisk.c"
        break;

    case YYSYMBOL_FOREACH: /* FOREACH  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2704 "basilisk.c"
        break;

    case YYSYMBOL_FOREACH_DIMENSION: /* FOREACH_DIMENSION  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2713 "basilisk.c"
        break;

    case YYSYMBOL_REDUCTION: /* REDUCTION  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2722 "basilisk.c"
        break;

    case YYSYMBOL_MACRO: /* MACRO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2731 "basilisk.c"
        break;

    case YYSYMBOL_ELLIPSIS_MACRO: /* ELLIPSIS_MACRO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2740 "basilisk.c"
        break;

    case YYSYMBOL_84_: /* ';'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2749 "basilisk.c"
        break;

    case YYSYMBOL_85_: /* '}'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2758 "basilisk.c"
        break;

    case YYSYMBOL_86_: /* ')'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2767 "basilisk.c"
        break;

    case YYSYMBOL_87_: /* '('  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2776 "basilisk.c"
        break;

    case YYSYMBOL_88_: /* ','  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2785 "basilisk.c"
        break;

    case YYSYMBOL_89_: /* ':'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2794 "basilisk.c"
        break;

    case YYSYMBOL_90_: /* '.'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2803 "basilisk.c"
        break;

    case YYSYMBOL_91_: /* '{'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2812 "basilisk.c"
        break;

    case YYSYMBOL_92_: /* '['  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2821 "basilisk.c"
        break;

    case YYSYMBOL_93_: /* ']'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2830 "basilisk.c"
        break;

    case YYSYMBOL_94_: /* '*'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2839 "basilisk.c"
        break;

    case YYSYMBOL_95_: /* '&'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2848 "basilisk.c"
        break;

    case YYSYMBOL_96_: /* '+'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2857 "basilisk.c"
        break;

    case YYSYMBOL_97_: /* '-'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2866 "basilisk.c"
        break;

    case YYSYMBOL_98_: /* '~'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2875 "basilisk.c"
        break;

    case YYSYMBOL_99_: /* '!'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2884 "basilisk.c"
        break;

    case YYSYMBOL_100_: /* '/'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2893 "basilisk.c"
        break;

    case YYSYMBOL_101_: /* '%'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2902 "basilisk.c"
        break;

    case YYSYMBOL_102_: /* '<'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2911 "basilisk.c"
        break;

    case YYSYMBOL_103_: /* '>'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2920 "basilisk.c"
        break;

    case YYSYMBOL_104_: /* '^'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2929 "basilisk.c"
        break;

    case YYSYMBOL_105_: /* '|'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2938 "basilisk.c"
        break;

    case YYSYMBOL_106_: /* '?'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2947 "basilisk.c"
        break;

    case YYSYMBOL_107_: /* '='  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2956 "basilisk.c"
        break;

    case YYSYMBOL_translation_unit: /* translation_unit  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2965 "basilisk.c"
        break;

    case YYSYMBOL_primary_expression: /* primary_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2974 "basilisk.c"
        break;

    case YYSYMBOL_expression_error: /* expression_error  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2983 "basilisk.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2992 "basilisk.c"
        break;

    case YYSYMBOL_enumeration_constant: /* enumeration_constant  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3001 "basilisk.c"
        break;

    case YYSYMBOL_string: /* string  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3010 "basilisk.c"
        break;

    case YYSYMBOL_generic_selection: /* generic_selection  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3019 "basilisk.c"
        break;

    case YYSYMBOL_generic_assoc_list: /* generic_assoc_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3028 "basilisk.c"
        break;

    case YYSYMBOL_generic_association: /* generic_association  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3037 "basilisk.c"
        break;

    case YYSYMBOL_postfix_expression: /* postfix_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3046 "basilisk.c"
        break;

    case YYSYMBOL_postfix_initializer: /* postfix_initializer  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3055 "basilisk.c"
        break;

    case YYSYMBOL_array_access: /* array_access  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3064 "basilisk.c"
        break;

    case YYSYMBOL_function_call: /* function_call  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3073 "basilisk.c"
        break;

    case YYSYMBOL_member_identifier: /* member_identifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3082 "basilisk.c"
        break;

    case YYSYMBOL_argument_expression_list: /* argument_expression_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3091 "basilisk.c"
        break;

    case YYSYMBOL_argument_expression_list_item: /* argument_expression_list_item  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3100 "basilisk.c"
        break;

    case YYSYMBOL_unary_expression: /* unary_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3109 "basilisk.c"
        break;

    case YYSYMBOL_unary_operator: /* unary_operator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3118 "basilisk.c"
        break;

    case YYSYMBOL_cast_expression: /* cast_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3127 "basilisk.c"
        break;

    case YYSYMBOL_multiplicative_expression: /* multiplicative_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3136 "basilisk.c"
        break;

    case YYSYMBOL_additive_expression: /* additive_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3145 "basilisk.c"
        break;

    case YYSYMBOL_shift_expression: /* shift_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3154 "basilisk.c"
        break;

    case YYSYMBOL_relational_expression: /* relational_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3163 "basilisk.c"
        break;

    case YYSYMBOL_equality_expression: /* equality_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3172 "basilisk.c"
        break;

    case YYSYMBOL_and_expression: /* and_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3181 "basilisk.c"
        break;

    case YYSYMBOL_exclusive_or_expression: /* exclusive_or_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3190 "basilisk.c"
        break;

    case YYSYMBOL_inclusive_or_expression: /* inclusive_or_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3199 "basilisk.c"
        break;

    case YYSYMBOL_logical_and_expression: /* logical_and_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3208 "basilisk.c"
        break;

    case YYSYMBOL_logical_or_expression: /* logical_or_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3217 "basilisk.c"
        break;

    case YYSYMBOL_conditional_expression: /* conditional_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3226 "basilisk.c"
        break;

    case YYSYMBOL_assignment_expression: /* assignment_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3235 "basilisk.c"
        break;

    case YYSYMBOL_assignment_operator: /* assignment_operator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3244 "basilisk.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3253 "basilisk.c"
        break;

    case YYSYMBOL_constant_expression: /* constant_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3262 "basilisk.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3271 "basilisk.c"
        break;

    case YYSYMBOL_declaration_specifiers: /* declaration_specifiers  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3280 "basilisk.c"
        break;

    case YYSYMBOL_init_declarator_list: /* init_declarator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3289 "basilisk.c"
        break;

    case YYSYMBOL_init_declarator: /* init_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3298 "basilisk.c"
        break;

    case YYSYMBOL_storage_class_specifier: /* storage_class_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3307 "basilisk.c"
        break;

    case YYSYMBOL_type_specifier: /* type_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3316 "basilisk.c"
        break;

    case YYSYMBOL_types: /* types  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3325 "basilisk.c"
        break;

    case YYSYMBOL_struct_or_union_specifier: /* struct_or_union_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3334 "basilisk.c"
        break;

    case YYSYMBOL_struct_or_union: /* struct_or_union  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3343 "basilisk.c"
        break;

    case YYSYMBOL_struct_declaration_list: /* struct_declaration_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3352 "basilisk.c"
        break;

    case YYSYMBOL_struct_declaration: /* struct_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3361 "basilisk.c"
        break;

    case YYSYMBOL_specifier_qualifier_list: /* specifier_qualifier_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3370 "basilisk.c"
        break;

    case YYSYMBOL_struct_declarator_list: /* struct_declarator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3379 "basilisk.c"
        break;

    case YYSYMBOL_struct_declarator: /* struct_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3388 "basilisk.c"
        break;

    case YYSYMBOL_enum_specifier: /* enum_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3397 "basilisk.c"
        break;

    case YYSYMBOL_enumerator_list: /* enumerator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3406 "basilisk.c"
        break;

    case YYSYMBOL_enumerator: /* enumerator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3415 "basilisk.c"
        break;

    case YYSYMBOL_atomic_type_specifier: /* atomic_type_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3424 "basilisk.c"
        break;

    case YYSYMBOL_type_qualifier: /* type_qualifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3433 "basilisk.c"
        break;

    case YYSYMBOL_function_specifier: /* function_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3442 "basilisk.c"
        break;

    case YYSYMBOL_alignment_specifier: /* alignment_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3451 "basilisk.c"
        break;

    case YYSYMBOL_declarator: /* declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3460 "basilisk.c"
        break;

    case YYSYMBOL_direct_declarator: /* direct_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3469 "basilisk.c"
        break;

    case YYSYMBOL_generic_identifier: /* generic_identifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3478 "basilisk.c"
        break;

    case YYSYMBOL_pointer: /* pointer  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3487 "basilisk.c"
        break;

    case YYSYMBOL_type_qualifier_list: /* type_qualifier_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3496 "basilisk.c"
        break;

    case YYSYMBOL_parameter_type_list: /* parameter_type_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3505 "basilisk.c"
        break;

    case YYSYMBOL_parameter_list: /* parameter_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3514 "basilisk.c"
        break;

    case YYSYMBOL_parameter_declaration: /* parameter_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3523 "basilisk.c"
        break;

    case YYSYMBOL_identifier_list: /* identifier_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3532 "basilisk.c"
        break;

    case YYSYMBOL_type_name: /* type_name  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3541 "basilisk.c"
        break;

    case YYSYMBOL_abstract_declarator: /* abstract_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3550 "basilisk.c"
        break;

    case YYSYMBOL_direct_abstract_declarator: /* direct_abstract_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3559 "basilisk.c"
        break;

    case YYSYMBOL_type_not_specified: /* type_not_specified  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3568 "basilisk.c"
        break;

    case YYSYMBOL_initializer: /* initializer  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3577 "basilisk.c"
        break;

    case YYSYMBOL_initializer_list: /* initializer_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3586 "basilisk.c"
        break;

    case YYSYMBOL_designation: /* designation  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3595 "basilisk.c"
        break;

    case YYSYMBOL_designator_list: /* designator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3604 "basilisk.c"
        break;

    case YYSYMBOL_designator: /* designator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3613 "basilisk.c"
        break;

    case YYSYMBOL_static_assert_declaration: /* static_assert_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3622 "basilisk.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3631 "basilisk.c"
        break;

    case YYSYMBOL_labeled_statement: /* labeled_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3640 "basilisk.c"
        break;

    case YYSYMBOL_compound_statement: /* compound_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3649 "basilisk.c"
        break;

    case YYSYMBOL_186_1: /* @1  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3658 "basilisk.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3667 "basilisk.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3676 "basilisk.c"
        break;

    case YYSYMBOL_expression_statement: /* expression_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3685 "basilisk.c"
        break;

    case YYSYMBOL_selection_statement: /* selection_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3694 "basilisk.c"
        break;

    case YYSYMBOL_for_scope: /* for_scope  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3703 "basilisk.c"
        break;

    case YYSYMBOL_iteration_statement: /* iteration_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3712 "basilisk.c"
        break;

    case YYSYMBOL_for_declaration_statement: /* for_declaration_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3721 "basilisk.c"
        break;

    case YYSYMBOL_jump_statement: /* jump_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3730 "basilisk.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3739 "basilisk.c"
        break;

    case YYSYMBOL_function_declaration: /* function_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3748 "basilisk.c"
        break;

    case YYSYMBOL_function_definition: /* function_definition  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3757 "basilisk.c"
        break;

    case YYSYMBOL_declaration_list: /* declaration_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3766 "basilisk.c"
        break;

    case YYSYMBOL_basilisk_statements: /* basilisk_statements  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3775 "basilisk.c"
        break;

    case YYSYMBOL_macro_call: /* macro_call  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3784 "basilisk.c"
        break;

    case YYSYMBOL_macro_statement: /* macro_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3793 "basilisk.c"
        break;

    case YYSYMBOL_foreach_statement: /* foreach_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3802 "basilisk.c"
        break;

    case YYSYMBOL_foreach_parameters: /* foreach_parameters  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3811 "basilisk.c"
        break;

    case YYSYMBOL_foreach_parameter: /* foreach_parameter  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3820 "basilisk.c"
        break;

    case YYSYMBOL_reduction_list: /* reduction_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3829 "basilisk.c"
        break;

    case YYSYMBOL_reduction: /* reduction  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3838 "basilisk.c"
        break;

    case YYSYMBOL_reduction_operator: /* reduction_operator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3847 "basilisk.c"
        break;

    case YYSYMBOL_reduction_array: /* reduction_array  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3856 "basilisk.c"
        break;

    case YYSYMBOL_foreach_dimension_statement: /* foreach_dimension_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3865 "basilisk.c"
        break;

    case YYSYMBOL_forin_declaration_statement: /* forin_declaration_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3874 "basilisk.c"
        break;

    case YYSYMBOL_forin_statement: /* forin_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3883 "basilisk.c"
        break;

    case YYSYMBOL_forin_arguments: /* forin_arguments  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3892 "basilisk.c"
        break;

    case YYSYMBOL_event_definition: /* event_definition  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3901 "basilisk.c"
        break;

    case YYSYMBOL_event_parameters: /* event_parameters  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3910 "basilisk.c"
        break;

    case YYSYMBOL_event_parameter: /* event_parameter  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3919 "basilisk.c"
        break;

    case YYSYMBOL_boundary_definition: /* boundary_definition  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3928 "basilisk.c"
        break;

    case YYSYMBOL_external_foreach_dimension: /* external_foreach_dimension  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3937 "basilisk.c"
        break;

    case YYSYMBOL_attribute: /* attribute  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3946 "basilisk.c"
        break;

    case YYSYMBOL_new_field: /* new_field  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3955 "basilisk.c"
        break;

    case YYSYMBOL_root: /* root  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3964 "basilisk.c"
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
#line 4360 "basilisk.c"
    break;

  case 5: /* translation_unit: translation_unit error '}'  */
#line 113 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4366 "basilisk.c"
    break;

  case 6: /* translation_unit: translation_unit error ')'  */
#line 114 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4372 "basilisk.c"
    break;

  case 13: /* expression_error: error  */
#line 127 "basilisk.yacc"
                        { yyvsp[0]->sym = YYSYMBOL_YYerror; }
#line 4378 "basilisk.c"
    break;

  case 111: /* declaration: declaration_specifiers ';' type_not_specified  */
#line 323 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 4384 "basilisk.c"
    break;

  case 112: /* declaration: declaration_specifiers init_declarator_list ';' type_not_specified  */
#line 324 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 4390 "basilisk.c"
    break;

  case 135: /* type_specifier: types  */
#line 362 "basilisk.yacc"
                   { parse->type_already_specified = true; }
#line 4396 "basilisk.c"
    break;

  case 155: /* struct_or_union_specifier: struct_or_union '{' error '}'  */
#line 388 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4402 "basilisk.c"
    break;

  case 156: /* struct_or_union_specifier: struct_or_union generic_identifier '{' error '}'  */
#line 389 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4408 "basilisk.c"
    break;

  case 206: /* direct_declarator: direct_declarator '(' type_not_specified error ')'  */
#line 484 "basilisk.yacc"
                                                                                           { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4414 "basilisk.c"
    break;

  case 254: /* type_not_specified: %empty  */
#line 565 "basilisk.yacc"
           { parse->type_already_specified = false; }
#line 4420 "basilisk.c"
    break;

  case 275: /* statement: error ';'  */
#line 607 "basilisk.yacc"
                     { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4426 "basilisk.c"
    break;

  case 280: /* @1: %empty  */
#line 619 "basilisk.yacc"
                           { stack_push (parse->stack, &(yyvsp[0])); yyval->sym = YYSYMBOL_YYUNDEF; }
#line 4432 "basilisk.c"
    break;

  case 281: /* compound_statement: '{' @1 block_item_list '}'  */
#line 621 "basilisk.yacc"
                           { ast_pop_scope (parse->stack, yyvsp[-3]); }
#line 4438 "basilisk.c"
    break;

  case 291: /* for_scope: FOR  */
#line 646 "basilisk.yacc"
              { stack_push (parse->stack, &(yyval)); }
#line 4444 "basilisk.c"
    break;

  case 294: /* iteration_statement: for_scope '(' expression_statement expression_statement ')' statement  */
#line 653 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 4450 "basilisk.c"
    break;

  case 295: /* iteration_statement: for_scope '(' expression_statement expression_statement expression ')' statement  */
#line 655 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 4456 "basilisk.c"
    break;

  case 297: /* for_declaration_statement: for_scope '(' declaration expression_statement ')' statement  */
#line 661 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 4462 "basilisk.c"
    break;

  case 298: /* for_declaration_statement: for_scope '(' declaration expression_statement expression ')' statement  */
#line 663 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 4468 "basilisk.c"
    break;

  case 311: /* external_declaration: error compound_statement  */
#line 682 "basilisk.yacc"
                                                { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4474 "basilisk.c"
    break;

  case 312: /* function_declaration: declaration_specifiers declarator  */
#line 686 "basilisk.yacc"
                                            { ast_push_function_definition (parse->stack, yyvsp[0]);  }
#line 4480 "basilisk.c"
    break;

  case 313: /* function_definition: function_declaration declaration_list compound_statement  */
#line 691 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-2]->child[1]); }
#line 4486 "basilisk.c"
    break;

  case 314: /* function_definition: function_declaration compound_statement  */
#line 693 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-1]->child[1]); }
#line 4492 "basilisk.c"
    break;

  case 343: /* forin_declaration_statement: for_scope '(' declaration_specifiers declarator IDENTIFIER forin_arguments ')' statement  */
#line 765 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-7]); }
#line 4498 "basilisk.c"
    break;

  case 344: /* forin_statement: for_scope '(' expression IDENTIFIER forin_arguments ')' statement  */
#line 770 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 4504 "basilisk.c"
    break;

  case 360: /* root: translation_unit  */
#line 813 "basilisk.yacc"
                           {
	  yyval = root;
	  yyval->sym = yyr1[yyn];
	  yyval->child = allocate ((Allocator *)parse->alloc, 2*sizeof(Ast *));
	  yyval->child[0] = yyvsp[0];
	  yyvsp[0]->parent = yyval;
	  yyval->child[1] = NULL;
        }
#line 4517 "basilisk.c"
    break;


#line 4521 "basilisk.c"

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

#line 823 "basilisk.yacc"


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
