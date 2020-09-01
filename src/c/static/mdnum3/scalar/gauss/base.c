// typedef struct{
//     mdnum3_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } femdnum3_t;

// ****************************************************************************************************
ord_t femdnum3_get_order( femdnum3_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order, mdnum3_get_order(&num->p_data[i]) );
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_get_order_im_to( ord_t order, femdnum3_t* num, femdnum3_t* res){
    
    uint64_t k;

    femdnum3_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_get_order_im_to( order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_get_order_im( ord_t order, femdnum3_t* num){
    
    femdnum3_t res;

    res = femdnum3_zeros( num->nip);

    femdnum3_get_order_im_to( order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_extract_im_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res){
    
    uint64_t k;

    femdnum3_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_extract_im( imdir_t idx, ord_t order, femdnum3_t* num){
    
    femdnum3_t res;

    res = femdnum3_zeros( num->nip);

    femdnum3_extract_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_extract_deriv_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res){
    
    uint64_t k;

    femdnum3_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_extract_deriv( imdir_t idx, ord_t order, femdnum3_t* num){
    
    femdnum3_t res;

    res = femdnum3_zeros( num->nip);

    femdnum3_extract_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_get_deriv_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res){
    
    uint64_t k;

    femdnum3_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_get_deriv( imdir_t idx, ord_t order, femdnum3_t* num){
    
    femdnum3_t res;

    res = femdnum3_zeros( num->nip);

    femdnum3_get_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_get_im_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res){
    
    uint64_t k;

    femdnum3_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_get_im( imdir_t idx, ord_t order, femdnum3_t* num){
    
    femdnum3_t res;

    res = femdnum3_zeros( num->nip);

    femdnum3_get_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_truncate_im_to( imdir_t idx, ord_t order, femdnum3_t* num,  femdnum3_t* res){
    
    uint64_t k;

    femdnum3_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_truncate_im( imdir_t idx, ord_t order, femdnum3_t* num){
    
    femdnum3_t res;

    res = femdnum3_zeros( num->nip);

    femdnum3_truncate_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_im_r( coeff_t val, imdir_t idx, ord_t order, femdnum3_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_set_im_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_im_o( mdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_set_im_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_im_f( femdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num){
    
    uint64_t k;

    femdnum3_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_set_im_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, femdnum3_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_set_deriv_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_deriv_o( mdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_set_deriv_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_deriv_f( femdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num){
    
    uint64_t k;

    femdnum3_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum3_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_to( femdnum3_t* src, femdnum3_t* dst){
    
    uint64_t i;

    femdnum3_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum3_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_copy( femdnum3_t* src){
    
    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty(src->nip);

    femdnum3_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_copy_to( femdnum3_t* src, femdnum3_t* dst){
    
    uint64_t i;

    femdnum3_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum3_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_f( femdnum3_t* num, femdnum3_t* res){
    
    femdnum3_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_o( mdnum3_t* num, femdnum3_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum3_set_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_r( coeff_t num, femdnum3_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum3_set_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_item_k_o( mdnum3_t* num, uint64_t k, femdnum3_t* res){
    
    if (k < res->nip){

        mdnum3_set_o(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum3_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_set_item_k_r(   coeff_t  num, uint64_t k, femdnum3_t* res){

    if (k < res->nip){

        mdnum3_set_r(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum3_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum3_t femdnum3_get_item_k(femdnum3_t* num, uint64_t k){

    mdnum3_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in femdnum3_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_get_item_k_to(femdnum3_t* num, uint64_t k, mdnum3_t* res){
    
    
    if (k < num->nip){

        mdnum3_copy_to( &num->p_data[k], res);

    } else {

        printf("ERROR: Index out of bounds in femdnum3_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdnum3_zeros(uint64_t nip){

    femdnum3_t  res  = femdnum3_createEmpty(nip);
    
    femdnum3_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum3_t femdnum3_createEmpty(uint64_t nip){

    femdnum3_t  res ;  
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( mdnum3_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of femdnum3.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( mdnum3_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum3_free(femdnum3_t* num){

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){
        // Free pointer 
        free(num->p_data);
    }

    *num = femdnum3_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum3_t femdnum3_init(void){
    
    femdnum3_t res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum3_t femdnum3_empty_like(femdnum3_t* arr){

    femdnum3_t res = femdnum3_createEmpty(arr->nip);

    return res;

}
// ----------------------------------------------------------------------------------------------------

