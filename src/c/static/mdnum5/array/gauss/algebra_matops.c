
// void femdarr5_dimCheck_FF_elementwise(femdarr5_t* arr1, femdarr5_t* arr2, femdarr5_t* res);
// void femdarr5_dimCheck_OF_elementwise(  mdarr5_t* arr1, femdarr5_t* arr2, femdarr5_t* res);
// void femdarr5_dimCheck_RF_elementwise(   darr_t* arr1, femdarr5_t* arr2, femdarr5_t* res);
// void femdarr5_dimCheck_FF_matmul( femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
// void femdarr5_dimCheck_OF_matmul(   mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
// void femdarr5_dimCheck_RF_matmul(    darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
// void femdarr5_dimCheck_FO_matmul( femdarr5_t* lhs,   mdarr5_t* rhs, femdarr5_t* res);
// void femdarr5_dimCheck_FR_matmul( femdarr5_t* lhs,    darr_t* rhs, femdarr5_t* res);
// void femdarr5_dimCheck_F_squareness( femdarr5_t* arr1, femdarr5_t* res);
// void femdarr5_dimCheck_F_transpose( femdarr5_t* arr1, femdarr5_t* res);

// ****************************************************************************************************
femdnum5_t femdarr5_dotproduct_FF(femdarr5_t* lhs, femdarr5_t* rhs){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty( rhs->nip);

    femdarr5_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_dotproduct_FF_to(femdarr5_t* lhs, femdarr5_t* rhs, femdnum5_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr5_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr5_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdarr5_dotproduct_OF(mdarr5_t* lhs, femdarr5_t* rhs){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty( rhs->nip);

    femdarr5_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_dotproduct_OF_to( mdarr5_t* lhs, femdarr5_t* rhs, femdnum5_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr5_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr5_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdarr5_dotproduct_RF( darr_t* lhs, femdarr5_t* rhs){

    femdnum5_t res = femdnum5_init();

    res = femdnum5_createEmpty( rhs->nip);

    femdarr5_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_dotproduct_RF_to( darr_t* lhs, femdarr5_t* rhs, femdnum5_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr5_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr5_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_matmul_FF(femdarr5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res = femdarr5_init();

    // Check dimensions.
    res = femdarr5_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr5_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_matmul_FF_to(femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr5_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr5_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_matmul_OF(mdarr5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res = femdarr5_init();

    // Check dimensions.
    res = femdarr5_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_matmul_OF_to(mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr5_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr5_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_matmul_FO(femdarr5_t* lhs, mdarr5_t* rhs){

    femdarr5_t res = femdarr5_init();

    // Check dimensions.
    res = femdarr5_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr5_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_matmul_FO_to(femdarr5_t* lhs, mdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr5_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr5_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_matmul_RF(darr_t* lhs, femdarr5_t* rhs){

    femdarr5_t res = femdarr5_init();

    // Check dimensions.
    res = femdarr5_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_matmul_RF_to(darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr5_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr5_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_matmul_FR(femdarr5_t* lhs, darr_t* rhs){

    femdarr5_t res = femdarr5_init();

    // Check dimensions.
    res = femdarr5_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr5_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_matmul_FR_to(femdarr5_t* lhs, darr_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr5_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr5_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdarr5_norm(femdarr5_t* arr){
    
    femdnum5_t res = femdnum5_init();

    
    res = femdnum5_createEmpty( arr->nip);

    femdarr5_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_norm_to(femdarr5_t* arr, femdnum5_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr5_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr5_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdarr5_pnorm(femdarr5_t* arr, coeff_t p){
    
    femdnum5_t res = femdnum5_init();

    
    res = femdnum5_createEmpty( arr->nip);

    femdarr5_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_pnorm_to(femdarr5_t* arr, coeff_t p, femdnum5_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr5_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr5_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum5_t femdarr5_det(femdarr5_t* arr){
    
    femdnum5_t res = femdnum5_init();

    
    res = femdnum5_createEmpty( arr->nip);

    femdarr5_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_det_to(femdarr5_t* arr, femdnum5_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr5_dimCheck_F_squareness( arr, arr);
    femdarr5_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        mdarr5_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_invert(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    // Should it copy offsets too?
    res = femdarr5_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr5_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_invert_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    femdarr5_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr5_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_transpose(femdarr5_t* arr){

    femdarr5_t res = femdarr5_init();

    // Should it copy offsets?
    res = femdarr5_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    femdarr5_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_transpose_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    // Check dimensions.
    femdarr5_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr5_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

