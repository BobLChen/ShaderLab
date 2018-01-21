
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
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

extern int yylineno;
extern char* yytext;

int yyerror(const char *s);
int yylex();

static void PushShaderState();
static void PopShaderState();

#define YYDEBUG 0



/* Line 189 of yacc.c  */
#line 104 "SLParserYacc.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     TOKEN_SETTEXTURE = 273,
     TOKEN_CONSTBUFFER = 274,
     TOKEN_BINDCB = 275,
     TOKEN_SETBUFFER = 276,
     TOKEN_MATRIX = 277,
     TOKEN_FLOAT = 278,
     TOKEN_RANGE = 279,
     TOKEN_VECTOR = 280,
     TOKEN_PROPERTIES = 281,
     TOKEN_PROGRAM = 282,
     TOKEN_SUBPROGRAM = 283,
     TOKEN_BIND = 284,
     TOKEN_TAGS = 285,
     TOKEN_NAME = 286,
     TOKEN_KEYWORDS = 287,
     TOKEN_ZWRITE = 288,
     TOKEN_ZTEST = 289,
     TOKEN_CULL = 290,
     TOKEN_BLEND = 291,
     TOKEN_BLEND_OP = 292,
     TOKEN_COLORMASK = 293,
     TOKEN_STENCIL = 294,
     TOKEN_REF = 295,
     TOKEN_READ_MASK = 296,
     TOKEN_WRITE_MASK = 297,
     TOKEN_COMP = 298,
     TOKEN_OP_PASS = 299,
     TOKEN_OP_FAIL = 300,
     TOKEN_OP_ZFAIL = 301,
     TOKEN_COMP_BACK = 302,
     TOKEN_OP_PASS_BACK = 303,
     TOKEN_OP_FAIL_BACK = 304,
     TOKEN_OP_ZFAIL_BACK = 305,
     TOKEN_COMP_FRONT = 306,
     TOKEN_OP_PASS_FRONT = 307,
     TOKEN_OP_FAIL_FRONT = 308,
     TOKEN_OP_ZFAIL_FRONT = 309,
     VAL_NUMBER = 310,
     VAL_ID = 311,
     VAL_STRING = 312,
     VAL_BRACKET_ID = 313,
     VAL_TRIANGLE_FACE = 314,
     VAL_COMPARE_MODE = 315,
     VAL_RGBA_MASK = 316,
     VAL_FOG_MODE = 317,
     VAL_TEX_DIM = 318,
     VAL_BLEND_FACTOR = 319,
     VAL_BLEND_OP_MODE = 320,
     VAL_STENCIL_ACTION = 321
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 31 "SLParserYacc.y"

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



/* Line 214 of yacc.c  */
#line 227 "SLParserYacc.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 239 "SLParserYacc.cpp"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   285

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNRULES -- Number of states.  */
#define YYNSTATES  263

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      69,    71,     2,     2,    70,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,    68,     2,     2,     2,     2,
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
      65,    66
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    15,    20,    21,    32,
      48,    59,    70,    81,    94,    95,    98,   108,   116,   117,
     120,   123,   126,   127,   134,   135,   141,   144,   149,   152,
     155,   159,   160,   166,   171,   174,   175,   181,   185,   188,
     189,   193,   197,   203,   209,   213,   217,   221,   225,   229,
     233,   237,   241,   249,   254,   258,   264,   268,   274,   281,
     283,   285,   287,   289,   291,   292,   297,   302,   303,   307,
     311,   315,   321,   331,   339,   341,   342,   346,   350,   354,
     358,   362,   366,   370,   374,   378,   382,   386,   390,   394,
     398,   402,   404,   406,   407,   414,   420,   421,   424,   429,
     434,   439,   445,   450,   456,   463,   469,   474,   480,   485,
     490,   495,   496,   499,   501,   503,   505,   507,   509,   511,
     513,   515,   517,   519
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      74,     0,    -1,    -1,    -1,     3,    57,    75,    67,    77,
      76,    81,    68,    -1,    -1,    26,    67,    78,    68,    -1,
      -1,    78,    79,    56,    69,    57,    70,    23,    71,    72,
      55,    -1,    78,    79,    56,    69,    57,    70,    24,    69,
      55,    70,    55,    71,    71,    72,    55,    -1,    78,    79,
      56,    69,    57,    70,    25,    71,    72,    80,    -1,    78,
      79,    56,    69,    57,    70,    14,    71,    72,    80,    -1,
      78,    79,    56,    69,    57,    70,    63,    71,    72,    57,
      -1,    78,    79,    56,    69,    57,    70,    63,    71,    72,
      57,    67,    68,    -1,    -1,    79,    58,    -1,    69,    55,
      70,    55,    70,    55,    70,    55,    71,    -1,    69,    55,
      70,    55,    70,    55,    71,    -1,    -1,    81,    82,    -1,
      81,    84,    -1,    81,    86,    -1,    -1,    11,    67,    83,
      91,    81,    68,    -1,    -1,     7,    67,    85,    87,    68,
      -1,    12,    57,    -1,    12,    57,    70,    55,    -1,    12,
      17,    -1,    91,    88,    -1,    87,    91,    88,    -1,    -1,
       4,    67,    89,    91,    68,    -1,     6,    67,    90,    68,
      -1,     5,    57,    -1,    -1,    90,    30,    67,    94,    68,
      -1,    90,    31,    57,    -1,    90,    57,    -1,    -1,    91,
      13,    55,    -1,    91,    31,    57,    -1,    91,    30,    67,
      94,    68,    -1,    91,     8,    67,    95,    68,    -1,    91,
      15,    93,    -1,    91,    34,   106,    -1,    91,    34,    16,
      -1,    91,    34,    17,    -1,    91,    33,    93,    -1,    91,
      38,   105,    -1,    91,    35,    92,    -1,    91,    35,    17,
      -1,    91,    36,   103,   103,    70,   103,   103,    -1,    91,
      36,   103,   103,    -1,    91,    36,    17,    -1,    91,    37,
     104,    70,   104,    -1,    91,    37,   104,    -1,    91,    39,
      67,    97,    68,    -1,    91,    27,    57,    67,    99,    68,
      -1,    58,    -1,    59,    -1,    58,    -1,    16,    -1,    17,
      -1,    -1,    94,    56,    72,    56,    -1,    94,    57,    72,
      57,    -1,    -1,    95,    14,    96,    -1,    95,    10,    62,
      -1,    95,     9,   102,    -1,    95,    24,   102,    70,   102,
      -1,    69,   102,    70,   102,    70,   102,    70,   102,    71,
      -1,    69,   102,    70,   102,    70,   102,    71,    -1,    58,
      -1,    -1,    97,    40,   102,    -1,    97,    41,   102,    -1,
      97,    42,   102,    -1,    97,    43,   106,    -1,    97,    44,
      98,    -1,    97,    45,    98,    -1,    97,    46,    98,    -1,
      97,    51,   106,    -1,    97,    52,    98,    -1,    97,    53,
      98,    -1,    97,    54,    98,    -1,    97,    47,   106,    -1,
      97,    48,    98,    -1,    97,    49,    98,    -1,    97,    50,
      98,    -1,    58,    -1,    66,    -1,    -1,    99,    28,    57,
      67,   100,    68,    -1,    99,    28,    67,   100,    68,    -1,
      -1,   100,    57,    -1,   100,    29,    57,    56,    -1,   100,
      23,    55,    58,    -1,   100,    25,    55,    58,    -1,   100,
      25,    55,    58,    55,    -1,   100,    22,    55,    58,    -1,
     100,    22,    55,    58,    55,    -1,   100,    18,    55,    58,
      63,    55,    -1,   100,    18,    55,    58,    63,    -1,   100,
      18,    58,    63,    -1,   100,    32,    67,   101,    68,    -1,
     100,    19,    57,    55,    -1,   100,    20,    57,    55,    -1,
     100,    21,    55,    58,    -1,    -1,   101,    57,    -1,    55,
      -1,    58,    -1,    58,    -1,    64,    -1,    58,    -1,    65,
      -1,    58,    -1,    61,    -1,    17,    -1,    58,    -1,    60,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    87,    81,   100,   103,   110,   113,   121,
     128,   137,   146,   159,   175,   178,   186,   191,   199,   202,
     206,   212,   218,   217,   228,   227,   242,   247,   252,   258,
     263,   271,   270,   285,   289,   297,   300,   306,   312,   321,
     324,   329,   335,   341,   351,   357,   363,   368,   373,   379,
     385,   391,   396,   408,   418,   426,   434,   441,   452,   461,
     467,   474,   480,   485,   493,   496,   505,   517,   521,   527,
     532,   538,   548,   557,   565,   575,   579,   585,   591,   597,
     603,   609,   615,   621,   627,   633,   639,   645,   651,   657,
     663,   671,   677,   685,   688,   695,   704,   707,   713,   720,
     726,   732,   738,   744,   750,   756,   762,   768,   774,   780,
     786,   795,   798,   806,   811,   819,   825,   832,   838,   845,
     851,   856,   863,   869
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_SHADER", "TOKEN_PASS",
  "TOKEN_USEPASS", "TOKEN_GRABPASS", "TOKEN_SUBSHADER", "TOKEN_FOG",
  "TOKEN_DENSITY", "TOKEN_MODE", "TOKEN_CATEGORY", "TOKEN_FALLBACK",
  "TOKEN_LOD", "TOKEN_COLOR", "TOKEN_ALPHA_TO_MASK", "TOKEN_TRUE",
  "TOKEN_FALSE", "TOKEN_SETTEXTURE", "TOKEN_CONSTBUFFER", "TOKEN_BINDCB",
  "TOKEN_SETBUFFER", "TOKEN_MATRIX", "TOKEN_FLOAT", "TOKEN_RANGE",
  "TOKEN_VECTOR", "TOKEN_PROPERTIES", "TOKEN_PROGRAM", "TOKEN_SUBPROGRAM",
  "TOKEN_BIND", "TOKEN_TAGS", "TOKEN_NAME", "TOKEN_KEYWORDS",
  "TOKEN_ZWRITE", "TOKEN_ZTEST", "TOKEN_CULL", "TOKEN_BLEND",
  "TOKEN_BLEND_OP", "TOKEN_COLORMASK", "TOKEN_STENCIL", "TOKEN_REF",
  "TOKEN_READ_MASK", "TOKEN_WRITE_MASK", "TOKEN_COMP", "TOKEN_OP_PASS",
  "TOKEN_OP_FAIL", "TOKEN_OP_ZFAIL", "TOKEN_COMP_BACK",
  "TOKEN_OP_PASS_BACK", "TOKEN_OP_FAIL_BACK", "TOKEN_OP_ZFAIL_BACK",
  "TOKEN_COMP_FRONT", "TOKEN_OP_PASS_FRONT", "TOKEN_OP_FAIL_FRONT",
  "TOKEN_OP_ZFAIL_FRONT", "VAL_NUMBER", "VAL_ID", "VAL_STRING",
  "VAL_BRACKET_ID", "VAL_TRIANGLE_FACE", "VAL_COMPARE_MODE",
  "VAL_RGBA_MASK", "VAL_FOG_MODE", "VAL_TEX_DIM", "VAL_BLEND_FACTOR",
  "VAL_BLEND_OP_MODE", "VAL_STENCIL_ACTION", "'{'", "'}'", "'('", "','",
  "')'", "'='", "$accept", "shader", "$@1", "$@2", "properties",
  "propitems", "propflags", "vector4", "shaderBlocks", "category", "$@3",
  "subshader", "$@4", "fallback", "passes", "pass", "$@5", "grabpass",
  "states", "cullval", "boolean", "tags", "fogblock", "color",
  "stencilblock", "stencilaction", "subprograms", "subprogram",
  "stringlist", "numval", "blendval", "blendopval", "maskval", "funcval", 0
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
     315,   316,   317,   318,   319,   320,   321,   123,   125,    40,
      44,    41,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    75,    76,    74,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    80,    80,    81,    81,
      81,    81,    83,    82,    85,    84,    86,    86,    86,    87,
      87,    89,    88,    88,    88,    90,    90,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    92,
      92,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      95,    95,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    98,    98,    99,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     105,   105,   106,   106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     0,     4,     0,    10,    15,
      10,    10,    10,    12,     0,     2,     9,     7,     0,     2,
       2,     2,     0,     6,     0,     5,     2,     4,     2,     2,
       3,     0,     5,     4,     2,     0,     5,     3,     2,     0,
       3,     3,     5,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     7,     4,     3,     5,     3,     5,     6,     1,
       1,     1,     1,     1,     0,     4,     4,     0,     3,     3,
       3,     5,     9,     7,     1,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     0,     6,     5,     0,     2,     4,     4,
       4,     5,     4,     5,     6,     5,     4,     5,     4,     4,
       4,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     5,     0,     3,     7,
      18,    14,     0,     6,     0,     0,     0,     0,     4,    19,
      20,    21,     0,    15,    24,    22,    28,    26,     0,    39,
      39,     0,     0,    39,     0,    18,    27,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,    30,    31,    34,    35,    67,    40,    62,
      63,    61,    44,     0,    64,    41,    48,    46,    47,   122,
     123,    45,    51,    59,    60,    50,    54,   115,   116,     0,
     117,   118,    56,   121,   119,   120,    49,    75,    23,     0,
       0,     0,     0,     0,    39,     0,     0,    93,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    33,     0,     0,     0,     0,    43,     0,     0,     0,
      42,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
      11,     8,     0,    10,    12,    32,    64,    37,   113,   114,
      70,    69,    74,     0,    68,     0,     0,    58,     0,     0,
       0,    76,    77,    78,    79,    91,    92,    80,    81,    82,
      87,    88,    89,    90,    83,    84,    85,    86,     0,     0,
       0,     0,     0,     0,     0,    96,    65,    66,    52,     0,
       0,    13,    36,     0,    71,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    95,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,     9,     0,     0,
     106,   108,   109,   110,   102,    99,   100,    98,     0,     0,
      17,     0,    73,   105,   103,   101,   112,   107,     0,     0,
     104,    16,    72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    10,     8,    11,    14,   150,    12,    19,
      30,    20,    29,    21,    33,    56,   104,   105,    34,    85,
      72,   108,   106,   164,   111,   177,   127,   206,   248,   160,
      89,    92,    96,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -126
static const yytype_int16 yypact[] =
{
      21,   -50,    34,  -126,  -126,   -26,    49,    -4,  -126,  -126,
    -126,    12,     4,  -126,    60,    30,    33,    20,  -126,  -126,
    -126,  -126,    35,  -126,  -126,  -126,  -126,    41,    70,  -126,
    -126,    83,    71,    91,   109,   141,  -126,     8,  -126,   109,
      88,   103,    96,    97,   106,    23,   108,    99,   110,    23,
      48,    44,     9,   -29,   -14,   102,  -126,     6,   128,   132,
     101,   136,   137,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,   114,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,   -52,
    -126,  -126,   139,  -126,  -126,  -126,  -126,  -126,  -126,   140,
     143,   118,   144,   145,  -126,    62,    11,  -126,    64,   148,
     -29,   142,   150,   156,   151,   150,   157,    15,   146,   163,
    -126,  -126,    54,   160,    32,    54,  -126,    42,   152,   153,
    -126,   -52,  -126,    54,    54,    54,    77,   -39,   -39,   -39,
      77,   -39,   -39,   -39,    77,   -39,   -39,   -39,  -126,   168,
    -126,  -126,   171,  -126,   161,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,    54,  -126,   159,   -53,  -126,   174,   170,
     -52,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,   162,   164,
     165,    94,   166,    54,   167,  -126,  -126,  -126,  -126,   176,
     169,  -126,  -126,    54,  -126,  -126,    37,   172,   173,   177,
      66,    73,   180,   181,   184,   186,   188,   189,   191,   179,
    -126,  -126,   194,   195,    54,  -126,   193,   190,   197,   199,
     198,   200,   201,   202,   205,  -126,    82,  -126,    87,   192,
    -126,  -126,  -126,  -126,   207,  -126,   208,  -126,    39,   209,
    -126,    54,  -126,   210,  -126,  -126,  -126,  -126,   196,   203,
    -126,  -126,  -126
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,  -126,  -126,  -126,  -126,   154,   222,  -126,
    -126,  -126,  -126,  -126,  -126,   227,  -126,  -126,   -28,  -126,
     219,   115,  -126,  -126,  -126,    59,  -126,    65,  -126,  -125,
     -88,   175,  -126,   -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     165,   109,    35,    93,   194,    39,    87,     3,   171,   172,
     173,    15,    88,    15,   195,    16,    17,    16,    17,   175,
     122,   123,    58,    43,     1,   124,    86,   176,    44,    90,
      45,    59,    60,    61,     4,   125,    91,    26,   192,    69,
      70,     6,    46,   170,    94,    47,    48,    95,    49,    50,
      51,    52,    53,    54,    55,   211,   212,   213,   214,   215,
     216,    82,   217,     9,    77,    78,   218,    87,   204,   219,
     166,    62,    18,    88,    98,     7,   117,    27,   209,   126,
      13,    71,   198,   155,   211,   212,   213,   214,   215,   216,
     162,   217,   118,   119,   220,   218,   256,    24,   219,   238,
      25,   163,    83,    84,    28,   221,    79,   257,    80,   158,
     167,    31,   159,    40,    41,    42,    22,    43,    23,   120,
     128,   129,    44,   220,    45,   174,   259,    32,   226,   180,
     121,   227,   130,   184,   225,    79,    46,    80,    36,    47,
      48,    37,    49,    50,    51,    52,    53,    54,    55,    43,
     128,   129,   249,   250,    44,    64,    45,   251,   252,    38,
      65,    68,   202,    66,    67,    73,    74,    75,    46,    97,
     101,    47,    48,   114,    49,    50,    51,    52,    53,    54,
      55,   107,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   178,   179,    99,
     181,   182,   183,   100,   185,   186,   187,   102,   103,   110,
     148,   151,   112,   156,   154,   113,   115,   116,   131,   149,
     157,   152,   161,   188,   168,   169,   189,   197,   190,   193,
     196,   207,   199,   201,   205,   200,   203,   228,   229,   230,
     208,   231,   222,   232,   233,   223,   235,   224,   234,   236,
     237,   239,   241,   240,   242,   253,   243,    57,   244,   245,
     246,   247,   254,   255,   258,   260,    63,   261,    76,   153,
     210,   191,     0,     0,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132
};

static const yytype_int16 yycheck[] =
{
     125,    89,    30,    17,    57,    33,    58,    57,   133,   134,
     135,     7,    64,     7,    67,    11,    12,    11,    12,    58,
       9,    10,    14,     8,     3,    14,    17,    66,    13,    58,
      15,    23,    24,    25,     0,    24,    65,    17,   163,    16,
      17,    67,    27,   131,    58,    30,    31,    61,    33,    34,
      35,    36,    37,    38,    39,    18,    19,    20,    21,    22,
      23,    17,    25,    67,    16,    17,    29,    58,   193,    32,
      28,    63,    68,    64,    68,    26,   104,    57,   203,    68,
      68,    58,   170,    68,    18,    19,    20,    21,    22,    23,
      58,    25,    30,    31,    57,    29,    57,    67,    32,   224,
      67,    69,    58,    59,    69,    68,    58,    68,    60,    55,
      68,    70,    58,     4,     5,     6,    56,     8,    58,    57,
      56,    57,    13,    57,    15,   136,   251,    57,    55,   140,
      68,    58,    68,   144,    68,    58,    27,    60,    55,    30,
      31,    70,    33,    34,    35,    36,    37,    38,    39,     8,
      56,    57,    70,    71,    13,    67,    15,    70,    71,    68,
      57,    55,    68,    67,    67,    57,    67,    57,    27,    67,
      69,    30,    31,    55,    33,    34,    35,    36,    37,    38,
      39,    67,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,   138,   139,    71,
     141,   142,   143,    71,   145,   146,   147,    71,    71,    70,
      68,    55,    72,    67,    57,    72,    72,    72,    70,    69,
      57,    70,    62,    55,    72,    72,    55,    57,    67,    70,
      56,    55,    70,    68,    67,    71,    70,    57,    57,    55,
      71,    55,    70,    55,    55,    72,    67,    70,    57,    55,
      55,    58,    55,    63,    55,    63,    58,    35,    58,    58,
      58,    56,    55,    55,    55,    55,    39,    71,    49,   115,
     205,   156,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    74,    57,     0,    75,    67,    26,    77,    67,
      76,    78,    81,    68,    79,     7,    11,    12,    68,    82,
      84,    86,    56,    58,    67,    67,    17,    57,    69,    85,
      83,    70,    57,    87,    91,    91,    55,    70,    68,    91,
       4,     5,     6,     8,    13,    15,    27,    30,    31,    33,
      34,    35,    36,    37,    38,    39,    88,    81,    14,    23,
      24,    25,    63,    88,    67,    57,    67,    67,    55,    16,
      17,    58,    93,    57,    67,    57,    93,    16,    17,    58,
      60,   106,    17,    58,    59,    92,    17,    58,    64,   103,
      58,    65,   104,    17,    58,    61,   105,    67,    68,    71,
      71,    69,    71,    71,    89,    90,    95,    67,    94,   103,
      70,    97,    72,    72,    55,    72,    72,    91,    30,    31,
      57,    68,     9,    10,    14,    24,    68,    99,    56,    57,
      68,    70,   104,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    68,    69,
      80,    55,    70,    80,    57,    68,    67,    57,    55,    58,
     102,    62,    58,    69,    96,   102,    28,    68,    72,    72,
     103,   102,   102,   102,   106,    58,    66,    98,    98,    98,
     106,    98,    98,    98,   106,    98,    98,    98,    55,    55,
      67,    94,   102,    70,    57,    67,    56,    57,   103,    70,
      71,    68,    68,    70,   102,    67,   100,    55,    71,   102,
     100,    18,    19,    20,    21,    22,    23,    25,    29,    32,
      57,    68,    70,    72,    70,    68,    55,    58,    57,    57,
      55,    55,    55,    55,    57,    67,    55,    55,   102,    58,
      63,    55,    55,    58,    58,    58,    58,    56,   101,    70,
      71,    70,    71,    63,    55,    55,    57,    68,    55,   102,
      55,    71,    71
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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

/* Line 1455 of yacc.c  */
#line 82 "SLParserYacc.y"
    {
				_currentShader->shaderName = (yyvsp[(2) - (2)].strval);
				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 87 "SLParserYacc.y"
    {
				if ((yyvsp[(5) - (5)].properties)) {
					_currentShader->properties = *(yyvsp[(5) - (5)].properties);
					delete (yyvsp[(5) - (5)].properties);
				}
			;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 94 "SLParserYacc.y"
    {
				
			;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 100 "SLParserYacc.y"
    {
				(yyval.properties) = nullptr;
			;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 104 "SLParserYacc.y"
    { 
				(yyval.properties) = (yyvsp[(3) - (4)].properties); 
			;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 110 "SLParserYacc.y"
    {
				(yyval.properties) = new SLProperties(); 
			;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 114 "SLParserYacc.y"
    { 
				(yyval.properties) = (yyvsp[(1) - (10)].properties); 
				(yyval.properties)->AddFloatProperty((yyvsp[(3) - (10)].strval), (yyvsp[(5) - (10)].strval), *(yyvsp[(2) - (10)].strings), (yyvsp[(10) - (10)].number));
				delete[] (yyvsp[(3) - (10)].strval);
				delete[] (yyvsp[(5) - (10)].strval);
				delete (yyvsp[(2) - (10)].strings); 
			;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 122 "SLParserYacc.y"
    { 
				(yyval.properties) = (yyvsp[(1) - (15)].properties); 
				(yyval.properties)->AddRangeProperty((yyvsp[(3) - (15)].strval), (yyvsp[(5) - (15)].strval), *(yyvsp[(2) - (15)].strings), (yyvsp[(15) - (15)].number), (yyvsp[(9) - (15)].number), (yyvsp[(11) - (15)].number)); 
				delete[] (yyvsp[(3) - (15)].strval);
				delete[] (yyvsp[(5) - (15)].strval);
			;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 129 "SLParserYacc.y"
    { 
				(yyval.properties) = (yyvsp[(1) - (10)].properties); 
				(yyval.properties)->AddVectorProperty((yyvsp[(3) - (10)].strval), (yyvsp[(5) - (10)].strval), *(yyvsp[(2) - (10)].strings), *(yyvsp[(10) - (10)].vector4));
				delete[] (yyvsp[(3) - (10)].strval);
				delete[] (yyvsp[(5) - (10)].strval);
				delete (yyvsp[(2) - (10)].strings);
				delete (yyvsp[(10) - (10)].vector4); 
			;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 138 "SLParserYacc.y"
    { 
				(yyval.properties) = (yyvsp[(1) - (10)].properties);
				(yyval.properties)->AddColorProperty((yyvsp[(3) - (10)].strval), (yyvsp[(5) - (10)].strval), *(yyvsp[(2) - (10)].strings), *(yyvsp[(10) - (10)].vector4));
				delete[] (yyvsp[(3) - (10)].strval);
				delete[] (yyvsp[(5) - (10)].strval);
				delete (yyvsp[(2) - (10)].strings);
				delete (yyvsp[(10) - (10)].vector4);
			;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 147 "SLParserYacc.y"
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
			;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 160 "SLParserYacc.y"
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
			;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 175 "SLParserYacc.y"
    { 
				(yyval.strings) = new std::vector<std::string>(); 
			;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 179 "SLParserYacc.y"
    {
				(yyval.strings) = (yyvsp[(1) - (2)].strings);
				(yyval.strings)->emplace_back((yyvsp[(2) - (2)].strval));
				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 187 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue((yyvsp[(2) - (9)].number), (yyvsp[(4) - (9)].number), (yyvsp[(6) - (9)].number), (yyvsp[(8) - (9)].number));
			;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 192 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue((yyvsp[(2) - (7)].number), (yyvsp[(4) - (7)].number), (yyvsp[(6) - (7)].number), 1.0f);
			;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 199 "SLParserYacc.y"
    {
				
			;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 203 "SLParserYacc.y"
    {
				
			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 207 "SLParserYacc.y"
    { 
				if ((yyvsp[(2) - (2)].subshader)) {
					_currentShader->subShaders.push_back((yyvsp[(2) - (2)].subshader)); 
				}
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 213 "SLParserYacc.y"
    {

			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 218 "SLParserYacc.y"
    { 
				PushShaderState (); 
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 222 "SLParserYacc.y"
    { 
				PopShaderState (); 
			;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 228 "SLParserYacc.y"
    { 
				PushShaderState (); 
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 232 "SLParserYacc.y"
    {
				(yyval.subshader) = new SLSubShader();
				const SLShaderState* state = _shaderStateStack.top();
				(yyval.subshader)->tags = state->tags;
				(yyval.subshader)->lod  = state->lod;
				(yyval.subshader)->SetPasses((yyvsp[(4) - (5)].passes));
				delete (yyvsp[(4) - (5)].passes);
				PopShaderState ();
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 243 "SLParserYacc.y"
    { 
				_currentShader->fallbackName = (yyvsp[(2) - (2)].strval);
				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 248 "SLParserYacc.y"
    {
				_currentShader->fallbackName = (yyvsp[(2) - (4)].strval);
				delete[] (yyvsp[(2) - (4)].strval);
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 253 "SLParserYacc.y"
    {
				_currentShader->fallbackName = "None";
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 259 "SLParserYacc.y"
    { 
				(yyval.passes) = new std::vector<SLPassBase*>; 
				(yyval.passes)->push_back((yyvsp[(2) - (2)].pass)); 
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 264 "SLParserYacc.y"
    { 
				(yyval.passes) = (yyvsp[(1) - (3)].passes);  
				(yyval.passes)->push_back((yyvsp[(3) - (3)].pass)); 
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 271 "SLParserYacc.y"
    { 
				PushShaderState(); 
				_yaccCurrentPrograms.clear();
			;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 276 "SLParserYacc.y"
    {	
				SLNormalPass *pp = new SLNormalPass(*_shaderStateStack.top());
				(yyval.pass) = pp;
				for (int i = 0; i < _yaccCurrentPrograms.size(); ++i) {
					pp->programs.push_back(_yaccCurrentPrograms[i]);
				}
				_yaccCurrentPrograms.clear();
				PopShaderState();
			;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 286 "SLParserYacc.y"
    { 
				(yyval.pass) = (yyvsp[(3) - (4)].grabpass); 
			;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 290 "SLParserYacc.y"
    { 
				(yyval.pass) = new SLUsePass((yyvsp[(2) - (2)].strval)); 
				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 297 "SLParserYacc.y"
    { 
				(yyval.grabpass) = new SLGrabPass(); 
			;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 301 "SLParserYacc.y"
    { 
				(yyval.grabpass) = (yyvsp[(1) - (5)].grabpass); 
				(yyval.grabpass)->AddTags(*(yyvsp[(4) - (5)].tags)); 
				delete (yyvsp[(4) - (5)].tags); 
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 307 "SLParserYacc.y"
    { 
				(yyval.grabpass) = (yyvsp[(1) - (3)].grabpass); 
				(yyval.grabpass)->name = std::string((yyvsp[(3) - (3)].strval)); 
				delete[] (yyvsp[(3) - (3)].strval);
			;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 313 "SLParserYacc.y"
    { 
				(yyval.grabpass) = (yyvsp[(1) - (2)].grabpass); 
				(yyval.grabpass)->textureName = std::string((yyvsp[(2) - (2)].strval)); 
				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 321 "SLParserYacc.y"
    {
				(yyval.states) = _shaderStateStack.top(); 
			;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 325 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->lod = int((yyvsp[(3) - (3)].number)); 
			;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 330 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->name = (yyvsp[(3) - (3)].strval); 
				delete[] (yyvsp[(3) - (3)].strval);
			;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 336 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (5)].states); 
				(yyval.states)->AddTags(*(yyvsp[(4) - (5)].tags));
				delete (yyvsp[(4) - (5)].tags);
			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 342 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (5)].states);
				(yyval.states)->fogColor   = (yyvsp[(4) - (5)].states)->fogColor;
				(yyval.states)->fogMode    = (yyvsp[(4) - (5)].states)->fogMode;
				(yyval.states)->fogDensity = (yyvsp[(4) - (5)].states)->fogDensity;
				(yyval.states)->fogStart   = (yyvsp[(4) - (5)].states)->fogStart;
				(yyval.states)->fogEnd     = (yyvsp[(4) - (5)].states)->fogEnd;
				PopShaderState();
			;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 352 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->alphaToMask = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 358 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->zTest = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 364 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->zTest.SetValue(kFuncLEqual); 
			;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 369 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->zTest.SetValue(kFuncDisabled); 
			;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 374 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->zWrite = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 380 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->colMask = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 386 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->culling = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 392 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->culling.SetValue(kCullOff); 
			;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 397 "SLParserYacc.y"
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
			;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 409 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (4)].states); 
				(yyval.states)->srcBlend = *(yyvsp[(3) - (4)].floatval);
				(yyval.states)->destBlend = *(yyvsp[(4) - (4)].floatval);
				(yyval.states)->srcBlendAlpha = *(yyvsp[(3) - (4)].floatval);
				(yyval.states)->destBlendAlpha = *(yyvsp[(4) - (4)].floatval);
				delete (yyvsp[(3) - (4)].floatval);
				delete (yyvsp[(4) - (4)].floatval);
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 419 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->srcBlend.SetValue(kBlendOne); 
				(yyval.states)->srcBlendAlpha.SetValue(kBlendOne); 
				(yyval.states)->destBlend.SetValue(kBlendZero); 
				(yyval.states)->destBlendAlpha.SetValue(kBlendZero); 
			;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 427 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (5)].states); 
				(yyval.states)->blendOp = *(yyvsp[(3) - (5)].floatval);
				(yyval.states)->blendOpAlpha = *(yyvsp[(5) - (5)].floatval);
				delete (yyvsp[(3) - (5)].floatval);
				delete (yyvsp[(5) - (5)].floatval);
			;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 435 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->blendOp = *(yyvsp[(3) - (3)].floatval);
				(yyval.states)->blendOpAlpha = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 442 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (5)].states);
				(yyval.states)->stencilRef = (yyvsp[(4) - (5)].states)->stencilRef;
				(yyval.states)->stencilReadMask = (yyvsp[(4) - (5)].states)->stencilReadMask;
				(yyval.states)->stencilWriteMask = (yyvsp[(4) - (5)].states)->stencilWriteMask;
				(yyval.states)->stencilOp = (yyvsp[(4) - (5)].states)->stencilOp;
				(yyval.states)->stencilOpFront = (yyvsp[(4) - (5)].states)->stencilOpFront;
				(yyval.states)->stencilOpBack = (yyvsp[(4) - (5)].states)->stencilOpBack;
				PopShaderState();
			;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 453 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (6)].states);
				(yyvsp[(5) - (6)].program)->type = (yyvsp[(3) - (6)].strval);
				_yaccCurrentPrograms.push_back((yyvsp[(5) - (6)].program));
				delete[] (yyvsp[(3) - (6)].strval);
			;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 462 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 468 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval)); 
			;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 475 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 481 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(1); 
			;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 486 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(0); 
			;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 493 "SLParserYacc.y"
    {
				(yyval.tags) = new std::map<std::string, std::string>(); 
			;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 497 "SLParserYacc.y"
    { 
				(yyval.tags) = (yyvsp[(1) - (4)].tags);
				std::string key((yyvsp[(2) - (4)].strval));
				std::string value((yyvsp[(4) - (4)].strval));
				(*(yyval.tags))[key] = value;
				delete[] (yyvsp[(2) - (4)].strval);
				delete[] (yyvsp[(4) - (4)].strval);
			;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 506 "SLParserYacc.y"
    { 
				(yyval.tags) = (yyvsp[(1) - (4)].tags);
				std::string key((yyvsp[(2) - (4)].strval));
				std::string value((yyvsp[(4) - (4)].strval));
				(*(yyval.tags))[key] = value; 
				delete[] (yyvsp[(2) - (4)].strval);
				delete[] (yyvsp[(4) - (4)].strval);
			;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 517 "SLParserYacc.y"
    {
				PushShaderState(); 
				(yyval.states) = _shaderStateStack.top(); 
			;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 522 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyvsp[(1) - (3)].states)->fogColor = *(yyvsp[(3) - (3)].vector4); 
				delete (yyvsp[(3) - (3)].vector4); 
			;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 528 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyvsp[(1) - (3)].states)->fogMode = (FogMode)(yyvsp[(3) - (3)].enumval); 
			;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 533 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyvsp[(1) - (3)].states)->fogDensity = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 539 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (5)].states);
				(yyvsp[(1) - (5)].states)->fogStart = *(yyvsp[(3) - (5)].floatval);
				(yyvsp[(1) - (5)].states)->fogEnd = *(yyvsp[(5) - (5)].floatval);
				delete (yyvsp[(3) - (5)].floatval);
				delete (yyvsp[(5) - (5)].floatval);
			;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 549 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue(*(yyvsp[(2) - (9)].floatval), *(yyvsp[(4) - (9)].floatval), *(yyvsp[(6) - (9)].floatval), *(yyvsp[(8) - (9)].floatval));
				delete (yyvsp[(2) - (9)].floatval); 
				delete (yyvsp[(4) - (9)].floatval); 
				delete (yyvsp[(6) - (9)].floatval); 
				delete (yyvsp[(8) - (9)].floatval);
			;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 558 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue(*(yyvsp[(2) - (7)].floatval), *(yyvsp[(4) - (7)].floatval), *(yyvsp[(6) - (7)].floatval));
				delete (yyvsp[(2) - (7)].floatval); 
				delete (yyvsp[(4) - (7)].floatval); 
				delete (yyvsp[(6) - (7)].floatval);
			;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 566 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue(0, 0, 0, 0);
				(yyval.vector4)->SetRef((yyvsp[(1) - (1)].strval));
				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 575 "SLParserYacc.y"
    {
				PushShaderState(); 
				(yyval.states) = _shaderStateStack.top(); 
			;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 580 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states) ->stencilRef = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 586 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->stencilReadMask = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 592 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilWriteMask = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 598 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.comp = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 604 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.pass = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 610 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.fail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 616 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.zFail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 622 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.comp = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 628 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.pass = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 634 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.fail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 640 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.zFail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 646 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.comp = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 652 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.pass = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 658 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.fail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 664 "SLParserYacc.y"
    { 
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.zFail = *(yyvsp[(3) - (3)].floatval);
				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 672 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 678 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue ((yyvsp[(1) - (1)].enumval)); 
			;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 685 "SLParserYacc.y"
    { 
				(yyval.program) = new SLProgram(); 
			;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 689 "SLParserYacc.y"
    {
				(yyval.program) = (yyvsp[(1) - (6)].program);
				(yyvsp[(5) - (6)].subprogram)->name = (yyvsp[(3) - (6)].strval);
				(yyval.program)->subPrograms.push_back((yyvsp[(5) - (6)].subprogram));
				delete[] (yyvsp[(3) - (6)].strval);
			;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 696 "SLParserYacc.y"
    { 
				(yyval.program) = (yyvsp[(1) - (5)].program);
				(yyvsp[(4) - (5)].subprogram)->name = "";
				(yyvsp[(1) - (5)].program)->subPrograms.push_back((yyvsp[(4) - (5)].subprogram)); 
			;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 704 "SLParserYacc.y"
    { 
				(yyval.subprogram) = new SLSubProgram(); 
			;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 708 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (2)].subprogram); 
				(yyval.subprogram)->source = (yyvsp[(2) - (2)].strval); 
				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 714 "SLParserYacc.y"
    {
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram);
				(yyval.subprogram)->Bind((yyvsp[(3) - (4)].strval), (yyvsp[(4) - (4)].strval));
				delete[] (yyvsp[(3) - (4)].strval);
				delete[] (yyvsp[(4) - (4)].strval);
			;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 721 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->AddParamVector(kShaderParamFloat, (int)(yyvsp[(3) - (4)].number), 1, (yyvsp[(4) - (4)].strval)); 
				delete[] (yyvsp[(4) - (4)].strval);
			;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 727 "SLParserYacc.y"
    {
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->AddParamVector(kShaderParamFloat, (int)(yyvsp[(3) - (4)].number), 4, (yyvsp[(4) - (4)].strval)); 
				delete[] (yyvsp[(4) - (4)].strval);
			;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 733 "SLParserYacc.y"
    {
				(yyval.subprogram)=(yyvsp[(1) - (5)].subprogram); 
				(yyvsp[(1) - (5)].subprogram)->AddParamVector(kShaderParamFloat, (int)(yyvsp[(3) - (5)].number), (int)(yyvsp[(5) - (5)].number), (yyvsp[(4) - (5)].strval)); 
				delete[] (yyvsp[(4) - (5)].strval);
			;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 739 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->AddParamMatrix((int)(yyvsp[(3) - (4)].number), (yyvsp[(4) - (4)].strval), 4); 
				delete[] (yyvsp[(4) - (4)].strval);
			;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 745 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (5)].subprogram); 
				(yyvsp[(1) - (5)].subprogram)->AddParamMatrix((int)(yyvsp[(3) - (5)].number), (yyvsp[(4) - (5)].strval), (int)(yyvsp[(5) - (5)].number)); 
				delete[] (yyvsp[(4) - (5)].strval);
			;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 751 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (6)].subprogram); 
				(yyvsp[(1) - (6)].subprogram)->AddParamTexture((int)(yyvsp[(3) - (6)].number), (yyvsp[(4) - (6)].strval), (TextureDimension)(yyvsp[(5) - (6)].enumval), (int)(yyvsp[(6) - (6)].number)); 
				delete[] (yyvsp[(4) - (6)].strval);
			;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 757 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (5)].subprogram); 
				(yyvsp[(1) - (5)].subprogram)->AddParamTexture((int)(yyvsp[(3) - (5)].number), (yyvsp[(4) - (5)].strval), (TextureDimension)(yyvsp[(5) - (5)].enumval), (int)(yyvsp[(3) - (5)].number)); 
				delete[] (yyvsp[(4) - (5)].strval);
			;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 763 "SLParserYacc.y"
    {
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->AddParamTexture((yyvsp[(3) - (4)].strval), (TextureDimension)(yyvsp[(4) - (4)].enumval)); 
				delete[] (yyvsp[(3) - (4)].strval);
			;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 769 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (5)].subprogram); 
				(yyvsp[(1) - (5)].subprogram)->SetKeywords(*((yyvsp[(4) - (5)].strings))); 
				delete (yyvsp[(4) - (5)].strings); 
			;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 775 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->SetConstBuffer((yyvsp[(3) - (4)].strval), (int)(yyvsp[(4) - (4)].number)); 
				delete[] (yyvsp[(3) - (4)].strval);
			;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 781 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->BindConstBuffer((yyvsp[(3) - (4)].strval), (int)(yyvsp[(4) - (4)].number)); 
				delete[] (yyvsp[(3) - (4)].strval);
			;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 787 "SLParserYacc.y"
    { 
				(yyval.subprogram) = (yyvsp[(1) - (4)].subprogram); 
				(yyvsp[(1) - (4)].subprogram)->AddParamBuffer((int)(yyvsp[(3) - (4)].number), (yyvsp[(4) - (4)].strval)); 
				delete[] (yyvsp[(4) - (4)].strval);
			;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 795 "SLParserYacc.y"
    { 
				(yyval.strings) = new std::vector<std::string>(); 
			;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 799 "SLParserYacc.y"
    { 
				(yyval.strings) = (yyvsp[(1) - (2)].strings); 
				(yyval.strings)->emplace_back((yyvsp[(2) - (2)].strval));
				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 807 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].number)); 
			;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 812 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));
				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 820 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat (); 
				(yyval.floatval)->SetRef ((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 826 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat (); 
				(yyval.floatval)->SetValue ((yyvsp[(1) - (1)].enumval)); 
			;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 833 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat (); 
				(yyval.floatval)->SetRef ((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 839 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat (); 
				(yyval.floatval)->SetValue ((yyvsp[(1) - (1)].enumval)); 
			;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 846 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 852 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval)); 
			;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 857 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(0); 
			;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 864 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval)); 
				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 870 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval)); 
			;}
    break;



/* Line 1455 of yacc.c  */
#line 3043 "SLParserYacc.cpp"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 877 "SLParserYacc.y"


int yyerror (const char *s)
{
    printf("yyerror line %d %s\n", yylineno, s);
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

