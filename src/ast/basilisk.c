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
#define YYFINAL  191
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3446

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  349
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  629

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
     177,   178,   179,   180,   184,   185,   186,   187,   188,   189,
     193,   194,   200,   201,   202,   203,   207,   208,   209,   213,
     214,   215,   219,   220,   221,   222,   223,   227,   228,   229,
     233,   234,   238,   239,   243,   244,   248,   249,   253,   254,
     258,   259,   263,   264,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   282,   283,   287,   291,   292,
     293,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   310,   311,   315,   316,   320,   321,   322,   323,   324,
     325,   326,   330,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   353,
     354,   355,   356,   357,   361,   362,   366,   367,   371,   372,
     373,   377,   378,   379,   380,   384,   385,   389,   390,   391,
     395,   396,   397,   398,   399,   403,   404,   408,   409,   413,
     417,   418,   419,   420,   421,   425,   426,   430,   431,   435,
     436,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   458,   459,   463,   464,
     465,   466,   470,   471,   475,   476,   480,   481,   485,   486,
     487,   491,   492,   496,   497,   501,   502,   503,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   531,
     535,   536,   537,   541,   542,   543,   544,   548,   552,   553,
     557,   558,   562,   566,   567,   568,   569,   570,   571,   572,
     573,   577,   578,   579,   583,   585,   585,   591,   592,   596,
     597,   601,   602,   606,   607,   608,   612,   616,   617,   618,
     620,   622,   626,   628,   633,   634,   635,   636,   637,   641,
     642,   643,   644,   645,   646,   647,   651,   655,   657,   662,
     663,   670,   671,   672,   673,   674,   675,   679,   683,   684,
     688,   689,   693,   694,   698,   699,   703,   707,   708,   712,
     713,   717,   718,   722,   727,   732,   733,   737,   741,   745,
     746,   747,   751,   752,   753,   757,   761,   762,   766,   770
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

#define YYPACT_NINF (-541)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-350)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     948,    -4,   247,  -541,  -541,  -541,  -541,  2529,  2543,  2543,
     -12,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,
    -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,
    -541,  -541,  -541,  -541,  -541,    12,   -61,    37,    85,    94,
    -541,   106,  -541,  -541,    -2,  -541,   128,  1048,  -541,  -541,
    -541,  -541,  -541,  -541,   648,  -541,  -541,  -541,  -541,   442,
    -541,  -541,   569,  2641,  -541,   -53,   201,   317,    22,   353,
     136,    98,   127,   224,    20,  -541,   176,  -541,   235,  3250,
    3250,  -541,  -541,    56,  -541,  -541,  3250,  3250,  3250,    82,
    -541,  -541,  2942,  -541,  -541,  -541,  -541,  -541,   271,   205,
    -541,  -541,  1048,  -541,  1048,  -541,  -541,  -541,  -541,   281,
     229,  1324,  3370,  3370,  2641,  2641,   405,    46,  -541,  -541,
     220,  -541,   237,  3370,   145,  3370,   248,   232,  -541,    27,
    -541,  -541,  1864,    27,  1994,  -541,  -541,  -541,  -541,  -541,
    -541,  -541,  -541,  -541,  -541,  -541,  2641,  -541,  -541,  2641,
    2641,  2641,  2641,  2641,  2641,  2641,  2641,  2641,  2641,  2641,
    2641,  2641,  2641,  2641,  2641,  2641,  2641,  2641,  -541,  -541,
     199,   446,   152,  -541,   -20,   -11,  -541,    17,  -541,  -541,
    2636,   249,  -541,  -541,  -541,  3292,   259,  -541,   235,  -541,
    2942,  -541,  -541,   848,   274,   287,  -541,   263,   116,  -541,
     281,  -541,   290,   293,   297,   300,   302,   307,   460,   328,
    3250,  -541,  2641,  -541,  2877,  1378,    10,  -541,    49,  -541,
    -541,  2008,  -541,  -541,  -541,  -541,  -541,   325,  -541,  2641,
     -26,  -541,  -541,  -541,  -541,  -541,   -42,  -541,  -541,  -541,
    -541,   -53,   -53,   201,   201,   317,   317,   317,   317,    22,
      22,   353,   136,    98,   127,   224,   311,  -541,   349,  -541,
    -541,  -541,   446,  -541,   199,  2039,  -541,  1424,  -541,   -11,
     355,  3052,  -541,   305,  -541,  2832,  3100,  2641,   352,  -541,
    -541,   363,  2641,   360,   370,   376,   378,  1103,  -541,    27,
     384,   389,  2117,   388,   394,   396,  -541,    -4,   182,  -541,
     401,  -541,  -541,  -541,   748,  -541,  -541,  -541,   404,  -541,
    -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,   403,
     403,  2641,  -541,    55,   215,  -541,  -541,  -541,  -541,  3331,
     489,  -541,  3250,   199,  -541,  -541,  -541,    50,   410,   412,
    -541,   415,  1672,  -541,   411,   413,  1476,    49,  -541,  -541,
    1522,  1848,  -541,  -541,  2039,   226,  -541,  2148,  -541,  2641,
    -541,  -541,  -541,  -541,  -541,  1848,  -541,  -541,  2777,  1672,
    -541,   416,   418,  1574,  -541,  -541,  -541,  -541,  -541,  2641,
     184,  -541,   419,   427,  3148,  -541,   569,  -541,   108,  -541,
    -541,   424,  1103,  1148,  1148,  2641,   454,   434,  -541,  -541,
    -541,   209,  1896,  2226,    63,  -541,  -541,  1103,  -541,  -541,
    1226,  -541,  -541,  -541,  -541,    66,   430,   137,  -541,   436,
     445,  -541,  -541,  2712,  -541,   120,  -541,  -541,  3202,  -541,
    -541,   435,  1672,  -541,  -541,  2641,  -541,   440,  3002,  1672,
    -541,   450,   451,  1620,    27,  2641,  -541,   266,  2039,   153,
    -541,  -541,  -541,  -541,  -541,   270,   459,  -541,  -541,   462,
     165,   464,  1672,  -541,  -541,  2641,  -541,   465,   466,  -541,
    -541,  -541,   291,  2641,  -541,  -541,  2008,  2641,  1103,  2641,
    1103,  -541,   476,   477,   190,   478,  -541,  -541,   479,  1103,
    -541,   253,  -541,   481,  -541,  1103,   275,   483,  1103,  -541,
     -43,  2257,   235,  2257,  -541,  2641,  -541,  3331,  2641,   486,
    -541,  -541,  -541,   474,   480,  -541,  -541,   494,   482,  1672,
    -541,  -541,  2641,  -541,   491,  -541,   492,  -541,  1718,  -541,
    -541,  -541,  -541,  1750,  -541,  -541,  -541,   579,  -541,   506,
     507,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,
    -541,  -541,  1103,  1103,  1103,  2641,    14,  -541,  1103,  2355,
    -541,  -541,  1103,  1103,  -541,  2369,  2400,   -54,  2498,  -541,
    -541,  -541,  -541,  -541,  -541,  -541,  -541,  -541,   508,   509,
    -541,  -541,  -541,  -541,  2039,  -541,  -541,  -541,  -541,   543,
    -541,  -541,   332,  -541,  -541,   515,  -541,  -541,  -541,  -541,
     237,   520,  -541,  1103,   340,  2369,  1103,   343,  -541,  -541,
    -541,  1103,   523,    27,  1103,  -541,  1103,   522,  -541,  1103,
    -541,  -541,   524,  -541,  -541,  1103,  -541,  -541,  -541
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     7,    14,    15,    18,    19,     0,     0,     0,
     148,    16,   125,   126,   127,   129,   130,   185,   180,   181,
     182,   142,   134,   135,   136,   137,   140,   141,   138,   139,
     133,   143,   144,   154,   155,     0,     0,     0,   183,     0,
     186,     0,   128,   184,    52,   131,     0,     0,    54,    55,
      56,    57,    58,    59,     0,    25,     8,     9,    11,    45,
      27,    26,    60,     0,    62,    66,    69,    72,    77,    80,
      82,    84,    86,    88,    90,    92,     0,   300,     0,   112,
     114,   132,   146,     0,   147,   145,   116,   118,   120,     0,
     110,     2,     0,   299,   301,   302,   303,   304,     0,   275,
     305,     7,     0,    49,     0,    46,    47,   206,   207,     0,
     174,     0,     0,     0,     0,     0,     0,     0,    13,   148,
       0,   105,    12,   162,   249,   164,     0,     0,     3,     0,
      30,    31,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    94,     0,    60,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   345,   249,
       0,   211,     0,   121,   306,   249,   191,     0,   111,   113,
       0,   151,   115,   117,   119,     0,     0,   309,     0,   308,
       0,     1,   274,     0,     0,     0,    17,   178,     0,   175,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,   161,     0,     0,   226,   249,   227,   224,
     163,     0,     4,     5,     6,    29,    39,     7,    37,     0,
       0,    40,    42,    44,    28,    35,     0,    93,    63,    64,
      65,    67,    68,    70,    71,    75,    76,    73,    74,    78,
      79,    81,    83,    85,    87,    89,     0,   108,     0,   183,
     212,   210,   209,   249,     0,     0,   249,     0,   190,   249,
       0,     0,   156,     0,   160,     0,     0,     0,   124,   310,
     307,     0,     0,     0,     0,     0,     0,     0,   286,     0,
       0,     0,     0,     0,     0,     0,   281,    26,     0,   279,
       0,   280,   263,   264,     0,   277,   265,   266,     0,   267,
     291,   268,   269,   311,   312,   313,   314,   315,   316,    50,
       0,     0,   170,     0,     0,   188,   187,    51,   179,     0,
       0,    53,     0,     0,   346,   106,   245,   220,     0,   215,
     249,     0,     0,   229,    55,     0,     0,   225,   223,   249,
       0,     0,    32,    61,     0,     0,    38,     0,    36,     0,
     192,   213,   208,   109,   122,     0,   252,   123,     0,     0,
     193,    55,     0,     0,   189,   152,   149,   157,   249,     0,
       0,   165,   169,     0,     0,   348,    60,   342,     0,   339,
     270,     0,     0,     0,     0,     0,     0,     0,   295,   296,
     297,     0,     0,     0,     0,   317,   282,     0,   276,   278,
       0,   177,   171,   176,   172,     0,     0,     0,    21,     0,
       0,   347,   306,     0,   218,   226,   219,   246,     0,   216,
     228,     0,     0,   230,   236,     0,   235,     0,     0,     0,
     237,    55,     0,     0,     0,     0,   254,     0,     0,     0,
     258,    43,   337,    41,    91,     0,     0,   221,   204,     0,
       0,     0,     0,   194,   201,     0,   200,    55,     0,   158,
     167,   249,     0,     0,   153,   150,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,   294,   298,     0,     0,
     322,     0,   320,   323,   324,     0,     0,     0,     0,   271,
       0,     0,     0,     0,   173,     0,    20,     0,     0,     0,
     214,   249,   232,     0,     0,   234,   247,     0,     0,     0,
     238,   244,     0,   243,     0,   261,     0,    33,     0,   253,
     257,   259,   250,     0,   203,   202,   205,     0,   196,     0,
       0,   197,   199,   159,   166,   168,   344,   343,   341,   338,
     340,   272,     0,     0,     0,     0,     0,   318,     0,     0,
     325,   329,     0,     0,   331,     0,     0,   124,     0,    24,
      22,    23,   262,   217,   231,   233,   248,   240,     0,     0,
     241,   260,    34,   256,     0,   251,   222,   195,   198,   284,
     285,   287,     0,   328,   327,     0,   319,   321,   330,   332,
     335,     0,   336,     0,     0,     0,     0,     0,   239,   242,
     255,     0,     0,     0,     0,   292,     0,     0,   289,     0,
     283,   288,     0,   334,   293,     0,   290,   326,   333
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -541,  -541,  -541,    13,  -541,  -541,  -541,  -541,  -541,   102,
     495,   138,  -541,   -65,   484,  -541,   255,     3,  -541,   -50,
     286,   288,   303,   295,   453,   455,   452,   456,   457,  -541,
      95,     2,   233,   -29,   -77,   -84,   195,  -541,   356,  -541,
      74,  -541,  -541,  -541,  -153,  -249,   -92,  -541,   150,  -541,
     425,  -307,  -541,   -41,  -541,  -541,   -75,  -173,     0,  -119,
    -160,  -347,  -541,   196,  -541,   144,  -110,  -209,    44,  -237,
     261,  -353,  -541,   178,  -156,    25,  -541,    18,  -541,  -541,
     326,  -409,  -541,  -541,  -541,  -541,  -541,   575,  -541,  -201,
    -541,  -541,  -541,  -541,  -541,    73,  -541,   140,  -541,  -541,
    -541,  -541,  -541,    29,  -540,  -541,  -541,  -381,  -541,  -541,
    -541,  -541
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    54,    55,   120,    56,   197,    57,    58,   417,   418,
      59,   352,    60,    61,   225,   230,   231,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   121,   146,   298,   202,    77,   337,   172,   173,    79,
      80,    81,    82,    83,   271,   272,   124,   380,   381,    84,
     198,   199,    85,    86,    87,    88,   258,   175,   300,   177,
     262,   338,   339,   340,   460,   419,   341,   218,   219,   446,
     447,   448,   449,   450,    90,   301,   302,   303,   193,   304,
     305,   306,   307,   308,   309,   310,   311,    91,    92,    93,
     190,   312,   313,   314,   491,   492,   493,   494,   595,   315,
     316,   317,   318,   601,   233,    94,   388,   389,    95,    96,
      97,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,   503,    76,   174,   269,   216,   125,   347,   187,   334,
     103,   105,   106,   148,   217,   107,   413,   107,   122,   100,
     107,   459,   377,   605,   274,   602,   111,   377,   367,   274,
     107,   213,   276,   220,   565,   110,   156,   157,   207,   166,
     265,   406,   108,   149,   108,   212,   212,   108,   150,   151,
     209,   358,   261,   107,    89,   346,    76,   108,   196,   107,
     356,   125,   357,   125,  -124,   602,   147,   497,  -124,   196,
     125,   125,   125,   122,   265,   122,   266,  -207,   176,  -207,
     108,   267,   125,   181,   125,   107,   108,    99,   273,   186,
     116,   517,   566,   273,   568,   216,   548,   214,   550,   238,
     239,   240,   215,   109,   170,   236,   279,   373,   413,   299,
     189,   593,   108,   278,   147,   274,   206,   451,   147,   274,
     274,   123,   384,   107,   112,   158,   159,   167,   297,   226,
     260,   421,   210,   226,   232,   377,   349,   423,   256,   125,
     412,   350,   215,   362,   125,   100,   171,   180,   237,   498,
     108,   504,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     176,   353,   113,   185,   260,   584,   123,   176,   123,   273,
     584,   114,   432,   273,   273,   123,   123,   123,   176,   278,
     443,   126,   477,   115,   478,    78,   479,   123,   382,   123,
     355,   322,   107,   163,   323,   391,   201,   423,   280,   462,
     201,   529,   215,   257,   335,   117,   347,   345,   425,   268,
     299,   361,   297,   506,   147,   507,   260,   426,   274,   108,
     125,   162,   214,   164,   125,   125,   263,   215,   107,   297,
     264,   171,   165,   444,   411,   445,   194,   530,   195,    78,
    -206,   536,   269,   537,   123,   203,   204,   205,   422,   123,
     168,   348,   424,   401,   176,   108,   406,   366,   471,   372,
     212,   191,   472,   176,   178,   179,   554,  -206,   212,   519,
     386,   182,   183,   184,   196,   147,   170,   188,   125,   397,
     192,   583,   273,   487,   107,   171,   583,   212,   152,   153,
     414,   260,   470,   415,   425,   361,   211,   363,   107,   260,
     368,   452,   396,   374,   212,   405,   222,   223,   224,   169,
     200,   108,   170,    99,   147,   212,   501,   297,   260,   154,
     155,   171,   361,   176,   221,   108,  -206,   176,  -206,   558,
     275,   559,   297,   125,   431,   123,   277,   610,   437,   123,
     123,   527,   442,   366,   528,   532,   366,   321,   533,   232,
     319,   562,   147,   212,   122,   122,   484,   366,   526,   160,
     161,   461,   387,   320,   496,   468,   325,   201,   170,   326,
     379,   500,   147,   327,   429,   188,   328,   171,   188,   378,
     329,   361,   170,   438,   379,   330,   545,   382,   260,   212,
     359,   171,   361,   123,   490,   333,   482,   483,   101,     3,
       4,     5,     6,   297,   332,   297,   201,   481,   612,   354,
     212,   361,   469,   176,   297,   176,   616,   567,   212,   619,
     297,   212,   499,   297,   513,   360,    11,   514,   241,   242,
     375,   518,   243,   244,   525,   524,   265,   390,   147,   392,
     366,   129,   130,   131,   454,   249,   250,   393,   123,   245,
     246,   247,   248,   394,   539,   395,   125,   540,   398,   129,
     130,   131,   176,   399,   201,   402,   147,    39,   361,   147,
     386,   403,   386,   404,    18,    19,    20,   297,   297,   297,
     407,   410,   104,   297,   351,   420,   427,   297,   297,   188,
     428,   430,   176,   549,   433,   551,   434,   569,   473,   463,
     571,   464,   474,   480,   557,   543,   485,   259,   486,   505,
     561,   578,    43,   564,   579,   508,   592,   333,   512,   132,
     366,   509,   133,   515,   134,   366,   600,   604,   297,   607,
     201,   297,   171,   520,   521,   534,   297,   132,   535,   297,
     133,   297,   134,   331,   297,   573,   594,   538,   541,   542,
     297,   490,   552,   553,   488,   555,   556,   574,   201,   563,
     572,   547,   387,   575,   387,   577,   600,   589,   590,   591,
     576,   123,   586,   596,   580,   581,   366,   598,   599,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   587,
     588,   608,   609,   611,   613,   502,   614,   621,   625,   570,
     627,   208,   453,   622,   546,   251,   253,   234,   252,   476,
     364,   254,   544,   255,   511,   324,   455,   531,   615,   128,
     409,   618,   597,   560,   617,     0,   620,     0,     0,   623,
       0,   624,     0,     0,   626,     0,     0,     0,  -349,   127,
     628,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,     0,     0,
      46,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   281,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,   282,   283,   284,     0,   285,
     286,   287,   288,   289,   290,   291,   292,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,   293,   294,
     295,     0,   296,   408,     0,    47,     0,     0,     0,    99,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   281,
       0,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,   282,   283,   284,     0,   285,
     286,   287,   288,   289,   290,   291,   292,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,   293,   294,
     295,     0,   296,     0,     0,    47,     0,     0,     0,    99,
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
       0,     0,     0,    48,    49,    50,    51,    52,    53,   118,
       0,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,    11,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   281,     0,     2,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,    37,    38,
      39,     0,     0,     0,    43,     0,    44,     0,     0,     0,
       0,     0,     0,   108,    11,    47,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   118,
       0,   101,     3,     4,     5,     6,     7,     0,     8,     9,
     282,   283,   284,     0,   285,   286,   287,   288,   289,   290,
     291,   292,     0,    37,     0,    39,     0,     0,     0,    11,
       0,    44,     0,   293,   294,   295,     0,   296,     0,     0,
      47,     0,     0,     0,    99,     0,     0,     0,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,     0,     0,    44,     0,     0,   101,
       3,     4,     5,     6,     7,    47,     8,     9,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,   119,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,     0,     0,     0,     0,
     296,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,   101,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,    11,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,    37,    38,    39,     0,     0,     0,
      43,     0,    44,     0,     0,     0,     0,     0,     0,    11,
       0,    47,   342,     0,     0,     0,    18,    19,    20,    48,
      49,    50,    51,    52,    53,     0,     0,   101,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,   259,
      39,     0,     0,     0,    43,    11,    44,     0,   369,     0,
       0,     0,    18,    19,    20,    47,     0,     0,     0,     0,
       0,   343,     0,    48,   344,    50,    51,    52,    53,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,    37,   259,    39,     0,     0,     0,
      43,     0,    44,     0,     0,     0,     0,    11,     0,     0,
     435,    47,     0,     0,    18,    19,    20,   370,     0,    48,
     371,    50,    51,    52,    53,   101,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,   259,    39,     0,
       0,     0,    43,    11,    44,     0,   439,     0,     0,     0,
      18,    19,    20,    47,     0,     0,     0,     0,     0,   436,
       0,    48,    49,    50,    51,    52,    53,   101,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,    37,   259,    39,     0,     0,     0,    43,     0,
      44,     0,     0,     0,     0,    11,     0,     0,   465,    47,
       0,     0,    18,    19,    20,   440,     0,    48,   441,    50,
      51,    52,    53,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,   259,    39,     0,     0,     0,
      43,    11,    44,     0,   522,     0,     0,     0,    18,    19,
      20,    47,     0,     0,     0,     0,     0,   466,     0,    48,
     467,    50,    51,    52,    53,   101,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
      37,   259,    39,     0,     0,     0,    43,     0,    44,     0,
       0,     0,     0,    11,     0,     0,     0,    47,     0,     0,
      18,    19,    20,   523,     0,    48,    49,    50,    51,    52,
      53,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,   259,    39,     0,     0,     0,    43,    11,
      44,     0,     0,   101,     3,     4,     5,     6,     7,    47,
       8,     9,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,     0,   582,     0,    47,     0,     0,   444,   365,
     445,     0,     0,    48,    49,    50,    51,    52,    53,     0,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,   585,     0,    47,     0,     0,
     444,   365,   445,     0,     0,    48,    49,    50,    51,    52,
      53,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,   227,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,     0,     0,    44,    11,     0,     0,
       0,     0,     0,     0,    37,    47,    39,     0,   444,   365,
     445,     0,    44,    48,    49,    50,    51,    52,    53,     0,
     228,    47,     0,     0,     0,   229,     0,     0,     0,    48,
      49,    50,    51,    52,    53,     0,    37,     0,    39,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,   488,
       0,     0,   489,    47,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,   101,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,   101,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
      11,     0,    44,     0,     0,     0,     0,     0,    37,     0,
      39,    47,     0,     0,     0,     0,    44,   235,     0,    48,
      49,    50,    51,    52,    53,    47,     0,     0,     0,   351,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    37,
       0,    39,     0,     0,     0,     0,     0,    44,     0,     0,
     101,     3,     4,     5,     6,     7,    47,     8,     9,     0,
     365,     0,     0,     0,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,   227,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,   400,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    37,     0,
      39,     0,     0,     0,     0,     0,    44,     0,     0,   101,
       3,     4,     5,     6,     7,    47,     8,     9,     0,   229,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
     101,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,     0,
       0,     0,   495,    47,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,    37,     0,    39,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,   296,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,   101,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,   101,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,    11,     0,    44,     0,     0,     0,     0,   488,    37,
       0,    39,    47,     0,     0,     0,     0,    44,     0,     0,
      48,    49,    50,    51,    52,    53,    47,     0,     0,     0,
     229,     0,     0,     0,    48,    49,    50,    51,    52,    53,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,     0,   603,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,   101,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,   101,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,    11,     0,    44,     0,     0,     0,
       0,     0,     0,     0,   606,    47,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    37,
       0,    39,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,    37,     0,    39,   102,     0,     0,     0,
       0,    44,     0,     0,    48,    49,    50,    51,    52,    53,
     104,     0,     0,     0,     0,     0,     0,   270,    48,    49,
      50,    51,    52,    53,   101,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119,     0,     0,     0,
       0,     0,    11,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
      41,    37,    43,    39,     0,   107,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    10,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   456,     0,
     457,    36,     0,    38,     0,    40,     0,    42,    43,     0,
       0,    45,     0,     0,     0,     0,     0,     0,   336,   423,
       0,     0,     0,     0,   215,     0,     0,   119,   171,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   383,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,     0,
      40,     0,    42,    43,     0,     0,    45,     0,     0,     0,
       0,     0,   119,   458,     0,     0,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,    41,   119,    43,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,     0,
      40,     0,    42,    43,     0,     0,    45,     0,     0,     0,
       0,     0,     0,   336,   214,     0,     0,     0,     0,   215,
       0,     0,   119,   171,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    38,     0,    40,    41,    42,    43,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,    99,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    38,     0,    40,     0,    42,    43,     0,
       0,    45,   119,     0,     0,     0,     0,     0,   516,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,    41,     0,    43,     0,
     119,     0,     0,     0,     0,     0,     0,   376,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,    41,     0,    43,     0,   119,     0,
       0,     0,     0,     0,     0,   385,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,    41,     0,    43,     0,     0,     0,     0,     0,
       0,     0,   119,   475,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   510,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    38,     0,    40,     0,    42,    43,     0,
     119,    45,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
       0,    38,   119,    40,     0,    42,    43,     0,     0,    45,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,     0,    38,     0,     0,    41,     0,    43,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,   416,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,    38,     0,     0,     0,     0,    43,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
       0,   410,     0,    78,   177,   124,    47,   216,    92,   210,
       7,     8,     9,    63,   124,     3,   323,     3,    47,     1,
       3,   368,   271,    77,   180,   565,    87,   276,   265,   185,
       3,   123,   185,   125,    77,    35,    14,    15,   115,    19,
      94,    84,    30,    96,    30,    88,    88,    30,   101,   102,
       4,    93,   171,     3,    54,   215,    54,    30,     3,     3,
      86,   102,    88,   104,    84,   605,    63,     4,    88,     3,
     111,   112,   113,   102,    94,   104,    87,    89,    78,    91,
      30,    92,   123,    83,   125,     3,    30,    91,   180,    89,
      92,   438,   501,   185,   503,   214,   477,    87,   479,   149,
     150,   151,    92,    91,    87,   134,   190,   267,   415,   193,
      92,    97,    30,   188,   111,   271,   114,   354,   115,   275,
     276,    47,   275,     3,    87,   103,   104,   107,   193,   129,
     171,   332,    86,   133,   132,   384,    87,    87,   167,   180,
      85,    92,    92,   262,   185,   127,    96,    91,   146,    86,
      30,    85,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     170,   221,    87,    91,   215,   528,   102,   177,   104,   271,
     533,    87,   342,   275,   276,   111,   112,   113,   188,   264,
     350,    47,    84,    87,    86,     0,    88,   123,   273,   125,
     229,    85,     3,   105,    88,   282,   111,    87,   190,   369,
     115,   448,    92,   169,   212,    87,   425,   215,   337,   175,
     304,   262,   287,    86,   221,    88,   267,   337,   384,    30,
     271,    95,    87,   106,   275,   276,    84,    92,     3,   304,
      88,    96,    18,    90,   321,    92,   102,    94,   104,    54,
       3,    86,   425,    88,   180,   111,   112,   113,   333,   185,
      84,   217,   337,   292,   264,    30,    84,   265,    84,   267,
      88,     0,    88,   273,    79,    80,    86,    30,    88,   439,
     277,    86,    87,    88,     3,   282,    87,    92,   329,   289,
      85,   528,   384,    84,     3,    96,   533,    88,    97,    98,
      85,   342,   379,    88,   423,   346,    86,   263,     3,   350,
     266,    85,   287,   269,    88,   297,    84,    85,    86,    84,
      91,    30,    87,    91,   321,    88,   410,   392,   369,    12,
      13,    96,   373,   333,    86,    30,    89,   337,    91,    86,
      91,    88,   407,   384,   342,   271,    87,   584,   346,   275,
     276,    85,   350,   351,    88,    85,   354,    94,    88,   357,
      86,    86,   359,    88,   393,   394,   395,   365,   445,    16,
      17,   369,   277,    86,   403,   373,    86,   282,    87,    86,
      89,   410,   379,    86,   340,   190,    86,    96,   193,    84,
      88,   432,    87,   349,    89,    88,   473,   472,   439,    88,
      89,    96,   443,   329,   402,   210,   393,   394,     3,     4,
       5,     6,     7,   478,    86,   480,   321,   392,    86,    94,
      88,   462,   378,   423,   489,   425,    86,   502,    88,    86,
     495,    88,   407,   498,   432,    86,    31,   435,   152,   153,
      85,   439,   154,   155,   444,   443,    94,    84,   445,    89,
     448,     9,    10,    11,   359,   160,   161,    87,   384,   156,
     157,   158,   159,    87,   462,    87,   507,   465,    84,     9,
      10,    11,   472,    84,   379,    87,   473,    72,   519,   476,
     477,    87,   479,    87,    38,    39,    40,   552,   553,   554,
      89,    87,    87,   558,    91,     6,    86,   562,   563,   304,
      88,    86,   502,   478,    93,   480,    93,   505,    89,    93,
     508,    93,    85,    89,   489,   471,    62,    71,    84,    89,
     495,   519,    76,   498,   522,    89,   555,   332,    93,    87,
     528,    86,    90,    93,    92,   533,   565,   566,   603,   568,
     445,   606,    96,    93,    93,    86,   611,    87,    86,   614,
      90,   616,    92,    93,   619,   511,   556,    93,    93,    93,
     625,   559,    86,    86,    83,    87,    87,    93,   473,    86,
      84,   476,   477,    93,   479,    93,   605,   552,   553,   554,
      86,   507,     3,   558,    93,    93,   584,   562,   563,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    93,
      93,    93,    93,    60,    89,   410,    86,    84,    86,   507,
      86,   116,   357,   613,   476,   162,   164,   133,   163,   386,
     264,   165,   472,   166,   428,   200,   365,   449,   603,    54,
     304,   606,   559,   493,   605,    -1,   611,    -1,    -1,   614,
      -1,   616,    -1,    -1,   619,    -1,    -1,    -1,     0,     1,
     625,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    30,    31,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    31,
      -1,    78,    -1,    80,    81,    82,    -1,    84,    -1,    -1,
      87,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,     3,
       4,     5,     6,     7,     8,    87,    10,    11,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    87,    34,    -1,    -1,    -1,    38,    39,    40,    95,
      96,    97,    98,    99,   100,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    31,    78,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    87,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    95,    96,    97,    98,    99,   100,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    -1,    78,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      34,    87,    -1,    -1,    38,    39,    40,    93,    -1,    95,
      96,    97,    98,    99,   100,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    31,    78,    -1,    34,    -1,    -1,    -1,
      38,    39,    40,    87,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    95,    96,    97,    98,    99,   100,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
      78,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    87,
      -1,    -1,    38,    39,    40,    93,    -1,    95,    96,    97,
      98,    99,   100,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    31,    78,    -1,    34,    -1,    -1,    -1,    38,    39,
      40,    87,    -1,    -1,    -1,    -1,    -1,    93,    -1,    95,
      96,    97,    98,    99,   100,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    87,    -1,    -1,
      38,    39,    40,    93,    -1,    95,    96,    97,    98,    99,
     100,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    31,
      78,    -1,    -1,     3,     4,     5,     6,     7,     8,    87,
      10,    11,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    87,    -1,    -1,    90,    91,
      92,    -1,    -1,    95,    96,    97,    98,    99,   100,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    87,    -1,    -1,
      90,    91,    92,    -1,    -1,    95,    96,    97,    98,    99,
     100,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    87,    72,    -1,    90,    91,
      92,    -1,    78,    95,    96,    97,    98,    99,   100,    -1,
      86,    87,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,    -1,    70,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      31,    -1,    78,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    87,    -1,    -1,    -1,    -1,    78,    93,    -1,    95,
      96,    97,    98,    99,   100,    87,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
       3,     4,     5,     6,     7,     8,    87,    10,    11,    -1,
      91,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,     3,
       4,     5,     6,     7,     8,    87,    10,    11,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    31,    -1,    78,    -1,    -1,    -1,    -1,    83,    70,
      -1,    72,    87,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      95,    96,    97,    98,    99,   100,    87,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    31,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    87,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    95,    96,    97,    98,    99,   100,
      87,    -1,    -1,    -1,    -1,    -1,    -1,     1,    95,    96,
      97,    98,    99,   100,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    70,    76,    72,    -1,     3,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,    69,    -1,    71,    -1,    73,    -1,    75,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    30,    96,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,
      73,    -1,    75,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    30,    86,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    30,    96,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    74,    75,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    91,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,    -1,
      -1,    79,    30,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    85,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    76,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    85,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,    -1,
      30,    79,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    30,    73,    -1,    75,    76,    -1,    -1,    79,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    71,    -1,    -1,    74,    -1,    76,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    71,    -1,    -1,    -1,    -1,    76,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    76
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
     166,    87,    87,    87,    87,    87,    92,    87,     1,    30,
     111,   139,   141,   148,   154,   161,   173,     1,   195,     9,
      10,    11,    87,    90,    92,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    94,   140,   125,   127,    96,
     101,   102,    97,    98,    12,    13,    14,    15,   103,   104,
      16,    17,    95,   105,   106,    18,    19,   107,    84,    84,
      87,    96,   145,   146,   164,   165,   166,   167,   144,   144,
      91,   166,   144,   144,   144,    91,   166,   143,   144,   185,
     198,     0,    85,   186,   173,   173,     3,   113,   158,   159,
      91,   138,   142,   173,   173,   173,   139,   142,   118,     4,
      86,    86,    88,   154,    87,    92,   167,   174,   175,   176,
     154,    86,    84,    85,    86,   122,   166,     3,    86,    91,
     123,   124,   139,   212,   122,    93,   141,   139,   127,   127,
     127,   128,   128,   129,   129,   130,   130,   130,   130,   131,
     131,   132,   133,   134,   135,   136,   141,   176,   164,    71,
     161,   167,   168,    84,    88,    94,    87,    92,   176,   165,
       1,   152,   153,   154,   182,    91,   152,    87,   164,   143,
     185,     1,    57,    58,    59,    61,    62,    63,    64,    65,
      66,    67,    68,    80,    81,    82,    84,   121,   141,   143,
     166,   183,   184,   185,   187,   188,   189,   190,   191,   192,
     193,   194,   199,   200,   201,   207,   208,   209,   210,    86,
      86,    94,    85,    88,   158,    86,    86,    86,    86,    88,
      88,    93,    86,   144,   197,   139,    86,   144,   169,   170,
     171,   174,    34,    93,    96,   139,   168,   175,   176,    87,
      92,    91,   119,   127,    94,   141,    86,    88,    93,    89,
      86,   161,   167,   176,   146,    91,   139,   177,   176,    34,
      93,    96,   139,   168,   176,    85,    85,   153,    84,    89,
     155,   156,   164,     1,   152,    85,   125,   138,   214,   215,
      84,   142,    89,    87,    87,    87,   183,   166,    84,    84,
      84,   141,    87,    87,    87,   185,    84,    89,    85,   188,
      87,   142,    85,   159,    85,    88,    58,   116,   117,   173,
       6,   197,   164,    87,   164,   167,   174,    86,    88,   176,
      86,   139,   168,    93,    93,    34,    93,   139,   176,    34,
      93,    96,   139,   168,    90,    92,   177,   178,   179,   180,
     181,   177,    85,   124,   138,   178,     1,     3,    86,   169,
     172,   139,   168,    93,    93,    34,    93,    96,   139,   176,
     142,    84,    88,    89,    85,    85,   140,    84,    86,    88,
      89,   183,   111,   111,   141,    62,    84,    84,    83,    86,
     139,   202,   203,   204,   205,    86,   141,     4,    86,   183,
     141,   143,   144,   189,    85,    89,    86,    88,    89,    86,
      56,   171,    93,   139,   139,    93,    86,   169,   139,   168,
      93,    93,    34,    93,   139,   166,   142,    85,    88,   177,
      94,   181,    85,    88,    86,    86,    86,    88,    93,   139,
     139,    93,    93,   176,   156,   142,   119,   138,   215,   183,
     215,   183,    86,    86,    86,    87,    87,   183,    86,    88,
     205,   183,    86,    86,   183,    77,   189,   164,   189,   139,
     117,   139,    84,   176,    93,    93,    86,    93,   139,   139,
      93,    93,    85,   177,   179,    85,     3,    93,    93,   183,
     183,   183,   141,    97,   166,   206,   183,   203,   183,   183,
     141,   211,   212,    86,   141,    77,    86,   141,    93,    93,
     177,    60,    86,    89,    86,   183,    86,   211,   183,    86,
     183,    84,   166,   183,   183,    86,   183,    86,   183
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   112,   113,   114,   114,
     115,   116,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     123,   123,   124,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   126,   126,   126,   126,
     127,   127,   128,   128,   128,   128,   129,   129,   129,   130,
     130,   130,   131,   131,   131,   131,   131,   132,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   141,   141,   142,   143,   143,
     143,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   145,   145,   146,   146,   147,   147,   147,   147,   147,
     147,   147,   148,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   150,
     150,   150,   150,   150,   151,   151,   152,   152,   153,   153,
     153,   154,   154,   154,   154,   155,   155,   156,   156,   156,
     157,   157,   157,   157,   157,   158,   158,   159,   159,   160,
     161,   161,   161,   161,   161,   162,   162,   163,   163,   164,
     164,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   166,   166,   167,   167,
     167,   167,   168,   168,   169,   169,   170,   170,   171,   171,
     171,   172,   172,   173,   173,   174,   174,   174,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   176,
     177,   177,   177,   178,   178,   178,   178,   179,   180,   180,
     181,   181,   182,   183,   183,   183,   183,   183,   183,   183,
     183,   184,   184,   184,   185,   186,   185,   187,   187,   188,
     188,   189,   189,   190,   190,   190,   191,   192,   192,   192,
     192,   192,   193,   193,   194,   194,   194,   194,   194,   195,
     195,   195,   195,   195,   195,   195,   196,   197,   197,   198,
     198,   199,   199,   199,   199,   199,   199,   200,   201,   201,
     202,   202,   203,   203,   204,   204,   205,   206,   206,   207,
     207,   208,   208,   209,   210,   211,   211,   212,   213,   214,
     214,   214,   215,   215,   215,   216,   217,   217,   218,   219
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       2,     2,     4,     3,     4,     3,     4,     3,     4,     1,
       1,     3,     1,     3,     1,     1,     2,     2,     2,     2,
       4,     4,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     4,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     2,     4,     5,     1,     1,     1,     2,     3,     4,
       1,     2,     1,     2,     1,     1,     3,     2,     3,     1,
       4,     5,     5,     6,     2,     1,     3,     3,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     3,
       2,     1,     3,     3,     4,     6,     5,     5,     6,     5,
       4,     4,     5,     5,     4,     5,     1,     1,     3,     2,
       2,     1,     1,     2,     3,     1,     2,     4,     2,     2,
       1,     1,     3,     3,     2,     2,     1,     1,     3,     2,
       3,     5,     4,     5,     4,     3,     3,     3,     4,     6,
       5,     5,     6,     4,     4,     2,     3,     4,     5,     0,
       3,     4,     1,     2,     1,     4,     3,     2,     1,     2,
       3,     2,     7,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     4,     3,     2,     0,     4,     1,     2,     1,
       1,     1,     2,     7,     5,     5,     1,     5,     7,     6,
       7,     1,     6,     7,     3,     2,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     4,     5,
       1,     3,     1,     1,     1,     2,     6,     1,     1,     4,
       5,     4,     5,     8,     7,     1,     1,     3,     6,     1,
       3,     3,     1,     3,     3,     2,     4,     5,     4,     1
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
#line 2361 "basilisk.c"
    break;

  case 5: /* translation_unit: translation_unit error '}'  */
#line 84 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2367 "basilisk.c"
    break;

  case 6: /* translation_unit: translation_unit error ')'  */
#line 85 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2373 "basilisk.c"
    break;

  case 13: /* expression_error: error  */
#line 98 "basilisk.yacc"
                        { yyvsp[0]->sym = YYSYMBOL_YYerror; }
#line 2379 "basilisk.c"
    break;

  case 108: /* declaration: declaration_specifiers ';' type_not_specified  */
#line 291 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 2385 "basilisk.c"
    break;

  case 109: /* declaration: declaration_specifiers init_declarator_list ';' type_not_specified  */
#line 292 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 2391 "basilisk.c"
    break;

  case 132: /* type_specifier: types  */
#line 330 "basilisk.yacc"
                   { parse->type_already_specified = true; }
#line 2397 "basilisk.c"
    break;

  case 152: /* struct_or_union_specifier: struct_or_union '{' error '}'  */
#line 356 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2403 "basilisk.c"
    break;

  case 153: /* struct_or_union_specifier: struct_or_union generic_identifier '{' error '}'  */
#line 357 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2409 "basilisk.c"
    break;

  case 203: /* direct_declarator: direct_declarator '(' type_not_specified error ')'  */
#line 452 "basilisk.yacc"
                                                                                           { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2415 "basilisk.c"
    break;

  case 249: /* type_not_specified: %empty  */
#line 531 "basilisk.yacc"
           { parse->type_already_specified = false; }
#line 2421 "basilisk.c"
    break;

  case 270: /* statement: error ';'  */
#line 573 "basilisk.yacc"
                     { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2427 "basilisk.c"
    break;

  case 275: /* @1: %empty  */
#line 585 "basilisk.yacc"
                           { stack_push (parse->stack, &(yyvsp[0])); yyval->sym = YYSYMBOL_YYUNDEF; }
#line 2433 "basilisk.c"
    break;

  case 276: /* compound_statement: '{' @1 block_item_list '}'  */
#line 587 "basilisk.yacc"
                           { ast_pop_scope (parse->stack, yyvsp[-3]); }
#line 2439 "basilisk.c"
    break;

  case 286: /* for_scope: FOR  */
#line 612 "basilisk.yacc"
              { stack_push (parse->stack, &(yyval)); }
#line 2445 "basilisk.c"
    break;

  case 289: /* iteration_statement: for_scope '(' expression_statement expression_statement ')' statement  */
#line 619 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2451 "basilisk.c"
    break;

  case 290: /* iteration_statement: for_scope '(' expression_statement expression_statement expression ')' statement  */
#line 621 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2457 "basilisk.c"
    break;

  case 292: /* for_declaration_statement: for_scope '(' declaration expression_statement ')' statement  */
#line 627 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2463 "basilisk.c"
    break;

  case 293: /* for_declaration_statement: for_scope '(' declaration expression_statement expression ')' statement  */
#line 629 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2469 "basilisk.c"
    break;

  case 305: /* external_declaration: error compound_statement  */
#line 647 "basilisk.yacc"
                                                { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2475 "basilisk.c"
    break;

  case 306: /* function_declaration: declaration_specifiers declarator  */
#line 651 "basilisk.yacc"
                                            { ast_push_function_definition (parse->stack, yyvsp[0]);  }
#line 2481 "basilisk.c"
    break;

  case 307: /* function_definition: function_declaration declaration_list compound_statement  */
#line 656 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-2]->child[1]); }
#line 2487 "basilisk.c"
    break;

  case 308: /* function_definition: function_declaration compound_statement  */
#line 658 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-1]->child[1]); }
#line 2493 "basilisk.c"
    break;

  case 333: /* forin_declaration_statement: for_scope '(' declaration_specifiers declarator IN forin_arguments ')' statement  */
#line 723 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-7]); }
#line 2499 "basilisk.c"
    break;

  case 334: /* forin_statement: for_scope '(' expression IN forin_arguments ')' statement  */
#line 728 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2505 "basilisk.c"
    break;

  case 349: /* root: translation_unit  */
#line 770 "basilisk.yacc"
                           {
	  yyval = root;
	  yyval->sym = yyr1[yyn];
	  yyval->child = allocate ((Allocator *)parse->alloc, 2*sizeof(Ast *));
	  yyval->child[0] = yyvsp[0];
	  yyvsp[0]->parent = yyval;
	  yyval->child[1] = NULL;
        }
#line 2518 "basilisk.c"
    break;


#line 2522 "basilisk.c"

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

#line 780 "basilisk.yacc"


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
