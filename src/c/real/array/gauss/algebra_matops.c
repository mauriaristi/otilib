
// ****************************************************************************************************
fednum_t fedarr_dotproduct_FF(fedarr_t* lhs, fedarr_t* rhs){

    fednum_t res = fednum_init();

    res = fednum_createEmpty( rhs->nip);

    fedarr_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_dotproduct_FF_to(fedarr_t* lhs, fedarr_t* rhs, fednum_t* res){

    uint64_t i;

    // Check Dimensions
    fedarr_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        darr_dotproduct_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
fednum_t fedarr_dotproduct_RF( darr_t* lhs, fedarr_t* rhs){

    fednum_t res = fednum_init();

    res = fednum_createEmpty( rhs->nip);

    fedarr_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_dotproduct_RF_to( darr_t* lhs, fedarr_t* rhs, fednum_t* res){

    uint64_t i;

    // Check Dimensions
    fedarr_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        darr_dotproduct_RR_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------






















// ****************************************************************************************************
fedarr_t fedarr_matmul_FF(fedarr_t* lhs, fedarr_t* rhs){

    fedarr_t res = fedarr_init();

    // Check dimensions.
    res = fedarr_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    fedarr_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_matmul_FF_to(fedarr_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check Dimensions
    fedarr_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        darr_matmul_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_matmul_RF(darr_t* lhs, fedarr_t* rhs){

    fedarr_t res = fedarr_init();

    // Check dimensions.
    res = fedarr_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    fedarr_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_matmul_RF_to(darr_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check Dimensions
    fedarr_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        darr_matmul_RR_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_matmul_FR(fedarr_t* lhs, darr_t* rhs){

    fedarr_t res = fedarr_init();

    // Check dimensions.
    res = fedarr_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    fedarr_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_matmul_FR_to(fedarr_t* lhs, darr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check Dimensions
    fedarr_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        darr_matmul_RR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------


















// ****************************************************************************************************
fednum_t fedarr_norm(fedarr_t* arr){
    
    fednum_t res = fednum_init();

    
    res = fednum_createEmpty( arr->nip);

    fedarr_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_norm_to(fedarr_t* arr, fednum_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    fedarr_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        darr_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------










// ****************************************************************************************************
fednum_t fedarr_pnorm(fedarr_t* arr, coeff_t p){
    
    fednum_t res = fednum_init();

    
    res = fednum_createEmpty( arr->nip);

    fedarr_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_pnorm_to(fedarr_t* arr, coeff_t p, fednum_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    fedarr_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        darr_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fednum_t fedarr_det(fedarr_t* arr){
    
    fednum_t res = fednum_init();

    
    res = fednum_createEmpty( arr->nip);

    fedarr_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_det_to(fedarr_t* arr, fednum_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    fedarr_dimCheck_F_squareness( arr, arr);
    fedarr_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        darr_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------



















// ****************************************************************************************************
fedarr_t fedarr_invert(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    // Should it copy offsets too?
    res = fedarr_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    fedarr_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_invert_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    fedarr_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        darr_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

















// ****************************************************************************************************
fedarr_t fedarr_transpose(fedarr_t* arr){

    fedarr_t res = fedarr_init();

    // Should it copy offsets?
    res = fedarr_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    fedarr_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_transpose_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    // Check dimensions.
    fedarr_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        darr_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------




