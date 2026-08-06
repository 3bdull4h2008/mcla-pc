# fmt-config.cmake - Override for header-only fmt
# This is found first in CMAKE_PREFIX_PATH to avoid SDK's broken config

set(fmt_FOUND TRUE)
set(fmt_VERSION "10.2.1")

# Provide header-only target
add_library(fmt::fmt-header-only INTERFACE IMPORTED)
set_target_properties(fmt::fmt-header-only PROPERTIES
    INTERFACE_COMPILE_DEFINITIONS "FMT_HEADER_ONLY=1"
    INTERFACE_COMPILE_FEATURES "cxx_std_11"
    INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Alias for backward compatibility
add_library(fmt::fmt ALIAS fmt::fmt-header-only)

# Provide variables expected by consumers
set(fmt_INCLUDE_DIRS "${_IMPORT_PREFIX}/include")
set(fmt_LIBRARIES fmt::fmt)

# Mark as found
set(fmt_VERSION_MAJOR 10)
set(fmt_VERSION_MINOR 2)
set(fmt_VERSION_PATCH 1)

# Don't require any libraries
set(fmt_LIBRARIES "")
set(fmt_STATIC_LIBRARIES "")
set(fmt_SHARED_LIBRARIES "")

message(STATUS "Found fmt: ${fmt_VERSION} (header-only override)")