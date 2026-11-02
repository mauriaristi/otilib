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
