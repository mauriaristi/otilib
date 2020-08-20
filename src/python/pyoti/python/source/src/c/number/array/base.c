

// typedef struct {
//     sotinum_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
// } arrso_t;                ///< Array of OTIs type.


// ****************************************************************************************************
void arrso_taylor_integrate_to( coeff_t* deltas, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;

    arrso_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){
        
        soti_taylor_integrate_to( deltas, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_taylor_integrate( coeff_t* deltas, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res;

    res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_taylor_integrate_to( deltas, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void arrso_get_order_im_to( ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;

    arrso_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){
        
        soti_get_order_im_to( order, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_get_order_im( ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res;

    res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_get_order_im_to( order, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void arrso_truncate_im_to( imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;

    arrso_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){
        
        soti_truncate_im_to( idx, order, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_truncate_im( imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res;

    res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_truncate_im_to( idx, order, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------





// Copy operations.
// ****************************************************************************************************
void arrso_copy_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    uint64_t i;
    // TODO: add allocation check.
    if(res->nrows != arr->nrows || res->ncols != arr->ncols || res->size != arr->size){
        printf("ERROR: Assignment mismatch in dimensions. Check destination.\n");
        exit(OTI_undetErr);
    } 

    for (i=0; i<arr->size; i++){

        soti_copy_to(&arr->p_data[i],&res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_copy(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_empty_like(arr,dhl);

    arrso_copy_to(arr,&res,dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------








// Setters.
// Setter by one index.

// ****************************************************************************************************
inline void arrso_set_all_r( coeff_t num, arrso_t* arr, dhelpl_t dhl){
    
    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        arrso_set_item_i_r( num, i, arr, dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_r( coeff_t num, arrso_t* arr, dhelpl_t dhl){
    
    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        arrso_set_item_i_r( num, i, arr, dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_item_i_r( coeff_t num, uint64_t i, arrso_t* arr, dhelpl_t dhl){
        
    if( i<arr->size ){
        
        soti_set_r( num, &arr->p_data[i], dhl);

    } else {

        // res = soti_init();
        
        printf("ERROR: Index out of bounds in arrso_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl){

    arrso_set_item_i_r( num, j + i*arr->ncols, arr,  dhl);

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
inline void arrso_set_all_o( sotinum_t* num, arrso_t* arr, dhelpl_t dhl){

    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        arrso_set_item_i_o( num, i, arr, dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_o( sotinum_t* num, arrso_t* arr, dhelpl_t dhl){

    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        arrso_set_item_i_o( num, i, arr, dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_item_i_o( sotinum_t* src, uint64_t i, arrso_t* arr, dhelpl_t dhl){
    
    if (i < arr->size){

        soti_copy_to(src, &arr->p_data[i],dhl);

    }  else {
        
        printf("ERROR: Index out of bounds in arrso_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_item_ij_o( sotinum_t* num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl){

    if ( i < arr->nrows && j < arr->ncols ){

        arrso_set_item_i_o( num, j + i*arr->ncols, arr, dhl);

    } else {

        printf("ERROR: Index out of bounds in arrso_get_item_ij(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_set_slice_O( arrso_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrso_t* res, dhelpl_t dhl){

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // printf("nrows: %lld, ncols %lld \n",nrows, ncols);

    // printf("i: (%lld, %lld, %lld) \n", starti, stopi, stepi);
    // printf("j: (%lld, %lld, %lld) \n", startj, stopj, stepj);

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

            // printf("Setting result ( i, j) (%lld,%lld) from source (ii,jj) (%lld,%lld) \n", i, j, ii, jj);
            // printf("( i, j) (%lld,%lld) equates: %lld\n",  i,  j,  j +  i * res->ncols );
            // printf("(ii,jj) (%lld,%lld) equates: %lld\n", ii, jj, jj + ii * arr->ncols );

            soti_copy_to( &arr->p_data[  j +  i * arr->ncols ], 
                          &res->p_data[ jj + ii * res->ncols ], 
                          dhl);

            jj += stepj;
        
        }   

        ii += stepi;

    }



}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_set_slice_o( sotinum_t* num, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrso_t* res, dhelpl_t dhl){

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?
    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

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

            soti_set_o( num, 
                       &res->p_data[ jj + ii * res->ncols ],  
                        dhl);

            jj += stepj;
        
        }   

        ii += stepi;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_set_slice_r( coeff_t val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrso_t* res, dhelpl_t dhl){

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // printf("nrows: %lld, ncols %lld \n",nrows, ncols);

    // printf("i: (%lld, %lld, %lld) \n", starti, stopi, stepi);
    // printf("j: (%lld, %lld, %lld) \n", startj, stopj, stepj);


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

            // printf("Setting result ( i, j) (%lld,%lld) from source (ii,jj) (%lld,%lld) \n", i, j, ii, jj);
            // printf("( i, j) (%lld,%lld) equates: %lld\n",  i,  j,  j +  i * res->ncols );
            // printf("(ii,jj) (%lld,%lld) equates: %lld\n", ii, jj, jj + ii * arr->ncols );

            soti_set_r( val, 
                        &res->p_data[ jj + ii * res->ncols ],  
                        dhl);

            jj += stepj;
        
        }   

        ii += stepi;

    }



}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_set_O( arrso_t* arrin, arrso_t* arr, dhelpl_t dhl){

    arrso_copy_to( arrin, arr, dhl);

}
// ----------------------------------------------------------------------------------------------------














































// ****************************************************************************************************
darr_t arrso_get_im(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    darr_t res = darr_zeros( arr->nrows, arr->ncols);
    uint64_t i;
    
    for( i = 0; i < arr->size ; i++ ){
        
        darr_set_item_i(  
            soti_get_item( idx, order, &arr->p_data[i],  dhl), 
            i, &res);

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
arrso_t arrso_extract_im(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_extract_im_to( idx, order, arr, &res, dhl);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_extract_im_to(imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check first dimensions.
    arrso_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
                
        soti_extract_im_to( idx, order, &arr->p_data[i], &res->p_data[i],  dhl);

    }
    
}
// ----------------------------------------------------------------------------------------------------










// ****************************************************************************************************
darr_t arrso_get_deriv(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    darr_t res = darr_zeros( arr->nrows, arr->ncols);
    uint64_t i;
    
    for( i = 0; i < arr->size ; i++ ){
        
        darr_set_item_i(  
            soti_get_deriv( idx, order, &arr->p_data[i],  dhl), 
            i, &res);

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------









// ****************************************************************************************************
arrso_t arrso_get_im_o(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_get_im_to( idx, order, arr, &res, dhl);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_get_im_to(imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check first dimensions.
    arrso_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
        
        soti_get_im_to_o( idx, order, &arr->p_data[i], &res->p_data[i],  dhl);

    }
    
}
// ----------------------------------------------------------------------------------------------------
















// ****************************************************************************************************
arrso_t arrso_get_deriv_o(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_get_deriv_to( idx, order, arr, &res, dhl);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_get_deriv_to(imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check first dimensions.
    arrso_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
        
        soti_get_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i],  dhl);

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_extract_deriv(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_extract_deriv_to( idx, order, arr, &res, dhl);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_extract_deriv_to(imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check first dimensions.
    arrso_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
                
        soti_extract_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i],  dhl);

    }
    
}
// ----------------------------------------------------------------------------------------------------



















// Getters.
// ****************************************************************************************************
inline sotinum_t arrso_get_item_i(arrso_t* arr, uint64_t i, dhelpl_t dhl){
    
    sotinum_t res;

    // Check boundness
    if (i < arr->size){

        res = arr->p_data[i];
        
    } else {

        // res = soti_init();
        
        printf("ERROR: Index out of bounds in arrso_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t arrso_get_item_ij(arrso_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl){

    sotinum_t res = arrso_get_item_i(arr, j + i*arr->ncols, dhl );

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_get_item_i_to(arrso_t* arr, uint64_t i, sotinum_t* res, dhelpl_t dhl){
    
    // Check boundness
    if (i < arr->size){

        soti_copy_to( &arr->p_data[i], res, dhl);
        
    } else {
        // Raise error?
        printf("ERROR: Index out of bounds in arrso_get_item_i_to(...)\n");
        exit(OTI_BadIndx);
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_get_item_ij_to(arrso_t* arr, uint64_t i, uint64_t j, sotinum_t* res, dhelpl_t dhl){

    arrso_get_item_i_to(arr, j + i*arr->ncols, res, dhl);

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
arrso_t arrso_get_slice( arrso_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj, dhelpl_t dhl){

    uint64_t ncols, nrows; // Resulting number of rows and columns
    arrso_t res = arrso_init();

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);
    
    res = arrso_zeros_bases( nrows, ncols, 0, 0, dhl);

    arrso_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_get_slice_to( arrso_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrso_t* res, dhelpl_t dhl){

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols != ncols) || (res->nrows != nrows) ){

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){

        jj = startj;
        
        for ( j = 0; j < ncols; j++){

            // printf("Setting result ( i, j) (%lld,%lld) from source (ii,jj) (%lld,%lld) \n", i, j, ii, jj);
            // printf("( i, j) (%lld,%lld) equates: %lld\n",  i,  j,  j +  i * res->ncols );
            // printf("(ii,jj) (%lld,%lld) equates: %lld\n", ii, jj, jj + ii * arr->ncols );

            soti_copy_to( &arr->p_data[ jj + ii * arr->ncols ], 
                          &res->p_data[  j +  i * res->ncols ], dhl);

            jj += stepj;
        
        }   

        ii += stepi;

    }

}
// ----------------------------------------------------------------------------------------------------
























// Memory management.


// ****************************************************************************************************
arrso_t arrso_eye_bases(uint64_t nrows, bases_t nbases, ord_t order, dhelpl_t dhl){

    arrso_t  res;
    uint64_t i;

    res = arrso_zeros_bases( nrows, nrows, nbases, order, dhl);
    
    for (i=0; i<res.nrows; i++ ){
        res.p_data[ i + i*res.ncols ].<<<real_str>>> = 1.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_ones_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl){

    arrso_t  res;
    uint64_t i;
    
    res = arrso_createEmpty_bases(nrows, ncols, nbases, order, dhl);

    for (i=0; i<res.size; i++ ){
        soti_set_r(1.0,&res.p_data[i]);
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_zeros_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl){
    
    arrso_t  res;
    uint64_t i;
    
    res = arrso_createEmpty_bases(nrows, ncols, nbases, order, dhl);
    
    for (i=0; i<res.size; i++ ){
        soti_set_r(0.0,&res.p_data[i]);
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------








// ****************************************************************************************************
inline arrso_t arrso_empty_like(arrso_t* arr, dhelpl_t dhl){

    arrso_t  res;
    
    res = arrso_createEmpty_predef(arr->nrows, arr->ncols, dhl);    

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline arrso_t arrso_createEmpty_bases(uint64_t nrows, uint64_t ncols, dhelpl_t dhl){

    arrso_t  res ;
    uint64_t size = nrows * ncols;

    res.p_data = (sotinum_t*) malloc( size * sizeof( sotinum_t ) );

    if ( res.p_data == NULL ){
        printf("ERROR: Not enough memory to handle arrso.\n Exiting...\n");
        exit(OTI_OutOfMemory);
    }

    res.ncols = ncols;
    res.nrows = nrows;
    res.size  = size;

    return res;

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void arrso_free(arrso_t* arr){

    if ( (arr->flag != 0) && (arr->p_data!= NULL) ){
        
        free(arr->p_data);

    }

    (*arr) = arrso_init();

}
// ----------------------------------------------------------------------------------------------------





// Initialization
// ****************************************************************************************************
inline arrso_t arrso_init(void){

    arrso_t res;

    res.p_data = NULL;
    res.nrows = 0;
    res.ncols = 0;
    res.size  = 0;
    res.flag  = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------