#include "oti/static/onumm1n4.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "onumm1n4/scalar/base.c"

// Basic algebraic operations, such as addition and multiplication.
#include "onumm1n4/scalar/algebra.c"
#include "onumm1n4/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "onumm1n4/scalar/functions.c"
#include "onumm1n4/scalar/functions_to.c"

// Utils
#include "onumm1n4/scalar/utils.c"

// Gauss 
#include "onumm1n4/scalar/gauss.c"

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of OTIs support:
// Base functions to support memory manipulation.
#include "onumm1n4/array/base.c"

// Array algebra.
#include "onumm1n4/array/algebra_elementwise.c"
#include "onumm1n4/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "onumm1n4/array/algebra_matops.c"
#include "onumm1n4/array/algebra_matops_to.c"

#include "onumm1n4/array/utils.c"

// Array functions: Elementwise function evaluation.
#include "onumm1n4/array/functions.c"
#include "onumm1n4/array/functions_to.c"

// Gauss 
#include "onumm1n4/array/gauss.c"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

