// typedef struct{
//     mdnum4_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } femdnum4_t;

// ****************************************************************************************************
ord_t femdnum4_get_order( femdnum4_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order, mdnum4_get_order(&num->p_data[i]) );
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_get_order_im_to( ord_t order, femdnum4_t* num, femdnum4_t* res){
    
    uint64_t k;

    femdnum4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_get_order_im_to( order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_get_order_im( ord_t order, femdnum4_t* num){
    
    femdnum4_t res;

    res = femdnum4_zeros( num->nip);

    femdnum4_get_order_im_to( order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_extract_im_to( imdir_t idx, ord_t order, femdnum4_t* num, femdnum4_t* res){
    
    uint64_t k;

    femdnum4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_extract_im( imdir_t idx, ord_t order, femdnum4_t* num){
    
    femdnum4_t res;

    res = femdnum4_zeros( num->nip);

    femdnum4_extract_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_extract_deriv_to( imdir_t idx, ord_t order, femdnum4_t* num, femdnum4_t* res){
    
    uint64_t k;

    femdnum4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_extract_deriv( imdir_t idx, ord_t order, femdnum4_t* num){
    
    femdnum4_t res;

    res = femdnum4_zeros( num->nip);

    femdnum4_extract_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_get_deriv_to( imdir_t idx, ord_t order, femdnum4_t* num, femdnum4_t* res){
    
    uint64_t k;

    femdnum4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_get_deriv( imdir_t idx, ord_t order, femdnum4_t* num){
    
    femdnum4_t res;

    res = femdnum4_zeros( num->nip);

    femdnum4_get_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_get_im_to( imdir_t idx, ord_t order, femdnum4_t* num, femdnum4_t* res){
    
    uint64_t k;

    femdnum4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_get_im( imdir_t idx, ord_t order, femdnum4_t* num){
    
    femdnum4_t res;

    res = femdnum4_zeros( num->nip);

    femdnum4_get_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_truncate_im_to( imdir_t idx, ord_t order, femdnum4_t* num,  femdnum4_t* res){
    
    uint64_t k;

    femdnum4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_truncate_im( imdir_t idx, ord_t order, femdnum4_t* num){
    
    femdnum4_t res;

    res = femdnum4_zeros( num->nip);

    femdnum4_truncate_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_im_r( coeff_t val, imdir_t idx, ord_t order, femdnum4_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_set_im_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_im_o( mdnum4_t* val, imdir_t idx, ord_t order, femdnum4_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_set_im_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_im_f( femdnum4_t* val, imdir_t idx, ord_t order, femdnum4_t* num){
    
    uint64_t k;

    femdnum4_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_set_im_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, femdnum4_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_set_deriv_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_deriv_o( mdnum4_t* val, imdir_t idx, ord_t order, femdnum4_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_set_deriv_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_deriv_f( femdnum4_t* val, imdir_t idx, ord_t order, femdnum4_t* num){
    
    uint64_t k;

    femdnum4_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum4_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_to( femdnum4_t* src, femdnum4_t* dst){
    
    uint64_t i;

    femdnum4_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum4_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_copy( femdnum4_t* src){
    
    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty(src->nip);

    femdnum4_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_copy_to( femdnum4_t* src, femdnum4_t* dst){
    
    uint64_t i;

    femdnum4_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum4_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_f( femdnum4_t* num, femdnum4_t* res){
    
    femdnum4_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_o( mdnum4_t* num, femdnum4_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum4_set_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_r( coeff_t num, femdnum4_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum4_set_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_item_k_o( mdnum4_t* num, uint64_t k, femdnum4_t* res){
    
    if (k < res->nip){

        mdnum4_set_o(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum4_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_set_item_k_r(   coeff_t  num, uint64_t k, femdnum4_t* res){

    if (k < res->nip){

        mdnum4_set_r(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum4_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum4_t femdnum4_get_item_k(femdnum4_t* num, uint64_t k){

    mdnum4_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in femdnum4_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_get_item_k_to(femdnum4_t* num, uint64_t k, mdnum4_t* res){
    
    
    if (k < num->nip){

        mdnum4_copy_to( &num->p_data[k], res);

    } else {

        printf("ERROR: Index out of bounds in femdnum4_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdnum4_zeros(uint64_t nip){

    femdnum4_t  res  = femdnum4_createEmpty(nip);
    
    femdnum4_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum4_t femdnum4_createEmpty(uint64_t nip){

    femdnum4_t  res ;  
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( mdnum4_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of femdnum4.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( mdnum4_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum4_free(femdnum4_t* num){

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){
        // Free pointer 
        free(num->p_data);
    }

    *num = femdnum4_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum4_t femdnum4_init(void){
    
    femdnum4_t res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum4_t femdnum4_empty_like(femdnum4_t* arr){

    femdnum4_t res = femdnum4_createEmpty(arr->nip);

    return res;

}
// ----------------------------------------------------------------------------------------------------

