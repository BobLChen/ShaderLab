#include <stdio.h>
#include <string>

#include "Parser/SLParser.h"
#include "Compiler/SLCompiler.h"
#include "Compiler/HLSLCompiler.h"

bool ReadTextFile(const std::string &filename, std::string &output)
{
	FILE *file = fopen(filename.c_str(), "rt");
	if (!file) 
	{
		printf("file not found :%s\n", filename.c_str());
		return false;
	}

	fseek(file, 0, SEEK_END);
	int dataSize = ftell(file);
	fseek(file, 0, SEEK_SET);
	if (dataSize <= 0) 
	{
		fclose(file);
		printf("not found data :%s\n", filename.c_str());
		return false;
	}

	output.resize(dataSize);
	int readSize = fread(&(*output.begin()), 1, dataSize, file);
	fclose(file);
	output.resize(readSize);

	return true;
}

std::string OnLoadInlcudeCallback(const char* includeName)
{
	std::string includeData;
	if (!ReadTextFile(includeName, includeData))
	{
		printf("Failed to load include file:%s\n", includeName);
	}
	return includeData;
}

struct ArgOption
{
	std::string		input;
	std::string		output;
	std::string		include;
};

void Usage() 
{
	printf("Usage: ShaderCross\n");
	printf("\n");
	printf("Main options:\n");
	printf("  -h | -?               show help.\n");
	printf("  -i                    input shaderlab file name.\n");
	printf("  -o                    output compiled shader file name.\n");
	printf("  -include              include path.\n");
}

ArgOption ParseOptions(int argc, char const *argv[])
{
	ArgOption option;

	const int argcCheck = argc - 1;

	for (int i = 1; i < argc; ++i)
	{
		if (!strcmp("-h", argv[i]) || !strcmp("-?", argv[i]))
		{
			// nothing
		}
		else if (!strcmp("-i", argv[i]) && i < argcCheck)
		{
			option.input = argv[++i];
		}
		else if (!strcmp("-o", argv[i]) && i < argcCheck) {
			option.output = argv[++i];
		}
		else if (!strcmp("-include", argv[i]) && i < argcCheck) {
			option.include = argv[++i];
		}
	}

	return option;
}

int main(int argc, char const *argv[])
{
	// get options
	ArgOption option = ParseOptions(argc, argv);
	if (argc < 2 || option.input.empty())
	{
		Usage();
		return 0;
	}

	// load shaderlab text
    std::string shaderLabData;
	if (!ReadTextFile(option.input.c_str(), shaderLabData))
	{
		return 1;
	}

	// parse shaderlab
	shaderlab::SLShader* shader = ParseShaderLab(shaderLabData.c_str(), shaderLabData.size());
	
	// init compiler
	shaderlab::SLCompiler::Init();

	// compile hlsl
	for (int32 shaderIdx = 0; shaderIdx < shader->subShaders.size(); ++shaderIdx)
	{
		shaderlab::SLSubShader* subShader = shader->subShaders[shaderIdx];
		for (int32 subShaderIdx = 0; subShaderIdx < subShader->passes.size(); ++subShaderIdx)
		{
			shaderlab::SLPassBase* slpass = subShader->passes[subShaderIdx];
			if (slpass->type == shaderlab::SLPassBase::kPassNormal)
			{
				shaderlab::SLNormalPass* npass = (shaderlab::SLNormalPass*)slpass;
				shaderlab::SLProgram& program  = npass->program;
				
				shaderlab::ShaderSnippet snippet;
				snippet.fileName        = option.input.c_str();
				snippet.source          = program.source.c_str();
				snippet.sourceLength    = program.source.size();
				snippet.entryPoint      = "main";
				snippet.shaderModel     = { 6, 0 };
				snippet.shaderTarget    = shaderlab::ShaderTarget::kShaderTargetGLES20;
				snippet.stage		    = shaderlab::ShaderStage::kProgramFragment;
				snippet.includeCallback = OnLoadInlcudeCallback;

				shaderlab::HLSLCompileResult result = shaderlab::HLSLCompiler::Compile(snippet);
				printf("Status:%d Message:%s\n", result.data.size() != 0 ? "Success" : "Failed", result.warningErrorMsg.c_str());
			}
		}
	}

	delete shader;
    return 0;
}
