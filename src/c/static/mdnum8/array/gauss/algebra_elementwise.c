
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
femdarr8_t femdarr8_neg(femdarr8_t* arr){

    femdarr8_t res;

    res = femdarr8_createEmpty(arr->nrows, arr->ncols, arr->nip);

    femdarr8_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_neg_to(femdarr8_t* arr, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        mdarr8_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
femdarr8_t femdarr8_sum_FF(femdarr8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sum_fF(femdnum8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sum_OF(mdarr8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sum_RF(darr_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sum_oF(mdnum8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sum_rF(coeff_t lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sum_FF_to(femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sum_fF_to(femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sum_OF_to(mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sum_RF_to(darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sum_oF_to(mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sum_rF_to(coeff_t lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
femdarr8_t femdarr8_sub_FF(femdarr8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sub_fF(femdnum8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sub_Ff(femdarr8_t* lhs, femdnum8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr8_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sub_OF(mdarr8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sub_FO(femdarr8_t* lhs, mdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr8_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sub_RF(darr_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sub_FR(femdarr8_t* lhs, darr_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr8_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sub_oF(mdnum8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sub_Fo(femdarr8_t* lhs, mdnum8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr8_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sub_rF(coeff_t lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_sub_Fr(femdarr8_t* lhs, coeff_t rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr8_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sub_FF_to(femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sub_fF_to(femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sub_Ff_to(femdarr8_t* lhs, femdnum8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sub_OF_to(mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sub_FO_to(femdarr8_t* lhs, mdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sub_RF_to(darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sub_FR_to(femdarr8_t* lhs, darr_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sub_oF_to(mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sub_Fo_to(femdarr8_t* lhs, mdnum8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sub_rF_to(coeff_t lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_sub_Fr_to(femdarr8_t* lhs, coeff_t rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
femdarr8_t femdarr8_mul_FF(femdarr8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_mul_fF(femdnum8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_mul_OF(mdarr8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_mul_RF(darr_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_mul_oF(mdnum8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_mul_rF(coeff_t lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_mul_FF_to(femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_mul_fF_to(femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_mul_OF_to(mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_mul_RF_to(darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_mul_oF_to(mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_mul_rF_to(coeff_t lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
femdarr8_t femdarr8_div_FF(femdarr8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_div_Ff(femdarr8_t* lhs, femdnum8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr8_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_div_fF(femdnum8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_div_OF(mdarr8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_div_FO(femdarr8_t* lhs, mdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr8_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_div_RF(darr_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_div_FR(femdarr8_t* lhs, darr_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr8_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_div_oF(mdnum8_t* lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_div_Fo(femdarr8_t* lhs, mdnum8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr8_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_div_rF(coeff_t lhs, femdarr8_t* rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr8_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr8_t femdarr8_div_Fr(femdarr8_t* lhs, coeff_t rhs){

    femdarr8_t res;

    res = femdarr8_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr8_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_div_FF_to(femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_div_fF_to(femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_div_Ff_to(femdarr8_t* lhs, femdnum8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_div_OF_to(mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_div_FO_to(femdarr8_t* lhs, mdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_div_RF_to(darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_div_FR_to(femdarr8_t* lhs, darr_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_div_oF_to(mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_div_Fo_to(femdarr8_t* lhs, mdnum8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_div_rF_to(coeff_t lhs, femdarr8_t* rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_div_Fr_to(femdarr8_t* lhs, coeff_t rhs, femdarr8_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr8_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr8_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t femdarr8_integrate(femdarr8_t* arr, femdnum8_t* w){

    mdarr8_t  res = mdarr8_init();

    res = mdarr8_zeros(arr->nrows, arr->ncols);

    femdarr8_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr8_integrate_to(femdarr8_t* arr, femdnum8_t* w, mdarr8_t* res){

    uint64_t i = 0;

    // Check dimensions.
    femdarr8_dimCheck_FfO_integrate( arr, w, res);

    mdarr8_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        mdarr8_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

