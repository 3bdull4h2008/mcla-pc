# Local spdlog package config - provides header-only spdlog
# This overrides the broken SDK spdlog package (its spdlogConfigTargets.cmake
# references spdlogrd.lib/spdlogd.lib/spdlog.lib that the SDK never ships).

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

find_package(Threads REQUIRED)

set(SPDLOG_FMT_EXTERNAL ON)
set(SPDLOG_FMT_EXTERNAL_HO OFF)
set(SPDLOG_VERSION "1.14.1")

set(SPDLOG_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/third_party/spdlog/include")

if(NOT TARGET spdlog::spdlog_header_only)
  add_library(spdlog::spdlog_header_only INTERFACE IMPORTED)
  set_target_properties(spdlog::spdlog_header_only PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${SPDLOG_INCLUDE_DIR}"
    INTERFACE_COMPILE_DEFINITIONS "SPDLOG_FMT_EXTERNAL;SPDLOG_FWRITE_UNLOCKED"
    INTERFACE_LINK_LIBRARIES "Threads::Threads;fmt::fmt"
  )
endif()

# Alias for compatibility with code that names the compiled target.
if(NOT TARGET spdlog::spdlog)
  add_library(spdlog::spdlog ALIAS spdlog::spdlog_header_only)
endif()

set(spdlog_INCLUDE_DIRS "${SPDLOG_INCLUDE_DIR}")
set(spdlog_LIBRARIES spdlog::spdlog_header_only)
set(spdlog_STATIC_LIBRARIES "")

check_required_components(spdlog)

message(STATUS "Found spdlog: ${SPDLOG_VERSION} (header-only override)")
