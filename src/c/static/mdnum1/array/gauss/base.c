// typedef struct{
//     mdarr1_t*      p_data; ///< Data array
//     uint64_t      nrows;  ///< Number of rows.
//     uint64_t      ncols;  ///< Number of cols.
//     uint64_t       size;  ///< size of the array
//     uint64_t    nip;  ///< Number of integration points.
// } femdarr1_t;

// ****************************************************************************************************
ord_t femdarr1_get_order(femdarr1_t* arr){

    ord_t ord = 0;
    uint64_t i;

    for( i = 0; i < arr->nip; i++){

        ord = MAX( ord, mdarr1_get_order( &arr->p_data[i]) );

    }

    return ord;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_get_order_im_to( ord_t order, femdarr1_t* arr, femdarr1_t* res){
    
    uint64_t i;

    // check memory;
    femdarr1_dimCheck_FF_elementwise(arr, res, res);

    for (i = 0; i<arr->nip; i++ ){
        
        mdarr1_get_order_im_to( order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_get_order_im( ord_t order, femdarr1_t* arr){
    
    femdarr1_t res;

    res = femdarr1_zeros( arr->nrows, arr->ncols, arr->nip);

    femdarr1_get_order_im_to( order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_copy_to(femdarr1_t* src, femdarr1_t* dst){

    uint64_t i;

    // check memory;
    femdarr1_dimCheck_FF_elementwise(src, dst, dst);

    for( i = 0; i < src->nip; i++){

        mdarr1_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_copy(femdarr1_t* src){

    femdarr1_t res = femdarr1_createEmpty( src->nrows, src->ncols, src->nip);
    
    femdarr1_copy_to( src, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_truncate_im_to(imdir_t idx, ord_t order, femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    // check memory;
    femdarr1_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        mdarr1_truncate_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_truncate_im(imdir_t idx, ord_t order, femdarr1_t* arr){

    femdarr1_t res = femdarr1_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_truncate_im_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_extract_deriv_to(imdir_t idx, ord_t order, femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    // check memory;
    femdarr1_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        mdarr1_extract_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_extract_deriv( imdir_t idx, ord_t order, femdarr1_t* arr){

    femdarr1_t res = femdarr1_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_extract_deriv_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_get_deriv_to(imdir_t idx, ord_t order, femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    // check memory;
    femdarr1_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        mdarr1_get_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_get_deriv(imdir_t idx, ord_t order, femdarr1_t* arr){

    femdarr1_t res = femdarr1_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_get_deriv_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_get_im_to(imdir_t idx, ord_t order, femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    // check memory;
    femdarr1_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        mdarr1_get_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_get_im(imdir_t idx, ord_t order, femdarr1_t* arr){

    femdarr1_t res = femdarr1_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_get_im_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_extract_im_to(imdir_t idx, ord_t order, femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    // check memory;
    femdarr1_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        mdarr1_extract_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_extract_im(imdir_t idx, ord_t order, femdarr1_t* arr){

    femdarr1_t res = femdarr1_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_extract_im_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t femdarr1_get_item_k(femdarr1_t* arr, uint64_t k){
    
    mdarr1_t res;
    // TODO: Add bound checks.
    
    res = mdarr1_zeros(arr->nrows, arr->ncols);

    femdarr1_get_item_k_to(arr, k, &res);

    return res;    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdarr1_get_item_ij(femdarr1_t* arr, uint64_t i, uint64_t j){
        
    femdnum1_t res = femdnum1_init();
    // TODO: Add bound checks.
    
    res = femdnum1_zeros(arr->nip);

    femdarr1_get_item_ij_to(arr, i, j, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum1_t femdarr1_get_item_ijk(femdarr1_t* arr, uint64_t i, uint64_t j, uint64_t k){
    
    mdnum1_t res;
    
    res = mdarr1_get_item_ij(&arr->p_data[k], i, j);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_get_slice(femdarr1_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj){
    
    int64_t ncols, nrows;
    femdarr1_t res = femdarr1_init();

    // TODO: Add bound checks.
    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    res = femdarr1_zeros( nrows, ncols, arr->nip);

    femdarr1_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_get_item_k_to(femdarr1_t* arr, uint64_t k, mdarr1_t* res){
    
    // TODO: Add bound checks.

    mdarr1_copy_to( &arr->p_data[k], res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_get_item_ij_to(femdarr1_t* arr, uint64_t i, uint64_t j, femdnum1_t* res){
        
    uint64_t k;
    
    femdarr1_dimCheck_fF_elementwise(res,arr,arr);

    for (k = 0; k < arr->nip; k++){
        
        mdarr1_get_item_ij_to( &arr->p_data[k], i, j, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_get_item_ijk_to(femdarr1_t* arr, uint64_t i, uint64_t j, uint64_t k, mdnum1_t* res){
    
    // TODO: Add bound checks.
    if ( k < arr->nip && i < arr->nrows && j < arr->ncols){

        mdarr1_get_item_ij_to(&arr->p_data[k], i, j, res);

    } else {

        printf("Error: Bad index \n");
        exit(OTI_BadIndx);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_get_slice_to(femdarr1_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr1_t* res){
        
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
        
        mdarr1_get_slice_to( &arr->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// void mdarr1_set_slice_r( coeff_t val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          mdarr1_t* res);
// void mdarr1_set_slice_O( mdarr1_t* val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          mdarr1_t* res);
// void mdarr1_set_slice_o( mdnum1_t* val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          mdarr1_t* res);

// ****************************************************************************************************
void femdarr1_set_slice_r( coeff_t val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr1_t* res){
        
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
        
        mdarr1_set_slice_r( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_slice_o( mdnum1_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr1_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){
        
        mdarr1_set_slice_o( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_slice_f( femdnum1_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr1_t* res){
        
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
        
        mdarr1_set_slice_o( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_slice_O( mdarr1_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr1_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){
        
        mdarr1_set_slice_O( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_slice_F( femdarr1_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr1_t* res){
        
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
        
        mdarr1_set_slice_O( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_item_k( mdarr1_t* arr , uint64_t k, femdarr1_t* res){
    
    // No new allocation needed.
    mdarr1_copy_to( arr, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void femdarr1_set_item_ij(femdnum1_t* num, uint64_t i, uint64_t j, femdarr1_t* res){
    
//     uint64_t k;

//     //Check
//     femdarr1_dimCheck_fF_elementwise(num,res,res);

//     for (k = 0; k < num->nip; k++){
        
//         mdarr1_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k] );

//     }

// }
// // ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_item_ij_f(femdnum1_t* num, uint64_t i, uint64_t j, femdarr1_t* res){
    
    uint64_t k;

    //Check
    femdarr1_dimCheck_fF_elementwise(num,res,res);

    for (k = 0; k < num->nip; k++){
        
        mdarr1_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_item_ij_o( mdnum1_t* num, uint64_t i, uint64_t j, femdarr1_t* res){
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){
        
        mdarr1_set_item_ij_o( num, i, j, &res->p_data[k] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, femdarr1_t* res){
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){
        
        mdarr1_set_item_ij_r( num, i, j, &res->p_data[k] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_item_ijk_o(mdnum1_t* num, uint64_t i, uint64_t j, uint64_t k, 
    femdarr1_t* res){

    mdarr1_set_item_ij_o( num, i, j, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_item_ijk_r(coeff_t num, uint64_t i, uint64_t j, uint64_t k, 
    femdarr1_t* res){

    mdarr1_set_item_ij_r( num, i, j, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_item_ijk(mdnum1_t* num, uint64_t i, uint64_t j, uint64_t k, 
        femdarr1_t* res){

    mdarr1_set_item_ij_o( num, i, j, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_f( femdnum1_t* num, femdarr1_t* res ){ 
    
    uint64_t i;
    
    femdarr1_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        mdarr1_set_all_o( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_o( mdnum1_t* num, femdarr1_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        mdarr1_set_all_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_r( coeff_t num, femdarr1_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        mdarr1_set_all_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_all_f( femdnum1_t* num, femdarr1_t* res ){ 
    
    uint64_t i;
    
    femdarr1_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        mdarr1_set_all_o( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_all_o( mdnum1_t* num, femdarr1_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        mdarr1_set_all_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_set_all_r( coeff_t num, femdarr1_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        mdarr1_set_all_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_eye( uint64_t size, uint64_t nip ){ 
    
    uint64_t i,k;

    femdarr1_t res = femdarr1_createEmpty( size, size, nip);
    
    for( k = 0; k < res.nip; k++){

        mdarr1_set_all_r( 0.0, &res.p_data[k]);

    }
    
    for( i = 0; i < res.nrows; i++){
    
        for( k = 0; k < res.nip; k++){

            mdarr1_set_item_ij_r( 1.0, i, i, &res.p_data[k]);

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_zeros( uint64_t nrows, uint64_t ncols, uint64_t nip ){ 
    
    uint64_t i;

    femdarr1_t res = femdarr1_createEmpty( nrows, ncols, nip);
    
    for( i = 0; i < res.nip; i++){

        mdarr1_set_all_r( 0.0, &res.p_data[i]);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_ones( uint64_t nrows, uint64_t ncols, uint64_t nip  ){ 
    
    uint64_t i;

    femdarr1_t res = femdarr1_createEmpty( nrows, ncols, nip);
    
    for( i = 0; i < res.nip; i++){

        mdarr1_set_all_r( 1.0, &res.p_data[i]);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t nip){  
    
    uint64_t i;

    femdarr1_t res = femdarr1_init();

    res.nrows    =  nrows;
    res.ncols    =  ncols;
    res.size     =  nrows*ncols;
    
    res.nip  =  nip;

    // Allocate memory.
    res.p_data   = (mdarr1_t*) malloc( res.nip * sizeof(mdarr1_t) );

    // mdnum1array_createEmpty(mdnum1array_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order);
    if (res.p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for( i = 0; i < res.nip; i++){

        res.p_data[i] = mdarr1_createEmpty( nrows, ncols);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_free(femdarr1_t* arr){
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (arr->p_data != NULL){

        // Free all arrays.
        for (i = 0; i<arr->nip; i++){
        
            mdarr1_free(&arr->p_data[i]); 

        }

        // Free pointer 
        free(arr->p_data);

    }

    *arr = femdarr1_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_init(void){
    
    femdarr1_t res;
    
    res.p_data  = NULL;  
    res.nrows   = 0;   
    res.ncols   = 0;   
    res.size    = 0;    
    res.nip = 0; 

    return res;

}
// ----------------------------------------------------------------------------------------------------

