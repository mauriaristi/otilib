

// void fearrsso_dimCheck_FF_elementwise(fearrsso_t* arr1, fearrsso_t* arr2, fearrsso_t* res);
// void fearrsso_dimCheck_OF_elementwise(  arrsso_t* arr1, fearrsso_t* arr2, fearrsso_t* res);
// void fearrsso_dimCheck_RF_elementwise(   darr_t* arr1, fearrsso_t* arr2, fearrsso_t* res);
// void fearrsso_dimCheck_FF_matmul( fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res);
// void fearrsso_dimCheck_OF_matmul(   arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res);
// void fearrsso_dimCheck_RF_matmul(    darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res);
// void fearrsso_dimCheck_FO_matmul( fearrsso_t* lhs,   arrsso_t* rhs, fearrsso_t* res);
// void fearrsso_dimCheck_FR_matmul( fearrsso_t* lhs,    darr_t* rhs, fearrsso_t* res);
// void fearrsso_dimCheck_F_squareness( fearrsso_t* arr1, fearrsso_t* res);
// void fearrsso_dimCheck_F_transpose( fearrsso_t* arr1, fearrsso_t* res);



// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
fearrsso_t fearrsso_neg(fearrsso_t* arr,  dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(arr->nrows, arr->ncols, arr->nip, 0, 0, dhl);

    fearrsso_neg_to( arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_neg_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(arr, arr, res);

    // The loop for every element in arr.
    for (i = 0; i<res->nip; i++){

        arrsso_neg_to( &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------







// 1.2 Addition
// ****************************************************************************************************
fearrsso_t fearrsso_sum_FF(fearrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sum_FF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sum_fF(fessoti_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sum_fF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sum_OF(arrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sum_OF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sum_RF(darr_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sum_RF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sum_oF(semiotin_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sum_oF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sum_rF(coeff_t lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sum_rF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sum_FF_to(fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sum_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sum_fF_to(fessoti_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sum_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sum_OF_to(arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sum_OO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sum_RF_to(darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sum_RO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sum_oF_to(semiotin_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sum_oO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sum_rF_to(coeff_t lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sum_rO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------






















// 1.3 Subtraction
// ****************************************************************************************************
fearrsso_t fearrsso_sub_FF(fearrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sub_FF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sub_fF(fessoti_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sub_fF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sub_Ff(fearrsso_t* lhs, fessoti_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_sub_Ff_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sub_OF(arrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sub_OF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sub_FO(fearrsso_t* lhs, arrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_sub_FO_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sub_RF(darr_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sub_RF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sub_FR(fearrsso_t* lhs, darr_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_sub_FR_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sub_oF(semiotin_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sub_oF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sub_Fo(fearrsso_t* lhs, semiotin_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_sub_Fo_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sub_rF(coeff_t lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_sub_rF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_sub_Fr(fearrsso_t* lhs, coeff_t rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_sub_Fr_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sub_FF_to(fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sub_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sub_fF_to(fessoti_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sub_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sub_Ff_to(fearrsso_t* lhs, fessoti_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sub_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sub_OF_to(arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sub_OO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sub_FO_to(fearrsso_t* lhs, arrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sub_OO_to( &lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sub_RF_to(darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sub_RO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sub_FR_to(fearrsso_t* lhs, darr_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sub_OR_to(&lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrsso_sub_oF_to(semiotin_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sub_oO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sub_Fo_to(fearrsso_t* lhs, semiotin_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sub_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sub_rF_to(coeff_t lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sub_rO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_sub_Fr_to(fearrsso_t* lhs, coeff_t rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_sub_Or_to( &lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------














































// 1.4 Multiplication
// ****************************************************************************************************
fearrsso_t fearrsso_mul_FF(fearrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_mul_FF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_mul_fF(fessoti_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_mul_fF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_mul_OF(arrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_mul_OF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_mul_RF(darr_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_mul_RF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_mul_oF(semiotin_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_mul_oF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_mul_rF(coeff_t lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_mul_rF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_mul_FF_to(fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_mul_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_mul_fF_to(fessoti_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_mul_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_mul_OF_to(arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_mul_OO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_mul_RF_to(darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_mul_RO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_mul_oF_to(semiotin_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_mul_oO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_mul_rF_to(coeff_t lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_mul_rO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------























// 1.5 Division
// ****************************************************************************************************
fearrsso_t fearrsso_div_FF(fearrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_div_FF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_div_Ff(fearrsso_t* lhs, fessoti_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_div_Ff_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_div_fF(fessoti_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_div_fF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_div_OF(arrsso_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_div_OF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_div_FO(fearrsso_t* lhs, arrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_div_FO_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_div_RF(darr_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_div_RF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_div_FR(fearrsso_t* lhs, darr_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_div_FR_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_div_oF(semiotin_t* lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_div_oF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_div_Fo(fearrsso_t* lhs, semiotin_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_div_Fo_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_div_rF(coeff_t lhs, fearrsso_t* rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(rhs->nrows, rhs->ncols, rhs->nip, 0, 0, dhl);

    fearrsso_div_rF_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fearrsso_t fearrsso_div_Fr(fearrsso_t* lhs, coeff_t rhs, dhelpl_t dhl){

    fearrsso_t res;

    res = fearrsso_createEmpty_bases(lhs->nrows, lhs->ncols, lhs->nip, 0, 0, dhl);

    fearrsso_div_Fr_to(lhs,rhs,&res,dhl);       
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_div_FF_to(fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_div_OO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_div_fF_to(fessoti_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_fF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_div_oO_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_div_Ff_to(fearrsso_t* lhs, fessoti_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_Ff_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_div_Oo_to( &lhs->p_data[i], &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_div_OF_to(arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_OF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_div_OO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_div_FO_to(fearrsso_t* lhs, arrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_OF_elementwise(rhs,lhs,res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_div_OO_to( &lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_div_RF_to(darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_RF_elementwise(lhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_div_RO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_div_FR_to(fearrsso_t* lhs, darr_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_RF_elementwise( rhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_div_OR_to(&lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fearrsso_div_oF_to(semiotin_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_div_oO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_div_Fo_to(fearrsso_t* lhs, semiotin_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_div_Oo_to(&lhs->p_data[i],  rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_div_rF_to(coeff_t lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(rhs, rhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_div_rO_to( lhs, &rhs->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_div_Fr_to(fearrsso_t* lhs, coeff_t rhs, fearrsso_t* res, dhelpl_t dhl){

    uint64_t i;

    // Check first dimensions.
    fearrsso_dimCheck_FF_elementwise(lhs, lhs, res);

    // The loop for every element in arr.
    for (i = 0; i < res->nip; i++){

        arrsso_div_Or_to( &lhs->p_data[i], rhs, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------
























// ****************************************************************************************************
arrsso_t fearrsso_integrate(fearrsso_t* arr, fessoti_t* w, dhelpl_t dhl){

    arrsso_t  res = arrsso_init();

    res = arrsso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);

    fearrsso_integrate_to(arr, w, &res,  dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fearrsso_integrate_to(fearrsso_t* arr, fessoti_t* w, arrsso_t* res, dhelpl_t dhl){

    uint64_t i = 0;

    // Check dimensions.
    fearrsso_dimCheck_FfO_integrate( arr, w, res);

    arrsso_set_r(0., res, dhl);
    
    // The loop for every element in arr.
    for (i = 0; i < arr->nip; i++){
        
        arrsso_gem_oO_to( &w->p_data[i], &arr->p_data[i], res, res, dhl);

    }


}
// ----------------------------------------------------------------------------------------------------








