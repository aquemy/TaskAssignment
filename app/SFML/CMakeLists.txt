# TMX Example : SFML

# Minimum requiered version of cmake
cmake_minimum_required(VERSION 2.8)

# Project definition
## Name
project("SIF Example : SFML")

## Language
enable_language(CXX)

## Versioning
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

find_package(SFML REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/module")
set(SIF_ROOT ${CMAKE_SOURCE_DIR})

find_package(SIF REQUIRED)
include_directories(${SIF_INCLUDE_DIR})


######################################################################################
### ) Define general CXX flags for DEBUG and RELEASE
######################################################################################

if(DEBUG)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "" FORCE)
else(DEBUG)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif(DEBUG)

set(CMAKE_CXX_FLAGS_DEBUG  "${CMAKE_CXX_FLAGS_DEBUG} -lsfml-graphics -lsfml-window -lsfml-system -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -lsfml-graphics -lsfml-window -lsfml-system -std=c++11")

######################################################################################
### 4) Define and add paths
######################################################################################

# Sources
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(SRC
    main.cpp
    src/environment.cpp
    src/resource.cpp
    src/taskspot.cpp
    )

# Include the header
include_directories(${SRC_DIR})

# Create example
add_executable(sifExample ${SRC})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})

# Link tmxExample to TMX
target_link_libraries(sifExample ${SIF_LIBRARIES})

