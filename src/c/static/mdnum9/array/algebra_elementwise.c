
// typedef struct {
//     mdnum9_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } mdarr9_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
mdarr9_t mdarr9_neg(mdarr9_t* arr){

    mdarr9_t res = mdarr9_empty_like( arr);

    mdarr9_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
mdarr9_t mdarr9_sum_OO(mdarr9_t* arr1, mdarr9_t* arr2){
    // Perform O + O.
    mdarr9_t res;

    res = mdarr9_empty_like( arr1);

    mdarr9_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_sum_RO(darr_t* arr1, mdarr9_t* arr2){
    // Perform R + O.
    mdarr9_t res;
    res = mdarr9_empty_like( arr2);

    mdarr9_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_sum_oO(mdnum9_t* num, mdarr9_t* arr1){
    // Perform o + O.
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_sum_rO(coeff_t num, mdarr9_t* arr1){
    // Perform r + O.
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
mdarr9_t mdarr9_sub_OO( mdarr9_t* arr1, mdarr9_t* arr2){
    // Perform O - O
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_sub_OR( mdarr9_t* arr1, darr_t* arr2){
    // Perform O - R
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_sub_RO( darr_t* arr1, mdarr9_t* arr2){
    // Perform R - O
    mdarr9_t res;
    res = mdarr9_empty_like( arr2);

    mdarr9_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_sub_Oo( mdarr9_t* arr1, mdnum9_t* num){
    // Perform O - o
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_sub_oO( mdnum9_t* num, mdarr9_t* arr1){
    // Prrform o - O
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_sub_Or( mdarr9_t* arr1, coeff_t num){
    // Prrform O - r
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_sub_rO( coeff_t num, mdarr9_t* arr1){
    // Prrform r - O
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
mdarr9_t mdarr9_mul_OO(mdarr9_t* arr1, mdarr9_t* arr2){
    // Perform O * O
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_mul_RO(darr_t* arr1, mdarr9_t* arr2){
    // Perform R * O
    mdarr9_t res;
    res = mdarr9_empty_like( arr2);

    mdarr9_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_mul_oO(mdnum9_t* num, mdarr9_t* arr2){
    // Perform o * O
    mdarr9_t res;
    res = mdarr9_empty_like( arr2);

    mdarr9_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_mul_rO(coeff_t num, mdarr9_t* arr2){
    // Perform r * O
    mdarr9_t res;
    res = mdarr9_empty_like( arr2);

    mdarr9_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
mdarr9_t mdarr9_div_OO(mdarr9_t* arr1, mdarr9_t* arr2){
    // Perform O/O
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_div_OR(mdarr9_t* arr1, darr_t* arr2){
    // Perform O/R
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_div_RO(darr_t* arr1, mdarr9_t* arr2){
    // Perform R/O
    mdarr9_t res;
    res = mdarr9_empty_like( arr2);

    mdarr9_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_div_oO(mdnum9_t* num, mdarr9_t* arr2){
    // Perform o/O
    mdarr9_t res;
    res = mdarr9_empty_like( arr2);

    mdarr9_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_div_Oo(mdarr9_t* arr1, mdnum9_t* num){
    // Perform O/o
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_div_rO(coeff_t num, mdarr9_t* arr2){
    // Perform r/O
    mdarr9_t res;
    res = mdarr9_empty_like( arr2);

    mdarr9_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr9_t mdarr9_div_Or(mdarr9_t* arr1, coeff_t num){
    // Perform O/r
    mdarr9_t res;
    res = mdarr9_empty_like( arr1);

    mdarr9_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

