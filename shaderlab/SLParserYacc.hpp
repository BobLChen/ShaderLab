/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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

#ifndef YY_YY_SLPARSERYACC_HPP_INCLUDED
# define YY_YY_SLPARSERYACC_HPP_INCLUDED
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


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 32 "SLParserYacc.y"

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


/* Line 2058 of yacc.c  */
#line 145 "SLParserYacc.hpp"
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

#endif /* !YY_YY_SLPARSERYACC_HPP_INCLUDED  */
