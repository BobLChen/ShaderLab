%{

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

%}

%union 
{
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
};

%token TOKEN_SHADER TOKEN_PASS TOKEN_USEPASS TOKEN_SUBSHADER
%token TOKEN_CATEGORY TOKEN_FALLBACK TOKEN_LOD
%token TOKEN_COLOR TOKEN_ALPHA_TO_MASK TOKEN_TRUE TOKEN_FALSE
%token TOKEN_FLOAT TOKEN_RANGE TOKEN_VECTOR
%token TOKEN_PROPERTIES TOKEN_TAGS TOKEN_NAME
%token TOKEN_ZWRITE TOKEN_ZTEST TOKEN_CULL TOKEN_ZCLIP TOKEN_BLEND TOKEN_BLEND_OP TOKEN_COLORMASK TOKEN_OFFSET
%token TOKEN_STENCIL TOKEN_REF TOKEN_READ_MASK TOKEN_WRITE_MASK TOKEN_COMP TOKEN_OP_PASS TOKEN_OP_FAIL TOKEN_OP_ZFAIL
%token TOKEN_COMP_BACK TOKEN_OP_PASS_BACK TOKEN_OP_FAIL_BACK TOKEN_OP_ZFAIL_BACK
%token TOKEN_COMP_FRONT TOKEN_OP_PASS_FRONT TOKEN_OP_FAIL_FRONT TOKEN_OP_ZFAIL_FRONT

%token <number> VAL_NUMBER
%token <strval> VAL_ID VAL_STRING VAL_BRACKET_ID VAL_PROGRAM_SOURCE
%token <enumval> VAL_TRIANGLE_FACE VAL_COMPARE_MODE VAL_RGBA_MASK
%token <enumval> VAL_TEX_DIM VAL_BLEND_FACTOR VAL_BLEND_OP_MODE VAL_STENCIL_ACTION
%token <number> VAL_HLSLPROGRAM VAL_GLSLPROGRAM VAL_CGPROGRAM

%type <floatval> numval maskval blendval funcval blendopval stencilaction boolean cullval
%type <vector4> vector4
%type <shader> shader
%type <subshader> subshader
%type <properties> properties propitems
%type <tags> tags
%type <states> states stencilblock
%type <pass> pass
%type <passes> passes
%type <strings> propflags

%%

shader: 	TOKEN_SHADER VAL_STRING
			{
				g_CurrentShader->shaderName = $2;
			}
			'{' properties 
			{
				if ($5) 
				{
					g_CurrentShader->properties = *$5;
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

				delete   $2;
				delete[] $3;
				delete[] $5;
			}
			| propitems propflags VAL_ID '(' VAL_STRING ',' TOKEN_RANGE '(' VAL_NUMBER ',' VAL_NUMBER ')' ')' '=' VAL_NUMBER
			{
				$$ = $1;
				$$->AddRangeProperty($3, $5, *$2, $15, $9, $11); 

				delete   $2;
				delete[] $3;
				delete[] $5;
			}
			| propitems propflags VAL_ID '(' VAL_STRING ',' TOKEN_VECTOR ')' '=' vector4
			{
				$$ = $1;
				$$->AddVectorProperty($3, $5, *$2, *$10);

				delete[] $3;
				delete[] $5;
				delete   $2;
				delete   $10; 
			}
			| propitems propflags VAL_ID '(' VAL_STRING ',' TOKEN_COLOR ')' '=' vector4
			{
				$$ = $1;
				$$->AddColorProperty($3, $5, *$2, *$10);

				delete[] $3;
				delete[] $5;
				delete   $2;
				delete   $10;
			}
			| propitems propflags VAL_ID '(' VAL_STRING ',' VAL_TEX_DIM ')' '=' VAL_STRING
			{
				SLPropTexture texture;
				texture.name      = $10;
				texture.dimension = (TextureDimension)$7;

				$$ = $1;
				$$->AddTextureProperty($3, $5, *$2, texture);

				delete   $2;
				delete[] $3;
				delete[] $5;
				delete[] $10;
			}
			| propitems propflags VAL_ID '(' VAL_STRING ',' VAL_TEX_DIM ')' '=' VAL_STRING '{' '}'
			{
				SLPropTexture texture;
				texture.name      = $10;
				texture.dimension = (TextureDimension)$7;

				$$ = $1;
				$$->AddTextureProperty($3, $5, *$2, texture);

				delete   $2;
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

vector4:    '(' VAL_NUMBER ',' VAL_NUMBER ',' VAL_NUMBER ',' VAL_NUMBER ')'
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
				if ($2) 
				{
					g_CurrentShader->subShaders.push_back($2); 
				}
			}
			| shaderBlocks fallback
			{
				
			}
			;

category: 	TOKEN_CATEGORY '{'	
			{
				PushShaderState();
			}
			states shaderBlocks '}'		
			{
				PopShaderState();
			}
			;

subshader: 	TOKEN_SUBSHADER '{'		
			{
				PushShaderState();
			}
			passes '}'				
			{
				const SLShaderState* state = g_ShaderStateStack.top();

				$$ = new SLSubShader();
				$$->tags = state->tags;
				$$->lod  = state->lod;
				$$->SetPasses($4);

				delete $4;

				PopShaderState();
			}
			;

fallback: 	TOKEN_FALLBACK VAL_STRING			
			{
				g_CurrentShader->fallbackName = $2;
				delete[] $2;
			}
			| TOKEN_FALLBACK VAL_STRING ',' VAL_NUMBER	
			{
				g_CurrentShader->fallbackName = $2;
				delete[] $2;
			}
			| TOKEN_FALLBACK TOKEN_FALSE					
			{
				g_CurrentShader->fallbackName = "";
			}
			;
			
passes: 	states pass					
			{
				$$ = new std::vector<SLPassBase*>(); 
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
			}
			states '}'					
			{
				SLNormalPass* pp = new SLNormalPass(*g_ShaderStateStack.top());
				pp->program.type   = g_CurrentProgramType;
				pp->program.source = g_CurrentProgramCode;
				pp->program.lineNo = g_CurrentProgramLine;

				$$ = pp;
				
				g_CurrentProgramType = kCG;
				g_CurrentProgramCode = nullptr;
				g_CurrentProgramLine = 0;
				
				PopShaderState();
			}
			| TOKEN_USEPASS VAL_STRING				
			{
				$$ = new SLUsePass($2); 
				delete[] $2;
			}
			;
			
states:		
			{
				$$ = g_ShaderStateStack.top();
			}
			| states TOKEN_LOD VAL_NUMBER					
			{
				$$ = $1; 
				$$->lod = int32($3);
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

				$$->srcBlend       = *$3;
				$$->destBlend      = *$4;
				$$->srcBlendAlpha  = *$6;
				$$->destBlendAlpha = *$7;

				delete $3;
				delete $4;
				delete $6;
				delete $7;
			}
			| states TOKEN_BLEND blendval blendval			
			{
				$$ = $1; 

				$$->srcBlend       = *$3;
				$$->destBlend      = *$4;
				$$->srcBlendAlpha  = *$3;
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

				$$->blendOp      = *$3;
				$$->blendOpAlpha = *$5;

				delete $3;
				delete $5;
			}
			| states TOKEN_BLEND_OP blendopval					
			{
				$$ = $1;
				
				$$->blendOp      = *$3;
				$$->blendOpAlpha = *$3;

				delete $3;
			}
			| states TOKEN_STENCIL '{' stencilblock '}'		
			{
				$$ = $1;

				$$->stencilRef       = $4->stencilRef;
				$$->stencilReadMask  = $4->stencilReadMask;
				$$->stencilWriteMask = $4->stencilWriteMask;
				$$->stencilOp 		 = $4->stencilOp;
				$$->stencilOpFront   = $4->stencilOpFront;
				$$->stencilOpBack    = $4->stencilOpBack;

				PopShaderState();
			}
			| states TOKEN_OFFSET numval ',' numval
			{
				$$ = $1;

				$$->offsetFactor = *$3;
				$$->offsetUnits  = *$5;

				delete $3;
				delete $5;
			}
			| states VAL_HLSLPROGRAM VAL_PROGRAM_SOURCE
			{
				g_CurrentProgramCode = $3;
				g_CurrentProgramLine = $2;
				g_CurrentProgramType = kHLSL;
			}
			| states VAL_GLSLPROGRAM VAL_PROGRAM_SOURCE
			{
				g_CurrentProgramCode = $3;
				g_CurrentProgramLine = $2;
				g_CurrentProgramType = kGLSL;
			}
			| states VAL_CGPROGRAM VAL_PROGRAM_SOURCE
			{
				g_CurrentProgramCode = $3;
				g_CurrentProgramLine = $2;
				g_CurrentProgramType = kCG;
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
				std::string key($2);
				std::string value($4);

				$$ = $1;
				(*$$)[key] = value;

				delete[] $2;
				delete[] $4;
			}
			| tags VAL_STRING '=' VAL_STRING		
			{
				std::string key($2);
				std::string value($4);

				$$ = $1;
				(*$$)[key] = value;

				delete[] $2;
				delete[] $4;
			}
			;

stencilblock:					
			{
				PushShaderState(); 
				$$ = g_ShaderStateStack.top();
			}
			| stencilblock TOKEN_REF numval				
			{
				$$ = $1;
				$$->stencilRef = *$3;

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
				$$ = new SLFloat(); 
				$$->SetRef($1);

				delete[] $1;
			}
			| VAL_BLEND_FACTOR		
			{ 
				$$ = new SLFloat(); 
				$$->SetValue($1);
			}
			;

blendopval: VAL_BRACKET_ID	
			{
				$$ = new SLFloat();
				$$->SetRef($1);

				delete[] $1;
			}
			| VAL_BLEND_OP_MODE	
			{
				$$ = new SLFloat();
				$$->SetValue($1);
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