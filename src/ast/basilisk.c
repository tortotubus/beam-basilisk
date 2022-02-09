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
static int yyparse (AstRoot * parse, Ast ** root);

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
  YYSYMBOL_types = 148,                    /* types  */
  YYSYMBOL_struct_or_union_specifier = 149, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 150,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 151,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 152,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 153, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 154,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 155,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 156,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 157,          /* enumerator_list  */
  YYSYMBOL_enumerator = 158,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 159,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 160,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 161,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 162,      /* alignment_specifier  */
  YYSYMBOL_declarator = 163,               /* declarator  */
  YYSYMBOL_direct_declarator = 164,        /* direct_declarator  */
  YYSYMBOL_generic_identifier = 165,       /* generic_identifier  */
  YYSYMBOL_pointer = 166,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 167,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 168,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 169,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 170,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 171,          /* identifier_list  */
  YYSYMBOL_type_name = 172,                /* type_name  */
  YYSYMBOL_abstract_declarator = 173,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 174, /* direct_abstract_declarator  */
  YYSYMBOL_type_not_specified = 175,       /* type_not_specified  */
  YYSYMBOL_initializer = 176,              /* initializer  */
  YYSYMBOL_initializer_list = 177,         /* initializer_list  */
  YYSYMBOL_designation = 178,              /* designation  */
  YYSYMBOL_designator_list = 179,          /* designator_list  */
  YYSYMBOL_designator = 180,               /* designator  */
  YYSYMBOL_static_assert_declaration = 181, /* static_assert_declaration  */
  YYSYMBOL_statement = 182,                /* statement  */
  YYSYMBOL_labeled_statement = 183,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 184,       /* compound_statement  */
  YYSYMBOL_185_1 = 185,                    /* @1  */
  YYSYMBOL_block_item_list = 186,          /* block_item_list  */
  YYSYMBOL_block_item = 187,               /* block_item  */
  YYSYMBOL_expression_statement = 188,     /* expression_statement  */
  YYSYMBOL_selection_statement = 189,      /* selection_statement  */
  YYSYMBOL_for_scope = 190,                /* for_scope  */
  YYSYMBOL_iteration_statement = 191,      /* iteration_statement  */
  YYSYMBOL_for_declaration_statement = 192, /* for_declaration_statement  */
  YYSYMBOL_jump_statement = 193,           /* jump_statement  */
  YYSYMBOL_external_declaration = 194,     /* external_declaration  */
  YYSYMBOL_function_declaration = 195,     /* function_declaration  */
  YYSYMBOL_function_definition = 196,      /* function_definition  */
  YYSYMBOL_declaration_list = 197,         /* declaration_list  */
  YYSYMBOL_basilisk_statements = 198,      /* basilisk_statements  */
  YYSYMBOL_macro_statement = 199,          /* macro_statement  */
  YYSYMBOL_foreach_statement = 200,        /* foreach_statement  */
  YYSYMBOL_foreach_parameters = 201,       /* foreach_parameters  */
  YYSYMBOL_foreach_parameter = 202,        /* foreach_parameter  */
  YYSYMBOL_reduction_list = 203,           /* reduction_list  */
  YYSYMBOL_reduction = 204,                /* reduction  */
  YYSYMBOL_reduction_operator = 205,       /* reduction_operator  */
  YYSYMBOL_foreach_inner_statement = 206,  /* foreach_inner_statement  */
  YYSYMBOL_foreach_dimension_statement = 207, /* foreach_dimension_statement  */
  YYSYMBOL_forin_declaration_statement = 208, /* forin_declaration_statement  */
  YYSYMBOL_forin_statement = 209,          /* forin_statement  */
  YYSYMBOL_forin_arguments = 210,          /* forin_arguments  */
  YYSYMBOL_field_list = 211,               /* field_list  */
  YYSYMBOL_field_item_list = 212,          /* field_item_list  */
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
#define YYLAST   3561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  348
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  627

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
     136,   137,   138,   139,   143,   144,   148,   149,   153,   157,
     158,   162,   163,   164,   168,   169,   170,   171,   172,   173,
     174,   175,   179,   180,   181,   182,   183,   184,   188,   189,
     195,   196,   197,   198,   202,   203,   204,   208,   209,   210,
     214,   215,   216,   217,   218,   222,   223,   224,   228,   229,
     233,   234,   238,   239,   243,   244,   248,   249,   253,   254,
     258,   259,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   277,   278,   282,   286,   287,   288,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   305,
     306,   310,   311,   315,   316,   317,   318,   319,   320,   321,
     325,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   348,   349,   350,
     351,   352,   356,   357,   361,   362,   366,   367,   368,   372,
     373,   374,   375,   379,   380,   384,   385,   386,   390,   391,
     392,   393,   394,   398,   399,   403,   404,   408,   412,   413,
     414,   415,   416,   420,   421,   425,   426,   430,   431,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   453,   454,   458,   459,   460,   461,
     465,   466,   470,   471,   475,   476,   480,   481,   482,   486,
     487,   491,   492,   496,   497,   498,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   526,   530,   531,
     532,   536,   537,   538,   539,   543,   547,   548,   552,   553,
     557,   561,   562,   563,   564,   565,   566,   567,   568,   572,
     573,   574,   578,   580,   580,   586,   587,   591,   592,   596,
     597,   601,   602,   603,   607,   611,   612,   613,   615,   617,
     621,   623,   628,   629,   630,   631,   632,   636,   637,   638,
     639,   640,   641,   642,   646,   650,   652,   657,   658,   665,
     666,   667,   668,   669,   670,   674,   678,   679,   683,   684,
     688,   689,   693,   694,   698,   702,   703,   707,   708,   712,
     713,   717,   722,   727,   728,   732,   736,   737,   741,   745,
     746,   747,   751,   752,   756,   760,   761,   765,   769
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
  "field_list", "field_item_list", "event_definition", "event_parameters",
  "event_parameter", "boundary_definition", "external_foreach_dimension",
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
      46,   123,    91,    93,    61,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63
};
#endif

#define YYPACT_NINF (-530)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-349)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     940,   -49,   141,  -530,  -530,  -530,  -530,  2656,  2670,  2670,
      18,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,    33,   -34,   -12,    58,    73,
    -530,    86,  -530,  -530,  -530,  -530,    94,  1040,  -530,  -530,
    -530,  -530,  -530,  -530,   640,  -530,  -530,  -530,  -530,   317,
    -530,  -530,   570,  2701,  -530,   -40,   -67,    72,    37,   301,
      91,   101,   139,   247,    -7,  -530,   190,  -530,   205,  3365,
    3365,  -530,  -530,   182,  -530,  -530,  3365,  3365,  3365,   231,
    -530,  -530,  3057,  -530,  -530,  -530,  -530,  -530,   285,   208,
    -530,  -530,  1040,  -530,  1040,  -530,  -530,  -530,  -530,   287,
     223,  1316,  3485,  3485,  2701,  2701,    22,  -530,  -530,   213,
    -530,   215,  3485,   176,  3485,   251,    52,  -530,    25,  -530,
    -530,  1856,    25,  1986,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  2701,  -530,  -530,  2701,  2701,
    2701,  2701,  2701,  2701,  2701,  2701,  2701,  2701,  2701,  2701,
    2701,  2701,  2701,  2701,  2701,  2701,  2701,  -530,  -530,   144,
     343,   153,  -530,   -44,   -46,  -530,    34,  -530,  -530,  2892,
     258,  -530,  -530,  -530,  3407,   255,  -530,   205,  -530,  3057,
    -530,  -530,   840,   269,   282,  -530,   291,    90,  -530,   287,
    -530,   308,   316,   319,   331,   337,   346,   345,  3365,  -530,
    2701,  -530,  2992,  1370,   -27,  -530,    70,  -530,  -530,  2000,
    -530,  -530,  -530,  -530,  -530,   353,  -530,    25,   243,  -530,
    -530,  -530,  -530,  -530,    -1,  -530,  -530,  -530,  -530,   -40,
     -40,   -67,   -67,    72,    72,    72,    72,    37,    37,   301,
      91,   101,   139,   247,   272,  -530,   352,  -530,  -530,  -530,
     343,  -530,   144,  2031,  -530,  1416,  -530,   -46,   358,  3167,
    -530,    83,  -530,  2947,  3215,  2109,   362,  -530,  -530,   375,
    2701,   373,   386,   389,   393,  1095,  -530,    25,   399,   404,
    2140,   405,   406,   411,  -530,   -49,   164,  -530,   402,  -530,
    -530,  -530,   740,  -530,  -530,  -530,   412,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,   410,   410,  2701,
    -530,    35,    95,  -530,  -530,  -530,  -530,  3446,   496,  3365,
     144,  -530,  -530,  -530,   261,   417,   416,  -530,   419,  1664,
    -530,   415,   420,  1468,    70,  -530,  -530,  1514,  1840,  -530,
    2031,  -530,   172,  -530,  2238,  -530,  2701,  -530,  -530,  -530,
    -530,  -530,  1840,  -530,  -530,  2837,  1664,  -530,   422,   423,
    1566,  -530,  -530,  -530,  -530,  -530,  2701,   193,  -530,   428,
     424,  3263,  -530,  -530,   425,   225,  -530,  -530,   429,  1095,
    1140,  1140,  2701,   458,   438,  -530,  -530,  -530,   200,  1888,
    2254,  2286,  -530,  -530,  1095,  -530,  -530,  1218,  -530,  -530,
    -530,  -530,    42,   434,   283,  -530,   436,   440,  -530,  -530,
    2772,  -530,   280,  -530,  -530,  3317,  -530,  -530,   435,  1664,
    -530,  -530,  2701,  -530,   439,  3117,  1664,  -530,   441,   444,
    1612,    25,  2701,  -530,   212,  2031,   334,  -530,  -530,  -530,
      25,  -530,  -530,   220,   443,  -530,  -530,   445,   325,   447,
    1664,  -530,  -530,  2701,  -530,   448,   449,  -530,  -530,  -530,
      67,  2701,  -530,  -530,  2031,  2109,  1095,  2109,  1095,  -530,
     459,   461,   344,   446,  -530,  -530,   457,  1095,  -530,   349,
    -530,   470,  -530,  1095,   360,  1095,   369,  -530,   162,  2384,
     205,  2384,  -530,  2701,  -530,  3446,  2701,   472,  -530,  -530,
    -530,   465,   466,  -530,  -530,   474,   469,  1664,  -530,  -530,
    2701,  -530,   471,  -530,   473,  -530,  1710,  -530,  -530,  -530,
    -530,  -530,  1742,  -530,  -530,  -530,   524,  -530,   475,   479,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    1095,  1095,  1095,  2701,     2,  -530,  1095,  2415,  -530,  -530,
    1095,  -530,  1095,  2429,  2527,   486,  2558,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,   480,   481,  -530,  -530,
    -530,  -530,  2031,  -530,  -530,  -530,  -530,   505,  -530,  -530,
     377,  -530,  -530,   478,  -530,  -530,  -530,  -530,   215,   490,
    -530,  1095,   380,  2429,  1095,   383,  -530,  -530,  -530,  1095,
     493,    25,  1095,  -530,  1095,   492,  -530,  1095,  -530,  -530,
     494,  -530,  -530,  1095,  -530,  -530,  -530
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     7,    14,    15,    18,    19,     0,     0,     0,
     146,    16,   123,   124,   125,   127,   128,   183,   178,   179,
     180,   140,   132,   133,   134,   135,   138,   139,   136,   137,
     131,   141,   142,   152,   153,     0,     0,     0,   181,     0,
     184,     0,   126,   182,    51,   129,     0,     0,    52,    53,
      54,    55,    56,    57,     0,    25,     8,     9,    11,    44,
      27,    26,    58,     0,    60,    64,    67,    70,    75,    78,
      80,    82,    84,    86,    88,    90,     0,   298,     0,   110,
     112,   130,   144,     0,   145,   143,   114,   116,   118,     0,
     108,     2,     0,   297,   299,   300,   301,   302,     0,   273,
     303,     7,     0,    48,     0,    45,    46,   204,   205,     0,
     172,     0,     0,     0,     0,     0,     0,    13,   146,     0,
     103,    12,   160,   247,   162,     0,     0,     3,     0,    30,
      31,     0,     0,     0,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    92,     0,    58,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   344,   247,     0,
     209,     0,   119,   304,   247,   189,     0,   109,   111,     0,
     149,   113,   115,   117,     0,     0,   307,     0,   306,     0,
       1,   272,     0,     0,     0,    17,   176,     0,   173,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,   159,     0,     0,   224,   247,   225,   222,   161,     0,
       4,     5,     6,    29,    38,     7,    36,     0,     0,    39,
      41,    43,    28,    34,     0,    91,    61,    62,    63,    65,
      66,    68,    69,    73,    74,    71,    72,    76,    77,    79,
      81,    83,    85,    87,     0,   106,     0,   181,   210,   208,
     207,   247,     0,     0,   247,     0,   188,   247,     0,     0,
     154,     0,   158,     0,     0,     0,   122,   308,   305,     0,
       0,     0,     0,     0,     0,     0,   284,     0,     0,     0,
       0,     0,     0,     0,   279,    26,     0,   277,     0,   278,
     261,   262,     0,   275,   263,   264,     0,   265,   289,   266,
     267,   309,   310,   311,   312,   313,   314,    49,     0,     0,
     168,     0,     0,   186,   185,    50,   177,     0,     0,     0,
       0,   345,   104,   243,   218,     0,   213,   247,     0,     0,
     227,    53,     0,     0,   223,   221,   247,     0,     0,    59,
       0,   336,     0,    37,     0,    35,     0,   190,   211,   206,
     107,   120,     0,   250,   121,     0,     0,   191,    53,     0,
       0,   187,   150,   147,   155,   247,     0,     0,   163,   167,
       0,     0,   347,   342,     0,     0,   339,   268,     0,     0,
       0,     0,     0,     0,     0,   293,   294,   295,     0,     0,
       0,     0,   315,   280,     0,   274,   276,     0,   175,   169,
     174,   170,     0,     0,     0,    21,     0,     0,   346,   304,
       0,   216,   224,   217,   244,     0,   214,   226,     0,     0,
     228,   234,     0,   233,     0,     0,     0,   235,    53,     0,
       0,     0,     0,   252,     0,     0,     0,   256,    42,   335,
       0,    40,    89,     0,     0,   219,   202,     0,     0,     0,
       0,   192,   199,     0,   198,    53,     0,   156,   165,   247,
       0,     0,   151,   148,     0,     0,     0,     0,     0,   271,
       0,     0,     0,     0,   292,   296,     0,     0,   320,     0,
     318,   321,   322,     0,     0,     0,     0,   269,     0,     0,
       0,     0,   171,     0,    20,     0,     0,     0,   212,   247,
     230,     0,     0,   232,   245,     0,     0,     0,   236,   242,
       0,   241,     0,   259,     0,    32,     0,   251,   255,   257,
     337,   248,     0,   201,   200,   203,     0,   194,     0,     0,
     195,   197,   157,   164,   166,   343,   341,   338,   340,   270,
       0,     0,     0,     0,     0,   316,     0,     0,   323,   327,
       0,   329,     0,     0,     0,   119,     0,    24,    22,    23,
     260,   215,   229,   231,   246,   238,     0,     0,   239,   258,
      33,   254,     0,   249,   220,   193,   196,   282,   283,   285,
       0,   326,   325,     0,   317,   319,   328,   330,   333,     0,
     334,     0,     0,     0,     0,     0,   237,   240,   253,     0,
       0,     0,     0,   290,     0,     0,   287,     0,   281,   286,
       0,   332,   291,     0,   288,   324,   331
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -530,  -530,  -530,   -26,  -530,  -530,  -530,  -530,  -530,    78,
    -530,  -530,   -66,   452,  -530,   233,    40,  -530,   -54,   228,
     235,   296,   238,   427,   442,   437,   421,   450,  -530,   -98,
       4,  -530,   -14,   -96,   -91,   253,  -530,  -256,  -530,   -31,
    -530,  -530,  -530,  -157,  -259,   -18,  -530,   131,  -530,   403,
    -310,  -530,   -45,  -530,  -530,   -64,  -173,     0,  -101,  -189,
    -293,  -530,   178,  -530,   288,  -116,  -196,   -51,  -220,   244,
    -503,  -530,   159,  -159,    19,  -530,    20,  -530,  -530,   305,
    -368,  -530,  -530,  -530,  -530,  -530,   554,  -530,  -200,  -530,
    -530,  -530,  -530,  -530,    53,  -530,   118,  -530,  -530,  -530,
    -530,  -530,     9,  -529,  -530,  -530,  -530,    12,  -530,  -530,
    -530,  -530
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    54,    55,   119,    56,   196,    57,    58,   414,   415,
      59,    60,    61,   223,   228,   229,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     120,   145,   296,   201,    77,   334,   171,   172,    79,    80,
      81,    82,    83,   269,   270,   123,   377,   378,    84,   197,
     198,    85,    86,    87,    88,   276,   174,   298,   176,   260,
     335,   336,   337,   458,   416,   338,   216,   217,   443,   444,
     445,   446,   447,    90,   299,   300,   301,   192,   302,   303,
     304,   305,   306,   307,   308,   309,    91,    92,    93,   189,
     310,   311,   312,   489,   490,   491,   492,   593,   313,   314,
     315,   316,   599,   231,   352,    94,   385,   386,    95,    96,
      97,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,   186,   124,   267,    76,   107,   361,   215,   331,   147,
     374,   410,   165,   200,   173,   374,   122,   200,   344,   206,
     272,   100,   214,   582,   343,   272,   207,   274,   107,   582,
     151,   152,   108,   121,   600,   110,   107,   107,   195,   501,
    -122,   264,    99,   364,  -122,   195,   265,   103,   105,   106,
     263,   155,   156,   111,    89,   108,   148,   124,    76,   124,
     212,   149,   150,   108,   108,   213,   124,   124,   124,   259,
     107,   122,   457,   122,   600,   112,   370,   124,   175,   124,
     122,   122,   122,   180,   153,   154,   107,   210,   121,   185,
     121,   122,   355,   122,   236,   237,   238,   108,   277,   591,
     166,   297,   410,   146,   211,   256,   218,  -205,   208,  -205,
     272,   214,   188,   108,   272,   272,   381,   255,   205,   234,
     409,   169,   374,   266,   109,   258,   295,   502,   224,   418,
     448,   564,   224,   566,   124,   230,   220,   221,   222,   124,
     157,   158,   515,    99,  -204,   113,   100,   107,   122,   235,
     429,   146,   254,   122,   169,   146,   376,   346,   440,   359,
     114,   271,   347,   170,   345,   349,   271,   375,   258,   175,
     169,  -204,   376,   115,   108,   320,   175,   460,   321,   170,
     411,   116,   200,   412,   388,   107,   161,   175,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   162,   379,   107,   278,
     360,   297,   108,   365,   332,   358,   371,   342,   423,   295,
     258,   200,   272,   408,   124,   527,   344,   351,   124,   124,
    -204,   169,  -204,   422,   107,   108,   295,   261,   122,   563,
     170,   262,   122,   122,   565,   163,   403,   517,   403,   267,
     210,   271,   210,    78,   545,   271,   271,   449,   452,   146,
     450,   108,   175,   212,   107,   164,   419,   363,   213,   369,
     421,   175,   170,   179,   167,   384,   398,   469,   200,   383,
     468,   470,   124,   107,   485,   190,   426,   394,   210,   168,
     195,   108,   169,   191,   258,   435,   122,   525,   358,   209,
     526,   170,   258,   210,   393,   531,   581,    78,   532,   475,
     108,   476,   581,   477,   199,   402,   499,   159,   160,   422,
     146,   258,   184,   295,   467,   358,   128,   129,   130,   353,
     175,   354,   177,   178,   175,   125,   124,   219,   295,   181,
     182,   183,   275,   428,   200,   187,   524,   434,   420,   273,
     122,   439,   363,   213,   363,   317,   256,   170,   230,   146,
     210,   356,   608,   271,   480,   481,   363,   420,   318,   504,
     459,   505,   213,   200,   466,   544,   121,   121,   482,   239,
     240,    18,    19,    20,   358,   319,   494,   496,   241,   242,
     193,   258,   194,   498,   323,   358,   146,   247,   248,   202,
     203,   204,   324,   488,   131,   325,   379,   132,   479,   133,
     295,   535,   295,   536,   257,   358,   146,   326,   542,    43,
     175,   295,   175,   497,   441,   327,   442,   295,   528,   295,
     552,   329,   210,   511,   328,   556,   512,   557,   357,   170,
     516,   523,   187,   372,   522,   187,   560,   350,   210,   363,
     530,   243,   244,   245,   246,   562,   263,   210,   571,   387,
     124,   330,   389,   610,   538,   210,   614,   539,   210,   617,
     175,   210,   358,   390,   122,   384,   391,   384,   363,   383,
     392,   383,   146,   395,   295,   295,   295,   546,   396,   548,
     295,   404,   399,   400,   295,   547,   295,   549,   401,   407,
     175,   348,   417,   424,   425,   427,   555,   567,   430,   472,
     569,   146,   559,   431,   561,   461,   462,   471,   478,   474,
     483,   576,   484,   503,   577,   506,   507,   584,   510,   533,
     363,   534,   513,   553,   518,   295,   363,   519,   295,   590,
     537,   540,   541,   295,   554,   550,   295,   551,   295,   598,
     602,   295,   605,   486,   592,   187,   570,   295,   572,   573,
     574,   488,   575,   603,   578,   609,   579,   611,   585,   587,
     588,   589,   586,   606,   607,   594,   612,   619,   623,   596,
     625,   597,   330,   568,   232,   252,   363,   451,   249,   598,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     251,   543,   322,   509,   250,   529,   453,   406,   127,   558,
     595,   620,   615,     0,     0,   253,     0,     0,     0,     0,
     613,     0,     0,   616,     0,     0,     0,     0,   618,     0,
       0,   621,     0,   622,     0,     0,   624,     0,     0,     0,
    -348,   126,   626,     2,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
     500,     0,     0,     0,   144,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
       0,     0,    46,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,   279,     0,     2,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,   280,   281,   282,
       0,   283,   284,   285,   286,   287,   288,   289,   290,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
     291,   292,   293,     0,   294,   405,     0,    47,     0,     0,
       0,    99,     0,     0,     0,    48,    49,    50,    51,    52,
      53,   279,     0,     2,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,   280,   281,   282,
       0,   283,   284,   285,   286,   287,   288,   289,   290,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
     291,   292,   293,     0,   294,     0,     0,    47,     0,     0,
       0,    99,     0,     0,     0,    48,    49,    50,    51,    52,
      53,     1,     0,     2,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
       0,     0,    46,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,   117,     0,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,    11,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   279,     0,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
      37,    38,    39,     0,     0,     0,    43,     0,    44,     0,
       0,     0,     0,     0,     0,   108,    11,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,   117,     0,   101,     3,     4,     5,     6,     7,     0,
       8,     9,   280,   281,   282,     0,   283,   284,   285,   286,
     287,   288,   289,   290,     0,    37,     0,    39,     0,     0,
       0,    11,     0,    44,     0,   291,   292,   293,     0,   294,
       0,     0,    47,     0,     0,     0,    99,     0,     0,     0,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,   101,     3,     4,     5,     6,     7,    47,     8,     9,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,   118,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,     0,     0,
       0,     0,   294,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,    11,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,    37,    38,    39,     0,
       0,     0,    43,     0,    44,     0,     0,     0,     0,     0,
       0,    11,     0,    47,   339,     0,     0,     0,    18,    19,
      20,    48,    49,    50,    51,    52,    53,     0,     0,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,   257,    39,     0,     0,     0,    43,    11,    44,     0,
     366,     0,     0,     0,    18,    19,    20,    47,     0,     0,
       0,     0,     0,   340,     0,    48,   341,    50,    51,    52,
      53,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    37,   257,    39,     0,
       0,     0,    43,     0,    44,     0,     0,     0,     0,    11,
       0,     0,   432,    47,     0,     0,    18,    19,    20,   367,
       0,    48,   368,    50,    51,    52,    53,   101,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,   257,
      39,     0,     0,     0,    43,    11,    44,     0,   436,     0,
       0,     0,    18,    19,    20,    47,     0,     0,     0,     0,
       0,   433,     0,    48,    49,    50,    51,    52,    53,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,    37,   257,    39,     0,     0,     0,
      43,     0,    44,     0,     0,     0,     0,    11,     0,     0,
     463,    47,     0,     0,    18,    19,    20,   437,     0,    48,
     438,    50,    51,    52,    53,   101,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,   257,    39,     0,
       0,     0,    43,    11,    44,     0,   520,     0,     0,     0,
      18,    19,    20,    47,     0,     0,     0,     0,     0,   464,
       0,    48,   465,    50,    51,    52,    53,   101,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,    37,   257,    39,     0,     0,     0,    43,     0,
      44,     0,     0,     0,     0,    11,     0,     0,     0,    47,
       0,     0,    18,    19,    20,   521,     0,    48,    49,    50,
      51,    52,    53,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,   257,    39,     0,     0,     0,
      43,    11,    44,     0,     0,   101,     3,     4,     5,     6,
       7,    47,     8,     9,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,     0,     0,     0,     0,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,   580,     0,    47,     0,     0,
     441,   362,   442,     0,     0,    48,    49,    50,    51,    52,
      53,     0,    37,     0,    39,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,     0,   583,     0,    47,
       0,     0,   441,   362,   442,     0,     0,    48,    49,    50,
      51,    52,    53,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,   225,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    39,     0,     0,     0,     0,     0,    44,    11,
       0,     0,     0,     0,     0,     0,    37,    47,    39,     0,
     441,   362,   442,     0,    44,    48,    49,    50,    51,    52,
      53,     0,   226,    47,     0,     0,     0,   227,     0,     0,
       0,    48,    49,    50,    51,    52,    53,     0,    37,     0,
      39,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,   486,     0,     0,   487,    47,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,   101,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,    11,     0,    44,     0,     0,     0,     0,     0,
      37,     0,    39,    47,     0,     0,     0,     0,    44,   233,
       0,    48,    49,    50,    51,    52,    53,    47,     0,     0,
       0,   348,     0,     0,     0,    48,    49,    50,    51,    52,
      53,    37,     0,    39,     0,     0,     0,     0,     0,    44,
       0,     0,     2,     3,     4,     5,     6,     7,    47,     8,
       9,     0,   362,     0,     0,     0,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,   108,
      11,     0,     0,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,    53,
      37,     0,    39,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,   397,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,   225,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,   101,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,     0,     0,    44,    11,     0,     0,
       0,     0,     0,     0,    37,    47,    39,     0,     0,   227,
       0,     0,    44,    48,    49,    50,    51,    52,    53,     0,
     493,    47,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,     0,    37,     0,    39,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,     0,
       0,     0,   495,    47,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,   101,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,   101,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,   101,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
      11,     0,    44,     0,     0,     0,     0,     0,   294,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    37,     0,    39,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,   486,    37,
       0,    39,    47,     0,     0,     0,     0,    44,     0,     0,
      48,    49,    50,    51,    52,    53,    47,     0,     0,     0,
     227,     0,     0,     0,    48,    49,    50,    51,    52,    53,
     101,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,   101,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,     0,    44,     0,     0,     0,     0,
       0,     0,     0,   601,    47,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    37,     0,
      39,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,     0,     0,   604,    47,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,   101,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,   101,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,   101,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,    11,     0,    44,     0,     0,     0,     0,     0,
      37,     0,    39,   102,     0,     0,     0,     0,    44,     0,
       0,    48,    49,    50,    51,    52,    53,   104,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,    37,     0,    39,     0,   107,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    10,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   454,     0,
     455,    36,     0,    38,     0,    40,     0,    42,    43,     0,
       0,    45,     0,     0,     0,     0,     0,     0,   333,   420,
       0,     0,     0,     0,   213,     0,     0,   118,   170,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   268,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,     0,
      40,     0,    42,    43,     0,     0,    45,     0,     0,     0,
       0,     0,   118,   456,     0,     0,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   380,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,    41,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,   118,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    41,   118,    43,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    38,     0,    40,     0,    42,    43,     0,
       0,    45,     0,     0,     0,     0,     0,     0,   333,   212,
       0,     0,     0,     0,   213,     0,     0,   118,   170,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,     0,
      40,    41,    42,    43,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,    99,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,     0,
      40,     0,    42,    43,     0,     0,    45,   118,     0,     0,
       0,     0,     0,   514,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    41,     0,    43,     0,   118,     0,     0,     0,     0,
       0,     0,   373,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,    41,
       0,    43,     0,   118,     0,     0,     0,     0,     0,     0,
     382,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    41,     0,    43,
       0,     0,     0,     0,     0,     0,     0,   118,   473,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   508,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,     0,
      40,     0,    42,    43,     0,   118,    45,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,     0,    38,   118,    40,     0,
      42,    43,     0,     0,    45,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,     0,    38,     0,
       0,    41,     0,    43,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,   413,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,    38,     0,     0,
       0,     0,    43,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,    43
};

static const yytype_int16 yycheck[] =
{
       0,    92,    47,   176,     0,     3,   262,   123,   208,    63,
     269,   321,    19,   111,    78,   274,    47,   115,   214,   115,
     179,     1,   123,   526,   213,   184,     4,   184,     3,   532,
      97,    98,    30,    47,   563,    35,     3,     3,     3,   407,
      84,    87,    91,   263,    88,     3,    92,     7,     8,     9,
      94,    14,    15,    87,    54,    30,    96,   102,    54,   104,
      87,   101,   102,    30,    30,    92,   111,   112,   113,   170,
       3,   102,   365,   104,   603,    87,   265,   122,    78,   124,
     111,   112,   113,    83,    12,    13,     3,    88,   102,    89,
     104,   122,    93,   124,   148,   149,   150,    30,   189,    97,
     107,   192,   412,    63,   122,   169,   124,    89,    86,    91,
     269,   212,    92,    30,   273,   274,   273,   168,   114,   133,
      85,    87,   381,   174,    91,   170,   192,    85,   128,   329,
     350,   499,   132,   501,   179,   131,    84,    85,    86,   184,
     103,   104,   435,    91,     3,    87,   126,     3,   179,   145,
     339,   111,   166,   184,    87,   115,    89,    87,   347,   260,
      87,   179,    92,    96,   215,   219,   184,    84,   213,   169,
      87,    30,    89,    87,    30,    85,   176,   366,    88,    96,
      85,    87,   280,    88,   280,     3,    95,   187,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   105,   271,     3,   189,
     261,   302,    30,   264,   210,   260,   267,   213,   334,   285,
     265,   319,   381,   319,   269,   445,   422,   227,   273,   274,
      89,    87,    91,   334,     3,    30,   302,    84,   269,    77,
      96,    88,   273,   274,   500,   106,    84,   436,    84,   422,
      88,   269,    88,     0,   474,   273,   274,    85,   356,   219,
      88,    30,   262,    87,     3,    18,   330,   263,    92,   265,
     334,   271,    96,    91,    84,   275,   290,    84,   376,   275,
     376,    88,   327,     3,    84,     0,   337,   287,    88,    84,
       3,    30,    87,    85,   339,   346,   327,    85,   343,    86,
      88,    96,   347,    88,   285,    85,   526,    54,    88,    84,
      30,    86,   532,    88,    91,   295,   407,    16,    17,   420,
     280,   366,    91,   389,   375,   370,     9,    10,    11,    86,
     330,    88,    79,    80,   334,    47,   381,    86,   404,    86,
      87,    88,    87,   339,   442,    92,   442,   343,    87,    91,
     381,   347,   348,    92,   350,    86,   420,    96,   354,   319,
      88,    89,   582,   381,   390,   391,   362,    87,    86,    86,
     366,    88,    92,   471,   370,   471,   390,   391,   392,   151,
     152,    38,    39,    40,   429,    94,   400,   401,   153,   154,
     102,   436,   104,   407,    86,   440,   356,   159,   160,   111,
     112,   113,    86,   399,    87,    86,   470,    90,   389,    92,
     476,    86,   478,    88,    71,   460,   376,    86,   469,    76,
     420,   487,   422,   404,    90,    88,    92,   493,    94,   495,
      86,    86,    88,   429,    88,    86,   432,    88,    86,    96,
     436,   441,   189,    85,   440,   192,    86,    94,    88,   445,
     450,   155,   156,   157,   158,    86,    94,    88,   509,    84,
     505,   208,    89,    86,   460,    88,    86,   463,    88,    86,
     470,    88,   517,    87,   505,   475,    87,   477,   474,   475,
      87,   477,   442,    84,   550,   551,   552,   475,    84,   477,
     556,    89,    87,    87,   560,   476,   562,   478,    87,    87,
     500,    91,     6,    86,    88,    86,   487,   503,    93,    85,
     506,   471,   493,    93,   495,    93,    93,    89,    89,    94,
      62,   517,    84,    89,   520,    89,    86,     3,    93,    86,
     526,    86,    93,    87,    93,   601,   532,    93,   604,   553,
      93,    93,    93,   609,    87,    86,   612,    86,   614,   563,
     564,   617,   566,    83,   554,   302,    84,   623,    93,    93,
      86,   557,    93,    77,    93,    60,    93,    89,    93,   550,
     551,   552,    93,    93,    93,   556,    86,    84,    86,   560,
      86,   562,   329,   505,   132,   164,   582,   354,   161,   603,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
     163,   470,   199,   425,   162,   446,   362,   302,    54,   491,
     557,   611,   603,    -1,    -1,   165,    -1,    -1,    -1,    -1,
     601,    -1,    -1,   604,    -1,    -1,    -1,    -1,   609,    -1,
      -1,   612,    -1,   614,    -1,    -1,   617,    -1,    -1,    -1,
       0,     1,   623,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     407,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    -1,    84,    85,    -1,    87,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    -1,    84,    -1,    -1,    87,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    31,    -1,    78,    -1,    80,    81,    82,    -1,    84,
      -1,    -1,    87,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,     3,     4,     5,     6,     7,     8,    87,    10,    11,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    87,    34,    -1,    -1,    -1,    38,    39,
      40,    95,    96,    97,    98,    99,   100,    -1,    -1,     3,
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
      34,    87,    -1,    -1,    38,    39,    40,    93,    -1,    95,
      96,    97,    98,    99,   100,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    31,    78,    -1,    34,    -1,    -1,    -1,
      38,    39,    40,    87,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    95,    96,    97,    98,    99,   100,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
      78,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    87,
      -1,    -1,    38,    39,    40,    93,    -1,    95,    96,    97,
      98,    99,   100,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    31,    78,    -1,    -1,     3,     4,     5,     6,     7,
       8,    87,    10,    11,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    87,    -1,    -1,
      90,    91,    92,    -1,    -1,    95,    96,    97,    98,    99,
     100,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    87,
      -1,    -1,    90,    91,    92,    -1,    -1,    95,    96,    97,
      98,    99,   100,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    87,    72,    -1,
      90,    91,    92,    -1,    78,    95,    96,    97,    98,    99,
     100,    -1,    86,    87,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    31,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    87,    -1,    -1,    -1,    -1,    78,    93,
      -1,    95,    96,    97,    98,    99,   100,    87,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,     3,     4,     5,     6,     7,     8,    87,    10,
      11,    -1,    91,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    87,    72,    -1,    -1,    91,
      -1,    -1,    78,    95,    96,    97,    98,    99,   100,    -1,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,    -1,    70,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      31,    -1,    78,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    83,    70,
      -1,    72,    87,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      95,    96,    97,    98,    99,   100,    87,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    31,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    87,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    95,    96,    97,    98,    99,   100,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,    70,    -1,    72,    -1,     3,    -1,    -1,    -1,    78,
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
     119,   120,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   142,   143,   146,
     147,   148,   149,   150,   156,   159,   160,   161,   162,   165,
     181,   194,   195,   196,   213,   216,   217,   218,   219,    91,
     184,     3,    87,   124,    87,   124,   124,     3,    30,    91,
     165,    87,    87,    87,    87,    87,    87,     1,    30,   111,
     138,   140,   147,   153,   160,   172,     1,   194,     9,    10,
      11,    87,    90,    92,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    94,   139,   124,   126,    96,   101,
     102,    97,    98,    12,    13,    14,    15,   103,   104,    16,
      17,    95,   105,   106,    18,    19,   107,    84,    84,    87,
      96,   144,   145,   163,   164,   165,   166,   143,   143,    91,
     165,   143,   143,   143,    91,   165,   142,   143,   184,   197,
       0,    85,   185,   172,   172,     3,   113,   157,   158,    91,
     137,   141,   172,   172,   172,   138,   141,     4,    86,    86,
      88,   153,    87,    92,   166,   173,   174,   175,   153,    86,
      84,    85,    86,   121,   165,     3,    86,    91,   122,   123,
     138,   211,   121,    93,   140,   138,   126,   126,   126,   127,
     127,   128,   128,   129,   129,   129,   129,   130,   130,   131,
     132,   133,   134,   135,   140,   175,   163,    71,   160,   166,
     167,    84,    88,    94,    87,    92,   175,   164,     1,   151,
     152,   153,   181,    91,   151,    87,   163,   142,   184,     1,
      57,    58,    59,    61,    62,    63,    64,    65,    66,    67,
      68,    80,    81,    82,    84,   120,   140,   142,   165,   182,
     183,   184,   186,   187,   188,   189,   190,   191,   192,   193,
     198,   199,   200,   206,   207,   208,   209,    86,    86,    94,
      85,    88,   157,    86,    86,    86,    86,    88,    88,    86,
     143,   196,   138,    86,   143,   168,   169,   170,   173,    34,
      93,    96,   138,   167,   174,   175,    87,    92,    91,   126,
      94,   165,   212,    86,    88,    93,    89,    86,   160,   166,
     175,   145,    91,   138,   176,   175,    34,    93,    96,   138,
     167,   175,    85,    85,   152,    84,    89,   154,   155,   163,
       1,   151,    85,   138,   165,   214,   215,    84,   141,    89,
      87,    87,    87,   182,   165,    84,    84,    84,   140,    87,
      87,    87,   184,    84,    89,    85,   187,    87,   141,    85,
     158,    85,    88,    58,   116,   117,   172,     6,   196,   163,
      87,   163,   166,   173,    86,    88,   175,    86,   138,   167,
      93,    93,    34,    93,   138,   175,    34,    93,    96,   138,
     167,    90,    92,   176,   177,   178,   179,   180,   176,    85,
      88,   123,   137,   177,     1,     3,    86,   168,   171,   138,
     167,    93,    93,    34,    93,    96,   138,   175,   141,    84,
      88,    89,    85,    85,    94,    84,    86,    88,    89,   182,
     111,   111,   140,    62,    84,    84,    83,    86,   138,   201,
     202,   203,   204,    86,   140,    86,   140,   182,   140,   142,
     143,   188,    85,    89,    86,    88,    89,    86,    56,   170,
      93,   138,   138,    93,    86,   168,   138,   167,    93,    93,
      34,    93,   138,   165,   141,    85,    88,   176,    94,   180,
     165,    85,    88,    86,    86,    86,    88,    93,   138,   138,
      93,    93,   175,   155,   141,   176,   215,   182,   215,   182,
      86,    86,    86,    87,    87,   182,    86,    88,   204,   182,
      86,   182,    86,    77,   188,   145,   188,   138,   117,   138,
      84,   175,    93,    93,    86,    93,   138,   138,    93,    93,
      85,   176,   178,    85,     3,    93,    93,   182,   182,   182,
     140,    97,   165,   205,   182,   202,   182,   182,   140,   210,
     211,    86,   140,    77,    86,   140,    93,    93,   176,    60,
      86,    89,    86,   182,    86,   210,   182,    86,   182,    84,
     165,   182,   182,    86,   182,    86,   182
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   112,   113,   114,   114,
     115,   116,   116,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   119,   119,   120,   120,   121,   122,
     122,   123,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   127,   127,   127,   128,   128,   128,   129,   129,   129,
     130,   130,   130,   130,   130,   131,   131,   131,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   140,   140,   141,   142,   142,   142,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   144,
     144,   145,   145,   146,   146,   146,   146,   146,   146,   146,
     147,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   149,   149,   149,
     149,   149,   150,   150,   151,   151,   152,   152,   152,   153,
     153,   153,   153,   154,   154,   155,   155,   155,   156,   156,
     156,   156,   156,   157,   157,   158,   158,   159,   160,   160,
     160,   160,   160,   161,   161,   162,   162,   163,   163,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   165,   165,   166,   166,   166,   166,
     167,   167,   168,   168,   169,   169,   170,   170,   170,   171,
     171,   172,   172,   173,   173,   173,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   175,   176,   176,
     176,   177,   177,   177,   177,   178,   179,   179,   180,   180,
     181,   182,   182,   182,   182,   182,   182,   182,   182,   183,
     183,   183,   184,   185,   184,   186,   186,   187,   187,   188,
     188,   189,   189,   189,   190,   191,   191,   191,   191,   191,
     192,   192,   193,   193,   193,   193,   193,   194,   194,   194,
     194,   194,   194,   194,   195,   196,   196,   197,   197,   198,
     198,   198,   198,   198,   198,   199,   200,   200,   201,   201,
     202,   202,   203,   203,   204,   205,   205,   206,   206,   207,
     207,   208,   209,   210,   210,   211,   212,   212,   213,   214,
     214,   214,   215,   215,   216,   217,   217,   218,   219
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       2,     2,     6,     7,     3,     4,     3,     4,     1,     1,
       3,     1,     3,     1,     1,     2,     2,     2,     2,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     4,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     2,
       4,     5,     1,     1,     1,     2,     3,     4,     1,     2,
       1,     2,     1,     1,     3,     2,     3,     1,     4,     5,
       5,     6,     2,     1,     3,     3,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     2,     1,
       3,     3,     4,     6,     5,     5,     6,     5,     4,     4,
       5,     5,     4,     5,     1,     1,     3,     2,     2,     1,
       1,     2,     3,     1,     2,     4,     2,     2,     1,     1,
       3,     3,     2,     2,     1,     1,     3,     2,     3,     5,
       4,     5,     4,     3,     3,     3,     4,     6,     5,     5,
       6,     4,     4,     2,     3,     4,     5,     0,     3,     4,
       1,     2,     1,     4,     3,     2,     1,     2,     3,     2,
       7,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     3,     2,     0,     4,     1,     2,     1,     1,     1,
       2,     7,     5,     5,     1,     5,     7,     6,     7,     1,
       6,     7,     3,     2,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     4,     5,     1,     3,
       1,     1,     1,     2,     6,     1,     1,     4,     5,     4,
       5,     8,     7,     1,     1,     3,     1,     3,     6,     1,
       3,     3,     1,     3,     2,     4,     5,     4,     1
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
#line 83 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2386 "basilisk.c"
    break;

  case 5: /* translation_unit: translation_unit error '}'  */
#line 84 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2392 "basilisk.c"
    break;

  case 6: /* translation_unit: translation_unit error ')'  */
#line 85 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2398 "basilisk.c"
    break;

  case 13: /* expression_error: error  */
#line 98 "basilisk.yacc"
                        { yyvsp[0]->sym = YYSYMBOL_YYerror; }
#line 2404 "basilisk.c"
    break;

  case 106: /* declaration: declaration_specifiers ';' type_not_specified  */
#line 286 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 2410 "basilisk.c"
    break;

  case 107: /* declaration: declaration_specifiers init_declarator_list ';' type_not_specified  */
#line 287 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 2416 "basilisk.c"
    break;

  case 130: /* type_specifier: types  */
#line 325 "basilisk.yacc"
                   { parse->type_already_specified = true; }
#line 2422 "basilisk.c"
    break;

  case 150: /* struct_or_union_specifier: struct_or_union '{' error '}'  */
#line 351 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2428 "basilisk.c"
    break;

  case 151: /* struct_or_union_specifier: struct_or_union generic_identifier '{' error '}'  */
#line 352 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2434 "basilisk.c"
    break;

  case 201: /* direct_declarator: direct_declarator '(' type_not_specified error ')'  */
#line 447 "basilisk.yacc"
                                                                                           { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2440 "basilisk.c"
    break;

  case 247: /* type_not_specified: %empty  */
#line 526 "basilisk.yacc"
           { parse->type_already_specified = false; }
#line 2446 "basilisk.c"
    break;

  case 268: /* statement: error ';'  */
#line 568 "basilisk.yacc"
                     { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2452 "basilisk.c"
    break;

  case 273: /* @1: %empty  */
#line 580 "basilisk.yacc"
                           { stack_push (parse->stack, &(yyvsp[0])); yyval->sym = YYSYMBOL_YYUNDEF; }
#line 2458 "basilisk.c"
    break;

  case 274: /* compound_statement: '{' @1 block_item_list '}'  */
#line 582 "basilisk.yacc"
                           { ast_pop_scope (parse->stack, yyvsp[-3]); }
#line 2464 "basilisk.c"
    break;

  case 284: /* for_scope: FOR  */
#line 607 "basilisk.yacc"
              { stack_push (parse->stack, &(yyval)); }
#line 2470 "basilisk.c"
    break;

  case 287: /* iteration_statement: for_scope '(' expression_statement expression_statement ')' statement  */
#line 614 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2476 "basilisk.c"
    break;

  case 288: /* iteration_statement: for_scope '(' expression_statement expression_statement expression ')' statement  */
#line 616 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2482 "basilisk.c"
    break;

  case 290: /* for_declaration_statement: for_scope '(' declaration expression_statement ')' statement  */
#line 622 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2488 "basilisk.c"
    break;

  case 291: /* for_declaration_statement: for_scope '(' declaration expression_statement expression ')' statement  */
#line 624 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2494 "basilisk.c"
    break;

  case 303: /* external_declaration: error compound_statement  */
#line 642 "basilisk.yacc"
                                                { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2500 "basilisk.c"
    break;

  case 304: /* function_declaration: declaration_specifiers declarator  */
#line 646 "basilisk.yacc"
                                            { ast_push_function_definition (parse->stack, yyvsp[0]);  }
#line 2506 "basilisk.c"
    break;

  case 305: /* function_definition: function_declaration declaration_list compound_statement  */
#line 651 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-2]->child[1]); }
#line 2512 "basilisk.c"
    break;

  case 306: /* function_definition: function_declaration compound_statement  */
#line 653 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-1]->child[1]); }
#line 2518 "basilisk.c"
    break;

  case 331: /* forin_declaration_statement: for_scope '(' declaration_specifiers init_declarator IN forin_arguments ')' statement  */
#line 718 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-7]); }
#line 2524 "basilisk.c"
    break;

  case 332: /* forin_statement: for_scope '(' expression IN forin_arguments ')' statement  */
#line 723 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2530 "basilisk.c"
    break;

  case 348: /* root: translation_unit  */
#line 769 "basilisk.yacc"
                           {
	  yyval = *root = allocate ((Allocator *)parse->alloc, sizeof(AstRoot));
	  memset (yyval, 0, sizeof(AstRoot));
	  yyval->sym = yyr1[yyn];
	  yyval->child = allocate ((Allocator *)parse->alloc, 2*sizeof(Ast *));
	  yyval->child[0] = yyvsp[0];
	  yyvsp[0]->parent = yyval;
	  yyval->child[1] = NULL;
        }
#line 2544 "basilisk.c"
    break;


#line 2548 "basilisk.c"

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
    if (c->sym == YYSYMBOL_YYUNDEF || c->sym == YYSYMBOL_type_not_specified)
      assert (!c->parent);
    else {
      if (c->parent)
	remove_child (c);
      c->parent = ast;
      ast->child[ndef++] = c;
    }
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
      assert (t->after == NULL);
      t->after = t->start + strlen (t->start) - 1;
    }
  return stack;
}

static void stack_externalize (Stack * stack)
{
  Ast ** n;
  for (int i = 0; (n = stack_index (stack, i)); i++)
    if ((*n)->sym == YYSYMBOL_IDENTIFIER) {
      AstTerminal * t = ast_terminal (*n);
      t->after = NULL;
    }
}

Ast * ast_parse (const char * code, Allocator * alloc)
{
  AstRoot parse;
  parse.file = malloc (sizeof (char *));
  parse.nf = 1;
  parse.file[0] = strdup ("<basilisk>");
  parse.alloc = alloc ? alloc : new_allocator();
  parse.stack = stack_new (sizeof (Ast *));
  parse.type_already_specified = false;
  extern void lexer_setup (char * buffer, size_t len);
  size_t len = strlen (code) + 1;
  char * buffer = malloc (len + 1);
  memcpy (buffer, code, len);
  buffer[len] = '\0';
  lexer_setup (buffer, len + 1);
  //  yydebug = 1;
  Ast * n = NULL;
  yyparse (&parse, &n);
#if 0
  { // list global declarations
    Ast ** n;
    for (int i = 0; (n = stack_index (parse.stack, i)); i++)
      fprintf (stderr, "global: "), ast_print_file_line (*n, stderr);
  }
#endif
  if (n) {
    const char * i = copy_strings (buffer, n, code - buffer);
    const char * end = i; while (*end != '\0') end++;
    AstRoot * root = ast_root (n);
    root->after = copy_range (i, end, code - buffer);
    root->file = parse.file;
    root->nf = parse.nf;    
    root->alloc = alloc ? NULL : parse.alloc;
    root->stack = parse.stack;
  }
  else {
    if (!alloc)
      free_allocator (parse.alloc);
    stack_destroy (parse.stack);
  }
  free (buffer);
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
