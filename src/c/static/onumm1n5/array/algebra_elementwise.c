
// typedef struct {
//     onumm1n5_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } oarrm1n5_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
oarrm1n5_t oarrm1n5_neg(oarrm1n5_t* arr){

    oarrm1n5_t res = oarrm1n5_empty_like( arr);

    oarrm1n5_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
oarrm1n5_t oarrm1n5_sum_OO(oarrm1n5_t* arr1, oarrm1n5_t* arr2){
    // Perform O + O.
    oarrm1n5_t res;

    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_sum_RO(darr_t* arr1, oarrm1n5_t* arr2){
    // Perform R + O.
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr2);

    oarrm1n5_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_sum_oO(onumm1n5_t* num, oarrm1n5_t* arr1){
    // Perform o + O.
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_sum_rO(coeff_t num, oarrm1n5_t* arr1){
    // Perform r + O.
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
oarrm1n5_t oarrm1n5_sub_OO( oarrm1n5_t* arr1, oarrm1n5_t* arr2){
    // Perform O - O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_sub_OR( oarrm1n5_t* arr1, darr_t* arr2){
    // Perform O - R
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_sub_RO( darr_t* arr1, oarrm1n5_t* arr2){
    // Perform R - O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr2);

    oarrm1n5_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_sub_Oo( oarrm1n5_t* arr1, onumm1n5_t* num){
    // Perform O - o
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_sub_oO( onumm1n5_t* num, oarrm1n5_t* arr1){
    // Prrform o - O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_sub_Or( oarrm1n5_t* arr1, coeff_t num){
    // Prrform O - r
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_sub_rO( coeff_t num, oarrm1n5_t* arr1){
    // Prrform r - O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
oarrm1n5_t oarrm1n5_mul_OO(oarrm1n5_t* arr1, oarrm1n5_t* arr2){
    // Perform O * O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_mul_RO(darr_t* arr1, oarrm1n5_t* arr2){
    // Perform R * O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr2);

    oarrm1n5_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_mul_oO(onumm1n5_t* num, oarrm1n5_t* arr2){
    // Perform o * O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr2);

    oarrm1n5_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_mul_rO(coeff_t num, oarrm1n5_t* arr2){
    // Perform r * O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr2);

    oarrm1n5_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
oarrm1n5_t oarrm1n5_div_OO(oarrm1n5_t* arr1, oarrm1n5_t* arr2){
    // Perform O/O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_div_OR(oarrm1n5_t* arr1, darr_t* arr2){
    // Perform O/R
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_div_RO(darr_t* arr1, oarrm1n5_t* arr2){
    // Perform R/O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr2);

    oarrm1n5_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_div_oO(onumm1n5_t* num, oarrm1n5_t* arr2){
    // Perform o/O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr2);

    oarrm1n5_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_div_Oo(oarrm1n5_t* arr1, onumm1n5_t* num){
    // Perform O/o
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_div_rO(coeff_t num, oarrm1n5_t* arr2){
    // Perform r/O
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr2);

    oarrm1n5_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm1n5_t oarrm1n5_div_Or(oarrm1n5_t* arr1, coeff_t num){
    // Perform O/r
    oarrm1n5_t res;
    res = oarrm1n5_empty_like( arr1);

    oarrm1n5_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

