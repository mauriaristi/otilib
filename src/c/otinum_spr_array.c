#include "oti/otinum_spr_array.h"


// ----------------------------------------------------------------------------------------------------
// ---------------------------------     SOTIMAT FUNCTIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_sotiarray_invert(sotiarray_t* p_arr1, sotiarray_t* p_arrRes, directionHelper* p_dH){
    /*
    c_sotiarray_transpose(sotiarray_t* p_arr1, sotiarray_t* p_arrRes)

    Transpose a  sotiarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    sotinum_t detInv,tmp1, tmp2, tmp;
    sotiarray_t tmpA1;

    if (p_arr1->ncols != p_arr1->nrows){
        printf("--- DimensionError in matrix inverse. Only square matrices are invertible. ---\n");
        exit(1);
    }

    if        (p_arr1->ncols == 1){

        if (p_arrRes->p_data == NULL){
    
            c_sotiarray_zeros( p_arrRes, p_arr1->ncols, p_arr1->nrows, p_arr1->order);

        }

        c_soti_pow(&p_arr1->p_data[0], -1.0, p_dH, &tmp);

        c_sotiarray_setItemOTI_indx(&tmp,0,p_arrRes);


    } else if (p_arr1->ncols == 2){

        if (p_arrRes->p_data == NULL){
    
            c_sotiarray_zeros( p_arrRes, p_arr1->ncols, p_arr1->nrows, p_arr1->order);

        }

        c_sotiarray_det( p_arr1, &tmp1, p_dH); // Get determinant.
        c_soti_pow(&tmp1, -1.0, p_dH,&detInv);
        c_soti_free(&tmp1);

        // Set position 0,0
        c_soti_mul(
            &p_arr1->p_data[3],
            &detInv,
            &tmp,
            p_dH);
        c_sotiarray_setItemOTI_indx(&tmp,0,p_arrRes);


        // Set position 0,1
        c_soti_neg(&p_arr1->p_data[1],&tmp1);
        c_soti_mul(
            &tmp1,
            &detInv,
            &tmp,
            p_dH);
        c_soti_free(&tmp1);
        c_sotiarray_setItemOTI_indx(&tmp,1,p_arrRes);

        
        // Set position 1,0
        c_soti_neg(&p_arr1->p_data[2],&tmp1);
        c_soti_mul(
            &tmp1,
            &detInv,
            &tmp,
            p_dH);
        c_soti_free(&tmp1);
        c_sotiarray_setItemOTI_indx(&tmp,2,p_arrRes);


        // Set position 1,1
        c_soti_mul(
            &p_arr1->p_data[0],
            &detInv,
            &tmp,
            p_dH);
        c_sotiarray_setItemOTI_indx(&tmp,3,p_arrRes);

        c_soti_free(&detInv);
        


    } else if (p_arr1->ncols == 3){

        c_sotiarray_zeros( &tmpA1, 2, 2, p_arr1->order);

        if (p_arrRes->p_data == NULL){
            c_sotiarray_zeros( p_arrRes, p_arr1->ncols, p_arr1->nrows, p_arr1->order);
        }

        c_sotiarray_det( p_arr1, &tmp1, p_dH); // Get determinant.
        c_soti_pow(&tmp1, -1.0, p_dH, &detInv);
        c_soti_free(&tmp1);



        // Set position 0,0
        tmpA1.p_data[0] = p_arr1->p_data[4];
        tmpA1.p_data[1] = p_arr1->p_data[5];
        tmpA1.p_data[2] = p_arr1->p_data[7];
        tmpA1.p_data[3] = p_arr1->p_data[8];
        c_sotiarray_det( &tmpA1, &tmp2, p_dH);
        c_soti_mul(
            &tmp2,
            &detInv,
            &tmp,
            p_dH);
        c_soti_free(&tmp2);
        c_sotiarray_setItemOTI_indx(&tmp,0,p_arrRes);

        // Set position 0,1
        tmpA1.p_data[0] = p_arr1->p_data[2];
        tmpA1.p_data[1] = p_arr1->p_data[1];
        tmpA1.p_data[2] = p_arr1->p_data[8];
        tmpA1.p_data[3] = p_arr1->p_data[7];
        c_sotiarray_det( &tmpA1, &tmp2, p_dH);
        c_soti_mul(
            &tmp2,
            &detInv,
            &tmp,
            p_dH);
        c_soti_free(&tmp2);
        c_sotiarray_setItemOTI_indx(&tmp,1,p_arrRes);

        // Set position 0,2
        tmpA1.p_data[0] = p_arr1->p_data[1];
        tmpA1.p_data[1] = p_arr1->p_data[2];
        tmpA1.p_data[2] = p_arr1->p_data[4];
        tmpA1.p_data[3] = p_arr1->p_data[5];
        c_sotiarray_det( &tmpA1, &tmp2, p_dH);
        c_soti_mul(
            &tmp2,
            &detInv,
            &tmp,
            p_dH);
        c_soti_free(&tmp2);
        c_sotiarray_setItemOTI_indx(&tmp,2,p_arrRes);




        // Set position 1,0
        tmpA1.p_data[0] = p_arr1->p_data[5];
        tmpA1.p_data[1] = p_arr1->p_data[3];
        tmpA1.p_data[2] = p_arr1->p_data[8];
        tmpA1.p_data[3] = p_arr1->p_data[6];
        c_sotiarray_det( &tmpA1, &tmp2, p_dH);
        c_soti_mul(
            &tmp2,
            &detInv,
            &tmp,
            p_dH);
        c_soti_free(&tmp2);
        c_sotiarray_setItemOTI_indx(&tmp,3,p_arrRes);

        // Set position 1,1
        tmpA1.p_data[0] = p_arr1->p_data[0];
        tmpA1.p_data[1] = p_arr1->p_data[2];
        tmpA1.p_data[2] = p_arr1->p_data[6];
        tmpA1.p_data[3] = p_arr1->p_data[8];
        c_sotiarray_det( &tmpA1, &tmp2, p_dH);
        c_soti_mul(
            &tmp2,
            &detInv,
            &tmp,
            p_dH);
        c_soti_free(&tmp2);
        c_sotiarray_setItemOTI_indx(&tmp,4,p_arrRes);

        // Set position 1,2
        tmpA1.p_data[0] = p_arr1->p_data[2];
        tmpA1.p_data[1] = p_arr1->p_data[0];
        tmpA1.p_data[2] = p_arr1->p_data[5];
        tmpA1.p_data[3] = p_arr1->p_data[3];
        c_sotiarray_det( &tmpA1, &tmp2, p_dH);
        c_soti_mul(
            &tmp2,
            &detInv,
            &tmp,
            p_dH);
        c_soti_free(&tmp2);
        c_sotiarray_setItemOTI_indx(&tmp,5,p_arrRes);




        // Set position 2,0
        tmpA1.p_data[0] = p_arr1->p_data[3];
        tmpA1.p_data[1] = p_arr1->p_data[4];
        tmpA1.p_data[2] = p_arr1->p_data[6];
        tmpA1.p_data[3] = p_arr1->p_data[7];
        c_sotiarray_det( &tmpA1, &tmp2, p_dH);
        c_soti_mul(
            &tmp2,
            &detInv,
            &tmp,
            p_dH);
        c_soti_free(&tmp2);
        c_sotiarray_setItemOTI_indx(&tmp,6,p_arrRes);

        // Set position 2,1
        tmpA1.p_data[0] = p_arr1->p_data[1];
        tmpA1.p_data[1] = p_arr1->p_data[0];
        tmpA1.p_data[2] = p_arr1->p_data[7];
        tmpA1.p_data[3] = p_arr1->p_data[6];
        c_sotiarray_det( &tmpA1, &tmp2, p_dH);
        c_soti_mul(
            &tmp2,
            &detInv,
            &tmp,
            p_dH);
        c_soti_free(&tmp2);
        c_sotiarray_setItemOTI_indx(&tmp,7,p_arrRes);

        // Set position 2,2
        tmpA1.p_data[0] = p_arr1->p_data[0];
        tmpA1.p_data[1] = p_arr1->p_data[1];
        tmpA1.p_data[2] = p_arr1->p_data[3];
        tmpA1.p_data[3] = p_arr1->p_data[4];
        c_sotiarray_det( &tmpA1, &tmp2, p_dH);
        c_soti_mul(
            &tmp2,
            &detInv,
            &tmp,
            p_dH);
        c_soti_free(&tmp2);
        c_sotiarray_setItemOTI_indx(&tmp,8,p_arrRes);


        c_soti_free(&detInv);
        free(tmpA1.p_data);


    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_det(sotiarray_t* p_arr1, sotinum_t* p_res, directionHelper* p_dH){
    /*
    c_sotiarray_det(sotiarray_t* p_arr1, sotinum_t* p_res)

    Determinant of a sotiarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i, j ;
    sotinum_t tmp1, tmp2, tmp3;

    if (p_arr1->ncols != p_arr1->nrows){
        printf("--- DimensionError in matrix determinant. Only square matrices are valid. ---\n");
        exit(1);
    }



    if        (p_arr1->ncols == 1){

        c_soti_copy(p_res, &p_arr1->p_data[0]);

    } else if (p_arr1->ncols == 2){

        c_soti_mul(
            &p_arr1->p_data[0],
            &p_arr1->p_data[3],
            &tmp1,
            p_dH   ); 

        c_soti_mul(
            &p_arr1->p_data[1],
            &p_arr1->p_data[2],
            &tmp2,
            p_dH   ); 

        c_soti_sub(
            &tmp1,
            &tmp2,
            p_res,
            p_dH);

        c_soti_free(&tmp1);
        c_soti_free(&tmp2);

    } else if (p_arr1->ncols == 3){

        c_soti_createEmpty(p_res,0,p_arr1->order); // Initialize as zero.

        for (j=0; j<p_arr1->ncols; j++){
            
            c_soti_copy(&tmp1,&p_arr1->p_data[j]);
            
            
            for (i=1; i<p_arr1->nrows; i++){        
                
                tmp2 = tmp1;
                
                c_soti_mul(
                    &p_arr1->p_data[ ( (i+j)%p_arr1->ncols ) + i*p_arr1->ncols],
                    &tmp2,
                    &tmp1,
                    p_dH   );  

                c_soti_free(&tmp2);

            }

            tmp3 = *p_res;
            c_soti_sum(&tmp3,&tmp1,p_res,p_dH);
            
            c_soti_free(&tmp1);
            c_soti_free(&tmp3);

        }

        for (j=0; j<p_arr1->ncols; j++){
            
            c_soti_copy(&tmp1,&p_arr1->p_data[p_arr1->ncols-1-j]);
            
            for (i=1; i<p_arr1->nrows; i++){        
                
                tmp2 = tmp1;
                
                c_soti_mul(
                    &p_arr1->p_data[ (p_arr1->ncols-1 - (i+j)%p_arr1->ncols ) + i*p_arr1->ncols],
                    &tmp2,
                    &tmp1,
                    p_dH   );    

                c_soti_free(&tmp2);

            }

            tmp3 = *p_res;
            c_soti_sub(&tmp3,&tmp1,p_res,p_dH);
            
            c_soti_free(&tmp1);
            c_soti_free(&tmp3);

        }
    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_transpose(sotiarray_t* p_arr1, sotiarray_t* p_arrRes){
    /*
    c_sotiarray_transpose(sotiarray_t* p_arr1, sotiarray_t* p_arrRes)

    Transpose a  sotiarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1 + p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i, j ;
    sotinum_t tmp;

    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->nrows; i++){

        for (j=0; j<p_arr1->ncols; j++){
            
            c_soti_copy(
                &tmp, 
                &p_arr1->p_data[  j + i*p_arr1->ncols  ]);

            c_sotiarray_setItemOTI( &tmp, j, i, p_arrRes);

        }

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_mul_sotiarr(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }

    for (i=0; i<p_arr1->size; i++){

        c_soti_mul(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   p_dH );

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_neg(sotiarray_t* p_arr1, sotiarray_t* p_arrRes){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        c_soti_neg(
            &p_arr1->p_data[i]  ,
            &tmp);

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_matsub_Roti(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        c_soti_fsub(
            &p_arr1->p_data[i]  ,
             p_arr2->p_data[i]  ,
            &tmp);

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_matsub_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        c_soti_subf(
            &p_arr1->p_data[i]  ,
             p_arr2->p_data[i]  ,
            &tmp);

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_matsub_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }

    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }

    for (i=0; i<p_arr1->size; i++){

        c_soti_sub(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   p_dH );

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_oti_div(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        c_soti_div(
            num2  ,
            &p_arr1->p_data[i]  ,
            &tmp,   p_dH );

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_matdiv_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }

    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }

    for (i=0; i<p_arr1->size; i++){

        c_soti_div(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   p_dH );

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_div_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        c_soti_divf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_R_div(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        c_soti_fdiv(
             num2 ,
            &p_arr1->p_data[i]  ,
            &tmp,
            p_dH);

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_div_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }

    for (i=0; i<p_arr1->size; i++){

        c_soti_div(
            &p_arr1->p_data[i]  ,
            num2  ,
            &tmp,   p_dH );

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_oti_sub(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        c_soti_sub(
            num2  ,
            &p_arr1->p_data[i]  ,
            &tmp,   p_dH );

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_sotiarray_R_sub(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        c_soti_fsub(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void c_sotiarray_sub_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        c_soti_sub(
            &p_arr1->p_data[i]  ,
            num2  ,
            &tmp,   p_dH );

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_sotiarray_sub_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        c_soti_subf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);

        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_sum_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        c_soti_sum(
            &p_arr1->p_data[i]  ,
            num2  ,
            &tmp,   p_dH );
        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_sotiarray_sum_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        c_soti_sumf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);
        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_mul_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_getItem(sotiarray_t* p_array, uint64_t i, uint64_t j, sotinum_t* num)

    multiply two sparse oti number arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of <p_arr1,p_arr2>.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){
        
        c_soti_mul(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp,   p_dH );
        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_mul_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes){
    /*
    c_sotiarray_getItem(sotiarray_t* p_array, uint64_t i, uint64_t j, sotinum_t* num)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;

    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr1->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){
        
        c_soti_mulf(
            &p_arr1->p_data[i]  ,
             num2  ,
            &tmp);
        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_matmul_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_getItem(sotiarray_t* p_array, uint64_t i, uint64_t j, sotinum_t* num)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i, j, k;
    sotinum_t tmp1, tmp2, tmp3;
    // Check correctness of dimensions:
    if( (p_arr1->nrows!=p_arr2->ncols) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr2->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->nrows; i++){
        
        for(j=0; j<p_arr2->ncols; j++){
            
            c_soti_createEmpty(&tmp1, 0, p_arr1->order);

            for(k=0; k<p_arr1->ncols; k++){

                c_soti_mulf(
                    &p_arr1->p_data[k+i*p_arr1->ncols]  ,
                     p_arr2->p_data[j+k*p_arr2->ncols]  ,
                    &tmp3);

                tmp2 = tmp1; // Copy all information between elements
                
                // Sum
                c_soti_sum(&tmp2,&tmp3,&tmp1,p_dH);

                // Free memory ...
                c_soti_free(&tmp2);
                c_soti_free(&tmp3);

            }

            c_sotiarray_setItemOTI( &tmp1, i, j, p_arrRes);

        }

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_matmul_Roti(darray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_getItem(sotiarray_t* p_array, uint64_t i, uint64_t j, sotinum_t* num)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i, j, k;
    sotinum_t tmp1, tmp2, tmp3;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr2->ncols, p_arr2->order);
    }
    for (i=0; i<p_arr1->nrows; i++){
        
        for(j=0; j<p_arr2->ncols; j++){
            
            c_soti_createEmpty(&tmp1, 0, p_arr2->order);

            for(k=0; k<p_arr1->ncols; k++){

                c_soti_mulf(
                    &p_arr2->p_data[k+i*p_arr1->ncols]  ,
                     p_arr1->p_data[j+k*p_arr2->ncols]  ,
                    &tmp3);

                tmp2 = tmp1; // Copy all information between elements
                
                // Sum
                c_soti_sum(&tmp2,&tmp3,&tmp1,p_dH);

                // Free memory ...
                c_soti_free(&tmp2);
                c_soti_free(&tmp3);

            }
            
            c_sotiarray_setItemOTI( &tmp1, i, j, p_arrRes);

        }

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_matmul_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_getItem(sotiarray_t* p_array, uint64_t i, uint64_t j, sotinum_t* num)

    multiply two sparse oti number arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of <p_arr1,p_arr2>.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i, j, k;
    sotinum_t tmp1, tmp2, tmp3;

    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr1->nrows, p_arr2->ncols, p_arr2->order);
    }
    for (i=0; i<p_arr1->nrows; i++){
        
        for(j=0; j<p_arr2->ncols; j++){
                

            c_soti_createEmpty(&tmp1, 0, p_arr2->order);

            for(k=0; k<p_arr1->ncols; k++){

                c_soti_mul(
                    &p_arr1->p_data[k+i*p_arr1->ncols]  ,
                    &p_arr2->p_data[j+k*p_arr2->ncols]  ,
                    &tmp3,   p_dH );

                tmp2 = tmp1; // Copy all information between elements
                
                // Sum
                c_soti_sum(&tmp2,&tmp3,&tmp1,p_dH);

                // Free memory ...
                c_soti_free(&tmp2);
                c_soti_free(&tmp3);

            }

            c_sotiarray_setItemOTI( &tmp1, i, j, p_arrRes);

        }

    }
    

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_sotiarray_matsum_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr1->order);
    }
    for (i=0; i<p_arr1->size; i++){

        c_soti_sumf(
            &p_arr1->p_data[i]  ,
             p_arr2->p_data[i]  ,
            &tmp);
        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_matsum_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH){
    /*
    c_sotiarray_matsum(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH)

    Sum two sparse oti arrays.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t tmp;
    // Check correctness of dimensions:
    if( (p_arr1->ncols!=p_arr2->ncols) || (p_arr1->nrows!=p_arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (p_arrRes->p_data == NULL){
        c_sotiarray_zeros( p_arrRes, p_arr2->nrows, p_arr2->ncols, p_arr2->order);
    }
    for (i=0; i<p_arr1->size; i++){

        c_soti_sum(
            &p_arr1->p_data[i]  ,
            &p_arr2->p_data[i]  ,
            &tmp,   p_dH );
        c_sotiarray_setItemOTI_indx(&tmp,i,p_arrRes);

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_getItem(sotiarray_t* p_array, uint64_t i, uint64_t j, sotinum_t* num){
    /*
    c_sotiarray_getItem(sotiarray_t* p_array, uint64_t i, uint64_t j, sotinum_t* num)

    Get element at position i,j in p_array.

    INPUTS:

        ->      num:    Number to be placed.

        ->        i:    Row position.

        ->        j:    Column position.
        
        ->  p_array:    Address of the array.

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    num[0] = p_array->p_data[j+i*p_array->ncols];

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_setItemR_indx( double num, uint64_t i, sotiarray_t* p_array){
    /*
    c_sotiarray_setItem( double num, uint64_t i, uint64_t j,sotiarray_t* p_array)

    Set an item at position i,j in p_array. To be called only when p_array has already been created
    and has some correct values in it.

    INPUTS:

        ->      num:    Number to be placed.

        ->        i:    Row position.

        ->        j:    Column position.
        
        ->  p_array:    Address of the array.

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    sotinum_t* tmp = &p_array->p_data[i];
    c_soti_free(tmp);
    c_soti_createEmpty(tmp, 1, p_array->order);
    tmp->p_coefs[0] = num;
    tmp->p_indx[0]  = 0; 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_sotiarray_setItemR( double num, uint64_t i, uint64_t j,sotiarray_t* p_array){
    /*
    c_sotiarray_setItem( double num, uint64_t i, uint64_t j,sotiarray_t* p_array)

    Set an item at position i,j in p_array. To be called only when p_array has already been created
    and has some correct values in it.

    INPUTS:

        ->      num:    Number to be placed.

        ->        i:    Row position.

        ->        j:    Column position.
        
        ->  p_array:    Address of the array.

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    sotinum_t* tmp = &p_array->p_data[j+i*p_array->ncols];
    c_soti_free(tmp);
    c_soti_createEmpty(tmp, 1, p_array->order);
    tmp->p_coefs[0] = num;
    tmp->p_indx[0]  = 0; 

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_sotiarray_setItemOTI_indx( sotinum_t* num, uint64_t i, sotiarray_t* p_array){
    /*
    c_sotiarray_setItem( sotinum_t* num, uint64_t i, uint64_t j,sotiarray_t* p_array)

    Set an item at position i,j in p_array. To be called only when p_array has already been created
    and has some correct values in it.

    INPUTS:

        ->      num:    Number to be placed.

        ->        i:    Row position.

        ->        j:    Column position.
        
        ->  p_array:    Address of the array.

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************


    c_soti_free(&p_array->p_data[i]);
    p_array->p_data[i] = num[0]; // Does not copy coefficients, just takes the pointer!

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_sotiarray_setAllItems( sotinum_t* num, sotiarray_t* p_array){
    /*
    c_sotiarray_setItem( sotinum_t* num, uint64_t i, uint64_t j,sotiarray_t* p_array)

    Set an item at position i,j in p_array. To be called only when p_array has already been created
    and has some correct values in it.

    INPUTS:

        ->      num:    Number to be placed.

        ->        i:    Row position.

        ->        j:    Column position.
        
        ->  p_array:    Address of the array.

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    uint64_t i;
    sotinum_t tmp;

    for (i=0; i<p_array->size; i++){
    
        c_soti_free(&p_array->p_data[i]);
        c_soti_copy(&tmp,num);
        p_array->p_data[i] = tmp;

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_sotiarray_setItemOTI( sotinum_t* num, uint64_t i, uint64_t j, sotiarray_t* p_array){
    /*
    c_sotiarray_setItem( sotinum_t* num, uint64_t i, uint64_t j,sotiarray_t* p_array)

    Set an item at position i,j in p_array. To be called only when p_array has already been created
    and has some correct values in it.

    INPUTS:

        ->      num:    Number to be placed.

        ->        i:    Row position.

        ->        j:    Column position.
        
        ->  p_array:    Address of the array.

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************


    c_soti_free(&p_array->p_data[j+i*p_array->ncols]);
    p_array->p_data[j+i*p_array->ncols] = num[0]; // Does not copy coefficients, just takes the pointer!

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_sotiarray_zeros(sotiarray_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order){
    /*
    c_sotiarray_createEmpty(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, uint8_t order)

    C-level memory allocation of a dense oti number a direction array from a file

    INPUTS:

        ->  p_array:    Address of the array to be allocated.

        ->   shapex:    Number of elements in the first  dimension.

        ->   shapey:    Number of elements in the second dimension.
        
        ->    order:    Order of the numbers.
            Example: 3

        ->     coefs:    Number of nonzero coefficients in the number.
            Example: 100

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    uint64_t i;
    sotinum_t value;

    value.p_coefs=  NULL;
    value.p_indx =  NULL;
    value.size   =     0;
    value.order  = order;

    p_array->ncols  = ncols       ;
    p_array->nrows  = nrows       ;
    p_array->size   = ncols*nrows ;
    p_array->order  = order       ;
    p_array->p_data = (sotinum_t*) malloc( p_array->size * sizeof(sotinum_t) );

    if (p_array->p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for( i = 0; i < p_array->size; i++){

        p_array->p_data[i] = value;

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_free(sotiarray_t* p_array){
    /*
    c_sotiarray_free(sotiarray_t* p_array)
    
    Free all memory associated with the array.

    INPUTS:

        ->  p_array:    Address of the array to be freed.

        
    */ 
    // ************************************************************************************************
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if( p_array->p_data != NULL && p_array->size != 0){

        for (i = 0; i<p_array->size; i++){
            
            c_soti_free(&p_array->p_data[i]); 

        }
        free( p_array->p_data);
        p_array->p_data = NULL;

    }

    

    // Free pointer 
    
    
    p_array->ncols  =    0;
    p_array->nrows  =    0;
    p_array->size   =    0;
    p_array->order  =    0;
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_sotiarray_createEmpty(sotiarray_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order){
    /*
    c_sotiarray_createEmpty(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, uint8_t order)

    C-level memory allocation of a dense oti number a direction array from a file

    INPUTS:

        ->  p_array:    Address of the array to be allocated.

        ->   shapex:    Number of elements in the first  dimension.

        ->   shapey:    Number of elements in the second dimension.
        
        ->    order:    Order of the numbers.
            Example: 3

        ->     coefs:    Number of nonzero coefficients in the number.
            Example: 100

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    
    p_array->ncols  = ncols;
    p_array->nrows  = nrows;
    p_array->size   = ncols*nrows;
    p_array->order  = order ;
    p_array->p_data = (sotinum_t*) malloc( p_array->size * sizeof(sotinum_t) );

        
    if (p_array->p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

}
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
// -------------------------------     END SOTIMAT FUNCTIONS     --------------------------------------
// ----------------------------------------------------------------------------------------------------
