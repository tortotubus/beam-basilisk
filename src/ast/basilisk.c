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
  YYSYMBOL_FOREACH_DIMENSION = 79,         /* FOREACH_DIMENSION  */
  YYSYMBOL_REDUCTION = 80,                 /* REDUCTION  */
  YYSYMBOL_MACRO = 81,                     /* MACRO  */
  YYSYMBOL_ELLIPSIS_MACRO = 82,            /* ELLIPSIS_MACRO  */
  YYSYMBOL_foreach_statement = 83,         /* foreach_statement  */
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
  YYSYMBOL_macro_statement = 200,          /* macro_statement  */
  YYSYMBOL_reduction_list = 201,           /* reduction_list  */
  YYSYMBOL_reduction = 202,                /* reduction  */
  YYSYMBOL_reduction_operator = 203,       /* reduction_operator  */
  YYSYMBOL_reduction_array = 204,          /* reduction_array  */
  YYSYMBOL_foreach_dimension_statement = 205, /* foreach_dimension_statement  */
  YYSYMBOL_forin_declaration_statement = 206, /* forin_declaration_statement  */
  YYSYMBOL_forin_statement = 207,          /* forin_statement  */
  YYSYMBOL_forin_arguments = 208,          /* forin_arguments  */
  YYSYMBOL_event_definition = 209,         /* event_definition  */
  YYSYMBOL_event_parameters = 210,         /* event_parameters  */
  YYSYMBOL_event_parameter = 211,          /* event_parameter  */
  YYSYMBOL_boundary_definition = 212,      /* boundary_definition  */
  YYSYMBOL_external_foreach_dimension = 213, /* external_foreach_dimension  */
  YYSYMBOL_attribute = 214,                /* attribute  */
  YYSYMBOL_new_field = 215,                /* new_field  */
  YYSYMBOL_root = 216                      /* root  */
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
#define YYFINAL  200
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3506

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  353
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  633

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
       0,   116,   116,   117,   118,   119,   120,   124,   125,   126,
     127,   128,   129,   133,   134,   138,   139,   140,   144,   148,
     149,   153,   157,   158,   162,   163,   167,   168,   169,   170,
     171,   172,   173,   174,   178,   179,   183,   184,   185,   189,
     190,   194,   198,   199,   200,   204,   205,   209,   210,   211,
     212,   213,   214,   215,   216,   220,   221,   222,   223,   224,
     225,   229,   230,   236,   237,   238,   239,   243,   244,   245,
     249,   250,   251,   255,   256,   257,   258,   259,   263,   264,
     265,   269,   270,   274,   275,   279,   280,   284,   285,   289,
     290,   294,   295,   299,   300,   301,   302,   303,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   321,
     322,   326,   330,   331,   332,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   349,   350,   354,   355,   359,
     360,   361,   362,   363,   364,   365,   369,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   392,   393,   394,   395,   396,   400,   401,
     405,   406,   410,   411,   412,   416,   417,   418,   419,   423,
     424,   428,   429,   430,   434,   435,   436,   437,   438,   442,
     443,   447,   448,   452,   456,   457,   458,   459,   460,   464,
     465,   469,   470,   474,   475,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     497,   498,   499,   503,   504,   505,   506,   510,   511,   515,
     516,   520,   521,   525,   526,   527,   528,   529,   530,   534,
     535,   539,   540,   544,   545,   546,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   574,   578,   579,
     580,   584,   585,   586,   587,   591,   595,   596,   600,   601,
     605,   609,   610,   611,   612,   613,   614,   615,   616,   620,
     621,   622,   626,   628,   628,   634,   635,   639,   640,   644,
     645,   649,   650,   651,   655,   659,   660,   661,   663,   665,
     669,   671,   676,   677,   678,   679,   680,   684,   685,   686,
     687,   688,   689,   690,   694,   698,   700,   705,   706,   713,
     714,   715,   716,   717,   721,   722,   726,   727,   731,   735,
     736,   737,   741,   742,   746,   747,   751,   756,   761,   762,
     766,   770,   771,   772,   776,   777,   778,   782,   786,   787,
     791,   795,   796,   800
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
  "TRACE", "FOREACH_DIMENSION", "REDUCTION", "MACRO", "ELLIPSIS_MACRO",
  "foreach_statement", "';'", "'}'", "')'", "'('", "','", "':'", "'.'",
  "'{'", "'['", "']'", "'*'", "'&'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "$accept",
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
  "declaration_list", "basilisk_statements", "macro_statement",
  "reduction_list", "reduction", "reduction_operator", "reduction_array",
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
     335,   336,   337,   338,    59,   125,    41,    40,    44,    58,
      46,   123,    91,    93,    42,    38,    43,    45,   126,    33,
      47,    37,    60,    62,    94,   124,    63,    61
};
#endif

#define YYPACT_NINF (-380)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-354)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     961,   -30,   216,  -380,  -380,  -380,  -380,  2575,  2622,  2622,
     545,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,   328,    14,    67,    76,   148,
    -380,   226,  -380,  -380,   -63,  -380,   248,   262,  -380,  1060,
    -380,  -380,  -380,  -380,  -380,  -380,   664,  -380,  -380,  -380,
    -380,    72,  -380,  -380,   658,  2653,  -380,   -44,   -20,   194,
      20,   277,    -7,   -37,    91,   170,    13,  -380,   217,  -380,
     326,  3310,  3310,  -380,  -380,   330,  -380,  -380,  3310,  3310,
    3310,   334,  -380,  -380,  3004,  -380,   229,  -380,  -380,  -380,
    -380,  -380,  -380,   373,   295,  -380,  -380,  1060,  -380,  1060,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  2161,  -380,  -380,   380,   293,  1334,  3430,
    3430,  2497,  2653,   544,    16,    50,  -380,   658,   299,  -380,
     300,  3430,   -28,  3430,   303,   -45,  -380,    24,  -380,  -380,
    2021,    24,  2191,  2161,  -380,  -380,  2653,  2653,  2653,  2653,
    2653,  2653,  2653,  2653,  2653,  2653,  2653,  2653,  2653,  2653,
    2653,  2653,  2653,  2653,  2497,  -380,  -380,   106,   449,   -33,
    -380,   -60,   -62,  -380,   117,  -380,  -380,  -380,  2841,   305,
    -380,  -380,  -380,  3352,   317,  -380,   326,  -380,  3004,  -380,
    -380,  -380,   862,   319,   332,   658,  1943,  -380,  -380,  -380,
     309,   -36,  -380,   380,  -380,   336,   337,   340,   341,   324,
     342,   382,   345,  3310,  -380,  -380,  -380,   344,  -380,  2497,
    -380,  2941,  1412,   -17,  -380,    83,  -380,  -380,  2544,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,   130,  -380,  -380,  -380,
    -380,   347,    93,  -380,  -380,  -380,  -380,  -380,   -44,   -44,
     -20,   -20,   194,   194,   194,   194,    20,    20,   277,    -7,
     -37,    91,   170,   250,  -380,   348,  -380,  -380,  -380,   449,
    -380,   106,  2269,  -380,  1456,  -380,   -62,   352,  3113,  -380,
      96,  -380,  2896,  3161,  2653,   338,  -380,  -380,   354,  2653,
     355,   356,   360,   364,  1115,  -380,    24,   357,   372,  2299,
     371,   376,  -380,  -380,   115,  -380,   377,  -380,  -380,  -380,
     763,  -380,  -380,  -380,   381,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,   385,   385,    24,  1943,  2653,  -380,  -380,
       1,  2269,   -59,  -380,  2653,  -380,    42,   167,  -380,  -380,
    -380,  -380,  3391,   458,  -380,  3310,   106,  -380,    24,  -380,
     378,  -380,    84,   392,   383,  -380,   393,  1778,  -380,   387,
     390,  1534,    83,  -380,  -380,  1578,  -380,  -380,  -380,  2161,
    -380,  -380,  2653,  -380,  -380,  -380,  -380,  -380,  -380,  2786,
    1778,  -380,   406,   409,  1656,  -380,  -380,  -380,  -380,  -380,
    2653,   154,  -380,   417,   423,  3209,  -380,   658,  -380,   126,
    -380,  -380,   424,  1115,  1159,  1159,  2497,   658,   450,   432,
    -380,  -380,  -380,   163,    80,  2051,  -380,  1115,  -380,  -380,
    1237,  -380,   171,   425,  -380,  1816,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,    82,   430,   162,  -380,   438,   435,  -380,
    -380,   444,   453,  2148,  2723,   433,   231,  -380,  -380,  3263,
    -380,  -380,   448,  1778,  -380,  -380,  2497,  -380,   451,  3064,
    1778,  -380,   452,   460,  1700,  -380,  -380,   468,  -380,  -380,
     470,   200,   464,  1778,  -380,  -380,  2497,  -380,   465,   466,
    -380,  -380,  -380,   368,  2653,  -380,  -380,  2544,  2653,  1115,
    2653,  1115,  -380,   475,   477,   214,   459,  -380,  -380,   478,
    1115,  1115,   218,  -380,     8,  2347,   326,  2347,  -380,  1913,
    -380,  -380,  -380,  2269,  -380,  2497,  -380,  3391,  2497,   492,
     488,  -380,  -380,  -380,  -380,  2269,  -380,  -380,  -380,   485,
     486,  -380,  -380,   494,   489,  1778,  -380,  -380,  2497,  -380,
     491,  -380,  -380,  -380,   578,  -380,   493,   495,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  1115,
    1115,  1115,  2497,  1115,  -380,  -380,  1115,  2161,  2398,     6,
    2446,  -380,  -380,  -380,  -380,  -380,  -380,  2497,  -380,  -380,
    -380,  -380,  -380,  -380,   496,   497,  -380,  -380,  -380,  -380,
     525,  -380,  -380,   222,  -380,  -380,  -380,   300,   501,  1115,
     234,  2161,  1115,   238,   101,  -380,  -380,  1115,   507,  1115,
    -380,  1115,   509,  -380,  1115,  -380,  -380,  -380,  -380,  -380,
    1115,  -380,  -380
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     7,    15,    16,    19,    20,     0,     0,     0,
     152,    17,   129,   130,   131,   133,   134,   189,   184,   185,
     186,   146,   138,   139,   140,   141,   144,   145,   142,   143,
     137,   147,   148,   158,   159,     0,     0,     0,   187,     0,
     190,     0,   132,   188,   351,   135,     0,     0,   212,     0,
      56,    55,    57,    58,    59,    60,     0,    26,     8,     9,
      11,    47,    28,    27,    61,     0,    63,    67,    70,    73,
      78,    81,    83,    85,    87,    89,    91,    93,     0,   308,
       0,   116,   118,   136,   150,     0,   151,   149,   120,   122,
     124,     0,   114,     2,     0,   307,    12,   326,   309,   310,
     311,   312,    54,     0,   283,   313,     7,     0,    51,     0,
      48,    49,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    98,     0,   210,   211,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,    14,   152,     0,   109,
      13,   166,   257,   168,     0,     0,     3,     0,    31,    32,
       0,     0,     0,     0,    61,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   347,   257,     0,   216,     0,
     125,   314,   257,   195,     0,   152,   115,   117,     0,   155,
     119,   121,   123,     0,     0,   317,     0,   316,     0,   327,
       1,   282,     0,     0,     0,     0,     0,    97,    96,    18,
     182,     0,   179,     0,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   331,   330,   329,     0,    10,     0,
     165,     0,     0,   234,   257,   235,   232,   167,     0,     4,
       5,     6,    30,    41,    39,    46,     0,    42,    45,    29,
      36,    56,     0,    95,    94,    64,    65,    66,    68,    69,
      71,    72,    76,    77,    74,    75,    79,    80,    82,    84,
      86,    88,    90,     0,   112,     0,   187,   217,   215,   214,
     257,     0,     0,   257,     0,   194,   257,     0,     0,   160,
       0,   164,     0,     0,     0,   128,   318,   315,     0,     0,
       0,     0,     0,     0,     0,   294,     0,     0,     0,     0,
       0,   212,   319,   289,     0,   287,     0,   288,   271,   272,
       0,   285,   273,   274,     0,   275,   299,   276,   277,   320,
     321,   322,   323,    52,     0,     0,     0,     0,   260,   262,
       0,     0,     0,   266,     0,   174,     0,     0,   192,   191,
      53,   183,     0,     0,   352,     0,     0,   348,     0,   110,
       0,   253,   226,     0,   220,   257,     0,     0,   237,    56,
       0,     0,   233,   231,   257,     0,    33,    62,    40,    44,
      37,    38,     0,   196,   218,   213,   113,   126,   127,     0,
       0,   197,    56,     0,     0,   193,   156,   153,   161,   257,
       0,     0,   169,   173,     0,     0,   350,    61,   344,     0,
     341,   278,     0,     0,     0,     0,     0,   211,     0,     0,
     303,   304,   305,     0,     0,     0,   290,     0,   284,   286,
       0,   269,     0,     0,    34,     0,   261,   265,   267,   181,
     175,   180,   176,     0,     0,     0,    22,     0,     0,   349,
     314,   332,     0,     0,     0,   223,   234,   225,   254,     0,
     221,   236,     0,     0,   238,   244,     0,   243,     0,     0,
       0,   245,    56,     0,     0,    43,    92,     0,   229,   208,
       0,     0,     0,     0,   198,   205,     0,   204,    56,     0,
     162,   171,   257,     0,     0,   157,   154,     0,     0,     0,
       0,     0,   281,     0,     0,     0,     0,   302,   306,     0,
       0,     0,     0,   279,     0,     0,     0,     0,   258,     0,
     268,    35,   264,     0,   177,     0,    21,     0,     0,     0,
       0,   328,   228,   227,   152,     0,   219,   257,   240,     0,
       0,   242,   255,     0,     0,     0,   246,   252,     0,   251,
       0,   207,   206,   209,     0,   200,     0,     0,   201,   203,
     163,   170,   172,   346,   345,   343,   340,   342,   280,     0,
       0,     0,     0,     0,   334,   324,     0,     0,     0,   128,
       0,   259,   263,    25,    23,    24,   270,     0,   224,   222,
     239,   241,   256,   248,     0,     0,   249,   230,   199,   202,
     292,   293,   295,     0,   335,   325,   339,   338,     0,     0,
       0,     0,     0,     0,     0,   247,   250,     0,     0,     0,
     300,     0,     0,   297,     0,   333,   291,   296,   337,   301,
       0,   298,   336
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -380,  -380,  -380,   -73,  -380,  -380,  -380,  -380,  -380,    70,
     467,  -110,  -380,  -380,   447,   176,   223,   109,  -380,   -46,
     203,   207,   331,   208,   436,   434,   437,   439,   440,  -380,
      17,     7,   -61,   -49,  -117,   -58,   263,  -380,   329,  -380,
     102,  -380,  -380,  -380,  -185,  -271,  -120,  -380,   119,  -380,
     401,  -328,  -380,   -35,  -380,  -380,   -64,  -172,    44,  -140,
    -206,  -379,  -380,   156,  -380,   375,  -137,  -227,   -78,  -220,
     281,  -364,  -380,   278,  -151,    23,  -380,     3,  -380,  -380,
     301,  -365,  -380,  -380,  -380,  -380,  -380,   563,  -380,  -222,
    -380,  -380,  -380,  -380,   526,  -380,  -380,  -380,  -380,  -380,
      12,  -380,  -380,  -170,  -380,  -380,  -380,  -380,  -380
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    56,    57,   138,    58,   210,    59,    60,   445,   446,
      61,   245,    62,    63,   242,   246,   247,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   139,   123,   314,   215,    79,   362,   179,   180,    81,
      82,    83,    84,    85,   288,   289,   142,   401,   402,    86,
     211,   212,    87,    88,    89,    90,   275,   182,   316,   184,
     279,   363,   364,   365,   481,   447,   366,   235,   236,   339,
     340,   341,   342,   343,    92,   317,   318,   319,   202,   320,
     321,   322,   323,   324,   325,   326,   327,    93,    94,    95,
     198,   328,   329,    96,    97,   227,   452,   330,   331,   332,
     608,    98,   409,   410,    99,   100,   101,   102,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     140,   357,   233,   153,   105,   234,   372,    78,   293,   611,
     480,   577,   286,   207,   143,   220,   181,   398,   441,   155,
     222,   230,   398,   237,  -128,   283,   371,   124,  -128,   133,
     284,   335,   173,   337,   163,   164,   195,   291,   278,   239,
     240,   241,   291,   253,    91,   209,   104,   282,   437,   345,
     156,   280,   346,   124,   125,   281,   157,   158,   140,   231,
     140,   104,   388,    78,   232,   517,   178,   170,   290,   224,
     231,   523,   143,   290,   143,   232,   159,   160,   394,   127,
     125,   147,   148,   149,   509,   209,   434,   124,   169,   435,
     543,   233,   426,   143,   143,   143,   229,   197,   274,   124,
      91,   128,   223,   252,   285,    48,   143,   405,   143,   124,
     255,   256,   257,   282,   125,   441,   108,   110,   111,   174,
     124,   436,   165,   166,   183,   273,   125,   440,   376,   189,
     208,    48,   295,   449,   398,   194,   125,   291,   219,   385,
     296,   291,   291,   277,   315,   214,   225,   125,   105,   214,
     578,   141,   580,   143,   129,   523,   373,   248,   143,   150,
     254,   463,   151,   130,   152,    48,   510,   524,   290,   474,
     374,   454,   290,   290,   154,   375,   232,    48,   178,   226,
     399,   229,   412,   177,   483,   400,   381,    48,   172,   229,
     178,   243,   377,   177,   625,   243,   171,   277,    48,   426,
     178,   297,   386,   229,   177,   389,   161,   162,   395,   141,
     498,   141,   499,   338,   500,   522,   378,   295,   379,  -210,
     433,   183,   456,   376,   376,   457,   403,   439,   183,   372,
     141,   141,   141,   533,   124,   131,   359,   154,   492,   370,
     183,   154,   493,   141,   384,   141,  -210,   508,   526,   277,
     527,   229,   442,   143,   291,   443,   518,   143,   143,   519,
     423,   125,   315,    80,   545,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   491,   286,   290,   553,   460,   554,   338,
     141,   393,   450,   167,   168,   141,   469,  -210,   455,   522,
     571,   175,   229,   582,   576,  -210,   379,  -210,   618,    47,
     229,   408,    48,   132,   456,   588,   214,   143,   454,    80,
     621,   490,   229,   232,   624,   183,   229,   418,   565,   124,
     567,   124,   277,   124,   183,   134,   384,   124,   229,   382,
     277,   503,   504,   338,   186,   187,   497,   154,   338,   135,
     419,   190,   191,   192,   214,   277,   125,   196,   125,   384,
     125,   214,   258,   259,   125,   140,   140,   505,   260,   261,
     143,   124,   515,   200,   462,   266,   267,   562,   468,   431,
     201,   514,   473,   209,   213,   228,   248,   563,   229,   238,
     141,   147,   148,   149,   141,   141,   292,   482,   125,   476,
     183,   489,   451,   407,   294,   333,   183,    48,   154,    48,
     176,    48,   352,   177,   560,    48,   344,   214,   334,   126,
     178,   188,   348,   349,   144,   193,   350,   351,   384,   403,
     353,   355,   248,   358,   383,   277,   502,   396,   411,   384,
     380,   420,   338,   414,   413,   282,   154,   415,   384,    48,
     513,   416,   579,   154,   141,   177,   421,   400,   424,   589,
     338,   196,   178,   425,   448,   196,   427,   606,   430,   150,
     539,   459,   151,   540,   152,   354,   206,   544,   458,   461,
     464,   550,   203,   465,   204,   453,   356,    18,    19,    20,
     556,   154,   143,   557,   262,   263,   264,   265,   183,   484,
     183,   606,   485,   216,   217,   218,   494,   141,   495,   154,
     384,   214,   506,   501,   564,   408,   507,   408,   520,   525,
     276,   529,   566,   603,   568,    43,   338,   528,   607,   610,
     338,   613,   583,   574,   575,   585,   530,   183,   614,   531,
     535,   538,   338,   178,   541,   546,   572,   106,     3,     4,
       5,     6,   594,   547,   551,   595,   552,   555,   558,   559,
     183,   569,   607,   570,   573,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    11,   586,   587,   590,   591,
     592,   597,   593,   196,   596,   617,   598,   619,   599,   615,
     616,   627,   600,   601,   602,   630,   604,   584,   249,   605,
     221,   512,   475,   154,   269,   268,   154,   407,   270,   407,
     387,   271,   561,   272,   347,   537,    39,   432,   356,   146,
     438,   429,   199,   622,    47,     0,     0,     0,     0,   141,
       0,   109,   620,     0,  -211,   623,  -211,     0,     0,     0,
     626,     0,   628,     0,   629,     0,     0,   631,     0,     0,
       0,     0,   122,   632,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -353,   145,     0,     2,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,   516,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    54,    55,   298,   122,     2,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
     299,   300,   301,     0,   302,   303,   304,   305,   306,   307,
     308,   309,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,   310,    47,   311,   312,     0,   313,   428,     0,
      49,     0,     0,     0,   104,     0,     0,    50,    51,    52,
      53,    54,    55,   298,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,   299,
     300,   301,     0,   302,   303,   304,   305,   306,   307,   308,
     309,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,   310,    47,   311,   312,     0,   313,     0,     0,    49,
       0,     0,     0,   104,     0,     0,    50,    51,    52,    53,
      54,    55,     1,     0,     2,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,    50,    51,    52,    53,    54,
      55,   136,     0,   106,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,    11,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   298,     0,     2,     3,
       4,     5,     6,     7,     0,     8,     9,     0,     0,     0,
      37,    38,    39,     0,     0,     0,    43,    44,     0,     0,
      47,     0,     0,     0,     0,   417,    11,    49,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,    55,
     136,     0,   106,     3,     4,     5,     6,     7,     0,     8,
       9,     0,   299,   300,   301,     0,   302,   303,   304,   305,
     306,   307,   308,   309,     0,    37,     0,    39,     0,   205,
      11,     0,    44,     0,   310,    47,   311,   312,     0,   313,
       0,     0,    49,     0,     0,     0,   104,     0,     0,    50,
      51,    52,    53,    54,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,    44,     0,     0,    47,
     106,     3,     4,     5,     6,     7,    49,     8,     9,     0,
       0,     0,     0,    50,    51,    52,    53,    54,    55,     0,
       0,     0,     0,     0,     0,     0,     0,   137,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    47,     0,     0,
       0,   313,     0,     0,    49,     0,     0,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,   106,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   185,    11,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,     0,     0,     0,
      43,    44,     0,     0,    47,   106,     3,     4,     5,     6,
       7,    49,     8,     9,     0,     0,     0,     0,    50,    51,
      52,    53,    54,    55,     0,     0,     0,     0,     0,     0,
       0,     0,   205,    11,     0,     0,   367,     0,     0,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     0,   106,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,   276,    39,     0,   205,    11,    43,    44,
     390,     0,    47,     0,    18,    19,    20,     0,     0,    49,
       0,     0,     0,     0,     0,   368,   369,    51,    52,    53,
      54,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,   276,    39,     0,
       0,     0,    43,    44,     0,     0,    47,   106,     3,     4,
       5,     6,     7,    49,     8,     9,     0,     0,     0,   391,
     392,    51,    52,    53,    54,    55,     0,     0,     0,     0,
       0,     0,     0,     0,   205,    11,     0,     0,   466,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       0,   106,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,   276,    39,     0,   205,    11,
      43,    44,   470,     0,    47,     0,    18,    19,    20,     0,
       0,    49,     0,     0,     0,     0,     0,   467,    50,    51,
      52,    53,    54,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,   276,
      39,     0,     0,     0,    43,    44,     0,     0,    47,   106,
       3,     4,     5,     6,     7,    49,     8,     9,     0,     0,
       0,   471,   472,    51,    52,    53,    54,    55,     0,     0,
       0,     0,     0,     0,     0,     0,   205,    11,     0,     0,
     486,     0,     0,     0,    18,    19,    20,     0,     0,     0,
       0,     0,     0,   106,     3,     4,     5,     6,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,   276,    39,     0,
     205,    11,    43,    44,   548,     0,    47,     0,    18,    19,
      20,     0,     0,    49,     0,     0,     0,     0,     0,   487,
     488,    51,    52,    53,    54,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,   276,    39,     0,     0,     0,    43,    44,     0,     0,
      47,   106,     3,     4,     5,     6,     7,    49,     8,     9,
       0,     0,     0,   549,    50,    51,    52,    53,    54,    55,
       0,     0,     0,     0,     0,     0,     0,     0,   205,    11,
       0,     0,     0,     0,     0,     0,    18,    19,    20,   106,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,    11,    37,   276,
      39,     0,     0,     0,    43,    44,     0,     0,    47,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,    50,    51,    52,    53,    54,    55,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,     0,    44,     0,     0,    47,     0,     0,     0,
       0,   521,     0,    49,     0,     0,   335,   336,   337,     0,
      50,    51,    52,    53,    54,    55,   106,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,    11,     0,   106,     3,     4,     5,
       6,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,    11,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
      44,     0,     0,    47,     0,     0,     0,     0,   581,     0,
      49,     0,     0,   335,   336,   337,     0,    50,    51,    52,
      53,    54,    55,    37,     0,    39,     0,     0,     0,     0,
      44,     0,     0,    47,   106,     3,     4,     5,     6,     7,
      49,     8,     9,   335,   336,   337,     0,    50,    51,    52,
      53,    54,    55,     0,     0,     0,     0,     0,     0,     0,
       0,   205,    11,     0,   106,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,    11,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,    44,     0,
       0,    47,     0,     0,     0,     0,     0,   244,    49,     0,
       0,     0,   206,     0,     0,    50,    51,    52,    53,    54,
      55,    37,     0,    39,     0,     0,     0,     0,    44,     0,
       0,    47,     0,     0,     0,     0,     0,   511,    49,     0,
       0,     0,   206,     0,     0,    50,    51,    52,    53,    54,
      55,   106,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,   106,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,   205,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,    11,     0,   106,     3,     4,     5,     6,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   532,     0,     0,    37,     0,
      39,   205,    11,     0,     0,    44,     0,     0,    47,     0,
       0,    37,     0,    39,     0,    49,     0,     0,    44,   336,
       0,    47,    50,    51,    52,    53,    54,    55,    49,     0,
       0,     0,   206,     0,     0,    50,    51,    52,    53,    54,
      55,    37,     0,    39,     0,     0,     0,     0,    44,     0,
       0,    47,   106,     3,     4,     5,     6,     7,    49,     8,
       9,     0,     0,     0,   250,   251,    51,    52,    53,    54,
      55,     0,     0,     0,     0,     0,     0,     0,     0,   205,
      11,     0,   106,     3,     4,     5,     6,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
      11,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,    44,     0,     0,    47,
     106,     3,     4,     5,     6,     7,    49,     8,     9,     0,
     336,     0,     0,    50,    51,    52,    53,    54,    55,    37,
       0,    39,     0,     0,     0,     0,    44,   205,    11,    47,
       0,     0,     0,   422,     0,     0,    49,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,    55,     0,
       0,   106,     3,     4,     5,     6,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,    44,     0,     0,    47,   205,    11,
       0,   313,     0,     0,    49,     0,     0,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,     0,     0,   106,
       3,     4,     5,     6,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,     0,    44,   205,    11,    47,     0,
       0,     0,     0,     0,   609,    49,     0,     0,     0,     0,
       0,     0,    50,    51,    52,    53,    54,    55,     0,     0,
     106,     3,     4,     5,     6,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,     0,    44,     0,     0,    47,   205,    11,     0,
       0,     0,   612,    49,     0,     0,     0,     0,     0,     0,
      50,    51,    52,    53,    54,    55,     0,   106,     3,     4,
       5,     6,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,    44,    11,     0,    47,   106,     3,
       4,     5,     6,     7,    49,     8,     9,     0,     0,     0,
       0,    50,    51,    52,    53,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
       0,    44,     0,     0,    47,   106,     3,     4,     5,     6,
       7,    49,     8,     9,     0,   206,     0,     0,    50,    51,
      52,    53,    54,    55,     0,    37,     0,    39,     0,     0,
       0,     0,    44,    11,     0,    47,   106,     3,     4,     5,
       6,     7,   107,     8,     9,     0,     0,     0,     0,    50,
      51,    52,    53,    54,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,     0,    44,
       0,     0,    47,     0,     0,     0,     0,     0,     0,   109,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,    55,     0,    37,     0,    39,   124,     0,     0,     0,
      44,     0,     0,    47,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,   534,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,   477,     0,   478,
     360,     0,    36,     0,    38,     0,    40,     0,    42,    43,
       0,    45,     0,     0,    48,     0,     0,     0,     0,   361,
     454,     0,     0,     0,     0,   232,   185,   178,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   287,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   360,     0,    36,     0,    38,     0,    40,
       0,    42,    43,     0,    45,     0,     0,     0,     0,     0,
       0,   185,   479,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   404,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,    41,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,   185,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
      41,   185,    43,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   360,     0,
      36,     0,    38,     0,    40,     0,    42,    43,     0,    45,
       0,     0,     0,     0,     0,     0,     0,   361,   231,     0,
       0,     0,     0,   232,   185,   178,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,    38,     0,    40,    41,    42,
      43,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   185,   104,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   360,     0,    36,     0,    38,     0,    40,     0,    42,
      43,     0,    45,   185,     0,     0,     0,     0,     0,     0,
     542,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    41,     0,    43,
       0,   185,     0,     0,     0,     0,     0,     0,   397,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,    41,     0,    43,     0,   185,
       0,     0,     0,     0,     0,     0,   406,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,    41,     0,    43,     0,     0,     0,     0,
       0,     0,     0,   185,   496,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,   536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     360,     0,    36,     0,    38,     0,    40,     0,    42,    43,
     185,    45,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
       0,    38,   185,    40,     0,    42,    43,     0,    45,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   185,     0,    38,     0,     0,    41,     0,    43,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     0,     0,   444,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     185,     0,    38,     0,     0,     0,     0,    43,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
      49,   223,   142,    64,     1,   142,   233,     0,   193,     3,
     389,     3,   184,   123,    49,   132,    80,   288,   346,    65,
       4,   141,   293,   143,    84,    87,   232,     3,    88,    92,
      92,    90,    19,    92,    14,    15,    94,   188,   178,    84,
      85,    86,   193,   153,     0,     3,    91,   107,   107,    85,
      94,    84,    88,     3,    30,    88,   100,   101,   107,    87,
     109,    91,   282,    56,    92,   430,    94,   104,   188,    19,
      87,   435,   107,   193,   109,    92,    96,    97,   284,    35,
      30,     9,    10,    11,     4,     3,    85,     3,    95,    88,
     469,   231,    84,   128,   129,   130,    88,    94,   176,     3,
      56,    87,    86,   152,   182,    81,   141,   292,   143,     3,
     156,   157,   158,   107,    30,   443,     7,     8,     9,   106,
       3,   341,   102,   103,    80,   174,    30,    85,   238,    85,
     123,    81,   196,   355,   405,    91,    30,   288,   131,   279,
     198,   292,   293,   178,   202,   128,    96,    30,   145,   132,
     515,    49,   517,   188,    87,   519,   234,   150,   193,    87,
     153,   367,    90,    87,    92,    81,    86,    85,   288,   375,
      87,    87,   292,   293,    65,    92,    92,    81,    94,   135,
      84,    88,   299,    87,   390,    89,    93,    81,    18,    88,
      94,   147,   238,    87,    93,   151,   105,   232,    81,    84,
      94,   198,   280,    88,    87,   283,    12,    13,   286,   107,
      84,   109,    86,   206,    88,   435,    86,   281,    88,     3,
     337,   177,   362,   333,   334,   362,   290,   344,   184,   456,
     128,   129,   130,   453,     3,    87,   229,   128,    84,   232,
     196,   132,    88,   141,   279,   143,    30,    84,    86,   284,
      88,    88,    85,   288,   405,    88,    85,   292,   293,    88,
     309,    30,   320,     0,   470,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   400,   456,   405,    86,   365,    88,   282,
     188,   284,   356,    16,    17,   193,   374,    81,   362,   519,
      86,    84,    88,   523,    86,    89,    88,    91,    86,    80,
      88,   294,    81,    87,   454,   535,   299,   352,    87,    56,
      86,   399,    88,    92,    86,   281,    88,   304,   498,     3,
     500,     3,   367,     3,   290,    87,   371,     3,    88,    89,
     375,   414,   415,   336,    81,    82,   407,   238,   341,    87,
     306,    88,    89,    90,   337,   390,    30,    94,    30,   394,
      30,   344,   159,   160,    30,   414,   415,   416,   161,   162,
     405,     3,   430,     0,   367,   167,   168,   494,   371,   335,
      85,   430,   375,     3,    91,    86,   379,   497,    88,    86,
     288,     9,    10,    11,   292,   293,    91,   390,    30,   382,
     356,   394,   358,   294,    87,    86,   362,    81,   299,    81,
      84,    81,    88,    87,   492,    81,   107,   400,    86,    91,
      94,    91,    86,    86,    49,    91,    86,    86,   463,   493,
      88,    86,   425,    89,    86,   470,   413,    85,    84,   474,
      93,    84,   435,    87,    89,   107,   337,    87,   483,    81,
     427,    87,   516,   344,   352,    87,    84,    89,    87,   537,
     453,   198,    94,    87,     6,   202,    89,   577,    87,    87,
     463,    88,    90,   466,    92,    93,    91,   470,    86,    86,
      93,   474,   107,    93,   109,   107,   223,    38,    39,    40,
     483,   382,   527,   486,   163,   164,   165,   166,   454,    93,
     456,   611,    93,   128,   129,   130,    89,   405,    85,   400,
     545,   494,    62,    89,   497,   498,    84,   500,    93,    89,
      71,    86,   499,   572,   501,    76,   519,    89,   577,   578,
     523,   580,   525,   510,   511,   528,    92,   493,   587,    86,
     107,    93,   535,    94,    93,    93,    87,     3,     4,     5,
       6,     7,   545,    93,    86,   548,    86,    93,    93,    93,
     516,    86,   611,    86,    86,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    31,    84,    89,    93,    93,
      86,     3,    93,   320,    93,    60,    93,    86,    93,    93,
      93,    84,   569,   570,   571,    86,   573,   527,   151,   576,
     133,   425,   379,   494,   170,   169,   497,   498,   171,   500,
     281,   172,   493,   173,   213,   459,    72,   336,   355,    56,
     342,   320,    96,   611,    80,    -1,    -1,    -1,    -1,   527,
      -1,    87,   609,    -1,    89,   612,    91,    -1,    -1,    -1,
     617,    -1,   619,    -1,   621,    -1,    -1,   624,    -1,    -1,
      -1,    -1,   107,   630,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,   430,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,     1,   107,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    84,    85,    -1,
      87,    -1,    -1,    -1,    91,    -1,    -1,    94,    95,    96,
      97,    98,    99,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    84,    -1,    -1,    87,
      -1,    -1,    -1,    91,    -1,    -1,    94,    95,    96,    97,
      98,    99,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    77,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    30,    31,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    72,    -1,    30,
      31,    -1,    77,    -1,    79,    80,    81,    82,    -1,    84,
      -1,    -1,    87,    -1,    -1,    -1,    91,    -1,    -1,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    80,
       3,     4,     5,     6,     7,     8,    87,    10,    11,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    77,    -1,    -1,    80,     3,     4,     5,     6,     7,
       8,    87,    10,    11,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    30,    31,    76,    77,
      34,    -1,    80,    -1,    38,    39,    40,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    77,    -1,    -1,    80,     3,     4,     5,
       6,     7,     8,    87,    10,    11,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    30,    31,
      76,    77,    34,    -1,    80,    -1,    38,    39,    40,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,    77,    -1,    -1,    80,     3,
       4,     5,     6,     7,     8,    87,    10,    11,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,
      30,    31,    76,    77,    34,    -1,    80,    -1,    38,    39,
      40,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    77,    -1,    -1,
      80,     3,     4,     5,     6,     7,     8,    87,    10,    11,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    70,    71,
      72,    -1,    -1,    -1,    76,    77,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    80,    -1,    -1,    -1,
      -1,    85,    -1,    87,    -1,    -1,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    80,    -1,    -1,    -1,    -1,    85,    -1,
      87,    -1,    -1,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,    70,    -1,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    80,     3,     4,     5,     6,     7,     8,
      87,    10,    11,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    91,    -1,    -1,    94,    95,    96,    97,    98,
      99,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    91,    -1,    -1,    94,    95,    96,    97,    98,
      99,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      72,    30,    31,    -1,    -1,    77,    -1,    -1,    80,    -1,
      -1,    70,    -1,    72,    -1,    87,    -1,    -1,    77,    91,
      -1,    80,    94,    95,    96,    97,    98,    99,    87,    -1,
      -1,    -1,    91,    -1,    -1,    94,    95,    96,    97,    98,
      99,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    80,     3,     4,     5,     6,     7,     8,    87,    10,
      11,    -1,    -1,    -1,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    80,
       3,     4,     5,     6,     7,     8,    87,    10,    11,    -1,
      91,    -1,    -1,    94,    95,    96,    97,    98,    99,    70,
      -1,    72,    -1,    -1,    -1,    -1,    77,    30,    31,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    80,    30,    31,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    77,    30,    31,    80,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    80,    30,    31,    -1,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    77,    31,    -1,    80,     3,     4,
       5,     6,     7,     8,    87,    10,    11,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    80,     3,     4,     5,     6,     7,
       8,    87,    10,    11,    -1,    91,    -1,    -1,    94,    95,
      96,    97,    98,    99,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    77,    31,    -1,    80,     3,     4,     5,     6,
       7,     8,    87,    10,    11,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    77,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,    -1,    70,    -1,    72,     3,    -1,    -1,    -1,
      77,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
      67,    -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,
      -1,    78,    -1,    -1,    81,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    92,    30,    94,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    69,    -1,    71,    -1,    73,
      -1,    75,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    86,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    30,    76,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    71,    -1,    73,    -1,    75,    76,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    92,    30,    94,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    -1,    73,    74,    75,
      76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    91,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    -1,    71,    -1,    73,    -1,    75,
      76,    -1,    78,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    38,    39,    40,    41,    42,    43,    44,    45,    46,
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
      67,    -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,
      30,    78,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    30,    73,    -1,    75,    76,    -1,    78,    -1,
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
      73,    74,    75,    76,    77,    78,    79,    80,    81,    87,
      94,    95,    96,    97,    98,    99,   109,   110,   112,   114,
     115,   118,   120,   121,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   143,
     144,   147,   148,   149,   150,   151,   157,   160,   161,   162,
     163,   166,   182,   195,   196,   197,   201,   202,   209,   212,
     213,   214,   215,   216,    91,   185,     3,    87,   125,    87,
     125,   125,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,   107,   140,     3,    30,    91,   166,    87,    87,
      87,    87,    87,    92,    87,    87,     1,    30,   111,   139,
     141,   148,   154,   161,   173,     1,   195,     9,    10,    11,
      87,    90,    92,   140,   125,   127,    94,   100,   101,    96,
      97,    12,    13,    14,    15,   102,   103,    16,    17,    95,
     104,   105,    18,    19,   106,    84,    84,    87,    94,   145,
     146,   164,   165,   166,   167,    30,   144,   144,    91,   166,
     144,   144,   144,    91,   166,   143,   144,   185,   198,   202,
       0,    85,   186,   173,   173,    30,    91,   119,   139,     3,
     113,   158,   159,    91,   138,   142,   173,   173,   173,   139,
     142,   118,     4,    86,    19,    96,   166,   203,    86,    88,
     154,    87,    92,   167,   174,   175,   176,   154,    86,    84,
      85,    86,   122,   166,    86,   119,   123,   124,   139,   122,
      93,    94,   141,   119,   139,   127,   127,   127,   128,   128,
     129,   129,   130,   130,   130,   130,   131,   131,   132,   133,
     134,   135,   136,   141,   176,   164,    71,   161,   167,   168,
      84,    88,   107,    87,    92,   176,   165,     1,   152,   153,
     154,   182,    91,   152,    87,   164,   143,   185,     1,    57,
      58,    59,    61,    62,    63,    64,    65,    66,    67,    68,
      79,    81,    82,    84,   141,   143,   166,   183,   184,   185,
     187,   188,   189,   190,   191,   192,   193,   194,   199,   200,
     205,   206,   207,    86,    86,    90,    91,    92,   139,   177,
     178,   179,   180,   181,   107,    85,    88,   158,    86,    86,
      86,    86,    88,    88,    93,    86,   144,   197,    89,   139,
      67,    86,   144,   169,   170,   171,   174,    34,    93,    94,
     139,   168,   175,   176,    87,    92,   119,   127,    86,    88,
      93,    93,    89,    86,   161,   167,   176,   146,   177,   176,
      34,    93,    94,   139,   168,   176,    85,    85,   153,    84,
      89,   155,   156,   164,     1,   152,    85,   125,   138,   210,
     211,    84,   142,    89,    87,    87,    87,    30,   183,   166,
      84,    84,    84,   141,    87,    87,    84,    89,    85,   188,
      87,   166,   178,   142,    85,    88,   177,   107,   181,   142,
      85,   159,    85,    88,    58,   116,   117,   173,     6,   197,
     164,   166,   204,   107,    87,   164,   167,   174,    86,    88,
     176,    86,   139,   168,    93,    93,    34,    93,   139,   176,
      34,    93,    94,   139,   168,   124,   138,     1,     3,    86,
     169,   172,   139,   168,    93,    93,    34,    93,    94,   139,
     176,   142,    84,    88,    89,    85,    85,   140,    84,    86,
      88,    89,   183,   111,   111,   141,    62,    84,    84,     4,
      86,    86,   123,   183,   141,   143,   144,   189,    85,    88,
      93,    85,   177,   179,    85,    89,    86,    88,    89,    86,
      92,    86,    67,   177,    30,   107,    56,   171,    93,   139,
     139,    93,    86,   169,   139,   168,    93,    93,    34,    93,
     139,    86,    86,    86,    88,    93,   139,   139,    93,    93,
     176,   156,   142,   119,   138,   211,   183,   211,   183,    86,
      86,    86,    87,    86,   183,   183,    86,     3,   189,   164,
     189,    85,   177,   139,   117,   139,    84,    89,   177,   176,
      93,    93,    86,    93,   139,   139,    93,     3,    93,    93,
     183,   183,   183,   141,   183,   183,   119,   141,   208,    86,
     141,     3,    86,   141,   141,    93,    93,    60,    86,    86,
     183,    86,   208,   183,    86,    93,   183,    84,   183,   183,
      86,   183,   183
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   110,   111,   111,   112,   112,   112,   113,   114,
     114,   115,   116,   116,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   119,   119,   120,   120,   120,   121,
     121,   122,   123,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   125,   126,   126,   126,   126,   126,
     126,   127,   127,   128,   128,   128,   128,   129,   129,   129,
     130,   130,   130,   131,   131,   131,   131,   131,   132,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   139,   139,   139,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   141,
     141,   142,   143,   143,   143,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   145,   145,   146,   146,   147,
     147,   147,   147,   147,   147,   147,   148,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   150,   150,   150,   150,   150,   151,   151,
     152,   152,   153,   153,   153,   154,   154,   154,   154,   155,
     155,   156,   156,   156,   157,   157,   157,   157,   157,   158,
     158,   159,   159,   160,   161,   161,   161,   161,   161,   162,
     162,   163,   163,   164,   164,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     166,   166,   166,   167,   167,   167,   167,   168,   168,   169,
     169,   170,   170,   171,   171,   171,   171,   171,   171,   172,
     172,   173,   173,   174,   174,   174,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   176,   177,   177,
     177,   178,   178,   178,   178,   179,   180,   180,   181,   181,
     182,   183,   183,   183,   183,   183,   183,   183,   183,   184,
     184,   184,   185,   186,   185,   187,   187,   188,   188,   189,
     189,   190,   190,   190,   191,   192,   192,   192,   192,   192,
     193,   193,   194,   194,   194,   194,   194,   195,   195,   195,
     195,   195,   195,   195,   196,   197,   197,   198,   198,   199,
     199,   199,   199,   199,   200,   200,   201,   201,   202,   203,
     203,   203,   204,   204,   205,   205,   206,   207,   208,   208,
     209,   210,   210,   210,   211,   211,   211,   212,   213,   213,
     214,   215,   215,   216
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     1,     3,     3,     3,     1,     1,     1,     3,
       3,     2,     2,     4,     3,     4,     3,     4,     4,     3,
       4,     1,     1,     3,     2,     1,     1,     1,     2,     2,
       2,     2,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     4,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     2,     4,     5,     1,     1,
       1,     2,     3,     4,     1,     2,     1,     2,     1,     1,
       3,     2,     3,     1,     4,     5,     5,     6,     2,     1,
       3,     3,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     3,     2,     1,     3,     3,     4,     6,
       5,     5,     6,     5,     4,     4,     5,     5,     4,     5,
       1,     1,     1,     3,     2,     2,     1,     1,     2,     3,
       1,     2,     4,     2,     4,     2,     1,     3,     3,     1,
       3,     3,     2,     2,     1,     1,     3,     2,     3,     5,
       4,     5,     4,     3,     3,     3,     4,     6,     5,     5,
       6,     4,     4,     2,     3,     4,     5,     0,     3,     4,
       1,     2,     1,     4,     3,     2,     1,     2,     3,     2,
       7,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     3,     2,     0,     4,     1,     2,     1,     1,     1,
       2,     7,     5,     5,     1,     5,     7,     6,     7,     1,
       6,     7,     3,     2,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     2,     1,     2,     1,
       1,     1,     1,     1,     4,     5,     1,     2,     6,     1,
       1,     1,     1,     5,     4,     5,     8,     7,     1,     1,
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
#line 1990 "basilisk.c"
        break;

    case YYSYMBOL_I_CONSTANT: /* I_CONSTANT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 1999 "basilisk.c"
        break;

    case YYSYMBOL_F_CONSTANT: /* F_CONSTANT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2008 "basilisk.c"
        break;

    case YYSYMBOL_STRING_LITERAL: /* STRING_LITERAL  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2017 "basilisk.c"
        break;

    case YYSYMBOL_FUNC_NAME: /* FUNC_NAME  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2026 "basilisk.c"
        break;

    case YYSYMBOL_SIZEOF: /* SIZEOF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2035 "basilisk.c"
        break;

    case YYSYMBOL_PTR_OP: /* PTR_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2044 "basilisk.c"
        break;

    case YYSYMBOL_INC_OP: /* INC_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2053 "basilisk.c"
        break;

    case YYSYMBOL_DEC_OP: /* DEC_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2062 "basilisk.c"
        break;

    case YYSYMBOL_LEFT_OP: /* LEFT_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2071 "basilisk.c"
        break;

    case YYSYMBOL_RIGHT_OP: /* RIGHT_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2080 "basilisk.c"
        break;

    case YYSYMBOL_LE_OP: /* LE_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2089 "basilisk.c"
        break;

    case YYSYMBOL_GE_OP: /* GE_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2098 "basilisk.c"
        break;

    case YYSYMBOL_EQ_OP: /* EQ_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2107 "basilisk.c"
        break;

    case YYSYMBOL_NE_OP: /* NE_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2116 "basilisk.c"
        break;

    case YYSYMBOL_AND_OP: /* AND_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2125 "basilisk.c"
        break;

    case YYSYMBOL_OR_OP: /* OR_OP  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2134 "basilisk.c"
        break;

    case YYSYMBOL_MUL_ASSIGN: /* MUL_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2143 "basilisk.c"
        break;

    case YYSYMBOL_DIV_ASSIGN: /* DIV_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2152 "basilisk.c"
        break;

    case YYSYMBOL_MOD_ASSIGN: /* MOD_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2161 "basilisk.c"
        break;

    case YYSYMBOL_ADD_ASSIGN: /* ADD_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2170 "basilisk.c"
        break;

    case YYSYMBOL_SUB_ASSIGN: /* SUB_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2179 "basilisk.c"
        break;

    case YYSYMBOL_LEFT_ASSIGN: /* LEFT_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2188 "basilisk.c"
        break;

    case YYSYMBOL_RIGHT_ASSIGN: /* RIGHT_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2197 "basilisk.c"
        break;

    case YYSYMBOL_AND_ASSIGN: /* AND_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2206 "basilisk.c"
        break;

    case YYSYMBOL_XOR_ASSIGN: /* XOR_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2215 "basilisk.c"
        break;

    case YYSYMBOL_OR_ASSIGN: /* OR_ASSIGN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2224 "basilisk.c"
        break;

    case YYSYMBOL_TYPEDEF_NAME: /* TYPEDEF_NAME  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2233 "basilisk.c"
        break;

    case YYSYMBOL_ENUMERATION_CONSTANT: /* ENUMERATION_CONSTANT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2242 "basilisk.c"
        break;

    case YYSYMBOL_TYPEDEF: /* TYPEDEF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2251 "basilisk.c"
        break;

    case YYSYMBOL_EXTERN: /* EXTERN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2260 "basilisk.c"
        break;

    case YYSYMBOL_STATIC: /* STATIC  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2269 "basilisk.c"
        break;

    case YYSYMBOL_AUTO: /* AUTO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2278 "basilisk.c"
        break;

    case YYSYMBOL_REGISTER: /* REGISTER  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2287 "basilisk.c"
        break;

    case YYSYMBOL_INLINE: /* INLINE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2296 "basilisk.c"
        break;

    case YYSYMBOL_CONST: /* CONST  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2305 "basilisk.c"
        break;

    case YYSYMBOL_RESTRICT: /* RESTRICT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2314 "basilisk.c"
        break;

    case YYSYMBOL_VOLATILE: /* VOLATILE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2323 "basilisk.c"
        break;

    case YYSYMBOL_BOOL: /* BOOL  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2332 "basilisk.c"
        break;

    case YYSYMBOL_CHAR: /* CHAR  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2341 "basilisk.c"
        break;

    case YYSYMBOL_SHORT: /* SHORT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2350 "basilisk.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2359 "basilisk.c"
        break;

    case YYSYMBOL_LONG: /* LONG  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2368 "basilisk.c"
        break;

    case YYSYMBOL_SIGNED: /* SIGNED  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2377 "basilisk.c"
        break;

    case YYSYMBOL_UNSIGNED: /* UNSIGNED  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2386 "basilisk.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2395 "basilisk.c"
        break;

    case YYSYMBOL_DOUBLE: /* DOUBLE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2404 "basilisk.c"
        break;

    case YYSYMBOL_VOID: /* VOID  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2413 "basilisk.c"
        break;

    case YYSYMBOL_COMPLEX: /* COMPLEX  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2422 "basilisk.c"
        break;

    case YYSYMBOL_IMAGINARY: /* IMAGINARY  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2431 "basilisk.c"
        break;

    case YYSYMBOL_STRUCT: /* STRUCT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2440 "basilisk.c"
        break;

    case YYSYMBOL_UNION: /* UNION  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2449 "basilisk.c"
        break;

    case YYSYMBOL_ENUM: /* ENUM  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2458 "basilisk.c"
        break;

    case YYSYMBOL_ELLIPSIS: /* ELLIPSIS  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2467 "basilisk.c"
        break;

    case YYSYMBOL_CASE: /* CASE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2476 "basilisk.c"
        break;

    case YYSYMBOL_DEFAULT: /* DEFAULT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2485 "basilisk.c"
        break;

    case YYSYMBOL_IF: /* IF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2494 "basilisk.c"
        break;

    case YYSYMBOL_ELSE: /* ELSE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2503 "basilisk.c"
        break;

    case YYSYMBOL_SWITCH: /* SWITCH  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2512 "basilisk.c"
        break;

    case YYSYMBOL_WHILE: /* WHILE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2521 "basilisk.c"
        break;

    case YYSYMBOL_DO: /* DO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2530 "basilisk.c"
        break;

    case YYSYMBOL_FOR: /* FOR  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2539 "basilisk.c"
        break;

    case YYSYMBOL_GOTO: /* GOTO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2548 "basilisk.c"
        break;

    case YYSYMBOL_CONTINUE: /* CONTINUE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2557 "basilisk.c"
        break;

    case YYSYMBOL_BREAK: /* BREAK  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2566 "basilisk.c"
        break;

    case YYSYMBOL_RETURN: /* RETURN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2575 "basilisk.c"
        break;

    case YYSYMBOL_ALIGNAS: /* ALIGNAS  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2584 "basilisk.c"
        break;

    case YYSYMBOL_ALIGNOF: /* ALIGNOF  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2593 "basilisk.c"
        break;

    case YYSYMBOL_ATOMIC: /* ATOMIC  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2602 "basilisk.c"
        break;

    case YYSYMBOL_GENERIC: /* GENERIC  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2611 "basilisk.c"
        break;

    case YYSYMBOL_NORETURN: /* NORETURN  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2620 "basilisk.c"
        break;

    case YYSYMBOL_STATIC_ASSERT: /* STATIC_ASSERT  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2629 "basilisk.c"
        break;

    case YYSYMBOL_THREAD_LOCAL: /* THREAD_LOCAL  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2638 "basilisk.c"
        break;

    case YYSYMBOL_MAYBECONST: /* MAYBECONST  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2647 "basilisk.c"
        break;

    case YYSYMBOL_NEW_FIELD: /* NEW_FIELD  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2656 "basilisk.c"
        break;

    case YYSYMBOL_TRACE: /* TRACE  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2665 "basilisk.c"
        break;

    case YYSYMBOL_FOREACH_DIMENSION: /* FOREACH_DIMENSION  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2674 "basilisk.c"
        break;

    case YYSYMBOL_REDUCTION: /* REDUCTION  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2683 "basilisk.c"
        break;

    case YYSYMBOL_MACRO: /* MACRO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2692 "basilisk.c"
        break;

    case YYSYMBOL_ELLIPSIS_MACRO: /* ELLIPSIS_MACRO  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2701 "basilisk.c"
        break;

    case YYSYMBOL_foreach_statement: /* foreach_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2710 "basilisk.c"
        break;

    case YYSYMBOL_84_: /* ';'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2719 "basilisk.c"
        break;

    case YYSYMBOL_85_: /* '}'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2728 "basilisk.c"
        break;

    case YYSYMBOL_86_: /* ')'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2737 "basilisk.c"
        break;

    case YYSYMBOL_87_: /* '('  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2746 "basilisk.c"
        break;

    case YYSYMBOL_88_: /* ','  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2755 "basilisk.c"
        break;

    case YYSYMBOL_89_: /* ':'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2764 "basilisk.c"
        break;

    case YYSYMBOL_90_: /* '.'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2773 "basilisk.c"
        break;

    case YYSYMBOL_91_: /* '{'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2782 "basilisk.c"
        break;

    case YYSYMBOL_92_: /* '['  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2791 "basilisk.c"
        break;

    case YYSYMBOL_93_: /* ']'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2800 "basilisk.c"
        break;

    case YYSYMBOL_94_: /* '*'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2809 "basilisk.c"
        break;

    case YYSYMBOL_95_: /* '&'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2818 "basilisk.c"
        break;

    case YYSYMBOL_96_: /* '+'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2827 "basilisk.c"
        break;

    case YYSYMBOL_97_: /* '-'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2836 "basilisk.c"
        break;

    case YYSYMBOL_98_: /* '~'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2845 "basilisk.c"
        break;

    case YYSYMBOL_99_: /* '!'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2854 "basilisk.c"
        break;

    case YYSYMBOL_100_: /* '/'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2863 "basilisk.c"
        break;

    case YYSYMBOL_101_: /* '%'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2872 "basilisk.c"
        break;

    case YYSYMBOL_102_: /* '<'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2881 "basilisk.c"
        break;

    case YYSYMBOL_103_: /* '>'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2890 "basilisk.c"
        break;

    case YYSYMBOL_104_: /* '^'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2899 "basilisk.c"
        break;

    case YYSYMBOL_105_: /* '|'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2908 "basilisk.c"
        break;

    case YYSYMBOL_106_: /* '?'  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2917 "basilisk.c"
        break;

    case YYSYMBOL_107_: /* '='  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2926 "basilisk.c"
        break;

    case YYSYMBOL_translation_unit: /* translation_unit  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2935 "basilisk.c"
        break;

    case YYSYMBOL_primary_expression: /* primary_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2944 "basilisk.c"
        break;

    case YYSYMBOL_expression_error: /* expression_error  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2953 "basilisk.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2962 "basilisk.c"
        break;

    case YYSYMBOL_enumeration_constant: /* enumeration_constant  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2971 "basilisk.c"
        break;

    case YYSYMBOL_string: /* string  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2980 "basilisk.c"
        break;

    case YYSYMBOL_generic_selection: /* generic_selection  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2989 "basilisk.c"
        break;

    case YYSYMBOL_generic_assoc_list: /* generic_assoc_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 2998 "basilisk.c"
        break;

    case YYSYMBOL_generic_association: /* generic_association  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3007 "basilisk.c"
        break;

    case YYSYMBOL_postfix_expression: /* postfix_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3016 "basilisk.c"
        break;

    case YYSYMBOL_postfix_initializer: /* postfix_initializer  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3025 "basilisk.c"
        break;

    case YYSYMBOL_array_access: /* array_access  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3034 "basilisk.c"
        break;

    case YYSYMBOL_function_call: /* function_call  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3043 "basilisk.c"
        break;

    case YYSYMBOL_member_identifier: /* member_identifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3052 "basilisk.c"
        break;

    case YYSYMBOL_argument_expression_list: /* argument_expression_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3061 "basilisk.c"
        break;

    case YYSYMBOL_argument_expression_list_item: /* argument_expression_list_item  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3070 "basilisk.c"
        break;

    case YYSYMBOL_unary_expression: /* unary_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3079 "basilisk.c"
        break;

    case YYSYMBOL_unary_operator: /* unary_operator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3088 "basilisk.c"
        break;

    case YYSYMBOL_cast_expression: /* cast_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3097 "basilisk.c"
        break;

    case YYSYMBOL_multiplicative_expression: /* multiplicative_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3106 "basilisk.c"
        break;

    case YYSYMBOL_additive_expression: /* additive_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3115 "basilisk.c"
        break;

    case YYSYMBOL_shift_expression: /* shift_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3124 "basilisk.c"
        break;

    case YYSYMBOL_relational_expression: /* relational_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3133 "basilisk.c"
        break;

    case YYSYMBOL_equality_expression: /* equality_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3142 "basilisk.c"
        break;

    case YYSYMBOL_and_expression: /* and_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3151 "basilisk.c"
        break;

    case YYSYMBOL_exclusive_or_expression: /* exclusive_or_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3160 "basilisk.c"
        break;

    case YYSYMBOL_inclusive_or_expression: /* inclusive_or_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3169 "basilisk.c"
        break;

    case YYSYMBOL_logical_and_expression: /* logical_and_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3178 "basilisk.c"
        break;

    case YYSYMBOL_logical_or_expression: /* logical_or_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3187 "basilisk.c"
        break;

    case YYSYMBOL_conditional_expression: /* conditional_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3196 "basilisk.c"
        break;

    case YYSYMBOL_assignment_expression: /* assignment_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3205 "basilisk.c"
        break;

    case YYSYMBOL_assignment_operator: /* assignment_operator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3214 "basilisk.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3223 "basilisk.c"
        break;

    case YYSYMBOL_constant_expression: /* constant_expression  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3232 "basilisk.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3241 "basilisk.c"
        break;

    case YYSYMBOL_declaration_specifiers: /* declaration_specifiers  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3250 "basilisk.c"
        break;

    case YYSYMBOL_init_declarator_list: /* init_declarator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3259 "basilisk.c"
        break;

    case YYSYMBOL_init_declarator: /* init_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3268 "basilisk.c"
        break;

    case YYSYMBOL_storage_class_specifier: /* storage_class_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3277 "basilisk.c"
        break;

    case YYSYMBOL_type_specifier: /* type_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3286 "basilisk.c"
        break;

    case YYSYMBOL_types: /* types  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3295 "basilisk.c"
        break;

    case YYSYMBOL_struct_or_union_specifier: /* struct_or_union_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3304 "basilisk.c"
        break;

    case YYSYMBOL_struct_or_union: /* struct_or_union  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3313 "basilisk.c"
        break;

    case YYSYMBOL_struct_declaration_list: /* struct_declaration_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3322 "basilisk.c"
        break;

    case YYSYMBOL_struct_declaration: /* struct_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3331 "basilisk.c"
        break;

    case YYSYMBOL_specifier_qualifier_list: /* specifier_qualifier_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3340 "basilisk.c"
        break;

    case YYSYMBOL_struct_declarator_list: /* struct_declarator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3349 "basilisk.c"
        break;

    case YYSYMBOL_struct_declarator: /* struct_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3358 "basilisk.c"
        break;

    case YYSYMBOL_enum_specifier: /* enum_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3367 "basilisk.c"
        break;

    case YYSYMBOL_enumerator_list: /* enumerator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3376 "basilisk.c"
        break;

    case YYSYMBOL_enumerator: /* enumerator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3385 "basilisk.c"
        break;

    case YYSYMBOL_atomic_type_specifier: /* atomic_type_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3394 "basilisk.c"
        break;

    case YYSYMBOL_type_qualifier: /* type_qualifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3403 "basilisk.c"
        break;

    case YYSYMBOL_function_specifier: /* function_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3412 "basilisk.c"
        break;

    case YYSYMBOL_alignment_specifier: /* alignment_specifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3421 "basilisk.c"
        break;

    case YYSYMBOL_declarator: /* declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3430 "basilisk.c"
        break;

    case YYSYMBOL_direct_declarator: /* direct_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3439 "basilisk.c"
        break;

    case YYSYMBOL_generic_identifier: /* generic_identifier  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3448 "basilisk.c"
        break;

    case YYSYMBOL_pointer: /* pointer  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3457 "basilisk.c"
        break;

    case YYSYMBOL_type_qualifier_list: /* type_qualifier_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3466 "basilisk.c"
        break;

    case YYSYMBOL_parameter_type_list: /* parameter_type_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3475 "basilisk.c"
        break;

    case YYSYMBOL_parameter_list: /* parameter_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3484 "basilisk.c"
        break;

    case YYSYMBOL_parameter_declaration: /* parameter_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3493 "basilisk.c"
        break;

    case YYSYMBOL_identifier_list: /* identifier_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3502 "basilisk.c"
        break;

    case YYSYMBOL_type_name: /* type_name  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3511 "basilisk.c"
        break;

    case YYSYMBOL_abstract_declarator: /* abstract_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3520 "basilisk.c"
        break;

    case YYSYMBOL_direct_abstract_declarator: /* direct_abstract_declarator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3529 "basilisk.c"
        break;

    case YYSYMBOL_type_not_specified: /* type_not_specified  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3538 "basilisk.c"
        break;

    case YYSYMBOL_initializer: /* initializer  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3547 "basilisk.c"
        break;

    case YYSYMBOL_initializer_list: /* initializer_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3556 "basilisk.c"
        break;

    case YYSYMBOL_designation: /* designation  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3565 "basilisk.c"
        break;

    case YYSYMBOL_designator_list: /* designator_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3574 "basilisk.c"
        break;

    case YYSYMBOL_designator: /* designator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3583 "basilisk.c"
        break;

    case YYSYMBOL_static_assert_declaration: /* static_assert_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3592 "basilisk.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3601 "basilisk.c"
        break;

    case YYSYMBOL_labeled_statement: /* labeled_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3610 "basilisk.c"
        break;

    case YYSYMBOL_compound_statement: /* compound_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3619 "basilisk.c"
        break;

    case YYSYMBOL_186_1: /* @1  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3628 "basilisk.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3637 "basilisk.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3646 "basilisk.c"
        break;

    case YYSYMBOL_expression_statement: /* expression_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3655 "basilisk.c"
        break;

    case YYSYMBOL_selection_statement: /* selection_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3664 "basilisk.c"
        break;

    case YYSYMBOL_for_scope: /* for_scope  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3673 "basilisk.c"
        break;

    case YYSYMBOL_iteration_statement: /* iteration_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3682 "basilisk.c"
        break;

    case YYSYMBOL_for_declaration_statement: /* for_declaration_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3691 "basilisk.c"
        break;

    case YYSYMBOL_jump_statement: /* jump_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3700 "basilisk.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3709 "basilisk.c"
        break;

    case YYSYMBOL_function_declaration: /* function_declaration  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3718 "basilisk.c"
        break;

    case YYSYMBOL_function_definition: /* function_definition  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3727 "basilisk.c"
        break;

    case YYSYMBOL_declaration_list: /* declaration_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3736 "basilisk.c"
        break;

    case YYSYMBOL_basilisk_statements: /* basilisk_statements  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3745 "basilisk.c"
        break;

    case YYSYMBOL_macro_statement: /* macro_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3754 "basilisk.c"
        break;

    case YYSYMBOL_reduction_list: /* reduction_list  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3763 "basilisk.c"
        break;

    case YYSYMBOL_reduction: /* reduction  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3772 "basilisk.c"
        break;

    case YYSYMBOL_reduction_operator: /* reduction_operator  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3781 "basilisk.c"
        break;

    case YYSYMBOL_reduction_array: /* reduction_array  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3790 "basilisk.c"
        break;

    case YYSYMBOL_foreach_dimension_statement: /* foreach_dimension_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3799 "basilisk.c"
        break;

    case YYSYMBOL_forin_declaration_statement: /* forin_declaration_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3808 "basilisk.c"
        break;

    case YYSYMBOL_forin_statement: /* forin_statement  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3817 "basilisk.c"
        break;

    case YYSYMBOL_forin_arguments: /* forin_arguments  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3826 "basilisk.c"
        break;

    case YYSYMBOL_event_definition: /* event_definition  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3835 "basilisk.c"
        break;

    case YYSYMBOL_event_parameters: /* event_parameters  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3844 "basilisk.c"
        break;

    case YYSYMBOL_event_parameter: /* event_parameter  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3853 "basilisk.c"
        break;

    case YYSYMBOL_boundary_definition: /* boundary_definition  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3862 "basilisk.c"
        break;

    case YYSYMBOL_external_foreach_dimension: /* external_foreach_dimension  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3871 "basilisk.c"
        break;

    case YYSYMBOL_attribute: /* attribute  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3880 "basilisk.c"
        break;

    case YYSYMBOL_new_field: /* new_field  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3889 "basilisk.c"
        break;

    case YYSYMBOL_root: /* root  */
#line 54 "basilisk.yacc"
         {
  fputc ('\n', stderr);
  ast_print_tree ((*yyvaluep), stderr, "  ", 0, -1);
}
#line 3898 "basilisk.c"
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
#line 118 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4294 "basilisk.c"
    break;

  case 5: /* translation_unit: translation_unit error '}'  */
#line 119 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4300 "basilisk.c"
    break;

  case 6: /* translation_unit: translation_unit error ')'  */
#line 120 "basilisk.yacc"
                                      { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4306 "basilisk.c"
    break;

  case 14: /* expression_error: error  */
#line 134 "basilisk.yacc"
                        { yyvsp[0]->sym = YYSYMBOL_YYerror; }
#line 4312 "basilisk.c"
    break;

  case 112: /* declaration: declaration_specifiers ';' type_not_specified  */
#line 330 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 4318 "basilisk.c"
    break;

  case 113: /* declaration: declaration_specifiers init_declarator_list ';' type_not_specified  */
#line 331 "basilisk.yacc"
                                                                               { ast_push_declaration (parse->stack, yyval); }
#line 4324 "basilisk.c"
    break;

  case 136: /* type_specifier: types  */
#line 369 "basilisk.yacc"
                   { parse->type_already_specified = true; }
#line 4330 "basilisk.c"
    break;

  case 156: /* struct_or_union_specifier: struct_or_union '{' error '}'  */
#line 395 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4336 "basilisk.c"
    break;

  case 157: /* struct_or_union_specifier: struct_or_union generic_identifier '{' error '}'  */
#line 396 "basilisk.yacc"
                                                            { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4342 "basilisk.c"
    break;

  case 207: /* direct_declarator: direct_declarator '(' type_not_specified error ')'  */
#line 491 "basilisk.yacc"
                                                                                           { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4348 "basilisk.c"
    break;

  case 257: /* type_not_specified: %empty  */
#line 574 "basilisk.yacc"
           { parse->type_already_specified = false; }
#line 4354 "basilisk.c"
    break;

  case 278: /* statement: error ';'  */
#line 616 "basilisk.yacc"
                     { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4360 "basilisk.c"
    break;

  case 283: /* @1: %empty  */
#line 628 "basilisk.yacc"
                           { stack_push (parse->stack, &(yyvsp[0])); yyval->sym = YYSYMBOL_YYUNDEF; }
#line 4366 "basilisk.c"
    break;

  case 284: /* compound_statement: '{' @1 block_item_list '}'  */
#line 630 "basilisk.yacc"
                           { ast_pop_scope (parse->stack, yyvsp[-3]); }
#line 4372 "basilisk.c"
    break;

  case 294: /* for_scope: FOR  */
#line 655 "basilisk.yacc"
              { stack_push (parse->stack, &(yyval)); }
#line 4378 "basilisk.c"
    break;

  case 297: /* iteration_statement: for_scope '(' expression_statement expression_statement ')' statement  */
#line 662 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 4384 "basilisk.c"
    break;

  case 298: /* iteration_statement: for_scope '(' expression_statement expression_statement expression ')' statement  */
#line 664 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 4390 "basilisk.c"
    break;

  case 300: /* for_declaration_statement: for_scope '(' declaration expression_statement ')' statement  */
#line 670 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-5]); }
#line 4396 "basilisk.c"
    break;

  case 301: /* for_declaration_statement: for_scope '(' declaration expression_statement expression ')' statement  */
#line 672 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 4402 "basilisk.c"
    break;

  case 313: /* external_declaration: error compound_statement  */
#line 690 "basilisk.yacc"
                                                { yyvsp[-1]->sym = YYSYMBOL_YYerror; }
#line 4408 "basilisk.c"
    break;

  case 314: /* function_declaration: declaration_specifiers declarator  */
#line 694 "basilisk.yacc"
                                            { ast_push_function_definition (parse->stack, yyvsp[0]);  }
#line 4414 "basilisk.c"
    break;

  case 315: /* function_definition: function_declaration declaration_list compound_statement  */
#line 699 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-2]->child[1]); }
#line 4420 "basilisk.c"
    break;

  case 316: /* function_definition: function_declaration compound_statement  */
#line 701 "basilisk.yacc"
                                                { ast_pop_scope (parse->stack, yyvsp[-1]->child[1]); }
#line 4426 "basilisk.c"
    break;

  case 336: /* forin_declaration_statement: for_scope '(' declaration_specifiers declarator IDENTIFIER forin_arguments ')' statement  */
#line 752 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-7]); }
#line 4432 "basilisk.c"
    break;

  case 337: /* forin_statement: for_scope '(' expression IDENTIFIER forin_arguments ')' statement  */
#line 757 "basilisk.yacc"
                    { ast_pop_scope (parse->stack, yyvsp[-6]); }
#line 4438 "basilisk.c"
    break;

  case 353: /* root: translation_unit  */
#line 800 "basilisk.yacc"
                           {
	  yyval = root;
	  yyval->sym = yyr1[yyn];
	  yyval->child = allocate ((Allocator *)parse->alloc, 2*sizeof(Ast *));
	  yyval->child[0] = yyvsp[0];
	  yyvsp[0]->parent = yyval;
	  yyval->child[1] = NULL;
        }
#line 4451 "basilisk.c"
    break;


#line 4455 "basilisk.c"

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

#line 810 "basilisk.yacc"


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
