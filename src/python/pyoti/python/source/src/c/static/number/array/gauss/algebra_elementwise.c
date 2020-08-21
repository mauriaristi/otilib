
// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
fearrso_t fearrso_neg(fearrso_t* arr,  dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(arr->nrows, arr->ncols, arr->nip, dhl);

    fearrso_neg_to( arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_neg_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        arrso_neg_to( &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------







// 1.2 Addition
// ****************************************************************************************************
fearrso_t fearrso_sum_FF(fearrso_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sum_FF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sum_fF(fesoti_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sum_fF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sum_OF(arrso_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sum_OF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sum_RF(darr_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sum_RF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sum_oF(sotinum_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sum_oF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sum_rF(coeff_t lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sum_rF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sum_FF_to(fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sum_fF_to(fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sum_OF_to(arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sum_RF_to(darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sum_oF_to(sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sum_rF_to(coeff_t lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------






















// 1.3 Subtraction
// ****************************************************************************************************
fearrso_t fearrso_sub_FF(fearrso_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sub_FF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sub_fF(fesoti_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sub_fF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sub_Ff(fearrso_t* lhs, fesoti_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, dhl);

    fearrso_sub_Ff_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sub_OF(arrso_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sub_OF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sub_FO(fearrso_t* lhs, arrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, dhl);

    fearrso_sub_FO_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sub_RF(darr_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sub_RF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sub_FR(fearrso_t* lhs, darr_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, dhl);

    fearrso_sub_FR_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sub_oF(sotinum_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sub_oF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sub_Fo(fearrso_t* lhs, sotinum_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, dhl);

    fearrso_sub_Fo_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sub_rF(coeff_t lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_sub_rF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_sub_Fr(fearrso_t* lhs, coeff_t rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, dhl);

    fearrso_sub_Fr_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sub_FF_to(fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sub_fF_to(fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sub_Ff_to(fearrso_t* lhs, fesoti_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sub_OF_to(arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sub_FO_to(fearrso_t* lhs, arrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sub_RF_to(darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sub_FR_to(fearrso_t* lhs, darr_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrso_sub_oF_to(sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sub_Fo_to(fearrso_t* lhs, sotinum_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sub_rF_to(coeff_t lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_sub_Fr_to(fearrso_t* lhs, coeff_t rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------














































// 1.4 Multiplication
// ****************************************************************************************************
fearrso_t fearrso_mul_FF(fearrso_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_mul_FF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_mul_fF(fesoti_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_mul_fF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_mul_OF(arrso_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_mul_OF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_mul_RF(darr_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_mul_RF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_mul_oF(sotinum_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_mul_oF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_mul_rF(coeff_t lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_mul_rF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_mul_FF_to(fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_mul_fF_to(fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_mul_OF_to(arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_mul_RF_to(darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_mul_oF_to(sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_mul_rF_to(coeff_t lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------























// 1.5 Division
// ****************************************************************************************************
fearrso_t fearrso_div_FF(fearrso_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_div_FF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_div_Ff(fearrso_t* lhs, fesoti_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, dhl);

    fearrso_div_Ff_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_div_fF(fesoti_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_div_fF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_div_OF(arrso_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_div_OF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_div_FO(fearrso_t* lhs, arrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, dhl);

    fearrso_div_FO_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_div_RF(darr_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_div_RF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_div_FR(fearrso_t* lhs, darr_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, dhl);

    fearrso_div_FR_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_div_oF(sotinum_t* lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_div_oF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_div_Fo(fearrso_t* lhs, sotinum_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, dhl);

    fearrso_div_Fo_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_div_rF(coeff_t lhs, fearrso_t* rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, dhl);

    fearrso_div_rF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrso_t fearrso_div_Fr(fearrso_t* lhs, coeff_t rhs, dhelpl_t dhl){

    fearrso_t res;

    res = fearrso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, dhl);

    fearrso_div_Fr_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_div_FF_to(fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_div_fF_to(fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_div_Ff_to(fearrso_t* lhs, fesoti_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_div_OF_to(arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_div_FO_to(fearrso_t* lhs, arrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_div_RF_to(darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_div_FR_to(fearrso_t* lhs, darr_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrso_div_oF_to(sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_div_Fo_to(fearrso_t* lhs, sotinum_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_div_rF_to(coeff_t lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_div_Fr_to(fearrso_t* lhs, coeff_t rhs, fearrso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrso_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrso_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------
























// ****************************************************************************************************
arrso_t fearrso_integrate(fearrso_t* arr, fesoti_t* w, dhelpl_t dhl){

    arrso_t  res = arrso_init();

    res = arrso_zeros_bases(arr->nrows, arr->ncols, dhl);

    fearrso_integrate_to(arr, w, &res,  dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrso_integrate_to(fearrso_t* arr, fesoti_t* w, arrso_t* res, dhelpl_t dhl){

    uint64_t i = 0;

    // Check dimensions.
    fearrso_dimCheck_FfO_integrate( arr, w, res);

    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        arrso_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res, dhl);

    }


}
// ----------------------------------------------------------------------------------------------------








