#ifndef OTI_ONUMM0N0_H
#define OTI_ONUMM0N0_H

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
#include "onumm0n0/scalar/structures.h"

// Append core operations.
#include "onumm0n0/scalar/base.h"

// Append utils.
#include "onumm0n0/scalar/utils.h"

// Append algebra declarations.
#include "onumm0n0/scalar/algebra.h"

// Append function declarations.
#include "onumm0n0/scalar/functions.h"

// Gauss structure
#include "onumm0n0/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "onumm0n0/array/structures.h"

// Append core operations.
#include "onumm0n0/array/base.h"

// Append algebra declarations.
#include "onumm0n0/array/algebra_elementwise.h"
#include "onumm0n0/array/algebra_matops.h"

// Append utils.
#include "onumm0n0/array/utils.h"

// Function evaluation (Elementwise).
#include "onumm0n0/array/functions.h"

// Gauss structure
#include "onumm0n0/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif