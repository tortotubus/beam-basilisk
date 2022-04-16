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
#line 31 "basilisk.yacc"

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
  YYSYMBOL_IN = 77,                        /* IN  */
  YYSYMBOL_NEW_FIELD = 78,                 /* NEW_FIELD  */
  YYSYMBOL_TRACE = 79,                     /* TRACE  */
  YYSYMBOL_FOREACH = 80,                   /* FOREACH  */
  YYSYMBOL_FOREACH_INNER = 81,             /* FOREACH_INNER  */
  YYSYMBOL_FOREACH_DIMENSION = 82,         /* FOREACH_DIMENSION  */
  YYSYMBOL_REDUCTION = 83,                 /* REDUCTION  */
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
  YYSYMBOL_94_ = 94,                       /* '&'  */
  YYSYMBOL_95_ = 95,                       /* '*'  */
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
  YYSYMBOL_macro_statement = 200,          /* macro_statement  */
  YYSYMBOL_foreach_statement = 201,        /* foreach_statement  */
  YYSYMBOL_foreach_parameters = 202,       /* foreach_parameters  */
  YYSYMBOL_foreach_parameter = 203,        /* foreach_parameter  */
  YYSYMBOL_reduction_list = 204,           /* reduction_list  */
  YYSYMBOL_reduction = 205,                /* reduction  */
  YYSYMBOL_reduction_operator = 206,       /* reduction_operator  */
  YYSYMBOL_reduction_array = 207,          /* reduction_array  */
  YYSYMBOL_foreach_inner_statement = 208,  /* foreach_inner_statement  */
  YYSYMBOL_foreach_dimension_statement = 209, /* foreach_dimension_statement  */
  YYSYMBOL_forin_declaration_statement = 210, /* forin_declaration_statement  */
  YYSYMBOL_forin_statement = 211,          /* forin_statement  */
  YYSYMBOL_forin_arguments = 212,          /* forin_arguments  */
  YYSYMBOL_field_list = 213,               /* field_list  */
  YYSYMBOL_event_definition = 214,         /* event_definition  */
  YYSYMBOL_event_parameters = 215,         /* event_parameters  */
  YYSYMBOL_event_parameter = 216,          /* event_parameter  */
  YYSYMBOL_boundary_definition = 217,      /* boundary_definition  */
  YYSYMBOL_external_foreach_dimension = 218, /* external_foreach_dimension  */
  YYSYMBOL_attribute = 219,                /* attribute  */
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
#define YYFINAL  196
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3640

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  355
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  640

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
       2,     2,     2,    99,     2,     2,     2,   101,    94,     2,
      87,    86,    95,    96,    88,    97,    90,   100,     2,     2,
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
       0,    82,    82,    83,    84,    85,    86,    90,    91,    92,
      93,    94,    98,    99,   103,   104,   105,   109,   113,   114,
     118,   122,   123,   127,   128,   132,   133,   134,   135,   136,
     137,   138,   139,   143,   144,   148,   149,   153,   154,   158,
     162,   163,   164,   168,   169,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   185,   186,   187,   188,   189,   190,
     194,   195,   201,   202,   203,   204,   208,   209,   210,   214,
     215,   216,   220,   221,   222,   223,   224,   228,   229,   230,
     234,   235,   239,   240,   244,   245,   249,   250,   254,   255,
     259,   260,   264,   265,   266,   267,   268,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   286,   287,
     291,   295,   296,   297,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   314,   315,   319,   320,   324,   325,
     326,   327,   328,   329,   330,   334,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   357,   358,   359,   360,   361,   365,   366,   370,
     371,   375,   376,   377,   381,   382,   383,   384,   388,   389,
     393,   394,   395,   399,   400,   401,   402,   403,   407,   408,
     412,   413,   417,   421,   422,   423,   424,   425,   429,   430,
     434,   435,   439,   440,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   462,
     463,   467,   468,   469,   470,   474,   475,   479,   480,   484,
     485,   489,   490,   491,   495,   496,   500,   501,   505,   506,
     507,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   535,   539,   540,   541,   545,   546,   547,   548,
     552,   556,   557,   561,   562,   566,   570,   571,   572,   573,
     574,   575,   576,   577,   581,   582,   583,   587,   589,   589,
     595,   596,   600,   601,   605,   606,   610,   611,   612,   616,
     620,   621,   622,   624,   626,   630,   632,   637,   638,   639,
     640,   641,   645,   646,   647,   648,   649,   650,   651,   652,
     656,   660,   662,   667,   668,   675,   676,   677,   678,   679,
     680,   684,   688,   689,   693,   694,   698,   699,   703,   704,
     708,   712,   713,   717,   718,   722,   723,   727,   728,   732,
     737,   742,   743,   747,   751,   755,   756,   757,   761,   762,
     763,   767,   771,   772,   776,   780
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
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "MAYBECONST", "IN",
  "NEW_FIELD", "TRACE", "FOREACH", "FOREACH_INNER", "FOREACH_DIMENSION",
  "REDUCTION", "';'", "'}'", "')'", "'('", "','", "':'", "'.'", "'{'",
  "'['", "']'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
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
  "declaration_list", "basilisk_statements", "macro_statement",
  "foreach_statement", "foreach_parameters", "foreach_parameter",
  "reduction_list", "reduction", "reduction_operator", "reduction_array",
  "foreach_inner_statement", "foreach_dimension_statement",
  "forin_declaration_statement", "forin_statement", "forin_arguments",
  "field_list", "event_definition", "event_parameters", "event_parameter",
  "boundary_definition", "external_foreach_dimension", "attribute", "root", YY_NULLPTR
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
      46,   123,    91,    93,    38,    42,    43,    45,   126,    33,
      47,    37,    60,    62,    94,   124,    63,    61
};
#endif

#define YYPACT_NINF (-532)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-356)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1108,   -50,   206,  -532,  -532,  -532,  -532,  2728,  2825,  2825,
     434,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,
    -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,
    -532,  -532,  -532,  -532,  -532,    48,   -67,   -40,   -28,   -21,
    -532,    -7,  -532,  -532,    51,  -532,    66,  1207,  -532,  -532,
    -532,  -532,  -532,  -532,   808,  -532,  -532,  -532,  -532,   310,
    -532,   -50,   613,  2838,  -532,   121,    79,   205,    97,   369,
      72,     1,    77,   176,    14,  -532,   158,  -532,   174,  3444,
    3444,  -532,  -532,    65,  -532,  -532,  3444,  3444,  3444,   156,
    -532,  -532,  3136,  -532,  -532,  -532,  -532,  -532,  -532,   250,
     232,  -532,  -532,  1207,  -532,  -532,  1207,  -532,  -532,  -532,
    -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,
    2267,  -532,  -532,   254,   171,  1456,  3564,  3564,  2684,  2838,
     324,    18,  -532,   613,   225,  -532,   234,  3564,    92,  3564,
     240,   129,  -532,    60,  -532,  -532,  2140,    60,  2281,  -532,
    2267,  -532,  -532,  2838,  2838,  2838,  2838,  2838,  2838,  2838,
    2838,  2838,  2838,  2838,  2838,  2838,  2838,  2838,  2838,  2838,
    2838,  2684,  -532,  -532,   177,   214,   146,  -532,   -32,   -42,
    -532,   180,  -532,  -532,  -532,  2833,   255,  -532,  -532,  -532,
    3486,   277,  -532,   174,  -532,  3136,  -532,  -532,  1009,   253,
     267,   613,  2062,  -532,  -532,  -532,   261,     3,  -532,   254,
    -532,   289,   296,   309,   312,   313,   320,   334,   337,  3444,
    -532,  2684,  -532,  3072,  1534,    68,  -532,   103,  -532,  -532,
    2714,  -532,  -532,  -532,  -532,  -532,  -532,  2684,   149,  -532,
    -532,  -532,  -532,  -532,   -58,  -532,  -532,  -532,  -532,  -532,
     121,   121,    79,    79,   205,   205,   205,   205,    97,    97,
     369,    72,     1,    77,   176,   326,  -532,   339,  -532,  -532,
    -532,   214,  -532,   177,  2311,  -532,  1577,  -532,   -42,   325,
    3246,  -532,    46,  -532,  3027,  3294,  2838,   305,  -532,  -532,
     348,  2838,   345,   349,   350,   351,  1262,  -532,    60,   355,
     356,  2389,   354,   357,   359,  -532,   190,  -532,   346,  -532,
    -532,  -532,   910,  -532,  -532,  -532,   360,  -532,  -532,  -532,
    -532,  -532,  -532,  -532,  -532,  -532,  -532,   358,   358,    60,
    2062,  2838,  -532,  -532,   183,  2311,    82,  -532,  2838,  -532,
      61,   204,  -532,  -532,  -532,  -532,  3525,   436,  -532,  3444,
     177,  -532,  -532,  -532,   178,   365,   376,  -532,   367,  1897,
    -532,   373,   374,  1655,   103,  -532,  -532,  1698,  -532,  -532,
     228,  -532,  2419,  -532,  2838,  -532,  -532,  -532,  -532,  -532,
    -532,  2972,  1897,  -532,   375,   378,  1776,  -532,  -532,  -532,
    -532,  -532,  2838,   215,  -532,   383,   390,  3342,  -532,   613,
    -532,   248,  -532,  -532,   387,  1262,   679,   679,  2684,   613,
     417,   396,  -532,  -532,  -532,   226,  2170,  2433,    75,  -532,
    1262,  -532,  -532,  1359,  -532,   278,   392,  -532,  1935,  -532,
    -532,  -532,  -532,  -532,  -532,  -532,    86,   397,   212,  -532,
     398,   403,  -532,  -532,  2908,  -532,    70,  -532,  -532,  3396,
    -532,  -532,   400,  1897,  -532,  -532,  2684,  -532,   402,  3196,
    1897,  -532,   404,   405,  1819,  -532,  -532,  -532,   410,  -532,
    -532,   413,   252,   407,  1897,  -532,  -532,  2684,  -532,   409,
     411,  -532,  -532,  -532,   193,  2838,  -532,  -532,  2714,  2838,
    1262,  2838,  1262,  -532,   419,   420,   281,   416,  -532,  -532,
     421,  1262,  -532,   286,  -532,   426,  -532,  1262,   293,   425,
    1262,  -532,   172,  2530,   174,  2530,  -532,  2032,  -532,  -532,
    -532,  2311,  -532,  2684,  -532,  3525,  2684,   428,  -532,  -532,
    -532,  -532,   422,   423,  -532,  -532,   427,   424,  1897,  -532,
    -532,  2684,  -532,   429,  -532,  -532,  -532,   511,  -532,   431,
     433,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,
    -532,  -532,  1262,  1262,  1262,  2684,    40,  -532,  1262,  2560,
    -532,  -532,  1262,  1262,  -532,  2419,  2574,   -52,  2671,  -532,
    -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,  -532,
     435,   438,  -532,  -532,  -532,  -532,   460,  -532,  -532,   306,
    -532,  -532,   432,  -532,  -532,  -532,  -532,   234,   441,  -532,
    1262,   318,  2419,  1262,   321,  -532,  -532,  1262,   449,    60,
    1262,  -532,  1262,   450,  -532,  1262,  -532,  -532,   443,   451,
    -532,  -532,  1262,  -532,   453,  -532,  -532,  2684,    13,  -532
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
     189,     0,   131,   187,    52,   134,     0,     0,    54,    55,
      56,    57,    58,    59,     0,    25,     8,     9,    11,    45,
      27,    26,    60,     0,    62,    66,    69,    72,    77,    80,
      82,    84,    86,    88,    90,    92,     0,   303,     0,   115,
     117,   135,   149,     0,   150,   148,   119,   121,   123,     0,
     113,     2,     0,   302,   304,   305,   306,   307,   308,     0,
     278,   309,     7,     0,    26,    49,     0,    46,    47,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    97,
       0,   209,   210,     0,   177,     0,     0,     0,     0,     0,
       0,     0,    13,   151,     0,   108,    12,   165,   252,   167,
       0,     0,     3,     0,    30,    31,     0,     0,     0,   321,
       0,    60,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   351,   252,     0,   214,     0,   124,   310,   252,
     194,     0,   151,   114,   116,     0,   154,   118,   120,   122,
       0,     0,   313,     0,   312,     0,     1,   277,     0,     0,
       0,     0,     0,    96,    95,    17,   181,     0,   178,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     0,   164,     0,     0,   229,   252,   230,   227,   166,
       0,     4,     5,     6,    29,    39,    37,     0,     0,    40,
      43,    44,    28,    35,     0,    94,    93,    63,    64,    65,
      67,    68,    70,    71,    75,    76,    73,    74,    78,    79,
      81,    83,    85,    87,    89,     0,   111,     0,   186,   215,
     213,   212,   252,     0,     0,   252,     0,   193,   252,     0,
       0,   159,     0,   163,     0,     0,     0,   127,   314,   311,
       0,     0,     0,     0,     0,     0,     0,   289,     0,     0,
       0,     0,     0,     0,     0,   284,     0,   282,     0,   283,
     266,   267,     0,   280,   268,   269,     0,   270,   294,   271,
     272,   315,   316,   317,   318,   319,   320,    50,     0,     0,
       0,     0,   255,   257,     0,     0,     0,   261,     0,   173,
       0,     0,   191,   190,    51,   182,     0,     0,    53,     0,
       0,   352,   109,   248,   223,     0,   218,   252,     0,     0,
     232,    55,     0,     0,   228,   226,   252,     0,    32,    61,
       0,    38,    42,    36,     0,   195,   216,   211,   112,   125,
     126,     0,     0,   196,    55,     0,     0,   192,   155,   152,
     160,   252,     0,     0,   168,   172,     0,     0,   354,    60,
     348,     0,   345,   273,     0,     0,     0,     0,     0,   210,
       0,     0,   298,   299,   300,     0,     0,     0,     0,   285,
       0,   279,   281,     0,   264,     0,     0,    33,     0,   256,
     260,   262,   180,   174,   179,   175,     0,     0,     0,    21,
       0,     0,   353,   310,     0,   221,   229,   222,   249,     0,
     219,   231,     0,     0,   233,   239,     0,   238,     0,     0,
       0,   240,    55,     0,     0,   343,    41,    91,     0,   224,
     207,     0,     0,     0,     0,   197,   204,     0,   203,    55,
       0,   161,   170,   252,     0,     0,   156,   153,     0,     0,
       0,     0,     0,   276,     0,     0,     0,     0,   297,   301,
       0,     0,   326,     0,   324,   327,   328,     0,     0,     0,
       0,   274,     0,     0,     0,     0,   253,     0,   263,    34,
     259,     0,   176,     0,    20,     0,     0,     0,   151,   217,
     252,   235,     0,     0,   237,   250,     0,     0,     0,   241,
     247,     0,   246,     0,   206,   205,   208,     0,   199,     0,
       0,   200,   202,   162,   169,   171,   350,   349,   347,   344,
     346,   275,     0,     0,     0,     0,     0,   322,     0,     0,
     329,   335,     0,     0,   337,     0,     0,   127,     0,   254,
     258,    24,    22,    23,   265,   220,   234,   236,   251,   243,
       0,     0,   244,   225,   198,   201,   287,   288,   290,     0,
     332,   331,     0,   323,   325,   336,   338,   341,     0,   342,
       0,     0,     0,     0,     0,   242,   245,     0,     0,     0,
       0,   295,     0,     0,   292,     0,   286,   291,   333,     0,
     340,   296,     0,   293,     0,   330,   339,     0,     0,   334
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -532,  -532,  -532,    10,  -532,  -532,  -532,  -532,  -532,    23,
     430,  -118,  -532,     0,   406,  -532,   167,   538,  -532,   -27,
     262,   270,   188,   266,   384,   382,   386,   408,   381,  -532,
     -98,    17,   -57,   -46,  -126,   -66,    29,  -532,   279,  -532,
     -41,  -532,  -532,  -532,  -150,  -243,  -116,  -532,    83,  -532,
     347,  -312,  -532,   198,  -532,  -532,   -71,  -171,     4,  -129,
    -209,  -328,  -532,   110,  -532,   181,  -125,  -214,  -165,  -258,
     239,  -394,  -532,   235,  -166,   169,  -532,    11,  -532,  -532,
     263,  -375,  -532,  -532,  -532,  -532,  -532,   522,  -532,  -201,
    -532,  -532,    38,  -532,  -532,     9,  -532,    74,  -532,  -532,
    -532,  -532,  -532,  -532,   -31,  -531,  -532,  -532,  -392,  -532,
    -532,  -532,  -532
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    54,    55,   134,    56,   206,    57,    58,   438,   439,
      59,   368,    60,   104,   234,   238,   239,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   135,   120,   306,   211,    77,   354,   176,   177,    79,
      80,    81,    82,    83,   280,   281,   138,   393,   394,    84,
     207,   208,    85,    86,    87,    88,   267,   179,   308,   181,
     271,   355,   356,   357,   472,   440,   358,   227,   228,   333,
     334,   335,   336,   337,    90,   309,   310,   311,   198,   312,
     313,   314,   315,   316,   317,   318,   319,    91,    92,    93,
     195,   320,   321,   322,   503,   504,   505,   506,   602,   629,
     323,   324,   325,   326,   608,   241,    95,   401,   402,    96,
      97,    98,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,   136,   203,   216,    89,   150,   137,   178,   266,   225,
     278,   364,   101,   226,   277,   363,   380,    76,   351,   283,
     125,   222,   218,   229,   283,   612,   192,   210,   434,    78,
     221,   210,   245,   170,   521,   373,   152,   390,    94,   124,
     285,   100,   390,   121,   609,   275,   270,   126,   515,   121,
     276,   121,  -127,   471,    61,   274,  -127,   136,    89,   127,
     136,   365,   137,   121,   205,   137,   128,   386,   121,   282,
     122,    76,   149,   121,   282,   274,   122,   429,   122,   509,
     129,   609,   180,    78,   137,   137,   137,   186,   339,   205,
     122,   340,    94,   191,   225,   122,   137,   558,   137,   560,
     122,   221,   244,   194,   219,   167,   639,   378,   183,   184,
     381,   160,   161,   387,   283,   187,   188,   189,   283,   283,
     171,   193,   287,   521,   434,   265,   247,   248,   249,   288,
     391,   536,   307,   174,   397,   392,   600,   204,   576,   123,
     578,   175,   377,   130,   137,   215,   433,   235,   442,   137,
     453,   235,   101,   131,   390,   223,   185,   444,   464,   121,
     224,   510,   224,   240,   282,   404,   166,   246,   282,   282,
     520,   522,   329,   474,   331,   156,   157,   121,   180,   223,
     121,   121,   168,   121,   224,   180,   122,   175,   400,   430,
     366,   370,   450,   210,   169,   367,   121,   180,    61,   162,
     163,   459,   287,   369,   122,   426,   289,   122,   122,  -209,
     122,   395,   432,   231,   232,   233,   153,   158,   159,   332,
     100,   154,   155,   122,   193,   446,   481,   193,   140,   447,
     272,   283,   364,   210,   273,   371,  -209,   372,   352,   137,
     210,   362,   172,   137,   137,   139,   307,   190,   350,   575,
     196,   538,    18,    19,    20,   415,   419,   205,   173,   520,
     221,   174,   209,   580,   174,   444,   482,   174,   427,   175,
     224,   428,   175,   175,   419,   278,   467,   180,   221,   443,
     174,   282,   392,   445,   199,   268,   180,   200,   175,   435,
      43,   332,   436,   385,   210,  -209,    61,  -209,   524,   483,
     525,   139,   411,   484,   139,   137,   212,   213,   214,   175,
     499,   220,    61,   465,   221,   446,   221,   197,   553,   143,
     144,   145,   221,   139,   139,   139,   230,   102,     3,     4,
       5,     6,   489,   424,   490,   139,   491,   139,   546,   327,
     547,   193,   488,   143,   144,   145,   284,   332,   254,   255,
     256,   257,   332,   328,   180,    11,   137,   513,   180,   555,
     136,   136,   496,   516,   286,   585,   517,   564,   338,   221,
     556,   508,   568,   269,   569,   342,   452,   512,   350,   572,
     458,   221,   343,   139,   463,   164,   165,   210,   139,   240,
     557,   400,   618,   400,   221,   344,    39,   146,   345,   473,
     147,   346,   148,   480,   622,    61,   221,   625,   347,   221,
     388,   106,   274,   395,   221,   374,   494,   495,   250,   251,
      61,   146,   269,   349,   147,   375,   148,   348,   252,   253,
     258,   259,   403,   502,   405,   420,   406,   407,   408,   412,
     413,   416,   441,   577,   417,   332,   418,   423,   180,   202,
     180,   448,   514,   451,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   449,   410,   454,   455,   475,   376,
     532,   476,   485,   533,   269,   486,   492,   537,   139,   497,
     498,   543,   139,   139,   137,   518,   523,   526,   180,   527,
      61,   549,    61,   531,   550,   534,   544,   539,   540,   545,
     548,    61,   551,   565,   552,   562,   563,    61,   566,   500,
      61,   573,   584,   588,   593,   586,   587,   589,   180,   599,
     617,   619,   592,  -210,   594,  -210,   595,   620,   615,   607,
     611,   616,   614,   627,   332,   634,   632,   635,   332,   466,
     581,   119,   637,   583,   139,   105,   107,   108,   582,   261,
     260,   264,   379,   242,   262,   590,   341,   269,   591,   530,
     217,   376,    61,    61,    61,   269,   607,   554,    61,   425,
     601,   431,    61,    61,   493,   422,   142,   263,   604,   570,
     269,   623,     0,     0,   376,     0,   502,     0,     0,   511,
       0,   638,     0,     0,     0,   139,     0,     0,     0,     0,
       0,   151,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,    61,     0,     0,     0,    61,     0,     0,
      61,     0,    61,   628,     0,    61,     0,     0,     0,     0,
       0,     0,    61,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,     0,     0,     0,     0,     0,     0,     0,
       0,   376,     0,     0,     0,     0,     0,     0,   269,   559,
       0,   561,   376,   151,     0,     0,     0,   151,     0,     0,
     567,     0,   376,     0,     0,     0,   571,     0,     0,   574,
     132,     0,   102,     3,     4,     5,     6,     7,     0,     8,
       9,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   201,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,   139,     0,     0,     0,     0,     0,     0,
       0,   596,   597,   598,     0,     0,   376,   603,     0,     0,
       0,   605,   606,     0,     0,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,   151,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   621,
       0,     0,   624,     0,     0,     0,   626,     0,     0,   630,
       0,   631,     0,     0,   633,     0,     0,     0,     0,     0,
       0,   636,     0,     0,     0,     0,     0,     0,  -355,   141,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,   399,     0,     0,     0,     0,   151,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,   151,
       0,     0,     0,     0,     0,     0,   151,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,     0,     0,
      46,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     0,     0,
       0,   290,   151,     2,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
     151,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,   291,   292,   293,
       0,   294,   295,   296,   297,   298,   299,   300,   301,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
     302,   303,   304,     0,   305,   421,     0,    47,     0,     0,
       0,   100,     0,     0,    48,    49,    50,    51,    52,    53,
     290,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,   151,     0,     0,   151,   399,     0,   399,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,   291,   292,   293,     0,
     294,   295,   296,   297,   298,   299,   300,   301,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,   302,
     303,   304,     0,   305,     0,     0,    47,     0,     0,     0,
     100,     0,     0,    48,    49,    50,    51,    52,    53,     1,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,     0,     0,
      46,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,   132,     0,
     102,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   133,    11,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   290,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,    37,    38,    39,
       0,     0,     0,    43,     0,    44,     0,     0,     0,     0,
       0,     0,   409,    11,    47,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   291,
     292,   293,     0,   294,   295,   296,   297,   298,   299,   300,
     301,     0,    37,     0,    39,     0,     0,     0,     0,     0,
      44,     0,   302,   303,   304,     0,   305,     0,     0,    47,
       0,     0,     0,   100,     0,     0,    48,    49,    50,    51,
      52,    53,   102,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   133,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,     0,
       0,     0,     0,   305,     0,     0,    47,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   102,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,    11,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    38,    39,     0,
       0,     0,    43,     0,    44,     0,     0,   102,     3,     4,
       5,     6,     7,    47,     8,     9,     0,     0,     0,     0,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,   201,    11,     0,     0,   359,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,     0,
     102,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,   268,    39,   201,    11,     0,
      43,   382,    44,     0,     0,    18,    19,    20,     0,     0,
       0,    47,     0,     0,     0,     0,     0,   360,    48,   361,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,   268,    39,
       0,     0,     0,    43,     0,    44,     0,     0,   102,     3,
       4,     5,     6,     7,    47,     8,     9,     0,     0,     0,
     383,    48,   384,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,   201,    11,     0,     0,   456,
       0,     0,     0,    18,    19,    20,     0,     0,     0,     0,
       0,   102,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,   268,    39,   201,    11,
       0,    43,   460,    44,     0,     0,    18,    19,    20,     0,
       0,     0,    47,     0,     0,     0,     0,     0,   457,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,   268,
      39,     0,     0,     0,    43,     0,    44,     0,     0,   102,
       3,     4,     5,     6,     7,    47,     8,     9,     0,     0,
       0,   461,    48,   462,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,   201,    11,     0,     0,
     477,     0,     0,     0,    18,    19,    20,     0,     0,     0,
       0,     0,   102,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,   268,    39,   201,
      11,     0,    43,   541,    44,     0,     0,    18,    19,    20,
       0,     0,     0,    47,     0,     0,     0,     0,     0,   478,
      48,   479,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
     268,    39,     0,     0,     0,    43,     0,    44,     0,     0,
     102,     3,     4,     5,     6,     7,    47,     8,     9,     0,
       0,     0,   542,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,   201,    11,     0,
       0,     0,     0,     0,     0,    18,    19,    20,   102,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,    11,    37,   268,    39,
       0,     0,     0,    43,     0,    44,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
     519,     0,    47,     0,     0,   329,   330,   331,     0,    48,
      49,    50,    51,    52,    53,   102,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,    11,     0,   102,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,    11,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,     0,   579,     0,    47,
       0,     0,   329,   330,   331,     0,    48,    49,    50,    51,
      52,    53,    37,     0,    39,     0,     0,     0,     0,     0,
      44,     0,     0,   102,     3,     4,     5,     6,     7,    47,
       8,     9,   329,   330,   331,     0,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
     201,    11,     0,   102,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,    11,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,     0,   236,    47,     0,     0,
       0,   237,     0,     0,    48,    49,    50,    51,    52,    53,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,   500,     0,     0,   501,    47,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,    53,
     102,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,   102,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,   201,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,    11,     0,   102,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    39,
       0,   201,    11,     0,     0,    44,     0,     0,     0,     0,
       0,    37,     0,    39,    47,     0,     0,     0,   202,    44,
       0,    48,    49,    50,    51,    52,    53,     0,    47,     0,
       0,     0,     0,     0,   243,    48,    49,    50,    51,    52,
      53,    37,     0,    39,     0,     0,     0,     0,     0,    44,
       0,     0,   102,     3,     4,     5,     6,     7,    47,     8,
       9,     0,   330,     0,     0,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,   201,
      11,     0,   102,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,   102,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,   201,
      11,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    39,     0,   201,    11,     0,     0,    44,     0,     0,
       0,     0,     0,   414,     0,     0,    47,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    37,
       0,    39,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,    37,     0,    39,    47,     0,     0,     0,
     237,    44,     0,    48,    49,    50,    51,    52,    53,   507,
      47,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,   102,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,    11,     0,   102,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,   102,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
     201,    11,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    39,     0,   201,    11,     0,     0,    44,     0,
       0,     0,     0,     0,   305,     0,     0,    47,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,    53,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,   500,    37,     0,    39,    47,     0,     0,
       0,     0,    44,     0,    48,    49,    50,    51,    52,    53,
     610,    47,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,   102,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,   102,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,   201,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,    11,     0,   102,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,   102,     3,     4,     5,     6,     7,     0,     8,     9,
       0,    37,     0,    39,     0,    11,     0,     0,     0,    44,
       0,     0,     0,     0,    37,     0,    39,   613,    47,    11,
       0,     0,    44,     0,     0,    48,    49,    50,    51,    52,
      53,    47,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    37,     0,    39,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,    37,     0,
      39,    47,     0,     0,     0,   202,    44,     0,    48,    49,
      50,    51,    52,    53,     0,   103,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,   102,     3,
       4,     5,     6,     7,   279,     8,     9,     0,     0,     0,
       0,   102,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,   182,     0,     0,     0,     0,     0,    11,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,     0,    44,    38,     0,     0,    41,    37,    43,
      39,   121,   106,     0,     0,     0,    44,     0,     0,    48,
      49,    50,    51,    52,    53,    47,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,   528,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   468,     0,   469,     0,    36,     0,    38,
       0,    40,     0,    42,    43,     0,     0,    45,     0,     0,
       0,     0,     0,     0,   353,   444,     0,     0,     0,     0,
     224,     0,   182,   175,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   396,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    38,     0,    40,     0,    42,    43,     0,
       0,    45,     0,     0,     0,     0,     0,   182,   470,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    41,   182,    43,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    38,     0,    40,     0,    42,    43,     0,
       0,    45,     0,     0,     0,     0,     0,     0,   353,   223,
       0,     0,     0,     0,   224,     0,   182,   175,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,    38,     0,    40,
      41,    42,    43,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,   100,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,    38,     0,    40,
       0,    42,    43,     0,     0,    45,   182,     0,     0,     0,
       0,     0,   535,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
      41,     0,    43,     0,   182,     0,     0,     0,     0,     0,
       0,   389,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    41,     0,
      43,     0,   182,     0,     0,     0,     0,     0,     0,   398,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,    41,     0,    43,     0,
       0,     0,     0,     0,     0,     0,   182,   487,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   529,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,    38,     0,    40,
       0,    42,    43,     0,   182,    45,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,    38,   182,    40,     0,    42,
      43,     0,     0,    45,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,     0,    38,     0,     0,
      41,     0,    43,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,   437,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,     0,    38,     0,     0,     0,
       0,    43,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
      43
};

static const yytype_int16 yycheck[] =
{
       0,    47,   120,   129,     0,    62,    47,    78,   173,   138,
     181,   225,     1,   138,   179,   224,   274,     0,   219,   185,
      87,   137,     4,   139,   190,    77,    92,   125,   340,     0,
      88,   129,   150,    19,   428,    93,    63,   280,     0,    35,
     190,    91,   285,     3,   575,    87,   175,    87,   423,     3,
      92,     3,    84,   381,    54,   107,    88,   103,    54,    87,
     106,   226,   103,     3,     3,   106,    87,   276,     3,   185,
      30,    54,    61,     3,   190,   107,    30,   335,    30,     4,
      87,   612,    78,    54,   125,   126,   127,    83,    85,     3,
      30,    88,    54,    89,   223,    30,   137,   489,   139,   491,
      30,    88,   148,    92,    86,   104,    93,   272,    79,    80,
     275,    14,    15,   278,   280,    86,    87,    88,   284,   285,
     106,    92,   193,   517,   436,   171,   153,   154,   155,   195,
      84,   459,   198,    87,   284,    89,    96,   120,   513,    91,
     515,    95,   271,    92,   185,   128,    85,   143,   349,   190,
     359,   147,   141,    87,   397,    87,    91,    87,   367,     3,
      92,    86,    92,   146,   280,   291,    94,   150,   284,   285,
     428,    85,    90,   382,    92,    96,    97,     3,   174,    87,
       3,     3,   105,     3,    92,   181,    30,    95,   286,   107,
      87,   237,   357,   291,    18,    92,     3,   193,   198,   102,
     103,   366,   273,   230,    30,   331,   195,    30,    30,     3,
      30,   282,   338,    84,    85,    86,    95,    12,    13,   202,
      91,   100,   101,    30,   195,   354,   391,   198,    47,   354,
      84,   397,   446,   331,    88,    86,    30,    88,   221,   280,
     338,   224,    84,   284,   285,    47,   312,    91,   219,    77,
       0,   460,    38,    39,    40,   301,    84,     3,    84,   517,
      88,    87,    91,   521,    87,    87,   392,    87,    85,    95,
      92,    88,    95,    95,    84,   446,   374,   273,    88,   350,
      87,   397,    89,   354,   103,    71,   282,   106,    95,    85,
      76,   274,    88,   276,   392,    89,   296,    91,    86,    84,
      88,   103,   298,    88,   106,   346,   125,   126,   127,    95,
      84,    86,   312,    85,    88,   444,    88,    85,   483,     9,
      10,    11,    88,   125,   126,   127,    86,     3,     4,     5,
       6,     7,    84,   329,    86,   137,    88,   139,    86,    86,
      88,   312,   399,     9,    10,    11,    91,   330,   160,   161,
     162,   163,   335,    86,   350,    31,   397,   423,   354,   485,
     406,   407,   408,    85,    87,   530,    88,    86,   107,    88,
     488,   417,    86,   175,    88,    86,   359,   423,   349,    86,
     363,    88,    86,   185,   367,    16,    17,   485,   190,   372,
     488,   489,    86,   491,    88,    86,    72,    87,    86,   382,
      90,    88,    92,   386,    86,   405,    88,    86,    88,    88,
      85,    87,   107,   484,    88,    89,   406,   407,   156,   157,
     420,    87,   224,    86,    90,    86,    92,    93,   158,   159,
     164,   165,    84,   416,    89,    89,    87,    87,    87,    84,
      84,    87,     6,   514,    87,   428,    87,    87,   444,    91,
     446,    86,   423,    86,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    88,   296,    93,    93,    93,   271,
     453,    93,    89,   456,   276,    85,    89,   460,   280,    62,
      84,   464,   284,   285,   525,    93,    89,    89,   484,    86,
     490,   474,   492,    93,   477,    93,    86,    93,    93,    86,
      93,   501,    93,    87,    93,    86,    86,   507,    87,    83,
     510,    86,    84,    86,     3,    93,    93,    93,   514,   565,
      60,    89,    93,    89,    93,    91,    93,    86,    93,   575,
     576,    93,   578,    84,   517,    92,    86,    86,   521,   372,
     523,   107,    89,   526,   346,     7,     8,     9,   525,   167,
     166,   170,   273,   147,   168,   538,   209,   359,   541,   449,
     130,   363,   562,   563,   564,   367,   612,   484,   568,   330,
     566,   336,   572,   573,   405,   312,    54,   169,   569,   505,
     382,   612,    -1,    -1,   386,    -1,   569,    -1,    -1,   420,
      -1,   637,    -1,    -1,    -1,   397,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     610,    -1,    -1,   613,    -1,    -1,    -1,   617,    -1,    -1,
     620,    -1,   622,   619,    -1,   625,    -1,    -1,    -1,    -1,
      -1,    -1,   632,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,   460,   490,
      -1,   492,   464,   125,    -1,    -1,    -1,   129,    -1,    -1,
     501,    -1,   474,    -1,    -1,    -1,   507,    -1,    -1,   510,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,   525,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   562,   563,   564,    -1,    -1,   538,   568,    -1,    -1,
      -1,   572,   573,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,   230,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   610,
      -1,    -1,   613,    -1,    -1,    -1,   617,    -1,    -1,   620,
      -1,   622,    -1,    -1,   625,    -1,    -1,    -1,    -1,    -1,
      -1,   632,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,   286,    -1,    -1,    -1,    -1,   291,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,   331,
      -1,    -1,    -1,    -1,    -1,    -1,   338,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,     1,   374,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    -1,    84,    85,    -1,    87,    -1,    -1,
      -1,    91,    -1,    -1,    94,    95,    96,    97,    98,    99,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,   485,    -1,    -1,   488,   489,    -1,   491,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      91,    -1,    -1,    94,    95,    96,    97,    98,    99,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    80,    81,    82,    -1,    84,    -1,    -1,    87,
      -1,    -1,    -1,    91,    -1,    -1,    94,    95,    96,    97,
      98,    99,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    78,    -1,    -1,     3,     4,     5,
       6,     7,     8,    87,    10,    11,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    30,    31,    -1,
      76,    34,    78,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,    78,    -1,    -1,     3,     4,
       5,     6,     7,     8,    87,    10,    11,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    30,    31,
      -1,    76,    34,    78,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    -1,     3,
       4,     5,     6,     7,     8,    87,    10,    11,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    30,
      31,    -1,    76,    34,    78,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    -1,    78,    -1,    -1,
       3,     4,     5,     6,     7,     8,    87,    10,    11,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    87,    -1,    -1,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    87,
      -1,    -1,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,     3,     4,     5,     6,     7,     8,    87,
      10,    11,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    91,    -1,    -1,    94,    95,    96,    97,    98,    99,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    30,    31,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    87,    -1,    -1,    -1,    91,    78,
      -1,    94,    95,    96,    97,    98,    99,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,    98,
      99,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,     3,     4,     5,     6,     7,     8,    87,    10,
      11,    -1,    91,    -1,    -1,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    30,    31,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    87,    -1,    -1,    -1,
      91,    78,    -1,    94,    95,    96,    97,    98,    99,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    30,    31,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    83,    70,    -1,    72,    87,    -1,    -1,
      -1,    -1,    78,    -1,    94,    95,    96,    97,    98,    99,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    70,    -1,    72,    -1,    31,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    70,    -1,    72,    86,    87,    31,
      -1,    -1,    78,    -1,    -1,    94,    95,    96,    97,    98,
      99,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,    70,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    87,    -1,    -1,    -1,    91,    78,    -1,    94,    95,
      96,    97,    98,    99,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,     3,     4,
       5,     6,     7,     8,     1,    10,    11,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    71,    -1,    -1,    74,    70,    76,
      72,     3,    87,    -1,    -1,    -1,    78,    -1,    -1,    94,
      95,    96,    97,    98,    99,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,    -1,    69,    -1,    71,
      -1,    73,    -1,    75,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      92,    -1,    30,    95,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    30,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    30,    76,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    92,    -1,    30,    95,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      74,    75,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    91,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      -1,    75,    76,    -1,    -1,    79,    30,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    76,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      76,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    85,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      -1,    75,    76,    -1,    30,    79,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    30,    73,    -1,    75,
      76,    -1,    -1,    79,    38,    39,    40,    41,    42,    43,
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
      73,    74,    75,    76,    78,    79,    82,    87,    94,    95,
      96,    97,    98,    99,   109,   110,   112,   114,   115,   118,
     120,   121,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   143,   144,   147,
     148,   149,   150,   151,   157,   160,   161,   162,   163,   166,
     182,   195,   196,   197,   200,   214,   217,   218,   219,   220,
      91,   185,     3,    87,   121,   125,    87,   125,   125,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,   107,
     140,     3,    30,    91,   166,    87,    87,    87,    87,    87,
      92,    87,     1,    30,   111,   139,   141,   148,   154,   161,
     173,     1,   195,     9,    10,    11,    87,    90,    92,   185,
     140,   125,   127,    95,   100,   101,    96,    97,    12,    13,
      14,    15,   102,   103,    16,    17,    94,   104,   105,    18,
      19,   106,    84,    84,    87,    95,   145,   146,   164,   165,
     166,   167,    30,   144,   144,    91,   166,   144,   144,   144,
      91,   166,   143,   144,   185,   198,     0,    85,   186,   173,
     173,    30,    91,   119,   139,     3,   113,   158,   159,    91,
     138,   142,   173,   173,   173,   139,   142,   118,     4,    86,
      86,    88,   154,    87,    92,   167,   174,   175,   176,   154,
      86,    84,    85,    86,   122,   166,    86,    91,   123,   124,
     139,   213,   122,    93,   141,   119,   139,   127,   127,   127,
     128,   128,   129,   129,   130,   130,   130,   130,   131,   131,
     132,   133,   134,   135,   136,   141,   176,   164,    71,   161,
     167,   168,    84,    88,   107,    87,    92,   176,   165,     1,
     152,   153,   154,   182,    91,   152,    87,   164,   143,   185,
       1,    57,    58,    59,    61,    62,    63,    64,    65,    66,
      67,    68,    80,    81,    82,    84,   141,   143,   166,   183,
     184,   185,   187,   188,   189,   190,   191,   192,   193,   194,
     199,   200,   201,   208,   209,   210,   211,    86,    86,    90,
      91,    92,   139,   177,   178,   179,   180,   181,   107,    85,
      88,   158,    86,    86,    86,    86,    88,    88,    93,    86,
     144,   197,   139,    86,   144,   169,   170,   171,   174,    34,
      93,    95,   139,   168,   175,   176,    87,    92,   119,   127,
     141,    86,    88,    93,    89,    86,   161,   167,   176,   146,
     177,   176,    34,    93,    95,   139,   168,   176,    85,    85,
     153,    84,    89,   155,   156,   164,     1,   152,    85,   125,
     138,   215,   216,    84,   142,    89,    87,    87,    87,    30,
     183,   166,    84,    84,    84,   141,    87,    87,    87,    84,
      89,    85,   188,    87,   166,   178,   142,    85,    88,   177,
     107,   181,   142,    85,   159,    85,    88,    58,   116,   117,
     173,     6,   197,   164,    87,   164,   167,   174,    86,    88,
     176,    86,   139,   168,    93,    93,    34,    93,   139,   176,
      34,    93,    95,   139,   168,    85,   124,   138,     1,     3,
      86,   169,   172,   139,   168,    93,    93,    34,    93,    95,
     139,   176,   142,    84,    88,    89,    85,    85,   140,    84,
      86,    88,    89,   183,   111,   111,   141,    62,    84,    84,
      83,    86,   139,   202,   203,   204,   205,    86,   141,     4,
      86,   183,   141,   143,   144,   189,    85,    88,    93,    85,
     177,   179,    85,    89,    86,    88,    89,    86,    30,    56,
     171,    93,   139,   139,    93,    86,   169,   139,   168,    93,
      93,    34,    93,   139,    86,    86,    86,    88,    93,   139,
     139,    93,    93,   176,   156,   142,   119,   138,   216,   183,
     216,   183,    86,    86,    86,    87,    87,   183,    86,    88,
     205,   183,    86,    86,   183,    77,   189,   164,   189,    85,
     177,   139,   117,   139,    84,   176,    93,    93,    86,    93,
     139,   139,    93,     3,    93,    93,   183,   183,   183,   141,
      96,   166,   206,   183,   203,   183,   183,   141,   212,   213,
      86,   141,    77,    86,   141,    93,    93,    60,    86,    89,
      86,   183,    86,   212,   183,    86,   183,    84,   166,   207,
     183,   183,    86,   183,    92,    86,   183,    89,   141,    93
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   112,   113,   114,   114,
     115,   116,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     123,   123,   123,   124,   124,   125,   125,   125,   125,   125,
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
     170,   171,   171,   171,   172,   172,   173,   173,   174,   174,
     174,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   176,   177,   177,   177,   178,   178,   178,   178,
     179,   180,   180,   181,   181,   182,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   185,   186,   185,
     187,   187,   188,   188,   189,   189,   190,   190,   190,   191,
     192,   192,   192,   192,   192,   193,   193,   194,   194,   194,
     194,   194,   195,   195,   195,   195,   195,   195,   195,   195,
     196,   197,   197,   198,   198,   199,   199,   199,   199,   199,
     199,   200,   201,   201,   202,   202,   203,   203,   204,   204,
     205,   206,   206,   207,   207,   208,   208,   209,   209,   210,
     211,   212,   212,   213,   214,   215,   215,   215,   216,   216,
     216,   217,   218,   218,   219,   220
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       2,     2,     4,     3,     4,     3,     4,     3,     4,     1,
       1,     3,     2,     1,     1,     1,     2,     2,     2,     2,
       4,     4,     1,     4,     1,     1,     1,     1,     1,     1,
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
       4,     2,     2,     1,     1,     3,     3,     2,     2,     1,
       1,     3,     2,     3,     5,     4,     5,     4,     3,     3,
       3,     4,     6,     5,     5,     6,     4,     4,     2,     3,
       4,     5,     0,     3,     4,     1,     2,     1,     4,     3,
       2,     1,     2,     3,     2,     7,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     3,     2,     0,     4,
       1,     2,     1,     1,     1,     2,     7,     5,     5,     1,
       5,     7,     6,     7,     1,     6,     7,     3,     2,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     4,     5,     1,     3,     1,     1,     1,     2,
       6,     1,     1,     1,     5,     4,     5,     4,     5,     8,
       7,     1,     1,     3,     6,     1,     3,     3,     1,     3,
       3,     2,     4,     5,     4,     1
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
  YY_USE (yykind);
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
#line 84 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2408 "basilisk.c"
    break;

  case 5: /* translation_unit: translation_unit error '}'  */
#line 85 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2414 "basilisk.c"
    break;

  case 6: /* translation_unit: translation_unit error ')'  */
#line 86 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2420 "basilisk.c"
    break;

  case 13: /* expression_error: error  */
#line 99 "basilisk.yacc"
                        { yyvsp[0]->sym = YYSYMBOL_YYerror; }
#line 2426 "basilisk.c"
    break;

  case 111: /* declaration: declaration_specifiers ';' type_not_specified  */
#line 295 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 2432 "basilisk.c"
    break;

  case 112: /* declaration: declaration_specifiers init_declarator_list ';' type_not_specified  */
#line 296 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 2438 "basilisk.c"
    break;

  case 135: /* type_specifier: types  */
#line 334 "basilisk.yacc"
                   { parse->type_already_specified = true; }
#line 2444 "basilisk.c"
    break;

  case 155: /* struct_or_union_specifier: struct_or_union '{' error '}'  */
#line 360 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2450 "basilisk.c"
    break;

  case 156: /* struct_or_union_specifier: struct_or_union generic_identifier '{' error '}'  */
#line 361 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2456 "basilisk.c"
    break;

  case 206: /* direct_declarator: direct_declarator '(' type_not_specified error ')'  */
#line 456 "basilisk.yacc"
                                                                                           { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2462 "basilisk.c"
    break;

  case 252: /* type_not_specified: %empty  */
#line 535 "basilisk.yacc"
           { parse->type_already_specified = false; }
#line 2468 "basilisk.c"
    break;

  case 273: /* statement: error ';'  */
#line 577 "basilisk.yacc"
                     { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2474 "basilisk.c"
    break;

  case 278: /* @1: %empty  */
#line 589 "basilisk.yacc"
                           { stack_push (parse->stack, &(yyvsp[0])); yyval->sym = YYSYMBOL_YYUNDEF; }
#line 2480 "basilisk.c"
    break;

  case 279: /* compound_statement: '{' @1 block_item_list '}'  */
#line 591 "basilisk.yacc"
                           { ast_pop_scope (parse->stack, yyvsp[-3]); }
#line 2486 "basilisk.c"
    break;

  case 289: /* for_scope: FOR  */
#line 616 "basilisk.yacc"
              { stack_push (parse->stack, &(yyval)); }
#line 2492 "basilisk.c"
    break;

  case 292: /* iteration_statement: for_scope '(' expression_statement expression_statement ')' statement  */
#line 623 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2498 "basilisk.c"
    break;

  case 293: /* iteration_statement: for_scope '(' expression_statement expression_statement expression ')' statement  */
#line 625 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2504 "basilisk.c"
    break;

  case 295: /* for_declaration_statement: for_scope '(' declaration expression_statement ')' statement  */
#line 631 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2510 "basilisk.c"
    break;

  case 296: /* for_declaration_statement: for_scope '(' declaration expression_statement expression ')' statement  */
#line 633 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2516 "basilisk.c"
    break;

  case 309: /* external_declaration: error compound_statement  */
#line 652 "basilisk.yacc"
                                                { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2522 "basilisk.c"
    break;

  case 310: /* function_declaration: declaration_specifiers declarator  */
#line 656 "basilisk.yacc"
                                            { ast_push_function_definition (parse->stack, yyvsp[0]);  }
#line 2528 "basilisk.c"
    break;

  case 311: /* function_definition: function_declaration declaration_list compound_statement  */
#line 661 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-2]->child[1]); }
#line 2534 "basilisk.c"
    break;

  case 312: /* function_definition: function_declaration compound_statement  */
#line 663 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-1]->child[1]); }
#line 2540 "basilisk.c"
    break;

  case 339: /* forin_declaration_statement: for_scope '(' declaration_specifiers declarator IN forin_arguments ')' statement  */
#line 733 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-7]); }
#line 2546 "basilisk.c"
    break;

  case 340: /* forin_statement: for_scope '(' expression IN forin_arguments ')' statement  */
#line 738 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2552 "basilisk.c"
    break;

  case 355: /* root: translation_unit  */
#line 780 "basilisk.yacc"
                           {
	  yyval = root;
	  yyval->sym = yyr1[yyn];
	  yyval->child = allocate ((Allocator *)parse->alloc, 2*sizeof(Ast *));
	  yyval->child[0] = yyvsp[0];
	  yyvsp[0]->parent = yyval;
	  yyval->child[1] = NULL;
        }
#line 2565 "basilisk.c"
    break;


#line 2569 "basilisk.c"

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

#line 790 "basilisk.yacc"


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
      if (t->after != NULL) {
	fprintf (stderr, "%s:%d: %s after: %s\n",
		 t->file, t->line, t->start, t->after);
	abort();
      }
      t->after = t->start + strlen (t->start) - 1;
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
