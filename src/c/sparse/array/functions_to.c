
// ****************************************************************************************************
void arrso_erf_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_erf_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void arrso_atanh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_atanh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_asinh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_asinh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_acosh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_acosh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_tanh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_tanh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_cbrt_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_cbrt_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sqrt_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_sqrt_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_cosh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_cosh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sinh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_sinh_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_asin_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_asin_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_acos_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_acos_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_atan_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_atan_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_tan_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_tan_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_cos_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_cos_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_sin_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_sin_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_logb_to(arrso_t* arr, double base, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_logb_to(&arr->p_data[i], base, &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_log10_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_log10_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_log_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_log_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_exp_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_exp_to(&arr->p_data[i], &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_pow_soti_to(arrso_t* arr, sotinum_t* e, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_pow_soti_to(&arr->p_data[i], e, &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_pow_to(arrso_t* arr, double e, arrso_t* res, dhelpl_t dhl){

    // Loop for every element and add real to the oti number.
    // #ifdef _OPENMP
    // #pragma omp parallel
    // #endif
    // {
    uint64_t i;
    
    // #ifdef _OPENMP
    // int id = omp_get_thread_num();
    // int nThrds = omp_get_num_threads();
    // int istart = id*arr->size/nThrds;
    // int iend = (id+1)*arr->size/nThrds;
    // if (iend>arr->size) iend=arr->size;
    // #else
    int id = 0;
    int nThrds = 1;
    int istart = 0;
    int iend = arr->size;
    // #endif

    for( i = istart; i<iend; i++){
        
        soti_pow_to(&arr->p_data[i], e, &res->p_data[i], dhl);

    }

    // }

}
// ----------------------------------------------------------------------------------------------------

