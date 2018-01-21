
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 139 "SLParserYacc.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


