
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_neg(feoarrm0n0_t* arr){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(arr->nrows, arr->ncols, arr->nip);

    feoarrm0n0_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_neg_to(feoarrm0n0_t* arr, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        oarrm0n0_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sum_FF(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sum_fF(feonumm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sum_OF(oarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sum_RF(darr_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sum_oF(onumm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sum_rF(coeff_t lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sum_FF_to(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sum_fF_to(feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sum_OF_to(oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sum_RF_to(darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sum_oF_to(onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sum_rF_to(coeff_t lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sub_FF(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sub_fF(feonumm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sub_Ff(feoarrm0n0_t* lhs, feonumm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm0n0_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sub_OF(oarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sub_FO(feoarrm0n0_t* lhs, oarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm0n0_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sub_RF(darr_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sub_FR(feoarrm0n0_t* lhs, darr_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm0n0_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sub_oF(onumm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sub_Fo(feoarrm0n0_t* lhs, onumm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm0n0_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sub_rF(coeff_t lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_sub_Fr(feoarrm0n0_t* lhs, coeff_t rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm0n0_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sub_FF_to(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sub_fF_to(feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sub_Ff_to(feoarrm0n0_t* lhs, feonumm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sub_OF_to(oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sub_FO_to(feoarrm0n0_t* lhs, oarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sub_RF_to(darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sub_FR_to(feoarrm0n0_t* lhs, darr_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sub_oF_to(onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sub_Fo_to(feoarrm0n0_t* lhs, onumm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sub_rF_to(coeff_t lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_sub_Fr_to(feoarrm0n0_t* lhs, coeff_t rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_mul_FF(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_mul_fF(feonumm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_mul_OF(oarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_mul_RF(darr_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_mul_oF(onumm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_mul_rF(coeff_t lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_mul_FF_to(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_mul_fF_to(feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_mul_OF_to(oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_mul_RF_to(darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_mul_oF_to(onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_mul_rF_to(coeff_t lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_div_FF(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_div_Ff(feoarrm0n0_t* lhs, feonumm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm0n0_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_div_fF(feonumm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_div_OF(oarrm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_div_FO(feoarrm0n0_t* lhs, oarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm0n0_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_div_RF(darr_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_div_FR(feoarrm0n0_t* lhs, darr_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm0n0_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_div_oF(onumm0n0_t* lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_div_Fo(feoarrm0n0_t* lhs, onumm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm0n0_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_div_rF(coeff_t lhs, feoarrm0n0_t* rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm0n0_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm0n0_t feoarrm0n0_div_Fr(feoarrm0n0_t* lhs, coeff_t rhs){

    feoarrm0n0_t res;

    res = feoarrm0n0_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm0n0_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_div_FF_to(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_div_fF_to(feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_div_Ff_to(feoarrm0n0_t* lhs, feonumm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_div_OF_to(oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_div_FO_to(feoarrm0n0_t* lhs, oarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_div_RF_to(darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_div_FR_to(feoarrm0n0_t* lhs, darr_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_div_oF_to(onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_div_Fo_to(feoarrm0n0_t* lhs, onumm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_div_rF_to(coeff_t lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_div_Fr_to(feoarrm0n0_t* lhs, coeff_t rhs, feoarrm0n0_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm0n0_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm0n0_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t feoarrm0n0_integrate(feoarrm0n0_t* arr, feonumm0n0_t* w){

    oarrm0n0_t  res = oarrm0n0_init();

    res = oarrm0n0_zeros(arr->nrows, arr->ncols);

    feoarrm0n0_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_integrate_to(feoarrm0n0_t* arr, feonumm0n0_t* w, oarrm0n0_t* res){

    uint64_t i = 0;

    // Check dimensions.
    feoarrm0n0_dimCheck_FfO_integrate( arr, w, res);

    oarrm0n0_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        oarrm0n0_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

