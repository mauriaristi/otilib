
// void feoarrm8n1_dimCheck_FF_elementwise(feoarrm8n1_t* arr1, feoarrm8n1_t* arr2, feoarrm8n1_t* res);
// void feoarrm8n1_dimCheck_OF_elementwise(  oarrm8n1_t* arr1, feoarrm8n1_t* arr2, feoarrm8n1_t* res);
// void feoarrm8n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm8n1_t* arr2, feoarrm8n1_t* res);
// void feoarrm8n1_dimCheck_FF_matmul( feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
// void feoarrm8n1_dimCheck_OF_matmul(   oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
// void feoarrm8n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
// void feoarrm8n1_dimCheck_FO_matmul( feoarrm8n1_t* lhs,   oarrm8n1_t* rhs, feoarrm8n1_t* res);
// void feoarrm8n1_dimCheck_FR_matmul( feoarrm8n1_t* lhs,    darr_t* rhs, feoarrm8n1_t* res);
// void feoarrm8n1_dimCheck_F_squareness( feoarrm8n1_t* arr1, feoarrm8n1_t* res);
// void feoarrm8n1_dimCheck_F_transpose( feoarrm8n1_t* arr1, feoarrm8n1_t* res);

// ****************************************************************************************************
feonumm8n1_t feoarrm8n1_dotproduct_FF(feoarrm8n1_t* lhs, feoarrm8n1_t* rhs){

    feonumm8n1_t res = feonumm8n1_init();

    res = feonumm8n1_createEmpty( rhs->nip);

    feoarrm8n1_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_dotproduct_FF_to(feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feonumm8n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm8n1_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm8n1_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n1_t feoarrm8n1_dotproduct_OF(oarrm8n1_t* lhs, feoarrm8n1_t* rhs){

    feonumm8n1_t res = feonumm8n1_init();

    res = feonumm8n1_createEmpty( rhs->nip);

    feoarrm8n1_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_dotproduct_OF_to( oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feonumm8n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm8n1_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm8n1_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n1_t feoarrm8n1_dotproduct_RF( darr_t* lhs, feoarrm8n1_t* rhs){

    feonumm8n1_t res = feonumm8n1_init();

    res = feonumm8n1_createEmpty( rhs->nip);

    feoarrm8n1_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_dotproduct_RF_to( darr_t* lhs, feoarrm8n1_t* rhs, feonumm8n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm8n1_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm8n1_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_matmul_FF(feoarrm8n1_t* lhs, feoarrm8n1_t* rhs){

    feoarrm8n1_t res = feoarrm8n1_init();

    // Check dimensions.
    res = feoarrm8n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm8n1_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_matmul_FF_to(feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm8n1_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm8n1_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_matmul_OF(oarrm8n1_t* lhs, feoarrm8n1_t* rhs){

    feoarrm8n1_t res = feoarrm8n1_init();

    // Check dimensions.
    res = feoarrm8n1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm8n1_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_matmul_OF_to(oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm8n1_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm8n1_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_matmul_FO(feoarrm8n1_t* lhs, oarrm8n1_t* rhs){

    feoarrm8n1_t res = feoarrm8n1_init();

    // Check dimensions.
    res = feoarrm8n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm8n1_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_matmul_FO_to(feoarrm8n1_t* lhs, oarrm8n1_t* rhs, feoarrm8n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm8n1_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm8n1_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_matmul_RF(darr_t* lhs, feoarrm8n1_t* rhs){

    feoarrm8n1_t res = feoarrm8n1_init();

    // Check dimensions.
    res = feoarrm8n1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm8n1_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_matmul_RF_to(darr_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm8n1_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm8n1_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_matmul_FR(feoarrm8n1_t* lhs, darr_t* rhs){

    feoarrm8n1_t res = feoarrm8n1_init();

    // Check dimensions.
    res = feoarrm8n1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm8n1_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_matmul_FR_to(feoarrm8n1_t* lhs, darr_t* rhs, feoarrm8n1_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm8n1_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm8n1_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n1_t feoarrm8n1_norm(feoarrm8n1_t* arr){
    
    feonumm8n1_t res = feonumm8n1_init();

    
    res = feonumm8n1_createEmpty( arr->nip);

    feoarrm8n1_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_norm_to(feoarrm8n1_t* arr, feonumm8n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm8n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm8n1_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n1_t feoarrm8n1_pnorm(feoarrm8n1_t* arr, coeff_t p){
    
    feonumm8n1_t res = feonumm8n1_init();

    
    res = feonumm8n1_createEmpty( arr->nip);

    feoarrm8n1_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_pnorm_to(feoarrm8n1_t* arr, coeff_t p, feonumm8n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm8n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm8n1_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm8n1_t feoarrm8n1_det(feoarrm8n1_t* arr){
    
    feonumm8n1_t res = feonumm8n1_init();

    
    res = feonumm8n1_createEmpty( arr->nip);

    feoarrm8n1_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_det_to(feoarrm8n1_t* arr, feonumm8n1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm8n1_dimCheck_F_squareness( arr, arr);
    feoarrm8n1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm8n1_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_invert(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    // Should it copy offsets too?
    res = feoarrm8n1_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm8n1_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_invert_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm8n1_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm8n1_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm8n1_t feoarrm8n1_transpose(feoarrm8n1_t* arr){

    feoarrm8n1_t res = feoarrm8n1_init();

    // Should it copy offsets?
    res = feoarrm8n1_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm8n1_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n1_transpose_to(feoarrm8n1_t* arr, feoarrm8n1_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm8n1_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm8n1_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

