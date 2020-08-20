#include "oti/onumm3n3.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "onumm3n3/scalar/base.c"

// Basic algebraic operations, such as addition and multiplication.
#include "onumm3n3/scalar/algebra.c"
#include "onumm3n3/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "onumm3n3/scalar/functions.c"
#include "onumm3n3/scalar/functions_to.c"

// Utils
#include "onumm3n3/scalar/utils.c"

// Gauss 
#include "onumm3n3/scalar/gauss.c"

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of OTIs support:
// Base functions to support memory manipulation.
#include "onumm3n3/array/base.c"

// Array algebra.
#include "onumm3n3/array/algebra_elementwise.c"
#include "onumm3n3/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "onumm3n3/array/algebra_matops.c"
#include "onumm3n3/array/algebra_matops_to.c"

#include "onumm3n3/array/utils.c"

// Array functions: Elementwise function evaluation.
#include "onumm3n3/array/functions.c"
#include "onumm3n3/array/functions_to.c"

// Gauss 
#include "onumm3n3/array/gauss.c"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

