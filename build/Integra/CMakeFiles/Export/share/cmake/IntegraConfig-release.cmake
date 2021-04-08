#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Integra" for configuration "Release"
set_property(TARGET Integra APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Integra PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libIntegra.dll.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/libIntegra.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Integra )
list(APPEND _IMPORT_CHECK_FILES_FOR_Integra "${_IMPORT_PREFIX}/lib/libIntegra.dll.a" "${_IMPORT_PREFIX}/bin/libIntegra.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
