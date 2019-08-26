
















// // ****************************************************************************************************
// void feoarr_gaussIntegrateOverElement(feoarr_t* arr, elemProps_t* elem, oarr_t* res, dhelpl_t dhl){
//     /*
//     Gauss integration over all elements of a femarray.

//     INPUTS:

//         ->   p_arr1:    Array

//         ->   elem:      Element with the information of the solution.
        
//         -> res:    Result of operation.

//         ->     dhl:    Direction helper

//     */ 
//     // ************************************************************************************************

//     uint64_t i,j,k;
//     otinum_t tmp1, tmp2, tmp3,tmp4;

//     // double realVal;
    

//     if (res->p_data == NULL){

//         // sotiarray_zeros(res, p_arr1->ncols, p_arr1->nrows, p_arr1->order);

//     }

//     // printf("\nIntegrating over element.\n");
    
//     for (i = 0; i<p_arr1->nrows; i++){
    
//         for (j = 0; j<p_arr1->ncols; j++){

//             // printf("  Integrating position (%llu,%llu)\n",i,j);
            
//             soti_createEmpty(&tmp1,0,p_arr1->order);

//             for (k = 0; k<elem->nIntPts; k++){

//                 // printf("    Summing integration point %llu\n",k);
//                 // printf("    Getting element of integration function\n");
//                 feoarr_getItem_ijk(p_arr1, i, j, k, &tmp2);

//                 // printf("    Getting element of weights function\n");
//                 feoarr_getItem_ijk(&elem->p_detWeights, 0, 0, k, &tmp4);


//                 // printf("    Multiplying two otis\n");
//                 soti_mul(&tmp2, &tmp4, &tmp3, dhl);


//                 tmp2 = tmp1;

//                 // printf("    Adding two otis\n");
//                 soti_sum(&tmp2,&tmp3,&tmp1,dhl);

//                 // printf("    Freeing memory of temporal arrays.\n");
//                 // Free temporals that were created in here.
//                 soti_free(&tmp2);    
//                 soti_free(&tmp3);

//             }
//             // printf("  Adding position i: %llu,   j: %llu,    with offsets ->   i': %llu,   j': %llu\n", 
//                                 // i, j, p_arr1->offsetx+i,   p_arr1->offsety+j  );

//             // printf("  Getting element from result array\n");
//             sotiarray_getItem( res, p_arr1->offsetx + i, p_arr1->offsety + j, &tmp2);

//             // realVal = soti_getReal(&tmp2);

//             // printf("  tmp2: \n");
//             // soti_printf(&tmp2);
//             // realVal = soti_getReal(&tmp1);
//             // printf("\n  tmp1: \n");
//             // soti_printf(&tmp1);

//             // realVal = soti_getReal(&tmp3);
            
//             // printf("\n  tmp3: \n");
//             // soti_printf(&tmp3);

//             // printf("  Adding the two arrays\n");
            

//             soti_sum(&tmp2,&tmp1,&tmp3,dhl);



//             // printf("  Freeing memory temporal 1.\n");
//             soti_free(&tmp1);

            

//             sotiarray_setItemOTI(&tmp3,
//                 p_arr1->offsetx + i , p_arr1->offsety + j, res);
    
//         }
    
//     }

//     // printf("Exit.");


// }
// // ----------------------------------------------------------------------------------------------------






































// ****************************************************************************************************
void feoarr_copy_to(feoarr_t* src, feoarr_t* dst,dhelpl_t dhl){

    uint64_t i;

    for( i = 0; i < src->nIntPts; i++){

        oarr_copy_to( &src->p_data[i], &dst->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarr_t feoarr_copy(feoarr_t* src, dhelpl_t dhl){
    /*
    feoarr_fromOther(feoarr_t* p_arr1, feoarr_t* p_res)

    Define a femarray from another femarray.

    INPUTS:

        ->   p_arr1:    First array of shape (i,j) and k nIntPts.
        
        -> res:    Result of res = p_arr1.

                        NOTE: Shape can be (i,j) or (j,i), important is that the number of elements 
                              are the same.

    */ 
    // ************************************************************************************************

    uint64_t i;

    feoarr_t res;
    
    res.order    =  src->order  ;
    res.nbases   =  src->nbases ;

    res.ncols    =  src->nrows;
    res.nrows    =  src->ncols;
    res.size     =  src->size ;
    
    res.nIntPts  =  src->nIntPts;
    res.offsetx  =  src->offsetx;
    res.offsety  =  src->offsety;

    // Allocate memory.
    res.p_data   = (oarr_t*) malloc( res.nIntPts * sizeof(oarr_t) );

    // sotiarray_createEmpty(sotiarray_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order);
    if (res.p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for( i = 0; i < res.nIntPts; i++){

        res.p_data[i] = oarr_copy( &src->p_data[i], dhl);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------











// ****************************************************************************************************
void feoarr_get_item_ij_to(feoarr_t* arr, uint64_t i, uint64_t j, feoarr_t* res, dhelpl_t dhl){
    /*

    Transpose a femarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> res:    Result of p_arr1+p_arr2.

        ->     dhl:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t k;

    otinum_t tmp = oti_get_tmp(10, arr->nbases, arr->order, dhl);
    
    for (k = 0; k<arr->nIntPts; k++){
        
        feoarr_get_item_ijk_to( arr, i, j, k, &tmp, dhl);

        oarr_set_item_ij_o(&tmp, 0, 0, &res->p_data[k], dhl);
    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarr_get_item_k_to(feoarr_t* arr, uint64_t k, oarr_t* res, dhelpl_t dhl){
    /*

    Get k'th integration value of feoarr object.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> res:    Result of p_arr1+p_arr2.

        ->     dhl:    Direction helper

    */ 
    // ************************************************************************************************

    oarr_copy_to( &arr->p_data[k], res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarr_get_item_ijk_to(feoarr_t* arr, uint64_t i, uint64_t j, uint64_t k, otinum_t* res,dhelpl_t dhl){
    /*

    Get k'th integration value at [i,j] in the array.

    INPUTS:

        ->   arr:    Array.
        
        -> res:    Result of p_arr1+p_arr2.

        ->     dhl:    Direction helper

    */ 
    // ************************************************************************************************

    oarr_get_item_ij_to(&arr->p_data[k], i, j, res, dhl);

}
// ----------------------------------------------------------------------------------------------------








































// ****************************************************************************************************
void feoarr_set_item_ij(feoarr_t* arr, uint64_t i, uint64_t j, feoarr_t* res, dhelpl_t dhl){
    /*
    feoarr_getItem_ijk(feoarr_t* p_arr1, uint64_t i, uint64_t j, uint64_t k, 
                feoarr_t* res)

    Transpose a  femarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> res:    Result of p_arr1+p_arr2.

        ->     dhl:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t k;

    otinum_t tmp = oti_get_tmp( 10,  arr->nbases, arr->order, dhl);
    
    for (k = 0; k < arr->nIntPts; k++){
        
        oarr_get_item_ij_to(  &arr->p_data[k], 0, 0, &tmp, dhl);

        oarr_set_item_ij_o( &tmp, i, j, &res->p_data[k], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void feoarr_set_item_k( oarr_t* arr , uint64_t k, feoarr_t* res, dhelpl_t dhl){
    /*
    @brief Set integration point array value.

    @param[in] arr: Array to be set into res.
    @param[in] k: Index of the integration element to be set.
    @param[inout] res: Result holder. 
    @param[in] dhl:    Direction helper.

    */ 
    // ************************************************************************************************

    // No new allocation needed.
    oarr_copy_to( arr, &res->p_data[k], dhl);

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void feoarr_set_item_ijk(otinum_t* num, uint64_t i, uint64_t j, uint64_t k, 
        feoarr_t* res, dhelpl_t dhl){
    /*
    @brief Set integration point value.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> res:    Result of p_arr1+p_arr2.

        ->     dhl:    Direction helper

    */ 
    // ************************************************************************************************

    oarr_set_item_ij_o( num, i, j, &res->p_data[k], dhl);

}
// ----------------------------------------------------------------------------------------------------



















































// ****************************************************************************************************
feoarr_t feoarr_zeros( uint64_t nrows, uint64_t ncols, uint64_t offsetx, uint64_t offsety, 
                   uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl){
    /*
    feoarr_zeros(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, uint8_t order)

    C-level memory allocation of a fem array as zeros.

    INPUTS:

        ->  p_array:    Address of the array to be allocated.

        ->   shapex:    Number of elements in the first  dimension.

        ->   shapey:    Number of elements in the second dimension.

        ->   offsetx:    Number of elements in the second dimension.

        ->   offsety:    Number of elements in the second dimension.

        ->   nIntPts:    Number of elements in the third dimension.
        
        ->    order:    Order of the numbers.

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    uint64_t i;
    feoarr_t res = feoarr_init();
    
    res.order    =  order ;
    res.nbases   =  nbases ;

    res.ncols    =  nrows;
    res.nrows    =  ncols;
    res.size     =  nrows*ncols;
    
    res.nIntPts  =  nIntPts;
    res.offsetx  =  offsetx;
    res.offsety  =  offsety;

    // Allocate memory.
    res.p_data   = (oarr_t*) malloc( res.nIntPts * sizeof(oarr_t) );

    // sotiarray_createEmpty(sotiarray_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order);
    if (res.p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for( i = 0; i < res.nIntPts; i++){

        res.p_data[i] = oarr_zeros( nrows, ncols, nbases, order, dhl);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void feoarr_free(feoarr_t* arr){
    /*
    feoarr_createEmpty(feoarr_t* p_array)
    
    Free all memory associated with the array.

    INPUTS:

        ->  p_array:    Address of the array to be freed.
        
    */ 
    // ************************************************************************************************
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (arr->p_data != NULL){

        // Free all arrays.
        for (i = 0; i<arr->nIntPts; i++){
        
            oarr_free(&arr->p_data[i]); 

        }

        // Free pointer 
        free(arr->p_data);

    }

    *arr = feoarr_init();
    
}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline feoarr_t feoarr_init( void ){
    /*
    
    Initialize all elements of a feoarr_t object.        

    */ 
    // ************************************************************************************************

    feoarr_t res;

    res.ncols    =    0;
    res.nrows    =    0;
    res.size     =    0;
    
    res.nbases   =    0;
    res.order    =    0;
    
    res.nIntPts  =    0;
    
    res.offsetx  =    0;
    res.offsety  =    0;

    res.p_data   = NULL;

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarr_t feoarr_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t offsetx, uint64_t offsety, 
	                         uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl){  
    /*
    feoarr_createEmpty(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, 
        uint64_t offsetx, uint64_t offsety, uint64_t nIntPts, uint8_t order)

    C-level memory allocation of a fem array from a file

    INPUTS:

        ->  p_array:    Address of the array to be allocated.

        ->   shapex:    Number of elements in the first  dimension.

        ->   shapey:    Number of elements in the second dimension.

        ->   offsetx:    Number of elements in the second dimension.

        ->   offsety:    Number of elements in the second dimension.

        ->   nIntPts:    Number of elements in the third dimension.
        
        ->    order:    Order of the numbers.


    OUTPUTS:
        -> The result is the feoarr_t with the memory allocated.
    */ 
    // ************************************************************************************************
    
    uint64_t i;

    feoarr_t res;
    
    res.order    =  order ;
    res.nbases   =  nbases ;

    res.ncols    =  nrows;
    res.nrows    =  ncols;
    res.size     =  nrows*ncols;
    
    res.nIntPts  =  nIntPts;
    res.offsetx  =  offsetx;
    res.offsety  =  offsety;

    // Allocate memory.
    res.p_data   = (oarr_t*) malloc( res.nIntPts * sizeof(oarr_t) );

    // sotiarray_createEmpty(sotiarray_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order);
    if (res.p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for( i = 0; i < res.nIntPts; i++){

        res.p_data[i] = oarr_createEmpty( nrows, ncols, nbases, order, dhl);

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------



















