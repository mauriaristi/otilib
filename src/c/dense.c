#include "oti/dense.h"


// ----------------------------------------------------------------------------------------------------
// ---------------------------------     OTINUM FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "dense/base.c"

// Operations where a truncation is recquired.
#include "dense/trunc_ops.c"

// Basic algebraic operations, such as addition and multiplication.
#include "dense/algebra.c"

// Analytic and Trascendental function evaluation.
#include "dense/functions.c"

// Functions added to support pre-allocated result holders.
#include "dense/algebra_to.c"
#include "dense/functions_to.c"




// ----------------------------------------------------------------------------------------------------
// -------------------------------     END OTINUM FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------