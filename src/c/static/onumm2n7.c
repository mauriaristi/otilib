#include "oti/static/onumm2n7.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "onumm2n7/scalar/base.c"

// Basic algebraic operations, such as addition and multiplication.
#include "onumm2n7/scalar/algebra.c"
#include "onumm2n7/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "onumm2n7/scalar/functions.c"
#include "onumm2n7/scalar/functions_to.c"

// Utils
#include "onumm2n7/scalar/utils.c"

// Gauss 
#include "onumm2n7/scalar/gauss.c"

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of OTIs support:
// Base functions to support memory manipulation.
#include "onumm2n7/array/base.c"

// Array algebra.
#include "onumm2n7/array/algebra_elementwise.c"
#include "onumm2n7/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "onumm2n7/array/algebra_matops.c"
#include "onumm2n7/array/algebra_matops_to.c"

#include "onumm2n7/array/utils.c"

// Array functions: Elementwise function evaluation.
#include "onumm2n7/array/functions.c"
#include "onumm2n7/array/functions_to.c"

// Gauss 
#include "onumm2n7/array/gauss.c"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

