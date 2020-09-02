
// void feoarrm2n8_dimCheck_FF_elementwise(feoarrm2n8_t* arr1, feoarrm2n8_t* arr2, feoarrm2n8_t* res);
// void feoarrm2n8_dimCheck_OF_elementwise(  oarrm2n8_t* arr1, feoarrm2n8_t* arr2, feoarrm2n8_t* res);
// void feoarrm2n8_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm2n8_t* arr2, feoarrm2n8_t* res);
// void feoarrm2n8_dimCheck_FF_matmul( feoarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);
// void feoarrm2n8_dimCheck_OF_matmul(   oarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);
// void feoarrm2n8_dimCheck_RF_matmul(    darr_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);
// void feoarrm2n8_dimCheck_FO_matmul( feoarrm2n8_t* lhs,   oarrm2n8_t* rhs, feoarrm2n8_t* res);
// void feoarrm2n8_dimCheck_FR_matmul( feoarrm2n8_t* lhs,    darr_t* rhs, feoarrm2n8_t* res);
// void feoarrm2n8_dimCheck_F_squareness( feoarrm2n8_t* arr1, feoarrm2n8_t* res);
// void feoarrm2n8_dimCheck_F_transpose( feoarrm2n8_t* arr1, feoarrm2n8_t* res);

// ****************************************************************************************************
feonumm2n8_t feoarrm2n8_dotproduct_FF(feoarrm2n8_t* lhs, feoarrm2n8_t* rhs){

    feonumm2n8_t res = feonumm2n8_init();

    res = feonumm2n8_createEmpty( rhs->nip);

    feoarrm2n8_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_dotproduct_FF_to(feoarrm2n8_t* lhs, feoarrm2n8_t* rhs, feonumm2n8_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n8_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n8_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n8_t feoarrm2n8_dotproduct_OF(oarrm2n8_t* lhs, feoarrm2n8_t* rhs){

    feonumm2n8_t res = feonumm2n8_init();

    res = feonumm2n8_createEmpty( rhs->nip);

    feoarrm2n8_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_dotproduct_OF_to( oarrm2n8_t* lhs, feoarrm2n8_t* rhs, feonumm2n8_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n8_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm2n8_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n8_t feoarrm2n8_dotproduct_RF( darr_t* lhs, feoarrm2n8_t* rhs){

    feonumm2n8_t res = feonumm2n8_init();

    res = feonumm2n8_createEmpty( rhs->nip);

    feoarrm2n8_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_dotproduct_RF_to( darr_t* lhs, feoarrm2n8_t* rhs, feonumm2n8_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n8_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm2n8_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_matmul_FF(feoarrm2n8_t* lhs, feoarrm2n8_t* rhs){

    feoarrm2n8_t res = feoarrm2n8_init();

    // Check dimensions.
    res = feoarrm2n8_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm2n8_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_matmul_FF_to(feoarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n8_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n8_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_matmul_OF(oarrm2n8_t* lhs, feoarrm2n8_t* rhs){

    feoarrm2n8_t res = feoarrm2n8_init();

    // Check dimensions.
    res = feoarrm2n8_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n8_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_matmul_OF_to(oarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n8_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n8_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_matmul_FO(feoarrm2n8_t* lhs, oarrm2n8_t* rhs){

    feoarrm2n8_t res = feoarrm2n8_init();

    // Check dimensions.
    res = feoarrm2n8_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm2n8_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_matmul_FO_to(feoarrm2n8_t* lhs, oarrm2n8_t* rhs, feoarrm2n8_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n8_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n8_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_matmul_RF(darr_t* lhs, feoarrm2n8_t* rhs){

    feoarrm2n8_t res = feoarrm2n8_init();

    // Check dimensions.
    res = feoarrm2n8_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n8_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_matmul_RF_to(darr_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n8_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n8_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_matmul_FR(feoarrm2n8_t* lhs, darr_t* rhs){

    feoarrm2n8_t res = feoarrm2n8_init();

    // Check dimensions.
    res = feoarrm2n8_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm2n8_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_matmul_FR_to(feoarrm2n8_t* lhs, darr_t* rhs, feoarrm2n8_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n8_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n8_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n8_t feoarrm2n8_norm(feoarrm2n8_t* arr){
    
    feonumm2n8_t res = feonumm2n8_init();

    
    res = feonumm2n8_createEmpty( arr->nip);

    feoarrm2n8_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_norm_to(feoarrm2n8_t* arr, feonumm2n8_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm2n8_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm2n8_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n8_t feoarrm2n8_pnorm(feoarrm2n8_t* arr, coeff_t p){
    
    feonumm2n8_t res = feonumm2n8_init();

    
    res = feonumm2n8_createEmpty( arr->nip);

    feoarrm2n8_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_pnorm_to(feoarrm2n8_t* arr, coeff_t p, feonumm2n8_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm2n8_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm2n8_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n8_t feoarrm2n8_det(feoarrm2n8_t* arr){
    
    feonumm2n8_t res = feonumm2n8_init();

    
    res = feonumm2n8_createEmpty( arr->nip);

    feoarrm2n8_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_det_to(feoarrm2n8_t* arr, feonumm2n8_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm2n8_dimCheck_F_squareness( arr, arr);
    feoarrm2n8_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm2n8_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_invert(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    // Should it copy offsets too?
    res = feoarrm2n8_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n8_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_invert_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm2n8_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm2n8_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n8_t feoarrm2n8_transpose(feoarrm2n8_t* arr){

    feoarrm2n8_t res = feoarrm2n8_init();

    // Should it copy offsets?
    res = feoarrm2n8_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm2n8_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n8_transpose_to(feoarrm2n8_t* arr, feoarrm2n8_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm2n8_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm2n8_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

