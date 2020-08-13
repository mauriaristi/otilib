


// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
void arrso_neg_to(arrso_t* arr, arrso_t* res){{

    uint64_t i;
    // Check first dimensions.
    arrso_dimCheck_OO_elementwise(arr,arr,res);

    // The loop for every element in arr.
    for (i = 0; i<arr->size; i++){{
        soti_neg_to( &arr->p_data[i], &res->p_data[i], dhl);
    }}

}}
// ----------------------------------------------------------------------------------------------------







// 1.2. Addition.
// ****************************************************************************************************
void arrso_sum_OO_to(arrso_t* arr1, arrso_t* arr2, arrso_t* res){{
    // Perform O + O.
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_sum_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sum_RO_to(darr_t* arr1, arrso_t* arr2, arrso_t* res){{
    
    // Perform R + O.

    uint64_t i;

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_sum_ro_to(arr1->p_data[i], &arr2->p_data[i], &res->p_data[i],dhl);        
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sum_oO_to(sotinum_t* num, arrso_t* arr1, arrso_t* res){{
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_sum_oo_to( num, &arr1->p_data[i], &res->p_data[i], dhl);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sum_rO_to(coeff_t num, arrso_t* arr1, arrso_t* res){{

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_sum_ro_to(num, &arr1->p_data[i], &res->p_data[i],dhl);        
    }}

}}
// ----------------------------------------------------------------------------------------------------















// 1.3. Subtraction.
// ****************************************************************************************************
void arrso_sub_OO_to( arrso_t* arr1, arrso_t* arr2, arrso_t* res){{
    // Perform O - O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr2, res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_sub_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_OR_to( arrso_t* arr1, darr_t* arr2, arrso_t* res){{
    // Perform O - R
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr2,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_sub_or_to(&arr1->p_data[i], arr2->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_RO_to( darr_t* arr1, arrso_t* arr2, arrso_t* res){{
    // Perform R - O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_sub_ro_to( arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_Oo_to( arrso_t* arr1, sotinum_t* num, arrso_t* res){{
    // Perform O - o
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_sub_oo_to( &arr1->p_data[i], num, &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_oO_to( sotinum_t* num, arrso_t* arr1, arrso_t* res){{
    // Prrform o - O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_sub_oo_to( num, &arr1->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_Or_to( arrso_t* arr1, coeff_t num, arrso_t* res){{
    // Prrform O - r
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_sub_or_to( &arr1->p_data[i], num, &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_rO_to( coeff_t num, arrso_t* arr1, arrso_t* res){{
    // Prrform r - O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_sub_ro_to( num, &arr1->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------















// 1.4. Multiplication.
// ****************************************************************************************************
void arrso_mul_OO_to(arrso_t* arr1, arrso_t* arr2, arrso_t* res){{
    // Perform O * O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_mul_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_mul_RO_to(darr_t* arr1, arrso_t* arr2, arrso_t* res){{
    // Perform R * O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_mul_ro_to(arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_mul_oO_to(sotinum_t* num, arrso_t* arr2, arrso_t* res){{
    // Perform o * O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){{
        soti_mul_oo_to(num, &arr2->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_mul_rO_to(coeff_t num, arrso_t* arr2, arrso_t* res){{
    // Perform r * O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){{
        soti_mul_ro_to(num, &arr2->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void arrso_gem_OO_to(arrso_t* arr1, arrso_t* arr2, arrso_t* arr3, arrso_t* res){{
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr2,res);
    arrso_dimCheck_OO_elementwise(arr1,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){{

        soti_gem_oo_to(&arr1->p_data[i], &arr2->p_data[i], &arr3->p_data[i], &res->p_data[i], dhl);

    }}
}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_gem_oO_to(sotinum_t* arr1, arrso_t* arr2, arrso_t* arr3, arrso_t* res){{
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr2,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){{

        soti_gem_oo_to( arr1 , &arr2->p_data[i], &arr3->p_data[i], &res->p_data[i], dhl);

    }}
}}
// ----------------------------------------------------------------------------------------------------






// 1.5. Division
// ****************************************************************************************************
void arrso_div_OO_to(arrso_t* arr1, arrso_t* arr2, arrso_t* res){{
    // Perform O/O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_div_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_OR_to(arrso_t* arr1, darr_t* arr2, arrso_t* res){{
    // Perform O/R
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr2,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_div_or_to(&arr1->p_data[i], arr2->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_RO_to(darr_t* arr1, arrso_t* arr2, arrso_t* res){{
    // Perform R/O

    uint64_t i;

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){{
        soti_div_ro_to( arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_oO_to(sotinum_t* num, arrso_t* arr2, arrso_t* res){{
    // Perform o/O
    uint64_t i;
    
        // Check inputs:
    arrso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){{
        soti_div_oo_to( num, &arr2->p_data[i], &res->p_data[i], dhl);
    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_Oo_to(arrso_t* arr1, sotinum_t* num, arrso_t* res){{
    // Perform O/o
    uint64_t i;
    
    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_div_oo_to(&arr1->p_data[i], num, &res->p_data[i], dhl);
    }}
}}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_rO_to(coeff_t num, arrso_t* arr2, arrso_t* res){{
    // Perform r/O
    uint64_t i;
    
    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){{
        soti_div_ro_to( num, &arr2->p_data[i], &res->p_data[i], dhl);
    }}
}} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_Or_to(arrso_t* arr1, coeff_t num, arrso_t* res){{
    // Perform O/r
    uint64_t i;
    
    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){{
        soti_div_or_to(&arr1->p_data[i], num, &res->p_data[i], dhl);
    }}

}}
// ----------------------------------------------------------------------------------------------------





// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
arrso_t arrso_neg(arrso_t* arr){{

    arrso_t res = arrso_empty_like( arr, dhl);

    arrso_neg_to(arr,&res,dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------







// 1.2. Addition.
// ****************************************************************************************************
arrso_t arrso_sum_OO(arrso_t* arr1, arrso_t* arr2){{
    // Perform O + O.
    arrso_t res;

    res = arrso_empty_like( arr1, dhl);

    arrso_sum_OO_to( arr1, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sum_RO(darr_t* arr1, arrso_t* arr2){{
    // Perform R + O.
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_sum_RO_to( arr1, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sum_oO(sotinum_t* num, arrso_t* arr1){{
    // Perform o + O.
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sum_oO_to( num, arr1, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sum_rO(coeff_t num, arrso_t* arr1){{
    // Perform r + O.
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sum_rO_to( num, arr1, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------















// 1.3. Subtraction.
// ****************************************************************************************************
arrso_t arrso_sub_OO( arrso_t* arr1, arrso_t* arr2){{
    // Perform O - O
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_OO_to( arr1, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_OR( arrso_t* arr1, darr_t* arr2){{
    // Perform O - R
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_OR_to( arr1, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_RO( darr_t* arr1, arrso_t* arr2){{
    // Perform R - O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_sub_RO_to( arr1, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_Oo( arrso_t* arr1, sotinum_t* num){{
    // Perform O - o
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_Oo_to( arr1, num, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_oO( sotinum_t* num, arrso_t* arr1){{
    // Prrform o - O
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_oO_to( num, arr1, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_Or( arrso_t* arr1, coeff_t num){{
    // Prrform O - r
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_Or_to( arr1, num, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_sub_rO( coeff_t num, arrso_t* arr1){{
    // Prrform r - O
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_sub_rO_to( num, arr1, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------















// 1.4. Multiplication.
// ****************************************************************************************************
arrso_t arrso_mul_OO(arrso_t* arr1, arrso_t* arr2){{
    // Perform O * O
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_mul_OO_to( arr1, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_mul_RO(darr_t* arr1, arrso_t* arr2){{
    // Perform R * O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_mul_RO_to( arr1, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_mul_oO(sotinum_t* num, arrso_t* arr2){{
    // Perform o * O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_mul_oO_to( num, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_mul_rO(coeff_t num, arrso_t* arr2){{
    // Perform r * O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_mul_rO_to( num, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------













// 1.5. Division
// ****************************************************************************************************
arrso_t arrso_div_OO(arrso_t* arr1, arrso_t* arr2){{
    // Perform O/O
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_div_OO_to( arr1, arr2, &res, dhl);
    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_OR(arrso_t* arr1, darr_t* arr2){{
    // Perform O/R
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_div_OR_to( arr1, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_RO(darr_t* arr1, arrso_t* arr2){{
    // Perform R/O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_div_RO_to( arr1, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_oO(sotinum_t* num, arrso_t* arr2){{
    // Perform o/O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_div_oO_to( num, arr2, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_Oo(arrso_t* arr1, sotinum_t* num){{
    // Perform O/o
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_div_Oo_to( arr1, num, &res, dhl);

    return res;
}}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_rO(coeff_t num, arrso_t* arr2){{
    // Perform r/O
    arrso_t res;
    res = arrso_empty_like( arr2, dhl);

    arrso_div_rO_to( num, arr2, &res, dhl);

    return res;
}} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_div_Or(arrso_t* arr1, coeff_t num){{
    // Perform O/r
    arrso_t res;
    res = arrso_empty_like( arr1, dhl);

    arrso_div_Or_to( arr1, num, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------





