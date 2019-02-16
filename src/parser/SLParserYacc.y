%{

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

extern int yylineno;
extern char* yytext;

int yyerror(const char *s);
int yylex();

static void PushShaderState();
static void PopShaderState();

#define YYDEBUG 0

%}

%union {
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
};

%token TOKEN_SHADER TOKEN_PASS TOKEN_USEPASS TOKEN_GRABPASS TOKEN_SUBSHADER
%token TOKEN_FOG TOKEN_DENSITY TOKEN_MODE TOKEN_CATEGORY TOKEN_FALLBACK TOKEN_LOD
%token TOKEN_COLOR TOKEN_ALPHA_TO_MASK TOKEN_TRUE TOKEN_FALSE TOKEN_GPU_PROGRAM_ID
%token TOKEN_SETTEXTURE TOKEN_CONSTBUFFER TOKEN_BINDCB TOKEN_SETBUFFER TOKEN_MATRIX TOKEN_FLOAT TOKEN_RANGE TOKEN_VECTOR
%token TOKEN_PROPERTIES TOKEN_PROGRAM TOKEN_SUBPROGRAM TOKEN_BIND TOKEN_TAGS TOKEN_NAME TOKEN_KEYWORDS
%token TOKEN_ZWRITE TOKEN_ZTEST TOKEN_CULL TOKEN_BLEND TOKEN_BLEND_OP TOKEN_COLORMASK TOKEN_OFFSET
%token TOKEN_STENCIL TOKEN_REF TOKEN_READ_MASK TOKEN_WRITE_MASK TOKEN_COMP TOKEN_OP_PASS TOKEN_OP_FAIL TOKEN_OP_ZFAIL
%token TOKEN_COMP_BACK TOKEN_OP_PASS_BACK TOKEN_OP_FAIL_BACK TOKEN_OP_ZFAIL_BACK
%token TOKEN_COMP_FRONT TOKEN_OP_PASS_FRONT TOKEN_OP_FAIL_FRONT TOKEN_OP_ZFAIL_FRONT

%token <number> VAL_NUMBER
%token <strval> VAL_ID VAL_STRING VAL_BRACKET_ID
%token <enumval> VAL_TRIANGLE_FACE VAL_COMPARE_MODE VAL_RGBA_MASK VAL_FOG_MODE
%token <enumval> VAL_TEX_DIM VAL_BLEND_FACTOR VAL_BLEND_OP_MODE VAL_STENCIL_ACTION

%type <floatval> numval maskval blendval funcval blendopval stencilaction boolean cullval
%type <vector4> vector4 color
%type <shader> shader
%type <subshader> subshader
%type <properties> properties propitems
%type <tags> tags
%type <states> states fogblock stencilblock
%type <program> subprograms
%type <subprogram> subprogram
%type <pass> pass
%type <grabpass> grabpass
%type <passes> passes
%type <strings> stringlist propflags

%%

shader: 	TOKEN_SHADER VAL_STRING
			{
				_currentShader->shaderName = $2;
				delete[] $2;
			}
			'{' properties 
			{
				if ($5) {
					_currentShader->properties = *$5;
					delete $5;
				}
			}
			shaderBlocks '}'
			{
				
			}
			;
			
properties:
			{
				$$ = nullptr;
			}
			| TOKEN_PROPERTIES '{' propitems '}'		
			{ 
				$$ = $3; 
			}
			;
			
propitems:	
			{
				$$ = new SLProperties(); 
			}
			| propitems propflags VAL_ID '(' VAL_STRING ',' TOKEN_FLOAT ')' '=' VAL_NUMBER
			{ 
				$$ = $1; 
				$$->AddFloatProperty($3, $5, *$2, $10);
				delete[] $3;
				delete[] $5;
				delete $2; 
			}
			| propitems propflags VAL_ID '(' VAL_STRING ',' TOKEN_RANGE '(' VAL_NUMBER ',' VAL_NUMBER ')' ')' '=' VAL_NUMBER
			{ 
				$$ = $1; 
				$$->AddRangeProperty($3, $5, *$2, $15, $9, $11); 
				delete[] $3;
				delete[] $5;
			}
			| propitems propflags VAL_ID '(' VAL_STRING ',' TOKEN_VECTOR ')' '=' vector4
			{ 
				$$ = $1; 
				$$->AddVectorProperty($3, $5, *$2, *$10);
				delete[] $3;
				delete[] $5;
				delete $2;
				delete $10; 
			}
			| propitems propflags VAL_ID '(' VAL_STRING ',' TOKEN_COLOR ')' '=' vector4
			{ 
				$$ = $1;
				$$->AddColorProperty($3, $5, *$2, *$10);
				delete[] $3;
				delete[] $5;
				delete $2;
				delete $10;
			}
			| propitems propflags VAL_ID '(' VAL_STRING ',' VAL_TEX_DIM ')' '=' VAL_STRING
			{
				$$ = $1; 
				SLPropTexture *tex = new SLPropTexture();
				tex->name = $10;
				tex->dimension = (TextureDimension)$7;
				$$->AddTextureProperty($3, $5, *$2, *tex);
				delete $2;
				delete tex;
				delete[] $3;
				delete[] $5;
				delete[] $10;
			}
			| propitems propflags VAL_ID '(' VAL_STRING ',' VAL_TEX_DIM ')' '=' VAL_STRING '{' '}'
			{
				$$ = $1;
				SLPropTexture *tex = new SLPropTexture();
				tex->name = $10;
				tex->dimension = (TextureDimension)$7;
				$$->AddTextureProperty($3, $5, *$2, *tex);
				delete $2;
				delete tex;
				delete[] $3;
				delete[] $5;
				delete[] $10;
			}
			;
			
propflags:	
			{ 
				$$ = new std::vector<std::string>(); 
			}
			| propflags VAL_BRACKET_ID
			{
				$$ = $1;
				$$->emplace_back($2);
				delete[] $2;
			}
			;

vector4: '(' VAL_NUMBER ',' VAL_NUMBER ',' VAL_NUMBER ',' VAL_NUMBER ')'
			{
				$$ = new SLVector4();
				$$->SetValue($2, $4, $6, $8);
			}
		 	| '(' VAL_NUMBER ',' VAL_NUMBER ',' VAL_NUMBER ')'
			{
				$$ = new SLVector4();
				$$->SetValue($2, $4, $6, 1.0f);
			}
			;
			
shaderBlocks:
			{
				
			}
			| shaderBlocks category			
			{
				
			}
			| shaderBlocks subshader		
			{ 
				if ($2) {
					_currentShader->subShaders.push_back($2); 
				}
			}
			| shaderBlocks fallback
			{

			}
			;
category: 	TOKEN_CATEGORY '{'	
			{ 
				PushShaderState (); 
			}
			states shaderBlocks '}'		
			{ 
				PopShaderState (); 
			}
			;

subshader: 	TOKEN_SUBSHADER '{'		
			{ 
				PushShaderState (); 
			}
			passes '}'				
			{
				$$ = new SLSubShader();
				const SLShaderState* state = _shaderStateStack.top();
				$$->tags = state->tags;
				$$->lod  = state->lod;
				$$->SetPasses($4);
				delete $4;
				PopShaderState ();
			}
			;
fallback: 	TOKEN_FALLBACK VAL_STRING			
			{ 
				_currentShader->fallbackName = $2;
				delete[] $2;
			}
			| TOKEN_FALLBACK VAL_STRING ',' VAL_NUMBER	
			{
				_currentShader->fallbackName = $2;
				delete[] $2;
			}
			| TOKEN_FALLBACK TOKEN_FALSE					
			{
				_currentShader->fallbackName = "None";
			}
			;
			
passes: 	states pass					
			{ 
				$$ = new std::vector<SLPassBase*>; 
				$$->push_back($2); 
			}
			| passes states pass			
			{ 
				$$ = $1;  
				$$->push_back($3); 
			}
			;
	
pass:		TOKEN_PASS '{'							
			{ 
				PushShaderState(); 
				_yaccCurrentPrograms.clear();
			}
			states '}'					
			{	
				SLNormalPass *pp = new SLNormalPass(*_shaderStateStack.top());
				$$ = pp;
				for (int i = 0; i < _yaccCurrentPrograms.size(); ++i) {
					pp->programs.push_back(_yaccCurrentPrograms[i]);
				}
				_yaccCurrentPrograms.clear();
				PopShaderState();
			}
			| TOKEN_GRABPASS '{' grabpass '}'		
			{ 
				$$ = $3; 
			}
			| TOKEN_USEPASS VAL_STRING				
			{ 
				$$ = new SLUsePass($2); 
				delete[] $2;
			}
			;
			
grabpass:									
			{ 
				$$ = new SLGrabPass(); 
			}
			| grabpass TOKEN_TAGS '{' tags '}'		
			{ 
				$$ = $1; 
				$$->AddTags(*$4); 
				delete $4; 
			}
			| grabpass TOKEN_NAME VAL_STRING			
			{ 
				$$ = $1; 
				$$->name = std::string($3); 
				delete[] $3;
			}
			| grabpass VAL_STRING					
			{ 
				$$ = $1; 
				$$->textureName = std::string($2); 
				delete[] $2;
			}
			;
			
states:		
			{
				$$ = _shaderStateStack.top(); 
			}
			| states TOKEN_LOD VAL_NUMBER					
			{ 
				$$ = $1; 
				$$->lod = int($3); 
			}
			| states TOKEN_NAME VAL_STRING					
			{ 
				$$ = $1; 
				$$->name = $3; 
				delete[] $3;
			}
			| states TOKEN_TAGS '{' tags '}'					
			{ 
				$$ = $1; 
				$$->AddTags(*$4);
				delete $4;
			}
			| states TOKEN_FOG '{' fogblock '}'				
			{ 
				$$ = $1;
				$$->fogColor   = $4->fogColor;
				$$->fogMode    = $4->fogMode;
				$$->fogDensity = $4->fogDensity;
				$$->fogStart   = $4->fogStart;
				$$->fogEnd     = $4->fogEnd;
				PopShaderState();
			}
			| states TOKEN_ALPHA_TO_MASK boolean				
			{ 
				$$ = $1;
				$$->alphaToMask = *$3;
				delete $3;
			}
			| states TOKEN_ZTEST funcval						
			{ 
				$$ = $1;
				$$->zTest = *$3;
				delete $3;
			}
			| states TOKEN_ZTEST TOKEN_TRUE						
			{ 
				$$ = $1; 
				$$->zTest.SetValue(kFuncLEqual); 
			}
			| states TOKEN_ZTEST TOKEN_FALSE					
			{ 
				$$ = $1; 
				$$->zTest.SetValue(kFuncDisabled); 
			}
			| states TOKEN_ZWRITE boolean						
			{ 
				$$ = $1;
				$$->zWrite = *$3;
				delete $3;
			}
			| states TOKEN_COLORMASK maskval					
			{ 
				$$ = $1;
				$$->colMask = *$3;
				delete $3;
			}
			| states TOKEN_GPU_PROGRAM_ID VAL_NUMBER
			{
				$$ = $1;
				$$->gpuProgramID = $3;
			}
			| states TOKEN_CULL cullval						
			{ 
				$$ = $1;
				$$->culling = *$3;
				delete $3;
			}
			| states TOKEN_CULL TOKEN_FALSE						
			{ 
				$$ = $1; 
				$$->culling.SetValue(kCullOff); 
			}
			| states TOKEN_BLEND blendval blendval ',' blendval blendval 
			{ 
				$$ = $1;
				$$->srcBlend = *$3;
				$$->destBlend = *$4;
				$$->srcBlendAlpha = *$6;
				$$->destBlendAlpha = *$7;
				delete $3;
				delete $4;
				delete $6;
				delete $7;
			}
			| states TOKEN_BLEND blendval blendval			
			{ 
				$$ = $1; 
				$$->srcBlend = *$3;
				$$->destBlend = *$4;
				$$->srcBlendAlpha = *$3;
				$$->destBlendAlpha = *$4;
				delete $3;
				delete $4;
			}
			| states TOKEN_BLEND TOKEN_FALSE					
			{ 
				$$ = $1; 
				$$->srcBlend.SetValue(kBlendOne); 
				$$->srcBlendAlpha.SetValue(kBlendOne); 
				$$->destBlend.SetValue(kBlendZero); 
				$$->destBlendAlpha.SetValue(kBlendZero); 
			}
			| states TOKEN_BLEND_OP blendopval ',' blendopval	
			{ 
				$$ = $1; 
				$$->blendOp = *$3;
				$$->blendOpAlpha = *$5;
				delete $3;
				delete $5;
			}
			| states TOKEN_BLEND_OP blendopval					
			{ 
				$$ = $1; 
				$$->blendOp = *$3;
				$$->blendOpAlpha = *$3;
				delete $3;
			}
			| states TOKEN_STENCIL '{' stencilblock '}'		
			{ 
				$$ = $1;
				$$->stencilRef = $4->stencilRef;
				$$->stencilReadMask = $4->stencilReadMask;
				$$->stencilWriteMask = $4->stencilWriteMask;
				$$->stencilOp = $4->stencilOp;
				$$->stencilOpFront = $4->stencilOpFront;
				$$->stencilOpBack = $4->stencilOpBack;
				PopShaderState();
			}
			| states TOKEN_OFFSET numval ',' numval
			{
				$$ = $1;
				$$->offsetFactor = *$3;
				$$->offsetUnits = *$5;
				delete $3;
				delete $5;
			}
			| states TOKEN_PROGRAM VAL_STRING '{' subprograms '}'
			{
				$$ = $1;
				$5->type = $3;
				_yaccCurrentPrograms.push_back($5);
				delete[] $3;
			}
			;

cullval: 	VAL_BRACKET_ID		
			{
				$$ = new SLFloat(); 
				$$->SetRef($1); 
				delete[] $1;
			}
			| VAL_TRIANGLE_FACE		
			{ 
				$$ = new SLFloat(); 
				$$->SetValue($1); 
			}
			;
			
boolean: 	VAL_BRACKET_ID		
			{
				$$ = new SLFloat(); 
				$$->SetRef($1); 
				delete[] $1;
			}
			| TOKEN_TRUE
			{ 
				$$ = new SLFloat(); 
				$$->SetValue(1); 
			}
			| TOKEN_FALSE			
			{ 
				$$ = new SLFloat(); 
				$$->SetValue(0); 
			}
			;

tags:
			{
				$$ = new std::map<std::string, std::string>(); 
			}
			| tags VAL_ID '=' VAL_ID				
			{ 
				$$ = $1;
				std::string key($2);
				std::string value($4);
				(*$$)[key] = value;
				delete[] $2;
				delete[] $4;
			}
			| tags VAL_STRING '=' VAL_STRING		
			{ 
				$$ = $1;
				std::string key($2);
				std::string value($4);
				(*$$)[key] = value; 
				delete[] $2;
				delete[] $4;
			}
			;

fogblock:	
			{
				PushShaderState(); 
				$$ = _shaderStateStack.top(); 
			}
			| fogblock TOKEN_COLOR color					
			{ 
				$$ = $1; 
				$1->fogColor = *$3; 
				delete $3; 
			}
			| fogblock TOKEN_MODE VAL_FOG_MODE			
			{
				$$ = $1; 
				$1->fogMode = (FogMode)$3; 
			}
			| fogblock TOKEN_DENSITY numval				
			{
				$$ = $1;
				$1->fogDensity = *$3;
				delete $3;
			}
			| fogblock TOKEN_RANGE numval ',' numval		
			{ 
				$$ = $1;
				$1->fogStart = *$3;
				$1->fogEnd = *$5;
				delete $3;
				delete $5;
			}
			;
			
color:	   '(' numval ',' numval ',' numval ',' numval ')'
			{
				$$ = new SLVector4();
				$$->SetValue(*$2, *$4, *$6, *$8);
				delete $2; 
				delete $4; 
				delete $6; 
				delete $8;
			}
	 		| '(' numval ',' numval ',' numval ')'
			{
				$$ = new SLVector4();
				$$->SetValue(*$2, *$4, *$6);
				delete $2; 
				delete $4; 
				delete $6;
			}
			| VAL_BRACKET_ID
			{
				$$ = new SLVector4();
				$$->SetValue(0, 0, 0, 0);
				$$->SetRef($1);
				delete[] $1;
			}
			;
			
stencilblock:					
			{
				PushShaderState(); 
				$$ = _shaderStateStack.top(); 
			}
			| stencilblock TOKEN_REF numval				
			{ 
				$$ = $1;
				$$ ->stencilRef = *$3;
				delete $3;
			}
			| stencilblock TOKEN_READ_MASK numval			
			{ 
				$$ = $1; 
				$$->stencilReadMask = *$3;
				delete $3;
			}
			| stencilblock TOKEN_WRITE_MASK numval			
			{ 
				$$ = $1;
				$$->stencilWriteMask = *$3;
				delete $3;
			}
			| stencilblock TOKEN_COMP funcval				
			{ 
				$$ = $1;
				$$->stencilOp.comp = *$3;
				delete $3;
			}
			| stencilblock TOKEN_OP_PASS stencilaction		
			{ 
				$$ = $1;
				$$->stencilOp.pass = *$3;
				delete $3;
			}
			| stencilblock TOKEN_OP_FAIL stencilaction		
			{ 
				$$ = $1;
				$$->stencilOp.fail = *$3;
				delete $3;
			}
			| stencilblock TOKEN_OP_ZFAIL stencilaction		
			{ 
				$$ = $1;
				$$->stencilOp.zFail = *$3;
				delete $3;
			}
			| stencilblock TOKEN_COMP_FRONT funcval		
			{ 
				$$ = $1;
				$$->stencilOpFront.comp = *$3;
				delete $3;
			}
			| stencilblock TOKEN_OP_PASS_FRONT stencilaction	
			{ 
				$$ = $1;
				$$->stencilOpFront.pass = *$3;
				delete $3;
			}
			| stencilblock TOKEN_OP_FAIL_FRONT stencilaction	
			{ 
				$$ = $1;
				$$->stencilOpFront.fail = *$3;
				delete $3;
			}
			| stencilblock TOKEN_OP_ZFAIL_FRONT stencilaction	
			{ 
				$$ = $1;
				$$->stencilOpFront.zFail = *$3;
				delete $3;
			}
			| stencilblock TOKEN_COMP_BACK funcval			
			{ 
				$$ = $1;
				$$->stencilOpBack.comp = *$3;
				delete $3;
			}
			| stencilblock TOKEN_OP_PASS_BACK stencilaction	
			{ 
				$$ = $1;
				$$->stencilOpBack.pass = *$3;
				delete $3;
			}
			| stencilblock TOKEN_OP_FAIL_BACK stencilaction	
			{ 
				$$ = $1;
				$$->stencilOpBack.fail = *$3;
				delete $3;
			}
			| stencilblock TOKEN_OP_ZFAIL_BACK stencilaction	
			{ 
				$$ = $1;
				$$->stencilOpBack.zFail = *$3;
				delete $3;
			}
			;

stencilaction: VAL_BRACKET_ID	
			{
				$$ = new SLFloat(); 
				$$->SetRef($1); 
				delete[] $1;
			}
			| VAL_STENCIL_ACTION		
			{ 
				$$ = new SLFloat(); 
				$$->SetValue ($1); 
			}
			;
			
subprograms:
			{ 
				$$ = new SLProgram(); 
			}
			| subprograms TOKEN_SUBPROGRAM VAL_STRING '{' subprogram '}'
			{
				$$ = $1;
				$5->name = $3;
				$$->subPrograms.push_back($5);
				delete[] $3;
			}
			| subprograms TOKEN_SUBPROGRAM '{' subprogram '}'	
			{ 
				$$ = $1;
				$4->name = "";
				$1->subPrograms.push_back($4); 
			}
			;

subprogram:
			{ 
				$$ = new SLSubProgram(); 
			}
			| subprogram VAL_STRING									
			{ 
				$$ = $1; 
				$$->source = $2; 
				delete[] $2;
			}
			| subprogram TOKEN_BIND VAL_STRING VAL_ID
			{
				$$ = $1;
				$$->Bind($3, $4);
				delete[] $3;
				delete[] $4;
			}
			| subprogram TOKEN_FLOAT VAL_NUMBER VAL_BRACKET_ID				
			{ 
				$$ = $1; 
				$1->AddParamVector(kShaderParamFloat, (int)$3, 1, $4); 
				delete[] $4;
			}
			| subprogram TOKEN_VECTOR VAL_NUMBER VAL_BRACKET_ID				
			{
				$$ = $1; 
				$1->AddParamVector(kShaderParamFloat, (int)$3, 4, $4); 
				delete[] $4;
			}
			| subprogram TOKEN_VECTOR VAL_NUMBER VAL_BRACKET_ID VAL_NUMBER	
			{
				$$=$1; 
				$1->AddParamVector(kShaderParamFloat, (int)$3, (int)$5, $4); 
				delete[] $4;
			}
			| subprogram TOKEN_MATRIX VAL_NUMBER VAL_BRACKET_ID				
			{ 
				$$ = $1; 
				$1->AddParamMatrix((int)$3, $4, 4); 
				delete[] $4;
			}
			| subprogram TOKEN_MATRIX VAL_NUMBER VAL_BRACKET_ID VAL_NUMBER	
			{ 
				$$ = $1; 
				$1->AddParamMatrix((int)$3, $4, (int)$5); 
				delete[] $4;
			}
			| subprogram TOKEN_SETTEXTURE VAL_NUMBER VAL_BRACKET_ID VAL_TEX_DIM VAL_NUMBER 
			{ 
				$$ = $1; 
				$1->AddParamTexture((int)$3, $4, (TextureDimension)$5, (int)$6); 
				delete[] $4;
			}
			| subprogram TOKEN_SETTEXTURE VAL_NUMBER VAL_BRACKET_ID VAL_TEX_DIM
			{ 
				$$ = $1; 
				$1->AddParamTexture((int)$3, $4, (TextureDimension)$5, (int)$3); 
				delete[] $4;
			}
			| subprogram TOKEN_SETTEXTURE VAL_BRACKET_ID VAL_TEX_DIM				
			{
				$$ = $1; 
				$1->AddParamTexture($3, (TextureDimension)$4); 
				delete[] $3;
			}
			| subprogram TOKEN_KEYWORDS '{' stringlist '}'				
			{ 
				$$ = $1; 
				$1->SetKeywords(*($4)); 
				delete $4; 
			}
			| subprogram TOKEN_CONSTBUFFER VAL_STRING VAL_NUMBER		
			{ 
				$$ = $1; 
				$1->SetConstBuffer($3, (int)$4); 
				delete[] $3;
			}
			| subprogram TOKEN_BINDCB VAL_STRING VAL_NUMBER				
			{ 
				$$ = $1; 
				$1->BindConstBuffer($3, (int)$4); 
				delete[] $3;
			}
			| subprogram TOKEN_SETBUFFER VAL_NUMBER VAL_BRACKET_ID			
			{ 
				$$ = $1; 
				$1->AddParamBuffer((int)$3, $4); 
				delete[] $4;
			}
			;

stringlist:
			{ 
				$$ = new std::vector<std::string>(); 
			}
			| stringlist VAL_STRING				
			{ 
				$$ = $1; 
				$$->emplace_back($2);
				delete[] $2;
			}
			;
			
numval:   	VAL_NUMBER							
			{ 
				$$ = new SLFloat(); 
				$$->SetValue($1); 
			}
			| VAL_BRACKET_ID
			{
				$$ = new SLFloat();
				$$->SetRef($1);
				delete[] $1;
			}
			;
			
blendval: 	VAL_BRACKET_ID	
			{ 
				$$ = new SLFloat (); 
				$$->SetRef ($1); 
				delete[] $1;
			}
			| VAL_BLEND_FACTOR		
			{ 
				$$ = new SLFloat (); 
				$$->SetValue ($1); 
			}
			;

blendopval: VAL_BRACKET_ID	
			{ 
				$$ = new SLFloat (); 
				$$->SetRef ($1); 
				delete[] $1;
			}
			| VAL_BLEND_OP_MODE	
			{ 
				$$ = new SLFloat (); 
				$$->SetValue ($1); 
			}
			;

maskval: 	VAL_BRACKET_ID	
			{ 
				$$ = new SLFloat(); 
				$$->SetRef($1); 
				delete[] $1;
			}
			| VAL_RGBA_MASK	
			{ 
				$$ = new SLFloat(); 
				$$->SetValue($1); 
			}
			| TOKEN_FALSE			
			{ 
				$$ = new SLFloat(); 
				$$->SetValue(0); 
			}
			;

funcval: 	VAL_BRACKET_ID	
			{ 
				$$ = new SLFloat(); 
				$$->SetRef($1); 
				delete[] $1;
			}
			| VAL_COMPARE_MODE	
			{ 
				$$ = new SLFloat(); 
				$$->SetValue($1); 
			}
			;


%%

int yyerror (const char *s)
{
    printf("yyerror line %d %s\n", yylineno, s);
	_currentErrors.push_back(FormatString("Error line %d %s", yylineno, s));
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
