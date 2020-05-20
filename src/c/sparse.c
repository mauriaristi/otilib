#include "oti/sparse.h"






// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "sparse/scalar/base.c"

// Operations where a truncation is recquired.
#include "sparse/scalar/trunc_ops.c"

// Basic algebraic operations, such as addition and multiplication.
#include "sparse/scalar/algebra.c"
#include "sparse/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "sparse/scalar/functions.c"
#include "sparse/scalar/functions_to.c"

// Utils
#include "sparse/scalar/utils.c"


// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------










// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of OTIs support:
// Base functions to support memory manipulation.
#include "sparse/array/base.c"

// Array algebra.
#include "sparse/array/algebra_elementwise.c"
#include "sparse/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "sparse/array/algebra_matops.c"
#include "sparse/array/algebra_matops_to.c"

#include "sparse/array/utils.c"


// Array functions: Elementwise function evaluation.
#include "sparse/array/functions.c"
#include "sparse/array/functions_to.c"


// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

