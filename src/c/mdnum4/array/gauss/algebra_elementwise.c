
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
femdarr4_t femdarr4_neg(femdarr4_t* arr){

    femdarr4_t res;

    res = femdarr4_createEmpty(arr->nrows, arr->ncols, arr->nip);

    femdarr4_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_neg_to(femdarr4_t* arr, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        mdarr4_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
femdarr4_t femdarr4_sum_FF(femdarr4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sum_fF(femdnum4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sum_OF(mdarr4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sum_RF(darr_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sum_oF(mdnum4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sum_rF(coeff_t lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sum_FF_to(femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sum_fF_to(femdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sum_OF_to(mdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sum_RF_to(darr_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sum_oF_to(mdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sum_rF_to(coeff_t lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
femdarr4_t femdarr4_sub_FF(femdarr4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sub_fF(femdnum4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sub_Ff(femdarr4_t* lhs, femdnum4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr4_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sub_OF(mdarr4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sub_FO(femdarr4_t* lhs, mdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr4_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sub_RF(darr_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sub_FR(femdarr4_t* lhs, darr_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr4_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sub_oF(mdnum4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sub_Fo(femdarr4_t* lhs, mdnum4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr4_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sub_rF(coeff_t lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_sub_Fr(femdarr4_t* lhs, coeff_t rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr4_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sub_FF_to(femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sub_fF_to(femdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sub_Ff_to(femdarr4_t* lhs, femdnum4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sub_OF_to(mdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sub_FO_to(femdarr4_t* lhs, mdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sub_RF_to(darr_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sub_FR_to(femdarr4_t* lhs, darr_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sub_oF_to(mdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sub_Fo_to(femdarr4_t* lhs, mdnum4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sub_rF_to(coeff_t lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_sub_Fr_to(femdarr4_t* lhs, coeff_t rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
femdarr4_t femdarr4_mul_FF(femdarr4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_mul_fF(femdnum4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_mul_OF(mdarr4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_mul_RF(darr_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_mul_oF(mdnum4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_mul_rF(coeff_t lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_mul_FF_to(femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_mul_fF_to(femdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_mul_OF_to(mdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_mul_RF_to(darr_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_mul_oF_to(mdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_mul_rF_to(coeff_t lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
femdarr4_t femdarr4_div_FF(femdarr4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_div_Ff(femdarr4_t* lhs, femdnum4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr4_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_div_fF(femdnum4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_div_OF(mdarr4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_div_FO(femdarr4_t* lhs, mdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr4_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_div_RF(darr_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_div_FR(femdarr4_t* lhs, darr_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr4_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_div_oF(mdnum4_t* lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_div_Fo(femdarr4_t* lhs, mdnum4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr4_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_div_rF(coeff_t lhs, femdarr4_t* rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr4_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr4_t femdarr4_div_Fr(femdarr4_t* lhs, coeff_t rhs){

    femdarr4_t res;

    res = femdarr4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr4_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_div_FF_to(femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_div_fF_to(femdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_div_Ff_to(femdarr4_t* lhs, femdnum4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_div_OF_to(mdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_div_FO_to(femdarr4_t* lhs, mdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_div_RF_to(darr_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_div_FR_to(femdarr4_t* lhs, darr_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_div_oF_to(mdnum4_t* lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_div_Fo_to(femdarr4_t* lhs, mdnum4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_div_rF_to(coeff_t lhs, femdarr4_t* rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_div_Fr_to(femdarr4_t* lhs, coeff_t rhs, femdarr4_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr4_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t femdarr4_integrate(femdarr4_t* arr, femdnum4_t* w){

    mdarr4_t  res = mdarr4_init();

    res = mdarr4_zeros(arr->nrows, arr->ncols);

    femdarr4_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr4_integrate_to(femdarr4_t* arr, femdnum4_t* w, mdarr4_t* res){

    uint64_t i = 0;

    // Check dimensions.
    femdarr4_dimCheck_FfO_integrate( arr, w, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        mdarr4_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }

}
// ----------------------------------------------------------------------------------------------------

