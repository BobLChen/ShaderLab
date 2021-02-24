set(glslang_REV "d481e0716ade062a184e3effe3c2cd3f6e45fd37")

UpdateExternalLib("glslang" "https://github.com/KhronosGroup/glslang.git" ${glslang_REV})

set(SKIP_GLSLANG_INSTALL ON CACHE BOOL "" FORCE)
set(ENABLE_GLSLANG_BINARIES OFF CACHE BOOL "" FORCE)
set(ENABLE_HLSL OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(ENABLE_OPT OFF CACHE BOOL "" FORCE)

add_subdirectory(glslang)
foreach(target "glslang" "OGLCompiler" "OSDependent" "SPIRV" "SPVRemapper")
    set_target_properties(${target} PROPERTIES FOLDER "External/glslang")
endforeach()