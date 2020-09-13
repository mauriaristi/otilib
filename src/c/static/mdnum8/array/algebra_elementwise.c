
// typedef struct {
//     mdnum8_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } mdarr8_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
mdarr8_t mdarr8_neg(mdarr8_t* arr){

    mdarr8_t res = mdarr8_empty_like( arr);

    mdarr8_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
mdarr8_t mdarr8_sum_OO(mdarr8_t* arr1, mdarr8_t* arr2){
    // Perform O + O.
    mdarr8_t res;

    res = mdarr8_empty_like( arr1);

    mdarr8_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_sum_RO(darr_t* arr1, mdarr8_t* arr2){
    // Perform R + O.
    mdarr8_t res;
    res = mdarr8_empty_like( arr2);

    mdarr8_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_sum_oO(mdnum8_t* num, mdarr8_t* arr1){
    // Perform o + O.
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_sum_rO(coeff_t num, mdarr8_t* arr1){
    // Perform r + O.
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
mdarr8_t mdarr8_sub_OO( mdarr8_t* arr1, mdarr8_t* arr2){
    // Perform O - O
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_sub_OR( mdarr8_t* arr1, darr_t* arr2){
    // Perform O - R
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_sub_RO( darr_t* arr1, mdarr8_t* arr2){
    // Perform R - O
    mdarr8_t res;
    res = mdarr8_empty_like( arr2);

    mdarr8_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_sub_Oo( mdarr8_t* arr1, mdnum8_t* num){
    // Perform O - o
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_sub_oO( mdnum8_t* num, mdarr8_t* arr1){
    // Prrform o - O
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_sub_Or( mdarr8_t* arr1, coeff_t num){
    // Prrform O - r
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_sub_rO( coeff_t num, mdarr8_t* arr1){
    // Prrform r - O
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
mdarr8_t mdarr8_mul_OO(mdarr8_t* arr1, mdarr8_t* arr2){
    // Perform O * O
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_mul_RO(darr_t* arr1, mdarr8_t* arr2){
    // Perform R * O
    mdarr8_t res;
    res = mdarr8_empty_like( arr2);

    mdarr8_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_mul_oO(mdnum8_t* num, mdarr8_t* arr2){
    // Perform o * O
    mdarr8_t res;
    res = mdarr8_empty_like( arr2);

    mdarr8_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_mul_rO(coeff_t num, mdarr8_t* arr2){
    // Perform r * O
    mdarr8_t res;
    res = mdarr8_empty_like( arr2);

    mdarr8_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
mdarr8_t mdarr8_div_OO(mdarr8_t* arr1, mdarr8_t* arr2){
    // Perform O/O
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_div_OR(mdarr8_t* arr1, darr_t* arr2){
    // Perform O/R
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_div_RO(darr_t* arr1, mdarr8_t* arr2){
    // Perform R/O
    mdarr8_t res;
    res = mdarr8_empty_like( arr2);

    mdarr8_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_div_oO(mdnum8_t* num, mdarr8_t* arr2){
    // Perform o/O
    mdarr8_t res;
    res = mdarr8_empty_like( arr2);

    mdarr8_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_div_Oo(mdarr8_t* arr1, mdnum8_t* num){
    // Perform O/o
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_div_rO(coeff_t num, mdarr8_t* arr2){
    // Perform r/O
    mdarr8_t res;
    res = mdarr8_empty_like( arr2);

    mdarr8_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr8_t mdarr8_div_Or(mdarr8_t* arr1, coeff_t num){
    // Perform O/r
    mdarr8_t res;
    res = mdarr8_empty_like( arr1);

    mdarr8_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

