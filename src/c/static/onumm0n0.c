#include "oti/static/onumm0n0.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "onumm0n0/scalar/base.c"

// Basic algebraic operations, such as addition and multiplication.
#include "onumm0n0/scalar/algebra.c"
#include "onumm0n0/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "onumm0n0/scalar/functions.c"
#include "onumm0n0/scalar/functions_to.c"

// Utils
#include "onumm0n0/scalar/utils.c"

// Gauss 
#include "onumm0n0/scalar/gauss.c"

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of OTIs support:
// Base functions to support memory manipulation.
#include "onumm0n0/array/base.c"

// Array algebra.
#include "onumm0n0/array/algebra_elementwise.c"
#include "onumm0n0/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "onumm0n0/array/algebra_matops.c"
#include "onumm0n0/array/algebra_matops_to.c"

#include "onumm0n0/array/utils.c"

// Array functions: Elementwise function evaluation.
#include "onumm0n0/array/functions.c"
#include "onumm0n0/array/functions_to.c"

// Gauss 
#include "onumm0n0/array/gauss.c"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

