
// ****************************************************************************************************
fednum_t fecarr_dotproduct_FF(fecarr_t* lhs, fecarr_t* rhs){

    fednum_t res = fednum_init();

    res = fednum_createEmpty( rhs->nip);

    fecarr_dotproduct_FF_to(lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_dotproduct_FF_to(fecarr_t* lhs, fecarr_t* rhs, fednum_t* res){

    uint64_t i;

    // Check Dimensions
    fecarr_dimCheck_FF_samesize(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        carr_dotproduct_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
fednum_t fecarr_dotproduct_RF( carr_t* lhs, fecarr_t* rhs){

    fednum_t res = fednum_init();

    res = fednum_createEmpty( rhs->nip);

    fecarr_dotproduct_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_dotproduct_RF_to( carr_t* lhs, fecarr_t* rhs, fednum_t* res){

    uint64_t i;

    // Check Dimensions
    fecarr_dimCheck_RF_samesize(lhs, rhs, res);

    for (i = 0; i < res->nip; i++){

        carr_dotproduct_RR_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------






















// ****************************************************************************************************
fecarr_t fecarr_matmul_FF(fecarr_t* lhs, fecarr_t* rhs){

    fecarr_t res = fecarr_init();

    // Check dimensions.
    res = fecarr_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    fecarr_matmul_FF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_matmul_FF_to(fecarr_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check Dimensions
    fecarr_dimCheck_FF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        carr_matmul_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_matmul_RF(carr_t* lhs, fecarr_t* rhs){

    fecarr_t res = fecarr_init();

    // Check dimensions.
    res = fecarr_createEmpty( lhs->nrows, rhs->ncols, rhs->nip);

    fecarr_matmul_RF_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_matmul_RF_to(carr_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check Dimensions
    fecarr_dimCheck_RF_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        carr_matmul_RR_to( lhs, &rhs->p_data[i], &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_matmul_FR(fecarr_t* lhs, carr_t* rhs){

    fecarr_t res = fecarr_init();

    // Check dimensions.
    res = fecarr_createEmpty( lhs->nrows, rhs->ncols, lhs->nip);

    fecarr_matmul_FR_to( lhs, rhs, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_matmul_FR_to(fecarr_t* lhs, carr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check Dimensions
    fecarr_dimCheck_FR_matmul(lhs, rhs, res);

    for (i = 0; i<res->nip; i++){

        carr_matmul_RR_to( &lhs->p_data[i], rhs, &res->p_data[i] );

    }

}
// ----------------------------------------------------------------------------------------------------


















// ****************************************************************************************************
fednum_t fecarr_norm(fecarr_t* arr){
    
    fednum_t res = fednum_init();

    
    res = fednum_createEmpty( arr->nip);

    fecarr_norm_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_norm_to(fecarr_t* arr, fednum_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    fecarr_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        carr_pnorm_to( &arr->p_data[i], 2.0, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------










// ****************************************************************************************************
fednum_t fecarr_pnorm(fecarr_t* arr, coeff_t p){
    
    fednum_t res = fednum_init();

    
    res = fednum_createEmpty( arr->nip);

    fecarr_pnorm_to( arr, p, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_pnorm_to(fecarr_t* arr, coeff_t p, fednum_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    fecarr_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){

        carr_pnorm_to( &arr->p_data[i], p, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
fednum_t fecarr_det(fecarr_t* arr){
    
    fednum_t res = fednum_init();
    
    res = fednum_createEmpty( arr->nip );

    fecarr_det_to( arr, &res );
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_det_to(fecarr_t* arr, fednum_t* res){
    
    uint64_t i;
    
    // Check dimensions (squareness)
    fecarr_dimCheck_F_squareness( arr, arr);
    fecarr_dimCheck_fF_elementwise(res,arr,arr);

    for (i = 0; i<arr->nip; i++){
        
        carr_det_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------



















// ****************************************************************************************************
fecarr_t fecarr_invert(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    // Should it copy offsets too?
    res = fecarr_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    fecarr_invert_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_invert_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    // Check dimensions (must be square and equal).
    fecarr_dimCheck_F_squareness( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        carr_invert_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

















// ****************************************************************************************************
fecarr_t fecarr_transpose(fecarr_t* arr){

    fecarr_t res = fecarr_init();

    // Should it copy offsets?
    res = fecarr_createEmpty( arr->ncols, arr->nrows, arr->nip);
    
    fecarr_transpose_to( arr, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_transpose_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    // Check dimensions.
    fecarr_dimCheck_F_transpose( arr, res);
    
    for (i = 0; i<arr->nip; i++){

        carr_transpose_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------




