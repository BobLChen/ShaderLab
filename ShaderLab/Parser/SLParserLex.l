%{

// flex --nounistd -o SLParserLex.cpp SLParserLex.l

#define ECHO

#include <stdio.h>
#include <map>
#include <vector>
#include <string>

#include "Common/Common.h"
#include "SLParserTypes.h"

int32 shaderlaberror(const char *s);

namespace shaderlab
{
	struct SLFloat;
	struct SLVector4;
	struct SLShader;
	struct SLProperties;
	struct SLShaderState;
	struct SLSubShader;
	struct SLNormalPass;
	struct SLPassBase;
	struct SLProgram;
	struct SLPropTexture;
}

using namespace shaderlab;

#define yylex shaderlablex
#include "SLParserYacc.hpp"

static int32 yyinput();

bool ParseAndEatLine(std::string &outstring);

static char* CreateBracketString(const char* src);

static char* CreateNormalString(const char* src);

inline int32 GetYYLineno() 
{
	return yylineno;
}

static std::string g_LexTempString;

#define YY_NO_UNPUT

%}

%option caseless
%option noyywrap
%option never-interactive

NUMBER		[0-9]
VAR_STRING	[#_a-z][#_a-z0-9]*

%x STATE_STENIL STATE_PROGRAM
%s STATE_ZTEST STATE_COLMASK

%%

Shader					{ 	
							return TOKEN_SHADER; 
						}

Tags					{ 	
							return TOKEN_TAGS; 
						}

LOD						{ 	
							return TOKEN_LOD; 
						}

Category				{ 	
							return TOKEN_CATEGORY; 
						}

SubShader				{ 	
							return TOKEN_SUBSHADER; 
						}

Properties				{ 	
							return TOKEN_PROPERTIES; 
						}

Range					{
							return TOKEN_RANGE; 
						}

2D						{
							shaderlablval.enumval = kTexDim2D;
							return VAL_TEX_DIM;
						}

3D						{
							shaderlablval.enumval = kTexDim3D;
							return VAL_TEX_DIM;
						}

CUBE					{
							shaderlablval.enumval = kTexDimCUBE;
							return VAL_TEX_DIM;
						}

Color					{	
							return TOKEN_COLOR; 
						}

Float					{
							return TOKEN_FLOAT; 
						}

Vector					{ 	
							return TOKEN_VECTOR; 
						}

Int						{ 	
							return TOKEN_FLOAT; 
						}

True|On					{ 	
							return TOKEN_TRUE; 
						}

False|Off				{	
							return TOKEN_FALSE; 
						}

Offset					{	
							return TOKEN_OFFSET; 
						}

NAME					{	
							return TOKEN_NAME; 
						}

ZWrite					{ 	
							return TOKEN_ZWRITE; 
						}

ZTest					{
							BEGIN(STATE_ZTEST); 
							return TOKEN_ZTEST; 
						}

<STATE_ZTEST>{
	Never				{
							BEGIN(INITIAL);
							shaderlablval.enumval = kFuncNever;
							return VAL_COMPARE_MODE;
						}
	Less				{
							BEGIN(INITIAL);
							shaderlablval.enumval = kFuncLess;
							return VAL_COMPARE_MODE;
						}
	Greater				{
							BEGIN(INITIAL); 
							shaderlablval.enumval = kFuncGreater;
							return VAL_COMPARE_MODE;
						}
	LEqual				{
							BEGIN(INITIAL); 
							shaderlablval.enumval = kFuncLEqual;
							return VAL_COMPARE_MODE;
						}
	GEqual				{
							BEGIN(INITIAL); 
							shaderlablval.enumval = kFuncGEqual;
							return VAL_COMPARE_MODE;
						}
	Equal				{
							BEGIN(INITIAL); 
							shaderlablval.enumval = kFuncEqual;
							return VAL_COMPARE_MODE;
						}
	NotEqual			{
							BEGIN(INITIAL); 
							shaderlablval.enumval = kFuncNotEqual;
							return VAL_COMPARE_MODE;
						}
	Always				{
							BEGIN(INITIAL); 
							shaderlablval.enumval = kFuncAlways;
							return VAL_COMPARE_MODE;
						}
}

Stencil					{	
							BEGIN(STATE_STENIL);
							return TOKEN_STENCIL;
						}

<STATE_STENIL>{
	Ref					{
							return TOKEN_REF; 
						}
	ReadMask			{
							return TOKEN_READ_MASK; 
						}
	WriteMask			{
							return TOKEN_WRITE_MASK; 
						}
	Comp				{
							return TOKEN_COMP; 
						}
	Pass				{
							return TOKEN_OP_PASS; 
						}
	Fail				{
							return TOKEN_OP_FAIL; 
						}
	ZFail				{
							return TOKEN_OP_ZFAIL; 
						}
	Greater				{
							shaderlablval.enumval = kFuncGreater;
							return VAL_COMPARE_MODE;
						}
	GEqual				{
							shaderlablval.enumval = kFuncGEqual;
							return VAL_COMPARE_MODE;
						}
	Less				{
							shaderlablval.enumval = kFuncLess;
							return VAL_COMPARE_MODE;
						}
	LEqual				{
							shaderlablval.enumval = kFuncLEqual;
							return VAL_COMPARE_MODE;
						}
	Equal				{
							shaderlablval.enumval = kFuncEqual;
							return VAL_COMPARE_MODE;
						}
	NotEqual			{ 
							shaderlablval.enumval = kFuncNotEqual;
							return VAL_COMPARE_MODE;
						}
	Always				{ 
							shaderlablval.enumval = kFuncAlways;
							return VAL_COMPARE_MODE;
						}
	Never				{
							shaderlablval.enumval = kFuncNever;
							return VAL_COMPARE_MODE;
						}
	Keep				{
							shaderlablval.enumval = kStencilOpKeep;
							return VAL_STENCIL_ACTION;
						}
	Zero				{ 
							shaderlablval.enumval = kStencilOpZero;
							return VAL_STENCIL_ACTION;
						}
	Replace				{ 
							shaderlablval.enumval = kStencilOpReplace;
							return VAL_STENCIL_ACTION;
						}
	IncrSat				{
							shaderlablval.enumval = kStencilOpIncrSat;
							return VAL_STENCIL_ACTION;
						}
	DecrSat				{
							shaderlablval.enumval = kStencilOpDecrSat;
							return VAL_STENCIL_ACTION;
						}
	Invert				{
							shaderlablval.enumval = kStencilOpInvert;
							return VAL_STENCIL_ACTION;
						}
	IncrWrap			{
							shaderlablval.enumval = kStencilOpIncrWrap;
							return VAL_STENCIL_ACTION;
						}
	DecrWrap			{
							shaderlablval.enumval = kStencilOpDecrWrap;
							return VAL_STENCIL_ACTION;
						}
	CompFront			{
							return TOKEN_COMP_FRONT;
						}
	CompBack			{
							return TOKEN_COMP_BACK; 
						}
	PassFront			{
							return TOKEN_OP_PASS_FRONT; 
						}
	FailFront			{
							return TOKEN_OP_FAIL_FRONT; 
						}
	ZFailFront			{
							return TOKEN_OP_ZFAIL_FRONT; 
						}
	PassBack			{
							return TOKEN_OP_PASS_BACK; 
						}
	FailBack			{
							return TOKEN_OP_FAIL_BACK; 
						}
	ZFailBack			{
							return TOKEN_OP_ZFAIL_BACK; 
						}
	\}					{
							BEGIN(INITIAL);
							return '}';
						}
}

ColorMask				{
							BEGIN(STATE_COLMASK); 
							shaderlablval.enumval = 0;
							return TOKEN_COLORMASK;
						}

<STATE_COLMASK>[rgba0]*	{
							BEGIN(INITIAL);
							shaderlablval.enumval = 0;
							char* temp = yytext;
							while (*temp) { 
								switch (*temp++) {
									case 'r': 
									case 'R':
										shaderlablval.enumval |= 8;
										break;
									case 'g': 
									case 'G':
										shaderlablval.enumval |= 4;
										break;
									case 'b': 
									case 'B':
										shaderlablval.enumval |= 2;
										break;
									case 'a':
									case 'A':
										shaderlablval.enumval |= 1;
										break;
									case 0:
										shaderlablval.enumval = 0;
										break;
								} 
							}
							return VAL_RGBA_MASK;
						}
						
AlphaToMask				{ 	
							return TOKEN_ALPHA_TO_MASK; 
						}

Cull					{ 	
							return TOKEN_CULL; 
						}

Front					{ 
							shaderlablval.enumval = kCullFront;
							return VAL_TRIANGLE_FACE;
						}

Back					{
							shaderlablval.enumval = kCullBack;
							return VAL_TRIANGLE_FACE;
						}

FrontAndBack			{
							shaderlablval.enumval = kCullFrontAndBack;
							return VAL_TRIANGLE_FACE;
						}

blend					{
							return TOKEN_BLEND;
						}

Zero					{
							shaderlablval.enumval = kBlendZero;
							return VAL_BLEND_FACTOR;
						}

One						{
							shaderlablval.enumval = kBlendOne;
							return VAL_BLEND_FACTOR;
						}

SrcColor				{
							shaderlablval.enumval = kBlendSrcColor;
							return VAL_BLEND_FACTOR;
						}

SrcAlpha				{
							shaderlablval.enumval = kBlendSrcAlpha;
							return VAL_BLEND_FACTOR;
						}

DstColor				{
							shaderlablval.enumval = kBlendDstColor;
							return VAL_BLEND_FACTOR;
						}

DstAlpha				{
							shaderlablval.enumval = kBlendDstAlpha;
							return VAL_BLEND_FACTOR;
						}

OneMinusSrcColor		{
							shaderlablval.enumval = kBlendOneMinusSrcColor;
							return VAL_BLEND_FACTOR;
						}

OneMinusSrcAlpha		{	
							shaderlablval.enumval = kBlendOneMinusSrcAlpha;
							return VAL_BLEND_FACTOR;
						}

OneMinusDstColor		{
							shaderlablval.enumval = kBlendOneMinusDstColor;
							return VAL_BLEND_FACTOR;
						}

OneMinusDstAlpha		{
							shaderlablval.enumval = kBlendOneMinusDstAlpha;
							return VAL_BLEND_FACTOR;
						}

SrcAlphaSaturate		{
							shaderlablval.enumval = kBlendSrcAlphaSaturate;
							return VAL_BLEND_FACTOR;
						}

blendop					{
							return TOKEN_BLEND_OP;
						}

Add						{
							shaderlablval.enumval = kBlendOpAdd;
							return VAL_BLEND_OP_MODE;
						}

Sub						{
							shaderlablval.enumval = kBlendOpSub;
							return VAL_BLEND_OP_MODE;
						}

RevSub					{
							shaderlablval.enumval = kBlendOpRevSub;
							return VAL_BLEND_OP_MODE;
						}

Min						{
							shaderlablval.enumval = kBlendOpMin;
							return VAL_BLEND_OP_MODE;
						}

Max						{
							shaderlablval.enumval = kBlendOpMax;
							return VAL_BLEND_OP_MODE;
						}

LogicalClear			{
							shaderlablval.enumval = kBlendOpLogicalClear;
							return VAL_BLEND_OP_MODE;
						}

LogicalSet				{
							shaderlablval.enumval = kBlendOpLogicalSet;
							return VAL_BLEND_OP_MODE;
						}

LogicalCopy				{
							shaderlablval.enumval = kBlendOpLogicalCopy;
							return VAL_BLEND_OP_MODE;
						}

LogicalCopyInverted		{
							shaderlablval.enumval = kBlendOpLogicalCopyInverted;
							return VAL_BLEND_OP_MODE;
						}

LogicalNoop				{
							shaderlablval.enumval = kBlendOpLogicalNoop;
							return VAL_BLEND_OP_MODE;
						}

LogicalInvert			{
							shaderlablval.enumval = kBlendOpLogicalInvert;
							return VAL_BLEND_OP_MODE;
						}

LogicalAnd				{
							shaderlablval.enumval = kBlendOpLogicalAnd;
							return VAL_BLEND_OP_MODE;
						}

LogicalNand				{
							shaderlablval.enumval = kBlendOpLogicalNand;
							return VAL_BLEND_OP_MODE;
						}

LogicalOr				{
							shaderlablval.enumval = kBlendOpLogicalOr;
							return VAL_BLEND_OP_MODE;
						}

LogicalNor				{
							shaderlablval.enumval = kBlendOpLogicalNor;
							return VAL_BLEND_OP_MODE;
						}

LogicalXor				{
							shaderlablval.enumval = kBlendOpLogicalXor;
							return VAL_BLEND_OP_MODE;
						}

LogicalEquiv			{
							shaderlablval.enumval = kBlendOpLogicalEquiv;
							return VAL_BLEND_OP_MODE;
						}

LogicalAndReverse		{
							shaderlablval.enumval = kBlendOpLogicalAndReverse;
							return VAL_BLEND_OP_MODE;
						}

LogicalAndInverted		{
							shaderlablval.enumval = kBlendOpLogicalAndInverted;
							return VAL_BLEND_OP_MODE;
						}

LogicalOrReverse		{
							shaderlablval.enumval = kBlendOpLogicalOrReverse;
							return VAL_BLEND_OP_MODE;
						}

LogicalOrInverted		{
							shaderlablval.enumval = kBlendOpLogicalOrInverted;
							return VAL_BLEND_OP_MODE;
						}

PASS					{
							BEGIN(INITIAL);
							return TOKEN_PASS;
						}

USEPASS					{
							BEGIN(INITIAL);
							return TOKEN_USEPASS;
						}

GLSLPROGRAM				{
							BEGIN(STATE_PROGRAM);
							g_LexTempString.clear();
							shaderlablval.number = yylineno;
							return VAL_GLSLPROGRAM;
						}

HLSLPROGRAM				{
							BEGIN(STATE_PROGRAM);
							g_LexTempString.clear();
							shaderlablval.number = yylineno;
							return VAL_HLSLPROGRAM;
						}

CGPROGRAM				{
							BEGIN(STATE_PROGRAM);
							g_LexTempString.clear();
							shaderlablval.number = yylineno;
							return VAL_CGPROGRAM;
						}						

<STATE_PROGRAM>{

ENDHLSL|ENDCG|ENDGLSL	{
							BEGIN(INITIAL);
							shaderlablval.strval = g_LexTempString.c_str();
							return VAL_PROGRAM_SOURCE;
						}

[ \t]*					{
							char* temp = yytext;
							while (*temp)
							{
								g_LexTempString.push_back(*temp);
								temp++;
							}
 						}

"\/\/"[^\n\r]*			{
							char* temp = yytext;
							while (*temp)
							{
								g_LexTempString.push_back(*temp);
								temp++;
							}
						}

\r\n					{ 	
							char* temp = yytext;
							while (*temp)
							{
								g_LexTempString.push_back(*temp);
								temp++;
							}
							yylineno++; 
						}

\n\r					{ 	
							char* temp = yytext;
							while (*temp)
							{
								g_LexTempString.push_back(*temp);
								temp++;
							}
							yylineno++; 
						}

\r						{ 	
							char* temp = yytext;
							while (*temp)
							{
								g_LexTempString.push_back(*temp);
								temp++;
							}
							yylineno++; 
						}

\n						{	
							char* temp = yytext;
							while (*temp)
							{
								g_LexTempString.push_back(*temp);
								temp++;
							}
							yylineno++; 
						}

.						{
							char* temp = yytext;
							while (*temp)
							{
								g_LexTempString.push_back(*temp);
								temp++;
							}
						}

}

fallback				{ 	
							return TOKEN_FALLBACK; 
						}

<INITIAL,STATE_COLMASK,STATE_ZTEST,STATE_STENIL>{

\[{VAR_STRING}\]				{
									shaderlablval.strval = CreateBracketString(yytext);
									return VAL_BRACKET_ID;
								}

-?"."{NUMBER}+ 					{
									shaderlablval.number = atof(yytext);
									return VAL_NUMBER;
								}

-?{NUMBER}+("."({NUMBER}*))? 	{
									shaderlablval.number = atof(yytext);
									return VAL_NUMBER;
								}
								
{VAR_STRING}					{
									shaderlablval.strval = CreateNormalString(yytext);
									return VAL_ID;
								}

\"[^\"]*\"						{
									shaderlablval.strval = CreateBracketString(yytext);
									const char *temp = shaderlablval.strval;
									while (*temp) 
									{
										char c = *temp;
										if (c == '\n') 
										{
											yylineno++;
										}
										temp++;
									}
									return VAL_STRING;
								}

\}								{
									BEGIN(INITIAL);
									return *yytext;
								}

[ \t]*							{

 								}

"\/\/"[^\n\r]*					{

								}

\r\n							{ 	
									yylineno++; 
								}

\n\r							{ 	
									yylineno++; 
								}

\r								{ 	
									yylineno++; 
								}

\n								{	
									yylineno++; 
								}

"/*"        					{
									int32 c;
									int32 depth = 1;
									while (true) 
									{
										while ((c = yyinput()) != '*' && c != '/' && c != EOF && c != '\0') 
										{
											if (c == '\r') 
											{
												yylineno++;
												c = yyinput();
												if (c == '\r') 
												{
													++yylineno;
												}
											} 
											else if (c == '\n') 
											{
												yylineno++;
											}
										}
										if (c == EOF || c == '\0') 
										{
											shaderlaberror("Lex parse block comment end with EOF.");
											yyterminate();
											break;
										}
										if (c == '/') 
										{
											c = yyinput();
											if (c == '*') 
											{
												depth++;
											}
										}
										if (c == '*') 
										{
											while ((c = yyinput()) == '*') 
											{
												;
											}
											if (c == '/') 
											{
												depth--;
												if (depth == 0) 
												{
													break;
												}
											}
										}
									}
								}

.								{ 	
									return *yytext; 
								}

}

%%

inline bool IsEndChar(int32 c) 
{
	if (c == EOF || c == '\0' || c == '\r' || c == '\n') 
	{
		return true;
	} 
	else {
		return false;
	}
}

void InitLex(const char *data, int32 dataSize) 
{
	g_LexTempString.reserve(64 * 1024);
	YY_BUFFER_STATE b = yy_scan_bytes(data, dataSize);
	yy_switch_to_buffer(b);
	BEGIN(INITIAL);
}

void FreeLex() 
{
	g_LexTempString.clear();
	yy_delete_buffer(YY_CURRENT_BUFFER);
}

bool ParseAndEatLine(std::string &outstring)
{
	int32 c = 0;
	while ((c = yyinput()) && (c==' ' || c=='\t')) 
	{
        ;
    }
	if (IsEndChar(c)) 
	{
		return false;
	}
	std::string temp;
	temp += c;
	while ((c = yyinput()) && !IsEndChar(c)) 
	{
        temp += c;
    }
	if (c == EOF || c == '\0') 
	{
		return false;
	}
	outstring = temp;
	return true;
}

static char* CreateBracketString(const char *src) 
{
	int32 size = strlen(src);
	char *buffer = new char[size - 1];
	memcpy(buffer, src + 1, size - 2);
	buffer[size - 2] = '\0';
	return buffer;
}

static char* CreateNormalString(const char *src) 
{
	int32 size = strlen(src) + 1;
	char *buffer = new char[size];
	memcpy(buffer, src, size);
	buffer[size - 1] = '\0';
	return buffer;
}