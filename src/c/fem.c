
#include "oti/fem.h"


// ----------------------------------------------------------------------------------------------------
// ---------------------------------     DHELP FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------

// Algebra specific helpers.
// :::::::: REAL :::::::::
// #include "fem/ferarr_base.c"
// #include "fem/ferarr_algebra_elementwise.c"
// #include "fem/ferarr_algebra_matops.c"


// :::::::: OTI  :::::::::

// Dense oti Finite Element array.
#include "fem/feoarr_base.c"
#include "fem/feoarr_algebra_elementwise.c"
// #include "fem/feoarr_algebra_elementwise_to.c"
#include "fem/feoarr_algebra_matops.c"

// // Sparse oti. ?
// #include "fem/fesoarr_base.c"
// #include "fem/fesoarr_algebra_elementwise.c"
// #include "fem/fesoarr_algebra_matops.c"
















// Base FEM functions:
#include "fem/basis_functions.c"

// Setup integration points.
#include "fem/integration_points.c"

// Element structure various functions.
#include "fem/elem.c"

// #include "fem/base.c"

// #include "fem/helper_functions.c"





// Algebra specific helpers.

// ----------------------------------------------------------------------------------------------------
// --------------------------------     END DHELP FUNCTIONS   -----------------------------------------
// ----------------------------------------------------------------------------------------------------


