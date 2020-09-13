
// void femdarr9_dimCheck_FF_elementwise(femdarr9_t* arr1, femdarr9_t* arr2, femdarr9_t* res);
// void femdarr9_dimCheck_OF_elementwise(  mdarr9_t* arr1, femdarr9_t* arr2, femdarr9_t* res);
// void femdarr9_dimCheck_RF_elementwise(   darr_t* arr1, femdarr9_t* arr2, femdarr9_t* res);
// void femdarr9_dimCheck_FF_matmul( femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
// void femdarr9_dimCheck_OF_matmul(   mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
// void femdarr9_dimCheck_RF_matmul(    darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
// void femdarr9_dimCheck_FO_matmul( femdarr9_t* lhs,   mdarr9_t* rhs, femdarr9_t* res);
// void femdarr9_dimCheck_FR_matmul( femdarr9_t* lhs,    darr_t* rhs, femdarr9_t* res);
// void femdarr9_dimCheck_F_squareness( femdarr9_t* arr1, femdarr9_t* res);
// void femdarr9_dimCheck_F_transpose( femdarr9_t* arr1, femdarr9_t* res);

// ****************************************************************************************************
femdnum9_t femdarr9_dotproduct_FF(femdarr9_t* lhs, femdarr9_t* rhs){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty( rhs->nip);

    femdarr9_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_dotproduct_FF_to(femdarr9_t* lhs, femdarr9_t* rhs, femdnum9_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr9_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr9_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdarr9_dotproduct_OF(mdarr9_t* lhs, femdarr9_t* rhs){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty( rhs->nip);

    femdarr9_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_dotproduct_OF_to( mdarr9_t* lhs, femdarr9_t* rhs, femdnum9_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr9_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr9_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdarr9_dotproduct_RF( darr_t* lhs, femdarr9_t* rhs){

    femdnum9_t res = femdnum9_init();

    res = femdnum9_createEmpty( rhs->nip);

    femdarr9_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_dotproduct_RF_to( darr_t* lhs, femdarr9_t* rhs, femdnum9_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr9_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr9_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_matmul_FF(femdarr9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res = femdarr9_init();

    // Check dimensions.
    res = femdarr9_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr9_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_matmul_FF_to(femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr9_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr9_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_matmul_OF(mdarr9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res = femdarr9_init();

    // Check dimensions.
    res = femdarr9_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_matmul_OF_to(mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr9_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr9_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_matmul_FO(femdarr9_t* lhs, mdarr9_t* rhs){

    femdarr9_t res = femdarr9_init();

    // Check dimensions.
    res = femdarr9_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr9_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_matmul_FO_to(femdarr9_t* lhs, mdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr9_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr9_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_matmul_RF(darr_t* lhs, femdarr9_t* rhs){

    femdarr9_t res = femdarr9_init();

    // Check dimensions.
    res = femdarr9_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_matmul_RF_to(darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr9_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr9_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_matmul_FR(femdarr9_t* lhs, darr_t* rhs){

    femdarr9_t res = femdarr9_init();

    // Check dimensions.
    res = femdarr9_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr9_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_matmul_FR_to(femdarr9_t* lhs, darr_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr9_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr9_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdarr9_norm(femdarr9_t* arr){
    
    femdnum9_t res = femdnum9_init();

    
    res = femdnum9_createEmpty( arr->nip);

    femdarr9_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_norm_to(femdarr9_t* arr, femdnum9_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr9_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr9_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdarr9_pnorm(femdarr9_t* arr, coeff_t p){
    
    femdnum9_t res = femdnum9_init();

    
    res = femdnum9_createEmpty( arr->nip);

    femdarr9_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_pnorm_to(femdarr9_t* arr, coeff_t p, femdnum9_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr9_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr9_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum9_t femdarr9_det(femdarr9_t* arr){
    
    femdnum9_t res = femdnum9_init();

    
    res = femdnum9_createEmpty( arr->nip);

    femdarr9_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_det_to(femdarr9_t* arr, femdnum9_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr9_dimCheck_F_squareness( arr, arr);
    femdarr9_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        mdarr9_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_invert(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    // Should it copy offsets too?
    res = femdarr9_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr9_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_invert_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    femdarr9_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr9_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_transpose(femdarr9_t* arr){

    femdarr9_t res = femdarr9_init();

    // Should it copy offsets?
    res = femdarr9_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    femdarr9_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_transpose_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    // Check dimensions.
    femdarr9_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr9_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

