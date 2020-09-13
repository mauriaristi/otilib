// typedef struct{
//     mdarr6_t*      p_data; ///< Data array
//     uint64_t      nrows;  ///< Number of rows.
//     uint64_t      ncols;  ///< Number of cols.
//     uint64_t       size;  ///< size of the array
//     uint64_t    nip;  ///< Number of integration points.
// } femdarr6_t;

// ****************************************************************************************************
ord_t femdarr6_get_order(femdarr6_t* arr){

    ord_t ord = 0;
    uint64_t i;

    for( i = 0; i < arr->nip; i++){

        ord = MAX( ord, mdarr6_get_order( &arr->p_data[i]) );

    }

    return ord;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_get_order_im_to( ord_t order, femdarr6_t* arr, femdarr6_t* res){
    
    uint64_t i;

    // check memory;
    femdarr6_dimCheck_FF_elementwise(arr, res, res);

    for (i = 0; i<arr->nip; i++ ){
        
        mdarr6_get_order_im_to( order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_get_order_im( ord_t order, femdarr6_t* arr){
    
    femdarr6_t res;

    res = femdarr6_zeros( arr->nrows, arr->ncols, arr->nip);

    femdarr6_get_order_im_to( order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_copy_to(femdarr6_t* src, femdarr6_t* dst){

    uint64_t i;

    // check memory;
    femdarr6_dimCheck_FF_elementwise(src, dst, dst);

    for( i = 0; i < src->nip; i++){

        mdarr6_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_copy(femdarr6_t* src){

    femdarr6_t res = femdarr6_createEmpty( src->nrows, src->ncols, src->nip);
    
    femdarr6_copy_to( src, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_truncate_im_to(imdir_t idx, ord_t order, femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    // check memory;
    femdarr6_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        mdarr6_truncate_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_truncate_im(imdir_t idx, ord_t order, femdarr6_t* arr){

    femdarr6_t res = femdarr6_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_truncate_im_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_extract_deriv_to(imdir_t idx, ord_t order, femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    // check memory;
    femdarr6_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        mdarr6_extract_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_extract_deriv( imdir_t idx, ord_t order, femdarr6_t* arr){

    femdarr6_t res = femdarr6_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_extract_deriv_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_get_deriv_to(imdir_t idx, ord_t order, femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    // check memory;
    femdarr6_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        mdarr6_get_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_get_deriv(imdir_t idx, ord_t order, femdarr6_t* arr){

    femdarr6_t res = femdarr6_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_get_deriv_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_get_im_to(imdir_t idx, ord_t order, femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    // check memory;
    femdarr6_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        mdarr6_get_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_get_im(imdir_t idx, ord_t order, femdarr6_t* arr){

    femdarr6_t res = femdarr6_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_get_im_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_extract_im_to(imdir_t idx, ord_t order, femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    // check memory;
    femdarr6_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){

        mdarr6_extract_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_extract_im(imdir_t idx, ord_t order, femdarr6_t* arr){

    femdarr6_t res = femdarr6_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_extract_im_to( idx, order, arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t femdarr6_get_item_k(femdarr6_t* arr, uint64_t k){
    
    mdarr6_t res;
    // TODO: Add bound checks.
    
    res = mdarr6_zeros(arr->nrows, arr->ncols);

    femdarr6_get_item_k_to(arr, k, &res);

    return res;    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdarr6_get_item_ij(femdarr6_t* arr, uint64_t i, uint64_t j){
        
    femdnum6_t res = femdnum6_init();
    // TODO: Add bound checks.
    
    res = femdnum6_zeros(arr->nip);

    femdarr6_get_item_ij_to(arr, i, j, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum6_t femdarr6_get_item_ijk(femdarr6_t* arr, uint64_t i, uint64_t j, uint64_t k){
    
    mdnum6_t res;
    
    res = mdarr6_get_item_ij(&arr->p_data[k], i, j);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_get_slice(femdarr6_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj){
    
    int64_t ncols, nrows;
    femdarr6_t res = femdarr6_init();

    // TODO: Add bound checks.
    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    res = femdarr6_zeros( nrows, ncols, arr->nip);

    femdarr6_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_get_item_k_to(femdarr6_t* arr, uint64_t k, mdarr6_t* res){
    
    // TODO: Add bound checks.

    mdarr6_copy_to( &arr->p_data[k], res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_get_item_ij_to(femdarr6_t* arr, uint64_t i, uint64_t j, femdnum6_t* res){
        
    uint64_t k;
    
    femdarr6_dimCheck_fF_elementwise(res,arr,arr);

    for (k = 0; k < arr->nip; k++){
        
        mdarr6_get_item_ij_to( &arr->p_data[k], i, j, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_get_item_ijk_to(femdarr6_t* arr, uint64_t i, uint64_t j, uint64_t k, mdnum6_t* res){
    
    // TODO: Add bound checks.
    if ( k < arr->nip && i < arr->nrows && j < arr->ncols){

        mdarr6_get_item_ij_to(&arr->p_data[k], i, j, res);

    } else {

        printf("Error: Bad index \n");
        exit(OTI_BadIndx);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_get_slice_to(femdarr6_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr6_t* res){
        
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
        
        mdarr6_get_slice_to( &arr->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// void mdarr6_set_slice_r( coeff_t val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          mdarr6_t* res);
// void mdarr6_set_slice_O( mdarr6_t* val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          mdarr6_t* res);
// void mdarr6_set_slice_o( mdnum6_t* val, 
//                         int64_t starti, int64_t stopi, int64_t stepi,
//                         int64_t startj, int64_t stopj, int64_t stepj,
//                          mdarr6_t* res);

// ****************************************************************************************************
void femdarr6_set_slice_r( coeff_t val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr6_t* res){
        
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
        
        mdarr6_set_slice_r( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_slice_o( mdnum6_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr6_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){
        
        mdarr6_set_slice_o( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_slice_f( femdnum6_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr6_t* res){
        
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
        
        mdarr6_set_slice_o( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_slice_O( mdarr6_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr6_t* res){
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){
        
        mdarr6_set_slice_O( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_slice_F( femdarr6_t* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr6_t* res){
        
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
        
        mdarr6_set_slice_O( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_item_k( mdarr6_t* arr , uint64_t k, femdarr6_t* res){
    
    // No new allocation needed.
    mdarr6_copy_to( arr, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void femdarr6_set_item_ij(femdnum6_t* num, uint64_t i, uint64_t j, femdarr6_t* res){
    
//     uint64_t k;

//     //Check
//     femdarr6_dimCheck_fF_elementwise(num,res,res);

//     for (k = 0; k < num->nip; k++){
        
//         mdarr6_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k] );

//     }

// }
// // ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_item_ij_f(femdnum6_t* num, uint64_t i, uint64_t j, femdarr6_t* res){
    
    uint64_t k;

    //Check
    femdarr6_dimCheck_fF_elementwise(num,res,res);

    for (k = 0; k < num->nip; k++){
        
        mdarr6_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_item_ij_o( mdnum6_t* num, uint64_t i, uint64_t j, femdarr6_t* res){
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){
        
        mdarr6_set_item_ij_o( num, i, j, &res->p_data[k] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, femdarr6_t* res){
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){
        
        mdarr6_set_item_ij_r( num, i, j, &res->p_data[k] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_item_ijk_o(mdnum6_t* num, uint64_t i, uint64_t j, uint64_t k, 
    femdarr6_t* res){

    mdarr6_set_item_ij_o( num, i, j, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_item_ijk_r(coeff_t num, uint64_t i, uint64_t j, uint64_t k, 
    femdarr6_t* res){

    mdarr6_set_item_ij_r( num, i, j, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_item_ijk(mdnum6_t* num, uint64_t i, uint64_t j, uint64_t k, 
        femdarr6_t* res){

    mdarr6_set_item_ij_o( num, i, j, &res->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_f( femdnum6_t* num, femdarr6_t* res ){ 
    
    uint64_t i;
    
    femdarr6_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        mdarr6_set_all_o( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_o( mdnum6_t* num, femdarr6_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        mdarr6_set_all_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_r( coeff_t num, femdarr6_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        mdarr6_set_all_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_all_f( femdnum6_t* num, femdarr6_t* res ){ 
    
    uint64_t i;
    
    femdarr6_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){

        mdarr6_set_all_o( &num->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_all_o( mdnum6_t* num, femdarr6_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        mdarr6_set_all_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_set_all_r( coeff_t num, femdarr6_t* res ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        mdarr6_set_all_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_eye( uint64_t size, uint64_t nip ){ 
    
    uint64_t i,k;

    femdarr6_t res = femdarr6_createEmpty( size, size, nip);
    
    for( k = 0; k < res.nip; k++){

        mdarr6_set_all_r( 0.0, &res.p_data[k]);

    }
    
    for( i = 0; i < res.nrows; i++){
    
        for( k = 0; k < res.nip; k++){

            mdarr6_set_item_ij_r( 1.0, i, i, &res.p_data[k]);

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_zeros( uint64_t nrows, uint64_t ncols, uint64_t nip ){ 
    
    uint64_t i;

    femdarr6_t res = femdarr6_createEmpty( nrows, ncols, nip);
    
    for( i = 0; i < res.nip; i++){

        mdarr6_set_all_r( 0.0, &res.p_data[i]);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_ones( uint64_t nrows, uint64_t ncols, uint64_t nip  ){ 
    
    uint64_t i;

    femdarr6_t res = femdarr6_createEmpty( nrows, ncols, nip);
    
    for( i = 0; i < res.nip; i++){

        mdarr6_set_all_r( 1.0, &res.p_data[i]);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t nip){  
    
    uint64_t i;

    femdarr6_t res = femdarr6_init();

    res.nrows    =  nrows;
    res.ncols    =  ncols;
    res.size     =  nrows*ncols;
    
    res.nip  =  nip;

    // Allocate memory.
    res.p_data   = (mdarr6_t*) malloc( res.nip * sizeof(mdarr6_t) );

    // mdnum6array_createEmpty(mdnum6array_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order);
    if (res.p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for( i = 0; i < res.nip; i++){

        res.p_data[i] = mdarr6_createEmpty( nrows, ncols);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_free(femdarr6_t* arr){
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (arr->p_data != NULL){

        // Free all arrays.
        for (i = 0; i<arr->nip; i++){
        
            mdarr6_free(&arr->p_data[i]); 

        }

        // Free pointer 
        free(arr->p_data);

    }

    *arr = femdarr6_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_init(void){
    
    femdarr6_t res;
    
    res.p_data  = NULL;  
    res.nrows   = 0;   
    res.ncols   = 0;   
    res.size    = 0;    
    res.nip = 0; 

    return res;

}
// ----------------------------------------------------------------------------------------------------

