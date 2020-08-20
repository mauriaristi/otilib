
// void femdarr4_dimCheck_FF_elementwise(femdarr4_t* arr1, femdarr4_t* arr2, femdarr4_t* res);
// void femdarr4_dimCheck_OF_elementwise(  mdarr4_t* arr1, femdarr4_t* arr2, femdarr4_t* res);
// void femdarr4_dimCheck_RF_elementwise(   darr_t* arr1, femdarr4_t* arr2, femdarr4_t* res);
// void femdarr4_dimCheck_FF_matmul( femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);
// void femdarr4_dimCheck_OF_matmul(   mdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);
// void femdarr4_dimCheck_RF_matmul(    darr_t* lhs, femdarr4_t* rhs, femdarr4_t* res);
// void femdarr4_dimCheck_FO_matmul( femdarr4_t* lhs,   mdarr4_t* rhs, femdarr4_t* res);
// void femdarr4_dimCheck_FR_matmul( femdarr4_t* lhs,    darr_t* rhs, femdarr4_t* res);
// void femdarr4_dimCheck_F_squareness( femdarr4_t* arr1, femdarr4_t* res);
// void femdarr4_dimCheck_F_transpose( femdarr4_t* arr1, femdarr4_t* res);

// ****************************************************************************************************
femdnum4_t femdarr4_dotproduct_FF(femdarr4_t* lhs, femdarr4_t* rhs){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty( rhs->nip);

    femdarr4_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_dotproduct_FF_to(femdarr4_t* lhs, femdarr4_t* rhs, femdnum4_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr4_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr4_dotproduct_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdarr4_dotproduct_OF(mdarr4_t* lhs, femdarr4_t* rhs){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty( rhs->nip);

    femdarr4_dotproduct_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_dotproduct_OF_to( mdarr4_t* lhs, femdarr4_t* rhs, femdnum4_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr4_dimCheck_OF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr4_dotproduct_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdarr4_dotproduct_RF( darr_t* lhs, femdarr4_t* rhs){

    femdnum4_t res = femdnum4_init();

    res = femdnum4_createEmpty( rhs->nip);

    femdarr4_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_dotproduct_RF_to( darr_t* lhs, femdarr4_t* rhs, femdnum4_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr4_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        mdarr4_dotproduct_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_matmul_FF(femdarr4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res = femdarr4_init();

    // Check dimensions.
    res = femdarr4_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr4_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_matmul_FF_to(femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr4_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr4_matmul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_matmul_OF(mdarr4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res = femdarr4_init();

    // Check dimensions.
    res = femdarr4_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_matmul_OF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_matmul_OF_to(mdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr4_dimCheck_OF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr4_matmul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_matmul_FO(femdarr4_t* lhs, mdarr4_t* rhs){

    femdarr4_t res = femdarr4_init();

    // Check dimensions.
    res = femdarr4_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr4_matmul_FO_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_matmul_FO_to(femdarr4_t* lhs, mdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr4_dimCheck_FO_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr4_matmul_OO_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_matmul_RF(darr_t* lhs, femdarr4_t* rhs){

    femdarr4_t res = femdarr4_init();

    // Check dimensions.
    res = femdarr4_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_matmul_RF_to(darr_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr4_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr4_matmul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_matmul_FR(femdarr4_t* lhs, darr_t* rhs){

    femdarr4_t res = femdarr4_init();

    // Check dimensions.
    res = femdarr4_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    femdarr4_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_matmul_FR_to(femdarr4_t* lhs, darr_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check Dimensions
    femdarr4_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        mdarr4_matmul_OR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdarr4_norm(femdarr4_t* arr){
    
    femdnum4_t res = femdnum4_init();

    
    res = femdnum4_createEmpty( arr->nip);

    femdarr4_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_norm_to(femdarr4_t* arr, femdnum4_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr4_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr4_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdarr4_pnorm(femdarr4_t* arr, coeff_t p){
    
    femdnum4_t res = femdnum4_init();

    
    res = femdnum4_createEmpty( arr->nip);

    femdarr4_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_pnorm_to(femdarr4_t* arr, coeff_t p, femdnum4_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr4_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        mdarr4_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdnum4_t femdarr4_det(femdarr4_t* arr){
    
    femdnum4_t res = femdnum4_init();

    
    res = femdnum4_createEmpty( arr->nip);

    femdarr4_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_det_to(femdarr4_t* arr, femdnum4_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    femdarr4_dimCheck_F_squareness( arr, arr);
    femdarr4_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        mdarr4_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_invert(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    // Should it copy offsets too?
    res = femdarr4_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    femdarr4_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_invert_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    femdarr4_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr4_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_transpose(femdarr4_t* arr){

    femdarr4_t res = femdarr4_init();

    // Should it copy offsets?
    res = femdarr4_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    femdarr4_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_transpose_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    // Check dimensions.
    femdarr4_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        mdarr4_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

