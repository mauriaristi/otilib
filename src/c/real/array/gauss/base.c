// typedef struct{
//     darr_t*      p_data; ///< Data array
//     uint64_t      nrows;  ///< Number of rows.
//     uint64_t      ncols;  ///< Number of cols.
//     uint64_t       size;  ///< size of the array
//     uint64_t    nip;  ///< Number of integration points.
// } fedarr_t;






















// ****************************************************************************************************
void fedarr_copy_to(fedarr_t* src, fedarr_t* dst){

    uint64_t i;

    // check memory;
    fedarr_dimCheck_FF_elementwise(src, dst, dst);

    for( i = 0; i < src->nip; i++){

        darr_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_copy(fedarr_t* src){

    fedarr_t res = fedarr_createEmpty( src->nrows, src->ncols, src->nip );
    
    fedarr_copy_to( src, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
darr_t fedarr_get_item_k(fedarr_t* arr, uint64_t k){
    
    darr_t res;
    // TODO: Add bound checks.
    
    res = darr_zeros( arr->nrows, arr->ncols );

    fedarr_get_item_k_to(arr, k, &res);

    return res;    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fednum_t fedarr_get_item_ij(fedarr_t* arr, uint64_t i, uint64_t j){
        
    fednum_t res = fednum_init();
    // TODO: Add bound checks.
    
    res = fednum_zeros( arr->nip );

    fedarr_get_item_ij_to( arr, i, j, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
coeff_t fedarr_get_item_ijk(fedarr_t* arr, uint64_t i, uint64_t j, uint64_t k){
    
    coeff_t res;
    
    // Check dimensions.
    res = darr_get_item_ij( &arr->p_data[k], i, j );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_get_slice(fedarr_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj){
    
    int64_t ncols, nrows;
    fedarr_t res = fedarr_init();

    // TODO: Add bound checks.
    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);

    res = fedarr_zeros( nrows, ncols, arr->nip );

    fedarr_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------







// ****************************************************************************************************
void fedarr_get_item_k_to(fedarr_t* arr, uint64_t k, darr_t* res){
    
    // TODO: Add bound checks.

    darr_copy_to( &arr->p_data[k], res );

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_get_item_ij_to(fedarr_t* arr, uint64_t i, uint64_t j, fednum_t* res){
        
    uint64_t k;
    
    fedarr_dimCheck_fF_elementwise(res,arr,arr);

    for (k = 0; k < arr->nip; k++){
        
        darr_get_item_ij_to( &arr->p_data[k], i, j, &res->p_data[k] );
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_get_item_ijk_to(fedarr_t* arr, uint64_t i, uint64_t j, uint64_t k, coeff_t* res){
    
    // TODO: Add bound checks.
    if ( k < arr->nip && i < arr->nrows && j < arr->ncols){

        darr_get_item_ij_to( &arr->p_data[k], i, j, res );

    } else {

        printf("Error: Bad index \n");
        exit(OTI_BadIndx);
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fedarr_get_slice_to(fedarr_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fedarr_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols != ncols) || (res->nrows != nrows) || (res->nip != arr->nip)){

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }

    for (k = 0; k < arr->nip; k++){
        
        darr_get_slice_to( &arr->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------










// ****************************************************************************************************
void fedarr_set_slice_r( coeff_t val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fedarr_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols < ncols) || (res->nrows < nrows) ){

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }

    for (k = 0; k < res->nip; k++){
        
        darr_set_slice_r( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k] );
    
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fedarr_set_slice_f( fednum_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fedarr_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->nip != val->nip) ){

        printf("ERROR: Wrong number of integration points.\n");
        exit(OTI_BadIndx);

    }

    for (k = 0; k < res->nip; k++){
        
        darr_set_slice_r( val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_set_slice_R(  darr_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fedarr_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){
        
        darr_set_slice_R( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fedarr_set_slice_F( fedarr_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fedarr_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->nip != val->nip) ){

        printf("ERROR: Wrong number of integration points.\n");
        exit(OTI_BadIndx);

    }

    for (k = 0; k < res->nip; k++){
        
        darr_set_slice_R( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_set_item_k( darr_t* arr , uint64_t k, fedarr_t* res){
    
    // No new allocation needed.
    darr_copy_to( arr, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------


// // ****************************************************************************************************
// void fedarr_set_item_ij(fednum_t* num, uint64_t i, uint64_t j, fedarr_t* res){
    
//     uint64_t k;

//     //Check
//     fedarr_dimCheck_fF_elementwise(num,res,res);

//     for (k = 0; k < num->nip; k++){
        
//         darr_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k] );

//     }

// }
// // ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fedarr_set_item_ij_f(fednum_t* num, uint64_t i, uint64_t j, fedarr_t* res){
    
    uint64_t k;

    //Check
    fedarr_dimCheck_fF_elementwise(num,res,res);

    for (k = 0; k < num->nip; k++){
        
        darr_set_item_ij_r( num->p_data[k], i, j, &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fedarr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, fedarr_t* res){
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){
        
        darr_set_item_ij_r( num, i, j, &res->p_data[k] );

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fedarr_set_item_ijk_r(coeff_t num, uint64_t i, uint64_t j, uint64_t k, fedarr_t* res){

    if ( k < res->nip ){

        darr_set_item_ij_r( num, i, j, &res->p_data[k]);

    } else {

        printf("ERROR: Integration point Index.\n");
        exit(OTI_BadIndx);

    }

}
// ----------------------------------------------------------------------------------------------------





























// ****************************************************************************************************
void fedarr_set_f( fednum_t* num, fedarr_t* res ){ 
    
    uint64_t i;
    
    fedarr_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        darr_set_all_r( num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_set_R( darr_t* arr, fedarr_t* res ){ 
    
    uint64_t k;
    
    for( k = 0; k < res->nip; k++){

        darr_copy_to( arr, &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_set_F( fedarr_t* num, fedarr_t* res ){ 
    
    fedarr_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_set_r( coeff_t num, fedarr_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        darr_set_all_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void fedarr_set_all_f( fednum_t* num, fedarr_t* res ){ 
    
    uint64_t i;
    
    fedarr_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        darr_set_all_r( num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_set_all_r( coeff_t num, fedarr_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        darr_set_all_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fedarr_t fedarr_eye( uint64_t size, uint64_t nip ){ 
    
    uint64_t i,k;

    fedarr_t res = fedarr_zeros( size, size, nip);
    
    for( i = 0; i < res.nrows; i++){
    
        for( k = 0; k < res.nip; k++){

            darr_set_item_ij_r( 1.0, i, i, &res.p_data[k]);

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fedarr_t fedarr_zeros( uint64_t nrows, uint64_t ncols, uint64_t nip ){ 
    
    uint64_t i;

    fedarr_t res = fedarr_createEmpty( nrows, ncols, nip);
    
    for( i = 0; i < res.nip; i++){

        darr_set_all_r( 0.0, &res.p_data[i]);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fedarr_t fedarr_ones( uint64_t nrows, uint64_t ncols, uint64_t nip ){ 
    
    uint64_t i;

    fedarr_t res = fedarr_createEmpty( nrows, ncols, nip );
    
    for( i = 0; i < res.nip; i++){

        darr_set_all_r( 1.0, &res.p_data[i]);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fedarr_t fedarr_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t nip ){  
    
    uint64_t i;

    fedarr_t res = fedarr_init();

    res.nrows    =  nrows;
    res.ncols    =  ncols;
    res.size     =  nrows*ncols;
    
    res.nip  =  nip;

    // Allocate memory.
    res.p_data   = (darr_t*) malloc( res.nip * sizeof(darr_t) );

    if (res.p_data == NULL){
        printf("ERROR: Not enough memory to create fedarr object.\nExiting...\n");
        exit(OTI_OutOfMemory);
    }

    for( i = 0; i < res.nip; i++){

        res.p_data[i] = darr_createEmpty( nrows, ncols );

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_free(fedarr_t* arr){
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (arr->p_data != NULL){

        // Free all arrays.
        for (i = 0; i<arr->nip; i++){
        
            darr_free(&arr->p_data[i]); 

        }

        // Free pointer 
        free(arr->p_data);

    }

    *arr = fedarr_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_init(void){
    
    fedarr_t res;
    
    res.p_data  = NULL;  
    res.nrows   = 0;   
    res.ncols   = 0;   
    res.size    = 0;    
    res.nip = 0; 

    return res;

}
// ----------------------------------------------------------------------------------------------------

