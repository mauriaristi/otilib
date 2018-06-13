# OTI numbers in C -> CMakeLists.txt file
#
# Created by:
# Mauricio Aristizabal Cano
# Date: June 12 2018
# #






# -------------------------------------------------------------------
# --------------------------- BUILD OTI -----------------------------
# -------------------------------------------------------------------



# set (CMAKE_C_COMPILER "/usr/bin/clang")
# set(CMAKE_MACOSX_RPATH 1)

# # The version number.
# set (OTI_LIBRARY_VERSION_MAJOR 1)
# set (OTI_LIBRARY_VERSION_MINOR 0)

# set(CMAKE_BUILD_TYPE RELEASE)
# set(CMAKE_C_FLAGS_DEBUG "-O2 -g")
# set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall")


SET(GCC_COVERAGE_COMPILE_FLAGS "-arch i386 -arch x86_64 -g -fwrapv -O3 -Wall -Wstrict-prototypes")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

SET(CMAKE_OSX_DEPLOYMENT_TARGET 10.6)


include_directories ("${PROJECT_SOURCE_DIR}/include")
add_library (oti        c/core.c 
	                    c/darray.c 
	                    c/otinum_dense.c
	                    c/otinum_spr.c
	                    c/otinum_spr_array.c)
SET_TARGET_PROPERTIES(oti PROPERTIES LINK_FLAGS "-arch i386 -arch x86_64")


# -------------------------------------------------------------------
# --------------------------- BUILD OTI -----------------------------
# -------------------------------------------------------------------



# -------------------------------------------------------------------
# ------------------------- BUILD OTIFEM ----------------------------
# -------------------------------------------------------------------

# set (CMAKE_C_COMPILER "/usr/bin/clang")
# set(CMAKE_MACOSX_RPATH 1)

# # The version number.
# set (OTIFEM_LIBRARY_VERSION_MAJOR 1)
# set (OTIFEM_LIBRARY_VERSION_MINOR 0)

# set(CMAKE_BUILD_TYPE RELEASE)
# set(CMAKE_C_FLAGS_DEBUG "-O2 -g")
# set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall")


# SET(GCC_COVERAGE_COMPILE_FLAGS "-arch i386 -arch x86_64 -g -fwrapv -O3 -Wall -Wstrict-prototypes")
# add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

# SET(CMAKE_OSX_DEPLOYMENT_TARGET 10.6)

include_directories ("${PROJECT_SOURCE_DIR}/include")
add_library (otifem        c/otifem.c 
	                       c/otifem_array.c)
SET_TARGET_PROPERTIES(otifem PROPERTIES LINK_FLAGS "-arch i386 -arch x86_64")




target_link_libraries (otifem oti)




# -------------------------------------------------------------------
# ------------------------- BUILD OTIFEM ----------------------------
# -------------------------------------------------------------------









# -------------------------------------------------------------------
# --------------------- BUILD OTILIB - PYTHON -----------------------
# -------------------------------------------------------------------

# 1. Copy python files to the lib directory.


# Change to generate the proper file in compile time.

FILE(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/tmp_src)

# Copy the pure python files of the library to the library folder.
FILE(COPY  python/whereotilib.py  python/auxFunctions.py
	DESTINATION "${PROJECT_BINARY_DIR}/lib/" )


configure_file (
  "${PROJECT_SOURCE_DIR}/src/cython/setup.py.in"
  "${PROJECT_BINARY_DIR}/tmp_src/setup.py"
  )
# include_directories( ${PROJECT_SOURCE_DIR}/include )

# cython_add_module( otilib cython/otilib.pyx)

ADD_CUSTOM_TARGET(otipython ALL
	DEPENDS oti otifem)

# # 2. Execute Cython setup call 
ADD_CUSTOM_COMMAND (
	TARGET     otipython
	# POST_BUILD
	# COMMAND    CFLAGS="-I${PROJECT_SOURCE_DIR}/include" 
	#            LDFLAGS="-L${PROJECT_BINARY_DIR}/lib"   
	COMMAND python3 ${PROJECT_BINARY_DIR}/tmp_src/setup.py build_ext -b${PROJECT_BINARY_DIR}/lib
)
# # CFLAGS="-I../../include" LDFLAGS="-L../../build/lib" python3 setup.py build_ext -b../../build/lib





# -------------------------------------------------------------------
# --------------------- BUILD OTILIB - PYTHON -----------------------
# -------------------------------------------------------------------
