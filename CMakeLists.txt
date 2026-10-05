cmake_minimum_required(VERSION 3.25)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_CXX_FLAGS_INIT "")
    set(CMAKE_C_FLAGS_INIT "")
    set(CMAKE_EXE_LINKER_FLAGS_INIT "-fuse-ld=lld")
    set(CMAKE_SHARED_LINKER_FLAGS_INIT "-fuse-ld=lld")
    set(CMAKE_MODULE_LINKER_FLAGS_INIT "-fuse-ld=lld")
endif()

project(mcla VERSION 0.1.0 LANGUAGES C CXX)

# ===========================================================================
# GATE 1 - generated/ppc_xenon must hold EXACTLY 176 recomp translation units.
#
# This invariant used to live only in prose, so a recompiler regen that
# changed the TU count was silent in the dangerous direction.  The source
# list in the add_executable(mcla ...) block below is a hand-maintained
# ppc_recomp.0..175.cpp enumeration: a *stray extra* TU on disk (e.g.
# ppc_recomp.176.cpp) is never referenced, so it compiles and links fine and
# the emulator just silently loses whatever function landed in it.  A
# *missing* TU fails much later with an opaque "cannot open source file".
# Both directions now fail here, at configure time, with the reason.
#
# Invariant source of truth:
#   .qoder/skills/mcla-recompiler-regen/SKILL.md:57-58
#     "**TU count must stay 176** - `CMakeLists.txt` hardcodes
#      `ppc_recomp.0..175.cpp`.  A regen that changes the count breaks the
#      build."
#   plus the do-not list (LONG_TODO_MASTER.md section 4) and
#   SKILL.md:49 ("If a fresh regen is not byte-for-byte clean -> STOP").
#
# If a regen legitimately changes the count, that is an intentional
# migration: bump MCLA_EXPECTED_TU_COUNT, regenerate the source-list block
# from it, and re-run the reproducibility check (target check_regen_repro,
# at the bottom of this file).  Do not just append a line to the list.
# ===========================================================================
set(MCLA_EXPECTED_TU_COUNT 176)
set(MCLA_RECOMP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated/ppc_xenon")

# Expected TU names, derived from the count so the two can never drift.
set(MCLA_EXPECTED_RECOMP_TUS "")
math(EXPR _mcla_tu_last "${MCLA_EXPECTED_TU_COUNT} - 1")
foreach(_mcla_i RANGE 0 ${_mcla_tu_last})
    list(APPEND MCLA_EXPECTED_RECOMP_TUS "${MCLA_RECOMP_DIR}/ppc_recomp.${_mcla_i}.cpp")
endforeach()

# --- (a) every expected ppc_recomp.N.cpp exists ----------------------------
set(_mcla_missing_tus "")
foreach(_mcla_tu IN LISTS MCLA_EXPECTED_RECOMP_TUS)
    if(NOT EXISTS "${_mcla_tu}")
        list(APPEND _mcla_missing_tus "${_mcla_tu}")
    endif()
endforeach()
if(_mcla_missing_tus)
    list(LENGTH _mcla_missing_tus _mcla_missing_n)
    string(REPLACE ";" "\n    " _mcla_missing_list "${_mcla_missing_tus}")
    message(FATAL_ERROR
        "MCLA INVARIANT VIOLATED [generated TU count, missing]:\n"
        "  ${_mcla_missing_n} of ${MCLA_EXPECTED_TU_COUNT} expected ppc_recomp.N.cpp files are absent from\n"
        "  ${MCLA_RECOMP_DIR}\n"
        "    ${_mcla_missing_list}\n"
        "  A recompiler regen changed the translation-unit count. The count is an\n"
        "  invariant, not a stale number to be patched: .qoder/skills/mcla-recompiler-regen/SKILL.md:57-58\n"
        "  (\"TU count must stay 176 ... A regen that changes the count breaks the build\")\n"
        "  and SKILL.md:49 - a regen that is not byte-for-byte clean means STOP, fall back to Route A/C.\n"
        "  Do NOT fix this by deleting entries from the mcla source list.")
endif()

# --- (b) NO unexpected ppc_recomp.*.cpp on disk (the silent direction) -----
# This is the check that matters: the hand-written source list would ignore
# an extra TU, so this is the only thing standing between a regen and a
# silently-dropped guest function.
file(GLOB _mcla_actual_recomp_tus "${MCLA_RECOMP_DIR}/ppc_recomp.*.cpp")
set(_mcla_unexpected_tus "")
foreach(_mcla_tu IN LISTS _mcla_actual_recomp_tus)
    list(FIND MCLA_EXPECTED_RECOMP_TUS "${_mcla_tu}" _mcla_tu_idx)
    if(_mcla_tu_idx EQUAL -1)
        list(APPEND _mcla_unexpected_tus "${_mcla_tu}")
    endif()
endforeach()
if(_mcla_unexpected_tus)
    list(LENGTH _mcla_unexpected_tus _mcla_unexpected_n)
    list(LENGTH _mcla_actual_recomp_tus _mcla_actual_n)
    string(REPLACE ";" "\n    " _mcla_unexpected_list "${_mcla_unexpected_tus}")
    get_filename_component(_mcla_unexpected_names "${_mcla_unexpected_tus}" NAME)
    string(REPLACE ";" ", " _mcla_unexpected_names_csv "${_mcla_unexpected_names}")
    message(FATAL_ERROR
        "MCLA INVARIANT VIOLATED [generated TU count, UNEXPECTED EXTRA FILE]:\n"
        "  found ${_mcla_actual_n} ppc_recomp.*.cpp in ${MCLA_RECOMP_DIR} but only\n"
        "  ${MCLA_EXPECTED_TU_COUNT} are known; ${_mcla_unexpected_n} would be SILENTLY IGNORED:\n"
        "    ${_mcla_unexpected_list}\n"
        "  (${_mcla_unexpected_names_csv})\n"
        "  The mcla source list below enumerates ppc_recomp.0.cpp..ppc_recomp.${_mcla_tu_last}.cpp by hand,\n"
        "  so an extra file would compile, link and then never be called - the guest function it\n"
        "  holds would be silently dropped, with no build error at all.\n"
        "  Invariant: .qoder/skills/mcla-recompiler-regen/SKILL.md:57-58\n"
        "  (\"TU count must stay 176\"; the full skill is SKILL.md, the TU-count bullet is line 57).\n"
        "  Either delete the stray file (regen was pointed at the wrong out_directory_path, or a\n"
        "  partial regen left debris) or, if the count genuinely moved, bump MCLA_EXPECTED_TU_COUNT\n"
        "  and regenerate the source-list block to match - never just append to the list.")
endif()

# --- (c) the hand-written source list must still enumerate the same count --
# The add_executable(mcla ...) entries are the only 4-space-indented lines of
# this exact shape in the file, so this counts that block without parsing it.
# Catches the reverse drift the (a)/(b) pair cannot see: a TU dropped from
# the list while its file is still on disk compiles fine and is simply not
# linked into mcla.
# NOTE: CMAKE_CURRENT_LISTFILE is EMPTY on the cmake 4.4.0-rc3 this tree
# configures with (file(READ) then tries to open the working directory), so
# resolve this file's own path from CMAKE_CURRENT_LIST_DIR and fall back to the
# source dir - this gate lives in the top-level CMakeLists.txt by construction.
if(DEFINED CMAKE_CURRENT_LIST_DIR AND NOT CMAKE_CURRENT_LIST_DIR STREQUAL "")
    set(_mcla_this_file "${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt")
else()
    set(_mcla_this_file "${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt")
endif()
if(NOT EXISTS "${_mcla_this_file}")
    message(FATAL_ERROR
        "MCLA GATE [source-list drift]: cannot re-read '${_mcla_this_file}' to cross-check the\n"
        "  generated source list. Refusing to skip the check - this file must be the top-level\n"
        "  CMakeLists.txt for the check to mean anything.")
endif()
file(READ "${_mcla_this_file}" _mcla_cml_text)
string(REPLACE "\r\n" "\n" _mcla_cml_text "${_mcla_cml_text}")
string(REGEX MATCHALL "\n    generated/ppc_xenon/ppc_recomp\\.[0-9]+\\.cpp" _mcla_listed_tus "${_mcla_cml_text}")
list(LENGTH _mcla_listed_tus _mcla_listed_n)
if(NOT _mcla_listed_n EQUAL MCLA_EXPECTED_TU_COUNT)
    message(FATAL_ERROR
        "MCLA INVARIANT VIOLATED [source-list drift]:\n"
        "  the mcla source list enumerates ${_mcla_listed_n} generated/ppc_xenon/ppc_recomp.N.cpp\n"
        "  entries but MCLA_EXPECTED_TU_COUNT is ${MCLA_EXPECTED_TU_COUNT}.\n"
        "  The generated tree on disk passed checks (a) and (b), so the two have drifted apart and\n"
        "  some TU is either not compiled or not linked into mcla.exe.\n"
        "  Invariant: .qoder/skills/mcla-recompiler-regen/SKILL.md:57-58 (\"TU count must stay 176\").\n"
        "  Fix by regenerating the whole ppc_recomp.N.cpp block from MCLA_EXPECTED_TU_COUNT (entries\n"
        "  are counted only when indented with exactly 4 spaces, so keep that shape) - and if the\n"
        "  count really changed, update MCLA_EXPECTED_TU_COUNT at the same time.")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SDL3 REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

find_path(DXC_INCLUDE_DIR dxc/dxcapi.h PATHS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/dxc/inc" NO_DEFAULT_PATH)

# XenosRecomp shader cache generator
set(XENOS_RECOMP_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.research/XenosRecomp/XenosRecomp")
set(XENOS_RECOMP_THIRDPARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.research/XenosRecomp/thirdparty")

add_subdirectory(${XENOS_RECOMP_THIRDPARTY_DIR}/zstd/build/cmake zstd_build)
add_subdirectory(${XENOS_RECOMP_THIRDPARTY_DIR}/xxHash/cmake_unofficial xxhash_build)

add_library(smol-v STATIC
    ${XENOS_RECOMP_THIRDPARTY_DIR}/smol-v/source/smolv.cpp
)
target_include_directories(smol-v PUBLIC
    ${XENOS_RECOMP_THIRDPARTY_DIR}/smol-v/source
)
target_compile_definitions(smol-v PRIVATE _CRT_SECURE_NO_WARNINGS)

# EXCLUDE_FROM_ALL is load-bearing, not cosmetic. The XenosRecomp tool cannot
# be built with the toolchain this project pins: clang here is 19.1.7 and the
# MSVC STL that clang-cl actually resolves demands Clang >= 20, so every TU
# dies with `yvals_core.h(917): STL1000` (the `include_directories(AFTER
# SYSTEM ...)` block below pins the 14.44 toolset's own include dir *behind*
# the driver's default, and 14.44's copy of that same check only requires
# Clang >= 19). Documented at .qoder/skills/mcla-recompiler-regen/SKILL.md:11-19
# ("Current blocker (verified 2026-09-20) ... yvals_core.h(917): STL1000. Do
# not delete anything under .research/XenonRecomp/build-clang/ - the existing
# XenosRecomp.exe predates the VS upgrade and is the *only* binary carrying the
# landed JTS-TAILCALL patch").
#
# Before this flag a bare `ninja` built this target and failed, so "never run
# bare ninja" was tribal knowledge in the skill file. Now bare `ninja` is safe.
# CONSEQUENCE: the target no longer appears in `ninja` / `ninja all`. Anything
# that genuinely wants it must name it explicitly:
#     cmake --build build --target XenosRecomp
#     ninja -C build XenosRecomp
# and on this toolchain that command is EXPECTED TO FAIL with STL1000 - it is
# not a regression in mcla. Route A (a [[midasm_hook]] in the tracked
# config/mcla_xenonrecomp.toml, SKILL.md:21-26) is the supported path, and
# Route B is off the critical path as of 2026-09-20 (SKILL.md:18-19).
add_executable(XenosRecomp EXCLUDE_FROM_ALL
    ${XENOS_RECOMP_SOURCE_DIR}/main.cpp
    ${XENOS_RECOMP_SOURCE_DIR}/shader_recompiler.cpp
    ${XENOS_RECOMP_SOURCE_DIR}/dxc_compiler.cpp
)
target_include_directories(XenosRecomp PRIVATE
    ${XENOS_RECOMP_SOURCE_DIR}
    ${XENOS_RECOMP_THIRDPARTY_DIR}/fmt/include
    ${XENOS_RECOMP_THIRDPARTY_DIR}/smol-v/source
    ${XENOS_RECOMP_THIRDPARTY_DIR}/xxHash/lib
    ${XENOS_RECOMP_THIRDPARTY_DIR}/zstd/lib
    ${DXC_INCLUDE_DIR}
)
target_compile_definitions(XenosRecomp PRIVATE
    XENOS_RECOMP_DXIL
    NOMINMAX
    _CRT_SECURE_NO_WARNINGS
)
target_compile_options(XenosRecomp PRIVATE
    "/FI${CMAKE_CURRENT_BINARY_DIR}/xenos_recomp_include/force_include.h"
)
target_link_libraries(XenosRecomp PRIVATE
    fmt::fmt
    libzstd_static xxhash smol-v
    ${XENOS_RECOMP_THIRDPARTY_DIR}/dxc-bin/lib/x64/dxcompiler.lib
    user32.lib advapi32.lib
)

set_property(DIRECTORY APPEND PROPERTY CMAKE_CXX_KNOWN_TARGETS mcla)
list(APPEND MCLA_GENERATED_SOURCES ${SHADER_CACHE_OUTPUT})

# MSVC toolset + Windows SDK paths
set(MSVC_TOOLSET_PATH "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.44.35207")
set(MSVC_INCLUDE_PATH "${MSVC_TOOLSET_PATH}/include")
set(MSVC_LIB_PATH "${MSVC_TOOLSET_PATH}/lib/x64")

set(WINDOWS_SDK_PATH "C:/Program Files (x86)/Windows Kits/10")
set(WINDOWS_SDK_VERSION "10.0.26100.0")
set(WINDOWS_SDK_UM_LIB_PATH "${WINDOWS_SDK_PATH}/Lib/${WINDOWS_SDK_VERSION}/um/x64")
set(WINDOWS_SDK_UCRT_LIB_PATH "${WINDOWS_SDK_PATH}/Lib/${WINDOWS_SDK_VERSION}/ucrt/x64")

include_directories(AFTER SYSTEM
    "${MSVC_INCLUDE_PATH}"
    "${WINDOWS_SDK_PATH}/Include/${WINDOWS_SDK_VERSION}/ucrt"
    "${WINDOWS_SDK_PATH}/Include/${WINDOWS_SDK_VERSION}/shared"
    "${WINDOWS_SDK_PATH}/Include/${WINDOWS_SDK_VERSION}/um"
    "${WINDOWS_SDK_PATH}/Include/${WINDOWS_SDK_VERSION}/winrt"
)
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
    src/hooks/hooks.h
    src/hooks/alloc_census.cpp
    src/hooks/config_dispatch.cpp
    src/cpu/vmx128_pack.cpp
    src/dispatch_guard.cpp
    src/patches.h
    src/gpu_mmio.cpp
    src/gpu_mmio.h
    src/gpu_cp.cpp
    src/gpu_cp.h
    src/gpu_device.cpp
    src/gpu_device.h
    src/task_dispatch_trace.cpp
    src/native_renderer.cpp
    src/native_renderer.h
    src/renderer_mode.cpp
    src/renderer_mode.h
    src/renderer_hook_dispatch.cpp
    src/renderer_hook_dispatch.h
    src/guest_memory.cpp
    src/guest_memory.h
    src/guest_mem_scan.cpp
    src/frame_trace.cpp
    src/frame_trace.h
    src/capture_hooks.cpp
    src/capture_hooks.h
    src/renderer/trace_types.h
    src/fs/vfs_rpf.cpp
    src/fs/vfs_rpf.h
    src/fs/rpf3_nested.cpp
    src/fs/rpf3_nested.h
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
    # F-609 port batch. Hand-written ports of console kernel exports that used to
    # be empty GUEST_FUNCTION_STUB bodies in src/kernel/imports.cpp. These are
    # NOT generated recompiler output, so they are deliberately NOT of the form
    # "\n    generated/ppc_xenon/ppc_recomp.N.cpp" that the MCLA_EXPECTED_TU_COUNT
    # gate (c) counts -- adding them cannot move the 176-TU invariant, and
    # deliberately adding them in another shape would break it.
    src/kernel/port_net.cpp
    src/kernel/port_net.h
    src/kernel/port_xam_user.cpp
    src/kernel/port_xam_user.h
    src/kernel/port_kobj.cpp
    src/kernel/port_kobj.h
    src/kernel/port_voice_input.cpp
    src/kernel/port_voice_input.h
    .research/XenonRecomp/thirdparty/xxHash/xxhash.c
    src/boot_host.cpp
    src/boot_host.h
    src/boot_log.cpp
    src/common/logging.h
    src/common/cvar.h
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
    src/renderer/resource_cache.cpp
    src/renderer/resource_cache.h
    src/renderer/texture_decode.cpp
    src/renderer/texture_decode.h
    src/renderer/test_shaders.h
    src/render_queue.h
    src/render_thread.cpp
    src/render_thread.h
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
    .research/XenonRecomp/XenonUtils/xex.cpp
    .research/XenonRecomp/XenonUtils/image.cpp
    .research/XenonRecomp/XenonUtils/xex_patcher.cpp
    .research/XenonRecomp/XenonUtils/memory_mapped_file.cpp
    .research/XenonRecomp/thirdparty/libmspack/libmspack/mspack/lzxd.c
    .research/XenonRecomp/thirdparty/tiny-AES-c/aes.c
)

target_include_directories(mcla PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common
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
    kernel32.lib user32.lib gdi32.lib winmm.lib imm32.lib ole32.lib oleaut32.lib
    version.lib uuid.lib advapi32.lib setupapi.lib shell32.lib hid.lib dinput8.lib
    ws2_32.lib dbghelp.lib dxgi.lib dxguid.lib d3d12.lib
)

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

set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MT /O2 /Ob1 /DNDEBUG")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "/MT /O2 /Ob1 /DNDEBUG")

target_compile_options(mcla PRIVATE /GS- /EHa)
# F-119 follow-up: the boot-thread sampler reports HOST rips, and with no PDB in
# this build they were unnameable (llvm-symbolizer -> '??'), which blocked every
# "where is the main thread parked" question. /MAP is link-time only (no recompile
# flags change) and emits build/mcla.map with symbol addresses, so an RVA from a
# log line resolves to a function offline.
target_link_options(mcla PRIVATE /OPT:NOREF /MAP)
target_compile_definitions(mcla PRIVATE $<$<NOT:$<CONFIG:Debug>>:NDEBUG>)

# Offline validators
set(RENDERER_IR_TUS
    src/renderer/xenos_microcode.cpp
    src/renderer/xenos_shader_ir.cpp
    src/renderer/shader_translator.cpp
    tools/validators/shader_dxc_compile.cpp
    src/renderer/dxc_runtime.cpp
    src/renderer/pipeline_cache.cpp
)

set(VALIDATOR_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/validators
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/SDL3/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/fmt
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/toml++/include
    ${CMAKE_CURRENT_SOURCE_DIR}/.research/XenosRecomp/thirdparty/smol-v/source
    ${DXC_INCLUDE_DIR}
)
set(VALIDATOR_COMPILE_DEFS NOMINMAX WIN32_LEAN_AND_MEAN _CRT_SECURE_NO_WARNINGS MCLA_STANDALONE _ALLOW_COMPILER_AND_STL_VERSION_MISMATCH _HAS_CXX23=0)

add_executable(shader_pipeline_validator
    tools/validators/shader_pipeline_validator.cpp ${RENDERER_IR_TUS})
target_include_directories(shader_pipeline_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(shader_pipeline_validator PRIVATE ${VALIDATOR_COMPILE_DEFS})
target_link_libraries(shader_pipeline_validator PRIVATE d3d12.lib dxgi.lib dxguid.lib)

add_executable(xenos_decode_validator
    tools/validators/xenos_decode_validator.cpp ${RENDERER_IR_TUS})
target_include_directories(xenos_decode_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(xenos_decode_validator PRIVATE ${VALIDATOR_COMPILE_DEFS})
target_link_libraries(xenos_decode_validator PRIVATE d3d12.lib dxgi.lib dxguid.lib)

add_executable(phase3_validator
    tools/validators/phase3_validator.cpp ${RENDERER_IR_TUS}
    src/renderer/vertex_decode.cpp src/renderer/grc_fvf_decode.cpp src/renderer/resource_cache.cpp src/renderer/texture_decode.cpp)
target_include_directories(phase3_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(phase3_validator PRIVATE ${VALIDATOR_COMPILE_DEFS})
target_link_libraries(phase3_validator PRIVATE d3d12.lib dxgi.lib dxguid.lib)

add_executable(texture_decode_test
    tools/validators/texture_decode_test.cpp
    src/renderer/texture_decode.cpp src/renderer/resource_cache.cpp)
target_include_directories(texture_decode_test PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(texture_decode_test PRIVATE ${VALIDATOR_COMPILE_DEFS})

add_executable(capture_dump_validator
    tools/validators/capture_dump_validator.cpp src/frame_trace.cpp src/frame_trace.h
    src/renderer/vertex_decode.cpp)
target_include_directories(capture_dump_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(capture_dump_validator PRIVATE
    ${VALIDATOR_COMPILE_DEFS}
    FMT_HEADER_ONLY=1 SPDLOG_FMT_EXTERNAL SPDLOG_FWRITE_UNLOCKED)
# frame_trace.cpp -> logging.h uses try/catch (see phase0 note re bare -MT).
target_compile_options(capture_dump_validator PRIVATE /GS- /EHa)
target_link_libraries(capture_dump_validator PRIVATE
    fmt::fmt spdlog::spdlog_header_only)

add_executable(xtr_dump_validator tools/validators/xtr_dump_validator.cpp)
target_include_directories(xtr_dump_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(xtr_dump_validator PRIVATE ${VALIDATOR_COMPILE_DEFS})

# Build-artifact check for the Path A host XMem/raw-LZX decoder (src/xmem_lzx.h).
# Decodes the 4 UI .xsf straight out of the RPF and byte-compares against
# build/xmem_golden/*.bin (written by tools/xmem_decode.py). Deliberately NOT part
# of mcla.exe and NOT a soak dependency - it never touches the guest VM, so a
# byte-exactness regression fails here at build time instead of surfacing as a
# silently corrupt container in a boot log. Run: ninja -C build check_xmem_lzx
add_executable(xmem_lzx_test tools/xmem_lzx_test.cpp)
target_compile_definitions(xmem_lzx_test PRIVATE
    ${VALIDATOR_COMPILE_DEFS}
    MCLA_XMEM_ARCHIVE="${CMAKE_BINARY_DIR}/game_data/xarchive_cache.rpf"
    MCLA_XMEM_GOLDEN_DIR="${CMAKE_BINARY_DIR}/xmem_golden")

add_custom_target(check_xmem_lzx DEPENDS xmem_lzx_test
    COMMAND $<TARGET_FILE:xmem_lzx_test>
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Path A host LZX byte-exactness vs build/xmem_golden")

# ===========================================================================
# GATE 2 - a recompiler regen must be byte-reproducible.
#
# .qoder/skills/mcla-recompiler-regen/SKILL.md:41-49 ("Reproducibility gate
# (hard, run before touching the tool)") was prose only, so the second
# invariant could be violated by a regen with nothing in the build to notice.
# It is now a target.  Same shape as check_xmem_lzx above: an add_custom_target
# that runs a checker and fails the build.
#
# This is a VERIFIER, not a regen driver: it never runs XenosRecomp, which
# cannot be built with the pinned toolchain (SKILL.md:11-19, STL1000).  You
# run the regen yourself into a scratch dir, then point this at the result.
# Default scratch dir matches config/mcla_xenonrecomp_baseline.toml:3
# (out_directory_path = "build/xr_baseline").
#
# Invoke EITHER way:
#   via ninja, after -DMCLA_REGEN_OUTPUT_DIR=<your regen dir> at configure time:
#       cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_BUILD_TYPE=RelWithDebInfo -DMCLA_REGEN_OUTPUT_DIR=E:/tmp/xr_check
#       ninja -C build check_regen_repro
#   or standalone, no reconfigure, no build of anything (copy-pasteable):
#       cmake -DMCLA_REGEN_NEW_DIR="E:/mcla pc/build/xr_baseline" -DMCLA_REGEN_REF_DIR="E:/mcla pc/generated/ppc_xenon" -P build/check_regen_repro.cmake
#
# Allowed to differ, and nothing else (SKILL.md:45-48):
#   1. ppc_context.h  - a trailing newline (the regen does not emit the one
#      the round-tripped src/ppc_context.h header has).
#   2. the one TU that defines sub_8218CC70 - a HAND safety patch
#      (indirect-branch targetFn/basePtr validation via
#      mcla_DispatchGuard_8218CC94) that the tool cannot emit. SKILL.md:48:
#      "Never full-replace ppc_recomp.10.cpp or the session-38 null-dispatch
#      AV returns."  The TU is located BY SYMBOL, not by name: as of
#      2026-09-28 the hand patch actually lives in ppc_recomp.9.cpp
#      (lines 19138-19171), not ppc_recomp.10.cpp as SKILL.md:46-48 says, and
#      SKILL.md is not ours to edit here - the verifier reports which TU it
#      used so the stale doc line stays visible. The diff must stay INSIDE
#      that function body; a full-replace or a second edit fails.
# ===========================================================================
set(mcla_regen_script_tmpl [==[cmake_minimum_required(VERSION 3.25)

# ===========================================================================
# check_regen_repro.cmake - GENERATED BY CMakeLists.txt, DO NOT EDIT.
#
# Verifies that a XenonRecomp regen is byte-reproducible against
# generated/ppc_xenon, allowing exactly the two known deltas documented in
# .qoder/skills/mcla-recompiler-regen/SKILL.md:41-49.
#
# This never runs the recompiler. Run the regen yourself into a scratch dir
# (config/mcla_xenonrecomp_baseline.toml, SKILL.md:43-44), then:
#   cmake -DMCLA_REGEN_NEW_DIR=<regen dir> -P build/check_regen_repro.cmake
# ===========================================================================

set(_guard_fn "sub_8218CC70")
set(_guard_hook "mcla_DispatchGuard_8218CC94")
set(_expected_tu_count @MCLA_EXPECTED_TU_COUNT@)

# --- 0. arguments ----------------------------------------------------------
if(NOT DEFINED MCLA_REGEN_NEW_DIR OR MCLA_REGEN_NEW_DIR STREQUAL "")
    message(FATAL_ERROR
        "check_regen_repro: MCLA_REGEN_NEW_DIR is not set.\n"
        "  Pass the directory a regen wrote to, e.g.\n"
        "    cmake -DMCLA_REGEN_NEW_DIR=\"E:/mcla pc/build/xr_baseline\" -DMCLA_REGEN_REF_DIR=\"E:/mcla pc/generated/ppc_xenon\" -P build/check_regen_repro.cmake\n"
        "  or, via ninja: cmake -S . -B build -DMCLA_REGEN_OUTPUT_DIR=<dir> ... then ninja -C build check_regen_repro\n"
        "  (This target deliberately does not run the recompiler - it cannot be built with the\n"
        "   pinned toolchain; see .qoder/skills/mcla-recompiler-regen/SKILL.md:11-19.)")
endif()
if(NOT DEFINED MCLA_REGEN_REF_DIR OR MCLA_REGEN_REF_DIR STREQUAL "")
    set(MCLA_REGEN_REF_DIR "@MCLA_RECOMP_DIR@")
endif()
set(_ref "${MCLA_REGEN_REF_DIR}")
set(_new "${MCLA_REGEN_NEW_DIR}")
foreach(_d IN ITEMS _ref _new)
    if(NOT IS_DIRECTORY "${${_d}}")
        message(FATAL_ERROR "check_regen_repro: ${_d} = '${${_d}}' is not a directory")
    endif()
endforeach()
message(STATUS "check_regen_repro: REF (hand-patched, committed state) = ${_ref}")
message(STATUS "check_regen_repro: NEW (regen output)                  = ${_new}")

# --- helpers ---------------------------------------------------------------
# Byte span of the PPC_FUNC_IMPL(__imp__<fn>) "unit" inside a file held in the
# variable named <txtvar>: from the fn's alias line (extended back over the hand
# patch's "extern ... <hook>" declaration and blank lines) to just before the
# next top-level __attribute__ line.  Sets <prefix>_s / <prefix>_e.
#
# This works on raw text offsets rather than line indices on purpose.  Two
# reasons, both measured on the real ppc_recomp.9.cpp (1.4 MB):
#   * file(STRINGS) does not escape ';' inside a line, so a C++ statement ending
#     in ';' occupies two list elements and the ref/new index spaces are NOT
#     comparable - a line-index containment test FAILS on a genuine clean regen
#     (the hand patch inserts its extern line, shifting every later index by 1).
#   * splitting a 1.4 MB TU into ~40k list elements in CMake script mode took
#     149 s.  Native string ops on the raw text take about a second.
function(mcla_unit_span txtvar fn hook prefix)
    set(_t "${${txtvar}}")
    string(FIND "${_t}" "PPC_FUNC_IMPL(__imp__${fn})" _p)
    if(_p LESS 0)
        set(${prefix}_s -1)
        set(${prefix}_e -1)
        return()
    endif()
    # start of the unit: the alias line, extended back over the hook declaration
    set(_s ${_p})
    string(FIND "${_t}" "__attribute__((alias(\"__imp__${fn}\"" _a)
    if(NOT _a LESS 0 AND _a LESS _p)
        set(_s ${_a})
    endif()
    string(FIND "${_t}" "extern bool ${hook}" _x)
    if(NOT _x LESS 0 AND _x LESS _p AND _x LESS _s)
        set(_s ${_x})
    endif()
    # end of the unit: the next top-level __attribute__ after the impl line
    # (string(FIND) has no start-offset option, so search the tail and rebase).
    # If there is no later __attribute__ the function is last in the file and
    # the unit runs to EOF; that is the permissive direction, so the start
    # bound above is what pins the delta.
    string(SUBSTRING "${_t}" ${_p} -1 _rest)
    string(FIND "${_rest}" "\n__attribute__" _n)
    if(_n LESS 0)
        math(EXPR _e 1000000000)
    else()
        math(EXPR _e "${_p} + ${_n}")
    endif()
    set(${prefix}_s "${_s}" PARENT_SCOPE)
    set(${prefix}_e "${_e}" PARENT_SCOPE)
endfunction()

# Allowed delta 2: prove the difference is confined to the <fn> body.
# Method: strip each side's <fn> unit and require the remainders to be
# byte-identical.  That single statement is exactly the invariant, and it
# catches an edit anywhere else in the TU, not just near the function.
function(mcla_check_guard_delta ref new tu fn hook out_ok out_why)
    set(_ok FALSE)
    set(_why "")
    file(READ "${ref}/${tu}" _rt)
    file(READ "${new}/${tu}" _nt)
    mcla_unit_span(_rt "${fn}" "${hook}" r)
    mcla_unit_span(_nt "${fn}" "${hook}" n)
    if(r_s LESS 0 OR n_s LESS 0 OR r_e LESS 0 OR n_e LESS 0)
        set(_why "the ${fn} body was not locatable on one side, so the delta cannot be bounded")
    elseif(r_s GREATER r_e OR n_s GREATER n_e)
        set(_why "the ${fn} unit span is inverted on one side - refusing to guess")
    else()
        string(SUBSTRING "${_rt}" 0 ${r_s} _rpre)
        string(SUBSTRING "${_rt}" ${r_e} -1 _rpost)
        string(SUBSTRING "${_nt}" 0 ${n_s} _npre)
        string(SUBSTRING "${_nt}" ${n_e} -1 _npost)
        set(_rout "${_rpre}${_rpost}")
        set(_nout "${_npre}${_npost}")
        if(NOT "${_rout}" STREQUAL "${_nout}")
            set(_why "the two files differ OUTSIDE the ${fn} body - this TU carries more than the hand patch (a full-replace, or a second edit somewhere else in the file)")
        else()
            math(EXPR _rlen "${r_e} - ${r_s}")
            math(EXPR _nlen "${n_e} - ${n_s}")
            string(SUBSTRING "${_rt}" ${r_s} ${_rlen} _ru)
            string(SUBSTRING "${_nt}" ${n_s} ${_nlen} _nu)
            string(FIND "${_ru}" "${hook}" _hk_r)
            string(FIND "${_nu}" "${hook}" _hk_n)
            string(REGEX MATCHALL "\n" _rn "${_ru}")
            string(REGEX MATCHALL "\n" _nn "${_nu}")
            list(LENGTH _rn _rn)
            list(LENGTH _nn _nn)
            math(EXPR _d "${_rn} - ${_nn}")
            if(_hk_r LESS 0)
                set(_why "the ${fn} body in the reference tree does not contain ${hook} - the hand patch is gone")
            elseif(NOT _hk_n LESS 0)
                set(_why "the ${fn} body in the regen output also contains ${hook} - that is not the unpatched tool output, so this delta is not the known one")
            elseif("${_ru}" STREQUAL "${_nu}")
                set(_why "the ${fn} bodies are byte-identical - the hand patch is missing from the reference tree")
            else()
                set(_ok TRUE)
                set(_why "confined to the ${fn} body: ${_rlen} B / ${_rn} lines in the reference tree vs ${_nlen} B / ${_nn} lines in the regen output (${_d} lines)")
            endif()
        endif()
    endif()
    set(${out_ok} "${_ok}" PARENT_SCOPE)
    set(${out_why} "${_why}" PARENT_SCOPE)
endfunction()

# --- 1. TU count (invariant 1, checked here too) ---------------------------
# Deliberately BEFORE the file-set comparison, so a changed count gets the
# specific "TU count" diagnosis instead of the vaguer "file set mismatch".
file(GLOB _ref_all RELATIVE "${_ref}" "${_ref}/*")
file(GLOB _new_all RELATIVE "${_new}" "${_new}/*")
list(SORT _ref_all)
list(SORT _new_all)
set(_ref_tus "")
set(_new_tus "")
foreach(_f IN LISTS _ref_all)
    if(_f MATCHES "^ppc_recomp\\.[0-9]+\\.cpp$")
        list(APPEND _ref_tus "${_f}")
    endif()
endforeach()
foreach(_f IN LISTS _new_all)
    if(_f MATCHES "^ppc_recomp\\.[0-9]+\\.cpp$")
        list(APPEND _new_tus "${_f}")
    endif()
endforeach()
list(LENGTH _new_tus _new_tu_n)
if(NOT _new_tu_n EQUAL _expected_tu_count)
    message(FATAL_ERROR
        "check_regen_repro: the regen produced ${_new_tu_n} ppc_recomp.N.cpp files; the invariant is ${_expected_tu_count}\n"
        "  (.qoder/skills/mcla-recompiler-regen/SKILL.md:57-58, \"TU count must stay 176\"). The CMake\n"
        "  configure-time gate would reject the same tree. Per SKILL.md:49 a regen that is not clean\n"
        "  means STOP and fall back to Route A/C.")
endif()

# --- 2. identical file-name sets -------------------------------------------
set(_only_ref "")
set(_only_new "")
foreach(_f IN LISTS _ref_all)
    list(FIND _new_all "${_f}" _i)
    if(_i EQUAL -1)
        list(APPEND _only_ref "${_f}")
    endif()
endforeach()
foreach(_f IN LISTS _new_all)
    list(FIND _ref_all "${_f}" _i)
    if(_i EQUAL -1)
        list(APPEND _only_new "${_f}")
    endif()
endforeach()
if(_only_ref OR _only_new)
    set(_m "")
    if(_only_ref)
        list(JOIN _only_ref ", " _jr)
        string(APPEND _m "    only in REF: ${_jr}\n")
    endif()
    if(_only_new)
        list(JOIN _only_new ", " _jn)
        string(APPEND _m "    only in NEW: ${_jn}\n")
    endif()
    message(FATAL_ERROR
        "check_regen_repro: FILE SET MISMATCH - the regen did not reproduce the tree.\n"
        "${_m}"
        "  A regen is expected to differ in bytes only, never in file names\n"
        "  (.qoder/skills/mcla-recompiler-regen/SKILL.md:41-49).")
endif()

# --- 3. locate the hand-patched TU BY SYMBOL, not by name ------------------
# file(READ)+string(FIND) rather than file(STRINGS ... REGEX): the latter splits
# a 1.4 MB TU into ~40k list elements in script mode and took 149 s per file.
# The scan stops at the first hit, so the real tree costs 10 file reads.
set(_guard_needle "PPC_FUNC_IMPL(__imp__${_guard_fn})")
set(_guard_tu "")
foreach(_f IN LISTS _ref_tus)
    file(READ "${_ref}/${_f}" _blob)
    string(FIND "${_blob}" "${_guard_needle}" _hit)
    unset(_blob)
    if(NOT _hit LESS 0)
        set(_guard_tu "${_f}")
        break()
    endif()
endforeach()
if(_guard_tu STREQUAL "")
    message(FATAL_ERROR
        "check_regen_repro: no ppc_recomp.N.cpp in the reference tree defines PPC_FUNC_IMPL(__imp__${_guard_fn}),\n"
        "  which is the function the one allowed code delta is pinned to. Refusing to guess.")
endif()
message(STATUS "check_regen_repro: hand-patch TU located by symbol ${_guard_fn} -> ${_guard_tu}")
if(NOT _guard_tu STREQUAL "ppc_recomp.10.cpp")
    message(STATUS "check_regen_repro: NOTE SKILL.md:46-48 names ppc_recomp.10.cpp as the hand-patched TU, but the")
    message(STATUS "check_regen_repro:      tree actually carries it in ${_guard_tu}. Verifier follows the tree; the doc line is stale.")
endif()

# --- 4. the reference tree must still carry the hand patch -----------------
file(READ "${_ref}/${_guard_tu}" _ref_blob)
string(FIND "${_ref_blob}" "${_guard_hook}" _hook_at)
unset(_ref_blob)
if(_hook_at LESS 0)
    message(FATAL_ERROR
        "check_regen_repro: ${_guard_tu} in the reference tree (${_ref}) no longer contains the hand safety\n"
        "  patch symbol ${_guard_hook}: the hand-patched translation unit has been full-replaced.\n"
        "  .qoder/skills/mcla-recompiler-regen/SKILL.md:48: \"Never full-replace ppc_recomp.10.cpp or the\n"
        "  session-38 null-dispatch AV returns.\" Restore the patch; never accept a regen over it.")
endif()

# --- 5. byte-compare every file --------------------------------------------
# cmake -E compare_files rather than file(READ): generated/ppc_xenon is ~127 MB
# and CMake script-mode strings would have to hold all of it.
set(_identical 0)
set(_differing "")
foreach(_f IN LISTS _ref_all)
    execute_process(
        COMMAND "${CMAKE_COMMAND}" -E compare_files "${_ref}/${_f}" "${_new}/${_f}"
        RESULT_VARIABLE _rc OUTPUT_QUIET ERROR_QUIET)
    if(_rc EQUAL 0)
        math(EXPR _identical "${_identical} + 1")
    else()
        list(APPEND _differing "${_f}")
    endif()
endforeach()
list(LENGTH _ref_all _total)
message(STATUS "check_regen_repro: ${_identical}/${_total} files byte-identical (SKILL.md:45-48 expected 181/183)")

# --- 6. classify the differences: only the two known deltas are allowed ----
set(_unexpected "")
set(_accepted "")
foreach(_f IN LISTS _differing)
    if(_f STREQUAL "ppc_context.h")
        # allowed delta 1: a trailing newline and nothing else
        file(READ "${_ref}/${_f}" _hr HEX)
        file(READ "${_new}/${_f}" _hn HEX)
        string(LENGTH "${_hr}" _lr)
        string(LENGTH "${_hn}" _ln)
        set(_why "")
        if(_lr EQUAL _ln)
            set(_why "same length (${_lr} bytes) but not byte-identical, so a trailing newline cannot explain it")
        else()
            if(_lr GREATER _ln)
                set(_tail "${_hr}")
                set(_lead "${_hn}")
                set(_shortlen ${_ln})
            else()
                set(_tail "${_hn}")
                set(_lead "${_hr}")
                set(_shortlen ${_lr})
            endif()
            string(SUBSTRING "${_tail}" 0 ${_shortlen} _pre_tail)
            string(SUBSTRING "${_lead}" 0 ${_shortlen} _pre_lead)
            string(SUBSTRING "${_tail}" ${_shortlen} -1 _extra)
            if(NOT _pre_tail STREQUAL _pre_lead)
                set(_why "the two files differ BEFORE the final byte(s), so this is not a trailing-newline delta")
            elseif(NOT _extra STREQUAL "0a" AND NOT _extra STREQUAL "0d0a")
                set(_why "the only differing bytes are '${_extra}', which is not a newline (expected 0a or 0d0a)")
            endif()
        endif()
        if(_why STREQUAL "")
            list(APPEND _accepted "${_f} (trailing newline)")
        else()
            list(APPEND _unexpected "${_f}: ${_why}")
        endif()
    elseif(_f STREQUAL "${_guard_tu}")
        mcla_check_guard_delta("${_ref}" "${_new}" "${_guard_tu}" "${_guard_fn}" "${_guard_hook}" _gok _gwhy)
        if(_gok)
            list(APPEND _accepted "${_f} (hand safety patch in ${_guard_fn}: ${_gwhy})")
        else()
            list(APPEND _unexpected "${_f}: ${_gwhy}")
        endif()
    else()
        list(APPEND _unexpected "${_f}: not one of the two known deltas")
    endif()
endforeach()

# --- 7. verdict ------------------------------------------------------------
if(_unexpected)
    list(LENGTH _unexpected _un)
    list(JOIN _unexpected "\n    " _un_txt)
    message(FATAL_ERROR
        "check_regen_repro: REPRODUCIBILITY GATE FAILED - ${_un} unexpected difference(s):\n"
        "    ${_un_txt}\n"
        "  Only two deltas are allowed: (1) a ppc_context.h trailing newline, and (2) the hand safety\n"
        "  patch inside ${_guard_fn} in ${_guard_tu}.\n"
        "  .qoder/skills/mcla-recompiler-regen/SKILL.md:49: \"If a fresh regen is not byte-for-byte clean ->\n"
        "  STOP, fall back to Route A/C.\" Do not copy the regen output over generated/ppc_xenon, and do not\n"
        "  full-replace ${_guard_tu} (SKILL.md:48).")
endif()
list(LENGTH _accepted _acc)
list(JOIN _accepted "; " _acc_txt)
message(STATUS "check_regen_repro: accepted deltas: ${_acc_txt}")
message(STATUS "check_regen_repro: OK - regen is byte-reproducible (SKILL.md:41-49 satisfied)")
]==])

set(MCLA_REGEN_OUTPUT_DIR "${CMAKE_BINARY_DIR}/xr_baseline" CACHE PATH
    "Regen output directory compared against generated/ppc_xenon by the check_regen_repro target")

# The checker itself is emitted at configure time (kept inline here so the
# gate travels with the one file that owns it; it lands in the build dir and
# is disposable).  Only the two configure-time values are interpolated, by
# explicit REPLACE rather than string(CONFIGURE)/@ONLY: string(CONFIGURE)
# returns an EMPTY STRING on the cmake 4.4.0-rc3 this tree configures with, and
# an empty verifier would make `ninja check_regen_repro` pass vacuously.
string(REPLACE "@MCLA_RECOMP_DIR@" "${MCLA_RECOMP_DIR}" _mcla_regen_script "${mcla_regen_script_tmpl}")
string(REPLACE "@MCLA_EXPECTED_TU_COUNT@" "${MCLA_EXPECTED_TU_COUNT}" _mcla_regen_script "${_mcla_regen_script}")
if(_mcla_regen_script STREQUAL "")
    message(FATAL_ERROR "check_regen_repro: the verifier template expanded to nothing - refusing to install a check that cannot fail.")
endif()
string(FIND "${_mcla_regen_script}" "@MCLA_EXPECTED_TU_COUNT@" _mcla_unexpanded)
if(NOT _mcla_unexpanded EQUAL -1)
    message(FATAL_ERROR "check_regen_repro: the verifier template still contains an uninterpolated placeholder - refusing to install a half-written check.")
endif()
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/check_regen_repro.cmake" "${_mcla_regen_script}")

add_custom_target(check_regen_repro
    COMMAND ${CMAKE_COMMAND}
            "-DMCLA_REGEN_NEW_DIR=${MCLA_REGEN_OUTPUT_DIR}"
            "-DMCLA_REGEN_REF_DIR=${MCLA_RECOMP_DIR}"
            -P "${CMAKE_CURRENT_BINARY_DIR}/check_regen_repro.cmake"
    VERBATIM
    COMMENT "regen byte-reproducibility vs generated/ppc_xenon (2 known deltas allowed)")

add_executable(backend_validator
    tools/validators/backend_validator.cpp
    src/renderer/vertex_decode.cpp src/renderer/resource_cache.cpp src/renderer/texture_decode.cpp)
target_include_directories(backend_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(backend_validator PRIVATE ${VALIDATOR_COMPILE_DEFS})
target_link_libraries(backend_validator PRIVATE d3d12.lib dxgi.lib dxguid.lib)

# External asset-import proof: links the REAL src/d3d12_backend.cpp (not a replica of
# its calls the way backend_validator section 9 is) so CreateDecodedTexture finally has
# a producer. Deliberately not part of mcla.exe - it opens its own window, presents to
# it, and cannot affect the boot path or any CP-DRAW/DRAW_INDEXED counter.
add_executable(texture_import_validator
    tools/validators/texture_import_validator.cpp
    tools/validators/texture_import_stubs.cpp
    src/d3d12_backend.cpp
    src/guest_memory.cpp
    ${RENDERER_IR_TUS}
    src/renderer/vertex_decode.cpp
    src/renderer/grc_fvf_decode.cpp
    src/renderer/resource_cache.cpp
    src/renderer/texture_decode.cpp)
target_include_directories(texture_import_validator PRIVATE ${VALIDATOR_INCLUDE_DIRS})
target_compile_definitions(texture_import_validator PRIVATE
    ${VALIDATOR_COMPILE_DEFS}
    FMT_HEADER_ONLY=1 SPDLOG_FMT_EXTERNAL SPDLOG_FWRITE_UNLOCKED)
# src/common/logging.h uses try/catch and the default flag set is bare -MT (same
# reason capture_dump_validator carries this - see the phase0 note there).
target_compile_options(texture_import_validator PRIVATE /GS- /EHa)
target_link_libraries(texture_import_validator PRIVATE
    d3d12.lib dxgi.lib dxguid.lib user32.lib gdi32.lib
    fmt::fmt spdlog::spdlog_header_only)

add_executable(phase0_validator
    tools/validators/phase0_validator.cpp
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
# heap.cpp -> logging.h uses try/catch; needs async EH like mcla itself.
# NOTE: keep the /GS- first: this toolchain emits a bare -MT that swallows
# the next token as its depfile target (mcla's /GS- absorbs it, sparing /EHa).
target_compile_options(phase0_validator PRIVATE /GS- /EHa)
target_link_libraries(phase0_validator PRIVATE fmt::fmt spdlog::spdlog_header_only dbghelp.lib)

