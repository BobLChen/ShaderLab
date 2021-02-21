/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         shaderlabparse
#define yylex           shaderlablex
#define yyerror         shaderlaberror
#define yydebug         shaderlabdebug
#define yynerrs         shaderlabnerrs

#define yylval          shaderlablval
#define yychar          shaderlabchar

/* Copy the first part of user declarations.  */
#line 1 "SLParserYacc.y" /* yacc.c:339  */


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


#line 110 "SLParserYacc.cpp" /* yacc.c:339  */

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
   by #include "SLParserYacc.hpp".  */
#ifndef YY_SHADERLAB_SLPARSERYACC_HPP_INCLUDED
# define YY_SHADERLAB_SLPARSERYACC_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int shaderlabdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
/* Tokens.  */
#define TOKEN_SHADER 258
#define TOKEN_PASS 259
#define TOKEN_USEPASS 260
#define TOKEN_SUBSHADER 261
#define TOKEN_CATEGORY 262
#define TOKEN_FALLBACK 263
#define TOKEN_LOD 264
#define TOKEN_COLOR 265
#define TOKEN_ALPHA_TO_MASK 266
#define TOKEN_TRUE 267
#define TOKEN_FALSE 268
#define TOKEN_FLOAT 269
#define TOKEN_RANGE 270
#define TOKEN_VECTOR 271
#define TOKEN_PROPERTIES 272
#define TOKEN_TAGS 273
#define TOKEN_NAME 274
#define TOKEN_ZWRITE 275
#define TOKEN_ZTEST 276
#define TOKEN_CULL 277
#define TOKEN_ZCLIP 278
#define TOKEN_BLEND 279
#define TOKEN_BLEND_OP 280
#define TOKEN_COLORMASK 281
#define TOKEN_OFFSET 282
#define TOKEN_STENCIL 283
#define TOKEN_REF 284
#define TOKEN_READ_MASK 285
#define TOKEN_WRITE_MASK 286
#define TOKEN_COMP 287
#define TOKEN_OP_PASS 288
#define TOKEN_OP_FAIL 289
#define TOKEN_OP_ZFAIL 290
#define TOKEN_COMP_BACK 291
#define TOKEN_OP_PASS_BACK 292
#define TOKEN_OP_FAIL_BACK 293
#define TOKEN_OP_ZFAIL_BACK 294
#define TOKEN_COMP_FRONT 295
#define TOKEN_OP_PASS_FRONT 296
#define TOKEN_OP_FAIL_FRONT 297
#define TOKEN_OP_ZFAIL_FRONT 298
#define VAL_NUMBER 299
#define VAL_ID 300
#define VAL_STRING 301
#define VAL_BRACKET_ID 302
#define VAL_PROGRAM_SOURCE 303
#define VAL_TRIANGLE_FACE 304
#define VAL_COMPARE_MODE 305
#define VAL_RGBA_MASK 306
#define VAL_TEX_DIM 307
#define VAL_BLEND_FACTOR 308
#define VAL_BLEND_OP_MODE 309
#define VAL_STENCIL_ACTION 310
#define VAL_HLSLPROGRAM 311
#define VAL_GLSLPROGRAM 312
#define VAL_CGPROGRAM 313

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "SLParserYacc.y" /* yacc.c:355  */

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

#line 282 "SLParserYacc.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE shaderlablval;

int shaderlabparse (void);

#endif /* !YY_SHADERLAB_SLPARSERYACC_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 299 "SLParserYacc.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "blendopval", "maskval", "funcval", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   123,
     125,    40,    44,    41,    61
};
# endif

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   -87,   -87,    48,   137,   -87,
     -87,   -87,   -87,   -87,   -87,   135,   -87,   -30,   -87,   152,
     -87,   -87,    -5,    13,   -86,    60,   -87,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    10,     8,    11,    14,   143,    12,    19,
      30,    20,    29,    21,    33,    57,   108,    34,    83,    71,
     109,   113,   158,    97,    87,    90,    94,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
#line 84 "SLParserYacc.y" /* yacc.c:1646  */
    {
				g_CurrentShader->shaderName = (yyvsp[0].strval);
			}
#line 1520 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "SLParserYacc.y" /* yacc.c:1646  */
    {
				if ((yyvsp[0].properties)) 
				{
					g_CurrentShader->properties = *(yyvsp[0].properties);
					delete (yyvsp[0].properties);
				}
			}
#line 1532 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 96 "SLParserYacc.y" /* yacc.c:1646  */
    {

			}
#line 1540 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.properties) = nullptr;
			}
#line 1548 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 106 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.properties) = (yyvsp[-1].properties); 
			}
#line 1556 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.properties) = new SLProperties();
			}
#line 1564 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.properties) = (yyvsp[-9].properties);
				(yyval.properties)->AddFloatProperty((yyvsp[-7].strval), (yyvsp[-5].strval), *(yyvsp[-8].strings), (yyvsp[0].number));

				delete   (yyvsp[-8].strings);
				delete[] (yyvsp[-7].strval);
				delete[] (yyvsp[-5].strval);
			}
#line 1577 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 125 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.properties) = (yyvsp[-14].properties);
				(yyval.properties)->AddRangeProperty((yyvsp[-12].strval), (yyvsp[-10].strval), *(yyvsp[-13].strings), (yyvsp[0].number), (yyvsp[-6].number), (yyvsp[-4].number)); 

				delete   (yyvsp[-13].strings);
				delete[] (yyvsp[-12].strval);
				delete[] (yyvsp[-10].strval);
			}
#line 1590 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 134 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.properties) = (yyvsp[-9].properties);
				(yyval.properties)->AddVectorProperty((yyvsp[-7].strval), (yyvsp[-5].strval), *(yyvsp[-8].strings), *(yyvsp[0].vector4));

				delete[] (yyvsp[-7].strval);
				delete[] (yyvsp[-5].strval);
				delete   (yyvsp[-8].strings);
				delete   (yyvsp[0].vector4); 
			}
#line 1604 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 144 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.properties) = (yyvsp[-9].properties);
				(yyval.properties)->AddColorProperty((yyvsp[-7].strval), (yyvsp[-5].strval), *(yyvsp[-8].strings), *(yyvsp[0].vector4));

				delete[] (yyvsp[-7].strval);
				delete[] (yyvsp[-5].strval);
				delete   (yyvsp[-8].strings);
				delete   (yyvsp[0].vector4);
			}
#line 1618 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 154 "SLParserYacc.y" /* yacc.c:1646  */
    {
				SLPropTexture texture;
				texture.name      = (yyvsp[0].strval);
				texture.dimension = (TextureDimension)(yyvsp[-3].enumval);

				(yyval.properties) = (yyvsp[-9].properties);
				(yyval.properties)->AddTextureProperty((yyvsp[-7].strval), (yyvsp[-5].strval), *(yyvsp[-8].strings), texture);

				delete   (yyvsp[-8].strings);
				delete[] (yyvsp[-7].strval);
				delete[] (yyvsp[-5].strval);
				delete[] (yyvsp[0].strval);
			}
#line 1636 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 168 "SLParserYacc.y" /* yacc.c:1646  */
    {
				SLPropTexture texture;
				texture.name      = (yyvsp[-2].strval);
				texture.dimension = (TextureDimension)(yyvsp[-5].enumval);

				(yyval.properties) = (yyvsp[-11].properties);
				(yyval.properties)->AddTextureProperty((yyvsp[-9].strval), (yyvsp[-7].strval), *(yyvsp[-10].strings), texture);

				delete   (yyvsp[-10].strings);
				delete[] (yyvsp[-9].strval);
				delete[] (yyvsp[-7].strval);
				delete[] (yyvsp[-2].strval);
			}
#line 1654 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 184 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.strings) = new std::vector<std::string>();
			}
#line 1662 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 188 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.strings) = (yyvsp[-1].strings);
				(yyval.strings)->emplace_back((yyvsp[0].strval));

				delete[] (yyvsp[0].strval);
			}
#line 1673 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 197 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue((yyvsp[-7].number), (yyvsp[-5].number), (yyvsp[-3].number), (yyvsp[-1].number));
			}
#line 1682 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.vector4) = new SLVector4();
				(yyval.vector4)->SetValue((yyvsp[-5].number), (yyvsp[-3].number), (yyvsp[-1].number), 1.0f);
			}
#line 1691 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 209 "SLParserYacc.y" /* yacc.c:1646  */
    {

			}
#line 1699 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 213 "SLParserYacc.y" /* yacc.c:1646  */
    {

			}
#line 1707 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 217 "SLParserYacc.y" /* yacc.c:1646  */
    {
				if ((yyvsp[0].subshader)) 
				{
					g_CurrentShader->subShaders.push_back((yyvsp[0].subshader)); 
				}
			}
#line 1718 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 224 "SLParserYacc.y" /* yacc.c:1646  */
    {
				
			}
#line 1726 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 230 "SLParserYacc.y" /* yacc.c:1646  */
    {
				PushShaderState();
			}
#line 1734 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 234 "SLParserYacc.y" /* yacc.c:1646  */
    {
				PopShaderState();
			}
#line 1742 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 240 "SLParserYacc.y" /* yacc.c:1646  */
    {
				PushShaderState();
			}
#line 1750 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 244 "SLParserYacc.y" /* yacc.c:1646  */
    {
				const SLShaderState* state = g_ShaderStateStack.top();

				(yyval.subshader) = new SLSubShader();
				(yyval.subshader)->tags = state->tags;
				(yyval.subshader)->lod  = state->lod;
				(yyval.subshader)->SetPasses((yyvsp[-1].passes));

				delete (yyvsp[-1].passes);

				PopShaderState();
			}
#line 1767 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 259 "SLParserYacc.y" /* yacc.c:1646  */
    {
				g_CurrentShader->fallbackName = (yyvsp[0].strval);
				delete[] (yyvsp[0].strval);
			}
#line 1776 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 264 "SLParserYacc.y" /* yacc.c:1646  */
    {
				g_CurrentShader->fallbackName = (yyvsp[-2].strval);
				delete[] (yyvsp[-2].strval);
			}
#line 1785 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 269 "SLParserYacc.y" /* yacc.c:1646  */
    {
				g_CurrentShader->fallbackName = "";
			}
#line 1793 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 275 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.passes) = new std::vector<SLPassBase*>(); 
				(yyval.passes)->push_back((yyvsp[0].pass)); 
			}
#line 1802 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 280 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.passes) = (yyvsp[-2].passes);  
				(yyval.passes)->push_back((yyvsp[0].pass));
			}
#line 1811 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 287 "SLParserYacc.y" /* yacc.c:1646  */
    {
				PushShaderState();
			}
#line 1819 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 291 "SLParserYacc.y" /* yacc.c:1646  */
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
			}
#line 1838 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 306 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.pass) = new SLUsePass((yyvsp[0].strval)); 
				delete[] (yyvsp[0].strval);
			}
#line 1847 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 313 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = g_ShaderStateStack.top();
			}
#line 1855 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 317 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states); 
				(yyval.states)->lod = int32((yyvsp[0].number));
			}
#line 1864 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 322 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states); 
				(yyval.states)->name = (yyvsp[0].strval);

				delete[] (yyvsp[0].strval);
			}
#line 1875 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 329 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-4].states); 
				(yyval.states)->AddTags(*(yyvsp[-1].tags));

				delete (yyvsp[-1].tags);
			}
#line 1886 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 336 "SLParserYacc.y" /* yacc.c:1646  */
    {	
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->alphaToMask = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 1897 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 343 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->zTest = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 1908 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 350 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states); 
				(yyval.states)->zTest.SetValue(kFuncLEqual);
			}
#line 1917 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 355 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states); 
				(yyval.states)->zTest.SetValue(kFuncDisabled);
			}
#line 1926 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 360 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->zWrite = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 1937 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 367 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->colMask = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 1948 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 374 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->culling = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 1959 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 381 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states); 
				(yyval.states)->culling.SetValue(kCullOff);
			}
#line 1968 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 386 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-6].states);

				(yyval.states)->srcBlend       = *(yyvsp[-4].floatval);
				(yyval.states)->destBlend      = *(yyvsp[-3].floatval);
				(yyval.states)->srcBlendAlpha  = *(yyvsp[-1].floatval);
				(yyval.states)->destBlendAlpha = *(yyvsp[0].floatval);

				delete (yyvsp[-4].floatval);
				delete (yyvsp[-3].floatval);
				delete (yyvsp[-1].floatval);
				delete (yyvsp[0].floatval);
			}
#line 1986 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 400 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-3].states); 

				(yyval.states)->srcBlend       = *(yyvsp[-1].floatval);
				(yyval.states)->destBlend      = *(yyvsp[0].floatval);
				(yyval.states)->srcBlendAlpha  = *(yyvsp[-1].floatval);
				(yyval.states)->destBlendAlpha = *(yyvsp[0].floatval);

				delete (yyvsp[-1].floatval);
				delete (yyvsp[0].floatval);
			}
#line 2002 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 412 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states); 
				(yyval.states)->srcBlend.SetValue(kBlendOne); 
				(yyval.states)->srcBlendAlpha.SetValue(kBlendOne); 
				(yyval.states)->destBlend.SetValue(kBlendZero); 
				(yyval.states)->destBlendAlpha.SetValue(kBlendZero);
			}
#line 2014 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 420 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-4].states);

				(yyval.states)->blendOp      = *(yyvsp[-2].floatval);
				(yyval.states)->blendOpAlpha = *(yyvsp[0].floatval);

				delete (yyvsp[-2].floatval);
				delete (yyvsp[0].floatval);
			}
#line 2028 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 430 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				
				(yyval.states)->blendOp      = *(yyvsp[0].floatval);
				(yyval.states)->blendOpAlpha = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2041 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 439 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-4].states);

				(yyval.states)->stencilRef       = (yyvsp[-1].states)->stencilRef;
				(yyval.states)->stencilReadMask  = (yyvsp[-1].states)->stencilReadMask;
				(yyval.states)->stencilWriteMask = (yyvsp[-1].states)->stencilWriteMask;
				(yyval.states)->stencilOp 		 = (yyvsp[-1].states)->stencilOp;
				(yyval.states)->stencilOpFront   = (yyvsp[-1].states)->stencilOpFront;
				(yyval.states)->stencilOpBack    = (yyvsp[-1].states)->stencilOpBack;

				PopShaderState();
			}
#line 2058 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 452 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-4].states);

				(yyval.states)->offsetFactor = *(yyvsp[-2].floatval);
				(yyval.states)->offsetUnits  = *(yyvsp[0].floatval);

				delete (yyvsp[-2].floatval);
				delete (yyvsp[0].floatval);
			}
#line 2072 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 462 "SLParserYacc.y" /* yacc.c:1646  */
    {
				g_CurrentProgramCode = (yyvsp[0].strval);
				g_CurrentProgramLine = (yyvsp[-1].number);
				g_CurrentProgramType = kHLSL;
			}
#line 2082 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 468 "SLParserYacc.y" /* yacc.c:1646  */
    {
				g_CurrentProgramCode = (yyvsp[0].strval);
				g_CurrentProgramLine = (yyvsp[-1].number);
				g_CurrentProgramType = kGLSL;
			}
#line 2092 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 474 "SLParserYacc.y" /* yacc.c:1646  */
    {
				g_CurrentProgramCode = (yyvsp[0].strval);
				g_CurrentProgramLine = (yyvsp[-1].number);
				g_CurrentProgramType = kCG;
			}
#line 2102 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 482 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[0].strval));

				delete[] (yyvsp[0].strval);
			}
#line 2113 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 489 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[0].enumval));
			}
#line 2122 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 496 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[0].strval));

				delete[] (yyvsp[0].strval);
			}
#line 2133 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 503 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(1);
			}
#line 2142 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 508 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue(0);
			}
#line 2151 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 515 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.tags) = new std::map<std::string, std::string>();
			}
#line 2159 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 519 "SLParserYacc.y" /* yacc.c:1646  */
    {
				std::string key((yyvsp[-2].strval));
				std::string value((yyvsp[0].strval));

				(yyval.tags) = (yyvsp[-3].tags);
				(*(yyval.tags))[key] = value;

				delete[] (yyvsp[-2].strval);
				delete[] (yyvsp[0].strval);
			}
#line 2174 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 530 "SLParserYacc.y" /* yacc.c:1646  */
    {
				std::string key((yyvsp[-2].strval));
				std::string value((yyvsp[0].strval));

				(yyval.tags) = (yyvsp[-3].tags);
				(*(yyval.tags))[key] = value;

				delete[] (yyvsp[-2].strval);
				delete[] (yyvsp[0].strval);
			}
#line 2189 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 543 "SLParserYacc.y" /* yacc.c:1646  */
    {
				PushShaderState(); 
				(yyval.states) = g_ShaderStateStack.top();
			}
#line 2198 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 548 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilRef = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2209 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 555 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states); 
				(yyval.states)->stencilReadMask = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2220 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 562 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilWriteMask = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2231 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 569 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOp.comp = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2242 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 576 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOp.pass = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2253 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 583 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOp.fail = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2264 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 590 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOp.zFail = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2275 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 597 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOpFront.comp = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2286 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 604 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOpFront.pass = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2297 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 611 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOpFront.fail = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2308 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 618 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOpFront.zFail = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2319 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 625 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOpBack.comp = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2330 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 632 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOpBack.pass = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2341 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 639 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOpBack.fail = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2352 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 646 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.states) = (yyvsp[-2].states);
				(yyval.states)->stencilOpBack.zFail = *(yyvsp[0].floatval);

				delete (yyvsp[0].floatval);
			}
#line 2363 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 655 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[0].strval));

				delete[] (yyvsp[0].strval);
			}
#line 2374 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 662 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue ((yyvsp[0].enumval));
			}
#line 2383 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 669 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[0].number));
			}
#line 2392 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 674 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[0].strval));

				delete[] (yyvsp[0].strval);
			}
#line 2403 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 683 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetRef((yyvsp[0].strval));

				delete[] (yyvsp[0].strval);
			}
#line 2414 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 690 "SLParserYacc.y" /* yacc.c:1646  */
    { 
				(yyval.floatval) = new SLFloat(); 
				(yyval.floatval)->SetValue((yyvsp[0].enumval));
			}
#line 2423 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 697 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[0].strval));

				delete[] (yyvsp[0].strval);
			}
#line 2434 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 704 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[0].enumval));
			}
#line 2443 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 711 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[0].strval));

				delete[] (yyvsp[0].strval);
			}
#line 2454 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 718 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[0].enumval));
			}
#line 2463 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 723 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue(0);
			}
#line 2472 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 730 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetRef((yyvsp[0].strval));

				delete[] (yyvsp[0].strval);
			}
#line 2483 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 737 "SLParserYacc.y" /* yacc.c:1646  */
    {
				(yyval.floatval) = new SLFloat();
				(yyval.floatval)->SetValue((yyvsp[0].enumval));
			}
#line 2492 "SLParserYacc.cpp" /* yacc.c:1646  */
    break;


#line 2496 "SLParserYacc.cpp" /* yacc.c:1646  */
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
#line 743 "SLParserYacc.y" /* yacc.c:1906  */


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
