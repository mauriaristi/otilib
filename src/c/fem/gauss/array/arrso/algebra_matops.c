
// void fearrso_dimCheck_FF_elementwise(fearrso_t* arr1, fearrso_t* arr2, fearrso_t* res);
// void fearrso_dimCheck_OF_elementwise(  arrso_t* arr1, fearrso_t* arr2, fearrso_t* res);
// void fearrso_dimCheck_RF_elementwise(   darr_t* arr1, fearrso_t* arr2, fearrso_t* res);
// void fearrso_dimCheck_FF_matmul( fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res);
// void fearrso_dimCheck_OF_matmul(   arrso_t* lhs, fearrso_t* rhs, fearrso_t* res);
// void fearrso_dimCheck_RF_matmul(    darr_t* lhs, fearrso_t* rhs, fearrso_t* res);
// void fearrso_dimCheck_FO_matmul( fearrso_t* lhs,   arrso_t* rhs, fearrso_t* res);
// void fearrso_dimCheck_FR_matmul( fearrso_t* lhs,    darr_t* rhs, fearrso_t* res);
// void fearrso_dimCheck_F_squareness( fearrso_t* arr1, fearrso_t* res);
// void fearrso_dimCheck_F_transpose( fearrso_t* arr1, fearrso_t* res);


// ****************************************************************************************************
fearrso_t fearrso_matmul_FF(fearrso_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    // Check dimensions.
    res = fearrso_createEmpty_bases( lhs->nrows, rhs->ncols, 0, 0, lhs->nIntPts, 0, 0, dhl);

    fearrso_matmul_FF_to( lhs, rhs, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrso_matmul_FF_to(fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check Dimensions
    fearrso_dimCheck_FF_elementwise(lhs, rhs, res);

    for (i = 0; i<lhs->nIntPts; i++){

        arrso_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fesoti_t fearrso_det(fearrso_t* arr, dhelpl_t dhl){
    
    fesoti_t res = fesoti_init();

    
    res = fesoti_createEmpty_bases( arr->nIntPts, 0, 0, dhl);

    fearrso_det_to( arr, &res, dhl );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_det_to(fearrso_t* arr, fesoti_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    fearrso_dimCheck_F_squareness( arr, arr);

    for (i = 0; i<arr->nIntPts; i++){

        arrso_det_to( &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------







// ****************************************************************************************************
fearrso_t fearrso_invert(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    // Should it copy offsets too?
    res = fearrso_createEmpty_bases( arr->nrows, arr->ncols, 0, 0, arr->nIntPts, 0, 0, dhl);
    
    fearrso_invert_to( arr, &res, dhl );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_invert_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check dimensions (must be square and equal).
    fearrso_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nIntPts; i++){

        arrso_invert_to( &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fearrso_t fearrso_transpose(fearrso_t* arr, dhelpl_t dhl){

    fearrso_t res = fearrso_init();

    // Should it copy offsets?
    res = fearrso_createEmpty_bases( arr->ncols, arr->nrows, 0, 0, arr->nIntPts, 0, 0, dhl);
    
    fearrso_transpose_to( arr, &res, dhl );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_transpose_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check dimensions.
    fearrso_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nIntPts; i++){

        arrso_transpose_to( &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------





