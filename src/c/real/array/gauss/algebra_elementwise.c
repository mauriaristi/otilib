// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
fedarr_t fedarr_neg(fedarr_t* arr){

    fedarr_t res;

    res = fedarr_createEmpty(arr->nrows, arr->ncols, arr->nip);

    fedarr_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_neg_to(fedarr_t* arr, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        darr_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------







// 1.2 Addition
// ****************************************************************************************************
fedarr_t fedarr_sum_FF(fedarr_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_sum_fF(fednum_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_sum_RF(darr_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fedarr_t fedarr_sum_rF(coeff_t lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void fedarr_sum_FF_to(fedarr_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_sum_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sum_fF_to(fednum_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_sum_rR_to( lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sum_RF_to(darr_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_sum_RR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sum_rF_to(coeff_t lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_sum_rR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------






















// 1.3 Subtraction
// ****************************************************************************************************
fedarr_t fedarr_sub_FF(fedarr_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_sub_fF(fednum_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_sub_Ff(fedarr_t* lhs, fednum_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fedarr_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_sub_RF(darr_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_sub_FR(fedarr_t* lhs, darr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fedarr_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fedarr_t fedarr_sub_rF(coeff_t lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_sub_Fr(fedarr_t* lhs, coeff_t rhs){

    fedarr_t res;

    res = fedarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fedarr_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sub_FF_to(fedarr_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_sub_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sub_fF_to(fednum_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_sub_rR_to( lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sub_Ff_to(fedarr_t* lhs, fednum_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_sub_Rr_to( &lhs->p_data[i], rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void fedarr_sub_RF_to(darr_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_sub_RR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sub_FR_to(fedarr_t* lhs, darr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_sub_RR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sub_rF_to(coeff_t lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_sub_rR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_sub_Fr_to(fedarr_t* lhs, coeff_t rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_sub_Rr_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------














































// 1.4 Multiplication
// ****************************************************************************************************
fedarr_t fedarr_mul_FF(fedarr_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_mul_fF(fednum_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_mul_RF(darr_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fedarr_t fedarr_mul_rF(coeff_t lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_mul_FF_to(fedarr_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_mul_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_mul_fF_to(fednum_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_mul_rR_to( lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fedarr_mul_RF_to(darr_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_mul_RR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fedarr_mul_rF_to(coeff_t lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_mul_rR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------























// 1.5 Division
// ****************************************************************************************************
fedarr_t fedarr_div_FF(fedarr_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_div_Ff(fedarr_t* lhs, fednum_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fedarr_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_div_fF(fednum_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_div_RF(darr_t* lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_div_FR(fedarr_t* lhs, darr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fedarr_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_div_rF(coeff_t lhs, fedarr_t* rhs){

    fedarr_t res;

    res = fedarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fedarr_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fedarr_t fedarr_div_Fr(fedarr_t* lhs, coeff_t rhs){

    fedarr_t res;

    res = fedarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fedarr_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_div_FF_to(fedarr_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_div_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_div_fF_to(fednum_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_div_rR_to( lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_div_Ff_to(fedarr_t* lhs, fednum_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_div_Rr_to( &lhs->p_data[i], rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_div_RF_to(darr_t* lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_div_RR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_div_FR_to(fedarr_t* lhs, darr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_div_RR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_div_rF_to(coeff_t lhs, fedarr_t* rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_div_rR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_div_Fr_to(fedarr_t* lhs, coeff_t rhs, fedarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fedarr_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        darr_div_Rr_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

















// ****************************************************************************************************
darr_t fedarr_integrate(fedarr_t* arr, fednum_t* w){

    darr_t  res = darr_init();

    res = darr_zeros(arr->nrows, arr->ncols);

    fedarr_integrate_to( arr, w, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fedarr_integrate_to(fedarr_t* arr, fednum_t* w, darr_t* res){

    uint64_t i = 0;

    // Check dimensions.
    fedarr_dimCheck_FfR_integrate( arr, w, res);

    darr_set_all_r(0.0, res);
    
    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        darr_gem_rR_to( w->p_data[i], &arr->p_data[i], res, res);

    }


}
// ----------------------------------------------------------------------------------------------------




