#ifndef OTI_MDNUM4_H
#define OTI_MDNUM4_H

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
#include "mdnum4/scalar/structures.h"

// Append core operations.
#include "mdnum4/scalar/base.h"

// Append utils.
#include "mdnum4/scalar/utils.h"

// Append algebra declarations.
#include "mdnum4/scalar/algebra.h"

// Append function declarations.
#include "mdnum4/scalar/functions.h"

// Gauss structure
#include "mdnum4/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "mdnum4/array/structures.h"

// Append core operations.
#include "mdnum4/array/base.h"

// Append algebra declarations.
#include "mdnum4/array/algebra_elementwise.h"
#include "mdnum4/array/algebra_matops.h"

// Append utils.
#include "mdnum4/array/utils.h"

// Function evaluation (Elementwise).
#include "mdnum4/array/functions.h"

// Gauss structure
#include "mdnum4/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif