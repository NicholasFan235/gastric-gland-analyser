

cmake_minimum_required(VERSION 3.15)
message(STATUS "Using CMake version ${CMAKE_VERSION}")

project(cEpiabm LANGUAGES CXX VERSION 0.0.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Link this 'library' to set the C++ standard / compile-time options requested
include(cmake/ProjectSettings.cmake)
add_library(project_settings INTERFACE)
target_compile_features(project_settings INTERFACE cxx_std_17)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# Sanitiser options if supported by compiler
include(cmake/Sanitisers.cmake)
enable_sanitisers(project_settings)

# allow for static analysis options
include(cmake/StaticAnalysers.cmake)

add_subdirectory(src)

option(ENABLE_APPS "Whether to build apps" ON)
if (ENABLE_APPS)
    add_subdirectory(apps)
endif()

add_library(gastric_gland_analyser::gga_module ALIAS gga_lib)
add_library(gastric_gland_analyser::project_warnings ALIAS project_warnings)
add_library(gastric_gland_analyser::project_settings ALIAS project_settings)
include(GNUInstallDirs)
install(TARGETS gga_lib project_warnings project_settings EXPORT gastric_gland_analyser)

install(EXPORT gastric_gland_analyser
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/gastric_gland_analyser
        NAMESPACE gastric_gland_analyser::
        FILE gastric_gland_analyser-runtime.cmake
        COMPONENT gastric_gland_analyser-runtime
)

install(FILES cmake/gastric_gland_analyser-config.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/gastric_gland_analyser
)