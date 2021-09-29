// typedef struct{
//     semiotin_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } fessoti_t;








// ****************************************************************************************************
ord_t fessoti_get_order( fessoti_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order,num->p_data[0].trc_order);
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void fessoti_get_order_im_to( ord_t order, fessoti_t* num, fessoti_t* res, dhelpl_t dhl){
    
    uint64_t k;

    fessoti_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_get_order_im_to( order, &num->p_data[k], &res->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_get_order_im( ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    fessoti_t res;

    res = fessoti_zeros_bases( num->nip, 0, 0, dhl);

    fessoti_get_order_im_to( order, num, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------











// ****************************************************************************************************
void fessoti_extract_im_to( imdir_t idx, ord_t order, fessoti_t* num, fessoti_t* res, dhelpl_t dhl){
    
    uint64_t k;

    fessoti_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_extract_im( imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    fessoti_t res;

    res = fessoti_zeros_bases( num->nip, 0, 0, dhl);

    fessoti_extract_im_to( idx, order, num, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------












// ****************************************************************************************************
void fessoti_extract_deriv_to( imdir_t idx, ord_t order, fessoti_t* num, fessoti_t* res, dhelpl_t dhl){
    
    uint64_t k;

    fessoti_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_extract_deriv( imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    fessoti_t res;

    res = fessoti_zeros_bases( num->nip, 0, 0, dhl);

    fessoti_extract_deriv_to( idx, order, num, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------









// ****************************************************************************************************
void fessoti_get_deriv_to( imdir_t idx, ord_t order, fessoti_t* num, fessoti_t* res, dhelpl_t dhl){
    
    uint64_t k;

    fessoti_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_get_deriv( imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    fessoti_t res;

    res = fessoti_zeros_bases( num->nip, 0, 0, dhl);

    fessoti_get_deriv_to( idx, order, num, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------














// ****************************************************************************************************
void fessoti_get_im_to( imdir_t idx, ord_t order, fessoti_t* num, fessoti_t* res, dhelpl_t dhl){
    
    uint64_t k;

    fessoti_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_get_im( imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    fessoti_t res;

    res = fessoti_zeros_bases( num->nip, 0, 0, dhl);

    fessoti_get_im_to( idx, order, num, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------















// ****************************************************************************************************
void fessoti_truncate_im_to( imdir_t idx, ord_t order, fessoti_t* num,  fessoti_t* res, dhelpl_t dhl){
    
    uint64_t k;

    fessoti_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fessoti_t fessoti_truncate_im( imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    fessoti_t res;

    res = fessoti_zeros_bases( num->nip, 0, 0, dhl);

    fessoti_truncate_im_to( idx, order, num, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------






















// ****************************************************************************************************
void fessoti_set_im_r( coeff_t val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_set_im_r( val, idx, order, &num->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_set_im_o( semiotin_t* val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_set_im_o( val, idx, order, &num->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_set_im_f( fessoti_t* val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    uint64_t k;

    fessoti_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_set_im_o( &val->p_data[k], idx, order, &num->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------




















// ****************************************************************************************************
void fessoti_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_set_deriv_r( val, idx, order, &num->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_set_deriv_o( semiotin_t* val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_set_deriv_o( val, idx, order, &num->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_set_deriv_f( fessoti_t* val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl){
    
    uint64_t k;

    fessoti_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){
        
        ssoti_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------























// ****************************************************************************************************
void fessoti_set_to( fessoti_t* src, fessoti_t* dst, dhelpl_t dhl){
    
    uint64_t i;

    fessoti_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        ssoti_copy_to( &src->p_data[i], &dst->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fessoti_t fessoti_copy( fessoti_t* src, dhelpl_t dhl){
    
    fessoti_t res = fessoti_init();

    res = fessoti_createEmpty_bases(src->nip, 0,0, dhl);

    fessoti_copy_to( src, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fessoti_copy_to( fessoti_t* src, fessoti_t* dst, dhelpl_t dhl){
    
    uint64_t i;

    fessoti_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        ssoti_copy_to( &src->p_data[i], &dst->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------














// ****************************************************************************************************
void fessoti_set_f( fessoti_t* num, fessoti_t* res, dhelpl_t dhl){
    
    fessoti_copy_to(num,res,dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fessoti_set_o( semiotin_t* num, fessoti_t* res, dhelpl_t dhl){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        ssoti_set_o( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fessoti_set_r( coeff_t num, fessoti_t* res, dhelpl_t dhl){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        ssoti_set_r( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fessoti_set_item_k_o( semiotin_t* num, uint64_t k, fessoti_t* res, dhelpl_t dhl){
    
    if (k < res->nip){

        ssoti_set_o(num, &res->p_data[k], dhl); 

    } else {

        printf("ERROR: Index out of bounds in fessoti_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fessoti_set_item_k_r(   coeff_t  num, uint64_t k, fessoti_t* res, dhelpl_t dhl){

    if (k < res->nip){

        ssoti_set_r(num, &res->p_data[k], dhl); 

    } else {

        printf("ERROR: Index out of bounds in fessoti_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
semiotin_t fessoti_get_item_k(fessoti_t* num, uint64_t k, dhelpl_t dhl){

    semiotin_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];   
        res.flag = 0;

    } else {

        printf("ERROR: Index out of bounds in fessoti_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fessoti_get_item_k_to(fessoti_t* num, uint64_t k, semiotin_t* res, dhelpl_t dhl){
    
    
    if (k < num->nip){

        ssoti_copy_to( &num->p_data[k], res, dhl);

    } else {

        printf("ERROR: Index out of bounds in fessoti_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------





























// ****************************************************************************************************
fessoti_t fessoti_zeros_bases(uint64_t nip, bases_t nbases, ord_t order, dhelpl_t dhl){

    fessoti_t  res  = fessoti_createEmpty_bases(nip, nbases, order, dhl);
    
    fessoti_set_r( 0.0, &res, dhl);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline fessoti_t fessoti_createEmpty_bases(uint64_t nip, bases_t nbases, ord_t order, dhelpl_t dhl){

    fessoti_t  res ;
    ndir_t p_nnz[_MAXORDER_OTI];
    ord_t    ordi;
    uint64_t i;    
    void * memory = NULL;

    for ( ordi = 0; ordi < order ; ordi++ ){

        p_nnz[ ordi ] = dhelp_ndirOrder( nbases, ordi+1 );

    }

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( semiotin_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of fesoti.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( semiotin_t* ) memory;
    res.nip = nip;

    // Loop for all elements in the array
    for(i = 0; i < res.nip; i++){

        // Allocate every number as indicated
        res.p_data[i] = ssoti_createEmpty_predef( p_nnz, order, dhl);
    
    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------










// ****************************************************************************************************
void fessoti_free(fessoti_t* num){
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){

        // Free all arrays.
        for (i = 0; i<num->nip; i++){
        
            ssoti_free(&num->p_data[i]); 

        }

        // Free pointer 
        free(num->p_data);

    }

    *num = fessoti_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline fessoti_t fessoti_init(void){
    
    fessoti_t res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
inline fessoti_t fessoti_empty_like(fessoti_t* arr, dhelpl_t dhl){

    fessoti_t res = fessoti_createEmpty_bases(arr->nip, 0, 0, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------




