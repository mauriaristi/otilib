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

# Semi-sparse OTI numbers (PLAN-semisparse.md):
#   core   index helpers (unions, local/global ranks, remaps, table sub-block vs rank);
#   scalar ssotinum_t against the sotinum_t oracle;
#   soa    oarrss_t (SoA arrays) against the arrso_t oracle;
#   aos    arrss_t (AoS arrays) against the arrso_t oracle.
# A test whose source is not written yet is skipped, so the tree always configures.
foreach(ss_test core scalar soa aos review utils io gauss csr)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test_semisparse_${ss_test}.c")
        add_executable(test_c_semisparse_${ss_test} test_semisparse_${ss_test}.c)
        target_link_libraries(test_c_semisparse_${ss_test} oti oticwrap ${LINK_TARGET_OMP_C})
        add_test(NAME c_semisparse_${ss_test}_test COMMAND test_c_semisparse_${ss_test})
    endif()
endforeach()
