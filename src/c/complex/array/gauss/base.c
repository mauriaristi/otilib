// typedef struct{
//     carr_t*      p_data; ///< Data array
//     uint64_t      nrows;  ///< Number of rows.
//     uint64_t      ncols;  ///< Number of cols.
//     uint64_t       size;  ///< size of the array
//     uint64_t    nip;  ///< Number of integration points.
// } fecarr_t;






















// ****************************************************************************************************
void fecarr_copy_to(fecarr_t* src, fecarr_t* dst){

    uint64_t i;

    // check memory;
    fecarr_dimCheck_FF_elementwise(src, dst, dst);

    for( i = 0; i < src->nip; i++){

        carr_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_copy(fecarr_t* src){

    fecarr_t res = fecarr_createEmpty( src->nrows, src->ncols, src->nip );
    
    fecarr_copy_to( src, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
carr_t fecarr_get_item_k(fecarr_t* arr, uint64_t k){
    
    carr_t res;
    // TODO: Add bound checks.
    
    res = carr_zeros( arr->nrows, arr->ncols );

    fecarr_get_item_k_to(arr, k, &res);

    return res;    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fednum_t fecarr_get_item_ij(fecarr_t* arr, uint64_t i, uint64_t j){
        
    fednum_t res = fednum_init();
    // TODO: Add bound checks.
    
    res = fednum_zeros( arr->nip );

    fecarr_get_item_ij_to( arr, i, j, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
coeff_t fecarr_get_item_ijk(fecarr_t* arr, uint64_t i, uint64_t j, uint64_t k){
    
    coeff_t res;
    
    // Check dimensions.
    res = carr_get_item_ij( &arr->p_data[k], i, j );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_get_slice(fecarr_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj){
    
    int64_t ncols, nrows;
    fecarr_t res = fecarr_init();

    // TODO: Add bound checks.
    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);

    res = fecarr_zeros( nrows, ncols, arr->nip );

    fecarr_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------







// ****************************************************************************************************
void fecarr_get_item_k_to(fecarr_t* arr, uint64_t k, carr_t* res){
    
    // TODO: Add bound checks.

    carr_copy_to( &arr->p_data[k], res );

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_get_item_ij_to(fecarr_t* arr, uint64_t i, uint64_t j, fednum_t* res){
        
    uint64_t k;
    
    fecarr_dimCheck_fF_elementwise(res,arr,arr);

    for (k = 0; k < arr->nip; k++){
        
        carr_get_item_ij_to( &arr->p_data[k], i, j, &res->p_data[k] );
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_get_item_ijk_to(fecarr_t* arr, uint64_t i, uint64_t j, uint64_t k, coeff_t* res){
    
    // TODO: Add bound checks.
    if ( k < arr->nip && i < arr->nrows && j < arr->ncols){

        carr_get_item_ij_to( &arr->p_data[k], i, j, res );

    } else {

        printf("Error: Bad index \n");
        exit(OTI_BadIndx);
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fecarr_get_slice_to(fecarr_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fecarr_t* res){
        
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
        
        carr_get_slice_to( &arr->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------










// ****************************************************************************************************
void fecarr_set_slice_r( coeff_t val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fecarr_t* res){
        
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
        
        carr_set_slice_r( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k] );
    
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fecarr_set_slice_f( fednum_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fecarr_t* res){
        
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
        
        carr_set_slice_r( val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_set_slice_R(  carr_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fecarr_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = get_slice_size(starti, stopi, stepi);
    ncols = get_slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){
        
        carr_set_slice_R( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fecarr_set_slice_F( fecarr_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fecarr_t* res){
        
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
        
        carr_set_slice_R( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_set_item_k( carr_t* arr , uint64_t k, fecarr_t* res){
    
    // No new allocation needed.
    carr_copy_to( arr, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------


// // ****************************************************************************************************
// void fecarr_set_item_ij(fednum_t* num, uint64_t i, uint64_t j, fecarr_t* res){
    
//     uint64_t k;

//     //Check
//     fecarr_dimCheck_fF_elementwise(num,res,res);

//     for (k = 0; k < num->nip; k++){
        
//         carr_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k] );

//     }

// }
// // ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fecarr_set_item_ij_f(fednum_t* num, uint64_t i, uint64_t j, fecarr_t* res){
    
    uint64_t k;

    //Check
    fecarr_dimCheck_fF_elementwise(num,res,res);

    for (k = 0; k < num->nip; k++){
        
        carr_set_item_ij_r( num->p_data[k], i, j, &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fecarr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, fecarr_t* res){
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){
        
        carr_set_item_ij_r( num, i, j, &res->p_data[k] );

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fecarr_set_item_ijk_r(coeff_t num, uint64_t i, uint64_t j, uint64_t k, fecarr_t* res){

    if ( k < res->nip ){

        carr_set_item_ij_r( num, i, j, &res->p_data[k]);

    } else {

        printf("ERROR: Integration point Index.\n");
        exit(OTI_BadIndx);

    }

}
// ----------------------------------------------------------------------------------------------------





























// ****************************************************************************************************
void fecarr_set_f( fednum_t* num, fecarr_t* res ){ 
    
    uint64_t i;
    
    fecarr_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        carr_set_all_r( num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_set_R( carr_t* arr, fecarr_t* res ){ 
    
    uint64_t k;
    
    for( k = 0; k < res->nip; k++){

        carr_copy_to( arr, &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_set_F( fecarr_t* num, fecarr_t* res ){ 
    
    fecarr_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_set_r( coeff_t num, fecarr_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        carr_set_all_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void fecarr_set_all_f( fednum_t* num, fecarr_t* res ){ 
    
    uint64_t i;
    
    fecarr_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        carr_set_all_r( num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_set_all_r( coeff_t num, fecarr_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        carr_set_all_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fecarr_t fecarr_eye( uint64_t size, uint64_t nip ){ 
    
    uint64_t i,k;

    fecarr_t res = fecarr_zeros( size, size, nip);
    
    for( i = 0; i < res.nrows; i++){
    
        for( k = 0; k < res.nip; k++){

            carr_set_item_ij_r( 1.0, i, i, &res.p_data[k]);

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fecarr_t fecarr_zeros( uint64_t nrows, uint64_t ncols, uint64_t nip ){ 
    
    uint64_t i;

    fecarr_t res = fecarr_createEmpty( nrows, ncols, nip);
    
    for( i = 0; i < res.nip; i++){

        carr_set_all_r( 0.0, &res.p_data[i]);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fecarr_t fecarr_ones( uint64_t nrows, uint64_t ncols, uint64_t nip ){ 
    
    uint64_t i;

    fecarr_t res = fecarr_createEmpty( nrows, ncols, nip );
    
    for( i = 0; i < res.nip; i++){

        carr_set_all_r( 1.0, &res.p_data[i]);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fecarr_t fecarr_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t nip ){  
    
    uint64_t i;

    fecarr_t res = fecarr_init();

    res.nrows    =  nrows;
    res.ncols    =  ncols;
    res.size     =  nrows*ncols;
    
    res.nip  =  nip;

    // Allocate memory.
    res.p_data   = (carr_t*) malloc( res.nip * sizeof(carr_t) );

    if (res.p_data == NULL){
        printf("ERROR: Not enough memory to create fecarr object.\nExiting...\n");
        exit(OTI_OutOfMemory);
    }

    for( i = 0; i < res.nip; i++){

        res.p_data[i] = carr_createEmpty( nrows, ncols );

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_free(fecarr_t* arr){
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (arr->p_data != NULL){

        // Free all arrays.
        for (i = 0; i<arr->nip; i++){
        
            carr_free(&arr->p_data[i]); 

        }

        // Free pointer 
        free(arr->p_data);

    }

    *arr = fecarr_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_init(void){
    
    fecarr_t res;
    
    res.p_data  = NULL;  
    res.nrows   = 0;   
    res.ncols   = 0;   
    res.size    = 0;    
    res.nip = 0; 

    return res;

}
// ----------------------------------------------------------------------------------------------------

