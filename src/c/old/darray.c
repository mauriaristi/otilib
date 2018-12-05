#include "oti/darray.h"


// ----------------------------------------------------------------------------------------------------
// ---------------------------------     DARRAY FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void c_darray_getItem(darray_t* p_array, uint64_t i, uint64_t j, double* num){
    /*
    c_darray_getItem(darray_t* p_array, uint64_t i, uint64_t j, double* num)

    Get element at position i,j in p_array.

    INPUTS:

        ->      num:    Number to be placed.

        ->        i:    Row position.

        ->        j:    Column position.
        
        ->  p_array:    Address of the array.

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    num[0] = p_array->p_data[j+i*p_array->ncols];

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void c_darray_setItem( double num, uint64_t i, uint64_t j, darray_t* p_array){
    /*
    c_sotiarray_setItem( sotinum_t* num, uint64_t i, uint64_t j,sotiarray_t* p_array)

    Set an item at position i,j in p_array. To be called only when p_array has already been created
    and has some correct values in it.

    INPUTS:

        ->      num:    Number to be placed.

        ->        i:    Row position.

        ->        j:    Column position.
        
        ->  p_array:    Address of the array.

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    
    p_array->p_data[j+i*p_array->ncols] = num; 

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
int64_t c_darray_zeros(darray_t* p_array, uint64_t nrows, uint64_t ncols){
    /*
    c_sotiarray_createEmpty(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey)

    C-level memory allocation of a dense oti number a direction array from a file

    INPUTS:

        ->  p_array:    Address of the array to be allocated.

        ->   shapex:    Number of elements in the first  dimension.

        ->   shapey:    Number of elements in the second dimension.
        
        

    OUTPUTS:
        -> The result is the array with the memory allocated and initialized.
    */ 
    // ************************************************************************************************
    
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
void c_darray_free(darray_t* p_array){
    /*
    c_darray_free(sotiarray_t* p_array)
    
    Free all memory associated with the array.

    INPUTS:

        ->  p_array:    Address of the array to be freed.

    */ 
    // ************************************************************************************************
    
    // Free pointer 
    free( p_array->p_data);
    p_array->p_data = NULL;
    p_array->ncols  =    0;
    p_array->nrows  =    0;
    p_array->size   =    0;
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_darray_createEmpty(darray_t* p_array, uint64_t nrows, uint64_t ncols){
    /*
    c_darray_createEmpty(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey)

    C-level memory allocation of array.

    INPUTS:

        ->  p_array:    Address of the array to be allocated.

        ->   shapex:    Number of elements in the first  dimension.

        ->   shapey:    Number of elements in the second dimension.

        

    OUTPUTS:
        -> The result is the memory allocated.
    */ 
    // ************************************************************************************************
    
    
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
