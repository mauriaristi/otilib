#ifndef OTI_ONUMM1N6_H
#define OTI_ONUMM1N6_H

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
#include "onumm1n6/scalar/structures.h"

// Append core operations.
#include "onumm1n6/scalar/base.h"

// Append utils.
#include "onumm1n6/scalar/utils.h"

// Append algebra declarations.
#include "onumm1n6/scalar/algebra.h"

// Append function declarations.
#include "onumm1n6/scalar/functions.h"

// Gauss structure
#include "onumm1n6/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "onumm1n6/array/structures.h"

// Append core operations.
#include "onumm1n6/array/base.h"

// Append algebra declarations.
#include "onumm1n6/array/algebra_elementwise.h"
#include "onumm1n6/array/algebra_matops.h"

// Append utils.
#include "onumm1n6/array/utils.h"

// Function evaluation (Elementwise).
#include "onumm1n6/array/functions.h"

// Gauss structure
#include "onumm1n6/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif