
// void feoarrm0n0_dimCheck_FF_elementwise(feoarrm0n0_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res);
// void feoarrm0n0_dimCheck_OF_elementwise(  oarrm0n0_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res);
// void feoarrm0n0_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res);
// void feoarrm0n0_dimCheck_FF_matmul( feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
// void feoarrm0n0_dimCheck_OF_matmul(   oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
// void feoarrm0n0_dimCheck_RF_matmul(    darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
// void feoarrm0n0_dimCheck_FO_matmul( feoarrm0n0_t* lhs,   oarrm0n0_t* rhs, feoarrm0n0_t* res);
// void feoarrm0n0_dimCheck_FR_matmul( feoarrm0n0_t* lhs,    darr_t* rhs, feoarrm0n0_t* res);
// void feoarrm0n0_dimCheck_F_squareness( feoarrm0n0_t* arr1, feoarrm0n0_t* res);
// void feoarrm0n0_dimCheck_F_transpose( feoarrm0n0_t* arr1, feoarrm0n0_t* res);

// ****************************************************************************************************
feonumm0n0_t feoarrm0n0_dotproduct_FF(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feonumm0n0_t res = feonumm0n0_init();

    res = feonumm0n0_createEmpty( rhs->nip);

    feoarrm0n0_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_dotproduct_FF_to(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feonumm0n0_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm0n0_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm0n0_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feoarrm0n0_dotproduct_OF(oarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feonumm0n0_t res = feonumm0n0_init();

    res = feonumm0n0_createEmpty( rhs->nip);

    feoarrm0n0_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_dotproduct_OF_to( oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feonumm0n0_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm0n0_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm0n0_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feoarrm0n0_dotproduct_RF( darr_t* lhs, feoarrm0n0_t* rhs){

    feonumm0n0_t res = feonumm0n0_init();

    res = feonumm0n0_createEmpty( rhs->nip);

    feoarrm0n0_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_dotproduct_RF_to( darr_t* lhs, feoarrm0n0_t* rhs, feonumm0n0_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm0n0_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm0n0_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_matmul_FF(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res = feoarrm0n0_init();

    // Check dimensions.
    res = feoarrm0n0_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm0n0_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_matmul_FF_to(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm0n0_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm0n0_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_matmul_OF(oarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res = feoarrm0n0_init();

    // Check dimensions.
    res = feoarrm0n0_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_matmul_OF_to(oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm0n0_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm0n0_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_matmul_FO(feoarrm0n0_t* lhs, oarrm0n0_t* rhs){

    feoarrm0n0_t res = feoarrm0n0_init();

    // Check dimensions.
    res = feoarrm0n0_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm0n0_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_matmul_FO_to(feoarrm0n0_t* lhs, oarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm0n0_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm0n0_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_matmul_RF(darr_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res = feoarrm0n0_init();

    // Check dimensions.
    res = feoarrm0n0_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_matmul_RF_to(darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm0n0_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm0n0_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_matmul_FR(feoarrm0n0_t* lhs, darr_t* rhs){

    feoarrm0n0_t res = feoarrm0n0_init();

    // Check dimensions.
    res = feoarrm0n0_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm0n0_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_matmul_FR_to(feoarrm0n0_t* lhs, darr_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm0n0_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm0n0_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feoarrm0n0_norm(feoarrm0n0_t* arr){
    
    feonumm0n0_t res = feonumm0n0_init();

    
    res = feonumm0n0_createEmpty( arr->nip);

    feoarrm0n0_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_norm_to(feoarrm0n0_t* arr, feonumm0n0_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm0n0_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm0n0_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feoarrm0n0_pnorm(feoarrm0n0_t* arr, coeff_t p){
    
    feonumm0n0_t res = feonumm0n0_init();

    
    res = feonumm0n0_createEmpty( arr->nip);

    feoarrm0n0_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_pnorm_to(feoarrm0n0_t* arr, coeff_t p, feonumm0n0_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm0n0_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm0n0_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm0n0_t feoarrm0n0_det(feoarrm0n0_t* arr){
    
    feonumm0n0_t res = feonumm0n0_init();

    
    res = feonumm0n0_createEmpty( arr->nip);

    feoarrm0n0_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_det_to(feoarrm0n0_t* arr, feonumm0n0_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm0n0_dimCheck_F_squareness( arr, arr);
    feoarrm0n0_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm0n0_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_invert(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    // Should it copy offsets too?
    res = feoarrm0n0_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm0n0_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_invert_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm0n0_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm0n0_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_transpose(feoarrm0n0_t* arr){

    feoarrm0n0_t res = feoarrm0n0_init();

    // Should it copy offsets?
    res = feoarrm0n0_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm0n0_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_transpose_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm0n0_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm0n0_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

