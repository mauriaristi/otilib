// typedef struct{
//     mdnum8_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } femdnum8_t;

// ****************************************************************************************************
ord_t femdnum8_get_order( femdnum8_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order, mdnum8_get_order(&num->p_data[i]) );
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_get_order_im_to( ord_t order, femdnum8_t* num, femdnum8_t* res){
    
    uint64_t k;

    femdnum8_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_get_order_im_to( order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_get_order_im( ord_t order, femdnum8_t* num){
    
    femdnum8_t res;

    res = femdnum8_zeros( num->nip);

    femdnum8_get_order_im_to( order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_extract_im_to( imdir_t idx, ord_t order, femdnum8_t* num, femdnum8_t* res){
    
    uint64_t k;

    femdnum8_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_extract_im( imdir_t idx, ord_t order, femdnum8_t* num){
    
    femdnum8_t res;

    res = femdnum8_zeros( num->nip);

    femdnum8_extract_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_extract_deriv_to( imdir_t idx, ord_t order, femdnum8_t* num, femdnum8_t* res){
    
    uint64_t k;

    femdnum8_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_extract_deriv( imdir_t idx, ord_t order, femdnum8_t* num){
    
    femdnum8_t res;

    res = femdnum8_zeros( num->nip);

    femdnum8_extract_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_get_deriv_to( imdir_t idx, ord_t order, femdnum8_t* num, femdnum8_t* res){
    
    uint64_t k;

    femdnum8_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_get_deriv( imdir_t idx, ord_t order, femdnum8_t* num){
    
    femdnum8_t res;

    res = femdnum8_zeros( num->nip);

    femdnum8_get_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_get_im_to( imdir_t idx, ord_t order, femdnum8_t* num, femdnum8_t* res){
    
    uint64_t k;

    femdnum8_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_get_im( imdir_t idx, ord_t order, femdnum8_t* num){
    
    femdnum8_t res;

    res = femdnum8_zeros( num->nip);

    femdnum8_get_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_truncate_im_to( imdir_t idx, ord_t order, femdnum8_t* num,  femdnum8_t* res){
    
    uint64_t k;

    femdnum8_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_truncate_im( imdir_t idx, ord_t order, femdnum8_t* num){
    
    femdnum8_t res;

    res = femdnum8_zeros( num->nip);

    femdnum8_truncate_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_im_r( coeff_t val, imdir_t idx, ord_t order, femdnum8_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_set_im_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_im_o( mdnum8_t* val, imdir_t idx, ord_t order, femdnum8_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_set_im_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_im_f( femdnum8_t* val, imdir_t idx, ord_t order, femdnum8_t* num){
    
    uint64_t k;

    femdnum8_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_set_im_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, femdnum8_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_set_deriv_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_deriv_o( mdnum8_t* val, imdir_t idx, ord_t order, femdnum8_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_set_deriv_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_deriv_f( femdnum8_t* val, imdir_t idx, ord_t order, femdnum8_t* num){
    
    uint64_t k;

    femdnum8_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum8_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_to( femdnum8_t* src, femdnum8_t* dst){
    
    uint64_t i;

    femdnum8_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum8_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_copy( femdnum8_t* src){
    
    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty(src->nip);

    femdnum8_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_copy_to( femdnum8_t* src, femdnum8_t* dst){
    
    uint64_t i;

    femdnum8_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum8_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_f( femdnum8_t* num, femdnum8_t* res){
    
    femdnum8_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_o( mdnum8_t* num, femdnum8_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum8_set_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_r( coeff_t num, femdnum8_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum8_set_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_item_k_o( mdnum8_t* num, uint64_t k, femdnum8_t* res){
    
    if (k < res->nip){

        mdnum8_set_o(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum8_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_set_item_k_r(   coeff_t  num, uint64_t k, femdnum8_t* res){

    if (k < res->nip){

        mdnum8_set_r(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum8_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum8_t femdnum8_get_item_k(femdnum8_t* num, uint64_t k){

    mdnum8_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in femdnum8_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_get_item_k_to(femdnum8_t* num, uint64_t k, mdnum8_t* res){
    
    
    if (k < num->nip){

        mdnum8_copy_to( &num->p_data[k], res);

    } else {

        printf("ERROR: Index out of bounds in femdnum8_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdnum8_zeros(uint64_t nip){

    femdnum8_t  res  = femdnum8_createEmpty(nip);
    
    femdnum8_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum8_t femdnum8_createEmpty(uint64_t nip){

    femdnum8_t  res ;  
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( mdnum8_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of femdnum8.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( mdnum8_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum8_free(femdnum8_t* num){

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){
        // Free pointer 
        free(num->p_data);
    }

    *num = femdnum8_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum8_t femdnum8_init(void){
    
    femdnum8_t res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum8_t femdnum8_empty_like(femdnum8_t* arr){

    femdnum8_t res = femdnum8_createEmpty(arr->nip);

    return res;

}
// ----------------------------------------------------------------------------------------------------

