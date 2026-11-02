#ifndef OTI_DENSE_H
#define OTI_DENSE_H

// Dense OTI numbers (PLAN-dense-update.md): every number is dense over the global bases 1..nact and
// carries its own truncation order, with the semi-sparse order rules. Scalar otinum_t, SoA array
// oarr_t, AoS array arro_t, Gauss-point types feoarr_t / feotinum_t, CSR builder and view lilo_t /
// csro_t, save / read. Conventions in include/oti/dense/scalar/base.h.

// -------------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "oti/core.h"
#include "oti/real.h"
#include "oti/sparse.h"

// -------------------------------------------------------------------------------------------------------
// ---------------------------------     SCALAR DECLARATIONS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "dense/scalar/structures.h"
#include "dense/scalar/base.h"
#include "dense/scalar/algebra.h"
#include "dense/scalar/functions.h"
#include "dense/scalar/utils.h"

// -------------------------------------------------------------------------------------------------------
// ---------------------------------     SOA ARRAY DECLARATIONS     --------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "dense/soa/structures.h"
#include "dense/soa/base.h"
#include "dense/soa/algebra.h"
#include "dense/soa/linalg.h"
#include "dense/soa/utils.h"

// -------------------------------------------------------------------------------------------------------
// ---------------------------------     AOS, IO, GAUSS, CSR     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

#include "dense/aos/aos.h"
#include "dense/io/io.h"
#include "dense/gauss/gauss.h"
#include "dense/csr/csr.h"

#endif
