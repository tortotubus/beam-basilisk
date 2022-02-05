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
#line 11 "basilisk.yacc"

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
  YYSYMBOL_183_1 = 183,                    /* @1  */
  YYSYMBOL_block_item_list = 184,          /* block_item_list  */
  YYSYMBOL_block_item = 185,               /* block_item  */
  YYSYMBOL_expression_statement = 186,     /* expression_statement  */
  YYSYMBOL_selection_statement = 187,      /* selection_statement  */
  YYSYMBOL_for_scope = 188,                /* for_scope  */
  YYSYMBOL_iteration_statement = 189,      /* iteration_statement  */
  YYSYMBOL_for_declaration_statement = 190, /* for_declaration_statement  */
  YYSYMBOL_jump_statement = 191,           /* jump_statement  */
  YYSYMBOL_external_declaration = 192,     /* external_declaration  */
  YYSYMBOL_function_declaration = 193,     /* function_declaration  */
  YYSYMBOL_function_definition = 194,      /* function_definition  */
  YYSYMBOL_declaration_list = 195,         /* declaration_list  */
  YYSYMBOL_basilisk_statements = 196,      /* basilisk_statements  */
  YYSYMBOL_macro_statement = 197,          /* macro_statement  */
  YYSYMBOL_foreach_statement = 198,        /* foreach_statement  */
  YYSYMBOL_foreach_parameters = 199,       /* foreach_parameters  */
  YYSYMBOL_foreach_parameter = 200,        /* foreach_parameter  */
  YYSYMBOL_reduction_list = 201,           /* reduction_list  */
  YYSYMBOL_reduction = 202,                /* reduction  */
  YYSYMBOL_reduction_operator = 203,       /* reduction_operator  */
  YYSYMBOL_foreach_inner_statement = 204,  /* foreach_inner_statement  */
  YYSYMBOL_foreach_dimension_statement = 205, /* foreach_dimension_statement  */
  YYSYMBOL_forin_declaration_statement = 206, /* forin_declaration_statement  */
  YYSYMBOL_forin_statement = 207,          /* forin_statement  */
  YYSYMBOL_forin_arguments = 208,          /* forin_arguments  */
  YYSYMBOL_field_list = 209,               /* field_list  */
  YYSYMBOL_field_item_list = 210,          /* field_item_list  */
  YYSYMBOL_event_definition = 211,         /* event_definition  */
  YYSYMBOL_event_parameters = 212,         /* event_parameters  */
  YYSYMBOL_event_parameter = 213,          /* event_parameter  */
  YYSYMBOL_boundary_definition = 214,      /* boundary_definition  */
  YYSYMBOL_external_foreach_dimension = 215, /* external_foreach_dimension  */
  YYSYMBOL_attribute = 216,                /* attribute  */
  YYSYMBOL_root = 217                      /* root  */
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
#define YYFINAL  188
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3618

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  346
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  613

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
       0,    61,    61,    62,    63,    64,    65,    69,    70,    71,
      72,    73,    77,    78,    82,    83,    84,    88,    92,    93,
      97,   101,   102,   106,   107,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   123,   124,   128,   129,   133,   137,
     138,   142,   143,   144,   148,   149,   150,   151,   152,   153,
     154,   155,   159,   160,   161,   162,   163,   164,   168,   169,
     175,   176,   177,   178,   182,   183,   184,   188,   189,   190,
     194,   195,   196,   197,   198,   202,   203,   204,   208,   209,
     213,   214,   218,   219,   223,   224,   228,   229,   233,   234,
     238,   239,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   257,   258,   262,   266,   267,   269,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   286,
     287,   291,   292,   296,   297,   298,   299,   300,   301,   302,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   325,   326,   327,   328,
     329,   333,   334,   338,   339,   343,   344,   345,   349,   350,
     351,   352,   356,   357,   361,   362,   363,   367,   368,   369,
     370,   371,   375,   376,   380,   381,   385,   389,   390,   391,
     392,   393,   397,   398,   402,   403,   407,   408,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   430,   431,   435,   436,   437,   438,   442,
     443,   448,   449,   453,   454,   458,   459,   460,   464,   465,
     469,   470,   474,   475,   476,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   504,   505,   506,   510,
     511,   512,   513,   517,   521,   522,   526,   527,   531,   535,
     536,   537,   538,   539,   540,   541,   542,   546,   547,   548,
     552,   554,   554,   560,   561,   565,   566,   570,   571,   575,
     576,   577,   581,   585,   586,   587,   589,   591,   595,   597,
     602,   603,   604,   605,   606,   610,   611,   612,   613,   614,
     615,   616,   620,   624,   626,   631,   632,   639,   640,   641,
     642,   643,   644,   648,   652,   653,   657,   658,   662,   663,
     667,   668,   672,   676,   677,   681,   682,   686,   687,   691,
     696,   701,   702,   706,   710,   711,   715,   719,   720,   721,
     725,   726,   730,   734,   735,   739,   743
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

#define YYPACT_NINF (-534)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-347)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1187,   -71,  -534,  -534,  -534,  -534,  -534,  2775,  2824,  2824,
    1434,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,  -534,  -534,  -534,    66,   -47,   -41,   -20,    11,
    -534,    61,  -534,  -534,  -534,  -534,    75,  1287,  -534,  -534,
    -534,  -534,  -534,  -534,   887,  -534,  -534,  -534,  -534,   196,
    -534,  -534,   718,  2873,  -534,   113,   120,   289,    56,   225,
     -37,    65,    73,   164,     7,  -534,   104,  -534,    60,  3422,
    3422,  -534,    96,  -534,  -534,  3422,  3422,  3422,   148,  -534,
    -534,  1439,  -534,  -534,  -534,  -534,  -534,   201,   140,  -534,
    -534,  1287,  -534,  -534,  1287,  -534,  -534,    18,   157,  1637,
    3542,  3542,  2873,  2873,    69,  -534,   171,  -534,   184,  3542,
     -28,  3542,   198,   147,  -534,    18,  -534,  -534,  2138,    18,
    2236,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,  2873,  -534,  -534,  2873,  2873,  2873,  2873,  2873,
    2873,  2873,  2873,  2873,  2873,  2873,  2873,  2873,  2873,  2873,
    2873,  2873,  2873,  2873,  -534,  -534,    31,   235,   206,  -534,
     -43,   -48,  -534,    80,  -534,  -534,  -534,  2887,   190,  -534,
    -534,  -534,  3464,   253,  -534,    60,  -534,  1439,  -534,  -534,
    1087,   226,   258,   271,   -58,  -534,  -534,    18,  -534,   283,
     287,   291,   293,   299,   302,   305,  3422,  -534,  2873,  -534,
    3109,  1691,   -13,  -534,    94,  -534,  2285,  -534,  -534,  -534,
    -534,  -534,  -534,    18,   205,  -534,  -534,   303,  -534,  -534,
    -534,   101,  -534,  -534,  -534,  -534,   113,   113,   120,   120,
     289,   289,   289,   289,    56,    56,   225,   -37,    65,    73,
     164,   231,   307,  -534,  -534,  -534,   235,  -534,    31,  2334,
    3009,  1741,   -48,   313,  3224,  -534,    35,  -534,  3064,  3272,
    2873,   310,  -534,  -534,   315,  2873,   312,   319,   320,   322,
    1342,  -534,    18,   330,   331,  2383,   332,   334,   336,  -534,
     -71,   208,  -534,   328,  -534,  -534,  -534,   987,  -534,  -534,
    -534,   337,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,
    -534,  -534,   335,   335,  2873,  -534,   162,   123,  -534,  -534,
    -534,  -534,  3503,   419,  3422,    31,  -534,  -534,  -534,    25,
     341,   340,  -534,   343,  1991,  -534,   338,   346,  1791,    94,
    3174,  1841,  2089,  -534,  -534,   142,  -534,  2432,  2334,  -534,
    2873,  -534,  -534,  -534,  -534,  2089,  -534,  -534,   348,  -534,
    -534,   350,   240,  1991,  -534,   349,   354,  1891,  -534,  -534,
    -534,  -534,  2873,   215,  -534,   359,   365,  3320,  -534,  -534,
     357,   167,  -534,  -534,   366,  1342,   575,   575,  2873,   392,
     372,  -534,  -534,  -534,   216,  2187,  2481,  2530,  -534,  -534,
    1342,  -534,  -534,  1539,  -534,  -534,  -534,  -534,   174,   368,
     247,  -534,   369,   373,  -534,  -534,  2944,  -534,    54,  -534,
    -534,  3374,  -534,   367,  1991,  -534,  -534,  2873,  -534,   374,
    -534,   375,  1991,  -534,   380,   381,  1941,    18,  2873,  -534,
     222,  2334,   195,  -534,  -534,    18,  -534,  -534,  -534,   229,
    -534,  -534,  -534,    18,   387,  1991,  -534,  -534,  2873,  -534,
     389,   391,  -534,  -534,    46,  2873,  -534,  -534,  2334,  2873,
    1342,  2873,  1342,  -534,   376,   379,   250,   398,  -534,  -534,
     399,  1342,  -534,   251,  -534,   405,  -534,  1342,   257,  1342,
     274,  -534,   -52,  2579,    60,  2579,  -534,  2873,  -534,  3503,
    2873,   406,  -534,  -534,  -534,   400,   402,  -534,  -534,   403,
    1991,  -534,  -534,  2873,  -534,   404,  -534,   407,  -534,   785,
    -534,  -534,  -534,  -534,  -534,  2040,  -534,  -534,   408,   409,
    -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  -534,  1342,
    1342,  1342,  2873,    12,  -534,  1342,  2628,  -534,  -534,  1342,
    -534,  1342,  2432,  2677,   414,  2726,  -534,  -534,  -534,  -534,
    -534,  -534,  -534,   410,   411,  -534,  -534,  -534,  -534,  2334,
    -534,  -534,  -534,   438,  -534,  -534,   278,  -534,  -534,   417,
    -534,  -534,  -534,  -534,   184,   413,  -534,  1342,   284,  2432,
    1342,   290,  -534,  -534,  -534,  1342,   423,    18,  1342,  -534,
    1342,   424,  -534,  1342,  -534,  -534,   425,  -534,  -534,  1342,
    -534,  -534,  -534
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
     183,     0,   126,   181,    51,   129,     0,     0,    52,    53,
      54,    55,    56,    57,     0,    25,     8,     9,    11,    44,
      27,    26,    58,     0,    60,    64,    67,    70,    75,    78,
      80,    82,    84,    86,    88,    90,     0,   296,     0,   110,
     112,   143,     0,   144,   142,   114,   116,   118,     7,   108,
       2,     0,   295,   297,   298,   299,   300,     0,   271,   301,
     204,     0,    48,     7,     0,    45,    46,     0,   171,     0,
       0,     0,     0,     0,     0,    13,     0,   103,    12,   159,
     221,   161,     0,     0,     3,     0,    30,    31,     0,     0,
       0,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    92,     0,    58,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   342,   106,     0,   208,     0,   119,
     302,   187,   188,     0,   145,   109,   111,     0,   148,   113,
     115,   117,     0,     0,   305,     0,   304,     0,     1,   270,
       0,     0,     0,   175,     0,   172,    17,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,    10,     0,   158,
       0,     0,   223,   220,   224,   160,     0,     4,     5,     6,
      29,    38,    36,     0,     0,    39,    41,     7,    43,    28,
      34,     0,    91,    61,    62,    63,    65,    66,    68,    69,
      73,    74,    71,    72,    76,    77,    79,    81,    83,    85,
      87,     0,     0,   180,   209,   207,   206,   107,     0,     0,
       0,     0,   186,     0,     0,   153,     0,   157,     0,     0,
       0,   122,   306,   303,     0,     0,     0,     0,     0,     0,
       0,   282,     0,     0,     0,     0,     0,     0,     0,   277,
      26,     0,   275,     7,   276,   259,   260,     0,   273,   261,
     262,     0,   263,   287,   264,   265,   307,   308,   309,   310,
     311,   312,    49,     0,     0,   167,     0,     0,   185,   184,
      50,   176,     0,     0,     0,     0,   343,   104,   242,   217,
       0,   212,   213,     0,     0,   226,    53,     0,     0,   222,
       0,     0,     0,    59,   334,     0,    37,     0,     0,    35,
       0,   189,   210,   205,   120,     0,   248,   121,     0,   201,
     218,     0,     0,     0,   190,    53,     0,     0,   149,   146,
     154,   155,     0,     0,   162,   166,     0,     0,   345,   340,
       7,     0,   337,   266,     0,     0,     0,     0,     0,     0,
       0,   291,   292,   293,     0,     0,     0,     0,   313,   278,
       0,   272,   274,     0,   174,   168,   173,   169,     0,     0,
       0,    21,     0,     0,   344,   302,     0,   215,   223,   216,
     243,     0,   225,     0,     0,   227,   233,     0,   232,     0,
     244,     0,     0,   234,    53,     0,     0,     0,     0,   250,
       0,     0,     0,   254,   333,     0,    40,    42,    89,     0,
     200,   199,   202,     0,     0,     0,   191,   198,     0,   197,
      53,     0,   164,   156,     0,     0,   150,   147,     0,     0,
       0,     0,     0,   269,     0,     0,     0,     0,   290,   294,
       0,     0,   318,     0,   316,   319,   320,     0,     0,     0,
       0,   267,     0,     0,     0,     0,   170,     0,    20,     0,
       0,     0,   211,   214,   229,     0,     0,   231,   245,     0,
       0,   235,   241,     0,   240,     0,   257,     0,    32,     0,
     249,   253,   255,   335,   246,     0,   219,   193,     0,     0,
     194,   196,   163,   165,   341,   339,   336,   338,   268,     0,
       0,     0,     0,     0,   314,     0,     0,   321,   325,     0,
     327,     0,     0,     0,   119,     0,    24,    22,    23,   258,
     228,   230,   237,     0,     0,   238,   256,    33,   252,     0,
     247,   192,   195,   280,   281,   283,     0,   324,   323,     0,
     315,   317,   326,   328,   331,     0,   332,     0,     0,     0,
       0,     0,   236,   239,   251,     0,     0,     0,     0,   288,
       0,     0,   285,     0,   279,   284,     0,   330,   289,     0,
     286,   322,   329
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -534,  -534,  -534,   -64,  -534,  -534,  -534,  -534,  -534,    10,
    -534,  -534,  -157,   386,  -534,   169,   539,  -534,   -53,   203,
     230,   110,   239,   361,   358,   360,   364,   370,  -534,  -104,
       8,  -534,   -29,  -111,   -85,    89,  -534,  -257,  -534,   -24,
    -534,  -534,  -116,  -247,   -69,  -534,    58,  -534,   333,  -263,
    -534,   301,  -534,  -534,   -75,  -169,     0,  -107,  -180,  -156,
    -534,   107,  -534,   125,  -108,  -205,  -248,   176,  -482,  -534,
      87,  -153,   234,  -534,    15,  -534,  -534,   237,  -356,  -534,
    -534,  -534,  -534,  -534,   481,  -534,  -192,  -534,  -534,  -534,
    -534,  -534,   -10,  -534,    52,  -534,  -534,  -534,  -534,  -534,
     -51,  -533,  -534,  -534,  -534,  -273,  -534,  -534,  -534,  -534
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    54,    55,   116,    56,   193,    57,    58,   410,   411,
      59,    60,    61,   220,   224,   225,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     117,   142,   291,   199,    77,   329,   168,   169,    79,    80,
      81,    82,   264,   265,   120,   373,   374,    83,   194,   195,
      84,    85,    86,    87,   271,   171,   103,   173,   256,   330,
     331,   332,   362,   412,   333,   214,   439,   440,   441,   442,
     443,    89,   294,   295,   296,   190,   297,   298,   299,   300,
     301,   302,   303,   304,    90,    91,    92,   187,   305,   306,
     307,   483,   484,   485,   486,   579,   308,   309,   310,   311,
     585,   228,   345,    93,   381,   382,    94,    95,    96,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,   354,   204,   170,   262,   198,   184,   339,    76,   198,
     144,   357,   213,   212,   326,     2,    99,   370,   118,   586,
      98,     2,   370,   119,   267,   552,   162,   315,     2,   267,
     316,   338,   399,   290,     2,   108,   208,   569,     2,   260,
     109,  -122,   100,   569,   261,  -122,   110,   495,   100,     2,
     209,   259,   215,   406,    88,   100,   586,     2,   158,   210,
     255,   100,    76,     2,   211,   100,   269,   111,   167,     2,
     152,   153,   118,   205,   210,   118,   100,   119,   172,   211,
     119,   367,   178,     2,   100,   119,   119,   119,   183,    78,
     100,   252,   233,   234,   235,   119,   100,   119,   112,     2,
     447,   231,   272,   212,   361,   292,   186,   196,   266,   577,
     100,   267,   416,   266,   163,   267,   267,   211,   166,   371,
     203,   167,   166,   290,   372,   221,   100,   167,   227,   221,
     370,   167,   414,   166,   251,   372,   226,   553,    99,   555,
     290,   416,   167,    78,   165,   406,   211,   166,   113,   353,
     232,     2,   377,   119,   424,   206,   167,   107,   119,   154,
     155,   436,   114,   343,   384,     2,   172,   166,   175,   176,
     159,   198,   122,   172,   179,   180,   181,     2,   100,   160,
     185,   340,   161,   455,   431,   172,   341,   177,   164,   208,
     293,   375,   100,   520,   349,   266,   535,   196,   537,   266,
     266,   188,   273,   404,   100,   125,   126,   127,   407,   145,
     198,   408,   292,   339,   146,   147,   327,   148,   149,   337,
     534,   419,   418,   344,   267,   189,   191,   444,   290,   192,
     445,   217,   218,   219,   200,   201,   202,   554,    98,   182,
     119,   156,   157,   290,   119,   119,   448,   405,   197,   262,
     415,   469,   510,   470,   417,   471,   394,   207,   172,   496,
     360,   462,   240,   241,   242,   243,   172,   356,   198,   366,
     380,   568,   208,    18,    19,    20,   185,   568,   379,   185,
     293,   268,   390,   128,   216,   437,   129,   438,   130,   521,
     257,   346,   399,   347,   258,   325,   208,   293,   119,   463,
     479,   150,   151,   464,   208,   398,   253,   518,   266,   418,
     519,    43,   312,   290,   524,   290,   196,   525,   493,   208,
     350,   594,   474,   475,   290,   172,   452,   517,   453,   172,
     290,   167,   290,   498,   198,   499,   541,   545,   208,   546,
     270,   252,   423,   549,   313,   208,   429,   227,   121,   435,
     356,   236,   237,   119,   533,   226,   356,   118,   118,   476,
     551,   198,   208,   356,   596,   314,   208,   488,   490,   318,
     600,   454,   208,   319,   492,   461,   603,   320,   208,   321,
     238,   239,   290,   290,   290,   293,   185,   322,   290,   375,
     323,   324,   290,   351,   290,   244,   245,   348,   368,   383,
     293,   385,   121,   482,   259,   121,   386,   387,   196,   388,
     121,   121,   121,   325,   391,   392,   172,   400,   172,   395,
     121,   396,   121,   397,   403,   413,   342,   420,   421,   422,
     290,   425,   505,   290,   450,   506,   451,   516,   290,   426,
     509,   290,   456,   290,   515,   523,   290,   457,   465,   356,
     466,   468,   290,   526,   477,   472,   478,   497,   500,   501,
     504,   508,   539,   528,   172,   540,   529,   507,   254,   380,
     293,   380,   293,   511,   512,   119,   356,   379,   121,   379,
     527,   293,   530,   121,   531,   542,   543,   293,   480,   293,
     559,   589,   494,   560,   172,   561,   562,   565,   595,   598,
     566,   571,   572,   592,   593,   556,   597,   605,   558,   557,
     609,   611,   254,   576,   389,   229,   446,   247,   563,   246,
     248,   564,   532,   584,   588,   249,   591,   356,   503,   522,
     317,   449,   250,   356,   402,   124,   581,   547,   601,   293,
     293,   293,     0,   578,     0,   293,   102,   105,   106,   293,
       0,   293,     0,     0,   482,     0,     0,   352,     0,     0,
     584,     0,   254,     0,     0,   121,     0,     0,     0,   121,
     121,     0,     0,     0,     0,     0,   115,   356,     2,     3,
       4,     5,     6,     7,     0,     8,     9,   293,     0,     0,
     293,     0,     0,     0,     0,   293,     0,   606,   293,     0,
     293,     0,   143,   293,     0,   100,    11,     0,     0,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   473,
       0,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,   254,     0,     0,     0,   352,
       0,     0,   254,     0,     0,    37,     0,    39,   143,     0,
       0,     0,   143,    44,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,   254,     0,     0,     0,   352,     0,
      48,    49,    50,    51,    52,    53,     0,     0,   121,     0,
       0,     0,     0,     0,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,     0,     0,   536,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,   544,     0,     0,     0,     0,
       0,   548,     0,   550,     0,   352,     0,     0,     0,     0,
       0,     0,     0,   254,     0,     0,     0,   352,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,   143,   352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   573,   574,   575,     0,     0,     0,   580,
       0,     0,     0,   582,     0,   583,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   352,   141,     0,   143,   100,    11,     0,     0,     0,
       0,   599,     0,     0,   602,     0,     0,     0,     0,   604,
       0,     0,   607,     0,   608,     0,     0,   610,     0,     0,
       0,     0,     0,   612,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,     0,    37,     0,    39,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
     567,     0,    47,     0,     0,   437,   355,   438,     0,     0,
      48,    49,    50,    51,    52,    53,     0,  -346,   123,   143,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,     0,     0,    46,
       0,     0,     0,     0,    47,     0,     0,   143,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,   274,     0,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,   275,   276,   277,     0,   278,   279,
     280,   281,   282,   283,   284,   285,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,   286,   287,   288,
       0,   289,   401,     0,    47,     0,     0,     0,    98,     0,
       0,     0,    48,    49,    50,    51,    52,    53,   274,     0,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,   275,   276,   277,     0,   278,   279,
     280,   281,   282,   283,   284,   285,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,   286,   287,   288,
       0,   289,     0,     0,    47,     0,     0,     0,    98,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     1,     0,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,     0,     0,    46,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,   115,     0,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,   274,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,    37,    38,    39,
       0,     0,     0,    43,     0,    44,     0,     0,     0,     0,
       0,     0,   100,    11,    47,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   275,
     276,   277,     0,   278,   279,   280,   281,   282,   283,   284,
     285,     0,    37,     0,    39,     0,     0,     0,     0,     0,
      44,     0,   286,   287,   288,     0,   289,     0,     0,    47,
       0,     0,     0,    98,     0,     0,     0,    48,    49,    50,
      51,    52,    53,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,     0,     0,     0,     0,     0,   174,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,     0,
      38,  -204,    40,    41,    42,    43,     0,     0,    45,     0,
       0,     0,     0,  -204,  -204,  -204,     0,     0,  -204,  -204,
      98,  -204,  -204,     0,     0,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,     0,
       0,     0,     0,   289,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,    53,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,    37,    38,    39,
       0,     0,     0,    43,     0,    44,     0,     0,     0,     0,
       0,   100,    11,     0,    47,   334,     0,     0,     0,    18,
      19,    20,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,    37,   253,    39,     0,     0,     0,    43,     0,    44,
       0,   100,    11,     0,     0,   363,     0,     0,    47,    18,
      19,    20,     0,     0,   335,     0,    48,   336,    50,    51,
      52,    53,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,    37,   253,    39,     0,     0,     0,    43,     0,    44,
       0,   100,    11,     0,     0,   427,     0,     0,    47,    18,
      19,    20,     0,     0,   364,     0,    48,   365,    50,    51,
      52,    53,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,    37,   253,    39,     0,     0,     0,    43,     0,    44,
       0,   100,    11,     0,     0,   432,     0,     0,    47,    18,
      19,    20,     0,     0,   428,     0,    48,    49,    50,    51,
      52,    53,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,    37,   253,    39,     0,     0,     0,    43,     0,    44,
       0,   100,    11,     0,     0,   458,     0,     0,    47,    18,
      19,    20,     0,     0,   433,     0,    48,   434,    50,    51,
      52,    53,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,    37,   253,    39,     0,     0,     0,    43,     0,    44,
       0,   100,    11,     0,     0,   513,     0,     0,    47,    18,
      19,    20,     0,     0,   459,     0,    48,   460,    50,    51,
      52,    53,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,    37,   253,    39,     0,     0,     0,    43,     0,    44,
       0,   100,    11,     0,     0,     0,     0,     0,    47,    18,
      19,    20,     0,     0,   514,     0,    48,    49,    50,    51,
      52,    53,     0,     2,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,   253,    39,     0,     0,     0,    43,     0,    44,
     100,    11,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    39,     0,     0,     0,     0,     0,    44,   100,
      11,     0,     0,     0,     0,   570,     0,    47,     0,     0,
     437,   355,   438,     0,     0,    48,    49,    50,    51,    52,
      53,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,    44,   100,    11,
       0,     0,     0,     0,     0,     0,    47,     0,     0,   437,
     355,   438,     0,     0,    48,    49,    50,    51,    52,    53,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,     0,     0,    44,   100,    11,     0,
       0,     0,     0,     0,   222,    47,     0,     0,     0,   223,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,     0,    44,   100,    11,     0,     0,
     480,     0,     0,   481,    47,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,     0,     0,    44,   100,    11,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,   230,
       0,    48,    49,    50,    51,    52,    53,     2,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,     0,    44,   100,    11,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,   342,     0,     0,     0,
      48,    49,    50,    51,    52,    53,     2,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
       0,     0,    44,   100,    11,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,   355,     0,     0,     0,    48,
      49,    50,    51,    52,    53,     2,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,    44,   100,    11,     0,     0,     0,   393,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,     0,     0,
      44,   100,    11,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,   223,     0,     0,     0,    48,    49,    50,
      51,    52,    53,     2,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,     0,    44,
     100,    11,     0,     0,     0,     0,     0,   487,    47,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,    53,     2,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    39,     0,     0,     0,     0,     0,    44,   100,
      11,     0,     0,     0,     0,     0,   489,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,     2,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,    44,   100,    11,
       0,     0,     0,   289,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,    53,
       2,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,     0,     0,    44,   100,    11,     0,
       0,   480,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,     2,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,     0,    44,   100,    11,     0,     0,
       0,     0,     0,   587,    47,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,     0,     0,    44,   100,    11,     0,     0,     0,
       0,     0,   590,    47,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,     2,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,     0,    44,   100,    11,     0,     0,     0,     0,
       0,     0,   101,     0,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,    53,     2,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,   263,     0,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
       0,     0,    44,   100,    11,     0,     0,     0,     0,     0,
       0,   104,     0,     0,     0,     0,     0,   174,     0,    48,
      49,    50,    51,    52,    53,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    37,     0,    39,     0,     2,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,    38,     0,
      47,    41,     0,    43,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    10,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     358,     0,     2,    36,     0,    38,     0,    40,     0,    42,
      43,     0,     0,    45,     0,     0,     0,     0,     0,     0,
     328,   416,     0,     0,     0,     0,   211,     0,     0,    10,
     167,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   376,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,     0,
      38,     0,    40,     0,    42,    43,     0,     0,    45,     0,
       0,     0,     0,     0,   174,   359,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    41,   174,
      43,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,     0,
      38,     0,    40,     0,    42,    43,     0,     0,    45,     0,
       0,     0,     0,     0,     0,   328,   210,     0,     0,     0,
       0,   211,     0,     0,   174,   167,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,    38,     0,    40,     0,    42,
      43,     0,     0,    45,   174,     0,     0,     0,     0,     0,
     430,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    41,     0,
      43,     0,   174,     0,     0,     0,     0,     0,     0,   369,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,    41,     0,    43,     0,
     174,     0,     0,     0,     0,     0,     0,   378,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,    41,     0,    43,     0,     0,     0,
       0,     0,     0,     0,   174,   467,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     502,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,    38,     0,    40,     0,    42,
      43,     0,   174,    45,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    38,   174,    40,     0,    42,    43,     0,
       0,    45,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,    38,     0,     0,    41,     0,
      43,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,   409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   174,     0,    38,     0,     0,     0,     0,    43,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
       0,   258,   113,    78,   173,   109,    91,   212,     0,   113,
      63,   259,   120,   120,   206,     3,     1,   264,    47,   552,
      91,     3,   269,    47,   177,    77,    19,    85,     3,   182,
      88,   211,    84,   190,     3,    35,    88,   519,     3,    87,
      87,    84,    30,   525,    92,    88,    87,   403,    30,     3,
     119,    94,   121,   316,    54,    30,   589,     3,    95,    87,
     167,    30,    54,     3,    92,    30,   182,    87,    96,     3,
      14,    15,   101,     4,    87,   104,    30,   101,    78,    92,
     104,   261,    82,     3,    30,   109,   110,   111,    88,     0,
      30,   166,   145,   146,   147,   119,    30,   121,    87,     3,
     348,   130,   187,   210,   260,   190,    91,   107,   177,    97,
      30,   264,    87,   182,   107,   268,   269,    92,    87,    84,
     112,    96,    87,   280,    89,   125,    30,    96,   128,   129,
     377,    96,   324,    87,   163,    89,   128,   493,   123,   495,
     297,    87,    96,    54,    84,   408,    92,    87,    87,   256,
     142,     3,   268,   177,   334,    86,    96,    91,   182,   103,
     104,   341,    87,   216,   275,     3,   166,    87,    79,    80,
     105,   275,    47,   173,    85,    86,    87,     3,    30,   106,
      91,    87,    18,   363,   340,   185,    92,    91,    84,    88,
     190,   266,    30,   441,    93,   264,   469,   197,   471,   268,
     269,     0,   187,   314,    30,     9,    10,    11,    85,    96,
     314,    88,   297,   418,   101,   102,   208,    97,    98,   211,
     468,   329,   329,   223,   377,    85,   101,    85,   385,   104,
      88,    84,    85,    86,   109,   110,   111,   494,    91,    91,
     264,    16,    17,   400,   268,   269,   350,    85,    91,   418,
     325,    84,   432,    86,   329,    88,   285,    86,   258,    85,
     260,   372,   152,   153,   154,   155,   266,   259,   372,   261,
     270,   519,    88,    38,    39,    40,   187,   525,   270,   190,
     280,    91,   282,    87,    86,    90,    90,    92,    92,    94,
      84,    86,    84,    88,    88,   206,    88,   297,   322,    84,
      84,    12,    13,    88,    88,   290,    71,    85,   377,   416,
      88,    76,    86,   470,    85,   472,   316,    88,   403,    88,
      89,   569,   386,   387,   481,   325,    86,   438,    88,   329,
     487,    96,   489,    86,   438,    88,    86,    86,    88,    88,
      87,   416,   334,    86,    86,    88,   338,   347,    47,   341,
     342,   148,   149,   377,   465,   347,   348,   386,   387,   388,
      86,   465,    88,   355,    86,    94,    88,   396,   397,    86,
      86,   363,    88,    86,   403,   367,    86,    86,    88,    86,
     150,   151,   539,   540,   541,   385,   297,    88,   545,   464,
      88,    86,   549,    86,   551,   156,   157,    94,    85,    84,
     400,    89,   101,   395,    94,   104,    87,    87,   408,    87,
     109,   110,   111,   324,    84,    84,   416,    89,   418,    87,
     119,    87,   121,    87,    87,     6,    91,    86,    88,    86,
     587,    93,   424,   590,    86,   427,    86,   437,   595,    93,
     432,   598,    93,   600,   436,   445,   603,    93,    89,   441,
      85,    94,   609,   453,    62,    89,    84,    89,    89,    86,
      93,    86,    86,   455,   464,    86,   458,    93,   167,   469,
     470,   471,   472,    93,    93,   499,   468,   469,   177,   471,
      93,   481,    93,   182,    93,    87,    87,   487,    83,   489,
      84,    77,   403,    93,   494,    93,    93,    93,    60,    86,
      93,    93,    93,    93,    93,   497,    89,    84,   500,   499,
      86,    86,   211,   542,   280,   129,   347,   159,   510,   158,
     160,   513,   464,   552,   553,   161,   555,   519,   421,   442,
     197,   355,   162,   525,   297,    54,   546,   485,   589,   539,
     540,   541,    -1,   543,    -1,   545,     7,     8,     9,   549,
      -1,   551,    -1,    -1,   546,    -1,    -1,   256,    -1,    -1,
     589,    -1,   261,    -1,    -1,   264,    -1,    -1,    -1,   268,
     269,    -1,    -1,    -1,    -1,    -1,     1,   569,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,   587,    -1,    -1,
     590,    -1,    -1,    -1,    -1,   595,    -1,   597,   598,    -1,
     600,    -1,    63,   603,    -1,    30,    31,    -1,    -1,   609,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,
      -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   400,   334,    -1,    -1,    -1,   338,
      -1,    -1,   341,    -1,    -1,    70,    -1,    72,   109,    -1,
      -1,    -1,   113,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,   363,    -1,    -1,    -1,   367,    -1,
      95,    96,    97,    98,    99,   100,    -1,    -1,   377,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,    -1,    -1,   470,    -1,   472,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,    -1,
      -1,   487,    -1,   489,    -1,   424,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   432,    -1,    -1,    -1,   436,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,   455,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   539,   540,   541,    -1,    -1,    -1,   545,
      -1,    -1,    -1,   549,    -1,   551,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
     499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   510,    94,    -1,   275,    30,    31,    -1,    -1,    -1,
      -1,   587,    -1,    -1,   590,    -1,    -1,    -1,    -1,   595,
      -1,    -1,   598,    -1,   600,    -1,    -1,   603,    -1,    -1,
      -1,    -1,    -1,   609,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   314,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    87,    -1,    -1,    90,    91,    92,    -1,    -1,
      95,    96,    97,    98,    99,   100,    -1,     0,     1,   350,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   372,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    87,    -1,    -1,   438,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,   465,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      -1,    84,    85,    -1,    87,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    80,    81,    82,    -1,    84,    -1,    -1,    87,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    77,    73,    74,    75,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,
      91,    97,    98,    -1,    -1,   101,   102,   103,   104,   105,
     106,   107,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    87,    34,    -1,    -1,    -1,    38,
      39,    40,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,
      -1,    30,    31,    -1,    -1,    34,    -1,    -1,    87,    38,
      39,    40,    -1,    -1,    93,    -1,    95,    96,    97,    98,
      99,   100,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,
      -1,    30,    31,    -1,    -1,    34,    -1,    -1,    87,    38,
      39,    40,    -1,    -1,    93,    -1,    95,    96,    97,    98,
      99,   100,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,
      -1,    30,    31,    -1,    -1,    34,    -1,    -1,    87,    38,
      39,    40,    -1,    -1,    93,    -1,    95,    96,    97,    98,
      99,   100,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,
      -1,    30,    31,    -1,    -1,    34,    -1,    -1,    87,    38,
      39,    40,    -1,    -1,    93,    -1,    95,    96,    97,    98,
      99,   100,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,
      -1,    30,    31,    -1,    -1,    34,    -1,    -1,    87,    38,
      39,    40,    -1,    -1,    93,    -1,    95,    96,    97,    98,
      99,   100,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    87,    38,
      39,    40,    -1,    -1,    93,    -1,    95,    96,    97,    98,
      99,   100,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    78,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    30,
      31,    -1,    -1,    -1,    -1,    85,    -1,    87,    -1,    -1,
      90,    91,    92,    -1,    -1,    95,    96,    97,    98,    99,
     100,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    90,
      91,    92,    -1,    -1,    95,    96,    97,    98,    99,   100,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    30,    31,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    78,    30,    31,    -1,    -1,
      83,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    95,    96,    97,    98,    99,   100,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    78,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    78,    30,    31,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      78,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,
      30,    31,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    30,
      31,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    78,    30,    31,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    30,    31,    -1,
      -1,    83,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    78,    30,    31,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    78,    30,    31,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    78,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    78,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    30,    -1,    95,
      96,    97,    98,    99,   100,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    70,    -1,    72,    -1,     3,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      87,    74,    -1,    76,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,    69,    -1,    71,    -1,    73,    -1,    75,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    30,
      96,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    73,    -1,    75,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    30,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    30,
      76,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    73,    -1,    75,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    30,    96,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,
      76,    -1,    -1,    79,    30,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
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
      -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,
      76,    -1,    30,    79,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    30,    73,    -1,    75,    76,    -1,
      -1,    79,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    71,    -1,    -1,    74,    -1,
      76,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    71,    -1,    -1,    -1,    -1,    76,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    76
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
     147,   148,   149,   155,   158,   159,   160,   161,   164,   179,
     192,   193,   194,   211,   214,   215,   216,   217,    91,   182,
      30,    87,   124,   164,    87,   124,   124,    91,   164,    87,
      87,    87,    87,    87,    87,     1,   111,   138,   140,   147,
     152,   159,   171,     1,   192,     9,    10,    11,    87,    90,
      92,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    94,   139,   124,   126,    96,   101,   102,    97,    98,
      12,    13,    14,    15,   103,   104,    16,    17,    95,   105,
     106,    18,    19,   107,    84,    84,    87,    96,   144,   145,
     162,   163,   164,   165,    30,   143,   143,    91,   164,   143,
     143,   143,    91,   164,   142,   143,   182,   195,     0,    85,
     183,   171,   171,   113,   156,   157,   164,    91,   137,   141,
     171,   171,   171,   138,   141,     4,    86,    86,    88,   152,
      87,    92,   165,   172,   173,   152,    86,    84,    85,    86,
     121,   164,    86,    91,   122,   123,   138,   164,   209,   121,
      93,   140,   138,   126,   126,   126,   127,   127,   128,   128,
     129,   129,   129,   129,   130,   130,   131,   132,   133,   134,
     135,   140,   162,    71,   159,   165,   166,    84,    88,    94,
      87,    92,   163,     1,   150,   151,   152,   179,    91,   150,
      87,   162,   142,   182,     1,    57,    58,    59,    61,    62,
      63,    64,    65,    66,    67,    68,    80,    81,    82,    84,
     120,   140,   142,   164,   180,   181,   182,   184,   185,   186,
     187,   188,   189,   190,   191,   196,   197,   198,   204,   205,
     206,   207,    86,    86,    94,    85,    88,   156,    86,    86,
      86,    86,    88,    88,    86,   143,   194,   138,    86,   143,
     167,   168,   169,   172,    34,    93,    96,   138,   166,   173,
      87,    92,    91,   126,   164,   210,    86,    88,    94,    93,
      89,    86,   159,   165,   145,    91,   138,   174,     1,    86,
     164,   167,   170,    34,    93,    96,   138,   166,    85,    85,
     151,    84,    89,   153,   154,   162,     1,   150,    85,   138,
     164,   212,   213,    84,   141,    89,    87,    87,    87,   180,
     164,    84,    84,    84,   140,    87,    87,    87,   182,    84,
      89,    85,   185,    87,   141,    85,   157,    85,    88,    58,
     116,   117,   171,     6,   194,   162,    87,   162,   165,   172,
      86,    88,    86,   138,   166,    93,    93,    34,    93,   138,
      86,   167,    34,    93,    96,   138,   166,    90,    92,   174,
     175,   176,   177,   178,    85,    88,   123,   174,   137,   175,
      86,    86,    86,    88,   138,   166,    93,    93,    34,    93,
      96,   138,   141,    84,    88,    89,    85,    85,    94,    84,
      86,    88,    89,   180,   111,   111,   140,    62,    84,    84,
      83,    86,   138,   199,   200,   201,   202,    86,   140,    86,
     140,   180,   140,   142,   143,   186,    85,    89,    86,    88,
      89,    86,    56,   169,    93,   138,   138,    93,    86,   138,
     166,    93,    93,    34,    93,   138,   164,   141,    85,    88,
     174,    94,   178,   164,    85,    88,   164,    93,   138,   138,
      93,    93,   154,   141,   174,   213,   180,   213,   180,    86,
      86,    86,    87,    87,   180,    86,    88,   202,   180,    86,
     180,    86,    77,   186,   145,   186,   138,   117,   138,    84,
      93,    93,    93,   138,   138,    93,    93,    85,   174,   176,
      85,    93,    93,   180,   180,   180,   140,    97,   164,   203,
     180,   200,   180,   180,   140,   208,   209,    86,   140,    77,
      86,   140,    93,    93,   174,    60,    86,    89,    86,   180,
      86,   208,   180,    86,   180,    84,   164,   180,   180,    86,
     180,    86,   180
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
     182,   183,   182,   184,   184,   185,   185,   186,   186,   187,
     187,   187,   188,   189,   189,   189,   189,   189,   190,   190,
     191,   191,   191,   191,   191,   192,   192,   192,   192,   192,
     192,   192,   193,   194,   194,   195,   195,   196,   196,   196,
     196,   196,   196,   197,   198,   198,   199,   199,   200,   200,
     201,   201,   202,   203,   203,   204,   204,   205,   205,   206,
     207,   208,   208,   209,   210,   210,   211,   212,   212,   212,
     213,   213,   214,   215,   215,   216,   217
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
       2,     0,     4,     1,     2,     1,     1,     1,     2,     7,
       5,     5,     1,     5,     7,     6,     7,     1,     6,     7,
       3,     2,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     4,     5,     1,     3,     1,     1,
       1,     2,     6,     1,     1,     4,     5,     4,     5,     8,
       7,     1,     1,     3,     1,     3,     6,     1,     3,     3,
       1,     3,     2,     4,     5,     4,     1
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
#line 63 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2388 "basilisk.c"
    break;

  case 5: /* translation_unit: translation_unit error '}'  */
#line 64 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2394 "basilisk.c"
    break;

  case 6: /* translation_unit: translation_unit error ')'  */
#line 65 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2400 "basilisk.c"
    break;

  case 13: /* expression_error: error  */
#line 78 "basilisk.yacc"
                        { yyvsp[0]->sym = YYSYMBOL_YYerror; }
#line 2406 "basilisk.c"
    break;

  case 106: /* declaration: declaration_specifiers ';'  */
#line 266 "basilisk.yacc"
                                                          { ast_push_declaration (parse->stack, yyval); }
#line 2412 "basilisk.c"
    break;

  case 107: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 267 "basilisk.yacc"
                                                          { type_definition ((Allocator *)parse->alloc, yyval);
                                                            ast_push_declaration (parse->stack, yyval); }
#line 2419 "basilisk.c"
    break;

  case 149: /* struct_or_union_specifier: struct_or_union '{' error '}'  */
#line 328 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2425 "basilisk.c"
    break;

  case 150: /* struct_or_union_specifier: struct_or_union generic_identifier '{' error '}'  */
#line 329 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2431 "basilisk.c"
    break;

  case 200: /* direct_declarator: direct_declarator '(' error ')'  */
#line 424 "basilisk.yacc"
                                                                        { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2437 "basilisk.c"
    break;

  case 266: /* statement: error ';'  */
#line 542 "basilisk.yacc"
                     { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2443 "basilisk.c"
    break;

  case 271: /* @1: %empty  */
#line 554 "basilisk.yacc"
                           { stack_push (parse->stack, &(yyvsp[0])); yyval->sym = YYSYMBOL_YYUNDEF; }
#line 2449 "basilisk.c"
    break;

  case 272: /* compound_statement: '{' @1 block_item_list '}'  */
#line 556 "basilisk.yacc"
                           { ast_pop_scope (parse->stack, yyvsp[-3]); }
#line 2455 "basilisk.c"
    break;

  case 282: /* for_scope: FOR  */
#line 581 "basilisk.yacc"
              { stack_push (parse->stack, &(yyval)); }
#line 2461 "basilisk.c"
    break;

  case 285: /* iteration_statement: for_scope '(' expression_statement expression_statement ')' statement  */
#line 588 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2467 "basilisk.c"
    break;

  case 286: /* iteration_statement: for_scope '(' expression_statement expression_statement expression ')' statement  */
#line 590 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2473 "basilisk.c"
    break;

  case 288: /* for_declaration_statement: for_scope '(' declaration expression_statement ')' statement  */
#line 596 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 2479 "basilisk.c"
    break;

  case 289: /* for_declaration_statement: for_scope '(' declaration expression_statement expression ')' statement  */
#line 598 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2485 "basilisk.c"
    break;

  case 301: /* external_declaration: error compound_statement  */
#line 616 "basilisk.yacc"
                                                { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 2491 "basilisk.c"
    break;

  case 302: /* function_declaration: declaration_specifiers declarator  */
#line 620 "basilisk.yacc"
                                                { ast_push_function_definition (parse->stack, yyvsp[0]); }
#line 2497 "basilisk.c"
    break;

  case 303: /* function_definition: function_declaration declaration_list compound_statement  */
#line 625 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-2]->child[1]); }
#line 2503 "basilisk.c"
    break;

  case 304: /* function_definition: function_declaration compound_statement  */
#line 627 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-1]->child[1]); }
#line 2509 "basilisk.c"
    break;

  case 329: /* forin_declaration_statement: for_scope '(' declaration_specifiers init_declarator IN forin_arguments ')' statement  */
#line 692 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-7]); }
#line 2515 "basilisk.c"
    break;

  case 330: /* forin_statement: for_scope '(' expression IN forin_arguments ')' statement  */
#line 697 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 2521 "basilisk.c"
    break;

  case 346: /* root: translation_unit  */
#line 743 "basilisk.yacc"
                           {
	  yyval = *root = allocate ((Allocator *)parse->alloc, sizeof(AstRoot));
	  memset (yyval, 0, sizeof(AstRoot));
	  yyval->sym = yyr1[yyn];
	  yyval->child = allocate ((Allocator *)parse->alloc, 2*sizeof(Ast *));
	  yyval->child[0] = yyvsp[0];
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

#line 753 "basilisk.yacc"


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
  int ndef = 0;
  for (int i = 0; i < n; i++) {
    Ast * c = children[i + 1 - n];
    if (c->sym != YYSYMBOL_YYUNDEF)
      ndef++;
  }  
  ast->child = allocate (alloc, (ndef + 1)*sizeof(Ast *));
  ndef = 0;
  for (int i = 0; i < n; i++) {
    Ast * c = children[i + 1 - n];
    if (c->sym == YYSYMBOL_YYUNDEF)
      assert (!c->parent);
    else {
      if (c->parent)
	remove_child (c);
      c->parent = ast;
      ast->child[ndef++] = c;
      ast->child[ndef] = NULL;
    }
  }
  return ast;
}

Ast * ast_parse (const char * code)
{
  AstRoot parse;
  parse.file = malloc (sizeof (char *));
  parse.nf = 1;
  parse.file[0] = strdup ("<basilisk>");
  parse.alloc = new_allocator();
  parse.stack = stack_new (sizeof (Ast *));
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
    n = recopy_ast (n);
    const char * end = i; while (*end != '\0') end++;
    AstRoot * root = ast_root (n);
    root->after = copy_range (i, end, code - buffer);
    root->file = parse.file;
    root->nf = parse.nf;
  }
  free (buffer);
  free_allocator (parse.alloc);
  stack_destroy (parse.stack);
  typedef_cleanup();
  yylex_destroy();
  //  exit (1);
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

Ast * internal_identifier_declaration (Stack * stack, const char * identifier)
{
  Ast ** d;
  for (int i = 0; (d = stack_index (stack, i)); i++)
    if ((*d)->sym == YYSYMBOL_IDENTIFIER) {
      char * s = ast_terminal(*d)->start, * end = ast_terminal(*d)->after;
      const char * i = identifier;
      for (; *i != '\0' && s <= end && *s == *i; s++, i++);
      if (*i == '\0' && s == end + 1)
	return *d;
    }
  return NULL;
}
