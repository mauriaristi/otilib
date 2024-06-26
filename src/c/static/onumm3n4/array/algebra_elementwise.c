
// typedef struct {
//     onumm3n4_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } oarrm3n4_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
oarrm3n4_t oarrm3n4_neg(oarrm3n4_t* arr){

    oarrm3n4_t res = oarrm3n4_empty_like( arr);

    oarrm3n4_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
oarrm3n4_t oarrm3n4_sum_OO(oarrm3n4_t* arr1, oarrm3n4_t* arr2){
    // Perform O + O.
    oarrm3n4_t res;

    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_sum_RO(darr_t* arr1, oarrm3n4_t* arr2){
    // Perform R + O.
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr2);

    oarrm3n4_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_sum_oO(onumm3n4_t* num, oarrm3n4_t* arr1){
    // Perform o + O.
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_sum_rO(coeff_t num, oarrm3n4_t* arr1){
    // Perform r + O.
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
oarrm3n4_t oarrm3n4_sub_OO( oarrm3n4_t* arr1, oarrm3n4_t* arr2){
    // Perform O - O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_sub_OR( oarrm3n4_t* arr1, darr_t* arr2){
    // Perform O - R
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_sub_RO( darr_t* arr1, oarrm3n4_t* arr2){
    // Perform R - O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr2);

    oarrm3n4_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_sub_Oo( oarrm3n4_t* arr1, onumm3n4_t* num){
    // Perform O - o
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_sub_oO( onumm3n4_t* num, oarrm3n4_t* arr1){
    // Prrform o - O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_sub_Or( oarrm3n4_t* arr1, coeff_t num){
    // Prrform O - r
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_sub_rO( coeff_t num, oarrm3n4_t* arr1){
    // Prrform r - O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
oarrm3n4_t oarrm3n4_mul_OO(oarrm3n4_t* arr1, oarrm3n4_t* arr2){
    // Perform O * O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_mul_RO(darr_t* arr1, oarrm3n4_t* arr2){
    // Perform R * O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr2);

    oarrm3n4_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_mul_oO(onumm3n4_t* num, oarrm3n4_t* arr2){
    // Perform o * O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr2);

    oarrm3n4_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_mul_rO(coeff_t num, oarrm3n4_t* arr2){
    // Perform r * O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr2);

    oarrm3n4_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
oarrm3n4_t oarrm3n4_div_OO(oarrm3n4_t* arr1, oarrm3n4_t* arr2){
    // Perform O/O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_div_OR(oarrm3n4_t* arr1, darr_t* arr2){
    // Perform O/R
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_div_RO(darr_t* arr1, oarrm3n4_t* arr2){
    // Perform R/O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr2);

    oarrm3n4_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_div_oO(onumm3n4_t* num, oarrm3n4_t* arr2){
    // Perform o/O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr2);

    oarrm3n4_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_div_Oo(oarrm3n4_t* arr1, onumm3n4_t* num){
    // Perform O/o
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_div_rO(coeff_t num, oarrm3n4_t* arr2){
    // Perform r/O
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr2);

    oarrm3n4_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarrm3n4_t oarrm3n4_div_Or(oarrm3n4_t* arr1, coeff_t num){
    // Perform O/r
    oarrm3n4_t res;
    res = oarrm3n4_empty_like( arr1);

    oarrm3n4_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

