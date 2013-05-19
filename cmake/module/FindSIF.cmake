# File: FindSIF.cmake
# Version: 0.0.1
#
# The following variables are filled out:
# - SIF_INCLUDE_DIR : 
# - SIF_LIBRARIES :   the list of all required modules
#
# Output
# ------
#
# example:
#   find_package(SIF REQUIRED)
#   include_directories(${SIF_INCLUDE_DIR})
#   add_executable(example ...)
#   target_link_libraries(examplep ${SIF_LIBRARIES})

# enabled components
set(SIF_LIBRARIES_TO_FIND sif)

#set the build directory
set(BUILD_DIR build)

# Path
set(SIF_SRC_PATHS
        ${SIF_ROOT}/include/
        $ENV{SIF_ROOT}
        /usr/local/
        /usr/
        /sw # Fink
        /opt/local/ # DarwinPorts
        /opt/csw/ # Blastwave
        /opt/
        [KEY_CURRENT_USER\\Software\\SIF]/local
        [HKEY_LOCAL_MACHINE\\Software\\SIF]/local
)

find_path(SIF_INCLUDE_DIR sif.hpp
          PATHS ${SIF_SRC_PATHS})

# find the requested modules
set(SIF_FOUND true) # will be set to false if one of the required modules is not found

set(FIND_SIF_LIB_PATHS
        ${SIF_ROOT}/${BUILD_DIR}
        $ENV{SIF_ROOT}
        /usr/local/
        /usr/
        /sw # Fink
        /opt/local/ # DarwinPorts
        /opt/csw/ # Blastwave
        /opt/
        [KEY_CURRENT_USER\\Software\\SIF]/local
        [HKEY_LOCAL_MACHINE\\Software\\SIF]/local
)

#Suffixes
set(SIF_LIB_PATHS_SUFFIXES
        ./
        lib 
        lib32 
        lib64
        )
        
foreach(FIND_SIF_COMPONENT ${SIF_LIBRARIES_TO_FIND})
    string(TOUPPER ${FIND_SIF_COMPONENT} FIND_SIF_COMPONENT_UPPER)
    # release library
    find_library(SIF_${FIND_SIF_COMPONENT_UPPER}_LIBRARY
                 NAMES ${FIND_SIF_COMPONENT}
                 PATH_SUFFIXES ${SIF_LIB_PATHS_SUFFIXES}
                 PATHS ${FIND_SIF_LIB_PATHS})
    if (SIF_${FIND_SIF_COMPONENT_UPPER}_LIBRARY)
        # library found
        set(SIF_${FIND_SIF_COMPONENT_UPPER}_FOUND true)
    else()
        # library not found
        set(SIF_FOUND false)
        set(SIF_${FIND_SIF_COMPONENT_UPPER}_FOUND false)
        set(FIND_SIF_MISSING "${FIND_SIF_MISSING} ${FIND_SIF_COMPONENT}")
    endif()
    set(SIF_LIBRARIES ${SIF_LIBRARIES} "${SIF_${FIND_SIF_COMPONENT_UPPER}_LIBRARY}")
endforeach()

# handle result
if(SIF_FOUND)
    message(STATUS "Found SIF includes :")
    message(${SIF_INCLUDE_DIR})
else()
    # include directory or library not found
    message(FATAL_ERROR "Could NOT find SIF (missing : ${FIND_SIF_MISSING})")
endif()
