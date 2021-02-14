#include <stdio.h>
#include <string>

#include "SLParser.h"

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
    std::string data;
    ReadTextFile("CGSourceShader.shader", data);
	
	shaderlab::SLShader* shader = ParseShaderLab(data.c_str(), data.size());

    printf("Done\n");

    delete shader;

    return 0;
}
