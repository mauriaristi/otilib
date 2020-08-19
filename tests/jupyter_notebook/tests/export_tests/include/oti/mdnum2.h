#ifndef OTI_MDNUM2_H
#define OTI_MDNUM2_H

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
#include "mdnum2/scalar/structures.h"

// Append core operations.
#include "mdnum2/scalar/base.h"

// Append utils.
#include "mdnum2/scalar/utils.h"

// Append algebra declarations.
#include "mdnum2/scalar/algebra.h"

// Append function declarations.
#include "mdnum2/scalar/functions.h"

// Gauss structure
#include "mdnum2/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "mdnum2/array/structures.h"

// Append core operations.
#include "mdnum2/array/base.h"

// Append algebra declarations.
#include "mdnum2/array/algebra_elementwise.h"
#include "mdnum2/array/algebra_matops.h"

// Append utils.
#include "mdnum2/array/utils.h"

// Function evaluation (Elementwise).
#include "mdnum2/array/functions.h"

// Gauss structure
#include "mdnum2/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif