#include "oti/dense.h"






// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "dense/scalar/base.c"

// Operations where a truncation is recquired.
#include "dense/scalar/trunc_ops.c"

// Basic algebraic operations, such as addition and multiplication.
#include "dense/scalar/algebra.c"
#include "dense/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "dense/scalar/functions.c"
#include "dense/scalar/functions_to.c"

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------






// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------
// Array support.

// Base functions to support manipulation.
#include "dense/array/base.c"

// Array algebra: Elementwise operations.
#include "dense/array/algebra_elementwise.c"
#include "dense/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "dense/array/algebra_matops.c"
#include "dense/array/algebra_matops_to.c"

#include "dense/array/algebra_helper.c"

// // Array functions: Elementwise function evaluation.
#include "dense/array/functions.c"


// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

