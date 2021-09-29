
// void fearrsso_dimCheck_FF_elementwise(fearrsso_t* arr1, fearrsso_t* arr2, fearrsso_t* res);
// void fearrsso_dimCheck_OF_elementwise(  arrsso_t* arr1, fearrsso_t* arr2, fearrsso_t* res);
// void fearrsso_dimCheck_RF_elementwise(   darr_t* arr1, fearrsso_t* arr2, fearrsso_t* res);
// void fearrsso_dimCheck_FF_matmul( fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res);
// void fearrsso_dimCheck_OF_matmul(   arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res);
// void fearrsso_dimCheck_RF_matmul(    darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res);
// void fearrsso_dimCheck_FO_matmul( fearrsso_t* lhs,   arrsso_t* rhs, fearrsso_t* res);
// void fearrsso_dimCheck_FR_matmul( fearrsso_t* lhs,    darr_t* rhs, fearrsso_t* res);
// void fearrsso_dimCheck_F_squareness( fearrsso_t* arr1, fearrsso_t* res);
// void fearrsso_dimCheck_F_transpose( fearrsso_t* arr1, fearrsso_t* res);


// ****************************************************************************************************
fessoti_t fearrsso_dotproduct_FF(fearrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fessoti_t res = fessoti_init();

    res = fessoti_createEmpty_bases( rhs->nip, 0, 0, dhl);

    fearrsso_dotproduct_FF_to(lhs, rhs, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_dotproduct_FF_to(fearrsso_t* lhs, fearrsso_t* rhs, fessoti_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check Dimensions
    fearrsso_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        arrsso_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
fessoti_t fearrsso_dotproduct_OF(arrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fessoti_t res = fessoti_init();

    res = fessoti_createEmpty_bases( rhs->nip, 0, 0, dhl);

    fearrsso_dotproduct_OF_to( lhs, rhs, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_dotproduct_OF_to( arrsso_t* lhs, fearrsso_t* rhs, fessoti_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check Dimensions
    fearrsso_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        arrsso_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
fessoti_t fearrsso_dotproduct_RF( darr_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fessoti_t res = fessoti_init();

    res = fessoti_createEmpty_bases( rhs->nip, 0, 0, dhl);

    fearrsso_dotproduct_RF_to( lhs, rhs, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_dotproduct_RF_to( darr_t* lhs, fearrsso_t* rhs, fessoti_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check Dimensions
    fearrsso_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        arrsso_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------






















// ****************************************************************************************************
fearrsso_t fearrsso_matmul_FF(fearrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    // Check dimensions.
    res = fearrsso_createEmpty_bases( lhs->nrows, rhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_matmul_FF_to( lhs, rhs, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_matmul_FF_to(fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check Dimensions
    fearrsso_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        arrsso_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fearrsso_t fearrsso_matmul_OF(arrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    // Check dimensions.
    res = fearrsso_createEmpty_bases( lhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_matmul_OF_to( lhs, rhs, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_matmul_OF_to(arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check Dimensions
    fearrsso_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        arrsso_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_matmul_FO(fearrsso_t* lhs, arrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    // Check dimensions.
    res = fearrsso_createEmpty_bases( lhs->nrows, rhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_matmul_FO_to( lhs, rhs, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_matmul_FO_to(fearrsso_t* lhs, arrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check Dimensions
    fearrsso_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        arrsso_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------







// ****************************************************************************************************
fearrsso_t fearrsso_matmul_RF(darr_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    // Check dimensions.
    res = fearrsso_createEmpty_bases( lhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_matmul_RF_to( lhs, rhs, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_matmul_RF_to(darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check Dimensions
    fearrsso_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        arrsso_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_matmul_FR(fearrsso_t* lhs, darr_t* rhs, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    // Check dimensions.
    res = fearrsso_createEmpty_bases( lhs->nrows, rhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_matmul_FR_to( lhs, rhs, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_matmul_FR_to(fearrsso_t* lhs, darr_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check Dimensions
    fearrsso_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        arrsso_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i], dhl );

    }

}
// ----------------------------------------------------------------------------------------------------


















// ****************************************************************************************************
fessoti_t fearrsso_norm(fearrsso_t* arr, dhelpl_t dhl){
    
    fessoti_t res = fessoti_init();

    
    res = fessoti_createEmpty_bases( arr->nip, 0, 0, dhl);

    fearrsso_norm_to( arr, &res, dhl );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_norm_to(fearrsso_t* arr, fessoti_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    fearrsso_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        arrsso_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------










// ****************************************************************************************************
fessoti_t fearrsso_pnorm(fearrsso_t* arr, coeff_t p, dhelpl_t dhl){
    
    fessoti_t res = fessoti_init();

    
    res = fessoti_createEmpty_bases( arr->nip, 0, 0, dhl);

    fearrsso_pnorm_to( arr, p, &res, dhl );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_pnorm_to(fearrsso_t* arr, coeff_t p, fessoti_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    fearrsso_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        arrsso_pnorm_to( &arr->p_data[i], p, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fessoti_t fearrsso_det(fearrsso_t* arr, dhelpl_t dhl){
    
    fessoti_t res = fessoti_init();

    
    res = fessoti_createEmpty_bases( arr->nip, 0, 0, dhl);

    fearrsso_det_to( arr, &res, dhl );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_det_to(fearrsso_t* arr, fessoti_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    fearrsso_dimCheck_F_squareness( arr, arr);
    fearrsso_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        arrsso_det_to( &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------



















// ****************************************************************************************************
fearrsso_t fearrsso_invert(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    // Should it copy offsets too?
    res = fearrsso_createEmpty_bases( arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);
    
    fearrsso_invert_to( arr, &res, dhl );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_invert_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check dimensions (must be square and equal).
    fearrsso_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        arrsso_invert_to( &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

















// ****************************************************************************************************
fearrsso_t fearrsso_transpose(fearrsso_t* arr, dhelpl_t dhl){

    fearrsso_t res = fearrsso_init();

    // Should it copy offsets?
    res = fearrsso_createEmpty_bases( arr->ncols, arr->nrows, arr->nip, 0, 0, dhl);
    
    fearrsso_transpose_to( arr, &res, dhl );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_transpose_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check dimensions.
    fearrsso_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        arrsso_transpose_to( &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------





