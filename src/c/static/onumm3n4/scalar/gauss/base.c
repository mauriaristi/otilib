// typedef struct{
//     onumm3n4_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } feonumm3n4_t;

// ****************************************************************************************************
ord_t feonumm3n4_get_order( feonumm3n4_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order, onumm3n4_get_order(&num->p_data[i]) );
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_get_order_im_to( ord_t order, feonumm3n4_t* num, feonumm3n4_t* res){
    
    uint64_t k;

    feonumm3n4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_get_order_im_to( order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n4_t feonumm3n4_get_order_im( ord_t order, feonumm3n4_t* num){
    
    feonumm3n4_t res;

    res = feonumm3n4_zeros( num->nip);

    feonumm3n4_get_order_im_to( order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_extract_im_to( imdir_t idx, ord_t order, feonumm3n4_t* num, feonumm3n4_t* res){
    
    uint64_t k;

    feonumm3n4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n4_t feonumm3n4_extract_im( imdir_t idx, ord_t order, feonumm3n4_t* num){
    
    feonumm3n4_t res;

    res = feonumm3n4_zeros( num->nip);

    feonumm3n4_extract_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_extract_deriv_to( imdir_t idx, ord_t order, feonumm3n4_t* num, feonumm3n4_t* res){
    
    uint64_t k;

    feonumm3n4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n4_t feonumm3n4_extract_deriv( imdir_t idx, ord_t order, feonumm3n4_t* num){
    
    feonumm3n4_t res;

    res = feonumm3n4_zeros( num->nip);

    feonumm3n4_extract_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_get_deriv_to( imdir_t idx, ord_t order, feonumm3n4_t* num, feonumm3n4_t* res){
    
    uint64_t k;

    feonumm3n4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n4_t feonumm3n4_get_deriv( imdir_t idx, ord_t order, feonumm3n4_t* num){
    
    feonumm3n4_t res;

    res = feonumm3n4_zeros( num->nip);

    feonumm3n4_get_deriv_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_get_im_to( imdir_t idx, ord_t order, feonumm3n4_t* num, feonumm3n4_t* res){
    
    uint64_t k;

    feonumm3n4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n4_t feonumm3n4_get_im( imdir_t idx, ord_t order, feonumm3n4_t* num){
    
    feonumm3n4_t res;

    res = feonumm3n4_zeros( num->nip);

    feonumm3n4_get_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_truncate_im_to( imdir_t idx, ord_t order, feonumm3n4_t* num,  feonumm3n4_t* res){
    
    uint64_t k;

    feonumm3n4_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n4_t feonumm3n4_truncate_im( imdir_t idx, ord_t order, feonumm3n4_t* num){
    
    feonumm3n4_t res;

    res = feonumm3n4_zeros( num->nip);

    feonumm3n4_truncate_im_to( idx, order, num, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_im_r( coeff_t val, imdir_t idx, ord_t order, feonumm3n4_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_set_im_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_im_o( onumm3n4_t* val, imdir_t idx, ord_t order, feonumm3n4_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_set_im_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_im_f( feonumm3n4_t* val, imdir_t idx, ord_t order, feonumm3n4_t* num){
    
    uint64_t k;

    feonumm3n4_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_set_im_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, feonumm3n4_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_set_deriv_r( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_deriv_o( onumm3n4_t* val, imdir_t idx, ord_t order, feonumm3n4_t* num){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_set_deriv_o( val, idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_deriv_f( feonumm3n4_t* val, imdir_t idx, ord_t order, feonumm3n4_t* num){
    
    uint64_t k;

    feonumm3n4_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        onumm3n4_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_to( feonumm3n4_t* src, feonumm3n4_t* dst){
    
    uint64_t i;

    feonumm3n4_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        onumm3n4_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n4_t feonumm3n4_copy( feonumm3n4_t* src){
    
    feonumm3n4_t res = feonumm3n4_init();

    res = feonumm3n4_createEmpty(src->nip);

    feonumm3n4_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_copy_to( feonumm3n4_t* src, feonumm3n4_t* dst){
    
    uint64_t i;

    feonumm3n4_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        onumm3n4_copy_to( &src->p_data[i], &dst->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_f( feonumm3n4_t* num, feonumm3n4_t* res){
    
    feonumm3n4_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_o( onumm3n4_t* num, feonumm3n4_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        onumm3n4_set_o( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_r( coeff_t num, feonumm3n4_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        onumm3n4_set_r( num, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_item_k_o( onumm3n4_t* num, uint64_t k, feonumm3n4_t* res){
    
    if (k < res->nip){

        onumm3n4_set_o(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in feonumm3n4_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_set_item_k_r(   coeff_t  num, uint64_t k, feonumm3n4_t* res){

    if (k < res->nip){

        onumm3n4_set_r(num, &res->p_data[k]); 

    } else {

        printf("ERROR: Index out of bounds in feonumm3n4_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm3n4_t feonumm3n4_get_item_k(feonumm3n4_t* num, uint64_t k){

    onumm3n4_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in feonumm3n4_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_get_item_k_to(feonumm3n4_t* num, uint64_t k, onumm3n4_t* res){
    
    
    if (k < num->nip){

        onumm3n4_copy_to( &num->p_data[k], res);

    } else {

        printf("ERROR: Index out of bounds in feonumm3n4_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n4_t feonumm3n4_zeros(uint64_t nip){

    feonumm3n4_t  res  = feonumm3n4_createEmpty(nip);
    
    feonumm3n4_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline feonumm3n4_t feonumm3n4_createEmpty(uint64_t nip){

    feonumm3n4_t  res ;  
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( onumm3n4_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of feonumm3n4.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( onumm3n4_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm3n4_free(feonumm3n4_t* num){

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){
        // Free pointer 
        free(num->p_data);
    }

    *num = feonumm3n4_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline feonumm3n4_t feonumm3n4_init(void){
    
    feonumm3n4_t res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline feonumm3n4_t feonumm3n4_empty_like(feonumm3n4_t* arr){

    feonumm3n4_t res = feonumm3n4_createEmpty(arr->nip);

    return res;

}
// ----------------------------------------------------------------------------------------------------

