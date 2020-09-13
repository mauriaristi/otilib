
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
femdarr7_t femdarr7_neg(femdarr7_t* arr){

    femdarr7_t res;

    res = femdarr7_createEmpty(arr->nrows, arr->ncols, arr->nip);

    femdarr7_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_neg_to(femdarr7_t* arr, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        mdarr7_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
femdarr7_t femdarr7_sum_FF(femdarr7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sum_fF(femdnum7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sum_OF(mdarr7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sum_RF(darr_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sum_oF(mdnum7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sum_rF(coeff_t lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sum_FF_to(femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sum_fF_to(femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sum_OF_to(mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sum_RF_to(darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sum_oF_to(mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sum_rF_to(coeff_t lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
femdarr7_t femdarr7_sub_FF(femdarr7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sub_fF(femdnum7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sub_Ff(femdarr7_t* lhs, femdnum7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr7_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sub_OF(mdarr7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sub_FO(femdarr7_t* lhs, mdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr7_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sub_RF(darr_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sub_FR(femdarr7_t* lhs, darr_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr7_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sub_oF(mdnum7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sub_Fo(femdarr7_t* lhs, mdnum7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr7_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sub_rF(coeff_t lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_sub_Fr(femdarr7_t* lhs, coeff_t rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr7_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sub_FF_to(femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sub_fF_to(femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sub_Ff_to(femdarr7_t* lhs, femdnum7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sub_OF_to(mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sub_FO_to(femdarr7_t* lhs, mdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sub_RF_to(darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sub_FR_to(femdarr7_t* lhs, darr_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sub_oF_to(mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sub_Fo_to(femdarr7_t* lhs, mdnum7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sub_rF_to(coeff_t lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_sub_Fr_to(femdarr7_t* lhs, coeff_t rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
femdarr7_t femdarr7_mul_FF(femdarr7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_mul_fF(femdnum7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_mul_OF(mdarr7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_mul_RF(darr_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_mul_oF(mdnum7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_mul_rF(coeff_t lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_mul_FF_to(femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_mul_fF_to(femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_mul_OF_to(mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_mul_RF_to(darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_mul_oF_to(mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_mul_rF_to(coeff_t lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
femdarr7_t femdarr7_div_FF(femdarr7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_div_Ff(femdarr7_t* lhs, femdnum7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr7_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_div_fF(femdnum7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_div_OF(mdarr7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_div_FO(femdarr7_t* lhs, mdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr7_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_div_RF(darr_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_div_FR(femdarr7_t* lhs, darr_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr7_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_div_oF(mdnum7_t* lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_div_Fo(femdarr7_t* lhs, mdnum7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr7_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_div_rF(coeff_t lhs, femdarr7_t* rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr7_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr7_t femdarr7_div_Fr(femdarr7_t* lhs, coeff_t rhs){

    femdarr7_t res;

    res = femdarr7_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr7_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_div_FF_to(femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_div_fF_to(femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_div_Ff_to(femdarr7_t* lhs, femdnum7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_div_OF_to(mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_div_FO_to(femdarr7_t* lhs, mdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_div_RF_to(darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_div_FR_to(femdarr7_t* lhs, darr_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_div_oF_to(mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_div_Fo_to(femdarr7_t* lhs, mdnum7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_div_rF_to(coeff_t lhs, femdarr7_t* rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_div_Fr_to(femdarr7_t* lhs, coeff_t rhs, femdarr7_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr7_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr7_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t femdarr7_integrate(femdarr7_t* arr, femdnum7_t* w){

    mdarr7_t  res = mdarr7_init();

    res = mdarr7_zeros(arr->nrows, arr->ncols);

    femdarr7_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr7_integrate_to(femdarr7_t* arr, femdnum7_t* w, mdarr7_t* res){

    uint64_t i = 0;

    // Check dimensions.
    femdarr7_dimCheck_FfO_integrate( arr, w, res);

    mdarr7_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        mdarr7_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

