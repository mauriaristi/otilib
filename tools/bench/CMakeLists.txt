# C benchmarks of the semi-sparse types against the sparse types (PLAN-semisparse.md, 5.2).
# Built only on request: cmake -DOTI_BUILD_BENCH=ON ..; then
#   ./tools/bench/bench_semisparse_scalar [--quick] > scalar.csv
#   ./tools/bench/bench_semisparse_arrays [--quick] > arrays.csv
#   ./tools/bench/bench_semisparse_memory ... (one case per process; see its header)
include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${OTI_GENERATED_INCLUDE_DIR}"
    "${PROJECT_SOURCE_DIR}/src/c"
)

foreach(bench scalar arrays)
    add_executable(bench_semisparse_${bench} bench_semisparse_${bench}.c)
    target_link_libraries(bench_semisparse_${bench} oti oticwrap ${LINK_TARGET_OMP_C})
endforeach()

# Heap memory benchmark (macOS): memtrack interposes the malloc family and counts live/peak bytes.
#   ./tools/bench/bench_semisparse_memory scalar mul 10 4 full same semi
if (APPLE)
    add_library(memtrack SHARED memtrack.c)
    add_executable(bench_semisparse_memory bench_semisparse_memory.c)
    target_link_libraries(bench_semisparse_memory memtrack oti oticwrap ${LINK_TARGET_OMP_C})
endif ()

# ndarray BLAS batch costs (PLAN-ndarray-contracts.md S28; blas.c's NDBL_COST table), never run by
# ctest or at gates:  ./tools/bench/bench_blas_batch [--quick]
add_executable(bench_blas_batch bench_blas_batch.c)
target_link_libraries(bench_blas_batch oti oticwrap ${LINK_TARGET_OMP_C})

# Phase 7a per-call costs of the dense SoA / AoS API (critic W3 finding 1; tools/bench/bench_7a.c),
# compiled against the 7a structs (-DOTI7A); never run by ctest or at gates:
#   OMP_NUM_THREADS=1 ./tools/bench/bench_7a          (FEM sizes, one thread)
#   ./tools/bench/bench_7a large                     (large arrays, default threads)
# Its Python counterpart is tools/bench/bench_7a_py.py (run standalone, see its header).
add_executable(bench_7a bench_7a.c)
target_compile_definitions(bench_7a PRIVATE OTI7A)
target_link_libraries(bench_7a oti oticwrap ${LINK_TARGET_OMP_C})
