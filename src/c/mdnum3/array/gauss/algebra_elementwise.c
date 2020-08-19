
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
femdarr3_t femdarr3_neg(femdarr3_t* arr){

    femdarr3_t res;

    res = femdarr3_createEmpty(arr->nrows, arr->ncols, arr->nip);

    femdarr3_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_neg_to(femdarr3_t* arr, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        mdarr3_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
femdarr3_t femdarr3_sum_FF(femdarr3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sum_fF(femdnum3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sum_OF(mdarr3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sum_RF(darr_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sum_oF(mdnum3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sum_rF(coeff_t lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sum_FF_to(femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sum_fF_to(femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sum_OF_to(mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sum_RF_to(darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sum_oF_to(mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sum_rF_to(coeff_t lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
femdarr3_t femdarr3_sub_FF(femdarr3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sub_fF(femdnum3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sub_Ff(femdarr3_t* lhs, femdnum3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr3_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sub_OF(mdarr3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sub_FO(femdarr3_t* lhs, mdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr3_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sub_RF(darr_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sub_FR(femdarr3_t* lhs, darr_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr3_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sub_oF(mdnum3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sub_Fo(femdarr3_t* lhs, mdnum3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr3_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sub_rF(coeff_t lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_sub_Fr(femdarr3_t* lhs, coeff_t rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr3_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sub_FF_to(femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sub_fF_to(femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sub_Ff_to(femdarr3_t* lhs, femdnum3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sub_OF_to(mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sub_FO_to(femdarr3_t* lhs, mdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sub_RF_to(darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sub_FR_to(femdarr3_t* lhs, darr_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sub_oF_to(mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sub_Fo_to(femdarr3_t* lhs, mdnum3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sub_rF_to(coeff_t lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_sub_Fr_to(femdarr3_t* lhs, coeff_t rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
femdarr3_t femdarr3_mul_FF(femdarr3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_mul_fF(femdnum3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_mul_OF(mdarr3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_mul_RF(darr_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_mul_oF(mdnum3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_mul_rF(coeff_t lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_mul_FF_to(femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_mul_fF_to(femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_mul_OF_to(mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_mul_RF_to(darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_mul_oF_to(mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_mul_rF_to(coeff_t lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
femdarr3_t femdarr3_div_FF(femdarr3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_div_Ff(femdarr3_t* lhs, femdnum3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr3_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_div_fF(femdnum3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_div_OF(mdarr3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_div_FO(femdarr3_t* lhs, mdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr3_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_div_RF(darr_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_div_FR(femdarr3_t* lhs, darr_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr3_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_div_oF(mdnum3_t* lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_div_Fo(femdarr3_t* lhs, mdnum3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr3_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_div_rF(coeff_t lhs, femdarr3_t* rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    femdarr3_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
femdarr3_t femdarr3_div_Fr(femdarr3_t* lhs, coeff_t rhs){

    femdarr3_t res;

    res = femdarr3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    femdarr3_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_div_FF_to(femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_div_fF_to(femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_div_Ff_to(femdarr3_t* lhs, femdnum3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_div_OF_to(mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_div_FO_to(femdarr3_t* lhs, mdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_div_RF_to(darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_div_FR_to(femdarr3_t* lhs, darr_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_div_oF_to(mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_div_Fo_to(femdarr3_t* lhs, mdnum3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_div_rF_to(coeff_t lhs, femdarr3_t* rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_div_Fr_to(femdarr3_t* lhs, coeff_t rhs, femdarr3_t* res){

    uint64_t i;

    // Check first dimensions.
    femdarr3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        mdarr3_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t femdarr3_integrate(femdarr3_t* arr, femdnum3_t* w){

    mdarr3_t  res = mdarr3_init();

    res = mdarr3_zeros(arr->nrows, arr->ncols);

    femdarr3_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr3_integrate_to(femdarr3_t* arr, femdnum3_t* w, mdarr3_t* res){

    uint64_t i = 0;

    // Check dimensions.
    femdarr3_dimCheck_FfO_integrate( arr, w, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        mdarr3_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }

}
// ----------------------------------------------------------------------------------------------------

