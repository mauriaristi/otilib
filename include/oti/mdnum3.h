#ifndef OTI_MDNUM3_H
#define OTI_MDNUM3_H

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
#include "mdnum3/scalar/structures.h"

// Append core operations.
#include "mdnum3/scalar/base.h"

// Append utils.
#include "mdnum3/scalar/utils.h"

// Append algebra declarations.
#include "mdnum3/scalar/algebra.h"

// Append function declarations.
#include "mdnum3/scalar/functions.h"

// Gauss structure
#include "mdnum3/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "mdnum3/array/structures.h"

// Append core operations.
#include "mdnum3/array/base.h"

// Append algebra declarations.
#include "mdnum3/array/algebra_elementwise.h"
#include "mdnum3/array/algebra_matops.h"

// Append utils.
#include "mdnum3/array/utils.h"

// Function evaluation (Elementwise).
#include "mdnum3/array/functions.h"

// Gauss structure
#include "mdnum3/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif