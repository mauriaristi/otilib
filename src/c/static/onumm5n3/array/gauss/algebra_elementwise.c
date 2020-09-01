
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_neg(feoarrm5n3_t* arr){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(arr->nrows, arr->ncols, arr->nip);

    feoarrm5n3_neg_to( arr, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_neg_to(feoarrm5n3_t* arr, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        oarrm5n3_neg_to( &arr->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.2 Addition
// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sum_FF(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sum_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sum_fF(feonumm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sum_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sum_OF(oarrm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sum_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sum_RF(darr_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sum_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sum_oF(onumm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sum_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sum_rF(coeff_t lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sum_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sum_FF_to(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sum_fF_to(feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sum_OF_to(oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sum_RF_to(darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sum_oF_to(onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sum_rF_to(coeff_t lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.3 Subtraction
// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sub_FF(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sub_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sub_fF(feonumm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sub_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sub_Ff(feoarrm5n3_t* lhs, feonumm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n3_sub_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sub_OF(oarrm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sub_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sub_FO(feoarrm5n3_t* lhs, oarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n3_sub_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sub_RF(darr_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sub_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sub_FR(feoarrm5n3_t* lhs, darr_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n3_sub_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sub_oF(onumm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sub_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sub_Fo(feoarrm5n3_t* lhs, onumm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n3_sub_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sub_rF(coeff_t lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_sub_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_sub_Fr(feoarrm5n3_t* lhs, coeff_t rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n3_sub_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sub_FF_to(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sub_fF_to(feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sub_Ff_to(feoarrm5n3_t* lhs, feonumm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sub_OF_to(oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sub_FO_to(feoarrm5n3_t* lhs, oarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sub_RF_to(darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sub_FR_to(feoarrm5n3_t* lhs, darr_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sub_oF_to(onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sub_Fo_to(feoarrm5n3_t* lhs, onumm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sub_rF_to(coeff_t lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_sub_Fr_to(feoarrm5n3_t* lhs, coeff_t rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.4 Multiplication
// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_mul_FF(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_mul_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_mul_fF(feonumm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_mul_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_mul_OF(oarrm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_mul_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_mul_RF(darr_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_mul_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_mul_oF(onumm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_mul_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_mul_rF(coeff_t lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_mul_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_mul_FF_to(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_mul_fF_to(feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_mul_OF_to(oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_mul_RF_to(darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_mul_oF_to(onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_mul_rF_to(coeff_t lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// 1.5 Division
// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_div_FF(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_div_FF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_div_Ff(feoarrm5n3_t* lhs, feonumm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n3_div_Ff_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_div_fF(feonumm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_div_fF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_div_OF(oarrm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_div_OF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_div_FO(feoarrm5n3_t* lhs, oarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n3_div_FO_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_div_RF(darr_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_div_RF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_div_FR(feoarrm5n3_t* lhs, darr_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n3_div_FR_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_div_oF(onumm5n3_t* lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_div_oF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_div_Fo(feoarrm5n3_t* lhs, onumm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n3_div_Fo_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_div_rF(coeff_t lhs, feoarrm5n3_t* rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(rhs->nrows, rhs->ncols, rhs->nip);

    feoarrm5n3_div_rF_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
feoarrm5n3_t feoarrm5n3_div_Fr(feoarrm5n3_t* lhs, coeff_t rhs){

    feoarrm5n3_t res;

    res = feoarrm5n3_createEmpty(lhs->nrows, lhs->ncols, lhs->nip);

    feoarrm5n3_div_Fr_to(lhs,rhs,&res);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_div_FF_to(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_div_fF_to(feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_div_Ff_to(feoarrm5n3_t* lhs, feonumm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_div_OF_to(oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_div_FO_to(feoarrm5n3_t* lhs, oarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_div_RF_to(darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_div_FR_to(feoarrm5n3_t* lhs, darr_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_div_oF_to(onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_div_Fo_to(feoarrm5n3_t* lhs, onumm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_div_rF_to(coeff_t lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_div_Fr_to(feoarrm5n3_t* lhs, coeff_t rhs, feoarrm5n3_t* res){

    uint64_t i;

    // Check first dimensions.
    feoarrm5n3_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        oarrm5n3_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm5n3_t feoarrm5n3_integrate(feoarrm5n3_t* arr, feonumm5n3_t* w){

    oarrm5n3_t  res = oarrm5n3_init();

    res = oarrm5n3_zeros(arr->nrows, arr->ncols);

    feoarrm5n3_integrate_to(arr, w, &res);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm5n3_integrate_to(feoarrm5n3_t* arr, feonumm5n3_t* w, oarrm5n3_t* res){

    uint64_t i = 0;

    // Check dimensions.
    feoarrm5n3_dimCheck_FfO_integrate( arr, w, res);

    oarrm5n3_set_r(0.0, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        oarrm5n3_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res);

    }
    
}
// ----------------------------------------------------------------------------------------------------

