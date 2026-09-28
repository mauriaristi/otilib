# C Tests for OTIlib

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${OTI_GENERATED_INCLUDE_DIR}"
    "${PROJECT_SOURCE_DIR}/src/c"
)

link_directories(
    "${PROJECT_BINARY_DIR}/lib"
)

add_executable(test_c_scalar test_scalar.c)
target_link_libraries(test_c_scalar oti oticwrap ${LINK_TARGET_OMP_C})
add_test(NAME c_scalar_test COMMAND test_c_scalar)

add_executable(test_c_array test_array.c)
target_link_libraries(test_c_array oti oticwrap ${LINK_TARGET_OMP_C})
add_test(NAME c_array_test COMMAND test_c_array)

add_executable(test_c_version test_version.c)
target_link_libraries(test_c_version oti oticwrap ${LINK_TARGET_OMP_C})
add_test(NAME c_version_test COMMAND test_c_version)

add_executable(test_c_lapack test_lapack.c)
target_link_libraries(test_c_lapack oti oticwrap ${LINK_TARGET_OMP_C})
add_test(NAME c_lapack_test COMMAND test_c_lapack)

# Sparse OTI linear algebra (LU / solve).
add_executable(test_c_sparse_linalg test_sparse_linalg.c)
target_link_libraries(test_c_sparse_linalg oti oticwrap ${LINK_TARGET_OMP_C})
add_test(NAME c_sparse_linalg_test COMMAND test_c_sparse_linalg)

# Lazy, in-memory direction-helper tables (nbasis schedule, lazy multtabl build, thread safety).
add_executable(test_c_dhelp test_dhelp.c)
target_link_libraries(test_c_dhelp oti oticwrap ${LINK_TARGET_OMP_C})
add_test(NAME c_dhelp_test COMMAND test_c_dhelp)
