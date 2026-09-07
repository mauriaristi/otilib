# Fortran Tests for OTIlib

include_directories(
    "${PROJECT_BINARY_DIR}/lib"
    "${PROJECT_SOURCE_DIR}/include/"
)

link_directories(
    "${PROJECT_BINARY_DIR}/lib"
)

add_executable(test_f_static_scalar test_static_scalar.f90)
target_link_libraries(test_f_static_scalar otistatic ${LINK_TARGET_OMP_Fortran})
add_test(NAME fortran_static_scalar_test COMMAND test_f_static_scalar)

add_executable(test_f_sparse_scalar test_sparse_scalar.f90)
target_link_libraries(test_f_sparse_scalar otifsparse ${LINK_TARGET_OMP_Fortran})
add_test(NAME fortran_sparse_scalar_test COMMAND test_f_sparse_scalar)
