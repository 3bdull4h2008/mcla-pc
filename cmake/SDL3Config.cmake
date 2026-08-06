# Minimal SDL3 config - provides header-only target to avoid missing DLL issue
# This is found first due to CMAKE_PREFIX_PATH ordering

set(SDL3_FOUND TRUE)
set(SDL3_VERSION "3.2.0")
set(SDL3_VERSION_STRING "3.2.0")

# Headers target (provided by SDK)
if(NOT TARGET SDL3::Headers)
  add_library(SDL3::Headers INTERFACE IMPORTED)
  set_target_properties(SDL3::Headers PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  )
endif()

# Provide a header-only SDL3::SDL3 target that doesn't need DLL
if(NOT TARGET SDL3::SDL3)
  add_library(SDL3::SDL3 INTERFACE IMPORTED)
  set_target_properties(SDL3::SDL3 PROPERTIES
    INTERFACE_LINK_LIBRARIES "SDL3::Headers"
    INTERFACE_COMPILE_DEFINITIONS "SDL_STATIC=1"
  )
endif()

# Also provide static alias
if(NOT TARGET SDL3::SDL3-static)
  add_library(SDL3::SDL3-static ALIAS SDL3::SDL3)
endif()

# Test target
if(NOT TARGET SDL3::SDL3_test)
  add_library(SDL3::SDL3_test INTERFACE IMPORTED)
  set_target_properties(SDL3::SDL3_test PROPERTIES
    INTERFACE_LINK_LIBRARIES "SDL3::SDL3"
  )
endif()

# Variables
set(SDL3_LIBRARIES SDL3::SDL3)
set(SDL3_STATIC_LIBRARIES SDL3::SDL3-static)
set(SDL3_STATIC_PRIVATE_LIBS "")

message(STATUS "Using minimal header-only SDL3 config")