
// ****************************************************************************************************
void oarrm1n30_taylor_integrate_to( coeff_t* deltas, oarrm1n30_t* arr, oarrm1n30_t* res){
    
    uint64_t i;

    oarrm1n30_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){
        
        onumm1n30_taylor_integrate_to( deltas, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_taylor_integrate( coeff_t* deltas, oarrm1n30_t* arr){
    
    oarrm1n30_t res;

    res = oarrm1n30_zeros( arr->nrows, arr->ncols);

    oarrm1n30_taylor_integrate_to( deltas, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_get_order_im_to( ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res){
    
    uint64_t i;

    oarrm1n30_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){
        
        onumm1n30_get_order_im_to( order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_get_order_im( ord_t order, oarrm1n30_t* arr){
    
    oarrm1n30_t res;

    res = oarrm1n30_zeros( arr->nrows, arr->ncols);

    oarrm1n30_get_order_im_to( order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_truncate_im_to( imdir_t idx, ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res){
    
    uint64_t i;

    oarrm1n30_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){
        
        onumm1n30_truncate_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_truncate_im( imdir_t idx, ord_t order, oarrm1n30_t* arr){
    
    oarrm1n30_t res;

    res = oarrm1n30_zeros( arr->nrows, arr->ncols);

    oarrm1n30_truncate_im_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// Copy operations.
// ****************************************************************************************************
void oarrm1n30_copy_to(oarrm1n30_t* arr, oarrm1n30_t* res){

    uint64_t i;
    // TODO: add allocation check.
    if(res->nrows != arr->nrows || res->ncols != arr->ncols || res->size != arr->size){
        printf("ERROR: Assignment mismatch in dimensions. Check destination.\n");
        exit(OTI_undetErr);
    } 

    for (i=0; i<arr->size; i++){

        onumm1n30_copy_to(&arr->p_data[i],&res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_copy(oarrm1n30_t* arr){

    oarrm1n30_t res = oarrm1n30_empty_like(arr);

    oarrm1n30_copy_to(arr,&res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// Setters.
// Setter by one index.

// ****************************************************************************************************
inline void oarrm1n30_set_all_r( coeff_t num, oarrm1n30_t* arr){
    
    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        oarrm1n30_set_item_i_r( num, i, arr);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm1n30_set_r( coeff_t num, oarrm1n30_t* arr){
    
    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        oarrm1n30_set_item_i_r( num, i, arr);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm1n30_set_item_i_r( coeff_t num, uint64_t i, oarrm1n30_t* arr){
        
    if( i<arr->size ){
        
        onumm1n30_set_r( num, &arr->p_data[i]);

    } else {

        // res = onumm1n30_init();
        
        printf("ERROR: Index out of bounds in oarrm1n30_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm1n30_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm1n30_t* arr){

    oarrm1n30_set_item_i_r( num, j + i*arr->ncols, arr);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm1n30_set_all_o( onumm1n30_t* num, oarrm1n30_t* arr){

    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        oarrm1n30_set_item_i_o( num, i, arr);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm1n30_set_o( onumm1n30_t* num, oarrm1n30_t* arr){

    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        oarrm1n30_set_item_i_o( num, i, arr);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm1n30_set_item_i_o( onumm1n30_t* src, uint64_t i, oarrm1n30_t* arr){
    
    if (i < arr->size){

        onumm1n30_copy_to(src, &arr->p_data[i]);

    }  else {
        
        printf("ERROR: Index out of bounds in oarrm1n30_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm1n30_set_item_ij_o( onumm1n30_t* num, uint64_t i, uint64_t j, oarrm1n30_t* arr){

    if ( i < arr->nrows && j < arr->ncols ){

        oarrm1n30_set_item_i_o( num, j + i*arr->ncols, arr);

    } else {

        printf("ERROR: Index out of bounds in oarrm1n30_get_item_ij(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_set_slice_O( oarrm1n30_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         oarrm1n30_t* res){

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

            onumm1n30_copy_to( &arr->p_data[  j +  i * arr->ncols ], 
                          &res->p_data[ jj + ii * res->ncols ]);

            jj += stepj;
        
        }   

        ii += stepi;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_set_slice_o( onumm1n30_t* num, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         oarrm1n30_t* res){

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

            onumm1n30_set_o( num, 
                       &res->p_data[ jj + ii * res->ncols ]);

            jj += stepj;
        
        }   

        ii += stepi;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_set_slice_r( coeff_t val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         oarrm1n30_t* res){

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

            onumm1n30_set_r( val, 
                        &res->p_data[ jj + ii * res->ncols ]);

            jj += stepj;
        
        }   

        ii += stepi;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_set_O( oarrm1n30_t* arrin, oarrm1n30_t* arr){

    oarrm1n30_copy_to( arrin, arr);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
darr_t oarrm1n30_get_im(imdir_t idx, ord_t order, oarrm1n30_t* arr){
    
    darr_t res = darr_zeros( arr->nrows, arr->ncols);
    uint64_t i;
    
    for( i = 0; i < arr->size ; i++ ){
        
        darr_set_item_i(  
            onumm1n30_get_item( idx, order, &arr->p_data[i]), 
            i, &res);

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_extract_im(imdir_t idx, ord_t order, oarrm1n30_t* arr){
    
    oarrm1n30_t res = oarrm1n30_zeros( arr->nrows, arr->ncols);
    
    oarrm1n30_extract_im_to( idx, order, arr, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_extract_im_to(imdir_t idx, ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res){
    
    uint64_t i;
    
    // Check first dimensions.
    oarrm1n30_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
                
        onumm1n30_extract_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
darr_t oarrm1n30_get_deriv(imdir_t idx, ord_t order, oarrm1n30_t* arr){
    
    darr_t res = darr_zeros( arr->nrows, arr->ncols);
    uint64_t i;
    
    for( i = 0; i < arr->size ; i++ ){
        
        darr_set_item_i(  
            onumm1n30_get_deriv( idx, order, &arr->p_data[i]), 
            i, &res);

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_get_im_o(imdir_t idx, ord_t order, oarrm1n30_t* arr){
    
    oarrm1n30_t res = oarrm1n30_zeros( arr->nrows, arr->ncols);
    
    oarrm1n30_get_im_to( idx, order, arr, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_get_im_to(imdir_t idx, ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res){
    
    uint64_t i;
    
    // Check first dimensions.
    oarrm1n30_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
        
        onumm1n30_get_im_to_o( idx, order, &arr->p_data[i], &res->p_data[i]);

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_get_deriv_o(imdir_t idx, ord_t order, oarrm1n30_t* arr){
    
    oarrm1n30_t res = oarrm1n30_zeros( arr->nrows, arr->ncols);
    
    oarrm1n30_get_deriv_to( idx, order, arr, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_get_deriv_to(imdir_t idx, ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res){
    
    uint64_t i;
    
    // Check first dimensions.
    oarrm1n30_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
        
        onumm1n30_get_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_extract_deriv(imdir_t idx, ord_t order, oarrm1n30_t* arr){
    
    oarrm1n30_t res = oarrm1n30_zeros( arr->nrows, arr->ncols);
    
    oarrm1n30_extract_deriv_to( idx, order, arr, &res);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_extract_deriv_to(imdir_t idx, ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res){
    
    uint64_t i;
    
    // Check first dimensions.
    oarrm1n30_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
                
        onumm1n30_extract_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }
    
}
// ----------------------------------------------------------------------------------------------------

// Getters.
// ****************************************************************************************************
inline onumm1n30_t oarrm1n30_get_item_i(oarrm1n30_t* arr, uint64_t i){
    
    onumm1n30_t res;

    // Check boundness
    if (i < arr->size){

        res = arr->p_data[i];
        
    } else {

        // res = onumm1n30_init();
        
        printf("ERROR: Index out of bounds in oarrm1n30_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n30_t oarrm1n30_get_item_ij(oarrm1n30_t* arr, uint64_t i, uint64_t j){

    onumm1n30_t res = oarrm1n30_get_item_i(arr, j + i*arr->ncols );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_get_item_i_to(oarrm1n30_t* arr, uint64_t i, onumm1n30_t* res){
    
    // Check boundness
    if (i < arr->size){

        onumm1n30_copy_to( &arr->p_data[i], res);
        
    } else {
        // Raise error?
        printf("ERROR: Index out of bounds in oarrm1n30_get_item_i_to(...)\n");
        exit(OTI_BadIndx);
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_get_item_ij_to(oarrm1n30_t* arr, uint64_t i, uint64_t j, onumm1n30_t* res){

    oarrm1n30_get_item_i_to(arr, j + i*arr->ncols, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_get_slice( oarrm1n30_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj){

    uint64_t ncols, nrows; // Resulting number of rows and columns
    oarrm1n30_t res = oarrm1n30_init();

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);
    
    res = oarrm1n30_zeros( nrows, ncols);

    oarrm1n30_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_get_slice_to( oarrm1n30_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         oarrm1n30_t* res){

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

            onumm1n30_copy_to( &arr->p_data[ jj + ii * arr->ncols ], 
                          &res->p_data[  j +  i * res->ncols ]);

            jj += stepj;
        
        }   

        ii += stepi;

    }

}
// ----------------------------------------------------------------------------------------------------

// Memory management.
// ****************************************************************************************************
oarrm1n30_t oarrm1n30_eye(uint64_t nrows){

    oarrm1n30_t  res;
    uint64_t i;

    res = oarrm1n30_zeros( nrows, nrows);
    
    for (i=0; i<res.nrows; i++ ){
        res.p_data[ i + i*res.ncols ].r = 1.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_ones(uint64_t nrows, uint64_t ncols){

    oarrm1n30_t  res;
    uint64_t i;
    
    res = oarrm1n30_createEmpty(nrows, ncols);

    for (i=0; i<res.size; i++ ){
        onumm1n30_set_r(1.0,&res.p_data[i]);
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n30_t oarrm1n30_zeros(uint64_t nrows, uint64_t ncols){
    
    oarrm1n30_t  res;
    uint64_t i;
    
    res = oarrm1n30_createEmpty(nrows, ncols);
    
    for (i=0; i<res.size; i++ ){
        onumm1n30_set_r(0.0,&res.p_data[i]);
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline oarrm1n30_t oarrm1n30_empty_like(oarrm1n30_t* arr){

    oarrm1n30_t  res;
    
    res = oarrm1n30_createEmpty(arr->nrows, arr->ncols);    

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline oarrm1n30_t oarrm1n30_createEmpty(uint64_t nrows, uint64_t ncols){

    oarrm1n30_t  res ;
    uint64_t size = nrows * ncols;

    res.p_data = (onumm1n30_t*) malloc( size * sizeof( onumm1n30_t ) );

    if ( res.p_data == NULL ){
        printf("ERROR: Not enough memory to handle oarrm1n30.\n Exiting...\n");
        exit(OTI_OutOfMemory);
    }

    res.ncols = ncols;
    res.nrows = nrows;
    res.size  = size;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm1n30_free(oarrm1n30_t* arr){

    if ( arr->p_data!= NULL ){
        free(arr->p_data);
    }

    (*arr) = oarrm1n30_init();

}
// ----------------------------------------------------------------------------------------------------

// Initialization
// ****************************************************************************************************
inline oarrm1n30_t oarrm1n30_init(void){

    oarrm1n30_t res;

    res.p_data = NULL;
    res.nrows = 0;
    res.ncols = 0;
    res.size  = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------