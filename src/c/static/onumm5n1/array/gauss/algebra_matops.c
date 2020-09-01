
// void feoarrm5n1_dimCheck_FF_elementwise(feoarrm5n1_t* arr1, feoarrm5n1_t* arr2, feoarrm5n1_t* res);
// void feoarrm5n1_dimCheck_OF_elementwise(  oarrm5n1_t* arr1, feoarrm5n1_t* arr2, feoarrm5n1_t* res);
// void feoarrm5n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm5n1_t* arr2, feoarrm5n1_t* res);
// void feoarrm5n1_dimCheck_FF_matmul( feoarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
// void feoarrm5n1_dimCheck_OF_matmul(   oarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
// void feoarrm5n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
// void feoarrm5n1_dimCheck_FO_matmul( feoarrm5n1_t* lhs,   oarrm5n1_t* rhs, feoarrm5n1_t* res);
// void feoarrm5n1_dimCheck_FR_matmul( feoarrm5n1_t* lhs,    darr_t* rhs, feoarrm5n1_t* res);
// void feoarrm5n1_dimCheck_F_squareness( feoarrm5n1_t* arr1, feoarrm5n1_t* res);
// void feoarrm5n1_dimCheck_F_transpose( feoarrm5n1_t* arr1, feoarrm5n1_t* res);

// ****************************************************************************************************
feonumm5n1_t feoarrm5n1_dotproduct_FF(feoarrm5n1_t* lhs, feoarrm5n1_t* rhs){

    feonumm5n1_t res = feonumm5n1_init();

    res = feonumm5n1_createEmpty( rhs->nip);

    feoarrm5n1_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_dotproduct_FF_to(feoarrm5n1_t* lhs, feoarrm5n1_t* rhs, feonumm5n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n1_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n1_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n1_t feoarrm5n1_dotproduct_OF(oarrm5n1_t* lhs, feoarrm5n1_t* rhs){

    feonumm5n1_t res = feonumm5n1_init();

    res = feonumm5n1_createEmpty( rhs->nip);

    feoarrm5n1_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_dotproduct_OF_to( oarrm5n1_t* lhs, feoarrm5n1_t* rhs, feonumm5n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n1_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm5n1_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n1_t feoarrm5n1_dotproduct_RF( darr_t* lhs, feoarrm5n1_t* rhs){

    feonumm5n1_t res = feonumm5n1_init();

    res = feonumm5n1_createEmpty( rhs->nip);

    feoarrm5n1_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_dotproduct_RF_to( darr_t* lhs, feoarrm5n1_t* rhs, feonumm5n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n1_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm5n1_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_matmul_FF(feoarrm5n1_t* lhs, feoarrm5n1_t* rhs){

    feoarrm5n1_t res = feoarrm5n1_init();

    // Check dimensions.
    res = feoarrm5n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm5n1_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_matmul_FF_to(feoarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n1_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n1_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_matmul_OF(oarrm5n1_t* lhs, feoarrm5n1_t* rhs){

    feoarrm5n1_t res = feoarrm5n1_init();

    // Check dimensions.
    res = feoarrm5n1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n1_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_matmul_OF_to(oarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n1_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n1_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_matmul_FO(feoarrm5n1_t* lhs, oarrm5n1_t* rhs){

    feoarrm5n1_t res = feoarrm5n1_init();

    // Check dimensions.
    res = feoarrm5n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm5n1_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_matmul_FO_to(feoarrm5n1_t* lhs, oarrm5n1_t* rhs, feoarrm5n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n1_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n1_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_matmul_RF(darr_t* lhs, feoarrm5n1_t* rhs){

    feoarrm5n1_t res = feoarrm5n1_init();

    // Check dimensions.
    res = feoarrm5n1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n1_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_matmul_RF_to(darr_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n1_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n1_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_matmul_FR(feoarrm5n1_t* lhs, darr_t* rhs){

    feoarrm5n1_t res = feoarrm5n1_init();

    // Check dimensions.
    res = feoarrm5n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm5n1_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_matmul_FR_to(feoarrm5n1_t* lhs, darr_t* rhs, feoarrm5n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm5n1_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm5n1_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n1_t feoarrm5n1_norm(feoarrm5n1_t* arr){
    
    feonumm5n1_t res = feonumm5n1_init();

    
    res = feonumm5n1_createEmpty( arr->nip);

    feoarrm5n1_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_norm_to(feoarrm5n1_t* arr, feonumm5n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm5n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm5n1_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n1_t feoarrm5n1_pnorm(feoarrm5n1_t* arr, coeff_t p){
    
    feonumm5n1_t res = feonumm5n1_init();

    
    res = feonumm5n1_createEmpty( arr->nip);

    feoarrm5n1_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_pnorm_to(feoarrm5n1_t* arr, coeff_t p, feonumm5n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm5n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm5n1_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm5n1_t feoarrm5n1_det(feoarrm5n1_t* arr){
    
    feonumm5n1_t res = feonumm5n1_init();

    
    res = feonumm5n1_createEmpty( arr->nip);

    feoarrm5n1_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_det_to(feoarrm5n1_t* arr, feonumm5n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm5n1_dimCheck_F_squareness( arr, arr);
    feoarrm5n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm5n1_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_invert(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    // Should it copy offsets too?
    res = feoarrm5n1_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm5n1_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_invert_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm5n1_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm5n1_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n1_t feoarrm5n1_transpose(feoarrm5n1_t* arr){

    feoarrm5n1_t res = feoarrm5n1_init();

    // Should it copy offsets?
    res = feoarrm5n1_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm5n1_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n1_transpose_to(feoarrm5n1_t* arr, feoarrm5n1_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm5n1_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm5n1_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

