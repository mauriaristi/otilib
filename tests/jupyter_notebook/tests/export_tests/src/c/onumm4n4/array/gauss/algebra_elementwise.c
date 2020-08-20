
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_neg(feoarrm4n4_t* arr){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n4_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_neg_to(feoarrm4n4_t* arr, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        oarrm4n4_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sum_FF(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sum_fF(feonumm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sum_OF(oarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sum_RF(darr_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sum_oF(onumm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sum_rF(coeff_t lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sum_FF_to(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sum_fF_to(feonumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sum_OF_to(oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sum_RF_to(darr_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sum_oF_to(onumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sum_rF_to(coeff_t lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sub_FF(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sub_fF(feonumm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sub_Ff(feoarrm4n4_t* lhs, feonumm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n4_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sub_OF(oarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sub_FO(feoarrm4n4_t* lhs, oarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n4_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sub_RF(darr_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sub_FR(feoarrm4n4_t* lhs, darr_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n4_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sub_oF(onumm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sub_Fo(feoarrm4n4_t* lhs, onumm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n4_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sub_rF(coeff_t lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_sub_Fr(feoarrm4n4_t* lhs, coeff_t rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n4_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sub_FF_to(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sub_fF_to(feonumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sub_Ff_to(feoarrm4n4_t* lhs, feonumm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sub_OF_to(oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sub_FO_to(feoarrm4n4_t* lhs, oarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sub_RF_to(darr_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sub_FR_to(feoarrm4n4_t* lhs, darr_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sub_oF_to(onumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sub_Fo_to(feoarrm4n4_t* lhs, onumm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sub_rF_to(coeff_t lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_sub_Fr_to(feoarrm4n4_t* lhs, coeff_t rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_mul_FF(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_mul_fF(feonumm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_mul_OF(oarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_mul_RF(darr_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_mul_oF(onumm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_mul_rF(coeff_t lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_mul_FF_to(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_mul_fF_to(feonumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_mul_OF_to(oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_mul_RF_to(darr_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_mul_oF_to(onumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_mul_rF_to(coeff_t lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_div_FF(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_div_Ff(feoarrm4n4_t* lhs, feonumm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n4_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_div_fF(feonumm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_div_OF(oarrm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_div_FO(feoarrm4n4_t* lhs, oarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n4_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_div_RF(darr_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_div_FR(feoarrm4n4_t* lhs, darr_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n4_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_div_oF(onumm4n4_t* lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_div_Fo(feoarrm4n4_t* lhs, onumm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n4_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_div_rF(coeff_t lhs, feoarrm4n4_t* rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n4_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n4_t feoarrm4n4_div_Fr(feoarrm4n4_t* lhs, coeff_t rhs){

    feoarrm4n4_t res;

    res = feoarrm4n4_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n4_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_div_FF_to(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_div_fF_to(feonumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_div_Ff_to(feoarrm4n4_t* lhs, feonumm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_div_OF_to(oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_div_FO_to(feoarrm4n4_t* lhs, oarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_div_RF_to(darr_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_div_FR_to(feoarrm4n4_t* lhs, darr_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_div_oF_to(onumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_div_Fo_to(feoarrm4n4_t* lhs, onumm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_div_rF_to(coeff_t lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_div_Fr_to(feoarrm4n4_t* lhs, coeff_t rhs, feoarrm4n4_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n4_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n4_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm4n4_t feoarrm4n4_integrate(feoarrm4n4_t* arr, feonumm4n4_t* w){

    oarrm4n4_t  res = oarrm4n4_init();

    res = oarrm4n4_zeros(arr->nrows, arr->ncols);

    feoarrm4n4_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n4_integrate_to(feoarrm4n4_t* arr, feonumm4n4_t* w, oarrm4n4_t* res){

    uint64_t i = 0;

    // Check dimensions.
    feoarrm4n4_dimCheck_FfO_integrate( arr, w, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        oarrm4n4_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }

}
// ----------------------------------------------------------------------------------------------------

