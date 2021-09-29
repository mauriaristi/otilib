
// typedef struct {
//     semiotin_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
// } arrsso_t;                ///< Array of OTIs type.





// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
void arrsso_neg_to(arrsso_t* arr, arrsso_t* res, dhelpl_t dhl){

    uint64_t i;
    // Check first dimensions.
    arrsso_dimCheck_OO_elementwise(arr,arr,res);

    // The loop for every element in arr.
    for (i = 0; i<arr->size; i++){
        ssoti_neg_to( &arr->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------







// 1.2. Addition.
// ****************************************************************************************************
void arrsso_sum_OO_to(arrsso_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform O + O.
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_sum_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_sum_RO_to(darr_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    
    // Perform R + O.

    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_sum_ro_to(arr1->p_data[i], &arr2->p_data[i], &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_sum_oO_to(semiotin_t* num, arrsso_t* arr1, arrsso_t* res, dhelpl_t dhl){
    // Perform o + O.
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_sum_oo_to( num, &arr1->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_sum_rO_to(coeff_t num, arrsso_t* arr1, arrsso_t* res, dhelpl_t dhl){

    // Perform r + O.
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_sum_ro_to(num, &arr1->p_data[i], &res->p_data[i],dhl);        
    }

}
// ----------------------------------------------------------------------------------------------------















// 1.3. Subtraction.
// ****************************************************************************************************
void arrsso_sub_OO_to( arrsso_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform O - O
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr2, res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_sub_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_sub_OR_to( arrsso_t* arr1, darr_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform O - R
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_RO_elementwise(arr2,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_sub_or_to(&arr1->p_data[i], arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_sub_RO_to( darr_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform R - O
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_sub_ro_to( arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_sub_Oo_to( arrsso_t* arr1, semiotin_t* num, arrsso_t* res, dhelpl_t dhl){
    // Perform O - o
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_sub_oo_to( &arr1->p_data[i], num, &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_sub_oO_to( semiotin_t* num, arrsso_t* arr1, arrsso_t* res, dhelpl_t dhl){
    // Prrform o - O
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_sub_oo_to( num, &arr1->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_sub_Or_to( arrsso_t* arr1, coeff_t num, arrsso_t* res, dhelpl_t dhl){
    // Prrform O - r
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_sub_or_to( &arr1->p_data[i], num, &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_sub_rO_to( coeff_t num, arrsso_t* arr1, arrsso_t* res, dhelpl_t dhl){
    // Prrform r - O
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_sub_ro_to( num, &arr1->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_trunc_sub_OO_to( ord_t ord, arrsso_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform O - O
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr2, res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_trunc_sub_oo_to( ord, &arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------













// 1.4. Multiplication.
// ****************************************************************************************************
void arrsso_mul_OO_to(arrsso_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform O * O
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_mul_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_mul_RO_to(darr_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform R * O
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_mul_ro_to(arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_mul_oO_to(semiotin_t* num, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform o * O
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){
        ssoti_mul_oo_to(num, &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_mul_rO_to(coeff_t num, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform r * O
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){
        ssoti_mul_ro_to(num, &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void arrsso_gem_OO_to(arrsso_t* arr1, arrsso_t* arr2, arrsso_t* arr3, arrsso_t* res, dhelpl_t dhl){
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr2,res);
    arrsso_dimCheck_OO_elementwise(arr1,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){

        ssoti_gem_oo_to(&arr1->p_data[i], &arr2->p_data[i], &arr3->p_data[i], &res->p_data[i], dhl);

    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrsso_gem_oO_to(semiotin_t* arr1, arrsso_t* arr2, arrsso_t* arr3, arrsso_t* res, dhelpl_t dhl){
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr2,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){

        ssoti_gem_oo_to( arr1 , &arr2->p_data[i], &arr3->p_data[i], &res->p_data[i], dhl);

    }
}
// ----------------------------------------------------------------------------------------------------






// 1.5. Division
// ****************************************************************************************************
void arrsso_div_OO_to(arrsso_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform O/O
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_div_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_div_OR_to(arrsso_t* arr1, darr_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform O/R
    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_RO_elementwise(arr2,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_div_or_to(&arr1->p_data[i], arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_div_RO_to(darr_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform R/O

    uint64_t i;

    // Check inputs:
    arrsso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){
        ssoti_div_ro_to( arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_div_oO_to(semiotin_t* num, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform o/O
    uint64_t i;
    
        // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){
        ssoti_div_oo_to( num, &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_div_Oo_to(arrsso_t* arr1, semiotin_t* num, arrsso_t* res, dhelpl_t dhl){
    // Perform O/o
    uint64_t i;
    
    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_div_oo_to(&arr1->p_data[i], num, &res->p_data[i], dhl);
    }
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_div_rO_to(coeff_t num, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
    // Perform r/O
    uint64_t i;
    
    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){
        ssoti_div_ro_to( num, &arr2->p_data[i], &res->p_data[i], dhl);
    }
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_div_Or_to(arrsso_t* arr1, coeff_t num, arrsso_t* res, dhelpl_t dhl){
    // Perform O/r
    uint64_t i;
    
    // Check inputs:
    arrsso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        ssoti_div_or_to(&arr1->p_data[i], num, &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------





