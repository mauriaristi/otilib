
// void femdarr1_dimCheck_FF_elementwise(femdarr1_t* arr1, femdarr1_t* arr2, femdarr1_t* res);
// void femdarr1_dimCheck_OF_elementwise(  mdarr1_t* arr1, femdarr1_t* arr2, femdarr1_t* res);
// void femdarr1_dimCheck_RF_elementwise(   darr_t* arr1, femdarr1_t* arr2, femdarr1_t* res);
// void femdarr1_dimCheck_FF_matmul( femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
// void femdarr1_dimCheck_OF_matmul(   mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
// void femdarr1_dimCheck_RF_matmul(    darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
// void femdarr1_dimCheck_FO_matmul( femdarr1_t* lhs,   mdarr1_t* rhs, femdarr1_t* res);
// void femdarr1_dimCheck_FR_matmul( femdarr1_t* lhs,    darr_t* rhs, femdarr1_t* res);
// void femdarr1_dimCheck_F_squareness( femdarr1_t* arr1, femdarr1_t* res);
// void femdarr1_dimCheck_F_transpose( femdarr1_t* arr1, femdarr1_t* res);

// ****************************************************************************************************
femdnum1_t femdarr1_dotproduct_FF(femdarr1_t* lhs, femdarr1_t* rhs){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty( rhs->nip);

    femdarr1_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_dotproduct_FF_to(femdarr1_t* lhs, femdarr1_t* rhs, femdnum1_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr1_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr1_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdarr1_dotproduct_OF(mdarr1_t* lhs, femdarr1_t* rhs){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty( rhs->nip);

    femdarr1_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_dotproduct_OF_to( mdarr1_t* lhs, femdarr1_t* rhs, femdnum1_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr1_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr1_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdarr1_dotproduct_RF( darr_t* lhs, femdarr1_t* rhs){

    femdnum1_t res = femdnum1_init();

    res = femdnum1_createEmpty( rhs->nip);

    femdarr1_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_dotproduct_RF_to( darr_t* lhs, femdarr1_t* rhs, femdnum1_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr1_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr1_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_matmul_FF(femdarr1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res = femdarr1_init();

    // Check dimensions.
    res = femdarr1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr1_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_matmul_FF_to(femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr1_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr1_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_matmul_OF(mdarr1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res = femdarr1_init();

    // Check dimensions.
    res = femdarr1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_matmul_OF_to(mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr1_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr1_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_matmul_FO(femdarr1_t* lhs, mdarr1_t* rhs){

    femdarr1_t res = femdarr1_init();

    // Check dimensions.
    res = femdarr1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr1_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_matmul_FO_to(femdarr1_t* lhs, mdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr1_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr1_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_matmul_RF(darr_t* lhs, femdarr1_t* rhs){

    femdarr1_t res = femdarr1_init();

    // Check dimensions.
    res = femdarr1_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_matmul_RF_to(darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr1_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr1_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_matmul_FR(femdarr1_t* lhs, darr_t* rhs){

    femdarr1_t res = femdarr1_init();

    // Check dimensions.
    res = femdarr1_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr1_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_matmul_FR_to(femdarr1_t* lhs, darr_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr1_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr1_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdarr1_norm(femdarr1_t* arr){
    
    femdnum1_t res = femdnum1_init();

    
    res = femdnum1_createEmpty( arr->nip);

    femdarr1_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_norm_to(femdarr1_t* arr, femdnum1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr1_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdarr1_pnorm(femdarr1_t* arr, coeff_t p){
    
    femdnum1_t res = femdnum1_init();

    
    res = femdnum1_createEmpty( arr->nip);

    femdarr1_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_pnorm_to(femdarr1_t* arr, coeff_t p, femdnum1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr1_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum1_t femdarr1_det(femdarr1_t* arr){
    
    femdnum1_t res = femdnum1_init();

    
    res = femdnum1_createEmpty( arr->nip);

    femdarr1_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_det_to(femdarr1_t* arr, femdnum1_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr1_dimCheck_F_squareness( arr, arr);
    femdarr1_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        mdarr1_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_invert(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    // Should it copy offsets too?
    res = femdarr1_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr1_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_invert_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    femdarr1_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr1_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_transpose(femdarr1_t* arr){

    femdarr1_t res = femdarr1_init();

    // Should it copy offsets?
    res = femdarr1_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    femdarr1_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_transpose_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    // Check dimensions.
    femdarr1_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr1_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

