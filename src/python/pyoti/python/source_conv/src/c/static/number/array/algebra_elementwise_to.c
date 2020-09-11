
// typedef struct {{
//     {num_type}*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
// }} {arr_type};                ///< Array of OTIs type.

// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
void {arr_func}_neg_to({arr_type}* arr, {arr_type}* res){{

    uint64_t i;
    // Check first dimensions.
    {arr_func}_dimCheck_OO_elementwise(arr,arr,res);

    // The loop for every element in arr.
    for (i = 0; i<arr->size; i++){{
        {num_func}_neg_to( &arr->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// 1.2. Addition.
// ****************************************************************************************************
void {arr_func}_sum_OO_to({arr_type}* arr1, {arr_type}* arr2, {arr_type}* res){{
    // Perform O + O.
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_sum_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_sum_RO_to(darr_t* arr1, {arr_type}* arr2, {arr_type}* res){{
    
    // Perform R + O.

    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_sum_ro_to(arr1->p_data[i], &arr2->p_data[i], &res->p_data[i]);        
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_sum_oO_to({num_type}* num, {arr_type}* arr1, {arr_type}* res){{
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_sum_oo_to( num, &arr1->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_sum_rO_to(coeff_t num, {arr_type}* arr1, {arr_type}* res){{

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_sum_ro_to(num, &arr1->p_data[i], &res->p_data[i]);        
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_trunc_sum_OO_to(ord_t order, {arr_type}* arr1, {arr_type}* arr2, {arr_type}* res){{
    // Perform O + O.
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_trunc_sum_oo_to(order, &arr1->p_data[i], &arr2->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// 1.3. Subtraction.
// ****************************************************************************************************
void {arr_func}_sub_OO_to( {arr_type}* arr1, {arr_type}* arr2, {arr_type}* res){{
    // Perform O - O
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr2, res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_sub_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_sub_OR_to( {arr_type}* arr1, darr_t* arr2, {arr_type}* res){{
    // Perform O - R
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_RO_elementwise(arr2,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_sub_or_to(&arr1->p_data[i], arr2->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_sub_RO_to( darr_t* arr1, {arr_type}* arr2, {arr_type}* res){{
    // Perform R - O
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_sub_ro_to( arr1->p_data[i], &arr2->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_sub_Oo_to( {arr_type}* arr1, {num_type}* num, {arr_type}* res){{
    // Perform O - o
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_sub_oo_to( &arr1->p_data[i], num, &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_sub_oO_to( {num_type}* num, {arr_type}* arr1, {arr_type}* res){{
    // Prrform o - O
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_sub_oo_to( num, &arr1->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_sub_Or_to( {arr_type}* arr1, coeff_t num, {arr_type}* res){{
    // Prrform O - r
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_sub_or_to( &arr1->p_data[i], num, &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_sub_rO_to( coeff_t num, {arr_type}* arr1, {arr_type}* res){{
    // Prrform r - O
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_sub_ro_to( num, &arr1->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_trunc_sub_OO_to(ord_t order, {arr_type}* arr1, {arr_type}* arr2, {arr_type}* res){{
    // Perform O + O.
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_trunc_sub_oo_to(order, &arr1->p_data[i], &arr2->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// 1.4. Multiplication.
// ****************************************************************************************************
void {arr_func}_mul_OO_to({arr_type}* arr1, {arr_type}* arr2, {arr_type}* res){{
    // Perform O * O
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_mul_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_mul_RO_to(darr_t* arr1, {arr_type}* arr2, {arr_type}* res){{
    // Perform R * O
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_mul_ro_to(arr1->p_data[i], &arr2->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_mul_oO_to({num_type}* num, {arr_type}* arr2, {arr_type}* res){{
    // Perform o * O
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){{
        {num_func}_mul_oo_to(num, &arr2->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_mul_rO_to(coeff_t num, {arr_type}* arr2, {arr_type}* res){{
    // Perform r * O
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){{
        {num_func}_mul_ro_to(num, &arr2->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_gem_OO_to({arr_type}* arr1, {arr_type}* arr2, {arr_type}* arr3, {arr_type}* res){{
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr2,res);
    {arr_func}_dimCheck_OO_elementwise(arr1,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){{

        {num_func}_gem_oo_to(&arr1->p_data[i], &arr2->p_data[i], &arr3->p_data[i], &res->p_data[i]);

    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_gem_oO_to({num_type}* arr1, {arr_type}* arr2, {arr_type}* arr3, {arr_type}* res){{
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr2,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){{

        {num_func}_gem_oo_to( arr1 , &arr2->p_data[i], &arr3->p_data[i], &res->p_data[i]);

    }}
}}
// ----------------------------------------------------------------------------------------------------

// 1.5. Division
// ****************************************************************************************************
void {arr_func}_div_OO_to({arr_type}* arr1, {arr_type}* arr2, {arr_type}* res){{
    // Perform O/O
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_div_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_div_OR_to({arr_type}* arr1, darr_t* arr2, {arr_type}* res){{
    // Perform O/R
    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_RO_elementwise(arr2,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_div_or_to(&arr1->p_data[i], arr2->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_div_RO_to(darr_t* arr1, {arr_type}* arr2, {arr_type}* res){{
    // Perform R/O

    uint64_t i;

    // Check inputs:
    {arr_func}_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){{
        {num_func}_div_ro_to( arr1->p_data[i], &arr2->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_div_oO_to({num_type}* num, {arr_type}* arr2, {arr_type}* res){{
    // Perform o/O
    uint64_t i;
    
        // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){{
        {num_func}_div_oo_to( num, &arr2->p_data[i], &res->p_data[i]);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_div_Oo_to({arr_type}* arr1, {num_type}* num, {arr_type}* res){{
    // Perform O/o
    uint64_t i;
    
    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_div_oo_to(&arr1->p_data[i], num, &res->p_data[i]);
    }}
}}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_div_rO_to(coeff_t num, {arr_type}* arr2, {arr_type}* res){{
    // Perform r/O
    uint64_t i;
    
    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){{
        {num_func}_div_ro_to( num, &arr2->p_data[i], &res->p_data[i]);
    }}
}} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_div_Or_to({arr_type}* arr1, coeff_t num, {arr_type}* res){{
    // Perform O/r
    uint64_t i;
    
    // Check inputs:
    {arr_func}_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        {num_func}_div_or_to(&arr1->p_data[i], num, &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

