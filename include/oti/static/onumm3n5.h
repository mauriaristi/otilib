#ifndef OTI_ONUMM3N5_H
#define OTI_ONUMM3N5_H

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
#include "onumm3n5/scalar/structures.h"

// Append core operations.
#include "onumm3n5/scalar/base.h"

// Append utils.
#include "onumm3n5/scalar/utils.h"

// Append algebra declarations.
#include "onumm3n5/scalar/algebra.h"

// Append function declarations.
#include "onumm3n5/scalar/functions.h"

// Gauss structure
#include "onumm3n5/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "onumm3n5/array/structures.h"

// Append core operations.
#include "onumm3n5/array/base.h"

// Append algebra declarations.
#include "onumm3n5/array/algebra_elementwise.h"
#include "onumm3n5/array/algebra_matops.h"

// Append utils.
#include "onumm3n5/array/utils.h"

// Function evaluation (Elementwise).
#include "onumm3n5/array/functions.h"

// Gauss structure
#include "onumm3n5/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif