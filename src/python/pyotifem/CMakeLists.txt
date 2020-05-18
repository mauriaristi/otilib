# OTI numbers in C -> CMakeLists.txt file
#
# Created by:
# Mauricio Aristizabal Cano
# Date: June 14 2018
#




# -------------------------------------------------------------------
# --------------------- BUILD OTIFEM - PYTHON -----------------------
# -------------------------------------------------------------------

# 1. Copy python files to the lib directory.
# Change to generate the proper file in compile time.

# Copy the pure python files of the library to the library folder.
FILE(COPY  python/__init__.py
	DESTINATION "${PROJECT_BINARY_DIR}/pyotifem" )


SET(CYTHON_BUILD_DIR     "${PROJECT_BINARY_DIR}/pyotifem"        )
SET(CYTHON_SOUCE_DIR     "${PROJECT_SOURCE_DIR}/pyotifem/cython" )
SET(CYTHON_INCLUDE_DIR   "${PROJECT_SOURCE_DIR}/include"      )
SET(CYTHON_SETUP_DIR     "${PROJECT_BINARY_DIR}/tmp_src"      )
SET(CYTHON_LINK_DIR      "${PROJECT_BINARY_DIR}/lib"          )

SET(CYTHON_SOURCES_NAMES dense.pyx core.pyx)

SET(CYTHONIZE_BUILD_DIR   "${PROJECT_BINARY_DIR}/tmp_src"   )
SET(CYTHONIZE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include"   )

configure_file (
  "${PROJECT_SOURCE_DIR}/pyotifem/cython/setup.py.in"
  "${PROJECT_BINARY_DIR}/tmp_src/setup_pyotifem.py"
  )



ADD_CUSTOM_TARGET(pyotifem ALL
	DEPENDS oti otifem oticython)

# # 2. Execute Cython setup call 
ADD_CUSTOM_COMMAND (
	TARGET  pyotifem
	COMMAND python3 ${CYTHON_SETUP_DIR}/setup_pyotifem.py build_ext -b${PROJECT_BINARY_DIR} 
)

ADD_CUSTOM_COMMAND (
	TARGET  pyotifem
	# COMMAND pwd
	COMMAND cp ${PROJECT_SOURCE_DIR}/pyotifem/python/__init__.py     ${CYTHON_BUILD_DIR}/
)



# -------------------------------------------------------------------
# --------------------- BUILD OTILIB - PYTHON -----------------------
# -------------------------------------------------------------------
