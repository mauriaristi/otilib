




// void darr_neg(darr_t* arr1, darr_t* aRes);
// void darr_sum_RR(darr_t* arr1, darr_t* arr2, darr_t* aRes);
// void darr_sum_Rr(darr_t* arr1, coeff_t num, darr_t* aRes);
// void darr_sub_RR(darr_t* arr1, darr_t* arr2, darr_t* aRes);
// void darr_sub_Rr(darr_t* arr1, coeff_t num, darr_t* aRes);
// void darr_sub_rR(coeff_t num, darr_t* arr1, darr_t* aRes);
// void darr_mul_RR(darr_t* arr1, darr_t* arr2, darr_t* aRes);
// void darr_mul_Rr(darr_t* arr1, coeff_t num, darr_t* aRes);
// void darr_div_RR(darr_t* arr1, darr_t* arr2, darr_t* aRes);
// void darr_div_Rr(darr_t* arr1, coeff_t num, darr_t* aRes);
// void darr_div_rR(coeff_t num, darr_t* arr2, darr_t* aRes);

























// 1. Elementwise operations.

// 1.1. Negation.
// ****************************************************************************************************
void darr_neg(darr_t* arr1, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = -arr1->p_data[i];
        
    }    

}
// ----------------------------------------------------------------------------------------------------






// 1.2. Addition.

// 1.2.1. Real Array - Real Array.
// ****************************************************************************************************
void darr_sum_RR(darr_t* arr1, darr_t* arr2, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] + arr2->p_data[i];

    }
    
}
// ----------------------------------------------------------------------------------------------------


// 1.2.2. Real Array - Real Scalar.
// ****************************************************************************************************
void darr_sum_Rr(darr_t* arr1, coeff_t num, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] + num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------



















// 1.3. Subtraction.

// 1.3.1. Real Array  - Real Array.
// ****************************************************************************************************
void darr_sub_RR(darr_t* arr1, darr_t* arr2, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;


    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] - arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------

// 1.3.2. Real Array  - Real Scalar.
// ****************************************************************************************************
void darr_sub_Rr(darr_t* arr1, coeff_t num, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] - num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// 1.3.3. Real Scalar - Real Array.
// ****************************************************************************************************
void darr_sub_rR(coeff_t num, darr_t* arr1, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = num - arr1->p_data[i];
        
    }    

}
// ----------------------------------------------------------------------------------------------------





























// 1.4. Multiplication.

// 1.4.1. Real Array - Real Array.
// ****************************************************************************************************
void darr_mul_RR(darr_t* arr1, darr_t* arr2, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] * arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------



// 1.4.2. Real Array - Real Scalar.
// ****************************************************************************************************
void darr_mul_Rr(darr_t* arr1, coeff_t num, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] * num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------


















// 1.5. Division

// 1.5.1. Real Array  - Real Array.
// ****************************************************************************************************
void darr_div_RR(darr_t* arr1, darr_t* arr2, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] / arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------


// 1.5.2. Real Array  - Real Scalar.
// ****************************************************************************************************
void darr_div_Rr(darr_t* arr1, coeff_t num, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] / num;
        
    }
    
}
// ----------------------------------------------------------------------------------------------------

// 1.5.3. Real Scalar - Real Array.
// ****************************************************************************************************
void darr_div_rR(coeff_t num, darr_t* arr2, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr2->size;
    aRes->ncols = arr2->ncols;
    aRes->nrows = arr2->nrows;

    for (i = 0; i < arr2->size; i++){

        aRes->p_data[i] = num / arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------



