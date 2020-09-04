
// void feoarrm9n1_dimCheck_FF_elementwise(feoarrm9n1_t* arr1, feoarrm9n1_t* arr2, feoarrm9n1_t* res);
// void feoarrm9n1_dimCheck_OF_elementwise(  oarrm9n1_t* arr1, feoarrm9n1_t* arr2, feoarrm9n1_t* res);
// void feoarrm9n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm9n1_t* arr2, feoarrm9n1_t* res);
// void feoarrm9n1_dimCheck_FF_matmul( feoarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
// void feoarrm9n1_dimCheck_OF_matmul(   oarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
// void feoarrm9n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
// void feoarrm9n1_dimCheck_FO_matmul( feoarrm9n1_t* lhs,   oarrm9n1_t* rhs, feoarrm9n1_t* res);
// void feoarrm9n1_dimCheck_FR_matmul( feoarrm9n1_t* lhs,    darr_t* rhs, feoarrm9n1_t* res);
// void feoarrm9n1_dimCheck_F_squareness( feoarrm9n1_t* arr1, feoarrm9n1_t* res);
// void feoarrm9n1_dimCheck_F_transpose( feoarrm9n1_t* arr1, feoarrm9n1_t* res);

// ****************************************************************************************************
feonumm9n1_t feoarrm9n1_dotproduct_FF(feoarrm9n1_t* lhs, feoarrm9n1_t* rhs){

    feonumm9n1_t res = feonumm9n1_init();

    res = feonumm9n1_createEmpty( rhs->nip);

    feoarrm9n1_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_dotproduct_FF_to(feoarrm9n1_t* lhs, feoarrm9n1_t* rhs, feonumm9n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm9n1_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm9n1_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm9n1_t feoarrm9n1_dotproduct_OF(oarrm9n1_t* lhs, feoarrm9n1_t* rhs){

    feonumm9n1_t res = feonumm9n1_init();

    res = feonumm9n1_createEmpty( rhs->nip);

    feoarrm9n1_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_dotproduct_OF_to( oarrm9n1_t* lhs, feoarrm9n1_t* rhs, feonumm9n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm9n1_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm9n1_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm9n1_t feoarrm9n1_dotproduct_RF( darr_t* lhs, feoarrm9n1_t* rhs){

    feonumm9n1_t res = feonumm9n1_init();

    res = feonumm9n1_createEmpty( rhs->nip);

    feoarrm9n1_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_dotproduct_RF_to( darr_t* lhs, feoarrm9n1_t* rhs, feonumm9n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm9n1_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm9n1_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_matmul_FF(feoarrm9n1_t* lhs, feoarrm9n1_t* rhs){

    feoarrm9n1_t res = feoarrm9n1_init();

    // Check dimensions.
    res = feoarrm9n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm9n1_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_matmul_FF_to(feoarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm9n1_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm9n1_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_matmul_OF(oarrm9n1_t* lhs, feoarrm9n1_t* rhs){

    feoarrm9n1_t res = feoarrm9n1_init();

    // Check dimensions.
    res = feoarrm9n1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n1_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_matmul_OF_to(oarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm9n1_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm9n1_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_matmul_FO(feoarrm9n1_t* lhs, oarrm9n1_t* rhs){

    feoarrm9n1_t res = feoarrm9n1_init();

    // Check dimensions.
    res = feoarrm9n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm9n1_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_matmul_FO_to(feoarrm9n1_t* lhs, oarrm9n1_t* rhs, feoarrm9n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm9n1_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm9n1_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_matmul_RF(darr_t* lhs, feoarrm9n1_t* rhs){

    feoarrm9n1_t res = feoarrm9n1_init();

    // Check dimensions.
    res = feoarrm9n1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n1_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_matmul_RF_to(darr_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm9n1_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm9n1_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_matmul_FR(feoarrm9n1_t* lhs, darr_t* rhs){

    feoarrm9n1_t res = feoarrm9n1_init();

    // Check dimensions.
    res = feoarrm9n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm9n1_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_matmul_FR_to(feoarrm9n1_t* lhs, darr_t* rhs, feoarrm9n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm9n1_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm9n1_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm9n1_t feoarrm9n1_norm(feoarrm9n1_t* arr){
    
    feonumm9n1_t res = feonumm9n1_init();

    
    res = feonumm9n1_createEmpty( arr->nip);

    feoarrm9n1_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_norm_to(feoarrm9n1_t* arr, feonumm9n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm9n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm9n1_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm9n1_t feoarrm9n1_pnorm(feoarrm9n1_t* arr, coeff_t p){
    
    feonumm9n1_t res = feonumm9n1_init();

    
    res = feonumm9n1_createEmpty( arr->nip);

    feoarrm9n1_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_pnorm_to(feoarrm9n1_t* arr, coeff_t p, feonumm9n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm9n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm9n1_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm9n1_t feoarrm9n1_det(feoarrm9n1_t* arr){
    
    feonumm9n1_t res = feonumm9n1_init();

    
    res = feonumm9n1_createEmpty( arr->nip);

    feoarrm9n1_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_det_to(feoarrm9n1_t* arr, feonumm9n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm9n1_dimCheck_F_squareness( arr, arr);
    feoarrm9n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm9n1_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_invert(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    // Should it copy offsets too?
    res = feoarrm9n1_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm9n1_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_invert_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm9n1_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm9n1_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n1_t feoarrm9n1_transpose(feoarrm9n1_t* arr){

    feoarrm9n1_t res = feoarrm9n1_init();

    // Should it copy offsets?
    res = feoarrm9n1_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm9n1_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n1_transpose_to(feoarrm9n1_t* arr, feoarrm9n1_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm9n1_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm9n1_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

