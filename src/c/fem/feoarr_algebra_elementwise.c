




// ****************************************************************************************************
void feoarr_sub(feoarr_t* p_arr1, feoarr_t* p_arr2, feoarr_t* p_arrRes, 
    dhelpl_t dhl){
    /*
    feoarr_det(feoarr_t* p_arr1, feoarr_t* p_arrRes, dhelpl_t dhl)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array

        ->   p_arr2:    Array
        
        -> p_arrRes:    Result of operation.

        ->     dhl:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        feoarr_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }


    for (i = 0; i<p_arr1->nIntPts; i++){

        sotiarray_matsub_otioti(&p_arr1->p_data[i], &p_arr2->p_data[i], 
            &p_arrRes->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void feoarr_sum(feoarr_t* p_arr1, feoarr_t* p_arr2, feoarr_t* p_arrRes, 
    dhelpl_t dhl){
    /*
    feoarr_det(feoarr_t* p_arr1, feoarr_t* p_arrRes, dhelpl_t dhl)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array

        ->   p_arr2:    Array
        
        -> p_arrRes:    Result of operation.

        ->     dhl:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        feoarr_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }


    for (i = 0; i<p_arr1->nIntPts; i++){

        sotiarray_matsum_otioti(&p_arr1->p_data[i], &p_arr2->p_data[i], 
            &p_arrRes->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void feoarr_mul_oti(feoarr_t* p_arr1, otinum_t* num2, feoarr_t* p_arrRes, 
    dhelpl_t dhl){
    /*
    feoarr_det(feoarr_t* p_arr1, feoarr_t* p_arrRes, dhelpl_t dhl)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array

        ->   p_arr2:    Array
        
        -> p_arrRes:    Result of operation.

        ->     dhl:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        feoarr_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }

    for (i = 0; i<p_arr1->nIntPts; i++){

        sotiarray_mul_oti(&p_arr1->p_data[i], num2, &p_arrRes->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void feoarr_neg(feoarr_t* p_arr1, feoarr_t* p_arrRes){
    /*
    feoarr_det(feoarr_t* p_arr1, feoarr_t* p_arrRes, dhelpl_t dhl)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array

        ->   p_arr2:    Array
        
        -> p_arrRes:    Result of operation.

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        feoarr_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }

    for (i = 0; i<p_arr1->nIntPts; i++){

        sotiarray_neg(&p_arr1->p_data[i], &p_arrRes->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void feoarr_mul_rF(coeff_t num, feoarr_t* arr, feoarr_t* res, dhelpl_t dhl){
    /*
    feoarr_det(feoarr_t* p_arr1, feoarr_t* p_arrRes, dhelpl_t dhl)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array

        ->   p_arr2:    Array
        
        -> p_arrRes:    Result of operation.

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        feoarr_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }

    for (i = 0; i<p_arr1->nIntPts; i++){

        sotiarray_mul_R(&p_arr1->p_data[i], num2, &p_arrRes->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------





