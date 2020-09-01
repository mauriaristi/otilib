#include "oti/static/onumm5n1.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "onumm5n1/scalar/base.c"

// Basic algebraic operations, such as addition and multiplication.
#include "onumm5n1/scalar/algebra.c"
#include "onumm5n1/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "onumm5n1/scalar/functions.c"
#include "onumm5n1/scalar/functions_to.c"

// Utils
#include "onumm5n1/scalar/utils.c"

// Gauss 
#include "onumm5n1/scalar/gauss.c"

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of OTIs support:
// Base functions to support memory manipulation.
#include "onumm5n1/array/base.c"

// Array algebra.
#include "onumm5n1/array/algebra_elementwise.c"
#include "onumm5n1/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "onumm5n1/array/algebra_matops.c"
#include "onumm5n1/array/algebra_matops_to.c"

#include "onumm5n1/array/utils.c"

// Array functions: Elementwise function evaluation.
#include "onumm5n1/array/functions.c"
#include "onumm5n1/array/functions_to.c"

// Gauss 
#include "onumm5n1/array/gauss.c"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

