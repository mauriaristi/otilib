#include "oti/static/mdnum7.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "mdnum7/scalar/base.c"

// Basic algebraic operations, such as addition and multiplication.
#include "mdnum7/scalar/algebra.c"
#include "mdnum7/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "mdnum7/scalar/functions.c"
#include "mdnum7/scalar/functions_to.c"

// Utils
#include "mdnum7/scalar/utils.c"

// Gauss 
#include "mdnum7/scalar/gauss.c"

// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of OTIs support:
// Base functions to support memory manipulation.
#include "mdnum7/array/base.c"

// Array algebra.
#include "mdnum7/array/algebra_elementwise.c"
#include "mdnum7/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "mdnum7/array/algebra_matops.c"
#include "mdnum7/array/algebra_matops_to.c"

#include "mdnum7/array/utils.c"

// Array functions: Elementwise function evaluation.
#include "mdnum7/array/functions.c"
#include "mdnum7/array/functions_to.c"

// Gauss 
#include "mdnum7/array/gauss.c"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

