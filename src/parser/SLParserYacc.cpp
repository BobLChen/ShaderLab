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

/* Substitute the type names.  */
#define YYSTYPE         YY1STYPE
/* Substitute the variable and function names.  */
#define yyparse         yy1parse
#define yylex           yy1lex
#define yyerror         yy1error
#define yylval          yy1lval
#define yychar          yy1char
#define yydebug         yy1debug
#define yynerrs         yy1nerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "SLParserYacc.y"


// bison -d -b y -o SLParserYacc.cpp SLParserYacc.ypp
#include <stdio.h>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include "SLParserData.h"

using namespace shaderlab;

static std::vector<SLProgram*> _yaccCurrentPrograms;
SLShader* _currentShader;
std::stack<SLShaderState*> _shaderStateStack;
std::vector<std::string> _currentErrors;

extern int yy1lineno;
extern char* yy1text;

int yy1error(const char *s);
int yy1lex();

static void PushShaderState();
static void PopShaderState();

#define YYDEBUG 0


/* Line 371 of yacc.c  */
#line 107 "SLParserYacc.cpp"

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "SLParserYacc.hpp".  */
#ifndef YY_YY1_SLPARSERYACC_HPP_INCLUDED
# define YY_YY1_SLPARSERYACC_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YY1DEBUG
# if defined YYDEBUG
#  if YYDEBUG
#   define YY1DEBUG 1
#  else
#   define YY1DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define YY1DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined YY1DEBUG */
#if YY1DEBUG
extern int yy1debug;
#endif

/* Tokens.  */
#ifndef YY1TOKENTYPE
# define YY1TOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yy1tokentype {
     TOKEN_SHADER = 258,
     TOKEN_PASS = 259,
     TOKEN_USEPASS = 260,
     TOKEN_GRABPASS = 261,
     TOKEN_SUBSHADER = 262,
     TOKEN_FOG = 263,
     TOKEN_DENSITY = 264,
     TOKEN_MODE = 265,
     TOKEN_CATEGORY = 266,
     TOKEN_FALLBACK = 267,
     TOKEN_LOD = 268,
     TOKEN_COLOR = 269,
     TOKEN_ALPHA_TO_MASK = 270,
     TOKEN_TRUE = 271,
     TOKEN_FALSE = 272,
     TOKEN_GPU_PROGRAM_ID = 273,
     TOKEN_SETTEXTURE = 274,
     TOKEN_CONSTBUFFER = 275,
     TOKEN_BINDCB = 276,
     TOKEN_SETBUFFER = 277,
     TOKEN_MATRIX = 278,
     TOKEN_FLOAT = 279,
     TOKEN_RANGE = 280,
     TOKEN_VECTOR = 281,
     TOKEN_PROPERTIES = 282,
     TOKEN_PROGRAM = 283,
     TOKEN_SUBPROGRAM = 284,
     TOKEN_BIND = 285,
     TOKEN_TAGS = 286,
     TOKEN_NAME = 287,
     TOKEN_KEYWORDS = 288,
     TOKEN_ZWRITE = 289,
     TOKEN_ZTEST = 290,
     TOKEN_CULL = 291,
     TOKEN_BLEND = 292,
     TOKEN_BLEND_OP = 293,
     TOKEN_COLORMASK = 294,
     TOKEN_OFFSET = 295,
     TOKEN_STENCIL = 296,
     TOKEN_REF = 297,
     TOKEN_READ_MASK = 298,
     TOKEN_WRITE_MASK = 299,
     TOKEN_COMP = 300,
     TOKEN_OP_PASS = 301,
     TOKEN_OP_FAIL = 302,
     TOKEN_OP_ZFAIL = 303,
     TOKEN_COMP_BACK = 304,
     TOKEN_OP_PASS_BACK = 305,
     TOKEN_OP_FAIL_BACK = 306,
     TOKEN_OP_ZFAIL_BACK = 307,
     TOKEN_COMP_FRONT = 308,
     TOKEN_OP_PASS_FRONT = 309,
     TOKEN_OP_FAIL_FRONT = 310,
     TOKEN_OP_ZFAIL_FRONT = 311,
     VAL_NUMBER = 312,
     VAL_ID = 313,
     VAL_STRING = 314,
     VAL_BRACKET_ID = 315,
     VAL_TRIANGLE_FACE = 316,
     VAL_COMPARE_MODE = 317,
     VAL_RGBA_MASK = 318,
     VAL_FOG_MODE = 319,
     VAL_TEX_DIM = 320,
     VAL_BLEND_FACTOR = 321,
     VAL_BLEND_OP_MODE = 322,
     VAL_STENCIL_ACTION = 323
   };
#endif


#if ! defined YY1STYPE && ! defined YY1STYPE_IS_DECLARED
typedef union YY1STYPE
{
/* Line 387 of yacc.c  */
#line 34 "SLParserYacc.y"

	SLVector4 *vector4;
	SLFloat *floatval;
	SLShader *shader;
	SLProperties *properties;
	SLShaderState *states;
	SLPassBase *pass;
	SLGrabPass *grabpass;
	SLSubShader *subshader;
	SLProgram *program;
	SLSubProgram *subprogram;
	char *strval;
	float number;
	int enumval;
	std::vector<std::string> *strings;
	std::map<std::string, std::string> *tags;
	std::vector<SLPassBase*> *passes;


/* Line 387 of yacc.c  */
#line 246 "SLParserYacc.cpp"
} YY1STYPE;
# define YY1STYPE_IS_TRIVIAL 1
# define yy1stype YY1STYPE /* obsolescent; will be withdrawn */
# define YY1STYPE_IS_DECLARED 1
#endif

extern YY1STYPE yy1lval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yy1parse (void *YYPARSE_PARAM);
#else
int yy1parse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yy1parse (void);
#else
int yy1parse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY1_SLPARSERYACC_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 274 "SLParserYacc.cpp"

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
	 || (defined YY1STYPE_IS_TRIVIAL && YY1STYPE_IS_TRIVIAL)))

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNRULES -- Number of states.  */
#define YYNSTATES  274

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      71,    73,     2,     2,    72,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    74,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,     2,    70,     2,     2,     2,     2,
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
      65,    66,    67,    68
};

#if YY1DEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    15,    20,    21,    32,
      48,    59,    70,    81,    94,    95,    98,   108,   116,   117,
     120,   123,   126,   127,   134,   135,   141,   144,   149,   152,
     155,   159,   160,   166,   171,   174,   175,   181,   185,   188,
     189,   193,   197,   203,   209,   213,   217,   221,   225,   229,
     233,   237,   241,   245,   253,   258,   262,   268,   272,   278,
     284,   291,   293,   295,   297,   299,   301,   302,   307,   312,
     313,   317,   321,   325,   331,   341,   349,   351,   352,   356,
     360,   364,   368,   372,   376,   380,   384,   388,   392,   396,
     400,   404,   408,   412,   414,   416,   417,   424,   430,   431,
     434,   439,   445,   450,   456,   461,   467,   474,   479,   485,
     492,   500,   507,   513,   518,   524,   529,   534,   539,   540,
     543,   545,   547,   549,   551,   553,   555,   557,   559,   561,
     563
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      76,     0,    -1,    -1,    -1,     3,    59,    77,    69,    79,
      78,    83,    70,    -1,    -1,    27,    69,    80,    70,    -1,
      -1,    80,    81,    58,    71,    59,    72,    24,    73,    74,
      57,    -1,    80,    81,    58,    71,    59,    72,    25,    71,
      57,    72,    57,    73,    73,    74,    57,    -1,    80,    81,
      58,    71,    59,    72,    26,    73,    74,    82,    -1,    80,
      81,    58,    71,    59,    72,    14,    73,    74,    82,    -1,
      80,    81,    58,    71,    59,    72,    65,    73,    74,    59,
      -1,    80,    81,    58,    71,    59,    72,    65,    73,    74,
      59,    69,    70,    -1,    -1,    81,    60,    -1,    71,    57,
      72,    57,    72,    57,    72,    57,    73,    -1,    71,    57,
      72,    57,    72,    57,    73,    -1,    -1,    83,    84,    -1,
      83,    86,    -1,    83,    88,    -1,    -1,    11,    69,    85,
      93,    83,    70,    -1,    -1,     7,    69,    87,    89,    70,
      -1,    12,    59,    -1,    12,    59,    72,    57,    -1,    12,
      17,    -1,    93,    90,    -1,    89,    93,    90,    -1,    -1,
       4,    69,    91,    93,    70,    -1,     6,    69,    92,    70,
      -1,     5,    59,    -1,    -1,    92,    31,    69,    96,    70,
      -1,    92,    32,    59,    -1,    92,    59,    -1,    -1,    93,
      13,    57,    -1,    93,    32,    59,    -1,    93,    31,    69,
      96,    70,    -1,    93,     8,    69,    97,    70,    -1,    93,
      15,    95,    -1,    93,    35,   108,    -1,    93,    35,    16,
      -1,    93,    35,    17,    -1,    93,    34,    95,    -1,    93,
      39,   107,    -1,    93,    18,    57,    -1,    93,    36,    94,
      -1,    93,    36,    17,    -1,    93,    37,   105,   105,    72,
     105,   105,    -1,    93,    37,   105,   105,    -1,    93,    37,
      17,    -1,    93,    38,   106,    72,   106,    -1,    93,    38,
     106,    -1,    93,    41,    69,    99,    70,    -1,    93,    40,
     104,    72,   104,    -1,    93,    28,    59,    69,   101,    70,
      -1,    60,    -1,    61,    -1,    60,    -1,    16,    -1,    17,
      -1,    -1,    96,    58,    74,    58,    -1,    96,    59,    74,
      59,    -1,    -1,    97,    14,    98,    -1,    97,    10,    64,
      -1,    97,     9,   104,    -1,    97,    25,   104,    72,   104,
      -1,    71,   104,    72,   104,    72,   104,    72,   104,    73,
      -1,    71,   104,    72,   104,    72,   104,    73,    -1,    60,
      -1,    -1,    99,    42,   104,    -1,    99,    43,   104,    -1,
      99,    44,   104,    -1,    99,    45,   108,    -1,    99,    46,
     100,    -1,    99,    47,   100,    -1,    99,    48,   100,    -1,
      99,    53,   108,    -1,    99,    54,   100,    -1,    99,    55,
     100,    -1,    99,    56,   100,    -1,    99,    49,   108,    -1,
      99,    50,   100,    -1,    99,    51,   100,    -1,    99,    52,
     100,    -1,    60,    -1,    68,    -1,    -1,   101,    29,    59,
      69,   102,    70,    -1,   101,    29,    69,   102,    70,    -1,
      -1,   102,    59,    -1,   102,    30,    59,    58,    -1,   102,
      30,    59,    58,    57,    -1,   102,    24,    57,    60,    -1,
     102,    24,    57,    60,    57,    -1,   102,    26,    57,    60,
      -1,   102,    26,    57,    60,    57,    -1,   102,    26,    57,
      60,    57,    57,    -1,   102,    23,    57,    60,    -1,   102,
      23,    57,    60,    57,    -1,   102,    23,    57,    60,    57,
      57,    -1,   102,    23,    57,    60,    57,    57,    57,    -1,
     102,    19,    57,    60,    65,    57,    -1,   102,    19,    57,
      60,    65,    -1,   102,    19,    60,    65,    -1,   102,    33,
      69,   103,    70,    -1,   102,    20,    59,    57,    -1,   102,
      21,    59,    57,    -1,   102,    22,    57,    60,    -1,    -1,
     103,    59,    -1,    57,    -1,    60,    -1,    60,    -1,    66,
      -1,    60,    -1,    67,    -1,    60,    -1,    63,    -1,    17,
      -1,    60,    -1,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    90,    84,   103,   106,   113,   116,   124,
     131,   140,   149,   162,   178,   181,   189,   194,   202,   205,
     209,   215,   221,   220,   231,   230,   245,   250,   255,   261,
     266,   274,   273,   288,   292,   300,   303,   309,   315,   324,
     327,   332,   338,   344,   354,   360,   366,   371,   376,   382,
     388,   393,   399,   404,   416,   426,   434,   442,   449,   460,
     468,   477,   483,   490,   496,   501,   509,   512,   521,   533,
     537,   543,   548,   554,   564,   573,   581,   591,   595,   601,
     607,   613,   619,   625,   631,   637,   643,   649,   655,   661,
     667,   673,   679,   687,   693,   701,   704,   711,   720,   723,
     729,   736,   743,   749,   755,   761,   767,   773,   779,   785,
     791,   797,   803,   809,   815,   821,   827,   833,   842,   845,
     853,   858,   866,   872,   879,   885,   892,   898,   903,   910,
     916
};
#endif

#if YY1DEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_SHADER", "TOKEN_PASS",
  "TOKEN_USEPASS", "TOKEN_GRABPASS", "TOKEN_SUBSHADER", "TOKEN_FOG",
  "TOKEN_DENSITY", "TOKEN_MODE", "TOKEN_CATEGORY", "TOKEN_FALLBACK",
  "TOKEN_LOD", "TOKEN_COLOR", "TOKEN_ALPHA_TO_MASK", "TOKEN_TRUE",
  "TOKEN_FALSE", "TOKEN_GPU_PROGRAM_ID", "TOKEN_SETTEXTURE",
  "TOKEN_CONSTBUFFER", "TOKEN_BINDCB", "TOKEN_SETBUFFER", "TOKEN_MATRIX",
  "TOKEN_FLOAT", "TOKEN_RANGE", "TOKEN_VECTOR", "TOKEN_PROPERTIES",
  "TOKEN_PROGRAM", "TOKEN_SUBPROGRAM", "TOKEN_BIND", "TOKEN_TAGS",
  "TOKEN_NAME", "TOKEN_KEYWORDS", "TOKEN_ZWRITE", "TOKEN_ZTEST",
  "TOKEN_CULL", "TOKEN_BLEND", "TOKEN_BLEND_OP", "TOKEN_COLORMASK",
  "TOKEN_OFFSET", "TOKEN_STENCIL", "TOKEN_REF", "TOKEN_READ_MASK",
  "TOKEN_WRITE_MASK", "TOKEN_COMP", "TOKEN_OP_PASS", "TOKEN_OP_FAIL",
  "TOKEN_OP_ZFAIL", "TOKEN_COMP_BACK", "TOKEN_OP_PASS_BACK",
  "TOKEN_OP_FAIL_BACK", "TOKEN_OP_ZFAIL_BACK", "TOKEN_COMP_FRONT",
  "TOKEN_OP_PASS_FRONT", "TOKEN_OP_FAIL_FRONT", "TOKEN_OP_ZFAIL_FRONT",
  "VAL_NUMBER", "VAL_ID", "VAL_STRING", "VAL_BRACKET_ID",
  "VAL_TRIANGLE_FACE", "VAL_COMPARE_MODE", "VAL_RGBA_MASK", "VAL_FOG_MODE",
  "VAL_TEX_DIM", "VAL_BLEND_FACTOR", "VAL_BLEND_OP_MODE",
  "VAL_STENCIL_ACTION", "'{'", "'}'", "'('", "','", "')'", "'='",
  "$accept", "shader", "$@1", "$@2", "properties", "propitems",
  "propflags", "vector4", "shaderBlocks", "category", "$@3", "subshader",
  "$@4", "fallback", "passes", "pass", "$@5", "grabpass", "states",
  "cullval", "boolean", "tags", "fogblock", "color", "stencilblock",
  "stencilaction", "subprograms", "subprogram", "stringlist", "numval",
  "blendval", "blendopval", "maskval", "funcval", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   123,
     125,    40,    44,    41,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    77,    78,    76,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    83,    85,    84,    87,    86,    88,    88,    88,    89,
      89,    91,    90,    90,    90,    92,    92,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    94,    94,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    97,    97,    98,    98,    98,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   100,   101,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   103,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   107,   108,
     108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     0,     4,     0,    10,    15,
      10,    10,    10,    12,     0,     2,     9,     7,     0,     2,
       2,     2,     0,     6,     0,     5,     2,     4,     2,     2,
       3,     0,     5,     4,     2,     0,     5,     3,     2,     0,
       3,     3,     5,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     7,     4,     3,     5,     3,     5,     5,
       6,     1,     1,     1,     1,     1,     0,     4,     4,     0,
       3,     3,     3,     5,     9,     7,     1,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     0,     6,     5,     0,     2,
       4,     5,     4,     5,     4,     5,     6,     4,     5,     6,
       7,     6,     5,     4,     5,     4,     4,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     5,     0,     3,     7,
      18,    14,     0,     6,     0,     0,     0,     0,     4,    19,
      20,    21,     0,    15,    24,    22,    28,    26,     0,    39,
      39,     0,     0,    39,     0,    18,    27,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,    30,    31,    34,    35,    69,
      40,    64,    65,    63,    44,    50,     0,    66,    41,    48,
      46,    47,   129,   130,    45,    52,    61,    62,    51,    55,
     122,   123,     0,   124,   125,    57,   128,   126,   127,    49,
     120,   121,     0,    77,    23,     0,     0,     0,     0,     0,
      39,     0,     0,    95,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    33,     0,
       0,     0,     0,    43,     0,     0,     0,    42,     0,    56,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,    11,     8,
       0,    10,    12,    32,    66,    37,    72,    71,    76,     0,
      70,     0,     0,    60,     0,     0,     0,    78,    79,    80,
      81,    93,    94,    82,    83,    84,    89,    90,    91,    92,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,    98,    67,    68,    53,     0,     0,    13,    36,     0,
      73,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,    97,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,     0,     9,     0,     0,   113,   115,   116,   117,
     107,   102,   104,   100,     0,     0,    17,     0,    75,   112,
     108,   103,   105,   101,   119,   114,     0,     0,   111,   109,
     106,    16,    74,   110
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    10,     8,    11,    14,   158,    12,    19,
      30,    20,    29,    21,    33,    58,   110,   111,    34,    88,
      74,   114,   112,   170,   118,   183,   134,   212,   254,   102,
      92,    95,    99,    84
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -118
static const yytype_int16 yypact[] =
{
      -1,    10,    86,  -118,  -118,    45,    93,    63,  -118,  -118,
    -118,    67,    -3,  -118,   -44,    79,    82,    -6,  -118,  -118,
    -118,  -118,    73,  -118,  -118,  -118,  -118,    89,    80,  -118,
    -118,    90,    91,    92,   118,   152,  -118,    54,  -118,   118,
      95,   107,   105,   109,   122,     5,   124,   123,   116,   135,
       5,    29,   -12,   -10,   -25,    27,    68,   141,  -118,     6,
     138,   139,   142,   143,   144,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,   145,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,    40,  -118,  -118,   146,  -118,  -118,  -118,  -118,
    -118,  -118,   147,  -118,  -118,   148,   150,   158,   151,   154,
    -118,    71,    18,  -118,    57,   149,   -25,    68,   153,   155,
     163,   157,   155,   168,    23,   161,   172,  -118,  -118,    68,
     169,   -41,    68,  -118,    37,   160,   162,  -118,    40,  -118,
    -118,    68,    68,    68,    49,    44,    44,    44,    49,    44,
      44,    44,    49,    44,    44,    44,  -118,   175,  -118,  -118,
     178,  -118,   170,  -118,  -118,  -118,  -118,  -118,  -118,    68,
    -118,   165,   -49,  -118,   180,   181,    40,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,   171,   173,   174,    59,   176,    68,
     182,  -118,  -118,  -118,  -118,   184,   177,  -118,  -118,    68,
    -118,  -118,    51,   183,   179,   185,    75,    78,   186,   188,
     192,   195,   197,   199,   200,   189,  -118,  -118,   203,   204,
      68,  -118,   202,   198,   207,   208,   206,   209,   210,   211,
     214,  -118,   -33,  -118,    70,   212,  -118,  -118,  -118,  -118,
     216,   217,   218,   219,   -36,   221,  -118,    68,  -118,   222,
     223,  -118,   224,  -118,  -118,  -118,   194,   213,  -118,   225,
    -118,  -118,  -118,  -118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,  -118,  -118,  -118,  -118,   120,   233,  -118,
    -118,  -118,  -118,  -118,  -118,   244,  -118,  -118,   -27,  -118,
     234,   121,  -118,  -118,  -118,    22,  -118,    76,  -118,  -117,
     -91,   187,  -118,  -115
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     140,   115,     1,    35,    15,    85,    39,    89,    16,    17,
     200,    26,   166,    15,    22,   171,    23,    16,    17,   168,
     201,    71,    72,   264,   177,   178,   179,   129,   130,   180,
     169,    43,   131,   186,   265,    93,    44,   190,    45,   255,
     256,    46,    94,   132,    96,    80,    81,   176,    86,    87,
      90,    47,   198,    27,    48,    49,    91,    50,    51,    52,
      53,    54,    55,    56,    57,    73,   172,    18,    60,     3,
     217,   218,   219,   220,   221,   222,   104,   223,    61,    62,
      63,   224,   210,   124,   225,   204,     4,    97,   133,    82,
      98,    83,   215,   163,   217,   218,   219,   220,   221,   222,
      90,   223,   125,   126,   181,   224,    91,   173,   225,    82,
     226,    83,   182,   244,     6,   135,   136,   135,   136,    64,
       7,   227,    40,    41,    42,   100,    43,   137,   101,   208,
     127,    44,     9,    45,   226,   232,    46,    13,   233,    32,
     267,   128,   257,   258,    28,   231,    47,    36,    24,    48,
      49,    25,    50,    51,    52,    53,    54,    55,    56,    57,
      43,    31,    38,    37,    66,    44,    67,    45,   184,   185,
      46,   187,   188,   189,    68,   191,   192,   193,    69,    70,
      47,    75,    76,    48,    49,    77,    50,    51,    52,    53,
      54,    55,    56,    57,    78,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     103,   105,   106,   107,   113,   121,   108,   109,   116,   117,
     159,   138,   119,   156,   120,   122,   157,   162,   123,   160,
     164,   165,   194,   167,   174,   195,   175,   199,   202,   196,
     203,   213,   161,   205,   207,   234,   206,   235,   209,   236,
     214,   211,   237,   229,   238,   228,   239,   230,   241,   240,
     242,   243,   245,   246,   247,   248,   249,   271,    59,   250,
     251,   252,   253,   260,   261,   262,   263,   259,   266,   268,
     269,   270,   273,    65,    79,   197,   272,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   139
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-118)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     117,    92,     3,    30,     7,    17,    33,    17,    11,    12,
      59,    17,   129,     7,    58,   132,    60,    11,    12,    60,
      69,    16,    17,    59,   141,   142,   143,     9,    10,   144,
      71,     8,    14,   148,    70,    60,    13,   152,    15,    72,
      73,    18,    67,    25,    17,    16,    17,   138,    60,    61,
      60,    28,   169,    59,    31,    32,    66,    34,    35,    36,
      37,    38,    39,    40,    41,    60,    29,    70,    14,    59,
      19,    20,    21,    22,    23,    24,    70,    26,    24,    25,
      26,    30,   199,   110,    33,   176,     0,    60,    70,    60,
      63,    62,   209,    70,    19,    20,    21,    22,    23,    24,
      60,    26,    31,    32,    60,    30,    66,    70,    33,    60,
      59,    62,    68,   230,    69,    58,    59,    58,    59,    65,
      27,    70,     4,     5,     6,    57,     8,    70,    60,    70,
      59,    13,    69,    15,    59,    57,    18,    70,    60,    59,
     257,    70,    72,    73,    71,    70,    28,    57,    69,    31,
      32,    69,    34,    35,    36,    37,    38,    39,    40,    41,
       8,    72,    70,    72,    69,    13,    59,    15,   146,   147,
      18,   149,   150,   151,    69,   153,   154,   155,    69,    57,
      28,    57,    59,    31,    32,    69,    34,    35,    36,    37,
      38,    39,    40,    41,    59,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      69,    73,    73,    71,    69,    57,    73,    73,    72,    72,
      57,    72,    74,    70,    74,    74,    71,    59,    74,    72,
      69,    59,    57,    64,    74,    57,    74,    72,    58,    69,
      59,    57,   122,    72,    70,    59,    73,    59,    72,    57,
      73,    69,    57,    74,    57,    72,    57,    72,    69,    59,
      57,    57,    60,    65,    57,    57,    60,    73,    35,    60,
      60,    60,    58,    57,    57,    57,    57,    65,    57,    57,
      57,    57,    57,    39,    50,   164,    73,   211,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    76,    59,     0,    77,    69,    27,    79,    69,
      78,    80,    83,    70,    81,     7,    11,    12,    70,    84,
      86,    88,    58,    60,    69,    69,    17,    59,    71,    87,
      85,    72,    59,    89,    93,    93,    57,    72,    70,    93,
       4,     5,     6,     8,    13,    15,    18,    28,    31,    32,
      34,    35,    36,    37,    38,    39,    40,    41,    90,    83,
      14,    24,    25,    26,    65,    90,    69,    59,    69,    69,
      57,    16,    17,    60,    95,    57,    59,    69,    59,    95,
      16,    17,    60,    62,   108,    17,    60,    61,    94,    17,
      60,    66,   105,    60,    67,   106,    17,    60,    63,   107,
      57,    60,   104,    69,    70,    73,    73,    71,    73,    73,
      91,    92,    97,    69,    96,   105,    72,    72,    99,    74,
      74,    57,    74,    74,    93,    31,    32,    59,    70,     9,
      10,    14,    25,    70,   101,    58,    59,    70,    72,   106,
     104,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    70,    71,    82,    57,
      72,    82,    59,    70,    69,    59,   104,    64,    60,    71,
      98,   104,    29,    70,    74,    74,   105,   104,   104,   104,
     108,    60,    68,   100,   100,   100,   108,   100,   100,   100,
     108,   100,   100,   100,    57,    57,    69,    96,   104,    72,
      59,    69,    58,    59,   105,    72,    73,    70,    70,    72,
     104,    69,   102,    57,    73,   104,   102,    19,    20,    21,
      22,    23,    24,    26,    30,    33,    59,    70,    72,    74,
      72,    70,    57,    60,    59,    59,    57,    57,    57,    57,
      59,    69,    57,    57,   104,    60,    65,    57,    57,    60,
      60,    60,    60,    58,   103,    72,    73,    72,    73,    65,
      57,    57,    57,    57,    59,    70,    57,   104,    57,    57,
      57,    73,    73,    57
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
#if YY1DEBUG

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
#else /* !YY1DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YY1DEBUG */


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
#line 85 "SLParserYacc.y"
    {
				_currentShader->shaderName = (yyvsp[(2) - (2)].strval);
				delete[] (yyvsp[(2) - (2)].strval);
			}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 90 "SLParserYacc.y"
    {
				if ((yyvsp[(5) - (5)].properties)) {
					_currentShader->properties = *(yyvsp[(5) - (5)].properties);
					delete (yyvsp[(5) - (5)].properties);
				}
			}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 97 "SLParserYacc.y"
    {
				
			}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 103 "SLParserYacc.y"
    {
				(yyval.properties) = nullptr;
			}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 107 "SLParserYacc.y"
    { 
				(yyval.properties) = (yyvsp[(3) - (4)].properties); 
			}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 113 "SLParserYacc.y"
    {
				(yyval.properties) = new SLProperties(); 
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 117 "SLParserYacc.y"
    { 
				(yyval.properties) = (yyvsp[(1) - (10)].properties); 
				(yyval.properties)->AddFloatProperty((yyvsp[(3) - (10)].strval), (yyvsp[(5) - (10)].strval), *(yyvsp[(2) - (10)].strings), (yyvsp[(10) - (10)].number));
				delete[] (yyvsp[(3) - (10)].strval);
				delete[] (yyvsp[(5) - (10)].strval);
				delete (yyvsp[(2) - (10)].strings); 
			}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 125 "SLParserYacc.y"
    { 
				(yyval.properties) = (yyvsp[(1) - (15)].properties); 
				(yyval.properties)->AddRangeProperty((yyvsp[(3) - (15)].strval), (yyvsp[(5) - (15)].strval), *(yyvsp[(2) - (15)].strings), (yyvsp[(15) - (15)].number), (yyvsp[(9) - (15)].number), (yyvsp[(11) - (15)].number)); 
				delete[] (yyvsp[(3) - (15)].strval);
				delete[] (yyvsp[(5) - (15)].strval);
			}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 132 "SLParserYacc.y"
    { 
				(yyval.properties) = (yyvsp[(1) - (10)].properties); 
				(yyval.properties)->AddVectorProperty((yyvsp[(3) - (10)].strval), (yyvsp[(5) - (10)].strval), *(yyvsp[(2) - (10)].strings), *(yyvsp[(10) - (10)].vector4));
				delete[] (yyvsp[(3) - (10)].strval);
				delete[] (yyvsp[(5) - (10)].strval);
				delete (yyvsp[(2) - (10)].strings);
				delete (yyvsp[(10) - (10)].vector4); 
			}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 141 "SLParserYacc.y"
    { 
				(yyval.properties) = (yyvsp[(1) - (10)].properties);
				(yyval.properties)->AddColorProperty((yyvsp[(3) - (10)].strval), (yyvsp[(5) - (10)].strval), *(yyvsp[(2) - (10)].strings), *(yyvsp[(10) - (10)].vector4));
				delete[] (yyvsp[(3) - (10)].strval);
				delete[] (yyvsp[(5) - (10)].strval);
				delete (yyvsp[(2) - (10)].strings);
				delete (yyvsp[(10) - (10)].vector4);
			}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 150 "SLParserYacc.y"
    {
				(yyval.properties) = (yyvsp[(1) - (10)].properties); 
				SLPropTexture *tex = new SLPropTexture();
				tex->name = (yyvsp[(10) - (10)].strval);
				tex->dimension = (TextureDimension)(yyvsp[(7) - (10)].enumval);
				(yyval.properties)->AddTextureProperty((yyvsp[(3) - (10)].strval), (yyvsp[(5) - (10)].strval), *(yyvsp[(2) - (10)].strings), *tex);
				delete (yyvsp[(2) - (10)].strings);
				delete tex;
				delete[] (yyvsp[(3) - (10)].strval);
				delete[] (yyvsp[(5) - (10)].strval);
				delete[] (yyvsp[(10) - (10)].strval);
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 163 "SLParserYacc.y"
    {
				(yyval.properties) = (yyvsp[(1) - (12)].properties);
				SLPropTexture *tex = new SLPropTexture();
				tex->name = (yyvsp[(10) - (12)].strval);
				tex->dimension = (TextureDimension)(yyvsp[(7) - (12)].enumval);
				(yyval.properties)->AddTextureProperty((yyvsp[(3) - (12)].strval), (yyvsp[(5) - (12)].strval), *(yyvsp[(2) - (12)].strings), *tex);
				delete (yyvsp[(2) - (12)].strings);
				delete tex;
				delete[] (yyvsp[(3) - (12)].strval);
				delete[] (yyvsp[(5) - (12)].strval);
				delete[] (yyvsp[(10) - (12)].strval);
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 178 "SLParserYacc.y"
    { 
				(yyval.strings) = new std::vector<std::string>(); 
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 182 "SLParserYacc.y"
    {
				(yyval.strings) = (yyvsp[(1) - (2)].strings);
				(yyval.strings)->emplace_back((yyvsp[(2) - (2)].strval));
				delete[] (yyvsp[(2) - (2)].strval);
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 190 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue((yyvsp[(2) - (9)].number), (yyvsp[(4) - (9)].number), (yyvsp[(6) - (9)].number), (yyvsp[(8) - (9)].number));
			}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 195 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue((yyvsp[(2) - (7)].number), (yyvsp[(4) - (7)].number), (yyvsp[(6) - (7)].number), 1.0f);
			}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 202 "SLParserYacc.y"
    {
				
			}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 206 "SLParserYacc.y"
    {
				
			}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 210 "SLParserYacc.y"
    { 
				if ((yyvsp[(2) - (2)].subshader)) {
					_currentShader->subShaders.push_back((yyvsp[(2) - (2)].subshader)); 
				}
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 216 "SLParserYacc.y"
    {

			}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 221 "SLParserYacc.y"
    { 
				PushShaderState (); 
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 225 "SLParserYacc.y"
    { 
				PopShaderState (); 
			}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 231 "SLParserYacc.y"
    { 
				PushShaderState (); 
			}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 235 "SLParserYacc.y"
    {
				(yyval.subshader) = new SLSubShader();
				const SLShaderState* state = _shaderStateStack.top();
				(yyval.subshader)->tags = state->tags;
				(yyval.subshader)->lod  = state->lod;
				(yyval.subshader)->SetPasses((yyvsp[(4) - (5)].passes));
				delete (yyvsp[(4) - (5)].passes);
				PopShaderState ();
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 246 "SLParserYacc.y"
    { 
				_currentShader->fallbackName = (yyvsp[(2) - (2)].strval);
				delete[] (yyvsp[(2) - (2)].strval);
			}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 251 "SLParserYacc.y"
    {
				_currentShader->fallbackName = (yyvsp[(2) - (4)].strval);
				delete[] (yyvsp[(2) - (4)].strval);
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 256 "SLParserYacc.y"
    {
				_currentShader->fallbackName = "None";
			}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 262 "SLParserYacc.y"
    { 
				(yyval.passes) = new std::vector<SLPassBase*>; 
				(yyval.passes)->push_back((yyvsp[(2) - (2)].pass)); 
			}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 267 "SLParserYacc.y"
    { 
				(yyval.passes) = (yyvsp[(1) - (3)].passes);  
				(yyval.passes)->push_back((yyvsp[(3) - (3)].pass)); 
			}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 274 "SLParserYacc.y"
    { 
				PushShaderState(); 
				_yaccCurrentPrograms.clear();
			}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 279 "SLParserYacc.y"
    {	
				SLNormalPass *pp = new SLNormalPass(*_shaderStateStack.top());
				(yyval.pass) = pp;
				for (int i = 0; i < _yaccCurrentPrograms.size(); ++i) {
					pp->programs.push_back(_yaccCurrentPrograms[i]);
				}
				_yaccCurrentPrograms.clear();
				PopShaderState();
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 289 "SLParserYacc.y"
    { 
				(yyval.pass) = (yyvsp[(3) - (4)].grabpass); 
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 293 "SLParserYacc.y"
    { 
				(yyval.pass) = new SLUsePass((yyvsp[(2) - (2)].strval)); 
				delete[] (yyvsp[(2) - (2)].strval);
			}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 300 "SLParserYacc.y"
    { 
				(yyval.grabpass) = new SLGrabPass(); 
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 304 "SLParserYacc.y"
    { 
				(yyval.grabpass) = (yyvsp[(1) - (5)].grabpass); 
				(yyval.grabpass)->AddTags(*(yyvsp[(4) - (5)].tags)); 
				delete (yyvsp[(4) - (5)].tags); 
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 310 "SLParserYacc.y"
    { 
				(yyval.grabpass) = (yyvsp[(1) - (3)].grabpass); 
				(yyval.grabpass)->name = std::string((yyvsp[(3) - (3)].strval)); 
				delete[] (yyvsp[(3) - (3)].strval);
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 316 "SLParserYacc.y"
    { 
				(yyval.grabpass) = (yyvsp[(1) - (2)].grabpass); 
				(yyval.grabpass)->textureName = std::string((yyvsp[(2) - (2)].strval)); 
				delete[] (yyvsp[(2) - (2)].strval);
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 324 "SLParserYacc.y"
    {
				(yyval.states) = _shaderStateStack.top(); 
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 328 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->lod = int((yyvsp[(3) - (3)].number)); 
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 333 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->name = (yyvsp[(3) - (3)].strval); 
				delete[] (yyvsp[(3) - (3)].strval);
			}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 339 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (5)].states); 
				(yyval.states)->AddTags(*(yyvsp[(4) - (5)].tags));
				delete (yyvsp[(4) - (5)].tags);
			}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 345 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (5)].states);
				(yyval.states)->fogColor   = (yyvsp[(4) - (5)].states)->fogColor;
				(yyval.states)->fogMode    = (yyvsp[(4) - (5)].states)->fogMode;
				(yyval.states)->fogDensity = (yyvsp[(4) - (5)].states)->fogDensity;
				(yyval.states)->fogStart   = (yyvsp[(4) - (5)].states)->fogStart;
				(yyval.states)->fogEnd     = (yyvsp[(4) - (5)].states)->fogEnd;
				PopShaderState();
			}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 355 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->alphaToMask = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 361 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->zTest = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 367 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->zTest.SetValue(kFuncLEqual); 
			}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 372 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->zTest.SetValue(kFuncDisabled); 
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 377 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->zWrite = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 383 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->colMask = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 389 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->gpuProgramID = (yyvsp[(3) - (3)].number);
			}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 394 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->culling = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 400 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->culling.SetValue(kCullOff); 
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 405 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (7)].states);
				(yyval.states)->srcBlend = *(yyvsp[(3) - (7)].floatval);
				(yyval.states)->destBlend = *(yyvsp[(4) - (7)].floatval);
				(yyval.states)->srcBlendAlpha = *(yyvsp[(6) - (7)].floatval);
				(yyval.states)->destBlendAlpha = *(yyvsp[(7) - (7)].floatval);
				delete (yyvsp[(3) - (7)].floatval);
				delete (yyvsp[(4) - (7)].floatval);
				delete (yyvsp[(6) - (7)].floatval);
				delete (yyvsp[(7) - (7)].floatval);
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 417 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (4)].states); 
				(yyval.states)->srcBlend = *(yyvsp[(3) - (4)].floatval);
				(yyval.states)->destBlend = *(yyvsp[(4) - (4)].floatval);
				(yyval.states)->srcBlendAlpha = *(yyvsp[(3) - (4)].floatval);
				(yyval.states)->destBlendAlpha = *(yyvsp[(4) - (4)].floatval);
				delete (yyvsp[(3) - (4)].floatval);
				delete (yyvsp[(4) - (4)].floatval);
			}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 427 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->srcBlend.SetValue(kBlendOne); 
				(yyval.states)->srcBlendAlpha.SetValue(kBlendOne); 
				(yyval.states)->destBlend.SetValue(kBlendZero); 
				(yyval.states)->destBlendAlpha.SetValue(kBlendZero); 
			}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 435 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (5)].states); 
				(yyval.states)->blendOp = *(yyvsp[(3) - (5)].floatval);
				(yyval.states)->blendOpAlpha = *(yyvsp[(5) - (5)].floatval);
				delete (yyvsp[(3) - (5)].floatval);
				delete (yyvsp[(5) - (5)].floatval);
			}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 443 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->blendOp = *(yyvsp[(3) - (3)].floatval);
				(yyval.states)->blendOpAlpha = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 450 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (5)].states);
				(yyval.states)->stencilRef = (yyvsp[(4) - (5)].states)->stencilRef;
				(yyval.states)->stencilReadMask = (yyvsp[(4) - (5)].states)->stencilReadMask;
				(yyval.states)->stencilWriteMask = (yyvsp[(4) - (5)].states)->stencilWriteMask;
				(yyval.states)->stencilOp = (yyvsp[(4) - (5)].states)->stencilOp;
				(yyval.states)->stencilOpFront = (yyvsp[(4) - (5)].states)->stencilOpFront;
				(yyval.states)->stencilOpBack = (yyvsp[(4) - (5)].states)->stencilOpBack;
				PopShaderState();
			}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 461 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (5)].states);
				(yyval.states)->offsetFactor = *(yyvsp[(3) - (5)].floatval);
				(yyval.states)->offsetUnits = *(yyvsp[(5) - (5)].floatval);
				delete (yyvsp[(3) - (5)].floatval);
				delete (yyvsp[(5) - (5)].floatval);
			}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 469 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (6)].states);
				(yyvsp[(5) - (6)].program)->type = (yyvsp[(3) - (6)].strval);
				_yaccCurrentPrograms.push_back((yyvsp[(5) - (6)].program));
				delete[] (yyvsp[(3) - (6)].strval);
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 478 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 484 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval)); 
			}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 491 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 497 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(1); 
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 502 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(0); 
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 509 "SLParserYacc.y"
    {
				(yyval.tags) = new std::map<std::string, std::string>(); 
			}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 513 "SLParserYacc.y"
    { 
				(yyval.tags) = (yyvsp[(1) - (4)].tags);
				std::string key((yyvsp[(2) - (4)].strval));
				std::string value((yyvsp[(4) - (4)].strval));
				(*(yyval.tags))[key] = value;
				delete[] (yyvsp[(2) - (4)].strval);
				delete[] (yyvsp[(4) - (4)].strval);
			}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 522 "SLParserYacc.y"
    { 
				(yyval.tags) = (yyvsp[(1) - (4)].tags);
				std::string key((yyvsp[(2) - (4)].strval));
				std::string value((yyvsp[(4) - (4)].strval));
				(*(yyval.tags))[key] = value; 
				delete[] (yyvsp[(2) - (4)].strval);
				delete[] (yyvsp[(4) - (4)].strval);
			}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 533 "SLParserYacc.y"
    {
				PushShaderState(); 
				(yyval.states) = _shaderStateStack.top(); 
			}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 538 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyvsp[(1) - (3)].states)->fogColor = *(yyvsp[(3) - (3)].vector4); 
				delete (yyvsp[(3) - (3)].vector4); 
			}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 544 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyvsp[(1) - (3)].states)->fogMode = (FogMode)(yyvsp[(3) - (3)].enumval); 
			}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 549 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyvsp[(1) - (3)].states)->fogDensity = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 555 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (5)].states);
				(yyvsp[(1) - (5)].states)->fogStart = *(yyvsp[(3) - (5)].floatval);
				(yyvsp[(1) - (5)].states)->fogEnd = *(yyvsp[(5) - (5)].floatval);
				delete (yyvsp[(3) - (5)].floatval);
				delete (yyvsp[(5) - (5)].floatval);
			}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 565 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue(*(yyvsp[(2) - (9)].floatval), *(yyvsp[(4) - (9)].floatval), *(yyvsp[(6) - (9)].floatval), *(yyvsp[(8) - (9)].floatval));
				delete (yyvsp[(2) - (9)].floatval); 
				delete (yyvsp[(4) - (9)].floatval); 
				delete (yyvsp[(6) - (9)].floatval); 
				delete (yyvsp[(8) - (9)].floatval);
			}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 574 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue(*(yyvsp[(2) - (7)].floatval), *(yyvsp[(4) - (7)].floatval), *(yyvsp[(6) - (7)].floatval));
				delete (yyvsp[(2) - (7)].floatval); 
				delete (yyvsp[(4) - (7)].floatval); 
				delete (yyvsp[(6) - (7)].floatval);
			}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 582 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue(0, 0, 0, 0);
				(yyval.vector4)->SetRef((yyvsp[(1) - (1)].strval));
				delete[] (yyvsp[(1) - (1)].strval);
			}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 591 "SLParserYacc.y"
    {
				PushShaderState(); 
				(yyval.states) = _shaderStateStack.top(); 
			}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 596 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states) ->stencilRef = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 602 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->stencilReadMask = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 608 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilWriteMask = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 614 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.comp = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 620 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.pass = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 626 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.fail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 632 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.zFail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 638 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.comp = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 644 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.pass = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 650 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.fail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 656 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.zFail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 662 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.comp = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 668 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.pass = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 674 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.fail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 680 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.zFail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 688 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 694 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue ((yyvsp[(1) - (1)].enumval)); 
			}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 701 "SLParserYacc.y"
    { 
				(yyval.program) = new SLProgram(); 
			}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 705 "SLParserYacc.y"
    {
				(yyval.program) = (yyvsp[(1) - (6)].program);
				(yyvsp[(5) - (6)].subprogram)->name = (yyvsp[(3) - (6)].strval);
				(yyval.program)->subPrograms.push_back((yyvsp[(5) - (6)].subprogram));
				delete[] (yyvsp[(3) - (6)].strval);
			}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 712 "SLParserYacc.y"
    { 
				(yyval.program) = (yyvsp[(1) - (5)].program);
				(yyvsp[(4) - (5)].subprogram)->name = "";
				(yyvsp[(1) - (5)].program)->subPrograms.push_back((yyvsp[(4) - (5)].subprogram)); 
			}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 720 "SLParserYacc.y"
    { 
				(yyval.subprogram) = new SLSubProgram(); 
			}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 724 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (2)].subprogram); 
				(yyval.subprogram)->source = (yyvsp[(2) - (2)].strval); 
				delete[] (yyvsp[(2) - (2)].strval);
			}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 730 "SLParserYacc.y"
    {
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram);
				(yyval.subprogram)->Bind((yyvsp[(3) - (4)].strval), (yyvsp[(4) - (4)].strval));
				delete[] (yyvsp[(3) - (4)].strval);
				delete[] (yyvsp[(4) - (4)].strval);
			}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 737 "SLParserYacc.y"
    {
				(yyval.subprogram) = (yyvsp[(1) - (5)].subprogram);
				(yyval.subprogram)->Bind((yyvsp[(3) - (5)].strval), (yyvsp[(4) - (5)].strval), (int)(yyvsp[(5) - (5)].number));
				delete[] (yyvsp[(3) - (5)].strval);
				delete[] (yyvsp[(4) - (5)].strval);
			}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 744 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->AddParamVector(kShaderParamFloat, (int)(yyvsp[(3) - (4)].number), 1, (yyvsp[(4) - (4)].strval)); 
				delete[] (yyvsp[(4) - (4)].strval);
			}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 750 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (5)].subprogram); 
				(yyvsp[(1) - (5)].subprogram)->AddParamVector(kShaderParamFloat, (int)(yyvsp[(3) - (5)].number), 1, (yyvsp[(4) - (5)].strval), (yyvsp[(5) - (5)].number)); 
				delete[] (yyvsp[(4) - (5)].strval);
			}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 756 "SLParserYacc.y"
    {
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->AddParamVector(kShaderParamFloat, (int)(yyvsp[(3) - (4)].number), 4, (yyvsp[(4) - (4)].strval)); 
				delete[] (yyvsp[(4) - (4)].strval);
			}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 762 "SLParserYacc.y"
    {
				(yyval.subprogram)=(yyvsp[(1) - (5)].subprogram); 
				(yyvsp[(1) - (5)].subprogram)->AddParamVector(kShaderParamFloat, (int)(yyvsp[(3) - (5)].number), (int)(yyvsp[(5) - (5)].number), (yyvsp[(4) - (5)].strval)); 
				delete[] (yyvsp[(4) - (5)].strval);
			}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 768 "SLParserYacc.y"
    {
				(yyval.subprogram)=(yyvsp[(1) - (6)].subprogram); 
				(yyvsp[(1) - (6)].subprogram)->AddParamVector(kShaderParamFloat, (int)(yyvsp[(3) - (6)].number), (int)(yyvsp[(5) - (6)].number), (yyvsp[(4) - (6)].strval), (yyvsp[(6) - (6)].number)); 
				delete[] (yyvsp[(4) - (6)].strval);
			}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 774 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->AddParamMatrix((int)(yyvsp[(3) - (4)].number), (yyvsp[(4) - (4)].strval), 4, 4); 
				delete[] (yyvsp[(4) - (4)].strval);
			}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 780 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (5)].subprogram); 
				(yyvsp[(1) - (5)].subprogram)->AddParamMatrix((int)(yyvsp[(3) - (5)].number), (yyvsp[(4) - (5)].strval), (int)(yyvsp[(5) - (5)].number), 4); 
				delete[] (yyvsp[(4) - (5)].strval);
			}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 786 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (6)].subprogram); 
				(yyvsp[(1) - (6)].subprogram)->AddParamMatrix((int)(yyvsp[(3) - (6)].number), (yyvsp[(4) - (6)].strval), (int)(yyvsp[(5) - (6)].number), (int)(yyvsp[(6) - (6)].number)); 
				delete[] (yyvsp[(4) - (6)].strval);
			}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 792 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (7)].subprogram); 
				(yyvsp[(1) - (7)].subprogram)->AddParamMatrix((int)(yyvsp[(3) - (7)].number), (yyvsp[(4) - (7)].strval), (int)(yyvsp[(5) - (7)].number), (int)(yyvsp[(6) - (7)].number), (int)(yyvsp[(7) - (7)].number)); 
				delete[] (yyvsp[(4) - (7)].strval);
			}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 798 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (6)].subprogram); 
				(yyvsp[(1) - (6)].subprogram)->AddParamTexture((int)(yyvsp[(3) - (6)].number), (yyvsp[(4) - (6)].strval), (TextureDimension)(yyvsp[(5) - (6)].enumval), (int)(yyvsp[(6) - (6)].number)); 
				delete[] (yyvsp[(4) - (6)].strval);
			}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 804 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (5)].subprogram); 
				(yyvsp[(1) - (5)].subprogram)->AddParamTexture((int)(yyvsp[(3) - (5)].number), (yyvsp[(4) - (5)].strval), (TextureDimension)(yyvsp[(5) - (5)].enumval), (int)(yyvsp[(3) - (5)].number)); 
				delete[] (yyvsp[(4) - (5)].strval);
			}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 810 "SLParserYacc.y"
    {
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->AddParamTexture((yyvsp[(3) - (4)].strval), (TextureDimension)(yyvsp[(4) - (4)].enumval)); 
				delete[] (yyvsp[(3) - (4)].strval);
			}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 816 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (5)].subprogram); 
				(yyvsp[(1) - (5)].subprogram)->SetKeywords(*((yyvsp[(4) - (5)].strings))); 
				delete (yyvsp[(4) - (5)].strings); 
			}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 822 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->SetConstBuffer((yyvsp[(3) - (4)].strval), (int)(yyvsp[(4) - (4)].number)); 
				delete[] (yyvsp[(3) - (4)].strval);
			}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 828 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->BindConstBuffer((yyvsp[(3) - (4)].strval), (int)(yyvsp[(4) - (4)].number)); 
				delete[] (yyvsp[(3) - (4)].strval);
			}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 834 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->AddParamBuffer((int)(yyvsp[(3) - (4)].number), (yyvsp[(4) - (4)].strval)); 
				delete[] (yyvsp[(4) - (4)].strval);
			}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 842 "SLParserYacc.y"
    { 
				(yyval.strings) = new std::vector<std::string>(); 
			}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 846 "SLParserYacc.y"
    { 
				(yyval.strings) = (yyvsp[(1) - (2)].strings); 
				(yyval.strings)->emplace_back((yyvsp[(2) - (2)].strval));
				delete[] (yyvsp[(2) - (2)].strval);
			}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 854 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].number)); 
			}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 859 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));
				delete[] (yyvsp[(1) - (1)].strval);
			}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 867 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat (); 
				(yyval.floatval)->SetRef ((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 873 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat (); 
				(yyval.floatval)->SetValue ((yyvsp[(1) - (1)].enumval)); 
			}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 880 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat (); 
				(yyval.floatval)->SetRef ((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 886 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat (); 
				(yyval.floatval)->SetValue ((yyvsp[(1) - (1)].enumval)); 
			}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 893 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 899 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval)); 
			}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 904 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(0); 
			}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 911 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 917 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval)); 
			}
    break;


/* Line 1792 of yacc.c  */
#line 3042 "SLParserYacc.cpp"
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
#line 924 "SLParserYacc.y"


int yy1error (const char *s)
{
    printf("yy1error line %d %s\n", yy1lineno, s);
	_currentErrors.push_back(FormatString("Error line %d %s", yy1lineno, s));
	return 0;
}

static void PushShaderState ()
{
	SLShaderState* s = new SLShaderState(*_shaderStateStack.top());
	_shaderStateStack.push (s);
}

static void PopShaderState ()
{
	SLShaderState* s = _shaderStateStack.top();
	_shaderStateStack.pop ();
	delete s;
}
