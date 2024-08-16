
// typedef struct {
//     sotinum_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
// } arrso_t;                ///< Array of OTIs type.





// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
void arrso_neg_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    uint64_t i;
    // Check first dimensions.
    arrso_dimCheck_OO_elementwise(arr,arr,res);

    // The loop for every element in arr.
    for (i = 0; i<arr->size; i++){
        soti_neg_to( &arr->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------
// 1.2 Abs.
// ****************************************************************************************************
void arrso_abs_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    uint64_t i;
    // Check first dimensions.
    arrso_dimCheck_OO_elementwise(arr,arr,res);

    // The loop for every element in arr.
    for (i = 0; i<arr->size; i++){
        soti_abs_to( &arr->p_data[i], &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------



#ifdef _OPENMP

// Parallel implementation
#define _SOTI_CHUNCK_SIZE 8
int nthrds_global;

void setup_global_omp_dist(void){
    
    nthrds_global=omp_get_max_threads();
    omp_set_num_threads(nthrds_global/2);

}

int setup_omp_parallel_elementwise( int totalnIter ){

    int nthrds_prev=omp_get_max_threads();
    int N = totalnIter, nthrds_toset;
    int estThrds_performance = (N/_SOTI_CHUNCK_SIZE)+1;
    

    nthrds_toset = MIN(nthrds_prev,estThrds_performance);
    omp_set_num_threads(nthrds_toset);
    return nthrds_prev;
}
#endif

// 1.2. Addition.
// ****************************************************************************************************
void arrso_sum_OO_to(arrso_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform O + O.
    
     
    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr2,res);

    
    // int nthrds_prev = setup_omp_parallel_elementwise(arr1->size);

    // printf("Received size: %d\n",N);
    // printf("Nthrds: %d\n",nthrds_prev);
    // printf("Nthrds estimated: %d\n",estThrds_performance);
    // printf("Setting up with:  %d\n",nthrds_toset);


    // Loop for every element and add real to the oti number.
    #ifdef _OPENMP
    #pragma omp parallel
    #endif
    {
    uint64_t i;
    
    #ifdef _OPENMP
    int id = omp_get_thread_num();
    int nThrds = omp_get_num_threads();
    int istart = id*arr1->size/nThrds;
    int iend = (id+1)*arr1->size/nThrds;
    if (iend>arr1->size) iend=arr1->size;
    #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr1->size;
    #endif
    
    // #pragma omp critical 
    // {
    // printf("Reporting from Thrd %d: Nthrds: %d - Range: [%d,%d]\n",id,nThrds,istart,iend-1);
    // }

    for( i = istart; i<iend; i++){
        soti_sum_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }

    }

    // omp_set_num_threads(nthrds_prev);
    // nthrds_toset = omp_get_max_threads();

    // printf("Reset nthreads to: %d\n",nthrds_toset);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sum_RO_to(darr_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    
    // Perform R + O.

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // #else
    int id = 0;
    int nThrds = 1;
    // #endif

    // Loop for every element and add real to the oti number.
    for ( i = id; i < arr1->size; i+=nThrds){
        soti_sum_ro_to(arr1->p_data[i], &arr2->p_data[i], &res->p_data[i],dhl);        
    }
    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sum_oO_to(sotinum_t* num, arrso_t* arr1, arrso_t* res, dhelpl_t dhl){
    // Perform o + O.
    

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // #else
    int id = 0;
    int nThrds = 1;
    // #endif

    // Loop for every element and add real to the oti number.
    for ( i = id; i < arr1->size; i+=nThrds){
        soti_sum_oo_to( num, &arr1->p_data[i], &res->p_data[i], dhl);
    }
    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sum_rO_to(coeff_t num, arrso_t* arr1, arrso_t* res, dhelpl_t dhl){

    // Perform r + O.
    
    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // #else
    int id = 0;
    int nThrds = 1;
    // #endif
    // Loop for every element and add real to the oti number.
    for ( i = id; i < arr1->size; i+=nThrds){
        soti_sum_ro_to(num, &arr1->p_data[i], &res->p_data[i],dhl);        
    }

    // }

}
// ----------------------------------------------------------------------------------------------------















// 1.3. Subtraction.
// ****************************************************************************************************
void arrso_sub_OO_to( arrso_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform O - O
    
    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr2, res);

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // #else
    int id = 0;
    int nThrds = 1;
    // #endif
    
    for ( i = id; i < arr1->size; i+=nThrds){
        soti_sub_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
    
    // }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_OR_to( arrso_t* arr1, darr_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform O - R
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr2,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_sub_or_to(&arr1->p_data[i], arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_RO_to( darr_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform R - O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_sub_ro_to( arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_Oo_to( arrso_t* arr1, sotinum_t* num, arrso_t* res, dhelpl_t dhl){
    // Perform O - o
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_sub_oo_to( &arr1->p_data[i], num, &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_oO_to( sotinum_t* num, arrso_t* arr1, arrso_t* res, dhelpl_t dhl){
    // Prrform o - O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_sub_oo_to( num, &arr1->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_Or_to( arrso_t* arr1, coeff_t num, arrso_t* res, dhelpl_t dhl){
    // Prrform O - r
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_sub_or_to( &arr1->p_data[i], num, &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sub_rO_to( coeff_t num, arrso_t* arr1, arrso_t* res, dhelpl_t dhl){
    // Prrform r - O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_sub_ro_to( num, &arr1->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_trunc_sub_OO_to( ord_t ord, arrso_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform O - O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr2, res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_trunc_sub_oo_to( ord, &arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------













// 1.4. Multiplication.
// ****************************************************************************************************
void arrso_mul_OO_to(arrso_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform O * O
    

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr2,res);

    // // // Loop for every element and add real to the oti number.
    // // #ifdef _OPENMP
    // // #pragma omp parallel for
    // // #endif
    // for ( i = 0; i < arr1->size; i++){
    //     soti_mul_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    // }

    // Loop for every element and add real to the oti number.
// #ifdef _OPENMP
//     #pragma omp parallel
// #endif
    {
    
// #ifdef _OPENMP
//     int id = omp_get_thread_num();
//     int nThrds = omp_get_num_threads();
// #else
    int id = 0;
    int nThrds = 1;
    // int istart = 0;
    // int iend = arr1->size;
// #endif
    int istart = id*arr1->size/nThrds;
    int iend = (id+1)*arr1->size/nThrds;
    if (iend>arr1->size) iend=arr1->size;    
    
    uint64_t i;
    for( i = istart; i<iend; i++){
        soti_mul_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }

    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_mul_RO_to(darr_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform R * O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_mul_ro_to(arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_mul_oO_to(sotinum_t* num, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform o * O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){
        soti_mul_oo_to(num, &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_mul_rO_to(coeff_t num, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform r * O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){
        soti_mul_ro_to(num, &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void arrso_gem_OO_to(arrso_t* arr1, arrso_t* arr2, arrso_t* arr3, arrso_t* res, dhelpl_t dhl){
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr2,res);
    arrso_dimCheck_OO_elementwise(arr1,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){

        soti_gem_oo_to(&arr1->p_data[i], &arr2->p_data[i], &arr3->p_data[i], &res->p_data[i], dhl);

    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_gem_oO_to(sotinum_t* arr1, arrso_t* arr2, arrso_t* arr3, arrso_t* res, dhelpl_t dhl){
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr2,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){

        soti_gem_oo_to( arr1 , &arr2->p_data[i], &arr3->p_data[i], &res->p_data[i], dhl);

    }
}
// ----------------------------------------------------------------------------------------------------






// 1.5. Division
// ****************************************************************************************************
void arrso_div_OO_to(arrso_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform O/O
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_div_oo_to(&arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_OR_to(arrso_t* arr1, darr_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform O/R
    uint64_t i;

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr2,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_div_or_to(&arr1->p_data[i], arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_RO_to(darr_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform R/O

    uint64_t i;

    // Check inputs:
    arrso_dimCheck_RO_elementwise(arr1,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){
        soti_div_ro_to( arr1->p_data[i], &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_oO_to(sotinum_t* num, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform o/O
    uint64_t i;
    
        // Check inputs:
    arrso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){
        soti_div_oo_to( num, &arr2->p_data[i], &res->p_data[i], dhl);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_Oo_to(arrso_t* arr1, sotinum_t* num, arrso_t* res, dhelpl_t dhl){
    // Perform O/o
    uint64_t i;
    
    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_div_oo_to(&arr1->p_data[i], num, &res->p_data[i], dhl);
    }
}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_rO_to(coeff_t num, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
    // Perform r/O
    uint64_t i;
    
    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr2,arr2,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr2->size; i++){
        soti_div_ro_to( num, &arr2->p_data[i], &res->p_data[i], dhl);
    }
} 
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_div_Or_to(arrso_t* arr1, coeff_t num, arrso_t* res, dhelpl_t dhl){
    // Perform O/r
    uint64_t i;
    
    // Check inputs:
    arrso_dimCheck_OO_elementwise(arr1,arr1,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < arr1->size; i++){
        soti_div_or_to(&arr1->p_data[i], num, &res->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------





