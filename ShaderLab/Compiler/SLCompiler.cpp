#include "SLCompiler.h"
#include "HLSLCompiler.h"

#include "Utils/StringUtils.h"

#include "spirv-tools/libspirv.h"
#include "spirv.hpp"
#include "spirv_cross.hpp"
#include "spirv_glsl.hpp"
#include "spirv_hlsl.hpp"
#include "spirv_msl.hpp"
#include "spirv_cross_util.hpp"

#include <memory>

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
		else if (shaderTarget == kShaderTargetMetalIOS)
		{
			return "ios";
		}
		else if (shaderTarget == kShaderTargetMetalMac)
		{
			return "mac";
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
		else if (strcmp(name.c_str(), "ios") == 0)
		{
			return kShaderTargetMetalIOS;
		}
		else if (strcmp(name.c_str(), "mac") == 0)
		{
			return kShaderTargetMetalMac;
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

	void ProcessShaderSnippets(const CompileShaderInfo& shaderInfo, shaderlab::ProgramType sourceType, const std::string& source, const ProgramParameters& params, std::vector<ShaderSnippet>& snippets)
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
						snippet.sourceType      = sourceType;
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

	void FixupSampler(std::shared_ptr<spirv_cross::Compiler> compiler, bool buildDummySampler, bool combinedImageSamplers)
	{
		if (buildDummySampler)
		{
			const uint32_t sampler = compiler->build_dummy_sampler_for_combined_images();
			if (sampler != 0)
			{
				compiler->set_decoration(sampler, spv::DecorationDescriptorSet, 0);
				compiler->set_decoration(sampler, spv::DecorationBinding, 0);
			}
		}

		if (combinedImageSamplers)
		{
			compiler->build_combined_image_samplers();
			for (auto& remap : compiler->get_combined_image_samplers())
			{
				compiler->set_name(remap.combined_id, "SPIRV_Cross_Combined" + compiler->get_name(remap.image_id) + compiler->get_name(remap.sampler_id));
			}
		}
	}

	void FixupLegacyMetal(const ShaderSnippet& snippet, std::shared_ptr<spirv_cross::Compiler> compiler)
	{
		auto* mslCompiler = static_cast<spirv_cross::CompilerMSL*>(compiler.get());
		auto mslOpts = mslCompiler->get_msl_options();
		mslOpts.msl_version = 0;
		mslOpts.swizzle_texture_samples = false;
		mslOpts.platform = (snippet.shaderTarget == ShaderTarget::kShaderTargetMetalIOS) ? spirv_cross::CompilerMSL::Options::iOS : spirv_cross::CompilerMSL::Options::macOS;
		mslCompiler->set_msl_options(mslOpts);

		const auto& resources = mslCompiler->get_shader_resources();

		uint32_t textureBinding = 0;
		for (const auto& image : resources.separate_images)
		{
			mslCompiler->set_decoration(image.id, spv::DecorationBinding, textureBinding);
			++textureBinding;
		}

		uint32_t samplerBinding = 0;
		for (const auto& sampler : resources.separate_samplers)
		{
			mslCompiler->set_decoration(sampler.id, spv::DecorationBinding, samplerBinding);
			++samplerBinding;
		}
	}

	void FixupLegacyGLSL(const ShaderSnippet& snippet, std::shared_ptr<spirv_cross::Compiler> compiler)
	{
		auto variables = compiler->get_active_interface_variables();
		for (auto& var : variables)
		{
			auto varClass = compiler->get_storage_class(var);
			if ((snippet.stage == ShaderStage::kProgramVertex) && (varClass == spv::StorageClass::StorageClassOutput))
			{
				auto name = compiler->get_name(var);
				if (name.find("out.var.") == 0)
				{
					name.replace(0, 8, "out_var_");
					compiler->set_name(var, name);
				}
			}
			else if ((snippet.stage == ShaderStage::kProgramFragment) && (varClass == spv::StorageClass::StorageClassInput))
			{
				auto name = compiler->get_name(var);
				if (name.find("in.var.") == 0)
				{
					name.replace(0, 7, "in_var_");
					compiler->set_name(var, name);
				}
			}
		}
	}

	int32 GetGLSLTargetVersion(ShaderTarget shaderTarget)
	{
		int32 version = 0;

		if (shaderTarget == ShaderTarget::kShaderTargetGLES20)
		{
			version = 100;
		}
		else if (shaderTarget == ShaderTarget::kShaderTargetGLES30)
		{
			version = 320;
		}
		else
		{
			version = 460;
		}

		return version;
	}

	spv::ExecutionModel GetExecutionModel(ShaderStage stage)
	{
		spv::ExecutionModel model = spv::ExecutionModelMax;
		switch (stage)
		{
			case ShaderStage::kProgramVertex:
			{
				model = spv::ExecutionModelVertex;
				break;
			}
			case ShaderStage::kProgramHull:
			{
				model = spv::ExecutionModelTessellationControl;
				break;
			}
			case ShaderStage::kProgramDomain:
			{
				model = spv::ExecutionModelTessellationEvaluation;
				break;
			}
			case ShaderStage::kProgramGeometry:
			{
				model = spv::ExecutionModelGeometry;
				break;
			}
			case ShaderStage::kProgramFragment:
			{
				model = spv::ExecutionModelFragment;
				break;
			}
			case ShaderStage::kProgramCompute:
			{
				model = spv::ExecutionModelGLCompute;
				break;
			}
			default:
			{
				break;
			}
		}
		return model;
	}

	ShaderSnippetCompiledResult CrossCompile(const ShaderSnippet& snippet, const HLSLCompileResult& hlslCompield)
	{
		ShaderSnippetCompiledResult snippetCompiledResult;

		// get spirv
		const uint32* spirvData = (const uint32*)hlslCompield.data.data();
		const int32   spirvSize = hlslCompield.data.size() / sizeof(uint32);

		bool buildDummySampler     = false;
		bool combinedImageSamplers = false;
		std::shared_ptr<spirv_cross::CompilerGLSL> compiler = nullptr;

		// make version and compiler
		int32 version = 0;
		if (snippet.shaderTarget == ShaderTarget::kShaderTargetGLES20 ||
			snippet.shaderTarget == ShaderTarget::kShaderTargetGLES30 ||
			snippet.shaderTarget == ShaderTarget::kShaderTargetOpenGL
		)
		{
			version = GetGLSLTargetVersion(snippet.shaderTarget);
			compiler = std::make_shared<spirv_cross::CompilerGLSL>(spirvData, spirvSize);
			buildDummySampler = true;
			combinedImageSamplers = true;
			if (version <= 300)
			{
				FixupLegacyGLSL(snippet, compiler);
			}
		}
		else if (snippet.shaderTarget == ShaderTarget::kShaderTargetMetalIOS || snippet.shaderTarget == ShaderTarget::kShaderTargetMetalMac)
		{
			compiler = std::make_shared<spirv_cross::CompilerMSL>(spirvData, spirvSize);
		}

		if (compiler == nullptr)
		{
			snippetCompiledResult.errorMsg = "ShaderTarget not supported.";
			return snippetCompiledResult;
		}

		// get model
		spv::ExecutionModel model = GetExecutionModel(snippet.stage);
		if (model == spv::ExecutionModelMax)
		{
			snippetCompiledResult.errorMsg = "ExecutionModel not supported.";
			return snippetCompiledResult;
		}

		compiler->set_entry_point(snippet.entryPoint, model);

		// option
		spirv_cross::CompilerGLSL::Options options = compiler->get_common_options();
		options.version = version;
		options.es = snippet.shaderTarget == ShaderTarget::kShaderTargetGLES20 || snippet.shaderTarget == ShaderTarget::kShaderTargetGLES30;
		options.force_temporary = false;
		options.separate_shader_objects = true;
		options.flatten_multidimensional_arrays = false;
		options.enable_420pack_extension = snippet.shaderTarget == ShaderTarget::kShaderTargetOpenGL && options.version >= 420;
		options.vulkan_semantics = false;
		options.vertex.fixup_clipspace = false;
		options.vertex.flip_vert_y = false;
		options.vertex.support_nonzero_base_instance = true;
		compiler->set_common_options(options);

		if (snippet.shaderTarget == ShaderTarget::kShaderTargetMetalIOS || snippet.shaderTarget == ShaderTarget::kShaderTargetMetalMac)
		{
			FixupLegacyMetal(snippet, compiler);
		}

		if (buildDummySampler || combinedImageSamplers)
		{
			FixupSampler(compiler, buildDummySampler, combinedImageSamplers);
		}

		try
		{
			const std::string compiledCode = compiler->compile();
			SLCompiledProgram* program = new SLCompiledProgram();
			program->shaderTarget = snippet.shaderTarget;
			program->stage        = snippet.stage;
			program->entryPoint   = snippet.entryPoint;
			program->data.resize(compiledCode.size());
			memcpy(program->data.data(), compiledCode.data(), compiledCode.size());
			snippetCompiledResult.program = program;
		}
		catch (spirv_cross::CompilerError& error)
		{
			const char* errorMsg = error.what();
			snippetCompiledResult.errorMsg = errorMsg;
		}

		return snippetCompiledResult;
	}

	ShaderSnippetCompiledResult CompileHLSLToOther(const SLNormalPass* pass, const SLProgram& program, const ShaderSnippet& snippet)
	{
		ShaderSnippetCompiledResult snippetCompiledResult;

		// compile hlsl
		HLSLCompileResult result = HLSLCompiler::Compile(snippet);
		if (result.data.size() == 0)
		{
			FixErrorLineNumber(result.warningErrorMsg, snippet.fileName, program.lineNo + 1);
			snippetCompiledResult.errorMsg = result.warningErrorMsg;
		}
		else if (snippet.shaderTarget == ShaderTarget::kShaderTargetVulkan || snippet.shaderTarget == ShaderTarget::kShaderTargetHLSL)
		{
			SLCompiledProgram* program = new SLCompiledProgram();
			program->data         = result.data;
			program->shaderTarget = snippet.shaderTarget;
			program->stage        = snippet.stage;
			program->entryPoint   = snippet.entryPoint;
			snippetCompiledResult.program = program;
		}
		else
		{
			snippetCompiledResult = CrossCompile(snippet, result);
		}

		return snippetCompiledResult;
	}

	void CompileGLSLToOther(const SLNormalPass* pass, const SLProgram& program, const ShaderSnippet& snippet)
	{

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
		ProcessShaderSnippets(shaderInfo, program.type, source, programParams, snippets);

		// compile code
		for (int32 snippetIndex = 0; snippetIndex < snippets.size(); ++snippetIndex)
		{
			const ShaderSnippet& snippet = snippets[snippetIndex];
			switch (snippet.sourceType)
			{
			case ProgramType::kCG:
			case ProgramType::kHLSL:
			{
				CompileHLSLToOther(pass, program, snippet);
				break;
			}
			case ProgramType::kGLSL:
			{
				CompileGLSLToOther(pass, program, snippet);
				break;
			}
			default:
				printf("ProgramType[%d] not support!", snippet.sourceType);
				break;
			}
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