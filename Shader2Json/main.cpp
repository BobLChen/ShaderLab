#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

#include "parser/SLParser.h"
#include "compiler/SLCompiler.h"

bool ReadTextFile(const std::string &filename, std::string &output)
{
	FILE *file = fopen(filename.c_str(), "rt");
	if (!file) {
		return false;
	}
	fseek(file, 0, SEEK_END);
	int dataSize = ftell(file);
	fseek(file, 0, SEEK_SET);
	if (dataSize <= 0) {
		fclose(file);
		return false;
	}
	output.resize(dataSize);
	int readSize = fread(&(*output.begin()), 1, dataSize, file);
	fclose(file);
	output.resize(readSize);
	return true;
}

bool includeOpenCallback(bool isSystem, const char *fileName, const char *parentFileName, const char *parent, std::string &output, void *data)
{
	return ReadTextFile(fileName, output);
}

int main(int argc, char* argv[])
{
	std::string source;
	std::string compiled;
	ReadTextFile("nosurfce.shader", source);
	shaderlab::compileCG(source, includeOpenCallback, compiled);
	FILE* f = fopen("nosurfceOutput.shader", "wb");
	fwrite(compiled.c_str(), compiled.size(), 1, f);
	fclose(f);
	
	std::vector<std::string> errors;
	shaderlab::SLShader *shader = ParseShader(compiled.c_str(), compiled.size(), errors);
    printf("shader:%s\n", shader->toString().c_str());
	if (errors.size() > 0) {
		for (std::size_t i = 0; i < errors.size(); ++i) {
			printf("%s\n", errors[i].c_str());
		}
	} else {
		printf("Parse success.\n");
	}

	if (errors.size() == 0) {
		Json::Value jsonValue;
		shader->ToJson(jsonValue);
		Json::FastWriter fastWsriter;
		fastWsriter.omitEndingLineFeed();
		std::string jsonString = fastWsriter.write(jsonValue);

		FILE* jsonFile = fopen("output.json", "wb");
		fwrite(jsonString.c_str(), jsonString.size(), 1, jsonFile);
		fclose(jsonFile);

		printf("%s\n", jsonString.c_str());
	}
	
	system("pause");
    return 0;
}