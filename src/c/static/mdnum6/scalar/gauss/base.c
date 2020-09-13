// typedef struct{
//     mdnum6_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } femdnum6_t;

// ****************************************************************************************************
ord_t femdnum6_get_order( femdnum6_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order, mdnum6_get_order(&num->p_data[i]) );
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_get_order_im_to( ord_t order, femdnum6_t* num, femdnum6_t* res){
    
    uint64_t k;

    femdnum6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_get_order_im_to( order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_get_order_im( ord_t order, femdnum6_t* num){
    
    femdnum6_t res;

    res = femdnum6_zeros( num->nip);

    femdnum6_get_order_im_to( order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_extract_im_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res){
    
    uint64_t k;

    femdnum6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_extract_im( imdir_t idx, ord_t order, femdnum6_t* num){
    
    femdnum6_t res;

    res = femdnum6_zeros( num->nip);

    femdnum6_extract_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_extract_deriv_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res){
    
    uint64_t k;

    femdnum6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_extract_deriv( imdir_t idx, ord_t order, femdnum6_t* num){
    
    femdnum6_t res;

    res = femdnum6_zeros( num->nip);

    femdnum6_extract_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_get_deriv_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res){
    
    uint64_t k;

    femdnum6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_get_deriv( imdir_t idx, ord_t order, femdnum6_t* num){
    
    femdnum6_t res;

    res = femdnum6_zeros( num->nip);

    femdnum6_get_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_get_im_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res){
    
    uint64_t k;

    femdnum6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_get_im( imdir_t idx, ord_t order, femdnum6_t* num){
    
    femdnum6_t res;

    res = femdnum6_zeros( num->nip);

    femdnum6_get_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_truncate_im_to( imdir_t idx, ord_t order, femdnum6_t* num,  femdnum6_t* res){
    
    uint64_t k;

    femdnum6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_truncate_im( imdir_t idx, ord_t order, femdnum6_t* num){
    
    femdnum6_t res;

    res = femdnum6_zeros( num->nip);

    femdnum6_truncate_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_im_r( coeff_t val, imdir_t idx, ord_t order, femdnum6_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_set_im_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_im_o( mdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_set_im_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_im_f( femdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num){
    
    uint64_t k;

    femdnum6_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_set_im_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, femdnum6_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_set_deriv_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_deriv_o( mdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_set_deriv_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_deriv_f( femdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num){
    
    uint64_t k;

    femdnum6_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum6_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_to( femdnum6_t* src, femdnum6_t* dst){
    
    uint64_t i;

    femdnum6_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum6_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_copy( femdnum6_t* src){
    
    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty(src->nip);

    femdnum6_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_copy_to( femdnum6_t* src, femdnum6_t* dst){
    
    uint64_t i;

    femdnum6_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum6_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_f( femdnum6_t* num, femdnum6_t* res){
    
    femdnum6_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_o( mdnum6_t* num, femdnum6_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum6_set_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_r( coeff_t num, femdnum6_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum6_set_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_item_k_o( mdnum6_t* num, uint64_t k, femdnum6_t* res){
    
    if (k < res->nip){

        mdnum6_set_o(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum6_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_set_item_k_r(   coeff_t  num, uint64_t k, femdnum6_t* res){

    if (k < res->nip){

        mdnum6_set_r(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum6_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum6_t femdnum6_get_item_k(femdnum6_t* num, uint64_t k){

    mdnum6_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in femdnum6_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_get_item_k_to(femdnum6_t* num, uint64_t k, mdnum6_t* res){
    
    
    if (k < num->nip){

        mdnum6_copy_to( &num->p_data[k], res);

    } else {

        printf("ERROR: Index out of bounds in femdnum6_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdnum6_zeros(uint64_t nip){

    femdnum6_t  res  = femdnum6_createEmpty(nip);
    
    femdnum6_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum6_t femdnum6_createEmpty(uint64_t nip){

    femdnum6_t  res ;  
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( mdnum6_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of femdnum6.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( mdnum6_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum6_free(femdnum6_t* num){

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){
        // Free pointer 
        free(num->p_data);
    }

    *num = femdnum6_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum6_t femdnum6_init(void){
    
    femdnum6_t res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum6_t femdnum6_empty_like(femdnum6_t* arr){

    femdnum6_t res = femdnum6_createEmpty(arr->nip);

    return res;

}
// ----------------------------------------------------------------------------------------------------

