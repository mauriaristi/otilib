# C Tests for OTIlib

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
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
