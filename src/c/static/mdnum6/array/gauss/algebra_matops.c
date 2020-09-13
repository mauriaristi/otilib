
// void femdarr6_dimCheck_FF_elementwise(femdarr6_t* arr1, femdarr6_t* arr2, femdarr6_t* res);
// void femdarr6_dimCheck_OF_elementwise(  mdarr6_t* arr1, femdarr6_t* arr2, femdarr6_t* res);
// void femdarr6_dimCheck_RF_elementwise(   darr_t* arr1, femdarr6_t* arr2, femdarr6_t* res);
// void femdarr6_dimCheck_FF_matmul( femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
// void femdarr6_dimCheck_OF_matmul(   mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
// void femdarr6_dimCheck_RF_matmul(    darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
// void femdarr6_dimCheck_FO_matmul( femdarr6_t* lhs,   mdarr6_t* rhs, femdarr6_t* res);
// void femdarr6_dimCheck_FR_matmul( femdarr6_t* lhs,    darr_t* rhs, femdarr6_t* res);
// void femdarr6_dimCheck_F_squareness( femdarr6_t* arr1, femdarr6_t* res);
// void femdarr6_dimCheck_F_transpose( femdarr6_t* arr1, femdarr6_t* res);

// ****************************************************************************************************
femdnum6_t femdarr6_dotproduct_FF(femdarr6_t* lhs, femdarr6_t* rhs){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty( rhs->nip);

    femdarr6_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_dotproduct_FF_to(femdarr6_t* lhs, femdarr6_t* rhs, femdnum6_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr6_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr6_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdarr6_dotproduct_OF(mdarr6_t* lhs, femdarr6_t* rhs){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty( rhs->nip);

    femdarr6_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_dotproduct_OF_to( mdarr6_t* lhs, femdarr6_t* rhs, femdnum6_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr6_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr6_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdarr6_dotproduct_RF( darr_t* lhs, femdarr6_t* rhs){

    femdnum6_t res = femdnum6_init();

    res = femdnum6_createEmpty( rhs->nip);

    femdarr6_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_dotproduct_RF_to( darr_t* lhs, femdarr6_t* rhs, femdnum6_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr6_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr6_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_matmul_FF(femdarr6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res = femdarr6_init();

    // Check dimensions.
    res = femdarr6_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr6_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_matmul_FF_to(femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr6_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr6_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_matmul_OF(mdarr6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res = femdarr6_init();

    // Check dimensions.
    res = femdarr6_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_matmul_OF_to(mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr6_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr6_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_matmul_FO(femdarr6_t* lhs, mdarr6_t* rhs){

    femdarr6_t res = femdarr6_init();

    // Check dimensions.
    res = femdarr6_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr6_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_matmul_FO_to(femdarr6_t* lhs, mdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr6_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr6_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_matmul_RF(darr_t* lhs, femdarr6_t* rhs){

    femdarr6_t res = femdarr6_init();

    // Check dimensions.
    res = femdarr6_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_matmul_RF_to(darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr6_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr6_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_matmul_FR(femdarr6_t* lhs, darr_t* rhs){

    femdarr6_t res = femdarr6_init();

    // Check dimensions.
    res = femdarr6_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr6_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_matmul_FR_to(femdarr6_t* lhs, darr_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr6_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr6_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdarr6_norm(femdarr6_t* arr){
    
    femdnum6_t res = femdnum6_init();

    
    res = femdnum6_createEmpty( arr->nip);

    femdarr6_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_norm_to(femdarr6_t* arr, femdnum6_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr6_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr6_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdarr6_pnorm(femdarr6_t* arr, coeff_t p){
    
    femdnum6_t res = femdnum6_init();

    
    res = femdnum6_createEmpty( arr->nip);

    femdarr6_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_pnorm_to(femdarr6_t* arr, coeff_t p, femdnum6_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr6_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr6_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum6_t femdarr6_det(femdarr6_t* arr){
    
    femdnum6_t res = femdnum6_init();

    
    res = femdnum6_createEmpty( arr->nip);

    femdarr6_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_det_to(femdarr6_t* arr, femdnum6_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr6_dimCheck_F_squareness( arr, arr);
    femdarr6_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        mdarr6_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_invert(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    // Should it copy offsets too?
    res = femdarr6_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr6_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_invert_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    femdarr6_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr6_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_transpose(femdarr6_t* arr){

    femdarr6_t res = femdarr6_init();

    // Should it copy offsets?
    res = femdarr6_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    femdarr6_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_transpose_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    // Check dimensions.
    femdarr6_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr6_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

