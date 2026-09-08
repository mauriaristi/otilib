# OTIlib Test Suite CMake Configuration

enable_testing()

# C tests
add_subdirectory(c)

# Fortran tests
if(CMAKE_Fortran_COMPILER)
    add_subdirectory(fortran)
endif()

# C++ tests
add_subdirectory(cpp)
