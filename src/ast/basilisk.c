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
#line 6 "basilisk.yacc"

#include <string.h>
#include <assert.h>
#include <stdlib.h>
  
#include "parser.h"

static Ast * ast_reduce (Allocator * alloc, int sym, Ast ** children, int n);
#define DEFAULT_ACTION(yyn)					\
  yyval = ast_reduce ((Allocator *)parse->data, yyr1[yyn], yyvsp, yyr2[yyn])
static int yyparse (AstRoot * parse, Ast ** root);


#line 85 "basilisk.c"

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
  YYSYMBOL_array_access = 119,             /* array_access  */
  YYSYMBOL_function_call = 120,            /* function_call  */
  YYSYMBOL_member_identifier = 121,        /* member_identifier  */
  YYSYMBOL_argument_expression_list = 122, /* argument_expression_list  */
  YYSYMBOL_argument_expression_list_item = 123, /* argument_expression_list_item  */
  YYSYMBOL_unary_expression = 124,         /* unary_expression  */
  YYSYMBOL_unary_operator = 125,           /* unary_operator  */
  YYSYMBOL_cast_expression = 126,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 127, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 128,      /* additive_expression  */
  YYSYMBOL_shift_expression = 129,         /* shift_expression  */
  YYSYMBOL_relational_expression = 130,    /* relational_expression  */
  YYSYMBOL_equality_expression = 131,      /* equality_expression  */
  YYSYMBOL_and_expression = 132,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 133,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 134,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 135,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 136,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 137,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 138,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 139,      /* assignment_operator  */
  YYSYMBOL_expression = 140,               /* expression  */
  YYSYMBOL_constant_expression = 141,      /* constant_expression  */
  YYSYMBOL_declaration = 142,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 143,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 144,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 145,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 146,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 147,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 148, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 149,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 150,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 151,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 152, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 153,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 154,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 155,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 156,          /* enumerator_list  */
  YYSYMBOL_enumerator = 157,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 158,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 159,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 160,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 161,      /* alignment_specifier  */
  YYSYMBOL_declarator = 162,               /* declarator  */
  YYSYMBOL_direct_declarator = 163,        /* direct_declarator  */
  YYSYMBOL_generic_identifier = 164,       /* generic_identifier  */
  YYSYMBOL_pointer = 165,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 166,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 167,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 168,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 169,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 170,          /* identifier_list  */
  YYSYMBOL_type_name = 171,                /* type_name  */
  YYSYMBOL_abstract_declarator = 172,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 173, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 174,              /* initializer  */
  YYSYMBOL_initializer_list = 175,         /* initializer_list  */
  YYSYMBOL_designation = 176,              /* designation  */
  YYSYMBOL_designator_list = 177,          /* designator_list  */
  YYSYMBOL_designator = 178,               /* designator  */
  YYSYMBOL_static_assert_declaration = 179, /* static_assert_declaration  */
  YYSYMBOL_statement = 180,                /* statement  */
  YYSYMBOL_labeled_statement = 181,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 182,       /* compound_statement  */
  YYSYMBOL_block_item_list = 183,          /* block_item_list  */
  YYSYMBOL_block_item = 184,               /* block_item  */
  YYSYMBOL_expression_statement = 185,     /* expression_statement  */
  YYSYMBOL_selection_statement = 186,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 187,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 188,           /* jump_statement  */
  YYSYMBOL_external_declaration = 189,     /* external_declaration  */
  YYSYMBOL_function_definition = 190,      /* function_definition  */
  YYSYMBOL_declaration_list = 191,         /* declaration_list  */
  YYSYMBOL_basilisk_statements = 192,      /* basilisk_statements  */
  YYSYMBOL_foreach_statement = 193,        /* foreach_statement  */
  YYSYMBOL_foreach_parameters = 194,       /* foreach_parameters  */
  YYSYMBOL_foreach_parameter = 195,        /* foreach_parameter  */
  YYSYMBOL_reduction = 196,                /* reduction  */
  YYSYMBOL_reduction_operator = 197,       /* reduction_operator  */
  YYSYMBOL_foreach_inner_statement = 198,  /* foreach_inner_statement  */
  YYSYMBOL_foreach_dimension_statement = 199, /* foreach_dimension_statement  */
  YYSYMBOL_forin_statement = 200,          /* forin_statement  */
  YYSYMBOL_field_list = 201,               /* field_list  */
  YYSYMBOL_field_item_list = 202,          /* field_item_list  */
  YYSYMBOL_event_definition = 203,         /* event_definition  */
  YYSYMBOL_event_parameter = 204,          /* event_parameter  */
  YYSYMBOL_event_parameters = 205,         /* event_parameters  */
  YYSYMBOL_boundary_definition = 206,      /* boundary_definition  */
  YYSYMBOL_external_foreach_dimension = 207, /* external_foreach_dimension  */
  YYSYMBOL_attribute = 208,                /* attribute  */
  YYSYMBOL_root = 209                      /* root  */
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
#define YYFINAL  183
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3785

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  102
/* YYNRULES -- Number of rules.  */
#define YYNRULES  338
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  602

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
       0,    50,    50,    51,    52,    53,    54,    58,    59,    60,
      61,    62,    66,    67,    71,    72,    73,    77,    81,    82,
      86,    90,    91,    95,    96,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   112,   113,   117,   118,   122,   126,
     127,   131,   132,   136,   137,   138,   139,   140,   141,   142,
     143,   147,   148,   149,   150,   151,   152,   156,   157,   163,
     164,   165,   166,   170,   171,   172,   176,   177,   178,   182,
     183,   184,   185,   186,   190,   191,   192,   196,   197,   201,
     202,   206,   207,   211,   212,   216,   217,   221,   222,   226,
     227,   229,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   247,   248,   252,   256,   257,   260,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   277,
     278,   282,   283,   287,   288,   289,   290,   291,   292,   293,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   316,   317,   318,   319,
     320,   324,   325,   329,   330,   334,   335,   336,   340,   341,
     342,   343,   347,   348,   352,   353,   354,   358,   359,   360,
     361,   362,   366,   367,   371,   372,   376,   380,   381,   382,
     383,   384,   388,   389,   393,   394,   398,   399,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   421,   422,   426,   427,   428,   429,   433,
     434,   439,   440,   444,   445,   449,   450,   451,   455,   456,
     460,   461,   465,   466,   467,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   495,   496,   497,   501,
     502,   503,   504,   508,   512,   513,   517,   518,   522,   526,
     527,   528,   529,   530,   531,   532,   533,   537,   538,   539,
     543,   544,   548,   549,   553,   554,   558,   559,   560,   564,
     565,   566,   570,   571,   572,   573,   574,   575,   579,   580,
     581,   582,   583,   587,   588,   589,   590,   591,   592,   593,
     597,   598,   602,   603,   609,   610,   611,   612,   620,   621,
     625,   626,   630,   631,   635,   639,   640,   644,   645,   649,
     650,   654,   655,   659,   660,   664,   665,   669,   673,   674,
     675,   679,   680,   681,   685,   689,   690,   694,   698
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
  "array_access", "function_call", "member_identifier",
  "argument_expression_list", "argument_expression_list_item",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator",
  "generic_identifier", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "external_declaration", "function_definition",
  "declaration_list", "basilisk_statements", "foreach_statement",
  "foreach_parameters", "foreach_parameter", "reduction",
  "reduction_operator", "foreach_inner_statement",
  "foreach_dimension_statement", "forin_statement", "field_list",
  "field_item_list", "event_definition", "event_parameter",
  "event_parameters", "boundary_definition", "external_foreach_dimension",
  "attribute", "root", YY_NULLPTR
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

#define YYPACT_NINF (-434)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-339)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1072,   -64,  -434,  -434,  -434,  -434,  -434,  2738,  2835,  2835,
    1262,  -434,  -434,  -434,  -434,  -434,  -434,  -434,  -434,  -434,
    -434,  -434,  -434,  -434,  -434,  -434,  -434,  -434,  -434,  -434,
    -434,  -434,  -434,  -434,  -434,    10,   -38,   -16,    23,    36,
    -434,    75,  -434,  -434,  -434,  -434,    92,  1171,  -434,  -434,
    -434,  -434,  -434,  -434,   747,  -434,  -434,  -434,  -434,   157,
    -434,  -434,   292,  2848,  -434,    63,   163,   257,    46,   293,
      93,    96,   108,   220,   -11,  -434,   161,  -434,    91,  3589,
    3589,  -434,    42,  -434,  -434,  3589,  3589,  3589,    45,  -434,
    -434,  -434,  -434,  -434,  -434,  -434,   252,   874,  -434,  -434,
    1171,  -434,  -434,  1171,  -434,  -434,    39,   173,  1464,  3709,
    3709,  2848,  2848,    32,  -434,   193,  -434,   199,  3709,   -48,
    3709,   209,   170,  -434,    39,  -434,  -434,  2148,    39,  2305,
    -434,  -434,  -434,  -434,  -434,  -434,  -434,  -434,  -434,  -434,
    -434,  2318,  -434,  -434,  2848,  2848,  2848,  2848,  2848,  2848,
    2848,  2848,  2848,  2848,  2848,  2848,  2848,  2848,  2848,  2848,
    2848,  2848,  2848,  -434,  -434,   207,   337,   -47,  -434,  3101,
     -49,  -434,     2,  -434,  -434,  -434,  2843,   233,  -434,  -434,
    -434,  3631,   251,  -434,   263,  2848,   260,   270,   279,   281,
     637,   291,    39,   298,   301,  2415,   299,   302,   303,  -434,
    -434,   132,  -434,    91,   307,  -434,  -434,  -434,   973,  -434,
    -434,  -434,  -434,  -434,  -434,  -434,  -434,  -434,  -434,   305,
     306,   290,    67,  -434,  -434,    39,  -434,   314,   315,   316,
     319,   300,   324,   320,  3589,  -434,  2848,  -434,  3217,  1542,
     -35,  -434,   -25,  -434,  2428,  -434,  -434,  -434,  -434,  -434,
    -434,    39,    -1,  -434,  -434,   199,  -434,  -434,  -434,     3,
    2070,  -434,  -434,  -434,  -434,  -434,    63,    63,   163,   163,
     257,   257,   257,   257,    46,    46,   293,    93,    96,   108,
     220,   253,   321,  -434,  -434,  -434,   337,  -434,   207,  2318,
    -434,  -434,  3281,  3046,  1585,   -49,   334,  3391,  -434,   196,
    -434,  3172,  3439,  2848,  -434,   331,   637,  1226,  1226,  2848,
     361,  1367,   341,  -434,  -434,  -434,    97,  2178,  2458,  2555,
    -434,  -434,   322,   637,  -434,  -434,   339,   339,  2848,  -434,
      20,    88,  -434,  -434,  -434,  -434,  3670,   428,  3589,   207,
    -434,  -434,  -434,   194,   349,   348,  -434,   351,  1905,  -434,
     347,   354,  1663,   -25,  3341,  1706,  2070,  -434,  -434,   133,
    -434,  2568,  -434,    39,  2848,  -434,  -434,   158,  2318,   -37,
    -434,  2848,  -434,  -434,  -434,  -434,  -434,  -434,  -434,   358,
    -434,  -434,   362,    59,  1905,  -434,   357,   359,  1784,  -434,
    -434,  -434,  -434,  2848,   146,  -434,   364,   369,  3487,  -434,
     199,   350,  -434,    -7,   637,  -434,   370,   373,   119,   368,
    2982,   100,  2598,  2598,  -434,  -434,   374,   637,   199,  2275,
    -434,  -434,   637,   210,   637,   219,  -434,  -434,  -434,  -434,
    -434,    28,   371,   239,  -434,   375,   377,  -434,  3281,  2918,
    -434,   127,  -434,  -434,  3541,  -434,   372,  1905,  -434,  -434,
    2848,  -434,   376,  -434,   380,  1905,  -434,   378,   383,  1827,
     180,  -434,    39,  -434,  -434,   384,  -434,  1943,  -434,  -434,
    -434,  -434,  -434,  -434,  -434,    39,   386,  1905,  -434,  -434,
    2848,  -434,   387,   389,  -434,  -434,   109,  2848,  -434,  -434,
    2318,  2848,   637,  2848,  -434,   637,   637,   637,  2848,   390,
    2568,  2695,  2725,    21,  -434,   637,  -434,  -434,   637,  -434,
     637,  -434,  2848,  -434,  3670,  2848,   399,  -434,  -434,  -434,
     391,   394,  -434,  -434,   395,  1905,  -434,  -434,  2848,  -434,
     396,  -434,  2040,  -434,  -434,  -434,  -434,  2318,  -434,  -434,
     397,   401,  -434,  -434,  -434,  -434,  -434,   199,  -434,  -434,
    -434,  -434,   438,  -434,  -434,   245,  2568,   413,   637,   246,
     637,   249,  -434,  -434,   411,  -434,  -434,  -434,  -434,  -434,
    -434,  -434,  -434,  -434,  -434,   408,   414,  -434,  -434,  -434,
    -434,  -434,   637,   420,   423,   637,  -434,   637,  -434,   637,
      39,  -434,  -434,  -434,  -434,   637,  -434,  -434,  -434,   425,
    -434,  -434
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,   203,    14,    15,    18,    19,     0,     0,     0,
     145,    16,   123,   124,   125,   127,   128,   182,   177,   178,
     179,   139,   131,   132,   133,   134,   137,   138,   135,   136,
     130,   140,   141,   151,   152,     0,     0,     0,   180,     0,
     183,     0,   126,   181,    50,   129,     0,     0,    51,    52,
      53,    54,    55,    56,     0,    25,     8,     9,    11,    43,
      27,    26,    57,     0,    59,    63,    66,    69,    74,    77,
      79,    81,    83,    85,    87,    89,     0,   294,     0,   110,
     112,   143,     0,   144,   142,   114,   116,   118,     7,   108,
       2,   293,   295,   296,   297,   298,     0,     0,   299,   204,
       0,    47,     7,     0,    44,    45,     0,   171,     0,     0,
       0,     0,     0,     0,    13,     0,   103,    12,   159,   221,
     161,     0,     0,     3,     0,    30,    31,     0,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      92,     0,    57,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   334,   106,     0,   208,     0,   119,   122,
     187,   188,     0,   145,   109,   111,     0,   148,   113,   115,
     117,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
     270,     0,   274,     0,     7,   275,   259,   260,     0,   272,
     261,   262,   263,   264,   265,   304,   305,   306,   307,     0,
       0,   175,     0,   172,    17,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,   158,     0,     0,
     223,   220,   224,   160,     0,     4,     5,     6,    29,    38,
      36,     0,     0,    39,    41,   323,    42,    28,    34,     0,
       0,    90,    91,    60,    61,    62,    64,    65,    67,    68,
      72,    73,    70,    71,    75,    76,    78,    80,    82,    84,
      86,     0,     0,   180,   209,   207,   206,   107,     0,     0,
     302,   301,     0,     0,     0,   186,     0,     0,   153,     0,
     157,     0,     0,     0,   266,     0,     0,     0,     0,     0,
       0,     0,     0,   289,   290,   291,     0,     0,     0,     0,
     277,   278,   122,     0,   271,   273,    48,     0,     0,   167,
       0,     0,   185,   184,    49,   176,     0,     0,     0,     0,
     335,   104,   242,   217,     0,   212,   213,     0,     0,   226,
      52,     0,     0,   222,     0,     0,     0,    58,   325,     0,
      37,     0,    35,     0,     0,   248,   250,     0,     0,     0,
     254,     0,   189,   210,   205,   120,   121,   303,   300,     0,
     201,   218,     0,     0,     0,   190,    52,     0,     0,   149,
     146,   154,   155,     0,     0,   162,   166,     0,     0,   337,
     328,     7,   331,     0,     0,   269,     0,     0,     0,     0,
     204,     0,     0,     0,   288,   292,     0,     0,   312,     0,
     310,   313,     0,     0,     0,     0,   267,   174,   168,   173,
     169,     0,     0,     0,    21,     0,     0,   336,     0,     0,
     215,   223,   216,   243,     0,   225,     0,     0,   227,   233,
       0,   232,     0,   244,     0,     0,   234,    52,     0,     0,
       0,   324,     0,    40,   257,     0,   246,     0,   249,   253,
     255,    88,   200,   199,   202,     0,     0,     0,   191,   198,
       0,   197,    52,     0,   164,   156,     0,     0,   150,   147,
       0,     0,     0,     0,   268,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   308,     0,   311,   317,     0,   319,
       0,   170,     0,    20,     0,     0,     0,   211,   214,   229,
       0,     0,   231,   245,     0,     0,   235,   241,     0,   240,
       0,    32,     0,   326,   256,   247,   252,     0,   219,   193,
       0,     0,   194,   196,   163,   165,   103,   330,   329,   333,
     327,   332,   280,   281,   282,     0,     0,     0,     0,     0,
       0,     0,   316,   315,     0,   309,   318,   320,    24,    22,
      23,   258,   228,   230,   237,     0,     0,   238,    33,   251,
     192,   195,     0,     0,     0,     0,   286,     0,   284,     0,
       0,   236,   239,   279,   283,     0,   322,   287,   285,     0,
     321,   314
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -434,  -434,  -434,    38,  -434,  -434,  -434,  -434,  -434,    -8,
    -434,  -434,  -434,   388,  -434,   154,   505,  -434,   -42,   211,
     224,   123,   225,   360,   363,   365,   366,   367,  -434,   -93,
      90,  -434,    53,   -92,   -83,    29,  -434,   230,  -434,    51,
    -434,  -434,  -155,  -269,  -108,  -434,    33,  -434,   295,  -300,
    -434,   -44,  -434,  -434,   -77,  -168,     0,  -103,  -214,  -247,
    -434,    78,  -434,   318,  -110,  -229,  -139,   167,  -433,  -434,
     156,  -159,   179,  -434,     5,  -434,   323,  -293,  -434,  -434,
    -434,   473,  -227,  -434,  -434,  -434,  -434,   110,  -434,  -434,
    -434,  -434,  -434,  -416,  -434,  -434,  -209,  -434,  -434,  -434,
    -434,  -434
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    54,    55,   115,    56,   221,    57,    58,   433,   434,
      59,    60,    61,   248,   252,   253,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     116,   141,   201,   227,    77,   203,   167,   168,    79,    80,
      81,    82,   297,   298,   119,   394,   395,    83,   222,   223,
      84,    85,    86,    87,   282,   170,   102,   172,   286,   344,
     345,   346,   383,   435,   347,   242,   366,   367,   368,   369,
     370,    89,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    90,    91,   292,   214,   215,   419,   420,   421,   564,
     216,   217,   218,   256,   359,    92,   402,   403,    93,    94,
      95,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,   169,   262,   120,   295,     2,    98,   340,   161,   241,
     237,   353,   243,     2,   202,   226,   240,   300,   413,   226,
     232,   143,   300,     2,     2,   352,   302,    97,   391,    78,
     429,     2,    99,   391,   537,   107,   233,   287,   293,   238,
      99,   288,     2,   294,   239,     2,   382,   166,     2,   108,
      99,    99,   238,   363,    88,   364,   120,   239,    99,   120,
     151,   152,   354,   285,   120,   120,   120,   355,   299,    99,
     469,   109,    99,   299,   120,    99,   120,   491,   171,   492,
     388,   493,   177,    78,   557,   360,   290,   361,   182,   165,
      76,   236,   226,   305,     2,   162,   362,   204,   118,   537,
     117,   106,   263,   264,   265,   428,   224,   454,   174,   175,
     110,   437,     2,   511,   178,   179,   180,   562,   234,   501,
     502,    99,   284,   111,   249,   202,   322,    98,   249,   391,
       2,   429,   120,   176,   447,   240,   181,   120,   300,    99,
     584,   459,   300,   300,    76,   474,   398,   475,   153,   154,
     376,   118,   329,   117,   118,   330,   117,    99,   144,   118,
     118,   118,   112,   145,   146,   171,   124,   125,   126,   118,
     477,   118,   171,   430,   291,   164,   431,   500,   165,   113,
     255,   415,   259,   374,   320,   236,   166,   157,   236,   299,
     204,    97,   312,   299,   299,   284,   165,     2,   393,     2,
     158,   231,   357,   171,   166,   497,   321,   236,   204,   377,
       2,   322,   353,   159,   439,   281,   320,   254,   461,   239,
     236,   462,   396,    97,    99,   224,    99,   118,   412,   468,
     485,   261,   118,   442,   486,   226,   427,    99,   160,   300,
     441,   525,   373,   466,   127,   163,   467,   128,   316,   129,
     284,   358,   183,   120,   245,   246,   247,   120,   120,   147,
     148,    97,   438,   339,   225,   531,   440,   343,   532,   149,
     150,   226,   465,   295,   270,   271,   272,   273,   471,   235,
     392,   439,   549,   165,   551,   393,   239,   236,   171,   166,
     299,   166,   120,   381,   165,   244,   508,   378,   236,   171,
     226,   484,   166,   401,   284,   510,   204,   236,   373,   155,
     156,   284,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   343,   204,   301,   513,   341,   514,   536,   351,
     224,   583,   587,   236,   236,   589,   441,   236,   303,   171,
     284,   236,   371,   171,   373,   406,   407,   304,   118,   306,
     365,   548,   118,   118,   120,   290,   400,   307,   266,   267,
     117,   117,   408,   464,   411,   121,   308,   339,   309,   310,
     418,   423,   425,   268,   269,    18,    19,    20,   311,   365,
     274,   275,   313,   343,   387,   314,   317,   118,   336,   318,
     319,   326,   327,   536,   226,   545,   323,   328,   579,   140,
     332,   333,   334,   373,   204,   335,   338,   372,   283,   396,
     499,   284,   337,    43,   255,   373,   321,   204,   219,   389,
     404,   220,   204,   409,   204,   414,   228,   229,   230,   289,
     356,   224,   166,   373,   436,   443,   444,   445,   446,   171,
     448,   171,   452,   291,   472,   458,   365,   449,   473,   118,
     478,   254,   479,   487,   488,   498,   495,   490,   365,   496,
     512,   503,   533,   516,   515,   519,   523,   556,   343,   522,
     120,   526,   418,   343,   476,   538,   527,   534,   483,   539,
     542,   373,   543,   571,   572,   405,   171,   573,   574,   577,
     580,   401,   204,   401,   581,   204,   204,   204,   582,   585,
     590,   591,   426,   563,   594,   204,   569,   592,   204,   595,
     204,   601,   101,   104,   105,   463,   257,   276,   375,   544,
     331,   277,   518,   460,   278,   470,   279,   123,   280,   506,
       0,   325,     0,     0,     0,     0,     0,   520,     0,     0,
     521,     0,     0,   547,   400,   524,   400,     0,     0,   530,
       0,   555,     0,   255,   559,   561,     0,   365,   204,     0,
     204,     0,     0,     0,     0,   118,     0,   540,   142,     0,
     541,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     546,     0,   204,   494,     0,   204,     0,   204,     0,   204,
     599,     0,     0,     0,     0,   204,   504,     0,     0,     0,
       0,   507,   568,   509,     0,   570,     0,     0,     0,   255,
       0,     0,     0,   142,     0,   575,     0,   142,   576,     0,
       0,     0,   365,     0,     0,     0,     0,   365,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,     0,
       2,     3,     4,     5,     6,     7,     0,     8,     9,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,    99,    11,     0,
       0,   550,     0,     0,   552,   553,   554,     0,     0,     0,
       0,     0,     0,     0,   565,     0,     0,   566,     0,   567,
     142,     0,     0,     0,   185,   186,   187,     0,   188,   189,
     190,   191,   192,   193,   194,   195,     0,    37,     0,    39,
       0,     0,     0,     0,     0,    44,     0,   196,   197,   198,
       0,   199,     0,     0,    47,     0,     0,     0,    97,     0,
       0,    48,    49,    50,    51,    52,    53,   586,     0,   588,
       0,     0,     0,     0,     0,     0,     0,  -338,   122,   142,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,   593,     0,     0,   596,     0,   597,     0,   598,     0,
       0,     0,     0,     0,   600,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,     0,     0,    46,
       0,     0,     0,   142,    47,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,     0,   184,   142,     2,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,     0,
       0,     0,     0,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,   185,   186,   187,     0,   188,   189,   190,   191,   192,
     193,   194,   195,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,   196,   197,   198,     0,   199,   200,
       0,    47,     0,     0,     0,    97,     0,     0,    48,    49,
      50,    51,    52,    53,   184,     0,     2,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
     185,   186,   187,     0,   188,   189,   190,   191,   192,   193,
     194,   195,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,   196,   197,   198,     0,   199,   324,     0,
      47,     0,     0,     0,    97,     0,     0,    48,    49,    50,
      51,    52,    53,     1,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,     0,     0,    46,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,   114,     0,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   114,     0,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,    37,    38,    39,     0,     0,     0,    43,     0,    44,
       0,     0,     0,     0,     0,     0,    99,    11,    47,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -204,  -204,  -204,     0,     0,  -204,     0,  -204,  -204,
       0,     0,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   410,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,     0,     0,     0,
       0,   199,     0,     0,    47,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,     2,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,     0,     0,     0,
      43,     0,    44,     0,     0,     2,     3,     4,     5,     6,
       7,    47,     8,     9,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,    99,    11,     0,     0,   348,     0,     0,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,   283,    39,    99,    11,     0,    43,   384,
      44,     0,     0,    18,    19,    20,     0,     0,     0,    47,
       0,     0,     0,     0,     0,   349,    48,   350,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,   283,    39,     0,     0,
       0,    43,     0,    44,     0,     0,     2,     3,     4,     5,
       6,     7,    47,     8,     9,     0,     0,     0,   385,    48,
     386,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,    99,    11,     0,     0,   450,     0,     0,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,   283,    39,    99,    11,     0,    43,
     455,    44,     0,     0,    18,    19,    20,     0,     0,     0,
      47,     0,     0,     0,     0,     0,   451,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,   283,    39,     0,
       0,     0,    43,     0,    44,     0,     0,     2,     3,     4,
       5,     6,     7,    47,     8,     9,     0,     0,     0,   456,
      48,   457,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,    99,    11,     0,     0,   480,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,   283,    39,    99,    11,     0,
      43,   528,    44,     0,     0,    18,    19,    20,     0,     0,
       0,    47,     0,     0,     0,     0,     0,   481,    48,   482,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,   283,    39,
       0,     0,     0,    43,     0,    44,     0,     0,     2,     3,
       4,     5,     6,     7,    47,     8,     9,     0,     0,     0,
     529,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,    99,    11,     0,     0,     0,
       0,     0,     0,    18,    19,    20,     2,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,    11,    37,   283,    39,     0,     0,
       0,    43,     0,    44,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,   535,     0,
      47,     0,     0,   363,   260,   364,     0,    48,    49,    50,
      51,    52,    53,     2,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,    11,     0,     2,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,    11,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,   578,     0,    47,     0,     0,
     363,   260,   364,     0,    48,    49,    50,    51,    52,    53,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,     2,     3,     4,     5,     6,     7,    47,     8,     9,
     363,   260,   364,     0,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,    99,    11,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,    11,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,     0,     0,   250,    47,     0,     0,     0,   251,
       0,     0,    48,    49,    50,    51,    52,    53,    37,     0,
      39,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,   416,     0,     0,   417,    47,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,    11,     0,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,    99,    11,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    39,    99,    11,
       0,     0,     0,    44,     0,     0,     0,     0,   416,     0,
       0,   505,    47,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    37,     0,    39,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,    37,     0,
      39,     0,    47,     0,     0,     0,    44,     0,   258,    48,
      49,    50,    51,    52,    53,    47,     0,     0,     0,   260,
       0,     0,    48,    49,    50,    51,    52,    53,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,    99,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,    11,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    39,    99,    11,
       0,     0,     0,    44,     0,     0,     0,     0,    37,   315,
      39,     0,    47,     0,     0,     0,    44,     0,     0,    48,
      49,    50,    51,    52,    53,    47,     0,     0,     0,   356,
       0,     0,    48,    49,    50,    51,    52,    53,    37,     0,
      39,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,     0,     0,   422,    47,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,    99,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,    11,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    39,    99,    11,
       0,     0,     0,    44,     0,     0,     0,     0,    37,     0,
      39,   424,    47,     0,     0,     0,    44,     0,     0,    48,
      49,    50,    51,    52,    53,    47,     0,     0,     0,   251,
       0,     0,    48,    49,    50,    51,    52,    53,    37,     0,
      39,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,   199,     0,     0,    47,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,    11,     0,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,    99,    11,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    39,    99,    11,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       0,   558,    47,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    37,     0,    39,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,    37,     0,
      39,   560,    47,     0,     0,     0,    44,     0,     0,    48,
      49,    50,    51,    52,    53,   100,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     2,     3,
       4,     5,     6,     7,   296,     8,     9,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,    99,    11,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,    99,    11,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,     0,    44,    38,     0,     0,    41,    37,    43,
      39,     2,   103,     0,     0,     0,    44,     0,     0,    48,
      49,    50,    51,    52,    53,    47,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    10,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,    36,     0,    38,
       0,    40,     0,    42,    43,     0,     0,    45,     0,     0,
       0,     0,     0,     0,   342,   439,     0,     0,     0,     0,
     239,     0,    99,   166,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   379,     0,     2,
       0,  -145,     0,  -145,     0,  -145,     0,  -145,  -145,     0,
       0,  -145,     0,     0,     0,     0,  -145,     0,     0,  -145,
       0,     0,     0,     0,     0,     0,    10,  -145,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,    38,     0,    40,
       0,    42,    43,     0,     0,    45,     0,     0,     0,     0,
       0,   173,   380,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,    38,   397,    40,    41,    42,    43,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,     0,   289,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,    41,   173,    43,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,     0,
      40,     0,    42,    43,     0,     0,    45,     0,     0,     0,
       0,     0,     0,   342,   238,     0,     0,     0,     0,   239,
       0,   173,   166,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,    38,     0,    40,    41,    42,    43,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,    97,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,    38,     0,    40,     0,    42,    43,     0,     0,
      45,   173,     0,     0,     0,     0,     0,   453,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,    41,     0,    43,     0,   173,
       0,     0,     0,     0,     0,     0,   390,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,    41,     0,    43,     0,   173,     0,     0,
       0,     0,     0,     0,   399,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    41,     0,    43,     0,     0,     0,     0,     0,     0,
       0,   173,   489,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   517,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,    38,     0,    40,     0,    42,    43,     0,   173,
      45,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,     0,
      38,   173,    40,     0,    42,    43,     0,     0,    45,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,     0,    38,     0,     0,    41,     0,    43,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
       0,    38,     0,     0,     0,     0,    43,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
       0,    78,   141,    47,   172,     3,     1,   234,    19,   119,
     118,   240,   120,     3,    97,   108,   119,   176,   311,   112,
     112,    63,   181,     3,     3,   239,   181,    91,   297,     0,
     330,     3,    30,   302,   467,    35,     4,    84,    87,    87,
      30,    88,     3,    92,    92,     3,   293,    95,     3,    87,
      30,    30,    87,    90,    54,    92,   100,    92,    30,   103,
      14,    15,    87,   166,   108,   109,   110,    92,   176,    30,
     107,    87,    30,   181,   118,    30,   120,    84,    78,    86,
     294,    88,    82,    54,   500,    86,   169,    88,    88,    87,
       0,    88,   185,   185,     3,   106,    93,    97,    47,   532,
      47,    91,   144,   145,   146,    85,   106,   354,    79,    80,
      87,   338,     3,    85,    85,    86,    87,    96,    86,   412,
     413,    30,   166,    87,   124,   208,   203,   122,   128,   398,
       3,   431,   176,    91,   348,   238,    91,   181,   297,    30,
     556,   355,   301,   302,    54,    86,   301,    88,   102,   103,
     289,   100,    85,   100,   103,    88,   103,    30,    95,   108,
     109,   110,    87,   100,   101,   165,     9,    10,    11,   118,
     384,   120,   172,    85,   169,    84,    88,    77,    87,    87,
     127,    84,   129,   286,    84,    88,    95,    94,    88,   297,
     190,    91,   192,   301,   302,   239,    87,     3,    89,     3,
     104,   111,   244,   203,    95,    86,   201,    88,   208,   292,
       3,   288,   441,   105,    87,   162,    84,   127,    85,    92,
      88,    88,   299,    91,    30,   225,    30,   176,   311,   368,
      84,   141,   181,   343,    88,   328,   328,    30,    18,   398,
     343,   455,   286,    85,    87,    84,    88,    90,   195,    92,
     294,   251,     0,   297,    84,    85,    86,   301,   302,    96,
      97,    91,   339,   234,    91,    85,   343,   238,    88,    12,
      13,   364,   364,   441,   151,   152,   153,   154,   371,    86,
      84,    87,   491,    87,   493,    89,    92,    88,   288,    95,
     398,    95,   336,   293,    87,    86,    86,   292,    88,   299,
     393,   393,    95,   303,   348,    86,   306,    88,   352,    16,
      17,   355,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,   293,   323,    91,    86,   236,    88,   467,   239,
     330,    86,    86,    88,    88,    86,   439,    88,    87,   339,
     384,    88,    89,   343,   388,   307,   308,    84,   297,    89,
     260,   490,   301,   302,   398,   438,   303,    87,   147,   148,
     307,   308,   309,   363,   311,    47,    87,   338,    87,   190,
     317,   318,   319,   149,   150,    38,    39,    40,    87,   289,
     155,   156,    84,   354,   294,    84,    87,   336,    88,    87,
      87,    86,    86,   532,   487,   487,    89,   107,   537,   107,
      86,    86,    86,   447,   404,    86,    86,    86,    71,   486,
     410,   455,    88,    76,   361,   459,   411,   417,   100,    85,
      89,   103,   422,    62,   424,    84,   108,   109,   110,   107,
      91,   431,    95,   477,     6,    86,    88,    86,   348,   439,
      93,   441,   352,   438,    86,   355,   356,    93,    86,   398,
      93,   361,    93,    89,    85,    87,    86,   107,   368,    86,
      89,    87,   462,    86,    89,    93,    86,    77,   439,    93,
     514,    93,   419,   444,   384,   475,    93,    93,   388,    93,
      93,   525,    93,    84,    93,   306,   486,    93,    93,    93,
      93,   491,   492,   493,    93,   495,   496,   497,    60,    86,
      89,    93,   323,   503,    84,   505,   514,    93,   508,    86,
     510,    86,     7,     8,     9,   361,   128,   157,   288,   486,
     225,   158,   444,   356,   159,   369,   160,    54,   161,   419,
      -1,   208,    -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,
     450,    -1,    -1,   490,   491,   455,   493,    -1,    -1,   459,
      -1,   498,    -1,   500,   501,   502,    -1,   467,   558,    -1,
     560,    -1,    -1,    -1,    -1,   514,    -1,   477,    63,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     490,    -1,   582,   404,    -1,   585,    -1,   587,    -1,   589,
     590,    -1,    -1,    -1,    -1,   595,   417,    -1,    -1,    -1,
      -1,   422,   512,   424,    -1,   515,    -1,    -1,    -1,   556,
      -1,    -1,    -1,   108,    -1,   525,    -1,   112,   528,    -1,
      -1,    -1,   532,    -1,    -1,    -1,    -1,   537,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    30,    31,    -1,
      -1,   492,    -1,    -1,   495,   496,   497,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   505,    -1,    -1,   508,    -1,   510,
     185,    -1,    -1,    -1,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,    -1,
      -1,    94,    95,    96,    97,    98,    99,   558,    -1,   560,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,   244,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,   582,    -1,    -1,   585,    -1,   587,    -1,   589,    -1,
      -1,    -1,    -1,    -1,   595,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    -1,    -1,    82,
      -1,    -1,    -1,   328,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   364,
      -1,    -1,    -1,    -1,    -1,     1,   371,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    -1,    84,    85,
      -1,    87,    -1,    -1,    -1,    91,    -1,    -1,    94,    95,
      96,    97,    98,    99,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    -1,    84,    85,    -1,
      87,    -1,    -1,    -1,    91,    -1,    -1,    94,    95,    96,
      97,    98,    99,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    -1,    -1,    82,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    -1,    -1,    94,    -1,    96,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    -1,    78,    -1,    -1,     3,     4,     5,     6,     7,
       8,    87,    10,    11,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    30,    31,    -1,    76,    34,
      78,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    78,    -1,    -1,     3,     4,     5,     6,
       7,     8,    87,    10,    11,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    30,    31,    -1,    76,
      34,    78,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    78,    -1,    -1,     3,     4,     5,
       6,     7,     8,    87,    10,    11,    -1,    -1,    -1,    93,
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
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      87,    -1,    -1,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    87,    -1,    -1,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,     3,     4,     5,     6,     7,     8,    87,    10,    11,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    91,
      -1,    -1,    94,    95,    96,    97,    98,    99,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    30,    31,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    87,    -1,    -1,    -1,    78,    -1,    93,    94,
      95,    96,    97,    98,    99,    87,    -1,    -1,    -1,    91,
      -1,    -1,    94,    95,    96,    97,    98,    99,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    30,    31,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    70,    84,
      72,    -1,    87,    -1,    -1,    -1,    78,    -1,    -1,    94,
      95,    96,    97,    98,    99,    87,    -1,    -1,    -1,    91,
      -1,    -1,    94,    95,    96,    97,    98,    99,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    30,    31,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    70,    -1,
      72,    86,    87,    -1,    -1,    -1,    78,    -1,    -1,    94,
      95,    96,    97,    98,    99,    87,    -1,    -1,    -1,    91,
      -1,    -1,    94,    95,    96,    97,    98,    99,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    30,    31,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    70,    -1,
      72,    86,    87,    -1,    -1,    -1,    78,    -1,    -1,    94,
      95,    96,    97,    98,    99,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,     3,     4,
       5,     6,     7,     8,     1,    10,    11,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    30,    31,
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
      -1,    -1,    -1,    -1,    -1,     3,    -1,    69,    -1,    71,
      -1,    73,    -1,    75,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      92,    -1,    30,    95,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    95,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      -1,    75,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    30,    86,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,     1,    73,    74,    75,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,   107,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    30,    76,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,
      73,    -1,    75,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,
      -1,    30,    95,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    -1,    73,    74,    75,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    91,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    -1,    73,    -1,    75,    76,    -1,    -1,
      79,    30,    -1,    -1,    -1,    -1,    -1,    86,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    76,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    85,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    -1,    73,    -1,    75,    76,    -1,    30,
      79,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    30,    73,    -1,    75,    76,    -1,    -1,    79,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    71,    -1,    -1,    74,    -1,    76,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    71,    -1,    -1,    -1,    -1,    76,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    76
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
     119,   120,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   142,   143,   146,
     147,   148,   149,   155,   158,   159,   160,   161,   164,   179,
     189,   190,   203,   206,   207,   208,   209,    91,   182,    30,
      87,   124,   164,    87,   124,   124,    91,   164,    87,    87,
      87,    87,    87,    87,     1,   111,   138,   140,   147,   152,
     159,   171,     1,   189,     9,    10,    11,    87,    90,    92,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
     107,   139,   124,   126,    95,   100,   101,    96,    97,    12,
      13,    14,    15,   102,   103,    16,    17,    94,   104,   105,
      18,    19,   106,    84,    84,    87,    95,   144,   145,   162,
     163,   164,   165,    30,   143,   143,    91,   164,   143,   143,
     143,    91,   164,     0,     1,    57,    58,    59,    61,    62,
      63,    64,    65,    66,    67,    68,    80,    81,    82,    84,
      85,   140,   142,   143,   164,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   192,   193,   198,   199,   200,   171,
     171,   113,   156,   157,   164,    91,   137,   141,   171,   171,
     171,   138,   141,     4,    86,    86,    88,   152,    87,    92,
     165,   172,   173,   152,    86,    84,    85,    86,   121,   164,
      86,    91,   122,   123,   138,   140,   201,   121,    93,   140,
      91,   138,   174,   126,   126,   126,   127,   127,   128,   128,
     129,   129,   129,   129,   130,   130,   131,   132,   133,   134,
     135,   140,   162,    71,   159,   165,   166,    84,    88,   107,
     142,   182,   191,    87,    92,   163,     1,   150,   151,   152,
     179,    91,   150,    87,    84,   141,    89,    87,    87,    87,
     180,    87,   164,    84,    84,    84,   140,    87,    87,    87,
      84,   182,   162,    89,    85,   184,    86,    86,   107,    85,
      88,   156,    86,    86,    86,    86,    88,    88,    86,   143,
     190,   138,    86,   143,   167,   168,   169,   172,    34,    93,
      95,   138,   166,   173,    87,    92,    91,   126,   164,   202,
      86,    88,    93,    90,    92,   138,   174,   175,   176,   177,
     178,    89,    86,   159,   165,   145,   174,   142,   182,     1,
      86,   164,   167,   170,    34,    93,    95,   138,   166,    85,
      85,   151,    84,    89,   153,   154,   162,     1,   150,    85,
     140,   164,   204,   205,    89,   180,   111,   111,   140,    62,
      30,   140,   142,   185,    84,    84,    83,    86,   140,   194,
     195,   196,    86,   140,    86,   140,   180,   141,    85,   157,
      85,    88,    58,   116,   117,   171,     6,   190,   162,    87,
     162,   165,   172,    86,    88,    86,   138,   166,    93,    93,
      34,    93,   138,    86,   167,    34,    93,    95,   138,   166,
     175,    85,    88,   123,   164,   141,    85,    88,   174,   107,
     178,   137,    86,    86,    86,    88,   138,   166,    93,    93,
      34,    93,    95,   138,   141,    84,    88,    89,    85,    85,
     107,    84,    86,    88,   180,    86,    86,    86,    87,   164,
      77,   185,   185,    87,   180,    86,   195,   180,    86,   180,
      86,    85,    89,    86,    88,    89,    86,    56,   169,    93,
     138,   138,    93,    86,   138,   166,    93,    93,    34,    93,
     138,    85,    88,   164,    93,    85,   174,   176,   164,    93,
     138,   138,    93,    93,   154,   141,   138,   140,   174,   204,
     180,   204,   180,   180,   180,   140,    77,   201,    86,   140,
      86,   140,    96,   164,   197,   180,   180,   180,   138,   117,
     138,    84,    93,    93,    93,   138,   138,    93,    85,   174,
      93,    93,    60,    86,   201,    86,   180,    86,   180,    86,
      89,    93,    93,   180,    84,    86,   180,   180,   180,   164,
     180,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   112,   113,   114,   114,
     115,   116,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   119,   119,   120,   120,   121,   122,
     122,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     124,   125,   125,   125,   125,   125,   125,   126,   126,   127,
     127,   127,   127,   128,   128,   128,   129,   129,   129,   130,
     130,   130,   130,   130,   131,   131,   131,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   138,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   140,   140,   141,   142,   142,   142,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   144,
     144,   145,   145,   146,   146,   146,   146,   146,   146,   146,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   148,   148,   148,   148,
     148,   149,   149,   150,   150,   151,   151,   151,   152,   152,
     152,   152,   153,   153,   154,   154,   154,   155,   155,   155,
     155,   155,   156,   156,   157,   157,   158,   159,   159,   159,
     159,   159,   160,   160,   161,   161,   162,   162,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   164,   164,   165,   165,   165,   165,   166,
     166,   167,   167,   168,   168,   169,   169,   169,   170,   170,
     171,   171,   172,   172,   172,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   174,   174,   174,   175,
     175,   175,   175,   176,   177,   177,   178,   178,   179,   180,
     180,   180,   180,   180,   180,   180,   180,   181,   181,   181,
     182,   182,   183,   183,   184,   184,   185,   185,   185,   186,
     186,   186,   187,   187,   187,   187,   187,   187,   188,   188,
     188,   188,   188,   189,   189,   189,   189,   189,   189,   189,
     190,   190,   191,   191,   192,   192,   192,   192,   193,   193,
     194,   194,   195,   195,   196,   197,   197,   198,   198,   199,
     199,   200,   200,   201,   201,   202,   202,   203,   204,   204,
     204,   205,   205,   205,   206,   207,   207,   208,   209
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       2,     2,     6,     7,     3,     4,     3,     4,     1,     1,
       3,     1,     1,     1,     2,     2,     2,     2,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     2,     4,
       5,     1,     1,     1,     2,     2,     3,     1,     2,     1,
       2,     1,     1,     3,     2,     3,     1,     4,     5,     5,
       6,     2,     1,     3,     3,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     2,     1,     1,     3,
       3,     4,     6,     5,     5,     6,     5,     4,     4,     4,
       4,     3,     4,     1,     1,     3,     2,     2,     1,     1,
       2,     3,     1,     1,     3,     2,     2,     1,     1,     3,
       2,     1,     2,     1,     1,     3,     2,     3,     5,     4,
       5,     4,     3,     3,     3,     4,     6,     5,     5,     6,
       4,     4,     2,     3,     3,     4,     3,     4,     1,     2,
       1,     4,     3,     2,     1,     2,     3,     2,     7,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     3,
       2,     3,     1,     2,     1,     1,     1,     2,     2,     7,
       5,     5,     5,     7,     6,     7,     6,     7,     3,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     2,
       4,     3,     1,     2,     1,     1,     1,     1,     4,     5,
       1,     2,     1,     1,     6,     1,     1,     4,     5,     4,
       5,     8,     7,     1,     3,     1,     3,     6,     1,     3,
       3,     1,     3,     3,     2,     4,     5,     4,     1
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
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, AstRoot * parse, Ast ** root)
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, AstRoot * parse, Ast ** root)
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
                 int yyrule, AstRoot * parse, Ast ** root)
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, AstRoot * parse, Ast ** root)
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
yyparse (AstRoot * parse, Ast ** root)
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
#line 52 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2407 "basilisk.c"
    break;

  case 5: /* translation_unit: translation_unit error '}'  */
#line 53 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2413 "basilisk.c"
    break;

  case 6: /* translation_unit: translation_unit error ')'  */
#line 54 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2419 "basilisk.c"
    break;

  case 13: /* expression_error: error  */
#line 67 "basilisk.yacc"
                        { yyvsp[0]->sym = YYSYMBOL_YYerror; }
#line 2425 "basilisk.c"
    break;

  case 107: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 257 "basilisk.yacc"
                                                          {
	  type_definition ((Allocator *)parse->data, yyval);
        }
#line 2433 "basilisk.c"
    break;

  case 149: /* struct_or_union_specifier: struct_or_union '{' error '}'  */
#line 319 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2439 "basilisk.c"
    break;

  case 150: /* struct_or_union_specifier: struct_or_union generic_identifier '{' error '}'  */
#line 320 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2445 "basilisk.c"
    break;

  case 200: /* direct_declarator: direct_declarator '(' error ')'  */
#line 415 "basilisk.yacc"
                                             { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2451 "basilisk.c"
    break;

  case 266: /* statement: error ';'  */
#line 533 "basilisk.yacc"
                     { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2457 "basilisk.c"
    break;

  case 299: /* external_declaration: error compound_statement  */
#line 593 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2463 "basilisk.c"
    break;

  case 338: /* root: translation_unit  */
#line 698 "basilisk.yacc"
                           {
	  yyval = *root = allocate ((Allocator *)parse->data, sizeof(AstRoot));
	  memset (yyval, 0, sizeof(AstRoot));
	  yyval->sym = yyr1[yyn];
	  yyval->child = allocate ((Allocator *)parse->data, 2*sizeof(Ast *));
	  yyval->child[0] = yyvsp[0];
	  yyval->child[1] = NULL;
        }
#line 2476 "basilisk.c"
    break;


#line 2480 "basilisk.c"

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

#line 708 "basilisk.yacc"


/* Called by yyparse on error.  */
void
yyerror (AstRoot * parse, Ast ** root, char const *s)
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

static Ast * recopy_ast (Ast * n)
{
  AstRoot * r = ast_root (n);
  AstTerminal * t = ast_terminal (n);
  size_t size = r ? sizeof (AstRoot) : t ? sizeof (AstTerminal) : sizeof (Ast);
  Ast * c = malloc (size);
  memcpy (c, n, size);
  if (t) {
    t->before = NULL;
    t->start = NULL;
  }
  else {
    int len = 0;
    for (Ast ** i = n->child; *i; i++, len++);
    c->child = malloc ((len + 1)*sizeof (Ast *));
    c->child[len] = NULL;
    for (Ast ** i = n->child, ** j = c->child; *i; i++, j++) {
      *j = recopy_ast (*i);
      (*j)->parent = c;
    }
  }
  return c;
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
  ast->child = allocate (alloc, (n + 1)*sizeof(Ast *));
  for (int i = 0; i < n; i++) {
    Ast * c = children[i + 1 - n];
    if (c->parent)
      remove_child (c);
    c->parent = ast;
    ast->child[i] = c;
    ast->child[i + 1] = NULL;
  }
  return ast;
}

Ast * ast_parse (const char * code)
{
  AstRoot parse;
  parse.file = malloc (sizeof (char *));
  parse.nf = 1;
  parse.file[0] = strdup ("<basilisk>");
  parse.data = new_allocator();
  extern void lexer_setup (char * buffer, size_t len);
  size_t len = strlen (code) + 1;
  char * buffer = malloc (len + 1);
  memcpy (buffer, code, len);
  buffer[len] = '\0';
  lexer_setup (buffer, len + 1);
  //  yydebug = 1;
  Ast * n = NULL;
  yyparse (&parse, &n);
  assert (n);
  const char * i = copy_strings (buffer, n, code - buffer);
  n = recopy_ast (n);
  const char * end = i; while (*end != '\0') end++;
  AstRoot * root = ast_root (n);
  root->after = copy_range (i, end, code - buffer);
  root->file = parse.file;
  root->nf = parse.nf;
  free (buffer);
  free_allocator (parse.data);
  typedef_cleanup();
  yylex_destroy();
  return n;
}

int token_symbol (int token)
{
  return YYTRANSLATE (token);
}

const char * symbol_name (int sym)
{
  return yytname[sym];
}
