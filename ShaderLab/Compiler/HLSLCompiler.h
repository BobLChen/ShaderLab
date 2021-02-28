#pragma once

#include <string>
#include <vector>
#include <functional>

#include "Common/Common.h"
#include "SLCompiler.h"

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

	struct HLSLCompileResult
	{
		std::vector<uint8>				data;
		std::string						warningErrorMsg;
	};

	class HLSLCompiler
	{
	public:

		static bool Init();

		static bool Destroy();

		static HLSLCompileResult Compile(const ShaderSnippet& snippet);
	};
}

