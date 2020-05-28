// typedef struct{
//     arrso_t*      p_data; ///< Data array
//     uint64_t      nrows;  ///< Number of rows.
//     uint64_t      ncols;  ///< Number of cols.
//     uint64_t       size;  ///< size of the array
//     uint64_t    nip;  ///< Number of integration points.
// } fearrso_t;











// ****************************************************************************************************
ord_t fearrso_get_order(fearrso_t* arr){

    ord_t ord = 0;
    uint64_t i;

    for( i = 0; i < arr->nip; i++){

        ord = MAX( ord, arrso_get_order( &arr->p_data[i]) );

    }

    return ord;

}
// ----------------------------------------------------------------------------------------------------




















// ****************************************************************************************************
void fearrso_copy_to(fearrso_t* src, fearrso_t* dst, dhelpl_t dhl){

    uint64_t i;

    // check memory;
    fearrso_dimCheck_FF_elementwise(src, dst, dst);

    for( i = 0; i < src->nip; i++){

        arrso_copy_to( &src->p_data[i], &dst->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_copy(fearrso_t* src, dhelpl_t dhl){

    fearrso_t res = fearrso_createEmpty_bases( src->nrows, src->ncols, 
                        src->nip,  0,   
                        0,    dhl);
    
    fearrso_copy_to( src, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------






















// ****************************************************************************************************
arrso_t fearrso_get_item_k(fearrso_t* arr, uint64_t k, dhelpl_t dhl){
    
    arrso_t res;
    // TODO: Add bound checks.
    
    res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    fearrso_get_item_k_to(arr, k, &res, dhl);

    return res;    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fesoti_t fearrso_get_item_ij(fearrso_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl){
        
    fesoti_t res = fesoti_init();
    // TODO: Add bound checks.
    
    res = fesoti_zeros_bases(arr->nip, 0, 0, dhl);

    fearrso_get_item_ij_to(arr, i, j, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t fearrso_get_item_ijk(fearrso_t* arr, uint64_t i, uint64_t j, uint64_t k, dhelpl_t dhl){
    
    sotinum_t res;
    
    res = arrso_get_item_ij(&arr->p_data[k], i, j, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------









// ****************************************************************************************************
void fearrso_get_item_k_to(fearrso_t* arr, uint64_t k, arrso_t* res, dhelpl_t dhl){
    
    // TODO: Add bound checks.

    arrso_copy_to( &arr->p_data[k], res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_get_item_ij_to(fearrso_t* arr, uint64_t i, uint64_t j, fesoti_t* res, dhelpl_t dhl){
        
    uint64_t k;
    
    fearrso_dimCheck_fF_elementwise(res,arr,arr);

    for (k = 0; k < arr->nip; k++){
        
        arrso_get_item_ij_to( &arr->p_data[k], i, j, &res->p_data[k], dhl);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_get_item_ijk_to(fearrso_t* arr, uint64_t i, uint64_t j, uint64_t k, sotinum_t* res, dhelpl_t dhl){
    
    // TODO: Add bound checks.
    if ( k < arr->nip && i < arr->nrows && j < arr->ncols){

        arrso_get_item_ij_to(&arr->p_data[k], i, j, res, dhl);

    } else {

        printf("Error: Bad index \n");
        exit(OTI_BadIndx);
    }

}
// ----------------------------------------------------------------------------------------------------
















// ****************************************************************************************************
void fearrso_set_item_k( arrso_t* arr , uint64_t k, fearrso_t* res, dhelpl_t dhl){
    
    // No new allocation needed.
    arrso_copy_to( arr, &res->p_data[k], dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrso_set_item_ij(fesoti_t* num, uint64_t i, uint64_t j, fearrso_t* res, dhelpl_t dhl){
    
    uint64_t k;

    //Check
    fearrso_dimCheck_fF_elementwise(num,res,res);

    for (k = 0; k < num->nip; k++){
        
        arrso_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void fearrso_set_item_ijk(sotinum_t* num, uint64_t i, uint64_t j, uint64_t k, 
        fearrso_t* res, dhelpl_t dhl){

    arrso_set_item_ij_o( num, i, j, &res->p_data[k], dhl);

}
// ----------------------------------------------------------------------------------------------------














































// ****************************************************************************************************
void fearrso_set_all_o( sotinum_t* num, fearrso_t* res, dhelpl_t dhl ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        arrso_set_all_o( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_set_all_r( coeff_t num, fearrso_t* res, dhelpl_t dhl ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){

        arrso_set_all_r( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
fearrso_t fearrso_zeros_bases( uint64_t nrows,   uint64_t ncols, 
                               uint64_t nip, bases_t  nbases, 
                               ord_t    order,   dhelpl_t dhl     ){ 
    
    uint64_t i;

    fearrso_t res = fearrso_createEmpty_bases( nrows, ncols, 
                                               nip, nbases,   
                                               order, dhl);
    
    for( i = 0; i < res.nip; i++){

        arrso_set_all_r( 0.0, &res.p_data[i], dhl);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fearrso_t fearrso_createEmpty_bases( uint64_t nrows,   uint64_t ncols, 
                                     uint64_t nip, bases_t  nbases, 
                                     ord_t    order,   dhelpl_t dhl){  
    
    uint64_t i;

    fearrso_t res = fearrso_init();

    res.nrows    =  nrows;
    res.ncols    =  ncols;
    res.size     =  nrows*ncols;
    
    res.nip  =  nip;

    // Allocate memory.
    res.p_data   = (arrso_t*) malloc( res.nip * sizeof(arrso_t) );

    // sotiarray_createEmpty(sotiarray_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order);
    if (res.p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for( i = 0; i < res.nip; i++){

        res.p_data[i] = arrso_createEmpty_bases( nrows, ncols, nbases, order, dhl);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------




























// ****************************************************************************************************
void fearrso_free(fearrso_t* arr){
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (arr->p_data != NULL){

        // Free all arrays.
        for (i = 0; i<arr->nip; i++){
        
            arrso_free(&arr->p_data[i]); 

        }

        // Free pointer 
        free(arr->p_data);

    }

    *arr = fearrso_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_init(void){
    
    fearrso_t res;
    
    res.p_data  = NULL;  
    res.nrows   = 0;   
    res.ncols   = 0;   
    res.size    = 0;    
    res.nip = 0; 

    return res;

}
// ----------------------------------------------------------------------------------------------------

