#pragma once

#include <string>
#include <vector>
#include <functional>

#include "Common/Common.h"
#include "SLCompiler.h"

namespace shaderlab
{
	struct GLSLCompileResult
	{
		std::vector<uint8>				data;
		std::string						warningErrorMsg;
	};

	class GLSLCompiler
	{
	public:

		static bool Init();

		static bool Destroy();

		static GLSLCompileResult Compile(const ShaderSnippet& snippet);

	};
}