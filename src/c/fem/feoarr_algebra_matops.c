
void feoarr_matmul_to(feoarr_t* lhs, feoarr_t* rhs, feoarr_t* res, dhelpl_t dhl);
void feoarr_det_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
void feoarr_invert_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);













// ****************************************************************************************************
void feoarr_matmul_to(feoarr_t* lhs, feoarr_t* rhs, feoarr_t* res, dhelpl_t dhl){
    /*
    
    MATMUL operation of Finite Element OTI array.

    INPUTS:

        ->   lhs:    Left hand side array.

        ->   rhs:    Right hand side array
        
        -> p_arrRes:    Result of operation.

        ->     dhl:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;

    for (i = 0; i<lhs->nIntPts; i++){

        oarr_matmul_OO_to(&lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void feoarr_det_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl){
    /*

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array
        
        -> p_arrRes:    Result of operation. must be (1x1)

        ->     dhl:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;
    otinum_t tmp = oti_get_tmp( 11, arr->nbases, arr->order, dhl);

    for (i = 0; i<arr->nIntPts; i++){

        oarr_det_to( &arr->p_data[i], &tmp, dhl);

        feoarr_set_item_ijk( &tmp, 0, 0, i, res, dhl);

    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void feoarr_invert_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl){
    /*
    sotiarray_invert(feoarr_t* p_arr1, feoarr_t* p_arrRes, dhelpl_t dhl)

    Transpose a  femarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     dhl:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;


    for (i = 0; i<arr->nIntPts; i++){

        oarr_invert_to( &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

