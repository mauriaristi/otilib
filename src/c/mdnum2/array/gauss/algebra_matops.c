
// void femdarr2_dimCheck_FF_elementwise(femdarr2_t* arr1, femdarr2_t* arr2, femdarr2_t* res);
// void femdarr2_dimCheck_OF_elementwise(  mdarr2_t* arr1, femdarr2_t* arr2, femdarr2_t* res);
// void femdarr2_dimCheck_RF_elementwise(   darr_t* arr1, femdarr2_t* arr2, femdarr2_t* res);
// void femdarr2_dimCheck_FF_matmul( femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
// void femdarr2_dimCheck_OF_matmul(   mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
// void femdarr2_dimCheck_RF_matmul(    darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
// void femdarr2_dimCheck_FO_matmul( femdarr2_t* lhs,   mdarr2_t* rhs, femdarr2_t* res);
// void femdarr2_dimCheck_FR_matmul( femdarr2_t* lhs,    darr_t* rhs, femdarr2_t* res);
// void femdarr2_dimCheck_F_squareness( femdarr2_t* arr1, femdarr2_t* res);
// void femdarr2_dimCheck_F_transpose( femdarr2_t* arr1, femdarr2_t* res);

// ****************************************************************************************************
femdnum2_t femdarr2_dotproduct_FF(femdarr2_t* lhs, femdarr2_t* rhs){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty( rhs->nip);

    femdarr2_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_dotproduct_FF_to(femdarr2_t* lhs, femdarr2_t* rhs, femdnum2_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr2_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr2_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdarr2_dotproduct_OF(mdarr2_t* lhs, femdarr2_t* rhs){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty( rhs->nip);

    femdarr2_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_dotproduct_OF_to( mdarr2_t* lhs, femdarr2_t* rhs, femdnum2_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr2_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr2_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdarr2_dotproduct_RF( darr_t* lhs, femdarr2_t* rhs){

    femdnum2_t res = femdnum2_init();

    res = femdnum2_createEmpty( rhs->nip);

    femdarr2_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_dotproduct_RF_to( darr_t* lhs, femdarr2_t* rhs, femdnum2_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr2_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr2_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_matmul_FF(femdarr2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res = femdarr2_init();

    // Check dimensions.
    res = femdarr2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr2_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_matmul_FF_to(femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr2_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr2_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_matmul_OF(mdarr2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res = femdarr2_init();

    // Check dimensions.
    res = femdarr2_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_matmul_OF_to(mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr2_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr2_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_matmul_FO(femdarr2_t* lhs, mdarr2_t* rhs){

    femdarr2_t res = femdarr2_init();

    // Check dimensions.
    res = femdarr2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr2_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_matmul_FO_to(femdarr2_t* lhs, mdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr2_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr2_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_matmul_RF(darr_t* lhs, femdarr2_t* rhs){

    femdarr2_t res = femdarr2_init();

    // Check dimensions.
    res = femdarr2_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_matmul_RF_to(darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr2_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr2_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_matmul_FR(femdarr2_t* lhs, darr_t* rhs){

    femdarr2_t res = femdarr2_init();

    // Check dimensions.
    res = femdarr2_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr2_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_matmul_FR_to(femdarr2_t* lhs, darr_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr2_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr2_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdarr2_norm(femdarr2_t* arr){
    
    femdnum2_t res = femdnum2_init();

    
    res = femdnum2_createEmpty( arr->nip);

    femdarr2_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_norm_to(femdarr2_t* arr, femdnum2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr2_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdarr2_pnorm(femdarr2_t* arr, coeff_t p){
    
    femdnum2_t res = femdnum2_init();

    
    res = femdnum2_createEmpty( arr->nip);

    femdarr2_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_pnorm_to(femdarr2_t* arr, coeff_t p, femdnum2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr2_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum2_t femdarr2_det(femdarr2_t* arr){
    
    femdnum2_t res = femdnum2_init();

    
    res = femdnum2_createEmpty( arr->nip);

    femdarr2_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_det_to(femdarr2_t* arr, femdnum2_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr2_dimCheck_F_squareness( arr, arr);
    femdarr2_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        mdarr2_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_invert(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    // Should it copy offsets too?
    res = femdarr2_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr2_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_invert_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    femdarr2_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr2_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_transpose(femdarr2_t* arr){

    femdarr2_t res = femdarr2_init();

    // Should it copy offsets?
    res = femdarr2_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    femdarr2_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_transpose_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    // Check dimensions.
    femdarr2_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr2_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

