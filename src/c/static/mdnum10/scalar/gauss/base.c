// typedef struct{
//     mdnum10_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } femdnum10_t;

// ****************************************************************************************************
ord_t femdnum10_get_order( femdnum10_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order, mdnum10_get_order(&num->p_data[i]) );
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_get_order_im_to( ord_t order, femdnum10_t* num, femdnum10_t* res){
    
    uint64_t k;

    femdnum10_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_get_order_im_to( order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_get_order_im( ord_t order, femdnum10_t* num){
    
    femdnum10_t res;

    res = femdnum10_zeros( num->nip);

    femdnum10_get_order_im_to( order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_extract_im_to( imdir_t idx, ord_t order, femdnum10_t* num, femdnum10_t* res){
    
    uint64_t k;

    femdnum10_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_extract_im( imdir_t idx, ord_t order, femdnum10_t* num){
    
    femdnum10_t res;

    res = femdnum10_zeros( num->nip);

    femdnum10_extract_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_extract_deriv_to( imdir_t idx, ord_t order, femdnum10_t* num, femdnum10_t* res){
    
    uint64_t k;

    femdnum10_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_extract_deriv( imdir_t idx, ord_t order, femdnum10_t* num){
    
    femdnum10_t res;

    res = femdnum10_zeros( num->nip);

    femdnum10_extract_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_get_deriv_to( imdir_t idx, ord_t order, femdnum10_t* num, femdnum10_t* res){
    
    uint64_t k;

    femdnum10_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_get_deriv( imdir_t idx, ord_t order, femdnum10_t* num){
    
    femdnum10_t res;

    res = femdnum10_zeros( num->nip);

    femdnum10_get_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_get_im_to( imdir_t idx, ord_t order, femdnum10_t* num, femdnum10_t* res){
    
    uint64_t k;

    femdnum10_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_get_im( imdir_t idx, ord_t order, femdnum10_t* num){
    
    femdnum10_t res;

    res = femdnum10_zeros( num->nip);

    femdnum10_get_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_truncate_im_to( imdir_t idx, ord_t order, femdnum10_t* num,  femdnum10_t* res){
    
    uint64_t k;

    femdnum10_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_truncate_im( imdir_t idx, ord_t order, femdnum10_t* num){
    
    femdnum10_t res;

    res = femdnum10_zeros( num->nip);

    femdnum10_truncate_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_im_r( coeff_t val, imdir_t idx, ord_t order, femdnum10_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_set_im_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_im_o( mdnum10_t* val, imdir_t idx, ord_t order, femdnum10_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_set_im_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_im_f( femdnum10_t* val, imdir_t idx, ord_t order, femdnum10_t* num){
    
    uint64_t k;

    femdnum10_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_set_im_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, femdnum10_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_set_deriv_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_deriv_o( mdnum10_t* val, imdir_t idx, ord_t order, femdnum10_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_set_deriv_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_deriv_f( femdnum10_t* val, imdir_t idx, ord_t order, femdnum10_t* num){
    
    uint64_t k;

    femdnum10_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum10_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_to( femdnum10_t* src, femdnum10_t* dst){
    
    uint64_t i;

    femdnum10_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum10_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_copy( femdnum10_t* src){
    
    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty(src->nip);

    femdnum10_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_copy_to( femdnum10_t* src, femdnum10_t* dst){
    
    uint64_t i;

    femdnum10_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum10_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_f( femdnum10_t* num, femdnum10_t* res){
    
    femdnum10_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_o( mdnum10_t* num, femdnum10_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum10_set_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_r( coeff_t num, femdnum10_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum10_set_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_item_k_o( mdnum10_t* num, uint64_t k, femdnum10_t* res){
    
    if (k < res->nip){

        mdnum10_set_o(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum10_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_set_item_k_r(   coeff_t  num, uint64_t k, femdnum10_t* res){

    if (k < res->nip){

        mdnum10_set_r(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum10_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum10_t femdnum10_get_item_k(femdnum10_t* num, uint64_t k){

    mdnum10_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in femdnum10_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_get_item_k_to(femdnum10_t* num, uint64_t k, mdnum10_t* res){
    
    
    if (k < num->nip){

        mdnum10_copy_to( &num->p_data[k], res);

    } else {

        printf("ERROR: Index out of bounds in femdnum10_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdnum10_zeros(uint64_t nip){

    femdnum10_t  res  = femdnum10_createEmpty(nip);
    
    femdnum10_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum10_t femdnum10_createEmpty(uint64_t nip){

    femdnum10_t  res ;  
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( mdnum10_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of femdnum10.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( mdnum10_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum10_free(femdnum10_t* num){

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){
        // Free pointer 
        free(num->p_data);
    }

    *num = femdnum10_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum10_t femdnum10_init(void){
    
    femdnum10_t res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum10_t femdnum10_empty_like(femdnum10_t* arr){

    femdnum10_t res = femdnum10_createEmpty(arr->nip);

    return res;

}
// ----------------------------------------------------------------------------------------------------

