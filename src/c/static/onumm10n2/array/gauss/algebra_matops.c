
// void feoarrm10n2_dimCheck_FF_elementwise(feoarrm10n2_t* arr1, feoarrm10n2_t* arr2, feoarrm10n2_t* res);
// void feoarrm10n2_dimCheck_OF_elementwise(  oarrm10n2_t* arr1, feoarrm10n2_t* arr2, feoarrm10n2_t* res);
// void feoarrm10n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm10n2_t* arr2, feoarrm10n2_t* res);
// void feoarrm10n2_dimCheck_FF_matmul( feoarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
// void feoarrm10n2_dimCheck_OF_matmul(   oarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
// void feoarrm10n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
// void feoarrm10n2_dimCheck_FO_matmul( feoarrm10n2_t* lhs,   oarrm10n2_t* rhs, feoarrm10n2_t* res);
// void feoarrm10n2_dimCheck_FR_matmul( feoarrm10n2_t* lhs,    darr_t* rhs, feoarrm10n2_t* res);
// void feoarrm10n2_dimCheck_F_squareness( feoarrm10n2_t* arr1, feoarrm10n2_t* res);
// void feoarrm10n2_dimCheck_F_transpose( feoarrm10n2_t* arr1, feoarrm10n2_t* res);

// ****************************************************************************************************
feonumm10n2_t feoarrm10n2_dotproduct_FF(feoarrm10n2_t* lhs, feoarrm10n2_t* rhs){

    feonumm10n2_t res = feonumm10n2_init();

    res = feonumm10n2_createEmpty( rhs->nip);

    feoarrm10n2_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_dotproduct_FF_to(feoarrm10n2_t* lhs, feoarrm10n2_t* rhs, feonumm10n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm10n2_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm10n2_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm10n2_t feoarrm10n2_dotproduct_OF(oarrm10n2_t* lhs, feoarrm10n2_t* rhs){

    feonumm10n2_t res = feonumm10n2_init();

    res = feonumm10n2_createEmpty( rhs->nip);

    feoarrm10n2_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_dotproduct_OF_to( oarrm10n2_t* lhs, feoarrm10n2_t* rhs, feonumm10n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm10n2_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm10n2_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm10n2_t feoarrm10n2_dotproduct_RF( darr_t* lhs, feoarrm10n2_t* rhs){

    feonumm10n2_t res = feonumm10n2_init();

    res = feonumm10n2_createEmpty( rhs->nip);

    feoarrm10n2_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_dotproduct_RF_to( darr_t* lhs, feoarrm10n2_t* rhs, feonumm10n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm10n2_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm10n2_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_matmul_FF(feoarrm10n2_t* lhs, feoarrm10n2_t* rhs){

    feoarrm10n2_t res = feoarrm10n2_init();

    // Check dimensions.
    res = feoarrm10n2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm10n2_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_matmul_FF_to(feoarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm10n2_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm10n2_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_matmul_OF(oarrm10n2_t* lhs, feoarrm10n2_t* rhs){

    feoarrm10n2_t res = feoarrm10n2_init();

    // Check dimensions.
    res = feoarrm10n2_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm10n2_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_matmul_OF_to(oarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm10n2_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm10n2_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_matmul_FO(feoarrm10n2_t* lhs, oarrm10n2_t* rhs){

    feoarrm10n2_t res = feoarrm10n2_init();

    // Check dimensions.
    res = feoarrm10n2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm10n2_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_matmul_FO_to(feoarrm10n2_t* lhs, oarrm10n2_t* rhs, feoarrm10n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm10n2_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm10n2_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_matmul_RF(darr_t* lhs, feoarrm10n2_t* rhs){

    feoarrm10n2_t res = feoarrm10n2_init();

    // Check dimensions.
    res = feoarrm10n2_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm10n2_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_matmul_RF_to(darr_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm10n2_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm10n2_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_matmul_FR(feoarrm10n2_t* lhs, darr_t* rhs){

    feoarrm10n2_t res = feoarrm10n2_init();

    // Check dimensions.
    res = feoarrm10n2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm10n2_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_matmul_FR_to(feoarrm10n2_t* lhs, darr_t* rhs, feoarrm10n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm10n2_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm10n2_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm10n2_t feoarrm10n2_norm(feoarrm10n2_t* arr){
    
    feonumm10n2_t res = feonumm10n2_init();

    
    res = feonumm10n2_createEmpty( arr->nip);

    feoarrm10n2_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_norm_to(feoarrm10n2_t* arr, feonumm10n2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm10n2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm10n2_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm10n2_t feoarrm10n2_pnorm(feoarrm10n2_t* arr, coeff_t p){
    
    feonumm10n2_t res = feonumm10n2_init();

    
    res = feonumm10n2_createEmpty( arr->nip);

    feoarrm10n2_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_pnorm_to(feoarrm10n2_t* arr, coeff_t p, feonumm10n2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm10n2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm10n2_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm10n2_t feoarrm10n2_det(feoarrm10n2_t* arr){
    
    feonumm10n2_t res = feonumm10n2_init();

    
    res = feonumm10n2_createEmpty( arr->nip);

    feoarrm10n2_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_det_to(feoarrm10n2_t* arr, feonumm10n2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm10n2_dimCheck_F_squareness( arr, arr);
    feoarrm10n2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm10n2_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_invert(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    // Should it copy offsets too?
    res = feoarrm10n2_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm10n2_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_invert_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm10n2_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm10n2_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm10n2_t feoarrm10n2_transpose(feoarrm10n2_t* arr){

    feoarrm10n2_t res = feoarrm10n2_init();

    // Should it copy offsets?
    res = feoarrm10n2_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm10n2_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm10n2_transpose_to(feoarrm10n2_t* arr, feoarrm10n2_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm10n2_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm10n2_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

