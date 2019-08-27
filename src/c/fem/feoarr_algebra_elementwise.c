



// ****************************************************************************************************
void feoarr_sub_FF_to(feoarr_t* arr1, feoarr_t* arr2, feoarr_t* res, dhelpl_t dhl){
    /*
    Subtraction of two arrays.

    INPUTS:

        -> arr1:   Array.
        -> arr2:   Array.
        -> res:    Result of operation.
        -> dhl:    Direction helper.

    */ 
    // ************************************************************************************************

    uint64_t i;

    for (i = 0; i<arr1->nIntPts; i++){

        oarr_sub_OO_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void feoarr_sum_FF_to(feoarr_t* arr1, feoarr_t* arr2, feoarr_t* res, dhelpl_t dhl){
    /*
    feoarr_det(feoarr_t* arr1, feoarr_t* res, dhelpl_t dhl)

    Determinant of femarray

    INPUTS:

        -> arr1: Array
        -> arr2: Array        
        -> res:  Result of operation.
        -> dhl:  Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;

    for (i = 0; i<arr1->nIntPts; i++){

        oarr_sum_OO_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void feoarr_neg_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl){
    /*
    @brief Negation of feoarr type.

    @param[in]    arr:  Array.
    @param[inout] res:   Result of operation.

    */ 
    // ************************************************************************************************

    uint64_t i;

    for (i = 0; i<arr->nIntPts; i++){

        oarr_neg_to( &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void feoarr_mul_fF_to( feoarr_t* num, feoarr_t* arr, feoarr_t* res, dhelpl_t dhl){
    /*
    @brief Elementwise multiplication by scalar oti number.

    @param arr1:   Array.
    @param res:    Result of operation.
    @param dhl:    Direction helper.

    */ 
    // ************************************************************************************************

    uint64_t i;

    otinum_t tmp = oti_get_tmp( 11, arr->nbases, arr->order, dhl );

    for (i = 0; i<arr->nIntPts; i++){

        // get otinum representation of the element in num.
        feoarr_get_item_ijk_to(num, 0, 0, i, &tmp, dhl);

        // multiply the oti number by the array.
        oarr_mul_oO_to( &tmp, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void feoarr_mul_oF_to( otinum_t* num, feoarr_t* arr, feoarr_t* res, dhelpl_t dhl){
    /*
    @brief Elementwise multiplication by scalar oti number.

    @param arr1:   Array.
    @param res:    Result of operation.
    @param dhl:    Direction helper.

    */ 
    // ************************************************************************************************

    uint64_t i;

    for (i = 0; i<arr->nIntPts; i++){

        oarr_mul_oO_to( num, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void feoarr_mul_rF_to(coeff_t num, feoarr_t* arr, feoarr_t* res, dhelpl_t dhl){
    /*
    @brief Elementwise multiplication by a real number.

    INPUTS:

    @param[in]    num:   Scalar.
    @param[in]    arr:   Array
    @param[inout] res:   Result of operation.

    */ 
    // ************************************************************************************************

    uint64_t i;

    for (i = 0; i<arr->nIntPts; i++){

        oarr_mul_rO_to( num, &arr->p_data[i],  &res->p_data[i], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------





