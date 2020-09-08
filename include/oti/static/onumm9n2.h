#ifndef OTI_ONUMM9N2_H
#define OTI_ONUMM9N2_H

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
#include "onumm9n2/scalar/structures.h"

// Append core operations.
#include "onumm9n2/scalar/base.h"

// Append utils.
#include "onumm9n2/scalar/utils.h"

// Append algebra declarations.
#include "onumm9n2/scalar/algebra.h"

// Append function declarations.
#include "onumm9n2/scalar/functions.h"

// Gauss structure
#include "onumm9n2/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "onumm9n2/array/structures.h"

// Append core operations.
#include "onumm9n2/array/base.h"

// Append algebra declarations.
#include "onumm9n2/array/algebra_elementwise.h"
#include "onumm9n2/array/algebra_matops.h"

// Append utils.
#include "onumm9n2/array/utils.h"

// Function evaluation (Elementwise).
#include "onumm9n2/array/functions.h"

// Gauss structure
#include "onumm9n2/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif