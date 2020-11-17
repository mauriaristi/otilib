






// 1. Elementwise operations.

// 1.1. Negation.
// ****************************************************************************************************
void carr_neg_to(carr_t* arr1, carr_t* aRes){
    
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
void carr_self_neg( carr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] = -res->p_data[i] ;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
carr_t carr_neg(carr_t* arr1){
    
    carr_t aRes = carr_copy(arr1);
    int64_t i;

    for (i = 0; i < aRes.size; i++){

        aRes.p_data[i] *= -1;
        
    }    

    return aRes;

}
// ----------------------------------------------------------------------------------------------------






// 1.2. Addition.

// 1.2.1. Real Array - Real Array.

// ****************************************************************************************************
carr_t carr_sum_RR(carr_t* arr1, carr_t* arr2){
    
    carr_t aRes = carr_copy(arr1);
    int64_t i;

    
    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] += arr2->p_data[i];

    }

    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------


// 1.2.2. Real Array - Real Scalar.
// ****************************************************************************************************
carr_t carr_sum_rR(coeff_t num, carr_t* arr1){
    
    carr_t aRes = carr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] += num;
        
    }    

    return aRes;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
carr_t carr_sum_Rr(carr_t* arr1, coeff_t num){
    
    return carr_sum_rR( num, arr1);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void carr_sum_RR_to(carr_t* arr1, carr_t* arr2, carr_t* aRes){
    
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
void carr_self_sum_R(carr_t* arr1, carr_t* res){
    
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        res->p_data[i] += arr1->p_data[i];

    }
    
}
// ----------------------------------------------------------------------------------------------------



// 1.2.2. Real Array - Real Scalar.
// ****************************************************************************************************
void carr_sum_rR_to(coeff_t num, carr_t* arr1, carr_t* aRes){
    
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
void carr_sum_Rr_to(carr_t* arr1, coeff_t num, carr_t* aRes){
    
    carr_sum_rR_to( num, arr1, aRes);    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void carr_self_sum_r(coeff_t num, carr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] += num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

















// 1.3. Subtraction.

// 1.3.1. Real Array  - Real Array.
// ****************************************************************************************************
carr_t carr_sub_RR(carr_t* arr1, carr_t* arr2){
    
    carr_t aRes = carr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] -= arr2->p_data[i];
        
    }
    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------

// 1.3.2. Real Array  - Real Scalar.
// ****************************************************************************************************
carr_t carr_sub_Rr(carr_t* arr1, coeff_t num){
    
    carr_t aRes = carr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] -= num;
        
    }    
    return aRes;

}
// ----------------------------------------------------------------------------------------------------

// 1.3.3. Real Scalar - Real Array.
// ****************************************************************************************************
carr_t carr_sub_rR(coeff_t num, carr_t* arr1){
    
    carr_t aRes = carr_neg(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] += num;
        
    }    
    return aRes;

}
// ----------------------------------------------------------------------------------------------------


// 1.3.1. Real Array  - Real Array.
// ****************************************************************************************************
void carr_sub_RR_to(carr_t* arr1, carr_t* arr2, carr_t* aRes){
    
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
void carr_self_sub_R(carr_t* arr1, carr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] -= arr1->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------

// 1.3.2. Real Array  - Real Scalar.
// ****************************************************************************************************
void carr_sub_Rr_to(carr_t* arr1, coeff_t num, carr_t* aRes){
    
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
void carr_sub_rR_to(coeff_t num, carr_t* arr1, carr_t* aRes){
    
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
void carr_self_sub_r(coeff_t num, carr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] -= num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------



























// 1.4. Multiplication.
// ****************************************************************************************************
carr_t carr_mul_RR(carr_t* arr1, carr_t* arr2){
    
    carr_t aRes = carr_copy(arr1);
    int64_t i;

    for (i = 0; i < aRes.size; i++){

        aRes.p_data[i] *= arr2->p_data[i];
        
    }

    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
carr_t carr_mul_rR(coeff_t num, carr_t* arr1){
    
    int64_t i;
    carr_t aRes = carr_copy(arr1);

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] *= num;
        
    }

    return aRes;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
carr_t carr_mul_Rr( carr_t* arr1, coeff_t num){
    
    return carr_mul_rR( num, arr1);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void carr_mul_RR_to(carr_t* arr1, carr_t* arr2, carr_t* aRes){
    
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
void carr_self_mul_R(carr_t* arr1, carr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] *= arr1->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void carr_mul_and_selfsum_RR_to(carr_t* arr1, carr_t* arr2, carr_t* aRes){
    
    int64_t i;


    // This for is pararellizable
    for (i = 0; i < arr1->size; i++){

        aRes->p_data[i] += arr1->p_data[i] * arr2->p_data[i];
        
    }
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void carr_mul_rR_to(coeff_t num, carr_t* arr1, carr_t* aRes){
    
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
void carr_mul_Rr_to(carr_t* arr1, coeff_t num, carr_t* aRes){
    
    carr_mul_rR_to( num, arr1, aRes);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void carr_self_mul_r(coeff_t num, carr_t* res){
    
    int64_t i;

    for (i = 0; i < res->size; i++){

        res->p_data[i] *= num;
        
    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void carr_mul_and_selfsum_rR_to(coeff_t num, carr_t* arr1, carr_t* aRes){
    
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
void carr_mul_and_selfsum_Rr_to( carr_t* arr1, coeff_t num, carr_t* aRes){
    
    carr_mul_and_selfsum_rR_to( num, arr1, aRes);

}
// ----------------------------------------------------------------------------------------------------















// 1.5. Division
// 1.5.1. Real Array  - Real Array.
// ****************************************************************************************************
carr_t carr_div_RR(carr_t* arr1, carr_t* arr2){
    
    carr_t aRes=carr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] /= arr2->p_data[i];
        
    }

    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------


// 1.5.2. Real Array  - Real Scalar.
// ****************************************************************************************************
carr_t carr_div_Rr(carr_t* arr1, coeff_t num){
    
    carr_t aRes = carr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] /= num;
        
    }

    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------

// 1.5.3. Real Scalar - Real Array.
// ****************************************************************************************************
carr_t carr_div_rR(coeff_t num, carr_t* arr1){
    
    carr_t aRes = carr_copy(arr1);
    int64_t i;

    for (i = 0; i < arr1->size; i++){

        aRes.p_data[i] = num / arr1->p_data[i];
        
    }

    return aRes;
    
}
// ----------------------------------------------------------------------------------------------------

// 1.5.1. Real Array  - Real Array.
// ****************************************************************************************************
void carr_div_RR_to(carr_t* arr1, carr_t* arr2, carr_t* aRes){
    
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
void carr_div_Rr_to(carr_t* arr1, coeff_t num, carr_t* aRes){
    
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
void carr_div_rR_to(coeff_t num, carr_t* arr2, carr_t* aRes){
    
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
void carr_gem_RR_to(carr_t* arr1, carr_t* arr2, carr_t* arr3, carr_t* res){
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    carr_dimCheck_RR_elementwise(arr1,arr2,res);
    carr_dimCheck_RR_elementwise(arr1,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){

        res->p_data[i] = arr1->p_data[i] * arr2->p_data[i] + arr3->p_data[i];

    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void carr_gem_rR_to(coeff_t arr1, carr_t* arr2, carr_t* arr3, carr_t* res){
    // This function does GEM (GEneral Multiplication): RES = ARR1*ARR2 + ARR3
    // Allows to do the following RES = ARR1*ARR2 + RES
    uint64_t i;

    // Check inputs:
    carr_dimCheck_RR_elementwise(arr2,arr3,res);

    // Loop for every element and add real to the oti number.
    for ( i = 0; i < res->size; i++){

        res->p_data[i] = arr1 * arr2->p_data[i] + arr3->p_data[i];

    }
}
// ----------------------------------------------------------------------------------------------------




