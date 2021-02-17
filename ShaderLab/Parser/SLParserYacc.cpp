
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

/* Substitute the variable and function names.  */
#define yyparse         shaderlabparse
#define yylex           shaderlablex
#define yyerror         shaderlaberror
#define yylval          shaderlablval
#define yychar          shaderlabchar
#define yydebug         shaderlabdebug
#define yynerrs         shaderlabnerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "SLParserYacc.y"


// bison -d -b y -o SLParserYacc.cpp -p "shaderlab_parser" SLParserYacc.y

#include <stdio.h>
#include <stack>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

#include "Common/Common.h"
#include "SLParserData.h"

using namespace shaderlab;

SLShader*					g_CurrentShader;
std::stack<SLShaderState*>	g_ShaderStateStack;
const char*                 g_CurrentProgramCode;
ProgramType					g_CurrentProgramType;

extern int32 yylineno;
extern char* yytext;

int32 shaderlaberror(const char *s);

int32 shaderlablex();

static void PushShaderState();
static void PopShaderState();

#define YYDEBUG 0



/* Line 189 of yacc.c  */
#line 117 "SLParserYacc.cpp"

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
     TOKEN_SUBSHADER = 261,
     TOKEN_CATEGORY = 262,
     TOKEN_FALLBACK = 263,
     TOKEN_LOD = 264,
     TOKEN_COLOR = 265,
     TOKEN_ALPHA_TO_MASK = 266,
     TOKEN_TRUE = 267,
     TOKEN_FALSE = 268,
     TOKEN_FLOAT = 269,
     TOKEN_RANGE = 270,
     TOKEN_VECTOR = 271,
     TOKEN_PROPERTIES = 272,
     TOKEN_TAGS = 273,
     TOKEN_NAME = 274,
     TOKEN_ZWRITE = 275,
     TOKEN_ZTEST = 276,
     TOKEN_CULL = 277,
     TOKEN_ZCLIP = 278,
     TOKEN_BLEND = 279,
     TOKEN_BLEND_OP = 280,
     TOKEN_COLORMASK = 281,
     TOKEN_OFFSET = 282,
     TOKEN_STENCIL = 283,
     TOKEN_REF = 284,
     TOKEN_READ_MASK = 285,
     TOKEN_WRITE_MASK = 286,
     TOKEN_COMP = 287,
     TOKEN_OP_PASS = 288,
     TOKEN_OP_FAIL = 289,
     TOKEN_OP_ZFAIL = 290,
     TOKEN_COMP_BACK = 291,
     TOKEN_OP_PASS_BACK = 292,
     TOKEN_OP_FAIL_BACK = 293,
     TOKEN_OP_ZFAIL_BACK = 294,
     TOKEN_COMP_FRONT = 295,
     TOKEN_OP_PASS_FRONT = 296,
     TOKEN_OP_FAIL_FRONT = 297,
     TOKEN_OP_ZFAIL_FRONT = 298,
     TOKEN_HLSLPROGRAM = 299,
     TOKEN_GLSLPROGRAM = 300,
     TOKEN_CGPROGRAM = 301,
     VAL_NUMBER = 302,
     VAL_ID = 303,
     VAL_STRING = 304,
     VAL_BRACKET_ID = 305,
     VAL_PROGRAM_SOURCE = 306,
     VAL_TRIANGLE_FACE = 307,
     VAL_COMPARE_MODE = 308,
     VAL_RGBA_MASK = 309,
     VAL_TEX_DIM = 310,
     VAL_BLEND_FACTOR = 311,
     VAL_BLEND_OP_MODE = 312,
     VAL_STENCIL_ACTION = 313
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 37 "SLParserYacc.y"

	SLVector4*							vector4;
	SLFloat*							floatval;
	SLShader*							shader;
	SLProperties*						properties;
	SLShaderState*						states;
	SLPassBase*							pass;
	SLSubShader*						subshader;
	const char*							strval;
	float								number;
	int32									enumval;
	std::vector<std::string>*			strings;
	std::map<std::string, std::string>* tags;
	std::vector<SLPassBase*>*			passes;



/* Line 214 of yacc.c  */
#line 229 "SLParserYacc.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 241 "SLParserYacc.cpp"

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
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      61,    63,     2,     2,    62,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      55,    56,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    15,    20,    21,    32,
      48,    59,    70,    81,    94,    95,    98,   108,   116,   117,
     120,   123,   126,   127,   134,   135,   141,   144,   149,   152,
     155,   159,   160,   166,   169,   170,   174,   178,   184,   188,
     192,   196,   200,   204,   208,   212,   216,   224,   229,   233,
     239,   243,   249,   255,   259,   263,   267,   269,   271,   273,
     275,   277,   278,   283,   288,   289,   293,   297,   301,   305,
     309,   313,   317,   321,   325,   329,   333,   337,   341,   345,
     349,   351,   353,   355,   357,   359,   361,   363,   365,   367,
     369,   371,   373
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      66,     0,    -1,    -1,    -1,     3,    49,    67,    59,    69,
      68,    73,    60,    -1,    -1,    17,    59,    70,    60,    -1,
      -1,    70,    71,    48,    61,    49,    62,    14,    63,    64,
      47,    -1,    70,    71,    48,    61,    49,    62,    15,    61,
      47,    62,    47,    63,    63,    64,    47,    -1,    70,    71,
      48,    61,    49,    62,    16,    63,    64,    72,    -1,    70,
      71,    48,    61,    49,    62,    10,    63,    64,    72,    -1,
      70,    71,    48,    61,    49,    62,    55,    63,    64,    49,
      -1,    70,    71,    48,    61,    49,    62,    55,    63,    64,
      49,    59,    60,    -1,    -1,    71,    50,    -1,    61,    47,
      62,    47,    62,    47,    62,    47,    63,    -1,    61,    47,
      62,    47,    62,    47,    63,    -1,    -1,    73,    74,    -1,
      73,    76,    -1,    73,    78,    -1,    -1,     7,    59,    75,
      82,    73,    60,    -1,    -1,     6,    59,    77,    79,    60,
      -1,     8,    49,    -1,     8,    49,    62,    47,    -1,     8,
      13,    -1,    82,    80,    -1,    79,    82,    80,    -1,    -1,
       4,    59,    81,    82,    60,    -1,     5,    49,    -1,    -1,
      82,     9,    47,    -1,    82,    19,    49,    -1,    82,    18,
      59,    85,    60,    -1,    82,    11,    84,    -1,    82,    21,
      92,    -1,    82,    21,    12,    -1,    82,    21,    13,    -1,
      82,    20,    84,    -1,    82,    26,    91,    -1,    82,    22,
      83,    -1,    82,    22,    13,    -1,    82,    24,    89,    89,
      62,    89,    89,    -1,    82,    24,    89,    89,    -1,    82,
      24,    13,    -1,    82,    25,    90,    62,    90,    -1,    82,
      25,    90,    -1,    82,    28,    59,    86,    60,    -1,    82,
      27,    88,    62,    88,    -1,    82,    44,    51,    -1,    82,
      45,    51,    -1,    82,    46,    51,    -1,    50,    -1,    52,
      -1,    50,    -1,    12,    -1,    13,    -1,    -1,    85,    48,
      64,    48,    -1,    85,    49,    64,    49,    -1,    -1,    86,
      29,    88,    -1,    86,    30,    88,    -1,    86,    31,    88,
      -1,    86,    32,    92,    -1,    86,    33,    87,    -1,    86,
      34,    87,    -1,    86,    35,    87,    -1,    86,    40,    92,
      -1,    86,    41,    87,    -1,    86,    42,    87,    -1,    86,
      43,    87,    -1,    86,    36,    92,    -1,    86,    37,    87,
      -1,    86,    38,    87,    -1,    86,    39,    87,    -1,    50,
      -1,    58,    -1,    47,    -1,    50,    -1,    50,    -1,    56,
      -1,    50,    -1,    57,    -1,    50,    -1,    54,    -1,    13,
      -1,    50,    -1,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    87,    82,   101,   104,   111,   114,   123,
     132,   142,   152,   166,   183,   186,   195,   200,   208,   211,
     215,   222,   229,   228,   239,   238,   257,   262,   267,   273,
     278,   286,   285,   302,   310,   313,   318,   325,   332,   339,
     346,   351,   356,   363,   370,   377,   382,   396,   408,   416,
     426,   435,   448,   458,   463,   468,   475,   482,   489,   496,
     501,   509,   512,   523,   537,   541,   548,   555,   562,   569,
     576,   583,   590,   597,   604,   611,   618,   625,   632,   639,
     648,   655,   662,   667,   676,   683,   690,   697,   704,   711,
     716,   723,   730
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_SHADER", "TOKEN_PASS",
  "TOKEN_USEPASS", "TOKEN_SUBSHADER", "TOKEN_CATEGORY", "TOKEN_FALLBACK",
  "TOKEN_LOD", "TOKEN_COLOR", "TOKEN_ALPHA_TO_MASK", "TOKEN_TRUE",
  "TOKEN_FALSE", "TOKEN_FLOAT", "TOKEN_RANGE", "TOKEN_VECTOR",
  "TOKEN_PROPERTIES", "TOKEN_TAGS", "TOKEN_NAME", "TOKEN_ZWRITE",
  "TOKEN_ZTEST", "TOKEN_CULL", "TOKEN_ZCLIP", "TOKEN_BLEND",
  "TOKEN_BLEND_OP", "TOKEN_COLORMASK", "TOKEN_OFFSET", "TOKEN_STENCIL",
  "TOKEN_REF", "TOKEN_READ_MASK", "TOKEN_WRITE_MASK", "TOKEN_COMP",
  "TOKEN_OP_PASS", "TOKEN_OP_FAIL", "TOKEN_OP_ZFAIL", "TOKEN_COMP_BACK",
  "TOKEN_OP_PASS_BACK", "TOKEN_OP_FAIL_BACK", "TOKEN_OP_ZFAIL_BACK",
  "TOKEN_COMP_FRONT", "TOKEN_OP_PASS_FRONT", "TOKEN_OP_FAIL_FRONT",
  "TOKEN_OP_ZFAIL_FRONT", "TOKEN_HLSLPROGRAM", "TOKEN_GLSLPROGRAM",
  "TOKEN_CGPROGRAM", "VAL_NUMBER", "VAL_ID", "VAL_STRING",
  "VAL_BRACKET_ID", "VAL_PROGRAM_SOURCE", "VAL_TRIANGLE_FACE",
  "VAL_COMPARE_MODE", "VAL_RGBA_MASK", "VAL_TEX_DIM", "VAL_BLEND_FACTOR",
  "VAL_BLEND_OP_MODE", "VAL_STENCIL_ACTION", "'{'", "'}'", "'('", "','",
  "')'", "'='", "$accept", "shader", "$@1", "$@2", "properties",
  "propitems", "propflags", "vector4", "shaderBlocks", "category", "$@3",
  "subshader", "$@4", "fallback", "passes", "pass", "$@5", "states",
  "cullval", "boolean", "tags", "stencilblock", "stencilaction", "numval",
  "blendval", "blendopval", "maskval", "funcval", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   123,
     125,    40,    44,    41,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    67,    68,    66,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    73,    75,    74,    77,    76,    78,    78,    78,    79,
      79,    81,    80,    80,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    84,    84,
      84,    85,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      91,    92,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     0,     4,     0,    10,    15,
      10,    10,    10,    12,     0,     2,     9,     7,     0,     2,
       2,     2,     0,     6,     0,     5,     2,     4,     2,     2,
       3,     0,     5,     2,     0,     3,     3,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     7,     4,     3,     5,
       3,     5,     5,     3,     3,     3,     1,     1,     1,     1,
       1,     0,     4,     4,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     5,     0,     3,     7,
      18,    14,     0,     6,     0,     0,     0,     0,     4,    19,
      20,    21,     0,    15,    24,    22,    28,    26,     0,    34,
      34,     0,     0,    34,     0,    18,    27,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,    30,    31,    33,    35,    59,    60,
      58,    38,    61,    36,    42,    40,    41,    91,    92,    39,
      45,    56,    57,    44,    48,    84,    85,     0,    86,    87,
      50,    90,    88,    89,    43,    82,    83,     0,    64,    53,
      54,    55,    23,     0,     0,     0,     0,     0,    34,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    49,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,    11,     8,     0,    10,    12,    32,     0,
       0,     0,    65,    66,    67,    68,    80,    81,    69,    70,
      71,    76,    77,    78,    79,    72,    73,    74,    75,     0,
       0,     0,    62,    63,    46,     0,     0,    13,     0,     0,
       0,     0,     0,     9,     0,    17,     0,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    10,     8,    11,    14,   143,    12,    19,
      30,    20,    29,    21,    33,    57,   108,    34,    83,    71,
     109,   113,   158,    97,    87,    90,    94,    79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int16 yypact[] =
{
      47,    14,    64,   -94,   -94,    26,    73,    49,   -94,   -94,
     -94,    50,    -2,   -94,    41,    52,    53,     5,   -94,   -94,
     -94,   -94,    56,   -94,   -94,   -94,   -94,    51,    60,   -94,
     -94,    71,    57,    81,    48,    77,   -94,     0,   -94,    48,
      61,    96,   102,    21,    91,   103,    21,    29,    -1,   -11,
      27,     6,    33,    92,   105,   106,   107,   -94,     1,    90,
      97,    93,    98,    99,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,    31,   -94,   -94,
     101,   -94,   -94,   -94,   -94,   -94,   -94,   104,   -94,   -94,
     -94,   -94,   -94,   100,   108,   112,   109,   110,   -94,   -17,
     113,    27,    33,    95,   115,   118,   116,   115,   119,     2,
     117,   120,   -94,    31,   -94,   -94,    33,    33,    33,   -15,
     -33,   -33,   -33,   -15,   -33,   -33,   -33,   -15,   -33,   -33,
     -33,   -94,   122,   -94,   -94,   123,   -94,   121,   -94,   129,
     130,    31,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   124,
     125,   111,   -94,   -94,   -94,   135,   126,   -94,   128,   127,
     136,   138,    44,   -94,   140,   -94,   131,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   -94,   -94,   -94,   -94,   -94,    75,   132,   -94,
     -94,   -94,   -94,   -94,   -94,   154,   -94,   -30,   -94,   149,
     -94,   -94,     8,   -12,   -86,    85,   -94,   -93
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      35,   110,    84,    39,    15,    16,    17,    15,    16,    17,
      59,    42,    80,    43,    60,    61,    62,   156,    26,    91,
      44,    45,    46,    47,    48,   157,    49,    50,    51,    52,
      53,   120,   121,    68,    69,    77,   155,   151,    78,    85,
     161,    75,    76,   122,   165,    86,    54,    55,    56,    81,
       1,    82,    40,    41,    27,    63,    92,    42,    18,    43,
      93,   102,   148,     3,     4,   174,    44,    45,    46,    47,
      48,    70,    49,    50,    51,    52,    53,    88,   119,    77,
      95,    85,    78,    96,    89,     6,    42,    86,    43,    22,
       7,    23,    54,    55,    56,    44,    45,    46,    47,    48,
     125,    49,    50,    51,    52,    53,   184,   185,     9,    32,
      13,    24,    25,    31,   152,   153,   154,    28,    36,    37,
      65,    54,    55,    56,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   159,
     160,    38,   162,   163,   164,    66,   166,   167,   168,    67,
      72,    98,    73,   103,   105,   141,    99,   100,   101,   116,
     104,   106,   107,   111,   114,   144,   112,    58,   147,   169,
     170,   177,   115,   117,   118,   123,   142,   172,   145,   173,
     171,   149,   178,   182,   150,   183,   175,   186,   176,   179,
     180,   181,   146,    64,   187,    74,   124
};

static const yytype_uint8 yycheck[] =
{
      30,    87,    13,    33,     6,     7,     8,     6,     7,     8,
      10,     9,    13,    11,    14,    15,    16,    50,    13,    13,
      18,    19,    20,    21,    22,    58,    24,    25,    26,    27,
      28,    48,    49,    12,    13,    50,   129,   123,    53,    50,
     133,    12,    13,    60,   137,    56,    44,    45,    46,    50,
       3,    52,     4,     5,    49,    55,    50,     9,    60,    11,
      54,    60,    60,    49,     0,   151,    18,    19,    20,    21,
      22,    50,    24,    25,    26,    27,    28,    50,   108,    50,
      47,    50,    53,    50,    57,    59,     9,    56,    11,    48,
      17,    50,    44,    45,    46,    18,    19,    20,    21,    22,
     112,    24,    25,    26,    27,    28,    62,    63,    59,    49,
      60,    59,    59,    62,   126,   127,   128,    61,    47,    62,
      59,    44,    45,    46,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   131,
     132,    60,   134,   135,   136,    49,   138,   139,   140,    47,
      59,    59,    49,    63,    61,    60,    51,    51,    51,    47,
      63,    63,    63,    62,    64,    47,    62,    35,    49,    47,
      47,    60,    64,    64,    64,    62,    61,    48,    62,    49,
      59,    64,    47,    47,    64,    47,    62,    47,    63,    63,
      62,    64,   117,    39,    63,    46,   111
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    66,    49,     0,    67,    59,    17,    69,    59,
      68,    70,    73,    60,    71,     6,     7,     8,    60,    74,
      76,    78,    48,    50,    59,    59,    13,    49,    61,    77,
      75,    62,    49,    79,    82,    82,    47,    62,    60,    82,
       4,     5,     9,    11,    18,    19,    20,    21,    22,    24,
      25,    26,    27,    28,    44,    45,    46,    80,    73,    10,
      14,    15,    16,    55,    80,    59,    49,    47,    12,    13,
      50,    84,    59,    49,    84,    12,    13,    50,    53,    92,
      13,    50,    52,    83,    13,    50,    56,    89,    50,    57,
      90,    13,    50,    54,    91,    47,    50,    88,    59,    51,
      51,    51,    60,    63,    63,    61,    63,    63,    81,    85,
      89,    62,    62,    86,    64,    64,    47,    64,    64,    82,
      48,    49,    60,    62,    90,    88,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    60,    61,    72,    47,    62,    72,    49,    60,    64,
      64,    89,    88,    88,    88,    92,    50,    58,    87,    87,
      87,    92,    87,    87,    87,    92,    87,    87,    87,    47,
      47,    59,    48,    49,    89,    62,    63,    60,    47,    63,
      62,    64,    47,    47,    62,    63,    47,    63
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
#line 83 "SLParserYacc.y"
    {
				g_CurrentShader->shaderName = (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 87 "SLParserYacc.y"
    {
				if ((yyvsp[(5) - (5)].properties)) 
				{
					g_CurrentShader->properties = *(yyvsp[(5) - (5)].properties);
					delete (yyvsp[(5) - (5)].properties);
				}
			;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 95 "SLParserYacc.y"
    {

			;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 101 "SLParserYacc.y"
    {
				(yyval.properties) = nullptr;
			;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 105 "SLParserYacc.y"
    {
				(yyval.properties) = (yyvsp[(3) - (4)].properties); 
			;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 111 "SLParserYacc.y"
    {
				(yyval.properties) = new SLProperties();
			;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 115 "SLParserYacc.y"
    {
				(yyval.properties) = (yyvsp[(1) - (10)].properties);
				(yyval.properties)->AddFloatProperty((yyvsp[(3) - (10)].strval), (yyvsp[(5) - (10)].strval), *(yyvsp[(2) - (10)].strings), (yyvsp[(10) - (10)].number));

				delete   (yyvsp[(2) - (10)].strings);
				delete[] (yyvsp[(3) - (10)].strval);
				delete[] (yyvsp[(5) - (10)].strval);
			;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 124 "SLParserYacc.y"
    {
				(yyval.properties) = (yyvsp[(1) - (15)].properties);
				(yyval.properties)->AddRangeProperty((yyvsp[(3) - (15)].strval), (yyvsp[(5) - (15)].strval), *(yyvsp[(2) - (15)].strings), (yyvsp[(15) - (15)].number), (yyvsp[(9) - (15)].number), (yyvsp[(11) - (15)].number)); 

				delete   (yyvsp[(2) - (15)].strings);
				delete[] (yyvsp[(3) - (15)].strval);
				delete[] (yyvsp[(5) - (15)].strval);
			;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 133 "SLParserYacc.y"
    {
				(yyval.properties) = (yyvsp[(1) - (10)].properties);
				(yyval.properties)->AddVectorProperty((yyvsp[(3) - (10)].strval), (yyvsp[(5) - (10)].strval), *(yyvsp[(2) - (10)].strings), *(yyvsp[(10) - (10)].vector4));

				delete[] (yyvsp[(3) - (10)].strval);
				delete[] (yyvsp[(5) - (10)].strval);
				delete   (yyvsp[(2) - (10)].strings);
				delete   (yyvsp[(10) - (10)].vector4); 
			;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 143 "SLParserYacc.y"
    {
				(yyval.properties) = (yyvsp[(1) - (10)].properties);
				(yyval.properties)->AddColorProperty((yyvsp[(3) - (10)].strval), (yyvsp[(5) - (10)].strval), *(yyvsp[(2) - (10)].strings), *(yyvsp[(10) - (10)].vector4));

				delete[] (yyvsp[(3) - (10)].strval);
				delete[] (yyvsp[(5) - (10)].strval);
				delete   (yyvsp[(2) - (10)].strings);
				delete   (yyvsp[(10) - (10)].vector4);
			;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 153 "SLParserYacc.y"
    {
				SLPropTexture texture;
				texture.name      = (yyvsp[(10) - (10)].strval);
				texture.dimension = (TextureDimension)(yyvsp[(7) - (10)].enumval);

				(yyval.properties) = (yyvsp[(1) - (10)].properties);
				(yyval.properties)->AddTextureProperty((yyvsp[(3) - (10)].strval), (yyvsp[(5) - (10)].strval), *(yyvsp[(2) - (10)].strings), texture);

				delete   (yyvsp[(2) - (10)].strings);
				delete[] (yyvsp[(3) - (10)].strval);
				delete[] (yyvsp[(5) - (10)].strval);
				delete[] (yyvsp[(10) - (10)].strval);
			;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 167 "SLParserYacc.y"
    {
				SLPropTexture texture;
				texture.name      = (yyvsp[(10) - (12)].strval);
				texture.dimension = (TextureDimension)(yyvsp[(7) - (12)].enumval);

				(yyval.properties) = (yyvsp[(1) - (12)].properties);
				(yyval.properties)->AddTextureProperty((yyvsp[(3) - (12)].strval), (yyvsp[(5) - (12)].strval), *(yyvsp[(2) - (12)].strings), texture);

				delete   (yyvsp[(2) - (12)].strings);
				delete[] (yyvsp[(3) - (12)].strval);
				delete[] (yyvsp[(5) - (12)].strval);
				delete[] (yyvsp[(10) - (12)].strval);
			;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 183 "SLParserYacc.y"
    {
				(yyval.strings) = new std::vector<std::string>();
			;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 187 "SLParserYacc.y"
    {
				(yyval.strings) = (yyvsp[(1) - (2)].strings);
				(yyval.strings)->emplace_back((yyvsp[(2) - (2)].strval));

				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 196 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue((yyvsp[(2) - (9)].number), (yyvsp[(4) - (9)].number), (yyvsp[(6) - (9)].number), (yyvsp[(8) - (9)].number));
			;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 201 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue((yyvsp[(2) - (7)].number), (yyvsp[(4) - (7)].number), (yyvsp[(6) - (7)].number), 1.0f);
			;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 208 "SLParserYacc.y"
    {

			;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 212 "SLParserYacc.y"
    {

			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 216 "SLParserYacc.y"
    {
				if ((yyvsp[(2) - (2)].subshader)) 
				{
					g_CurrentShader->subShaders.push_back((yyvsp[(2) - (2)].subshader)); 
				}
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 223 "SLParserYacc.y"
    {
				
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 229 "SLParserYacc.y"
    {
				PushShaderState();
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 233 "SLParserYacc.y"
    {
				PopShaderState();
			;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 239 "SLParserYacc.y"
    {
				PushShaderState();
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 243 "SLParserYacc.y"
    {
				const SLShaderState* state = g_ShaderStateStack.top();

				(yyval.subshader) = new SLSubShader();
				(yyval.subshader)->tags = state->tags;
				(yyval.subshader)->lod  = state->lod;
				(yyval.subshader)->SetPasses((yyvsp[(4) - (5)].passes));

				delete (yyvsp[(4) - (5)].passes);

				PopShaderState();
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 258 "SLParserYacc.y"
    {
				g_CurrentShader->fallbackName = (yyvsp[(2) - (2)].strval);
				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 263 "SLParserYacc.y"
    {
				g_CurrentShader->fallbackName = (yyvsp[(2) - (4)].strval);
				delete[] (yyvsp[(2) - (4)].strval);
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 268 "SLParserYacc.y"
    {
				g_CurrentShader->fallbackName = "";
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 274 "SLParserYacc.y"
    {
				(yyval.passes) = new std::vector<SLPassBase*>(); 
				(yyval.passes)->push_back((yyvsp[(2) - (2)].pass)); 
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 279 "SLParserYacc.y"
    {
				(yyval.passes) = (yyvsp[(1) - (3)].passes);  
				(yyval.passes)->push_back((yyvsp[(3) - (3)].pass));
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 286 "SLParserYacc.y"
    {
				PushShaderState();
			;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 290 "SLParserYacc.y"
    {
				SLNormalPass* pp = new SLNormalPass(*g_ShaderStateStack.top());
				pp->program.type   = g_CurrentProgramType;
				pp->program.source = g_CurrentProgramCode;

				(yyval.pass) = pp;
				
				g_CurrentProgramType = kCG;
				g_CurrentProgramCode = nullptr;
				
				PopShaderState();
			;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 303 "SLParserYacc.y"
    {
				(yyval.pass) = new SLUsePass((yyvsp[(2) - (2)].strval)); 
				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 310 "SLParserYacc.y"
    {
				(yyval.states) = g_ShaderStateStack.top();
			;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 314 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->lod = int32((yyvsp[(3) - (3)].number));
			;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 319 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->name = (yyvsp[(3) - (3)].strval);

				delete[] (yyvsp[(3) - (3)].strval);
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 326 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (5)].states); 
				(yyval.states)->AddTags(*(yyvsp[(4) - (5)].tags));

				delete (yyvsp[(4) - (5)].tags);
			;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 333 "SLParserYacc.y"
    {	
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->alphaToMask = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 340 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->zTest = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 347 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->zTest.SetValue(kFuncLEqual);
			;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 352 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->zTest.SetValue(kFuncDisabled);
			;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 357 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->zWrite = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 364 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->colMask = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 371 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->culling = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 378 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->culling.SetValue(kCullOff);
			;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 383 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (7)].states);

				(yyval.states)->srcBlend       = *(yyvsp[(3) - (7)].floatval);
				(yyval.states)->destBlend      = *(yyvsp[(4) - (7)].floatval);
				(yyval.states)->srcBlendAlpha  = *(yyvsp[(6) - (7)].floatval);
				(yyval.states)->destBlendAlpha = *(yyvsp[(7) - (7)].floatval);

				delete (yyvsp[(3) - (7)].floatval);
				delete (yyvsp[(4) - (7)].floatval);
				delete (yyvsp[(6) - (7)].floatval);
				delete (yyvsp[(7) - (7)].floatval);
			;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 397 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (4)].states); 

				(yyval.states)->srcBlend       = *(yyvsp[(3) - (4)].floatval);
				(yyval.states)->destBlend      = *(yyvsp[(4) - (4)].floatval);
				(yyval.states)->srcBlendAlpha  = *(yyvsp[(3) - (4)].floatval);
				(yyval.states)->destBlendAlpha = *(yyvsp[(4) - (4)].floatval);

				delete (yyvsp[(3) - (4)].floatval);
				delete (yyvsp[(4) - (4)].floatval);
			;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 409 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->srcBlend.SetValue(kBlendOne); 
				(yyval.states)->srcBlendAlpha.SetValue(kBlendOne); 
				(yyval.states)->destBlend.SetValue(kBlendZero); 
				(yyval.states)->destBlendAlpha.SetValue(kBlendZero);
			;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 417 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (5)].states);

				(yyval.states)->blendOp      = *(yyvsp[(3) - (5)].floatval);
				(yyval.states)->blendOpAlpha = *(yyvsp[(5) - (5)].floatval);

				delete (yyvsp[(3) - (5)].floatval);
				delete (yyvsp[(5) - (5)].floatval);
			;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 427 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				
				(yyval.states)->blendOp      = *(yyvsp[(3) - (3)].floatval);
				(yyval.states)->blendOpAlpha = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 436 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (5)].states);

				(yyval.states)->stencilRef       = (yyvsp[(4) - (5)].states)->stencilRef;
				(yyval.states)->stencilReadMask  = (yyvsp[(4) - (5)].states)->stencilReadMask;
				(yyval.states)->stencilWriteMask = (yyvsp[(4) - (5)].states)->stencilWriteMask;
				(yyval.states)->stencilOp 		 = (yyvsp[(4) - (5)].states)->stencilOp;
				(yyval.states)->stencilOpFront   = (yyvsp[(4) - (5)].states)->stencilOpFront;
				(yyval.states)->stencilOpBack    = (yyvsp[(4) - (5)].states)->stencilOpBack;

				PopShaderState();
			;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 449 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (5)].states);

				(yyval.states)->offsetFactor = *(yyvsp[(3) - (5)].floatval);
				(yyval.states)->offsetUnits  = *(yyvsp[(5) - (5)].floatval);

				delete (yyvsp[(3) - (5)].floatval);
				delete (yyvsp[(5) - (5)].floatval);
			;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 459 "SLParserYacc.y"
    {
				g_CurrentProgramCode = (yyvsp[(3) - (3)].strval);
				g_CurrentProgramType = kHLSL;
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 464 "SLParserYacc.y"
    {
				g_CurrentProgramCode = (yyvsp[(3) - (3)].strval);
				g_CurrentProgramType = kGLSL;
			;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 469 "SLParserYacc.y"
    {
				g_CurrentProgramCode = (yyvsp[(3) - (3)].strval);
				g_CurrentProgramType = kCG;
			;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 476 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 483 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval));
			;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 490 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 497 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(1);
			;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 502 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(0);
			;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 509 "SLParserYacc.y"
    {
				(yyval.tags) = new std::map<std::string, std::string>();
			;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 513 "SLParserYacc.y"
    {
				std::string key((yyvsp[(2) - (4)].strval));
				std::string value((yyvsp[(4) - (4)].strval));

				(yyval.tags) = (yyvsp[(1) - (4)].tags);
				(*(yyval.tags))[key] = value;

				delete[] (yyvsp[(2) - (4)].strval);
				delete[] (yyvsp[(4) - (4)].strval);
			;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 524 "SLParserYacc.y"
    {
				std::string key((yyvsp[(2) - (4)].strval));
				std::string value((yyvsp[(4) - (4)].strval));

				(yyval.tags) = (yyvsp[(1) - (4)].tags);
				(*(yyval.tags))[key] = value;

				delete[] (yyvsp[(2) - (4)].strval);
				delete[] (yyvsp[(4) - (4)].strval);
			;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 537 "SLParserYacc.y"
    {
				PushShaderState(); 
				(yyval.states) = g_ShaderStateStack.top();
			;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 542 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilRef = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 549 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->stencilReadMask = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 556 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilWriteMask = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 563 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.comp = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 570 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.pass = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 577 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.fail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 584 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.zFail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 591 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.comp = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 598 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.pass = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 605 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.fail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 612 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.zFail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 619 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.comp = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 626 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.pass = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 633 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.fail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 640 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.zFail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 649 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 656 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue ((yyvsp[(1) - (1)].enumval));
			;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 663 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].number));
			;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 668 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 677 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 684 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval));
			;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 691 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 698 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval));
			;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 705 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 712 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval));
			;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 717 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue(0);
			;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 724 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 731 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval));
			;}
    break;



/* Line 1455 of yacc.c  */
#line 2684 "SLParserYacc.cpp"
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
#line 737 "SLParserYacc.y"


int32 shaderlaberror(const char *s)
{
    printf("shaderlaberror line %d %s\n", yylineno, s);
	return 0;
}

static void PushShaderState()
{
	SLShaderState* s = new SLShaderState(*g_ShaderStateStack.top());
	g_ShaderStateStack.push(s);
}

static void PopShaderState()
{
	SLShaderState* s = g_ShaderStateStack.top();
	g_ShaderStateStack.pop();
	delete s;
}
