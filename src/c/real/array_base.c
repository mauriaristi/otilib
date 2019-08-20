


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
inline void darr_set_item_ij( coeff_t num, uint64_t i, uint64_t j, darr_t* arr){
    
    arr->p_data[j + i*arr->ncols] = num; 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darr_set_all( coeff_t num, darr_t* arr){
    
    uint64_t i;
    
    for (i=0; i<arr->size; i++){

        arr->p_data[i] = num;     

    }
    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darr_set_item_i( coeff_t num, uint64_t i, darr_t* arr){
    
    arr->p_data[i] = num; 

}
// ----------------------------------------------------------------------------------------------------

// Getters.

// ****************************************************************************************************
inline coeff_t darr_get_item_ij(darr_t* arr, uint64_t i, uint64_t j){
    
    return arr->p_data[j+i*arr->ncols];

}
// ----------------------------------------------------------------------------------------------------
// ****************************************************************************************************
inline coeff_t darr_get_item_i(darr_t* arr, uint64_t i){
    
    return arr->p_data[i];

}
// ----------------------------------------------------------------------------------------------------



// Copy operations.
// ****************************************************************************************************
darr_t darr_copy(darr_t* src ){
	
	darr_t dst = darr_createEmpty( src->nrows, src->ncols);

	memcpy( dst.p_data, src->p_data, src->size * sizeof(coeff_t) );

	return dst;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_copy_to(darr_t* src, darr_t* dst ){
	
	// Must come allocated. and have the same dimensions.

	memcpy( dst->p_data, src->p_data, src->size * sizeof(coeff_t) );

}
// ----------------------------------------------------------------------------------------------------






// Helpers.

// ****************************************************************************************************
inline uint64_t darr_getSize(darr_t* arr){
    
    return arr->ncols * arr->nrows;

}
// ----------------------------------------------------------------------------------------------------








// Memory management.

// ****************************************************************************************************
darr_t darr_zeros( uint64_t nrows, uint64_t ncols){
    
    darr_t arr;
    coeff_t value = 0.0;

    arr.ncols  = ncols       ;
    arr.nrows  = nrows       ;
    arr.size   = ncols*nrows ;
    arr.p_data = (coeff_t*) malloc( arr.size * sizeof(coeff_t) );

    if (arr.p_data == NULL){

    	printf("ERROR: OUT of memory. Exiting.\n");
        exit(OTI_OutOfMemory);

    }

    // Set 0 to all elements.
    memset(arr.p_data, value, arr.size*sizeof(coeff_t)  );

    return arr;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
darr_t darr_eye( uint64_t size){
    
    darr_t arr = darr_zeros( size, size);
    coeff_t value = 1.0;

    

    // Set 0 to all elements.
    for (uint64_t i = 0; i<size; i++){

        arr.p_data[ i + size*i ] = value;   
        
    }

    return arr;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
darr_t darr_ones( uint64_t nrows, uint64_t ncols){
    
    darr_t arr;
    coeff_t value = 1.0;

    arr.ncols  = ncols       ;
    arr.nrows  = nrows       ;
    arr.size   = ncols*nrows ;
    arr.p_data = (coeff_t*) malloc( arr.size * sizeof(coeff_t) );

    if (arr.p_data == NULL){

        printf("ERROR: OUT of memory. Exiting.\n");
        exit(OTI_OutOfMemory);

    }

    // Set 0 to all elements.
    for (uint64_t i=0; i<arr.size; i++){

        arr.p_data[i] = value;   
        
    }

    return arr;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_free(darr_t* arr){
    
    // Free pointer 
    if (arr->p_data != NULL){
        free( arr->p_data);    
    }

    arr->p_data = NULL;
    arr->ncols  =    0;
    arr->nrows  =    0;
    arr->size   =    0;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
darr_t darr_createEmpty(uint64_t nrows, uint64_t ncols){
    
    darr_t arr;

    arr.ncols  = ncols;
    arr.nrows  = nrows;
    arr.size   = ncols*nrows;
    arr.p_data = (coeff_t*) malloc( arr.size * sizeof(coeff_t) );
        
    if (arr.p_data == NULL){

    	printf("ERROR: OUT of memory. Exiting.\n");
        exit(OTI_OutOfMemory);
        
    }

    return arr;

}

// ----------------------------------------------------------------------------------------------------