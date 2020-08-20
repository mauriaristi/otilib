
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
femdarr5_t femdarr5_neg(femdarr5_t* arr){

    femdarr5_t res;

    res = femdarr5_createEmpty(arr->nrows, arr->ncols, arr->nip);

    femdarr5_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_neg_to(femdarr5_t* arr, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        mdarr5_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
femdarr5_t femdarr5_sum_FF(femdarr5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sum_fF(femdnum5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sum_OF(mdarr5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sum_RF(darr_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sum_oF(mdnum5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sum_rF(coeff_t lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sum_FF_to(femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sum_fF_to(femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sum_OF_to(mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sum_RF_to(darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sum_oF_to(mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sum_rF_to(coeff_t lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
femdarr5_t femdarr5_sub_FF(femdarr5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sub_fF(femdnum5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sub_Ff(femdarr5_t* lhs, femdnum5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr5_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sub_OF(mdarr5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sub_FO(femdarr5_t* lhs, mdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr5_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sub_RF(darr_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sub_FR(femdarr5_t* lhs, darr_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr5_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sub_oF(mdnum5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sub_Fo(femdarr5_t* lhs, mdnum5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr5_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sub_rF(coeff_t lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_sub_Fr(femdarr5_t* lhs, coeff_t rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr5_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sub_FF_to(femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sub_fF_to(femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sub_Ff_to(femdarr5_t* lhs, femdnum5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sub_OF_to(mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sub_FO_to(femdarr5_t* lhs, mdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sub_RF_to(darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sub_FR_to(femdarr5_t* lhs, darr_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sub_oF_to(mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sub_Fo_to(femdarr5_t* lhs, mdnum5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sub_rF_to(coeff_t lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_sub_Fr_to(femdarr5_t* lhs, coeff_t rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
femdarr5_t femdarr5_mul_FF(femdarr5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_mul_fF(femdnum5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_mul_OF(mdarr5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_mul_RF(darr_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_mul_oF(mdnum5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_mul_rF(coeff_t lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_mul_FF_to(femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_mul_fF_to(femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_mul_OF_to(mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_mul_RF_to(darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_mul_oF_to(mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_mul_rF_to(coeff_t lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
femdarr5_t femdarr5_div_FF(femdarr5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_div_Ff(femdarr5_t* lhs, femdnum5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr5_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_div_fF(femdnum5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_div_OF(mdarr5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_div_FO(femdarr5_t* lhs, mdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr5_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_div_RF(darr_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_div_FR(femdarr5_t* lhs, darr_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr5_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_div_oF(mdnum5_t* lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_div_Fo(femdarr5_t* lhs, mdnum5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr5_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_div_rF(coeff_t lhs, femdarr5_t* rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr5_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr5_t femdarr5_div_Fr(femdarr5_t* lhs, coeff_t rhs){

    femdarr5_t res;

    res = femdarr5_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr5_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_div_FF_to(femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_div_fF_to(femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_div_Ff_to(femdarr5_t* lhs, femdnum5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_div_OF_to(mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_div_FO_to(femdarr5_t* lhs, mdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_div_RF_to(darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_div_FR_to(femdarr5_t* lhs, darr_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_div_oF_to(mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_div_Fo_to(femdarr5_t* lhs, mdnum5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_div_rF_to(coeff_t lhs, femdarr5_t* rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_div_Fr_to(femdarr5_t* lhs, coeff_t rhs, femdarr5_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr5_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr5_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t femdarr5_integrate(femdarr5_t* arr, femdnum5_t* w){

    mdarr5_t  res = mdarr5_init();

    res = mdarr5_zeros(arr->nrows, arr->ncols);

    femdarr5_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr5_integrate_to(femdarr5_t* arr, femdnum5_t* w, mdarr5_t* res){

    uint64_t i = 0;

    // Check dimensions.
    femdarr5_dimCheck_FfO_integrate( arr, w, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        mdarr5_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }

}
// ----------------------------------------------------------------------------------------------------

