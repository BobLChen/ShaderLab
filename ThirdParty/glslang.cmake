set(glslang_REV "5421877c380d5f92c1965c7a94620dac861297dd")

UpdateExternalLib("glslang" "https://github.com/KhronosGroup/glslang.git" ${glslang_REV})

set(SKIP_GLSLANG_INSTALL ON CACHE BOOL "" FORCE)
set(ENABLE_GLSLANG_BINARIES OFF CACHE BOOL "" FORCE)
set(ENABLE_HLSL OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(ENABLE_OPT OFF CACHE BOOL "" FORCE)

add_subdirectory(glslang)
foreach(target "glslang" "OGLCompiler" "OSDependent" "SPIRV" "SPVRemapper" "GenericCodeGen" "MachineIndependent")
    set_target_properties(${target} PROPERTIES FOLDER "External/glslang")
endforeach()