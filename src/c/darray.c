#include "oti/darray.h"


// ----------------------------------------------------------------------------------------------------
// ---------------------------------     DARRAY FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void darray_r_sub(darray_t* p_arr1, double num, darray_t* p_arrres){
    
    int64_t i;

    p_arrres->size = p_arr1->size;
    p_arrres->ncols = p_arr1->ncols;
    p_arrres->nrows = p_arr1->nrows;

    for (i = 0; i < p_arr1->size; i++){

        p_arrres->p_data[i] = - p_arr1->p_data[i] + num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darray_neg(darray_t* p_arr1, darray_t* p_arrres){
    
    int64_t i;

    p_arrres->size = p_arr1->size;
    p_arrres->ncols = p_arr1->ncols;
    p_arrres->nrows = p_arr1->nrows;

    for (i = 0; i < p_arr1->size; i++){

        p_arrres->p_data[i] = -p_arr1->p_data[i];
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darray_mul_r(darray_t* p_arr1, double num, darray_t* p_arrres){
    
    int64_t i;

    p_arrres->size = p_arr1->size;
    p_arrres->ncols = p_arr1->ncols;
    p_arrres->nrows = p_arr1->nrows;

    for (i = 0; i < p_arr1->size; i++){

        p_arrres->p_data[i] = p_arr1->p_data[i] * num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darray_sub_r(darray_t* p_arr1, double num, darray_t* p_arrres){
    
    int64_t i;

    p_arrres->size = p_arr1->size;
    p_arrres->ncols = p_arr1->ncols;
    p_arrres->nrows = p_arr1->nrows;

    for (i = 0; i < p_arr1->size; i++){

        p_arrres->p_data[i] = p_arr1->p_data[i] - num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darray_sum_r(darray_t* p_arr1, double num, darray_t* p_arrres){
    
    int64_t i;

    p_arrres->size = p_arr1->size;
    p_arrres->ncols = p_arr1->ncols;
    p_arrres->nrows = p_arr1->nrows;

    for (i = 0; i < p_arr1->size; i++){

        p_arrres->p_data[i] = p_arr1->p_data[i] + num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darray_div(darray_t* p_arr1, darray_t* p_arr2, darray_t* p_arrres){
    
    int64_t i;

    p_arrres->size = p_arr1->size;
    p_arrres->ncols = p_arr1->ncols;
    p_arrres->nrows = p_arr1->nrows;

    for (i = 0; i < p_arr1->size; i++){

        p_arrres->p_data[i] = p_arr1->p_data[i] / p_arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darray_mul(darray_t* p_arr1, darray_t* p_arr2, darray_t* p_arrres){
    
    int64_t i;

    p_arrres->size = p_arr1->size;
    p_arrres->ncols = p_arr1->ncols;
    p_arrres->nrows = p_arr1->nrows;

    for (i = 0; i < p_arr1->size; i++){

        p_arrres->p_data[i] = p_arr1->p_data[i] * p_arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darray_sub(darray_t* p_arr1, darray_t* p_arr2, darray_t* p_arrres){
    
    int64_t i;

    p_arrres->size = p_arr1->size;
    p_arrres->ncols = p_arr1->ncols;
    p_arrres->nrows = p_arr1->nrows;


    for (i = 0; i < p_arr1->size; i++){

        p_arrres->p_data[i] = p_arr1->p_data[i] - p_arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darray_sum(darray_t* p_arr1, darray_t* p_arr2, darray_t* p_arrres){
    
    int64_t i;

    p_arrres->size = p_arr1->size;
    p_arrres->ncols = p_arr1->ncols;
    p_arrres->nrows = p_arr1->nrows;

    for (i = 0; i < p_arr1->size; i++){

        p_arrres->p_data[i] = p_arr1->p_data[i] + p_arr2->p_data[i];

    }
    
}
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
int64_t darray_ones(darray_t* p_array, uint64_t nrows, uint64_t ncols){
    
    double value = 1.0;

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
