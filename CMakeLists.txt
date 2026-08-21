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
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# Local cmake dir for our own configs
list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Find SDL3, fmt, spdlog (vendored third-party configs in ./cmake)
find_package(SDL3 REQUIRED)

# Find fmt and spdlog (header-only via local configs)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

# Additional UnleashedRecomp game-agnostic libraries (via vcpkg - install with vcpkg if needed)
# find_package(freetype REQUIRED)
# find_package(curl REQUIRED)
# find_package(nlohmann_json REQUIRED)
# find_package(unordered_dense REQUIRED)
# find_package(magic_enum REQUIRED)
# find_package(msdf-atlas-gen REQUIRED)
# find_package(ddspp REQUIRED)
# find_package(nativefiledialog REQUIRED)
# find_package(zstd REQUIRED)
# find_package(xxhash REQUIRED)
# find_package(plume REQUIRED)
# find_package(concurrentqueue REQUIRED)
# find_package(stb REQUIRED)

# DXC headers (for shader compilation)
find_path(DXC_INCLUDE_DIR dxc/dxcapi.h PATHS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/dxc/inc" NO_DEFAULT_PATH)

# MSVC toolset path (VS 2022 BuildTools has both headers and libraries; VS 2026 BuildTools is minimal)
set(MSVC_TOOLSET_PATH "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.44.35207")
set(MSVC_INCLUDE_PATH "${MSVC_TOOLSET_PATH}/include")
set(MSVC_LIB_PATH "${MSVC_TOOLSET_PATH}/lib/x64")

# Windows SDK library paths
set(WINDOWS_SDK_UM_LIB_PATH "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.26100.0/um/x64")
set(WINDOWS_SDK_UCRT_LIB_PATH "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.26100.0/ucrt/x64")

# Override the default MSVC include path to use VS 2022 toolset
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -imsvc${MSVC_INCLUDE_PATH}")
set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT} -imsvc${MSVC_INCLUDE_PATH}")

link_directories(${MSVC_LIB_PATH} ${WINDOWS_SDK_UM_LIB_PATH} ${WINDOWS_SDK_UCRT_LIB_PATH})

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_compile_definitions("$<$<CXX_COMPILER_ID:MSVC>:__builtin_isnan=_isnan>")

# Main executable
add_executable(mcla
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
    src/apu/audio.cpp
    src/apu/audio.h
    src/kernel/memory.cpp
    src/kernel/heap.cpp
    src/kernel/o1heap.c
    src/kernel/xdm.cpp
    src/kernel/guest_thread.cpp
    src/kernel/function.h
    src/kernel/imports.cpp
    src/kernel/xam.cpp
    src/kernel/xam.h
    .research/XenonRecomp/thirdparty/xxHash/xxhash.c
    src/boot_host.cpp
    src/boot_host.h
    src/boot_log.cpp
    
    src/logging.h
    src/cvar.h
    src/renderer/xenos_microcode.cpp
    src/renderer/xenos_microcode.h
    src/renderer/xenos_shader_ir.cpp
    src/renderer/xenos_shader_ir.h
    src/renderer/shader_translator.cpp
    src/renderer/shader_translator.h
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
    generated/ppc_xenon/ppc_func_mapping.cpp
    generated/ppc_xenon/ppc_recomp.0.cpp
    generated/ppc_xenon/ppc_recomp.1.cpp
    generated/ppc_xenon/ppc_recomp.2.cpp
    generated/ppc_xenon/ppc_recomp.3.cpp
    generated/ppc_xenon/ppc_recomp.4.cpp
    generated/ppc_xenon/ppc_recomp.5.cpp
    generated/ppc_xenon/ppc_recomp.6.cpp
    generated/ppc_xenon/ppc_recomp.7.cpp
    generated/ppc_xenon/ppc_recomp.8.cpp
    generated/ppc_xenon/ppc_recomp.9.cpp
    generated/ppc_xenon/ppc_recomp.10.cpp
    generated/ppc_xenon/ppc_recomp.11.cpp
    generated/ppc_xenon/ppc_recomp.12.cpp
    generated/ppc_xenon/ppc_recomp.13.cpp
    generated/ppc_xenon/ppc_recomp.14.cpp
    generated/ppc_xenon/ppc_recomp.15.cpp
    generated/ppc_xenon/ppc_recomp.16.cpp
    generated/ppc_xenon/ppc_recomp.17.cpp
    generated/ppc_xenon/ppc_recomp.18.cpp
    generated/ppc_xenon/ppc_recomp.19.cpp
    generated/ppc_xenon/ppc_recomp.20.cpp
    generated/ppc_xenon/ppc_recomp.21.cpp
    generated/ppc_xenon/ppc_recomp.22.cpp
    generated/ppc_xenon/ppc_recomp.23.cpp
    generated/ppc_xenon/ppc_recomp.24.cpp
    generated/ppc_xenon/ppc_recomp.25.cpp
    generated/ppc_xenon/ppc_recomp.26.cpp
    generated/ppc_xenon/ppc_recomp.27.cpp
    generated/ppc_xenon/ppc_recomp.28.cpp
    generated/ppc_xenon/ppc_recomp.29.cpp
    generated/ppc_xenon/ppc_recomp.30.cpp
    generated/ppc_xenon/ppc_recomp.31.cpp
    generated/ppc_xenon/ppc_recomp.32.cpp
    generated/ppc_xenon/ppc_recomp.33.cpp
    generated/ppc_xenon/ppc_recomp.34.cpp
    generated/ppc_xenon/ppc_recomp.35.cpp
    generated/ppc_xenon/ppc_recomp.36.cpp
    generated/ppc_xenon/ppc_recomp.37.cpp
    generated/ppc_xenon/ppc_recomp.38.cpp
    generated/ppc_xenon/ppc_recomp.39.cpp
    generated/ppc_xenon/ppc_recomp.40.cpp
    generated/ppc_xenon/ppc_recomp.41.cpp
    generated/ppc_xenon/ppc_recomp.42.cpp
    generated/ppc_xenon/ppc_recomp.43.cpp
    generated/ppc_xenon/ppc_recomp.44.cpp
    generated/ppc_xenon/ppc_recomp.45.cpp
    generated/ppc_xenon/ppc_recomp.46.cpp
    generated/ppc_xenon/ppc_recomp.47.cpp
    generated/ppc_xenon/ppc_recomp.48.cpp
    generated/ppc_xenon/ppc_recomp.49.cpp
    generated/ppc_xenon/ppc_recomp.50.cpp
    generated/ppc_xenon/ppc_recomp.51.cpp
    generated/ppc_xenon/ppc_recomp.52.cpp
    generated/ppc_xenon/ppc_recomp.53.cpp
    generated/ppc_xenon/ppc_recomp.54.cpp
    generated/ppc_xenon/ppc_recomp.55.cpp
    generated/ppc_xenon/ppc_recomp.56.cpp
    generated/ppc_xenon/ppc_recomp.57.cpp
    generated/ppc_xenon/ppc_recomp.58.cpp
    generated/ppc_xenon/ppc_recomp.59.cpp
    generated/ppc_xenon/ppc_recomp.60.cpp
    generated/ppc_xenon/ppc_recomp.61.cpp
    generated/ppc_xenon/ppc_recomp.62.cpp
    generated/ppc_xenon/ppc_recomp.63.cpp
    generated/ppc_xenon/ppc_recomp.64.cpp
    generated/ppc_xenon/ppc_recomp.65.cpp
    generated/ppc_xenon/ppc_recomp.66.cpp
    generated/ppc_xenon/ppc_recomp.67.cpp
    generated/ppc_xenon/ppc_recomp.68.cpp
    generated/ppc_xenon/ppc_recomp.69.cpp
    generated/ppc_xenon/ppc_recomp.70.cpp
    generated/ppc_xenon/ppc_recomp.71.cpp
    generated/ppc_xenon/ppc_recomp.72.cpp
    generated/ppc_xenon/ppc_recomp.73.cpp
    generated/ppc_xenon/ppc_recomp.74.cpp
    generated/ppc_xenon/ppc_recomp.75.cpp
    generated/ppc_xenon/ppc_recomp.76.cpp
    generated/ppc_xenon/ppc_recomp.77.cpp
    generated/ppc_xenon/ppc_recomp.78.cpp
    generated/ppc_xenon/ppc_recomp.79.cpp
    generated/ppc_xenon/ppc_recomp.80.cpp
    generated/ppc_xenon/ppc_recomp.81.cpp
    generated/ppc_xenon/ppc_recomp.82.cpp
    generated/ppc_xenon/ppc_recomp.83.cpp
    generated/ppc_xenon/ppc_recomp.84.cpp
    generated/ppc_xenon/ppc_recomp.85.cpp
    generated/ppc_xenon/ppc_recomp.86.cpp
    generated/ppc_xenon/ppc_recomp.87.cpp
    generated/ppc_xenon/ppc_recomp.88.cpp
    generated/ppc_xenon/ppc_recomp.89.cpp
    generated/ppc_xenon/ppc_recomp.90.cpp
    generated/ppc_xenon/ppc_recomp.91.cpp
    generated/ppc_xenon/ppc_recomp.92.cpp
    generated/ppc_xenon/ppc_recomp.93.cpp
    generated/ppc_xenon/ppc_recomp.94.cpp
    generated/ppc_xenon/ppc_recomp.95.cpp
    generated/ppc_xenon/ppc_recomp.96.cpp
    generated/ppc_xenon/ppc_recomp.97.cpp
    generated/ppc_xenon/ppc_recomp.98.cpp
    generated/ppc_xenon/ppc_recomp.99.cpp
    generated/ppc_xenon/ppc_recomp.100.cpp
    generated/ppc_xenon/ppc_recomp.101.cpp
    generated/ppc_xenon/ppc_recomp.102.cpp
    generated/ppc_xenon/ppc_recomp.103.cpp
    generated/ppc_xenon/ppc_recomp.104.cpp
    generated/ppc_xenon/ppc_recomp.105.cpp
    generated/ppc_xenon/ppc_recomp.106.cpp
    generated/ppc_xenon/ppc_recomp.107.cpp
    generated/ppc_xenon/ppc_recomp.108.cpp
    generated/ppc_xenon/ppc_recomp.109.cpp
    generated/ppc_xenon/ppc_recomp.110.cpp
    generated/ppc_xenon/ppc_recomp.111.cpp
    generated/ppc_xenon/ppc_recomp.112.cpp
    generated/ppc_xenon/ppc_recomp.113.cpp
    generated/ppc_xenon/ppc_recomp.114.cpp
    generated/ppc_xenon/ppc_recomp.115.cpp
    generated/ppc_xenon/ppc_recomp.116.cpp
    generated/ppc_xenon/ppc_recomp.117.cpp
    generated/ppc_xenon/ppc_recomp.118.cpp
    generated/ppc_xenon/ppc_recomp.119.cpp
    generated/ppc_xenon/ppc_recomp.120.cpp
    generated/ppc_xenon/ppc_recomp.121.cpp
    generated/ppc_xenon/ppc_recomp.122.cpp
    generated/ppc_xenon/ppc_recomp.123.cpp
    generated/ppc_xenon/ppc_recomp.124.cpp
    generated/ppc_xenon/ppc_recomp.125.cpp
    generated/ppc_xenon/ppc_recomp.126.cpp
    generated/ppc_xenon/ppc_recomp.127.cpp
    generated/ppc_xenon/ppc_recomp.128.cpp
    generated/ppc_xenon/ppc_recomp.129.cpp
    generated/ppc_xenon/ppc_recomp.130.cpp
    generated/ppc_xenon/ppc_recomp.131.cpp
    generated/ppc_xenon/ppc_recomp.132.cpp
    generated/ppc_xenon/ppc_recomp.133.cpp
    generated/ppc_xenon/ppc_recomp.134.cpp
    generated/ppc_xenon/ppc_recomp.135.cpp
    generated/ppc_xenon/ppc_recomp.136.cpp
    generated/ppc_xenon/ppc_recomp.137.cpp
    generated/ppc_xenon/ppc_recomp.138.cpp
    generated/ppc_xenon/ppc_recomp.139.cpp
    generated/ppc_xenon/ppc_recomp.140.cpp
    generated/ppc_xenon/ppc_recomp.141.cpp
    generated/ppc_xenon/ppc_recomp.142.cpp
    generated/ppc_xenon/ppc_recomp.143.cpp
    generated/ppc_xenon/ppc_recomp.144.cpp
    generated/ppc_xenon/ppc_recomp.145.cpp
    generated/ppc_xenon/ppc_recomp.146.cpp
    generated/ppc_xenon/ppc_recomp.147.cpp
    generated/ppc_xenon/ppc_recomp.148.cpp
    generated/ppc_xenon/ppc_recomp.149.cpp
    generated/ppc_xenon/ppc_recomp.150.cpp
    generated/ppc_xenon/ppc_recomp.151.cpp
    generated/ppc_xenon/ppc_recomp.152.cpp
    generated/ppc_xenon/ppc_recomp.153.cpp
    generated/ppc_xenon/ppc_recomp.154.cpp
    generated/ppc_xenon/ppc_recomp.155.cpp
    generated/ppc_xenon/ppc_recomp.156.cpp
    generated/ppc_xenon/ppc_recomp.157.cpp
    generated/ppc_xenon/ppc_recomp.158.cpp
    generated/ppc_xenon/ppc_recomp.159.cpp
    generated/ppc_xenon/ppc_recomp.160.cpp
    generated/ppc_xenon/ppc_recomp.161.cpp
    generated/ppc_xenon/ppc_recomp.162.cpp
    generated/ppc_xenon/ppc_recomp.163.cpp
    generated/ppc_xenon/ppc_recomp.164.cpp
    generated/ppc_xenon/ppc_recomp.165.cpp
    generated/ppc_xenon/ppc_recomp.166.cpp
    generated/ppc_xenon/ppc_recomp.167.cpp
    generated/ppc_xenon/ppc_recomp.168.cpp
    generated/ppc_xenon/ppc_recomp.169.cpp
    generated/ppc_xenon/ppc_recomp.170.cpp
    generated/ppc_xenon/ppc_recomp.171.cpp
    generated/ppc_xenon/ppc_recomp.172.cpp
    generated/ppc_xenon/ppc_recomp.173.cpp
    generated/ppc_xenon/ppc_recomp.174.cpp
    generated/ppc_xenon/ppc_recomp.175.cpp
    generated/ppc_xenon/ppc_recomp.176.cpp
    generated/ppc_xenon/ppc_recomp.177.cpp
    generated/ppc_xenon/ppc_recomp.178.cpp
    generated/ppc_xenon/ppc_recomp.178.cpp
    .research/XenonRecomp/XenonUtils/xex.cpp
    .research/XenonRecomp/XenonUtils/image.cpp
    .research/XenonRecomp/XenonUtils/xex_patcher.cpp
    .research/XenonRecomp/XenonUtils/memory_mapped_file.cpp
    .research/XenonRecomp/thirdparty/libmspack/libmspack/mspack/lzxd.c
    .research/XenonRecomp/thirdparty/tiny-AES-c/aes.c
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
    generated/ppc_xenon/ppc_func_mapping.cpp
    generated/ppc_xenon/ppc_recomp.0.cpp
    generated/ppc_xenon/ppc_recomp.1.cpp
    generated/ppc_xenon/ppc_recomp.2.cpp
    generated/ppc_xenon/ppc_recomp.3.cpp
    generated/ppc_xenon/ppc_recomp.4.cpp
    generated/ppc_xenon/ppc_recomp.5.cpp
    generated/ppc_xenon/ppc_recomp.6.cpp
    generated/ppc_xenon/ppc_recomp.7.cpp
    generated/ppc_xenon/ppc_recomp.8.cpp
    generated/ppc_xenon/ppc_recomp.9.cpp
    generated/ppc_xenon/ppc_recomp.10.cpp
    generated/ppc_xenon/ppc_recomp.11.cpp
    generated/ppc_xenon/ppc_recomp.12.cpp
    generated/ppc_xenon/ppc_recomp.13.cpp
    generated/ppc_xenon/ppc_recomp.14.cpp
    generated/ppc_xenon/ppc_recomp.15.cpp
    generated/ppc_xenon/ppc_recomp.16.cpp
    generated/ppc_xenon/ppc_recomp.17.cpp
    generated/ppc_xenon/ppc_recomp.18.cpp
    generated/ppc_xenon/ppc_recomp.19.cpp
    generated/ppc_xenon/ppc_recomp.20.cpp
    generated/ppc_xenon/ppc_recomp.21.cpp
    generated/ppc_xenon/ppc_recomp.22.cpp
    generated/ppc_xenon/ppc_recomp.23.cpp
    generated/ppc_xenon/ppc_recomp.24.cpp
    generated/ppc_xenon/ppc_recomp.25.cpp
    generated/ppc_xenon/ppc_recomp.26.cpp
    generated/ppc_xenon/ppc_recomp.27.cpp
    generated/ppc_xenon/ppc_recomp.28.cpp
    generated/ppc_xenon/ppc_recomp.29.cpp
    generated/ppc_xenon/ppc_recomp.30.cpp
    generated/ppc_xenon/ppc_recomp.31.cpp
    generated/ppc_xenon/ppc_recomp.32.cpp
    generated/ppc_xenon/ppc_recomp.33.cpp
    generated/ppc_xenon/ppc_recomp.34.cpp
    generated/ppc_xenon/ppc_recomp.35.cpp
    generated/ppc_xenon/ppc_recomp.36.cpp
    generated/ppc_xenon/ppc_recomp.37.cpp
    generated/ppc_xenon/ppc_recomp.38.cpp
    generated/ppc_xenon/ppc_recomp.39.cpp
    generated/ppc_xenon/ppc_recomp.40.cpp
    generated/ppc_xenon/ppc_recomp.41.cpp
    generated/ppc_xenon/ppc_recomp.42.cpp
    generated/ppc_xenon/ppc_recomp.43.cpp
    generated/ppc_xenon/ppc_recomp.44.cpp
    generated/ppc_xenon/ppc_recomp.45.cpp
    generated/ppc_xenon/ppc_recomp.46.cpp
    generated/ppc_xenon/ppc_recomp.47.cpp
    generated/ppc_xenon/ppc_recomp.48.cpp
    generated/ppc_xenon/ppc_recomp.49.cpp
    generated/ppc_xenon/ppc_recomp.50.cpp
    generated/ppc_xenon/ppc_recomp.51.cpp
    generated/ppc_xenon/ppc_recomp.52.cpp
    generated/ppc_xenon/ppc_recomp.53.cpp
    generated/ppc_xenon/ppc_recomp.54.cpp
    generated/ppc_xenon/ppc_recomp.55.cpp
    generated/ppc_xenon/ppc_recomp.56.cpp
    generated/ppc_xenon/ppc_recomp.57.cpp
    generated/ppc_xenon/ppc_recomp.58.cpp
    generated/ppc_xenon/ppc_recomp.59.cpp
    generated/ppc_xenon/ppc_recomp.60.cpp
    generated/ppc_xenon/ppc_recomp.61.cpp
    generated/ppc_xenon/ppc_recomp.62.cpp
    generated/ppc_xenon/ppc_recomp.63.cpp
    generated/ppc_xenon/ppc_recomp.64.cpp
    generated/ppc_xenon/ppc_recomp.65.cpp
    generated/ppc_xenon/ppc_recomp.66.cpp
    generated/ppc_xenon/ppc_recomp.67.cpp
    generated/ppc_xenon/ppc_recomp.68.cpp
    generated/ppc_xenon/ppc_recomp.69.cpp
    generated/ppc_xenon/ppc_recomp.70.cpp
    generated/ppc_xenon/ppc_recomp.71.cpp
    generated/ppc_xenon/ppc_recomp.72.cpp
    generated/ppc_xenon/ppc_recomp.73.cpp
    generated/ppc_xenon/ppc_recomp.74.cpp
    generated/ppc_xenon/ppc_recomp.75.cpp
    generated/ppc_xenon/ppc_recomp.76.cpp
    generated/ppc_xenon/ppc_recomp.77.cpp
    generated/ppc_xenon/ppc_recomp.78.cpp
    generated/ppc_xenon/ppc_recomp.79.cpp
    generated/ppc_xenon/ppc_recomp.80.cpp
    generated/ppc_xenon/ppc_recomp.81.cpp
    generated/ppc_xenon/ppc_recomp.82.cpp
    generated/ppc_xenon/ppc_recomp.83.cpp
    generated/ppc_xenon/ppc_recomp.84.cpp
    generated/ppc_xenon/ppc_recomp.85.cpp
    generated/ppc_xenon/ppc_recomp.86.cpp
    generated/ppc_xenon/ppc_recomp.87.cpp
    generated/ppc_xenon/ppc_recomp.88.cpp
    generated/ppc_xenon/ppc_recomp.89.cpp
    generated/ppc_xenon/ppc_recomp.90.cpp
    generated/ppc_xenon/ppc_recomp.91.cpp
    generated/ppc_xenon/ppc_recomp.92.cpp
    generated/ppc_xenon/ppc_recomp.93.cpp
    generated/ppc_xenon/ppc_recomp.94.cpp
    generated/ppc_xenon/ppc_recomp.95.cpp
    generated/ppc_xenon/ppc_recomp.96.cpp
    generated/ppc_xenon/ppc_recomp.97.cpp
    generated/ppc_xenon/ppc_recomp.98.cpp
    generated/ppc_xenon/ppc_recomp.99.cpp
    generated/ppc_xenon/ppc_recomp.100.cpp
    generated/ppc_xenon/ppc_recomp.101.cpp
    generated/ppc_xenon/ppc_recomp.102.cpp
    generated/ppc_xenon/ppc_recomp.103.cpp
    generated/ppc_xenon/ppc_recomp.104.cpp
    generated/ppc_xenon/ppc_recomp.105.cpp
    generated/ppc_xenon/ppc_recomp.106.cpp
    generated/ppc_xenon/ppc_recomp.107.cpp
    generated/ppc_xenon/ppc_recomp.108.cpp
    generated/ppc_xenon/ppc_recomp.109.cpp
    generated/ppc_xenon/ppc_recomp.110.cpp
    generated/ppc_xenon/ppc_recomp.111.cpp
    generated/ppc_xenon/ppc_recomp.112.cpp
    generated/ppc_xenon/ppc_recomp.113.cpp
    generated/ppc_xenon/ppc_recomp.114.cpp
    generated/ppc_xenon/ppc_recomp.115.cpp
    generated/ppc_xenon/ppc_recomp.116.cpp
    generated/ppc_xenon/ppc_recomp.117.cpp
    generated/ppc_xenon/ppc_recomp.118.cpp
    generated/ppc_xenon/ppc_recomp.119.cpp
    generated/ppc_xenon/ppc_recomp.120.cpp
    generated/ppc_xenon/ppc_recomp.121.cpp
    generated/ppc_xenon/ppc_recomp.122.cpp
    generated/ppc_xenon/ppc_recomp.124.cpp
    generated/ppc_xenon/ppc_recomp.125.cpp
    generated/ppc_xenon/ppc_recomp.126.cpp
    generated/ppc_xenon/ppc_recomp.127.cpp
    generated/ppc_xenon/ppc_recomp.128.cpp
    generated/ppc_xenon/ppc_recomp.129.cpp
    generated/ppc_xenon/ppc_recomp.130.cpp
    generated/ppc_xenon/ppc_recomp.131.cpp
    generated/ppc_xenon/ppc_recomp.132.cpp
    generated/ppc_xenon/ppc_recomp.133.cpp
    generated/ppc_xenon/ppc_recomp.134.cpp
    generated/ppc_xenon/ppc_recomp.135.cpp
    generated/ppc_xenon/ppc_recomp.136.cpp
    generated/ppc_xenon/ppc_recomp.137.cpp
    generated/ppc_xenon/ppc_recomp.138.cpp
    generated/ppc_xenon/ppc_recomp.139.cpp
    generated/ppc_xenon/ppc_recomp.140.cpp
    generated/ppc_xenon/ppc_recomp.141.cpp
    generated/ppc_xenon/ppc_recomp.142.cpp
    generated/ppc_xenon/ppc_recomp.143.cpp
    generated/ppc_xenon/ppc_recomp.144.cpp
    generated/ppc_xenon/ppc_recomp.145.cpp
    generated/ppc_xenon/ppc_recomp.146.cpp
    generated/ppc_xenon/ppc_recomp.147.cpp
    generated/ppc_xenon/ppc_recomp.148.cpp
    generated/ppc_xenon/ppc_recomp.149.cpp
    generated/ppc_xenon/ppc_recomp.150.cpp
    generated/ppc_xenon/ppc_recomp.151.cpp
    generated/ppc_xenon/ppc_recomp.152.cpp
    generated/ppc_xenon/ppc_recomp.153.cpp
    generated/ppc_xenon/ppc_recomp.154.cpp
    generated/ppc_xenon/ppc_recomp.155.cpp
    generated/ppc_xenon/ppc_recomp.156.cpp
    generated/ppc_xenon/ppc_recomp.157.cpp
    generated/ppc_xenon/ppc_recomp.158.cpp
    generated/ppc_xenon/ppc_recomp.159.cpp
    generated/ppc_xenon/ppc_recomp.160.cpp
    generated/ppc_xenon/ppc_recomp.161.cpp
    generated/ppc_xenon/ppc_recomp.162.cpp
    generated/ppc_xenon/ppc_recomp.163.cpp
    generated/ppc_xenon/ppc_recomp.164.cpp
    generated/ppc_xenon/ppc_recomp.165.cpp
    generated/ppc_xenon/ppc_recomp.166.cpp
    generated/ppc_xenon/ppc_recomp.167.cpp
    generated/ppc_xenon/ppc_recomp.168.cpp
    generated/ppc_xenon/ppc_recomp.169.cpp
    generated/ppc_xenon/ppc_recomp.170.cpp
    generated/ppc_xenon/ppc_recomp.171.cpp
    generated/ppc_xenon/ppc_recomp.172.cpp
    generated/ppc_xenon/ppc_recomp.173.cpp
    generated/ppc_xenon/ppc_recomp.174.cpp
    generated/ppc_xenon/ppc_recomp.175.cpp
    generated/ppc_xenon/ppc_recomp.176.cpp
    generated/ppc_xenon/ppc_recomp.177.cpp
generated/ppc_xenon/ppc_recomp.178.cpp
    generated/ppc_xenon/ppc_recomp.178.cpp
)

target_include_directories(mcla PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/kernel
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/ppc_xenon
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/UnleashedRecomp/tools/XenonRecomp/XenonUtils
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/UnleashedRecomp/UnleashedRecomp
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/XenonRecomp/XenonUtils
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/XenonRecomp/thirdparty
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/XenonRecomp/thirdparty/tiny-AES-c
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/XenonRecomp/thirdparty/TinySHA1
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/XenonRecomp/thirdparty/libmspack/libmspack/mspack
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/XenonRecomp/thirdparty/xxHash
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/XenosRecomp/thirdparty/smol-v/source
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/SDL3/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/fmt
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/toml++/include
    ${DXC_INCLUDE_DIR}
)

target_link_libraries(mcla PRIVATE
    SDL3::SDL3
    fmt::fmt
    spdlog::spdlog_header_only
    # freetype::freetype
    # CURL::libcurl
    # nlohmann_json::nlohmann_json
    # magic_enum::magic_enum
    # msdf-atlas-gen::msdf-atlas-gen
    # nativefiledialog::nfd
    # ddspp::ddspp
    # zstd::libzstd_static
    # xxhash::xxhash
    # plume::plume
    # concurrentqueue::concurrentqueue
    # stb::stb
    kernel32.lib user32.lib gdi32.lib winmm.lib imm32.lib ole32.lib oleaut32.lib
    version.lib uuid.lib advapi32.lib setupapi.lib shell32.lib hid.lib dinput8.lib
    ws2_32.lib dbghelp.lib dxgi.lib dxguid.lib d3d12.lib
)

# Add SDL3 library directory
target_link_directories(mcla PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/third_party/SDL3/lib")

target_compile_definitions(mcla PRIVATE
    NOMINMAX
    WIN32_LEAN_AND_MEAN
    _CRT_SECURE_NO_WARNINGS
    _MT
    MCLA_STANDALONE
    _ALLOW_COMPILER_AND_STL_VERSION_MISMATCH
    _HAS_CXX23=0
)

# Disable debug info for RelWithDebInfo to avoid clang-cl SEH crash
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MT /O2 /Ob1 /DNDEBUG")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "/MT /O2 /Ob1 /DNDEBUG")

target_compile_options(mcla PRIVATE /GS- /EHa)
target_link_options(mcla PRIVATE /OPT:NOREF)
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
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/SDL3/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/fmt
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/toml++/include
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/XenosRecomp/thirdparty/smol-v/source
    ${DXC_INCLUDE_DIR}
)
set(VALIDATOR_COMPILE_DEFS NOMINMAX WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS MCLA_STANDALONE _ALLOW_COMPILER_AND_STL_VERSION_MISMATCH _HAS_CXX23=0)

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

# phase0_validator: kernel framework unit tests (memory, handles, hooks, kernel objects).
add_executable(phase0_validator
    src/kernel/phase0_validator.cpp
    src/kernel/memory.cpp
    src/kernel/heap.cpp
    src/kernel/o1heap.c
    src/kernel/xdm.cpp
    src/kernel/guest_thread.cpp
    src/kernel/function.h
    src/kernel/kernel_objects.h
    src/kernel/xbox.h)
target_include_directories(phase0_validator PRIVATE
    ${VALIDATOR_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/kernel
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/ppc_xenon
    "${CMAKE_CURRENT_SOURCE_DIR}/.research/UnleashedRecomp/tools/XenonRecomp/XenonUtils"
    "${CMAKE_CURRENT_SOURCE_DIR}/.research/UnleashedRecomp/UnleashedRecomp"
    "${CMAKE_CURRENT_SOURCE_DIR}/.research/XenonRecomp/XenonUtils"
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/XenonRecomp/thirdparty
    "${CMAKE_CURRENT_SOURCE_DIR}/.research/XenonRecomp/thirdparty/tiny-AES-c"
    "${CMAKE_CURRENT_SOURCE_DIR}/.research/XenonRecomp/thirdparty/TinySHA1"
    "${CMAKE_CURRENT_SOURCE_DIR}/.research/XenonRecomp/thirdparty/libmspack/libmspack/mspack")
target_compile_definitions(phase0_validator PRIVATE ${VALIDATOR_COMPILE_DEFS})
target_link_libraries(phase0_validator PRIVATE fmt::fmt spdlog::spdlog_header_only)