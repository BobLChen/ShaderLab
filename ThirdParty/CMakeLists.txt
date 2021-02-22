# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

find_program(git_executable NAMES git git.exe git.cmd)

if (NOT git_executable)
    message(FATAL_ERROR "Failed to find git.")
endif()

function(UpdateExternalLib name url rev)

    set(need_checkout FALSE)
    set(external_folder "${SOURCE_ROOT_DIR}/ThirdParty")
    set(external_lib_folder "${external_folder}/${name}")
    
    if(EXISTS "${external_lib_folder}/.git")
        message(STATUS "Updating ${name} to revision ${rev}...")
        execute_process(COMMAND "${git_executable}" "fetch" "origin" WORKING_DIRECTORY "${external_lib_folder}")
        execute_process(COMMAND "${git_executable}" "rev-parse" "HEAD" WORKING_DIRECTORY "${external_lib_folder}" OUTPUT_VARIABLE head_rev)
        string(STRIP ${head_rev} head_rev)
        if (${head_rev} STREQUAL ${rev})
            set(need_checkout FALSE)
        else()
            set(need_checkout TRUE)
        endif()
    else()
        message(STATUS "Cloning ${name} revision...")
        execute_process(COMMAND "${git_executable}" "clone" ${url} "-n" WORKING_DIRECTORY "${external_folder}")
        set(need_checkout TRUE)
    endif()

    if(need_checkout)
        message(STATUS "Checking out to revision ${rev}...")
        execute_process(COMMAND "${git_executable}" "checkout" "-q" ${rev} WORKING_DIRECTORY "${external_lib_folder}")
    endif()

    set(${ARGV3} ${need_checkout} PARENT_SCOPE)
endfunction()

include(SPIRV-Header.cmake)
include(SPIRV-Tools.cmake)
include(DirectXShaderCompiler.cmake)
include(SPIRV-Cross.cmake)
