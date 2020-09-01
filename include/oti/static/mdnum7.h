#ifndef OTI_MDNUM7_H
#define OTI_MDNUM7_H

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
#include "mdnum7/scalar/structures.h"

// Append core operations.
#include "mdnum7/scalar/base.h"

// Append utils.
#include "mdnum7/scalar/utils.h"

// Append algebra declarations.
#include "mdnum7/scalar/algebra.h"

// Append function declarations.
#include "mdnum7/scalar/functions.h"

// Gauss structure
#include "mdnum7/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "mdnum7/array/structures.h"

// Append core operations.
#include "mdnum7/array/base.h"

// Append algebra declarations.
#include "mdnum7/array/algebra_elementwise.h"
#include "mdnum7/array/algebra_matops.h"

// Append utils.
#include "mdnum7/array/utils.h"

// Function evaluation (Elementwise).
#include "mdnum7/array/functions.h"

// Gauss structure
#include "mdnum7/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif