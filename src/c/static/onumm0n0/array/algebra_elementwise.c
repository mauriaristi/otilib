
// typedef struct {
//     onumm0n0_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } oarrm0n0_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
oarrm0n0_t oarrm0n0_neg(oarrm0n0_t* arr){

    oarrm0n0_t res = oarrm0n0_empty_like( arr);

    oarrm0n0_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
oarrm0n0_t oarrm0n0_sum_OO(oarrm0n0_t* arr1, oarrm0n0_t* arr2){
    // Perform O + O.
    oarrm0n0_t res;

    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_sum_RO(darr_t* arr1, oarrm0n0_t* arr2){
    // Perform R + O.
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr2);

    oarrm0n0_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_sum_oO(onumm0n0_t* num, oarrm0n0_t* arr1){
    // Perform o + O.
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_sum_rO(coeff_t num, oarrm0n0_t* arr1){
    // Perform r + O.
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
oarrm0n0_t oarrm0n0_sub_OO( oarrm0n0_t* arr1, oarrm0n0_t* arr2){
    // Perform O - O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_sub_OR( oarrm0n0_t* arr1, darr_t* arr2){
    // Perform O - R
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_sub_RO( darr_t* arr1, oarrm0n0_t* arr2){
    // Perform R - O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr2);

    oarrm0n0_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_sub_Oo( oarrm0n0_t* arr1, onumm0n0_t* num){
    // Perform O - o
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_sub_oO( onumm0n0_t* num, oarrm0n0_t* arr1){
    // Prrform o - O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_sub_Or( oarrm0n0_t* arr1, coeff_t num){
    // Prrform O - r
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_sub_rO( coeff_t num, oarrm0n0_t* arr1){
    // Prrform r - O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
oarrm0n0_t oarrm0n0_mul_OO(oarrm0n0_t* arr1, oarrm0n0_t* arr2){
    // Perform O * O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_mul_RO(darr_t* arr1, oarrm0n0_t* arr2){
    // Perform R * O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr2);

    oarrm0n0_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_mul_oO(onumm0n0_t* num, oarrm0n0_t* arr2){
    // Perform o * O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr2);

    oarrm0n0_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_mul_rO(coeff_t num, oarrm0n0_t* arr2){
    // Perform r * O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr2);

    oarrm0n0_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
oarrm0n0_t oarrm0n0_div_OO(oarrm0n0_t* arr1, oarrm0n0_t* arr2){
    // Perform O/O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_div_OR(oarrm0n0_t* arr1, darr_t* arr2){
    // Perform O/R
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_div_RO(darr_t* arr1, oarrm0n0_t* arr2){
    // Perform R/O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr2);

    oarrm0n0_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_div_oO(onumm0n0_t* num, oarrm0n0_t* arr2){
    // Perform o/O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr2);

    oarrm0n0_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_div_Oo(oarrm0n0_t* arr1, onumm0n0_t* num){
    // Perform O/o
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_div_rO(coeff_t num, oarrm0n0_t* arr2){
    // Perform r/O
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr2);

    oarrm0n0_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm0n0_t oarrm0n0_div_Or(oarrm0n0_t* arr1, coeff_t num){
    // Perform O/r
    oarrm0n0_t res;
    res = oarrm0n0_empty_like( arr1);

    oarrm0n0_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

