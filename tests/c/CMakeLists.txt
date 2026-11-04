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

# Dense OTI numbers (PLAN-dense-update.md), each against the sotinum_t / arrso_t oracle and
# cross-checked with semi-sparse:
#   scalar otinum_t;   soa    oarr_t (SoA);        linalg LU, solve, inv, det;
#   aos    arro_t;     utils  order plumbing, truncated products, rom_eval;
#   io     save/read;  gauss  feoarr_t;            csr    lilo_t / csro_t;
#   review edge cases found in review.
# A test whose source is not written yet is skipped, so the tree always configures.
foreach(dn_test scalar soa linalg aos utils io gauss csr review)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test_dense_${dn_test}.c")
        add_executable(test_c_dense_${dn_test} test_dense_${dn_test}.c)
        target_link_libraries(test_c_dense_${dn_test} oti oticwrap ${LINK_TARGET_OMP_C})
        add_test(NAME c_dense_${dn_test}_test COMMAND test_c_dense_${dn_test})
    endif()
endforeach()

# n-dimensional real arrays (PLAN-ndarray.md, contracts section 10), written by the oracle agent:
#   core   descriptors, state word, ownership, validator, overlap, statuses;
#   views  basic indexing and view functions;     iter   the multi-operand iterator;
#   ufunc  elementwise arithmetic and functions;   reduce, blas, linalg, index in later phases.
# A test whose source is not written yet is skipped, so the tree always configures.
foreach(nd_test core views iter ufunc reduce blas linalg index alloc)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test_real_ndarray_${nd_test}.c")
        add_executable(test_c_real_ndarray_${nd_test} test_real_ndarray_${nd_test}.c)
        target_link_libraries(test_c_real_ndarray_${nd_test} oti oticwrap ${LINK_TARGET_OMP_C})
        add_test(NAME c_real_ndarray_${nd_test}_test COMMAND test_c_real_ndarray_${nd_test})
    endif()
endforeach()

# Execution layer: oti_ctx, oti_parallel_for, determinism (Phase X).
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test_exec.c")
    add_executable(test_c_exec test_exec.c)
    target_link_libraries(test_c_exec oti oticwrap ${LINK_TARGET_OMP_C})
    add_test(NAME c_exec_test COMMAND test_c_exec)
endif()

# OTI layout metadata oti_meta_t (Phase 7a, contracts section 7), written by the oracle agent.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test_oti_meta.c")
    add_executable(test_c_oti_meta test_oti_meta.c)
    target_link_libraries(test_c_oti_meta oti oticwrap ${LINK_TARGET_OMP_C})
    add_test(NAME c_oti_meta_test COMMAND test_c_oti_meta)
endif()

# Phase 7b readiness and non-finite zero-skip checks of the dense 7a arrays, written by the oracle agent.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test_dense_7b_ready.c")
    add_executable(test_c_dense_7b_ready test_dense_7b_ready.c)
    target_link_libraries(test_c_dense_7b_ready oti oticwrap ${LINK_TARGET_OMP_C})
    add_test(NAME c_dense_7b_ready_test COMMAND test_c_dense_7b_ready)
endif()

# Phase 7b dense SoA n-D C API (views, assignment rules, reservations, strided kernels), oracle agent.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test_dense_7b.c")
    add_executable(test_c_dense_7b test_dense_7b.c)
    target_link_libraries(test_c_dense_7b oti oticwrap ${LINK_TARGET_OMP_C})
    add_test(NAME c_dense_7b_test COMMAND test_c_dense_7b)
endif()

# slice_size() of src/c/core/utils.c (empty, reversed and extreme-step ranges), nd-core agent.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test_core_slice.c")
    add_executable(test_c_core_slice test_core_slice.c)
    target_link_libraries(test_c_core_slice oti oticwrap ${LINK_TARGET_OMP_C})
    add_test(NAME c_core_slice_test COMMAND test_c_core_slice)
endif()

# darr_abs / darr_abs_to / darr_self_abs on non-integer, signed-zero and non-finite values, nd-core agent.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test_real_darr_abs.c")
    add_executable(test_c_real_darr_abs test_real_darr_abs.c)
    target_link_libraries(test_c_real_darr_abs oti oticwrap ${LINK_TARGET_OMP_C})
    add_test(NAME c_real_darr_abs_test COMMAND test_c_real_darr_abs)
endif()
