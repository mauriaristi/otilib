
// void feoarrm1n3_dimCheck_FF_elementwise(feoarrm1n3_t* arr1, feoarrm1n3_t* arr2, feoarrm1n3_t* res);
// void feoarrm1n3_dimCheck_OF_elementwise(  oarrm1n3_t* arr1, feoarrm1n3_t* arr2, feoarrm1n3_t* res);
// void feoarrm1n3_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm1n3_t* arr2, feoarrm1n3_t* res);
// void feoarrm1n3_dimCheck_FF_matmul( feoarrm1n3_t* lhs, feoarrm1n3_t* rhs, feoarrm1n3_t* res);
// void feoarrm1n3_dimCheck_OF_matmul(   oarrm1n3_t* lhs, feoarrm1n3_t* rhs, feoarrm1n3_t* res);
// void feoarrm1n3_dimCheck_RF_matmul(    darr_t* lhs, feoarrm1n3_t* rhs, feoarrm1n3_t* res);
// void feoarrm1n3_dimCheck_FO_matmul( feoarrm1n3_t* lhs,   oarrm1n3_t* rhs, feoarrm1n3_t* res);
// void feoarrm1n3_dimCheck_FR_matmul( feoarrm1n3_t* lhs,    darr_t* rhs, feoarrm1n3_t* res);
// void feoarrm1n3_dimCheck_F_squareness( feoarrm1n3_t* arr1, feoarrm1n3_t* res);
// void feoarrm1n3_dimCheck_F_transpose( feoarrm1n3_t* arr1, feoarrm1n3_t* res);

// ****************************************************************************************************
feonumm1n3_t feoarrm1n3_dotproduct_FF(feoarrm1n3_t* lhs, feoarrm1n3_t* rhs){

    feonumm1n3_t res = feonumm1n3_init();

    res = feonumm1n3_createEmpty( rhs->nip);

    feoarrm1n3_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_dotproduct_FF_to(feoarrm1n3_t* lhs, feoarrm1n3_t* rhs, feonumm1n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm1n3_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm1n3_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n3_t feoarrm1n3_dotproduct_OF(oarrm1n3_t* lhs, feoarrm1n3_t* rhs){

    feonumm1n3_t res = feonumm1n3_init();

    res = feonumm1n3_createEmpty( rhs->nip);

    feoarrm1n3_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_dotproduct_OF_to( oarrm1n3_t* lhs, feoarrm1n3_t* rhs, feonumm1n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm1n3_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm1n3_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n3_t feoarrm1n3_dotproduct_RF( darr_t* lhs, feoarrm1n3_t* rhs){

    feonumm1n3_t res = feonumm1n3_init();

    res = feonumm1n3_createEmpty( rhs->nip);

    feoarrm1n3_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_dotproduct_RF_to( darr_t* lhs, feoarrm1n3_t* rhs, feonumm1n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm1n3_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm1n3_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_matmul_FF(feoarrm1n3_t* lhs, feoarrm1n3_t* rhs){

    feoarrm1n3_t res = feoarrm1n3_init();

    // Check dimensions.
    res = feoarrm1n3_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm1n3_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_matmul_FF_to(feoarrm1n3_t* lhs, feoarrm1n3_t* rhs, feoarrm1n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm1n3_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm1n3_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_matmul_OF(oarrm1n3_t* lhs, feoarrm1n3_t* rhs){

    feoarrm1n3_t res = feoarrm1n3_init();

    // Check dimensions.
    res = feoarrm1n3_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm1n3_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_matmul_OF_to(oarrm1n3_t* lhs, feoarrm1n3_t* rhs, feoarrm1n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm1n3_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm1n3_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_matmul_FO(feoarrm1n3_t* lhs, oarrm1n3_t* rhs){

    feoarrm1n3_t res = feoarrm1n3_init();

    // Check dimensions.
    res = feoarrm1n3_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm1n3_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_matmul_FO_to(feoarrm1n3_t* lhs, oarrm1n3_t* rhs, feoarrm1n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm1n3_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm1n3_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_matmul_RF(darr_t* lhs, feoarrm1n3_t* rhs){

    feoarrm1n3_t res = feoarrm1n3_init();

    // Check dimensions.
    res = feoarrm1n3_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm1n3_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_matmul_RF_to(darr_t* lhs, feoarrm1n3_t* rhs, feoarrm1n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm1n3_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm1n3_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_matmul_FR(feoarrm1n3_t* lhs, darr_t* rhs){

    feoarrm1n3_t res = feoarrm1n3_init();

    // Check dimensions.
    res = feoarrm1n3_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm1n3_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_matmul_FR_to(feoarrm1n3_t* lhs, darr_t* rhs, feoarrm1n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm1n3_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm1n3_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n3_t feoarrm1n3_norm(feoarrm1n3_t* arr){
    
    feonumm1n3_t res = feonumm1n3_init();

    
    res = feonumm1n3_createEmpty( arr->nip);

    feoarrm1n3_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_norm_to(feoarrm1n3_t* arr, feonumm1n3_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm1n3_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm1n3_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n3_t feoarrm1n3_pnorm(feoarrm1n3_t* arr, coeff_t p){
    
    feonumm1n3_t res = feonumm1n3_init();

    
    res = feonumm1n3_createEmpty( arr->nip);

    feoarrm1n3_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_pnorm_to(feoarrm1n3_t* arr, coeff_t p, feonumm1n3_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm1n3_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm1n3_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm1n3_t feoarrm1n3_det(feoarrm1n3_t* arr){
    
    feonumm1n3_t res = feonumm1n3_init();

    
    res = feonumm1n3_createEmpty( arr->nip);

    feoarrm1n3_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_det_to(feoarrm1n3_t* arr, feonumm1n3_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm1n3_dimCheck_F_squareness( arr, arr);
    feoarrm1n3_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm1n3_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_invert(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    // Should it copy offsets too?
    res = feoarrm1n3_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm1n3_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_invert_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm1n3_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm1n3_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm1n3_t feoarrm1n3_transpose(feoarrm1n3_t* arr){

    feoarrm1n3_t res = feoarrm1n3_init();

    // Should it copy offsets?
    res = feoarrm1n3_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm1n3_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_transpose_to(feoarrm1n3_t* arr, feoarrm1n3_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm1n3_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm1n3_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

