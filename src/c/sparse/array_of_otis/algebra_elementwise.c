



// 1. Elementwise operations.
// 1.1. Negation.
// ****************************************************************************************************
arrso_t arrso_neg(arrso_t* arr, arrso_t* res){
       
    arrso_t res = arrso_empty_like( arr, dhl);
    
    arrso_neg_to(arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------







// 1.2. Addition.
// 1.2.1. OTI Array - OTI Array.
// 1.2.2. OTI Array - Real Array.
// 1.2.3. OTI Array - OTI Scalar.
// 1.2.3. OTI Array - Real Scalar.
// ****************************************************************************************************
void arrso_matsum_otiR(arrso_t* p_arr1, darray_t* p_arr2, arrso_t* p_arrRes){
        
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_sumf(
            &p_arr1->p_data[i]  ,
             p_arr2->p_data[i]  ,
            &tmp);
        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_matsum_otioti(arrso_t* p_arr1, arrso_t* p_arr2, arrso_t* p_arrRes, 
                        dhelpl_t dhl){
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_sum(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   dhl );
        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void arrso_sum_oti(arrso_t* p_arr1, sotinum_t* num2, arrso_t* p_arrRes, 
                        dhelpl_t dhl){
        
    uint64_t i;

    sotinum_t tmp;

    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_sum(
            &p_arr1->p_data[i]  ,
            num2  ,
            &tmp,   dhl );

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void arrso_sum_R(arrso_t* p_arr1, double num2, arrso_t* p_arrRes){
        
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_sumf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);
        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



















































// 1.3. Subtraction.
// 1.3.1. OTI Array   - OTI Array.
// 1.3.2. OTI Array   - Real Array.
// 1.3.3. Real Array  - OTI Array.
// 1.3.4. OTI Array   - OTI Scalar.
// 1.3.4. OTI Array   - Real Scalar.
// 1.3.5. OTI Scalar  - OTI Array.
// 1.3.5. Real Scalar - OTI Array.



// ****************************************************************************************************
void arrso_matsub_Roti(arrso_t* p_arr1, darray_t* p_arr2, arrso_t* p_arrRes){
        
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_fsub(
            &p_arr1->p_data[i]  ,
             p_arr2->p_data[i]  ,
            &tmp);

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void arrso_matsub_otiR(arrso_t* p_arr1, darray_t* p_arr2, arrso_t* p_arrRes){
    
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_subf(
            &p_arr1->p_data[i]  ,
             p_arr2->p_data[i]  ,
            &tmp);

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void arrso_matsub_otioti(arrso_t* p_arr1, arrso_t* p_arr2, arrso_t* p_arrRes, 
                        dhelpl_t dhl){
    
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }

    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_sub(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   dhl );

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------






































// 1.4. Multiplication.
// 1.4.1. OTI Array - OTI Array.
// 1.4.2. OTI Array - Real Array.
// 1.4.3. OTI Array - OTI Scalar.
// 1.4.3. OTI Array - Real Scalar.


// ****************************************************************************************************
void arrso_mul_sotiarr(arrso_t* p_arr1, arrso_t* p_arr2, arrso_t* p_arrRes, 
                        dhelpl_t dhl){
        
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_mul(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   dhl );

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_mul_oti(arrso_t* p_arr1, sotinum_t* num2, arrso_t* p_arrRes, 
                        dhelpl_t dhl){

    // Perform: A*a
    // A: OTI matrix.
    // a: OTI scalar.
        
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){
        
        soti_mul(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp,   dhl );
        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void arrso_mul_R(arrso_t* p_arr1, double num2, arrso_t* p_arrRes){
    
    // Perform A*c = c*A
    // A: OTI matrix.
    // c: Real numeber.

    uint64_t i;
    sotinum_t tmp;

    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){
        
        soti_mulf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);
        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------






















































// 1.5. Division
// 1.3.1. OTI Array   - OTI Array.
// 1.3.2. OTI Array   - Real Array.
// 1.3.3. Real Array  - OTI Array.
// 1.3.4. OTI Array   - OTI Scalar.
// 1.3.4. OTI Array   - Real Scalar.
// 1.3.5. OTI Scalar  - OTI Array.
// 1.3.5. Real Scalar - OTI Array.



// ****************************************************************************************************
void arrso_oti_div(arrso_t* p_arr1, sotinum_t* num2, arrso_t* p_arrRes, 
                        dhelpl_t dhl){
    
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_div(
            num2  ,
            &p_arr1->p_data[i]  ,
            &tmp,   dhl );

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void arrso_matdiv_otioti(arrso_t* p_arr1, arrso_t* p_arr2, arrso_t* p_arrRes, 
                        dhelpl_t dhl){
    
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }

    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_div(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   dhl );

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------































































// ****************************************************************************************************
void arrso_div_R(arrso_t* p_arr1, double num2, arrso_t* p_arrRes){
    
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_divf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_R_div(arrso_t* p_arr1, double num2, arrso_t* p_arrRes, 
                        dhelpl_t dhl){
   
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_fdiv(
             num2 ,
            &p_arr1->p_data[i]  ,
            &tmp,
            dhl);

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_div_oti(arrso_t* p_arr1, sotinum_t* num2, arrso_t* p_arrRes, 
                        dhelpl_t dhl){
    
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_div(
            &p_arr1->p_data[i]  ,
            num2  ,
            &tmp,   dhl );

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void arrso_oti_sub(arrso_t* p_arr1, sotinum_t* num2, arrso_t* p_arrRes, 
                        dhelpl_t dhl){
        
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_sub(
            num2  ,
            &p_arr1->p_data[i]  ,
            &tmp,   dhl );

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void arrso_R_sub(arrso_t* p_arr1, double num2, arrso_t* p_arrRes){
        
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_fsub(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void arrso_sub_oti(arrso_t* p_arr1, sotinum_t* num2, arrso_t* p_arrRes, 
                        dhelpl_t dhl){
        
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_sub(
            &p_arr1->p_data[i]  ,
            num2  ,
            &tmp,   dhl );

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void arrso_sub_R(arrso_t* p_arr1, double num2, arrso_t* p_arrRes){
    
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        arrso_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_subf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);

        arrso_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------







