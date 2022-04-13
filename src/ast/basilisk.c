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
#define YYFINAL  194
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3521

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  352
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  631

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
     161,   162,   163,   167,   168,   169,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   185,   186,   187,   188,   189,
     190,   194,   195,   201,   202,   203,   204,   208,   209,   210,
     214,   215,   216,   220,   221,   222,   223,   224,   228,   229,
     230,   234,   235,   239,   240,   244,   245,   249,   250,   254,
     255,   259,   260,   264,   265,   266,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   284,   285,   289,
     293,   294,   295,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   312,   313,   317,   318,   322,   323,   324,
     325,   326,   327,   328,   332,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   355,   356,   357,   358,   359,   363,   364,   368,   369,
     373,   374,   375,   379,   380,   381,   382,   386,   387,   391,
     392,   393,   397,   398,   399,   400,   401,   405,   406,   410,
     411,   415,   419,   420,   421,   422,   423,   427,   428,   432,
     433,   437,   438,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   460,   461,
     465,   466,   467,   468,   472,   473,   477,   478,   482,   483,
     487,   488,   489,   493,   494,   498,   499,   503,   504,   505,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   533,   537,   538,   539,   543,   544,   545,   546,   550,
     554,   555,   559,   560,   564,   568,   569,   570,   571,   572,
     573,   574,   575,   579,   580,   581,   585,   587,   587,   593,
     594,   598,   599,   603,   604,   608,   609,   610,   614,   618,
     619,   620,   622,   624,   628,   630,   635,   636,   637,   638,
     639,   643,   644,   645,   646,   647,   648,   649,   650,   654,
     658,   660,   665,   666,   673,   674,   675,   676,   677,   678,
     682,   686,   687,   691,   692,   696,   697,   701,   702,   706,
     710,   711,   715,   716,   720,   721,   725,   730,   735,   736,
     740,   744,   748,   749,   750,   754,   755,   756,   760,   764,
     765,   769,   773
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

#define YYPACT_NINF (-562)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-353)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1068,   -45,   139,  -562,  -562,  -562,  -562,  2604,  2618,  2618,
     -53,  -562,  -562,  -562,  -562,  -562,  -562,  -562,  -562,  -562,
    -562,  -562,  -562,  -562,  -562,  -562,  -562,  -562,  -562,  -562,
    -562,  -562,  -562,  -562,  -562,    10,   -38,   -26,   -20,   -14,
    -562,    -4,  -562,  -562,     5,  -562,    40,  1168,  -562,  -562,
    -562,  -562,  -562,  -562,   768,  -562,  -562,  -562,  -562,   396,
    -562,   -45,   683,  2716,  -562,   103,    83,   323,    71,   334,
     106,   109,   101,   201,     9,  -562,   150,  -562,    30,  3325,
    3325,  -562,  -562,    65,  -562,  -562,  3325,  3325,  3325,    85,
    -562,  -562,  3017,  -562,  -562,  -562,  -562,  -562,  -562,   243,
     193,  -562,  -562,  1168,  -562,  -562,  1168,  -562,  -562,  -562,
    -562,   280,   203,  1399,  3445,  3445,  2716,  2716,   281,    46,
    -562,  -562,   224,  -562,   232,  3445,   -55,  3445,   240,   154,
    -562,    13,  -562,  -562,  1939,    13,  2069,  -562,  -562,  -562,
    -562,  -562,  -562,  -562,  -562,  -562,  -562,  -562,  -562,  2083,
    -562,  -562,  2716,  2716,  2716,  2716,  2716,  2716,  2716,  2716,
    2716,  2716,  2716,  2716,  2716,  2716,  2716,  2716,  2716,  2716,
    2716,  -562,  -562,    59,   425,   149,  -562,   104,   -39,  -562,
     179,  -562,  -562,  2711,   252,  -562,  -562,  -562,  3367,   267,
    -562,    30,  -562,  3017,  -562,  -562,   968,   278,   283,  -562,
     285,   128,  -562,   280,  -562,   307,   317,   324,   333,   295,
     343,   385,   335,  3325,  -562,  2716,  -562,  2952,  1453,   -11,
    -562,   123,  -562,  -562,  2083,  -562,  -562,  -562,  -562,  -562,
     328,  -562,  2716,    64,  -562,  -562,  -562,  -562,  -562,   -59,
    1923,  -562,  -562,  -562,  -562,  -562,   103,   103,    83,    83,
     323,   323,   323,   323,    71,    71,   334,   106,   109,   101,
     201,   284,  -562,   354,  -562,  -562,  -562,   425,  -562,    59,
    2114,  -562,  1499,  -562,   -39,   357,  3127,  -562,    41,  -562,
    2907,  3175,  2716,   350,  -562,  -562,   364,  2716,   362,   366,
     380,   381,   584,  -562,    13,   386,   387,  2192,   382,   392,
     393,  -562,   213,  -562,   401,  -562,  -562,  -562,   868,  -562,
    -562,  -562,   394,  -562,  -562,  -562,  -562,  -562,  -562,  -562,
    -562,  -562,  -562,   383,   383,  2716,  -562,    75,   192,  -562,
    -562,  -562,  -562,  3406,   476,  -562,  3325,    59,  -562,  -562,
    -562,    61,   405,   404,  -562,   407,  1747,  -562,   402,   409,
    1551,   123,  -562,  -562,  1597,  -562,  -562,  2114,   217,  -562,
    2223,  -562,    13,  1923,  2716,  -562,  -562,   229,  2114,    97,
    -562,  2716,  -562,  -562,  -562,  -562,  -562,  -562,  2852,  1747,
    -562,   412,   416,  1649,  -562,  -562,  -562,  -562,  -562,  2716,
     215,  -562,   408,   415,  3223,  -562,   683,  -562,   205,  -562,
    -562,   422,   584,  1223,  1223,  2716,   432,   428,  -562,  -562,
    -562,   223,  1971,  2301,    80,  -562,   584,  -562,  -562,  1301,
    -562,  -562,  -562,  -562,    93,   424,   241,  -562,   429,   431,
    -562,  -562,  2787,  -562,    62,  -562,  -562,  3277,  -562,  -562,
     421,  1747,  -562,  -562,  2716,  -562,   427,  3077,  1747,  -562,
     430,   433,  1695,  -562,  -562,  -562,  -562,   233,   434,  -562,
    1793,  -562,  -562,  -562,  -562,   436,  -562,  -562,   438,   254,
     435,  1747,  -562,  -562,  2716,  -562,   441,   443,  -562,  -562,
    -562,    42,  2716,  -562,  -562,  2083,  2716,   584,  2716,   584,
    -562,   439,   445,   258,   451,  -562,  -562,   452,   584,  -562,
     261,  -562,   457,  -562,   584,   269,   460,   584,  -562,   102,
    2332,    30,  2332,  -562,  2716,  -562,  3406,  2716,   463,  -562,
    -562,  -562,   455,   458,  -562,  -562,   464,   459,  1747,  -562,
    -562,  2716,  -562,   461,  -562,  1825,  -562,  -562,  -562,  2114,
    -562,  -562,  -562,   550,  -562,   462,   468,  -562,  -562,  -562,
    -562,  -562,  -562,  -562,  -562,  -562,  -562,  -562,   584,   584,
     584,  2716,    27,  -562,   584,  2430,  -562,  -562,   584,   584,
    -562,  2444,  2475,   -52,  2573,  -562,  -562,  -562,  -562,  -562,
    -562,  -562,  -562,  -562,   469,   470,  -562,  -562,  -562,  -562,
    -562,  -562,   496,  -562,  -562,   272,  -562,  -562,   481,  -562,
    -562,  -562,  -562,   232,   471,  -562,   584,   275,  2444,   584,
     292,  -562,  -562,   584,   487,    13,   584,  -562,   584,   479,
    -562,   584,  -562,  -562,   489,  -562,  -562,   584,  -562,  -562,
    -562
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     7,    14,    15,    18,    19,     0,     0,     0,
     150,    16,   127,   128,   129,   131,   132,   187,   182,   183,
     184,   144,   136,   137,   138,   139,   142,   143,   140,   141,
     135,   145,   146,   156,   157,     0,     0,     0,   185,     0,
     188,     0,   130,   186,    53,   133,     0,     0,    55,    56,
      57,    58,    59,    60,     0,    25,     8,     9,    11,    46,
      27,    26,    61,     0,    63,    67,    70,    73,    78,    81,
      83,    85,    87,    89,    91,    93,     0,   302,     0,   114,
     116,   134,   148,     0,   149,   147,   118,   120,   122,     0,
     112,     2,     0,   301,   303,   304,   305,   306,   307,     0,
     277,   308,     7,     0,    26,    50,     0,    47,    48,   208,
     209,     0,   176,     0,     0,     0,     0,     0,     0,     0,
      13,   150,     0,   107,    12,   164,   251,   166,     0,     0,
       3,     0,    30,    31,     0,     0,     0,   320,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    96,     0,
      61,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,   251,     0,   213,     0,   123,   309,   251,   193,
       0,   113,   115,     0,   153,   117,   119,   121,     0,     0,
     312,     0,   311,     0,     1,   276,     0,     0,     0,    17,
     180,     0,   177,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,   163,     0,     0,   228,
     251,   229,   226,   165,     0,     4,     5,     6,    29,    39,
       7,    37,     0,     0,    40,    43,    45,    28,    35,     0,
       0,    95,    94,    64,    65,    66,    68,    69,    71,    72,
      76,    77,    74,    75,    79,    80,    82,    84,    86,    88,
      90,     0,   110,     0,   185,   214,   212,   211,   251,     0,
       0,   251,     0,   192,   251,     0,     0,   158,     0,   162,
       0,     0,     0,   126,   313,   310,     0,     0,     0,     0,
       0,     0,     0,   288,     0,     0,     0,     0,     0,     0,
       0,   283,     0,   281,     0,   282,   265,   266,     0,   279,
     267,   268,     0,   269,   293,   270,   271,   314,   315,   316,
     317,   318,   319,    51,     0,     0,   172,     0,     0,   190,
     189,    52,   181,     0,     0,    54,     0,     0,   349,   108,
     247,   222,     0,   217,   251,     0,     0,   231,    56,     0,
       0,   227,   225,   251,     0,    32,    62,     0,     0,    38,
      42,    36,     0,     0,     0,   254,   256,     0,     0,     0,
     260,     0,   194,   215,   210,   111,   124,   125,     0,     0,
     195,    56,     0,     0,   191,   154,   151,   159,   251,     0,
       0,   167,   171,     0,     0,   351,    61,   345,     0,   342,
     272,     0,     0,     0,     0,     0,     0,     0,   297,   298,
     299,     0,     0,     0,     0,   284,     0,   278,   280,     0,
     179,   173,   178,   174,     0,     0,     0,    21,     0,     0,
     350,   309,     0,   220,   228,   221,   248,     0,   218,   230,
       0,     0,   232,   238,     0,   237,     0,     0,     0,   239,
      56,     0,     0,    44,   340,    41,   263,     0,     0,    33,
       0,   255,   259,   261,    92,     0,   223,   206,     0,     0,
       0,     0,   196,   203,     0,   202,    56,     0,   160,   169,
     251,     0,     0,   155,   152,     0,     0,     0,     0,     0,
     275,     0,     0,     0,     0,   296,   300,     0,     0,   325,
       0,   323,   326,   327,     0,     0,     0,     0,   273,     0,
       0,     0,     0,   175,     0,    20,     0,     0,     0,   216,
     251,   234,     0,     0,   236,   249,     0,     0,     0,   240,
     246,     0,   245,     0,   252,     0,   262,    34,   258,     0,
     205,   204,   207,     0,   198,     0,     0,   199,   201,   161,
     168,   170,   347,   346,   344,   341,   343,   274,     0,     0,
       0,     0,     0,   321,     0,     0,   328,   332,     0,     0,
     334,     0,     0,   126,     0,    24,    22,    23,   264,   219,
     233,   235,   250,   242,     0,     0,   243,   253,   257,   224,
     197,   200,   286,   287,   289,     0,   331,   330,     0,   322,
     324,   333,   335,   338,     0,   339,     0,     0,     0,     0,
       0,   241,   244,     0,     0,     0,     0,   294,     0,     0,
     291,     0,   285,   290,     0,   337,   295,     0,   292,   329,
     336
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -562,  -562,  -562,   -17,  -562,  -562,  -562,  -562,  -562,    57,
     466,  -148,  -562,     0,   447,  -562,   216,    95,  -562,   -54,
     242,   260,   296,   297,   413,   437,   426,   440,   442,  -562,
     -58,     2,   202,   -29,   -94,   -87,   236,  -562,   330,  -562,
     320,  -562,  -562,  -562,  -157,  -254,  -113,  -562,   116,  -562,
     399,  -303,  -562,    58,  -562,  -562,   -72,  -163,     4,  -123,
    -152,  -357,  -562,   167,  -562,   286,  -119,  -211,  -109,  -235,
     244,  -260,  -562,   248,  -168,   133,  -562,    18,  -562,  -562,
     302,  -367,  -562,  -562,  -562,  -562,  -562,   551,  -562,  -202,
    -562,  -562,    26,  -562,  -562,    47,  -562,   121,  -562,  -562,
    -562,  -562,  -562,    16,  -561,  -562,  -562,   -73,  -562,  -562,
    -562,  -562
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    54,    55,   122,    56,   200,    57,    58,   426,   427,
      59,   355,    60,   104,   228,   233,   234,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   123,   149,   302,   205,    77,   341,   175,   176,    79,
      80,    81,    82,    83,   276,   277,   126,   390,   391,    84,
     201,   202,    85,    86,    87,    88,   263,   178,   304,   180,
     267,   342,   343,   344,   469,   428,   345,   221,   222,   366,
     367,   368,   369,   370,    90,   305,   306,   307,   196,   308,
     309,   310,   311,   312,   313,   314,   315,    91,    92,    93,
     193,   316,   317,   318,   500,   501,   502,   503,   598,   319,
     320,   321,   322,   604,   236,    95,   398,   399,    96,    97,
      98,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,   241,    76,   219,    89,   190,   177,   220,   351,   151,
     605,   338,   216,   109,   223,   279,   109,   274,   124,   101,
     279,   468,   387,   210,   422,   608,    94,   387,   169,   215,
     109,   281,   217,   109,   361,   377,  -209,   218,  -209,   112,
     110,   174,   270,   110,   109,   109,   100,   605,   271,   113,
     212,   266,   512,   272,    61,   204,    76,   110,    89,   204,
     110,   114,   109,   262,   109,   109,   350,   115,   109,   273,
     278,   110,   110,   116,   124,   278,   217,   124,   199,   137,
      94,   218,   179,   117,   506,   159,   160,   184,   109,   110,
     526,   110,   110,   189,   219,   110,   199,   118,   243,   244,
     245,   111,   105,   107,   108,   127,   284,   239,   279,   303,
     192,   352,   279,   279,   172,   110,   170,   173,   209,   283,
     383,   422,   453,   394,   596,   388,   174,   119,   173,   173,
     389,   389,   213,   461,   430,   229,   235,   174,   174,   229,
     387,   261,  -208,   572,   374,   574,   173,   101,   432,   432,
     359,   242,   360,   218,   218,   174,   183,   174,   150,   375,
     421,   127,   378,   278,   127,   384,   507,   278,   278,  -208,
     356,   127,   127,   127,   161,   162,   188,   179,   513,   571,
     155,   156,   109,   127,   179,   127,   415,   362,  -126,   364,
     215,   462,  -126,   401,   441,   179,    61,   283,   270,   152,
     539,   165,   452,   358,   153,   154,   392,   167,   150,   110,
     353,   285,   150,   326,   166,   354,   327,   339,   434,   168,
     349,   303,   435,   351,   397,   538,   279,   471,  -208,   204,
    -208,   420,   265,   268,   171,   438,    78,   269,   225,   226,
     227,   127,   365,   194,   447,   100,   127,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   431,   173,   204,   411,   433,
     458,   274,   365,   179,   382,   539,   265,   423,   195,   478,
     424,   278,   179,   199,   102,     3,     4,     5,     6,   486,
      78,   487,    61,   488,   203,   479,   528,   415,   407,   480,
     538,   215,   454,   481,   588,   215,   204,   496,    61,   434,
     214,   215,    11,   464,   459,   181,   182,   460,   534,   150,
     215,   535,   185,   186,   187,   373,   224,   515,   191,   516,
     265,   204,   510,   128,   127,   157,   158,   552,   127,   127,
     542,   179,   543,   280,   560,   179,   215,   564,   440,   565,
     163,   164,   446,    39,   282,   568,   451,   215,   614,   365,
     215,   618,   235,   215,   323,   365,   456,   125,   106,   324,
     365,   549,   215,   371,   124,   124,   493,   396,   621,   325,
     215,   470,   150,   333,   505,   477,   491,   492,   551,   197,
     509,   127,   198,   329,   131,   132,   133,   246,   247,   206,
     207,   208,    61,   330,   265,   131,   132,   133,   373,   392,
     331,   579,   265,   554,   499,   556,    61,   248,   249,   332,
     150,   336,   357,   125,   204,   406,   125,   553,   397,   191,
     397,   334,   191,   125,   125,   125,   179,   265,   179,   573,
     372,   373,   385,   522,   270,   125,   523,   125,   400,   337,
     527,   402,   127,   403,   533,   250,   251,   252,   253,   150,
     254,   255,   365,    18,    19,    20,   150,   404,   405,   412,
     408,   409,   134,   545,   240,   135,   546,   136,   335,   413,
     414,   419,   429,   134,   150,   179,   135,    61,   136,    61,
     416,   436,   437,   439,   494,   442,   264,   482,    61,   373,
     483,    43,   443,   125,    61,   472,   265,    61,   125,   473,
     373,   489,   495,   514,   521,   179,   575,   518,   517,   577,
     524,   174,   540,   529,   541,   558,   530,   536,   544,   373,
     584,   559,   595,   585,   547,   490,   548,   365,   561,   562,
     497,   365,   603,   607,   191,   610,   569,   578,   580,   508,
     582,   581,   583,   589,   586,   590,   613,   616,    61,    61,
      61,   591,   611,   612,    61,   627,   597,   499,    61,    61,
     615,   623,   337,   576,   127,   629,   455,   150,   256,   603,
     150,   396,   237,   396,   211,   286,   373,     2,     3,     4,
       5,     6,     7,   258,     8,     9,   125,   550,   485,   376,
     125,   125,   328,   257,   520,   130,    61,   457,   259,    61,
     418,   260,   600,    61,   110,    11,    61,   463,    61,   624,
     555,    61,   557,   566,   619,     0,     0,    61,     0,     0,
       0,   563,     0,     0,     0,     0,     0,   567,     0,     0,
     570,   287,   288,   289,     0,   290,   291,   292,   293,   294,
     295,   296,   297,   125,    37,   511,    39,     0,     0,     0,
       0,     0,    44,     0,   298,   299,   300,     0,   301,     0,
       0,    47,     0,     0,     0,   100,     0,     0,     0,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,   592,   593,   594,     0,     0,     0,   599,     0,     0,
       0,   601,   602,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   617,
       0,     0,   620,     0,     0,     0,   622,     0,     0,   625,
       0,   626,     0,     0,   628,     0,     0,     0,     0,     0,
     630,     0,     0,     0,     0,     0,     0,     0,  -352,   129,
       0,     2,     3,     4,     5,     6,     7,   148,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,     0,     0,
      46,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   286,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,   287,   288,   289,     0,   290,
     291,   292,   293,   294,   295,   296,   297,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,   298,   299,
     300,     0,   301,   417,     0,    47,     0,     0,     0,   100,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   286,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,   287,   288,   289,     0,   290,
     291,   292,   293,   294,   295,   296,   297,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,   298,   299,
     300,     0,   301,     0,     0,    47,     0,     0,     0,   100,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     1,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,     0,     0,
      46,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   120,
       0,   102,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,    11,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   120,     0,   102,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,    37,    38,
      39,     0,     0,     0,    43,     0,    44,     0,     0,     0,
       0,     0,     0,     0,    11,    47,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,    44,     0,     0,   102,     3,     4,     5,     6,     7,
      47,     8,     9,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,   121,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,     0,     0,     0,     0,   301,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,   102,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
      11,     0,     0,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,   102,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,    37,
      38,    39,     0,     0,     0,    43,     0,    44,     0,     0,
       0,     0,     0,     0,    11,     0,    47,   346,     0,     0,
       0,    18,    19,    20,    48,    49,    50,    51,    52,    53,
       0,     0,   102,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,   264,    39,     0,     0,     0,    43,
      11,    44,     0,   379,     0,     0,     0,    18,    19,    20,
      47,     0,     0,     0,     0,     0,   347,     0,    48,   348,
      50,    51,    52,    53,   102,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,    37,
     264,    39,     0,     0,     0,    43,     0,    44,     0,     0,
       0,     0,    11,     0,     0,   444,    47,     0,     0,    18,
      19,    20,   380,     0,    48,   381,    50,    51,    52,    53,
     102,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,   264,    39,     0,     0,     0,    43,    11,    44,
       0,   448,     0,     0,     0,    18,    19,    20,    47,     0,
       0,     0,     0,     0,   445,     0,    48,    49,    50,    51,
      52,    53,   102,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    37,   264,    39,
       0,     0,     0,    43,     0,    44,     0,     0,     0,     0,
      11,     0,     0,   474,    47,     0,     0,    18,    19,    20,
     449,     0,    48,   450,    50,    51,    52,    53,   102,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
     264,    39,     0,     0,     0,    43,    11,    44,     0,   531,
       0,     0,     0,    18,    19,    20,    47,     0,     0,     0,
       0,     0,   475,     0,    48,   476,    50,    51,    52,    53,
     102,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,    37,   264,    39,     0,     0,
       0,    43,     0,    44,     0,     0,     0,     0,    11,     0,
       0,     0,    47,     0,     0,    18,    19,    20,   532,     0,
      48,    49,    50,    51,    52,    53,   102,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,   264,    39,
       0,     0,     0,    43,    11,    44,     0,     0,   102,     3,
       4,     5,     6,     7,    47,     8,     9,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,   537,     0,
      47,     0,     0,   362,   363,   364,     0,     0,    48,    49,
      50,    51,    52,    53,     0,    37,     0,    39,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
     587,     0,    47,     0,     0,   362,   363,   364,     0,     0,
      48,    49,    50,    51,    52,    53,   102,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,   230,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,   102,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,    44,    11,     0,     0,     0,     0,     0,     0,    37,
      47,    39,     0,   362,   363,   364,     0,    44,    48,    49,
      50,    51,    52,    53,     0,   231,    47,     0,     0,     0,
     232,     0,     0,     0,    48,    49,    50,    51,    52,    53,
       0,    37,     0,    39,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,   497,     0,     0,   498,    47,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,   102,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,   102,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,   102,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,    11,     0,    44,     0,     0,
       0,     0,     0,    37,     0,    39,    47,     0,     0,     0,
       0,    44,   238,     0,    48,    49,    50,    51,    52,    53,
      47,     0,     0,     0,   240,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    37,     0,    39,     0,     0,     0,
       0,     0,    44,     0,     0,   102,     3,     4,     5,     6,
       7,    47,     8,     9,     0,   363,     0,     0,     0,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,   230,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,   410,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,    37,     0,    39,     0,     0,     0,     0,
       0,    44,     0,     0,   102,     3,     4,     5,     6,     7,
      47,     8,     9,     0,   232,     0,     0,     0,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,   102,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,     0,   504,    47,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    37,     0,    39,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,   301,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,   102,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,   102,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,   102,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    39,     0,     0,     0,    11,     0,    44,     0,
       0,     0,     0,   497,    37,     0,    39,    47,     0,     0,
       0,     0,    44,     0,     0,    48,    49,    50,    51,    52,
      53,    47,     0,     0,     0,   232,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    37,     0,    39,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       0,   606,    47,     0,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,    53,   102,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,   102,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,   102,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,    11,
       0,    44,     0,     0,     0,     0,     0,     0,     0,   609,
      47,     0,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    37,     0,    39,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,    37,     0,
      39,   103,     0,     0,     0,     0,    44,     0,     0,    48,
      49,    50,    51,    52,    53,   106,     0,     0,     0,     0,
       0,     0,   275,    48,    49,    50,    51,    52,    53,   102,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,     0,     0,    11,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,    41,    37,    43,    39,     0,
     109,     0,     0,     0,    44,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,    10,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   465,     0,   466,    36,     0,    38,     0,
      40,     0,    42,    43,     0,     0,    45,     0,     0,     0,
       0,     0,     0,   340,   432,     0,     0,     0,     0,   218,
       0,     0,   121,   174,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   393,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    38,     0,    40,     0,    42,    43,     0,
       0,    45,     0,     0,     0,     0,     0,   121,   467,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    41,   121,    43,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    38,     0,    40,     0,    42,    43,     0,
       0,    45,     0,     0,     0,     0,     0,     0,   340,   217,
       0,     0,     0,     0,   218,     0,     0,   121,   174,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,     0,
      40,    41,    42,    43,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   100,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,     0,
      40,     0,    42,    43,     0,     0,    45,   121,     0,     0,
       0,     0,     0,   525,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    41,     0,    43,     0,   121,     0,     0,     0,     0,
       0,     0,   386,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,    41,
       0,    43,     0,   121,     0,     0,     0,     0,     0,     0,
     395,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    41,     0,    43,
       0,     0,     0,     0,     0,     0,     0,   121,   484,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   519,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,     0,
      40,     0,    42,    43,     0,   121,    45,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,     0,    38,   121,    40,     0,
      42,    43,     0,     0,    45,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,    38,     0,
       0,    41,     0,    43,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,   425,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,    38,     0,     0,
       0,     0,    43,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,    43
};

static const yytype_int16 yycheck[] =
{
       0,   149,     0,   126,     0,    92,    78,   126,   219,    63,
     571,   213,   125,     3,   127,   183,     3,   180,    47,     1,
     188,   378,   276,   117,   327,    77,     0,   281,    19,    88,
       3,   188,    87,     3,    93,   270,    89,    92,    91,    35,
      30,    96,    94,    30,     3,     3,    91,   608,    87,    87,
       4,   174,   419,    92,    54,   113,    54,    30,    54,   117,
      30,    87,     3,   172,     3,     3,   218,    87,     3,   178,
     183,    30,    30,    87,   103,   188,    87,   106,     3,    61,
      54,    92,    78,    87,     4,    14,    15,    83,     3,    30,
     447,    30,    30,    89,   217,    30,     3,    92,   152,   153,
     154,    91,     7,     8,     9,    47,   193,   136,   276,   196,
      92,   220,   280,   281,    84,    30,   107,    87,   116,   191,
     272,   424,   357,   280,    97,    84,    96,    87,    87,    87,
      89,    89,    86,   368,   336,   131,   134,    96,    96,   135,
     394,   170,     3,   510,   267,   512,    87,   129,    87,    87,
      86,   149,    88,    92,    92,    96,    91,    96,    63,   268,
      85,   103,   271,   276,   106,   274,    86,   280,   281,    30,
     224,   113,   114,   115,   103,   104,    91,   173,    85,    77,
      97,    98,     3,   125,   180,   127,    84,    90,    84,    92,
      88,    94,    88,   287,   346,   191,   196,   269,    94,    96,
     460,    95,   354,   232,   101,   102,   278,   106,   113,    30,
      87,   193,   117,    85,   105,    92,    88,   215,   341,    18,
     218,   308,   341,   434,   282,   460,   394,   379,    89,   287,
      91,   325,   174,    84,    84,   344,     0,    88,    84,    85,
      86,   183,   240,     0,   353,    91,   188,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   337,    87,   325,   297,   341,
     364,   434,   270,   269,   272,   535,   218,    85,    85,   388,
      88,   394,   278,     3,     3,     4,     5,     6,     7,    84,
      54,    86,   292,    88,    91,   389,   448,    84,   294,    84,
     535,    88,    85,    88,   539,    88,   364,    84,   308,   432,
      86,    88,    31,   371,    85,    79,    80,    88,    85,   224,
      88,    88,    86,    87,    88,   267,    86,    86,    92,    88,
     272,   389,   419,    47,   276,    12,    13,   485,   280,   281,
      86,   337,    88,    91,    86,   341,    88,    86,   346,    88,
      16,    17,   350,    72,    87,    86,   354,    88,    86,   357,
      88,    86,   360,    88,    86,   363,   362,    47,    87,    86,
     368,   480,    88,    89,   403,   404,   405,   282,    86,    94,
      88,   379,   287,    88,   413,   383,   403,   404,   482,   103,
     419,   333,   106,    86,     9,    10,    11,   155,   156,   113,
     114,   115,   402,    86,   346,     9,    10,    11,   350,   481,
      86,   520,   354,   486,   412,   488,   416,   157,   158,    86,
     325,    86,    94,   103,   482,   292,   106,   485,   486,   193,
     488,    88,   196,   113,   114,   115,   432,   379,   434,   511,
      86,   383,    85,   441,    94,   125,   444,   127,    84,   213,
     448,    89,   394,    87,   452,   159,   160,   161,   162,   364,
     163,   164,   460,    38,    39,    40,   371,    87,    87,    87,
      84,    84,    87,   471,    91,    90,   474,    92,    93,    87,
      87,    87,     6,    87,   389,   481,    90,   487,    92,   489,
      89,    86,    88,    86,    62,    93,    71,    89,   498,   441,
      85,    76,    93,   183,   504,    93,   448,   507,   188,    93,
     452,    89,    84,    89,    93,   511,   514,    86,    89,   517,
      93,    96,    86,    93,    86,    86,    93,    93,    93,   471,
     528,    86,   561,   531,    93,   402,    93,   535,    87,    87,
      83,   539,   571,   572,   308,   574,    86,    84,    93,   416,
      86,    93,    93,     3,    93,    93,    60,    86,   558,   559,
     560,    93,    93,    93,   564,    86,   562,   565,   568,   569,
      89,    84,   336,   516,   516,    86,   360,   482,   165,   608,
     485,   486,   135,   488,   118,     1,   528,     3,     4,     5,
       6,     7,     8,   167,    10,    11,   276,   481,   396,   269,
     280,   281,   203,   166,   437,    54,   606,   363,   168,   609,
     308,   169,   565,   613,    30,    31,   616,   369,   618,   615,
     487,   621,   489,   502,   608,    -1,    -1,   627,    -1,    -1,
      -1,   498,    -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,
     507,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,   333,    70,   419,    72,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    81,    82,    -1,    84,    -1,
      -1,    87,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,   558,   559,   560,    -1,    -1,    -1,   564,    -1,    -1,
      -1,   568,   569,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,   394,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   606,
      -1,    -1,   609,    -1,    -1,    -1,   613,    -1,    -1,   616,
      -1,   618,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,
     627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,    94,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   516,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    -1,    84,    85,    -1,    87,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,     3,     4,     5,     6,     7,     8,
      87,    10,    11,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      79,    -1,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    87,    34,    -1,    -1,
      -1,    38,    39,    40,    95,    96,    97,    98,    99,   100,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
      31,    78,    -1,    34,    -1,    -1,    -1,    38,    39,    40,
      87,    -1,    -1,    -1,    -1,    -1,    93,    -1,    95,    96,
      97,    98,    99,   100,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    -1,    78,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    87,    -1,    -1,    38,
      39,    40,    93,    -1,    95,    96,    97,    98,    99,   100,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    31,    78,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    87,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    95,    96,    97,    98,
      99,   100,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    87,    -1,    -1,    38,    39,    40,
      93,    -1,    95,    96,    97,    98,    99,   100,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    31,    78,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    87,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    95,    96,    97,    98,    99,   100,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    87,    -1,    -1,    38,    39,    40,    93,    -1,
      95,    96,    97,    98,    99,   100,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    31,    78,    -1,    -1,     3,     4,
       5,     6,     7,     8,    87,    10,    11,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      87,    -1,    -1,    90,    91,    92,    -1,    -1,    95,    96,
      97,    98,    99,   100,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    87,    -1,    -1,    90,    91,    92,    -1,    -1,
      95,    96,    97,    98,    99,   100,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    78,    31,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      87,    72,    -1,    90,    91,    92,    -1,    78,    95,    96,
      97,    98,    99,   100,    -1,    86,    87,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    31,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    87,    -1,    -1,    -1,
      -1,    78,    93,    -1,    95,    96,    97,    98,    99,   100,
      87,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    70,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,     3,     4,     5,     6,     7,
       8,    87,    10,    11,    -1,    91,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    70,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,     3,     4,     5,     6,     7,     8,
      87,    10,    11,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    31,    -1,    78,    -1,
      -1,    -1,    -1,    83,    70,    -1,    72,    87,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    95,    96,    97,    98,    99,
     100,    87,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    31,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    70,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    87,    -1,    -1,    -1,    -1,    78,    -1,    -1,    95,
      96,    97,    98,    99,   100,    87,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    95,    96,    97,    98,    99,   100,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    31,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    70,    76,    72,    -1,
       3,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,    69,    -1,    71,    -1,
      73,    -1,    75,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    30,    96,    32,    33,    34,    35,    36,    37,
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
      -1,    -1,    -1,    -1,    92,    -1,    -1,    30,    96,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,
      73,    74,    75,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    91,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,
      73,    -1,    75,    76,    -1,    -1,    79,    30,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    76,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,    76,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    85,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,
      73,    -1,    75,    76,    -1,    30,    79,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    30,    73,    -1,
      75,    76,    -1,    -1,    79,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    71,    -1,
      -1,    74,    -1,    76,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    71,    -1,    -1,
      -1,    -1,    76,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    76
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
     182,   195,   196,   197,   200,   213,   216,   217,   218,   219,
      91,   185,     3,    87,   121,   125,    87,   125,   125,     3,
      30,    91,   166,    87,    87,    87,    87,    87,    92,    87,
       1,    30,   111,   139,   141,   148,   154,   161,   173,     1,
     195,     9,    10,    11,    87,    90,    92,   185,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    94,   140,
     125,   127,    96,   101,   102,    97,    98,    12,    13,    14,
      15,   103,   104,    16,    17,    95,   105,   106,    18,    19,
     107,    84,    84,    87,    96,   145,   146,   164,   165,   166,
     167,   144,   144,    91,   166,   144,   144,   144,    91,   166,
     143,   144,   185,   198,     0,    85,   186,   173,   173,     3,
     113,   158,   159,    91,   138,   142,   173,   173,   173,   139,
     142,   118,     4,    86,    86,    88,   154,    87,    92,   167,
     174,   175,   176,   154,    86,    84,    85,    86,   122,   166,
       3,    86,    91,   123,   124,   139,   212,   122,    93,   141,
      91,   119,   139,   127,   127,   127,   128,   128,   129,   129,
     130,   130,   130,   130,   131,   131,   132,   133,   134,   135,
     136,   141,   176,   164,    71,   161,   167,   168,    84,    88,
      94,    87,    92,   176,   165,     1,   152,   153,   154,   182,
      91,   152,    87,   164,   143,   185,     1,    57,    58,    59,
      61,    62,    63,    64,    65,    66,    67,    68,    80,    81,
      82,    84,   141,   143,   166,   183,   184,   185,   187,   188,
     189,   190,   191,   192,   193,   194,   199,   200,   201,   207,
     208,   209,   210,    86,    86,    94,    85,    88,   158,    86,
      86,    86,    86,    88,    88,    93,    86,   144,   197,   139,
      86,   144,   169,   170,   171,   174,    34,    93,    96,   139,
     168,   175,   176,    87,    92,   119,   127,    94,   141,    86,
      88,    93,    90,    91,    92,   139,   177,   178,   179,   180,
     181,    89,    86,   161,   167,   176,   146,   177,   176,    34,
      93,    96,   139,   168,   176,    85,    85,   153,    84,    89,
     155,   156,   164,     1,   152,    85,   125,   138,   214,   215,
      84,   142,    89,    87,    87,    87,   183,   166,    84,    84,
      84,   141,    87,    87,    87,    84,    89,    85,   188,    87,
     142,    85,   159,    85,    88,    58,   116,   117,   173,     6,
     197,   164,    87,   164,   167,   174,    86,    88,   176,    86,
     139,   168,    93,    93,    34,    93,   139,   176,    34,    93,
      96,   139,   168,   177,    85,   124,   166,   178,   142,    85,
      88,   177,    94,   181,   138,     1,     3,    86,   169,   172,
     139,   168,    93,    93,    34,    93,    96,   139,   176,   142,
      84,    88,    89,    85,    85,   140,    84,    86,    88,    89,
     183,   111,   111,   141,    62,    84,    84,    83,    86,   139,
     202,   203,   204,   205,    86,   141,     4,    86,   183,   141,
     143,   144,   189,    85,    89,    86,    88,    89,    86,    56,
     171,    93,   139,   139,    93,    86,   169,   139,   168,    93,
      93,    34,    93,   139,    85,    88,    93,    85,   177,   179,
      86,    86,    86,    88,    93,   139,   139,    93,    93,   176,
     156,   142,   119,   138,   215,   183,   215,   183,    86,    86,
      86,    87,    87,   183,    86,    88,   205,   183,    86,    86,
     183,    77,   189,   164,   189,   139,   117,   139,    84,   176,
      93,    93,    86,    93,   139,   139,    93,    85,   177,     3,
      93,    93,   183,   183,   183,   141,    97,   166,   206,   183,
     203,   183,   183,   141,   211,   212,    86,   141,    77,    86,
     141,    93,    93,    60,    86,    89,    86,   183,    86,   211,
     183,    86,   183,    84,   166,   183,   183,    86,   183,    86,
     183
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   112,   113,   114,   114,
     115,   116,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     123,   123,   123,   124,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   126,   126,   126,   126,   126,
     126,   127,   127,   128,   128,   128,   128,   129,   129,   129,
     130,   130,   130,   131,   131,   131,   131,   131,   132,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   139,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   141,   141,   142,
     143,   143,   143,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   145,   145,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   148,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   150,   150,   150,   150,   150,   151,   151,   152,   152,
     153,   153,   153,   154,   154,   154,   154,   155,   155,   156,
     156,   156,   157,   157,   157,   157,   157,   158,   158,   159,
     159,   160,   161,   161,   161,   161,   161,   162,   162,   163,
     163,   164,   164,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   166,   166,
     167,   167,   167,   167,   168,   168,   169,   169,   170,   170,
     171,   171,   171,   172,   172,   173,   173,   174,   174,   174,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   176,   177,   177,   177,   178,   178,   178,   178,   179,
     180,   180,   181,   181,   182,   183,   183,   183,   183,   183,
     183,   183,   183,   184,   184,   184,   185,   186,   185,   187,
     187,   188,   188,   189,   189,   190,   190,   190,   191,   192,
     192,   192,   192,   192,   193,   193,   194,   194,   194,   194,
     194,   195,   195,   195,   195,   195,   195,   195,   195,   196,
     197,   197,   198,   198,   199,   199,   199,   199,   199,   199,
     200,   201,   201,   202,   202,   203,   203,   204,   204,   205,
     206,   206,   207,   207,   208,   208,   209,   210,   211,   211,
     212,   213,   214,   214,   214,   215,   215,   215,   216,   217,
     217,   218,   219
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       2,     2,     4,     3,     4,     3,     4,     3,     4,     1,
       1,     3,     2,     1,     3,     1,     1,     2,     2,     2,
       2,     4,     4,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     4,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     2,     4,     5,     1,     1,     1,     2,
       3,     4,     1,     2,     1,     2,     1,     1,     3,     2,
       3,     1,     4,     5,     5,     6,     2,     1,     3,     3,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     3,     2,     1,     3,     3,     4,     6,     5,     5,
       6,     5,     4,     4,     5,     5,     4,     5,     1,     1,
       3,     2,     2,     1,     1,     2,     3,     1,     2,     4,
       2,     2,     1,     1,     3,     3,     2,     2,     1,     1,
       3,     2,     3,     5,     4,     5,     4,     3,     3,     3,
       4,     6,     5,     5,     6,     4,     4,     2,     3,     4,
       5,     0,     3,     4,     1,     2,     1,     4,     3,     2,
       1,     2,     3,     2,     7,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     3,     2,     0,     4,     1,
       2,     1,     1,     1,     2,     7,     5,     5,     1,     5,
       7,     6,     7,     1,     6,     7,     3,     2,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     4,     5,     1,     3,     1,     1,     1,     2,     6,
       1,     1,     4,     5,     4,     5,     8,     7,     1,     1,
       3,     6,     1,     3,     3,     1,     3,     3,     2,     4,
       5,     4,     1
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
#line 2383 "basilisk.c"
    break;

  case 5: /* translation_unit: translation_unit error '}'  */
#line 84 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2389 "basilisk.c"
    break;

  case 6: /* translation_unit: translation_unit error ')'  */
#line 85 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2395 "basilisk.c"
    break;

  case 13: /* expression_error: error  */
#line 98 "basilisk.yacc"
                        { yyvsp[0]->sym = YYSYMBOL_YYerror; }
#line 2401 "basilisk.c"
    break;

  case 110: /* declaration: declaration_specifiers ';' type_not_specified  */
#line 293 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 2407 "basilisk.c"
    break;

  case 111: /* declaration: declaration_specifiers init_declarator_list ';' type_not_specified  */
#line 294 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 2413 "basilisk.c"
    break;

  case 134: /* type_specifier: types  */
#line 332 "basilisk.yacc"
                   { parse->type_already_specified = true; }
#line 2419 "basilisk.c"
    break;

  case 154: /* struct_or_union_specifier: struct_or_union '{' error '}'  */
#line 358 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2425 "basilisk.c"
    break;

  case 155: /* struct_or_union_specifier: struct_or_union generic_identifier '{' error '}'  */
#line 359 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2431 "basilisk.c"
    break;

  case 205: /* direct_declarator: direct_declarator '(' type_not_specified error ')'  */
#line 454 "basilisk.yacc"
                                                                                           { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2437 "basilisk.c"
    break;

  case 251: /* type_not_specified: %empty  */
#line 533 "basilisk.yacc"
           { parse->type_already_specified = false; }
#line 2443 "basilisk.c"
    break;

  case 272: /* statement: error ';'  */
#line 575 "basilisk.yacc"
                     { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2449 "basilisk.c"
    break;

  case 277: /* @1: %empty  */
#line 587 "basilisk.yacc"
                           { stack_push (parse->stack, &(yyvsp[0])); yyval->sym = YYSYMBOL_YYUNDEF; }
#line 2455 "basilisk.c"
    break;

  case 278: /* compound_statement: '{' @1 block_item_list '}'  */
#line 589 "basilisk.yacc"
                           { ast_pop_scope (parse->stack, yyvsp[-3]); }
#line 2461 "basilisk.c"
    break;

  case 288: /* for_scope: FOR  */
#line 614 "basilisk.yacc"
              { stack_push (parse->stack, &(yyval)); }
#line 2467 "basilisk.c"
    break;

  case 291: /* iteration_statement: for_scope '(' expression_statement expression_statement ')' statement  */
#line 621 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2473 "basilisk.c"
    break;

  case 292: /* iteration_statement: for_scope '(' expression_statement expression_statement expression ')' statement  */
#line 623 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2479 "basilisk.c"
    break;

  case 294: /* for_declaration_statement: for_scope '(' declaration expression_statement ')' statement  */
#line 629 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2485 "basilisk.c"
    break;

  case 295: /* for_declaration_statement: for_scope '(' declaration expression_statement expression ')' statement  */
#line 631 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2491 "basilisk.c"
    break;

  case 308: /* external_declaration: error compound_statement  */
#line 650 "basilisk.yacc"
                                                { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2497 "basilisk.c"
    break;

  case 309: /* function_declaration: declaration_specifiers declarator  */
#line 654 "basilisk.yacc"
                                            { ast_push_function_definition (parse->stack, yyvsp[0]);  }
#line 2503 "basilisk.c"
    break;

  case 310: /* function_definition: function_declaration declaration_list compound_statement  */
#line 659 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-2]->child[1]); }
#line 2509 "basilisk.c"
    break;

  case 311: /* function_definition: function_declaration compound_statement  */
#line 661 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-1]->child[1]); }
#line 2515 "basilisk.c"
    break;

  case 336: /* forin_declaration_statement: for_scope '(' declaration_specifiers declarator IN forin_arguments ')' statement  */
#line 726 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-7]); }
#line 2521 "basilisk.c"
    break;

  case 337: /* forin_statement: for_scope '(' expression IN forin_arguments ')' statement  */
#line 731 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2527 "basilisk.c"
    break;

  case 352: /* root: translation_unit  */
#line 773 "basilisk.yacc"
                           {
	  yyval = root;
	  yyval->sym = yyr1[yyn];
	  yyval->child = allocate ((Allocator *)parse->alloc, 2*sizeof(Ast *));
	  yyval->child[0] = yyvsp[0];
	  yyvsp[0]->parent = yyval;
	  yyval->child[1] = NULL;
        }
#line 2540 "basilisk.c"
    break;


#line 2544 "basilisk.c"

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

#line 783 "basilisk.yacc"


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
