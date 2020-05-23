#ifndef OTI_FEM_H
#define OTI_FEM_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "oti/comm.h"
#include "oti/real.h"
#include "oti/dense.h"
#include "oti/sparse.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------

// Gaussian array.
#include "fem/gauss.h"
// #include "fem/feoarr.h"

// Enums.
#include "fem/enums.h"


// Basis functions.
#include "fem/basis_functions.h"

// Element class methods.
#include "fem/element.h"

// Finite Element related functions.
#include "fem/functions.h"

// Finite ELement integration point computation.
#include "fem/integration_points.h"




#endif