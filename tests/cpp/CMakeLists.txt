# C++ Tests for OTIlib

enable_language(CXX)

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/src/c"
)

link_directories(
    "${PROJECT_BINARY_DIR}/lib"
)

add_executable(test_cpp_vector test_vector.cpp)
add_test(NAME cpp_vector_test COMMAND test_cpp_vector)

add_executable(test_cpp_headers test_cpp_headers.cpp)
target_link_libraries(test_cpp_headers oti oticwrap ${LINK_TARGET_OMP_C})
add_test(NAME cpp_headers_test COMMAND test_cpp_headers)
