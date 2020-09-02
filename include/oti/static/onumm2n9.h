#ifndef OTI_ONUMM2N9_H
#define OTI_ONUMM2N9_H

// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "oti/core.h"
#include "oti/real.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    SCALAR DECLARATIONS     ------------------------------------
// ----------------------------------------------------------------------------------------------------

// Append oti number structures.
#include "onumm2n9/scalar/structures.h"

// Append core operations.
#include "onumm2n9/scalar/base.h"

// Append utils.
#include "onumm2n9/scalar/utils.h"

// Append algebra declarations.
#include "onumm2n9/scalar/algebra.h"

// Append function declarations.
#include "onumm2n9/scalar/functions.h"

// Gauss structure
#include "onumm2n9/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "onumm2n9/array/structures.h"

// Append core operations.
#include "onumm2n9/array/base.h"

// Append algebra declarations.
#include "onumm2n9/array/algebra_elementwise.h"
#include "onumm2n9/array/algebra_matops.h"

// Append utils.
#include "onumm2n9/array/utils.h"

// Function evaluation (Elementwise).
#include "onumm2n9/array/functions.h"

// Gauss structure
#include "onumm2n9/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif