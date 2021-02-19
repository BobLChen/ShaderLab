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

	// compile shader
	shaderlab::CompileShaderInfo info = { };
	info.shader          = shader;
	info.fileName        = option.input.c_str();
	info.includeCallback = OnLoadInlcudeCallback;
	shaderlab::SLCompiler::Compile(info);

	delete shader;
    return 0;
}
