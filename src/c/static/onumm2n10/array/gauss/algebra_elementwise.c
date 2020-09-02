
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_neg(feoarrm2n10_t* arr){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(arr->nrows, arr->ncols, arr->nip);

    feoarrm2n10_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_neg_to(feoarrm2n10_t* arr, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        oarrm2n10_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sum_FF(feoarrm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sum_fF(feonumm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sum_OF(oarrm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sum_RF(darr_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sum_oF(onumm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sum_rF(coeff_t lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sum_FF_to(feoarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sum_fF_to(feonumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sum_OF_to(oarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sum_RF_to(darr_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sum_oF_to(onumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sum_rF_to(coeff_t lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sub_FF(feoarrm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sub_fF(feonumm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sub_Ff(feoarrm2n10_t* lhs, feonumm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm2n10_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sub_OF(oarrm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sub_FO(feoarrm2n10_t* lhs, oarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm2n10_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sub_RF(darr_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sub_FR(feoarrm2n10_t* lhs, darr_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm2n10_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sub_oF(onumm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sub_Fo(feoarrm2n10_t* lhs, onumm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm2n10_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sub_rF(coeff_t lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_sub_Fr(feoarrm2n10_t* lhs, coeff_t rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm2n10_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sub_FF_to(feoarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sub_fF_to(feonumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sub_Ff_to(feoarrm2n10_t* lhs, feonumm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sub_OF_to(oarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sub_FO_to(feoarrm2n10_t* lhs, oarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sub_RF_to(darr_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sub_FR_to(feoarrm2n10_t* lhs, darr_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sub_oF_to(onumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sub_Fo_to(feoarrm2n10_t* lhs, onumm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sub_rF_to(coeff_t lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_sub_Fr_to(feoarrm2n10_t* lhs, coeff_t rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_mul_FF(feoarrm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_mul_fF(feonumm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_mul_OF(oarrm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_mul_RF(darr_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_mul_oF(onumm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_mul_rF(coeff_t lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_mul_FF_to(feoarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_mul_fF_to(feonumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_mul_OF_to(oarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_mul_RF_to(darr_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_mul_oF_to(onumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_mul_rF_to(coeff_t lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_div_FF(feoarrm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_div_Ff(feoarrm2n10_t* lhs, feonumm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm2n10_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_div_fF(feonumm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_div_OF(oarrm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_div_FO(feoarrm2n10_t* lhs, oarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm2n10_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_div_RF(darr_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_div_FR(feoarrm2n10_t* lhs, darr_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm2n10_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_div_oF(onumm2n10_t* lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_div_Fo(feoarrm2n10_t* lhs, onumm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm2n10_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_div_rF(coeff_t lhs, feoarrm2n10_t* rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm2n10_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm2n10_t feoarrm2n10_div_Fr(feoarrm2n10_t* lhs, coeff_t rhs){

    feoarrm2n10_t res;

    res = feoarrm2n10_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm2n10_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_div_FF_to(feoarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_div_fF_to(feonumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_div_Ff_to(feoarrm2n10_t* lhs, feonumm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_div_OF_to(oarrm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_div_FO_to(feoarrm2n10_t* lhs, oarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_div_RF_to(darr_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_div_FR_to(feoarrm2n10_t* lhs, darr_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_div_oF_to(onumm2n10_t* lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_div_Fo_to(feoarrm2n10_t* lhs, onumm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_div_rF_to(coeff_t lhs, feoarrm2n10_t* rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_div_Fr_to(feoarrm2n10_t* lhs, coeff_t rhs, feoarrm2n10_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm2n10_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm2n10_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm2n10_t feoarrm2n10_integrate(feoarrm2n10_t* arr, feonumm2n10_t* w){

    oarrm2n10_t  res = oarrm2n10_init();

    res = oarrm2n10_zeros(arr->nrows, arr->ncols);

    feoarrm2n10_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm2n10_integrate_to(feoarrm2n10_t* arr, feonumm2n10_t* w, oarrm2n10_t* res){

    uint64_t i = 0;

    // Check dimensions.
    feoarrm2n10_dimCheck_FfO_integrate( arr, w, res);

    oarrm2n10_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        oarrm2n10_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

