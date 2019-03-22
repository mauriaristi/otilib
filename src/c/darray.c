#include "oti/darray.h"


// ----------------------------------------------------------------------------------------------------
// ---------------------------------     DARRAY FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darray_getItem(darray_t* p_array, uint64_t i, uint64_t j, double* num){
    
    num[0] = p_array->p_data[j+i*p_array->ncols];

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darray_setItem( double num, uint64_t i, uint64_t j, darray_t* p_array){
    
    p_array->p_data[j+i*p_array->ncols] = num; 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
int64_t darray_zeros(darray_t* p_array, uint64_t nrows, uint64_t ncols){
    
    double value = 0.0;

    p_array->ncols  = ncols       ;
    p_array->nrows  = nrows       ;
    p_array->size   = ncols*nrows ;
    p_array->p_data = (double*) malloc( p_array->size * sizeof(double) );

    if (p_array->p_data == NULL){
        return OTI_OutOfMemory;
    }

    // Set 0 to all elements.
    memset(p_array->p_data, value, p_array->size*sizeof(double)  );

    return OTI_success;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darray_free(darray_t* p_array){
    
    // Free pointer 
    free( p_array->p_data);
    p_array->p_data = NULL;
    p_array->ncols  =    0;
    p_array->nrows  =    0;
    p_array->size   =    0;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
int64_t darray_createEmpty(darray_t* p_array, uint64_t nrows, uint64_t ncols){
    
    p_array->ncols  = ncols;
    p_array->nrows  = nrows;
    p_array->size   = ncols*nrows;
    p_array->p_data = (double*) malloc( p_array->size * sizeof(double) );
        
    if (p_array->p_data == NULL){
        return OTI_OutOfMemory;
    }
    
    return OTI_success;

}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// -------------------------------     END DARRAY FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------
