
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_neg(feoarrm9n2_t* arr){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(arr->nrows, arr->ncols, arr->nip);

    feoarrm9n2_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_neg_to(feoarrm9n2_t* arr, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        oarrm9n2_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sum_FF(feoarrm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sum_fF(feonumm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sum_OF(oarrm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sum_RF(darr_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sum_oF(onumm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sum_rF(coeff_t lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sum_FF_to(feoarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sum_fF_to(feonumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sum_OF_to(oarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sum_RF_to(darr_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sum_oF_to(onumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sum_rF_to(coeff_t lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sub_FF(feoarrm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sub_fF(feonumm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sub_Ff(feoarrm9n2_t* lhs, feonumm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm9n2_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sub_OF(oarrm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sub_FO(feoarrm9n2_t* lhs, oarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm9n2_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sub_RF(darr_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sub_FR(feoarrm9n2_t* lhs, darr_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm9n2_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sub_oF(onumm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sub_Fo(feoarrm9n2_t* lhs, onumm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm9n2_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sub_rF(coeff_t lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_sub_Fr(feoarrm9n2_t* lhs, coeff_t rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm9n2_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sub_FF_to(feoarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sub_fF_to(feonumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sub_Ff_to(feoarrm9n2_t* lhs, feonumm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sub_OF_to(oarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sub_FO_to(feoarrm9n2_t* lhs, oarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sub_RF_to(darr_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sub_FR_to(feoarrm9n2_t* lhs, darr_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sub_oF_to(onumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sub_Fo_to(feoarrm9n2_t* lhs, onumm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sub_rF_to(coeff_t lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_sub_Fr_to(feoarrm9n2_t* lhs, coeff_t rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_mul_FF(feoarrm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_mul_fF(feonumm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_mul_OF(oarrm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_mul_RF(darr_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_mul_oF(onumm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_mul_rF(coeff_t lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_mul_FF_to(feoarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_mul_fF_to(feonumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_mul_OF_to(oarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_mul_RF_to(darr_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_mul_oF_to(onumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_mul_rF_to(coeff_t lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_div_FF(feoarrm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_div_Ff(feoarrm9n2_t* lhs, feonumm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm9n2_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_div_fF(feonumm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_div_OF(oarrm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_div_FO(feoarrm9n2_t* lhs, oarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm9n2_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_div_RF(darr_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_div_FR(feoarrm9n2_t* lhs, darr_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm9n2_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_div_oF(onumm9n2_t* lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_div_Fo(feoarrm9n2_t* lhs, onumm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm9n2_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_div_rF(coeff_t lhs, feoarrm9n2_t* rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm9n2_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm9n2_t feoarrm9n2_div_Fr(feoarrm9n2_t* lhs, coeff_t rhs){

    feoarrm9n2_t res;

    res = feoarrm9n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm9n2_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_div_FF_to(feoarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_div_fF_to(feonumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_div_Ff_to(feoarrm9n2_t* lhs, feonumm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_div_OF_to(oarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_div_FO_to(feoarrm9n2_t* lhs, oarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_div_RF_to(darr_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_div_FR_to(feoarrm9n2_t* lhs, darr_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_div_oF_to(onumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_div_Fo_to(feoarrm9n2_t* lhs, onumm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_div_rF_to(coeff_t lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_div_Fr_to(feoarrm9n2_t* lhs, coeff_t rhs, feoarrm9n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm9n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm9n2_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm9n2_t feoarrm9n2_integrate(feoarrm9n2_t* arr, feonumm9n2_t* w){

    oarrm9n2_t  res = oarrm9n2_init();

    res = oarrm9n2_zeros(arr->nrows, arr->ncols);

    feoarrm9n2_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm9n2_integrate_to(feoarrm9n2_t* arr, feonumm9n2_t* w, oarrm9n2_t* res){

    uint64_t i = 0;

    // Check dimensions.
    feoarrm9n2_dimCheck_FfO_integrate( arr, w, res);

    oarrm9n2_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        oarrm9n2_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

