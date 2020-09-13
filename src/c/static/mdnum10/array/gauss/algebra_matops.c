
// void femdarr10_dimCheck_FF_elementwise(femdarr10_t* arr1, femdarr10_t* arr2, femdarr10_t* res);
// void femdarr10_dimCheck_OF_elementwise(  mdarr10_t* arr1, femdarr10_t* arr2, femdarr10_t* res);
// void femdarr10_dimCheck_RF_elementwise(   darr_t* arr1, femdarr10_t* arr2, femdarr10_t* res);
// void femdarr10_dimCheck_FF_matmul( femdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);
// void femdarr10_dimCheck_OF_matmul(   mdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);
// void femdarr10_dimCheck_RF_matmul(    darr_t* lhs, femdarr10_t* rhs, femdarr10_t* res);
// void femdarr10_dimCheck_FO_matmul( femdarr10_t* lhs,   mdarr10_t* rhs, femdarr10_t* res);
// void femdarr10_dimCheck_FR_matmul( femdarr10_t* lhs,    darr_t* rhs, femdarr10_t* res);
// void femdarr10_dimCheck_F_squareness( femdarr10_t* arr1, femdarr10_t* res);
// void femdarr10_dimCheck_F_transpose( femdarr10_t* arr1, femdarr10_t* res);

// ****************************************************************************************************
femdnum10_t femdarr10_dotproduct_FF(femdarr10_t* lhs, femdarr10_t* rhs){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty( rhs->nip);

    femdarr10_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_dotproduct_FF_to(femdarr10_t* lhs, femdarr10_t* rhs, femdnum10_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr10_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr10_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdarr10_dotproduct_OF(mdarr10_t* lhs, femdarr10_t* rhs){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty( rhs->nip);

    femdarr10_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_dotproduct_OF_to( mdarr10_t* lhs, femdarr10_t* rhs, femdnum10_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr10_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr10_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdarr10_dotproduct_RF( darr_t* lhs, femdarr10_t* rhs){

    femdnum10_t res = femdnum10_init();

    res = femdnum10_createEmpty( rhs->nip);

    femdarr10_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_dotproduct_RF_to( darr_t* lhs, femdarr10_t* rhs, femdnum10_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr10_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr10_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_matmul_FF(femdarr10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res = femdarr10_init();

    // Check dimensions.
    res = femdarr10_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr10_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_matmul_FF_to(femdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr10_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr10_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_matmul_OF(mdarr10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res = femdarr10_init();

    // Check dimensions.
    res = femdarr10_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_matmul_OF_to(mdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr10_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr10_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_matmul_FO(femdarr10_t* lhs, mdarr10_t* rhs){

    femdarr10_t res = femdarr10_init();

    // Check dimensions.
    res = femdarr10_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr10_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_matmul_FO_to(femdarr10_t* lhs, mdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr10_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr10_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_matmul_RF(darr_t* lhs, femdarr10_t* rhs){

    femdarr10_t res = femdarr10_init();

    // Check dimensions.
    res = femdarr10_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_matmul_RF_to(darr_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr10_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr10_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_matmul_FR(femdarr10_t* lhs, darr_t* rhs){

    femdarr10_t res = femdarr10_init();

    // Check dimensions.
    res = femdarr10_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr10_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_matmul_FR_to(femdarr10_t* lhs, darr_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr10_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr10_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdarr10_norm(femdarr10_t* arr){
    
    femdnum10_t res = femdnum10_init();

    
    res = femdnum10_createEmpty( arr->nip);

    femdarr10_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_norm_to(femdarr10_t* arr, femdnum10_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr10_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr10_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdarr10_pnorm(femdarr10_t* arr, coeff_t p){
    
    femdnum10_t res = femdnum10_init();

    
    res = femdnum10_createEmpty( arr->nip);

    femdarr10_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_pnorm_to(femdarr10_t* arr, coeff_t p, femdnum10_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr10_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr10_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum10_t femdarr10_det(femdarr10_t* arr){
    
    femdnum10_t res = femdnum10_init();

    
    res = femdnum10_createEmpty( arr->nip);

    femdarr10_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_det_to(femdarr10_t* arr, femdnum10_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr10_dimCheck_F_squareness( arr, arr);
    femdarr10_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        mdarr10_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_invert(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    // Should it copy offsets too?
    res = femdarr10_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr10_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_invert_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    femdarr10_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr10_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_transpose(femdarr10_t* arr){

    femdarr10_t res = femdarr10_init();

    // Should it copy offsets?
    res = femdarr10_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    femdarr10_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_transpose_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    // Check dimensions.
    femdarr10_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr10_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

