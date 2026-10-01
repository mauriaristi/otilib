#include "oti/dense.h"

// Dense OTI numbers (PLAN-dense-update.md): dense over the global bases 1..nact, per-number truncation
// order, semi-sparse order rules. One translation unit: every file below shares the statics of the
// files before it, so static helpers carry a file-specific prefix.

// -------------------------------------------------------------------------------------------------------
// ---------------------------------     SCALAR FUNCTIONS     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// Memory management and the per-thread workspace.
#include "dense/scalar/memory.c"

// Element access, conversions to and from sotinum_t, truncation and compaction.
#include "dense/scalar/base.c"

// Kernels (same-layout product, zero-extension) and algebra.
#include "dense/scalar/algebra.c"

// Taylor series evaluation and elementary functions.
#include "dense/scalar/functions.c"

// Order and derivative extraction, truncated subtraction, rom_eval, global layouts.
#include "dense/scalar/utils.c"


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     SOA ARRAY FUNCTIONS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

// Memory, element and block access, conversions to and from arrso_t, truncation.
#include "dense/soa/base.c"

// Elementwise and matrix block-product kernels.
#include "dense/soa/kernels.c"

// Elementwise algebra and functions, matrix products.
#include "dense/soa/algebra.c"

// Linear algebra: LU, solve, inverse, determinant.
#include "dense/soa/linalg.c"

// Order and derivative plumbing, truncated products, rom_eval, interp1d.
#include "dense/soa/utils.c"


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     AOS ARRAY FUNCTIONS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

// Arrays of dense scalars: elementwise, matmul, conversions, linear algebra through SoA.
#include "dense/aos/aos.c"


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     SAVE / READ     -------------------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "dense/io/io.c"


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     GAUSS-POINT TYPES     -------------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "dense/gauss/gauss.c"


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     OTI SPARSE MATRICES (CSR)     -----------------------------------
// -------------------------------------------------------------------------------------------------------

#include "dense/csr/csr.c"
