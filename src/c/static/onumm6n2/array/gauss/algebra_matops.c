
// void feoarrm6n2_dimCheck_FF_elementwise(feoarrm6n2_t* arr1, feoarrm6n2_t* arr2, feoarrm6n2_t* res);
// void feoarrm6n2_dimCheck_OF_elementwise(  oarrm6n2_t* arr1, feoarrm6n2_t* arr2, feoarrm6n2_t* res);
// void feoarrm6n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm6n2_t* arr2, feoarrm6n2_t* res);
// void feoarrm6n2_dimCheck_FF_matmul( feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
// void feoarrm6n2_dimCheck_OF_matmul(   oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
// void feoarrm6n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
// void feoarrm6n2_dimCheck_FO_matmul( feoarrm6n2_t* lhs,   oarrm6n2_t* rhs, feoarrm6n2_t* res);
// void feoarrm6n2_dimCheck_FR_matmul( feoarrm6n2_t* lhs,    darr_t* rhs, feoarrm6n2_t* res);
// void feoarrm6n2_dimCheck_F_squareness( feoarrm6n2_t* arr1, feoarrm6n2_t* res);
// void feoarrm6n2_dimCheck_F_transpose( feoarrm6n2_t* arr1, feoarrm6n2_t* res);

// ****************************************************************************************************
feonumm6n2_t feoarrm6n2_dotproduct_FF(feoarrm6n2_t* lhs, feoarrm6n2_t* rhs){

    feonumm6n2_t res = feonumm6n2_init();

    res = feonumm6n2_createEmpty( rhs->nip);

    feoarrm6n2_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_dotproduct_FF_to(feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feonumm6n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm6n2_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm6n2_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm6n2_t feoarrm6n2_dotproduct_OF(oarrm6n2_t* lhs, feoarrm6n2_t* rhs){

    feonumm6n2_t res = feonumm6n2_init();

    res = feonumm6n2_createEmpty( rhs->nip);

    feoarrm6n2_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_dotproduct_OF_to( oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feonumm6n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm6n2_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm6n2_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm6n2_t feoarrm6n2_dotproduct_RF( darr_t* lhs, feoarrm6n2_t* rhs){

    feonumm6n2_t res = feonumm6n2_init();

    res = feonumm6n2_createEmpty( rhs->nip);

    feoarrm6n2_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_dotproduct_RF_to( darr_t* lhs, feoarrm6n2_t* rhs, feonumm6n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm6n2_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm6n2_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_matmul_FF(feoarrm6n2_t* lhs, feoarrm6n2_t* rhs){

    feoarrm6n2_t res = feoarrm6n2_init();

    // Check dimensions.
    res = feoarrm6n2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm6n2_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_matmul_FF_to(feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm6n2_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm6n2_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_matmul_OF(oarrm6n2_t* lhs, feoarrm6n2_t* rhs){

    feoarrm6n2_t res = feoarrm6n2_init();

    // Check dimensions.
    res = feoarrm6n2_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm6n2_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_matmul_OF_to(oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm6n2_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm6n2_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_matmul_FO(feoarrm6n2_t* lhs, oarrm6n2_t* rhs){

    feoarrm6n2_t res = feoarrm6n2_init();

    // Check dimensions.
    res = feoarrm6n2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm6n2_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_matmul_FO_to(feoarrm6n2_t* lhs, oarrm6n2_t* rhs, feoarrm6n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm6n2_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm6n2_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_matmul_RF(darr_t* lhs, feoarrm6n2_t* rhs){

    feoarrm6n2_t res = feoarrm6n2_init();

    // Check dimensions.
    res = feoarrm6n2_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm6n2_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_matmul_RF_to(darr_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm6n2_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm6n2_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_matmul_FR(feoarrm6n2_t* lhs, darr_t* rhs){

    feoarrm6n2_t res = feoarrm6n2_init();

    // Check dimensions.
    res = feoarrm6n2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm6n2_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_matmul_FR_to(feoarrm6n2_t* lhs, darr_t* rhs, feoarrm6n2_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm6n2_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm6n2_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm6n2_t feoarrm6n2_norm(feoarrm6n2_t* arr){
    
    feonumm6n2_t res = feonumm6n2_init();

    
    res = feonumm6n2_createEmpty( arr->nip);

    feoarrm6n2_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_norm_to(feoarrm6n2_t* arr, feonumm6n2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm6n2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm6n2_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm6n2_t feoarrm6n2_pnorm(feoarrm6n2_t* arr, coeff_t p){
    
    feonumm6n2_t res = feonumm6n2_init();

    
    res = feonumm6n2_createEmpty( arr->nip);

    feoarrm6n2_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_pnorm_to(feoarrm6n2_t* arr, coeff_t p, feonumm6n2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm6n2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm6n2_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm6n2_t feoarrm6n2_det(feoarrm6n2_t* arr){
    
    feonumm6n2_t res = feonumm6n2_init();

    
    res = feonumm6n2_createEmpty( arr->nip);

    feoarrm6n2_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_det_to(feoarrm6n2_t* arr, feonumm6n2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm6n2_dimCheck_F_squareness( arr, arr);
    feoarrm6n2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm6n2_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_invert(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    // Should it copy offsets too?
    res = feoarrm6n2_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm6n2_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_invert_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm6n2_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm6n2_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm6n2_t feoarrm6n2_transpose(feoarrm6n2_t* arr){

    feoarrm6n2_t res = feoarrm6n2_init();

    // Should it copy offsets?
    res = feoarrm6n2_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm6n2_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm6n2_transpose_to(feoarrm6n2_t* arr, feoarrm6n2_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm6n2_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm6n2_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

