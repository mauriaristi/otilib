
// typedef struct {
//     mdnum5_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } mdarr5_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
mdarr5_t mdarr5_neg(mdarr5_t* arr){

    mdarr5_t res = mdarr5_empty_like( arr);

    mdarr5_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
mdarr5_t mdarr5_sum_OO(mdarr5_t* arr1, mdarr5_t* arr2){
    // Perform O + O.
    mdarr5_t res;

    res = mdarr5_empty_like( arr1);

    mdarr5_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_sum_RO(darr_t* arr1, mdarr5_t* arr2){
    // Perform R + O.
    mdarr5_t res;
    res = mdarr5_empty_like( arr2);

    mdarr5_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_sum_oO(mdnum5_t* num, mdarr5_t* arr1){
    // Perform o + O.
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_sum_rO(coeff_t num, mdarr5_t* arr1){
    // Perform r + O.
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
mdarr5_t mdarr5_sub_OO( mdarr5_t* arr1, mdarr5_t* arr2){
    // Perform O - O
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_sub_OR( mdarr5_t* arr1, darr_t* arr2){
    // Perform O - R
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_sub_RO( darr_t* arr1, mdarr5_t* arr2){
    // Perform R - O
    mdarr5_t res;
    res = mdarr5_empty_like( arr2);

    mdarr5_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_sub_Oo( mdarr5_t* arr1, mdnum5_t* num){
    // Perform O - o
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_sub_oO( mdnum5_t* num, mdarr5_t* arr1){
    // Prrform o - O
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_sub_Or( mdarr5_t* arr1, coeff_t num){
    // Prrform O - r
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_sub_rO( coeff_t num, mdarr5_t* arr1){
    // Prrform r - O
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
mdarr5_t mdarr5_mul_OO(mdarr5_t* arr1, mdarr5_t* arr2){
    // Perform O * O
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_mul_RO(darr_t* arr1, mdarr5_t* arr2){
    // Perform R * O
    mdarr5_t res;
    res = mdarr5_empty_like( arr2);

    mdarr5_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_mul_oO(mdnum5_t* num, mdarr5_t* arr2){
    // Perform o * O
    mdarr5_t res;
    res = mdarr5_empty_like( arr2);

    mdarr5_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_mul_rO(coeff_t num, mdarr5_t* arr2){
    // Perform r * O
    mdarr5_t res;
    res = mdarr5_empty_like( arr2);

    mdarr5_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
mdarr5_t mdarr5_div_OO(mdarr5_t* arr1, mdarr5_t* arr2){
    // Perform O/O
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_div_OR(mdarr5_t* arr1, darr_t* arr2){
    // Perform O/R
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_div_RO(darr_t* arr1, mdarr5_t* arr2){
    // Perform R/O
    mdarr5_t res;
    res = mdarr5_empty_like( arr2);

    mdarr5_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_div_oO(mdnum5_t* num, mdarr5_t* arr2){
    // Perform o/O
    mdarr5_t res;
    res = mdarr5_empty_like( arr2);

    mdarr5_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_div_Oo(mdarr5_t* arr1, mdnum5_t* num){
    // Perform O/o
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_div_rO(coeff_t num, mdarr5_t* arr2){
    // Perform r/O
    mdarr5_t res;
    res = mdarr5_empty_like( arr2);

    mdarr5_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr5_t mdarr5_div_Or(mdarr5_t* arr1, coeff_t num){
    // Perform O/r
    mdarr5_t res;
    res = mdarr5_empty_like( arr1);

    mdarr5_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

