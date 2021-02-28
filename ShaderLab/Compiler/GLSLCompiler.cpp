#include <algorithm>
#include <string>
#include <fstream>

#include "GLSLCompiler.h"

#include "glslang/Include/ShHandle.h"
#include "glslang/Include/ResourceLimits.h"
#include "glslang/Public/ShaderLang.h"

#include "SPIRV/GlslangToSpv.h"
#include "SPIRV/GLSL.std.450.h"
#include "SPIRV/doc.h"
#include "SPIRV/disassemble.h"

namespace shaderlab
{
	const TBuiltInResource DefaultTBuiltInResource = {
		/* .MaxLights = */ 32,
		/* .MaxClipPlanes = */ 6,
		/* .MaxTextureUnits = */ 32,
		/* .MaxTextureCoords = */ 32,
		/* .MaxVertexAttribs = */ 64,
		/* .MaxVertexUniformComponents = */ 4096,
		/* .MaxVaryingFloats = */ 64,
		/* .MaxVertexTextureImageUnits = */ 32,
		/* .MaxCombinedTextureImageUnits = */ 80,
		/* .MaxTextureImageUnits = */ 32,
		/* .MaxFragmentUniformComponents = */ 4096,
		/* .MaxDrawBuffers = */ 32,
		/* .MaxVertexUniformVectors = */ 128,
		/* .MaxVaryingVectors = */ 8,
		/* .MaxFragmentUniformVectors = */ 16,
		/* .MaxVertexOutputVectors = */ 16,
		/* .MaxFragmentInputVectors = */ 15,
		/* .MinProgramTexelOffset = */ -8,
		/* .MaxProgramTexelOffset = */ 7,
		/* .MaxClipDistances = */ 8,
		/* .MaxComputeWorkGroupCountX = */ 65535,
		/* .MaxComputeWorkGroupCountY = */ 65535,
		/* .MaxComputeWorkGroupCountZ = */ 65535,
		/* .MaxComputeWorkGroupSizeX = */ 1024,
		/* .MaxComputeWorkGroupSizeY = */ 1024,
		/* .MaxComputeWorkGroupSizeZ = */ 64,
		/* .MaxComputeUniformComponents = */ 1024,
		/* .MaxComputeTextureImageUnits = */ 16,
		/* .MaxComputeImageUniforms = */ 8,
		/* .MaxComputeAtomicCounters = */ 8,
		/* .MaxComputeAtomicCounterBuffers = */ 1,
		/* .MaxVaryingComponents = */ 60,
		/* .MaxVertexOutputComponents = */ 64,
		/* .MaxGeometryInputComponents = */ 64,
		/* .MaxGeometryOutputComponents = */ 128,
		/* .MaxFragmentInputComponents = */ 128,
		/* .MaxImageUnits = */ 8,
		/* .MaxCombinedImageUnitsAndFragmentOutputs = */ 8,
		/* .MaxCombinedShaderOutputResources = */ 8,
		/* .MaxImageSamples = */ 0,
		/* .MaxVertexImageUniforms = */ 0,
		/* .MaxTessControlImageUniforms = */ 0,
		/* .MaxTessEvaluationImageUniforms = */ 0,
		/* .MaxGeometryImageUniforms = */ 0,
		/* .MaxFragmentImageUniforms = */ 8,
		/* .MaxCombinedImageUniforms = */ 8,
		/* .MaxGeometryTextureImageUnits = */ 16,
		/* .MaxGeometryOutputVertices = */ 256,
		/* .MaxGeometryTotalOutputComponents = */ 1024,
		/* .MaxGeometryUniformComponents = */ 1024,
		/* .MaxGeometryVaryingComponents = */ 64,
		/* .MaxTessControlInputComponents = */ 128,
		/* .MaxTessControlOutputComponents = */ 128,
		/* .MaxTessControlTextureImageUnits = */ 16,
		/* .MaxTessControlUniformComponents = */ 1024,
		/* .MaxTessControlTotalOutputComponents = */ 4096,
		/* .MaxTessEvaluationInputComponents = */ 128,
		/* .MaxTessEvaluationOutputComponents = */ 128,
		/* .MaxTessEvaluationTextureImageUnits = */ 16,
		/* .MaxTessEvaluationUniformComponents = */ 1024,
		/* .MaxTessPatchComponents = */ 120,
		/* .MaxPatchVertices = */ 32,
		/* .MaxTessGenLevel = */ 64,
		/* .MaxViewports = */ 16,
		/* .MaxVertexAtomicCounters = */ 0,
		/* .MaxTessControlAtomicCounters = */ 0,
		/* .MaxTessEvaluationAtomicCounters = */ 0,
		/* .MaxGeometryAtomicCounters = */ 0,
		/* .MaxFragmentAtomicCounters = */ 8,
		/* .MaxCombinedAtomicCounters = */ 8,
		/* .MaxAtomicCounterBindings = */ 1,
		/* .MaxVertexAtomicCounterBuffers = */ 0,
		/* .MaxTessControlAtomicCounterBuffers = */ 0,
		/* .MaxTessEvaluationAtomicCounterBuffers = */ 0,
		/* .MaxGeometryAtomicCounterBuffers = */ 0,
		/* .MaxFragmentAtomicCounterBuffers = */ 1,
		/* .MaxCombinedAtomicCounterBuffers = */ 1,
		/* .MaxAtomicCounterBufferSize = */ 16384,
		/* .MaxTransformFeedbackBuffers = */ 4,
		/* .MaxTransformFeedbackInterleavedComponents = */ 64,
		/* .MaxCullDistances = */ 8,
		/* .MaxCombinedClipAndCullDistances = */ 8,
		/* .MaxSamples = */ 4,
		/* .maxMeshOutputVerticesNV = */ 256,
		/* .maxMeshOutputPrimitivesNV = */ 512,
		/* .maxMeshWorkGroupSizeX_NV = */ 32,
		/* .maxMeshWorkGroupSizeY_NV = */ 1,
		/* .maxMeshWorkGroupSizeZ_NV = */ 1,
		/* .maxTaskWorkGroupSizeX_NV = */ 32,
		/* .maxTaskWorkGroupSizeY_NV = */ 1,
		/* .maxTaskWorkGroupSizeZ_NV = */ 1,
		/* .maxMeshViewCountNV = */ 4,
		/* .maxDualSourceDrawBuffersEXT = */ 1,

		/* .limits = */ {
		/* .nonInductiveForLoops = */ 1,
		/* .whileLoops = */ 1,
		/* .doWhileLoops = */ 1,
		/* .generalUniformIndexing = */ 1,
		/* .generalAttributeMatrixVectorIndexing = */ 1,
		/* .generalVaryingIndexing = */ 1,
		/* .generalSamplerIndexing = */ 1,
		/* .generalVariableIndexing = */ 1,
		/* .generalConstantMatrixVectorIndexing = */ 1,
	} };

	void GenerateDefineString(const ShaderSnippet& snippet, std::string& outDefines)
	{
		std::string stageString = "STAGE_" + GetShaderStage(snippet.shaderStage);
		std::transform(stageString.begin(), stageString.end(), stageString.begin(), ::toupper);

		// stage
		outDefines.append("#define ");
		outDefines.append(stageString);
		outDefines.append("\n");
		
		// macro
		for (int32 i = 0; i < snippet.defines.size(); ++i)
		{
			const MacroDefine& macro = snippet.defines[i];
			if (macro.name.empty())
			{
				continue;
			}

			outDefines.append("#define ");
			outDefines.append(macro.name);

			if (!macro.value.empty())
			{
				outDefines.append("=");
				outDefines.append(macro.value);
			}

			outDefines.append("\n");
		}
	}

	EShLanguage GetEShLanguage(ShaderStage stage)
	{
		if (stage == ShaderStage::kProgramVertex)
		{
			return EShLanguage::EShLangVertex;
		}
		else if (stage == ShaderStage::kProgramHull)
		{
			return EShLanguage::EShLangTessControl;
		}
		else if (stage == ShaderStage::kProgramDomain)
		{
			return EShLanguage::EShLangTessEvaluation;
		}
		else if (stage == ShaderStage::kProgramGeometry)
		{
			return EShLanguage::EShLangGeometry;
		}
		else if (stage == ShaderStage::kProgramFragment)
		{
			return EShLanguage::EShLangFragment;
		}
		else if (stage == ShaderStage::kProgramCompute)
		{
			return EShLanguage::EShLangCompute;
		}
		else if (stage == ShaderStage::kProgramRayGen)
		{
			return EShLanguage::EShLangRayGen;
		}
		else if (stage == ShaderStage::kProgramRayInt)
		{
			return EShLanguage::EShLangIntersect;
		}
		else if (stage == ShaderStage::kProgramRayAHit)
		{
			return EShLanguage::EShLangAnyHit;
		}
		else if (stage == ShaderStage::kProgramRayCHit)
		{
			return EShLanguage::EShLangClosestHit;
		}
		else if (stage == ShaderStage::kProgramRayMiss)
		{
			return EShLanguage::EShLangMiss;
		}
		else if (stage == ShaderStage::kProgramRayRcall)
		{
			return EShLanguage::EShLangCallable;
		}
		else if (stage == ShaderStage::kProgramMesh)
		{
			return EShLanguage::EShLangMeshNV;
		}
		else if (stage == ShaderStage::kProgramTask)
		{
			return EShLanguage::EShLangTaskNV;
		}

		return EShLanguage::EShLangVertex;
	}

	class GLSLIncludeHandler : public glslang::TShader::Includer
	{
	public:
		GLSLIncludeHandler(IncludeCallback loadCallback)
			: m_LoadCallback(std::move(loadCallback))
		{

		}

		virtual IncludeResult* includeLocal(const char* headerName, const char* includerName, size_t inclusionDepth) override
		{
			return ReadIncludeData(headerName, includerName, inclusionDepth);
		}

		virtual IncludeResult* includeSystem(const char* headerName, const char* includerName, size_t inclusionDepth) override
		{
			return ReadIncludeData(headerName, includerName, inclusionDepth);
		}

		virtual void releaseInclude(IncludeResult* result) override
		{
			if (result != nullptr) 
			{
				delete result;
			}
		}

		virtual ~GLSLIncludeHandler() override 
		{
			for (int32 i = 0; i < m_Datas.size(); ++i)
			{
				delete[] m_Datas[i].data;
			}

			m_Datas.clear();
		}

		IncludeResult* ReadIncludeData(const char* headerName, const char* includerName, size_t inclusionDepth)
		{
			std::string path = GetDirectory(includerName) + "/" + headerName;
			ByteArray bytes  = m_LoadCallback(path.c_str());
			m_Datas.push_back(bytes);
			return new IncludeResult(path, bytes.data, bytes.size, bytes.data);
		}

		std::string GetDirectory(const std::string& path) const
		{
			size_t last = path.find_last_of("/\\");
			return last == std::string::npos ? "." : path.substr(0, last);
		}

	protected:
		IncludeCallback         m_LoadCallback;
		std::vector<ByteArray>  m_Datas;
	};

	bool GLSLCompiler::Init()
	{
		glslang::InitializeProcess();
		return true;
	}

	bool GLSLCompiler::Destroy()
	{
		glslang::FinalizeProcess();
		return true;
	}
	
	GLSLCompileResult GLSLCompiler::Compile(const ShaderSnippet& snippet)
	{
		glslang::EShClient Client = glslang::EShClientNone;
		glslang::EShTargetLanguageVersion TargetVersion = glslang::EShTargetSpv_1_5;
		glslang::EShTargetClientVersion ClientVersion = glslang::EShTargetVulkan_1_2;
		int32 ClientInputSemanticsVersion = 100;
		int32 defaultVersion = 110;

		GLSLCompileResult glslResult;

		// message
		EShMessages messages = EShMsgDefault;
		messages = (EShMessages)(messages | EShMsgSpvRules);
		messages = (EShMessages)(messages | EShMsgVulkanRules);

		// include
		GLSLIncludeHandler includer(std::move(snippet.includeCallback));

		// resources
		TBuiltInResource Resources = DefaultTBuiltInResource;

		// defines
		std::string strDefine;
		GenerateDefineString(snippet, strDefine);

		// shader stage
		EShLanguage shaderStage = GetEShLanguage(snippet.shaderStage);

		// shader
		glslang::TShader shader(shaderStage);
		shader.setStringsWithLengthsAndNames(&snippet.source, nullptr, &snippet.fileName, 1);
		shader.setEntryPoint(snippet.entryPoint);
		shader.setSourceEntryPoint("main");
		shader.setPreamble(strDefine.c_str());
		shader.setNoStorageFormat(false);
		shader.setNanMinMaxClamp(false);
		shader.setEnvInput(glslang::EShSourceGlsl, shaderStage, glslang::EShClientVulkan, ClientInputSemanticsVersion);
		shader.setEnvClient(glslang::EShClientVulkan, ClientVersion);
		shader.setEnvTarget(glslang::EShTargetSpv, TargetVersion);
		
		// parse shader
		if (!shader.parse(&Resources, defaultVersion, false, messages, includer))
		{
			glslResult.warningErrorMsg += shader.getInfoLog();
			glslResult.warningErrorMsg += shader.getInfoDebugLog();
			return glslResult;
		}

		// process program
		glslang::TProgram program;
		program.addShader(&shader);

		// link
		if (!program.link(messages))
		{
			glslResult.warningErrorMsg += program.getInfoLog();
			glslResult.warningErrorMsg += program.getInfoDebugLog();
			return glslResult;
		}

		// map io
		if (!program.mapIO())
		{
			glslResult.warningErrorMsg += program.getInfoLog();
			glslResult.warningErrorMsg += program.getInfoDebugLog();
			return glslResult;
		}

		std::vector<uint32> spirv;
		spv::SpvBuildLogger logger;
		glslang::SpvOptions spvOptions;
		spvOptions.disableOptimizer = false;
		spvOptions.optimizeSize     = false;
		glslang::GlslangToSpv(*program.getIntermediate(shaderStage), spirv, &logger, &spvOptions);

		// spirv data
		glslResult.data.resize(spirv.size() * sizeof(uint32));
		memcpy(glslResult.data.data(), spirv.data(), glslResult.data.size());

		return glslResult;
	}

}