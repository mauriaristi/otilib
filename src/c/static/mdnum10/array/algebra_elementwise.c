
// typedef struct {
//     mdnum10_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } mdarr10_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
mdarr10_t mdarr10_neg(mdarr10_t* arr){

    mdarr10_t res = mdarr10_empty_like( arr);

    mdarr10_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
mdarr10_t mdarr10_sum_OO(mdarr10_t* arr1, mdarr10_t* arr2){
    // Perform O + O.
    mdarr10_t res;

    res = mdarr10_empty_like( arr1);

    mdarr10_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_sum_RO(darr_t* arr1, mdarr10_t* arr2){
    // Perform R + O.
    mdarr10_t res;
    res = mdarr10_empty_like( arr2);

    mdarr10_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_sum_oO(mdnum10_t* num, mdarr10_t* arr1){
    // Perform o + O.
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_sum_rO(coeff_t num, mdarr10_t* arr1){
    // Perform r + O.
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
mdarr10_t mdarr10_sub_OO( mdarr10_t* arr1, mdarr10_t* arr2){
    // Perform O - O
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_sub_OR( mdarr10_t* arr1, darr_t* arr2){
    // Perform O - R
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_sub_RO( darr_t* arr1, mdarr10_t* arr2){
    // Perform R - O
    mdarr10_t res;
    res = mdarr10_empty_like( arr2);

    mdarr10_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_sub_Oo( mdarr10_t* arr1, mdnum10_t* num){
    // Perform O - o
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_sub_oO( mdnum10_t* num, mdarr10_t* arr1){
    // Prrform o - O
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_sub_Or( mdarr10_t* arr1, coeff_t num){
    // Prrform O - r
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_sub_rO( coeff_t num, mdarr10_t* arr1){
    // Prrform r - O
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
mdarr10_t mdarr10_mul_OO(mdarr10_t* arr1, mdarr10_t* arr2){
    // Perform O * O
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_mul_RO(darr_t* arr1, mdarr10_t* arr2){
    // Perform R * O
    mdarr10_t res;
    res = mdarr10_empty_like( arr2);

    mdarr10_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_mul_oO(mdnum10_t* num, mdarr10_t* arr2){
    // Perform o * O
    mdarr10_t res;
    res = mdarr10_empty_like( arr2);

    mdarr10_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_mul_rO(coeff_t num, mdarr10_t* arr2){
    // Perform r * O
    mdarr10_t res;
    res = mdarr10_empty_like( arr2);

    mdarr10_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
mdarr10_t mdarr10_div_OO(mdarr10_t* arr1, mdarr10_t* arr2){
    // Perform O/O
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_div_OR(mdarr10_t* arr1, darr_t* arr2){
    // Perform O/R
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_div_RO(darr_t* arr1, mdarr10_t* arr2){
    // Perform R/O
    mdarr10_t res;
    res = mdarr10_empty_like( arr2);

    mdarr10_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_div_oO(mdnum10_t* num, mdarr10_t* arr2){
    // Perform o/O
    mdarr10_t res;
    res = mdarr10_empty_like( arr2);

    mdarr10_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_div_Oo(mdarr10_t* arr1, mdnum10_t* num){
    // Perform O/o
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_div_rO(coeff_t num, mdarr10_t* arr2){
    // Perform r/O
    mdarr10_t res;
    res = mdarr10_empty_like( arr2);

    mdarr10_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr10_t mdarr10_div_Or(mdarr10_t* arr1, coeff_t num){
    // Perform O/r
    mdarr10_t res;
    res = mdarr10_empty_like( arr1);

    mdarr10_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

