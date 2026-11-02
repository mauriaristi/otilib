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
