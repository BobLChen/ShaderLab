//
//  SLParserData.h
//  ShaderLab
//
//  Created by Neil on 13/1/18.
//  Copyright © 2018 Neil. All rights reserved.
//

#ifndef __SL_PARSER_H__
#define __SL_PARSER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stack>
#include "SLParserData.h"

using namespace shaderlab;

extern std::stack<SLShaderState*> _shaderStateStack;
extern SLShader* _currentShader;
extern std::vector<std::string> _currentErrors;

void InitLex(const char *c, size_t length);
void FreeLex();
int yyparse();

void SetDefaultShaderState(SLShaderState &base)
{
	base.lod = 0;
	base.gpuProgramID = -1;
	base.offsetFactor.SetValue(0.0f);
	base.offsetUnits.SetValue(0.0f);
	base.fogMode = kFogUnknown;
	base.fogDensity.SetRef("unity_FogDensity");
	base.fogStart.SetRef("unity_FogStart");
	base.fogEnd.SetRef("unity_FogEnd");
	base.fogColor.SetRef("unity_FogColor");

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

SLShader* ParseShader(const char* data, int dataSize, std::vector<std::string> &outErrors)
{
	if (data == nullptr || dataSize < 3) {
		return nullptr;
	}

	if (data[0] == '\xEF' && data[1] == '\xBB' && data[2] == '\xBF') {
		data += 3;
		dataSize -= 3;
	}

	_currentErrors.resize(0);

	SLShader* shader = new SLShader();

	SLShaderState base;
	SetDefaultShaderState(base);
	
	_shaderStateStack.push(&base);
	_currentShader = shader;
	
	InitLex(data, dataSize);
	yyparse();
	FreeLex();

	while (_shaderStateStack.size() > 1) {
		SLShaderState *state = _shaderStateStack.top();
		delete state;
		_shaderStateStack.pop();
	}

	_currentShader = nullptr;

	for (std::size_t i = 0; i < _currentErrors.size(); ++i) {
		outErrors.push_back(_currentErrors[i]);
	}
	
	return shader;
}

#endif