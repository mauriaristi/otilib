# OTI numbers in C and Fortran -> CMakeLists.txt file
#
# Created by:
# Mauricio Aristizabal Cano
# Date: January 24 2024
# Last Modified: January 24 2024
#


# Fortran Examples:

include_directories (   
	"${PROJECT_BINARY_DIR}/lib"
	"${PROJECT_SOURCE_DIR}/include/"
)

link_directories (    
    "${PROJECT_BINARY_DIR}/lib"
)


add_executable(sparse_scalar_c c/sparse_scalar_01.c)


target_link_libraries ( sparse_scalar_c oti oticwrap ${LINK_TARGET_OMP_C} )
