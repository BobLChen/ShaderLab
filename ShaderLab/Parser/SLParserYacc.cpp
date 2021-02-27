
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
int32						g_CurrentProgramLine;
ProgramType					g_CurrentProgramType;

extern int32 yylineno;
extern char* yytext;

int32 shaderlaberror(const char *s);

int32 shaderlablex();

static void PushShaderState();
static void PopShaderState();

#define YYDEBUG 0



/* Line 189 of yacc.c  */
#line 118 "SLParserYacc.cpp"

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
     VAL_NUMBER = 299,
     VAL_ID = 300,
     VAL_STRING = 301,
     VAL_BRACKET_ID = 302,
     VAL_PROGRAM_SOURCE = 303,
     VAL_TRIANGLE_FACE = 304,
     VAL_COMPARE_MODE = 305,
     VAL_RGBA_MASK = 306,
     VAL_TEX_DIM = 307,
     VAL_BLEND_FACTOR = 308,
     VAL_BLEND_OP_MODE = 309,
     VAL_STENCIL_ACTION = 310,
     VAL_HLSLPROGRAM = 311,
     VAL_GLSLPROGRAM = 312,
     VAL_CGPROGRAM = 313
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 38 "SLParserYacc.y"

	SLVector4*							vector4;
	SLFloat*							floatval;
	SLShader*							shader;
	SLProperties*						properties;
	SLShaderState*						states;
	SLPassBase*							pass;
	SLSubShader*						subshader;
	const char*							strval;
	float								number;
	int32								enumval;
	std::vector<std::string>*			strings;
	std::map<std::string, std::string>* tags;
	std::vector<SLPassBase*>*			passes;



/* Line 214 of yacc.c  */
#line 230 "SLParserYacc.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 242 "SLParserYacc.cpp"

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
#define YYLAST   198

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
      66,     0,    -1,    -1,    -1,     3,    46,    67,    59,    69,
      68,    73,    60,    -1,    -1,    17,    59,    70,    60,    -1,
      -1,    70,    71,    45,    61,    46,    62,    14,    63,    64,
      44,    -1,    70,    71,    45,    61,    46,    62,    15,    61,
      44,    62,    44,    63,    63,    64,    44,    -1,    70,    71,
      45,    61,    46,    62,    16,    63,    64,    72,    -1,    70,
      71,    45,    61,    46,    62,    10,    63,    64,    72,    -1,
      70,    71,    45,    61,    46,    62,    52,    63,    64,    46,
      -1,    70,    71,    45,    61,    46,    62,    52,    63,    64,
      46,    59,    60,    -1,    -1,    71,    47,    -1,    61,    44,
      62,    44,    62,    44,    62,    44,    63,    -1,    61,    44,
      62,    44,    62,    44,    63,    -1,    -1,    73,    74,    -1,
      73,    76,    -1,    73,    78,    -1,    -1,     7,    59,    75,
      82,    73,    60,    -1,    -1,     6,    59,    77,    79,    60,
      -1,     8,    46,    -1,     8,    46,    62,    44,    -1,     8,
      13,    -1,    82,    80,    -1,    79,    82,    80,    -1,    -1,
       4,    59,    81,    82,    60,    -1,     5,    46,    -1,    -1,
      82,     9,    44,    -1,    82,    19,    46,    -1,    82,    18,
      59,    85,    60,    -1,    82,    11,    84,    -1,    82,    21,
      92,    -1,    82,    21,    12,    -1,    82,    21,    13,    -1,
      82,    20,    84,    -1,    82,    26,    91,    -1,    82,    22,
      83,    -1,    82,    22,    13,    -1,    82,    24,    89,    89,
      62,    89,    89,    -1,    82,    24,    89,    89,    -1,    82,
      24,    13,    -1,    82,    25,    90,    62,    90,    -1,    82,
      25,    90,    -1,    82,    28,    59,    86,    60,    -1,    82,
      27,    88,    62,    88,    -1,    82,    56,    48,    -1,    82,
      57,    48,    -1,    82,    58,    48,    -1,    47,    -1,    49,
      -1,    47,    -1,    12,    -1,    13,    -1,    -1,    85,    45,
      64,    45,    -1,    85,    46,    64,    46,    -1,    -1,    86,
      29,    88,    -1,    86,    30,    88,    -1,    86,    31,    88,
      -1,    86,    32,    92,    -1,    86,    33,    87,    -1,    86,
      34,    87,    -1,    86,    35,    87,    -1,    86,    40,    92,
      -1,    86,    41,    87,    -1,    86,    42,    87,    -1,    86,
      43,    87,    -1,    86,    36,    92,    -1,    86,    37,    87,
      -1,    86,    38,    87,    -1,    86,    39,    87,    -1,    47,
      -1,    55,    -1,    44,    -1,    47,    -1,    47,    -1,    53,
      -1,    47,    -1,    54,    -1,    47,    -1,    51,    -1,    13,
      -1,    47,    -1,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    88,    83,   102,   105,   112,   115,   124,
     133,   143,   153,   167,   184,   187,   196,   201,   209,   212,
     216,   223,   230,   229,   240,   239,   258,   263,   268,   274,
     279,   287,   286,   305,   313,   316,   321,   328,   335,   342,
     349,   354,   359,   366,   373,   380,   385,   399,   411,   419,
     429,   438,   451,   461,   467,   473,   481,   488,   495,   502,
     507,   515,   518,   529,   543,   547,   554,   561,   568,   575,
     582,   589,   596,   603,   610,   617,   624,   631,   638,   645,
     654,   661,   668,   673,   682,   689,   696,   703,   710,   717,
     722,   729,   736
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
  "TOKEN_OP_ZFAIL_FRONT", "VAL_NUMBER", "VAL_ID", "VAL_STRING",
  "VAL_BRACKET_ID", "VAL_PROGRAM_SOURCE", "VAL_TRIANGLE_FACE",
  "VAL_COMPARE_MODE", "VAL_RGBA_MASK", "VAL_TEX_DIM", "VAL_BLEND_FACTOR",
  "VAL_BLEND_OP_MODE", "VAL_STENCIL_ACTION", "VAL_HLSLPROGRAM",
  "VAL_GLSLPROGRAM", "VAL_CGPROGRAM", "'{'", "'}'", "'('", "','", "')'",
  "'='", "$accept", "shader", "$@1", "$@2", "properties", "propitems",
  "propflags", "vector4", "shaderBlocks", "category", "$@3", "subshader",
  "$@4", "fallback", "passes", "pass", "$@5", "states", "cullval",
  "boolean", "tags", "stencilblock", "stencilaction", "numval", "blendval",
  "blendopval", "maskval", "funcval", 0
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
#define YYPACT_NINF -87
static const yytype_int16 yypact[] =
{
       5,   -10,    52,   -87,   -87,     4,   104,    69,   -87,   -87,
     -87,    72,     6,   -87,    55,    79,    83,   -11,   -87,   -87,
     -87,   -87,    75,   -87,   -87,   -87,   -87,    81,    98,   -87,
     -87,   101,    84,    87,     0,    66,   -87,    45,   -87,     0,
      89,   103,   106,    58,    92,   107,    58,    17,    49,    -7,
      35,    25,   -37,    93,   108,   109,   110,   -87,     9,    91,
      96,    94,    97,    99,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -14,   -87,   -87,
     102,   -87,   -87,   -87,   -87,   -87,   -87,   105,   -87,   -87,
     -87,   -87,   -87,   111,   112,   117,   113,   114,   -87,     8,
     118,    35,   -37,    77,   120,   119,   121,   120,   122,    23,
     115,   123,   -87,   -14,   -87,   -87,   -37,   -37,   -37,    54,
     -24,   -24,   -24,    54,   -24,   -24,   -24,    54,   -24,   -24,
     -24,   -87,   125,   -87,   -87,   126,   -87,   127,   -87,   128,
     136,   -14,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   129,
     130,   124,   -87,   -87,   -87,   141,   131,   -87,   133,   132,
     144,   145,    11,   -87,   146,   -87,   134,   -87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   -87,   -87,    48,   137,   -87,
     -87,   -87,   -87,   -87,   -87,   135,   -87,   -30,   -87,   152,
     -87,   -87,    -5,    13,   -86,    60,   -87,   -34
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      35,   110,    26,    39,    40,    41,    84,    95,     1,    42,
      96,    43,    15,    16,    17,    15,    16,    17,    44,    45,
      46,    47,    48,   156,    49,    50,    51,    52,    53,    75,
      76,   157,    42,    85,    43,    27,     3,   151,    91,    86,
      85,    44,    45,    46,    47,    48,    86,    49,    50,    51,
      52,    53,     4,   120,   121,    59,    54,    55,    56,    60,
      61,    62,    80,     6,    77,   174,    18,    78,   122,   102,
      68,    69,    92,   184,   185,    42,    93,    43,   119,    54,
      55,    56,    88,   148,    44,    45,    46,    47,    48,    89,
      49,    50,    51,    52,    53,   155,    81,    63,    82,   161,
      22,    77,    23,   165,    78,    70,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     7,    54,    55,    56,   125,   159,   160,     9,   162,
     163,   164,    13,   166,   167,   168,    28,   141,    24,   152,
     153,   154,    25,    31,    32,    36,    37,    38,    65,    66,
      67,    72,    98,    73,   103,   105,    99,   100,   101,   104,
     106,   116,   107,   144,   111,   146,     0,   112,   147,   169,
     170,   124,    58,   172,    64,   114,   115,   117,   118,   149,
     123,   142,   173,   145,   177,   178,   171,   150,   182,   183,
     186,   175,     0,   176,   179,   180,   181,   187,    74
};

static const yytype_int16 yycheck[] =
{
      30,    87,    13,    33,     4,     5,    13,    44,     3,     9,
      47,    11,     6,     7,     8,     6,     7,     8,    18,    19,
      20,    21,    22,    47,    24,    25,    26,    27,    28,    12,
      13,    55,     9,    47,    11,    46,    46,   123,    13,    53,
      47,    18,    19,    20,    21,    22,    53,    24,    25,    26,
      27,    28,     0,    45,    46,    10,    56,    57,    58,    14,
      15,    16,    13,    59,    47,   151,    60,    50,    60,    60,
      12,    13,    47,    62,    63,     9,    51,    11,   108,    56,
      57,    58,    47,    60,    18,    19,    20,    21,    22,    54,
      24,    25,    26,    27,    28,   129,    47,    52,    49,   133,
      45,    47,    47,   137,    50,    47,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    17,    56,    57,    58,   112,   131,   132,    59,   134,
     135,   136,    60,   138,   139,   140,    61,    60,    59,   126,
     127,   128,    59,    62,    46,    44,    62,    60,    59,    46,
      44,    59,    59,    46,    63,    61,    48,    48,    48,    63,
      63,    44,    63,    44,    62,   117,    -1,    62,    46,    44,
      44,   111,    35,    45,    39,    64,    64,    64,    64,    64,
      62,    61,    46,    62,    60,    44,    59,    64,    44,    44,
      44,    62,    -1,    63,    63,    62,    64,    63,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    66,    46,     0,    67,    59,    17,    69,    59,
      68,    70,    73,    60,    71,     6,     7,     8,    60,    74,
      76,    78,    45,    47,    59,    59,    13,    46,    61,    77,
      75,    62,    46,    79,    82,    82,    44,    62,    60,    82,
       4,     5,     9,    11,    18,    19,    20,    21,    22,    24,
      25,    26,    27,    28,    56,    57,    58,    80,    73,    10,
      14,    15,    16,    52,    80,    59,    46,    44,    12,    13,
      47,    84,    59,    46,    84,    12,    13,    47,    50,    92,
      13,    47,    49,    83,    13,    47,    53,    89,    47,    54,
      90,    13,    47,    51,    91,    44,    47,    88,    59,    48,
      48,    48,    60,    63,    63,    61,    63,    63,    81,    85,
      89,    62,    62,    86,    64,    64,    44,    64,    64,    82,
      45,    46,    60,    62,    90,    88,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    60,    61,    72,    44,    62,    72,    46,    60,    64,
      64,    89,    88,    88,    88,    92,    47,    55,    87,    87,
      87,    92,    87,    87,    87,    92,    87,    87,    87,    44,
      44,    59,    45,    46,    89,    62,    63,    60,    44,    63,
      62,    64,    44,    44,    62,    63,    44,    63
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
#line 84 "SLParserYacc.y"
    {
				g_CurrentShader->shaderName = (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 88 "SLParserYacc.y"
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
#line 96 "SLParserYacc.y"
    {

			;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 102 "SLParserYacc.y"
    {
				(yyval.properties) = nullptr;
			;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 106 "SLParserYacc.y"
    {
				(yyval.properties) = (yyvsp[(3) - (4)].properties); 
			;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 112 "SLParserYacc.y"
    {
				(yyval.properties) = new SLProperties();
			;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 116 "SLParserYacc.y"
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
#line 125 "SLParserYacc.y"
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
#line 134 "SLParserYacc.y"
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
#line 144 "SLParserYacc.y"
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
#line 154 "SLParserYacc.y"
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
#line 168 "SLParserYacc.y"
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
#line 184 "SLParserYacc.y"
    {
				(yyval.strings) = new std::vector<std::string>();
			;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 188 "SLParserYacc.y"
    {
				(yyval.strings) = (yyvsp[(1) - (2)].strings);
				(yyval.strings)->emplace_back((yyvsp[(2) - (2)].strval));

				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 197 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue((yyvsp[(2) - (9)].number), (yyvsp[(4) - (9)].number), (yyvsp[(6) - (9)].number), (yyvsp[(8) - (9)].number));
			;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 202 "SLParserYacc.y"
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue((yyvsp[(2) - (7)].number), (yyvsp[(4) - (7)].number), (yyvsp[(6) - (7)].number), 1.0f);
			;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 209 "SLParserYacc.y"
    {

			;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 213 "SLParserYacc.y"
    {

			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 217 "SLParserYacc.y"
    {
				if ((yyvsp[(2) - (2)].subshader)) 
				{
					g_CurrentShader->subShaders.push_back((yyvsp[(2) - (2)].subshader)); 
				}
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 224 "SLParserYacc.y"
    {
				
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 230 "SLParserYacc.y"
    {
				PushShaderState();
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 234 "SLParserYacc.y"
    {
				PopShaderState();
			;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 240 "SLParserYacc.y"
    {
				PushShaderState();
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 244 "SLParserYacc.y"
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
#line 259 "SLParserYacc.y"
    {
				g_CurrentShader->fallbackName = (yyvsp[(2) - (2)].strval);
				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 264 "SLParserYacc.y"
    {
				g_CurrentShader->fallbackName = (yyvsp[(2) - (4)].strval);
				delete[] (yyvsp[(2) - (4)].strval);
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 269 "SLParserYacc.y"
    {
				g_CurrentShader->fallbackName = "";
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 275 "SLParserYacc.y"
    {
				(yyval.passes) = new std::vector<SLPassBase*>(); 
				(yyval.passes)->push_back((yyvsp[(2) - (2)].pass)); 
			;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 280 "SLParserYacc.y"
    {
				(yyval.passes) = (yyvsp[(1) - (3)].passes);  
				(yyval.passes)->push_back((yyvsp[(3) - (3)].pass));
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 287 "SLParserYacc.y"
    {
				PushShaderState();
			;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 291 "SLParserYacc.y"
    {
				SLNormalPass* pp = new SLNormalPass(*g_ShaderStateStack.top());
				pp->program.type   = g_CurrentProgramType;
				pp->program.source = g_CurrentProgramCode;
				pp->program.lineNo = g_CurrentProgramLine;

				(yyval.pass) = pp;
				
				g_CurrentProgramType = kCG;
				g_CurrentProgramCode = nullptr;
				g_CurrentProgramLine = 0;
				
				PopShaderState();
			;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 306 "SLParserYacc.y"
    {
				(yyval.pass) = new SLUsePass((yyvsp[(2) - (2)].strval)); 
				delete[] (yyvsp[(2) - (2)].strval);
			;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 313 "SLParserYacc.y"
    {
				(yyval.states) = g_ShaderStateStack.top();
			;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 317 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->lod = int32((yyvsp[(3) - (3)].number));
			;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 322 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->name = (yyvsp[(3) - (3)].strval);

				delete[] (yyvsp[(3) - (3)].strval);
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 329 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (5)].states); 
				(yyval.states)->AddTags(*(yyvsp[(4) - (5)].tags));

				delete (yyvsp[(4) - (5)].tags);
			;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 336 "SLParserYacc.y"
    {	
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->alphaToMask = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 343 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->zTest = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 350 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->zTest.SetValue(kFuncLEqual);
			;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 355 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->zTest.SetValue(kFuncDisabled);
			;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 360 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->zWrite = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 367 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->colMask = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 374 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->culling = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 381 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->culling.SetValue(kCullOff);
			;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 386 "SLParserYacc.y"
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
#line 400 "SLParserYacc.y"
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
#line 412 "SLParserYacc.y"
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
#line 420 "SLParserYacc.y"
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
#line 430 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				
				(yyval.states)->blendOp      = *(yyvsp[(3) - (3)].floatval);
				(yyval.states)->blendOpAlpha = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 439 "SLParserYacc.y"
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
#line 452 "SLParserYacc.y"
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
#line 462 "SLParserYacc.y"
    {
				g_CurrentProgramCode = (yyvsp[(3) - (3)].strval);
				g_CurrentProgramLine = (yyvsp[(2) - (3)].number);
				g_CurrentProgramType = kHLSL;
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 468 "SLParserYacc.y"
    {
				g_CurrentProgramCode = (yyvsp[(3) - (3)].strval);
				g_CurrentProgramLine = (yyvsp[(2) - (3)].number);
				g_CurrentProgramType = kGLSL;
			;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 474 "SLParserYacc.y"
    {
				g_CurrentProgramCode = (yyvsp[(3) - (3)].strval);
				g_CurrentProgramLine = (yyvsp[(2) - (3)].number);
				g_CurrentProgramType = kCG;
			;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 482 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 489 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval));
			;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 496 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 503 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(1);
			;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 508 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(0);
			;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 515 "SLParserYacc.y"
    {
				(yyval.tags) = new std::map<std::string, std::string>();
			;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 519 "SLParserYacc.y"
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
#line 530 "SLParserYacc.y"
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
#line 543 "SLParserYacc.y"
    {
				PushShaderState(); 
				(yyval.states) = g_ShaderStateStack.top();
			;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 548 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilRef = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 555 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states); 
				(yyval.states)->stencilReadMask = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 562 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilWriteMask = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 569 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.comp = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 576 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.pass = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 583 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.fail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 590 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOp.zFail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 597 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.comp = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 604 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.pass = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 611 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.fail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 618 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpFront.zFail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 625 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.comp = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 632 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.pass = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 639 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.fail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 646 "SLParserYacc.y"
    {
				(yyval.states) = (yyvsp[(1) - (3)].states);
				(yyval.states)->stencilOpBack.zFail = *(yyvsp[(3) - (3)].floatval);

				delete (yyvsp[(3) - (3)].floatval);
			;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 655 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 662 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue ((yyvsp[(1) - (1)].enumval));
			;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 669 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].number));
			;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 674 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 683 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 690 "SLParserYacc.y"
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval));
			;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 697 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 704 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval));
			;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 711 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 718 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval));
			;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 723 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue(0);
			;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 730 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[(1) - (1)].strval));

				delete[] (yyvsp[(1) - (1)].strval);
			;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 737 "SLParserYacc.y"
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[(1) - (1)].enumval));
			;}
    break;



/* Line 1455 of yacc.c  */
#line 2690 "SLParserYacc.cpp"
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
#line 743 "SLParserYacc.y"


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
