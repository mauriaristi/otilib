# OTI numbers in C -> CMakeLists.txt file
#
# Created by:
# Mauricio Aristizabal Cano
#
# Date created: June 12 2018
# Last modified: June 18 2024
#
# This file sets up CMake to run the appropriate commands to 
# compile the OTI number library project

# cmake_minimum_required (VERSION 3.20)
cmake_minimum_required (VERSION 3.20)

# Set specific OS deployment target.
# SET(CMAKE_OSX_DEPLOYMENT_TARGET 12.1)
SET(CMAKE_OSX_DEPLOYMENT_TARGET 11.0)

# Include the CMake script copyfiles.cmake. 
include(CheckLanguage)


check_language(Fortran)

if(CMAKE_Fortran_COMPILER)
  enable_language(Fortran)
else()
  message(STATUS "No Fortran support")
endif()

# Enable fortran compilation.
enable_language(Fortran)


# Name of the global project.
project(oti 
  VERSION 0.1
  LANGUAGES Fortran C) 

message(STATUS "SETTING UP COMPILATION FOR OTIlib ${PROJECT_VERSION}")

message(STATUS "Compiler IDs")
message(STATUS "      C: ${CMAKE_C_COMPILER_ID}")
message(STATUS "    CXX: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Fortran: ${CMAKE_Fortran_COMPILER_ID}")

# Make the scripts available in the 'cmake' directory.
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake )


# Detect compiler
if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
  # using Clang
elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
  # using GCC
elseif (CMAKE_C_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
endif()







option (USE_OPENMP "Use OpenMP to enamble <omp.h>" YES)
message( "USE_OPENMP flag is set to: ${USE_OPENMP}" )

# set(OpenMP_EXTRA_INLCUDE_FLAGS "")
# set(OpenMP_EXTRA_LINK_FLAGS "")
# Uncomment this for macOS
if(APPLE)
	# This is for the case of apple macOS
	
  #set(CMAKE_C_COMPILER "/usr/bin/clang")
  #set(CYTHON_CMD_CALL_PREC "CC=gcc")


  # Openmp.
  if(USE_OPENMP)
    # set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp")
    # set(OpenMP_C_LIB_NAMES "omp")
    # set(OpenMP_omp_LIBRARY omp)
    message( STATUS " -- OpenMP Link Flags: ${OpenMP_INLCUDE_FLAGS}" )
    message( STATUS " -- OpenMP Link Flags: ${OpenMP_LINK_FLAGS}" )
    set(OpenMP_EXTRA_INLCUDE_FLAGS "-I/opt/homebrew/opt/libomp/include/")
    set(OpenMP_EXTRA_LINK_FLAGS "-L/opt/homebrew/opt/libomp/lib/")
  else(USE_OPENMP)
    set(OpenMP_C_FLAGS "")
  endif(USE_OPENMP)


elseif(UNIX)

  # This is for the case of unix OS
  # set(CMAKE_C_COMPILER "gcc")
  # set(CYTHON_CMD_CALL_PREC "CC=gcc")
  #set(CMAKE_C_COMPILER "icx")
  #set(CYTHON_CMD_CALL_PREC "CC=icx")

endif(APPLE)



# -------------------------------------------------------------------------------------------------
# This allows to track if OpenMP exsists in the system and if it can be used to compile with the
#  compiler selected;.


if (USE_OPENMP)

  message("OPENMP compilation - Enabled. Checking for OpenMP.")

  find_package(OpenMP)
  

  if (OpenMP_C_FOUND)
    message("OpenMP-C Found! Enabling for C compilation.")
    set(CYTHON_OPENMP_COMPILE_FLAG "True")
    set(LINK_TARGET_OMP_C OpenMP::OpenMP_C)
    

  else(OpenMP_C_FOUND)

    set(CYTHON_OPENMP_COMPILE_FLAG "False")
    set(LINK_TARGET_OMP_C "")
    
  endif(OpenMP_C_FOUND)

  if (OpenMP_Fortran_FOUND)
    message("OpenMP-Fortran Found! Enabling for Fortran compilation.")
    set(LINK_TARGET_OMP_Fortran OpenMP::OpenMP_Fortran)
  else()
    set(LINK_TARGET_OMP_Fortran "")
  endif()

else(USE_OPENMP)

  message("OPENMP compilation - Disabled")
  set(CYTHON_OPENMP_COMPILE_FLAG "False")

endif(USE_OPENMP)
# -------------------------------------------------------------------------------------------------

message(STATUS ${LINK_TARGET_OMP})

include( copyfiles )
 
set(CMAKE_MACOSX_RPATH 1)

# The version number.
set (OTI_LIBRARY_VERSION_MAJOR 0)
set (OTI_LIBRARY_VERSION_MINOR 1)

# set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_BUILD_TYPE DEBUG)
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
option (GENERATE_TESTS
        "Generate tests files" ON) 

if (GENERATE_TESTS)
  add_subdirectory (tests)
endif (GENERATE_TESTS)


# should we do the Fortran part too?
option (GENERATE_FORTRAN
        "Generate the Fortran library wrapper" OFF) 

# add_subdirectory (src/fortran/ "${PROJECT_BINARY_DIR}/lib/fortran/")
add_subdirectory (src "${PROJECT_BINARY_DIR}/lib")

add_subdirectory (examples "${PROJECT_BINARY_DIR}/examples")
