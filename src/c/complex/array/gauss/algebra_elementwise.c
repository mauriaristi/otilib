// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
fecarr_t fecarr_neg(fecarr_t* arr){

    fecarr_t res;

    res = fecarr_createEmpty(arr->nrows, arr->ncols, arr->nip);

    fecarr_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_neg_to(fecarr_t* arr, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        carr_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------







// 1.2 Addition
// ****************************************************************************************************
fecarr_t fecarr_sum_FF(fecarr_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_sum_fF(fednum_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_sum_RF(carr_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fecarr_t fecarr_sum_rF(coeff_t lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void fecarr_sum_FF_to(fecarr_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_sum_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sum_fF_to(fednum_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_sum_rR_to( lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sum_RF_to(carr_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_sum_RR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sum_rF_to(coeff_t lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_sum_rR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------






















// 1.3 Subtraction
// ****************************************************************************************************
fecarr_t fecarr_sub_FF(fecarr_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_sub_fF(fednum_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_sub_Ff(fecarr_t* lhs, fednum_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fecarr_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_sub_RF(carr_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_sub_FR(fecarr_t* lhs, carr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fecarr_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fecarr_t fecarr_sub_rF(coeff_t lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_sub_Fr(fecarr_t* lhs, coeff_t rhs){

    fecarr_t res;

    res = fecarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fecarr_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sub_FF_to(fecarr_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_sub_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sub_fF_to(fednum_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_sub_rR_to( lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sub_Ff_to(fecarr_t* lhs, fednum_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_sub_Rr_to( &lhs->p_data[i], rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void fecarr_sub_RF_to(carr_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_sub_RR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sub_FR_to(fecarr_t* lhs, carr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_sub_RR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sub_rF_to(coeff_t lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_sub_rR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_sub_Fr_to(fecarr_t* lhs, coeff_t rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_sub_Rr_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------














































// 1.4 Multiplication
// ****************************************************************************************************
fecarr_t fecarr_mul_FF(fecarr_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_mul_fF(fednum_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_mul_RF(carr_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
fecarr_t fecarr_mul_rF(coeff_t lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_mul_FF_to(fecarr_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_mul_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_mul_fF_to(fednum_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_mul_rR_to( lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fecarr_mul_RF_to(carr_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_mul_RR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fecarr_mul_rF_to(coeff_t lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_mul_rR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------























// 1.5 Division
// ****************************************************************************************************
fecarr_t fecarr_div_FF(fecarr_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_div_Ff(fecarr_t* lhs, fednum_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fecarr_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_div_fF(fednum_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_div_RF(carr_t* lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_div_FR(fecarr_t* lhs, carr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fecarr_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_div_rF(coeff_t lhs, fecarr_t* rhs){

    fecarr_t res;

    res = fecarr_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    fecarr_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fecarr_t fecarr_div_Fr(fecarr_t* lhs, coeff_t rhs){

    fecarr_t res;

    res = fecarr_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    fecarr_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_div_FF_to(fecarr_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_div_RR_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_div_fF_to(fednum_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_div_rR_to( lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_div_Ff_to(fecarr_t* lhs, fednum_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_div_Rr_to( &lhs->p_data[i], rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_div_RF_to(carr_t* lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_div_RR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_div_FR_to(fecarr_t* lhs, carr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_div_RR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_div_rF_to(coeff_t lhs, fecarr_t* rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_div_rR_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_div_Fr_to(fecarr_t* lhs, coeff_t rhs, fecarr_t* res){

    uint64_t i;

    // Check first dimensions.
    fecarr_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        carr_div_Rr_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

















// ****************************************************************************************************
carr_t fecarr_integrate(fecarr_t* arr, fednum_t* w){

    carr_t  res = carr_init();

    res = carr_zeros(arr->nrows, arr->ncols);

    fecarr_integrate_to( arr, w, &res );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecarr_integrate_to(fecarr_t* arr, fednum_t* w, carr_t* res){

    uint64_t i = 0;

    // Check dimensions.
    fecarr_dimCheck_FfR_integrate( arr, w, res);

    carr_set_all_r(0.0, res);
    
    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        carr_gem_rR_to( w->p_data[i], &arr->p_data[i], res, res);

    }


}
// ----------------------------------------------------------------------------------------------------




