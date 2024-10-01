# OTI numbers in Fortran
#
# Created by:
# Mauricio Aristizabal Cano
# Date: June 18 2024
# Last Modified: June 18 2024
#


# Configure Static libraries:


# Core Fortran libraries:
add_library (master_parameters STATIC 
    static/master_parameters.f90
)
add_library (real_utils STATIC 
    static/real_utils.f90
)
target_link_libraries(master_parameters OpenMP::OpenMP_Fortran)
target_link_libraries(real_utils master_parameters OpenMP::OpenMP_Fortran)


file(GLOB static_f90_srcs static/oti*.f90 static/cwrap*.f90)
file(GLOB sparse_f90_srcs sparse/soti_n1.f90)

add_library (otifort STATIC 
    ${static_f90_srcs}
    ${sparse_f90_srcs}
)

target_link_libraries(otifort real_utils master_parameters OpenMP::OpenMP_Fortran)




# add_library (otistatic c/core.c 
#                     c/real.c
#                     c/dense.c
#                     c/sparse.c
#                     c/semisparse.c
#                     c/static.c
#                     c/fem.c
#                     )