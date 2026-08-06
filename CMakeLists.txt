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

# Prepend local cmake dir to override SDK's broken fmt config
list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/rexglue-sdk/win-amd64")

# Let SDK's fmt cmake config handle header-only mode

include(generated/rexglue.cmake)

# Custom setup macro that links against SDK import libraries directly
# This bypasses the SDK's CMake targets which have missing dependencies
macro(rexglue_setup_target_custom target_name)
    target_sources(${target_name} PRIVATE ${REXGLUE_ENTRYPOINT_GENERATED_SOURCES})
    target_include_directories(${target_name} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${REXGLUE_ENTRYPOINT_INCLUDE_DIR}
        "${CMAKE_CURRENT_SOURCE_DIR}/rexglue-sdk/win-amd64/include"
    )
    
    # Link against SDK import libraries (lib/*.lib) and SDK CMake targets
    target_link_libraries(${target_name} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/rexglue-sdk/win-amd64/lib/rexruntime.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/rexglue-sdk/win-amd64/lib/rexgpu-xenos.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/rexglue-sdk/win-amd64/lib/SDL3.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/rexglue-sdk/win-amd64/lib/TracyClient.lib"
        fmt::fmt
        spdlog::spdlog_header_only
        kernel32.lib user32.lib gdi32.lib winmm.lib imm32.lib ole32.lib oleaut32.lib
        version.lib uuid.lib advapi32.lib setupapi.lib shell32.lib hid.lib dinput8.lib
        ws2_32.lib dbghelp.lib dxgi.lib dxguid.lib
    )
    
    # Compiler definitions from SDK
    target_compile_definitions(${target_name} PRIVATE
        NOMINMAX
        REXGLUE_BUILD_CONFIG="Release"
        REX_HAS_D3D12=1
        TRACY_DELAYED_INIT
        TRACY_ENABLE
        TRACY_FIBERS
        TRACY_IMPORTS
        TRACY_MANUAL_LIFETIME
        TRACY_ON_DEMAND
        WIN32_LEAN_AND_MEAN
        _DLL
        _MT
    )
    
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/metadata/icons")
        rexglue_embed_metadata(${target_name}
            DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/metadata/icons"
            PREFIX "icons")
    endif()
    
    # GPU plugin configuration
    target_compile_definitions(${target_name} PRIVATE REX_GPU_PLUGINS="xenos")
endmacro()

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_compile_definitions("$<$<CXX_COMPILER_ID:MSVC>:__builtin_isnan=_isnan>")

add_executable(mcla WIN32
    src/main.cpp src/early_init.cpp src/mcla_app.h src/patches.cpp src/patches.h src/gpu_mmio.cpp src/gpu_mmio.h src/native_renderer.cpp src/native_renderer.h
    src/renderer_mode.cpp src/renderer_mode.h src/renderer_hook_dispatch.cpp src/renderer_hook_dispatch.h
    src/guest_memory.cpp src/guest_memory.h src/frame_trace.cpp src/frame_trace.h src/capture_hooks.cpp src/capture_hooks.h src/native_types.h
    src/d3d12_backend.cpp src/d3d12_backend.h
    src/renderer/xenos_microcode.cpp src/renderer/xenos_microcode.h
    src/renderer/xenos_shader_ir.cpp src/renderer/xenos_shader_ir.h
      src/renderer/shader_translator.cpp src/renderer/shader_translator.h
      src/renderer/pipeline_cache.cpp src/renderer/pipeline_cache.h
      src/renderer/vertex_decode.cpp src/renderer/vertex_decode.h
      src/renderer/resource_cache.cpp src/renderer/resource_cache.h
      src/renderer/test_shaders.h
    src/compat.cpp src/compat.h
    "src/rex_app.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/rexglue-sdk/win-amd64/share/rexglue/windowed_app_main_sdl.cpp")
rexglue_setup_target_custom(mcla)
target_compile_options(mcla PRIVATE /GS- /EHa)
target_compile_definitions(mcla PRIVATE $<$<NOT:$<CONFIG:Debug>>:NDEBUG>)



