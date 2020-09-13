#ifndef OTI_MDNUM6_H
#define OTI_MDNUM6_H

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
#include "mdnum6/scalar/structures.h"

// Append core operations.
#include "mdnum6/scalar/base.h"

// Append utils.
#include "mdnum6/scalar/utils.h"

// Append algebra declarations.
#include "mdnum6/scalar/algebra.h"

// Append function declarations.
#include "mdnum6/scalar/functions.h"

// Gauss structure
#include "mdnum6/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "mdnum6/array/structures.h"

// Append core operations.
#include "mdnum6/array/base.h"

// Append algebra declarations.
#include "mdnum6/array/algebra_elementwise.h"
#include "mdnum6/array/algebra_matops.h"

// Append utils.
#include "mdnum6/array/utils.h"

// Function evaluation (Elementwise).
#include "mdnum6/array/functions.h"

// Gauss structure
#include "mdnum6/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif