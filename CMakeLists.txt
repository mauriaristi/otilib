# OTI numbers in C -> CMakeLists.txt file
#
# Created by:
# Mauricio Aristizabal Cano
# Date: June 12 2018
#
# This file sets up CMake to run the appropriate commands to 
# compile the OTI number library project

cmake_minimum_required (VERSION 2.8)





project (oti)




# Make the scripts available in the 'cmake' directory.
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake )

# Include the CMake script copyfiles.cmake. 
include( copyfiles )








set (CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_MACOSX_RPATH 1)

# The version number.
set (OTI_LIBRARY_VERSION_MAJOR 1)
set (OTI_LIBRARY_VERSION_MINOR 0)

set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall")
 

# should we do the Cython part too?
option (GENERATE_CYTHON 
        "Also generate the Cython implementation" ON) 

# add the CYTHON part?
#
# if (GENERATE_CYTHON)
  # include_directories ("${PROJECT_BINARY_DIR}/include")
  # add_subdirectory (MathFunctions "${PROJECT_BINARY_DIR}/lib")
  # set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
  
# endif (GENERATE_CYTHON)


# should we do the Cython part too?
option (GENERATE_FORTRAN
        "Generate the Fortran library wrapper" OFF) 





add_subdirectory (src "${PROJECT_BINARY_DIR}/lib")


