
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_neg(feoarrm4n2_t* arr){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(arr->nrows, arr->ncols, arr->nip);

    feoarrm4n2_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_neg_to(feoarrm4n2_t* arr, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        oarrm4n2_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sum_FF(feoarrm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sum_fF(feonumm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sum_OF(oarrm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sum_RF(darr_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sum_oF(onumm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sum_rF(coeff_t lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sum_FF_to(feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sum_fF_to(feonumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sum_OF_to(oarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sum_RF_to(darr_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sum_oF_to(onumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sum_rF_to(coeff_t lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sub_FF(feoarrm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sub_fF(feonumm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sub_Ff(feoarrm4n2_t* lhs, feonumm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n2_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sub_OF(oarrm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sub_FO(feoarrm4n2_t* lhs, oarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n2_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sub_RF(darr_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sub_FR(feoarrm4n2_t* lhs, darr_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n2_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sub_oF(onumm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sub_Fo(feoarrm4n2_t* lhs, onumm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n2_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sub_rF(coeff_t lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_sub_Fr(feoarrm4n2_t* lhs, coeff_t rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n2_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sub_FF_to(feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sub_fF_to(feonumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sub_Ff_to(feoarrm4n2_t* lhs, feonumm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sub_OF_to(oarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sub_FO_to(feoarrm4n2_t* lhs, oarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sub_RF_to(darr_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sub_FR_to(feoarrm4n2_t* lhs, darr_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sub_oF_to(onumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sub_Fo_to(feoarrm4n2_t* lhs, onumm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sub_rF_to(coeff_t lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_sub_Fr_to(feoarrm4n2_t* lhs, coeff_t rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_mul_FF(feoarrm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_mul_fF(feonumm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_mul_OF(oarrm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_mul_RF(darr_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_mul_oF(onumm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_mul_rF(coeff_t lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_mul_FF_to(feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_mul_fF_to(feonumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_mul_OF_to(oarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_mul_RF_to(darr_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_mul_oF_to(onumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_mul_rF_to(coeff_t lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_div_FF(feoarrm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_div_Ff(feoarrm4n2_t* lhs, feonumm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n2_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_div_fF(feonumm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_div_OF(oarrm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_div_FO(feoarrm4n2_t* lhs, oarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n2_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_div_RF(darr_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_div_FR(feoarrm4n2_t* lhs, darr_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n2_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_div_oF(onumm4n2_t* lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_div_Fo(feoarrm4n2_t* lhs, onumm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n2_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_div_rF(coeff_t lhs, feoarrm4n2_t* rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm4n2_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm4n2_t feoarrm4n2_div_Fr(feoarrm4n2_t* lhs, coeff_t rhs){

    feoarrm4n2_t res;

    res = feoarrm4n2_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm4n2_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_div_FF_to(feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_div_fF_to(feonumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_div_Ff_to(feoarrm4n2_t* lhs, feonumm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_div_OF_to(oarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_div_FO_to(feoarrm4n2_t* lhs, oarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_div_RF_to(darr_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_div_FR_to(feoarrm4n2_t* lhs, darr_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_div_oF_to(onumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_div_Fo_to(feoarrm4n2_t* lhs, onumm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_div_rF_to(coeff_t lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_div_Fr_to(feoarrm4n2_t* lhs, coeff_t rhs, feoarrm4n2_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm4n2_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm4n2_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm4n2_t feoarrm4n2_integrate(feoarrm4n2_t* arr, feonumm4n2_t* w){

    oarrm4n2_t  res = oarrm4n2_init();

    res = oarrm4n2_zeros(arr->nrows, arr->ncols);

    feoarrm4n2_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm4n2_integrate_to(feoarrm4n2_t* arr, feonumm4n2_t* w, oarrm4n2_t* res){

    uint64_t i = 0;

    // Check dimensions.
    feoarrm4n2_dimCheck_FfO_integrate( arr, w, res);

    oarrm4n2_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        oarrm4n2_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------
