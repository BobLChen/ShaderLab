#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "SLParser.h"

int main(int argc,char* argv[])
{
    std::ifstream istream("CgBatchOutput.shader");
	std::string text((std::istreambuf_iterator<char>(istream)), std::istreambuf_iterator<char>());
	std::vector<std::string> errors;
	shaderlab::SLShader *shader = ParseShader(text.c_str(), text.size(), errors);
    printf("shader:%s\n", shader->toString().c_str());
	if (errors.size() > 0) {
		for (std::size_t i = 0; i < errors.size(); ++i) {
			printf("%s\n", errors[i].c_str());
		}
	} else {
		printf("Parse success.\n");
	}
	system("pause");
    return 0;
}