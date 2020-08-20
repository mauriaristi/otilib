
// void feoarrm3n3_dimCheck_FF_elementwise(feoarrm3n3_t* arr1, feoarrm3n3_t* arr2, feoarrm3n3_t* res);
// void feoarrm3n3_dimCheck_OF_elementwise(  oarrm3n3_t* arr1, feoarrm3n3_t* arr2, feoarrm3n3_t* res);
// void feoarrm3n3_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm3n3_t* arr2, feoarrm3n3_t* res);
// void feoarrm3n3_dimCheck_FF_matmul( feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
// void feoarrm3n3_dimCheck_OF_matmul(   oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
// void feoarrm3n3_dimCheck_RF_matmul(    darr_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
// void feoarrm3n3_dimCheck_FO_matmul( feoarrm3n3_t* lhs,   oarrm3n3_t* rhs, feoarrm3n3_t* res);
// void feoarrm3n3_dimCheck_FR_matmul( feoarrm3n3_t* lhs,    darr_t* rhs, feoarrm3n3_t* res);
// void feoarrm3n3_dimCheck_F_squareness( feoarrm3n3_t* arr1, feoarrm3n3_t* res);
// void feoarrm3n3_dimCheck_F_transpose( feoarrm3n3_t* arr1, feoarrm3n3_t* res);

// ****************************************************************************************************
feonumm3n3_t feoarrm3n3_dotproduct_FF(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feonumm3n3_t res = feonumm3n3_init();

    res = feonumm3n3_createEmpty( rhs->nip);

    feoarrm3n3_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_dotproduct_FF_to(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feonumm3n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm3n3_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm3n3_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feoarrm3n3_dotproduct_OF(oarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feonumm3n3_t res = feonumm3n3_init();

    res = feonumm3n3_createEmpty( rhs->nip);

    feoarrm3n3_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_dotproduct_OF_to( oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feonumm3n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm3n3_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm3n3_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feoarrm3n3_dotproduct_RF( darr_t* lhs, feoarrm3n3_t* rhs){

    feonumm3n3_t res = feonumm3n3_init();

    res = feonumm3n3_createEmpty( rhs->nip);

    feoarrm3n3_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_dotproduct_RF_to( darr_t* lhs, feoarrm3n3_t* rhs, feonumm3n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm3n3_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm3n3_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_matmul_FF(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res = feoarrm3n3_init();

    // Check dimensions.
    res = feoarrm3n3_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm3n3_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_matmul_FF_to(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm3n3_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm3n3_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_matmul_OF(oarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res = feoarrm3n3_init();

    // Check dimensions.
    res = feoarrm3n3_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_matmul_OF_to(oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm3n3_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm3n3_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_matmul_FO(feoarrm3n3_t* lhs, oarrm3n3_t* rhs){

    feoarrm3n3_t res = feoarrm3n3_init();

    // Check dimensions.
    res = feoarrm3n3_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm3n3_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_matmul_FO_to(feoarrm3n3_t* lhs, oarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm3n3_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm3n3_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_matmul_RF(darr_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res = feoarrm3n3_init();

    // Check dimensions.
    res = feoarrm3n3_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_matmul_RF_to(darr_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm3n3_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm3n3_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_matmul_FR(feoarrm3n3_t* lhs, darr_t* rhs){

    feoarrm3n3_t res = feoarrm3n3_init();

    // Check dimensions.
    res = feoarrm3n3_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm3n3_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_matmul_FR_to(feoarrm3n3_t* lhs, darr_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm3n3_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm3n3_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feoarrm3n3_norm(feoarrm3n3_t* arr){
    
    feonumm3n3_t res = feonumm3n3_init();

    
    res = feonumm3n3_createEmpty( arr->nip);

    feoarrm3n3_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_norm_to(feoarrm3n3_t* arr, feonumm3n3_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm3n3_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm3n3_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feoarrm3n3_pnorm(feoarrm3n3_t* arr, coeff_t p){
    
    feonumm3n3_t res = feonumm3n3_init();

    
    res = feonumm3n3_createEmpty( arr->nip);

    feoarrm3n3_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_pnorm_to(feoarrm3n3_t* arr, coeff_t p, feonumm3n3_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm3n3_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm3n3_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm3n3_t feoarrm3n3_det(feoarrm3n3_t* arr){
    
    feonumm3n3_t res = feonumm3n3_init();

    
    res = feonumm3n3_createEmpty( arr->nip);

    feoarrm3n3_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_det_to(feoarrm3n3_t* arr, feonumm3n3_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm3n3_dimCheck_F_squareness( arr, arr);
    feoarrm3n3_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm3n3_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_invert(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    // Should it copy offsets too?
    res = feoarrm3n3_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm3n3_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_invert_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm3n3_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm3n3_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_transpose(feoarrm3n3_t* arr){

    feoarrm3n3_t res = feoarrm3n3_init();

    // Should it copy offsets?
    res = feoarrm3n3_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm3n3_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_transpose_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm3n3_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm3n3_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

