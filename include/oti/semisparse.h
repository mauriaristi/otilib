#ifndef OTI_SEMISPARSE_H
#define OTI_SEMISPARSE_H

// Semi-sparse OTI numbers (PLAN-semisparse.md): dense coefficients over a sorted list of active bases.
// Scalar type ssotinum_t, AoS array arrss_t and SoA array oarrss_t.

// -------------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "oti/core.h"
#include "oti/real.h"
#include "oti/sparse.h"

// -------------------------------------------------------------------------------------------------------
// ---------------------------------     SCALAR DECLARATIONS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "semisparse/scalar/structures.h"
#include "semisparse/scalar/base.h"
#include "semisparse/scalar/algebra.h"
#include "semisparse/scalar/functions.h"
#include "semisparse/scalar/utils.h"


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     SOA ARRAY DECLARATIONS     --------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "semisparse/soa/structures.h"
#include "semisparse/soa/base.h"
#include "semisparse/soa/algebra.h"
#include "semisparse/soa/linalg.h"
#include "semisparse/soa/utils.h"

// -------------------------------------------------------------------------------------------------------
// ---------------------------------     AOS ARRAY DECLARATIONS     --------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "semisparse/array/array.h"
#include "semisparse/io/io.h"
#include "semisparse/gauss/gauss.h"
#include "semisparse/csr/csr.h"

#endif
