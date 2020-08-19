// typedef struct{
//     mdnum2_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } femdnum2_t;

// ****************************************************************************************************
ord_t femdnum2_get_order( femdnum2_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order,num->p_data[0].order);
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_get_order_im_to( ord_t order, femdnum2_t* num, femdnum2_t* res){
    
    uint64_t k;

    femdnum2_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_get_order_im_to( order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_get_order_im( ord_t order, femdnum2_t* num){
    
    femdnum2_t res;

    res = femdnum2_zeros( num->nip);

    femdnum2_get_order_im_to( order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_extract_im_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res){
    
    uint64_t k;

    femdnum2_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_extract_im( imdir_t idx, ord_t order, femdnum2_t* num){
    
    femdnum2_t res;

    res = femdnum2_zeros( num->nip);

    femdnum2_extract_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_extract_deriv_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res){
    
    uint64_t k;

    femdnum2_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_extract_deriv( imdir_t idx, ord_t order, femdnum2_t* num){
    
    femdnum2_t res;

    res = femdnum2_zeros( num->nip);

    femdnum2_extract_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_get_deriv_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res){
    
    uint64_t k;

    femdnum2_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_get_deriv( imdir_t idx, ord_t order, femdnum2_t* num){
    
    femdnum2_t res;

    res = femdnum2_zeros( num->nip);

    femdnum2_get_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_get_im_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res){
    
    uint64_t k;

    femdnum2_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_get_im( imdir_t idx, ord_t order, femdnum2_t* num){
    
    femdnum2_t res;

    res = femdnum2_zeros( num->nip);

    femdnum2_get_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_truncate_im_to( imdir_t idx, ord_t order, femdnum2_t* num,  femdnum2_t* res){
    
    uint64_t k;

    femdnum2_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_truncate_im( imdir_t idx, ord_t order, femdnum2_t* num){
    
    femdnum2_t res;

    res = femdnum2_zeros( num->nip);

    femdnum2_truncate_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_im_r( coeff_t val, imdir_t idx, ord_t order, femdnum2_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_set_im_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_im_o( mdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_set_im_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_im_f( femdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num){
    
    uint64_t k;

    femdnum2_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_set_im_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, femdnum2_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_set_deriv_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_deriv_o( mdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_set_deriv_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_deriv_f( femdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num){
    
    uint64_t k;

    femdnum2_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum2_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_to( femdnum2_t* src, femdnum2_t* dst){
    
    uint64_t i;

    femdnum2_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum2_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_copy( femdnum2_t* src){
    
    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty(src->nip);

    femdnum2_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_copy_to( femdnum2_t* src, femdnum2_t* dst){
    
    uint64_t i;

    femdnum2_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum2_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_f( femdnum2_t* num, femdnum2_t* res){
    
    femdnum2_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_o( mdnum2_t* num, femdnum2_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum2_set_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_r( coeff_t num, femdnum2_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum2_set_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_item_k_o( mdnum2_t* num, uint64_t k, femdnum2_t* res){
    
    if (k < res->nip){

        mdnum2_set_o(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum2_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_set_item_k_r(   coeff_t  num, uint64_t k, femdnum2_t* res){

    if (k < res->nip){

        mdnum2_set_r(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum2_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum2_t femdnum2_get_item_k(femdnum2_t* num, uint64_t k){

    mdnum2_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];   
        res.flag = 0;

    } else {

        printf("ERROR: Index out of bounds in femdnum2_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_get_item_k_to(femdnum2_t* num, uint64_t k, mdnum2_t* res){
    
    
    if (k < num->nip){

        mdnum2_copy_to( &num->p_data[k], res);

    } else {

        printf("ERROR: Index out of bounds in femdnum2_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdnum2_zeros(uint64_t nip){

    femdnum2_t  res  = femdnum2_createEmpty(nip);
    
    femdnum2_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum2_t femdnum2_createEmpty(uint64_t nip){

    femdnum2_t  res ;
    ndir_t p_nnz[_MAXORDER_OTI];
    ord_t    ordi;
    uint64_t i;    
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( mdnum2_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of femdnum2.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( mdnum2_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum2_free(femdnum2_t* num){
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){

        // Free all arrays.
        for (i = 0; i<num->nip; i++){
        
            mdnum2_free(&num->p_data[i]); 

        }

        // Free pointer 
        free(num->p_data);

    }

    *num = femdnum2_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum2_t femdnum2_init(void){
    
    femdnum2_t res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum2_t femdnum2_empty_like(femdnum2_t* arr){

    femdnum2_t res = femdnum2_createEmpty(arr->nip, 0, 0);

    return res;

}
// ----------------------------------------------------------------------------------------------------

