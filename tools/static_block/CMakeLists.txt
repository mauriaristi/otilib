# Static block-kernel harness (PLAN-ndarray.md Phase 10, item 3). Added by the top-level
# CMakeLists.txt only with -DOTI_BUILD_STATIC_BLOCK=ON (off by default); never registered with ctest:
#
#   cmake -S . -B <build> -DOTI_BUILD_STATIC_BLOCK=ON
#   cmake --build <build> --target test_static_block
#   <build>/tools/static_block/test_static_block
#
# src/python/pyoti/python/block_kernel_writer.py generates the fixed-(k, p) block kernels into this
# build directory; test_static_block checks them bit for bit against the dense SoA product
# (oarr_kernel_mul_acc, src/c/dense/soa/kernels.c). The generated kernels are compiled with the
# default C flags, as src/c/dense.c is: neither sets -ffp-contract, so both contract (or not) the
# same way, which the bit-for-bit comparison relies on.
find_package(Python3 REQUIRED COMPONENTS Interpreter)

set(OTI_BLOCK_WRITER "${PROJECT_SOURCE_DIR}/src/python/pyoti/python/block_kernel_writer.py")
set(OTI_BLOCK_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(OTI_BLOCK_COMBOS 1,1 1,10 2,4 3,3 10,2)

add_custom_command(
    OUTPUT "${OTI_BLOCK_DIR}/oti_static_block.h" "${OTI_BLOCK_DIR}/oti_static_block.c"
    COMMAND Python3::Interpreter -I "${OTI_BLOCK_WRITER}" --output "${OTI_BLOCK_DIR}"
            --combos ${OTI_BLOCK_COMBOS}
    DEPENDS "${OTI_BLOCK_WRITER}"
    COMMENT "Generating the static block kernels for ${OTI_BLOCK_COMBOS}"
    VERBATIM)

add_executable(test_static_block test_static_block.c "${OTI_BLOCK_DIR}/oti_static_block.c")
target_include_directories(test_static_block PRIVATE
    "${OTI_BLOCK_DIR}"
    "${PROJECT_SOURCE_DIR}/include"
    "${OTI_GENERATED_INCLUDE_DIR}"
    "${PROJECT_SOURCE_DIR}/src/c")
target_compile_options(test_static_block PRIVATE -Wextra)
target_link_libraries(test_static_block oti oticwrap ${LINK_TARGET_OMP_C})
