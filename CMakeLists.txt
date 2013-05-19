# Spatial Intelligence Framework

######################################################################################
### 0) Check the CMake version
######################################################################################

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

######################################################################################
### 1) Define the project
######################################################################################

## Name
project("Spatial Intelligence Framework")

## Language
enable_language(CXX)

## Test the presence of a compiler
if("${CMAKE_CXX_COMPILER}" STREQUAL "" OR "${CMAKE_C_COMPILER}" STREQUAL "")
    message(FATAL_ERROR "No compiler found!")
endif()

## Versioning
set(VERSION_MAJOR 0 CACHE STRING "Major version number" )
set(VERSION_MINOR 0 CACHE STRING "Minor version number" )
set(VERSION_PATCH 1 CACHE STRING "Patch version number" )

SET(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}" CACHE INTERNAL "Package version" FORCE)
SET(VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}${PROJECT_VERSION_MISC}" CACHE INTERNAL "Global version" FORCE)
SET(GLOBAL_VERSION "${VERSION}")

######################################################################################
### 2) Check dependencies
######################################################################################
 
## Optional
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/module" CACHE INTERNAL "CMake module" FORCE)
include(FindDoxygen OPTIONAL)

######################################################################################
### 3) Include CMake files
######################################################################################

## Configuration file for building type and flags
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake)

## Macro file
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Macro.cmake)

## Custom Targets file
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Target.cmake)

######################################################################################
### 4) Define and add module paths
######################################################################################

## Paths
set(SIF_SRC_DIR "${CMAKE_SOURCE_DIR}/include/SIF" CACHE INTERNAL "SIF source directory" FORCE)
set(SIF_BIN_DIR "${CMAKE_BINARY_DIR}" CACHE INTERNAL "SIF binary directory" FORCE)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Files.cmake)

add_subdirectory(doc)
add_subdirectory(test)
add_subdirectory(lessons)
add_subdirectory(app)

######################################################################################
### 5) Packaging : only in release !
######################################################################################

if("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Package.cmake)
endif()
