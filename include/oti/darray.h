#ifndef DARRAY_H
#define DARRAY_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------
#include "oti/core.h" // Requires error codes, stdlib.h and string libraries.
#include <stdlib.h>
#include <string.h>
// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    double*       p_data; // Data array
    uint64_t       nrows; // Number of rows.
    uint64_t       ncols; // Number of cols.
    uint64_t        size; // Total size of the array.
} darray_t;


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd



// added to c_otilib.pxd

void c_darray_getItem(darray_t* p_array, uint64_t i, uint64_t j, double* num); // inline

void c_darray_setItem( double num, uint64_t i, uint64_t j, darray_t* p_array); // inline

int64_t c_darray_zeros(darray_t* p_array, uint64_t nrows, uint64_t ncols);

void c_darray_free(darray_t* p_array);

int64_t c_darray_createEmpty(darray_t* p_array, uint64_t nrows, uint64_t ncols);

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif