# CMakeList.txt: CMake-Projekt für "Integra". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)
project(Integra VERSION 1.0.0 DESCRIPTION "Integra is a numerical integration library.")
# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.


add_library(${PROJECT_NAME} SHARED src/Integra.cpp)

include(GNUInstallDirs)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

set_target_properties(Integra PROPERTIES VERSION ${PROJECT_VERSION})

install(TARGETS ${PROJECT_NAME} EXPORT IntegraConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


install(EXPORT IntegraConfig DESTINATION share/cmake)

export(TARGETS ${PROJECT_NAME} FILE IntegraConfig.cmake)

add_subdirectory(test)
add_subdirectory(src)
enable_testing()
add_test(NAME integra_test COMMAND Test)
# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
