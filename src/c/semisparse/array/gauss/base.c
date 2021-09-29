// typedef struct{
//     arrsso_t*      p_data; ///< Data array
//     uint64_t      nrows;  ///< Number of rows.
//     uint64_t      ncols;  ///< Number of cols.
//     uint64_t       size;  ///< size of the array
//     uint64_t    nip;  ///< Number of integration points.
// } fearrsso_t;











// ****************************************************************************************************
ord_t fearrsso_get_order(fearrsso_t* arr){

    ord_t ord = 0;
    uint64_t i;

    for( i = 0; i < arr->nip; i++){

        ord = MAX( ord, arrsso_get_order( &arr->p_data[i]) );

    }

    return ord;

}
// ----------------------------------------------------------------------------------------------------









// ****************************************************************************************************
void fearrsso_get_order_im_to( ord_t order, fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){
    
    uint64_t i;

    // check memory;
    fearrsso_dimCheck_FF_elementwise(arr, res, res);

    for (i = 0; i<arr->nip; i++ ){
        
        arrsso_get_order_im_to( order, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_get_order_im( ord_t order, fearrsso_t* arr, dhelpl_t dhl){
    
    fearrsso_t res;

    res = fearrsso_zeros_bases( arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrsso_get_order_im_to( order, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------















// ****************************************************************************************************
void fearrsso_copy_to(fearrsso_t* src, fearrsso_t* dst, dhelpl_t dhl){

    uint64_t i;

    // check memory;
    fearrsso_dimCheck_FF_elementwise(src, dst, dst);

    for( i = 0; i < src->nip; i++){

        arrsso_copy_to( &src->p_data[i], &dst->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_copy(fearrsso_t* src, dhelpl_t dhl){

    fearrsso_t res = fearrsso_createEmpty_bases( src->nrows, src->ncols, src->nip, 0, 0, dhl);
    
    fearrsso_copy_to( src, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------








// ****************************************************************************************************
void fearrsso_truncate_im_to(imdir_t idx, ord_t order, fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // check memory;
    fearrsso_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        arrsso_truncate_im_to( idx, order, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_truncate_im(imdir_t idx, ord_t order, fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_createEmpty_bases( arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_truncate_im_to( idx, order, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------






















// ****************************************************************************************************
void fearrsso_extract_deriv_to(imdir_t idx, ord_t order, fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // check memory;
    fearrsso_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        arrsso_extract_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_extract_deriv( imdir_t idx, ord_t order, fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_createEmpty_bases( arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_extract_deriv_to( idx, order, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------







// ****************************************************************************************************
void fearrsso_get_deriv_to(imdir_t idx, ord_t order, fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // check memory;
    fearrsso_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        arrsso_get_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_get_deriv(imdir_t idx, ord_t order, fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_createEmpty_bases( arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_get_deriv_to( idx, order, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------








// ****************************************************************************************************
void fearrsso_get_im_to(imdir_t idx, ord_t order, fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // check memory;
    fearrsso_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        arrsso_get_im_to( idx, order, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_get_im(imdir_t idx, ord_t order, fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_createEmpty_bases( arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_get_im_to( idx, order, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------



















// ****************************************************************************************************
void fearrsso_extract_im_to(imdir_t idx, ord_t order, fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // check memory;
    fearrsso_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        arrsso_extract_im_to( idx, order, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_extract_im(imdir_t idx, ord_t order, fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_createEmpty_bases( arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_extract_im_to( idx, order, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------








// ****************************************************************************************************
arrsso_t fearrsso_get_item_k(fearrsso_t* arr, uint64_t k, dhelpl_t dhl){
    
    arrsso_t res;
    // TODO: Add bound checks.
    
    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    fearrsso_get_item_k_to(arr, k, &res, dhl);

    return res;    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fessoti_t fearrsso_get_item_ij(fearrsso_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl){
        
    fessoti_t res = fessoti_init();
    // TODO: Add bound checks.
    
    res = fessoti_zeros_bases(arr->nip, 0, 0, dhl);

    fearrsso_get_item_ij_to(arr, i, j, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
semiotin_t fearrsso_get_item_ijk(fearrsso_t* arr, uint64_t i, uint64_t j, uint64_t k, dhelpl_t dhl){
    
    semiotin_t res;
    
    res = arrsso_get_item_ij(&arr->p_data[k], i, j, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_get_slice(fearrsso_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                           dhelpl_t dhl){
    
    int64_t ncols, nrows;
    fearrsso_t res = fearrsso_init();

    // TODO: Add bound checks.
    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    res = fearrsso_zeros_bases( nrows, ncols, arr->nip, 0, 0, dhl);

    fearrsso_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------







// ****************************************************************************************************
void fearrsso_get_item_k_to(fearrsso_t* arr, uint64_t k, arrsso_t* res, dhelpl_t dhl){
    
    // TODO: Add bound checks.

    arrsso_copy_to( &arr->p_data[k], res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_get_item_ij_to(fearrsso_t* arr, uint64_t i, uint64_t j, fessoti_t* res, dhelpl_t dhl){
        
    uint64_t k;
    
    fearrsso_dimCheck_fF_elementwise(res,arr,arr);

    for (k = 0; k < arr->nip; k++){
        
        arrsso_get_item_ij_to( &arr->p_data[k], i, j, &res->p_data[k], dhl);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_get_item_ijk_to(fearrsso_t* arr, uint64_t i, uint64_t j, uint64_t k, semiotin_t* res, dhelpl_t dhl){
    
    // TODO: Add bound checks.
    if ( k < arr->nip && i < arr->nrows && j < arr->ncols){

        arrsso_get_item_ij_to(&arr->p_data[k], i, j, res, dhl);

    } else {

        printf("Error: Bad index \n");
        exit(OTI_BadIndx);
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrsso_get_slice_to(fearrsso_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fearrsso_t* res, dhelpl_t dhl){
        
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
        
        arrsso_get_slice_to( &arr->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k], dhl);
    
    }

}
// ----------------------------------------------------------------------------------------------------









// void arrsso_set_slice_r( coeff_t val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          arrsso_t* res, dhelpl_t dhl);
// void arrsso_set_slice_O( arrsso_t* val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          arrsso_t* res, dhelpl_t dhl);
// void arrsso_set_slice_o( semiotin_t* val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          arrsso_t* res, dhelpl_t dhl);

// ****************************************************************************************************
void fearrsso_set_slice_r( coeff_t val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fearrsso_t* res, dhelpl_t dhl){
        
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
        
        arrsso_set_slice_r( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k], dhl);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_set_slice_o( semiotin_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fearrsso_t* res, dhelpl_t dhl){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){
        
        arrsso_set_slice_o( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k], dhl);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_set_slice_f( fessoti_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fearrsso_t* res, dhelpl_t dhl){
        
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
        
        arrsso_set_slice_o( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k], dhl);
    
    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void fearrsso_set_slice_O( arrsso_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fearrsso_t* res, dhelpl_t dhl){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){
        
        arrsso_set_slice_O( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k], dhl);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_set_slice_F( fearrsso_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fearrsso_t* res, dhelpl_t dhl){
        
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
        
        arrsso_set_slice_O( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k], dhl);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_set_item_k( arrsso_t* arr , uint64_t k, fearrsso_t* res, dhelpl_t dhl){
    
    // No new allocation needed.
    arrsso_copy_to( arr, &res->p_data[k], dhl);

}
// ----------------------------------------------------------------------------------------------------


// // ****************************************************************************************************
// void fearrsso_set_item_ij(fessoti_t* num, uint64_t i, uint64_t j, fearrsso_t* res, dhelpl_t dhl){
    
//     uint64_t k;

//     //Check
//     fearrsso_dimCheck_fF_elementwise(num,res,res);

//     for (k = 0; k < num->nip; k++){
        
//         arrsso_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k], dhl );

//     }

// }
// // ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrsso_set_item_ij_f(fessoti_t* num, uint64_t i, uint64_t j, fearrsso_t* res, dhelpl_t dhl){
    
    uint64_t k;

    //Check
    fearrsso_dimCheck_fF_elementwise(num,res,res);

    for (k = 0; k < num->nip; k++){
        
        arrsso_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrsso_set_item_ij_o( semiotin_t* num, uint64_t i, uint64_t j, fearrsso_t* res, dhelpl_t dhl){
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){
        
        arrsso_set_item_ij_o( num, i, j, &res->p_data[k], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, fearrsso_t* res, dhelpl_t dhl){
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){
        
        arrsso_set_item_ij_r( num, i, j, &res->p_data[k], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrsso_set_item_ijk_o(semiotin_t* num, uint64_t i, uint64_t j, uint64_t k, 
    fearrsso_t* res, dhelpl_t dhl){

    arrsso_set_item_ij_o( num, i, j, &res->p_data[k], dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_set_item_ijk_r(coeff_t num, uint64_t i, uint64_t j, uint64_t k, 
    fearrsso_t* res, dhelpl_t dhl){

    arrsso_set_item_ij_r( num, i, j, &res->p_data[k], dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_set_item_ijk(semiotin_t* num, uint64_t i, uint64_t j, uint64_t k, 
        fearrsso_t* res, dhelpl_t dhl){

    arrsso_set_item_ij_o( num, i, j, &res->p_data[k], dhl);

}
// ----------------------------------------------------------------------------------------------------

































// ****************************************************************************************************
void fearrsso_set_f( fessoti_t* num, fearrsso_t* res, dhelpl_t dhl ){ 
    
    uint64_t i;
    
    fearrsso_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        arrsso_set_all_o( &num->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_set_o( semiotin_t* num, fearrsso_t* res, dhelpl_t dhl ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        arrsso_set_all_o( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_set_r( coeff_t num, fearrsso_t* res, dhelpl_t dhl ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        arrsso_set_all_r( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------














// ****************************************************************************************************
void fearrsso_set_all_f( fessoti_t* num, fearrsso_t* res, dhelpl_t dhl ){ 
    
    uint64_t i;
    
    fearrsso_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        arrsso_set_all_o( &num->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_set_all_o( semiotin_t* num, fearrsso_t* res, dhelpl_t dhl ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        arrsso_set_all_o( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_set_all_r( coeff_t num, fearrsso_t* res, dhelpl_t dhl ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        arrsso_set_all_r( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fearrsso_t fearrsso_eye_bases( uint64_t size,
                               uint64_t nip, bases_t  nbases, 
                               ord_t    order,   dhelpl_t dhl     ){ 
    
    uint64_t i,k;

    fearrsso_t res = fearrsso_createEmpty_bases( size, size, nip, nbases, order, dhl);
    
    for( k = 0; k < res.nip; k++){

        arrsso_set_all_r( 0.0, &res.p_data[k], dhl);

    }
    
    for( i = 0; i < res.nrows; i++){
    
        for( k = 0; k < res.nip; k++){

            arrsso_set_item_ij_r( 1.0, i, i, &res.p_data[k], dhl);

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fearrsso_t fearrsso_zeros_bases( uint64_t nrows,   uint64_t ncols, 
                               uint64_t nip, bases_t  nbases, 
                               ord_t    order,   dhelpl_t dhl     ){ 
    
    uint64_t i;

    fearrsso_t res = fearrsso_createEmpty_bases( nrows, ncols, nip, nbases, order, dhl);
    
    for( i = 0; i < res.nip; i++){

        arrsso_set_all_r( 0.0, &res.p_data[i], dhl);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fearrsso_t fearrsso_ones_bases( uint64_t nrows,   uint64_t ncols, uint64_t nip, bases_t  nbases, 
                               ord_t    order,   dhelpl_t dhl     ){ 
    
    uint64_t i;

    fearrsso_t res = fearrsso_createEmpty_bases( nrows, ncols, nip, nbases, order, dhl);
    
    for( i = 0; i < res.nip; i++){

        arrsso_set_all_r( 1.0, &res.p_data[i], dhl);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fearrsso_t fearrsso_createEmpty_bases( uint64_t nrows,   uint64_t ncols, 
                                     uint64_t nip, bases_t  nbases, 
                                     ord_t    order,   dhelpl_t dhl){  
    
    uint64_t i;

    fearrsso_t res = fearrsso_init();

    res.nrows    =  nrows;
    res.ncols    =  ncols;
    res.size     =  nrows*ncols;
    
    res.nip  =  nip;

    // Allocate memory.
    res.p_data   = (arrsso_t*) malloc( res.nip * sizeof(arrsso_t) );

    // sotiarray_createEmpty(sotiarray_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order);
    if (res.p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for( i = 0; i < res.nip; i++){

        res.p_data[i] = arrsso_createEmpty_bases( nrows, ncols, nbases, order, dhl);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------




























// ****************************************************************************************************
void fearrsso_free(fearrsso_t* arr){
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (arr->p_data != NULL){

        // Free all arrays.
        for (i = 0; i<arr->nip; i++){
        
            arrsso_free(&arr->p_data[i]); 

        }

        // Free pointer 
        free(arr->p_data);

    }

    *arr = fearrsso_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_init(void){
    
    fearrsso_t res;
    
    res.p_data  = NULL;  
    res.nrows   = 0;   
    res.ncols   = 0;   
    res.size    = 0;    
    res.nip = 0; 

    return res;

}
// ----------------------------------------------------------------------------------------------------

