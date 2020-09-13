
// typedef struct {
//     mdnum6_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// } mdarr6_t;                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
mdarr6_t mdarr6_neg(mdarr6_t* arr){

    mdarr6_t res = mdarr6_empty_like( arr);

    mdarr6_neg_to(arr,&res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
mdarr6_t mdarr6_sum_OO(mdarr6_t* arr1, mdarr6_t* arr2){
    // Perform O + O.
    mdarr6_t res;

    res = mdarr6_empty_like( arr1);

    mdarr6_sum_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_sum_RO(darr_t* arr1, mdarr6_t* arr2){
    // Perform R + O.
    mdarr6_t res;
    res = mdarr6_empty_like( arr2);

    mdarr6_sum_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_sum_oO(mdnum6_t* num, mdarr6_t* arr1){
    // Perform o + O.
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_sum_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_sum_rO(coeff_t num, mdarr6_t* arr1){
    // Perform r + O.
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_sum_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
mdarr6_t mdarr6_sub_OO( mdarr6_t* arr1, mdarr6_t* arr2){
    // Perform O - O
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_sub_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_sub_OR( mdarr6_t* arr1, darr_t* arr2){
    // Perform O - R
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_sub_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_sub_RO( darr_t* arr1, mdarr6_t* arr2){
    // Perform R - O
    mdarr6_t res;
    res = mdarr6_empty_like( arr2);

    mdarr6_sub_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_sub_Oo( mdarr6_t* arr1, mdnum6_t* num){
    // Perform O - o
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_sub_Oo_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_sub_oO( mdnum6_t* num, mdarr6_t* arr1){
    // Prrform o - O
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_sub_oO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_sub_Or( mdarr6_t* arr1, coeff_t num){
    // Prrform O - r
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_sub_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_sub_rO( coeff_t num, mdarr6_t* arr1){
    // Prrform r - O
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_sub_rO_to( num, arr1, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
mdarr6_t mdarr6_mul_OO(mdarr6_t* arr1, mdarr6_t* arr2){
    // Perform O * O
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_mul_OO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_mul_RO(darr_t* arr1, mdarr6_t* arr2){
    // Perform R * O
    mdarr6_t res;
    res = mdarr6_empty_like( arr2);

    mdarr6_mul_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_mul_oO(mdnum6_t* num, mdarr6_t* arr2){
    // Perform o * O
    mdarr6_t res;
    res = mdarr6_empty_like( arr2);

    mdarr6_mul_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_mul_rO(coeff_t num, mdarr6_t* arr2){
    // Perform r * O
    mdarr6_t res;
    res = mdarr6_empty_like( arr2);

    mdarr6_mul_rO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
mdarr6_t mdarr6_div_OO(mdarr6_t* arr1, mdarr6_t* arr2){
    // Perform O/O
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_div_OO_to( arr1, arr2, &res);
    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_div_OR(mdarr6_t* arr1, darr_t* arr2){
    // Perform O/R
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_div_OR_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_div_RO(darr_t* arr1, mdarr6_t* arr2){
    // Perform R/O
    mdarr6_t res;
    res = mdarr6_empty_like( arr2);

    mdarr6_div_RO_to( arr1, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_div_oO(mdnum6_t* num, mdarr6_t* arr2){
    // Perform o/O
    mdarr6_t res;
    res = mdarr6_empty_like( arr2);

    mdarr6_div_oO_to( num, arr2, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_div_Oo(mdarr6_t* arr1, mdnum6_t* num){
    // Perform O/o
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_div_Oo_to( arr1, num, &res);

    return res;
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_div_rO(coeff_t num, mdarr6_t* arr2){
    // Perform r/O
    mdarr6_t res;
    res = mdarr6_empty_like( arr2);

    mdarr6_div_rO_to( num, arr2, &res);

    return res;
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdarr6_t mdarr6_div_Or(mdarr6_t* arr1, coeff_t num){
    // Perform O/r
    mdarr6_t res;
    res = mdarr6_empty_like( arr1);

    mdarr6_div_Or_to( arr1, num, &res);

    return res;
}
// ----------------------------------------------------------------------------------------------------

