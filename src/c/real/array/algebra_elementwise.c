






// 1. Elementwise operations.

// 1.1. Negation.
// ****************************************************************************************************
void darr_neg_to(darr_t* arr1, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = -arr1->p_data[i];
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_self_neg( darr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] = -res->p_data[i] ;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
darr_t darr_neg(darr_t* arr1){
    
    darr_t aRes = darr_copy(arr1);
    int64_t i;

    for (i = 0; i < aRes.size; i++){

        aRes.p_data[i] *= -1;
        
    }    

    return aRes;

}
// ----------------------------------------------------------------------------------------------------

// 1.1. Negation.
// ****************************************************************************************************
void darr_abs_to(darr_t* arr1, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = abs(arr1->p_data[i]);
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_self_abs( darr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] = abs(res->p_data[i]) ;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
darr_t darr_abs(darr_t* arr1){
    
    darr_t aRes = darr_copy(arr1);
    int64_t i;

    for (i = 0; i < aRes.size; i++){

        aRes.p_data[i] = abs(aRes.p_data[i]);
        
    }    

    return aRes;

}
// ----------------------------------------------------------------------------------------------------





// 1.2. Addition.

// 1.2.1. Real Array - Real Array.

// ****************************************************************************************************
darr_t darr_sum_RR(darr_t* arr1, darr_t* arr2){
    
    darr_t aRes = darr_copy(arr1);
    int64_t i;

    
    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] += arr2->p_data[i];

    }

    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------


// 1.2.2. Real Array - Real Scalar.
// ****************************************************************************************************
darr_t darr_sum_rR(coeff_t num, darr_t* arr1){
    
    darr_t aRes = darr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] += num;
        
    }    

    return aRes;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
darr_t darr_sum_Rr(darr_t* arr1, coeff_t num){
    
    return darr_sum_rR( num, arr1);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darr_sum_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] + arr2->p_data[i];

    }
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darr_self_sum_R(darr_t* arr1, darr_t* res){
    
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        res->p_data[i] += arr1->p_data[i];

    }
    
}
// ----------------------------------------------------------------------------------------------------



// 1.2.2. Real Array - Real Scalar.
// ****************************************************************************************************
void darr_sum_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] + num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_sum_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes){
    
    darr_sum_rR_to( num, arr1, aRes);    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_self_sum_r(coeff_t num, darr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] += num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

















// 1.3. Subtraction.

// 1.3.1. Real Array  - Real Array.
// ****************************************************************************************************
darr_t darr_sub_RR(darr_t* arr1, darr_t* arr2){
    
    darr_t aRes = darr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] -= arr2->p_data[i];
        
    }
    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------

// 1.3.2. Real Array  - Real Scalar.
// ****************************************************************************************************
darr_t darr_sub_Rr(darr_t* arr1, coeff_t num){
    
    darr_t aRes = darr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] -= num;
        
    }    
    return aRes;

}
// ----------------------------------------------------------------------------------------------------

// 1.3.3. Real Scalar - Real Array.
// ****************************************************************************************************
darr_t darr_sub_rR(coeff_t num, darr_t* arr1){
    
    darr_t aRes = darr_neg(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] += num;
        
    }    
    return aRes;

}
// ----------------------------------------------------------------------------------------------------


// 1.3.1. Real Array  - Real Array.
// ****************************************************************************************************
void darr_sub_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;


    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] - arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------

// 1.3.1. Real Array  - Real Array.
// ****************************************************************************************************
void darr_self_sub_R(darr_t* arr1, darr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] -= arr1->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------

// 1.3.2. Real Array  - Real Scalar.
// ****************************************************************************************************
void darr_sub_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes){
    
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
void darr_sub_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = num - arr1->p_data[i];
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_self_sub_r(coeff_t num, darr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] -= num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------



























// 1.4. Multiplication.
// ****************************************************************************************************
darr_t darr_mul_RR(darr_t* arr1, darr_t* arr2){
    
    darr_t aRes = darr_copy(arr1);
    int64_t i;

    for (i = 0; i < aRes.size; i++){

        aRes.p_data[i] *= arr2->p_data[i];
        
    }

    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
darr_t darr_mul_rR(coeff_t num, darr_t* arr1){
    
    int64_t i;
    darr_t aRes = darr_copy(arr1);

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] *= num;
        
    }

    return aRes;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
darr_t darr_mul_Rr( darr_t* arr1, coeff_t num){
    
    return darr_mul_rR( num, arr1);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darr_mul_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] * arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_self_mul_R(darr_t* arr1, darr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] *= arr1->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_mul_and_selfsum_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes){
    
    int64_t i;


    // This for is pararellizable
    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] += arr1->p_data[i] * arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darr_mul_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] = arr1->p_data[i] * num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_mul_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes){
    
    darr_mul_rR_to( num, arr1, aRes);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_self_mul_r(coeff_t num, darr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] *= num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_mul_and_selfsum_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr1->size;
    aRes->ncols = arr1->ncols;
    aRes->nrows = arr1->nrows;

    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] += arr1->p_data[i] * num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_mul_and_selfsum_Rr_to( darr_t* arr1, coeff_t num, darr_t* aRes){
    
    darr_mul_and_selfsum_rR_to( num, arr1, aRes);

}
// ----------------------------------------------------------------------------------------------------















// 1.5. Division
// 1.5.1. Real Array  - Real Array.
// ****************************************************************************************************
darr_t darr_div_RR(darr_t* arr1, darr_t* arr2){
    
    darr_t aRes=darr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] /= arr2->p_data[i];
        
    }

    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------


// 1.5.2. Real Array  - Real Scalar.
// ****************************************************************************************************
darr_t darr_div_Rr(darr_t* arr1, coeff_t num){
    
    darr_t aRes = darr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] /= num;
        
    }

    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------

// 1.5.3. Real Scalar - Real Array.
// ****************************************************************************************************
darr_t darr_div_rR(coeff_t num, darr_t* arr1){
    
    darr_t aRes = darr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] = num / arr1->p_data[i];
        
    }

    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------

// 1.5.1. Real Array  - Real Array.
// ****************************************************************************************************
void darr_div_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes){
    
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
void darr_div_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes){
    
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
void darr_div_rR_to(coeff_t num, darr_t* arr2, darr_t* aRes){
    
    int64_t i;

    aRes->size = arr2->size;
    aRes->ncols = arr2->ncols;
    aRes->nrows = arr2->nrows;

    for (i = 0; i < arr2->size; i++){

        aRes->p_data[i] = num / arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------












// ****************************************************************************************************
void darr_gem_RR_to(darr_t* arr1, darr_t* arr2, darr_t* arr3, darr_t* res){
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    darr_dimCheck_RR_elementwise(arr1,arr2,res);
    darr_dimCheck_RR_elementwise(arr1,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){

        res->p_data[i] = arr1->p_data[i] * arr2->p_data[i] + arr3->p_data[i];

    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darr_gem_rR_to(coeff_t arr1, darr_t* arr2, darr_t* arr3, darr_t* res){
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    darr_dimCheck_RR_elementwise(arr2,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){

        res->p_data[i] = arr1 * arr2->p_data[i] + arr3->p_data[i];

    }
}
// ----------------------------------------------------------------------------------------------------




