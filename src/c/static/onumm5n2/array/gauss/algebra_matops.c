
// void feoarrm5n2_dimCheck_FF_elementwise(feoarrm5n2_t* arr1, feoarrm5n2_t* arr2, feoarrm5n2_t* res);
// void feoarrm5n2_dimCheck_OF_elementwise(  oarrm5n2_t* arr1, feoarrm5n2_t* arr2, feoarrm5n2_t* res);
// void feoarrm5n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm5n2_t* arr2, feoarrm5n2_t* res);
// void feoarrm5n2_dimCheck_FF_matmul( feoarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
// void feoarrm5n2_dimCheck_OF_matmul(   oarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
// void feoarrm5n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
// void feoarrm5n2_dimCheck_FO_matmul( feoarrm5n2_t* lhs,   oarrm5n2_t* rhs, feoarrm5n2_t* res);
// void feoarrm5n2_dimCheck_FR_matmul( feoarrm5n2_t* lhs,    darr_t* rhs, feoarrm5n2_t* res);
// void feoarrm5n2_dimCheck_F_squareness( feoarrm5n2_t* arr1, feoarrm5n2_t* res);
// void feoarrm5n2_dimCheck_F_transpose( feoarrm5n2_t* arr1, feoarrm5n2_t* res);

// ****************************************************************************************************
feonumm5n2_t feoarrm5n2_dotproduct_FF(feoarrm5n2_t* lhs, feoarrm5n2_t* rhs){

    feonumm5n2_t res = feonumm5n2_init();

    res = feonumm5n2_createEmpty( rhs->nip);

    feoarrm5n2_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_dotproduct_FF_to(feoarrm5n2_t* lhs, feoarrm5n2_t* rhs, feonumm5n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n2_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n2_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n2_t feoarrm5n2_dotproduct_OF(oarrm5n2_t* lhs, feoarrm5n2_t* rhs){

    feonumm5n2_t res = feonumm5n2_init();

    res = feonumm5n2_createEmpty( rhs->nip);

    feoarrm5n2_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_dotproduct_OF_to( oarrm5n2_t* lhs, feoarrm5n2_t* rhs, feonumm5n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n2_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm5n2_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n2_t feoarrm5n2_dotproduct_RF( darr_t* lhs, feoarrm5n2_t* rhs){

    feonumm5n2_t res = feonumm5n2_init();

    res = feonumm5n2_createEmpty( rhs->nip);

    feoarrm5n2_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_dotproduct_RF_to( darr_t* lhs, feoarrm5n2_t* rhs, feonumm5n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n2_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm5n2_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_matmul_FF(feoarrm5n2_t* lhs, feoarrm5n2_t* rhs){

    feoarrm5n2_t res = feoarrm5n2_init();

    // Check dimensions.
    res = feoarrm5n2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm5n2_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_matmul_FF_to(feoarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n2_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n2_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_matmul_OF(oarrm5n2_t* lhs, feoarrm5n2_t* rhs){

    feoarrm5n2_t res = feoarrm5n2_init();

    // Check dimensions.
    res = feoarrm5n2_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n2_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_matmul_OF_to(oarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n2_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n2_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_matmul_FO(feoarrm5n2_t* lhs, oarrm5n2_t* rhs){

    feoarrm5n2_t res = feoarrm5n2_init();

    // Check dimensions.
    res = feoarrm5n2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm5n2_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_matmul_FO_to(feoarrm5n2_t* lhs, oarrm5n2_t* rhs, feoarrm5n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n2_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n2_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_matmul_RF(darr_t* lhs, feoarrm5n2_t* rhs){

    feoarrm5n2_t res = feoarrm5n2_init();

    // Check dimensions.
    res = feoarrm5n2_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n2_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_matmul_RF_to(darr_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n2_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n2_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_matmul_FR(feoarrm5n2_t* lhs, darr_t* rhs){

    feoarrm5n2_t res = feoarrm5n2_init();

    // Check dimensions.
    res = feoarrm5n2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm5n2_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_matmul_FR_to(feoarrm5n2_t* lhs, darr_t* rhs, feoarrm5n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n2_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n2_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n2_t feoarrm5n2_norm(feoarrm5n2_t* arr){
    
    feonumm5n2_t res = feonumm5n2_init();

    
    res = feonumm5n2_createEmpty( arr->nip);

    feoarrm5n2_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_norm_to(feoarrm5n2_t* arr, feonumm5n2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm5n2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm5n2_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n2_t feoarrm5n2_pnorm(feoarrm5n2_t* arr, coeff_t p){
    
    feonumm5n2_t res = feonumm5n2_init();

    
    res = feonumm5n2_createEmpty( arr->nip);

    feoarrm5n2_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_pnorm_to(feoarrm5n2_t* arr, coeff_t p, feonumm5n2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm5n2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm5n2_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n2_t feoarrm5n2_det(feoarrm5n2_t* arr){
    
    feonumm5n2_t res = feonumm5n2_init();

    
    res = feonumm5n2_createEmpty( arr->nip);

    feoarrm5n2_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_det_to(feoarrm5n2_t* arr, feonumm5n2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm5n2_dimCheck_F_squareness( arr, arr);
    feoarrm5n2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm5n2_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_invert(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    // Should it copy offsets too?
    res = feoarrm5n2_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n2_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_invert_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm5n2_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm5n2_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n2_t feoarrm5n2_transpose(feoarrm5n2_t* arr){

    feoarrm5n2_t res = feoarrm5n2_init();

    // Should it copy offsets?
    res = feoarrm5n2_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm5n2_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n2_transpose_to(feoarrm5n2_t* arr, feoarrm5n2_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm5n2_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm5n2_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

