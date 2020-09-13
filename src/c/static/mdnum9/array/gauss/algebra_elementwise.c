
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
femdarr9_t femdarr9_neg(femdarr9_t* arr){

    femdarr9_t res;

    res = femdarr9_createEmpty(arr->nrows, arr->ncols, arr->nip);

    femdarr9_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_neg_to(femdarr9_t* arr, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        mdarr9_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
femdarr9_t femdarr9_sum_FF(femdarr9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sum_fF(femdnum9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sum_OF(mdarr9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sum_RF(darr_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sum_oF(mdnum9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sum_rF(coeff_t lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sum_FF_to(femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sum_fF_to(femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sum_OF_to(mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sum_RF_to(darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sum_oF_to(mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sum_rF_to(coeff_t lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
femdarr9_t femdarr9_sub_FF(femdarr9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sub_fF(femdnum9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sub_Ff(femdarr9_t* lhs, femdnum9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr9_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sub_OF(mdarr9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sub_FO(femdarr9_t* lhs, mdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr9_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sub_RF(darr_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sub_FR(femdarr9_t* lhs, darr_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr9_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sub_oF(mdnum9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sub_Fo(femdarr9_t* lhs, mdnum9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr9_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sub_rF(coeff_t lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_sub_Fr(femdarr9_t* lhs, coeff_t rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr9_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sub_FF_to(femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sub_fF_to(femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sub_Ff_to(femdarr9_t* lhs, femdnum9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sub_OF_to(mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sub_FO_to(femdarr9_t* lhs, mdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sub_RF_to(darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sub_FR_to(femdarr9_t* lhs, darr_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sub_oF_to(mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sub_Fo_to(femdarr9_t* lhs, mdnum9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sub_rF_to(coeff_t lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_sub_Fr_to(femdarr9_t* lhs, coeff_t rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
femdarr9_t femdarr9_mul_FF(femdarr9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_mul_fF(femdnum9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_mul_OF(mdarr9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_mul_RF(darr_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_mul_oF(mdnum9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_mul_rF(coeff_t lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_mul_FF_to(femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_mul_fF_to(femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_mul_OF_to(mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_mul_RF_to(darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_mul_oF_to(mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_mul_rF_to(coeff_t lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
femdarr9_t femdarr9_div_FF(femdarr9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_div_Ff(femdarr9_t* lhs, femdnum9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr9_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_div_fF(femdnum9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_div_OF(mdarr9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_div_FO(femdarr9_t* lhs, mdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr9_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_div_RF(darr_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_div_FR(femdarr9_t* lhs, darr_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr9_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_div_oF(mdnum9_t* lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_div_Fo(femdarr9_t* lhs, mdnum9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr9_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_div_rF(coeff_t lhs, femdarr9_t* rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr9_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr9_t femdarr9_div_Fr(femdarr9_t* lhs, coeff_t rhs){

    femdarr9_t res;

    res = femdarr9_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr9_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_div_FF_to(femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_div_fF_to(femdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_div_Ff_to(femdarr9_t* lhs, femdnum9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_div_OF_to(mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_div_FO_to(femdarr9_t* lhs, mdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_div_RF_to(darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_div_FR_to(femdarr9_t* lhs, darr_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_div_oF_to(mdnum9_t* lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_div_Fo_to(femdarr9_t* lhs, mdnum9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_div_rF_to(coeff_t lhs, femdarr9_t* rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_div_Fr_to(femdarr9_t* lhs, coeff_t rhs, femdarr9_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr9_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr9_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t femdarr9_integrate(femdarr9_t* arr, femdnum9_t* w){

    mdarr9_t  res = mdarr9_init();

    res = mdarr9_zeros(arr->nrows, arr->ncols);

    femdarr9_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr9_integrate_to(femdarr9_t* arr, femdnum9_t* w, mdarr9_t* res){

    uint64_t i = 0;

    // Check dimensions.
    femdarr9_dimCheck_FfO_integrate( arr, w, res);

    mdarr9_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        mdarr9_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

