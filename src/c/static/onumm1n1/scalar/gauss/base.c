// typedef struct{
//     onumm1n1_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } feonumm1n1_t;

// ****************************************************************************************************
ord_t feonumm1n1_get_order( feonumm1n1_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order, onumm1n1_get_order(&num->p_data[i]) );
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_get_order_im_to( ord_t order, feonumm1n1_t* num, feonumm1n1_t* res){
    
    uint64_t k;

    feonumm1n1_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_get_order_im_to( order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n1_t feonumm1n1_get_order_im( ord_t order, feonumm1n1_t* num){
    
    feonumm1n1_t res;

    res = feonumm1n1_zeros( num->nip);

    feonumm1n1_get_order_im_to( order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_extract_im_to( imdir_t idx, ord_t order, feonumm1n1_t* num, feonumm1n1_t* res){
    
    uint64_t k;

    feonumm1n1_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n1_t feonumm1n1_extract_im( imdir_t idx, ord_t order, feonumm1n1_t* num){
    
    feonumm1n1_t res;

    res = feonumm1n1_zeros( num->nip);

    feonumm1n1_extract_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_extract_deriv_to( imdir_t idx, ord_t order, feonumm1n1_t* num, feonumm1n1_t* res){
    
    uint64_t k;

    feonumm1n1_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n1_t feonumm1n1_extract_deriv( imdir_t idx, ord_t order, feonumm1n1_t* num){
    
    feonumm1n1_t res;

    res = feonumm1n1_zeros( num->nip);

    feonumm1n1_extract_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_get_deriv_to( imdir_t idx, ord_t order, feonumm1n1_t* num, feonumm1n1_t* res){
    
    uint64_t k;

    feonumm1n1_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n1_t feonumm1n1_get_deriv( imdir_t idx, ord_t order, feonumm1n1_t* num){
    
    feonumm1n1_t res;

    res = feonumm1n1_zeros( num->nip);

    feonumm1n1_get_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_get_im_to( imdir_t idx, ord_t order, feonumm1n1_t* num, feonumm1n1_t* res){
    
    uint64_t k;

    feonumm1n1_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n1_t feonumm1n1_get_im( imdir_t idx, ord_t order, feonumm1n1_t* num){
    
    feonumm1n1_t res;

    res = feonumm1n1_zeros( num->nip);

    feonumm1n1_get_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_truncate_im_to( imdir_t idx, ord_t order, feonumm1n1_t* num,  feonumm1n1_t* res){
    
    uint64_t k;

    feonumm1n1_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n1_t feonumm1n1_truncate_im( imdir_t idx, ord_t order, feonumm1n1_t* num){
    
    feonumm1n1_t res;

    res = feonumm1n1_zeros( num->nip);

    feonumm1n1_truncate_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_im_r( coeff_t val, imdir_t idx, ord_t order, feonumm1n1_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_set_im_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_im_o( onumm1n1_t* val, imdir_t idx, ord_t order, feonumm1n1_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_set_im_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_im_f( feonumm1n1_t* val, imdir_t idx, ord_t order, feonumm1n1_t* num){
    
    uint64_t k;

    feonumm1n1_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_set_im_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, feonumm1n1_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_set_deriv_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_deriv_o( onumm1n1_t* val, imdir_t idx, ord_t order, feonumm1n1_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_set_deriv_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_deriv_f( feonumm1n1_t* val, imdir_t idx, ord_t order, feonumm1n1_t* num){
    
    uint64_t k;

    feonumm1n1_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        onumm1n1_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_to( feonumm1n1_t* src, feonumm1n1_t* dst){
    
    uint64_t i;

    feonumm1n1_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        onumm1n1_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n1_t feonumm1n1_copy( feonumm1n1_t* src){
    
    feonumm1n1_t res = feonumm1n1_init();

    res = feonumm1n1_createEmpty(src->nip);

    feonumm1n1_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_copy_to( feonumm1n1_t* src, feonumm1n1_t* dst){
    
    uint64_t i;

    feonumm1n1_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        onumm1n1_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_f( feonumm1n1_t* num, feonumm1n1_t* res){
    
    feonumm1n1_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_o( onumm1n1_t* num, feonumm1n1_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        onumm1n1_set_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_r( coeff_t num, feonumm1n1_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        onumm1n1_set_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_item_k_o( onumm1n1_t* num, uint64_t k, feonumm1n1_t* res){
    
    if (k < res->nip){

        onumm1n1_set_o(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in feonumm1n1_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_set_item_k_r(   coeff_t  num, uint64_t k, feonumm1n1_t* res){

    if (k < res->nip){

        onumm1n1_set_r(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in feonumm1n1_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n1_t feonumm1n1_get_item_k(feonumm1n1_t* num, uint64_t k){

    onumm1n1_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in feonumm1n1_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_get_item_k_to(feonumm1n1_t* num, uint64_t k, onumm1n1_t* res){
    
    
    if (k < num->nip){

        onumm1n1_copy_to( &num->p_data[k], res);

    } else {

        printf("ERROR: Index out of bounds in feonumm1n1_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n1_t feonumm1n1_zeros(uint64_t nip){

    feonumm1n1_t  res  = feonumm1n1_createEmpty(nip);
    
    feonumm1n1_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline feonumm1n1_t feonumm1n1_createEmpty(uint64_t nip){

    feonumm1n1_t  res ;  
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( onumm1n1_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of feonumm1n1.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( onumm1n1_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n1_free(feonumm1n1_t* num){

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){
        // Free pointer 
        free(num->p_data);
    }

    *num = feonumm1n1_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline feonumm1n1_t feonumm1n1_init(void){
    
    feonumm1n1_t res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline feonumm1n1_t feonumm1n1_empty_like(feonumm1n1_t* arr){

    feonumm1n1_t res = feonumm1n1_createEmpty(arr->nip);

    return res;

}
// ----------------------------------------------------------------------------------------------------

