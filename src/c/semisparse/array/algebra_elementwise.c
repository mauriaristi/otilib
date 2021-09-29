
// typedef struct {
//     semiotin_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } arrsso_t;                ///< Array of OTIs type.


// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
arrsso_t arrsso_neg(arrsso_t* arr, dhelpl_t dhl){

    arrsso_t res = arrsso_empty_like( arr, dhl);

    arrsso_neg_to(arr,&res,dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------







// 1.2. Addition.
// ****************************************************************************************************
arrsso_t arrsso_sum_OO(arrsso_t* arr1, arrsso_t* arr2, dhelpl_t dhl){
    // Perform O + O.
    arrsso_t res;

    res = arrsso_empty_like( arr1, dhl);

    arrsso_sum_OO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sum_RO(darr_t* arr1, arrsso_t* arr2, dhelpl_t dhl){
    // Perform R + O.
    arrsso_t res;
    res = arrsso_empty_like( arr2, dhl);

    arrsso_sum_RO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sum_oO(semiotin_t* num, arrsso_t* arr1, dhelpl_t dhl){
    // Perform o + O.
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_sum_oO_to( num, arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sum_rO(coeff_t num, arrsso_t* arr1, dhelpl_t dhl){
    // Perform r + O.
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_sum_rO_to( num, arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------















// 1.3. Subtraction.
// ****************************************************************************************************
arrsso_t arrsso_sub_OO( arrsso_t* arr1, arrsso_t* arr2, dhelpl_t dhl){
    // Perform O - O
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_sub_OO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sub_OR( arrsso_t* arr1, darr_t* arr2, dhelpl_t dhl){
    // Perform O - R
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_sub_OR_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sub_RO( darr_t* arr1, arrsso_t* arr2, dhelpl_t dhl){
    // Perform R - O
    arrsso_t res;
    res = arrsso_empty_like( arr2, dhl);

    arrsso_sub_RO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sub_Oo( arrsso_t* arr1, semiotin_t* num, dhelpl_t dhl){
    // Perform O - o
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_sub_Oo_to( arr1, num, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sub_oO( semiotin_t* num, arrsso_t* arr1, dhelpl_t dhl){
    // Prrform o - O
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_sub_oO_to( num, arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sub_Or( arrsso_t* arr1, coeff_t num, dhelpl_t dhl){
    // Prrform O - r
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_sub_Or_to( arr1, num, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_sub_rO( coeff_t num, arrsso_t* arr1, dhelpl_t dhl){
    // Prrform r - O
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_sub_rO_to( num, arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------















// 1.4. Multiplication.
// ****************************************************************************************************
arrsso_t arrsso_mul_OO(arrsso_t* arr1, arrsso_t* arr2, dhelpl_t dhl){
    // Perform O * O
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_mul_OO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_mul_RO(darr_t* arr1, arrsso_t* arr2, dhelpl_t dhl){
    // Perform R * O
    arrsso_t res;
    res = arrsso_empty_like( arr2, dhl);

    arrsso_mul_RO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_mul_oO(semiotin_t* num, arrsso_t* arr2, dhelpl_t dhl){
    // Perform o * O
    arrsso_t res;
    res = arrsso_empty_like( arr2, dhl);

    arrsso_mul_oO_to( num, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_mul_rO(coeff_t num, arrsso_t* arr2, dhelpl_t dhl){
    // Perform r * O
    arrsso_t res;
    res = arrsso_empty_like( arr2, dhl);

    arrsso_mul_rO_to( num, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------













// 1.5. Division
// ****************************************************************************************************
arrsso_t arrsso_div_OO(arrsso_t* arr1, arrsso_t* arr2, dhelpl_t dhl){
    // Perform O/O
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_div_OO_to( arr1, arr2, &res, dhl);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_div_OR(arrsso_t* arr1, darr_t* arr2, dhelpl_t dhl){
    // Perform O/R
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_div_OR_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_div_RO(darr_t* arr1, arrsso_t* arr2, dhelpl_t dhl){
    // Perform R/O
    arrsso_t res;
    res = arrsso_empty_like( arr2, dhl);

    arrsso_div_RO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_div_oO(semiotin_t* num, arrsso_t* arr2, dhelpl_t dhl){
    // Perform o/O
    arrsso_t res;
    res = arrsso_empty_like( arr2, dhl);

    arrsso_div_oO_to( num, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_div_Oo(arrsso_t* arr1, semiotin_t* num, dhelpl_t dhl){
    // Perform O/o
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_div_Oo_to( arr1, num, &res, dhl);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_div_rO(coeff_t num, arrsso_t* arr2, dhelpl_t dhl){
    // Perform r/O
    arrsso_t res;
    res = arrsso_empty_like( arr2, dhl);

    arrsso_div_rO_to( num, arr2, &res, dhl);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrsso_t arrsso_div_Or(arrsso_t* arr1, coeff_t num, dhelpl_t dhl){
    // Perform O/r
    arrsso_t res;
    res = arrsso_empty_like( arr1, dhl);

    arrsso_div_Or_to( arr1, num, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------





