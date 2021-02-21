/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 38 "SLParserYacc.y" /* yacc.c:1909  */

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

#line 186 "SLParserYacc.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE shaderlablval;

int shaderlabparse (void);

#endif /* !YY_SHADERLAB_SLPARSERYACC_HPP_INCLUDED  */
