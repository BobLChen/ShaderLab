#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

#include "parser/SLParser.h"
#include "compiler/SLCompiler.h"

enum ProcessType
{
	kProcessCompile,
	kProcessImport
};

struct Options {
	Options()
	{
		process = kProcessCompile;
	}
	std::string input;
	std::string output;
	std::string include;
	ProcessType process;
};

Options options;

bool readTextFile(const std::string &filename, std::string &output)
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

bool includeOpenCallback(bool isSystem, const char *fileName, const char *parentFileName, const char *parent, std::string &output, void *data)
{
	return readTextFile(fileName, output);
}

bool compileShader(const std::string &inputfile, std::string &compiled)
{
	std::string source;
	bool success = readTextFile(inputfile, source);
	
	if (success) {
		success = shaderlab::compileCG(source, includeOpenCallback, compiled);
	}
	
	return success;
}

bool convertToJson(const std::string &inputfile, std::string &outputfile)
{
	std::string compiled;
	readTextFile(inputfile, compiled);

	std::vector<std::string> errors;
	shaderlab::SLShader *shader = ParseShader(compiled.c_str(), compiled.size(), errors);
	
	if (errors.size() == 0) {
		Json::Value jsonValue;
		shader->ToJson(jsonValue);

		Json::FastWriter fastWsriter;
		fastWsriter.omitEndingLineFeed();
		
		std::string jsonString = fastWsriter.write(jsonValue);
		
		FILE* jsonFile = fopen(outputfile.c_str(), "wb");
		fwrite(jsonString.c_str(), jsonString.size(), 1, jsonFile);
		fclose(jsonFile);

		printf("%s: %s\n", "Json file      ", outputfile.c_str());
	}
	else {
		for (int i = 0; i < errors.size(); ++i) {
			printf("ERROR:%s\n", errors[i].c_str());
		}
	}

	delete shader;
	return errors.size() == 0;
}

void Usage() {
	printf("Usage: shader_parser [options] -i input\n");
	printf("\n");
	printf("Main options:\n");
	printf("  -h | -?               show help.\n");
	printf("  -o <output>           output file name.\n");
	printf("  -include <include>    *.cginc include folder\n");
	printf("  -compile <compile>    compile shdaer\n");
	printf("  -import <compile>     convert compiled shader to json \n");
}

int main(int argc, char* argv[])
{
	const int argc_check = argc - 1;

	for (int i = 1; i < argc; ++i) {
		if (!strcmp("-h", argv[i]) || !strcmp("-?", argv[i])) {
			Usage();
			return 0;
		}
		else if (!strcmp("-i", argv[i]) && i < argc_check) {
			options.input = argv[++i];
		}
		else if (!strcmp("-o", argv[i]) && i < argc_check) {
			options.output = argv[++i];
		}
		else if (!strcmp("-include", argv[i]) && i < argc_check) {
			options.include = argv[++i];
		}
		else if (!strcmp("-compile", argv[i]) && i < argc_check) {
			options.process = kProcessCompile;
		}
		else if (!strcmp("-import", argv[i]) && i < argc_check) {
			options.process = kProcessImport;
		}
	}
	
	if (argc < 3 || options.input.empty()) {
		Usage();
		return -1;
	}

	if (options.output.empty()) {
		options.output = options.input + ".json";
	}

	printf("%s: %s\n", "input          ", options.input.c_str());
	printf("%s: %s\n", "output         ", options.output.c_str());
	printf("%s: %s\n", "include        ", options.include.c_str());
	printf("%s: %s\n", "process        ", options.process == kProcessCompile ? "compile" : "import");

	std::string tempOutputFile = "Compiled_" + options.input;
	if (options.process == kProcessCompile) {
		std::string compiled;
		bool success = compileShader(options.input, compiled);

		if (!success) {
			printf("compile shader failed.");
			return -1;
		}
		
		FILE* f = fopen(tempOutputFile.c_str(), "wb");
		fwrite(compiled.c_str(), compiled.size(), 1, f);
		fclose(f);
		
		printf("%s: %s\n", "compiled file  ", tempOutputFile.c_str());
	}
	else {
		tempOutputFile = options.input;
	}
	
	bool success = convertToJson(tempOutputFile, options.output);
	if (success) {
		printf("Done!");
	}
	else {
		printf("convert to json failed.");
		return -1;
	}
	
    return 0;
}