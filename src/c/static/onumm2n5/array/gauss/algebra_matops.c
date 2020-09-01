
// void feoarrm2n5_dimCheck_FF_elementwise(feoarrm2n5_t* arr1, feoarrm2n5_t* arr2, feoarrm2n5_t* res);
// void feoarrm2n5_dimCheck_OF_elementwise(  oarrm2n5_t* arr1, feoarrm2n5_t* arr2, feoarrm2n5_t* res);
// void feoarrm2n5_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm2n5_t* arr2, feoarrm2n5_t* res);
// void feoarrm2n5_dimCheck_FF_matmul( feoarrm2n5_t* lhs, feoarrm2n5_t* rhs, feoarrm2n5_t* res);
// void feoarrm2n5_dimCheck_OF_matmul(   oarrm2n5_t* lhs, feoarrm2n5_t* rhs, feoarrm2n5_t* res);
// void feoarrm2n5_dimCheck_RF_matmul(    darr_t* lhs, feoarrm2n5_t* rhs, feoarrm2n5_t* res);
// void feoarrm2n5_dimCheck_FO_matmul( feoarrm2n5_t* lhs,   oarrm2n5_t* rhs, feoarrm2n5_t* res);
// void feoarrm2n5_dimCheck_FR_matmul( feoarrm2n5_t* lhs,    darr_t* rhs, feoarrm2n5_t* res);
// void feoarrm2n5_dimCheck_F_squareness( feoarrm2n5_t* arr1, feoarrm2n5_t* res);
// void feoarrm2n5_dimCheck_F_transpose( feoarrm2n5_t* arr1, feoarrm2n5_t* res);

// ****************************************************************************************************
feonumm2n5_t feoarrm2n5_dotproduct_FF(feoarrm2n5_t* lhs, feoarrm2n5_t* rhs){

    feonumm2n5_t res = feonumm2n5_init();

    res = feonumm2n5_createEmpty( rhs->nip);

    feoarrm2n5_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_dotproduct_FF_to(feoarrm2n5_t* lhs, feoarrm2n5_t* rhs, feonumm2n5_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n5_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n5_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n5_t feoarrm2n5_dotproduct_OF(oarrm2n5_t* lhs, feoarrm2n5_t* rhs){

    feonumm2n5_t res = feonumm2n5_init();

    res = feonumm2n5_createEmpty( rhs->nip);

    feoarrm2n5_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_dotproduct_OF_to( oarrm2n5_t* lhs, feoarrm2n5_t* rhs, feonumm2n5_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n5_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm2n5_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n5_t feoarrm2n5_dotproduct_RF( darr_t* lhs, feoarrm2n5_t* rhs){

    feonumm2n5_t res = feonumm2n5_init();

    res = feonumm2n5_createEmpty( rhs->nip);

    feoarrm2n5_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_dotproduct_RF_to( darr_t* lhs, feoarrm2n5_t* rhs, feonumm2n5_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n5_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm2n5_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_matmul_FF(feoarrm2n5_t* lhs, feoarrm2n5_t* rhs){

    feoarrm2n5_t res = feoarrm2n5_init();

    // Check dimensions.
    res = feoarrm2n5_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm2n5_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_matmul_FF_to(feoarrm2n5_t* lhs, feoarrm2n5_t* rhs, feoarrm2n5_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n5_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n5_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_matmul_OF(oarrm2n5_t* lhs, feoarrm2n5_t* rhs){

    feoarrm2n5_t res = feoarrm2n5_init();

    // Check dimensions.
    res = feoarrm2n5_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n5_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_matmul_OF_to(oarrm2n5_t* lhs, feoarrm2n5_t* rhs, feoarrm2n5_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n5_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n5_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_matmul_FO(feoarrm2n5_t* lhs, oarrm2n5_t* rhs){

    feoarrm2n5_t res = feoarrm2n5_init();

    // Check dimensions.
    res = feoarrm2n5_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm2n5_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_matmul_FO_to(feoarrm2n5_t* lhs, oarrm2n5_t* rhs, feoarrm2n5_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n5_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n5_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_matmul_RF(darr_t* lhs, feoarrm2n5_t* rhs){

    feoarrm2n5_t res = feoarrm2n5_init();

    // Check dimensions.
    res = feoarrm2n5_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n5_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_matmul_RF_to(darr_t* lhs, feoarrm2n5_t* rhs, feoarrm2n5_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n5_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n5_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_matmul_FR(feoarrm2n5_t* lhs, darr_t* rhs){

    feoarrm2n5_t res = feoarrm2n5_init();

    // Check dimensions.
    res = feoarrm2n5_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm2n5_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_matmul_FR_to(feoarrm2n5_t* lhs, darr_t* rhs, feoarrm2n5_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n5_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n5_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n5_t feoarrm2n5_norm(feoarrm2n5_t* arr){
    
    feonumm2n5_t res = feonumm2n5_init();

    
    res = feonumm2n5_createEmpty( arr->nip);

    feoarrm2n5_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_norm_to(feoarrm2n5_t* arr, feonumm2n5_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm2n5_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm2n5_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n5_t feoarrm2n5_pnorm(feoarrm2n5_t* arr, coeff_t p){
    
    feonumm2n5_t res = feonumm2n5_init();

    
    res = feonumm2n5_createEmpty( arr->nip);

    feoarrm2n5_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_pnorm_to(feoarrm2n5_t* arr, coeff_t p, feonumm2n5_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm2n5_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm2n5_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n5_t feoarrm2n5_det(feoarrm2n5_t* arr){
    
    feonumm2n5_t res = feonumm2n5_init();

    
    res = feonumm2n5_createEmpty( arr->nip);

    feoarrm2n5_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_det_to(feoarrm2n5_t* arr, feonumm2n5_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm2n5_dimCheck_F_squareness( arr, arr);
    feoarrm2n5_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm2n5_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_invert(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    // Should it copy offsets too?
    res = feoarrm2n5_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n5_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_invert_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm2n5_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm2n5_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n5_t feoarrm2n5_transpose(feoarrm2n5_t* arr){

    feoarrm2n5_t res = feoarrm2n5_init();

    // Should it copy offsets?
    res = feoarrm2n5_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm2n5_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n5_transpose_to(feoarrm2n5_t* arr, feoarrm2n5_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm2n5_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm2n5_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

