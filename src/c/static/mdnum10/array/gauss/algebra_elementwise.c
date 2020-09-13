
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
femdarr10_t femdarr10_neg(femdarr10_t* arr){

    femdarr10_t res;

    res = femdarr10_createEmpty(arr->nrows, arr->ncols, arr->nip);

    femdarr10_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_neg_to(femdarr10_t* arr, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        mdarr10_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
femdarr10_t femdarr10_sum_FF(femdarr10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sum_fF(femdnum10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sum_OF(mdarr10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sum_RF(darr_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sum_oF(mdnum10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sum_rF(coeff_t lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sum_FF_to(femdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sum_fF_to(femdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sum_OF_to(mdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sum_RF_to(darr_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sum_oF_to(mdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sum_rF_to(coeff_t lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
femdarr10_t femdarr10_sub_FF(femdarr10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sub_fF(femdnum10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sub_Ff(femdarr10_t* lhs, femdnum10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr10_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sub_OF(mdarr10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sub_FO(femdarr10_t* lhs, mdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr10_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sub_RF(darr_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sub_FR(femdarr10_t* lhs, darr_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr10_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sub_oF(mdnum10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sub_Fo(femdarr10_t* lhs, mdnum10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr10_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sub_rF(coeff_t lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_sub_Fr(femdarr10_t* lhs, coeff_t rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr10_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sub_FF_to(femdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sub_fF_to(femdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sub_Ff_to(femdarr10_t* lhs, femdnum10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sub_OF_to(mdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sub_FO_to(femdarr10_t* lhs, mdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sub_RF_to(darr_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sub_FR_to(femdarr10_t* lhs, darr_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sub_oF_to(mdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sub_Fo_to(femdarr10_t* lhs, mdnum10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sub_rF_to(coeff_t lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_sub_Fr_to(femdarr10_t* lhs, coeff_t rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
femdarr10_t femdarr10_mul_FF(femdarr10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_mul_fF(femdnum10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_mul_OF(mdarr10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_mul_RF(darr_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_mul_oF(mdnum10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_mul_rF(coeff_t lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_mul_FF_to(femdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_mul_fF_to(femdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_mul_OF_to(mdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_mul_RF_to(darr_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_mul_oF_to(mdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_mul_rF_to(coeff_t lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
femdarr10_t femdarr10_div_FF(femdarr10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_div_Ff(femdarr10_t* lhs, femdnum10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr10_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_div_fF(femdnum10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_div_OF(mdarr10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_div_FO(femdarr10_t* lhs, mdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr10_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_div_RF(darr_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_div_FR(femdarr10_t* lhs, darr_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr10_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_div_oF(mdnum10_t* lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_div_Fo(femdarr10_t* lhs, mdnum10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr10_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_div_rF(coeff_t lhs, femdarr10_t* rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr10_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr10_t femdarr10_div_Fr(femdarr10_t* lhs, coeff_t rhs){

    femdarr10_t res;

    res = femdarr10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr10_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_div_FF_to(femdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_div_fF_to(femdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_div_Ff_to(femdarr10_t* lhs, femdnum10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_div_OF_to(mdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_div_FO_to(femdarr10_t* lhs, mdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_div_RF_to(darr_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_div_FR_to(femdarr10_t* lhs, darr_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_div_oF_to(mdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_div_Fo_to(femdarr10_t* lhs, mdnum10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_div_rF_to(coeff_t lhs, femdarr10_t* rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_div_Fr_to(femdarr10_t* lhs, coeff_t rhs, femdarr10_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr10_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr10_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t femdarr10_integrate(femdarr10_t* arr, femdnum10_t* w){

    mdarr10_t  res = mdarr10_init();

    res = mdarr10_zeros(arr->nrows, arr->ncols);

    femdarr10_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr10_integrate_to(femdarr10_t* arr, femdnum10_t* w, mdarr10_t* res){

    uint64_t i = 0;

    // Check dimensions.
    femdarr10_dimCheck_FfO_integrate( arr, w, res);

    mdarr10_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        mdarr10_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

