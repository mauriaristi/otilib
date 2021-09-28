
// void feoarrm20n1_dimCheck_FF_elementwise(feoarrm20n1_t* arr1, feoarrm20n1_t* arr2, feoarrm20n1_t* res);
// void feoarrm20n1_dimCheck_OF_elementwise(  oarrm20n1_t* arr1, feoarrm20n1_t* arr2, feoarrm20n1_t* res);
// void feoarrm20n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm20n1_t* arr2, feoarrm20n1_t* res);
// void feoarrm20n1_dimCheck_FF_matmul( feoarrm20n1_t* lhs, feoarrm20n1_t* rhs, feoarrm20n1_t* res);
// void feoarrm20n1_dimCheck_OF_matmul(   oarrm20n1_t* lhs, feoarrm20n1_t* rhs, feoarrm20n1_t* res);
// void feoarrm20n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm20n1_t* rhs, feoarrm20n1_t* res);
// void feoarrm20n1_dimCheck_FO_matmul( feoarrm20n1_t* lhs,   oarrm20n1_t* rhs, feoarrm20n1_t* res);
// void feoarrm20n1_dimCheck_FR_matmul( feoarrm20n1_t* lhs,    darr_t* rhs, feoarrm20n1_t* res);
// void feoarrm20n1_dimCheck_F_squareness( feoarrm20n1_t* arr1, feoarrm20n1_t* res);
// void feoarrm20n1_dimCheck_F_transpose( feoarrm20n1_t* arr1, feoarrm20n1_t* res);

// ****************************************************************************************************
feonumm20n1_t feoarrm20n1_dotproduct_FF(feoarrm20n1_t* lhs, feoarrm20n1_t* rhs){

    feonumm20n1_t res = feonumm20n1_init();

    res = feonumm20n1_createEmpty( rhs->nip);

    feoarrm20n1_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_dotproduct_FF_to(feoarrm20n1_t* lhs, feoarrm20n1_t* rhs, feonumm20n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm20n1_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm20n1_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feoarrm20n1_dotproduct_OF(oarrm20n1_t* lhs, feoarrm20n1_t* rhs){

    feonumm20n1_t res = feonumm20n1_init();

    res = feonumm20n1_createEmpty( rhs->nip);

    feoarrm20n1_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_dotproduct_OF_to( oarrm20n1_t* lhs, feoarrm20n1_t* rhs, feonumm20n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm20n1_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm20n1_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feoarrm20n1_dotproduct_RF( darr_t* lhs, feoarrm20n1_t* rhs){

    feonumm20n1_t res = feonumm20n1_init();

    res = feonumm20n1_createEmpty( rhs->nip);

    feoarrm20n1_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_dotproduct_RF_to( darr_t* lhs, feoarrm20n1_t* rhs, feonumm20n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm20n1_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm20n1_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_matmul_FF(feoarrm20n1_t* lhs, feoarrm20n1_t* rhs){

    feoarrm20n1_t res = feoarrm20n1_init();

    // Check dimensions.
    res = feoarrm20n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm20n1_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_matmul_FF_to(feoarrm20n1_t* lhs, feoarrm20n1_t* rhs, feoarrm20n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm20n1_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm20n1_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_matmul_OF(oarrm20n1_t* lhs, feoarrm20n1_t* rhs){

    feoarrm20n1_t res = feoarrm20n1_init();

    // Check dimensions.
    res = feoarrm20n1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm20n1_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_matmul_OF_to(oarrm20n1_t* lhs, feoarrm20n1_t* rhs, feoarrm20n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm20n1_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm20n1_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_matmul_FO(feoarrm20n1_t* lhs, oarrm20n1_t* rhs){

    feoarrm20n1_t res = feoarrm20n1_init();

    // Check dimensions.
    res = feoarrm20n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm20n1_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_matmul_FO_to(feoarrm20n1_t* lhs, oarrm20n1_t* rhs, feoarrm20n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm20n1_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm20n1_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_matmul_RF(darr_t* lhs, feoarrm20n1_t* rhs){

    feoarrm20n1_t res = feoarrm20n1_init();

    // Check dimensions.
    res = feoarrm20n1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm20n1_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_matmul_RF_to(darr_t* lhs, feoarrm20n1_t* rhs, feoarrm20n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm20n1_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm20n1_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_matmul_FR(feoarrm20n1_t* lhs, darr_t* rhs){

    feoarrm20n1_t res = feoarrm20n1_init();

    // Check dimensions.
    res = feoarrm20n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm20n1_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_matmul_FR_to(feoarrm20n1_t* lhs, darr_t* rhs, feoarrm20n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm20n1_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm20n1_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feoarrm20n1_norm(feoarrm20n1_t* arr){
    
    feonumm20n1_t res = feonumm20n1_init();

    
    res = feonumm20n1_createEmpty( arr->nip);

    feoarrm20n1_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_norm_to(feoarrm20n1_t* arr, feonumm20n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm20n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm20n1_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feoarrm20n1_pnorm(feoarrm20n1_t* arr, coeff_t p){
    
    feonumm20n1_t res = feonumm20n1_init();

    
    res = feonumm20n1_createEmpty( arr->nip);

    feoarrm20n1_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_pnorm_to(feoarrm20n1_t* arr, coeff_t p, feonumm20n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm20n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm20n1_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm20n1_t feoarrm20n1_det(feoarrm20n1_t* arr){
    
    feonumm20n1_t res = feonumm20n1_init();

    
    res = feonumm20n1_createEmpty( arr->nip);

    feoarrm20n1_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_det_to(feoarrm20n1_t* arr, feonumm20n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm20n1_dimCheck_F_squareness( arr, arr);
    feoarrm20n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm20n1_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_invert(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    // Should it copy offsets too?
    res = feoarrm20n1_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm20n1_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_invert_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm20n1_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm20n1_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm20n1_t feoarrm20n1_transpose(feoarrm20n1_t* arr){

    feoarrm20n1_t res = feoarrm20n1_init();

    // Should it copy offsets?
    res = feoarrm20n1_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm20n1_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm20n1_transpose_to(feoarrm20n1_t* arr, feoarrm20n1_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm20n1_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm20n1_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

