cmake_minimum_required(VERSION 3.25)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_CXX_FLAGS_INIT "")
    set(CMAKE_C_FLAGS_INIT "")
    set(CMAKE_EXE_LINKER_FLAGS_INIT "-fuse-ld=lld")
endif()

project(xenon_smoke LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

set(REPO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../..")
set(GENERATED_DIR "${REPO_ROOT}/generated/ppc_xenon")
set(XENONUTILS_DIR "${REPO_ROOT}/.research/XenonRecomp/XenonUtils")
set(THIRDPARTY_DIR "${REPO_ROOT}/.research/XenonRecomp/thirdparty")

file(GLOB PPC_RECOMP_SOURCES "${GENERATED_DIR}/ppc_recomp.*.cpp")

add_executable(xenon_smoke
    ${CMAKE_CURRENT_SOURCE_DIR}/xenon_smoke.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel_stubs.cpp
    ${PPC_RECOMP_SOURCES}
    "${GENERATED_DIR}/ppc_func_mapping.cpp"
    "${XENONUTILS_DIR}/xex.cpp"
    "${XENONUTILS_DIR}/image.cpp"
    "${XENONUTILS_DIR}/xex_patcher.cpp"
    "${XENONUTILS_DIR}/memory_mapped_file.cpp"
    "${THIRDPARTY_DIR}/libmspack/libmspack/mspack/lzxd.c"
    "${THIRDPARTY_DIR}/tiny-AES-c/aes.c"
)

target_include_directories(xenon_smoke PRIVATE
    "${GENERATED_DIR}"
    "${XENONUTILS_DIR}"
    "${THIRDPARTY_DIR}/simde"
    "${THIRDPARTY_DIR}/tiny-AES-c"
    "${THIRDPARTY_DIR}/TinySHA1"
    "${THIRDPARTY_DIR}/libmspack/libmspack/mspack"
)

target_compile_options(xenon_smoke PRIVATE
    /utf-8
    /GS-
    /EHa
    /W0
)
target_compile_definitions(xenon_smoke PRIVATE
    NOMINMAX
    WIN32_LEAN_AND_MEAN
    _CRT_SECURE_NO_WARNINGS
    $<$<NOT:$<CONFIG:Debug>>:NDEBUG>
)