set(SHADER_LAB_PARSER_HDRS
	SLParser.h
	SLParserData.h
	SLParserTypes.h
	SLParserYacc.hpp
)

set(SHADER_LAB_PARSER_SRCS
	SLParserData.cpp
	SLParserLex.cpp
	SLParserYacc.cpp
)

add_library(ShaderLabParser STATIC
	${SHADER_LAB_PARSER_HDRS}
	${SHADER_LAB_PARSER_SRCS}
)

source_group(shaderlab FILES ${SHADER_LAB_PARSER_SRCS} ${SHADER_LAB_PARSER_HDRS})