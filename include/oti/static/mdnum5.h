#ifndef OTI_MDNUM5_H
#define OTI_MDNUM5_H

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
#include "mdnum5/scalar/structures.h"

// Append core operations.
#include "mdnum5/scalar/base.h"

// Append utils.
#include "mdnum5/scalar/utils.h"

// Append algebra declarations.
#include "mdnum5/scalar/algebra.h"

// Append function declarations.
#include "mdnum5/scalar/functions.h"

// Gauss structure
#include "mdnum5/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "mdnum5/array/structures.h"

// Append core operations.
#include "mdnum5/array/base.h"

// Append algebra declarations.
#include "mdnum5/array/algebra_elementwise.h"
#include "mdnum5/array/algebra_matops.h"

// Append utils.
#include "mdnum5/array/utils.h"

// Function evaluation (Elementwise).
#include "mdnum5/array/functions.h"

// Gauss structure
#include "mdnum5/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif