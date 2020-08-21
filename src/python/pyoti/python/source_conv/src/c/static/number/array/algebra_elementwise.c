
// typedef struct {{
//     {num_type}*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
//     return res;
// }} {arr_type};                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
{arr_type} {arr_func}_neg({arr_type}* arr){{

    {arr_type} res = {arr_func}_empty_like( arr);

    {arr_func}_neg_to(arr,&res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
{arr_type} {arr_func}_sum_OO({arr_type}* arr1, {arr_type}* arr2){{
    // Perform O + O.
    {arr_type} res;

    res = {arr_func}_empty_like( arr1);

    {arr_func}_sum_OO_to( arr1, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_sum_RO(darr_t* arr1, {arr_type}* arr2){{
    // Perform R + O.
    {arr_type} res;
    res = {arr_func}_empty_like( arr2);

    {arr_func}_sum_RO_to( arr1, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_sum_oO({num_type}* num, {arr_type}* arr1){{
    // Perform o + O.
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_sum_oO_to( num, arr1, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_sum_rO(coeff_t num, {arr_type}* arr1){{
    // Perform r + O.
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_sum_rO_to( num, arr1, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
{arr_type} {arr_func}_sub_OO( {arr_type}* arr1, {arr_type}* arr2){{
    // Perform O - O
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_sub_OO_to( arr1, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_sub_OR( {arr_type}* arr1, darr_t* arr2){{
    // Perform O - R
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_sub_OR_to( arr1, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_sub_RO( darr_t* arr1, {arr_type}* arr2){{
    // Perform R - O
    {arr_type} res;
    res = {arr_func}_empty_like( arr2);

    {arr_func}_sub_RO_to( arr1, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_sub_Oo( {arr_type}* arr1, {num_type}* num){{
    // Perform O - o
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_sub_Oo_to( arr1, num, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_sub_oO( {num_type}* num, {arr_type}* arr1){{
    // Prrform o - O
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_sub_oO_to( num, arr1, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_sub_Or( {arr_type}* arr1, coeff_t num){{
    // Prrform O - r
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_sub_Or_to( arr1, num, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_sub_rO( coeff_t num, {arr_type}* arr1){{
    // Prrform r - O
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_sub_rO_to( num, arr1, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
{arr_type} {arr_func}_mul_OO({arr_type}* arr1, {arr_type}* arr2){{
    // Perform O * O
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_mul_OO_to( arr1, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_mul_RO(darr_t* arr1, {arr_type}* arr2){{
    // Perform R * O
    {arr_type} res;
    res = {arr_func}_empty_like( arr2);

    {arr_func}_mul_RO_to( arr1, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_mul_oO({num_type}* num, {arr_type}* arr2){{
    // Perform o * O
    {arr_type} res;
    res = {arr_func}_empty_like( arr2);

    {arr_func}_mul_oO_to( num, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_mul_rO(coeff_t num, {arr_type}* arr2){{
    // Perform r * O
    {arr_type} res;
    res = {arr_func}_empty_like( arr2);

    {arr_func}_mul_rO_to( num, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
{arr_type} {arr_func}_div_OO({arr_type}* arr1, {arr_type}* arr2){{
    // Perform O/O
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_div_OO_to( arr1, arr2, &res);
    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_div_OR({arr_type}* arr1, darr_t* arr2){{
    // Perform O/R
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_div_OR_to( arr1, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_div_RO(darr_t* arr1, {arr_type}* arr2){{
    // Perform R/O
    {arr_type} res;
    res = {arr_func}_empty_like( arr2);

    {arr_func}_div_RO_to( arr1, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_div_oO({num_type}* num, {arr_type}* arr2){{
    // Perform o/O
    {arr_type} res;
    res = {arr_func}_empty_like( arr2);

    {arr_func}_div_oO_to( num, arr2, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_div_Oo({arr_type}* arr1, {num_type}* num){{
    // Perform O/o
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_div_Oo_to( arr1, num, &res);

    return res;
}}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_div_rO(coeff_t num, {arr_type}* arr2){{
    // Perform r/O
    {arr_type} res;
    res = {arr_func}_empty_like( arr2);

    {arr_func}_div_rO_to( num, arr2, &res);

    return res;
}} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_div_Or({arr_type}* arr1, coeff_t num){{
    // Perform O/r
    {arr_type} res;
    res = {arr_func}_empty_like( arr1);

    {arr_func}_div_Or_to( arr1, num, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

