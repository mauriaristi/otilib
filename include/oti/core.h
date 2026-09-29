#ifndef OTICORE_H
#define OTICORE_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "oti/comm.h"
#include <math.h>

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------


// Structure definitions
#include "core/structures.h"


// Base implementation of direction Helper.
#include "core/base.h"

// Utils
#include "core/utils.h"

// Data precomputation functions.
#include "core/precompute.h"

// Inline helpers (lazy multiplication tables).
#include "core/dhelp_inline.h"

// Semi-sparse index helpers (active-base unions, local/global ranks, product-index pairs).
#include "core/semisparse.h"

// Dense.
#include "core/dense.h"

// Sparse.
#include "core/sparse.h"

// LAPACK / BLAS interface (Fortran wrappers, library otilapack).
#include "core/lapack.h"


#endif