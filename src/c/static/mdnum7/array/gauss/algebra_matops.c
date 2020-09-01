
// void femdarr7_dimCheck_FF_elementwise(femdarr7_t* arr1, femdarr7_t* arr2, femdarr7_t* res);
// void femdarr7_dimCheck_OF_elementwise(  mdarr7_t* arr1, femdarr7_t* arr2, femdarr7_t* res);
// void femdarr7_dimCheck_RF_elementwise(   darr_t* arr1, femdarr7_t* arr2, femdarr7_t* res);
// void femdarr7_dimCheck_FF_matmul( femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
// void femdarr7_dimCheck_OF_matmul(   mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
// void femdarr7_dimCheck_RF_matmul(    darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
// void femdarr7_dimCheck_FO_matmul( femdarr7_t* lhs,   mdarr7_t* rhs, femdarr7_t* res);
// void femdarr7_dimCheck_FR_matmul( femdarr7_t* lhs,    darr_t* rhs, femdarr7_t* res);
// void femdarr7_dimCheck_F_squareness( femdarr7_t* arr1, femdarr7_t* res);
// void femdarr7_dimCheck_F_transpose( femdarr7_t* arr1, femdarr7_t* res);

// ****************************************************************************************************
femdnum7_t femdarr7_dotproduct_FF(femdarr7_t* lhs, femdarr7_t* rhs){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty( rhs->nip);

    femdarr7_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_dotproduct_FF_to(femdarr7_t* lhs, femdarr7_t* rhs, femdnum7_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr7_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr7_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdarr7_dotproduct_OF(mdarr7_t* lhs, femdarr7_t* rhs){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty( rhs->nip);

    femdarr7_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_dotproduct_OF_to( mdarr7_t* lhs, femdarr7_t* rhs, femdnum7_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr7_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr7_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdarr7_dotproduct_RF( darr_t* lhs, femdarr7_t* rhs){

    femdnum7_t res = femdnum7_init();

    res = femdnum7_createEmpty( rhs->nip);

    femdarr7_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_dotproduct_RF_to( darr_t* lhs, femdarr7_t* rhs, femdnum7_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr7_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr7_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_matmul_FF(femdarr7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res = femdarr7_init();

    // Check dimensions.
    res = femdarr7_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr7_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_matmul_FF_to(femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr7_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr7_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_matmul_OF(mdarr7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res = femdarr7_init();

    // Check dimensions.
    res = femdarr7_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_matmul_OF_to(mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr7_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr7_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_matmul_FO(femdarr7_t* lhs, mdarr7_t* rhs){

    femdarr7_t res = femdarr7_init();

    // Check dimensions.
    res = femdarr7_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr7_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_matmul_FO_to(femdarr7_t* lhs, mdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr7_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr7_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_matmul_RF(darr_t* lhs, femdarr7_t* rhs){

    femdarr7_t res = femdarr7_init();

    // Check dimensions.
    res = femdarr7_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_matmul_RF_to(darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr7_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr7_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_matmul_FR(femdarr7_t* lhs, darr_t* rhs){

    femdarr7_t res = femdarr7_init();

    // Check dimensions.
    res = femdarr7_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr7_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_matmul_FR_to(femdarr7_t* lhs, darr_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr7_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr7_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdarr7_norm(femdarr7_t* arr){
    
    femdnum7_t res = femdnum7_init();

    
    res = femdnum7_createEmpty( arr->nip);

    femdarr7_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_norm_to(femdarr7_t* arr, femdnum7_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr7_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr7_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdarr7_pnorm(femdarr7_t* arr, coeff_t p){
    
    femdnum7_t res = femdnum7_init();

    
    res = femdnum7_createEmpty( arr->nip);

    femdarr7_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_pnorm_to(femdarr7_t* arr, coeff_t p, femdnum7_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr7_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr7_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum7_t femdarr7_det(femdarr7_t* arr){
    
    femdnum7_t res = femdnum7_init();

    
    res = femdnum7_createEmpty( arr->nip);

    femdarr7_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_det_to(femdarr7_t* arr, femdnum7_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr7_dimCheck_F_squareness( arr, arr);
    femdarr7_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        mdarr7_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_invert(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    // Should it copy offsets too?
    res = femdarr7_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr7_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_invert_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    femdarr7_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr7_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_transpose(femdarr7_t* arr){

    femdarr7_t res = femdarr7_init();

    // Should it copy offsets?
    res = femdarr7_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    femdarr7_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_transpose_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    // Check dimensions.
    femdarr7_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr7_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

