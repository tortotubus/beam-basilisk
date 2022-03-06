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
  YYSYMBOL_94_ = 94,                       /* '='  */
  YYSYMBOL_95_ = 95,                       /* '&'  */
  YYSYMBOL_96_ = 96,                       /* '*'  */
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
  YYSYMBOL_foreach_inner_statement = 207,  /* foreach_inner_statement  */
  YYSYMBOL_foreach_dimension_statement = 208, /* foreach_dimension_statement  */
  YYSYMBOL_forin_declaration_statement = 209, /* forin_declaration_statement  */
  YYSYMBOL_forin_statement = 210,          /* forin_statement  */
  YYSYMBOL_forin_arguments = 211,          /* forin_arguments  */
  YYSYMBOL_field_list = 212,               /* field_list  */
  YYSYMBOL_event_definition = 213,         /* event_definition  */
  YYSYMBOL_event_parameters = 214,         /* event_parameters  */
  YYSYMBOL_event_parameter = 215,          /* event_parameter  */
  YYSYMBOL_boundary_definition = 216,      /* boundary_definition  */
  YYSYMBOL_external_foreach_dimension = 217, /* external_foreach_dimension  */
  YYSYMBOL_attribute = 218,                /* attribute  */
  YYSYMBOL_root = 219                      /* root  */
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
#define YYFINAL  190
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3527

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  347
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  625

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
       2,     2,     2,   100,     2,     2,     2,   102,    95,     2,
      87,    86,    96,    97,    88,    98,    90,   101,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    89,    84,
     103,    94,   104,   107,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    92,     2,    93,   105,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,   106,    85,    99,     2,     2,     2,
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
       0,    81,    81,    82,    83,    84,    85,    89,    90,    91,
      92,    93,    97,    98,   102,   103,   104,   108,   112,   113,
     117,   121,   122,   126,   127,   131,   132,   133,   134,   135,
     136,   137,   138,   142,   143,   147,   148,   152,   153,   157,
     161,   162,   166,   167,   168,   172,   173,   174,   175,   176,
     177,   178,   179,   183,   184,   185,   186,   187,   188,   192,
     193,   199,   200,   201,   202,   206,   207,   208,   212,   213,
     214,   218,   219,   220,   221,   222,   226,   227,   228,   232,
     233,   237,   238,   242,   243,   247,   248,   252,   253,   257,
     258,   262,   263,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   281,   282,   286,   290,   291,   292,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     309,   310,   314,   315,   319,   320,   321,   322,   323,   324,
     325,   329,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   352,   353,
     354,   355,   356,   360,   361,   365,   366,   370,   371,   372,
     376,   377,   378,   379,   383,   384,   388,   389,   390,   394,
     395,   396,   397,   398,   402,   403,   407,   408,   412,   416,
     417,   418,   419,   420,   424,   425,   429,   430,   434,   435,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   457,   458,   462,   463,   464,
     465,   469,   470,   474,   475,   479,   480,   484,   485,   486,
     490,   491,   495,   496,   500,   501,   502,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   530,   534,
     535,   536,   540,   541,   542,   543,   547,   551,   552,   556,
     557,   561,   565,   566,   567,   568,   569,   570,   571,   572,
     576,   577,   578,   582,   584,   584,   590,   591,   595,   596,
     600,   601,   605,   606,   607,   611,   615,   616,   617,   619,
     621,   625,   627,   632,   633,   634,   635,   636,   640,   641,
     642,   643,   644,   645,   646,   650,   654,   656,   661,   662,
     669,   670,   671,   672,   673,   674,   678,   682,   683,   687,
     688,   692,   693,   697,   698,   702,   706,   707,   711,   712,
     716,   717,   721,   726,   731,   732,   736,   740,   744,   745,
     746,   750,   751,   755,   759,   760,   764,   768
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
  "'['", "']'", "'='", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "$accept", "translation_unit",
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
  "reduction_list", "reduction", "reduction_operator",
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
      46,   123,    91,    93,    61,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63
};
#endif

#define YYPACT_NINF (-542)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-348)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     992,   -66,   147,  -542,  -542,  -542,  -542,  2610,  2624,  2624,
      -9,  -542,  -542,  -542,  -542,  -542,  -542,  -542,  -542,  -542,
    -542,  -542,  -542,  -542,  -542,  -542,  -542,  -542,  -542,  -542,
    -542,  -542,  -542,  -542,  -542,    23,   -56,   -37,   -25,    11,
    -542,    56,  -542,  -542,  -542,  -542,    66,  1092,  -542,  -542,
    -542,  -542,  -542,  -542,   690,  -542,  -542,  -542,  -542,   298,
    -542,  -542,   623,  2722,  -542,   100,   278,   283,    41,   370,
      79,   -35,    91,   208,    20,  -542,   148,  -542,    46,  3331,
    3331,  -542,  -542,    69,  -542,  -542,  3331,  3331,  3331,   154,
    -542,  -542,  3023,  -542,  -542,  -542,  -542,  -542,   239,   175,
    -542,  -542,  1092,  -542,  1092,  -542,  -542,  -542,  -542,   273,
     201,  1368,  3451,  3451,  2722,  2722,    77,  -542,  -542,   182,
    -542,   216,  3451,   103,  3451,   228,   242,  -542,    18,  -542,
    -542,  1908,    18,  2038,  -542,  -542,  -542,  -542,  -542,  -542,
    -542,  -542,  -542,  -542,  -542,  2722,  -542,  -542,  2722,  2722,
    2722,  2722,  2722,  2722,  2722,  2722,  2722,  2722,  2722,  2722,
    2722,  2722,  2722,  2722,  2722,  2722,  2722,  -542,  -542,   153,
     341,    71,  -542,   -50,   -47,  -542,   178,  -542,  -542,  2717,
     231,  -542,  -542,  -542,  3373,   251,  -542,    46,  -542,  3023,
    -542,  -542,   892,   259,   274,  -542,   256,   121,  -542,   273,
    -542,   282,   287,   291,   297,   268,   301,   308,  3331,  -542,
    2722,  -542,  2958,  1422,   -40,  -542,   -18,  -542,  -542,  2052,
    -542,  -542,  -542,  -542,  -542,   302,  -542,  2722,   158,  -542,
    -542,  -542,  -542,  -542,   -51,  -542,  -542,  -542,  -542,   100,
     100,   278,   278,   283,   283,   283,   283,    41,    41,   370,
      79,   -35,    91,   208,   304,  -542,   316,  -542,  -542,  -542,
     341,  -542,   153,  2083,  -542,  1468,  -542,   -47,   319,  3133,
    -542,    33,  -542,  2913,  3181,  2161,   315,  -542,  -542,   327,
    2722,   324,   334,   336,   337,  1147,  -542,    18,   343,   347,
    2192,   345,   348,   351,  -542,   -66,   101,  -542,   350,  -542,
    -542,  -542,   792,  -542,  -542,  -542,   355,  -542,  -542,  -542,
    -542,  -542,  -542,  -542,  -542,  -542,  -542,   352,   352,  2722,
    -542,    88,   192,  -542,  -542,  -542,  -542,  3412,   428,  3331,
     153,  -542,  -542,  -542,    83,   362,   363,  -542,   364,  1716,
    -542,   359,   361,  1520,   -18,  -542,  -542,  1566,  1892,  -542,
    -542,  2083,   196,  -542,  2290,  -542,  2722,  -542,  -542,  -542,
    -542,  -542,  1892,  -542,  -542,  2858,  1716,  -542,   365,   367,
    1618,  -542,  -542,  -542,  -542,  -542,  2722,   139,  -542,   366,
     371,  3229,  -542,  -542,   368,   205,  -542,  -542,   372,  1147,
    1192,  1192,  2722,   402,   381,  -542,  -542,  -542,   186,  1940,
    2306,   144,  -542,  -542,  1147,  -542,  -542,  1270,  -542,  -542,
    -542,  -542,   169,   378,   165,  -542,   379,   384,  -542,  -542,
    2793,  -542,   163,  -542,  -542,  3283,  -542,  -542,   380,  1716,
    -542,  -542,  2722,  -542,   382,  3083,  1716,  -542,   386,   388,
    1664,    18,  2722,  -542,   198,  2083,   207,  -542,  -542,  -542,
    -542,  -542,   227,   396,  -542,  -542,   397,   217,   391,  1716,
    -542,  -542,  2722,  -542,   392,   393,  -542,  -542,  -542,   177,
    2722,  -542,  -542,  2083,  2161,  1147,  2161,  1147,  -542,   403,
     404,   243,   401,  -542,  -542,   405,  1147,  -542,   249,  -542,
     408,  -542,  1147,   253,   407,  1147,  -542,   -55,  2338,    46,
    2338,  -542,  2722,  -542,  3412,  2722,   410,  -542,  -542,  -542,
     409,   411,  -542,  -542,   414,   412,  1716,  -542,  -542,  2722,
    -542,   415,  -542,   417,  -542,  1762,  -542,  -542,  -542,  -542,
    1794,  -542,  -542,  -542,   492,  -542,   418,   419,  -542,  -542,
    -542,  -542,  -542,  -542,  -542,  -542,  -542,  -542,  1147,  1147,
    1147,  2722,    13,  -542,  1147,  2436,  -542,  -542,  1147,  1147,
    -542,  2450,  2481,   -53,  2579,  -542,  -542,  -542,  -542,  -542,
    -542,  -542,  -542,  -542,   421,   422,  -542,  -542,  -542,  -542,
    2083,  -542,  -542,  -542,  -542,   437,  -542,  -542,   260,  -542,
    -542,   429,  -542,  -542,  -542,  -542,   216,   431,  -542,  1147,
     271,  2450,  1147,   281,  -542,  -542,  -542,  1147,   435,    18,
    1147,  -542,  1147,   439,  -542,  1147,  -542,  -542,   440,  -542,
    -542,  1147,  -542,  -542,  -542
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     7,    14,    15,    18,    19,     0,     0,     0,
     147,    16,   124,   125,   126,   128,   129,   184,   179,   180,
     181,   141,   133,   134,   135,   136,   139,   140,   137,   138,
     132,   142,   143,   153,   154,     0,     0,     0,   182,     0,
     185,     0,   127,   183,    52,   130,     0,     0,    53,    54,
      55,    56,    57,    58,     0,    25,     8,     9,    11,    45,
      27,    26,    59,     0,    61,    65,    68,    71,    76,    79,
      81,    83,    85,    87,    89,    91,     0,   299,     0,   111,
     113,   131,   145,     0,   146,   144,   115,   117,   119,     0,
     109,     2,     0,   298,   300,   301,   302,   303,     0,   274,
     304,     7,     0,    49,     0,    46,    47,   205,   206,     0,
     173,     0,     0,     0,     0,     0,     0,    13,   147,     0,
     104,    12,   161,   248,   163,     0,     0,     3,     0,    30,
      31,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    93,     0,    59,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   343,   248,     0,
     210,     0,   120,   305,   248,   190,     0,   110,   112,     0,
     150,   114,   116,   118,     0,     0,   308,     0,   307,     0,
       1,   273,     0,     0,     0,    17,   177,     0,   174,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,   160,     0,     0,   225,   248,   226,   223,   162,     0,
       4,     5,     6,    29,    39,     7,    37,     0,     0,    40,
      42,    44,    28,    35,     0,    92,    62,    63,    64,    66,
      67,    69,    70,    74,    75,    72,    73,    77,    78,    80,
      82,    84,    86,    88,     0,   107,     0,   182,   211,   209,
     208,   248,     0,     0,   248,     0,   189,   248,     0,     0,
     155,     0,   159,     0,     0,     0,   123,   309,   306,     0,
       0,     0,     0,     0,     0,     0,   285,     0,     0,     0,
       0,     0,     0,     0,   280,    26,     0,   278,     0,   279,
     262,   263,     0,   276,   264,   265,     0,   266,   290,   267,
     268,   310,   311,   312,   313,   314,   315,    50,     0,     0,
     169,     0,     0,   187,   186,    51,   178,     0,     0,     0,
       0,   344,   105,   244,   219,     0,   214,   248,     0,     0,
     228,    54,     0,     0,   224,   222,   248,     0,     0,    32,
      60,     0,     0,    38,     0,    36,     0,   191,   212,   207,
     108,   121,     0,   251,   122,     0,     0,   192,    54,     0,
       0,   188,   151,   148,   156,   248,     0,     0,   164,   168,
       0,     0,   346,   341,     0,     0,   338,   269,     0,     0,
       0,     0,     0,     0,     0,   294,   295,   296,     0,     0,
       0,     0,   316,   281,     0,   275,   277,     0,   176,   170,
     175,   171,     0,     0,     0,    21,     0,     0,   345,   305,
       0,   217,   225,   218,   245,     0,   215,   227,     0,     0,
     229,   235,     0,   234,     0,     0,     0,   236,    54,     0,
       0,     0,     0,   253,     0,     0,     0,   257,    43,   336,
      41,    90,     0,     0,   220,   203,     0,     0,     0,     0,
     193,   200,     0,   199,    54,     0,   157,   166,   248,     0,
       0,   152,   149,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,   293,   297,     0,     0,   321,     0,   319,
     322,   323,     0,     0,     0,     0,   270,     0,     0,     0,
       0,   172,     0,    20,     0,     0,     0,   213,   248,   231,
       0,     0,   233,   246,     0,     0,     0,   237,   243,     0,
     242,     0,   260,     0,    33,     0,   252,   256,   258,   249,
       0,   202,   201,   204,     0,   195,     0,     0,   196,   198,
     158,   165,   167,   342,   340,   337,   339,   271,     0,     0,
       0,     0,     0,   317,     0,     0,   324,   328,     0,     0,
     330,     0,     0,   123,     0,    24,    22,    23,   261,   216,
     230,   232,   247,   239,     0,     0,   240,   259,    34,   255,
       0,   250,   221,   194,   197,   283,   284,   286,     0,   327,
     326,     0,   318,   320,   329,   331,   334,     0,   335,     0,
       0,     0,     0,     0,   238,   241,   254,     0,     0,     0,
       0,   291,     0,     0,   288,     0,   282,   287,     0,   333,
     292,     0,   289,   325,   332
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -542,  -542,  -542,    10,  -542,  -542,  -542,  -542,  -542,    -1,
    -542,  -542,  -542,    21,   389,  -542,   170,   438,  -542,   -48,
     264,   265,   162,   270,   369,   374,   375,   373,   376,  -542,
     -98,     4,  -542,   -29,   -88,   -83,   124,  -542,   266,  -542,
     -17,  -542,  -542,  -542,  -165,  -266,   -32,  -542,    58,  -542,
     340,  -289,  -542,   -45,  -542,  -542,   -71,  -175,     0,  -109,
    -201,  -281,  -542,   115,  -542,   295,  -112,  -204,  -103,  -240,
     180,  -437,  -542,    98,  -133,    68,  -542,     5,  -542,  -542,
     244,  -379,  -542,  -542,  -542,  -542,  -542,   493,  -542,  -203,
    -542,  -542,  -542,  -542,  -542,    -7,  -542,    60,  -542,  -542,
    -542,  -542,  -542,   -46,  -541,  -542,  -542,  -288,  -542,  -542,
    -542,  -542
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    54,    55,   119,    56,   196,    57,    58,   414,   415,
      59,   349,    60,    61,   223,   228,   229,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   120,   145,   296,   201,    77,   334,   171,   172,    79,
      80,    81,    82,    83,   269,   270,   123,   377,   378,    84,
     197,   198,    85,    86,    87,    88,   256,   174,   298,   176,
     260,   335,   336,   337,   457,   416,   338,   216,   217,   443,
     444,   445,   446,   447,    90,   299,   300,   301,   192,   302,
     303,   304,   305,   306,   307,   308,   309,    91,    92,    93,
     189,   310,   311,   312,   488,   489,   490,   491,   591,   313,
     314,   315,   316,   597,   231,    94,   385,   386,    95,    96,
      97,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,   267,   124,   374,    76,   331,   100,   173,   374,   186,
     344,   215,   343,   200,   214,   147,   107,   200,   121,   274,
     598,   107,   561,   364,   601,    99,   107,   206,   500,   403,
     122,   111,   410,   210,  -123,   110,   107,   210,  -123,   165,
     264,   263,   355,   108,   263,   265,   272,   212,   108,   107,
     112,   272,   213,   108,    89,   155,   156,   124,    76,   124,
     598,   259,   113,   108,   370,   255,   124,   124,   124,   346,
     162,   266,   107,   121,   347,   121,   108,   124,   175,   124,
    -206,   207,  -206,   180,   456,   122,   107,   122,   580,   185,
     211,   195,   218,   580,   122,   122,   122,   188,   114,   108,
     236,   237,   238,   214,   234,   122,   277,   122,   381,   297,
     589,   448,   345,   108,   109,   374,   276,   375,   205,   562,
     169,   564,   376,   410,    78,   258,   418,   166,   224,   170,
     168,   100,   224,   169,   124,   230,   272,   254,   429,   124,
     272,   272,   170,   115,   157,   158,   440,   271,   494,   235,
    -205,   359,   271,   116,   514,   261,   107,   107,   360,   262,
     179,   365,   122,   208,   371,   459,   107,   122,   258,   175,
     420,   350,   195,   409,   161,   213,   175,  -205,    78,   170,
     107,   107,   200,   108,   108,   403,   544,   175,   546,   210,
     212,   276,   388,   108,   278,   213,   148,   163,   352,   170,
     379,   149,   150,   177,   178,   526,   320,   108,   108,   321,
     181,   182,   183,   295,   332,   358,   187,   342,   344,   297,
     258,   200,   423,   468,   124,   422,   164,   469,   124,   124,
     495,   408,   167,   543,   426,   516,  -205,   271,  -205,   190,
     169,   271,   271,   435,   353,   184,   354,   267,   272,   170,
     420,   503,   122,   504,   501,   213,   122,   122,   451,   419,
     191,   398,   175,   421,   169,   169,   376,   363,   209,   369,
     484,   175,   466,   170,   210,   384,   195,   411,   200,   383,
     412,   449,   124,   524,   210,   579,   525,   394,   467,   474,
     579,   475,   199,   476,   258,   153,   154,   441,   358,   442,
     402,   527,   258,   533,   210,   534,   295,   128,   129,   130,
     122,   422,   529,   187,   219,   530,   187,   243,   244,   245,
     246,   258,   273,   295,   498,   358,   220,   221,   222,   550,
     175,   210,   330,    99,   175,   554,   124,   555,   275,   558,
     606,   210,   125,   428,   200,   317,   608,   434,   210,   271,
     319,   439,   363,   393,   523,   363,   327,   612,   230,   210,
     318,   121,   121,   481,   122,   540,   363,   615,   323,   210,
     458,   493,   200,   324,   465,   151,   152,   325,   497,    18,
      19,    20,   542,   326,   358,   131,   159,   160,   132,   328,
     133,   258,   210,   356,   329,   358,   351,   193,   379,   194,
     479,   480,   357,   487,   372,   569,   202,   203,   204,   263,
     295,   387,   257,   389,   358,   239,   240,    43,   241,   242,
     175,   390,   175,   391,   392,   295,   187,   395,   563,   247,
     248,   396,   399,   510,   417,   400,   511,   170,   401,   404,
     515,   522,   407,   348,   521,   103,   105,   106,   424,   363,
     427,   425,   430,   330,   431,   470,   471,   478,   460,   124,
     461,   477,   473,   536,   482,   483,   537,   502,   505,   175,
     506,   358,   496,   509,   384,   512,   384,   363,   383,   517,
     383,   518,   531,   532,   535,   538,   539,   122,   551,   548,
     549,   485,   552,   559,   568,   582,   295,   607,   295,   175,
     572,   146,   570,   566,   571,   573,   565,   295,   576,   567,
     577,   583,   584,   295,   604,   605,   295,   610,   609,   617,
     574,   232,   588,   575,   450,   621,   623,   541,   361,   363,
     249,   499,   596,   600,   363,   603,   250,   252,   251,   322,
     508,   253,   452,   545,   528,   547,   406,   127,   593,   146,
     556,     0,   590,   146,   553,   613,     0,     0,     0,   487,
     557,     0,     0,   560,     0,     0,     0,     0,     0,   295,
     295,   295,   596,     0,     0,   295,     0,     0,     0,   295,
     295,     0,     0,     0,   363,     0,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,     0,     0,     0,     0,     0,   618,
       0,     0,     0,     0,     0,     0,   585,   586,   587,     0,
     295,     0,   592,   295,     0,     0,   594,   595,   295,     0,
       0,   295,     0,   295,     0,     0,   295,     0,     0,     0,
       0,     0,   295,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,     0,     0,     0,     0,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   611,     0,     0,
     614,     0,     0,     0,     0,   616,     0,     0,   619,     0,
     620,     0,     0,   622,     0,     0,     0,     0,     0,   624,
    -347,   126,     0,     2,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144,   146,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   146,     0,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
       0,     0,    46,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,     0,     0,   279,   146,     2,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,   280,
     281,   282,     0,   283,   284,   285,   286,   287,   288,   289,
     290,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,   291,   292,   293,     0,   294,   405,     0,    47,
     146,     0,     0,    99,     0,     0,     0,    48,    49,    50,
      51,    52,    53,   279,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,   280,
     281,   282,     0,   283,   284,   285,   286,   287,   288,   289,
     290,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,   291,   292,   293,     0,   294,     0,     0,    47,
       0,     0,     0,    99,     0,     0,     0,    48,    49,    50,
      51,    52,    53,     1,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,     0,     0,    46,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,   117,     0,   101,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,    11,     0,     0,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   279,     0,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,    37,    38,    39,     0,     0,     0,    43,     0,
      44,     0,     0,     0,     0,     0,     0,   108,    11,    47,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,   117,     0,   101,     3,     4,     5,     6,
       7,     0,     8,     9,   280,   281,   282,     0,   283,   284,
     285,   286,   287,   288,   289,   290,     0,    37,     0,    39,
       0,     0,     0,    11,     0,    44,     0,   291,   292,   293,
       0,   294,     0,     0,    47,     0,     0,     0,    99,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,     0,     0,
      44,     0,     0,   101,     3,     4,     5,     6,     7,    47,
       8,     9,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,     0,
     118,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
       0,     0,     0,     0,   294,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,    11,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,   101,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,    37,    38,
      39,     0,     0,     0,    43,     0,    44,     0,     0,     0,
       0,     0,     0,    11,     0,    47,   339,     0,     0,     0,
      18,    19,    20,    48,    49,    50,    51,    52,    53,     0,
       0,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,   257,    39,     0,     0,     0,    43,    11,
      44,     0,   366,     0,     0,     0,    18,    19,    20,    47,
       0,     0,     0,     0,     0,   340,     0,    48,   341,    50,
      51,    52,    53,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,    37,   257,
      39,     0,     0,     0,    43,     0,    44,     0,     0,     0,
       0,    11,     0,     0,   432,    47,     0,     0,    18,    19,
      20,   367,     0,    48,   368,    50,    51,    52,    53,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,   257,    39,     0,     0,     0,    43,    11,    44,     0,
     436,     0,     0,     0,    18,    19,    20,    47,     0,     0,
       0,     0,     0,   433,     0,    48,    49,    50,    51,    52,
      53,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    37,   257,    39,     0,
       0,     0,    43,     0,    44,     0,     0,     0,     0,    11,
       0,     0,   462,    47,     0,     0,    18,    19,    20,   437,
       0,    48,   438,    50,    51,    52,    53,   101,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,   257,
      39,     0,     0,     0,    43,    11,    44,     0,   519,     0,
       0,     0,    18,    19,    20,    47,     0,     0,     0,     0,
       0,   463,     0,    48,   464,    50,    51,    52,    53,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,    37,   257,    39,     0,     0,     0,
      43,     0,    44,     0,     0,     0,     0,    11,     0,     0,
       0,    47,     0,     0,    18,    19,    20,   520,     0,    48,
      49,    50,    51,    52,    53,   101,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,   257,    39,     0,
       0,     0,    43,    11,    44,     0,     0,   101,     3,     4,
       5,     6,     7,    47,     8,     9,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,     0,   578,     0,    47,
       0,     0,   441,   362,   442,     0,     0,    48,    49,    50,
      51,    52,    53,     0,    37,     0,    39,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,   581,
       0,    47,     0,     0,   441,   362,   442,     0,     0,    48,
      49,    50,    51,    52,    53,   101,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,   225,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,     0,     0,
      44,    11,     0,     0,     0,     0,     0,     0,    37,    47,
      39,     0,   441,   362,   442,     0,    44,    48,    49,    50,
      51,    52,    53,     0,   226,    47,     0,     0,     0,   227,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     0,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,   485,     0,     0,   486,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,   101,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,   101,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,    11,     0,    44,     0,     0,     0,
       0,     0,    37,     0,    39,    47,     0,     0,     0,     0,
      44,   233,     0,    48,    49,    50,    51,    52,    53,    47,
       0,     0,     0,   348,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    37,     0,    39,     0,     0,     0,     0,
       0,    44,     0,     0,     2,     3,     4,     5,     6,     7,
      47,     8,     9,     0,   362,     0,     0,     0,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,   108,    11,     0,     0,   101,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    37,     0,    39,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,   397,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,   225,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    39,     0,     0,     0,     0,     0,    44,    11,
       0,     0,     0,     0,     0,     0,    37,    47,    39,     0,
       0,   227,     0,     0,    44,    48,    49,    50,    51,    52,
      53,     0,   492,    47,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,     0,    37,     0,
      39,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,   294,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,   101,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,    11,     0,    44,     0,     0,     0,     0,   485,
      37,     0,    39,    47,     0,     0,     0,     0,    44,     0,
       0,    48,    49,    50,    51,    52,    53,    47,     0,     0,
       0,   227,     0,     0,     0,    48,    49,    50,    51,    52,
      53,    37,     0,    39,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,     0,   599,    47,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,   101,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,   101,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,    11,     0,    44,     0,     0,
       0,     0,     0,     0,     0,   602,    47,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,    53,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,    37,     0,    39,   102,     0,     0,
       0,     0,    44,     0,     0,    48,    49,    50,    51,    52,
      53,   104,     0,     0,     0,     0,     0,     0,   268,    48,
      49,    50,    51,    52,    53,   101,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,     0,     0,
       0,     0,     0,    11,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    41,    37,    43,    39,     0,   107,     0,     0,     0,
      44,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    10,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   453,
       0,   454,    36,     0,    38,     0,    40,     0,    42,    43,
       0,     0,    45,     0,     0,     0,     0,     0,     0,   333,
     420,     0,     0,     0,     0,   213,     0,     0,   118,   170,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   380,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    38,
       0,    40,     0,    42,    43,     0,     0,    45,     0,     0,
       0,     0,     0,   118,   455,     0,     0,     0,     0,     0,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    41,   118,    43,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    38,
       0,    40,     0,    42,    43,     0,     0,    45,     0,     0,
       0,     0,     0,     0,   333,   212,     0,     0,     0,     0,
     213,     0,     0,   118,   170,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,     0,    38,     0,    40,    41,    42,    43,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   118,    99,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,     0,    38,     0,    40,     0,    42,    43,
       0,     0,    45,   118,     0,     0,     0,     0,     0,   513,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    41,     0,    43,
       0,   118,     0,     0,     0,     0,     0,     0,   373,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,    41,     0,    43,     0,   118,
       0,     0,     0,     0,     0,     0,   382,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,    41,     0,    43,     0,     0,     0,     0,
       0,     0,     0,   118,   472,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,   507,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,     0,    38,     0,    40,     0,    42,    43,
       0,   118,    45,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,    38,   118,    40,     0,    42,    43,     0,     0,
      45,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,     0,    38,     0,     0,    41,     0,    43,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
     413,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,     0,    38,     0,     0,     0,     0,    43,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
       0,   176,    47,   269,     0,   208,     1,    78,   274,    92,
     214,   123,   213,   111,   123,    63,     3,   115,    47,   184,
     561,     3,    77,   263,    77,    91,     3,   115,   407,    84,
      47,    87,   321,    88,    84,    35,     3,    88,    88,    19,
      87,    94,    93,    30,    94,    92,   179,    87,    30,     3,
      87,   184,    92,    30,    54,    14,    15,   102,    54,   104,
     601,   170,    87,    30,   265,   168,   111,   112,   113,    87,
     105,   174,     3,   102,    92,   104,    30,   122,    78,   124,
      89,     4,    91,    83,   365,   102,     3,   104,   525,    89,
     122,     3,   124,   530,   111,   112,   113,    92,    87,    30,
     148,   149,   150,   212,   133,   122,   189,   124,   273,   192,
      97,   351,   215,    30,    91,   381,   187,    84,   114,   498,
      87,   500,    89,   412,     0,   170,   329,   107,   128,    96,
      84,   126,   132,    87,   179,   131,   269,   166,   339,   184,
     273,   274,    96,    87,   103,   104,   347,   179,     4,   145,
       3,   260,   184,    87,   435,    84,     3,     3,   261,    88,
      91,   264,   179,    86,   267,   366,     3,   184,   213,   169,
      87,   219,     3,    85,    95,    92,   176,    30,    54,    96,
       3,     3,   280,    30,    30,    84,   474,   187,   476,    88,
      87,   262,   280,    30,   189,    92,    96,   106,   227,    96,
     271,   101,   102,    79,    80,   445,    85,    30,    30,    88,
      86,    87,    88,   192,   210,   260,    92,   213,   422,   302,
     265,   319,   334,    84,   269,   334,    18,    88,   273,   274,
      86,   319,    84,   473,   337,   436,    89,   269,    91,     0,
      87,   273,   274,   346,    86,    91,    88,   422,   381,    96,
      87,    86,   269,    88,    85,    92,   273,   274,   356,   330,
      85,   290,   262,   334,    87,    87,    89,   263,    86,   265,
      84,   271,   375,    96,    88,   275,     3,    85,   376,   275,
      88,    85,   327,    85,    88,   525,    88,   287,   376,    84,
     530,    86,    91,    88,   339,    12,    13,    90,   343,    92,
     295,    94,   347,    86,    88,    88,   285,     9,    10,    11,
     327,   420,    85,   189,    86,    88,   192,   155,   156,   157,
     158,   366,    91,   302,   407,   370,    84,    85,    86,    86,
     330,    88,   208,    91,   334,    86,   381,    88,    87,    86,
     580,    88,    47,   339,   442,    86,    86,   343,    88,   381,
      94,   347,   348,   285,   442,   351,    88,    86,   354,    88,
      86,   390,   391,   392,   381,   468,   362,    86,    86,    88,
     366,   400,   470,    86,   370,    97,    98,    86,   407,    38,
      39,    40,   470,    86,   429,    87,    16,    17,    90,    88,
      92,   436,    88,    89,    86,   440,    94,   102,   469,   104,
     390,   391,    86,   399,    85,   508,   111,   112,   113,    94,
     389,    84,    71,    89,   459,   151,   152,    76,   153,   154,
     420,    87,   422,    87,    87,   404,   302,    84,   499,   159,
     160,    84,    87,   429,     6,    87,   432,    96,    87,    89,
     436,   441,    87,    91,   440,     7,     8,     9,    86,   445,
      86,    88,    93,   329,    93,    89,    85,   389,    93,   504,
      93,    89,    94,   459,    62,    84,   462,    89,    89,   469,
      86,   516,   404,    93,   474,    93,   476,   473,   474,    93,
     476,    93,    86,    86,    93,    93,    93,   504,    87,    86,
      86,    83,    87,    86,    84,     3,   475,    60,   477,   499,
      86,    63,    93,   504,    93,    93,   502,   486,    93,   505,
      93,    93,    93,   492,    93,    93,   495,    86,    89,    84,
     516,   132,   551,   519,   354,    86,    86,   469,   262,   525,
     161,   407,   561,   562,   530,   564,   162,   164,   163,   199,
     425,   165,   362,   475,   446,   477,   302,    54,   555,   111,
     490,    -1,   552,   115,   486,   601,    -1,    -1,    -1,   555,
     492,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,   548,
     549,   550,   601,    -1,    -1,   554,    -1,    -1,    -1,   558,
     559,    -1,    -1,    -1,   580,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   609,
      -1,    -1,    -1,    -1,    -1,    -1,   548,   549,   550,    -1,
     599,    -1,   554,   602,    -1,    -1,   558,   559,   607,    -1,
      -1,   610,    -1,   612,    -1,    -1,   615,    -1,    -1,    -1,
      -1,    -1,   621,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,    -1,    -1,
     602,    -1,    -1,    -1,    -1,   607,    -1,    -1,   610,    -1,
     612,    -1,    -1,   615,    -1,    -1,    -1,    -1,    -1,   621,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,   280,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,    -1,    -1,     1,   356,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    -1,    84,    85,    -1,    87,
     442,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,   470,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    -1,    84,    -1,    -1,    87,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    -1,    -1,    82,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    31,    -1,    78,    -1,    80,    81,    82,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,     3,     4,     5,     6,     7,     8,    87,
      10,    11,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    87,    34,    -1,    -1,    -1,
      38,    39,    40,    95,    96,    97,    98,    99,   100,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    31,
      78,    -1,    34,    -1,    -1,    -1,    38,    39,    40,    87,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    95,    96,    97,
      98,    99,   100,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    34,    87,    -1,    -1,    38,    39,
      40,    93,    -1,    95,    96,    97,    98,    99,   100,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    31,    78,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    87,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    95,    96,    97,    98,    99,
     100,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    87,    -1,    -1,    38,    39,    40,    93,
      -1,    95,    96,    97,    98,    99,   100,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    31,    78,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    87,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    95,    96,    97,    98,    99,   100,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    -1,    78,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    87,    -1,    -1,    38,    39,    40,    93,    -1,    95,
      96,    97,    98,    99,   100,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    31,    78,    -1,    -1,     3,     4,     5,
       6,     7,     8,    87,    10,    11,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    87,
      -1,    -1,    90,    91,    92,    -1,    -1,    95,    96,    97,
      98,    99,   100,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    87,    -1,    -1,    90,    91,    92,    -1,    -1,    95,
      96,    97,    98,    99,   100,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    31,    -1,    -1,    -1,    -1,    -1,    -1,    70,    87,
      72,    -1,    90,    91,    92,    -1,    78,    95,    96,    97,
      98,    99,   100,    -1,    86,    87,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    31,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    87,    -1,    -1,    -1,    -1,
      78,    93,    -1,    95,    96,    97,    98,    99,   100,    87,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    70,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,     3,     4,     5,     6,     7,     8,
      87,    10,    11,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    87,    72,    -1,
      -1,    91,    -1,    -1,    78,    95,    96,    97,    98,    99,
     100,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    31,    -1,    78,    -1,    -1,    -1,    -1,    83,
      70,    -1,    72,    87,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    95,    96,    97,    98,    99,   100,    87,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    31,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    87,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    95,    96,    97,    98,    99,
     100,    87,    -1,    -1,    -1,    -1,    -1,    -1,     1,    95,
      96,    97,    98,    99,   100,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    70,    76,    72,    -1,     3,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,    69,    -1,    71,    -1,    73,    -1,    75,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    30,    96,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      -1,    73,    -1,    75,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    30,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    30,    76,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      -1,    73,    -1,    75,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    30,    96,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    -1,    73,    74,    75,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    91,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,
      -1,    -1,    79,    30,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    85,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    85,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,
      -1,    30,    79,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    30,    73,    -1,    75,    76,    -1,    -1,
      79,    38,    39,    40,    41,    42,    43,    44,    45,    46,
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
      73,    74,    75,    76,    78,    79,    82,    87,    95,    96,
      97,    98,    99,   100,   109,   110,   112,   114,   115,   118,
     120,   121,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   143,   144,   147,
     148,   149,   150,   151,   157,   160,   161,   162,   163,   166,
     182,   195,   196,   197,   213,   216,   217,   218,   219,    91,
     185,     3,    87,   125,    87,   125,   125,     3,    30,    91,
     166,    87,    87,    87,    87,    87,    87,     1,    30,   111,
     139,   141,   148,   154,   161,   173,     1,   195,     9,    10,
      11,    87,    90,    92,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    94,   140,   125,   127,    96,   101,
     102,    97,    98,    12,    13,    14,    15,   103,   104,    16,
      17,    95,   105,   106,    18,    19,   107,    84,    84,    87,
      96,   145,   146,   164,   165,   166,   167,   144,   144,    91,
     166,   144,   144,   144,    91,   166,   143,   144,   185,   198,
       0,    85,   186,   173,   173,     3,   113,   158,   159,    91,
     138,   142,   173,   173,   173,   139,   142,     4,    86,    86,
      88,   154,    87,    92,   167,   174,   175,   176,   154,    86,
      84,    85,    86,   122,   166,     3,    86,    91,   123,   124,
     139,   212,   122,    93,   141,   139,   127,   127,   127,   128,
     128,   129,   129,   130,   130,   130,   130,   131,   131,   132,
     133,   134,   135,   136,   141,   176,   164,    71,   161,   167,
     168,    84,    88,    94,    87,    92,   176,   165,     1,   152,
     153,   154,   182,    91,   152,    87,   164,   143,   185,     1,
      57,    58,    59,    61,    62,    63,    64,    65,    66,    67,
      68,    80,    81,    82,    84,   121,   141,   143,   166,   183,
     184,   185,   187,   188,   189,   190,   191,   192,   193,   194,
     199,   200,   201,   207,   208,   209,   210,    86,    86,    94,
      85,    88,   158,    86,    86,    86,    86,    88,    88,    86,
     144,   197,   139,    86,   144,   169,   170,   171,   174,    34,
      93,    96,   139,   168,   175,   176,    87,    92,    91,   119,
     127,    94,   141,    86,    88,    93,    89,    86,   161,   167,
     176,   146,    91,   139,   177,   176,    34,    93,    96,   139,
     168,   176,    85,    85,   153,    84,    89,   155,   156,   164,
       1,   152,    85,   139,   166,   214,   215,    84,   142,    89,
      87,    87,    87,   183,   166,    84,    84,    84,   141,    87,
      87,    87,   185,    84,    89,    85,   188,    87,   142,    85,
     159,    85,    88,    58,   116,   117,   173,     6,   197,   164,
      87,   164,   167,   174,    86,    88,   176,    86,   139,   168,
      93,    93,    34,    93,   139,   176,    34,    93,    96,   139,
     168,    90,    92,   177,   178,   179,   180,   181,   177,    85,
     124,   138,   178,     1,     3,    86,   169,   172,   139,   168,
      93,    93,    34,    93,    96,   139,   176,   142,    84,    88,
      89,    85,    85,    94,    84,    86,    88,    89,   183,   111,
     111,   141,    62,    84,    84,    83,    86,   139,   202,   203,
     204,   205,    86,   141,     4,    86,   183,   141,   143,   144,
     189,    85,    89,    86,    88,    89,    86,    56,   171,    93,
     139,   139,    93,    86,   169,   139,   168,    93,    93,    34,
      93,   139,   166,   142,    85,    88,   177,    94,   181,    85,
      88,    86,    86,    86,    88,    93,   139,   139,    93,    93,
     176,   156,   142,   177,   215,   183,   215,   183,    86,    86,
      86,    87,    87,   183,    86,    88,   205,   183,    86,    86,
     183,    77,   189,   164,   189,   139,   117,   139,    84,   176,
      93,    93,    86,    93,   139,   139,    93,    93,    85,   177,
     179,    85,     3,    93,    93,   183,   183,   183,   141,    97,
     166,   206,   183,   203,   183,   183,   141,   211,   212,    86,
     141,    77,    86,   141,    93,    93,   177,    60,    86,    89,
      86,   183,    86,   211,   183,    86,   183,    84,   166,   183,
     183,    86,   183,    86,   183
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   112,   113,   114,   114,
     115,   116,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     123,   123,   124,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   126,   126,   126,   127,
     127,   128,   128,   128,   128,   129,   129,   129,   130,   130,
     130,   131,   131,   131,   131,   131,   132,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   141,   142,   143,   143,   143,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     145,   145,   146,   146,   147,   147,   147,   147,   147,   147,
     147,   148,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   150,   150,
     150,   150,   150,   151,   151,   152,   152,   153,   153,   153,
     154,   154,   154,   154,   155,   155,   156,   156,   156,   157,
     157,   157,   157,   157,   158,   158,   159,   159,   160,   161,
     161,   161,   161,   161,   162,   162,   163,   163,   164,   164,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   166,   166,   167,   167,   167,
     167,   168,   168,   169,   169,   170,   170,   171,   171,   171,
     172,   172,   173,   173,   174,   174,   174,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   176,   177,
     177,   177,   178,   178,   178,   178,   179,   180,   180,   181,
     181,   182,   183,   183,   183,   183,   183,   183,   183,   183,
     184,   184,   184,   185,   186,   185,   187,   187,   188,   188,
     189,   189,   190,   190,   190,   191,   192,   192,   192,   192,
     192,   193,   193,   194,   194,   194,   194,   194,   195,   195,
     195,   195,   195,   195,   195,   196,   197,   197,   198,   198,
     199,   199,   199,   199,   199,   199,   200,   201,   201,   202,
     202,   203,   203,   204,   204,   205,   206,   206,   207,   207,
     208,   208,   209,   210,   211,   211,   212,   213,   214,   214,
     214,   215,   215,   216,   217,   217,   218,   219
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       2,     2,     4,     3,     4,     3,     4,     3,     4,     1,
       1,     3,     1,     3,     1,     1,     2,     2,     2,     2,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     4,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       2,     4,     5,     1,     1,     1,     2,     3,     4,     1,
       2,     1,     2,     1,     1,     3,     2,     3,     1,     4,
       5,     5,     6,     2,     1,     3,     3,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     2,
       1,     3,     3,     4,     6,     5,     5,     6,     5,     4,
       4,     5,     5,     4,     5,     1,     1,     3,     2,     2,
       1,     1,     2,     3,     1,     2,     4,     2,     2,     1,
       1,     3,     3,     2,     2,     1,     1,     3,     2,     3,
       5,     4,     5,     4,     3,     3,     3,     4,     6,     5,
       5,     6,     4,     4,     2,     3,     4,     5,     0,     3,
       4,     1,     2,     1,     4,     3,     2,     1,     2,     3,
       2,     7,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     4,     3,     2,     0,     4,     1,     2,     1,     1,
       1,     2,     7,     5,     5,     1,     5,     7,     6,     7,
       1,     6,     7,     3,     2,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     4,     5,     1,
       3,     1,     1,     1,     2,     6,     1,     1,     4,     5,
       4,     5,     8,     7,     1,     1,     3,     6,     1,     3,
       3,     1,     3,     2,     4,     5,     4,     1
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
#line 83 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2377 "basilisk.c"
    break;

  case 5: /* translation_unit: translation_unit error '}'  */
#line 84 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2383 "basilisk.c"
    break;

  case 6: /* translation_unit: translation_unit error ')'  */
#line 85 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2389 "basilisk.c"
    break;

  case 13: /* expression_error: error  */
#line 98 "basilisk.yacc"
                        { yyvsp[0]->sym = YYSYMBOL_YYerror; }
#line 2395 "basilisk.c"
    break;

  case 107: /* declaration: declaration_specifiers ';' type_not_specified  */
#line 290 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 2401 "basilisk.c"
    break;

  case 108: /* declaration: declaration_specifiers init_declarator_list ';' type_not_specified  */
#line 291 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 2407 "basilisk.c"
    break;

  case 131: /* type_specifier: types  */
#line 329 "basilisk.yacc"
                   { parse->type_already_specified = true; }
#line 2413 "basilisk.c"
    break;

  case 151: /* struct_or_union_specifier: struct_or_union '{' error '}'  */
#line 355 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2419 "basilisk.c"
    break;

  case 152: /* struct_or_union_specifier: struct_or_union generic_identifier '{' error '}'  */
#line 356 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2425 "basilisk.c"
    break;

  case 202: /* direct_declarator: direct_declarator '(' type_not_specified error ')'  */
#line 451 "basilisk.yacc"
                                                                                           { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2431 "basilisk.c"
    break;

  case 248: /* type_not_specified: %empty  */
#line 530 "basilisk.yacc"
           { parse->type_already_specified = false; }
#line 2437 "basilisk.c"
    break;

  case 269: /* statement: error ';'  */
#line 572 "basilisk.yacc"
                     { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2443 "basilisk.c"
    break;

  case 274: /* @1: %empty  */
#line 584 "basilisk.yacc"
                           { stack_push (parse->stack, &(yyvsp[0])); yyval->sym = YYSYMBOL_YYUNDEF; }
#line 2449 "basilisk.c"
    break;

  case 275: /* compound_statement: '{' @1 block_item_list '}'  */
#line 586 "basilisk.yacc"
                           { ast_pop_scope (parse->stack, yyvsp[-3]); }
#line 2455 "basilisk.c"
    break;

  case 285: /* for_scope: FOR  */
#line 611 "basilisk.yacc"
              { stack_push (parse->stack, &(yyval)); }
#line 2461 "basilisk.c"
    break;

  case 288: /* iteration_statement: for_scope '(' expression_statement expression_statement ')' statement  */
#line 618 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2467 "basilisk.c"
    break;

  case 289: /* iteration_statement: for_scope '(' expression_statement expression_statement expression ')' statement  */
#line 620 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2473 "basilisk.c"
    break;

  case 291: /* for_declaration_statement: for_scope '(' declaration expression_statement ')' statement  */
#line 626 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2479 "basilisk.c"
    break;

  case 292: /* for_declaration_statement: for_scope '(' declaration expression_statement expression ')' statement  */
#line 628 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2485 "basilisk.c"
    break;

  case 304: /* external_declaration: error compound_statement  */
#line 646 "basilisk.yacc"
                                                { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2491 "basilisk.c"
    break;

  case 305: /* function_declaration: declaration_specifiers declarator  */
#line 650 "basilisk.yacc"
                                            { ast_push_function_definition (parse->stack, yyvsp[0]);  }
#line 2497 "basilisk.c"
    break;

  case 306: /* function_definition: function_declaration declaration_list compound_statement  */
#line 655 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-2]->child[1]); }
#line 2503 "basilisk.c"
    break;

  case 307: /* function_definition: function_declaration compound_statement  */
#line 657 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-1]->child[1]); }
#line 2509 "basilisk.c"
    break;

  case 332: /* forin_declaration_statement: for_scope '(' declaration_specifiers declarator IN forin_arguments ')' statement  */
#line 722 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-7]); }
#line 2515 "basilisk.c"
    break;

  case 333: /* forin_statement: for_scope '(' expression IN forin_arguments ')' statement  */
#line 727 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2521 "basilisk.c"
    break;

  case 347: /* root: translation_unit  */
#line 768 "basilisk.yacc"
                           {
	  yyval = root;
	  yyval->sym = yyr1[yyn];
	  yyval->child = allocate ((Allocator *)parse->alloc, 2*sizeof(Ast *));
	  yyval->child[0] = yyvsp[0];
	  yyvsp[0]->parent = yyval;
	  yyval->child[1] = NULL;
        }
#line 2534 "basilisk.c"
    break;


#line 2538 "basilisk.c"

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

#line 778 "basilisk.yacc"


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
