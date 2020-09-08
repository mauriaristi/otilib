#include "oti/static/onumm7n2.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "onumm7n2/scalar/base.c"

// Basic algebraic operations, such as addition and multiplication.
#include "onumm7n2/scalar/algebra.c"
#include "onumm7n2/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "onumm7n2/scalar/functions.c"
#include "onumm7n2/scalar/functions_to.c"

// Utils
#include "onumm7n2/scalar/utils.c"

// Gauss 
#include "onumm7n2/scalar/gauss.c"

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of OTIs support:
// Base functions to support memory manipulation.
#include "onumm7n2/array/base.c"

// Array algebra.
#include "onumm7n2/array/algebra_elementwise.c"
#include "onumm7n2/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "onumm7n2/array/algebra_matops.c"
#include "onumm7n2/array/algebra_matops_to.c"

#include "onumm7n2/array/utils.c"

// Array functions: Elementwise function evaluation.
#include "onumm7n2/array/functions.c"
#include "onumm7n2/array/functions_to.c"

// Gauss 
#include "onumm7n2/array/gauss.c"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

