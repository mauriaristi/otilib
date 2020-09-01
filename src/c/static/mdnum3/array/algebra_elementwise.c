
// typedef struct {
//     mdnum3_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } mdarr3_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
mdarr3_t mdarr3_neg(mdarr3_t* arr){

    mdarr3_t res = mdarr3_empty_like( arr);

    mdarr3_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
mdarr3_t mdarr3_sum_OO(mdarr3_t* arr1, mdarr3_t* arr2){
    // Perform O + O.
    mdarr3_t res;

    res = mdarr3_empty_like( arr1);

    mdarr3_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_sum_RO(darr_t* arr1, mdarr3_t* arr2){
    // Perform R + O.
    mdarr3_t res;
    res = mdarr3_empty_like( arr2);

    mdarr3_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_sum_oO(mdnum3_t* num, mdarr3_t* arr1){
    // Perform o + O.
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_sum_rO(coeff_t num, mdarr3_t* arr1){
    // Perform r + O.
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
mdarr3_t mdarr3_sub_OO( mdarr3_t* arr1, mdarr3_t* arr2){
    // Perform O - O
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_sub_OR( mdarr3_t* arr1, darr_t* arr2){
    // Perform O - R
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_sub_RO( darr_t* arr1, mdarr3_t* arr2){
    // Perform R - O
    mdarr3_t res;
    res = mdarr3_empty_like( arr2);

    mdarr3_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_sub_Oo( mdarr3_t* arr1, mdnum3_t* num){
    // Perform O - o
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_sub_oO( mdnum3_t* num, mdarr3_t* arr1){
    // Prrform o - O
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_sub_Or( mdarr3_t* arr1, coeff_t num){
    // Prrform O - r
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_sub_rO( coeff_t num, mdarr3_t* arr1){
    // Prrform r - O
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
mdarr3_t mdarr3_mul_OO(mdarr3_t* arr1, mdarr3_t* arr2){
    // Perform O * O
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_mul_RO(darr_t* arr1, mdarr3_t* arr2){
    // Perform R * O
    mdarr3_t res;
    res = mdarr3_empty_like( arr2);

    mdarr3_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_mul_oO(mdnum3_t* num, mdarr3_t* arr2){
    // Perform o * O
    mdarr3_t res;
    res = mdarr3_empty_like( arr2);

    mdarr3_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_mul_rO(coeff_t num, mdarr3_t* arr2){
    // Perform r * O
    mdarr3_t res;
    res = mdarr3_empty_like( arr2);

    mdarr3_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
mdarr3_t mdarr3_div_OO(mdarr3_t* arr1, mdarr3_t* arr2){
    // Perform O/O
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_div_OR(mdarr3_t* arr1, darr_t* arr2){
    // Perform O/R
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_div_RO(darr_t* arr1, mdarr3_t* arr2){
    // Perform R/O
    mdarr3_t res;
    res = mdarr3_empty_like( arr2);

    mdarr3_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_div_oO(mdnum3_t* num, mdarr3_t* arr2){
    // Perform o/O
    mdarr3_t res;
    res = mdarr3_empty_like( arr2);

    mdarr3_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_div_Oo(mdarr3_t* arr1, mdnum3_t* num){
    // Perform O/o
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_div_rO(coeff_t num, mdarr3_t* arr2){
    // Perform r/O
    mdarr3_t res;
    res = mdarr3_empty_like( arr2);

    mdarr3_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr3_t mdarr3_div_Or(mdarr3_t* arr1, coeff_t num){
    // Perform O/r
    mdarr3_t res;
    res = mdarr3_empty_like( arr1);

    mdarr3_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

