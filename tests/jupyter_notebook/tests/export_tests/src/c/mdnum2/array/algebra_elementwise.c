
// typedef struct {
//     mdnum2_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } mdarr2_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
mdarr2_t mdarr2_neg(mdarr2_t* arr){

    mdarr2_t res = mdarr2_empty_like( arr);

    mdarr2_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
mdarr2_t mdarr2_sum_OO(mdarr2_t* arr1, mdarr2_t* arr2){
    // Perform O + O.
    mdarr2_t res;

    res = mdarr2_empty_like( arr1);

    mdarr2_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_sum_RO(darr_t* arr1, mdarr2_t* arr2){
    // Perform R + O.
    mdarr2_t res;
    res = mdarr2_empty_like( arr2);

    mdarr2_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_sum_oO(mdnum2_t* num, mdarr2_t* arr1){
    // Perform o + O.
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_sum_rO(coeff_t num, mdarr2_t* arr1){
    // Perform r + O.
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
mdarr2_t mdarr2_sub_OO( mdarr2_t* arr1, mdarr2_t* arr2){
    // Perform O - O
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_sub_OR( mdarr2_t* arr1, darr_t* arr2){
    // Perform O - R
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_sub_RO( darr_t* arr1, mdarr2_t* arr2){
    // Perform R - O
    mdarr2_t res;
    res = mdarr2_empty_like( arr2);

    mdarr2_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_sub_Oo( mdarr2_t* arr1, mdnum2_t* num){
    // Perform O - o
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_sub_oO( mdnum2_t* num, mdarr2_t* arr1){
    // Prrform o - O
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_sub_Or( mdarr2_t* arr1, coeff_t num){
    // Prrform O - r
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_sub_rO( coeff_t num, mdarr2_t* arr1){
    // Prrform r - O
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
mdarr2_t mdarr2_mul_OO(mdarr2_t* arr1, mdarr2_t* arr2){
    // Perform O * O
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_mul_RO(darr_t* arr1, mdarr2_t* arr2){
    // Perform R * O
    mdarr2_t res;
    res = mdarr2_empty_like( arr2);

    mdarr2_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_mul_oO(mdnum2_t* num, mdarr2_t* arr2){
    // Perform o * O
    mdarr2_t res;
    res = mdarr2_empty_like( arr2);

    mdarr2_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_mul_rO(coeff_t num, mdarr2_t* arr2){
    // Perform r * O
    mdarr2_t res;
    res = mdarr2_empty_like( arr2);

    mdarr2_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
mdarr2_t mdarr2_div_OO(mdarr2_t* arr1, mdarr2_t* arr2){
    // Perform O/O
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_div_OR(mdarr2_t* arr1, darr_t* arr2){
    // Perform O/R
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_div_RO(darr_t* arr1, mdarr2_t* arr2){
    // Perform R/O
    mdarr2_t res;
    res = mdarr2_empty_like( arr2);

    mdarr2_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_div_oO(mdnum2_t* num, mdarr2_t* arr2){
    // Perform o/O
    mdarr2_t res;
    res = mdarr2_empty_like( arr2);

    mdarr2_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_div_Oo(mdarr2_t* arr1, mdnum2_t* num){
    // Perform O/o
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_div_rO(coeff_t num, mdarr2_t* arr2){
    // Perform r/O
    mdarr2_t res;
    res = mdarr2_empty_like( arr2);

    mdarr2_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr2_t mdarr2_div_Or(mdarr2_t* arr1, coeff_t num){
    // Perform O/r
    mdarr2_t res;
    res = mdarr2_empty_like( arr1);

    mdarr2_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

