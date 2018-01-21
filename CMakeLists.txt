cmake_minimum_required(VERSION 3.0)

project(ShaderLab)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(ALL_LIBS
	ShaderLabParser
)

include_directories(
	shaderlab/
)

add_subdirectory(shaderlab)
add_subdirectory(test)