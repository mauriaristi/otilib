#include "oti/sparse.h"


// ----------------------------------------------------------------------------------------------------
// -------------------------------    SPARSE OTINUM FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// Base functions to support manipulation.
#include "sparse/base.c"

// Operations where a truncation is recquired.
#include "sparse/trunc_ops.c"

// Basic algebraic operations, such as addition and multiplication.
#include "sparse/algebra.c"

// Analytic and Trascendental function evaluation.
#include "sparse/functions.c"

// Functions added to support pre-allocated result holders.
#include "sparse/algebra_to.c"
#include "sparse/functions_to.c"

// ----------------------------------------------------------------------------------------------------
// ----------------------------    END SPARSE OTINUM FUNCTIONS   --------------------------------------
// ----------------------------------------------------------------------------------------------------