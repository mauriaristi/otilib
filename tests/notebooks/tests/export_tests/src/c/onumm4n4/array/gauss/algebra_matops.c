
// void feoarrm4n4_dimCheck_FF_elementwise(feoarrm4n4_t* arr1, feoarrm4n4_t* arr2, feoarrm4n4_t* res);
// void feoarrm4n4_dimCheck_OF_elementwise(  oarrm4n4_t* arr1, feoarrm4n4_t* arr2, feoarrm4n4_t* res);
// void feoarrm4n4_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm4n4_t* arr2, feoarrm4n4_t* res);
// void feoarrm4n4_dimCheck_FF_matmul( feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
// void feoarrm4n4_dimCheck_OF_matmul(   oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
// void feoarrm4n4_dimCheck_RF_matmul(    darr_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
// void feoarrm4n4_dimCheck_FO_matmul( feoarrm4n4_t* lhs,   oarrm4n4_t* rhs, feoarrm4n4_t* res);
// void feoarrm4n4_dimCheck_FR_matmul( feoarrm4n4_t* lhs,    darr_t* rhs, feoarrm4n4_t* res);
// void feoarrm4n4_dimCheck_F_squareness( feoarrm4n4_t* arr1, feoarrm4n4_t* res);
// void feoarrm4n4_dimCheck_F_transpose( feoarrm4n4_t* arr1, feoarrm4n4_t* res);

// ****************************************************************************************************
feonumm4n4_t feoarrm4n4_dotproduct_FF(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feonumm4n4_t res = feonumm4n4_init();

    res = feonumm4n4_createEmpty( rhs->nip);

    feoarrm4n4_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_dotproduct_FF_to(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feonumm4n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm4n4_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm4n4_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm4n4_t feoarrm4n4_dotproduct_OF(oarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feonumm4n4_t res = feonumm4n4_init();

    res = feonumm4n4_createEmpty( rhs->nip);

    feoarrm4n4_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_dotproduct_OF_to( oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feonumm4n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm4n4_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm4n4_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm4n4_t feoarrm4n4_dotproduct_RF( darr_t* lhs, feoarrm4n4_t* rhs){

    feonumm4n4_t res = feonumm4n4_init();

    res = feonumm4n4_createEmpty( rhs->nip);

    feoarrm4n4_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_dotproduct_RF_to( darr_t* lhs, feoarrm4n4_t* rhs, feonumm4n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm4n4_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        oarrm4n4_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_matmul_FF(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res = feoarrm4n4_init();

    // Check dimensions.
    res = feoarrm4n4_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm4n4_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_matmul_FF_to(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm4n4_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm4n4_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_matmul_OF(oarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res = feoarrm4n4_init();

    // Check dimensions.
    res = feoarrm4n4_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_matmul_OF_to(oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm4n4_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm4n4_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_matmul_FO(feoarrm4n4_t* lhs, oarrm4n4_t* rhs){

    feoarrm4n4_t res = feoarrm4n4_init();

    // Check dimensions.
    res = feoarrm4n4_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm4n4_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_matmul_FO_to(feoarrm4n4_t* lhs, oarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm4n4_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm4n4_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_matmul_RF(darr_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res = feoarrm4n4_init();

    // Check dimensions.
    res = feoarrm4n4_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_matmul_RF_to(darr_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm4n4_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm4n4_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_matmul_FR(feoarrm4n4_t* lhs, darr_t* rhs){

    feoarrm4n4_t res = feoarrm4n4_init();

    // Check dimensions.
    res = feoarrm4n4_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    feoarrm4n4_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_matmul_FR_to(feoarrm4n4_t* lhs, darr_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check Dimensions
    feoarrm4n4_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        oarrm4n4_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm4n4_t feoarrm4n4_norm(feoarrm4n4_t* arr){
    
    feonumm4n4_t res = feonumm4n4_init();

    
    res = feonumm4n4_createEmpty( arr->nip);

    feoarrm4n4_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_norm_to(feoarrm4n4_t* arr, feonumm4n4_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm4n4_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm4n4_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm4n4_t feoarrm4n4_pnorm(feoarrm4n4_t* arr, coeff_t p){
    
    feonumm4n4_t res = feonumm4n4_init();

    
    res = feonumm4n4_createEmpty( arr->nip);

    feoarrm4n4_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_pnorm_to(feoarrm4n4_t* arr, coeff_t p, feonumm4n4_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm4n4_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        oarrm4n4_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feonumm4n4_t feoarrm4n4_det(feoarrm4n4_t* arr){
    
    feonumm4n4_t res = feonumm4n4_init();

    
    res = feonumm4n4_createEmpty( arr->nip);

    feoarrm4n4_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_det_to(feoarrm4n4_t* arr, feonumm4n4_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    feoarrm4n4_dimCheck_F_squareness( arr, arr);
    feoarrm4n4_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        oarrm4n4_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_invert(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    // Should it copy offsets too?
    res = feoarrm4n4_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    feoarrm4n4_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_invert_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    feoarrm4n4_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm4n4_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_transpose(feoarrm4n4_t* arr){

    feoarrm4n4_t res = feoarrm4n4_init();

    // Should it copy offsets?
    res = feoarrm4n4_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    feoarrm4n4_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_transpose_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    // Check dimensions.
    feoarrm4n4_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        oarrm4n4_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

