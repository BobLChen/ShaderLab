%{

// flex --nounistd -o SLParserLex.cpp SLParserLex.lpp

#define ECHO 

#include <map>
#include <vector>
#include <string>
#include "SLParserTypes.h"

int yyerror (const char *s);

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
	struct SLGrabPass;
	struct SLProgram;
	struct SLSubProgram;
	struct SLPropTexture;
}

using namespace shaderlab;

#include "SLParserYacc.hpp"

void InitLex(const char *data, size_t dataSize);
void FreeLex();
int  GetYYLineno();
bool ParseAndEatLine(std::string &outstring);

static int   yyinput (void);
static char* CreateBracketString(const char *src);
static char* CreateNormalString(const char *src);

#define YY_NO_UNPUT

%}

%option caseless
%option noyywrap
%option never-interactive

NUMBER		[0-9]
VAR_STRING	[#_a-z][#_a-z0-9]*

%x STATE_FOG STATE_STENIL
%s STATE_CHANNELS STATE_ZTEST STATE_COLMASK

%%

Shader					{ 	return TOKEN_SHADER; }
Tags					{ 	return TOKEN_TAGS; }
LOD						{ 	return TOKEN_LOD; }
Category				{ 	return TOKEN_CATEGORY; }
SubShader				{ 	return TOKEN_SUBSHADER; }
Properties				{ 	return TOKEN_PROPERTIES; }
Range					{ 	return TOKEN_RANGE; }
GpuProgramID			{	return TOKEN_GPU_PROGRAM_ID; }
2D						{
							yylval.enumval = kTexDim2D;
							return VAL_TEX_DIM;
						}
3D						{
							yylval.enumval = kTexDim3D;
							return VAL_TEX_DIM;
						}
CUBE					{
							yylval.enumval = kTexDimCUBE;
							return VAL_TEX_DIM;
						}
RECT					{
							yylval.enumval = kTexDim2D;
							return VAL_TEX_DIM;
						}

Bind					{
							// https://docs.unity3d.com/Manual/SL-ShaderSemantics.html
							BEGIN(STATE_CHANNELS);
							return TOKEN_BIND;
						}
<STATE_CHANNELS>{
{VAR_STRING}			{
							BEGIN(INITIAL);
							yylval.strval = CreateNormalString(yytext);
							return VAL_ID;
						}
}

Color					{	
							// After bind because of Bind "color" Color
							return TOKEN_COLOR; 
						}

SETTEXTURE				{
							return TOKEN_SETTEXTURE;
						}
Float					{ 	return TOKEN_FLOAT; }
Vector					{ 	return TOKEN_VECTOR; }
Int						{ 	return TOKEN_FLOAT; }
MATRIX					{ 	return TOKEN_MATRIX; }
KEYWORDS				{ 	return TOKEN_KEYWORDS; }
CONSTBUFFER				{ 	return TOKEN_CONSTBUFFER; }
BINDCB					{ 	return TOKEN_BINDCB; }
SETBUFFER				{ 	return TOKEN_SETBUFFER; }
True|On					{ 	return TOKEN_TRUE; }
False|Off				{	return TOKEN_FALSE; }
Offset					{	return TOKEN_OFFSET; }
NAME					{	return TOKEN_NAME; }
ZWrite					{ 	return TOKEN_ZWRITE; }
ZTest					{
							// https://docs.unity3d.com/Manual/SL-CullAndDepth.html
							BEGIN(STATE_ZTEST); 
							return TOKEN_ZTEST; 
						}
<STATE_ZTEST>{
	Never				{
							BEGIN(INITIAL);
							yylval.enumval = kFuncNever;
							return VAL_COMPARE_MODE;
						}
	Less				{
							BEGIN(INITIAL);
							yylval.enumval = kFuncLess;
							return VAL_COMPARE_MODE;
						}
	Greater				{
							BEGIN(INITIAL); 
							yylval.enumval = kFuncGreater;	
							return VAL_COMPARE_MODE;
						}
	LEqual				{
							BEGIN(INITIAL); 
							yylval.enumval = kFuncLEqual;	
							return VAL_COMPARE_MODE;
						}
	GEqual				{
							BEGIN(INITIAL); 
							yylval.enumval = kFuncGEqual;	
							return VAL_COMPARE_MODE;
						}
	Equal				{ 
							yylval.enumval = kFuncEqual;
							BEGIN(INITIAL); 
							return VAL_COMPARE_MODE;
						}
	NotEqual			{
							BEGIN(INITIAL); 
							yylval.enumval = kFuncNotEqual;
							return VAL_COMPARE_MODE;
						}
	Always				{
							BEGIN(INITIAL); 
							yylval.enumval = kFuncAlways;	
							return VAL_COMPARE_MODE;
						}
}

Fog						{
							// https://docs.unity3d.com/Manual/SL-Fog.html
							BEGIN(STATE_FOG); 
							return TOKEN_FOG; 
						}
<STATE_FOG>{
	Color				{ 	return TOKEN_COLOR; }
	Mode				{ 	return TOKEN_MODE; }
	Density				{ 	return TOKEN_DENSITY; }
	Range				{ 	return TOKEN_RANGE; }
	Off					{
							yylval.enumval = kFogDisabled; 
							return VAL_FOG_MODE;
						}
	Linear				{
							yylval.enumval = kFogLinear;
							return VAL_FOG_MODE;
						}
	Exp					{	
							yylval.enumval = kFogExp;
							return VAL_FOG_MODE; 
						}
	Exp2				{
							yylval.enumval = kFogExp2;
							return VAL_FOG_MODE; 
						}
	Global				{
							yylval.enumval = kFogUnknown;
							return VAL_FOG_MODE;
						}
	\}					{
							BEGIN(INITIAL); 
							return '}';
						}
}

Stencil					{	// https://docs.unity3d.com/Manual/SL-Stencil.html '
							BEGIN(STATE_STENIL);
							return TOKEN_STENCIL;
						}
<STATE_STENIL>{
	Ref					{ return TOKEN_REF; }
	ReadMask			{ return TOKEN_READ_MASK; }
	WriteMask			{ return TOKEN_WRITE_MASK; }
	Comp				{ return TOKEN_COMP; }
	Pass				{ return TOKEN_OP_PASS; }
	Fail				{ return TOKEN_OP_FAIL; }
	ZFail				{ return TOKEN_OP_ZFAIL; }

	Greater				{
							yylval.enumval = kFuncGreater;
							return VAL_COMPARE_MODE;
						}
	GEqual				{
							yylval.enumval = kFuncGEqual;
							return VAL_COMPARE_MODE;
						}
	Less				{
							yylval.enumval = kFuncLess;
							return VAL_COMPARE_MODE;
						}
	LEqual				{
							yylval.enumval = kFuncLEqual;
							return VAL_COMPARE_MODE;
						}
	Equal				{
							yylval.enumval = kFuncEqual;
							return VAL_COMPARE_MODE;
						}
	NotEqual			{ 
							yylval.enumval = kFuncNotEqual;
							return VAL_COMPARE_MODE;
						}
	Always				{ 
							yylval.enumval = kFuncAlways;		
							return VAL_COMPARE_MODE;
						}
	Never				{
							yylval.enumval = kFuncNever;
							return VAL_COMPARE_MODE;
						}
	
	Keep				{
							yylval.enumval = kStencilOpKeep;
							return VAL_STENCIL_ACTION;
						}
	Zero				{ 
							yylval.enumval = kStencilOpZero;
							return VAL_STENCIL_ACTION;
						}
	Replace				{ 
							yylval.enumval = kStencilOpReplace;
							return VAL_STENCIL_ACTION;
						}
	IncrSat				{
							yylval.enumval = kStencilOpIncrSat;
							return VAL_STENCIL_ACTION;
						}
	DecrSat				{
							yylval.enumval = kStencilOpDecrSat;
							return VAL_STENCIL_ACTION;
						}
	Invert				{
							yylval.enumval = kStencilOpInvert;	
							return VAL_STENCIL_ACTION;
						}
	IncrWrap			{
							yylval.enumval = kStencilOpIncrWrap;
							return VAL_STENCIL_ACTION;
						}
	DecrWrap			{
							yylval.enumval = kStencilOpDecrWrap;
							return VAL_STENCIL_ACTION;
						}
	CompFront			{ 	return TOKEN_COMP_FRONT; }
	CompBack			{ 	return TOKEN_COMP_BACK; }
	PassFront			{ 	return TOKEN_OP_PASS_FRONT; }
	FailFront			{ 	return TOKEN_OP_FAIL_FRONT; }
	ZFailFront			{ 	return TOKEN_OP_ZFAIL_FRONT; }
	PassBack			{ 	return TOKEN_OP_PASS_BACK; }
	FailBack			{ 	return TOKEN_OP_FAIL_BACK; }
	ZFailBack			{ 	return TOKEN_OP_ZFAIL_BACK; }
	\}					{
							BEGIN(INITIAL);
							return '}';
						}
}

ColorMask				{
							// https://docs.unity3d.com/Manual/SL-Pass.html '
							BEGIN(STATE_COLMASK); 
							yylval.enumval = 0;
							return TOKEN_COLORMASK;
						}
<STATE_COLMASK>[rgba0]*	{
							BEGIN(INITIAL); 
							yylval.enumval = 0; 
							char *temp = yytext;
							while (*temp) { 
								switch (*temp++) {
									case 'r': 
									case 'R':
										yylval.enumval |= 8;
										break;
									case 'g': 
									case 'G':
										yylval.enumval |= 4;
										break;
									case 'b': 
									case 'B':
										yylval.enumval |= 2;
										break;
									case 'a':
									case 'A':
										yylval.enumval |= 1;
										break;
									case 0:
										yylval.enumval = 0;
										break;
								} 
							}
							return VAL_RGBA_MASK;
						}
						
AlphaToMask				{ 	return TOKEN_ALPHA_TO_MASK; }
Cull					{ 	return TOKEN_CULL; }
Front					{ 
							yylval.enumval = kCullFront; 
							return VAL_TRIANGLE_FACE;
						}
Back					{
							yylval.enumval = kCullBack; 
							return VAL_TRIANGLE_FACE;
						}
FrontAndBack			{
							yylval.enumval = kCullFrontAndBack;
							return VAL_TRIANGLE_FACE;
						}
blend					{
							// https://docs.unity3d.com/Manual/SL-Blend.html
							return TOKEN_BLEND;
						}
Zero					{
							yylval.enumval = kBlendZero; 
							return VAL_BLEND_FACTOR;
						}
One						{
							yylval.enumval = kBlendOne;
							return VAL_BLEND_FACTOR;
						}
SrcColor				{
							yylval.enumval = kBlendSrcColor;
							return VAL_BLEND_FACTOR;
						}
SrcAlpha				{
							yylval.enumval = kBlendSrcAlpha;
							return VAL_BLEND_FACTOR;
						}
DstColor				{
							yylval.enumval = kBlendDstColor;
							return VAL_BLEND_FACTOR;
						}
DstAlpha				{
							yylval.enumval = kBlendDstAlpha;
							return VAL_BLEND_FACTOR;
						}
OneMinusSrcColor		{
							yylval.enumval = kBlendOneMinusSrcColor;
							return VAL_BLEND_FACTOR;
						}
OneMinusSrcAlpha		{	yylval.enumval = kBlendOneMinusSrcAlpha;
							return VAL_BLEND_FACTOR;
						}
OneMinusDstColor		{
							yylval.enumval = kBlendOneMinusDstColor; 
							return VAL_BLEND_FACTOR;
						}
OneMinusDstAlpha		{
							yylval.enumval = kBlendOneMinusDstAlpha;
							return VAL_BLEND_FACTOR;
						}
SrcAlphaSaturate		{
							yylval.enumval = kBlendSrcAlphaSaturate;
							return VAL_BLEND_FACTOR;
						}
blendop					{
							// https://docs.unity3d.com/Manual/SL-Blend.html
							return TOKEN_BLEND_OP;
						}
Add						{
							yylval.enumval = kBlendOpAdd;
							return VAL_BLEND_OP_MODE;
						}
Sub						{
							yylval.enumval = kBlendOpSub;
							return VAL_BLEND_OP_MODE;
						}
RevSub					{
							yylval.enumval = kBlendOpRevSub;
							return VAL_BLEND_OP_MODE;
						}
Min						{
							yylval.enumval = kBlendOpMin;
							return VAL_BLEND_OP_MODE;
						}
Max						{
							yylval.enumval = kBlendOpMax;
							return VAL_BLEND_OP_MODE;
						}
LogicalClear			{
							yylval.enumval = kBlendOpLogicalClear;
							return VAL_BLEND_OP_MODE;
						}
LogicalSet				{
							yylval.enumval = kBlendOpLogicalSet;
							return VAL_BLEND_OP_MODE;
						}
LogicalCopy				{
							yylval.enumval = kBlendOpLogicalCopy;
							return VAL_BLEND_OP_MODE;
						}
LogicalCopyInverted		{
							yylval.enumval = kBlendOpLogicalCopyInverted;
							return VAL_BLEND_OP_MODE;
						}
LogicalNoop				{
							yylval.enumval = kBlendOpLogicalNoop;
							return VAL_BLEND_OP_MODE;
						}
LogicalInvert			{
							yylval.enumval = kBlendOpLogicalInvert;
							return VAL_BLEND_OP_MODE;
						}
LogicalAnd				{
							yylval.enumval = kBlendOpLogicalAnd;
							return VAL_BLEND_OP_MODE;
						}
LogicalNand				{
							yylval.enumval = kBlendOpLogicalNand;
							return VAL_BLEND_OP_MODE;
						}
LogicalOr				{
							yylval.enumval = kBlendOpLogicalOr;
							return VAL_BLEND_OP_MODE;
						}
LogicalNor				{
							yylval.enumval = kBlendOpLogicalNor;
							return VAL_BLEND_OP_MODE;
						}
LogicalXor				{
							yylval.enumval = kBlendOpLogicalXor;
							return VAL_BLEND_OP_MODE;
						}
LogicalEquiv			{
							yylval.enumval = kBlendOpLogicalEquiv;
							return VAL_BLEND_OP_MODE;
						}
LogicalAndReverse		{
							yylval.enumval = kBlendOpLogicalAndReverse;
							return VAL_BLEND_OP_MODE;
						}
LogicalAndInverted		{
							yylval.enumval = kBlendOpLogicalAndInverted;
							return VAL_BLEND_OP_MODE;
						}
LogicalOrReverse		{
							yylval.enumval = kBlendOpLogicalOrReverse;
							return VAL_BLEND_OP_MODE;
						}
LogicalOrInverted		{
							yylval.enumval = kBlendOpLogicalOrInverted;
							return VAL_BLEND_OP_MODE;
						}

PASS					{
							BEGIN(INITIAL);
							return TOKEN_PASS;
						}
GRABPASS				{
							BEGIN(INITIAL);
							return TOKEN_GRABPASS;
						}
USEPASS					{
							BEGIN(INITIAL);
							return TOKEN_USEPASS;
						}
PROGRAM					{
							BEGIN(INITIAL);
							return TOKEN_PROGRAM;
						}

SUBPROGRAM				{
							BEGIN(INITIAL);
							return TOKEN_SUBPROGRAM;
						}

fallback				{ 	return TOKEN_FALLBACK; }

<INITIAL,STATE_FOG,STATE_CHANNELS,STATE_COLMASK,STATE_ZTEST,STATE_STENIL>{

\[{VAR_STRING}\]				{
									yylval.strval = CreateBracketString(yytext);
									return VAL_BRACKET_ID;
								}
-?"."{NUMBER}+ 					{
									yylval.number = atof(yytext);
									return VAL_NUMBER;
								}
-?{NUMBER}+("."({NUMBER}*))? 	{
									yylval.number = atof(yytext);
									return VAL_NUMBER;
								}
#LINE							{
									std::string numstr;
									if (ParseAndEatLine(numstr)) {
										// TODO:get line number do something
									} else {
										yyerror("Lex parse #LINE end witch EOF.");
										yyterminate();
									}
								}
#warning 						{
									std::string warningstr;
									if (ParseAndEatLine(warningstr)) {
										// TODO:add warning
									} else {
										yyerror("Lex parse #warning end witch EOF.");
										yyterminate();
									}
								}
#error 							{
									std::string errorstr;
									if (ParseAndEatLine(errorstr)) {
										// TODO:add error
									} else {
										yyerror("Lex parse #warning end witch EOF.");
										yyterminate();
									}
								}
{VAR_STRING}					{
									yylval.strval = CreateNormalString(yytext);
									return VAL_ID;
								}
\"[^\"]*\"						{
									yylval.strval = CreateBracketString(yytext);
									const char *temp = yylval.strval;
									while (*temp) {
										char c = *temp;
										if (c == '\n') {
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
[ \t]*							{  }
"\/\/"[^\n\r]*	
\r\n							{ 	yylineno++; }
\n\r							{ 	yylineno++; }
\r								{ 	yylineno++; }
\n								{	yylineno++; }
"/*"        					{
									int c;
									int depth = 1;
									while (true) {
										while ((c = yyinput()) != '*' && c != '/' && c != EOF && c != '\0') {
											if (c == '\r') {
												yylineno++;
												c = yyinput();
												if (c == '\r') {
													++yylineno;
												}
											} else if (c == '\n') {
												yylineno++;
											}
										}
										if (c == EOF || c == '\0') {
											yyerror("Lex parse block comment end with EOF.");
											yyterminate();
											break;
										}
										if (c == '/') {
											c = yyinput();
											if (c == '*') {
												depth++;
											}
										}
										if (c == '*') {
											while ((c = yyinput()) == '*') {
												;
											}
											if (c == '/') {
												depth--;
												if (depth == 0) {
													break;
												}
											}
										}
									}
									
								}
.								{ 	return *yytext; }
}

%%

YY_BUFFER_STATE b;

void InitLex(const char *data, size_t dataSize) {
	b = yy_scan_bytes(data, dataSize);
	yy_switch_to_buffer(b);
	BEGIN(INITIAL);
}

void FreeLex() {
	yy_delete_buffer(YY_CURRENT_BUFFER);
}

int GetYYLineno() {
	return yylineno;
}

static char *CreateBracketString(const char *src) {
	int size = strlen(src);
	char *buffer = new char[size - 1];
	memcpy(buffer, src + 1, size - 2);
	buffer[size - 2] = '\0';
	return buffer;
}

static char *CreateNormalString(const char *src) {
	int size = strlen(src) + 1;
	char *buffer = new char[size];
	memcpy(buffer, src, size);
	buffer[size - 1] = '\0';
	return buffer;
}

inline bool IsEndChar(int c) {
	if (c == EOF || c == '\0' || c == '\r' || c == '\n') {
		return true;
	} else {
		return false;
	}
}

bool ParseAndEatLine(std::string &outstring)
{
	int c = 0;
	while ((c = yyinput()) && (c==' ' || c=='\t')) {
        ;
    }
	if (IsEndChar(c)) {
		return false;
	}
	std::string temp;
	temp += c;
	while ((c = yyinput()) && !IsEndChar(c)) {
        temp += c;
    }
	if (c == EOF || c == '\0') {
		return false;
	}
	outstring = temp;
	return true;
}