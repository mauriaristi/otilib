
// void feoarrm2n1_dimCheck_FF_elementwise(feoarrm2n1_t* arr1, feoarrm2n1_t* arr2, feoarrm2n1_t* res);
// void feoarrm2n1_dimCheck_OF_elementwise(  oarrm2n1_t* arr1, feoarrm2n1_t* arr2, feoarrm2n1_t* res);
// void feoarrm2n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm2n1_t* arr2, feoarrm2n1_t* res);
// void feoarrm2n1_dimCheck_FF_matmul( feoarrm2n1_t* lhs, feoarrm2n1_t* rhs, feoarrm2n1_t* res);
// void feoarrm2n1_dimCheck_OF_matmul(   oarrm2n1_t* lhs, feoarrm2n1_t* rhs, feoarrm2n1_t* res);
// void feoarrm2n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm2n1_t* rhs, feoarrm2n1_t* res);
// void feoarrm2n1_dimCheck_FO_matmul( feoarrm2n1_t* lhs,   oarrm2n1_t* rhs, feoarrm2n1_t* res);
// void feoarrm2n1_dimCheck_FR_matmul( feoarrm2n1_t* lhs,    darr_t* rhs, feoarrm2n1_t* res);
// void feoarrm2n1_dimCheck_F_squareness( feoarrm2n1_t* arr1, feoarrm2n1_t* res);
// void feoarrm2n1_dimCheck_F_transpose( feoarrm2n1_t* arr1, feoarrm2n1_t* res);

// ****************************************************************************************************
feonumm2n1_t feoarrm2n1_dotproduct_FF(feoarrm2n1_t* lhs, feoarrm2n1_t* rhs){

    feonumm2n1_t res = feonumm2n1_init();

    res = feonumm2n1_createEmpty( rhs->nip);

    feoarrm2n1_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_dotproduct_FF_to(feoarrm2n1_t* lhs, feoarrm2n1_t* rhs, feonumm2n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n1_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n1_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n1_t feoarrm2n1_dotproduct_OF(oarrm2n1_t* lhs, feoarrm2n1_t* rhs){

    feonumm2n1_t res = feonumm2n1_init();

    res = feonumm2n1_createEmpty( rhs->nip);

    feoarrm2n1_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_dotproduct_OF_to( oarrm2n1_t* lhs, feoarrm2n1_t* rhs, feonumm2n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n1_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm2n1_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n1_t feoarrm2n1_dotproduct_RF( darr_t* lhs, feoarrm2n1_t* rhs){

    feonumm2n1_t res = feonumm2n1_init();

    res = feonumm2n1_createEmpty( rhs->nip);

    feoarrm2n1_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_dotproduct_RF_to( darr_t* lhs, feoarrm2n1_t* rhs, feonumm2n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n1_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm2n1_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_matmul_FF(feoarrm2n1_t* lhs, feoarrm2n1_t* rhs){

    feoarrm2n1_t res = feoarrm2n1_init();

    // Check dimensions.
    res = feoarrm2n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm2n1_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_matmul_FF_to(feoarrm2n1_t* lhs, feoarrm2n1_t* rhs, feoarrm2n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n1_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n1_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_matmul_OF(oarrm2n1_t* lhs, feoarrm2n1_t* rhs){

    feoarrm2n1_t res = feoarrm2n1_init();

    // Check dimensions.
    res = feoarrm2n1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n1_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_matmul_OF_to(oarrm2n1_t* lhs, feoarrm2n1_t* rhs, feoarrm2n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n1_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n1_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_matmul_FO(feoarrm2n1_t* lhs, oarrm2n1_t* rhs){

    feoarrm2n1_t res = feoarrm2n1_init();

    // Check dimensions.
    res = feoarrm2n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm2n1_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_matmul_FO_to(feoarrm2n1_t* lhs, oarrm2n1_t* rhs, feoarrm2n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n1_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n1_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_matmul_RF(darr_t* lhs, feoarrm2n1_t* rhs){

    feoarrm2n1_t res = feoarrm2n1_init();

    // Check dimensions.
    res = feoarrm2n1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n1_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_matmul_RF_to(darr_t* lhs, feoarrm2n1_t* rhs, feoarrm2n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n1_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n1_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_matmul_FR(feoarrm2n1_t* lhs, darr_t* rhs){

    feoarrm2n1_t res = feoarrm2n1_init();

    // Check dimensions.
    res = feoarrm2n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm2n1_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_matmul_FR_to(feoarrm2n1_t* lhs, darr_t* rhs, feoarrm2n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm2n1_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm2n1_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n1_t feoarrm2n1_norm(feoarrm2n1_t* arr){
    
    feonumm2n1_t res = feonumm2n1_init();

    
    res = feonumm2n1_createEmpty( arr->nip);

    feoarrm2n1_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_norm_to(feoarrm2n1_t* arr, feonumm2n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm2n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm2n1_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n1_t feoarrm2n1_pnorm(feoarrm2n1_t* arr, coeff_t p){
    
    feonumm2n1_t res = feonumm2n1_init();

    
    res = feonumm2n1_createEmpty( arr->nip);

    feoarrm2n1_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_pnorm_to(feoarrm2n1_t* arr, coeff_t p, feonumm2n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm2n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm2n1_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm2n1_t feoarrm2n1_det(feoarrm2n1_t* arr){
    
    feonumm2n1_t res = feonumm2n1_init();

    
    res = feonumm2n1_createEmpty( arr->nip);

    feoarrm2n1_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_det_to(feoarrm2n1_t* arr, feonumm2n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm2n1_dimCheck_F_squareness( arr, arr);
    feoarrm2n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm2n1_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_invert(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    // Should it copy offsets too?
    res = feoarrm2n1_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm2n1_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_invert_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm2n1_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm2n1_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n1_t feoarrm2n1_transpose(feoarrm2n1_t* arr){

    feoarrm2n1_t res = feoarrm2n1_init();

    // Should it copy offsets?
    res = feoarrm2n1_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm2n1_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n1_transpose_to(feoarrm2n1_t* arr, feoarrm2n1_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm2n1_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm2n1_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

