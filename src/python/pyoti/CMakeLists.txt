# OTI numbers in C -> CMakeLists.txt file
#
# Created by:
# Mauricio Aristizabal Cano
# Date: June 14 2018
#


# -------------------------------------------------------------------
# --------------------- BUILD OTILIB - PYTHON -----------------------
# -------------------------------------------------------------------

# 1. Copy python files to the lib directory.
# Change to generate the proper file in compile time.

FILE(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/tmp_src)

# Copy the pure python files of the library to the library folder.
FILE(COPY  python/whereotilib.py  python/auxFunctions.py
	DESTINATION "${PROJECT_BINARY_DIR}/pyoti/" )

FILE(COPY  python/__init__.py
	DESTINATION "${PROJECT_BINARY_DIR}/pyoti" )


SET(CYTHON_BUILD_DIR     "${PROJECT_BINARY_DIR}/pyoti"                   )
SET(CYTHON_SOUCE_DIR     "${PROJECT_SOURCE_DIR}/src/python/pyoti/cython" )
SET(CYTHON_INCLUDE_DIR   "${PROJECT_SOURCE_DIR}/include"                 )
SET(CYTHON_SETUP_DIR     "${PROJECT_BINARY_DIR}/tmp_src"                 )
SET(CYTHON_LINK_DIR      "${PROJECT_BINARY_DIR}/lib"                     )


SET(CYTHON_COMPILE_INTEL_FLAG "False")
SET(CYTHON_COMPILE_GNU_FLAG "False")

# Use the default compiler as the precall for the cython command line.
SET(CYTHON_CMD_CALL_PREC "CC=${CMAKE_C_COMPILER}")

# Compiler dependent flags:
if (CMAKE_C_COMPILER_ID STREQUAL "Intel")
  # using Intel icc.
  SET(CYTHON_COMPILE_INTEL_FLAG  "True") 	
endif()

if (CMAKE_C_COMPILER_ID STREQUAL "IntelLLVM")
  # using Intel icx.
	SET(CYTHON_COMPILE_INTEL_FLAG  "True") 	
endif()

if (CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
  
  # Avoidin using Clang (compilation issues)
  SET(CYTHON_COMPILE_GNU_FLAG  "False")

  # Reset the cython pre-compilation flag
  # to use "gcc wrapper".
  set(CYTHON_CMD_CALL_PREC "DISTUTILS_DEBUG=1")

endif()

# if (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
#   # using Visual Studio C++
# endif()

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
  # using GCC
  SET(CYTHON_COMPILE_GNU_FLAG  "True") 	
endif()



# TODO: Add option to selectively compile static libraries.
SET(CYTHON_COMPILE_STATIC_FLAG "True")



SET(CYTHON_SOURCES_NAMES dense.pyx core.pyx)

SET(CYTHONIZE_BUILD_DIR   "${PROJECT_BINARY_DIR}/tmp_src"                )
SET(CYTHONIZE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include"                )

if(APPLE)
	# Apple requires the arquitecture to be defined.
	# SET(DUTILS_ECARG1 "-arch i386"  )
	# SET(DUTILS_ECARG2 "-arch x86_64")

	SET(DUTILS_ECARG1 "-I.")
	SET(DUTILS_ECARG2 "-I.")

else()
	# these are dummy arguments for distutils, because linux does
	# not require setting this
	SET(DUTILS_ECARG1 "-I.")
	SET(DUTILS_ECARG2 "-I.")

endif()

configure_file (
  "${PROJECT_SOURCE_DIR}/src/python/pyoti/cython/setup.py.in"
  "${PROJECT_BINARY_DIR}/tmp_src/setup.py"
  )


# message( STATUS "Using the f")

message(STATUS ">>> CYTHON_CMD_CALL_PREC: ${CYTHON_CMD_CALL_PREC}")



# CMAKE
ADD_CUSTOM_TARGET(oticython ALL
	DEPENDS oti otiarrinter)

# # 2. Execute Cython setup call 
ADD_CUSTOM_COMMAND (
	TARGET  oticython
	# COMMAND python3 ${CYTHON_SETUP_DIR}/setup.py build_ext -b${PROJECT_BINARY_DIR} 
	# COMMAND CC=icc python3 ${CYTHON_SETUP_DIR}/setup.py build_ext -b${PROJECT_BINARY_DIR} 
	COMMAND ${CYTHON_CMD_CALL_PREC} python3 ${CYTHON_SETUP_DIR}/setup.py -q build_ext -b${PROJECT_BINARY_DIR} -j 8 -v
)
# TODO: This may not work in Windows.... Check this, maybe change to FILE(COPY ...)
#  ---- 
ADD_CUSTOM_COMMAND (
	TARGET  oticython
	# COMMAND pwd
	COMMAND cp ${PROJECT_SOURCE_DIR}/src/python/pyoti/python/__init__.py      ${CYTHON_BUILD_DIR}/
	COMMAND cp ${PROJECT_SOURCE_DIR}/src/python/pyoti/python/whereotilib.py   ${CYTHON_BUILD_DIR}/
	COMMAND cp ${PROJECT_SOURCE_DIR}/src/python/pyoti/python/auxFunctions.py  ${CYTHON_BUILD_DIR}/
	COMMAND cp ${PROJECT_SOURCE_DIR}/src/python/pyoti/python/fmod_writer.py   ${CYTHON_BUILD_DIR}/
	COMMAND cp ${PROJECT_SOURCE_DIR}/src/python/pyoti/python/cmod_writer.py   ${CYTHON_BUILD_DIR}/
	COMMAND cp -R ${PROJECT_SOURCE_DIR}/src/python/pyoti/python/source_conv   ${CYTHON_BUILD_DIR}/
	COMMAND cp ${PROJECT_SOURCE_DIR}/src/python/pyoti/python/base_derivs_fortran.f90   ${CYTHON_BUILD_DIR}/
	COMMAND cp ${PROJECT_SOURCE_DIR}/src/python/pyoti/python/core_functions.f90   ${CYTHON_BUILD_DIR}/
)

# -------------------------------------------------------------------
# --------------------- BUILD OTILIB - PYTHON -----------------------
# -------------------------------------------------------------------

