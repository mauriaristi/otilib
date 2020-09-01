
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_neg(feoarrm5n4_t* arr){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n4_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_neg_to(feoarrm5n4_t* arr, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        oarrm5n4_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sum_FF(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sum_fF(feonumm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sum_OF(oarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sum_RF(darr_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sum_oF(onumm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sum_rF(coeff_t lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sum_FF_to(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sum_fF_to(feonumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sum_OF_to(oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sum_RF_to(darr_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sum_oF_to(onumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sum_rF_to(coeff_t lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sub_FF(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sub_fF(feonumm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sub_Ff(feoarrm5n4_t* lhs, feonumm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n4_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sub_OF(oarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sub_FO(feoarrm5n4_t* lhs, oarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n4_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sub_RF(darr_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sub_FR(feoarrm5n4_t* lhs, darr_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n4_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sub_oF(onumm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sub_Fo(feoarrm5n4_t* lhs, onumm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n4_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sub_rF(coeff_t lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_sub_Fr(feoarrm5n4_t* lhs, coeff_t rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n4_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sub_FF_to(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sub_fF_to(feonumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sub_Ff_to(feoarrm5n4_t* lhs, feonumm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sub_OF_to(oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sub_FO_to(feoarrm5n4_t* lhs, oarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sub_RF_to(darr_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sub_FR_to(feoarrm5n4_t* lhs, darr_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sub_oF_to(onumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sub_Fo_to(feoarrm5n4_t* lhs, onumm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sub_rF_to(coeff_t lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_sub_Fr_to(feoarrm5n4_t* lhs, coeff_t rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_mul_FF(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_mul_fF(feonumm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_mul_OF(oarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_mul_RF(darr_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_mul_oF(onumm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_mul_rF(coeff_t lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_mul_FF_to(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_mul_fF_to(feonumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_mul_OF_to(oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_mul_RF_to(darr_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_mul_oF_to(onumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_mul_rF_to(coeff_t lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_div_FF(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_div_Ff(feoarrm5n4_t* lhs, feonumm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n4_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_div_fF(feonumm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_div_OF(oarrm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_div_FO(feoarrm5n4_t* lhs, oarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n4_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_div_RF(darr_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_div_FR(feoarrm5n4_t* lhs, darr_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n4_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_div_oF(onumm5n4_t* lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_div_Fo(feoarrm5n4_t* lhs, onumm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n4_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_div_rF(coeff_t lhs, feoarrm5n4_t* rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n4_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n4_t feoarrm5n4_div_Fr(feoarrm5n4_t* lhs, coeff_t rhs){

    feoarrm5n4_t res;

    res = feoarrm5n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n4_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_div_FF_to(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_div_fF_to(feonumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_div_Ff_to(feoarrm5n4_t* lhs, feonumm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_div_OF_to(oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_div_FO_to(feoarrm5n4_t* lhs, oarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_div_RF_to(darr_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_div_FR_to(feoarrm5n4_t* lhs, darr_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_div_oF_to(onumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_div_Fo_to(feoarrm5n4_t* lhs, onumm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_div_rF_to(coeff_t lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_div_Fr_to(feoarrm5n4_t* lhs, coeff_t rhs, feoarrm5n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n4_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n4_t feoarrm5n4_integrate(feoarrm5n4_t* arr, feonumm5n4_t* w){

    oarrm5n4_t  res = oarrm5n4_init();

    res = oarrm5n4_zeros(arr->nrows, arr->ncols);

    feoarrm5n4_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n4_integrate_to(feoarrm5n4_t* arr, feonumm5n4_t* w, oarrm5n4_t* res){

    uint64_t i = 0;

    // Check dimensions.
    feoarrm5n4_dimCheck_FfO_integrate( arr, w, res);

    oarrm5n4_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        oarrm5n4_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

