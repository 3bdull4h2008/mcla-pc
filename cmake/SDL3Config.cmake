# SDL3 config - links against vendored SDL3.lib

set(SDL3_FOUND TRUE)
set(SDL3_VERSION "3.2.6")
set(SDL3_VERSION_STRING "3.2.6")

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../" ABSOLUTE)

# Headers target (vendored in third_party)
if(NOT TARGET SDL3::Headers)
  add_library(SDL3::Headers INTERFACE IMPORTED)
  set_target_properties(SDL3::Headers PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${PACKAGE_PREFIX_DIR}/third_party/SDL3/include"
  )
endif()

# Main SDL3 target linking against vendored SDL3.lib
if(NOT TARGET SDL3::SDL3)
  add_library(SDL3::SDL3 UNKNOWN IMPORTED)
  set_target_properties(SDL3::SDL3 PROPERTIES
    IMPORTED_LOCATION "${PACKAGE_PREFIX_DIR}/third_party/SDL3/lib/SDL3.lib"
    INTERFACE_INCLUDE_DIRECTORIES "${PACKAGE_PREFIX_DIR}/third_party/SDL3/include"
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