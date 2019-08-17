#include "oti/sparse.h"


// ----------------------------------------------------------------------------------------------------
// -------------------------------    SPARSE OTINUM FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "sparse/base.c"

// Operations where a truncation is recquired.
#include "sparse/trunc_ops.c"

// Basic algebraic operations, such as addition and multiplication.
#include "sparse/algebra.c"

// Analytic and Trascendental function evaluation.
#include "sparse/functions.c"

// Functions added to support pre-allocated result holders.
#include "sparse/algebra_to.c"
#include "sparse/functions_to.c"



// // Array support.
// // Base functions to support manipulation.
// #include "sparse/array_base.c"

// // Array algebra: Elementwise operations.
// #include "sparse/array_algebra_elementwise.c"

// // Array algebra: Matrix operations such as matmul, determinant and invertion.
// #include "sparse/array_algebra_matops.c"

// // Array functions: Elementwise function evaluation.
// #include "sparse/array_functions.c"

// ----------------------------------------------------------------------------------------------------
// ----------------------------    END SPARSE OTINUM FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------