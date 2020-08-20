
// typedef struct {
//     mdnum4_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } mdarr4_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
mdarr4_t mdarr4_neg(mdarr4_t* arr){

    mdarr4_t res = mdarr4_empty_like( arr);

    mdarr4_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
mdarr4_t mdarr4_sum_OO(mdarr4_t* arr1, mdarr4_t* arr2){
    // Perform O + O.
    mdarr4_t res;

    res = mdarr4_empty_like( arr1);

    mdarr4_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_sum_RO(darr_t* arr1, mdarr4_t* arr2){
    // Perform R + O.
    mdarr4_t res;
    res = mdarr4_empty_like( arr2);

    mdarr4_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_sum_oO(mdnum4_t* num, mdarr4_t* arr1){
    // Perform o + O.
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_sum_rO(coeff_t num, mdarr4_t* arr1){
    // Perform r + O.
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
mdarr4_t mdarr4_sub_OO( mdarr4_t* arr1, mdarr4_t* arr2){
    // Perform O - O
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_sub_OR( mdarr4_t* arr1, darr_t* arr2){
    // Perform O - R
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_sub_RO( darr_t* arr1, mdarr4_t* arr2){
    // Perform R - O
    mdarr4_t res;
    res = mdarr4_empty_like( arr2);

    mdarr4_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_sub_Oo( mdarr4_t* arr1, mdnum4_t* num){
    // Perform O - o
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_sub_oO( mdnum4_t* num, mdarr4_t* arr1){
    // Prrform o - O
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_sub_Or( mdarr4_t* arr1, coeff_t num){
    // Prrform O - r
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_sub_rO( coeff_t num, mdarr4_t* arr1){
    // Prrform r - O
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
mdarr4_t mdarr4_mul_OO(mdarr4_t* arr1, mdarr4_t* arr2){
    // Perform O * O
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_mul_RO(darr_t* arr1, mdarr4_t* arr2){
    // Perform R * O
    mdarr4_t res;
    res = mdarr4_empty_like( arr2);

    mdarr4_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_mul_oO(mdnum4_t* num, mdarr4_t* arr2){
    // Perform o * O
    mdarr4_t res;
    res = mdarr4_empty_like( arr2);

    mdarr4_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_mul_rO(coeff_t num, mdarr4_t* arr2){
    // Perform r * O
    mdarr4_t res;
    res = mdarr4_empty_like( arr2);

    mdarr4_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
mdarr4_t mdarr4_div_OO(mdarr4_t* arr1, mdarr4_t* arr2){
    // Perform O/O
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_div_OR(mdarr4_t* arr1, darr_t* arr2){
    // Perform O/R
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_div_RO(darr_t* arr1, mdarr4_t* arr2){
    // Perform R/O
    mdarr4_t res;
    res = mdarr4_empty_like( arr2);

    mdarr4_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_div_oO(mdnum4_t* num, mdarr4_t* arr2){
    // Perform o/O
    mdarr4_t res;
    res = mdarr4_empty_like( arr2);

    mdarr4_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_div_Oo(mdarr4_t* arr1, mdnum4_t* num){
    // Perform O/o
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_div_rO(coeff_t num, mdarr4_t* arr2){
    // Perform r/O
    mdarr4_t res;
    res = mdarr4_empty_like( arr2);

    mdarr4_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr4_t mdarr4_div_Or(mdarr4_t* arr1, coeff_t num){
    // Perform O/r
    mdarr4_t res;
    res = mdarr4_empty_like( arr1);

    mdarr4_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

