
// void feoarrm5n4_dimCheck_FF_elementwise(feoarrm5n4_t* arr1, feoarrm5n4_t* arr2, feoarrm5n4_t* res);
// void feoarrm5n4_dimCheck_OF_elementwise(  oarrm5n4_t* arr1, feoarrm5n4_t* arr2, feoarrm5n4_t* res);
// void feoarrm5n4_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm5n4_t* arr2, feoarrm5n4_t* res);
// void feoarrm5n4_dimCheck_FF_matmul( feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
// void feoarrm5n4_dimCheck_OF_matmul(   oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
// void feoarrm5n4_dimCheck_RF_matmul(    darr_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
// void feoarrm5n4_dimCheck_FO_matmul( feoarrm5n4_t* lhs,   oarrm5n4_t* rhs, feoarrm5n4_t* res);
// void feoarrm5n4_dimCheck_FR_matmul( feoarrm5n4_t* lhs,    darr_t* rhs, feoarrm5n4_t* res);
// void feoarrm5n4_dimCheck_F_squareness( feoarrm5n4_t* arr1, feoarrm5n4_t* res);
// void feoarrm5n4_dimCheck_F_transpose( feoarrm5n4_t* arr1, feoarrm5n4_t* res);

// ****************************************************************************************************
feonumm5n4_t feoarrm5n4_dotproduct_FF(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feonumm5n4_t res = feonumm5n4_init();

    res = feonumm5n4_createEmpty( rhs->nip);

    feoarrm5n4_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_dotproduct_FF_to(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feonumm5n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n4_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n4_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feoarrm5n4_dotproduct_OF(oarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feonumm5n4_t res = feonumm5n4_init();

    res = feonumm5n4_createEmpty( rhs->nip);

    feoarrm5n4_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_dotproduct_OF_to( oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feonumm5n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n4_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm5n4_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feoarrm5n4_dotproduct_RF( darr_t* lhs, feoarrm5n4_t* rhs){

    feonumm5n4_t res = feonumm5n4_init();

    res = feonumm5n4_createEmpty( rhs->nip);

    feoarrm5n4_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_dotproduct_RF_to( darr_t* lhs, feoarrm5n4_t* rhs, feonumm5n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n4_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm5n4_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_matmul_FF(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res = feoarrm5n4_init();

    // Check dimensions.
    res = feoarrm5n4_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm5n4_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_matmul_FF_to(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n4_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n4_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_matmul_OF(oarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res = feoarrm5n4_init();

    // Check dimensions.
    res = feoarrm5n4_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_matmul_OF_to(oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n4_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n4_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_matmul_FO(feoarrm5n4_t* lhs, oarrm5n4_t* rhs){

    feoarrm5n4_t res = feoarrm5n4_init();

    // Check dimensions.
    res = feoarrm5n4_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm5n4_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_matmul_FO_to(feoarrm5n4_t* lhs, oarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n4_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n4_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_matmul_RF(darr_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res = feoarrm5n4_init();

    // Check dimensions.
    res = feoarrm5n4_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_matmul_RF_to(darr_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n4_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n4_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_matmul_FR(feoarrm5n4_t* lhs, darr_t* rhs){

    feoarrm5n4_t res = feoarrm5n4_init();

    // Check dimensions.
    res = feoarrm5n4_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm5n4_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_matmul_FR_to(feoarrm5n4_t* lhs, darr_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n4_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n4_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feoarrm5n4_norm(feoarrm5n4_t* arr){
    
    feonumm5n4_t res = feonumm5n4_init();

    
    res = feonumm5n4_createEmpty( arr->nip);

    feoarrm5n4_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_norm_to(feoarrm5n4_t* arr, feonumm5n4_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm5n4_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm5n4_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feoarrm5n4_pnorm(feoarrm5n4_t* arr, coeff_t p){
    
    feonumm5n4_t res = feonumm5n4_init();

    
    res = feonumm5n4_createEmpty( arr->nip);

    feoarrm5n4_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_pnorm_to(feoarrm5n4_t* arr, coeff_t p, feonumm5n4_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm5n4_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm5n4_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n4_t feoarrm5n4_det(feoarrm5n4_t* arr){
    
    feonumm5n4_t res = feonumm5n4_init();

    
    res = feonumm5n4_createEmpty( arr->nip);

    feoarrm5n4_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_det_to(feoarrm5n4_t* arr, feonumm5n4_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm5n4_dimCheck_F_squareness( arr, arr);
    feoarrm5n4_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm5n4_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_invert(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    // Should it copy offsets too?
    res = feoarrm5n4_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n4_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_invert_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm5n4_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm5n4_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_transpose(feoarrm5n4_t* arr){

    feoarrm5n4_t res = feoarrm5n4_init();

    // Should it copy offsets?
    res = feoarrm5n4_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm5n4_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_transpose_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm5n4_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm5n4_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

