cmake_minimum_required(VERSION 3.0)

project(ShaderLab)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(ALL_LIBS
	hlsl2glsl
	glsl_optimizer
	shaderlab
)

include_directories(
	src/
	external/hlsl2glslfork/include/
	external/glsl-optimizer/src/glsl/
)

add_subdirectory(external/hlsl2glslfork)
add_subdirectory(external/glsl-optimizer)
add_subdirectory(src)
add_subdirectory(Shader2Json)