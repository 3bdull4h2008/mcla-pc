cmake_minimum_required(VERSION 3.25)

# Disable clang's -nostartfiles -nostdlib on Windows by setting these BEFORE project()
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_CXX_FLAGS_INIT "")
    set(CMAKE_C_FLAGS_INIT "")
    set(CMAKE_EXE_LINKER_FLAGS_INIT "-fuse-ld=lld")
    set(CMAKE_SHARED_LINKER_FLAGS_INIT "-fuse-ld=lld")
    set(CMAKE_MODULE_LINKER_FLAGS_INIT "-fuse-ld=lld")
endif()

project(mcla VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

# Local cmake dir for our own configs
list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# ReXGlue SDK for third-party deps (fmt, spdlog, SDL3 headers, tracy, dxc)
list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/rexglue-sdk/win-amd64")

# Find SDL3 - try SDK first, then system
find_package(SDL3 REQUIRED)

# Find fmt and spdlog (header-only via SDK configs)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

# Tracy (header-only, from SDK)
find_path(TRACY_INCLUDE_DIR Tracy.hpp PATHS "${CMAKE_CURRENT_SOURCE_DIR}/rexglue-sdk/win-amd64/include" NO_DEFAULT_PATH)
if(NOT TRACY_INCLUDE_DIR)
    message(FATAL_ERROR "Tracy not found in rexglue-sdk")
endif()

# DXC headers (for shader compilation)
find_path(DXC_INCLUDE_DIR dxcapi.h PATHS "${CMAKE_CURRENT_SOURCE_DIR}/.research/XenosRecomp/thirdparty/dxc-bin/inc" NO_DEFAULT_PATH)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_compile_definitions("$<$<CXX_COMPILER_ID:MSVC>:__builtin_isnan=_isnan>")

# Main executable
add_executable(mcla WIN32
    src/main.cpp
    src/early_init.cpp
    src/app.cpp
    src/app.h
    src/patches.cpp
    src/patches.h
    src/gpu_mmio.cpp
    src/gpu_mmio.h
    src/native_renderer.cpp
    src/native_renderer.h
    src/renderer_mode.cpp
    src/renderer_mode.h
    src/renderer_hook_dispatch.cpp
    src/renderer_hook_dispatch.h
    src/guest_memory.cpp
    src/guest_memory.h
    src/frame_trace.cpp
    src/frame_trace.h
    src/capture_hooks.cpp
    src/capture_hooks.h
    src/native_types.h
    src/vfs_rpf.cpp
    src/vfs_rpf.h
    src/d3d12_backend.cpp
    src/d3d12_backend.h
    src/compat.cpp
    src/compat.h
    src/logging.cpp
    src/logging.h
    src/cvar.cpp
    src/cvar.h
    src/renderer/xenos_microcode.cpp
    src/renderer/xenos_microcode.h
    src/renderer/xenos_shader_ir.cpp
    src/renderer/xenos_shader_ir.h
    src/renderer/shader_translator.cpp
    src/renderer/shader_translator.h
    src/renderer/shader_dxc_compile.cpp
    src/renderer/dxc_runtime.cpp
    src/renderer/dxc_runtime.h
    src/renderer/pipeline_cache.cpp
    src/renderer/pipeline_cache.h
    src/renderer/vertex_decode.cpp
    src/renderer/vertex_decode.h
    src/renderer/grc_fvf_decode.cpp
    src/renderer/grc_fvf_decode.h
    src/renderer/rage_asset_pipeline.cpp
    src/renderer/rage_asset_pipeline.h
    src/renderer/resource_cache.cpp
    src/renderer/resource_cache.h
    src/renderer/texture_decode.cpp
    src/renderer/texture_decode.h
    src/renderer/test_shaders.h
)

target_include_directories(mcla PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${TRACY_INCLUDE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/rexglue-sdk/win-amd64/include"
    ${DXC_INCLUDE_DIR}
)

target_link_libraries(mcla PRIVATE
    SDL3::SDL3
    fmt::fmt
    spdlog::spdlog_header_only
    kernel32.lib user32.lib gdi32.lib winmm.lib imm32.lib ole32.lib oleaut32.lib
    version.lib uuid.lib advapi32.lib setupapi.lib shell32.lib hid.lib dinput8.lib
    ws2_32.lib dbghelp.lib dxgi.lib dxguid.lib d3d12.lib
)

target_compile_definitions(mcla PRIVATE
    NOMINMAX
    WIN32_LEAN_AND_MEAN
    TRACY_DELAYED_INIT
    TRACY_ENABLE
    TRACY_FIBERS
    TRACY_IMPORTS
    TRACY_MANUAL_LIFETIME
    TRACY_ON_DEMAND
    _DLL
    _MT
    MCLA_STANDALONE
)

target_compile_options(mcla PRIVATE /GS- /EHa)
target_compile_definitions(mcla PRIVATE $<$<NOT:$<CONFIG:Debug>>:NDEBUG>)

# ---------------------------------------------------------------------------
# Offline validators (headless; no SDL/window). Built by `cmake --build build`.
# Each is a standalone console tool over the shared renderer TUs.
# ---------------------------------------------------------------------------
set(RENDERER_IR_TUS
    src/renderer/xenos_microcode.cpp
    src/renderer/xenos_shader_ir.cpp
    src/renderer/shader_translator.cpp
    src/renderer/shader_dxc_compile.cpp
    src/renderer/dxc_runtime.cpp
    src/renderer/pipeline_cache.cpp
)

# Shared flags for all validator targets (clang-cl).
set(VALIDATOR_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    "${CMAKE_CURRENT_SOURCE_DIR}/rexglue-sdk/win-amd64/include"
    ${DXC_INCLUDE_DIR}
)
set(VALIDATOR_COMPILE_DEFS NOMINMAX WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS MCLA_STANDALONE)

# shader_pipeline_validator: Phase 4/5 gate — parse + translate every shader
# container, fail (exit 1) if any unknown/unsupported opcode or empty HLSL.
add_executable(shader_pipeline_validator
    src/renderer/shader_pipeline_validator.cpp ${RENDERER_IR_TUS})
target_include_directories(shader_pipeline_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(shader_pipeline_validator PRIVATE ${VALIDATOR_COMPILE_DEFS})

# xenos_decode_validator: raw Xenos microcode decode over the shader corpus.
add_executable(xenos_decode_validator
    src/renderer/xenos_decode_validator.cpp ${RENDERER_IR_TUS})
target_include_directories(xenos_decode_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(xenos_decode_validator PRIVATE ${VALIDATOR_COMPILE_DEFS})

# phase3_validator: vertex fetch + resource/texture decode unit checks.
add_executable(phase3_validator
    src/renderer/phase3_validator.cpp ${RENDERER_IR_TUS}
    src/renderer/vertex_decode.cpp src/renderer/grc_fvf_decode.cpp src/renderer/resource_cache.cpp src/renderer/texture_decode.cpp)
target_include_directories(phase3_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(phase3_validator PRIVATE ${VALIDATOR_COMPILE_DEFS})

# texture_decode_test: tiled/Xenos texture decode vs oracle.
add_executable(texture_decode_test
    src/renderer/texture_decode_test.cpp
    src/renderer/texture_decode.cpp src/renderer/resource_cache.cpp)
target_include_directories(texture_decode_test PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(texture_decode_test PRIVATE ${VALIDATOR_COMPILE_DEFS})

# capture_dump_validator: cross-checks captured DrawPacket stream vs raw guest memory.
add_executable(capture_dump_validator
    src/renderer/capture_dump_validator.cpp src/frame_trace.cpp src/frame_trace.h
    src/renderer/vertex_decode.cpp)
target_include_directories(capture_dump_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(capture_dump_validator PRIVATE
    ${VALIDATOR_COMPILE_DEFS}
    FMT_HEADER_ONLY=1 SPDLOG_FMT_EXTERNAL SPDLOG_FWRITE_UNLOCKED)
target_link_libraries(capture_dump_validator PRIVATE
    fmt::fmt spdlog::spdlog_header_only)

# xtr_dump_validator: standalone capture dumps.
add_executable(xtr_dump_validator src/renderer/xtr_dump_validator.cpp)
target_include_directories(xtr_dump_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(xtr_dump_validator PRIVATE ${VALIDATOR_COMPILE_DEFS})

# backend_validator: D3D12 device + PSO smoke test (mirrors CreateTestPipeline).
add_executable(backend_validator
    src/renderer/backend_validator.cpp
    src/renderer/vertex_decode.cpp src/renderer/resource_cache.cpp src/renderer/texture_decode.cpp)
target_include_directories(backend_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(backend_validator PRIVATE ${VALIDATOR_COMPILE_DEFS})
target_link_libraries(backend_validator PRIVATE d3d12.lib dxgi.lib dxguid.lib)