#pragma once

#include <stdio.h>
#include <stack>

#include "SLParserData.h"

using namespace shaderlab;

extern SLShader*					g_CurrentShader;
extern std::stack<SLShaderState*>	g_ShaderStateStack;
extern const char*                  g_CurrentProgramCode;
extern ProgramType					g_CurrentProgramType;

void InitLex(const char *c, size_t length);

void FreeLex();

int shaderlabparse();

SLShader* ParseShaderLab(const char* data, size_t length);