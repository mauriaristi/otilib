// typedef struct{
//     arrso_t*      p_data; ///< Data array
//     uint64_t      nrows;  ///< Number of rows.
//     uint64_t      ncols;  ///< Number of cols.
//     uint64_t       size;  ///< size of the array
//     uint64_t    nIntPts;  ///< Number of integration points.
//     uint64_t    offsetx;  ///< Offset x in the element formulation
//     uint64_t    offsety;  ///< Offset y in the element formulation
// } fearrso_t;



// ****************************************************************************************************
void fearrso_copy_to(fearrso_t* src, fearrso_t* dst,dhelpl_t dhl){

    uint64_t i;


    // check memory;


    for( i = 0; i < src->nIntPts; i++){

        arrso_copy_to( &src->p_data[i], &dst->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_copy(fearrso_t* src, dhelpl_t dhl){

    fearrso_t res = fearrso_createEmpty_bases( src->nrows, src->ncols, 
                        src->offsetx, src->offsety, 
                        src->nIntPts,  0,   
                        0,    dhl);
    
    fearrso_copy_to( src, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------











// // ****************************************************************************************************
// void fearrso_get_item_ij_to(fearrso_t* arr, uint64_t i, uint64_t j, fearrso_t* res, dhelpl_t dhl){
        
//     uint64_t k;

//     sotinum_t tmp = soti_get_tmp( 10, arr->order, dhl);
    
//     for (k = 0; k<arr->nIntPts; k++){
        
//         fearrso_get_item_ijk_to( arr, i, j, k, &tmp, dhl);

//         arrso_set_item_ij_o(&tmp, 0, 0, &res->p_data[k], dhl);
    
//     }

// }
// // ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_get_item_k_to(fearrso_t* arr, uint64_t k, arrso_t* res, dhelpl_t dhl){
    
    // TODO: Add bound checks.

    arrso_copy_to( &arr->p_data[k], res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_get_item_ijk_to(fearrso_t* arr, uint64_t i, uint64_t j, uint64_t k, sotinum_t* res, dhelpl_t dhl){
    
    // TODO: Add bound checks.

    arrso_get_item_ij_to(&arr->p_data[k], i, j, res, dhl);

}
// ----------------------------------------------------------------------------------------------------











// ****************************************************************************************************
void fearrso_set_item_ij(fearrso_t* arr, uint64_t i, uint64_t j, fearrso_t* res, dhelpl_t dhl){
    
    // uint64_t k;

    // sotinum_t tmp = oti_get_tmp( 10,  arr->nbases, arr->order, dhl);
    
    // for (k = 0; k < arr->nIntPts; k++){
        
    //     arrso_get_item_ij_to(  &arr->p_data[k], 0, 0, &tmp, dhl);

    //     arrso_set_item_ij_o( &tmp, i, j, &res->p_data[k], dhl );

    // }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void fearrso_set_item_k( arrso_t* arr , uint64_t k, fearrso_t* res, dhelpl_t dhl){
    
    // No new allocation needed.
    arrso_copy_to( arr, &res->p_data[k], dhl);

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
    
    for( i = 0; i < res->nIntPts; i++){

        arrso_set_all_o( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_set_all_r( coeff_t num, fearrso_t* res, dhelpl_t dhl ){ 
    
    uint64_t i;
    
    for( i = 0; i < res->nIntPts; i++){

        arrso_set_all_r( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
fearrso_t fearrso_zeros_bases( uint64_t nrows,   uint64_t ncols, 
                               uint64_t offsetx, uint64_t offsety, 
                               uint64_t nIntPts, bases_t  nbases, 
                               ord_t    order,   dhelpl_t dhl     ){ 
    
    uint64_t i;

    fearrso_t res = fearrso_createEmpty_bases(   nrows,   ncols, 
                                               offsetx, offsety, 
                                               nIntPts,  nbases,   
                                               order,    dhl);
    
    for( i = 0; i < res.nIntPts; i++){

        arrso_set_all_r( 0.0, &res.p_data[i], dhl);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fearrso_t fearrso_createEmpty_bases( uint64_t nrows,   uint64_t ncols, 
                                     uint64_t offsetx, uint64_t offsety, 
                                     uint64_t nIntPts, bases_t  nbases, 
                                     ord_t    order,   dhelpl_t dhl){  
    
    uint64_t i;

    fearrso_t res = fearrso_init();

    res.ncols    =  nrows;
    res.nrows    =  ncols;
    res.size     =  nrows*ncols;
    
    res.nIntPts  =  nIntPts;
    res.offsetx  =  offsetx;
    res.offsety  =  offsety;

    // Allocate memory.
    res.p_data   = (arrso_t*) malloc( res.nIntPts * sizeof(arrso_t) );

    // sotiarray_createEmpty(sotiarray_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order);
    if (res.p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for( i = 0; i < res.nIntPts; i++){

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
        for (i = 0; i<arr->nIntPts; i++){
        
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
    res.nIntPts = 0; 
    res.offsetx = 0; 
    res.offsety = 0; 

    return res;

}
// ----------------------------------------------------------------------------------------------------

