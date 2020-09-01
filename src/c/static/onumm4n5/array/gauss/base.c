// typedef struct{
//     oarrm4n5_t*      p_data; ///< Data array
//     uint64_t      nrows;  ///< Number of rows.
//     uint64_t      ncols;  ///< Number of cols.
//     uint64_t       size;  ///< size of the array
//     uint64_t    nip;  ///< Number of integration points.
// } feoarrm4n5_t;

// ****************************************************************************************************
ord_t feoarrm4n5_get_order(feoarrm4n5_t* arr){

    ord_t ord = 0;
    uint64_t i;

    for( i = 0; i < arr->nip; i++){

        ord = MAX( ord, oarrm4n5_get_order( &arr->p_data[i]) );

    }

    return ord;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_get_order_im_to( ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res){
    
    uint64_t i;

    // check memory;
    feoarrm4n5_dimCheck_FF_elementwise(arr, res, res);

    for (i = 0; i<arr->nip; i++ ){
        
        oarrm4n5_get_order_im_to( order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_get_order_im( ord_t order, feoarrm4n5_t* arr){
    
    feoarrm4n5_t res;

    res = feoarrm4n5_zeros( arr->nrows, arr->ncols, arr->nip);

    feoarrm4n5_get_order_im_to( order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_copy_to(feoarrm4n5_t* src, feoarrm4n5_t* dst){

    uint64_t i;

    // check memory;
    feoarrm4n5_dimCheck_FF_elementwise(src, dst, dst);

    for( i = 0; i < src->nip; i++){

        oarrm4n5_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_copy(feoarrm4n5_t* src){

    feoarrm4n5_t res = feoarrm4n5_createEmpty( src->nrows, src->ncols, src->nip);
    
    feoarrm4n5_copy_to( src, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_truncate_im_to(imdir_t idx, ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    // check memory;
    feoarrm4n5_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        oarrm4n5_truncate_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_truncate_im(imdir_t idx, ord_t order, feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_truncate_im_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_extract_deriv_to(imdir_t idx, ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    // check memory;
    feoarrm4n5_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        oarrm4n5_extract_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_extract_deriv( imdir_t idx, ord_t order, feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_extract_deriv_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_get_deriv_to(imdir_t idx, ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    // check memory;
    feoarrm4n5_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        oarrm4n5_get_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_get_deriv(imdir_t idx, ord_t order, feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_get_deriv_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_get_im_to(imdir_t idx, ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    // check memory;
    feoarrm4n5_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        oarrm4n5_get_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_get_im(imdir_t idx, ord_t order, feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_get_im_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_extract_im_to(imdir_t idx, ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res){

    uint64_t i;

    // check memory;
    feoarrm4n5_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        oarrm4n5_extract_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_extract_im(imdir_t idx, ord_t order, feoarrm4n5_t* arr){

    feoarrm4n5_t res = feoarrm4n5_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n5_extract_im_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm4n5_t feoarrm4n5_get_item_k(feoarrm4n5_t* arr, uint64_t k){
    
    oarrm4n5_t res;
    // TODO: Add bound checks.
    
    res = oarrm4n5_zeros(arr->nrows, arr->ncols);

    feoarrm4n5_get_item_k_to(arr, k, &res);

    return res;    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm4n5_t feoarrm4n5_get_item_ij(feoarrm4n5_t* arr, uint64_t i, uint64_t j){
        
    feonumm4n5_t res = feonumm4n5_init();
    // TODO: Add bound checks.
    
    res = feonumm4n5_zeros(arr->nip);

    feoarrm4n5_get_item_ij_to(arr, i, j, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm4n5_t feoarrm4n5_get_item_ijk(feoarrm4n5_t* arr, uint64_t i, uint64_t j, uint64_t k){
    
    onumm4n5_t res;
    
    res = oarrm4n5_get_item_ij(&arr->p_data[k], i, j);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_get_slice(feoarrm4n5_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj){
    
    int64_t ncols, nrows;
    feoarrm4n5_t res = feoarrm4n5_init();

    // TODO: Add bound checks.
    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    res = feoarrm4n5_zeros( nrows, ncols, arr->nip);

    feoarrm4n5_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_get_item_k_to(feoarrm4n5_t* arr, uint64_t k, oarrm4n5_t* res){
    
    // TODO: Add bound checks.

    oarrm4n5_copy_to( &arr->p_data[k], res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_get_item_ij_to(feoarrm4n5_t* arr, uint64_t i, uint64_t j, feonumm4n5_t* res){
        
    uint64_t k;
    
    feoarrm4n5_dimCheck_fF_elementwise(res,arr,arr);

    for (k = 0; k < arr->nip; k++){
        
        oarrm4n5_get_item_ij_to( &arr->p_data[k], i, j, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_get_item_ijk_to(feoarrm4n5_t* arr, uint64_t i, uint64_t j, uint64_t k, onumm4n5_t* res){
    
    // TODO: Add bound checks.
    if ( k < arr->nip && i < arr->nrows && j < arr->ncols){

        oarrm4n5_get_item_ij_to(&arr->p_data[k], i, j, res);

    } else {

        printf("Error: Bad index \n");
        exit(OTI_BadIndx);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_get_slice_to(feoarrm4n5_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          feoarrm4n5_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols != ncols) || (res->nrows != nrows) || (res->nip != arr->nip)){

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }

    for (k = 0; k < arr->nip; k++){
        
        oarrm4n5_get_slice_to( &arr->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// void oarrm4n5_set_slice_r( coeff_t val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          oarrm4n5_t* res);
// void oarrm4n5_set_slice_O( oarrm4n5_t* val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          oarrm4n5_t* res);
// void oarrm4n5_set_slice_o( onumm4n5_t* val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          oarrm4n5_t* res);

// ****************************************************************************************************
void feoarrm4n5_set_slice_r( coeff_t val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          feoarrm4n5_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols < ncols) || (res->nrows < nrows) ){

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }

    for (k = 0; k < res->nip; k++){
        
        oarrm4n5_set_slice_r( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_slice_o( onumm4n5_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          feoarrm4n5_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){
        
        oarrm4n5_set_slice_o( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_slice_f( feonumm4n5_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          feoarrm4n5_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->nip != val->nip) ){

        printf("ERROR: Wrong number of integration points.\n");
        exit(OTI_BadIndx);

    }

    for (k = 0; k < res->nip; k++){
        
        oarrm4n5_set_slice_o( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_slice_O( oarrm4n5_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          feoarrm4n5_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){
        
        oarrm4n5_set_slice_O( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_slice_F( feoarrm4n5_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          feoarrm4n5_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->nip != val->nip) ){

        printf("ERROR: Wrong number of integration points.\n");
        exit(OTI_BadIndx);

    }

    for (k = 0; k < res->nip; k++){
        
        oarrm4n5_set_slice_O( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_item_k( oarrm4n5_t* arr , uint64_t k, feoarrm4n5_t* res){
    
    // No new allocation needed.
    oarrm4n5_copy_to( arr, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void feoarrm4n5_set_item_ij(feonumm4n5_t* num, uint64_t i, uint64_t j, feoarrm4n5_t* res){
    
//     uint64_t k;

//     //Check
//     feoarrm4n5_dimCheck_fF_elementwise(num,res,res);

//     for (k = 0; k < num->nip; k++){
        
//         oarrm4n5_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k] );

//     }

// }
// // ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_item_ij_f(feonumm4n5_t* num, uint64_t i, uint64_t j, feoarrm4n5_t* res){
    
    uint64_t k;

    //Check
    feoarrm4n5_dimCheck_fF_elementwise(num,res,res);

    for (k = 0; k < num->nip; k++){
        
        oarrm4n5_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_item_ij_o( onumm4n5_t* num, uint64_t i, uint64_t j, feoarrm4n5_t* res){
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){
        
        oarrm4n5_set_item_ij_o( num, i, j, &res->p_data[k] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, feoarrm4n5_t* res){
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){
        
        oarrm4n5_set_item_ij_r( num, i, j, &res->p_data[k] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_item_ijk_o(onumm4n5_t* num, uint64_t i, uint64_t j, uint64_t k, 
    feoarrm4n5_t* res){

    oarrm4n5_set_item_ij_o( num, i, j, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_item_ijk_r(coeff_t num, uint64_t i, uint64_t j, uint64_t k, 
    feoarrm4n5_t* res){

    oarrm4n5_set_item_ij_r( num, i, j, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_item_ijk(onumm4n5_t* num, uint64_t i, uint64_t j, uint64_t k, 
        feoarrm4n5_t* res){

    oarrm4n5_set_item_ij_o( num, i, j, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_f( feonumm4n5_t* num, feoarrm4n5_t* res ){ 
    
    uint64_t i;
    
    feoarrm4n5_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        oarrm4n5_set_all_o( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_o( onumm4n5_t* num, feoarrm4n5_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        oarrm4n5_set_all_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_r( coeff_t num, feoarrm4n5_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        oarrm4n5_set_all_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_all_f( feonumm4n5_t* num, feoarrm4n5_t* res ){ 
    
    uint64_t i;
    
    feoarrm4n5_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        oarrm4n5_set_all_o( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_all_o( onumm4n5_t* num, feoarrm4n5_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        oarrm4n5_set_all_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_set_all_r( coeff_t num, feoarrm4n5_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        oarrm4n5_set_all_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_eye( uint64_t size, uint64_t nip ){ 
    
    uint64_t i,k;

    feoarrm4n5_t res = feoarrm4n5_createEmpty( size, size, nip);
    
    for( k = 0; k < res.nip; k++){

        oarrm4n5_set_all_r( 0.0, &res.p_data[k]);

    }
    
    for( i = 0; i < res.nrows; i++){
    
        for( k = 0; k < res.nip; k++){

            oarrm4n5_set_item_ij_r( 1.0, i, i, &res.p_data[k]);

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_zeros( uint64_t nrows, uint64_t ncols, uint64_t nip ){ 
    
    uint64_t i;

    feoarrm4n5_t res = feoarrm4n5_createEmpty( nrows, ncols, nip);
    
    for( i = 0; i < res.nip; i++){

        oarrm4n5_set_all_r( 0.0, &res.p_data[i]);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_ones( uint64_t nrows, uint64_t ncols, uint64_t nip  ){ 
    
    uint64_t i;

    feoarrm4n5_t res = feoarrm4n5_createEmpty( nrows, ncols, nip);
    
    for( i = 0; i < res.nip; i++){

        oarrm4n5_set_all_r( 1.0, &res.p_data[i]);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t nip){  
    
    uint64_t i;

    feoarrm4n5_t res = feoarrm4n5_init();

    res.nrows    =  nrows;
    res.ncols    =  ncols;
    res.size     =  nrows*ncols;
    
    res.nip  =  nip;

    // Allocate memory.
    res.p_data   = (oarrm4n5_t*) malloc( res.nip * sizeof(oarrm4n5_t) );

    // onumm4n5array_createEmpty(onumm4n5array_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order);
    if (res.p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for( i = 0; i < res.nip; i++){

        res.p_data[i] = oarrm4n5_createEmpty( nrows, ncols);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n5_free(feoarrm4n5_t* arr){
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (arr->p_data != NULL){

        // Free all arrays.
        for (i = 0; i<arr->nip; i++){
        
            oarrm4n5_free(&arr->p_data[i]); 

        }

        // Free pointer 
        free(arr->p_data);

    }

    *arr = feoarrm4n5_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n5_t feoarrm4n5_init(void){
    
    feoarrm4n5_t res;
    
    res.p_data  = NULL;  
    res.nrows   = 0;   
    res.ncols   = 0;   
    res.size    = 0;    
    res.nip = 0; 

    return res;

}
// ----------------------------------------------------------------------------------------------------

