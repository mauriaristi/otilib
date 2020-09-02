// typedef struct{
//     onumm2n6_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } feonumm2n6_t;

// ****************************************************************************************************
ord_t feonumm2n6_get_order( feonumm2n6_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order, onumm2n6_get_order(&num->p_data[i]) );
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_get_order_im_to( ord_t order, feonumm2n6_t* num, feonumm2n6_t* res){
    
    uint64_t k;

    feonumm2n6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_get_order_im_to( order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n6_t feonumm2n6_get_order_im( ord_t order, feonumm2n6_t* num){
    
    feonumm2n6_t res;

    res = feonumm2n6_zeros( num->nip);

    feonumm2n6_get_order_im_to( order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_extract_im_to( imdir_t idx, ord_t order, feonumm2n6_t* num, feonumm2n6_t* res){
    
    uint64_t k;

    feonumm2n6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n6_t feonumm2n6_extract_im( imdir_t idx, ord_t order, feonumm2n6_t* num){
    
    feonumm2n6_t res;

    res = feonumm2n6_zeros( num->nip);

    feonumm2n6_extract_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_extract_deriv_to( imdir_t idx, ord_t order, feonumm2n6_t* num, feonumm2n6_t* res){
    
    uint64_t k;

    feonumm2n6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n6_t feonumm2n6_extract_deriv( imdir_t idx, ord_t order, feonumm2n6_t* num){
    
    feonumm2n6_t res;

    res = feonumm2n6_zeros( num->nip);

    feonumm2n6_extract_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_get_deriv_to( imdir_t idx, ord_t order, feonumm2n6_t* num, feonumm2n6_t* res){
    
    uint64_t k;

    feonumm2n6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n6_t feonumm2n6_get_deriv( imdir_t idx, ord_t order, feonumm2n6_t* num){
    
    feonumm2n6_t res;

    res = feonumm2n6_zeros( num->nip);

    feonumm2n6_get_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_get_im_to( imdir_t idx, ord_t order, feonumm2n6_t* num, feonumm2n6_t* res){
    
    uint64_t k;

    feonumm2n6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n6_t feonumm2n6_get_im( imdir_t idx, ord_t order, feonumm2n6_t* num){
    
    feonumm2n6_t res;

    res = feonumm2n6_zeros( num->nip);

    feonumm2n6_get_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_truncate_im_to( imdir_t idx, ord_t order, feonumm2n6_t* num,  feonumm2n6_t* res){
    
    uint64_t k;

    feonumm2n6_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n6_t feonumm2n6_truncate_im( imdir_t idx, ord_t order, feonumm2n6_t* num){
    
    feonumm2n6_t res;

    res = feonumm2n6_zeros( num->nip);

    feonumm2n6_truncate_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_im_r( coeff_t val, imdir_t idx, ord_t order, feonumm2n6_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_set_im_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_im_o( onumm2n6_t* val, imdir_t idx, ord_t order, feonumm2n6_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_set_im_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_im_f( feonumm2n6_t* val, imdir_t idx, ord_t order, feonumm2n6_t* num){
    
    uint64_t k;

    feonumm2n6_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_set_im_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, feonumm2n6_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_set_deriv_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_deriv_o( onumm2n6_t* val, imdir_t idx, ord_t order, feonumm2n6_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_set_deriv_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_deriv_f( feonumm2n6_t* val, imdir_t idx, ord_t order, feonumm2n6_t* num){
    
    uint64_t k;

    feonumm2n6_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        onumm2n6_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_to( feonumm2n6_t* src, feonumm2n6_t* dst){
    
    uint64_t i;

    feonumm2n6_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        onumm2n6_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n6_t feonumm2n6_copy( feonumm2n6_t* src){
    
    feonumm2n6_t res = feonumm2n6_init();

    res = feonumm2n6_createEmpty(src->nip);

    feonumm2n6_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_copy_to( feonumm2n6_t* src, feonumm2n6_t* dst){
    
    uint64_t i;

    feonumm2n6_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        onumm2n6_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_f( feonumm2n6_t* num, feonumm2n6_t* res){
    
    feonumm2n6_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_o( onumm2n6_t* num, feonumm2n6_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        onumm2n6_set_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_r( coeff_t num, feonumm2n6_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        onumm2n6_set_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_item_k_o( onumm2n6_t* num, uint64_t k, feonumm2n6_t* res){
    
    if (k < res->nip){

        onumm2n6_set_o(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in feonumm2n6_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_set_item_k_r(   coeff_t  num, uint64_t k, feonumm2n6_t* res){

    if (k < res->nip){

        onumm2n6_set_r(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in feonumm2n6_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm2n6_t feonumm2n6_get_item_k(feonumm2n6_t* num, uint64_t k){

    onumm2n6_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in feonumm2n6_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_get_item_k_to(feonumm2n6_t* num, uint64_t k, onumm2n6_t* res){
    
    
    if (k < num->nip){

        onumm2n6_copy_to( &num->p_data[k], res);

    } else {

        printf("ERROR: Index out of bounds in feonumm2n6_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n6_t feonumm2n6_zeros(uint64_t nip){

    feonumm2n6_t  res  = feonumm2n6_createEmpty(nip);
    
    feonumm2n6_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline feonumm2n6_t feonumm2n6_createEmpty(uint64_t nip){

    feonumm2n6_t  res ;  
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( onumm2n6_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of feonumm2n6.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( onumm2n6_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n6_free(feonumm2n6_t* num){

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){
        // Free pointer 
        free(num->p_data);
    }

    *num = feonumm2n6_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline feonumm2n6_t feonumm2n6_init(void){
    
    feonumm2n6_t res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline feonumm2n6_t feonumm2n6_empty_like(feonumm2n6_t* arr){

    feonumm2n6_t res = feonumm2n6_createEmpty(arr->nip);

    return res;

}
// ----------------------------------------------------------------------------------------------------

