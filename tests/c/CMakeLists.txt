# OTI numbers in C -> CMakeLists.txt file
#
# Created by:
# Mauricio Aristizabal Cano
# Date: January 30 2019
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

# To compile with macOs uncomment the following line 
#SET(GCC_COVERAGE_COMPILE_FLAGS "-arch i386 -arch x86_64 -g -fwrapv -O3 -Wall -Wstrict-prototypes")




if (GENERATE_C_TESTS)
  



# To compile with linux uncomment the following line
SET(GCC_COVERAGE_COMPILE_FLAGS "-g -fwrapv -O3 -Wall -Wstrict-prototypes ")
SET(GCC_COVERAGE_LINK_FLAGS "")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

SET(CMAKE_OSX_DEPLOYMENT_TARGET 10.6)


include_directories ("${PROJECT_SOURCE_DIR}/include")
add_executable(test_import test_import.c)

target_link_libraries (test_import oti)

add_executable(test_otinum test_otinum.c)
target_link_libraries (test_otinum oti)

add_executable(test_imdir_mult test_imdir_mult.c)
target_link_libraries (test_imdir_mult oti)


add_executable(test_gen_data test_gen_data.c)
target_link_libraries (test_gen_data oti)




# add_executable(test_sotinum test_sotinum.c)
# target_link_libraries (test_sotinum oti)

# add_executable(test_sparse_sum test_sparse_sum.c)
# target_link_libraries (test_sparse_sum oti)


# SET_TARGET_PROPERTIES(oti PROPERTIES LINK_FLAGS "")

endif (GENERATE_C_TESTS)
# -------------------------------------------------------------------
# --------------------------- BUILD OTI -----------------------------
# -------------------------------------------------------------------

