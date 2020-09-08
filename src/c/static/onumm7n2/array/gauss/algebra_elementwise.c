
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_neg(feoarrm7n2_t* arr){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(arr->nrows, arr->ncols, arr->nip);

    feoarrm7n2_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_neg_to(feoarrm7n2_t* arr, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        oarrm7n2_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sum_FF(feoarrm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sum_fF(feonumm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sum_OF(oarrm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sum_RF(darr_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sum_oF(onumm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sum_rF(coeff_t lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sum_FF_to(feoarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sum_fF_to(feonumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sum_OF_to(oarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sum_RF_to(darr_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sum_oF_to(onumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sum_rF_to(coeff_t lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sub_FF(feoarrm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sub_fF(feonumm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sub_Ff(feoarrm7n2_t* lhs, feonumm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm7n2_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sub_OF(oarrm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sub_FO(feoarrm7n2_t* lhs, oarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm7n2_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sub_RF(darr_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sub_FR(feoarrm7n2_t* lhs, darr_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm7n2_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sub_oF(onumm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sub_Fo(feoarrm7n2_t* lhs, onumm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm7n2_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sub_rF(coeff_t lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_sub_Fr(feoarrm7n2_t* lhs, coeff_t rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm7n2_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sub_FF_to(feoarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sub_fF_to(feonumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sub_Ff_to(feoarrm7n2_t* lhs, feonumm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sub_OF_to(oarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sub_FO_to(feoarrm7n2_t* lhs, oarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sub_RF_to(darr_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sub_FR_to(feoarrm7n2_t* lhs, darr_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sub_oF_to(onumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sub_Fo_to(feoarrm7n2_t* lhs, onumm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sub_rF_to(coeff_t lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_sub_Fr_to(feoarrm7n2_t* lhs, coeff_t rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_mul_FF(feoarrm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_mul_fF(feonumm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_mul_OF(oarrm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_mul_RF(darr_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_mul_oF(onumm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_mul_rF(coeff_t lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_mul_FF_to(feoarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_mul_fF_to(feonumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_mul_OF_to(oarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_mul_RF_to(darr_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_mul_oF_to(onumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_mul_rF_to(coeff_t lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_div_FF(feoarrm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_div_Ff(feoarrm7n2_t* lhs, feonumm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm7n2_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_div_fF(feonumm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_div_OF(oarrm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_div_FO(feoarrm7n2_t* lhs, oarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm7n2_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_div_RF(darr_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_div_FR(feoarrm7n2_t* lhs, darr_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm7n2_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_div_oF(onumm7n2_t* lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_div_Fo(feoarrm7n2_t* lhs, onumm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm7n2_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_div_rF(coeff_t lhs, feoarrm7n2_t* rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm7n2_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm7n2_t feoarrm7n2_div_Fr(feoarrm7n2_t* lhs, coeff_t rhs){

    feoarrm7n2_t res;

    res = feoarrm7n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm7n2_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_div_FF_to(feoarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_div_fF_to(feonumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_div_Ff_to(feoarrm7n2_t* lhs, feonumm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_div_OF_to(oarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_div_FO_to(feoarrm7n2_t* lhs, oarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_div_RF_to(darr_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_div_FR_to(feoarrm7n2_t* lhs, darr_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_div_oF_to(onumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_div_Fo_to(feoarrm7n2_t* lhs, onumm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_div_rF_to(coeff_t lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_div_Fr_to(feoarrm7n2_t* lhs, coeff_t rhs, feoarrm7n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm7n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm7n2_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm7n2_t feoarrm7n2_integrate(feoarrm7n2_t* arr, feonumm7n2_t* w){

    oarrm7n2_t  res = oarrm7n2_init();

    res = oarrm7n2_zeros(arr->nrows, arr->ncols);

    feoarrm7n2_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm7n2_integrate_to(feoarrm7n2_t* arr, feonumm7n2_t* w, oarrm7n2_t* res){

    uint64_t i = 0;

    // Check dimensions.
    feoarrm7n2_dimCheck_FfO_integrate( arr, w, res);

    oarrm7n2_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        oarrm7n2_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

