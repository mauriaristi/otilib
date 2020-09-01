
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
femdarr2_t femdarr2_neg(femdarr2_t* arr){

    femdarr2_t res;

    res = femdarr2_createEmpty(arr->nrows, arr->ncols, arr->nip);

    femdarr2_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_neg_to(femdarr2_t* arr, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        mdarr2_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
femdarr2_t femdarr2_sum_FF(femdarr2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sum_fF(femdnum2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sum_OF(mdarr2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sum_RF(darr_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sum_oF(mdnum2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sum_rF(coeff_t lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sum_FF_to(femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sum_fF_to(femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sum_OF_to(mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sum_RF_to(darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sum_oF_to(mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sum_rF_to(coeff_t lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
femdarr2_t femdarr2_sub_FF(femdarr2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sub_fF(femdnum2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sub_Ff(femdarr2_t* lhs, femdnum2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr2_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sub_OF(mdarr2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sub_FO(femdarr2_t* lhs, mdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr2_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sub_RF(darr_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sub_FR(femdarr2_t* lhs, darr_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr2_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sub_oF(mdnum2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sub_Fo(femdarr2_t* lhs, mdnum2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr2_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sub_rF(coeff_t lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_sub_Fr(femdarr2_t* lhs, coeff_t rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr2_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sub_FF_to(femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sub_fF_to(femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sub_Ff_to(femdarr2_t* lhs, femdnum2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sub_OF_to(mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sub_FO_to(femdarr2_t* lhs, mdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sub_RF_to(darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sub_FR_to(femdarr2_t* lhs, darr_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sub_oF_to(mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sub_Fo_to(femdarr2_t* lhs, mdnum2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sub_rF_to(coeff_t lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_sub_Fr_to(femdarr2_t* lhs, coeff_t rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
femdarr2_t femdarr2_mul_FF(femdarr2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_mul_fF(femdnum2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_mul_OF(mdarr2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_mul_RF(darr_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_mul_oF(mdnum2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_mul_rF(coeff_t lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_mul_FF_to(femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_mul_fF_to(femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_mul_OF_to(mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_mul_RF_to(darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_mul_oF_to(mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_mul_rF_to(coeff_t lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
femdarr2_t femdarr2_div_FF(femdarr2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_div_Ff(femdarr2_t* lhs, femdnum2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr2_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_div_fF(femdnum2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_div_OF(mdarr2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_div_FO(femdarr2_t* lhs, mdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr2_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_div_RF(darr_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_div_FR(femdarr2_t* lhs, darr_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr2_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_div_oF(mdnum2_t* lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_div_Fo(femdarr2_t* lhs, mdnum2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr2_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_div_rF(coeff_t lhs, femdarr2_t* rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr2_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr2_t femdarr2_div_Fr(femdarr2_t* lhs, coeff_t rhs){

    femdarr2_t res;

    res = femdarr2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr2_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_div_FF_to(femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_div_fF_to(femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_div_Ff_to(femdarr2_t* lhs, femdnum2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_div_OF_to(mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_div_FO_to(femdarr2_t* lhs, mdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_div_RF_to(darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_div_FR_to(femdarr2_t* lhs, darr_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_div_oF_to(mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_div_Fo_to(femdarr2_t* lhs, mdnum2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_div_rF_to(coeff_t lhs, femdarr2_t* rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_div_Fr_to(femdarr2_t* lhs, coeff_t rhs, femdarr2_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr2_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t femdarr2_integrate(femdarr2_t* arr, femdnum2_t* w){

    mdarr2_t  res = mdarr2_init();

    res = mdarr2_zeros(arr->nrows, arr->ncols);

    femdarr2_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr2_integrate_to(femdarr2_t* arr, femdnum2_t* w, mdarr2_t* res){

    uint64_t i = 0;

    // Check dimensions.
    femdarr2_dimCheck_FfO_integrate( arr, w, res);

    mdarr2_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        mdarr2_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

