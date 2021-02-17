set PATH=%PATH%;.\WinFlexBison\bin
.\WinFlexBison\bin\flex --nounistd -o SLParserLex.cpp SLParserLex.l
.\WinFlexBison\bin\bison -d -b y -o SLParserYacc.cpp -p "shaderlab" SLParserYacc.y
@REM .\WinFlexBison\bin\bison -d -b y -o SLParserYacc.cpp SLParserYacc.y
pause
