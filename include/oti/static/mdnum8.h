#ifndef OTI_MDNUM8_H
#define OTI_MDNUM8_H

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
#include "mdnum8/scalar/structures.h"

// Append core operations.
#include "mdnum8/scalar/base.h"

// Append utils.
#include "mdnum8/scalar/utils.h"

// Append algebra declarations.
#include "mdnum8/scalar/algebra.h"

// Append function declarations.
#include "mdnum8/scalar/functions.h"

// Gauss structure
#include "mdnum8/scalar/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "mdnum8/array/structures.h"

// Append core operations.
#include "mdnum8/array/base.h"

// Append algebra declarations.
#include "mdnum8/array/algebra_elementwise.h"
#include "mdnum8/array/algebra_matops.h"

// Append utils.
#include "mdnum8/array/utils.h"

// Function evaluation (Elementwise).
#include "mdnum8/array/functions.h"

// Gauss structure
#include "mdnum8/array/gauss.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------

#endif