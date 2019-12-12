



// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
void soarr_neg(soarr_t* p_arr1, soarr_t* p_arrRes){
       
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_neg(
            &p_arr1->p_data[i]  ,
            &tmp);

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }

}
// ----------------------------------------------------------------------------------------------------







// 1.2. Addition.
// 1.2.1. OTI Array - OTI Array.
// 1.2.2. OTI Array - Real Array.
// 1.2.3. OTI Array - OTI Scalar.
// 1.2.3. OTI Array - Real Scalar.
// ****************************************************************************************************
void soarr_matsum_otiR(soarr_t* p_arr1, darray_t* p_arr2, soarr_t* p_arrRes){
        
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_sumf(
            &p_arr1->p_data[i]  ,
             p_arr2->p_data[i]  ,
            &tmp);
        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soarr_matsum_otioti(soarr_t* p_arr1, soarr_t* p_arr2, soarr_t* p_arrRes, 
                        dhelpl_t dhl){
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_sum(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   dhl );
        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void soarr_sum_oti(soarr_t* p_arr1, sotinum_t* num2, soarr_t* p_arrRes, 
                        dhelpl_t dhl){
        
    uint64_t i;

    sotinum_t tmp;

    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_sum(
            &p_arr1->p_data[i]  ,
            num2  ,
            &tmp,   dhl );

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void soarr_sum_R(soarr_t* p_arr1, double num2, soarr_t* p_arrRes){
        
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_sumf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);
        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

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
void soarr_matsub_Roti(soarr_t* p_arr1, darray_t* p_arr2, soarr_t* p_arrRes){
        
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_fsub(
            &p_arr1->p_data[i]  ,
             p_arr2->p_data[i]  ,
            &tmp);

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void soarr_matsub_otiR(soarr_t* p_arr1, darray_t* p_arr2, soarr_t* p_arrRes){
    
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_subf(
            &p_arr1->p_data[i]  ,
             p_arr2->p_data[i]  ,
            &tmp);

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void soarr_matsub_otioti(soarr_t* p_arr1, soarr_t* p_arr2, soarr_t* p_arrRes, 
                        dhelpl_t dhl){
    
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }

    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_sub(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   dhl );

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------






































// 1.4. Multiplication.
// 1.4.1. OTI Array - OTI Array.
// 1.4.2. OTI Array - Real Array.
// 1.4.3. OTI Array - OTI Scalar.
// 1.4.3. OTI Array - Real Scalar.


// ****************************************************************************************************
void soarr_mul_sotiarr(soarr_t* p_arr1, soarr_t* p_arr2, soarr_t* p_arrRes, 
                        dhelpl_t dhl){
        
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_mul(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   dhl );

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soarr_mul_oti(soarr_t* p_arr1, sotinum_t* num2, soarr_t* p_arrRes, 
                        dhelpl_t dhl){

    // Perform: A*a
    // A: OTI matrix.
    // a: OTI scalar.
        
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){
        
        soti_mul(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp,   dhl );
        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void soarr_mul_R(soarr_t* p_arr1, double num2, soarr_t* p_arrRes){
    
    // Perform A*c = c*A
    // A: OTI matrix.
    // c: Real numeber.

    uint64_t i;
    sotinum_t tmp;

    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){
        
        soti_mulf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);
        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

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
void soarr_oti_div(soarr_t* p_arr1, sotinum_t* num2, soarr_t* p_arrRes, 
                        dhelpl_t dhl){
    
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_div(
            num2  ,
            &p_arr1->p_data[i]  ,
            &tmp,   dhl );

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void soarr_matdiv_otioti(soarr_t* p_arr1, soarr_t* p_arr2, soarr_t* p_arrRes, 
                        dhelpl_t dhl){
    
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }

    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_div(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   dhl );

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------































































// ****************************************************************************************************
void soarr_div_R(soarr_t* p_arr1, double num2, soarr_t* p_arrRes){
    
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_divf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soarr_R_div(soarr_t* p_arr1, double num2, soarr_t* p_arrRes, 
                        dhelpl_t dhl){
   
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_fdiv(
             num2 ,
            &p_arr1->p_data[i]  ,
            &tmp,
            dhl);

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soarr_div_oti(soarr_t* p_arr1, sotinum_t* num2, soarr_t* p_arrRes, 
                        dhelpl_t dhl){
    
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        soti_div(
            &p_arr1->p_data[i]  ,
            num2  ,
            &tmp,   dhl );

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void soarr_oti_sub(soarr_t* p_arr1, sotinum_t* num2, soarr_t* p_arrRes, 
                        dhelpl_t dhl){
        
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_sub(
            num2  ,
            &p_arr1->p_data[i]  ,
            &tmp,   dhl );

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void soarr_R_sub(soarr_t* p_arr1, double num2, soarr_t* p_arrRes){
        
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_fsub(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void soarr_sub_oti(soarr_t* p_arr1, sotinum_t* num2, soarr_t* p_arrRes, 
                        dhelpl_t dhl){
        
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_sub(
            &p_arr1->p_data[i]  ,
            num2  ,
            &tmp,   dhl );

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void soarr_sub_R(soarr_t* p_arr1, double num2, soarr_t* p_arrRes){
    
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        soarr_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        soti_subf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);

        soarr_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------







