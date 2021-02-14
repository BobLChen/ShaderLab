set(SL_PARSER_HDRS
    SLParser.h
    SLParserTypes.h
    SLParserData.h
    SLParserYacc.hpp
    SLParserLex.l
    SLParserYacc.y
)

set(SL_PARSER_SRCS
    SLParser.cpp
    SLParserLex.cpp
    SLParserYacc.cpp
)

add_library(shaderlab STATIC
	${SL_PARSER_HDRS}
	${SL_PARSER_SRCS}
)

source_group(ShaderLab\\ FILES ${SL_PARSER_HDRS} ${SL_PARSER_SRCS})