#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include <functional>

#include "Common/Common.h"
#include "Parser/SLParser.h"
#include "Parser/SLParserTypes.h"

namespace shaderlab
{
	struct ShaderModel
	{
		uint8 majorVer : 6;
		uint8 minorVer : 2;
		
		uint32 FullVersion() const noexcept
		{
			return (majorVer << 2) | minorVer;
		}

		bool operator<(const ShaderModel& other) const noexcept
		{
			return this->FullVersion() < other.FullVersion();
		}

		bool operator==(const ShaderModel& other) const noexcept
		{
			return this->FullVersion() == other.FullVersion();
		}

		bool operator>(const ShaderModel& other) const noexcept
		{
			return other < *this;
		}

		bool operator<=(const ShaderModel& other) const noexcept
		{
			return (*this < other) || (*this == other);
		}

		bool operator>=(const ShaderModel& other) const noexcept
		{
			return (*this > other) || (*this == other);
		}
	};

	std::wstring ShaderProfileName(ShaderStage stage, ShaderModel shaderModel);

	std::string GetShaderTargetName(ShaderTarget shaderTarget);

	ShaderTarget GetShaderTarget(const std::string& name);

	struct PragmaParam
	{
		std::string					option;
		std::vector<std::string>	values;
	};

	struct MultiCompileParam
	{
		MultiCompileParam(const std::vector<std::string>& inKeywords)
			: keywords(inKeywords)
		{

		}

		std::vector<std::string>	keywords;
	};

	struct ProgramParameters 
	{
		ProgramParameters()
			: shaderTarget(0)
		{

		}

		void SetPragmaParams(const std::vector<PragmaParam>& params)
		{
			for (size_t i = 0; i < params.size(); ++i) 
			{
				const PragmaParam& pragma = params[i];
				if (pragma.values.size() < 1)
				{
					printf("not enough params\n");
					continue;
				}
				if (pragma.option == "multi_compile") 
				{
					keywords.push_back(pragma.values);
				}
				else if (pragma.option == "vertex")
				{
					entryName[kProgramVertex] = pragma.values[0];
				}
				else if (pragma.option == "fragment")
				{
					entryName[kProgramFragment] = pragma.values[0];
				}
				else if (pragma.option == "compute")
				{
					entryName[kProgramCompute] = pragma.values[0];
				}
				else if (pragma.option == "geometry")
				{
					entryName[kProgramGeometry] = pragma.values[0];
				}
				else if (pragma.option == "hull")
				{
					entryName[kProgramHull] = pragma.values[0];
				}
				else if (pragma.option == "domain")
				{
					entryName[kProgramDomain] = pragma.values[0];
				}
				else if (pragma.option == "mesh")
				{
					entryName[kProgramMesh] = pragma.values[0];
				}
				else if (pragma.option == "task")
				{
					entryName[kProgramTask] = pragma.values[0];
				}
				else if (pragma.option == "rgen")
				{
					entryName[kProgramRayGen] = pragma.values[0];
				}
				else if (pragma.option == "rint")
				{
					entryName[kProgramRayInt] = pragma.values[0];
				}
				else if (pragma.option == "rahit")
				{
					entryName[kProgramRayAHit] = pragma.values[0];
				}
				else if (pragma.option == "rchit")
				{
					entryName[kProgramRayCHit] = pragma.values[0];
				}
				else if (pragma.option == "rmiss")
				{
					entryName[kProgramRayMiss] = pragma.values[0];
				}
				else if (pragma.option == "rcall")
				{
					entryName[kProgramRayRcall] = pragma.values[0];
				}
				else if (pragma.option == "target")
				{
					for (size_t idx = 0; idx < pragma.values.size(); ++idx)
					{
						shaderTarget = shaderTarget | (1 << GetShaderTarget(pragma.values[idx]));
					}
				}
			}
		}

		bool HasProgram() const
		{
			for (int i = 0; i < kProgramCount; ++i) 
			{
				if (!entryName[i].empty()) 
				{
					return true;
				}
			}
			return false;
		}

		bool HasProgram(ShaderStage p) const
		{
			return !entryName[p].empty();
		}

		uint32							shaderTarget;
		std::vector<MultiCompileParam>	keywords;
		std::string						entryName[kProgramCount];
	};

	struct MacroDefine
	{
		std::string						name;
		std::string						value;
	};

	typedef std::function<std::string(const char* includeName)> IncludeCallback;

	struct ShaderSnippet
	{
		const char*						fileName;
		ProgramType						sourceType;
		const char*						source;
		uint32							sourceLength;
		const char*						entryPoint;
		ShaderStage						stage;
		ShaderModel						shaderModel;
		ShaderTarget					shaderTarget;
		std::vector<MacroDefine>		defines;
		IncludeCallback					includeCallback;
	};

	struct CompileShaderInfo
	{
		SLShader*						shader;
		const char*						fileName;
		IncludeCallback					includeCallback;
	};

	struct ShaderSnippetCompiledResult
	{
		std::string						errorMsg;
		SLCompiledProgram*				program;
	};

	class SLCompiler
	{
	public:

		static bool Init();

		static bool Destroy();

		static SLShader* Compile(const CompileShaderInfo& shader);

	};
}