#include "oti/otifem.h"

// ----------------------------------------------------------------------------------------------------
// ---------------------------------     FEMARRAY FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_femarray_gaussIntegrateOverElement(femarray_t* p_arr1, elemProps_t* elem, sotiarray_t* p_arrRes, 
    directionHelper* p_dH){
    /*
    c_femarray_det(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

    Gauss integration over all elements of a femarray.

    INPUTS:

        ->   p_arr1:    Array

        ->   elem:      Element with the information of the solution.
        
        -> p_arrRes:    Result of operation.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i,j,k;
    sotinum_t tmp1, tmp2, tmp3,tmp4;

    // double realVal;
    

    if (p_arrRes->p_data == NULL){

        // c_sotiarray_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, p_arr1->order);

    }

    // printf("\nIntegrating over element.\n");
    
    for (i = 0; i<p_arr1->nrows; i++){
    
        for (j = 0; j<p_arr1->ncols; j++){

            // printf("  Integrating position (%llu,%llu)\n",i,j);
            
            c_soti_createEmpty(&tmp1,0,p_arr1->order);

            for (k = 0; k<elem->nIntPts; k++){

                // printf("    Summing integration point %llu\n",k);
                // printf("    Getting element of integration function\n");
                c_femarray_getItem_ijk(p_arr1, i, j, k, &tmp2);

                // printf("    Getting element of weights function\n");
                c_femarray_getItem_ijk(&elem->p_detWeights, 0, 0, k, &tmp4);


                // printf("    Multiplying two otis\n");
                c_soti_mul(&tmp2, &tmp4, &tmp3, p_dH);


                tmp2 = tmp1;

                // printf("    Adding two otis\n");
                c_soti_sum(&tmp2,&tmp3,&tmp1,p_dH);

                // printf("    Freeing memory of temporal arrays.\n");
                // Free temporals that were created in here.
                c_soti_free(&tmp2);    
                c_soti_free(&tmp3);

            }
            // printf("  Adding position i: %llu,   j: %llu,    with offsets ->   i': %llu,   j': %llu\n", 
                                // i, j, p_arr1->offsetx+i,   p_arr1->offsety+j  );

            // printf("  Getting element from result array\n");
            c_sotiarray_getItem( p_arrRes, p_arr1->offsetx + i, p_arr1->offsety + j, &tmp2);

            // realVal = c_soti_getReal(&tmp2);

            // printf("  tmp2: \n");
            // c_soti_printf(&tmp2);
            // realVal = c_soti_getReal(&tmp1);
            // printf("\n  tmp1: \n");
            // c_soti_printf(&tmp1);

            // realVal = c_soti_getReal(&tmp3);
            
            // printf("\n  tmp3: \n");
            // c_soti_printf(&tmp3);

            // printf("  Adding the two arrays\n");
            

            c_soti_sum(&tmp2,&tmp1,&tmp3,p_dH);



            // printf("  Freeing memory temporal 1.\n");
            c_soti_free(&tmp1);

            

            c_sotiarray_setItemOTI(&tmp3,
                p_arr1->offsetx + i , p_arr1->offsety + j, p_arrRes);
    
        }
    
    }

    // printf("Exit.");


}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_femarray_sub(femarray_t* p_arr1, femarray_t* p_arr2, femarray_t* p_arrRes, 
    directionHelper* p_dH){
    /*
    c_femarray_det(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array

        ->   p_arr2:    Array
        
        -> p_arrRes:    Result of operation.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        c_femarray_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }


    for (i = 0; i<p_arr1->nIntPts; i++){

        c_sotiarray_matsub_otioti(&p_arr1->p_data[i], &p_arr2->p_data[i], 
            &p_arrRes->p_data[i], p_dH);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_femarray_sum(femarray_t* p_arr1, femarray_t* p_arr2, femarray_t* p_arrRes, 
    directionHelper* p_dH){
    /*
    c_femarray_det(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array

        ->   p_arr2:    Array
        
        -> p_arrRes:    Result of operation.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        c_femarray_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }


    for (i = 0; i<p_arr1->nIntPts; i++){

        c_sotiarray_matsum_otioti(&p_arr1->p_data[i], &p_arr2->p_data[i], 
            &p_arrRes->p_data[i], p_dH);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_femarray_mul_oti(femarray_t* p_arr1, sotinum_t* num2, femarray_t* p_arrRes, 
    directionHelper* p_dH){
    /*
    c_femarray_det(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array

        ->   p_arr2:    Array
        
        -> p_arrRes:    Result of operation.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        c_femarray_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }

    for (i = 0; i<p_arr1->nIntPts; i++){

        c_sotiarray_mul_oti(&p_arr1->p_data[i], num2, &p_arrRes->p_data[i], p_dH);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_femarray_neg(femarray_t* p_arr1, femarray_t* p_arrRes){
    /*
    c_femarray_det(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array

        ->   p_arr2:    Array
        
        -> p_arrRes:    Result of operation.

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        c_femarray_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }

    for (i = 0; i<p_arr1->nIntPts; i++){

        c_sotiarray_neg(&p_arr1->p_data[i], &p_arrRes->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_femarray_mul_R(femarray_t* p_arr1, double num2, femarray_t* p_arrRes){
    /*
    c_femarray_det(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array

        ->   p_arr2:    Array
        
        -> p_arrRes:    Result of operation.

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        c_femarray_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }

    for (i = 0; i<p_arr1->nIntPts; i++){

        c_sotiarray_mul_R(&p_arr1->p_data[i], num2, &p_arrRes->p_data[i]);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_femarray_matmul(femarray_t* p_arr1, femarray_t* p_arr2, femarray_t* p_arrRes, 
    directionHelper* p_dH){
    /*
    c_femarray_det(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array

        ->   p_arr2:    Array
        
        -> p_arrRes:    Result of operation.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        c_femarray_zeros(p_arrRes, p_arr1->ncols, p_arr2->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }

    if ( ( p_arr1->ncols == 1) && ( p_arr1->nrows == 1) ){
        

        for (i = 0; i<p_arr1->nIntPts; i++){
         
            c_sotiarray_mul_oti(&p_arr2->p_data[i], &p_arr1->p_data[i].p_data[0], 
                &p_arrRes->p_data[i], p_dH);

        }

    } else if ( ( p_arr2->ncols == 1) && ( p_arr2->nrows == 1) ){
        
        for (i = 0; i<p_arr1->nIntPts; i++){

            c_sotiarray_mul_oti(&p_arr1->p_data[i], &p_arr2->p_data[i].p_data[0], 
                &p_arrRes->p_data[i], p_dH);

        }

    }else{

        for (i = 0; i<p_arr1->nIntPts; i++){

            c_sotiarray_matmul_otioti(&p_arr1->p_data[i], &p_arr2->p_data[i], 
                &p_arrRes->p_data[i], p_dH);

        }

    }


    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_femarray_det(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH){
    /*
    c_femarray_det(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

    Determinant of femarray

    INPUTS:

        ->   p_arr1:    Array
        
        -> p_arrRes:    Result of operation. must be (1x1)

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;
    sotinum_t tmp;

    if (p_arrRes->p_data == NULL){

        c_femarray_zeros(p_arrRes, 1, 1, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }


    for (i = 0; i<p_arr1->nIntPts; i++){

        c_sotiarray_det(&p_arr1->p_data[i], &tmp, p_dH);
        c_femarray_setItem_ijk(&tmp,0,0,i,p_arrRes);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_femarray_invert(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH){
    /*
    c_sotiarray_invert(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

    Transpose a  femarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    uint64_t i;

    if (p_arrRes->p_data == NULL){

        c_femarray_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }


    for (i = 0; i<p_arr1->nIntPts; i++){

        c_sotiarray_invert(&p_arr1->p_data[i], &p_arrRes->p_data[i], p_dH);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_femarray_fromOther(femarray_t* p_arr1, femarray_t* p_arrRes){
    /*
    c_femarray_fromOther(femarray_t* p_arr1, femarray_t* p_res)

    Define a femarray from another femarray.



    INPUTS:

        ->   p_arr1:    First array of shape (i,j) and k nIntPts.
        
        -> p_arrRes:    Result of p_arrRes = p_arr1.

                        NOTE: Shape can be (i,j) or (j,i), important is that the number of elements 
                              are the same.

    */ 
    // ************************************************************************************************

    sotinum_t tmp1, tmp2;
    uint64_t i,k;

    if (p_arrRes->p_data == NULL){

        c_femarray_zeros(p_arrRes, p_arr1->ncols, p_arr1->nrows, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }
    
    for (k=0; k<p_arr1->nIntPts; k++){

        for( i=0; i<p_arr1->p_data[k].size; i++ ){

            // Get the first element.
            tmp1 = p_arr1->p_data[k].p_data[i];

            c_soti_copy( &tmp2, &tmp1);

            // Remove the previous element.
            c_soti_free( &p_arrRes->p_data[k].p_data[i] );

            // Assign new element.
            p_arrRes->p_data[k].p_data[i] = tmp2;

        }

    }


}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_femarray_getItem_ij(femarray_t* p_arr1, uint64_t i, uint64_t j, femarray_t* p_arrRes){
    /*
    c_femarray_getItem_ijk(femarray_t* p_arr1, uint64_t i, uint64_t j, uint64_t k, 
                femarray_t* p_arrRes)

    Transpose a  femarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t k;
    sotinum_t tmp;

    if (p_arrRes->p_data == NULL){

        c_femarray_zeros(p_arrRes, 1, 1, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }
    
    for (k = 0; k<p_arr1->nIntPts; k++){
        
        c_femarray_getItem_ijk( p_arr1, i, j, k, &tmp );

        p_arrRes->p_data[k].p_data[0]=tmp;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_femarray_getItem_k(femarray_t* p_arr1, uint64_t k, 
        sotiarray_t* p_arrRes){
    /*
    c_femarray_getItem_ijk(femarray_t* p_arr1, uint64_t i, uint64_t j, uint64_t k, 
                femarray_t* p_arrRes)

    Transpose a  femarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    p_arrRes[0] = p_arr1->p_data[k];

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_femarray_getItem_ijk(femarray_t* p_arr1, uint64_t i, uint64_t j, uint64_t k, 
        sotinum_t* p_res){
    /*
    c_femarray_getItem_ijk(femarray_t* p_arr1, uint64_t i, uint64_t j, uint64_t k, 
                femarray_t* p_arrRes)

    Transpose a  femarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    c_sotiarray_getItem(&p_arr1->p_data[k], i, j, p_res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_femarray_setItem_ij(femarray_t* p_arr1, uint64_t i, uint64_t j, femarray_t* p_arrRes){
    /*
    c_femarray_getItem_ijk(femarray_t* p_arr1, uint64_t i, uint64_t j, uint64_t k, 
                femarray_t* p_arrRes)

    Transpose a  femarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************
    
    uint64_t k;
    sotinum_t tmp;

    if (p_arrRes->p_data == NULL){

        c_femarray_zeros(p_arrRes, 1, 1, 
            p_arr1->offsetx,p_arr1->offsety, p_arr1->nIntPts, p_arr1->order);

    }
    
    for (k = 0; k<p_arr1->nIntPts; k++){
        
        c_femarray_getItem_ijk( p_arr1, i, j, k, &tmp );

        p_arrRes->p_data[k].p_data[0]=tmp;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_femarray_setItem_k( sotiarray_t* p_arr1 , uint64_t k, femarray_t* p_arrRes){
    /*
    c_femarray_getItem_ijk(femarray_t* p_arr1, uint64_t i, uint64_t j, uint64_t k, 
                femarray_t* p_arrRes)

    Transpose a  femarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    c_sotiarray_free(&p_arrRes->p_data[k]);
    p_arrRes->p_data[k]=p_arr1[0];

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_femarray_setItem_ijk(sotinum_t* p_num, uint64_t i, uint64_t j, uint64_t k, 
        femarray_t* p_arrRes){
    /*
    c_femarray_getItem_ijk(femarray_t* p_arr1, uint64_t i, uint64_t j, uint64_t k, 
                femarray_t* p_arrRes)

    Transpose a  femarray.

    INPUTS:

        ->   p_arr1:    First array

        ->   p_arr2:    Second array.
        
        -> p_arrRes:    Result of p_arr1+p_arr2.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    c_sotiarray_setItemOTI( p_num, i, j, &p_arrRes->p_data[k]);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_femarray_zeros(femarray_t* p_array, uint64_t nrows, uint64_t ncols, 
                    uint64_t offsetx, uint64_t offsety, uint64_t nIntPts, uint8_t order){
    /*
    c_femarray_zeros(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, uint8_t order)

    C-level memory allocation of a fem array as zeros.

    INPUTS:

        ->  p_array:    Address of the array to be allocated.

        ->   shapex:    Number of elements in the first  dimension.

        ->   shapey:    Number of elements in the second dimension.

        ->   offsetx:    Number of elements in the second dimension.

        ->   offsety:    Number of elements in the second dimension.

        ->   nIntPts:    Number of elements in the third dimension.
        
        ->    order:    Order of the numbers.

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    uint64_t i;

    p_array->ncols    =  ncols;
    p_array->nrows    =  nrows;
    p_array->size     =  ncols*nrows;
    p_array->order    =  order;
    p_array->nIntPts  =  nIntPts;
    p_array->offsetx  =  offsetx;
    p_array->offsety  =  offsety;
    p_array->p_data = (sotiarray_t*) malloc( p_array->nIntPts * sizeof(sotiarray_t) );

    // c_sotiarray_createEmpty(sotiarray_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order);
    if (p_array->p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for(i=0; i<p_array->nIntPts; i++){

        c_sotiarray_zeros( &p_array->p_data[i], nrows, ncols, order);

    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_femarray_free(femarray_t* p_array){
    /*
    c_femarray_createEmpty(femarray_t* p_array)
    
    Free all memory associated with the array.

    INPUTS:

        ->  p_array:    Address of the array to be freed.

        
    */ 
    // ************************************************************************************************
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    for (i = 0; i<p_array->nIntPts; i++){
        
        c_sotiarray_free(&p_array->p_data[i]); 

    }

    // Free pointer 
    if (p_array->size != 0){

        c_free_ptr( (void**)&p_array->p_data);

    }



    p_array->ncols    =  0;
    p_array->nrows    =  0;
    p_array->size     =  0;
    p_array->order    =  0;
    p_array->nIntPts  =  0;
    p_array->offsetx  =  0;
    p_array->offsety  =  0;
    p_array->p_data = NULL;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_femarray_createEmpty(femarray_t* p_array, uint64_t nrows, uint64_t ncols, 
                    uint64_t offsetx, uint64_t offsety, uint64_t nIntPts, uint8_t order){  
    /*
    c_femarray_createEmpty(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, 
        uint64_t offsetx, uint64_t offsety, uint64_t nIntPts, uint8_t order)

    C-level memory allocation of a fem array from a file

    INPUTS:

        ->  p_array:    Address of the array to be allocated.

        ->   shapex:    Number of elements in the first  dimension.

        ->   shapey:    Number of elements in the second dimension.

        ->   offsetx:    Number of elements in the second dimension.

        ->   offsety:    Number of elements in the second dimension.

        ->   nIntPts:    Number of elements in the third dimension.
        
        ->    order:    Order of the numbers.


    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    uint64_t i;

    p_array->ncols    =  nrows;
    p_array->nrows    =  ncols;
    p_array->size     =  nrows*ncols;
    p_array->order    =  order ;
    p_array->nIntPts  =  nIntPts;
    p_array->offsetx  =  offsetx;
    p_array->offsety  =  offsety;
    p_array->p_data = (sotiarray_t*) malloc( p_array->nIntPts * sizeof(sotiarray_t) );

    // c_sotiarray_createEmpty(sotiarray_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order);
    if (p_array->p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for(i=0; i<p_array->nIntPts; i++){

        c_sotiarray_createEmpty( &p_array->p_data[i], nrows, ncols, order);

    }


}
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// -------------------------------     END FEMARRAY FUNCTIONS     -------------------------------------
// ----------------------------------------------------------------------------------------------------

