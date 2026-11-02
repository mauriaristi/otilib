// fseeko / ftello (semisparse/io/io.c) are POSIX, not C99: glibc hides them under the Release build's
// -std=c99 unless a feature-test macro is defined before the first system header. Not defined on
// Apple, where _POSIX_C_SOURCE would instead hide non-POSIX declarations.
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L
#endif

#include "oti/semisparse.h"

// Semi-sparse OTI numbers (PLAN-semisparse.md).

// -------------------------------------------------------------------------------------------------------
// ---------------------------------     SCALAR FUNCTIONS     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// Memory management and the per-thread workspace.
#include "semisparse/scalar/memory.c"

// Element access, conversions to and from sotinum_t, truncation and compaction.
#include "semisparse/scalar/base.c"

// Kernels (same-set product, expansion into a larger set) and algebra.
#include "semisparse/scalar/algebra.c"

// Taylor series evaluation and elementary functions.
#include "semisparse/scalar/functions.c"

// Order and derivative extraction, truncated products, rom_eval.
#include "semisparse/scalar/utils.c"


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     SOA ARRAY FUNCTIONS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

// Memory, element and block access, conversions to and from arrso_t, truncation.
#include "semisparse/soa/base.c"

// Elementwise and matrix block-product kernels.
#include "semisparse/soa/kernels.c"

// Elementwise algebra and functions, matrix products.
#include "semisparse/soa/algebra.c"

// Linear algebra: LU, solve, inverse, determinant.
#include "semisparse/soa/linalg.c"

// Order and derivative plumbing, truncated products, rom_eval, interp1d, inv_block.
#include "semisparse/soa/utils.c"


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     AOS ARRAY FUNCTIONS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

// Arrays of semi-sparse scalars: elementwise, matmul, conversions, linear algebra through SoA.
#include "semisparse/array/array.c"


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     SAVE / READ     -------------------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "semisparse/io/io.c"


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     GAUSS-POINT TYPES     -------------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "semisparse/gauss/gauss.c"


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     OTI SPARSE MATRICES (CSR)     -----------------------------------
// -------------------------------------------------------------------------------------------------------

#include "semisparse/csr/csr.c"
