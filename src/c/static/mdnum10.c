#include "oti/static/mdnum10.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "mdnum10/scalar/base.c"

// Basic algebraic operations, such as addition and multiplication.
#include "mdnum10/scalar/algebra.c"
#include "mdnum10/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "mdnum10/scalar/functions.c"
#include "mdnum10/scalar/functions_to.c"

// Utils
#include "mdnum10/scalar/utils.c"

// Gauss 
#include "mdnum10/scalar/gauss.c"

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of OTIs support:
// Base functions to support memory manipulation.
#include "mdnum10/array/base.c"

// Array algebra.
#include "mdnum10/array/algebra_elementwise.c"
#include "mdnum10/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "mdnum10/array/algebra_matops.c"
#include "mdnum10/array/algebra_matops_to.c"

#include "mdnum10/array/utils.c"

// Array functions: Elementwise function evaluation.
#include "mdnum10/array/functions.c"
#include "mdnum10/array/functions_to.c"

// Gauss 
#include "mdnum10/array/gauss.c"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

