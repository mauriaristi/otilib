# Fortran ndarray module and C-descriptor shim (PLAN-ndarray.md "Fortran interoperability", Phase F2;
# decision 24). Added by the top-level CMakeLists.txt (option OTI_BUILD_FORTRAN_NDARRAY).
#
# The shim (oti_fortran_shim.c) is compiled for the project's ONE Fortran compiler, against a
# build-directory copy of that vendor's ISO_Fortran_binding.h and nothing else of the vendor: a plain -I
# on the GCC or flang resource directory would shadow the C compiler's stddef.h / stdint.h. Another
# vendor means another build directory (the headers differ in layout and codes; S3 item 7).
#
# Products: library oti_fortran_nd (module oti_real_ndarray + shim; links oti), the module file in
# ${CMAKE_CURRENT_BINARY_DIR}/mod, and the conformance tests of tests/ (ctest -R fortran_nd).

# ---------------------------------------------------------------------- the vendor's CFI header
set (OTI_FORTRAN_CFI_HEADER "" CACHE FILEPATH
     "ISO_Fortran_binding.h of the Fortran compiler; found from the compiler when empty")

set (otif_cfi_header "${OTI_FORTRAN_CFI_HEADER}")
if (NOT otif_cfi_header)
  set (otif_cfi_dirs "")
  get_filename_component (otif_fc_bindir "${CMAKE_Fortran_COMPILER}" DIRECTORY)
  if (CMAKE_Fortran_COMPILER_ID STREQUAL "GNU")
    execute_process (COMMAND "${CMAKE_Fortran_COMPILER}" -print-file-name=include
                     OUTPUT_VARIABLE otif_dir OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_QUIET)
    list (APPEND otif_cfi_dirs "${otif_dir}")
  elseif (CMAKE_Fortran_COMPILER_ID MATCHES "Flang")
    execute_process (COMMAND "${CMAKE_Fortran_COMPILER}" -print-resource-dir
                     OUTPUT_VARIABLE otif_dir OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_QUIET)
    list (APPEND otif_cfi_dirs "${otif_dir}/include" "${otif_fc_bindir}/../include/flang")
  else ()
    # ifx, nvfortran (not tested yet; PLAN-ndarray.md decision 21): the compiler's include directory.
    list (APPEND otif_cfi_dirs "${otif_fc_bindir}/../include" "${otif_fc_bindir}/../../include")
  endif ()
  foreach (otif_dir IN LISTS otif_cfi_dirs)
    if (NOT otif_cfi_header AND EXISTS "${otif_dir}/ISO_Fortran_binding.h")
      set (otif_cfi_header "${otif_dir}/ISO_Fortran_binding.h")
    endif ()
  endforeach ()
endif ()

if (NOT otif_cfi_header OR NOT EXISTS "${otif_cfi_header}")
  message (WARNING "Fortran ndarray module: ISO_Fortran_binding.h of ${CMAKE_Fortran_COMPILER_ID} "
                   "not found; set OTI_FORTRAN_CFI_HEADER. The module is not built.")
  return ()
endif ()
message (STATUS "Fortran ndarray shim: ${CMAKE_Fortran_COMPILER_ID} header ${otif_cfi_header}")

# The one header, alone in its directory.
configure_file ("${otif_cfi_header}" "${CMAKE_CURRENT_BINARY_DIR}/cfi/ISO_Fortran_binding.h" COPYONLY)

# ---------------------------------------------------------------------- module + shim
add_library (oti_fortran_nd STATIC oti_fortran_shim.c oti_real_ndarray.f90)
set_target_properties (oti_fortran_nd PROPERTIES
                       Fortran_MODULE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/mod")
target_include_directories (oti_fortran_nd
  PUBLIC  "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/mod>"
          "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
          "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
          "$<BUILD_INTERFACE:$<$<COMPILE_LANGUAGE:C>:${CMAKE_CURRENT_BINARY_DIR}/cfi>>")
target_link_libraries (oti_fortran_nd PUBLIC oti)
set_source_files_properties (oti_fortran_shim.c PROPERTIES COMPILE_OPTIONS "-Wall;-Wextra")
if (CMAKE_Fortran_COMPILER_ID STREQUAL "GNU")
  set_source_files_properties (oti_real_ndarray.f90 PROPERTIES COMPILE_OPTIONS "-std=f2018;-Wall")
endif ()

# ---------------------------------------------------------------------- conformance tests
if (BUILD_TESTING)
  set (otif_tdir "${CMAKE_CURRENT_SOURCE_DIR}/tests")
  add_library (oti_fortran_nd_testutil STATIC
               "${otif_tdir}/nd_test_util.f90" "${otif_tdir}/shim_checks.c")
  set_target_properties (oti_fortran_nd_testutil PROPERTIES
                         Fortran_MODULE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/mod_tests")
  target_include_directories (oti_fortran_nd_testutil
    PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/mod_tests")
  target_link_libraries (oti_fortran_nd_testutil PUBLIC oti_fortran_nd)

  if (CMAKE_Fortran_COMPILER_ID STREQUAL "GNU")
    set (otif_test_fflags "-std=f2018;-fcheck=all;-Wall")
  else ()
    set (otif_test_fflags "")
  endif ()

  foreach (otif_test ops linalg saved alloc shim_c threads errstop)
    add_executable (test_fortran_nd_${otif_test} "${otif_tdir}/test_nd_${otif_test}.f90")
    target_link_libraries (test_fortran_nd_${otif_test} PRIVATE oti_fortran_nd_testutil)
    target_compile_options (test_fortran_nd_${otif_test} PRIVATE
                            "$<$<COMPILE_LANGUAGE:Fortran>:${otif_test_fflags}>")
    set_target_properties (test_fortran_nd_${otif_test} PROPERTIES
                           Fortran_MODULE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/mod_${otif_test}")
    if (CMAKE_C_FLAGS MATCHES "sanitize")
      # Link with the C driver so that the C compiler's sanitizer runtime is linked; CMake adds the
      # Fortran runtime as an implicit library of the mixed-language target.
      set_target_properties (test_fortran_nd_${otif_test} PROPERTIES LINKER_LANGUAGE C)
      target_link_options (test_fortran_nd_${otif_test} PRIVATE "-fsanitize=address,undefined")
    endif ()
  endforeach ()

  foreach (otif_test ops linalg saved alloc shim_c threads)
    add_test (NAME fortran_nd_${otif_test} COMMAND test_fortran_nd_${otif_test})
  endforeach ()

  # error stop when stat is absent: the message names the status and the failing C function.
  add_test (NAME fortran_nd_errstop COMMAND test_fortran_nd_errstop)
  set_tests_properties (fortran_nd_errstop PROPERTIES PASS_REGULAR_EXPRESSION
    "oti_real_ndarray: nd_add: OTI_ERR_SHAPE: [^\n]*\\(in nd_binary_to")

  # CFI_allocate results and borrowed inputs leak nothing (macOS leaks; not under a sanitizer).
  find_program (OTIF_LEAKS leaks)
  if (APPLE AND OTIF_LEAKS AND NOT CMAKE_C_FLAGS MATCHES "sanitize")
    add_test (NAME fortran_nd_leaks
              COMMAND "${OTIF_LEAKS}" --atExit -- "$<TARGET_FILE:test_fortran_nd_alloc>")
  endif ()
endif ()
