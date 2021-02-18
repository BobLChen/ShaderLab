#pragma once

#include <string>
#include <xstring>
#include <vector>
#include <functional>

#include "Common/Common.h"
#include "SLCompiler.h"

namespace shaderlab
{
	struct HLSLCompileResult
	{
		std::vector<uint8_t>			data;
		std::string						warningErrorMsg;
	};

	class HLSLCompiler
	{
	public:

		static bool Init();

		static bool Destroy();

		static HLSLCompileResult Compile(const ShaderSnippet& snippet);

	private:

	};
}

