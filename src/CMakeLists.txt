set(PARSER_HDRS
	parser/SLParser.h
	parser/SLParserData.h
	parser/SLParserTypes.h
	parser/SLParserYacc.hpp
)

set(PARSER_SRCS
	parser/SLParserData.cpp
	parser/SLParserLex.cpp
	parser/SLParserYacc.cpp
)

set(COMPILER_HDRS
	compiler/SLCompiler.h
)

set(COMPILER_SRCS
	compiler/SLCompiler.cpp
)

set(UTILS_HDRS
	utils/SLStringUtils.h
	utils/json.h
	utils/json-forwards.h
)

set(UTILS_SRCS
	utils/SLStringUtils.cpp
	utils/jsoncpp.cpp
)

add_library(shaderlab STATIC
	${PARSER_HDRS}
	${PARSER_SRCS}
	${COMPILER_HDRS}
	${COMPILER_SRCS}
	${UTILS_HDRS}
	${UTILS_SRCS}
)

include_directories(
	../external/cg/include
)

source_group(src\\parser FILES ${PARSER_SRCS} ${PARSER_HDRS})
source_group(src\\compiler FILES ${COMPILER_SRCS} ${COMPILER_HDRS})
source_group(src\\util FILES ${UTILS_HDRS} ${UTILS_SRCS})