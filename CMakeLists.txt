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

# 3.22: FindLAPACK honours BLA_SIZEOF_INTEGER (see the LAPACK section below).
cmake_minimum_required (VERSION 3.22)

# -------------------------------------------------------------------------------------------------
# Single source of truth for the library version.
#
# The root VERSION file is the ONLY place where the version number is written by hand. Every other
# artifact (C header, Fortran module, Python module, setup.py, conda recipe) is generated from it or
# reads it, so a release bump is a one-line edit (see tools/bump_version.py).
# -------------------------------------------------------------------------------------------------
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" OTI_VERSION_RAW)
string(STRIP "${OTI_VERSION_RAW}" OTI_VERSION)

if(NOT OTI_VERSION MATCHES "^([0-9]+)\\.([0-9]+)\\.([0-9]+)$")
  message(FATAL_ERROR
    "The VERSION file must contain a MAJOR.MINOR.PATCH version; got '${OTI_VERSION}'.")
endif()

set(OTI_VERSION_MAJOR ${CMAKE_MATCH_1})
set(OTI_VERSION_MINOR ${CMAKE_MATCH_2})
set(OTI_VERSION_PATCH ${CMAKE_MATCH_3})

# Name of the global project.
project(oti
  VERSION ${OTI_VERSION}
  LANGUAGES Fortran C)

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
    message( STATUS " -- OpenMP Link Flags: ${OpenMP_INCLUDE_FLAGS}" )
    message( STATUS " -- OpenMP Link Flags: ${OpenMP_LINK_FLAGS}" )
    set(OpenMP_EXTRA_INCLUDE_FLAGS "-I/opt/homebrew/opt/libomp/include/")
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

# -------------------------------------------------------------------------------------------------
# LAPACK / BLAS.
#
# Required by the dense linear algebra of the C core (LU factorization, solve, inverse, determinant).
# The C code only calls the Fortran wrappers in src/fortran/core/oti_lapack.f90 (library otilapack),
# which link to the target LAPACK::LAPACK found here.
#
# OTI_BLA_VENDOR selects the implementation (CMake's BLA_VENDOR values, e.g. Apple, OpenBLAS,
# Generic, Intel10_64lp). Empty means CMake's default search order. The conda recipe uses Generic
# so that conda-forge's switchable libblas / liblapack stubs are linked.
#
# BLA_SIZEOF_INTEGER = 4: the wrappers use 32-bit integers (LP64 LAPACK).
# -------------------------------------------------------------------------------------------------
set(OTI_BLA_VENDOR "" CACHE STRING "LAPACK vendor passed to FindLAPACK as BLA_VENDOR (empty: auto)")

if (OTI_BLA_VENDOR)
  set(BLA_VENDOR ${OTI_BLA_VENDOR})
endif ()

set(BLA_SIZEOF_INTEGER 4)

find_package(LAPACK REQUIRED)

message(STATUS "LAPACK libraries: ${LAPACK_LIBRARIES}")

# Link arguments for the Cython extensions (setup.py.in), which are not CMake targets.
#   - The order of LAPACK_LIBRARIES is kept as found: static archives may be repeated on purpose
#     to resolve cycles, so the list is never deduplicated.
#   - Frameworks become "-Wl,-framework,<name>", plus "-F<dir>" outside Apple's default locations.
#   - Non-system library directories (absolute paths and -L entries) get an rpath, appended at
#     the end, so the extension finds shared LAPACK libraries at import time.
#   - A static LAPACK (.a) needs the Fortran runtime after it; CMake's implicit Fortran link
#     directories and libraries are appended in that case (GNU ld resolves left to right).
set(OTI_LAPACK_LINK_ARGS "")
set(OTI_LAPACK_RPATH_DIRS "")
set(OTI_LAPACK_IS_STATIC FALSE)

foreach (oti_lapack_item ${LAPACK_LINKER_FLAGS} ${LAPACK_LIBRARIES})

  set(oti_lapack_dir "")

  if (oti_lapack_item MATCHES "^(.*)/([^/]+)\\.framework$")
    list(APPEND OTI_LAPACK_LINK_ARGS "-Wl,-framework,${CMAKE_MATCH_2}")
    set(oti_lapack_dir "${CMAKE_MATCH_1}")

    if (NOT oti_lapack_dir MATCHES "^/System(/|$)|\\.sdk(/|$)")
      list(APPEND OTI_LAPACK_LINK_ARGS "-F${oti_lapack_dir}")
    endif ()

  else ()
    list(APPEND OTI_LAPACK_LINK_ARGS "${oti_lapack_item}")

    if (oti_lapack_item MATCHES "^-L(.+)$")
      set(oti_lapack_dir "${CMAKE_MATCH_1}")
    elseif (IS_ABSOLUTE "${oti_lapack_item}" AND NOT oti_lapack_item MATCHES "\\.tbd$")
      get_filename_component(oti_lapack_dir "${oti_lapack_item}" DIRECTORY)
    endif ()

    if (oti_lapack_item MATCHES "\\.a$")
      set(OTI_LAPACK_IS_STATIC TRUE)
    endif ()
  endif ()

  if (oti_lapack_dir)
    list(APPEND OTI_LAPACK_RPATH_DIRS "${oti_lapack_dir}")
  endif ()

endforeach ()

if (OTI_LAPACK_IS_STATIC)

  foreach (oti_lapack_dir ${CMAKE_Fortran_IMPLICIT_LINK_DIRECTORIES})
    list(APPEND OTI_LAPACK_LINK_ARGS "-L${oti_lapack_dir}")
    list(APPEND OTI_LAPACK_RPATH_DIRS "${oti_lapack_dir}")
  endforeach ()

  foreach (oti_lapack_lib ${CMAKE_Fortran_IMPLICIT_LINK_LIBRARIES})
    list(APPEND OTI_LAPACK_LINK_ARGS "-l${oti_lapack_lib}")
  endforeach ()

endif ()

list(REMOVE_DUPLICATES OTI_LAPACK_RPATH_DIRS)

foreach (oti_lapack_dir ${OTI_LAPACK_RPATH_DIRS})

  # No rpath for system directories or SDK stubs, which the loader already resolves. Whole path
  # components are matched, so /usr/lib64 or /usr/library-custom are not treated as /usr/lib.
  if (NOT oti_lapack_dir MATCHES "^(/usr/lib|/lib|/System)(/|$)|\\.sdk(/|$)")
    list(APPEND OTI_LAPACK_LINK_ARGS "-Wl,-rpath,${oti_lapack_dir}")
  endif ()

endforeach ()

# Python list literal for setup.py.in. Backslashes and single quotes are escaped so that any path
# stays a valid Python string literal.
set(OTI_LAPACK_LINK_ARGS_PY "")

foreach (oti_lapack_item ${OTI_LAPACK_LINK_ARGS})
  string(REPLACE "\\" "\\\\" oti_lapack_item "${oti_lapack_item}")
  string(REPLACE "'" "\\'" oti_lapack_item "${oti_lapack_item}")
  list(APPEND OTI_LAPACK_LINK_ARGS_PY "'${oti_lapack_item}'")
endforeach ()

list(JOIN OTI_LAPACK_LINK_ARGS_PY ", " OTI_LAPACK_LINK_ARGS_PY)
set(OTI_LAPACK_LINK_ARGS_PY "[${OTI_LAPACK_LINK_ARGS_PY}]")

message(STATUS "LAPACK link arguments for Cython: ${OTI_LAPACK_LINK_ARGS_PY}")

include( copyfiles )
 
set(CMAKE_MACOSX_RPATH 1)

# -------------------------------------------------------------------------------------------------
# Version artifacts generated from the root VERSION file.
#
# All of these are written into the build tree (never into the source tree) so that the repository
# never holds a second, stale copy of the version number:
#
#   ${PROJECT_BINARY_DIR}/include/oti/version.h  -> C / C++ / Cython
#   ${PROJECT_BINARY_DIR}/generated/oti_version.f90 -> Fortran
#   ${PROJECT_BINARY_DIR}/pyoti/_version.py      -> Python (pyoti.__version__)
# -------------------------------------------------------------------------------------------------
set(OTI_GENERATED_INCLUDE_DIR "${PROJECT_BINARY_DIR}/include")
set(OTI_GENERATED_SOURCE_DIR  "${PROJECT_BINARY_DIR}/generated")

file(MAKE_DIRECTORY "${OTI_GENERATED_INCLUDE_DIR}/oti")
file(MAKE_DIRECTORY "${OTI_GENERATED_SOURCE_DIR}")
file(MAKE_DIRECTORY "${PROJECT_BINARY_DIR}/pyoti")

configure_file(
  "${PROJECT_SOURCE_DIR}/include/oti/version.h.in"
  "${OTI_GENERATED_INCLUDE_DIR}/oti/version.h"
  @ONLY)

configure_file(
  "${PROJECT_SOURCE_DIR}/src/fortran/core/oti_version.f90.in"
  "${OTI_GENERATED_SOURCE_DIR}/oti_version.f90"
  @ONLY)

configure_file(
  "${PROJECT_SOURCE_DIR}/src/python/pyoti/python/_version.py.in"
  "${PROJECT_BINARY_DIR}/pyoti/_version.py"
  @ONLY)

# The generated header must be visible everywhere "oti/version.h" is included.
include_directories("${OTI_GENERATED_INCLUDE_DIR}")

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

# Tests configuration
option (BUILD_TESTING "Build the test suite" ON)

if (BUILD_TESTING)
  enable_testing()
  add_subdirectory (tests "${PROJECT_BINARY_DIR}/tests")
endif (BUILD_TESTING)

# should we do the Fortran part too?
option (GENERATE_FORTRAN
        "Generate the Fortran library wrapper" OFF) 

# add_subdirectory (src/fortran/ "${PROJECT_BINARY_DIR}/lib/fortran/")
add_subdirectory (src "${PROJECT_BINARY_DIR}/lib")

add_subdirectory (examples "${PROJECT_BINARY_DIR}/examples")
