//
//  SLCompiler.h
//  ShaderLab
//
//  Created by Neil on 27/1/18.
//  Copyright © 2018 Neil. All rights reserved.
//

#ifndef __SL_COMPILER_H__
#define __SL_COMPILER_H__

#include <stdio.h>
#include <string>
#include <vector>

namespace shaderlab
{
	using namespace std;

	typedef bool(*IncludeOpenCallback)(bool isSystem, const char *fileName, const char *parentFileName, const char *parent, std::string &output, void *data);

	enum ShaderTarget
	{
		kShaderTargetOpenGL = 0,
		kShaderTargetGLES20,
		kShaderTargetGLES30,
		kShaderTargetCount
	};

	string GetShaderTargetName(ShaderTarget shaderTarget);
	ShaderTarget GetShaderTarget(const string &name);
	
	enum ShaderProgram {
		kProgramVertex = 0,
		kProgramFragment,
		kProgramSurface,
		kProgramCount
	};

	struct ShaderCompileArg {
		ShaderCompileArg(const string &n, const string &v) : name(n), value(v) { }
		string name;
		string value;
	};

	struct CGProgramParameters {

		CGProgramParameters() 
		: shaderTarget(0)
		, includeOpenCallback(nullptr)
		{

		}
		
		void SetPragmaParams(const vector<vector<string>> &params)
		{
			for (size_t i = 0; i < params.size(); ++i) {
				vector<string> names = params[i];
				if (names.size() <= 1) {
					printf("not enough params\n");
					continue;
				}
				string pragmaType = names[0];
				string pragmaName = names[1];
				if (pragmaType == "surface") {

				} else if (pragmaType == "multi_compile") {
					keywords = names;
					keywords.erase(keywords.begin());
				} else if (pragmaType == "vertex") {
					entryName[kProgramVertex] = pragmaName;
				} else if (pragmaType == "fragment") {
					entryName[kProgramFragment] = pragmaName;
				} else if (pragmaType == "target") {
					for (size_t idx = 1; idx < names.size(); ++idx) {
						shaderTarget = shaderTarget | (1 << GetShaderTarget(names[idx]));
					}
				}
			}
		}
		
		bool HasProgram() const
		{
			for (int i = 0; i < kProgramCount; ++i) {
				if (!entryName[i].empty()) {
					return true;
				}
			}
			return false;
		}

		bool HasProgram(ShaderProgram p) const 
		{ 
			return !entryName[p].empty(); 
		}

		string source;
		vector<string> keywords;
		IncludeOpenCallback includeOpenCallback;
		unsigned int shaderTarget;
		string entryName[kProgramCount];
	};

	struct ShaderCompileData
	{
		ShaderCompileData() 
		: shaderTarget(kShaderTargetGLES20) 
		{ 

		}

		const CGProgramParameters *params;
		vector<ShaderCompileArg> args;
		ShaderTarget shaderTarget;
		string output;
		string vertBinds;
		string fragBinds;
		string keywords;
	};
	
	bool compileCG(const std::string &source, IncludeOpenCallback includeOpenCallback, std::string &output);
}

#endif