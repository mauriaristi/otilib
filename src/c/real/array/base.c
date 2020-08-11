






// Setters.



// ****************************************************************************************************
void darr_set_slice_R( darr_t* arr, int64_t starti, int64_t stopi, int64_t stepi,
                       int64_t startj, int64_t stopj, int64_t stepj, darr_t* res){

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?

    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (arr->ncols != ncols) ||
         (arr->nrows != nrows)    ){

        printf("ERROR: Wrong dimensions for input array.\n");
        exit(OTI_BadIndx);

    }
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){

        jj = startj;
        
        for ( j = 0; j < ncols; j++){

            res->p_data[ jj + ii * res->ncols ] = arr->p_data[  j +  i * arr->ncols ];

            jj += stepj;
        
        }   

        ii += stepi;

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void darr_set_slice_r( coeff_t val, int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,darr_t* res   ){

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?

    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols < ncols) ||
         (res->nrows < nrows)    ){

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){

        jj = startj;
        
        for ( j = 0; j < ncols; j++){

            res->p_data[ jj + ii * res->ncols ] = val;

            jj += stepj;
        
        }   

        ii += stepi;

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
inline void darr_set_item_ij( coeff_t num, uint64_t i, uint64_t j, darr_t* arr){
    
    if ( (i < arr-> nrows) && (j < arr->ncols) ){

        arr->p_data[j + i*arr->ncols] = num;

    } else {

        printf("ERROR: Index out of bounds\n");
        exit(OTI_BadDim);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, darr_t* arr){
    
    if ( (i < arr-> nrows) && (j < arr->ncols) ){

        arr->p_data[j + i*arr->ncols] = num;

    } else {

        printf("ERROR: Index out of bounds\n");
        exit(OTI_BadDim);

    }

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
inline void darr_set_all_r( coeff_t num, darr_t* arr){
    
    uint64_t i;
    
    for (i=0; i<arr->size; i++){

        arr->p_data[i] = num;     

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darr_set_item_i( coeff_t num, uint64_t i, darr_t* arr){
    
    if ( i < arr-> size ){

        arr->p_data[i] = num;

    } else {

        printf("ERROR: Index out of bounds\n");
        exit(OTI_BadDim);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darr_set_item_i_r( coeff_t num, uint64_t i, darr_t* arr){
    
    if ( i < arr-> size ){

        arr->p_data[i] = num;

    } else {

        printf("ERROR: Index out of bounds\n");
        exit(OTI_BadDim);

    }

}
// ----------------------------------------------------------------------------------------------------


// Getters.

// ****************************************************************************************************
inline coeff_t darr_get_item_ij(darr_t* arr, uint64_t i, uint64_t j){
    
    coeff_t res;

    if ( (i < arr-> nrows) && (j < arr->ncols) ){

        res = arr->p_data[j+i*arr->ncols];

    } else {

        printf("ERROR: Index out of bounds\n");
        exit(OTI_BadDim);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void darr_get_item_ij_to(darr_t* arr, uint64_t i, uint64_t j, coeff_t* res ){

    if ( (i < arr-> nrows) && (j < arr->ncols) ){

        (*res) = arr->p_data[j+i*arr->ncols];

    } else {

        printf("ERROR: Index out of bounds\n");
        exit(OTI_BadDim);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darr_get_item_i_to(darr_t* arr, uint64_t i, coeff_t* res ){

    if ( i < arr-> size ){

        (*res) =  arr->p_data[i];

    } else {

        printf("ERROR: Index out of bounds\n");
        exit(OTI_BadDim);

    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline coeff_t darr_get_item_i(darr_t* arr, uint64_t i){
    
    coeff_t res;

    if ( i < arr-> size ){

        res =  arr->p_data[i];

    } else {

        printf("ERROR: Index out of bounds\n");
        exit(OTI_BadDim);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------














// ****************************************************************************************************
darr_t darr_get_slice(  darr_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj  ){

    uint64_t ncols, nrows; // Resulting number of rows and columns
    darr_t res = darr_init();

    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);
    
    res = darr_zeros( nrows, ncols);

    darr_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darr_get_slice_to( darr_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         darr_t* res){

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?

    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols != ncols) || (res->nrows != nrows) ){

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){

        jj = startj;
        
        for ( j = 0; j < ncols; j++){

            res->p_data[  j +  i * res->ncols ] = arr->p_data[ jj + ii * arr->ncols ];

            jj += stepj;
        
        }   

        ii += stepi;

    }

}
// ----------------------------------------------------------------------------------------------------































// Copy operations.
// ****************************************************************************************************
darr_t darr_copy( darr_t* src ){
	
	darr_t dst = darr_createEmpty( src->nrows, src->ncols );

	memcpy( dst.p_data, src->p_data, src->size * sizeof(coeff_t) );

	return dst;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_copy_to( darr_t* src, darr_t* dst ){
	
	// Must come allocated. and have the same dimensions.
    darr_dimCheck_RR_elementwise( src, dst, dst);

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
darr_t darr_init( void ){
    
    darr_t arr;
    
    arr.ncols  = 0 ;
    arr.nrows  = 0 ;
    arr.size   = 0 ;
    
    arr.p_data = NULL;

    return arr;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
darr_t darr_zeros( uint64_t nrows, uint64_t ncols){
    
    darr_t arr = darr_createEmpty( nrows, ncols);
    coeff_t value = 0.0;

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
    
    darr_t arr = darr_createEmpty( nrows, ncols);
    coeff_t value = 1.0;

    // Set 0 to all elements.
    for (uint64_t i = 0; i<arr.size; i++){

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