#include "oti/mdnum3.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "mdnum3/scalar/base.c"

// Basic algebraic operations, such as addition and multiplication.
#include "mdnum3/scalar/algebra.c"
#include "mdnum3/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "mdnum3/scalar/functions.c"
#include "mdnum3/scalar/functions_to.c"

// Utils
#include "mdnum3/scalar/utils.c"

// Gauss 
#include "mdnum3/scalar/gauss.c"

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of OTIs support:
// Base functions to support memory manipulation.
#include "mdnum3/array/base.c"

// Array algebra.
#include "mdnum3/array/algebra_elementwise.c"
#include "mdnum3/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "mdnum3/array/algebra_matops.c"
#include "mdnum3/array/algebra_matops_to.c"

#include "mdnum3/array/utils.c"

// Array functions: Elementwise function evaluation.
#include "mdnum3/array/functions.c"
#include "mdnum3/array/functions_to.c"

// Gauss 
#include "mdnum3/array/gauss.c"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

