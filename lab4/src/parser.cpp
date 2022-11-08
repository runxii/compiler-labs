/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 1 "src/parser.y"

    #include <iostream>
    #include <assert.h>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );

#line 77 "src/parser.cpp"




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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_BREAK = 7,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 8,                   /* CONTINUE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_CONST = 12,                     /* CONST  */
  YYSYMBOL_POUND = 13,                     /* POUND  */
  YYSYMBOL_LPAREN = 14,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 15,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 16,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 17,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 18,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_LSQR = 20,                      /* LSQR  */
  YYSYMBOL_RSQR = 21,                      /* RSQR  */
  YYSYMBOL_ADD = 22,                       /* ADD  */
  YYSYMBOL_SUB = 23,                       /* SUB  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_MUL = 25,                       /* MUL  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_LESS = 30,                      /* LESS  */
  YYSYMBOL_MORE = 31,                      /* MORE  */
  YYSYMBOL_ASSIGN = 32,                    /* ASSIGN  */
  YYSYMBOL_PLUSASSIGN = 33,                /* PLUSASSIGN  */
  YYSYMBOL_MINUSASSIGN = 34,               /* MINUSASSIGN  */
  YYSYMBOL_MULASSIGN = 35,                 /* MULASSIGN  */
  YYSYMBOL_DIVASSIGN = 36,                 /* DIVASSIGN  */
  YYSYMBOL_EQU = 37,                       /* EQU  */
  YYSYMBOL_GEQ = 38,                       /* GEQ  */
  YYSYMBOL_LEQ = 39,                       /* LEQ  */
  YYSYMBOL_NEQ = 40,                       /* NEQ  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_LINECOMMENTBEGIN = 42,          /* LINECOMMENTBEGIN  */
  YYSYMBOL_LINECOMMENTELEMENT = 43,        /* LINECOMMENTELEMENT  */
  YYSYMBOL_LINECOMMENTEND = 44,            /* LINECOMMENTEND  */
  YYSYMBOL_COMMENTBEIGN = 45,              /* COMMENTBEIGN  */
  YYSYMBOL_COMMENTELEMENT = 46,            /* COMMENTELEMENT  */
  YYSYMBOL_COMMENTEND = 47,                /* COMMENTEND  */
  YYSYMBOL_THEN = 48,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_Program = 50,                   /* Program  */
  YYSYMBOL_Stmts = 51,                     /* Stmts  */
  YYSYMBOL_Stmt = 52,                      /* Stmt  */
  YYSYMBOL_AssignStmt = 53,                /* AssignStmt  */
  YYSYMBOL_BlockStmt = 54,                 /* BlockStmt  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_IfStmt = 56,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 57,                 /* WhileStmt  */
  YYSYMBOL_ReturnStmt = 58,                /* ReturnStmt  */
  YYSYMBOL_SingleStmt = 59,                /* SingleStmt  */
  YYSYMBOL_Exp = 60,                       /* Exp  */
  YYSYMBOL_Cond = 61,                      /* Cond  */
  YYSYMBOL_LVal = 62,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 63,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 64,                  /* UnaryExp  */
  YYSYMBOL_MulExp = 65,                    /* MulExp  */
  YYSYMBOL_AddExp = 66,                    /* AddExp  */
  YYSYMBOL_RelExp = 67,                    /* RelExp  */
  YYSYMBOL_LAndExp = 68,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 69,                    /* LOrExp  */
  YYSYMBOL_Type = 70,                      /* Type  */
  YYSYMBOL_ConstDeclStmt = 71,             /* ConstDeclStmt  */
  YYSYMBOL_ConstIdQueue = 72,              /* ConstIdQueue  */
  YYSYMBOL_DeclStmt = 73,                  /* DeclStmt  */
  YYSYMBOL_IdQueue = 74,                   /* IdQueue  */
  YYSYMBOL_FuncRParams = 75,               /* FuncRParams  */
  YYSYMBOL_FuncFParams = 76,               /* FuncFParams  */
  YYSYMBOL_FuncDef = 77,                   /* FuncDef  */
  YYSYMBOL_78_2 = 78,                      /* $@2  */
  YYSYMBOL_79_3 = 79                       /* $@3  */
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
typedef yytype_uint8 yy_state_t;

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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    60,    61,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    82,    88,    87,
      98,   101,   104,   109,   115,   121,   127,   131,   135,   150,
     151,   156,   160,   162,   175,   188,   193,   198,   205,   207,
     213,   219,   227,   229,   235,   243,   245,   251,   257,   263,
     269,   275,   283,   285,   293,   295,   302,   305,   311,   315,
     328,   342,   346,   358,   368,   382,   396,   404,   413,   426,
     437,   452,   467,   467,   487,   487
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INTEGER", "IF",
  "ELSE", "BREAK", "CONTINUE", "WHILE", "INT", "VOID", "CONST", "POUND",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "COMMA", "LSQR",
  "RSQR", "ADD", "SUB", "DIV", "MUL", "MOD", "AND", "OR", "NOT", "LESS",
  "MORE", "ASSIGN", "PLUSASSIGN", "MINUSASSIGN", "MULASSIGN", "DIVASSIGN",
  "EQU", "GEQ", "LEQ", "NEQ", "RETURN", "LINECOMMENTBEGIN",
  "LINECOMMENTELEMENT", "LINECOMMENTEND", "COMMENTBEIGN", "COMMENTELEMENT",
  "COMMENTEND", "THEN", "$accept", "Program", "Stmts", "Stmt",
  "AssignStmt", "BlockStmt", "$@1", "IfStmt", "WhileStmt", "ReturnStmt",
  "SingleStmt", "Exp", "Cond", "LVal", "PrimaryExp", "UnaryExp", "MulExp",
  "AddExp", "RelExp", "LAndExp", "LOrExp", "Type", "ConstDeclStmt",
  "ConstIdQueue", "DeclStmt", "IdQueue", "FuncRParams", "FuncFParams",
  "FuncDef", "$@2", "$@3", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-113)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     154,   -11,  -113,    -6,     2,    38,    27,  -113,  -113,    23,
      21,  -113,  -113,    21,    21,    21,    21,    57,   154,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,    52,    42,  -113,  -113,
      43,    -5,    75,  -113,  -113,  -113,     7,    21,  -113,  -113,
      21,    76,    65,  -113,   154,  -113,  -113,  -113,    64,  -113,
    -113,  -113,    21,    21,    21,    21,    21,    21,    -9,    19,
    -113,  -113,    12,    68,    -5,     9,    58,    56,    73,    59,
      33,  -113,   126,  -113,    71,  -113,  -113,  -113,    43,    43,
      77,    21,  -113,    87,  -113,    21,   182,    21,    21,    21,
      21,    21,    21,    21,    21,   154,    21,  -113,    90,  -113,
    -113,    79,    23,  -113,    66,  -113,    80,    93,    -5,    -5,
      -5,    -5,    -5,    -5,     9,    58,  -113,  -113,    69,    84,
      99,    13,    21,  -113,   154,    21,  -113,    72,    84,    23,
    -113,  -113,  -113,    21,  -113,   100,  -113,    74,    21,  -113
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    28,    30,     0,     0,     0,     0,    56,    57,     0,
       0,    18,    13,     0,     0,     0,     0,     0,     2,     3,
       5,     6,     7,    12,     8,    16,     0,    29,    32,    38,
      42,    26,     0,    10,     9,    11,     0,     0,    14,    15,
       0,     0,     0,    29,     0,    35,    36,    37,     0,     1,
       4,    25,     0,     0,     0,     0,     0,     0,    62,     0,
      33,    66,     0,     0,    45,    52,    54,    27,     0,     0,
       0,    31,     0,    24,     0,    40,    39,    41,    43,    44,
      74,     0,    61,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,    19,
      17,     0,     0,    64,    63,    67,    18,    20,    46,    47,
      51,    48,    49,    50,    53,    55,    23,    59,     0,     0,
       0,     0,     0,    21,     0,     0,    73,    68,     0,     0,
      65,    22,    60,     0,    75,     0,    70,    69,     0,    71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -113,  -113,    61,   -14,  -113,  -112,  -113,  -113,  -113,  -113,
    -113,   -10,    67,     1,  -113,     0,    20,   -28,    15,    17,
    -113,    -7,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    17,    18,    19,    20,    21,    44,    22,    23,    24,
      25,    26,    63,    43,    28,    29,    30,    31,    65,    66,
      67,    32,    33,    70,    34,    59,    62,   121,    35,   101,
     102
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    27,    41,    36,    50,    80,    48,   126,    37,    64,
       1,     2,    64,    45,    46,    47,   134,    56,    57,    27,
      38,    10,    60,    81,     1,     2,    61,    84,   128,    13,
      14,    85,   129,     7,     8,    10,    15,    82,    83,    87,
      88,    40,    74,    13,    14,    27,    89,    90,    91,    92,
      15,    97,    98,    75,    76,    77,    39,    49,    50,   108,
     109,   110,   111,   112,   113,    64,    64,    53,    54,    55,
      51,   103,   107,    27,    52,   105,    78,    79,    58,    69,
      71,   116,    73,    86,    94,    93,   117,    27,    95,   100,
     104,    96,   -72,   118,   119,   120,    27,   123,   122,   124,
      11,   125,   127,   137,   133,    72,   138,    68,   114,     0,
     131,   115,   130,     0,     0,   132,     0,     0,     0,     0,
       0,     0,   135,   136,     0,    27,     0,     0,   139,     1,
       2,     3,     0,     4,     5,     6,     7,     8,     9,     0,
      10,     0,    11,    99,    12,     0,     0,     0,    13,    14,
       0,     0,     0,     0,     0,    15,     0,     1,     2,     3,
       0,     4,     5,     6,     7,     8,     9,    16,    10,     0,
      11,     0,    12,     0,     0,     0,    13,    14,     0,     0,
       0,     0,     0,    15,     0,     1,     2,     3,     0,     4,
       5,     6,     7,     8,     9,    16,    10,     0,   106,     0,
      12,     0,     0,     0,    13,    14,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16
};

static const yytype_int16 yycheck[] =
{
      10,     0,     9,    14,    18,    14,    16,   119,    14,    37,
       3,     4,    40,    13,    14,    15,   128,    22,    23,    18,
      18,    14,    15,    32,     3,     4,    36,    15,    15,    22,
      23,    19,    19,    10,    11,    14,    29,    18,    19,    30,
      31,    14,    52,    22,    23,    44,    37,    38,    39,    40,
      29,    18,    19,    53,    54,    55,    18,     0,    72,    87,
      88,    89,    90,    91,    92,    93,    94,    24,    25,    26,
      18,    81,    86,    72,    32,    85,    56,    57,     3,     3,
      15,    95,    18,    15,    28,    27,    96,    86,    15,    18,
       3,    32,    15,     3,    15,   102,    95,    17,    32,     6,
      16,    32,     3,     3,    32,    44,    32,    40,    93,    -1,
     124,    94,   122,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   133,    -1,   124,    -1,    -1,   138,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    29,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    41,    14,    -1,
      16,    -1,    18,    -1,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    12,    41,    14,    -1,    16,    -1,
      18,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    11,    12,
      14,    16,    18,    22,    23,    29,    41,    50,    51,    52,
      53,    54,    56,    57,    58,    59,    60,    62,    63,    64,
      65,    66,    70,    71,    73,    77,    14,    14,    18,    18,
      14,    70,    60,    62,    55,    64,    64,    64,    60,     0,
      52,    18,    32,    24,    25,    26,    22,    23,     3,    74,
      15,    60,    75,    61,    66,    67,    68,    69,    61,     3,
      72,    15,    51,    18,    60,    64,    64,    64,    65,    65,
      14,    32,    18,    19,    15,    19,    15,    30,    31,    37,
      38,    39,    40,    27,    28,    15,    32,    18,    19,    17,
      18,    78,    79,    60,     3,    60,    16,    52,    66,    66,
      66,    66,    66,    66,    67,    68,    52,    60,     3,    15,
      70,    76,    32,    17,     6,    32,    54,     3,    15,    19,
      60,    52,    60,    32,    54,    70,    60,     3,    32,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    55,    54,
      56,    56,    56,    57,    58,    59,    60,    61,    62,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    65,    65,
      65,    65,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      72,    73,    74,    74,    74,    74,    75,    75,    76,    76,
      76,    76,    78,    77,    79,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     4,     0,     4,
       5,     6,     7,     5,     3,     2,     1,     1,     1,     1,
       1,     3,     1,     3,     4,     2,     2,     2,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     3,     1,     1,     4,     3,
       5,     3,     1,     3,     3,     5,     1,     3,     2,     4,
       4,     6,     0,     6,     0,     7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (YY_("syntax error: cannot back up")); \
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: Stmts  */
#line 55 "src/parser.y"
            {
        ast.setRoot((yyvsp[0].stmttype));
    }
#line 1260 "src/parser.cpp"
    break;

  case 3: /* Stmts: Stmt  */
#line 60 "src/parser.y"
           {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1266 "src/parser.cpp"
    break;

  case 4: /* Stmts: Stmts Stmt  */
#line 61 "src/parser.y"
                {
        (yyval.stmttype) = new SeqNode((yyvsp[-1].stmttype), (yyvsp[0].stmttype));
    }
#line 1274 "src/parser.cpp"
    break;

  case 5: /* Stmt: AssignStmt  */
#line 66 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1280 "src/parser.cpp"
    break;

  case 6: /* Stmt: BlockStmt  */
#line 67 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1286 "src/parser.cpp"
    break;

  case 7: /* Stmt: IfStmt  */
#line 68 "src/parser.y"
             {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1292 "src/parser.cpp"
    break;

  case 8: /* Stmt: ReturnStmt  */
#line 69 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1298 "src/parser.cpp"
    break;

  case 9: /* Stmt: DeclStmt  */
#line 70 "src/parser.y"
               {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1304 "src/parser.cpp"
    break;

  case 10: /* Stmt: ConstDeclStmt  */
#line 71 "src/parser.y"
                    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1310 "src/parser.cpp"
    break;

  case 11: /* Stmt: FuncDef  */
#line 72 "src/parser.y"
              {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1316 "src/parser.cpp"
    break;

  case 12: /* Stmt: WhileStmt  */
#line 73 "src/parser.y"
                {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1322 "src/parser.cpp"
    break;

  case 13: /* Stmt: SEMICOLON  */
#line 74 "src/parser.y"
                {(yyval.stmttype) = new EmptyStmt();}
#line 1328 "src/parser.cpp"
    break;

  case 14: /* Stmt: BREAK SEMICOLON  */
#line 75 "src/parser.y"
                      {(yyval.stmttype) = new BreakStmt();}
#line 1334 "src/parser.cpp"
    break;

  case 15: /* Stmt: CONTINUE SEMICOLON  */
#line 76 "src/parser.y"
                         {(yyval.stmttype) = new ContinueStmt();}
#line 1340 "src/parser.cpp"
    break;

  case 16: /* Stmt: SingleStmt  */
#line 77 "src/parser.y"
                 {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1346 "src/parser.cpp"
    break;

  case 17: /* AssignStmt: LVal ASSIGN Exp SEMICOLON  */
#line 82 "src/parser.y"
                              {
        (yyval.stmttype) = new AssignStmt((yyvsp[-3].exprtype), (yyvsp[-1].exprtype));
    }
#line 1354 "src/parser.cpp"
    break;

  case 18: /* $@1: %empty  */
#line 88 "src/parser.y"
        {identifiers = new SymbolTable(identifiers);}
#line 1360 "src/parser.cpp"
    break;

  case 19: /* BlockStmt: LBRACE $@1 Stmts RBRACE  */
#line 90 "src/parser.y"
        {
            (yyval.stmttype) = new CompoundStmt((yyvsp[-1].stmttype));
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
#line 1371 "src/parser.cpp"
    break;

  case 20: /* IfStmt: IF LPAREN Cond RPAREN Stmt  */
#line 98 "src/parser.y"
                                            {
        (yyval.stmttype) = new IfStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 1379 "src/parser.cpp"
    break;

  case 21: /* IfStmt: IF LPAREN Cond RPAREN LBRACE RBRACE  */
#line 101 "src/parser.y"
                                          {
        (yyval.stmttype) = new IfStmt((yyvsp[-3].exprtype), new EmptyStmt());
    }
#line 1387 "src/parser.cpp"
    break;

  case 22: /* IfStmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 104 "src/parser.y"
                                           {
        (yyval.stmttype) = new IfElseStmt((yyvsp[-4].exprtype), (yyvsp[-2].stmttype), (yyvsp[0].stmttype));
    }
#line 1395 "src/parser.cpp"
    break;

  case 23: /* WhileStmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 109 "src/parser.y"
                                    {
        (yyval.stmttype) = new WhileStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 1403 "src/parser.cpp"
    break;

  case 24: /* ReturnStmt: RETURN Exp SEMICOLON  */
#line 115 "src/parser.y"
                         {
        (yyval.stmttype) = new ReturnStmt((yyvsp[-1].exprtype));
    }
#line 1411 "src/parser.cpp"
    break;

  case 25: /* SingleStmt: Exp SEMICOLON  */
#line 121 "src/parser.y"
                  {
        (yyval.stmttype) = new SingleStmt((yyvsp[-1].exprtype));
    }
#line 1419 "src/parser.cpp"
    break;

  case 26: /* Exp: AddExp  */
#line 127 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1425 "src/parser.cpp"
    break;

  case 27: /* Cond: LOrExp  */
#line 131 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1431 "src/parser.cpp"
    break;

  case 28: /* LVal: ID  */
#line 135 "src/parser.y"
         {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[0].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)(yyvsp[0].strtype));
            delete [](char*)(yyvsp[0].strtype);
            assert(se != nullptr);
        }
        (yyval.exprtype) = new Id(se);
        delete [](yyvsp[0].strtype);
    }
#line 1448 "src/parser.cpp"
    break;

  case 29: /* PrimaryExp: LVal  */
#line 150 "src/parser.y"
         {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1454 "src/parser.cpp"
    break;

  case 30: /* PrimaryExp: INTEGER  */
#line 151 "src/parser.y"
              {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::intType, (yyvsp[0].itype));
        (yyval.exprtype) = new Constant(se);
    }
#line 1463 "src/parser.cpp"
    break;

  case 31: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 156 "src/parser.y"
                      {(yyval.exprtype)=(yyvsp[-1].exprtype);}
#line 1469 "src/parser.cpp"
    break;

  case 32: /* UnaryExp: PrimaryExp  */
#line 160 "src/parser.y"
               {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1475 "src/parser.cpp"
    break;

  case 33: /* UnaryExp: ID LPAREN RPAREN  */
#line 162 "src/parser.y"
                     { // a()
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-2].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "Function \"%s\" is undefined\n", (char*)(yyvsp[-2].strtype));
            delete [](char*)(yyvsp[-2].strtype);
            assert(se != nullptr);
        }
        (yyval.exprtype) = new FunctionCall(se, nullptr);
        delete [](yyvsp[-2].strtype);
    }
#line 1492 "src/parser.cpp"
    break;

  case 34: /* UnaryExp: ID LPAREN FuncRParams RPAREN  */
#line 175 "src/parser.y"
                                 { // a(param)
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-3].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "Function \"%s\" is undefined\n", (char*)(yyvsp[-3].strtype));
            delete [](char*)(yyvsp[-3].strtype);
            assert(se != nullptr);
        }
        (yyval.exprtype) = new FunctionCall(se, (yyvsp[-1].FRtype));
        delete [](yyvsp[-3].strtype);
    }
#line 1509 "src/parser.cpp"
    break;

  case 35: /* UnaryExp: ADD UnaryExp  */
#line 188 "src/parser.y"
                 {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::ADD, (yyvsp[0].exprtype));
    }
#line 1518 "src/parser.cpp"
    break;

  case 36: /* UnaryExp: SUB UnaryExp  */
#line 193 "src/parser.y"
                 {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::SUB, (yyvsp[0].exprtype));
    }
#line 1527 "src/parser.cpp"
    break;

  case 37: /* UnaryExp: NOT UnaryExp  */
#line 198 "src/parser.y"
                 {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::NOT, (yyvsp[0].exprtype));
    }
#line 1536 "src/parser.cpp"
    break;

  case 38: /* MulExp: UnaryExp  */
#line 205 "src/parser.y"
             {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1542 "src/parser.cpp"
    break;

  case 39: /* MulExp: MulExp MUL UnaryExp  */
#line 208 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MUL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1551 "src/parser.cpp"
    break;

  case 40: /* MulExp: MulExp DIV UnaryExp  */
#line 214 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::DIV, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1560 "src/parser.cpp"
    break;

  case 41: /* MulExp: MulExp MOD UnaryExp  */
#line 220 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MOD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1569 "src/parser.cpp"
    break;

  case 42: /* AddExp: MulExp  */
#line 227 "src/parser.y"
           {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1575 "src/parser.cpp"
    break;

  case 43: /* AddExp: AddExp ADD MulExp  */
#line 230 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::ADD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1584 "src/parser.cpp"
    break;

  case 44: /* AddExp: AddExp SUB MulExp  */
#line 236 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::SUB, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1593 "src/parser.cpp"
    break;

  case 45: /* RelExp: AddExp  */
#line 243 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1599 "src/parser.cpp"
    break;

  case 46: /* RelExp: RelExp LESS AddExp  */
#line 246 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESS, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1608 "src/parser.cpp"
    break;

  case 47: /* RelExp: RelExp MORE AddExp  */
#line 252 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MORE, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1617 "src/parser.cpp"
    break;

  case 48: /* RelExp: RelExp GEQ AddExp  */
#line 258 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::GEQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1626 "src/parser.cpp"
    break;

  case 49: /* RelExp: RelExp LEQ AddExp  */
#line 264 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LEQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1635 "src/parser.cpp"
    break;

  case 50: /* RelExp: RelExp NEQ AddExp  */
#line 270 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NEQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1644 "src/parser.cpp"
    break;

  case 51: /* RelExp: RelExp EQU AddExp  */
#line 276 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::EQU, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1653 "src/parser.cpp"
    break;

  case 52: /* LAndExp: RelExp  */
#line 283 "src/parser.y"
           {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1659 "src/parser.cpp"
    break;

  case 53: /* LAndExp: LAndExp AND RelExp  */
#line 286 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::AND, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1668 "src/parser.cpp"
    break;

  case 54: /* LOrExp: LAndExp  */
#line 293 "src/parser.y"
            {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1674 "src/parser.cpp"
    break;

  case 55: /* LOrExp: LOrExp OR LAndExp  */
#line 296 "src/parser.y"
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::OR, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1683 "src/parser.cpp"
    break;

  case 56: /* Type: INT  */
#line 302 "src/parser.y"
          {
        (yyval.type) = TypeSystem::intType;
    }
#line 1691 "src/parser.cpp"
    break;

  case 57: /* Type: VOID  */
#line 305 "src/parser.y"
           {
        (yyval.type) = TypeSystem::voidType;
    }
#line 1699 "src/parser.cpp"
    break;

  case 58: /* ConstDeclStmt: CONST Type ConstIdQueue SEMICOLON  */
#line 311 "src/parser.y"
                                      {(yyval.stmttype)=new ConstDeclStmt((yyvsp[-1].constidtype));}
#line 1705 "src/parser.cpp"
    break;

  case 59: /* ConstIdQueue: ID ASSIGN Exp  */
#line 315 "src/parser.y"
                  {
        std::vector<ConstId*> constids;
        std::vector<AssignStmt*> assigns;
        ConstIdQueue* temp = new ConstIdQueue(constids, assigns);
        SymbolEntry* se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-2].strtype), identifiers -> getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        ConstId *t = new ConstId(se);
        temp -> constids.push_back(t);
        temp -> assigns.push_back(new AssignStmt(t, (yyvsp[0].exprtype)));
        (yyval.constidtype) = temp;
        delete [](yyvsp[-2].strtype);
    }
#line 1722 "src/parser.cpp"
    break;

  case 60: /* ConstIdQueue: ConstIdQueue COMMA ID ASSIGN Exp  */
#line 328 "src/parser.y"
                                     {
        ConstIdQueue *temp = (yyvsp[-4].constidtype);
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        ConstId *t = new ConstId(se);
        temp -> constids.push_back(t);
        temp -> assigns.push_back(new AssignStmt(t, (yyvsp[0].exprtype)));
        (yyval.constidtype) = temp;
        delete [](yyvsp[-2].strtype);
    }
#line 1738 "src/parser.cpp"
    break;

  case 61: /* DeclStmt: Type IdQueue SEMICOLON  */
#line 342 "src/parser.y"
                           {(yyval.stmttype)=new DeclStmt((yyvsp[-1].idqueuetype));}
#line 1744 "src/parser.cpp"
    break;

  case 62: /* IdQueue: ID  */
#line 346 "src/parser.y"
       {
        std::vector<Id*> ids;
        std::vector<AssignStmt*> assigns;
        IdQueue *temp = new IdQueue(ids, assigns);
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        temp -> ids.push_back(new Id(se));
        (yyval.idqueuetype) = temp;
        delete [](yyvsp[0].strtype);
    }
#line 1760 "src/parser.cpp"
    break;

  case 63: /* IdQueue: IdQueue COMMA ID  */
#line 358 "src/parser.y"
                     {
        IdQueue *temp = (yyvsp[-2].idqueuetype);
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        temp -> ids.push_back(new Id(se));
        (yyval.idqueuetype) = temp;
        delete [](yyvsp[0].strtype);
    }
#line 1774 "src/parser.cpp"
    break;

  case 64: /* IdQueue: ID ASSIGN Exp  */
#line 368 "src/parser.y"
                  {
        std::vector<Id*> ids;
        std::vector<AssignStmt*> assigns;
        IdQueue *temp = new IdQueue(ids, assigns);
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        Id *t = new Id(se);
        temp -> ids.push_back(t);
        temp -> assigns.push_back(new AssignStmt(t, (yyvsp[0].exprtype)));
        (yyval.idqueuetype) = temp;
        delete [](yyvsp[-2].strtype);
    }
#line 1792 "src/parser.cpp"
    break;

  case 65: /* IdQueue: IdQueue COMMA ID ASSIGN Exp  */
#line 382 "src/parser.y"
                                {
        IdQueue *temp = (yyvsp[-4].idqueuetype);
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        Id *t = new Id(se);
        temp -> ids.push_back(t);
        temp -> assigns.push_back(new AssignStmt(t, (yyvsp[0].exprtype)));
        (yyval.idqueuetype) = temp;
        delete [](yyvsp[-2].strtype);
    }
#line 1808 "src/parser.cpp"
    break;

  case 66: /* FuncRParams: Exp  */
#line 397 "src/parser.y"
    {
        std::vector<ExprNode*> t;
        t.push_back((yyvsp[0].exprtype));
        FuncRParams *temp = new FuncRParams(t);
        (yyval.FRtype) = temp;
    }
#line 1819 "src/parser.cpp"
    break;

  case 67: /* FuncRParams: FuncRParams COMMA Exp  */
#line 405 "src/parser.y"
    {
        FuncRParams *temp = (yyvsp[-2].FRtype);
        temp -> Exprs.push_back((yyvsp[0].exprtype));
        (yyval.FRtype) = temp;
    }
#line 1829 "src/parser.cpp"
    break;

  case 68: /* FuncFParams: Type ID  */
#line 414 "src/parser.y"
    {
        std::vector<FuncFParam*> FPs;
        std::vector<AssignStmt*> Assigns;
        FuncFParams *temp = new FuncFParams(FPs, Assigns);
        SymbolEntry *se;
        se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        temp -> FPs.push_back(new FuncFParam(se));
        (yyval.Fstype) = temp;
        delete [](yyvsp[0].strtype);
    }
#line 1845 "src/parser.cpp"
    break;

  case 69: /* FuncFParams: FuncFParams COMMA Type ID  */
#line 427 "src/parser.y"
    {
        FuncFParams *temp = (yyvsp[-3].Fstype);
        SymbolEntry *se;
        se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        temp -> FPs.push_back(new FuncFParam(se));
        (yyval.Fstype) = temp;
        delete [](yyvsp[0].strtype);
    }
#line 1859 "src/parser.cpp"
    break;

  case 70: /* FuncFParams: Type ID ASSIGN Exp  */
#line 438 "src/parser.y"
    {
        std::vector<FuncFParam*> FPs;
        std::vector<AssignStmt*> Assigns;
        FuncFParams *temp = new FuncFParams(FPs, Assigns);
        SymbolEntry *se;
        se = new IdentifierSymbolEntry((yyvsp[-3].type), (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        FuncFParam* t = new FuncFParam(se);
        temp -> FPs.push_back(t);
        temp -> Assigns.push_back(new AssignStmt(t, (yyvsp[0].exprtype)));
        (yyval.Fstype) = temp;
        delete [](yyvsp[-2].strtype);
    }
#line 1877 "src/parser.cpp"
    break;

  case 71: /* FuncFParams: FuncFParams COMMA Type ID ASSIGN Exp  */
#line 453 "src/parser.y"
    {
        FuncFParams *temp = (yyvsp[-5].Fstype);
        SymbolEntry *se;
        se = new IdentifierSymbolEntry((yyvsp[-3].type), (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        FuncFParam* t = new FuncFParam(se);
        temp -> FPs.push_back(t);
        temp -> Assigns.push_back(new AssignStmt(t, (yyvsp[0].exprtype)));
        (yyval.Fstype) = temp;
        delete [](yyvsp[-2].strtype);
    }
#line 1893 "src/parser.cpp"
    break;

  case 72: /* $@2: %empty  */
#line 467 "src/parser.y"
                   {
        Type *funcType;
        funcType = new FunctionType((yyvsp[-2].type),{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, (yyvsp[-1].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-1].strtype), se);
        identifiers = new SymbolTable(identifiers);
    }
#line 1905 "src/parser.cpp"
    break;

  case 73: /* FuncDef: Type ID LPAREN $@2 RPAREN BlockStmt  */
#line 476 "src/parser.y"
    {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-4].strtype));
        assert(se != nullptr);
        (yyval.stmttype) = new FunctionDef(se, nullptr,(yyvsp[0].stmttype));
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete [](yyvsp[-4].strtype);
    }
#line 1920 "src/parser.cpp"
    break;

  case 74: /* $@3: %empty  */
#line 487 "src/parser.y"
                   {
        Type *funcType;
        funcType = new FunctionType((yyvsp[-2].type),{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, (yyvsp[-1].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-1].strtype), se);
        identifiers = new SymbolTable(identifiers);
    }
#line 1932 "src/parser.cpp"
    break;

  case 75: /* FuncDef: Type ID LPAREN $@3 FuncFParams RPAREN BlockStmt  */
#line 496 "src/parser.y"
    {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[-5].strtype));
        assert(se != nullptr);
        (yyval.stmttype) = new FunctionDef(se, (yyvsp[-2].Fstype) ,(yyvsp[0].stmttype));
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        delete [](yyvsp[-5].strtype);
    }
#line 1947 "src/parser.cpp"
    break;


#line 1951 "src/parser.cpp"

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
      yyerror (YY_("syntax error"));
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
                      yytoken, &yylval);
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
  ++yynerrs;

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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 507 "src/parser.y"


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
