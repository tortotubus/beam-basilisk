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
  YYSYMBOL_for_declaration_statement = 188, /* for_declaration_statement  */
  YYSYMBOL_jump_statement = 189,           /* jump_statement  */
  YYSYMBOL_external_declaration = 190,     /* external_declaration  */
  YYSYMBOL_function_definition = 191,      /* function_definition  */
  YYSYMBOL_declaration_list = 192,         /* declaration_list  */
  YYSYMBOL_basilisk_statements = 193,      /* basilisk_statements  */
  YYSYMBOL_foreach_statement = 194,        /* foreach_statement  */
  YYSYMBOL_foreach_parameters = 195,       /* foreach_parameters  */
  YYSYMBOL_foreach_parameter = 196,        /* foreach_parameter  */
  YYSYMBOL_reduction = 197,                /* reduction  */
  YYSYMBOL_reduction_operator = 198,       /* reduction_operator  */
  YYSYMBOL_foreach_inner_statement = 199,  /* foreach_inner_statement  */
  YYSYMBOL_foreach_dimension_statement = 200, /* foreach_dimension_statement  */
  YYSYMBOL_forin_declaration_statement = 201, /* forin_declaration_statement  */
  YYSYMBOL_forin_statement = 202,          /* forin_statement  */
  YYSYMBOL_field_list = 203,               /* field_list  */
  YYSYMBOL_field_item_list = 204,          /* field_item_list  */
  YYSYMBOL_event_definition = 205,         /* event_definition  */
  YYSYMBOL_event_parameter = 206,          /* event_parameter  */
  YYSYMBOL_event_parameters = 207,         /* event_parameters  */
  YYSYMBOL_boundary_definition = 208,      /* boundary_definition  */
  YYSYMBOL_external_foreach_dimension = 209, /* external_foreach_dimension  */
  YYSYMBOL_attribute = 210,                /* attribute  */
  YYSYMBOL_root = 211                      /* root  */
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
#define YYLAST   3732

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  340
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  604

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
     565,   566,   570,   571,   572,   573,   574,   578,   579,   583,
     584,   585,   586,   587,   591,   592,   593,   594,   595,   596,
     597,   601,   602,   606,   607,   613,   614,   615,   616,   617,
     625,   626,   630,   631,   635,   636,   640,   644,   645,   649,
     650,   654,   655,   659,   663,   667,   668,   672,   673,   677,
     681,   682,   683,   687,   688,   689,   693,   697,   698,   702,
     706
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
  "for_declaration_statement", "jump_statement", "external_declaration",
  "function_definition", "declaration_list", "basilisk_statements",
  "foreach_statement", "foreach_parameters", "foreach_parameter",
  "reduction", "reduction_operator", "foreach_inner_statement",
  "foreach_dimension_statement", "forin_declaration_statement",
  "forin_statement", "field_list", "field_item_list", "event_definition",
  "event_parameter", "event_parameters", "boundary_definition",
  "external_foreach_dimension", "attribute", "root", YY_NULLPTR
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

#define YYPACT_NINF (-460)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-341)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1182,   -33,  -460,  -460,  -460,  -460,  -460,  2749,  2846,  2846,
    1273,  -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,
    -460,  -460,  -460,  -460,  -460,    20,    14,    73,   115,   125,
    -460,   167,  -460,  -460,  -460,  -460,   181,   642,  -460,  -460,
    -460,  -460,  -460,  -460,   885,  -460,  -460,  -460,  -460,   165,
    -460,  -460,   327,  2859,  -460,    99,   132,   251,    56,   255,
      53,   -57,    76,   168,    -1,  -460,   109,  -460,    36,  3536,
    3536,  -460,    92,  -460,  -460,  3536,  3536,  3536,   106,  -460,
    -460,  -460,  -460,  -460,  -460,  -460,   243,   984,  -460,  -460,
     642,  -460,  -460,   642,  -460,  -460,    22,   190,  1475,  3656,
    3656,  2859,  2859,    60,  -460,   202,  -460,   203,  3656,    93,
    3656,   210,   -23,  -460,    22,  -460,  -460,  2159,    22,  2316,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,
    -460,  2329,  -460,  -460,  2859,  2859,  2859,  2859,  2859,  2859,
    2859,  2859,  2859,  2859,  2859,  2859,  2859,  2859,  2859,  2859,
    2859,  2859,  2859,  -460,  -460,    62,   240,   -40,  -460,  3048,
     -41,  -460,   124,  -460,  -460,  -460,  2854,   212,  -460,  -460,
    -460,  3578,   222,  -460,   242,  2859,   257,   253,   275,   276,
     777,   277,    22,   282,   283,  2426,   281,   285,   286,  -460,
    -460,   -55,  -460,    36,   280,  -460,  -460,  -460,  1083,  -460,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,  -460,
    -460,   288,   290,   273,   119,  -460,  -460,    22,  -460,   296,
     297,   299,   300,   301,   305,   308,  3536,  -460,  2859,  -460,
    3164,  1553,   -20,  -460,   -13,  -460,  2439,  -460,  -460,  -460,
    -460,  -460,  -460,    22,   -48,  -460,  -460,   203,  -460,  -460,
    -460,   108,  2081,  -460,  -460,  -460,  -460,  -460,    99,    99,
     132,   132,   251,   251,   251,   251,    56,    56,   255,    53,
     -57,    76,   168,   248,   309,  -460,  -460,  -460,   240,  -460,
      62,  2329,  -460,  -460,  3228,  2993,  1596,   -41,   302,  3338,
    -460,   100,  -460,  3119,  3386,  2859,  -460,   307,   777,  1237,
    1237,  2859,   335,  1378,   314,  -460,  -460,  -460,    94,  2189,
    2469,  2566,  -460,  -460,   293,   777,  -460,  -460,   310,   310,
    2859,  -460,    54,   133,  -460,  -460,  -460,  -460,  3617,   396,
    3536,    62,  -460,  -460,  -460,    46,   317,   321,  -460,   319,
    1916,  -460,   320,   322,  1674,   -13,  3288,  1717,  2081,  -460,
    -460,   135,  -460,  2579,  -460,    22,  2859,  -460,  -460,   157,
    2329,   -47,  -460,  2859,  -460,  -460,  -460,  -460,  -460,  -460,
    -460,   324,  -460,  -460,   326,   211,  1916,  -460,   328,   329,
    1795,  -460,  -460,  -460,  -460,  2859,   172,  -460,   331,   338,
    3434,  -460,   203,   323,  -460,   198,   777,  -460,   345,   346,
     214,   348,   156,  2609,    36,  2609,  -460,  -460,   349,   777,
     203,  2286,  -460,  -460,   777,   218,   777,   227,  -460,  -460,
    -460,  -460,  -460,   161,   350,   232,  -460,   351,   352,  -460,
    3228,  2929,  -460,    50,  -460,  -460,  3488,  -460,   344,  1916,
    -460,  -460,  2859,  -460,   353,  -460,   359,  1916,  -460,   357,
     360,  1838,   163,  -460,    22,  -460,  -460,   361,  -460,  1954,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,    22,   362,  1916,
    -460,  -460,  2859,  -460,   366,   368,  -460,  -460,    66,  2859,
    -460,  -460,  2329,  2859,   777,  2859,  -460,   777,   777,   777,
    2859,  2579,  2706,   375,  2736,    11,  -460,   777,  -460,  -460,
     777,  -460,   777,  -460,  2859,  -460,  3617,  2859,   378,  -460,
    -460,  -460,   370,   373,  -460,  -460,   374,  1916,  -460,  -460,
    2859,  -460,   376,  -460,  2051,  -460,  -460,  -460,  -460,  2329,
    -460,  -460,   379,   382,  -460,  -460,  -460,  -460,  -460,   203,
    -460,  -460,  -460,  -460,   408,  -460,  -460,   235,   390,   777,
     236,  2579,   777,   241,  -460,  -460,   395,  -460,  -460,  -460,
    -460,  -460,  -460,  -460,  -460,  -460,  -460,   392,   393,  -460,
    -460,  -460,  -460,  -460,   777,   403,   777,  -460,   777,   410,
    -460,   777,    22,  -460,  -460,  -460,  -460,  -460,  -460,   777,
    -460,   415,  -460,  -460
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
      79,    81,    83,    85,    87,    89,     0,   295,     0,   110,
     112,   143,     0,   144,   142,   114,   116,   118,     7,   108,
       2,   294,   296,   297,   298,   299,     0,     0,   300,   204,
       0,    47,     7,     0,    44,    45,     0,   171,     0,     0,
       0,     0,     0,     0,    13,     0,   103,    12,   159,   221,
     161,     0,     0,     3,     0,    30,    31,     0,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      92,     0,    57,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   336,   106,     0,   208,     0,   119,   122,
     187,   188,     0,   145,   109,   111,     0,   148,   113,   115,
     117,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
     270,     0,   274,     0,     7,   275,   259,   260,     0,   272,
     261,   262,   263,   286,   264,   265,   305,   306,   307,   308,
     309,     0,     0,   175,     0,   172,    17,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,    10,     0,   158,
       0,     0,   223,   220,   224,   160,     0,     4,     5,     6,
      29,    38,    36,     0,     0,    39,    41,   325,    42,    28,
      34,     0,     0,    90,    91,    60,    61,    62,    64,    65,
      67,    68,    72,    73,    70,    71,    75,    76,    78,    80,
      82,    84,    86,     0,     0,   180,   209,   207,   206,   107,
       0,     0,   303,   302,     0,     0,     0,   186,     0,     0,
     153,     0,   157,     0,     0,     0,   266,     0,     0,     0,
       0,     0,     0,     0,     0,   290,   291,   292,     0,     0,
       0,     0,   277,   278,   122,     0,   271,   273,    48,     0,
       0,   167,     0,     0,   185,   184,    49,   176,     0,     0,
       0,     0,   337,   104,   242,   217,     0,   212,   213,     0,
       0,   226,    52,     0,     0,   222,     0,     0,     0,    58,
     327,     0,    37,     0,    35,     0,     0,   248,   250,     0,
       0,     0,   254,     0,   189,   210,   205,   120,   121,   304,
     301,     0,   201,   218,     0,     0,     0,   190,    52,     0,
       0,   149,   146,   154,   155,     0,     0,   162,   166,     0,
       0,   339,   330,     7,   333,     0,     0,   269,     0,     0,
       0,     0,     0,     0,     0,     0,   289,   293,     0,     0,
     314,     0,   312,   315,     0,     0,     0,     0,   267,   174,
     168,   173,   169,     0,     0,     0,    21,     0,     0,   338,
       0,     0,   215,   223,   216,   243,     0,   225,     0,     0,
     227,   233,     0,   232,     0,   244,     0,     0,   234,    52,
       0,     0,     0,   326,     0,    40,   257,     0,   246,     0,
     249,   253,   255,    88,   200,   199,   202,     0,     0,     0,
     191,   198,     0,   197,    52,     0,   164,   156,     0,     0,
     150,   147,     0,     0,     0,     0,   268,     0,     0,     0,
       0,     0,     0,   119,     0,     0,   310,     0,   313,   319,
       0,   321,     0,   170,     0,    20,     0,     0,     0,   211,
     214,   229,     0,     0,   231,   245,     0,     0,   235,   241,
       0,   240,     0,    32,     0,   328,   256,   247,   252,     0,
     219,   193,     0,     0,   194,   196,   163,   165,   103,   332,
     331,   335,   329,   334,   280,   281,   282,     0,     0,     0,
       0,     0,     0,     0,   318,   317,     0,   311,   320,   322,
      24,    22,    23,   258,   228,   230,   237,     0,     0,   238,
      33,   251,   192,   195,     0,     0,     0,   287,     0,     0,
     284,     0,     0,   236,   239,   279,   283,   324,   288,     0,
     285,     0,   323,   316
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -460,  -460,  -460,    29,  -460,  -460,  -460,  -460,  -460,   -14,
    -460,  -460,  -460,   381,  -460,   141,   420,  -460,   -31,   195,
     209,    16,   205,   354,   356,   363,   355,   358,  -460,   -81,
      21,  -460,   -44,  -108,   -96,   152,  -460,  -279,  -460,   -10,
    -460,  -460,  -169,  -284,   -90,  -460,    28,  -460,   291,  -308,
    -460,   371,  -460,  -460,   -71,  -170,     0,  -111,  -207,  -269,
    -460,    74,  -460,   116,  -109,  -233,  -135,   166,  -453,  -460,
     150,  -159,   117,  -460,     4,  -460,   318,  -294,  -460,  -460,
    -460,  -460,   471,  -223,  -460,  -460,  -460,  -460,   110,  -460,
    -460,  -460,  -460,  -460,  -460,  -459,  -460,  -460,  -162,  -460,
    -460,  -460,  -460,  -460
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    54,    55,   115,    56,   223,    57,    58,   435,   436,
      59,    60,    61,   250,   254,   255,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     116,   141,   201,   229,    77,   203,   167,   168,    79,    80,
      81,    82,   299,   300,   119,   396,   397,    83,   224,   225,
      84,    85,    86,    87,   324,   170,   102,   172,   288,   346,
     347,   348,   385,   437,   349,   244,   368,   369,   370,   371,
     372,    89,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,    90,    91,   294,   215,   216,   421,   422,   423,
     566,   217,   218,   219,   220,   258,   361,    92,   404,   405,
      93,    94,    95,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,   202,   297,   117,   234,    98,   264,   169,   242,   355,
     243,   377,   304,   342,     2,   393,   539,   302,   161,   415,
     393,    76,   302,     2,   431,     2,   384,   228,   239,   322,
     245,   228,   143,   238,   354,   107,    97,   118,   362,     2,
     363,    99,   558,   365,   289,   366,   295,   158,   290,     2,
      99,   296,    99,     2,    88,   287,   117,     2,    97,   117,
     471,   247,   248,   249,   235,     2,    99,   240,    97,     2,
     151,   152,   241,   292,   356,    76,    99,   307,   171,   357,
      99,   539,   177,   257,    99,   261,   301,   456,   182,   390,
     118,   301,    99,   118,   284,     2,    99,   204,   118,   118,
     118,   108,   589,     2,   228,   162,   226,   564,   118,     2,
     118,   106,   202,   265,   266,   267,   393,   439,   283,   502,
     164,   504,    99,   165,   251,   431,    98,     2,   251,   242,
      99,   166,   233,   441,   400,   503,    99,   441,   241,   430,
     302,   166,   241,   449,   302,   302,   236,   157,   256,   165,
     461,   318,    78,   165,    99,   395,   378,   166,   153,   154,
     109,   166,   263,   121,     2,   171,   118,   272,   273,   274,
     275,   118,   171,   293,   124,   125,   126,   376,   417,   479,
     240,   159,   238,   176,   394,   241,   160,   165,   166,   395,
     204,    99,   314,   163,   144,   166,   238,   181,   379,   145,
     146,   364,   110,   171,   331,   323,    78,   332,   204,   301,
     355,   165,   111,   301,   301,   359,   221,   413,   432,   222,
     463,   433,   429,   464,   230,   231,   232,   226,   147,   148,
     398,   174,   175,   501,   443,   470,   444,   178,   179,   180,
     322,   302,   468,   183,   238,   469,   513,    97,   533,   228,
     527,   534,   127,   360,   112,   128,   487,   129,   467,   343,
     488,   402,   353,   149,   150,   117,   117,   410,   113,   412,
     440,   155,   156,   297,   442,   420,   425,   427,    18,    19,
      20,   227,   493,   367,   494,   228,   495,   486,   237,   118,
     171,   238,   473,   118,   118,   383,   246,   476,   380,   477,
     499,   171,   238,   303,   510,   403,   238,   312,   204,   305,
     301,   285,   367,   512,   228,   238,    43,   389,   515,   257,
     516,   585,   588,   238,   238,   204,   306,   591,   118,   238,
     443,   551,   226,   553,   538,   166,   238,   373,   408,   409,
     309,   171,   268,   269,   292,   171,   308,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   550,   270,   271,
     276,   277,   310,   311,   313,   466,   315,   316,   319,   325,
     284,   448,   320,   321,   328,   454,   329,   420,   460,   367,
     330,   547,   334,   335,   256,   336,   337,   391,   341,   338,
     118,   367,   345,   339,   340,   374,   406,   411,   416,   538,
     291,   358,   438,   445,   581,   447,   204,   478,   228,   446,
     474,   485,   475,   450,   171,   451,   323,   398,   120,   204,
     489,   480,   481,   490,   204,   407,   204,   101,   104,   105,
     492,   497,   498,   226,   140,   500,   505,   521,   518,   514,
     517,   171,   428,   171,   293,   525,   524,   345,   549,   402,
     528,   402,   561,   529,   536,   541,   557,   257,   560,   544,
     563,   545,   573,   574,   535,   414,   575,   576,   584,   579,
     522,   120,   582,   523,   120,   583,   586,   540,   526,   120,
     120,   120,   532,   142,   592,   593,   594,   596,   171,   120,
     367,   120,   341,   403,   204,   403,   599,   204,   204,   204,
     542,   603,   571,   543,   465,   565,   118,   204,   345,   259,
     204,   278,   204,   548,   279,   281,   546,   257,   333,   282,
     520,   472,   280,   496,   462,   123,   327,     0,   142,     0,
       0,   508,   142,     0,     0,   570,   506,   286,   572,     0,
       0,   509,     0,   511,     0,     0,     0,   120,   577,     0,
       0,   578,   120,     0,     0,   367,     0,     0,     0,   204,
     367,     0,   204,     0,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,     0,     0,   204,     0,   204,     0,   204,     0,
       0,   204,   601,   345,     0,     0,     0,     0,   345,   204,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
       0,   552,   286,     0,   554,   555,   556,     0,     0,     0,
       0,     0,     0,     0,   567,     0,     0,   568,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,     0,   142,   286,     0,     0,
     120,     0,    10,    11,   120,   120,   587,     0,     0,   590,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,   595,     0,   597,     0,   598,     0,     0,   600,   120,
       0,     0,    37,    38,    39,     0,   602,     0,    43,     0,
      44,   286,     0,     0,     0,   375,     0,     0,   286,    47,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,   375,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,   184,     0,
       2,     3,     4,     5,     6,     7,   142,     8,     9,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,    11,     0,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
     375,     0,     0,     0,     0,     0,     0,     0,   286,     0,
       0,     0,   375,     0,   185,   186,   187,     0,   188,   189,
     190,   191,   192,   193,   194,   195,     0,    37,     0,    39,
     375,     0,     0,     0,     0,    44,     0,   196,   197,   198,
       0,   199,     0,     0,    47,     0,     0,     0,    97,     0,
       0,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,  -340,   122,   120,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,   375,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,     0,     0,    46,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,   184,     0,     2,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,   185,   186,   187,     0,   188,   189,   190,   191,   192,
     193,   194,   195,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,   196,   197,   198,     0,   199,   200,
       0,    47,     0,     0,     0,    97,     0,     0,    48,    49,
      50,    51,    52,    53,   184,     0,     2,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
     185,   186,   187,     0,   188,   189,   190,   191,   192,   193,
     194,   195,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,   196,   197,   198,     0,   199,   326,     0,
      47,     0,     0,     0,    97,     0,     0,    48,    49,    50,
      51,    52,    53,     1,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   114,     0,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,     0,     0,    46,     0,     0,    99,    11,    47,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -204,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -204,  -204,  -204,     0,     0,  -204,     0,  -204,
    -204,     0,     0,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,     0,     0,
       0,     0,   199,     0,     0,    47,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    38,    39,     0,     0,
       0,    43,     0,    44,     0,     0,     2,     3,     4,     5,
       6,     7,    47,     8,     9,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,    99,    11,     0,     0,   350,     0,     0,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,   285,    39,    99,    11,     0,    43,
     386,    44,     0,     0,    18,    19,    20,     0,     0,     0,
      47,     0,     0,     0,     0,     0,   351,    48,   352,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,   285,    39,     0,
       0,     0,    43,     0,    44,     0,     0,     2,     3,     4,
       5,     6,     7,    47,     8,     9,     0,     0,     0,   387,
      48,   388,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,    99,    11,     0,     0,   452,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,   285,    39,    99,    11,     0,
      43,   457,    44,     0,     0,    18,    19,    20,     0,     0,
       0,    47,     0,     0,     0,     0,     0,   453,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,   285,    39,
       0,     0,     0,    43,     0,    44,     0,     0,     2,     3,
       4,     5,     6,     7,    47,     8,     9,     0,     0,     0,
     458,    48,   459,    50,    51,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,    99,    11,     0,     0,   482,
       0,     0,     0,    18,    19,    20,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,   285,    39,    99,    11,
       0,    43,   530,    44,     0,     0,    18,    19,    20,     0,
       0,     0,    47,     0,     0,     0,     0,     0,   483,    48,
     484,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,   285,
      39,     0,     0,     0,    43,     0,    44,     0,     0,     2,
       3,     4,     5,     6,     7,    47,     8,     9,     0,     0,
       0,   531,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,    99,    11,     0,     0,
       0,     0,     0,     0,    18,    19,    20,     2,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,    11,    37,   285,    39,     0,
       0,     0,    43,     0,    44,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,   537,
       0,    47,     0,     0,   365,   262,   366,     0,    48,    49,
      50,    51,    52,    53,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,    11,     0,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,    11,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,   580,     0,    47,     0,
       0,   365,   262,   366,     0,    48,    49,    50,    51,    52,
      53,    37,     0,    39,     0,     0,     0,     0,     0,    44,
       0,     0,     2,     3,     4,     5,     6,     7,    47,     8,
       9,   365,   262,   366,     0,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,     0,    99,
      11,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
      11,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,   252,    47,     0,     0,     0,
     253,     0,     0,    48,    49,    50,    51,    52,    53,    37,
       0,    39,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,   418,     0,     0,   419,    47,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,    11,     0,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,    99,    11,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,    99,
      11,     0,     0,     0,    44,     0,     0,     0,     0,   418,
       0,     0,   507,    47,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,    53,    37,     0,    39,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,    37,
       0,    39,     0,    47,     0,     0,     0,    44,     0,   260,
      48,    49,    50,    51,    52,    53,    47,     0,     0,     0,
     262,     0,     0,    48,    49,    50,    51,    52,    53,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,    99,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
      11,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,    99,
      11,     0,     0,     0,    44,     0,     0,     0,     0,    37,
     317,    39,     0,    47,     0,     0,     0,    44,     0,     0,
      48,    49,    50,    51,    52,    53,    47,     0,     0,     0,
     358,     0,     0,    48,    49,    50,    51,    52,    53,    37,
       0,    39,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,   424,    47,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,    99,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
      11,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,    99,
      11,     0,     0,     0,    44,     0,     0,     0,     0,    37,
       0,    39,   426,    47,     0,     0,     0,    44,     0,     0,
      48,    49,    50,    51,    52,    53,    47,     0,     0,     0,
     253,     0,     0,    48,    49,    50,    51,    52,    53,    37,
       0,    39,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,   199,     0,     0,    47,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,    11,     0,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,    99,    11,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,    99,
      11,     0,     0,     0,    44,     0,     0,     0,     0,     0,
       0,     0,   559,    47,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,    53,    37,     0,    39,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,    37,
       0,    39,   562,    47,     0,     0,     0,    44,     0,     0,
      48,    49,    50,    51,    52,    53,   100,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     2,
       3,     4,     5,     6,     7,   298,     8,     9,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,    99,    11,     0,     0,
       0,     0,     0,     0,   173,     0,     0,     0,     0,    99,
      11,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,     0,     0,    44,    38,     0,     0,    41,    37,
      43,    39,     2,   103,     0,     0,     0,    44,     0,     0,
      48,    49,    50,    51,    52,    53,    47,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    10,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   381,     0,     2,     0,    36,     0,
      38,     0,    40,     0,    42,    43,     0,     0,    45,     0,
       0,     0,     0,     0,     0,   344,   441,     0,     0,     0,
       0,   241,     0,    10,   166,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,     0,    38,     0,    40,     0,    42,    43,
       0,     0,    45,     0,     0,     0,     0,     0,   173,   382,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    38,
     399,    40,    41,    42,    43,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
       0,     0,     0,     0,     0,   291,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,    41,   173,    43,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,    38,     0,    40,     0,    42,
      43,     0,     0,    45,     0,     0,     0,     0,     0,     0,
     344,   240,     0,     0,     0,     0,   241,     0,   173,   166,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    38,
       0,    40,    41,    42,    43,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,    97,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    38,
       0,    40,     0,    42,    43,     0,     0,    45,   173,     0,
       0,     0,     0,     0,   455,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,    41,     0,    43,     0,   173,     0,     0,     0,
       0,     0,     0,   392,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
      41,     0,    43,     0,   173,     0,     0,     0,     0,     0,
       0,   401,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    41,     0,
      43,     0,     0,     0,     0,     0,     0,     0,   173,   491,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    38,
       0,    40,     0,    42,    43,     0,   173,    45,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,    38,   173,    40,
       0,    42,    43,     0,     0,    45,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,     0,    38,
       0,     0,    41,     0,    43,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,   434,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,     0,    38,     0,
       0,     0,     0,    43,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,    43
};

static const yytype_int16 yycheck[] =
{
       0,    97,   172,    47,   112,     1,   141,    78,   119,   242,
     119,   290,   181,   236,     3,   299,   469,   176,    19,   313,
     304,     0,   181,     3,   332,     3,   295,   108,   118,    84,
     120,   112,    63,    88,   241,    35,    91,    47,    86,     3,
      88,    30,   501,    90,    84,    92,    87,   104,    88,     3,
      30,    92,    30,     3,    54,   166,   100,     3,    91,   103,
     107,    84,    85,    86,     4,     3,    30,    87,    91,     3,
      14,    15,    92,   169,    87,    54,    30,   185,    78,    92,
      30,   534,    82,   127,    30,   129,   176,   356,    88,   296,
     100,   181,    30,   103,   165,     3,    30,    97,   108,   109,
     110,    87,   561,     3,   185,   106,   106,    96,   118,     3,
     120,    91,   208,   144,   145,   146,   400,   340,   162,   413,
      84,   415,    30,    87,   124,   433,   122,     3,   128,   240,
      30,    95,   111,    87,   303,   414,    30,    87,    92,    85,
     299,    95,    92,   350,   303,   304,    86,    94,   127,    87,
     357,   195,     0,    87,    30,    89,   291,    95,   102,   103,
      87,    95,   141,    47,     3,   165,   176,   151,   152,   153,
     154,   181,   172,   169,     9,    10,    11,   288,    84,   386,
      87,   105,    88,    91,    84,    92,    18,    87,    95,    89,
     190,    30,   192,    84,    95,    95,    88,    91,   294,   100,
     101,    93,    87,   203,    85,   201,    54,    88,   208,   299,
     443,    87,    87,   303,   304,   246,   100,   313,    85,   103,
      85,    88,   330,    88,   108,   109,   110,   227,    96,    97,
     301,    79,    80,    77,   345,   370,   345,    85,    86,    87,
      84,   400,    85,     0,    88,    88,    85,    91,    85,   330,
     457,    88,    87,   253,    87,    90,    84,    92,   366,   238,
      88,   305,   241,    12,    13,   309,   310,   311,    87,   313,
     341,    16,    17,   443,   345,   319,   320,   321,    38,    39,
      40,    91,    84,   262,    86,   366,    88,   395,    86,   299,
     290,    88,   373,   303,   304,   295,    86,    86,   294,    88,
      86,   301,    88,    91,    86,   305,    88,   190,   308,    87,
     400,    71,   291,    86,   395,    88,    76,   296,    86,   363,
      88,    86,    86,    88,    88,   325,    84,    86,   338,    88,
     441,   493,   332,   495,   469,    95,    88,    89,   309,   310,
      87,   341,   147,   148,   440,   345,    89,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,   492,   149,   150,
     155,   156,    87,    87,    87,   365,    84,    84,    87,    89,
     441,   350,    87,    87,    86,   354,    86,   421,   357,   358,
     107,   489,    86,    86,   363,    86,    86,    85,   236,    88,
     400,   370,   240,    88,    86,    86,    89,    62,    84,   534,
     107,    91,     6,    86,   539,    86,   406,   386,   489,    88,
      86,   390,    86,    93,   414,    93,   412,   488,    47,   419,
      89,    93,    93,    85,   424,   308,   426,     7,     8,     9,
     107,    86,    86,   433,   107,    87,    87,    93,    86,    89,
      89,   441,   325,   443,   440,    86,    93,   295,   492,   493,
      93,   495,    77,    93,    93,    93,   500,   501,   502,    93,
     504,    93,    84,    93,   464,   313,    93,    93,    60,    93,
     449,   100,    93,   452,   103,    93,    86,   477,   457,   108,
     109,   110,   461,    63,    89,    93,    93,    84,   488,   118,
     469,   120,   340,   493,   494,   495,    86,   497,   498,   499,
     479,    86,   516,   482,   363,   505,   516,   507,   356,   128,
     510,   157,   512,   492,   158,   160,   488,   561,   227,   161,
     446,   371,   159,   406,   358,    54,   208,    -1,   108,    -1,
      -1,   421,   112,    -1,    -1,   514,   419,   166,   517,    -1,
      -1,   424,    -1,   426,    -1,    -1,    -1,   176,   527,    -1,
      -1,   530,   181,    -1,    -1,   534,    -1,    -1,    -1,   559,
     539,    -1,   562,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,   584,    -1,   586,    -1,   588,    -1,
      -1,   591,   592,   441,    -1,    -1,    -1,    -1,   446,   599,
      -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,
      -1,   494,   241,    -1,   497,   498,   499,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   507,    -1,    -1,   510,    -1,   512,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,   288,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   296,    -1,    -1,
     299,    -1,    30,    31,   303,   304,   559,    -1,    -1,   562,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,   584,    -1,   586,    -1,   588,    -1,    -1,   591,   338,
      -1,    -1,    70,    71,    72,    -1,   599,    -1,    76,    -1,
      78,   350,    -1,    -1,    -1,   354,    -1,    -1,   357,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     330,    -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   400,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,   366,    10,    11,    -1,
      -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,    -1,
     449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,    -1,
      -1,    -1,   461,    -1,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    72,
     479,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,    -1,
      -1,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,   516,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,   527,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   489,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    -1,    84,    85,
      -1,    87,    -1,    -1,    -1,    91,    -1,    -1,    94,    95,
      96,    97,    98,    99,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      48,    49,    50,    51,    52,    53,    54,    55,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    -1,    -1,    82,    -1,    -1,    30,    31,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    -1,    -1,    94,    -1,    96,
      97,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    78,    -1,    -1,     3,     4,     5,     6,
       7,     8,    87,    10,    11,    -1,    -1,    -1,    -1,    94,
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
      -1,    -1,    -1,    -1,    38,    39,    40,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    87,    -1,    -1,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    87,    -1,
      -1,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,     3,     4,     5,     6,     7,     8,    87,    10,
      11,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      91,    -1,    -1,    94,    95,    96,    97,    98,    99,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    30,
      31,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,    70,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    87,    -1,    -1,    -1,    78,    -1,    93,
      94,    95,    96,    97,    98,    99,    87,    -1,    -1,    -1,
      91,    -1,    -1,    94,    95,    96,    97,    98,    99,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    30,
      31,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    70,
      84,    72,    -1,    87,    -1,    -1,    -1,    78,    -1,    -1,
      94,    95,    96,    97,    98,    99,    87,    -1,    -1,    -1,
      91,    -1,    -1,    94,    95,    96,    97,    98,    99,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    30,
      31,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    70,
      -1,    72,    86,    87,    -1,    -1,    -1,    78,    -1,    -1,
      94,    95,    96,    97,    98,    99,    87,    -1,    -1,    -1,
      91,    -1,    -1,    94,    95,    96,    97,    98,    99,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    30,
      31,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,    70,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    70,
      -1,    72,    86,    87,    -1,    -1,    -1,    78,    -1,    -1,
      94,    95,    96,    97,    98,    99,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,     3,
       4,     5,     6,     7,     8,     1,    10,    11,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    30,
      31,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    71,    -1,    -1,    74,    70,
      76,    72,     3,    87,    -1,    -1,    -1,    78,    -1,    -1,
      94,    95,    96,    97,    98,    99,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,    -1,    69,    -1,
      71,    -1,    73,    -1,    75,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    -1,    30,    95,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    30,    86,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
       1,    73,    74,    75,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,   107,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    30,    76,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    92,    -1,    30,    95,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      -1,    73,    74,    75,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    91,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      -1,    73,    -1,    75,    76,    -1,    -1,    79,    30,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    76,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    76,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    85,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      -1,    73,    -1,    75,    76,    -1,    30,    79,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    30,    73,
      -1,    75,    76,    -1,    -1,    79,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    71,
      -1,    -1,    74,    -1,    76,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    71,    -1,
      -1,    -1,    -1,    76,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    76
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
     190,   191,   205,   208,   209,   210,   211,    91,   182,    30,
      87,   124,   164,    87,   124,   124,    91,   164,    87,    87,
      87,    87,    87,    87,     1,   111,   138,   140,   147,   152,
     159,   171,     1,   190,     9,    10,    11,    87,    90,    92,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
     107,   139,   124,   126,    95,   100,   101,    96,    97,    12,
      13,    14,    15,   102,   103,    16,    17,    94,   104,   105,
      18,    19,   106,    84,    84,    87,    95,   144,   145,   162,
     163,   164,   165,    30,   143,   143,    91,   164,   143,   143,
     143,    91,   164,     0,     1,    57,    58,    59,    61,    62,
      63,    64,    65,    66,    67,    68,    80,    81,    82,    84,
      85,   140,   142,   143,   164,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   193,   194,   199,   200,   201,
     202,   171,   171,   113,   156,   157,   164,    91,   137,   141,
     171,   171,   171,   138,   141,     4,    86,    86,    88,   152,
      87,    92,   165,   172,   173,   152,    86,    84,    85,    86,
     121,   164,    86,    91,   122,   123,   138,   140,   203,   121,
      93,   140,    91,   138,   174,   126,   126,   126,   127,   127,
     128,   128,   129,   129,   129,   129,   130,   130,   131,   132,
     133,   134,   135,   140,   162,    71,   159,   165,   166,    84,
      88,   107,   142,   182,   192,    87,    92,   163,     1,   150,
     151,   152,   179,    91,   150,    87,    84,   141,    89,    87,
      87,    87,   180,    87,   164,    84,    84,    84,   140,    87,
      87,    87,    84,   182,   162,    89,    85,   184,    86,    86,
     107,    85,    88,   156,    86,    86,    86,    86,    88,    88,
      86,   143,   191,   138,    86,   143,   167,   168,   169,   172,
      34,    93,    95,   138,   166,   173,    87,    92,    91,   126,
     164,   204,    86,    88,    93,    90,    92,   138,   174,   175,
     176,   177,   178,    89,    86,   159,   165,   145,   174,   142,
     182,     1,    86,   164,   167,   170,    34,    93,    95,   138,
     166,    85,    85,   151,    84,    89,   153,   154,   162,     1,
     150,    85,   140,   164,   206,   207,    89,   180,   111,   111,
     140,    62,   140,   142,   143,   185,    84,    84,    83,    86,
     140,   195,   196,   197,    86,   140,    86,   140,   180,   141,
      85,   157,    85,    88,    58,   116,   117,   171,     6,   191,
     162,    87,   162,   165,   172,    86,    88,    86,   138,   166,
      93,    93,    34,    93,   138,    86,   167,    34,    93,    95,
     138,   166,   175,    85,    88,   123,   164,   141,    85,    88,
     174,   107,   178,   137,    86,    86,    86,    88,   138,   166,
      93,    93,    34,    93,    95,   138,   141,    84,    88,    89,
      85,    85,   107,    84,    86,    88,   180,    86,    86,    86,
      87,    77,   185,   145,   185,    87,   180,    86,   196,   180,
      86,   180,    86,    85,    89,    86,    88,    89,    86,    56,
     169,    93,   138,   138,    93,    86,   138,   166,    93,    93,
      34,    93,   138,    85,    88,   164,    93,    85,   174,   176,
     164,    93,   138,   138,    93,    93,   154,   141,   138,   140,
     174,   206,   180,   206,   180,   180,   180,   140,   203,    86,
     140,    77,    86,   140,    96,   164,   198,   180,   180,   180,
     138,   117,   138,    84,    93,    93,    93,   138,   138,    93,
      85,   174,    93,    93,    60,    86,    86,   180,    86,   203,
     180,    86,    89,    93,    93,   180,    84,   180,   180,    86,
     180,   164,   180,    86
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
     186,   186,   187,   187,   187,   187,   187,   188,   188,   189,
     189,   189,   189,   189,   190,   190,   190,   190,   190,   190,
     190,   191,   191,   192,   192,   193,   193,   193,   193,   193,
     194,   194,   195,   195,   196,   196,   197,   198,   198,   199,
     199,   200,   200,   201,   202,   203,   203,   204,   204,   205,
     206,   206,   206,   207,   207,   207,   208,   209,   209,   210,
     211
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
       5,     5,     5,     7,     6,     7,     1,     6,     7,     3,
       2,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     1,     2,     1,     1,     1,     1,     1,
       4,     5,     1,     2,     1,     1,     6,     1,     1,     4,
       5,     4,     5,     8,     7,     1,     3,     1,     3,     6,
       1,     3,     3,     1,     3,     3,     2,     4,     5,     4,
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
#line 2402 "basilisk.c"
    break;

  case 5: /* translation_unit: translation_unit error '}'  */
#line 53 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2408 "basilisk.c"
    break;

  case 6: /* translation_unit: translation_unit error ')'  */
#line 54 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2414 "basilisk.c"
    break;

  case 13: /* expression_error: error  */
#line 67 "basilisk.yacc"
                        { yyvsp[0]->sym = YYSYMBOL_YYerror; }
#line 2420 "basilisk.c"
    break;

  case 107: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 257 "basilisk.yacc"
                                                          {
	  type_definition ((Allocator *)parse->data, yyval);
        }
#line 2428 "basilisk.c"
    break;

  case 149: /* struct_or_union_specifier: struct_or_union '{' error '}'  */
#line 319 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2434 "basilisk.c"
    break;

  case 150: /* struct_or_union_specifier: struct_or_union generic_identifier '{' error '}'  */
#line 320 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2440 "basilisk.c"
    break;

  case 200: /* direct_declarator: direct_declarator '(' error ')'  */
#line 415 "basilisk.yacc"
                                             { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2446 "basilisk.c"
    break;

  case 266: /* statement: error ';'  */
#line 533 "basilisk.yacc"
                     { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2452 "basilisk.c"
    break;

  case 300: /* external_declaration: error compound_statement  */
#line 597 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2458 "basilisk.c"
    break;

  case 340: /* root: translation_unit  */
#line 706 "basilisk.yacc"
                           {
	  yyval = *root = allocate ((Allocator *)parse->data, sizeof(AstRoot));
	  memset (yyval, 0, sizeof(AstRoot));
	  yyval->sym = yyr1[yyn];
	  yyval->child = allocate ((Allocator *)parse->data, 2*sizeof(Ast *));
	  yyval->child[0] = yyvsp[0];
	  yyval->child[1] = NULL;
        }
#line 2471 "basilisk.c"
    break;


#line 2475 "basilisk.c"

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

#line 716 "basilisk.yacc"


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
  if (n) {
    const char * i = copy_strings (buffer, n, code - buffer);
    n = recopy_ast (n);
    const char * end = i; while (*end != '\0') end++;
    AstRoot * root = ast_root (n);
    root->after = copy_range (i, end, code - buffer);
    root->file = parse.file;
    root->nf = parse.nf;
  }
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
