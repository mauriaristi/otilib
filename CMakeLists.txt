# OTI numbers in C -> CMakeLists.txt file
#
# Created by:
# Mauricio Aristizabal Cano
#
# Date created: June 12 2018
# Last modified: September 26 2018
#
# This file sets up CMake to run the appropriate commands to 
# compile the OTI number library project

cmake_minimum_required (VERSION 3.9)

# Name of the global project.
project(oti)

# Make the scripts available in the 'cmake' directory.
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake )

# Include the CMake script copyfiles.cmake. 
include( copyfiles )

option (USE_OPENMP "Use OpenMP to enamble <omp.h>" ON)
set(OpenMP_EXTRA_INLCUDE_FLAGS "")
set(OpenMP_EXTRA_LINK_FLAGS "")
# Uncomment this for macOS
if(APPLE)
	# This is for the case of apple macOS
	set(CMAKE_C_COMPILER "/usr/bin/clang")
  set(CYTHON_CMD_CALL_PREC "CC=gcc")


  # Openmp.
  if(USE_OPENMP)
    set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp")
    set(OpenMP_C_LIB_NAMES "omp")
    set(OpenMP_omp_LIBRARY omp)
    set(OpenMP_EXTRA_INLCUDE_FLAGS "-I/opt/homebrew/Cellar/libomp/13.0.1/include/")
    set(OpenMP_EXTRA_LINK_FLAGS "-L/opt/homebrew/Cellar/libomp/13.0.1/lib/")
  else(USE_OPENMP)
    set(OpenMP_C_FLAGS "")
  endif(USE_OPENMP)


elseif(UNIX)

  # This is for the case of unix OS
  set(CMAKE_C_COMPILER "gcc")
  set(CYTHON_CMD_CALL_PREC "CC=gcc")
  # set(CMAKE_C_COMPILER "icc")
  # set(CMAKE_C_COMPILER "gcc")
  # set(CYTHON_CMD_CALL_PREC "CC=icc")

endif(APPLE)



# -------------------------------------------------------------------------------------------------
# This allows to track if OpenMP exsists in the system and if it can be used to compile with the
#  compiler selected;.


if (USE_OPENMP)

  find_package(OpenMP)
  set(CYTHON_OPENMP_COMPILE_FLAG "True")

  if (OpenMP_C_FOUND)
  
    set(LINK_TARGET_OMP OpenMP::OpenMP_C)

  else(OpenMP_C_FOUND)

    set(LINK_TARGET_OMP "")

  endif(OpenMP_C_FOUND)

else(USE_OPENMP)

  set(CYTHON_OPENMP_COMPILE_FLAG "False")

endif(USE_OPENMP)
# -------------------------------------------------------------------------------------------------

 message(WARNING ${LINK_TARGET_OMP})
 
set(CMAKE_MACOSX_RPATH 1)

# The version number.
set (OTI_LIBRARY_VERSION_MAJOR 1)
set (OTI_LIBRARY_VERSION_MINOR 0)

set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall -std=c99")
 

# should we do the Cython part too?
option (GENERATE_CYTHON_OTI 
        "Generate the Cython implementation of OTI numbers" YES)
# "Also generate the Cython implementation" OFF) 

# add the CYTHON part?
if (GENERATE_CYTHON_OTI)
  add_subdirectory (src/python/pyoti "${PROJECT_BINARY_DIR}/pyoti")
endif (GENERATE_CYTHON_OTI)

# option (GENERATE_CYTHON_OTIFEM 
#         "Generate the Cython implementation of OTIFEM" OFF)
# if (GENERATE_CYTHON_OTIFEM)
#   add_subdirectory (pyotifem)  
# endif (GENERATE_CYTHON_OTIFEM)

# should we do the Cython part too?
option (GENERATE_C_TESTS
        "Generate C tests files" OFF) 

if (GENERATE_C_TESTS)
  add_subdirectory (tests/c)
endif (GENERATE_C_TESTS)


# should we do the Fortran part too?
option (GENERATE_FORTRAN
        "Generate the Fortran library wrapper" OFF) 

add_subdirectory (src "${PROJECT_BINARY_DIR}/lib")
