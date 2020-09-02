
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
femdarr1_t femdarr1_neg(femdarr1_t* arr){

    femdarr1_t res;

    res = femdarr1_createEmpty(arr->nrows, arr->ncols, arr->nip);

    femdarr1_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_neg_to(femdarr1_t* arr, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        mdarr1_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
femdarr1_t femdarr1_sum_FF(femdarr1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sum_fF(femdnum1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sum_OF(mdarr1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sum_RF(darr_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sum_oF(mdnum1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sum_rF(coeff_t lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sum_FF_to(femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sum_fF_to(femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sum_OF_to(mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sum_RF_to(darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sum_oF_to(mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sum_rF_to(coeff_t lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
femdarr1_t femdarr1_sub_FF(femdarr1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sub_fF(femdnum1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sub_Ff(femdarr1_t* lhs, femdnum1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr1_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sub_OF(mdarr1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sub_FO(femdarr1_t* lhs, mdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr1_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sub_RF(darr_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sub_FR(femdarr1_t* lhs, darr_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr1_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sub_oF(mdnum1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sub_Fo(femdarr1_t* lhs, mdnum1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr1_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sub_rF(coeff_t lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_sub_Fr(femdarr1_t* lhs, coeff_t rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr1_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sub_FF_to(femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sub_fF_to(femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sub_Ff_to(femdarr1_t* lhs, femdnum1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sub_OF_to(mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sub_FO_to(femdarr1_t* lhs, mdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sub_RF_to(darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sub_FR_to(femdarr1_t* lhs, darr_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sub_oF_to(mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sub_Fo_to(femdarr1_t* lhs, mdnum1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sub_rF_to(coeff_t lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_sub_Fr_to(femdarr1_t* lhs, coeff_t rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
femdarr1_t femdarr1_mul_FF(femdarr1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_mul_fF(femdnum1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_mul_OF(mdarr1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_mul_RF(darr_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_mul_oF(mdnum1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_mul_rF(coeff_t lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_mul_FF_to(femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_mul_fF_to(femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_mul_OF_to(mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_mul_RF_to(darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_mul_oF_to(mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_mul_rF_to(coeff_t lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
femdarr1_t femdarr1_div_FF(femdarr1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_div_Ff(femdarr1_t* lhs, femdnum1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr1_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_div_fF(femdnum1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_div_OF(mdarr1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_div_FO(femdarr1_t* lhs, mdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr1_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_div_RF(darr_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_div_FR(femdarr1_t* lhs, darr_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr1_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_div_oF(mdnum1_t* lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_div_Fo(femdarr1_t* lhs, mdnum1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr1_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_div_rF(coeff_t lhs, femdarr1_t* rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr1_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr1_t femdarr1_div_Fr(femdarr1_t* lhs, coeff_t rhs){

    femdarr1_t res;

    res = femdarr1_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr1_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_div_FF_to(femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_div_fF_to(femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_div_Ff_to(femdarr1_t* lhs, femdnum1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_div_OF_to(mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_div_FO_to(femdarr1_t* lhs, mdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_div_RF_to(darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_div_FR_to(femdarr1_t* lhs, darr_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_div_oF_to(mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_div_Fo_to(femdarr1_t* lhs, mdnum1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_div_rF_to(coeff_t lhs, femdarr1_t* rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_div_Fr_to(femdarr1_t* lhs, coeff_t rhs, femdarr1_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr1_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr1_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t femdarr1_integrate(femdarr1_t* arr, femdnum1_t* w){

    mdarr1_t  res = mdarr1_init();

    res = mdarr1_zeros(arr->nrows, arr->ncols);

    femdarr1_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_integrate_to(femdarr1_t* arr, femdnum1_t* w, mdarr1_t* res){

    uint64_t i = 0;

    // Check dimensions.
    femdarr1_dimCheck_FfO_integrate( arr, w, res);

    mdarr1_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        mdarr1_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

