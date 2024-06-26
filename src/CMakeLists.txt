# OTI numbers in C and Fortran -> CMakeLists.txt file
#
# Created by:
# Mauricio Aristizabal Cano
# Date: June 12 2018
# Last Modified: June 18 2024
#






# -------------------------------------------------------------------
# --------------------------- BUILD OTI -----------------------------
# -------------------------------------------------------------------

# add_subdirectory (fortran "${PROJECT_BINARY_DIR}/lib/fortran/")

# set (CMAKE_C_COMPILER "/usr/bin/clang")
# set(CMAKE_MACOSX_RPATH 1)


if(APPLE)
    # This is for the case of apple macOS
    # SET(GCC_COVERAGE_COMPILE_FLAGS "-arch i386 -arch x86_64 -g -fwrapv -O3 -Wall -Wstrict-prototypes")
    # SET(GCC_COVERAGE_COMPILE_FLAGS "-fPIC -g -fwrapv -O3 -Wall -Wstrict-prototypes -arch x86_64 ${OpenMP_EXTRA_INLCUDE_FLAGS}")
    SET(GCC_COVERAGE_COMPILE_FLAGS "-fPIC -fwrapv -O3 -Wall -Wstrict-prototypes ${OpenMP_EXTRA_INLCUDE_FLAGS}")
    SET(GCC_COVERAGE_LINK_FLAGS "${OpenMP_EXTRA_LINK_FLAGS} ")
  
elseif(UNIX)
    # This is for the case of Unix (Linux systems.)
    SET(GCC_COVERAGE_COMPILE_FLAGS "-fPIC -fwrapv -O3 -Wall -Wstrict-prototypes")
    SET(GCC_COVERAGE_LINK_FLAGS "")
    # SET(GCC_COVERAGE_COMPILE_FLAGS "-fPIC -fwrapv -Ofast -Wall -Wstrict-prototypes")
endif(APPLE)






add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")



include_directories (   "${PROJECT_SOURCE_DIR}/include"
                        "${PROJECT_SOURCE_DIR}/src/c"
                        )

# Add directories to link.
link_directories (    
    "${PROJECT_BINARY_DIR}/lib"
    )

# =========================================================================
#                Setup Fortran compilation
# =========================================================================

add_library (master_parameters STATIC 
    fortran/static/master_parameters.f90
)

add_library (real_utils STATIC 
    fortran/static/real_utils.f90
)

target_link_libraries(master_parameters 
    OpenMP::OpenMP_Fortran
)

target_link_libraries(real_utils master_parameters 
    OpenMP::OpenMP_Fortran
)


file(GLOB static_f90 
    fortran/static/oti*.f90
    fortran/static/real_utils.f90
    fortran/static/master_parameters.f90 
)
file(GLOB cwrap_f90 
    fortran/static/cwrap*.f90
    )

add_library (otistatic STATIC 
    ${static_f90}
)


add_library (oticwrap STATIC 
    ${cwrap_f90}
)

target_link_libraries(otistatic 
    OpenMP::OpenMP_Fortran)

target_link_libraries(oticwrap 
    otistatic
    OpenMP::OpenMP_Fortran)


file(GLOB array_interface_f90 
    fortran/experimental/array_interface*.f90
    fortran/static/real_utils.f90
    fortran/static/master_parameters.f90 
)

add_library (otiarrinter STATIC 
    ${array_interface_f90}
)
target_link_libraries(otiarrinter
    oticwrap 
    otistatic
    OpenMP::OpenMP_Fortran)


if (CMAKE_Fortran_COMPILER_ID STREQUAL "GNU")
    # Add free length of lines to compile fortran with gfortran.
    target_compile_options(otistatic 
        PRIVATE
        -ffree-line-length-0
        )

    # Declare additional link libraries for C-Fortran interface
    SET(ISOCBIND_Fortran_LFLAG gfortran) 

elseif (CMAKE_C_COMPILER_ID STREQUAL "Intel")
    # Declare additional link libraries for C-Fortran interface
    SET(ISOCBIND_Fortran_LFLAG ifcore)

elseif (CMAKE_C_COMPILER_ID STREQUAL "IntelLLVM")
    # Declare additional link libraries for C-Fortran interface
    SET(ISOCBIND_Fortran_LFLAG ifcore)

else()

    
endif()









# =========================================================================
#                Setup C library compilation
# =========================================================================

add_library (oti    c/core.c 
                    c/real.c
                    c/dense.c
                    c/sparse.c
                    c/semisparse.c
                    c/static.c
                    c/fem.c
                    )


                    


if(APPLE)
    # SET_TARGET_PROPERTIES(oti PROPERTIES LINK_FLAGS "-arch i386 -arch x86_64")
    # SET_TARGET_PROPERTIES(oti PROPERTIES LINK_FLAGS "-arch x86_64")
    SET_TARGET_PROPERTIES(oti PROPERTIES LINK_FLAGS "-arch arm64")
elseif(UNIX)
    SET_TARGET_PROPERTIES(oti PROPERTIES LINK_FLAGS "")
endif(APPLE)    

# Link to math libraries
target_link_libraries(oti 
    m  oticwrap otistatic ${ISOCBIND_Fortran_LFLAG}
    OpenMP::OpenMP_C)

# -------------------------------------------------------------------
# --------------------------- BUILD OTI -----------------------------
# -------------------------------------------------------------------



# BUILD DATAGEN.

# To compile with linux uncomment the following line
# SET(GCC_COVERAGE_COMPILE_FLAGS "-g -fwrapv -O3 -Wall -Wstrict-prototypes ")
# SET(GCC_COVERAGE_LINK_FLAGS "")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# SET(CMAKE_OSX_DEPLOYMENT_TARGET 12.1)

include_directories ("${PROJECT_SOURCE_DIR}/include")
add_executable(otigen datagen/oti_gen_data.c)

target_link_libraries (otigen oti ${LINK_TARGET_OMP})

# -d Sets directory
# -o Sets global order
# -a sets the number of basis for all elements
# -s Sets a starting order
# -f Sets an ending order
# -m sets the number of basis for the start-finish pair.
SET(OTIGEN_FLAGS -d"${PROJECT_BINARY_DIR}/data/" -o150 -a2)
SET(OTIGEN_FLAGS ${OTIGEN_FLAGS} -s21 -f50 -m3)
SET(OTIGEN_FLAGS ${OTIGEN_FLAGS} -s11 -f20 -m5)
SET(OTIGEN_FLAGS ${OTIGEN_FLAGS} -s5 -f10 -m10)
SET(OTIGEN_FLAGS ${OTIGEN_FLAGS} -s3 -f4 -m100)
SET(OTIGEN_FLAGS ${OTIGEN_FLAGS} -s2 -f2 -m1000)
SET(OTIGEN_FLAGS ${OTIGEN_FLAGS} -s1 -f1 -m65000)


# To generate data call
# ...: make gendata
ADD_CUSTOM_TARGET(gendata 
    COMMAND otigen ${OTIGEN_FLAGS}
    DEPENDS otigen)


# Create folder for data.
FILE(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/data)

# ADD_CUSTOM_COMMAND (
#     TARGET  gendata    
#     # OUTPUT  ${PROJECT_BINARY_DIR}/data/ndirs_n1.npy
#     COMMAND otigen ${OTIGEN_FLAGS}
#     DEPENDS otigen
# )

# INSTALL(
    
#     )




# BUILD EXAMPLES:



# # -------------------------------------------------------------------
# # ------------------------- BUILD OTIFEM ----------------------------
# # -------------------------------------------------------------------

# # set (CMAKE_C_COMPILER "/usr/bin/clang")
# # set(CMAKE_MACOSX_RPATH 1)

# # # The version number.
# # set (OTIFEM_LIBRARY_VERSION_MAJOR 1)
# # set (OTIFEM_LIBRARY_VERSION_MINOR 0)

# # set(CMAKE_BUILD_TYPE RELEASE)
# # set(CMAKE_C_FLAGS_DEBUG "-O2 -g")
# # set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall")


# # SET(GCC_COVERAGE_COMPILE_FLAGS "-arch i386 -arch x86_64 -g -fwrapv -O3 -Wall -Wstrict-prototypes")
# # add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

# # SET(CMAKE_OSX_DEPLOYMENT_TARGET 10.6)

# include_directories ("${PROJECT_SOURCE_DIR}/include")
# add_library (otifem        c/otifem.c 
#                          c/otifem_array.c)

# # To compile with macOs uncomment the following line  
# #SET_TARGET_PROPERTIES(otifem PROPERTIES LINK_FLAGS "-arch i386 -arch x86_64")

# # To compile with linux uncomment the following line
# SET_TARGET_PROPERTIES(otifem PROPERTIES LINK_FLAGS "")


# target_link_libraries (otifem oti)




# # -------------------------------------------------------------------
# # ------------------------- BUILD OTIFEM ----------------------------
# # -------------------------------------------------------------------









# # -------------------------------------------------------------------
# # --------------------- BUILD OTILIB - PYTHON -----------------------
# # -------------------------------------------------------------------

# # 1. Copy python files to the lib directory.


# # Change to generate the proper file in compile time.

# FILE(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/tmp_src)

# # Copy the pure python files of the library to the library folder.
# FILE(COPY  python/whereotilib.py  python/auxFunctions.py
#   DESTINATION "${PROJECT_BINARY_DIR}/lib/" )

# FILE(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/lib/oti)

# FILE(COPY  python/__init__.py
#   DESTINATION "${PROJECT_BINARY_DIR}/lib/oti" )

# configure_file (
#   "${PROJECT_SOURCE_DIR}/src/cython/setup.py.in"
#   "${PROJECT_BINARY_DIR}/tmp_src/setup.py"
#   )
# # include_directories( ${PROJECT_SOURCE_DIR}/include )

# # cython_add_module( otilib cython/otilib.pyx)

# ADD_CUSTOM_TARGET(otipython-core ALL
#   DEPENDS oti)

# # # 2. Execute Cython setup call 
# ADD_CUSTOM_COMMAND (
#   TARGET     otipython-core
#   # POST_BUILD
#   # COMMAND    CFLAGS="-I${PROJECT_SOURCE_DIR}/include" 
#   #            LDFLAGS="-L${PROJECT_BINARY_DIR}/lib"   
#   COMMAND python3 ${PROJECT_BINARY_DIR}/tmp_src/setup.py build_ext -b${PROJECT_BINARY_DIR}/lib 
# )
# # # CFLAGS="-I../../include" LDFLAGS="-L../../build/lib" python3 setup.py build_ext -b../../build/lib
# SET(filesToRemove 
#   ${PROJECT_BINARY_DIR}/lib/oti/*.so 
#   ${PROJECT_BINARY_DIR}/lib/whereotilib.py
#   ${PROJECT_BINARY_DIR}/lib/auxFunctions.py
#   ${PROJECT_BINARY_DIR}/tmp_src/setup.py)
# set_directory_properties( PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "whereotilib.py;auxFunctions.py"  )

# # set_property(DIRECTORY "${PROJECT_BINARY_DIR}/tmp_src"
# #     APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "setup.py")
# # set_property(DIRECTORY "${PROJECT_BINARY_DIR}/lib/oti"
# #     APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "*.so")

# # -------------------------------------------------------------------
# # --------------------- BUILD OTILIB - PYTHON -----------------------
# # -------------------------------------------------------------------

# add_library (static_oti   c/mdnum3.c)
# target_link_libraries(static_oti oti)
