
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_neg(feoarrm3n3_t* arr){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(arr->nrows, arr->ncols, arr->nip);

    feoarrm3n3_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_neg_to(feoarrm3n3_t* arr, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        oarrm3n3_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sum_FF(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sum_fF(feonumm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sum_OF(oarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sum_RF(darr_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sum_oF(onumm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sum_rF(coeff_t lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sum_FF_to(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sum_fF_to(feonumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sum_OF_to(oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sum_RF_to(darr_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sum_oF_to(onumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sum_rF_to(coeff_t lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sub_FF(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sub_fF(feonumm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sub_Ff(feoarrm3n3_t* lhs, feonumm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm3n3_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sub_OF(oarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sub_FO(feoarrm3n3_t* lhs, oarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm3n3_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sub_RF(darr_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sub_FR(feoarrm3n3_t* lhs, darr_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm3n3_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sub_oF(onumm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sub_Fo(feoarrm3n3_t* lhs, onumm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm3n3_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sub_rF(coeff_t lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_sub_Fr(feoarrm3n3_t* lhs, coeff_t rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm3n3_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sub_FF_to(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sub_fF_to(feonumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sub_Ff_to(feoarrm3n3_t* lhs, feonumm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sub_OF_to(oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sub_FO_to(feoarrm3n3_t* lhs, oarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sub_RF_to(darr_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sub_FR_to(feoarrm3n3_t* lhs, darr_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sub_oF_to(onumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sub_Fo_to(feoarrm3n3_t* lhs, onumm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sub_rF_to(coeff_t lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_sub_Fr_to(feoarrm3n3_t* lhs, coeff_t rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_mul_FF(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_mul_fF(feonumm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_mul_OF(oarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_mul_RF(darr_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_mul_oF(onumm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_mul_rF(coeff_t lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_mul_FF_to(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_mul_fF_to(feonumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_mul_OF_to(oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_mul_RF_to(darr_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_mul_oF_to(onumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_mul_rF_to(coeff_t lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_div_FF(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_div_Ff(feoarrm3n3_t* lhs, feonumm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm3n3_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_div_fF(feonumm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_div_OF(oarrm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_div_FO(feoarrm3n3_t* lhs, oarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm3n3_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_div_RF(darr_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_div_FR(feoarrm3n3_t* lhs, darr_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm3n3_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_div_oF(onumm3n3_t* lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_div_Fo(feoarrm3n3_t* lhs, onumm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm3n3_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_div_rF(coeff_t lhs, feoarrm3n3_t* rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm3n3_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm3n3_t feoarrm3n3_div_Fr(feoarrm3n3_t* lhs, coeff_t rhs){

    feoarrm3n3_t res;

    res = feoarrm3n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm3n3_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_div_FF_to(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_div_fF_to(feonumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_div_Ff_to(feoarrm3n3_t* lhs, feonumm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_div_OF_to(oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_div_FO_to(feoarrm3n3_t* lhs, oarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_div_RF_to(darr_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_div_FR_to(feoarrm3n3_t* lhs, darr_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_div_oF_to(onumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_div_Fo_to(feoarrm3n3_t* lhs, onumm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_div_rF_to(coeff_t lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_div_Fr_to(feoarrm3n3_t* lhs, coeff_t rhs, feoarrm3n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm3n3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm3n3_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n3_t feoarrm3n3_integrate(feoarrm3n3_t* arr, feonumm3n3_t* w){

    oarrm3n3_t  res = oarrm3n3_init();

    res = oarrm3n3_zeros(arr->nrows, arr->ncols);

    feoarrm3n3_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm3n3_integrate_to(feoarrm3n3_t* arr, feonumm3n3_t* w, oarrm3n3_t* res){

    uint64_t i = 0;

    // Check dimensions.
    feoarrm3n3_dimCheck_FfO_integrate( arr, w, res);

    oarrm3n3_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        oarrm3n3_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

