// typedef struct{
//     mdnum7_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } femdnum7_t;

// ****************************************************************************************************
ord_t femdnum7_get_order( femdnum7_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order, mdnum7_get_order(&num->p_data[i]) );
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_get_order_im_to( ord_t order, femdnum7_t* num, femdnum7_t* res){
    
    uint64_t k;

    femdnum7_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_get_order_im_to( order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_get_order_im( ord_t order, femdnum7_t* num){
    
    femdnum7_t res;

    res = femdnum7_zeros( num->nip);

    femdnum7_get_order_im_to( order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_extract_im_to( imdir_t idx, ord_t order, femdnum7_t* num, femdnum7_t* res){
    
    uint64_t k;

    femdnum7_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_extract_im( imdir_t idx, ord_t order, femdnum7_t* num){
    
    femdnum7_t res;

    res = femdnum7_zeros( num->nip);

    femdnum7_extract_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_extract_deriv_to( imdir_t idx, ord_t order, femdnum7_t* num, femdnum7_t* res){
    
    uint64_t k;

    femdnum7_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_extract_deriv( imdir_t idx, ord_t order, femdnum7_t* num){
    
    femdnum7_t res;

    res = femdnum7_zeros( num->nip);

    femdnum7_extract_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_get_deriv_to( imdir_t idx, ord_t order, femdnum7_t* num, femdnum7_t* res){
    
    uint64_t k;

    femdnum7_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_get_deriv( imdir_t idx, ord_t order, femdnum7_t* num){
    
    femdnum7_t res;

    res = femdnum7_zeros( num->nip);

    femdnum7_get_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_get_im_to( imdir_t idx, ord_t order, femdnum7_t* num, femdnum7_t* res){
    
    uint64_t k;

    femdnum7_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_get_im( imdir_t idx, ord_t order, femdnum7_t* num){
    
    femdnum7_t res;

    res = femdnum7_zeros( num->nip);

    femdnum7_get_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_truncate_im_to( imdir_t idx, ord_t order, femdnum7_t* num,  femdnum7_t* res){
    
    uint64_t k;

    femdnum7_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_truncate_im( imdir_t idx, ord_t order, femdnum7_t* num){
    
    femdnum7_t res;

    res = femdnum7_zeros( num->nip);

    femdnum7_truncate_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_im_r( coeff_t val, imdir_t idx, ord_t order, femdnum7_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_set_im_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_im_o( mdnum7_t* val, imdir_t idx, ord_t order, femdnum7_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_set_im_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_im_f( femdnum7_t* val, imdir_t idx, ord_t order, femdnum7_t* num){
    
    uint64_t k;

    femdnum7_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_set_im_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, femdnum7_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_set_deriv_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_deriv_o( mdnum7_t* val, imdir_t idx, ord_t order, femdnum7_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_set_deriv_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_deriv_f( femdnum7_t* val, imdir_t idx, ord_t order, femdnum7_t* num){
    
    uint64_t k;

    femdnum7_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        mdnum7_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_to( femdnum7_t* src, femdnum7_t* dst){
    
    uint64_t i;

    femdnum7_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum7_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_copy( femdnum7_t* src){
    
    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty(src->nip);

    femdnum7_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_copy_to( femdnum7_t* src, femdnum7_t* dst){
    
    uint64_t i;

    femdnum7_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        mdnum7_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_f( femdnum7_t* num, femdnum7_t* res){
    
    femdnum7_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_o( mdnum7_t* num, femdnum7_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum7_set_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_r( coeff_t num, femdnum7_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        mdnum7_set_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_item_k_o( mdnum7_t* num, uint64_t k, femdnum7_t* res){
    
    if (k < res->nip){

        mdnum7_set_o(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum7_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_set_item_k_r(   coeff_t  num, uint64_t k, femdnum7_t* res){

    if (k < res->nip){

        mdnum7_set_r(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in femdnum7_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum7_t femdnum7_get_item_k(femdnum7_t* num, uint64_t k){

    mdnum7_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in femdnum7_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_get_item_k_to(femdnum7_t* num, uint64_t k, mdnum7_t* res){
    
    
    if (k < num->nip){

        mdnum7_copy_to( &num->p_data[k], res);

    } else {

        printf("ERROR: Index out of bounds in femdnum7_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdnum7_zeros(uint64_t nip){

    femdnum7_t  res  = femdnum7_createEmpty(nip);
    
    femdnum7_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum7_t femdnum7_createEmpty(uint64_t nip){

    femdnum7_t  res ;  
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( mdnum7_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of femdnum7.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( mdnum7_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdnum7_free(femdnum7_t* num){

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){
        // Free pointer 
        free(num->p_data);
    }

    *num = femdnum7_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum7_t femdnum7_init(void){
    
    femdnum7_t res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline femdnum7_t femdnum7_empty_like(femdnum7_t* arr){

    femdnum7_t res = femdnum7_createEmpty(arr->nip);

    return res;

}
// ----------------------------------------------------------------------------------------------------

