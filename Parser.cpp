/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "Grammar.y"

#include <stdio.h>
#include <string.h>
#include "ASTClass.h"
#include <string>

using namespace std;

extern Expression* root;

extern int yyparse();
extern int yylex();

/*
int main()
{
    yyparse();
}
*/

static string strErrReplace(const char* str);

extern char* yytext;
extern int yylineno;

void yyerror(const char *str)
{
    cerr << "error: " << strErrReplace(str) << "." << endl;
    cerr << yytext << " at line " << yylineno << endl;
}

int yywrap()
{
    return 1;
}

int BasicNode::idCnt = 0;


/* Line 371 of yacc.c  */
#line 108 "Parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_ARRAY = 258,
     TOK_BREAK = 259,
     TOK_DO = 260,
     TOK_ELSE = 261,
     TOK_END = 262,
     TOK_FOR = 263,
     TOK_FUNCTION = 264,
     TOK_IF = 265,
     TOK_IN = 266,
     TOK_LET = 267,
     TOK_NIL = 268,
     TOK_OF = 269,
     TOK_THEN = 270,
     TOK_TO = 271,
     TOK_TYPE = 272,
     TOK_VAR = 273,
     TOK_WHILE = 274,
     TOK_PLUS_SIGN = 275,
     TOK_MINUS_SIGN = 276,
     TOK_MULT_SIGN = 277,
     TOK_DIV_SIGN = 278,
     TOK_AND = 279,
     TOK_OR = 280,
     TOK_EQUALS = 281,
     TOK_NEQ = 282,
     TOK_LT = 283,
     TOK_LTE = 284,
     TOK_GT = 285,
     TOK_GTE = 286,
     TOK_ASSIGN = 287,
     TOK_SEMIC = 288,
     TOK_COMMA = 289,
     TOK_COLON = 290,
     TOK_DOT = 291,
     TOK_LBR = 292,
     TOK_RBR = 293,
     TOK_LSQB = 294,
     TOK_RSQB = 295,
     TOK_LCURLB = 296,
     TOK_RCURLB = 297,
     TOK_INTEGER = 298,
     TOK_ID = 299,
     TOK_STRING = 300,
     EXP_REDUCE_PREC = 301,
     IF_WO_ELSE_PREC = 302,
     UNIOP_PREC = 303
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 41 "Grammar.y"

    string *strPtr;
    TInt integer;
    Expression* exp;
    Dec* dec;
    IdSqB* idSqB;
    LVal* lVal;
    ExpList* expList;
    ArgList* argList;
    FieldList* fieldList;
    FieldExpList* fieldExpList;
    DecList* decList;
    Ty* ty;
    BinOpType binOpType;
    UnOpType unOpType;


/* Line 387 of yacc.c  */
#line 217 "Parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 245 "Parser.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   254

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  133

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    18,    22,
      26,    30,    34,    38,    41,    46,    50,    54,    59,    66,
      71,    80,    82,    88,    92,    96,    97,   100,   102,   104,
     106,   111,   113,   117,   121,   126,   133,   141,   151,   154,
     156,   160,   162,   165,   166,   168,   172,   173,   175,   179,
     180,   184,   190,   191,   195,   201,   203,   205,   207,   209,
     211,   213,   215,   217,   219,   221,   223,   225
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    60,    -1,    43,    -1,    13,
      -1,    45,    -1,    44,    37,    62,    38,    -1,    51,    65,
      51,    -1,    51,    66,    51,    -1,    51,    67,    51,    -1,
      51,    68,    51,    -1,    51,    69,    51,    -1,    70,    51,
      -1,    44,    41,    64,    42,    -1,    37,    61,    38,    -1,
      60,    32,    51,    -1,    10,    51,    15,    51,    -1,    10,
      51,    15,    51,     6,    51,    -1,    19,    51,     5,    51,
      -1,     8,    44,    32,    51,    16,    51,     5,    51,    -1,
       4,    -1,    12,    53,    11,    61,     7,    -1,    59,    14,
      51,    -1,    39,    51,    40,    -1,    -1,    53,    54,    -1,
      55,    -1,    57,    -1,    58,    -1,    17,    44,    26,    56,
      -1,    44,    -1,    41,    63,    42,    -1,     3,    14,    44,
      -1,    18,    44,    32,    51,    -1,    18,    44,    35,    44,
      32,    51,    -1,     9,    44,    37,    63,    38,    26,    51,
      -1,     9,    44,    37,    63,    38,    35,    44,    26,    51,
      -1,    44,    52,    -1,    44,    -1,    60,    36,    44,    -1,
      59,    -1,    60,    52,    -1,    -1,    51,    -1,    61,    33,
      51,    -1,    -1,    51,    -1,    62,    34,    51,    -1,    -1,
      44,    35,    44,    -1,    63,    34,    44,    35,    44,    -1,
      -1,    44,    26,    51,    -1,    64,    34,    44,    26,    51,
      -1,    22,    -1,    23,    -1,    20,    -1,    21,    -1,    27,
      -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,    26,
      -1,    24,    -1,    25,    -1,    21,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   108,   112,   116,   120,   125,   130,   134,
     138,   142,   146,   150,   154,   159,   163,   167,   171,   175,
     179,   184,   188,   192,   199,   205,   208,   215,   216,   217,
     220,   227,   232,   236,   243,   248,   256,   261,   269,   275,
     280,   285,   289,   296,   299,   304,   312,   315,   320,   328,
     331,   338,   348,   351,   357,   365,   369,   374,   378,   383,
     387,   391,   395,   399,   403,   408,   413,   418
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_ARRAY", "TOK_BREAK", "TOK_DO",
  "TOK_ELSE", "TOK_END", "TOK_FOR", "TOK_FUNCTION", "TOK_IF", "TOK_IN",
  "TOK_LET", "TOK_NIL", "TOK_OF", "TOK_THEN", "TOK_TO", "TOK_TYPE",
  "TOK_VAR", "TOK_WHILE", "TOK_PLUS_SIGN", "TOK_MINUS_SIGN",
  "TOK_MULT_SIGN", "TOK_DIV_SIGN", "TOK_AND", "TOK_OR", "TOK_EQUALS",
  "TOK_NEQ", "TOK_LT", "TOK_LTE", "TOK_GT", "TOK_GTE", "TOK_ASSIGN",
  "TOK_SEMIC", "TOK_COMMA", "TOK_COLON", "TOK_DOT", "TOK_LBR", "TOK_RBR",
  "TOK_LSQB", "TOK_RSQB", "TOK_LCURLB", "TOK_RCURLB", "TOK_INTEGER",
  "TOK_ID", "TOK_STRING", "EXP_REDUCE_PREC", "IF_WO_ELSE_PREC",
  "UNIOP_PREC", "$accept", "Prog", "Exp", "SqBExp", "DecList", "Dec",
  "TyDec", "Ty", "VarDec", "FuncDec", "IdSqB", "LValue", "ExpList",
  "ArgList", "FieldList", "FieldExpList", "BinOp_L1", "BinOp_L2",
  "BinOp_L3", "BinOp_L4", "BinOp_L5", "UnOp", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    53,    53,    54,    54,    54,
      55,    56,    56,    56,    57,    57,    58,    58,    59,    60,
      60,    60,    60,    61,    61,    61,    62,    62,    62,    63,
      63,    63,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    68,    69,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     4,     3,     3,
       3,     3,     3,     2,     4,     3,     3,     4,     6,     4,
       8,     1,     5,     3,     3,     0,     2,     1,     1,     1,
       4,     1,     3,     3,     4,     6,     7,     9,     2,     1,
       3,     1,     2,     0,     1,     3,     0,     1,     3,     0,
       3,     5,     0,     3,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    21,     0,     0,    25,     5,     0,    67,    43,     4,
      39,     6,     0,     2,    41,     3,     0,     0,     0,     0,
       0,    44,     0,    46,     0,    52,    38,     1,    57,    58,
      55,    56,    65,    66,    64,    59,    60,    61,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,    42,    13,
       0,     0,     0,    43,     0,     0,    26,    27,    28,    29,
       0,     0,    15,    47,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    23,    16,    40,     0,    17,     0,     0,
       0,     0,    19,    45,     0,     7,    24,     0,     0,    14,
       0,     0,    49,    22,     0,     0,     0,    48,    53,     0,
       0,    18,     0,     0,     0,    49,    31,    30,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    20,
      50,     0,     0,     0,    33,    32,    35,     0,    36,     0,
      51,     0,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    21,    26,    19,    56,    57,   107,    58,    59,
      14,    15,    22,    64,   103,    67,    40,    41,    42,    43,
      44,    16
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -41
static const yytype_int16 yypact[] =
{
      55,   -41,   -40,    55,   -41,   -41,    55,   -41,    55,   -41,
      17,   -41,    19,   187,    23,    30,    55,    25,   159,     3,
       5,   187,    15,    55,    55,    -6,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
      55,    55,    55,    55,    55,    55,    55,    11,   -41,   -41,
      55,    55,    20,    55,    26,    33,   -41,   -41,   -41,   -41,
      55,    55,   -41,   187,   -16,   138,    21,   -33,   -41,    50,
     211,   223,   199,   187,   187,   -41,   175,   126,    41,     6,
      53,   -30,   187,   187,    55,   -41,   -41,    55,    36,   -41,
      55,    55,    38,   -41,     8,    55,    39,   187,   187,    59,
     113,   187,    46,    37,    72,    38,   -41,   -41,   187,    56,
      55,    55,    45,    49,   -18,    52,   -27,    55,   187,   187,
     -41,    62,    55,    57,   -41,   -41,   187,    58,   187,    68,
     -41,    55,   187
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,     0,    88,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,    51,   -41,     1,   -41,   -41,   -41,   -41,   -41,
     -41,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      13,    88,    95,    18,    17,    96,    20,   113,   122,    89,
      60,   104,    52,    93,    53,   125,    49,   123,    84,    27,
      54,    55,    85,    63,    65,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    45,    66,    61,
      68,    69,    70,    71,    72,    73,    74,    87,    61,   105,
      76,    77,   106,    62,    23,    75,    24,    50,    25,     1,
      82,    83,    46,     2,    78,     3,    47,     4,     5,    24,
      80,   113,    30,    31,     6,   114,     7,    81,    92,    94,
      99,   112,   102,   109,    97,   110,   115,    98,   117,   120,
     100,   101,     8,   121,   131,   108,   124,   127,     9,    10,
      11,   129,   130,    48,    79,     0,   116,     0,     0,     0,
     118,   119,     0,     0,     0,     0,     0,   126,   111,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
       0,   132,    91,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,     0,     0,     0,    51,     0,     0,     0,    86,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    90,     0,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    28,
      29,    30,    31,    32,     0,    34,    35,    36,    37,    38,
      39,    28,    29,    30,    31,     0,     0,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,     0,     0,    34,
      35,    36,    37,    38,    39
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-41)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

static const yytype_int16 yycheck[] =
{
       0,    34,    32,     3,    44,    35,     6,    34,    26,    42,
       5,     3,     9,     7,    11,    42,    16,    35,    34,     0,
      17,    18,    38,    23,    24,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    14,    44,    33,
      40,    41,    42,    43,    44,    45,    46,    26,    33,    41,
      50,    51,    44,    38,    37,    44,    39,    32,    41,     4,
      60,    61,    32,     8,    44,    10,    36,    12,    13,    39,
      44,    34,    22,    23,    19,    38,    21,    44,    37,    26,
      44,    35,    44,    44,    84,    26,    14,    87,    32,    44,
      90,    91,    37,    44,    26,    95,    44,    35,    43,    44,
      45,    44,    44,    15,    53,    -1,   105,    -1,    -1,    -1,
     110,   111,    -1,    -1,    -1,    -1,    -1,   117,     5,    -1,
      -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,     6,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    40,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    20,    21,    22,    23,    -1,    -1,    26,    27,    28,
      29,    30,    31,    20,    21,    22,    23,    -1,    -1,    26,
      27,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     8,    10,    12,    13,    19,    21,    37,    43,
      44,    45,    50,    51,    59,    60,    70,    44,    51,    53,
      51,    51,    61,    37,    39,    41,    52,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      65,    66,    67,    68,    69,    14,    32,    36,    52,    51,
      32,    15,     9,    11,    17,    18,    54,    55,    57,    58,
       5,    33,    38,    51,    62,    51,    44,    64,    51,    51,
      51,    51,    51,    51,    51,    44,    51,    51,    44,    61,
      44,    44,    51,    51,    34,    38,    40,    26,    34,    42,
      16,     6,    37,     7,    26,    32,    35,    51,    51,    44,
      51,    51,    44,    63,     3,    41,    44,    56,    51,    44,
      26,     5,    35,    34,    38,    14,    63,    32,    51,    51,
      44,    44,    26,    35,    44,    42,    51,    35,    51,    44,
      44,    26,    51
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 103 "Grammar.y"
    {
                            root = (yyvsp[(1) - (1)].exp);
                        }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 109 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpLValue((yyvsp[(1) - (1)].lVal));
                        }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 113 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpInteger((yyvsp[(1) - (1)].integer));
                        }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 117 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpNil();
                        }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 121 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpString(*(yyvsp[(1) - (1)].strPtr));
                            delete (yyvsp[(1) - (1)].strPtr); (yyvsp[(1) - (1)].strPtr) = NULL;
                        }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 126 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpFuncCall(*(yyvsp[(1) - (4)].strPtr), (yyvsp[(3) - (4)].argList));
                            delete (yyvsp[(1) - (4)].strPtr); (yyvsp[(1) - (4)].strPtr) = NULL;
                        }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 131 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpBinOp((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), (yyvsp[(2) - (3)].binOpType));
                        }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 135 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpBinOp((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), (yyvsp[(2) - (3)].binOpType));
                        }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 139 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpBinOp((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), (yyvsp[(2) - (3)].binOpType));
                        }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 143 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpBinOp((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), (yyvsp[(2) - (3)].binOpType));
                        }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 147 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpBinOp((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), (yyvsp[(2) - (3)].binOpType));
                        }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 151 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpUnOp((yyvsp[(2) - (2)].exp), (yyvsp[(1) - (2)].unOpType));
                        }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 155 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpRecord(*(yyvsp[(1) - (4)].strPtr), (yyvsp[(3) - (4)].fieldExpList));
                            delete (yyvsp[(1) - (4)].strPtr); (yyvsp[(1) - (4)].strPtr) = NULL;
                        }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 160 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpExpList((yyvsp[(2) - (3)].expList));
                        }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 164 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpAssign((yyvsp[(1) - (3)].lVal), (yyvsp[(3) - (3)].exp));
                        }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 168 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpIf((yyvsp[(2) - (4)].exp), (yyvsp[(4) - (4)].exp));
                        }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 172 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpIf((yyvsp[(2) - (6)].exp), (yyvsp[(4) - (6)].exp), (yyvsp[(6) - (6)].exp));
                        }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 176 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpWhile((yyvsp[(2) - (4)].exp), (yyvsp[(4) - (4)].exp));
                        }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 180 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpFor(*(yyvsp[(2) - (8)].strPtr), (yyvsp[(4) - (8)].exp), (yyvsp[(6) - (8)].exp), (yyvsp[(8) - (8)].exp));
                            delete (yyvsp[(2) - (8)].strPtr); (yyvsp[(2) - (8)].strPtr) = NULL;
                        }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 185 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpBreak();
                        }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 189 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpLet((yyvsp[(2) - (5)].decList), (yyvsp[(4) - (5)].expList));
                        }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 193 "Grammar.y"
    {
                            (yyval.exp) = (Expression*) new ExpArray((yyvsp[(1) - (3)].idSqB) -> first, (yyvsp[(1) - (3)].idSqB) -> second,  (yyvsp[(3) - (3)].exp));
                            delete (yyvsp[(1) - (3)].idSqB); (yyvsp[(1) - (3)].idSqB) = NULL;
                        }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 200 "Grammar.y"
    {
                            (yyval.exp) = (yyvsp[(2) - (3)].exp);
                        }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 205 "Grammar.y"
    {
                            (yyval.decList) = new DecList;
                        }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 209 "Grammar.y"
    {
                            (yyvsp[(1) - (2)].decList) -> push_back((yyvsp[(2) - (2)].dec));
                            (yyval.decList) = (yyvsp[(1) - (2)].decList);
                        }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 221 "Grammar.y"
    {
                            (yyval.dec) = (Dec*) new TyDec(*(yyvsp[(2) - (4)].strPtr), (yyvsp[(4) - (4)].ty));
                            delete (yyvsp[(2) - (4)].strPtr); (yyvsp[(2) - (4)].strPtr) = NULL;
                        }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 228 "Grammar.y"
    {
                            (yyval.ty) = new Ty(TY_ID, *(yyvsp[(1) - (1)].strPtr));
                            delete (yyvsp[(1) - (1)].strPtr); (yyvsp[(1) - (1)].strPtr) = NULL;
                        }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 233 "Grammar.y"
    {
                            (yyval.ty) = new Ty(TY_Record, (yyvsp[(2) - (3)].fieldList));
                        }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 237 "Grammar.y"
    {
                            (yyval.ty) = new Ty(TY_Array, *(yyvsp[(3) - (3)].strPtr));
                            delete (yyvsp[(3) - (3)].strPtr); (yyvsp[(3) - (3)].strPtr) = NULL;
                        }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 244 "Grammar.y"
    {
                            (yyval.dec) = (Dec*) new VarDec(*(yyvsp[(2) - (4)].strPtr), (yyvsp[(4) - (4)].exp));
                            delete (yyvsp[(2) - (4)].strPtr); (yyvsp[(2) - (4)].strPtr) = NULL;
                        }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 249 "Grammar.y"
    {
                            (yyval.dec) = (Dec*) new VarDec(*(yyvsp[(2) - (6)].strPtr), *(yyvsp[(4) - (6)].strPtr), (yyvsp[(6) - (6)].exp));
                            delete (yyvsp[(2) - (6)].strPtr); (yyvsp[(2) - (6)].strPtr) = NULL;
                            delete (yyvsp[(4) - (6)].strPtr); (yyvsp[(4) - (6)].strPtr) = NULL;
                        }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 257 "Grammar.y"
    {
                            (yyval.dec) = (Dec*) new FuncDec(*(yyvsp[(2) - (7)].strPtr), (yyvsp[(4) - (7)].fieldList), (yyvsp[(7) - (7)].exp));
                            delete (yyvsp[(2) - (7)].strPtr); (yyvsp[(2) - (7)].strPtr) = NULL;
                        }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 262 "Grammar.y"
    {
                            (yyval.dec) = (Dec*) new FuncDec(*(yyvsp[(2) - (9)].strPtr), (yyvsp[(4) - (9)].fieldList), *(yyvsp[(7) - (9)].strPtr), (yyvsp[(9) - (9)].exp));
                            delete (yyvsp[(2) - (9)].strPtr); (yyvsp[(2) - (9)].strPtr) = NULL;
                            delete (yyvsp[(7) - (9)].strPtr); (yyvsp[(7) - (9)].strPtr) = NULL;
                        }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 270 "Grammar.y"
    {
                            (yyval.idSqB) = new IdSqB(*(yyvsp[(1) - (2)].strPtr), (yyvsp[(2) - (2)].exp));
                            delete (yyvsp[(1) - (2)].strPtr); (yyvsp[(1) - (2)].strPtr) = NULL;
                        }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 276 "Grammar.y"
    {
                            (yyval.lVal) = (LVal*) new LValID(*(yyvsp[(1) - (1)].strPtr));
                            delete (yyvsp[(1) - (1)].strPtr); (yyvsp[(1) - (1)].strPtr) = NULL;
                        }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 281 "Grammar.y"
    {
                            (yyval.lVal) = (LVal*) new LValMember((yyvsp[(1) - (3)].lVal), *(yyvsp[(3) - (3)].strPtr));
                            delete (yyvsp[(3) - (3)].strPtr); (yyvsp[(3) - (3)].strPtr) = NULL;
                        }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 286 "Grammar.y"
    {
                            (yyval.lVal) = (LVal*) new LValElement((LVal*) new LValID((yyvsp[(1) - (1)].idSqB) -> first), (yyvsp[(1) - (1)].idSqB) -> second);
                        }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 290 "Grammar.y"
    {
                            (yyval.lVal) = (LVal*) new LValElement((yyvsp[(1) - (2)].lVal), (yyvsp[(2) - (2)].exp));
                        }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 296 "Grammar.y"
    {
                            (yyval.expList) = new ExpList;
                        }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 300 "Grammar.y"
    {
                            (yyval.expList) = new ExpList;
                            (yyval.expList) -> push_back((yyvsp[(1) - (1)].exp));
                        }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 305 "Grammar.y"
    {
                            (yyval.expList) = (yyvsp[(1) - (3)].expList);
                            (yyval.expList) -> push_back((yyvsp[(3) - (3)].exp));
                        }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 312 "Grammar.y"
    {
                            (yyval.argList) = new ArgList;
                        }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 316 "Grammar.y"
    {
                            (yyval.argList) = new ArgList;
                            (yyval.argList) -> push_back((yyvsp[(1) - (1)].exp));
                        }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 321 "Grammar.y"
    {
                            (yyval.argList) = (yyvsp[(1) - (3)].argList);
                            (yyval.argList) -> push_back((yyvsp[(3) - (3)].exp));
                        }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 328 "Grammar.y"
    {
                            (yyval.fieldList) = new FieldList;
                        }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 332 "Grammar.y"
    {
                            (yyval.fieldList) = new FieldList;
                            (yyval.fieldList) -> push_back(FieldEle(*(yyvsp[(1) - (3)].strPtr), *(yyvsp[(3) - (3)].strPtr)));
                            delete (yyvsp[(1) - (3)].strPtr); (yyvsp[(1) - (3)].strPtr) = NULL;
                            delete (yyvsp[(3) - (3)].strPtr); (yyvsp[(3) - (3)].strPtr) = NULL;
                        }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 339 "Grammar.y"
    {
                            (yyval.fieldList) = (yyvsp[(1) - (5)].fieldList);
                            (yyval.fieldList) -> push_back(FieldEle(*(yyvsp[(3) - (5)].strPtr), *(yyvsp[(5) - (5)].strPtr)));
                            delete (yyvsp[(3) - (5)].strPtr); (yyvsp[(3) - (5)].strPtr) = NULL;
                            delete (yyvsp[(5) - (5)].strPtr); (yyvsp[(5) - (5)].strPtr) = NULL;
                        }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 348 "Grammar.y"
    {
                            (yyval.fieldExpList) = new FieldExpList;
                        }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 352 "Grammar.y"
    {
                            (yyval.fieldExpList) = new FieldExpList;
                            (yyval.fieldExpList) -> push_back(FieldExpEle(*(yyvsp[(1) - (3)].strPtr), (yyvsp[(3) - (3)].exp)));
                            delete (yyvsp[(1) - (3)].strPtr); (yyvsp[(1) - (3)].strPtr) = NULL;
                        }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 358 "Grammar.y"
    {
                            (yyval.fieldExpList) = (yyvsp[(1) - (5)].fieldExpList);
                            (yyval.fieldExpList) -> push_back(FieldExpEle(*(yyvsp[(3) - (5)].strPtr), (yyvsp[(5) - (5)].exp)));
                            delete (yyvsp[(3) - (5)].strPtr); (yyvsp[(3) - (5)].strPtr) = NULL;
                        }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 366 "Grammar.y"
    {
                            (yyval.binOpType) = BO_Mul;
                        }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 370 "Grammar.y"
    {
                            (yyval.binOpType) = BO_Div;
                        }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 375 "Grammar.y"
    {
                            (yyval.binOpType) = BO_Plus;
                        }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 379 "Grammar.y"
    {
                            (yyval.binOpType) = BO_Minus;
                        }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 384 "Grammar.y"
    {
                            (yyval.binOpType) = BO_Neq;
                        }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 388 "Grammar.y"
    {
                            (yyval.binOpType) = BO_LT;
                        }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 392 "Grammar.y"
    {
                            (yyval.binOpType) = BO_LTE;
                        }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 396 "Grammar.y"
    {
                            (yyval.binOpType) = BO_GT;
                        }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 400 "Grammar.y"
    {
                            (yyval.binOpType) = BO_GTE;
                        }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 404 "Grammar.y"
    {
                            (yyval.binOpType) = BO_Equal;
                        }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 409 "Grammar.y"
    {
                            (yyval.binOpType) = BO_And;
                        }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 414 "Grammar.y"
    {
                            (yyval.binOpType) = BO_Or;
                        }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 419 "Grammar.y"
    {
                            (yyval.unOpType) = UO_Neg;
                        }
    break;


/* Line 1792 of yacc.c  */
#line 2115 "Parser.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 424 "Grammar.y"


static const char *const yyprintname[] =
{
  "end of file", "error", "undefined", "\"array\"", "\"break\"", "\"do\"",
  "\"else\"", "\"end\"", "\"for\"", "\"function\"", "\"if\"", "\"in\"",
  "\"let\"", "\"nil\"", "\"of\"", "\"then\"", "\"to\"", "\"type\"",
  "\"var\"", "\"while\"", "\"+\"", "\"-\"",
  "\"*\"", "\"/\"", "\"&\"", "\"|\"", "\"=\"",
  "\"<>\"", "\"<\"", "\"<=\"", "\">\"", "\">=\"", "\":=\"",
  "\";\"", "\",\"", "\":\"", "\".\"", "\"(\"", "\")\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "integer",
  "identifier", "string", "EXP_REDUCE_PREC", "IF_WO_ELSE_PREC",
  "UNIOP_PREC", "$accept", "Program", "Expression", "Square Brace Expression", "Declaration List", "Declaration",
  "Type Declaration", "Type", "Variable Declaration", "Function Declartion", "Identifier Square Brace Expression", "Left Hand Value", "Expression List",
  "Argument List", "Field List", "Field Expression List", "Binary Operation Level 1", "Binary Operation Level 2",
  "Binary Operation Level 3", "Binary Operation Level 4", "Binary Operation Level 5", "Uni-Operation", YY_NULL
};

static string strErrReplace(const char* str)
{
    string strBig = str;
    for (const char* const* src = yytname, * const* dst = yyprintname; *src != YY_NULL; ++ src, ++ dst) {
        string::size_type pos=0;
        string strsrc = *src;
        string strdst = *dst;
        string::size_type srclen=strsrc.size();
        string::size_type dstlen=strdst.size();
        while( (pos=strBig.find(strsrc, pos)) != string::npos)
        {
            if (((pos + srclen) < strBig.size()) && (isalpha(strBig[pos + srclen]) || (strBig[pos + srclen] == '_'))) {
                ++ pos;
                continue;
            }
            strBig.replace(pos, srclen, strdst);
            pos += dstlen;
        }
    }
    return strBig;
}

