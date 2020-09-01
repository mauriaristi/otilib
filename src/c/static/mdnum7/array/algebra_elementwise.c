
// typedef struct {
//     mdnum7_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } mdarr7_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
mdarr7_t mdarr7_neg(mdarr7_t* arr){

    mdarr7_t res = mdarr7_empty_like( arr);

    mdarr7_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
mdarr7_t mdarr7_sum_OO(mdarr7_t* arr1, mdarr7_t* arr2){
    // Perform O + O.
    mdarr7_t res;

    res = mdarr7_empty_like( arr1);

    mdarr7_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_sum_RO(darr_t* arr1, mdarr7_t* arr2){
    // Perform R + O.
    mdarr7_t res;
    res = mdarr7_empty_like( arr2);

    mdarr7_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_sum_oO(mdnum7_t* num, mdarr7_t* arr1){
    // Perform o + O.
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_sum_rO(coeff_t num, mdarr7_t* arr1){
    // Perform r + O.
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
mdarr7_t mdarr7_sub_OO( mdarr7_t* arr1, mdarr7_t* arr2){
    // Perform O - O
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_sub_OR( mdarr7_t* arr1, darr_t* arr2){
    // Perform O - R
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_sub_RO( darr_t* arr1, mdarr7_t* arr2){
    // Perform R - O
    mdarr7_t res;
    res = mdarr7_empty_like( arr2);

    mdarr7_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_sub_Oo( mdarr7_t* arr1, mdnum7_t* num){
    // Perform O - o
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_sub_oO( mdnum7_t* num, mdarr7_t* arr1){
    // Prrform o - O
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_sub_Or( mdarr7_t* arr1, coeff_t num){
    // Prrform O - r
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_sub_rO( coeff_t num, mdarr7_t* arr1){
    // Prrform r - O
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
mdarr7_t mdarr7_mul_OO(mdarr7_t* arr1, mdarr7_t* arr2){
    // Perform O * O
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_mul_RO(darr_t* arr1, mdarr7_t* arr2){
    // Perform R * O
    mdarr7_t res;
    res = mdarr7_empty_like( arr2);

    mdarr7_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_mul_oO(mdnum7_t* num, mdarr7_t* arr2){
    // Perform o * O
    mdarr7_t res;
    res = mdarr7_empty_like( arr2);

    mdarr7_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_mul_rO(coeff_t num, mdarr7_t* arr2){
    // Perform r * O
    mdarr7_t res;
    res = mdarr7_empty_like( arr2);

    mdarr7_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
mdarr7_t mdarr7_div_OO(mdarr7_t* arr1, mdarr7_t* arr2){
    // Perform O/O
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_div_OR(mdarr7_t* arr1, darr_t* arr2){
    // Perform O/R
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_div_RO(darr_t* arr1, mdarr7_t* arr2){
    // Perform R/O
    mdarr7_t res;
    res = mdarr7_empty_like( arr2);

    mdarr7_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_div_oO(mdnum7_t* num, mdarr7_t* arr2){
    // Perform o/O
    mdarr7_t res;
    res = mdarr7_empty_like( arr2);

    mdarr7_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_div_Oo(mdarr7_t* arr1, mdnum7_t* num){
    // Perform O/o
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_div_rO(coeff_t num, mdarr7_t* arr2){
    // Perform r/O
    mdarr7_t res;
    res = mdarr7_empty_like( arr2);

    mdarr7_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr7_t mdarr7_div_Or(mdarr7_t* arr1, coeff_t num){
    // Perform O/r
    mdarr7_t res;
    res = mdarr7_empty_like( arr1);

    mdarr7_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

