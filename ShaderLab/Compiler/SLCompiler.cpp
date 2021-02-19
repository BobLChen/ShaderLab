#include "SLCompiler.h"
#include "HLSLCompiler.h"

#include "Utils/StringUtils.h"

namespace shaderlab
{
	std::string GetShaderTargetName(ShaderTarget shaderTarget)
	{
		if (shaderTarget == kShaderTargetOpenGL) 
		{
			return "opengl";
		}
		else if (shaderTarget == kShaderTargetGLES20) 
		{
			return "gles20";
		}
		else if (shaderTarget == kShaderTargetGLES30) 
		{
			return "gles30";
		}
		else if (shaderTarget == kShaderTargetMetal)
		{
			return "metal";
		}
		else if (shaderTarget == kShaderTargetVulkan)
		{
			return "vulkan";
		}
		else if (shaderTarget == kShaderTargetHLSL)
		{
			return "hlsl";
		}
		return "gles20";
	}

	ShaderTarget GetShaderTarget(const std::string& name)
	{
		if (strcmp(name.c_str(), "opengl") == 0) 
		{
			return kShaderTargetOpenGL;
		}
		else if (strcmp(name.c_str(), "gles20") == 0) 
		{
			return kShaderTargetGLES20;
		}
		else if (strcmp(name.c_str(), "gles30") == 0) 
		{
			return kShaderTargetGLES30;
		}
		else if (strcmp(name.c_str(), "metal") == 0)
		{
			return kShaderTargetMetal;
		}
		else if (strcmp(name.c_str(), "vulkan") == 0)
		{
			return kShaderTargetVulkan;
		}
		else if (strcmp(name.c_str(), "hlsl") == 0)
		{
			return kShaderTargetHLSL;
		}

		return kShaderTargetGLES20;
	}

	std::wstring ShaderProfileName(ShaderStage stage, ShaderModel shaderModel)
	{
		std::wstring shaderProfile;

		switch (stage)
		{
		case ShaderStage::kProgramVertex:
			shaderProfile = L"vs";
			break;

		case ShaderStage::kProgramFragment:
			shaderProfile = L"ps";
			break;

		case ShaderStage::kProgramGeometry:
			shaderProfile = L"gs";
			break;

		case ShaderStage::kProgramHull:
			shaderProfile = L"hs";
			break;

		case ShaderStage::kProgramDomain:
			shaderProfile = L"ds";
			break;

		case ShaderStage::kProgramCompute:
			shaderProfile = L"cs";
			break;

		default:
			shaderProfile = L"vs";
			break;
		}

		shaderProfile.push_back(L'_');
		shaderProfile.push_back(L'0' + shaderModel.majorVer);
		shaderProfile.push_back(L'_');
		shaderProfile.push_back(L'0' + shaderModel.minorVer);

		return shaderProfile;
	}

	void ProcessPragmaArgs(const char* text, int32 textLen, const char* pragmaName, int32 pragmaLen, std::vector<PragmaParam>& outParams)
	{
		int32 pos = IndexOfToken(text, textLen, pragmaName, pragmaLen, 0);
		while (pos != -1) 
		{
			pos += pragmaLen;
			int32 lineEnd = ReadLine(text, textLen, pos);
			int32 linePos = 0;
			
			outParams.emplace_back();
			PragmaParam& pragma = outParams.back();
			
			while (linePos < (lineEnd - pos))
			{
				std::string token = ReadNonWhiteSpace(text + pos, lineEnd - pos, linePos);
				if (token.empty())
				{
					break;
				}
				pragma.values.push_back(token);
			}

			pragma.option = pragma.values[0];
			pragma.values.erase(pragma.values.begin());

			pos = IndexOfToken(text, textLen, pragmaName, pragmaLen, pos);
		}
	}

	void EnumerateKeywords(const ProgramParameters& params, int32 depth, std::vector<std::string>& result, std::vector<std::vector<std::string>>& results)
	{
		for (int32 i = 0; i < params.keywords[depth].keywords.size(); ++i)
		{
			result[depth] = params.keywords[depth].keywords[i];
			if (depth != params.keywords.size() - 1)
			{
				EnumerateKeywords(params, depth + 1, result, results);
			}
			else
			{
				results.push_back(result);
			}
		}
	}

	void ProcessShaderSnippets(const CompileShaderInfo& shaderInfo, const std::string& source, const ProgramParameters& params, std::vector<ShaderSnippet>& snippets)
	{
		// variants
		std::vector<std::string> temp;
		temp.resize(params.keywords.size());
		std::vector<std::vector<std::string>> variants;
		EnumerateKeywords(params, 0, temp, variants);

		// snippets
		for (int32 variantIndex = 0; variantIndex < variants.size(); ++variantIndex)
		{
			std::vector<MacroDefine> defines;
			defines.resize(variants[variantIndex].size());
			for (int32 defineIndex = 0; defineIndex < defines.size(); ++defineIndex)
			{
				defines[defineIndex].name = variants[variantIndex][defineIndex].c_str();
			}

			for (int32 programIndex = 0; programIndex < kProgramCount; ++programIndex)
			{
				ShaderStage stage = (ShaderStage)programIndex;
				if (!params.HasProgram(stage))
				{
					continue;
				}

				for (int32 shaderTargetIndex = 0; shaderTargetIndex < kShaderTargetCount; ++shaderTargetIndex)
				{
					uint32 shaderTargetMask = 1 << shaderTargetIndex;
					if (params.shaderTarget & shaderTargetMask)
					{
						ShaderSnippet snippet   = {};
						snippet.fileName        = shaderInfo.fileName;
						snippet.source          = source.c_str();
						snippet.sourceLength    = source.size();
						snippet.entryPoint      = params.entryName[programIndex].c_str();
						snippet.defines			= defines;
						snippet.stage           = stage;
						snippet.shaderModel     = { 6, 0 };
						snippet.shaderTarget    = (ShaderTarget)shaderTargetIndex;
						snippet.includeCallback = shaderInfo.includeCallback;
						snippets.push_back(snippet);
					}
				}
			}
		}
	}

	void CompileNormalPass(const CompileShaderInfo& shaderInfo, const SLNormalPass* pass)
	{
		const SLProgram& program = pass->program;

		// parse pragma
		std::vector<PragmaParam> pragmaParams;
		ProcessPragmaArgs(program.source.data(), program.source.size(), "#pragma ", strlen("#pragma "), pragmaParams);

		// disable pragma
		std::string source = program.source;
		ReplaceString(source, "#pragma", "// #pragma");

		// program params
		ProgramParameters programParams;
		programParams.SetPragmaParams(pragmaParams);

		// generate snippet
		std::vector<ShaderSnippet> snippets;
		ProcessShaderSnippets(shaderInfo, source, programParams, snippets);

		// compile code
		for (int32 snippetIndex = 0; snippetIndex < snippets.size(); ++snippetIndex)
		{
			const ShaderSnippet& snippet = snippets[snippetIndex];
			HLSLCompileResult result = HLSLCompiler::Compile(snippet);
			printf("Status:%s Message:%s\n", result.data.size() != 0 ? "Success" : "Failed", result.warningErrorMsg.c_str());
		}
	}

	bool SLCompiler::Init()
	{
		bool success = true;
		success &= HLSLCompiler::Init();
		return success;
	}

	bool SLCompiler::Destroy()
	{
		bool success = true;
		success &= HLSLCompiler::Destroy();
		return success;
	}

	void SLCompiler::Compile(const CompileShaderInfo& shaderInfo)
	{
		SLShader* shader = shaderInfo.shader;

		// compile code
		for (int32 shaderIdx = 0; shaderIdx < shader->subShaders.size(); ++shaderIdx)
		{
			SLSubShader* subShader = shader->subShaders[shaderIdx];
			for (int32 subShaderIdx = 0; subShaderIdx < subShader->passes.size(); ++subShaderIdx)
			{
				SLPassBase* slpass = subShader->passes[subShaderIdx];
				if (slpass->type == SLPassBase::kPassNormal)
				{
					CompileNormalPass(shaderInfo, (SLNormalPass*)slpass);
				}
			}
		}

		// result
	}
}