


// void darr_setItem( coeff_t num, uint64_t i, uint64_t j, darr_t* arr);
// coeff_t darr_getItem(darr_t* arr, uint64_t i, uint64_t j);
// darr_t darr_copy(darr_t* src );
// void darr_copy_to(darr_t* src, darr_t* dst );
// uint64_t darr_getSize(darr_t* arr);
// void darr_zeros(darr_t* arr, uint64_t nrows, uint64_t ncols);
// void darr_ones(darr_t* arr, uint64_t nrows, uint64_t ncols);
// void darr_free(darr_t* arr);
// void darr_createEmpty(darr_t* arr, uint64_t nrows, uint64_t ncols);























// Setters.

// ****************************************************************************************************
inline void darr_setItem( coeff_t num, uint64_t i, uint64_t j, darr_t* arr){
    
    arr->p_data[j + i*arr->ncols] = num; 

}
// ----------------------------------------------------------------------------------------------------



// Getters.

// ****************************************************************************************************
inline coeff_t darr_getItem(darr_t* arr, uint64_t i, uint64_t j){
    
    return arr->p_data[j+i*arr->ncols];

}
// ----------------------------------------------------------------------------------------------------


// Copy operations.
darr_t darr_copy(darr_t* src ){
	
	darr_t dst;

	darr_createEmpty( &dst, src->nrows, src->ncols);

	memcpy( dst.p_data, src->p_data, src->size * sizeof(coeff_t) );

	return dst;

}

void darr_copy_to(darr_t* src, darr_t* dst ){
	
	// Must come allocated. and have the same dimensions.

	memcpy( dst->p_data, src->p_data, src->size * sizeof(coeff_t) );

}






// Helpers.

// ****************************************************************************************************
inline uint64_t darr_getSize(darr_t* arr){
    
    return arr->ncols * arr->nrows;

}
// ----------------------------------------------------------------------------------------------------








// Memory management.

// ****************************************************************************************************
void darr_zeros(darr_t* arr, uint64_t nrows, uint64_t ncols){
    
    coeff_t value = 0.0;

    arr->ncols  = ncols       ;
    arr->nrows  = nrows       ;
    arr->size   = ncols*nrows ;
    arr->p_data = (coeff_t*) malloc( arr->size * sizeof(coeff_t) );

    if (arr->p_data == NULL){

    	printf("ERROR: OUT of memory. Exiting.\n");
        exit(OTI_OutOfMemory);

    }

    // Set 0 to all elements.
    memset(arr->p_data, value, arr->size*sizeof(coeff_t)  );

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darr_ones(darr_t* arr, uint64_t nrows, uint64_t ncols){
    
    coeff_t value = 1.0;

    arr->ncols  = ncols       ;
    arr->nrows  = nrows       ;
    arr->size   = ncols*nrows ;
    arr->p_data = (coeff_t*) malloc( arr->size * sizeof(coeff_t) );

    if (arr->p_data == NULL){

        printf("ERROR: OUT of memory. Exiting.\n");
        exit(OTI_OutOfMemory);

    }

    // Set 0 to all elements.
    memset(arr->p_data, value, arr->size*sizeof(coeff_t)  );

    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_free(darr_t* arr){
    
    // Free pointer 
    free( arr->p_data);
    arr->p_data = NULL;
    arr->ncols  =    0;
    arr->nrows  =    0;
    arr->size   =    0;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_createEmpty(darr_t* arr, uint64_t nrows, uint64_t ncols){
    
    arr->ncols  = ncols;
    arr->nrows  = nrows;
    arr->size   = ncols*nrows;
    arr->p_data = (coeff_t*) malloc( ncols*nrows * sizeof(coeff_t) );
        
    if (arr->p_data == NULL){

    	printf("ERROR: OUT of memory. Exiting.\n");
        exit(OTI_OutOfMemory);
        
    }

}
// ----------------------------------------------------------------------------------------------------