#pragma once

#include <stdio.h>
#include <stack>

#include "Common/Common.h"
#include "SLParserData.h"

using namespace shaderlab;

extern SLShader*					g_CurrentShader;
extern std::stack<SLShaderState*>	g_ShaderStateStack;
extern const char*                  g_CurrentProgramCode;
extern int32                        g_CurrentProgramLine;
extern ProgramType					g_CurrentProgramType;

void InitLex(const char *c, int32 length);

void FreeLex();

int32 shaderlabparse();

SLShader* ParseShaderLab(const char* data, int32 length);