#include "oti/static/<<<module_name>>>.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "<<<module_name>>>/scalar/base.c"

// Basic algebraic operations, such as addition and multiplication.
#include "<<<module_name>>>/scalar/algebra.c"
#include "<<<module_name>>>/scalar/algebra_to.c"

// Analytic and Trascendental function evaluation.
#include "<<<module_name>>>/scalar/functions.c"
#include "<<<module_name>>>/scalar/functions_to.c"

// Utils
#include "<<<module_name>>>/scalar/utils.c"

// Gauss 
#include "<<<module_name>>>/scalar/gauss.c"


// ----------------------------------------------------------------------------------------------------
// -----------------------------------   END SCALAR FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------------    ARRAY  FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of OTIs support:
// Base functions to support memory manipulation.
#include "<<<module_name>>>/array/base.c"

// Array algebra.
#include "<<<module_name>>>/array/algebra_elementwise.c"
#include "<<<module_name>>>/array/algebra_elementwise_to.c"

// Array algebra: Matrix operations such as matmul, determinant and invertion.
#include "<<<module_name>>>/array/algebra_matops.c"
#include "<<<module_name>>>/array/algebra_matops_to.c"

#include "<<<module_name>>>/array/utils.c"


// Array functions: Elementwise function evaluation.
#include "<<<module_name>>>/array/functions.c"
#include "<<<module_name>>>/array/functions_to.c"

// Gauss 
#include "<<<module_name>>>/array/gauss.c"

// ----------------------------------------------------------------------------------------------------
// --------------------------------------  END ARRAY FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------

