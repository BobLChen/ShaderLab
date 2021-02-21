#!/bin/bash

lex --nounistd -o SLParserLex.cpp SLParserLex.l
yacc -d -b y -o SLParserYacc.cpp -p "shaderlab" SLParserYacc.y