
// void femdarr3_dimCheck_FF_elementwise(femdarr3_t* arr1, femdarr3_t* arr2, femdarr3_t* res);
// void femdarr3_dimCheck_OF_elementwise(  mdarr3_t* arr1, femdarr3_t* arr2, femdarr3_t* res);
// void femdarr3_dimCheck_RF_elementwise(   darr_t* arr1, femdarr3_t* arr2, femdarr3_t* res);
// void femdarr3_dimCheck_FF_matmul( femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
// void femdarr3_dimCheck_OF_matmul(   mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
// void femdarr3_dimCheck_RF_matmul(    darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
// void femdarr3_dimCheck_FO_matmul( femdarr3_t* lhs,   mdarr3_t* rhs, femdarr3_t* res);
// void femdarr3_dimCheck_FR_matmul( femdarr3_t* lhs,    darr_t* rhs, femdarr3_t* res);
// void femdarr3_dimCheck_F_squareness( femdarr3_t* arr1, femdarr3_t* res);
// void femdarr3_dimCheck_F_transpose( femdarr3_t* arr1, femdarr3_t* res);

// ****************************************************************************************************
femdnum3_t femdarr3_dotproduct_FF(femdarr3_t* lhs, femdarr3_t* rhs){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty( rhs->nip);

    femdarr3_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_dotproduct_FF_to(femdarr3_t* lhs, femdarr3_t* rhs, femdnum3_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr3_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr3_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdarr3_dotproduct_OF(mdarr3_t* lhs, femdarr3_t* rhs){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty( rhs->nip);

    femdarr3_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_dotproduct_OF_to( mdarr3_t* lhs, femdarr3_t* rhs, femdnum3_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr3_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr3_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdarr3_dotproduct_RF( darr_t* lhs, femdarr3_t* rhs){

    femdnum3_t res = femdnum3_init();

    res = femdnum3_createEmpty( rhs->nip);

    femdarr3_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_dotproduct_RF_to( darr_t* lhs, femdarr3_t* rhs, femdnum3_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr3_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr3_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_matmul_FF(femdarr3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res = femdarr3_init();

    // Check dimensions.
    res = femdarr3_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr3_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_matmul_FF_to(femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr3_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr3_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_matmul_OF(mdarr3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res = femdarr3_init();

    // Check dimensions.
    res = femdarr3_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_matmul_OF_to(mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr3_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr3_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_matmul_FO(femdarr3_t* lhs, mdarr3_t* rhs){

    femdarr3_t res = femdarr3_init();

    // Check dimensions.
    res = femdarr3_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr3_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_matmul_FO_to(femdarr3_t* lhs, mdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr3_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr3_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_matmul_RF(darr_t* lhs, femdarr3_t* rhs){

    femdarr3_t res = femdarr3_init();

    // Check dimensions.
    res = femdarr3_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_matmul_RF_to(darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr3_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr3_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_matmul_FR(femdarr3_t* lhs, darr_t* rhs){

    femdarr3_t res = femdarr3_init();

    // Check dimensions.
    res = femdarr3_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr3_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_matmul_FR_to(femdarr3_t* lhs, darr_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr3_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr3_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdarr3_norm(femdarr3_t* arr){
    
    femdnum3_t res = femdnum3_init();

    
    res = femdnum3_createEmpty( arr->nip);

    femdarr3_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_norm_to(femdarr3_t* arr, femdnum3_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr3_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr3_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdarr3_pnorm(femdarr3_t* arr, coeff_t p){
    
    femdnum3_t res = femdnum3_init();

    
    res = femdnum3_createEmpty( arr->nip);

    femdarr3_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_pnorm_to(femdarr3_t* arr, coeff_t p, femdnum3_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr3_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr3_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum3_t femdarr3_det(femdarr3_t* arr){
    
    femdnum3_t res = femdnum3_init();

    
    res = femdnum3_createEmpty( arr->nip);

    femdarr3_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_det_to(femdarr3_t* arr, femdnum3_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr3_dimCheck_F_squareness( arr, arr);
    femdarr3_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        mdarr3_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_invert(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    // Should it copy offsets too?
    res = femdarr3_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr3_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_invert_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    femdarr3_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr3_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_transpose(femdarr3_t* arr){

    femdarr3_t res = femdarr3_init();

    // Should it copy offsets?
    res = femdarr3_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    femdarr3_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_transpose_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    // Check dimensions.
    femdarr3_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr3_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

