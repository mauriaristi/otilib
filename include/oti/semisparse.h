#ifndef OTI_SEMISPARSE_H
#define OTI_SEMISPARSE_H


// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "oti/core.h"
#include "oti/real.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------








// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
// ------------------------------------    SCALAR DECLARATIONS     ------------------------------------
// ----------------------------------------------------------------------------------------------------

// Append oti number structures.
#include "semisparse/scalar/structures.h"

// Append core operations.
#include "semisparse/scalar/base.h"

// Append utils.
#include "semisparse/scalar/utils.h"

// Append algebra declarations.
#include "semisparse/scalar/algebra.h"

// Append function declarations.
#include "semisparse/scalar/functions.h"

// Gauss structure
#include "semisparse/scalar/gauss.h"


// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END SCALAR DECLARATIONS     ---------------------------------
// ----------------------------------------------------------------------------------------------------




// ----------------------------------------------------------------------------------------------------
// ------------------------------------    ARRAY DECLARATIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Array of oti numbers
// Append array of otis structures.
#include "semisparse/array/structures.h"

// Append core operations.
#include "semisparse/array/base.h"

// Append algebra declarations.
#include "semisparse/array/algebra_elementwise.h"
#include "semisparse/array/algebra_matops.h"

// Append utils.
#include "semisparse/array/utils.h"


// Function evaluation (Elementwise).
#include "semisparse/array/functions.h"

// Gauss structure
#include "semisparse/array/gauss.h"



// Append oti of arrays structures.
// #include "semisparse/array/oti_of_array/structures.h"

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END ARRAY DECLARATIONS     ----------------------------------
// ----------------------------------------------------------------------------------------------------


#endif