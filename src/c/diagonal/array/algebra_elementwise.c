
// typedef struct {
//     sotinum_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } arrso_t;                ///< Array of OTIs type.


// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
arrso_t arrso_neg(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_empty_like( arr, dhl);

    arrso_neg_to(arr,&res,dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Abs
// ****************************************************************************************************
arrso_t arrso_abs(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_empty_like( arr, dhl);

    arrso_abs_to(arr,&res,dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------







// 1.2. Addition.
// ****************************************************************************************************
arrso_t arrso_sum_OO(arrso_t* arr1, arrso_t* arr2, dhelpl_t dhl){
    // Perform O + O.
    arrso_t res;

    res = arrso_empty_like( arr1, dhl);

    arrso_sum_OO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sum_RO(darr_t* arr1, arrso_t* arr2, dhelpl_t dhl){
    // Perform R + O.
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_sum_RO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sum_oO(sotinum_t* num, arrso_t* arr1, dhelpl_t dhl){
    // Perform o + O.
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sum_oO_to( num, arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sum_rO(coeff_t num, arrso_t* arr1, dhelpl_t dhl){
    // Perform r + O.
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sum_rO_to( num, arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------















// 1.3. Subtraction.
// ****************************************************************************************************
arrso_t arrso_sub_OO( arrso_t* arr1, arrso_t* arr2, dhelpl_t dhl){
    // Perform O - O
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_OO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_OR( arrso_t* arr1, darr_t* arr2, dhelpl_t dhl){
    // Perform O - R
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_OR_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_RO( darr_t* arr1, arrso_t* arr2, dhelpl_t dhl){
    // Perform R - O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_sub_RO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_Oo( arrso_t* arr1, sotinum_t* num, dhelpl_t dhl){
    // Perform O - o
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_Oo_to( arr1, num, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_oO( sotinum_t* num, arrso_t* arr1, dhelpl_t dhl){
    // Prrform o - O
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_oO_to( num, arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_Or( arrso_t* arr1, coeff_t num, dhelpl_t dhl){
    // Prrform O - r
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_Or_to( arr1, num, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_rO( coeff_t num, arrso_t* arr1, dhelpl_t dhl){
    // Prrform r - O
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_rO_to( num, arr1, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------















// 1.4. Multiplication.
// ****************************************************************************************************
arrso_t arrso_mul_OO(arrso_t* arr1, arrso_t* arr2, dhelpl_t dhl){
    // Perform O * O
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_mul_OO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_mul_RO(darr_t* arr1, arrso_t* arr2, dhelpl_t dhl){
    // Perform R * O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_mul_RO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_mul_oO(sotinum_t* num, arrso_t* arr2, dhelpl_t dhl){
    // Perform o * O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_mul_oO_to( num, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_mul_rO(coeff_t num, arrso_t* arr2, dhelpl_t dhl){
    // Perform r * O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_mul_rO_to( num, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------













// 1.5. Division
// ****************************************************************************************************
arrso_t arrso_div_OO(arrso_t* arr1, arrso_t* arr2, dhelpl_t dhl){
    // Perform O/O
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_div_OO_to( arr1, arr2, &res, dhl);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_OR(arrso_t* arr1, darr_t* arr2, dhelpl_t dhl){
    // Perform O/R
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_div_OR_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_RO(darr_t* arr1, arrso_t* arr2, dhelpl_t dhl){
    // Perform R/O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_div_RO_to( arr1, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_oO(sotinum_t* num, arrso_t* arr2, dhelpl_t dhl){
    // Perform o/O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_div_oO_to( num, arr2, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_Oo(arrso_t* arr1, sotinum_t* num, dhelpl_t dhl){
    // Perform O/o
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_div_Oo_to( arr1, num, &res, dhl);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_rO(coeff_t num, arrso_t* arr2, dhelpl_t dhl){
    // Perform r/O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_div_rO_to( num, arr2, &res, dhl);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_Or(arrso_t* arr1, coeff_t num, dhelpl_t dhl){
    // Perform O/r
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_div_Or_to( arr1, num, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------





