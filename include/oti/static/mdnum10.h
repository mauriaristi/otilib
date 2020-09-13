#ifndef OTI_MDNUM10_H
#define OTI_MDNUM10_H

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
#include "mdnum10/scalar/structures.h"

// Append core operations.
#include "mdnum10/scalar/base.h"

// Append utils.
#include "mdnum10/scalar/utils.h"

// Append algebra declarations.
#include "mdnum10/scalar/algebra.h"

// Append function declarations.
#include "mdnum10/scalar/functions.h"

// Gauss structure
#include "mdnum10/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "mdnum10/array/structures.h"

// Append core operations.
#include "mdnum10/array/base.h"

// Append algebra declarations.
#include "mdnum10/array/algebra_elementwise.h"
#include "mdnum10/array/algebra_matops.h"

// Append utils.
#include "mdnum10/array/utils.h"

// Function evaluation (Elementwise).
#include "mdnum10/array/functions.h"

// Gauss structure
#include "mdnum10/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif