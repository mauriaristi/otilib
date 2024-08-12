# OTI numbers in C and Fortran -> CMakeLists.txt file
#
# Created by:
# Mauricio Aristizabal Cano
# Date: June 18 2024
# Last Modified: June 18 2024
#


# Fortran Examples:

include_directories (   
	"${PROJECT_BINARY_DIR}/lib"
	"${PROJECT_SOURCE_DIR}/include/"
)

link_directories (    
    "${PROJECT_BINARY_DIR}/lib"
)


add_executable(basic_scalar_f fortran/basic_scalar.f90)

target_link_libraries ( basic_scalar_f otistatic ${LINK_TARGET_OMP_Fortran} )

add_executable(basic_scalar_c c/basic_scalar.c)
add_executable(basic_array_c c/basic_array.c)

target_link_libraries ( basic_scalar_c oti oticwrap ${LINK_TARGET_OMP_C} )
target_link_libraries ( basic_array_c oti oticwrap ${LINK_TARGET_OMP_C} )