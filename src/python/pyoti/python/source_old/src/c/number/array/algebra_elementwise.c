
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





