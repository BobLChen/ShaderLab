#include <stdio.h>
#include <string>

#include "Parser/SLParser.h"
#include "Compiler/SLCompiler.h"
#include "Compiler/HLSLCompiler.h"

bool ReadTextFile(const std::string &filename, std::string &output)
{
	FILE *file = fopen(filename.c_str(), "rt");
	if (!file) {
		printf("file not found :%s\n", filename.c_str());
		return false;
	}
	fseek(file, 0, SEEK_END);
	int dataSize = ftell(file);
	fseek(file, 0, SEEK_SET);
	if (dataSize <= 0) {
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

int main(int argc, char const *argv[])
{
    /*std::string data;
    ReadTextFile("CGSourceShader.shader", data);
	shaderlab::SLShader* shader = ParseShaderLab(data.c_str(), data.size());
	delete shader;*/

	shaderlab::SLCompiler::Init();

	std::string data0;
	ReadTextFile("CalcLight.hlsl", data0);

	shaderlab::ShaderSnippet snippet;
	snippet.fileName = "CalcLight.hlsl";
	snippet.source = data0.data();
	snippet.sourceLength = data0.size();
	snippet.entryPoint = "main";
	snippet.shaderModel.majorVer = 6;
	snippet.shaderModel.minorVer = 0;
	snippet.shaderTarget = shaderlab::ShaderTarget::kShaderTargetGLES20;
	snippet.stage = shaderlab::ShaderStage::kProgramFragment;
	shaderlab::HLSLCompiler::Compile(snippet);

    printf("Done\n");

    return 0;
}
