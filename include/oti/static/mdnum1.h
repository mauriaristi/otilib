#ifndef OTI_MDNUM1_H
#define OTI_MDNUM1_H

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
#include "mdnum1/scalar/structures.h"

// Append core operations.
#include "mdnum1/scalar/base.h"

// Append utils.
#include "mdnum1/scalar/utils.h"

// Append algebra declarations.
#include "mdnum1/scalar/algebra.h"

// Append function declarations.
#include "mdnum1/scalar/functions.h"

// Gauss structure
#include "mdnum1/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "mdnum1/array/structures.h"

// Append core operations.
#include "mdnum1/array/base.h"

// Append algebra declarations.
#include "mdnum1/array/algebra_elementwise.h"
#include "mdnum1/array/algebra_matops.h"

// Append utils.
#include "mdnum1/array/utils.h"

// Function evaluation (Elementwise).
#include "mdnum1/array/functions.h"

// Gauss structure
#include "mdnum1/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif