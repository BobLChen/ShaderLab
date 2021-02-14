#include "SLParser.h"

void SetDefaultShaderState(SLShaderState& base)
{
	base.lod = 0;
	base.name = "";

	base.offsetFactor.SetValue(0.0f);
	base.offsetUnits.SetValue(0.0f);

	base.culling.SetValue(kCullBack);
	base.colMask.SetValue(kColorWriteR | kColorWriteG | kColorWriteB | kColorWriteA);
	base.alphaToMask.SetValue(false);
	base.zTest.SetValue(kFuncLEqual);
	base.zWrite.SetValue(true);

	base.srcBlend.SetValue(kBlendOne);
	base.destBlend.SetValue(kBlendZero);
	base.srcBlendAlpha.SetValue(kBlendOne);
	base.destBlendAlpha.SetValue(kBlendZero);
	base.blendOp.SetValue(kBlendOpAdd);
	base.blendOpAlpha.SetValue(kBlendOpAdd);

	base.stencilRef.SetValue(0);
	base.stencilReadMask.SetValue(0xFF);
	base.stencilWriteMask.SetValue(0xFF);
	base.stencilOp.comp.SetValue(kFuncAlways);
	base.stencilOp.pass.SetValue(kStencilOpKeep);
	base.stencilOp.fail.SetValue(kStencilOpKeep);
	base.stencilOp.zFail.SetValue(kStencilOpKeep);
	base.stencilOpFront = base.stencilOp;
	base.stencilOpBack = base.stencilOp;
}

SLShader* ParseShaderLab(const char* data, size_t size)
{
	if (data == nullptr || size < 3)
	{
		return nullptr;
	}

	if (data[0] == '\xEF' && data[1] == '\xBB' && data[2] == '\xBF')
	{
		data += 3;
		size -= 3;
	}

	SLShader* shader = new SLShader();

	SLShaderState* baseState = new SLShaderState();
	SetDefaultShaderState(*baseState);

	g_CurrentShader = shader;
	g_ShaderStateStack.push(baseState);
	
	InitLex(data, size);

	shaderlabparse();

	FreeLex();

	while (g_ShaderStateStack.size() > 0)
	{
		SLShaderState* state = g_ShaderStateStack.top(); 
		g_ShaderStateStack.pop();
		delete state;
	}

	g_CurrentShader = nullptr;

	return shader;
}