// glibc hides posix_memalign (POSIX, not C99) under the Release build's -std=c99 unless a feature-test
// macro is defined before the first system header (contracts S23, the 1.3.1 pattern of src/c/dense.c).
// Not defined on Apple, where _POSIX_C_SOURCE would instead hide non-POSIX declarations.
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L
#endif

#include "oti/real/ndarray.h"
#include "real/ndarray/nd_internal.h"

// n-dimensional double arrays of the real module (PLAN-ndarray.md, PLAN-ndarray-contracts.md).
// Its own translation unit, compiled before src/c/real.c and with -ffp-contract=off (contracts S12).
// File-static helpers carry the per-file prefix listed in include/oti/real/ndarray/structures.h.

// Phase 1: storage, validator, views.
#include "real/ndarray/buffer.c"
#include "real/ndarray/validate.c"
#include "real/ndarray/create.c"
#include "real/ndarray/views.c"

// Phase 1: iterator and elementwise kernels.
#include "real/ndarray/iter.c"
#include "real/ndarray/elementwise.c"
#include "real/ndarray/functions.c"
