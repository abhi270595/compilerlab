/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "slp.y" /* yacc.c:339  */

	#include <stdio.h>
	#include "lex.yy.c"
	#include "exprtree1.h"
	extern yylineno;
	int datatype;

#line 74 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    ID = 259,
    READ = 260,
    WRITE = 261,
    IF = 262,
    THEN = 263,
    ELSE = 264,
    ENDIF = 265,
    WHILE = 266,
    DO = 267,
    ENDWHILE = 268,
    INTEGER = 269,
    BOOLEAN = 270,
    DECL = 271,
    ENDDECL = 272,
    BEGINING = 273,
    END = 274,
    MAIN = 275,
    RETURN = 276,
    EQUAL = 277,
    TRUE = 278,
    FALSE = 279,
    GE = 280,
    LE = 281,
    NE = 282,
    AND = 283,
    OR = 284,
    NOT = 285
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define READ 260
#define WRITE 261
#define IF 262
#define THEN 263
#define ELSE 264
#define ENDIF 265
#define WHILE 266
#define DO 267
#define ENDWHILE 268
#define INTEGER 269
#define BOOLEAN 270
#define DECL 271
#define ENDDECL 272
#define BEGINING 273
#define END 274
#define MAIN 275
#define RETURN 276
#define EQUAL 277
#define TRUE 278
#define FALSE 279
#define GE 280
#define LE 281
#define NE 282
#define AND 283
#define OR 284
#define NOT 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 10 "slp.y" /* yacc.c:355  */

	int ival;
	char *var;
	struct tree_node *nptr;	

#line 180 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 195 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    39,     2,     2,
      40,    41,    37,    35,    31,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      33,    32,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    33,    33,    35,    37,    39,    40,    42,    44,    45,
      47,    48,    50,    51,    52,    54,    55,    57,    59,    60,
      62,    64,    65,    67,    69,    71,    73,    74,    76,    78,
      79,    81,    83,    85,    86,    88,    89,    91,    92,    93,
      94,    95,    96,    97,    98,   100,   101,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "READ", "WRITE", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "INTEGER", "BOOLEAN",
  "DECL", "ENDDECL", "BEGINING", "END", "MAIN", "RETURN", "EQUAL", "TRUE",
  "FALSE", "GE", "LE", "NE", "AND", "OR", "NOT", "','", "'='", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'['", "']'",
  "';'", "'{'", "'}'", "$accept", "pgm", "total", "gdefblock", "gdeflist",
  "gdecl", "type", "gidlist", "gid", "arglist", "arg", "argidlist",
  "argid", "fdeflist", "fdef", "mainblock", "ldefblock", "ldeflist",
  "ldecl", "lidlist", "lid", "body", "retstmt", "Slist", "Stmt",
  "exprlist", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    44,    61,    60,    62,    43,    45,    42,    47,    37,
      40,    41,    91,    93,    59,   123,   125
};
# endif

#define YYPACT_NINF -139

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-139)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,    39,    21,  -139,  -139,  -139,  -139,    -1,    39,    37,
    -139,    55,  -139,  -139,   -33,    14,    50,    70,    94,  -139,
    -139,    39,    96,  -139,    37,    61,    68,   105,    69,    39,
      77,  -139,    86,    39,  -139,    74,    98,  -139,  -139,  -139,
      83,   106,  -139,   105,   121,   101,  -139,    39,   130,   121,
     152,   122,    39,  -139,   112,   130,  -139,   123,   134,  -139,
    -139,   279,  -139,   120,  -139,   152,   -18,   137,   143,   144,
     145,    75,   176,  -139,  -139,  -139,    16,    16,   197,    16,
      16,    16,   158,   159,  -139,  -139,    19,  -139,  -139,    16,
      16,    38,    78,    47,   135,   153,   171,  -139,  -139,  -139,
      16,  -139,   189,    16,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,    16,  -139,   181,   175,    16,
     177,   212,   219,   -16,    97,  -139,   268,   236,   236,   268,
     243,   225,   236,   236,     6,     6,  -139,  -139,  -139,    16,
    -139,   116,  -139,  -139,  -139,    16,  -139,  -139,    58,   196,
     304,    44,   207,  -139,   194,  -139,   195,   204,  -139,   312,
    -139,  -139,   205,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     0,     2,    22,     8,     9,     0,     6,     0,
       1,     0,     4,     5,    12,     0,    11,     8,     0,    21,
       3,    16,     0,     7,     0,     0,     0,     0,     0,    16,
       0,    10,     0,    16,    20,     0,    19,    13,    15,    14,
       0,     0,    17,     0,     0,     0,    18,    27,     0,     0,
       0,     0,    27,    36,     0,     0,    31,     0,    30,    25,
      26,     0,    24,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    23,    29,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    65,    62,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    46,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    49,    50,    51,    52,
      53,    54,    47,    48,    56,    57,    60,    58,    59,     0,
      42,     0,    44,    36,    36,     0,    63,    64,     0,     0,
       0,     0,    45,    41,     0,    36,     0,     0,    43,     0,
      37,    39,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,  -139,   246,  -139,     0,   231,  -139,   -11,
    -139,   213,  -139,  -139,  -139,  -139,   208,   214,  -139,   202,
    -139,   232,  -139,  -138,  -139,  -139,   -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     7,     8,    27,    15,    16,    28,
      29,    35,    36,    11,    19,    20,    48,    51,    52,    57,
      58,    54,    72,    61,    73,   123,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      92,     9,    94,    95,    96,   150,   151,    21,     9,    22,
       1,    18,   101,   102,    76,   145,    12,   159,    38,    85,
      86,    10,    41,   124,    77,   146,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    87,
      88,    14,   141,   113,   114,   115,    89,    50,    66,    67,
      68,    69,    50,     5,     6,    70,    90,   157,    23,    99,
     103,   100,   148,   104,   105,   106,   107,   108,   152,    17,
       6,   109,   110,   111,   112,   113,   114,   115,    82,    83,
     103,    24,   116,   104,   105,   106,   107,   108,   118,   119,
      25,   109,   110,   111,   112,   113,   114,   115,    26,    30,
     103,    32,   153,   104,   105,   106,   107,   108,    33,    34,
      37,   109,   110,   111,   112,   113,   114,   115,    42,   103,
      39,   117,   104,   105,   106,   107,   108,    40,    44,    43,
     109,   110,   111,   112,   113,   114,   115,    47,   103,    59,
     147,   104,   105,   106,   107,   108,    49,    45,    53,   109,
     110,   111,   112,   113,   114,   115,    56,   103,    62,   149,
     104,   105,   106,   107,   108,    65,    74,    64,   109,   110,
     111,   112,   113,   114,   115,   103,   120,    78,   104,   105,
     106,   107,   108,    79,    80,    81,   109,   110,   111,   112,
     113,   114,   115,   103,   121,    84,   104,   105,   106,   107,
     108,    93,    97,    98,   109,   110,   111,   112,   113,   114,
     115,   103,   122,   139,   104,   105,   106,   107,   108,   140,
     143,   142,   109,   110,   111,   112,   113,   114,   115,   103,
     125,   144,   104,   105,   106,   107,   108,   154,   158,   160,
     109,   110,   111,   112,   113,   114,   115,   103,   161,   163,
     104,   105,   106,   107,    13,    31,    46,    55,   109,   110,
     111,   112,   113,   114,   115,   103,    60,    75,   104,   105,
     106,   111,   112,   113,   114,   115,   109,   110,   111,   112,
     113,   114,   115,    66,    67,    68,    69,    63,     0,     0,
      70,     0,     0,   104,   105,     0,     0,     0,     0,     0,
      71,   109,   110,   111,   112,   113,   114,   115,    66,    67,
      68,    69,     0,   155,   156,    70,    66,    67,    68,    69,
       0,     0,   162,    70
};

static const yytype_int16 yycheck[] =
{
      77,     1,    79,    80,    81,   143,   144,    40,     8,    42,
      16,    11,    89,    90,    32,    31,    17,   155,    29,     3,
       4,     0,    33,   100,    42,    41,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    23,
      24,     4,   119,    37,    38,    39,    30,    47,     4,     5,
       6,     7,    52,    14,    15,    11,    40,    13,    44,    40,
      22,    42,   139,    25,    26,    27,    28,    29,   145,    14,
      15,    33,    34,    35,    36,    37,    38,    39,     3,     4,
      22,    31,    44,    25,    26,    27,    28,    29,    41,    42,
      20,    33,    34,    35,    36,    37,    38,    39,     4,     3,
      22,    40,    44,    25,    26,    27,    28,    29,    40,     4,
      41,    33,    34,    35,    36,    37,    38,    39,    44,    22,
      43,    43,    25,    26,    27,    28,    29,    41,    45,    31,
      33,    34,    35,    36,    37,    38,    39,    16,    22,    17,
      43,    25,    26,    27,    28,    29,    45,    41,    18,    33,
      34,    35,    36,    37,    38,    39,     4,    22,    46,    43,
      25,    26,    27,    28,    29,    31,    46,    44,    33,    34,
      35,    36,    37,    38,    39,    22,    41,    40,    25,    26,
      27,    28,    29,    40,    40,    40,    33,    34,    35,    36,
      37,    38,    39,    22,    41,    19,    25,    26,    27,    28,
      29,     4,    44,    44,    33,    34,    35,    36,    37,    38,
      39,    22,    41,    32,    25,    26,    27,    28,    29,    44,
       8,    44,    33,    34,    35,    36,    37,    38,    39,    22,
      41,    12,    25,    26,    27,    28,    29,    41,    44,    44,
      33,    34,    35,    36,    37,    38,    39,    22,    44,    44,
      25,    26,    27,    28,     8,    24,    43,    49,    33,    34,
      35,    36,    37,    38,    39,    22,    52,    65,    25,    26,
      27,    35,    36,    37,    38,    39,    33,    34,    35,    36,
      37,    38,    39,     4,     5,     6,     7,    55,    -1,    -1,
      11,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      21,    33,    34,    35,    36,    37,    38,    39,     4,     5,
       6,     7,    -1,     9,    10,    11,     4,     5,     6,     7,
      -1,    -1,    10,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    48,    49,    50,    14,    15,    51,    52,    53,
       0,    60,    17,    51,     4,    54,    55,    14,    53,    61,
      62,    40,    42,    44,    31,    20,     4,    53,    56,    57,
       3,    54,    40,    40,     4,    58,    59,    41,    56,    43,
      41,    56,    44,    31,    45,    41,    58,    16,    63,    45,
      53,    64,    65,    18,    68,    63,     4,    66,    67,    17,
      64,    70,    46,    68,    44,    31,     4,     5,     6,     7,
      11,    21,    69,    71,    46,    66,    32,    42,    40,    40,
      40,    40,     3,     4,    19,     3,     4,    23,    24,    30,
      40,    73,    73,     4,    73,    73,    73,    44,    44,    40,
      42,    73,    73,    22,    25,    26,    27,    28,    29,    33,
      34,    35,    36,    37,    38,    39,    44,    43,    41,    42,
      41,    41,    41,    72,    73,    41,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    32,
      44,    73,    44,     8,    12,    31,    41,    43,    73,    43,
      70,    70,    73,    44,    41,     9,    10,    13,    44,    70,
      44,    44,    10,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    51,    52,    53,    53,
      54,    54,    55,    55,    55,    56,    56,    57,    58,    58,
      59,    60,    60,    61,    62,    63,    64,    64,    65,    66,
      66,    67,    68,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     0,     3,     1,     1,
       3,     1,     1,     4,     4,     2,     0,     3,     3,     1,
       1,     2,     0,     9,     8,     3,     2,     0,     3,     3,
       1,     1,     4,     3,     3,     2,     0,     8,    10,     8,
       4,     7,     5,     8,     5,     3,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     1,     4,     4,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 33 "slp.y" /* yacc.c:1646  */
    {evaluate((yyvsp[0].nptr)); exit(0);}
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 35 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkNode("%PGM%",(yyvsp[-1].nptr),(yyvsp[0].nptr));}
#line 1415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 37 "slp.y" /* yacc.c:1646  */
    {}
#line 1421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 39 "slp.y" /* yacc.c:1646  */
    {}
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 40 "slp.y" /* yacc.c:1646  */
    {}
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 42 "slp.y" /* yacc.c:1646  */
    {}
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 44 "slp.y" /* yacc.c:1646  */
    {datatype=2;}
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 45 "slp.y" /* yacc.c:1646  */
    {datatype=1;}
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 47 "slp.y" /* yacc.c:1646  */
    {}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 48 "slp.y" /* yacc.c:1646  */
    {}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 50 "slp.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[0].var),datatype,1,"%ID%",NULL);}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 51 "slp.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[-3].var),datatype,1,"%FUNCTION%",ARGLIST); ARGLIST=NULL;}
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 52 "slp.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[-3].var),datatype,(yyvsp[-1].ival),"%ARR%",NULL);}
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 54 "slp.y" /* yacc.c:1646  */
    {}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 55 "slp.y" /* yacc.c:1646  */
    {}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 57 "slp.y" /* yacc.c:1646  */
    {}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 59 "slp.y" /* yacc.c:1646  */
    {}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 60 "slp.y" /* yacc.c:1646  */
    {}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 62 "slp.y" /* yacc.c:1646  */
    {Arginstall((yyvsp[0].var),datatype);}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 64 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkNode("%FDEFLIST%",(yyvsp[-1].nptr),(yyvsp[0].nptr));}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 65 "slp.y" /* yacc.c:1646  */
    {}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 67 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkFDefNode((yyvsp[-7].var),datatype,ARGLIST,(yyvsp[-1].nptr));}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 69 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkFDefNode("main",2,NULL,(yyvsp[-1].nptr));}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 71 "slp.y" /* yacc.c:1646  */
    {}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 73 "slp.y" /* yacc.c:1646  */
    {}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 74 "slp.y" /* yacc.c:1646  */
    {}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 76 "slp.y" /* yacc.c:1646  */
    {}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 78 "slp.y" /* yacc.c:1646  */
    {}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 79 "slp.y" /* yacc.c:1646  */
    {}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 81 "slp.y" /* yacc.c:1646  */
    {Linstall((yyvsp[0].var),datatype,lbind); lbind+=1;}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 83 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkNode("%BODY%",(yyvsp[-2].nptr),(yyvsp[-1].nptr));}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 85 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkReturnNode_Num((yyvsp[-1].ival));}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 86 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkReturnNode_Id((yyvsp[-1].var));}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 88 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkNode("%LIST%",(yyvsp[-1].nptr),(yyvsp[0].nptr));}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 89 "slp.y" /* yacc.c:1646  */
    {}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 91 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkCondNode("%IF%",(yyvsp[-5].nptr),NULL,(yyvsp[-2].nptr));}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 92 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkCondNode("%IFELSE%",(yyvsp[-7].nptr),(yyvsp[-4].nptr),(yyvsp[-2].nptr));}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 93 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkCondNode("%WHILE%",(yyvsp[-5].nptr),NULL,(yyvsp[-2].nptr));}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 94 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkEquNode("=",ckLeafNode_Id((yyvsp[-3].var)),(yyvsp[-1].nptr));}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 95 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkEquNode("=",ckLeafNode_Arr((yyvsp[-6].var),(yyvsp[-4].nptr)),(yyvsp[-1].nptr));}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 96 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkRNode((yyvsp[-2].var));}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 97 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkRArrNode((yyvsp[-5].var),(yyvsp[-3].nptr));}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 98 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkWNode((yyvsp[-2].nptr));}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 100 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkNode("%EXPRLIST%",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 101 "slp.y" /* yacc.c:1646  */
    {}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 103 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkBoolOptNode("<",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 104 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkBoolOptNode(">",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 105 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkBoolOptNode("==",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 106 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkBoolOptNode(">=",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 107 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkBoolOptNode("<=",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 108 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkBoolOptNode("!=",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 109 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkBoolOptBoolNode("AND",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 110 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkBoolOptBoolNode("OR",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 111 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkBoolOptNotNode("NOT",(yyvsp[0].nptr));}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 112 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkOperatorNode("+",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 113 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkOperatorNode("-",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 114 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkOperatorNode("/",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 115 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkOperatorNode("%",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 116 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkOperatorNode("*",(yyvsp[-2].nptr),(yyvsp[0].nptr));}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 117 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[-1].nptr);}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 118 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=ckLeafNode_Id((yyvsp[0].var));}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 119 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=ckLeafNode_Function((yyvsp[-3].var),(yyvsp[-1].nptr));}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 120 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=ckLeafNode_Arr((yyvsp[-3].var),(yyvsp[-1].nptr));}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 121 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkLeafNode_Num((yyvsp[0].ival));}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 122 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkLeafNode_Bool("TRUE");}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 123 "slp.y" /* yacc.c:1646  */
    {(yyval.nptr)=mkLeafNode_Bool("FALSE");}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1803 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 126 "slp.y" /* yacc.c:1906  */


yyerror()
{printf("Syntax Error:Line No-%d, None of the Grammer rules Matched\n",yylineno); exit(1);}

int main(int argc,char *argv[])
{
	if(argc>=2)
	{
		yyin=fopen(argv[1],"r");
		yyparse();
		fclose(yyin);
	}
	else
		return yyparse();	
	return 0;
}
