#ifndef OTI_ONUMM3N1_H
#define OTI_ONUMM3N1_H

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
#include "onumm3n1/scalar/structures.h"

// Append core operations.
#include "onumm3n1/scalar/base.h"

// Append utils.
#include "onumm3n1/scalar/utils.h"

// Append algebra declarations.
#include "onumm3n1/scalar/algebra.h"

// Append function declarations.
#include "onumm3n1/scalar/functions.h"

// Gauss structure
#include "onumm3n1/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "onumm3n1/array/structures.h"

// Append core operations.
#include "onumm3n1/array/base.h"

// Append algebra declarations.
#include "onumm3n1/array/algebra_elementwise.h"
#include "onumm3n1/array/algebra_matops.h"

// Append utils.
#include "onumm3n1/array/utils.h"

// Function evaluation (Elementwise).
#include "onumm3n1/array/functions.h"

// Gauss structure
#include "onumm3n1/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif