#include "SLCompiler.h"
#include "HLSLCompiler.h"

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
}