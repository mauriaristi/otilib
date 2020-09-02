
// typedef struct {
//     mdnum1_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } mdarr1_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
mdarr1_t mdarr1_neg(mdarr1_t* arr){

    mdarr1_t res = mdarr1_empty_like( arr);

    mdarr1_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
mdarr1_t mdarr1_sum_OO(mdarr1_t* arr1, mdarr1_t* arr2){
    // Perform O + O.
    mdarr1_t res;

    res = mdarr1_empty_like( arr1);

    mdarr1_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_sum_RO(darr_t* arr1, mdarr1_t* arr2){
    // Perform R + O.
    mdarr1_t res;
    res = mdarr1_empty_like( arr2);

    mdarr1_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_sum_oO(mdnum1_t* num, mdarr1_t* arr1){
    // Perform o + O.
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_sum_rO(coeff_t num, mdarr1_t* arr1){
    // Perform r + O.
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
mdarr1_t mdarr1_sub_OO( mdarr1_t* arr1, mdarr1_t* arr2){
    // Perform O - O
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_sub_OR( mdarr1_t* arr1, darr_t* arr2){
    // Perform O - R
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_sub_RO( darr_t* arr1, mdarr1_t* arr2){
    // Perform R - O
    mdarr1_t res;
    res = mdarr1_empty_like( arr2);

    mdarr1_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_sub_Oo( mdarr1_t* arr1, mdnum1_t* num){
    // Perform O - o
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_sub_oO( mdnum1_t* num, mdarr1_t* arr1){
    // Prrform o - O
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_sub_Or( mdarr1_t* arr1, coeff_t num){
    // Prrform O - r
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_sub_rO( coeff_t num, mdarr1_t* arr1){
    // Prrform r - O
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
mdarr1_t mdarr1_mul_OO(mdarr1_t* arr1, mdarr1_t* arr2){
    // Perform O * O
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_mul_RO(darr_t* arr1, mdarr1_t* arr2){
    // Perform R * O
    mdarr1_t res;
    res = mdarr1_empty_like( arr2);

    mdarr1_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_mul_oO(mdnum1_t* num, mdarr1_t* arr2){
    // Perform o * O
    mdarr1_t res;
    res = mdarr1_empty_like( arr2);

    mdarr1_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_mul_rO(coeff_t num, mdarr1_t* arr2){
    // Perform r * O
    mdarr1_t res;
    res = mdarr1_empty_like( arr2);

    mdarr1_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
mdarr1_t mdarr1_div_OO(mdarr1_t* arr1, mdarr1_t* arr2){
    // Perform O/O
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_div_OR(mdarr1_t* arr1, darr_t* arr2){
    // Perform O/R
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_div_RO(darr_t* arr1, mdarr1_t* arr2){
    // Perform R/O
    mdarr1_t res;
    res = mdarr1_empty_like( arr2);

    mdarr1_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_div_oO(mdnum1_t* num, mdarr1_t* arr2){
    // Perform o/O
    mdarr1_t res;
    res = mdarr1_empty_like( arr2);

    mdarr1_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_div_Oo(mdarr1_t* arr1, mdnum1_t* num){
    // Perform O/o
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_div_rO(coeff_t num, mdarr1_t* arr2){
    // Perform r/O
    mdarr1_t res;
    res = mdarr1_empty_like( arr2);

    mdarr1_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr1_t mdarr1_div_Or(mdarr1_t* arr1, coeff_t num){
    // Perform O/r
    mdarr1_t res;
    res = mdarr1_empty_like( arr1);

    mdarr1_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

