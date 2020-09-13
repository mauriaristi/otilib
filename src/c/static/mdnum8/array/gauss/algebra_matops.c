
// void femdarr8_dimCheck_FF_elementwise(femdarr8_t* arr1, femdarr8_t* arr2, femdarr8_t* res);
// void femdarr8_dimCheck_OF_elementwise(  mdarr8_t* arr1, femdarr8_t* arr2, femdarr8_t* res);
// void femdarr8_dimCheck_RF_elementwise(   darr_t* arr1, femdarr8_t* arr2, femdarr8_t* res);
// void femdarr8_dimCheck_FF_matmul( femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
// void femdarr8_dimCheck_OF_matmul(   mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
// void femdarr8_dimCheck_RF_matmul(    darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
// void femdarr8_dimCheck_FO_matmul( femdarr8_t* lhs,   mdarr8_t* rhs, femdarr8_t* res);
// void femdarr8_dimCheck_FR_matmul( femdarr8_t* lhs,    darr_t* rhs, femdarr8_t* res);
// void femdarr8_dimCheck_F_squareness( femdarr8_t* arr1, femdarr8_t* res);
// void femdarr8_dimCheck_F_transpose( femdarr8_t* arr1, femdarr8_t* res);

// ****************************************************************************************************
femdnum8_t femdarr8_dotproduct_FF(femdarr8_t* lhs, femdarr8_t* rhs){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty( rhs->nip);

    femdarr8_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_dotproduct_FF_to(femdarr8_t* lhs, femdarr8_t* rhs, femdnum8_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr8_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr8_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdarr8_dotproduct_OF(mdarr8_t* lhs, femdarr8_t* rhs){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty( rhs->nip);

    femdarr8_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_dotproduct_OF_to( mdarr8_t* lhs, femdarr8_t* rhs, femdnum8_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr8_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr8_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdarr8_dotproduct_RF( darr_t* lhs, femdarr8_t* rhs){

    femdnum8_t res = femdnum8_init();

    res = femdnum8_createEmpty( rhs->nip);

    femdarr8_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_dotproduct_RF_to( darr_t* lhs, femdarr8_t* rhs, femdnum8_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr8_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr8_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_matmul_FF(femdarr8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res = femdarr8_init();

    // Check dimensions.
    res = femdarr8_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr8_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_matmul_FF_to(femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr8_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr8_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_matmul_OF(mdarr8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res = femdarr8_init();

    // Check dimensions.
    res = femdarr8_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_matmul_OF_to(mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr8_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr8_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_matmul_FO(femdarr8_t* lhs, mdarr8_t* rhs){

    femdarr8_t res = femdarr8_init();

    // Check dimensions.
    res = femdarr8_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr8_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_matmul_FO_to(femdarr8_t* lhs, mdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr8_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr8_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_matmul_RF(darr_t* lhs, femdarr8_t* rhs){

    femdarr8_t res = femdarr8_init();

    // Check dimensions.
    res = femdarr8_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_matmul_RF_to(darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr8_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr8_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_matmul_FR(femdarr8_t* lhs, darr_t* rhs){

    femdarr8_t res = femdarr8_init();

    // Check dimensions.
    res = femdarr8_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr8_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_matmul_FR_to(femdarr8_t* lhs, darr_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr8_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr8_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdarr8_norm(femdarr8_t* arr){
    
    femdnum8_t res = femdnum8_init();

    
    res = femdnum8_createEmpty( arr->nip);

    femdarr8_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_norm_to(femdarr8_t* arr, femdnum8_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr8_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr8_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdarr8_pnorm(femdarr8_t* arr, coeff_t p){
    
    femdnum8_t res = femdnum8_init();

    
    res = femdnum8_createEmpty( arr->nip);

    femdarr8_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_pnorm_to(femdarr8_t* arr, coeff_t p, femdnum8_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr8_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr8_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum8_t femdarr8_det(femdarr8_t* arr){
    
    femdnum8_t res = femdnum8_init();

    
    res = femdnum8_createEmpty( arr->nip);

    femdarr8_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_det_to(femdarr8_t* arr, femdnum8_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr8_dimCheck_F_squareness( arr, arr);
    femdarr8_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        mdarr8_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_invert(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    // Should it copy offsets too?
    res = femdarr8_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr8_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_invert_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    femdarr8_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr8_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_transpose(femdarr8_t* arr){

    femdarr8_t res = femdarr8_init();

    // Should it copy offsets?
    res = femdarr8_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    femdarr8_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_transpose_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    // Check dimensions.
    femdarr8_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr8_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

