
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
femdarr6_t femdarr6_neg(femdarr6_t* arr){

    femdarr6_t res;

    res = femdarr6_createEmpty(arr->nrows, arr->ncols, arr->nip);

    femdarr6_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_neg_to(femdarr6_t* arr, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        mdarr6_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
femdarr6_t femdarr6_sum_FF(femdarr6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sum_fF(femdnum6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sum_OF(mdarr6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sum_RF(darr_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sum_oF(mdnum6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sum_rF(coeff_t lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sum_FF_to(femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sum_fF_to(femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sum_OF_to(mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sum_RF_to(darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sum_oF_to(mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sum_rF_to(coeff_t lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
femdarr6_t femdarr6_sub_FF(femdarr6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sub_fF(femdnum6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sub_Ff(femdarr6_t* lhs, femdnum6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr6_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sub_OF(mdarr6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sub_FO(femdarr6_t* lhs, mdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr6_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sub_RF(darr_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sub_FR(femdarr6_t* lhs, darr_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr6_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sub_oF(mdnum6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sub_Fo(femdarr6_t* lhs, mdnum6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr6_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sub_rF(coeff_t lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_sub_Fr(femdarr6_t* lhs, coeff_t rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr6_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sub_FF_to(femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sub_fF_to(femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sub_Ff_to(femdarr6_t* lhs, femdnum6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sub_OF_to(mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sub_FO_to(femdarr6_t* lhs, mdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sub_RF_to(darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sub_FR_to(femdarr6_t* lhs, darr_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sub_oF_to(mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sub_Fo_to(femdarr6_t* lhs, mdnum6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sub_rF_to(coeff_t lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_sub_Fr_to(femdarr6_t* lhs, coeff_t rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
femdarr6_t femdarr6_mul_FF(femdarr6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_mul_fF(femdnum6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_mul_OF(mdarr6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_mul_RF(darr_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_mul_oF(mdnum6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_mul_rF(coeff_t lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_mul_FF_to(femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_mul_fF_to(femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_mul_OF_to(mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_mul_RF_to(darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_mul_oF_to(mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_mul_rF_to(coeff_t lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
femdarr6_t femdarr6_div_FF(femdarr6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_div_Ff(femdarr6_t* lhs, femdnum6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr6_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_div_fF(femdnum6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_div_OF(mdarr6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_div_FO(femdarr6_t* lhs, mdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr6_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_div_RF(darr_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_div_FR(femdarr6_t* lhs, darr_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr6_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_div_oF(mdnum6_t* lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_div_Fo(femdarr6_t* lhs, mdnum6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr6_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_div_rF(coeff_t lhs, femdarr6_t* rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr6_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr6_t femdarr6_div_Fr(femdarr6_t* lhs, coeff_t rhs){

    femdarr6_t res;

    res = femdarr6_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr6_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_div_FF_to(femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_div_fF_to(femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_div_Ff_to(femdarr6_t* lhs, femdnum6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_div_OF_to(mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_div_FO_to(femdarr6_t* lhs, mdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_div_RF_to(darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_div_FR_to(femdarr6_t* lhs, darr_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_div_oF_to(mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_div_Fo_to(femdarr6_t* lhs, mdnum6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_div_rF_to(coeff_t lhs, femdarr6_t* rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_div_Fr_to(femdarr6_t* lhs, coeff_t rhs, femdarr6_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr6_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr6_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t femdarr6_integrate(femdarr6_t* arr, femdnum6_t* w){

    mdarr6_t  res = mdarr6_init();

    res = mdarr6_zeros(arr->nrows, arr->ncols);

    femdarr6_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr6_integrate_to(femdarr6_t* arr, femdnum6_t* w, mdarr6_t* res){

    uint64_t i = 0;

    // Check dimensions.
    femdarr6_dimCheck_FfO_integrate( arr, w, res);

    mdarr6_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        mdarr6_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

