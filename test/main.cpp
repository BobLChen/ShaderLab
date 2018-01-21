#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "SLParser.h"

int main(int argc,char* argv[])
{
    std::ifstream istream("CgBatchOutput.shader");
    std::string text((std::istreambuf_iterator<char>(istream)), std::istreambuf_iterator<char>());
    
	shaderlab::SLShader *shader = ParseShader(text.c_str(), text.size());

    printf("shader:%s\n", shader->toString().c_str());
	
	system("pause");
    return 0;
}