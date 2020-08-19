#include "oti/mdnum2.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "mdnum2/scalar/base.c"

// Basic algebraic operations, such as addition and multiplication.
#include "mdnum2/scalar/algebra.c"
#include "mdnum2/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "mdnum2/scalar/functions.c"
#include "mdnum2/scalar/functions_to.c"

// Utils
#include "mdnum2/scalar/utils.c"

// Gauss 
// #include "mdnum2/scalar/gauss.c"

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// // Array of OTIs support:
// // Base functions to support memory manipulation.
// #include "mdnum2/array/base.c"

// // Array algebra.
// #include "mdnum2/array/algebra_elementwise.c"
// #include "mdnum2/array/algebra_elementwise_to.c"

// // Array algebra: Matrix operations such as matmul, determinant and invertion.
// #include "mdnum2/array/algebra_matops.c"
// #include "mdnum2/array/algebra_matops_to.c"

// #include "mdnum2/array/utils.c"

// // Array functions: Elementwise function evaluation.
// #include "mdnum2/array/functions.c"
// #include "mdnum2/array/functions_to.c"

// // Gauss 
// #include "mdnum2/array/gauss.c"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

