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




SET(CYTHON_BUILD_DIR     "${PROJECT_BINARY_DIR}/pyoti"        )
SET(CYTHON_SOUCE_DIR     "${PROJECT_SOURCE_DIR}/pyoti/cython" )
SET(CYTHON_INCLUDE_DIR   "${PROJECT_SOURCE_DIR}/include"      )
SET(CYTHON_SETUP_DIR     "${PROJECT_BINARY_DIR}/tmp_src"      )
SET(CYTHON_LINK_DIR      "${PROJECT_BINARY_DIR}/lib"          )

SET(CYTHON_SOURCES_NAMES dense.pyx core.pyx)

SET(CYTHONIZE_BUILD_DIR   "${PROJECT_BINARY_DIR}/tmp_src"   )
SET(CYTHONIZE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include"   )

if(APPLE)
	# Apple requires the arquitecture to be defined.
	SET(DUTILS_ECARG1 "-arch i386"  )
	SET(DUTILS_ECARG2 "-arch x86_64")
else(APPLE)
	# these are dummy arguments for distutils, because linux does
	# not require setting this
	SET(DUTILS_ECARG1 "-I.")
	SET(DUTILS_ECARG2 "-I.")
endif(APPLE)

configure_file (
  "${PROJECT_SOURCE_DIR}/pyoti/cython/setup.py.in"
  "${PROJECT_BINARY_DIR}/tmp_src/setup.py"
  )



ADD_CUSTOM_TARGET(oticython ALL
	DEPENDS oti)

# # 2. Execute Cython setup call 
ADD_CUSTOM_COMMAND (
	TARGET  oticython
	COMMAND python3 ${CYTHON_SETUP_DIR}/setup.py build_ext -b${PROJECT_BINARY_DIR} 
)

ADD_CUSTOM_COMMAND (
	TARGET  oticython
	# COMMAND pwd
	COMMAND cp ${PROJECT_SOURCE_DIR}/pyoti/python/__init__.py     ${CYTHON_BUILD_DIR}/
	COMMAND cp ${PROJECT_SOURCE_DIR}/pyoti/python/whereotilib.py  ${CYTHON_BUILD_DIR}/
	COMMAND cp ${PROJECT_SOURCE_DIR}/pyoti/python/auxFunctions.py ${CYTHON_BUILD_DIR}/
)




# set_directory_properties( PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "whereotilib.py;auxFunctions.py"  )


# set_property(DIRECTORY "${PROJECT_BINARY_DIR}/tmp_src"
# 	APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "setup.py")
# set_property(DIRECTORY "${PROJECT_BINARY_DIR}/lib/oti"
# 	APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "*.so")

# -------------------------------------------------------------------
# --------------------- BUILD OTILIB - PYTHON -----------------------
# -------------------------------------------------------------------
