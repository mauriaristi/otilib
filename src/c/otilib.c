// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ------------------------------------     HEADER FILE     -------------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "c_otilib.h"

// ----------------------------------------------------------------------------------------------------
// ------------------------------------   END HEADER FILE   -------------------------------------------
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_printf(sotinum_t* num){
    /*
    c_soti_printf(sotinum_t* num)

    Function that prints a sparse OTI.

    INPUTS:

        ->   p_arr1:    Array

        ->   elem:      Element with the information of the solution.
        
        -> p_arrRes:    Result of operation.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    printf("soti(o: %hhu, sz: %llu, ",num->order,num->size);
    // printf("coefs at %p \n",num->p_coefs);
    c_printArrayDBL(num->p_coefs,num->size);
    printf(", ");
    // printf("indx at %p \n",num->p_indx);
    c_printArrayUI64(num->p_indx,num->size);
}
// ----------------------------------------------------------------------------------------------------



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




























































// ----------------------------------------------------------------------------------------------------
// ---------------------------------     OTIFEM FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_defFunctFrom_otiFunc(sotiarray_t* p_arr1, uint64_t derIndx, elemProps_t* elem, femarray_t* p_arrRes,
    directionHelper* p_dH) {
    /*
    c_fem_defFunctFrom_otiFunc( p_arr1, derIndx, elem, p_arrRes, p_dH)

    Define a constant function from a real number.

    INPUTS:

        -> p_arr1:        (1 x nbasis) otinum values of the function.

        -> derIndx:    Basis Id that defines this function.

        -> elem:       Element that interpolates the data.

        -> p_arrRes:   (1 x 1) Address of the array that holds the result.

        -> p_dH:       Direction helper


    OUTPUTS: 
        
        -> Assigns the result .

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    uint64_t i,k;
    sotinum_t tmpcnt, tmp1, tmp2, tmp3;    

    for (k=0; k<elem->nIntPts; k++){
        
        // Initialize counter as 0.
        c_soti_createEmpty(&tmpcnt,0,elem->otiorder);

        for ( i=0; i<elem->nbasis ; i++){
     
            c_femarray_getItem_ijk(&elem->p_basis[derIndx],0,i,k,&tmp1);


            c_soti_mul( &p_arr1->p_data[i], &tmp1, &tmp3, p_dH);

            tmp2 = tmpcnt;

            c_soti_sum( &tmp2, &tmp3, &tmpcnt, p_dH);


            
            c_soti_free(&tmp2);

            c_soti_free(&tmp3);
        }

        c_femarray_setItem_ijk(&tmpcnt,0,0,k,p_arrRes);

        // c_soti_free(&tmpcnt);

    }
    
    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_defFunctFrom_oti(sotinum_t* num, uint64_t derIndx, elemProps_t* elem, femarray_t* p_arrRes,
    directionHelper* p_dH) {
    /*
    c_fem_defFunctFrom_R( num, derIndx, elem, p_arrRes, p_dH)

    Define a constant function from a real number.

    INPUTS:

        -> num:        otinum value of the constant function.

        -> derIndx:    Basis Id that defines this function.

        -> elem:       Element that interpolates the data.

        -> p_arrRes:   (1 x 1) Address of the array that holds the result.

        -> p_dH:       Direction helper


    OUTPUTS: 
        
        -> Assigns the result .

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    uint64_t i,k;
    sotinum_t tmpcnt,tmp1,tmp2;


    // 
    // printf("Inside Function definition.\n");
    for (k=0; k<elem->nIntPts; k++){
        // printf("   Creating counter.\n");
        // Initialize counter as 0.
        c_soti_createEmpty(&tmpcnt,0,elem->otiorder);
     
        for ( i=0; i<elem->nbasis ; i++){
            // printf("       Geting  basis number %llu and for integration point %llu.\n",i,k);
            c_femarray_getItem_ijk(&elem->p_basis[derIndx],0,i,k,&tmp1);

            tmp2 = tmpcnt;
            // printf("       Sum  the elements.\n");
            c_soti_sum( &tmp2, &tmp1, &tmpcnt, p_dH);
            
            // printf("       Free tmp2.\n");
            c_soti_free(&tmp2);
        }
        

        // printf("   Multiply the given number times the sum.\n");

        c_soti_mul(&tmpcnt,num,&tmp2,p_dH);

        // printf("   Set position 0, 0, %llu.\n",k);

        c_femarray_setItem_ijk(&tmp2,0,0,k,p_arrRes);


        // printf("   Free tmpcnt.\n");
        c_soti_free(&tmpcnt);

    }
    // printf("Exit.\n");
    
    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_defFunctFrom_R(double num, uint64_t derIndx, elemProps_t* elem, femarray_t* p_arrRes,
    directionHelper* p_dH) {
    /*
    c_fem_defFunctFrom_R( num, derIndx, elem, p_arrRes, p_dH)

    Define a constant function from a real number.

    INPUTS:

        -> num:        Real value of the constant function.

        -> derIndx:    Basis Id that defines this function.

        -> elem:       Element that interpolates the data.

        -> p_arrRes:   (1 x 1) Address of the array that holds the result.

        -> p_dH:       Direction helper


    OUTPUTS: 
        
        -> Assigns the result .

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    uint64_t i,k;
    sotinum_t tmpcnt,tmp1,tmp2;


    

    for (k=0; k<elem->nIntPts; k++){

        // Initialize counter as 0.
        c_soti_createEmpty(&tmpcnt,0,elem->otiorder);
     
        for ( i=0; i<elem->nbasis ; i++){
     
            c_femarray_getItem_ijk(&elem->p_basis[derIndx],0,i,k,&tmp1);

            tmp2 = tmpcnt;

            c_soti_sum( &tmp2, &tmp1, &tmpcnt, p_dH);
            
            c_soti_free(&tmp2);
        }
        
        c_soti_mulf(&tmpcnt,num,&tmp2);

        c_femarray_setItem_ijk(&tmp2,0,0,k,p_arrRes);

        c_soti_free(&tmpcnt);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
int64_t c_fem_defineSpatial( elemProps_t* elem, uint16_t derFlags, directionHelper* p_dH) {
    /*
    c_fem_computeJacobian( elem, xcoords, ycoords, zcoords, nDimAnalysis, p_arrRes, p_dH) 

    Initialize the element Basis functions for the specified order of integration.

    INPUTS:

        -> elem:   Address of the structure that holds the element information.

        -> xcoords: Coordinates.
        
        -> ycoords: Coordinates.
        
        -> zcoords: Coordinates.

        -> nDimAnalysis: Number of dimension of the analysis. May differ from the number of 
                         dimensions of the element, however cannot be less than that.

        -> p_arrRes: list of result holders. Must come allocated.

        -> p_dH: Direction helper       


    OUTPUTS: 
        
        -> Assigns to elem the corresponding arrays with the correct data input.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    int64_t derId;
    uint64_t i,j;
    uint64_t k;
    sotinum_t tmp1,tmp2, tmpcntx, tmpcnty;
    double der;


    for( i = 0; i<elem->nder; i++){  // Do for each possible derivative.

        // 0. basisN  
        // 1. basisNx 
        // 2. basisNxx
        // 3. basisNy 
        // 4. basisNxy
        // 5. basisNyy
        // 6. basisNz 
        // 7. basisNxz
        // 8. basisNyz
        // 9. basisNzz
        derId = i+basisN;


        if(       (derId == basisN  ) && (derFlags & 1   ) ){
            
            for (j=0; j< elem-> nbasis; j++){
                
                for(k=0; k< elem->nIntPts; k++){

                    c_darray_getItem(&elem->p_evalBasis[i],j,k, &der);

                    c_soti_createFromReal(der,&tmp1,elem->otiorder);

                    c_femarray_setItem_ijk(&tmp1,0,j,k,&elem->p_basis[i]);
                
                }

            }

        }else if( (derId == basisNx ) && (derFlags & 1<<1) ){

            for (j=0; j< elem-> nbasis; j++){
                
                for(k=0; k< elem->nIntPts; k++){
                    //                    basisNa (dN/dxi)
                    c_darray_getItem(&elem->p_evalBasis[derNa-derN],j,k, &der); //ok

                    //                                From basisNx    from dim 1  
                    c_femarray_getItem_ijk(&elem->Jinv,       0    ,     0       , k, &tmp2);

                    c_soti_mulf(&tmp2,der,&tmpcntx);


                    if (elem->ndim >= 2){
                        //                      basisNb (dN/deta)
                        c_darray_getItem(&elem->p_evalBasis[derNb-derN],j,k, &der);

                                                    //    From basisNx    from dim 2  
                        c_femarray_getItem_ijk(&elem->Jinv,       0    ,     1       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                        


                    }

                    if (elem->ndim >= 3){

                        //                      basisNb (dN/dchi)
                        c_darray_getItem(&elem->p_evalBasis[derNc-derN],j,k, &der);

                                                    //    From basisNx    from dim 3  
                        c_femarray_getItem_ijk(&elem->Jinv,       0    ,     2       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                    

                    }

                    c_femarray_setItem_ijk(&tmpcntx,0,j,k,&elem->p_basis[i]);
                
                }

            }

        }else if( (derId == basisNxx) && (derFlags & 1<<2) ){
            // Not sure what to do yet

        }else if( (derId == basisNy ) && (derFlags & 1<<3) ){

            // Check that this is in dimension analysis.

            for (j=0; j< elem-> nbasis; j++){
                
                for(k=0; k< elem->nIntPts; k++){
                    //                    basisNa (dN/dxi)
                    c_darray_getItem(&elem->p_evalBasis[derNa-derN],j,k, &der);

                    //                                From basisNy    from dim 1  
                    c_femarray_getItem_ijk(&elem->Jinv,       1    ,     0       , k, &tmp2);

                    c_soti_mulf(&tmp2,der,&tmpcntx);


                    if (elem->ndim >= 2){
                        //                      basisNb (dN/deta)
                        c_darray_getItem(&elem->p_evalBasis[derNb-derN],j,k, &der);

                                                    //    From basisNy    from dim 2  
                        c_femarray_getItem_ijk(&elem->Jinv,       1    ,     1       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                        


                    }

                    if (elem->ndim >= 3){

                        //                      basisNb (dN/dchi)
                        c_darray_getItem(&elem->p_evalBasis[derNc-derN],j,k, &der);

                                                    //    From basisNy    from dim 3  
                        c_femarray_getItem_ijk(&elem->Jinv,       1    ,     2       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                    

                    }

                    c_femarray_setItem_ijk(&tmpcntx,0,j,k,&elem->p_basis[i]);
                
                }

            }

        }else if( (derId == basisNxy) && (derFlags & 1<<4) ){
            // Not sure what to do yet

        }else if( (derId == basisNyy) && (derFlags & 1<<5) ){
            // Not sure what to do yet

        }else if( (derId == basisNz ) && (derFlags & 1<<6) ){

            // Check that this is in dimension analysis.

            for (j=0; j< elem-> nbasis; j++){
                
                for(k=0; k< elem->nIntPts; k++){
                    //                    basisNa (dN/dxi)
                    c_darray_getItem(&elem->p_evalBasis[derNa-derN],j,k, &der);

                    //                                From basisNz    from dim 1  
                    c_femarray_getItem_ijk(&elem->Jinv,       2    ,     0       , k, &tmp2);

                    c_soti_mulf(&tmp2,der,&tmpcntx);


                    if (elem->ndim >= 2){
                        //                      basisNb (dN/deta)
                        c_darray_getItem(&elem->p_evalBasis[derNb-derN],j,k, &der);

                        //                                From basisNz    from dim 2  
                        c_femarray_getItem_ijk(&elem->Jinv,       2    ,     1       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                        


                    }

                    if (elem->ndim >= 3){

                        //                      basisNb (dN/dchi)
                        c_darray_getItem(&elem->p_evalBasis[derNc-derN],j,k, &der);

                        //                                From basisNz    from dim 3  
                        c_femarray_getItem_ijk(&elem->Jinv,       2    ,     2       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                    

                    }

                    c_femarray_setItem_ijk(&tmpcntx,0,j,k,&elem->p_basis[i]);
                
                }

            }

        }else if( (derId == basisNxz) && (derFlags & 1<<7) ){
            // Not sure what to do yet

        }else if( (derId == basisNyz) && (derFlags & 1<<8) ){
            // Not sure what to do yet

        }else if( (derId == basisNzz) && (derFlags & 1<<9) ){
            // Not sure what to do yet

        }
        
    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_computeJacobian( elemProps_t* elem, sotiarray_t* xcoords, sotiarray_t* ycoords,
                               sotiarray_t* zcoords, directionHelper* p_dH) {
    /*
    c_fem_computeJacobian( elem, xcoords, ycoords, zcoords, p_dH) 

    Initialize the element Basis functions for the specified order of integration.

    INPUTS:

        -> elem:   Address of the structure that holds the element information.

        -> xcoords: (ncoords x 1) Coordinates.
        
        -> ycoords: (ncoords x 1) Coordinates.
        
        -> zcoords: (ncoords x 1) Coordinates.

        -> nDimAnalysis: Number of dimension of the analysis. May differ from the number of 
                         dimensions of the element, however cannot be less than that.

        -> p_arrRes: Result holder. Must come allocated. shape: (nDimAnalysis x nDimElement)

        -> p_dH: Direction helper       


    OUTPUTS: 
        
        -> Assigns to elem the corresponding arrays with the correct data input.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    int64_t derId, posNa = derNa-derN, posNb = derNb-derN, posNc = derNc-derN;
    uint8_t intPt,elDim; // i , j
    uint64_t basis, i; //     k
    sotinum_t tmp1,tmp2,tmp3, tmpcntx, tmpcnty, tmpcntz;
    double dN_dxi;

    
    for( intPt = 0; intPt<elem->nIntPts; intPt++){  // Do for each integration point intPt.

        for( elDim = 0; elDim<elem->ndim; elDim++){ // take the derivative with respect to each
                                                    // of the canonical coordinates of the element.

            if        (elDim == 0){

                derId = posNa;

            } else if (elDim == 1){

                derId = posNb;

            }else{ // (elDim == 2)

                derId = posNc;

            }

            // create tmpcntx = 0.
            c_soti_createEmpty(&tmpcntx,0,elem->otiorder); 

            if (elem->nDimAnalysis >= 2){
                // create tmpcnty = 0.
                c_soti_createEmpty(&tmpcnty,0,elem->otiorder); 
            }
            
            if (elem->nDimAnalysis >= 3){
                // create tmpcntz = 0.
                c_soti_createEmpty(&tmpcntz,0,elem->otiorder); 
            }



            for( basis = 0; basis<elem->nbasis; basis++){

                // compute for analysis dimension 1
                // Extract the coordinate for the corresponding basis.
                c_sotiarray_getItem(xcoords, basis, 0, &tmp1); 

                // get the derivative of basis i with respect to elDim
                c_darray_getItem( &elem->p_evalBasis[derId], basis, intPt, &dN_dxi);

                // multiply coordinate times derivative dN/da
                c_soti_mulf(&tmp1,dN_dxi,&tmp2);

                // Sum the result to the accumulator tmpcntx
                tmp3 = tmpcntx;
                c_soti_sum(&tmp3,&tmp2,&tmpcntx,p_dH);

                // Free temps.
                c_soti_free(&tmp3);
                c_soti_free(&tmp2);

                if (elem->nDimAnalysis >= 2){

                    // compute for analysis dimension 2
                    c_sotiarray_getItem(ycoords, basis, 0, &tmp1); 

                    // multiply coordinate times derivative dN/db
                    c_soti_mulf(&tmp1,dN_dxi,&tmp2);

                    // Sum the result to the accumulator tmpcnty
                    tmp3 = tmpcnty;
                    c_soti_sum(&tmp3,&tmp2,&tmpcnty,p_dH);

                    // Free temps.
                    c_soti_free(&tmp3);
                    c_soti_free(&tmp2);

                }

                if (elem->nDimAnalysis >= 3){
                    // compute for analysis dimension 3
                    c_sotiarray_getItem(zcoords, basis, 0, &tmp1); 

                    // multiply coordinate times derivative dN/dc
                    c_soti_mulf(&tmp1,dN_dxi,&tmp2);

                    // Sum the result to the accumulator tmpcntz
                    tmp3 = tmpcntz;
                    c_soti_sum(&tmp3,&tmp2,&tmpcntz,p_dH);

                    // Free temps.
                    c_soti_free(&tmp3);
                    c_soti_free(&tmp2);
                }

            }

            // set element of the result array:
            c_femarray_setItem_ijk(    &tmpcntx, elDim, 0, intPt, &elem->J);

            if (elem->nDimAnalysis >= 2){
                // create an oti zero to get otinum = 0 .
                c_femarray_setItem_ijk(&tmpcnty, elDim, 1, intPt, &elem->J);
            }
            
            if (elem->nDimAnalysis >= 3){
                // create an oti zero to get otinum = 0 .
                c_femarray_setItem_ijk(&tmpcntz, elDim, 2, intPt, &elem->J);
            }

    
        }
    
    }

    // Here, Jacobian is already computed. Now, the inverse and determinant can be computed.

    if (elem->ndim == elem->nDimAnalysis){
        
        c_femarray_invert(&elem->J, &elem->Jinv, p_dH);
        c_femarray_det(   &elem->J, &elem->Jdet, p_dH);

        for ( intPt=0; intPt< elem->nIntPts; intPt++){
            
            c_femarray_getItem_ijk(&elem->Jdet,0,0,intPt,&tmp1);
            
            c_soti_mulf(&tmp1,elem->p_intWeights.p_data[intPt],&tmp2);

            // for (i=0; i<tmp2.size; i++){
            //     if( tmp2.p_indx[i] != 0 ){
            //         tmp2.p_coefs[i] = 0.0;
            //     }
            // }

            c_femarray_setItem_ijk(&tmp2,0,0,intPt,&elem->p_detWeights);

            
        }

    } else {

        if (elem->ndim == 0){

            c_soti_createFromReal( 1.0, &tmp1, elem->otiorder);
            c_femarray_setItem_ijk(&tmp1,0,0,0,&elem->p_detWeights);

        } else if (elem->ndim == 1){

            // sqrt( (dx/dxi)^2 + (dy/dxi)^2 + (dz/dxi)^2 )

            // Loop for every integration point
            for ( intPt=0; intPt< elem->nIntPts; intPt++){

                // initialize counter
               c_soti_createEmpty(&tmpcntx, 0, elem->otiorder); 


                // get dx/dxi
                c_femarray_getItem_ijk(&elem->J , 0, 0, intPt,&tmp1);

                // do (dx/dxi)^2
                c_soti_ipowfast(&tmp1,2,&tmp2,p_dH);

                // sum to counter
                tmp3 = tmpcntx;
                c_soti_sum( &tmp2, &tmp3, &tmpcntx, p_dH);

                c_soti_free(&tmp2);
                c_soti_free(&tmp3);

                if (elem->nDimAnalysis >= 2){
                    // get dy/dxi
                    c_femarray_getItem_ijk(&elem->J , 0, 1, intPt, &tmp1);

                    // do (dy/dxi)^2
                    c_soti_ipowfast(&tmp1,2,&tmp2,p_dH);

                    // sum to counter
                    tmp3 = tmpcntx;
                    c_soti_sum(&tmp2,&tmp3,&tmpcntx,p_dH);

                    c_soti_free(&tmp2);
                    c_soti_free(&tmp3);

                }

                if (elem->nDimAnalysis >= 3){

                    // get dz/dxi
                    c_femarray_getItem_ijk(&elem->J , 0, 2, intPt, &tmp1);

                    // do (dz/dxi)^2
                    c_soti_ipowfast(&tmp1,2,&tmp2,p_dH);

                    // sum to counter
                    tmp3 = tmpcntx;
                    c_soti_sum(&tmp2,&tmp3,&tmpcntx,p_dH);

                    c_soti_free(&tmp2);
                    c_soti_free(&tmp3);

                }

                // counter = sqrt(counter)
                c_soti_sqrt( &tmpcntx, p_dH, &tmp2);
                c_soti_free( &tmpcntx);

                // Multiply weight times the result.
                c_soti_mulf(&tmp2,elem->p_intWeights.p_data[intPt],&tmp1);
                c_soti_free(&tmp2);
                
                // for (i=0; i<tmp2.size; i++){
                //     if( tmp2.p_indx[i] != 0 ){
                //         tmp2.p_coefs[i] = 0.0;
                //     }
                // }
                // set the element with the result 
                c_femarray_setItem_ijk(&tmp1,0,0,intPt,&elem->p_detWeights);

                // Inverse is not determined,  yet.

            }

        // } else if (elem->ndim == 2){   // When 3D is supported
        //     //
        //     // Cross product between these two vectors.
        //     //                                                   
        //     //       ||                              ||          
        //     //       ||  | dx/dxi |      | dx/deta | ||          
        //     //       ||  |        |      |         | ||          
        //     //       ||  | dy/dxi |   x  | dy/deta | ||          
        //     //       ||  |        |      |         | ||          
        //     //       ||  | dz/dxi |      | dz/deta | ||          
        //     //       ||  |        |      |         | ||          
        //     //       ||                              ||          
        //     //











        }


    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_unInitElement(elemProps_t* elem) {
    /*
    c_fem_initElement(uint64_t order, elemProps_t* elem) 

    Initialize the element Basis functions for the specified order of integration.

    INPUTS:

        -> order:    Order of polynomial.

        -> elem:   Address of the structure that holds the element information.


    OUTPUTS: 
        
        -> Assigns to elem the corresponding arrays with the correct data input.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    int64_t derId;

    if (elem->isInit != 0){
        // Get the integration points and integration weights.
    
        c_darray_free(&elem->p_intPoints);
        c_darray_free(&elem->p_intWeights);
        
        elem->nIntPts = 0;

        // Loop through all derivatives
        for(derId = 0; derId<elem->nder; derId++){
            
            // Allocate new array
            c_darray_free(&elem->p_evalBasis[derId]);
            c_femarray_free(&elem->p_basis[ derId ]);

        }

        c_femarray_free(&elem->J   );

        
        c_femarray_free(&elem->Jinv);
        c_femarray_free(&elem->p_detWeights);
        c_femarray_free(&elem->Jdet);
        

        
        
        c_free_ptr((void**)&elem->p_evalBasis);
        c_free_ptr((void**)&elem->p_basis);
        elem->isInit       = 0; // Lower flag of initialization.
        elem->nDimAnalysis = 0;
        elem->otiorder     = 0;

        elem->p_evalBasis = NULL;
        elem->p_basis     = NULL;
    }
    
    

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_initElement(uint64_t order, uint8_t otiorder, uint8_t nDimAnalysis, elemProps_t* elem) {
    /*
    c_fem_initElement(uint64_t order, elemProps_t* elem) 

    Initialize the element Basis functions for the specified order of integration.

    INPUTS:

        -> order:    Order of polynomial.

        -> elem:   Address of the structure that holds the element information.


    OUTPUTS: 
        
        -> Assigns to elem the corresponding arrays with the correct data input.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    int64_t derId;
    uint64_t basisId;

    // Check first if the element is already initialized.
    if( elem->isInit == 0 ){
   
    
        // Get the integration points and integration weights.
        c_fem_integrationPoints(order, elem->geomBase, &elem->p_intPoints, &elem->p_intWeights);
        
        elem->nIntPts = elem->p_intPoints.nrows;


        elem->otiorder = otiorder;
        elem->nDimAnalysis = nDimAnalysis;


        elem->p_evalBasis = (darray_t*  )c_malloc_ptr(elem->nder,sizeof(darray_t  ));     
        elem->p_basis     = (femarray_t*)c_malloc_ptr(elem->nder,sizeof(femarray_t));

        if( elem->p_evalBasis == NULL || elem->p_basis == NULL ){
            printf("--- MemoryError ---\n");
            exit(1);
        }
        

        // Evaluate all basis functions at integration points.
        // Loop through all derivatives
        for(derId = 0; derId<elem->nder; derId++){

            // Allocate new array
            c_darray_createEmpty(&elem->p_evalBasis[derId], elem->nbasis, elem->nIntPts);

            // Loop through all basis functions.
            for(basisId = 0; basisId<elem->nbasis; basisId++){
                
                elem->f_basis(basisId, derId + derN, &elem->p_intPoints, NULL, &elem->p_evalBasis[derId]);
                

            }

            c_femarray_zeros(&elem->p_basis[ derId ],
                    1,elem->nbasis,0,0,elem->nIntPts,elem->otiorder);


        }


        // Allocate space for Jacobian, its inverse and determinant.
        c_femarray_zeros(&elem->J, MAX(elem->ndim,1),    elem->nDimAnalysis, 0, 0, elem->nIntPts, elem->otiorder);

        c_femarray_zeros(&elem->Jinv,elem->nDimAnalysis, MAX(elem->ndim,1),  0, 0, elem->nIntPts, elem->otiorder);

        c_femarray_zeros(&elem->Jdet,         1, 1, 0, 0, elem->nIntPts, elem->otiorder);
        
        c_femarray_zeros(&elem->p_detWeights, 1, 1, 0, 0, elem->nIntPts, elem->otiorder);

        
        elem->isInit = 1; // Raise flag of initialization.

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_integrateSOTIfunct(sotiarray_t* f_eval, darray_t* weights, sotinum_t* res,
                                 directionHelper* p_dH){
    /*
    c_fem_integrateSOTIfunct( f_eval, weights)

    Perform the numerical integration of the function.

    INPUTS:

        -> f_eval:    (nIntPoints x 1) Array of soti numbers with the evaluated sampling points 
                                       of the function.

        -> weights:   (nIntPoints x 1) Array of weights to evaluate the integral.

    OUTPUTS: 
        
        -> res:  sotinum that represents the result of the operation.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    double rtmp;
    uint64_t i, j = 0, nSamples = weights->nrows;

    sotinum_t sotitmp1, sotitmp2, sotitmp3;

    c_soti_createEmpty(&sotitmp3, 0, f_eval->order);

    // Note: This can be done in parallel.
    for ( i = 0; i < nSamples ; i++ ){

        // Get function evaluated at point i.
        c_sotiarray_getItem(f_eval,  i, j, &sotitmp1);
        
        // Get weight i.
        c_darray_getItem(weights,    i, j, &rtmp    );
        
        // Multiply weight times the function
        c_soti_mulf( &sotitmp1, rtmp, &sotitmp2 );

        // Sum to the temporal sum.
        sotitmp1 = sotitmp3;
        c_soti_sum( &sotitmp1, &sotitmp2, &sotitmp3, p_dH) ;

        c_soti_free( &sotitmp1 );
        c_soti_free( &sotitmp2 );

    }
    
    // Copy result.
    res[0] = sotitmp3;

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
int64_t c_fem_integrationPoints(uint64_t order, int64_t elementType, 
                                darray_t* coords, darray_t* weights){
    /*
    c_fem_integrationPoints(uint64_t order, int64_t elementType, double* coords) 

    Define the coordinates and weights for integration according to the type of element and 
    order of evaluation sought.

    INPUTS:

        -> order:    Order of integration.


        -> elementType:  Geometric Type of element. 
                         It can be: elLine, elTriangle, elQuadrangle,
                         elTetrahedra or elHexahedra.
    OUTPUTS: 
        
        -> coords:  Coordinates to evaluate the integral.

        -> weights: Weights to evaluate the integral.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    uint64_t i,j;
    uint64_t npoints, ndim;
    double a=0.0, b=0.0, c=0.0, w=0.0; 

    // Safely initialize the array.
    coords->ncols = 0;
    coords->nrows = 0;
    coords->size = 0;
    coords->p_data = NULL;

    weights->ncols = 0;
    weights->nrows = 0;
    weights->size = 0;
    weights->p_data = NULL;

    // Check if the elementType given is ok.
    if ( elementType < elNode || elementType > elHexahedra ){
        coords = NULL;
        return OTI_FEM_InvalidElementType;
    }

    // Depending on the element type, compute the data.
    if (elementType == elNode){
        npoints = 1;
        ndim = 1;

        c_darray_createEmpty(coords,npoints,ndim);
        c_darray_createEmpty(weights,npoints,1);

        c_darray_setItem(0.0,0,0,coords);
        c_darray_setItem(1.0,0,0,weights);

    } else if (elementType == elLine){
        
        uint64_t nIntPts = (order + 1)/2;
        // Line element.
        ndim = 1;
        if (nIntPts <= 1){ // Accepts 0 or 1.
            
            npoints = 1;
            c_darray_createEmpty(coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,1);

            // Point 0
            i = 0;
            a = 0.000000000000000;
            w = 2.000000000000000;
            i =  c_fem_addLineIntegrationPoints(1, i, a, w, coords, weights);


        } else if (nIntPts == 2) {

            npoints = 2;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0;
            a = 0.577350269189626;
            w = 1.000000000000000;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);
            

        } else if (nIntPts == 3) {

            npoints = 3;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.888888888888889;
            i =  c_fem_addLineIntegrationPoints(1, i, a, w, coords, weights); 

            a = 0.774596669241483; w = 0.555555555555556;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);


        } else if (nIntPts == 4) {

            npoints = 4;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0; 

            a = 0.861136311594053; w = 0.347854845137454;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.339981043584856; w = 0.652145154862546;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            

        } else if (nIntPts == 5) {

            npoints = 5;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.568888888888889;
            i =  c_fem_addLineIntegrationPoints(1, i, a, w, coords, weights);

            a = 0.906179845938664; w = 0.236926885056189;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.538469310105683; w = 0.478628670499366;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        } else if (nIntPts == 6) {

            npoints = 6;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0;

            a = 0.932469514203152; w = 0.171324492379170;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.661209386466265; w = 0.360761573048139;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.238619186083197; w = 0.467913934572691;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        } else if (nIntPts == 7) {

            npoints = 7;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.417959183673469;
            i =  c_fem_addLineIntegrationPoints(1, i, a, w, coords, weights);

            a = 0.949107912342759; w = 0.129484966168870;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.741531185599394; w = 0.279705391489277;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.405845151377397; w = 0.381830050505119;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        } else if (nIntPts == 8) {

            npoints = 8;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 

            a = 0.960289856497536; w = 0.101228536290376;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.796666477413627; w = 0.222381034453374;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.525532409916329; w = 0.313706645877887;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.183434642495650; w = 0.362683783378362;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        } else if (nIntPts == 9) {

            npoints = 9;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 

            a = 0.000000000000000; w = 0.362683783378362;
            i =  c_fem_addLineIntegrationPoints(1, i, a, w, coords, weights);

            a = 0.968160239507626; w = 0.101228536290376;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.836031107326636; w = 0.222381034453374;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.613371432700590; w = 0.313706645877887;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.324253423403809; w = 0.362683783378362;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        } else {    // Order >= 10  

            npoints = 10;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 

            a = 0.973906528517172; w = 0.066671344308688;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.865063366688985; w = 0.149451349150581;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.679409568299024; w = 0.219086362515982;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.433395394129247; w = 0.269266719309996;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.148874338981631; w = 0.295524224714753;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        }

    } else if (elementType == elTriangle){
        
        // Triangular element .
        ndim = 2;

        if (order <= 1){ // Accepts 0 or 1.

            npoints = 1;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 1.000000000000000; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);

        } else if (order == 2){

            npoints = 3;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Points 0, 1, 2
            i = 0; 
            a = 0.666666666666667; b = 0.166666666666667; c = b;
            w = 0.333333333333333; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

        } else if (order == 3){

            npoints = 1+3;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w =-0.562500000000000; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);

            a = 0.600000000000000; b = 0.200000000000000; c = b;
            w = 0.520833333333333; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

        } else if (order == 4){

            npoints = 3+3;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0;
            a = 0.108103018168070; b = 0.445948490915965; c = b;
            w = 0.223381589678011; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.816847572980459; b = 0.091576213509771; c = b;
            w = 0.109951743655322; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);
            
        } else if (order == 5){

            npoints = 1+3+3;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.225000000000000; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);
            
            a = 0.059715871789770; b = 0.470142064105115; c = b;
            w = 0.132394152788506; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.797426985353087; b = 0.101286507323456; c = b;
            w = 0.125939180544827; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            
        } else if (order == 6){

            npoints = 3+3+6;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 

            a = 0.501426509658179; b = 0.249286745170910; c = b;
            w = 0.116786275726379; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.873821971016996; b = 0.063089014491502; c = b;
            w = 0.050844906370207; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.053145049844817; b = 0.310352451033784; c = 0.636502499121399;
            w = 0.082851075618374; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);
            
        } else if (order == 7){

            npoints = 1+3+3+6;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w =-0.149570044467682; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);
            
            a = 0.479308067841920; b = 0.260345966079040; c = b;
            w = 0.175615257433208; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.869739794195568; b = 0.065130102902216; c = b;
            w = 0.053347235608838; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.048690315425316; b = 0.312865496004874; c = 0.638444188569810;
            w = 0.077113760890257; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);
            
        } else if (order == 8){

            npoints = 1+3+3+3+6;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.144315607677787; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);
            
            a = 0.081414823414554; b = 0.459292588292723; c = b;
            w = 0.095091634267285; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.658861384496480; b = 0.170569307751760; c = b;
            w = 0.103217370534718; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.898905543365938; b = 0.050547228317031; c = b;
            w = 0.032458497623198; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.008394777409958; b = 0.263112829634638; c = 0.728492392955404;
            w = 0.027230314174435; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights); 



        } else if (order == 9){

            npoints = 1+3+3+3+3+6;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.097135796282799; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);
            
            a = 0.020634961602525; b = 0.489682519198738; c = b;
            w = 0.031334700227139; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.125820817014127; b = 0.437089591492937; c = b;
            w = 0.077827541004774; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.623592928761935; b = 0.188203535619033; c = b;
            w = 0.079647738927210; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.910540973211095; b = 0.044729513394453; c = b;
            w = 0.025577675658698; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.036838412054736; b = 0.221962989160766; c = 0.741198598784498;
            w = 0.043283539377289; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);

        
        } else {

            npoints = 1+3+3+6+6+6;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.090817990382754; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);
            
            a = 0.028844733232685; b = 0.485577633383657; c = b;
            w = 0.036725957756467; w *= 0.5;            
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.781036849029926; b = 0.109481575485037; c = b;
            w = 0.045321059435528; w *= 0.5;            
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.141707219414880; b = 0.307939838764121; c = 0.550352941820999;
            w = 0.072757916845420; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);

            a = 0.025003534762686; b = 0.246672560639903; c = 0.728323904597411;
            w = 0.028327242531057; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);

            a = 0.009540815400299; b = 0.066803251012200; c = 0.923655933587500;
            w = 0.009421666963733; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);

        }




    } else if (elementType == elQuadrangle){

        darray_t coord_tmp;
        darray_t weights_tmp;

        double w_tmp1 = 0.0;
        double w_tmp2 = 0.0;

        ndim = 2;

        // Call the solution for the corresponding 1D line element.
        c_fem_integrationPoints(order, elLine, &coord_tmp, &weights_tmp);

        npoints = coord_tmp.nrows*coord_tmp.nrows;

        c_darray_createEmpty( coords, npoints, ndim);
        c_darray_createEmpty(weights, npoints,    1);

        for ( i = 0; i < coord_tmp.nrows; i++ ){

            // Get the first weight.
            c_darray_getItem(   &coord_tmp, i, 0, &a      ) ;
            c_darray_getItem( &weights_tmp, i, 0, &w_tmp1 ) ;

            for ( j = 0; j < coord_tmp.nrows; j++ ){

                // Get the second weight.
                c_darray_getItem(   &coord_tmp, j, 0, &b      ) ;
                c_darray_getItem( &weights_tmp, j, 0, &w_tmp2 ) ;

                w = w_tmp1 * w_tmp2;
                
                c_darray_setItem( a, coord_tmp.nrows*i + j, 0, coords );
                c_darray_setItem( b, coord_tmp.nrows*i + j, 1, coords );
                c_darray_setItem( w, coord_tmp.nrows*i + j, 0, weights);

            }

        }

        c_darray_free(&coord_tmp);
        c_darray_free(&weights_tmp);

        
    // } else if (elementType == elTetrahedra){
        
    } else if (elementType == elHexahedra){

        darray_t coord_tmp;
        darray_t weights_tmp;

        uint64_t k = 0, currentIndex = 0 ;

        double w_tmp1 = 0.0;
        double w_tmp2 = 0.0;
        double w_tmp3 = 0.0;

        ndim = 3;
        
        // Call the solution for the corresponding 1D line element.
        c_fem_integrationPoints(order, elLine, &coord_tmp, &weights_tmp);

        // Go for all possible combinations for 

        npoints = coord_tmp.nrows * coord_tmp.nrows * coord_tmp.nrows;

        c_darray_createEmpty( coords, npoints, ndim);
        c_darray_createEmpty(weights, npoints,    1);

        for ( i = 0; i < coord_tmp.nrows; i++ ){

            // Get the first weight.
            c_darray_getItem(   &coord_tmp, i, 0, &a      ) ;
            c_darray_getItem( &weights_tmp, i, 0, &w_tmp1 ) ;

            for ( j = 0; j < coord_tmp.nrows; j++ ){

                // Get the second weight.
                c_darray_getItem(   &coord_tmp, j, 0, &b      ) ;
                c_darray_getItem( &weights_tmp, j, 0, &w_tmp2 ) ;

                for ( k = 0; k < coord_tmp.nrows; k++ ){

                    // Get the second weight.
                    c_darray_getItem(   &coord_tmp, k, 0, &c      ) ;
                    c_darray_getItem( &weights_tmp, k, 0, &w_tmp3 ) ;

                    w = w_tmp1 * w_tmp2 * w_tmp3;
                    
                    c_darray_setItem( a, currentIndex, 0, coords );
                    c_darray_setItem( b, currentIndex, 1, coords );
                    c_darray_setItem( c, currentIndex, 2, coords );
                    c_darray_setItem( w, currentIndex, 0, weights);

                    currentIndex+= 1;

                }

            }

        }

        c_darray_free(&coord_tmp);
        c_darray_free(&weights_tmp);
    
    } else {

        return OTI_FEM_NotImplemented;

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_fem_addLineIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                           double a,  double w,
                                           darray_t* coords, darray_t* weights){
    /*
    c_fem_addTriangleIntegrationPoints( numberOfPermutations,  startPoint, 
                                        a, b,  c,  w,
                                        coords, weights)

    Permutations of the .


    INPUTS:

        -> numberOfPermutations: Number of permutations for the selected point. (1, 3 or 6)

        -> startPoint: Index of the starting point in the 

        -> a: Coordinate 

        -> w: Weight for this point

        -> coords:  ( ncoords x 1 ) Array to write the coordinates. Must come allocated.

        -> weights: ( ncoords x 1 ) Array to write the weights. Must come allocated.
    
    OUTPUTS: 

        -> Position after last element added. (startPoint + numberOfPermutations). Current positionAdded position

    */ 
    // ************************************************************************************************
    uint64_t i = 0 ,j = 0;

    if (numberOfPermutations == 1){
        // Point 1
        i = startPoint; 
        c_darray_setItem( a, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

    } else if (numberOfPermutations == 2){

        // Point 1
        i = startPoint; 
        c_darray_setItem(-a, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 2
        i+= 1; 
        c_darray_setItem( a, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

    }

    return i+1;
}   
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
uint64_t c_fem_addTriangleIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                           double a, double b, double c, double w,
                                           darray_t* coords, darray_t* weights){
    /*
    c_fem_addTriangleIntegrationPoints( numberOfPermutations,  startPoint, 
                                        a, b,  c,  w,
                                        coords, weights)

    Permutations of the .


    INPUTS:

        -> numberOfPermutations: Number of permutations for the selected point. (1, 3 or 6)

        -> startPoint: Index of the starting point in the 

        -> a: Area coordinate 1

        -> b: Area coordinate 2

        -> c: Area coordinate 3

        -> w: Weight for this configuration                      

        -> coords:  ( ncoords x 2 ) Array to write the coordinates. Must come allocated.

        -> weights: ( ncoords x 1 ) Array to write the weights. Must come allocated.
    
    OUTPUTS: 

        -> Position after last element added. (startPoint + numberOfPermutations). Current positionAdded position

    */ 
    // ************************************************************************************************
    uint64_t i=0,j=0;

    if (numberOfPermutations == 1){
        // Point 1
        i = startPoint; 
        j = 0; c_darray_setItem( b, i, j, coords);
        j = 1; c_darray_setItem( c, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

    } else if (numberOfPermutations == 3){

        // Point 1
        i = startPoint; 
        j = 0; c_darray_setItem(b, i, j, coords);
        j = 1; c_darray_setItem(b, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 2
        i+= 1; 
        j = 0; c_darray_setItem(a, i, j, coords);
        j = 1; c_darray_setItem(b, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 3
        i+= 1; 
        j = 0; c_darray_setItem(b, i, j, coords);
        j = 1; c_darray_setItem(a, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

    } else if (numberOfPermutations == 6){
        
        // Point 1
        i = startPoint; 
        j = 0; c_darray_setItem( b, i, j, coords);
        j = 1; c_darray_setItem( c, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 2
        i+= 1; 
        j = 0; c_darray_setItem( c, i, j, coords);
        j = 1; c_darray_setItem( b, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 3
        i+= 1; 
        j = 0; c_darray_setItem( a, i, j, coords);
        j = 1; c_darray_setItem( c, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 4
        i+= 1; 
        j = 0; c_darray_setItem( c, i, j, coords);
        j = 1; c_darray_setItem( a, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 5
        i+= 1; 
        j = 0; c_darray_setItem( a, i, j, coords);
        j = 1; c_darray_setItem( b, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 6
        i+= 1;
        j = 0; c_darray_setItem( b, i, j, coords);
        j = 1; c_darray_setItem( a, i, j, coords);
        c_darray_setItem( w, i, 0, weights); 
    }

    return i+1;
}   
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_QuadSerendP2_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_QuadSerendP2_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the serendipity 2D element.


    NODE NUMBERING:

                           (3)* *(6)* *(2) 
                            *           *
                            *           *
                           (7)         (5)
                            *           *
                            *           *
                           (0)* *(4)* *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, ..., 8. (N1, ..., N8)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN    , derNa  , derNaa
                        derNb   , derNab , derNbb
                        derNc   , derNac , 
                        derNbc  , derNcc ,  
                        

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     (ncoords x ndim) array with the  data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    SOURCE:
        
        -> http://www.pckingsford.com/cykchee/phd/chD.pdf

    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double xi, eta, evalBasis_i;

    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 7 ){
        printf("--- InvalidBaseId ---");
        exit(1);
        // return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        c_darray_getItem(coords,i,0,&xi);
        c_darray_getItem(coords,i,1,&eta);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0-xi)*(1.0-eta)*(1.+xi+eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(-1.+eta)*(2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(-1.+xi)*(xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.-eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.-xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(1-2.*xi-2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0+xi)*(1.0-eta)*(1.-xi+eta);  

            }else if (basisDer == derNa){

                evalBasis_i = 0.25*(-1.+eta)*(-2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.25*(1.+xi)*(-xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.-eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(-1-2.*xi+2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0+xi)*(1.0+eta)*(1.-xi-eta);  

            }else if (basisDer == derNa){

                evalBasis_i = 0.25*(1.+eta)*(2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.25*(1.+xi)*(xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(1+2.*xi+2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 3){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0-xi)*(1.0+eta)*(1.+xi-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.+eta)*(-2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(-1.+xi)*(-xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.-xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(-1+2.*xi-2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }
            // =============================================================================
        }  else if (basisId == 4){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = xi*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.5*(1.+xi)*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = (eta - 1.); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNab){

                evalBasis_i = xi; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 5){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0+xi)*(1.0+eta)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =-0.5*(1.+eta)*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -eta*(1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNbb){

                evalBasis_i = -(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = -eta; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 6){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i =-xi*(1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.5*(1.+xi)*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = -(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNab){

                evalBasis_i =-xi; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 7){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+eta)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.5*(1.+eta)*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  eta*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNbb){

                evalBasis_i = (xi-1.); 

            }else if (basisDer == derNab){

                evalBasis_i = eta; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_QuadP1_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_QuadP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:

                           (3)* * * * *(2) 
                            *           *
                            *           *
                            *           *
                            *           *
                            *           *
                           (0)* * * * *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double xi, eta, evalBasis_i;
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 3 ){
        return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        c_darray_getItem(coords,i,0,&xi);
        c_darray_getItem(coords,i,1,&eta);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0-xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.0-eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(1.0-xi); 

            }else if (basisDer == derNab){

                evalBasis_i =  0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0+xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.25*(1.0-eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(1.0+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = -0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0+xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.25*(1.0+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  0.25*(1.0+xi); 

            }else if (basisDer == derNab){

                evalBasis_i =  0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 3){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0-xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.0+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  0.25*(1.0-xi); 

            }else if (basisDer == derNab){ 

                evalBasis_i = -0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_TriangP2_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_TriangP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the P1 2D element.

    
    NODE NUMBERING:

    (2)
     * *
     *   * 
    (5)   (4) 
     *       *
     *         *
    (0)* *(3)* *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. 
                       For this case, id = 0,1,2,3,4 or 5. (N1, N2, N3, N4, N5, N6)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.



    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double xi, eta, evalBasis_i;
    
    if ( basisId > 5 ){
        return OTI_FEM_InvalidBaseId;
    }

    

    for(i=0; i<ncoords; i++){
        
        c_darray_getItem(coords,i,0,&xi);
        c_darray_getItem(coords,i,1,&eta);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){
            // N1
            // Detect which derivative is being computed
            if (basisDer == derN){
                
                evalBasis_i = 2.*pow(eta,2.)+4.*eta*xi - 3.*eta + 2.*pow(xi,2.)-3.*xi+ 1.; 

            } else if (basisDer == derNa){

                evalBasis_i = 4.*eta + 4.*xi - 3.; 

            } else if (basisDer == derNb){

                evalBasis_i = 4.*eta + 4.*xi - 3.; 

            } else if (basisDer == derNaa){

                evalBasis_i = 4.; 

            }  else if (basisDer == derNab){

                evalBasis_i = 4.; 

            }  else if (basisDer == derNbb){

                evalBasis_i = 4.; 

            } else {

                evalBasis_i = 0.0;  // dN1/d everything else.
                
            }

        } else if (basisId == 1){
            // N2
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 2.*pow(xi,2.0)-xi; // N2 = xi

            }else if (basisDer == derNa){

                evalBasis_i = 4.*xi-1.; 

            } else if (basisDer == derNaa){

                evalBasis_i = 4.; 

            } else{

                evalBasis_i = 0.0;

            }

        } else if (basisId == 2){
            // N3
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 2.*pow(eta,2.0)-eta; 

            }else if (basisDer == derNb){

                evalBasis_i = 4.*eta-1.; 

            } else if (basisDer == derNbb){

                evalBasis_i = 4.; 

            } else{

                evalBasis_i = 0.0; // dN1/deta = 0.0 and everything else (if asked).

            }

        } else if (basisId == 3){
            // N4
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = - 4.*eta*xi - 4.*pow(xi,2.0) + 4.*xi; 

            }else if (basisDer == derNa){

                evalBasis_i =  - 4.*eta - 8.*xi + 4.; 

            } else if (basisDer == derNaa){

                evalBasis_i = -8.; 

            }else if (basisDer == derNb){

                evalBasis_i = - 4.*xi; 

            } else if (basisDer == derNab){

                evalBasis_i = -4.; 

            } else{

                evalBasis_i = 0.0; 

            }

        } else if (basisId == 4){
            // N5
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 4.*eta*xi ; 

            }else if (basisDer == derNa){

                evalBasis_i =  4.*eta ; 

            }else if (basisDer == derNb){

                evalBasis_i = 4.*xi; 

            } else if (basisDer == derNab){

                evalBasis_i = 4.; 

            } else{

                evalBasis_i = 0.0; 

            }

        }else if (basisId == 5){
            // N6
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = - 4.*eta*xi - 4.*pow(eta,2.0) + 4.*eta; 

            }else if (basisDer == derNb){

                evalBasis_i =  - 4.*xi - 8.*eta + 4.; 

            } else if (basisDer == derNbb){

                evalBasis_i = -8.; 

            }else if (basisDer == derNa){

                evalBasis_i = - 4.*eta; 

            } else if (basisDer == derNab){

                evalBasis_i = -4.; 

            } else{

                evalBasis_i = 0.0; 

            }

        }  

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_TriangP1_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_TriangP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the P1 2D element.


    NODE NUMBERING:

                           (2)
                            * *
                            *   * 
                            *     *  
                            *       *
                            *         *
                           (0)* * * * *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1 or 2. (N1, N2, N3)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double xi, eta, evalBasis_i;
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 2 ){
        return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        c_darray_getItem(coords,i,0,&xi);
        c_darray_getItem(coords,i,1,&eta);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 1.0-xi-eta; // N1 = 1-xi-eta

            }else if (basisDer == derNa){

                evalBasis_i = -1.0; // dN1/dxi  = 1.0

            }else if (basisDer == derNb){

                evalBasis_i = -1.0; // dN1/deta  = 1.0

            } else{

                evalBasis_i = 0.0;  // dN1/d everything else.
                
            }

        } else if (basisId == 1){
            
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = xi; // N2 = xi

            }else if (basisDer == derNa){

                evalBasis_i = 1.0; // dN2/dxi  = 1.0

            } else{

                evalBasis_i = 0.0; // dN2/deta = 0.0 and everything else (if asked).

            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = eta; // N3 = eta

            }else if (basisDer == derNb){

                evalBasis_i = 1.0; // dN3/deta  = 1.0

            } else{

                evalBasis_i = 0.0; // dN3/dxi = 0.0 and everything else.
                
            }

        } 

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_TriangP0_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_TriangP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the P1 2D element.

    NODE NUMBERING:
                            
                     *                    |           *
                     * *                  |           * *
                     *   *                            *   * 
                     *     *         <-- o r -->      *     *  
                     *  (0)  *                        *       *
                     *         *          |           *         *
                     * * * * * * *        |          (0)* * * * * *

    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0. (N1)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab     

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double  evalBasis_i;
    
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 1 ){
        return OTI_FEM_InvalidBaseId;
    }

    
    for(i=0; i<ncoords; i++){
                    
        // Detect which derivative is being computed
        if (basisDer == derN){

            evalBasis_i = 1.0; // N1 = xi

        } else{

            evalBasis_i = 0.0; // everything else (if asked).

        }

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_LineP2_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_LineP2_1Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:


                           (0)* *(2)* *(1)



    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [    xi_1   ],
                         [    xi_2   ],
                             ... 
                         [ xi_ncoord,] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords = coords->nrows;
    double xi, evalBasis_i;
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 2 ){
        return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        c_darray_getItem(coords,i,0,&xi);
        
        // Detect which basis function is being computed: N1, N2
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.5*xi*(1.0-xi);

            }else if (basisDer == derNa){

                evalBasis_i = -0.5+xi;

            }else if (basisDer == derNaa){

                evalBasis_i = 1.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.5*xi*(1.0+xi); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.5+xi; 

            }else if (basisDer == derNaa){

                evalBasis_i = 1.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = (1.0-xi*xi); 

            }else if (basisDer == derNa){

                evalBasis_i = -2.0*xi; 

            }else if (basisDer == derNaa){

                evalBasis_i = -2.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_LineP1_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_LineP1_1Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:


                           (0)* * * * *(1)



    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [    xi_1   ],
                         [    xi_2   ],
                             ... 
                         [ xi_ncoord,] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords = coords->nrows;
    double xi, evalBasis_i;
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 1 ){
        return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        c_darray_getItem(coords,i,0,&xi);
        
        // Detect which basis function is being computed: N1, N2
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.5*(1.0-xi);

            }else if (basisDer == derNa){

                evalBasis_i = -0.5;

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.5*(1.0+xi); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.5; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_PntP0_0Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_PntP0_0Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:


                           (0)



    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [    xi_1   ],
                         [    xi_2   ],
                             ... 
                         [ xi_ncoord,] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords = coords->nrows;
    double evalBasis_i;
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 0 ){
        return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){
        
        // Detect which basis function is being computed: N1, N2
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 1.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------




// ----------------------------------------------------------------------------------------------------
// -------------------------------     END OTIFEM FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------






















































// ----------------------------------------------------------------------------------------------------
// ---------------------------------     DARRAY FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void c_darray_getItem(darray_t* p_array, uint64_t i, uint64_t j, double* num){
    /*
    c_darray_getItem(darray_t* p_array, uint64_t i, uint64_t j, double* num)

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
inline void c_darray_setItem( double num, uint64_t i, uint64_t j, darray_t* p_array){
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
    
    
    p_array->p_data[j+i*p_array->ncols] = num; 

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
int64_t c_darray_zeros(darray_t* p_array, uint64_t nrows, uint64_t ncols){
    /*
    c_sotiarray_createEmpty(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey)

    C-level memory allocation of a dense oti number a direction array from a file

    INPUTS:

        ->  p_array:    Address of the array to be allocated.

        ->   shapex:    Number of elements in the first  dimension.

        ->   shapey:    Number of elements in the second dimension.
        
        

    OUTPUTS:
        -> The result is the array with the memory allocated and initialized.
    */ 
    // ************************************************************************************************
    
    double value = 0.0;

    
    p_array->ncols  = ncols       ;
    p_array->nrows  = nrows       ;
    p_array->size   = ncols*nrows ;
    p_array->p_data = (double*) malloc( p_array->size * sizeof(double) );

    if (p_array->p_data == NULL){
        return OTI_OutOfMemory;
    }

    // Set 0 to all elements.
    memset(p_array->p_data, value, p_array->size*sizeof(double)  );

    return OTI_success;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_darray_free(darray_t* p_array){
    /*
    c_darray_free(sotiarray_t* p_array)
    
    Free all memory associated with the array.

    INPUTS:

        ->  p_array:    Address of the array to be freed.

    */ 
    // ************************************************************************************************
    
    // Free pointer 
    free( p_array->p_data);
    p_array->p_data = NULL;
    p_array->ncols  =    0;
    p_array->nrows  =    0;
    p_array->size   =    0;
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_darray_createEmpty(darray_t* p_array, uint64_t nrows, uint64_t ncols){
    /*
    c_darray_createEmpty(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey)

    C-level memory allocation of array.

    INPUTS:

        ->  p_array:    Address of the array to be allocated.

        ->   shapex:    Number of elements in the first  dimension.

        ->   shapey:    Number of elements in the second dimension.

        

    OUTPUTS:
        -> The result is the memory allocated.
    */ 
    // ************************************************************************************************
    
    
    p_array->ncols  = ncols;
    p_array->nrows  = nrows;
    p_array->size   = ncols*nrows;
    p_array->p_data = (double*) malloc( p_array->size * sizeof(double) );
        
    if (p_array->p_data == NULL){
        return OTI_OutOfMemory;
    }
    
    return OTI_success;

}
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
// -------------------------------     END DARRAY FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

































































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
























// ----------------------------------------------------------------------------------------------------
// -------------------------------     SPROTINUM FUNCTIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_fdiv(double numx, sotinum_t* numy, sotinum_t* res, directionHelper* p_dH){
    /*
    PURPOSE:  Inverse Tangent function counting all quadrants for OTI numbers.

    */
    //*************************************************************************************************

    sotinum_t tmp;

    c_soti_pow(numy,-1.0, p_dH, &tmp); // 1 / y

    c_soti_mulf(&tmp,numx,res); 
    
    c_soti_free(&tmp);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_divf(sotinum_t* numx, double numy, sotinum_t* res){
    /*
    PURPOSE:  Inverse Tangent function counting all quadrants for OTI numbers.

    */
    //*************************************************************************************************

    c_soti_mulf(numx,(1.0/numy),res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_div(sotinum_t* numx, sotinum_t* numy, sotinum_t* res, directionHelper* p_dH){
    /*
    PURPOSE:  Inverse Tangent function counting all quadrants for OTI numbers.

    */
    //*************************************************************************************************
    
    sotinum_t tmp;

    c_soti_pow(numy,-1.0,p_dH, &tmp); // 1 / y

    c_soti_mul(numx,&tmp,res,p_dH); 
    
    c_soti_free(&tmp);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_atan2(sotinum_t* numx, sotinum_t* numy, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Tangent function counting all quadrants for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[numx->order-1].p_fder; // holder for the derivatives in the helper.
    double x0    ;
    uint8_t i;
    sotinum_t tmp;


    // first perform the division of the numbers

    // 1/y
    c_soti_pow(numy,-1.0,p_dH, res);

    
    //x*(1/y) 
    c_soti_mul(numx, res, &tmp, p_dH);
    c_soti_free(res);

    x0 = c_soti_getReal(&tmp);

    for( i=0; i<(numx->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0] =  atan2(c_soti_getReal(numx),c_soti_getReal(numy));

            case 1:
                derivs[1] =  1.0/(pow(x0, 2) + 1);

            case 2:
                derivs[2] =  -2*x0/pow(pow(x0, 2) + 1, 2);
                // -2*x1/(x1**2 + 1)**2
            case 3:
                derivs[3] =  2*(4*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 2);
                // 2*(4*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**2
            case 4:
                derivs[4] =  24*x0*(-2*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 3);
                // 24*x1*(-2*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3
            case 5:
                derivs[5] =  24*(16*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 12*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 3);
                // 24*(16*x1**4/(x1**2 + 1)**2 - 12*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3 
            case 6:
                derivs[6] = 240*x0*(-16*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 16*pow(x0, 2)/(pow(x0, 2) + 1) - 3)/pow(pow(x0, 2) + 1, 4);
                // 240*x1*(-16*x1**4/(x1**2 + 1)**2 + 16*x1**2/(x1**2 + 1) - 3)/(x1**2 + 1)**4
            case 7:
                derivs[7] = 720*(64*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 80*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 24*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 4);
                // 720*(64*x1**6/(x1**2 + 1)**3 - 80*x1**4/(x1**2 + 1)**2 + 24*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**4
            case 8:
                derivs[8] = 40320*x0*(-16*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 24*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 10*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 5);
                // 40320*x1*(-16*x1**6/(x1**2 + 1)**3 + 24*x1**4/(x1**2 + 1)**2 - 10*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 9:
                derivs[9] = 40320*(256*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) - 448*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 240*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 40*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 5);
                // 40320*(256*x1**8/(x1**2 + 1)**4 - 448*x1**6/(x1**2 + 1)**3 + 240*x1**4/(x1**2 + 1)**2 - 40*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 10:
                derivs[10] =725760*x0*(-256*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) + 512*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 336*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 80*pow(x0, 2)/(pow(x0, 2) + 1) - 5)/pow(pow(x0, 2) + 1, 6);
                // 725760*x1*(-256*x1**8/(x1**2 + 1)**4 + 512*x1**6/(x1**2 + 1)**3 - 336*x1**4/(x1**2 + 1)**2 + 80*x1**2/(x1**2 + 1) - 5)/(x1**2 + 1)**6
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, &tmp, p_dH, res);
    c_soti_free(&tmp);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_logb(sotinum_t* num, int base, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  logarithm of base b function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  log(x0)/log(base);

            case 1:
                derivs[1]  =  1/(x0*log(base));

            case 2:
                derivs[2]  =  -1/(pow(x0, 2)*log(base));
                
            case 3:
                derivs[3]  =  2/(pow(x0, 3)*log(base));
                
            case 4:
                derivs[4]  =  -6/(pow(x0, 4)*log(base));
                
            case 5:
                derivs[5]  =  24/(pow(x0, 5)*log(base));
                
            case 6:
                derivs[6]  =  -120/(pow(x0, 6)*log(base));
                            
            case 7:
                derivs[7]  =  720/(pow(x0, 7)*log(base));
                
            case 8:
                derivs[8]  =  -5040/(pow(x0, 8)*log(base));
                
            case 9:
                derivs[9]  =  40320/(pow(x0, 9)*log(base));
                
            case 10:
                derivs[10] =  -362880/(pow(x0, 10)*log(base));
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_log10(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  logarithm of base 10 function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  log(x0)/log(10);

            case 1:
                derivs[1]  =  1/(x0*log(10));

            case 2:
                derivs[2]  =  -1/(pow(x0, 2)*log(10));
                
            case 3:
                derivs[3]  =  2/(pow(x0, 3)*log(10));
                
            case 4:
                derivs[4]  =  -6/(pow(x0, 4)*log(10));
                
            case 5:
                derivs[5]  =  24/(pow(x0, 5)*log(10));
                
            case 6:
                derivs[6]  =  -120/(pow(x0, 6)*log(10));
                            
            case 7:
                derivs[7]  =  720/(pow(x0, 7)*log(10));
                
            case 8:
                derivs[8]  =  -5040/(pow(x0, 8)*log(10));
                
            case 9:
                derivs[9]  =  40320/(pow(x0, 9)*log(10));
                
            case 10:
                derivs[10] =  -362880/(pow(x0, 10)*log(10));
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_atanh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Hyperbolic tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  atanh(x0);

            case 1:
                derivs[1]  =  1.0/(-pow(x0, 2) + 1);

            case 2:
                derivs[2]  =  2*x0/pow(pow(x0, 2) - 1, 2);
                
            case 3:
                derivs[3]  =  2*(-4*pow(x0, 2)/(pow(x0, 2) - 1) + 1)/pow(pow(x0, 2) - 1, 2);
                
            case 4:
                derivs[4]  =  24*x0*(2*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 3);
                
            case 5:
                derivs[5]  =  24*(-16*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) + 12*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 3);
                
            case 6:
                derivs[6]  =  240*x0*(16*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) - 16*pow(x0, 2)/(pow(x0, 2) - 1) + 3)/pow(pow(x0, 2) - 1, 4);
                            
            case 7:
                derivs[7]  =  720*(-64*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) + 80*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) - 24*pow(x0, 2)/(pow(x0, 2) - 1) + 1)/pow(pow(x0, 2) - 1, 4);
                
            case 8:
                derivs[8]  =  40320*x0*(16*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) - 24*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) + 10*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 5);
                
            case 9:
                derivs[9]  =  40320*(-256*pow(x0, 8)/pow(pow(x0, 2) - 1, 4) + 448*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) - 240*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) + 40*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 5);
                
            case 10:
                derivs[10] =  725760*x0*(256*pow(x0, 8)/pow(pow(x0, 2) - 1, 4) - 512*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) + 336*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) - 80*pow(x0, 2)/(pow(x0, 2) - 1) + 5)/pow(pow(x0, 2) - 1, 6);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_asinh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Hyperbolic sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  acosh(x0);

            case 1:
                derivs[1]  =  pow(pow(x0, 2) + 1, -1.0L/2.0L);

            case 2:
                derivs[2]  =  -x0/pow(pow(x0, 2) + 1, 3.0L/2.0L);
                
            case 3:
                derivs[3]  =  (3*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 3.0L/2.0L);
                //            (3*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 3.0L/2.0L)
                
            case 4:
                derivs[4]  =  3*x0*(-5*pow(x0, 2)/(pow(x0, 2) + 1) + 3)/pow(pow(x0, 2) + 1, 5.0L/2.0L);
                //             3*x0*(-5*pow(x0, 2)/(pow(x0, 2) + 1) + 3)/pow(pow(x0, 2) + 1, 5.0L/2.0L)
                
            case 5:
                derivs[5]  =  3*(35*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 30*pow(x0, 2)/(pow(x0, 2) + 1) + 3)/pow(pow(x0, 2) + 1, 5.0L/2.0L);
                
            case 6:
                derivs[6]  =  15*x0*(-63*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 70*pow(x0, 2)/(pow(x0, 2) + 1) - 15)/pow(pow(x0, 2) + 1, 7.0L/2.0L);
                            
            case 7:
                derivs[7]  =  45*(231*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 315*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 105*pow(x0, 2)/(pow(x0, 2) + 1) - 5)/pow(pow(x0, 2) + 1, 7.0L/2.0L);
                
            case 8:
                derivs[8]  =  315*x0*(-429*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 693*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 315*pow(x0, 2)/(pow(x0, 2) + 1) + 35)/pow(pow(x0, 2) + 1, 9.0L/2.0L);
                
            case 9:
                derivs[9]  =  315*(6435*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) - 12012*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 6930*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 1260*pow(x0, 2)/(pow(x0, 2) + 1) + 35)/pow(pow(x0, 2) + 1, 9.0L/2.0L);
                
            case 10:
                derivs[10] =  2835*x0*(-12155*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) + 25740*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 18018*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 4620*pow(x0, 2)/(pow(x0, 2) + 1) - 315)/pow(pow(x0, 2) + 1, 11.0L/2.0L);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_acosh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Hyperbolic inverse cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double x2m1 = pow(x0, 2.) - 1.;
    double sqx2m1 = pow(x2m1, 0.5);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  acosh(x0);

            case 1:
                derivs[1]  =  pow(sqx2m1, -1.0);

            case 2:
                derivs[2]  =  -x0/pow(sqx2m1, 3.0);
                
            case 3:
                derivs[3]  =  (3.*pow(x0, 2.)/(x2m1) - 1.)/pow(sqx2m1, 3.0);
                
            case 4:
                derivs[4]  =  3.*x0*(-5.*pow(x0, .2)/(x2m1) + 3.)/pow(sqx2m1, 5.0);
                
            case 5:
                derivs[5]  =  3.*(35.*pow(x0, 4.)/pow(x2m1, 2.) - 30*pow(x0, 2.)/(x2m1) + 3.)/pow(sqx2m1, 5.0);
                
            case 6:
                derivs[6]  =  15.*x0*(-63.*pow(x0, 4.)/pow(x2m1, 2.) + 70.*pow(x0, 2.)/(x2m1) - 15.)/pow(sqx2m1, 7.0);
                            
            case 7:
                derivs[7]  =  45.*(231.*pow(x0, 6.)/pow(x2m1, 3.) - 315.*pow(x0, 4.)/pow(x2m1, 2.) + 105.*pow(x0, 2.)/(x2m1) - 5.)/pow(sqx2m1, 7.0);
                
            case 8:
                derivs[8]  =  315.*x0*(-429.*pow(x0, 6.)/pow(x2m1, 3.) + 693.*pow(x0, 4.)/pow(x2m1, 2.) - 315.*pow(x0, 2.)/(x2m1) + 35.)/pow(sqx2m1, 9.0);
                
            case 9:
                derivs[9]  =  315.*(6435.*pow(x0, 8.)/pow(x2m1, 4.) - 12012.*pow(x0, 6.)/pow(x2m1, 3.) + 6930.*pow(x0, 4.)/pow(x2m1, 2.) - 1260.*pow(x0, 2.)/(x2m1) + 35.)/pow(sqx2m1, 9.0);
                
            case 10:
                derivs[10] =  2835.*x0*(-12155.*pow(x0, 8.)/pow(x2m1, 4.) + 25740.*pow(x0, 6.)/pow(x2m1, 3.) - 18018.*pow(x0, 4.)/pow(x2m1, 2.) + 4620.*pow(x0, 2.)/(x2m1) - 315.)/pow(sqx2m1, 11.0);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_tanh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Hyperbolic tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double tanhx0 = tanh(x0);
    double tanh2  = pow(tanhx0, 2); 
    double tanh2m1 = tanh2 - 1;
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  tanhx0;

            case 1:
                derivs[1]  =  -tanh2m1;

            case 2:
                derivs[2]  =  2.*(tanh2m1)*tanhx0;
                
            case 3:
                derivs[3]  =  -2.*(tanh2m1)*(3.*tanh2 - 1.);
                
            case 4:
                derivs[4]  =  8.*(tanh2m1)*(3.*tanh2 - 2.)*tanhx0;
                
            case 5:
                derivs[5]  =  -8.*(tanh2m1)*(2.*pow(tanh2m1, 2.) + 11.*(tanh2m1)*tanh2 + 2.*pow(tanhx0, 4.));
                
            case 6:
                derivs[6]  =  16.*(tanh2m1)*(17.*pow(tanh2m1, 2.) + 26.*(tanh2m1)*tanh2 + 2.*pow(tanhx0, 4.))*tanhx0;
                            
            case 7:
                derivs[7]  =  -16.*(tanh2m1)*(17.*pow(tanh2m1, 3.) + 180.*pow(tanh2m1, 2.)*tanh2 + 114.*(tanh2m1)*pow(tanh(x0), 4.) + 4*pow(tanhx0, 6.));
                
            case 8:
                derivs[8]  =  128.*(tanh2m1)*(62.*pow(tanh2m1, 3.) + 192.*pow(tanh2m1, 2.)*tanh2 + 60.*(tanh2m1)*pow(tanh(x0), 4.) + pow(tanhx0, 6.))*tanhx0;
                
            case 9:
                derivs[9]  =  -128.*(tanh2m1)*(62.*pow(tanh2m1, 4.) + 1072.*pow(tanh2m1, 3.)*tanh2 + 1452.*pow(tanh2m1, 2.)*pow(tanhx0, 4.) + 247.*(tanh2m1)*pow(tanhx0, 6.) + 2.*pow(tanhx0, 8.));
                
            case 10:
                derivs[10] =  256.*(tanh2m1)*(1382.*pow(tanh2m1, 4.) + 7192.*pow(tanh2m1, 3.)*tanh2 + 5097.*pow(tanh2m1, 2.)*pow(tanhx0, 4.) + 502.*(tanh2m1)*pow(tanhx0, 6.) + 2.*pow(tanhx0, 8.))*tanhx0;
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_sqrt(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Square root function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    // double x0 = num->p_coefs[0];
    double sqx = sqrt(c_soti_getReal(num));
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  sqx;

            case 1:
                derivs[1]  =  (0.5)/sqx;

            case 2:
                derivs[2]  =  -0.25/pow(sqx, 3.0);
                
            case 3:
                derivs[3]  =  (0.375)/pow(sqx, 5.0);
                
            case 4:
                derivs[4]  =  -0.9375/pow(sqx, 7.0);
                
            case 5:
                derivs[5]  =  (3.28125)/pow(sqx, 9.0);
                
            case 6:
                derivs[6]  =  -14.765625/pow(sqx, 11.0);
                            
            case 7:
                derivs[7]  =  (81.2109375)/pow(sqx, 13.0);
                
            case 8:
                derivs[8]  =  -527.87109375/pow(sqx, 15.0);
                
            case 9:
                derivs[9]  =  (3959.033203125)/pow(sqx, 17.0);
                
            case 10:
                derivs[10] =  (-33651.7822265625)/pow(sqx, 19.0);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_cosh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Hyperbolic Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double ch = cosh(x0);
    double sh = sinh(x0);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  ch;

            case 1:
                derivs[1]  =  sh;

            case 2:
                derivs[2]  =  ch;
                
            case 3:
                derivs[3]  =  sh;
                
            case 4:
                derivs[4]  =  ch;
                
            case 5:
                derivs[5]  =  sh;
                
            case 6:
                derivs[6]  =  ch;
                            
            case 7:
                derivs[7]  =  sh;
                
            case 8:
                derivs[8]  =  ch;
                
            case 9:
                derivs[9]  =  sh;
                
            case 10:
                derivs[10] =  ch;
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_sinh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Hyperbolic Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double ch = cosh(x0);
    double sh = sinh(x0);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  sh;

            case 1:
                derivs[1]  =  ch;

            case 2:
                derivs[2]  =  sh;
                
            case 3:
                derivs[3]  =  ch;
                
            case 4:
                derivs[4]  =  sh;
                
            case 5:
                derivs[5]  =  ch;
                
            case 6:
                derivs[6]  =  sh;
                            
            case 7:
                derivs[7]  =  ch;
                
            case 8:
                derivs[8]  =  sh;
                
            case 9:
                derivs[9]  =  ch;
                
            case 10:
                derivs[10] =  sh;
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_asin(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  asin(x0);

            case 1:
                derivs[1]  =  pow(-pow(x0, 2.) + 1., -1.0/2.0);

            case 2:
                derivs[2]  =  x0/pow(-pow(x0, 2.0) + 1., 3.0/2.0);
                
            case 3:
                derivs[3]  =  (3.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 1.)/pow(-pow(x0, 2.) + 1., 3.0/2.0);
                
            case 4:
                derivs[4]  =  3.*x0*(5.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 3.)/pow(-pow(x0, 2.) + 1., 5.0/2.0);
                
            case 5:
                derivs[5]  =  3.*(35.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 30.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 3.)/pow(-pow(x0, 2.) + 1., 5.0/2.0);
                
            case 6:
                derivs[6]  = 15.*x0*(63.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 70.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 15.)/pow(-pow(x0, 2.) + 1., 7.0/2.0);
                            
            case 7:
                derivs[7]  = 45.*(231.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 315.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 105.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 5.)/pow(-pow(x0, 2.) + 1., 7.0/2.0);
                
            case 8:
                derivs[8]  = 315.*x0*(429.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 693.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 315.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 35.)/pow(-pow(x0, 2.) + 1., 9.0/2.0);
                
            case 9:
                derivs[9]  = 315.*(6435.*pow(x0, 8.)/pow(-pow(x0, 2.) + 1., 4.) + 12012.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 6930.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 1260.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 35.)/pow(-pow(x0, 2.) + 1., 9.0/2.0);
                
            case 10:
                derivs[10] =2835.*x0*(12155.*pow(x0, 8.)/pow(-pow(x0, 2.) + 1., 4.) + 25740.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 18018.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 4620.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 315.)/pow(-pow(x0, 2.) + 1., 11.0/2.0);
                

        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_acos(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  acos(x0);

            case 1:
                derivs[1]  =  -1.0/sqrt(-pow(x0, 2.0) + 1.0);

            case 2:
                derivs[2]  =  -x0/pow(-pow(x0, 2.0) + 1.0, 3.0/2.0);
                
            case 3:
                derivs[3]  =  -(3.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 1.0)/pow(-pow(x0, 2.0) + 1.0, 3.0/2.0);
                
            case 4:
                derivs[4]  =  -3.0*x0*(5.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 3.0)/pow(-pow(x0, 2.0) + 1.0, 5.0/2.0);
                
            case 5:
                derivs[5]  =  -3.0*(35.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 30.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 3.0)/pow(-pow(x0, 2.0) + 1.0, 5.0/2.0);
                
            case 6:
                derivs[6]  = -15.0*x0*(63.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 70.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 15.0)/pow(-pow(x0, 2.0) + 1.0, 7.0/2.0);
                            
            case 7:
                derivs[7]  = -45.0*(231.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 315.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 105.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 5.0)/pow(-pow(x0, 2.0) + 1.0, 7.0/2.0);
                
            case 8:
                derivs[8]  = -315.0*x0*(429.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 693.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 315.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 35.0)/pow(-pow(x0, 2.0) + 1.0, 9.0/2.0);
                
            case 9:
                derivs[9]  = -315.0*(6435.0*pow(x0, 8.0)/pow(-pow(x0, 2.0) + 1.0, 4.0) + 12012.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 6930.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 1260.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 35.0)/pow(-pow(x0, 2.0) + 1.0, 9.0/2.0);
                
            case 10:
                derivs[10] =-2835.0*x0*(12155.0*pow(x0, 8.0)/pow(-pow(x0, 2.0) + 1.0, 4.0) + 25740.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 18018.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 4620.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 315)/pow(-pow(x0, 2.0) + 1.0, 11.0/2.0);
                

        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_soti_atan(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double x02   = pow(x0,2.0);
    double x02p1 = x02+1.0;
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0] =  atan(x0);

            case 1:
                derivs[1] =  1.0/(x02p1);

            case 2:
                derivs[2] =  -2.0 * x0 / ( pow( x02p1 , 2.0 ) );
                // -2*x1/(x1**2 + 1)**2
            case 3:
                derivs[3] =  2.0*(4.0*x02/(x02p1) - 1.0)/(pow(x02p1,2.0));
                // 2*(4*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**2
            case 4:
                derivs[4] =  24.0*x0*(-2.0*x02/(x02p1) + 1.0)/( pow( x02p1, 3) );
                // 24*x1*(-2*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3
            case 5:
                derivs[5] =  24.0*(16.0*pow( x0 ,4.0 )/( pow( x02p1, 2.0 ) ) - 12.0 * x02/(x02p1) + 1.0)/( pow( x02p1, 3.0) );
                // 24*(16*x1**4/(x1**2 + 1)**2 - 12*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3 
            case 6:
                derivs[6] = 240.0*x0*(-16.0*pow(x0,4.0)/pow(x02p1,2.0) + 16.0*x02/(x02p1) - 3.0 )/( pow(x02p1,4.0) );
                // 240*x1*(-16*x1**4/(x1**2 + 1)**2 + 16*x1**2/(x1**2 + 1) - 3)/(x1**2 + 1)**4
            case 7:
                derivs[7] = 720.0*(64.0*pow(x0,6.0)/pow(x02p1,3.0) - 80.0*pow(x0,4.0)/pow(x02p1,2.0) + 24.0*x02/(x02p1) - 1.0)/(pow(x02p1,4.0));
                // 720*(64*x1**6/(x1**2 + 1)**3 - 80*x1**4/(x1**2 + 1)**2 + 24*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**4
            case 8:
                derivs[8] = 40320.0*x0*(-16*pow(x0,6.0)/pow(x02p1,3.0) + 24.0*pow(x0,4.0)/pow(x02p1,2.0) - 10.0*x02/(x02p1) + 1.0)/(pow(x02p1,5.0));
                // 40320*x1*(-16*x1**6/(x1**2 + 1)**3 + 24*x1**4/(x1**2 + 1)**2 - 10*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 9:
                derivs[9] = 40320.0*(256.0*pow(x0,8.0)/(pow(x02p1,4.0)) - 448.0*pow(x0,6.0)/(pow(x02p1,3.0)) + 240.0*pow(x0,4.0)/(pow(x02p1,2.0)) - 40.0*x02/x02p1 + 1.0)/(pow(x02p1,5.0));
                // 40320*(256*x1**8/(x1**2 + 1)**4 - 448*x1**6/(x1**2 + 1)**3 + 240*x1**4/(x1**2 + 1)**2 - 40*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 10:
                derivs[10] =725760.0*x0*(-256*pow(x0,8.0)/(pow(x02p1,4.0)) + 512*pow(x0,6.0)/(pow(x02p1,3.0)) - 336*pow(x0,4.0)/(pow(x02p1,2.0)) + 80*x02/x02p1 - 5.0)/(pow(x02p1,6.0));
                // 725760*x1*(-256*x1**8/(x1**2 + 1)**4 + 512*x1**6/(x1**2 + 1)**3 - 336*x1**4/(x1**2 + 1)**2 + 80*x1**2/(x1**2 + 1) - 5)/(x1**2 + 1)**6
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_tan(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double tanx0 = tan(x0);
    double tanx02p1 = pow(tanx0,2.0) + 1.0 ;
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0] =  tan(x0);
            case 1:
                derivs[1] =  tanx02p1; 
                // tan(g)**2 + 1
            case 2:
                derivs[2] =  2.*(tanx02p1)*tanx0 ; 
                // 2*(tan(g)**2 + 1)*tan(g)
            case 3:
                derivs[3] =  2.*(tanx02p1)*(3.*pow(tanx0,2.0) + 1.);
                // 2*(tan(g)**2 + 1)*(3*tan(g)**2 + 1)
            case 4:
                derivs[4] =  8.*(tanx02p1)*(3.*pow(tanx0,2.0) + 2.)*tanx0;
                // 8*(tan(g)**2 + 1)*(3*tan(g)**2 + 2)*tan(g)
            case 5:
                derivs[5] =  8.*(tanx02p1)*(2.*pow((tanx02p1),2.0) + 
                    11.*(tanx02p1)*pow(tanx0,2.0) + 2.*pow(tanx0,4.0));
                //8*(tan(g)**2 + 1)*(2*(tan(g)**2 + 1)**2 + 11*(tan(g)**2 + 1)*tan(g)**2 + 2*tan(g)**4)
            case 6:
                derivs[6] = 16.*(tanx02p1)*(17*pow((tanx02p1),2.) + 
                    26.*(tanx02p1)*pow(tanx0,2.0) + 
                    2.*pow(tanx0,4.0))*tanx0;
                // 16*(tan(g)**2 + 1)*(17*(tan(g)**2 + 1)**2 + 26*(tan(g)**2 + 1)*tan(g)**2 + 2*tan(g)**4)*tan(g)
            case 7:
                derivs[7] = 16.*(tanx02p1)*(17.*pow((tanx02p1),3.) 
                    + 180.*pow((tanx02p1),2.)*pow(tanx0,2.0)
                    + 114.*(tanx02p1)*pow(tanx0,4.0) + 4.*pow(tanx0,6.0));
                //  16*(tan(g)**2 + 1)*(17*(tan(g)**2 + 1)**3 + 180*(tan(g)**2 + 1)**2*tan(g)**2 +
                // 114*(tan(g)**2 + 1)*tan(g)**4 + 4*tan(g)**6)
            case 8:
                derivs[8] = 128.*(tanx02p1)*(62.*pow((tanx02p1),3.) +
                    192.*pow((tanx02p1),2.0)*pow(tanx0,2.0) +
                     60.*(tanx02p1)*pow(tanx0,4.0)+ pow(tanx0,6.0))*tanx0;
                // 128*(tan(g)**2 + 1)*(62*(tan(g)**2 + 1)**3 + 192*(tan(g)**2 + 1)**2*tan(g)**2 +
                //  60*(tan(g)**2 + 1)*tan(g)**4 + tan(g)**6)*tan(g)
            case 9:
                derivs[9] = 128.*(pow(tanx0,2.0) + 1.)*(
                    62*pow((tanx02p1),4) + 
                    1072.*pow((tanx02p1),3.)*pow(tanx0,2.0) + 
                    1452.*pow((tanx02p1),2.)*pow(tanx0,4.0) + 
                    247. *    (tanx02p1)    *pow(tanx0,6.0) +
                    2.*(pow(tanx0,8.0))
                    );
                // Too many calls to pow(tanx0,2.0) +1.
                // 128*
                // (tan(x1)**2 + 1)*
                // (
                //     62*(tan(x1)**2 + 1)**4 + 
                //     1072*(tan(x1)**2 + 1)**3*tan(x1)**2 + 
                //     1452*(tan(x1)**2 + 1)**2*tan(x1)**4 + 
                //     247 *(tan(x1)**2 + 1)   *tan(x1)**6 + 
                //     2*tan(x1)**8
                // )
            case 10:

                derivs[10] =256.*(tanx02p1)*(
                    1382.*pow((tanx02p1),4.) + 
                    7192.*pow((tanx02p1),3.)*pow(tanx0,2.0) + 
                    5097.*pow((tanx02p1),2.)*pow(tanx0,4.0) + 
                    502. *(tanx02p1)*pow(tanx0,6.0) + 
                    2.*pow(tanx0,8.0)
                    )*tanx0;
                // 256*
                // (tan(x1)**2 + 1)*
                // (
                //     1382*(tan(x1)**2 + 1)**4 + 
                //     7192*(tan(x1)**2 + 1)**3*tan(x1)**2 + 
                //     5097*(tan(x1)**2 + 1)**2*tan(x1)**4 + 
                //     502 *(tan(x1)**2 + 1)   *tan(x1)**6 + 
                //     2*tan(x1)**8
                // ) * tan(x1)
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_soti_cos(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = c_soti_getReal(num);
    uint8_t i;
    uint8_t s = 0;
    double sign = 1.;
    
    for( i=0; i<(num->order+1); i++){
    
        if (s == 0){
        
            derivs[i]=sign*cos(x0);
        
        }else{
        
            sign = sign * (-1.0);
            derivs[i]=sign*sin(x0);
    
        }
    
        s = (s+1)%2;
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_sin(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = c_soti_getReal(num);
    uint8_t i;
    uint8_t s = 1;
    double sign = -1.;
    
    for( i=0; i<(num->order+1); i++){
    
        if (s == 0){
        
            derivs[i]=sign*cos(x0);
        
        }else{
        
            sign = sign * (-1.0);
            derivs[i]=sign*sin(x0);
    
        }
    
        s = (s+1)%2;
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_log(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Natural logarithm function for OTI numbers. 

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = c_soti_getReal(num);
    double sign = -1.;
    double factor = 1.;
    uint8_t i;    

    for (i=0; i<(num->order+1); i++){

        
        if (i == 0){
        
            derivs[i]=log(x0);
        
        }else{
         
            derivs[i] = factor * pow(sign,(i+1)) * (1.0/pow(x0,i) );
            factor    = factor * i;
    
        }

    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_exp(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Exponential function for OTI numbers. -> e**x, x is otinum

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double value = exp(c_soti_getReal(num));
    uint8_t i;    

    for (i=0; i<(num->order+1); i++){

        derivs[i]=value;

    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_pow(sotinum_t* num, double exponent, directionHelper* p_dH,sotinum_t* res){
    /*
    PURPOSE:  Power function for OTI numbers, for non integer exponents.

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double power_i = exponent;
    double x0 = c_soti_getReal(num);
    uint8_t flag = 0;
    double factor = 1.;
    uint8_t i;
    

    for (i=0; i<(num->order+1); i++){

        if( power_i != 0.0){
            
            derivs[i]=factor*pow(x0,power_i);
            factor = factor*power_i;
            power_i -= 1.;

        }else{

            if (i==0){

                derivs[i] = x0; // not sure if 1.0 or if coefs[0]
                flag = 1;

            } else if (flag == 0 ){

                derivs[i]=factor;
                flag = 1;

            }else{ 

                derivs[i] = 0.;

            }            

        }

    }
  
  // Compute all the derivatives 
  c_soti_derivFunc(derivs, num,  p_dH, res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_derivFunc(double* fder, sotinum_t* g, directionHelper* p_dH, sotinum_t* feval){
    /*
    void c_soti_derivFunc(double* fder, otinum_t* g, otinum_t* feval)
    
    Given the derivatives of a function f(g) with respect to g, finds the evaluation of the function 
    when g is an oti number.

    To differentiate a function f that depends on another function
    g which depends on several variables. 

    i.e. f( g(x1,...,xn) )

    g comes evaluated and it is represented by an OTI number.

    INPUTS:
        
        ->  fder:   Array of values holding all the derivatives of f with respect to g up to 
                    g.order. 
        
        ->  g:      oti number that represents g(x1,...,xn).

        -> iter:   Number of iterations to be evaluated. Best for exponentiation evaluation.

        ->  feval:  Evaluated function f(g) where g is an oti number.

    */

    uint8_t order = g->order;
    uint8_t i=0;

    sotinum_t tmp1, tmp2, tmp3;
    sotinum_t gp1, gp2, gp4, gp8;

    // Prepare for the evaluation
    
    if(g->size >= 1){

        gp1 = *g;

        if (gp1.p_indx[0]==0){

            // forget about real part
            gp1.p_indx = &gp1.p_indx[1];
            gp1.p_coefs = &gp1.p_coefs[1];
            gp1.size -= 1;

        }

        if (fder[0] == 0.0){

            c_soti_createEmpty(feval, 0, order);

        } else {

            c_soti_createEmpty(feval, 1, order);
            feval->p_coefs[0] = fder[0];
            feval->p_indx[0]  = 0;

        }

        c_soti_createEmpty(&gp2 , 0, order);
        c_soti_createEmpty(&gp4 , 0, order);
        c_soti_createEmpty(&gp8 , 0, order);
        
        // printf("C: Order Given: %hhu\n",order);

        for (i=1; i<=order; i++){

            if (i ==  1){
                
                if (fder[1]!=0.0){
                    c_soti_copy(  &tmp1, &gp1    );
                    c_soti_smulf( &tmp1, fder[1] );
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  2){
                
                // printf("C: i=2\n");
                c_soti_mul(&gp1, &gp1, &gp2, p_dH);

                if (fder[2]!=0.0){
                    
                    c_soti_copy(&tmp1,&gp2);
                    c_soti_smulf(&tmp1,fder[2]/2.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval, p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  3){

                if (fder[3]!=0.0){
                    c_soti_mul(&gp2, &gp1, &tmp1, p_dH);
                    c_soti_smulf(&tmp1,fder[3]/6.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }


            } else if (i ==  4){

                c_soti_mul(&gp2, &gp2, &gp4, p_dH);

                if (fder[3]!=0.0){
                    c_soti_copy(&tmp1,&gp4);
                    c_soti_smulf(&tmp1,fder[4]/24.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  5){

                if (fder[5]!=0.0){

                    c_soti_mul(&gp4, &gp1, &tmp1, p_dH);
                    c_soti_smulf(&tmp1,fder[5]/120.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  6){


                if (fder[6]!=0.0){
                    c_soti_mul(&gp4, &gp2, &tmp1, p_dH);
                    c_soti_smulf(&tmp1,fder[6]/720.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  7){

                if (fder[7]!=0.0){
                    c_soti_mul(&gp4, &gp2, &tmp2, p_dH);
                    c_soti_mul(&tmp2, &gp1, &tmp1, p_dH);
                    c_soti_smulf(&tmp1,fder[7]/5040.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp2);
                    c_soti_free(&tmp3);
                }


            } else if (i ==  8){


                c_soti_mul(&gp4, &gp4, &gp8, p_dH);

                if (fder[8]!=0.0){
                    c_soti_copy(&tmp1,&gp8);
                    c_soti_smulf(&tmp1, fder[8]/40320.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  9){

                if (fder[9]!=0.0){
                    c_soti_mul(&gp8, &gp1, &tmp1, p_dH);
                    c_soti_smulf(&tmp1, fder[9]/362880.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i == 10){

                if (fder[10]!=0.0){
                    c_soti_mul(&gp8, &gp1, &tmp1, p_dH);
                    c_soti_smulf(&tmp1, fder[10]/3628800.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            }

        }
        
        c_soti_free(&gp2);
        c_soti_free(&gp4);
        c_soti_free(&gp8);

    } else {

        if(fder[0]!=0.0){

            // Create number without internal derivatives (because all are zero)
            c_soti_createEmpty(feval,1,g->order);
            feval->p_coefs[0] = fder[0];
            feval->p_indx[0]  =       0;

        } else {

            // create empty number
            c_soti_createEmpty(feval,0,g->order);

        }
        
    }
    


}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
double c_soti_getReal(sotinum_t* num){
    /*
    PURPOSE:  Get the real coefficient of the given  sparse otinum.

    */
    //*************************************************************************************************
    
    double res = 0.0;

    if (num->size > 0){

        if( num->p_indx[0] == 0){

            res = num->p_coefs[0];
        
        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_ipowfast(sotinum_t* num1, uint8_t exp, sotinum_t* res, directionHelper* p_dH){
    /*
    void c_soti_ipowfast(sotinum_t* num1, uint8_t exp, sotinum_t* res)
    
    Fast Power of soti to an integer power. NOTE: This is  efficient for 
    positive exponents lower or equal than 10!.


    INPUTS:

        -> num1:    Direction to compute Faa Di Bruno formula
        
        -> exp:     exponent. 

        ->  p_dH:   list of helpers.

    OUTPUTS:

        -> res:    Holder with the rresulting number.
       res = num1 ** exp          // Python syntax.

       // It actually performs the following

       res = num1*num1*...*num1   // exp times

    */



    uint8_t flag = 0;

    sotinum_t numr[4];


    // printf(" ---> C: exp received: %hhu \n\n",exp);

    if (exp == 0){

        // printf(" ---> C: Case 0 \n");
        // Result is 1. 
        c_soti_createEmpty(&numr[0],1,num1->order);
        numr[0].p_coefs[0] = 1;
        numr[0].p_indx[0]  = 0;
        flag = 0;

    } else if (exp ==  1){

        // printf(" ---> C: Case 1 \n");
        // Result is the same number 
        c_soti_copy(&numr[0],num1); 
        flag = 0;

    } else if (exp ==  2){

        // printf(" ---> C: Case 2 \n");
        // The square of the number num1 x num1
        c_soti_mul(num1, num1, &numr[0], p_dH);
        flag = 0;

    } else if (exp ==  3){

        // printf(" ---> C: Case 3 \n");
        // The third power of num1: (num1 x num1) x num1
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], num1, &numr[1], p_dH);
        c_soti_free(&numr[0]);
        flag = 1;

    } else if (exp ==  4){

        // printf(" ---> C: Case 4 \n");
        // The fourth power of num1: (num1 x num1) x (num1 x num1)
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_free(&numr[0]);
        flag = 1;

    } else if (exp ==  5){

        // printf(" ---> C: Case 5 \n");
        // The fifth power of num1: (num1 x num1) x (num1 x num1) x num1
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_free(&numr[0]);
        c_soti_mul(&numr[1], num1, &numr[2], p_dH);
        c_soti_free(&numr[1]);
        flag = 2;

    } else if (exp ==  6){

        // printf(" ---> C: Case 6 \n");
        // The sixth power of num1: (num1 x num1) x (num1 x num1) x (num1 x num1)
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_mul(&numr[1], &numr[0], &numr[2], p_dH);
        c_soti_free(&numr[0]);
        c_soti_free(&numr[1]);
        flag = 2;

    } else if (exp ==  7){

        // printf(" ---> C: Case 7 \n");
        // The seventh power of num1: (num1 x num1) x (num1 x num1) x (num1 x num1) x num1
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_mul(&numr[1], &numr[0], &numr[2], p_dH);
        c_soti_mul(&numr[2], num1, &numr[3], p_dH);
        c_soti_free(&numr[0]);
        c_soti_free(&numr[1]);
        c_soti_free(&numr[2]);
        flag = 3;


    } else if (exp ==  8){

        // printf(" ---> C: Case 8 \n");
        // The eigth power of num1: (num1 x num1) x (num1 x num1) x (num1 x num1) x (num1 x num1)
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_mul(&numr[1], &numr[1], &numr[2], p_dH);
        c_soti_free(&numr[0]);
        c_soti_free(&numr[1]);
        flag = 2;

    } else if (exp ==  9){

        // printf(" ---> C: Case 9 \n");
        // The ninth power of num1: (num1 x num1) x (num1 x num1) x (num1 x num1) x (num1 x num1)
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_mul(&numr[1], &numr[1], &numr[2], p_dH);
        c_soti_mul(&numr[2], num1, &numr[3], p_dH);
        c_soti_free(&numr[0]);
        c_soti_free(&numr[1]);
        c_soti_free(&numr[2]);        
        flag = 3;

    } else if (exp == 10){

        // printf(" ---> C: Case 10 \n");

        // The seventh power of num1: (num1 x num1) x (num1 x num1) x (num1 x num1) x (num1 x num1)
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_mul(&numr[1], &numr[1], &numr[2], p_dH);
        c_soti_mul(&numr[2], &numr[0], &numr[3], p_dH);
        c_soti_free(&numr[0]);
        c_soti_free(&numr[1]);
        c_soti_free(&numr[2]);        
        flag = 3;
    }
           
    *res = numr[flag];

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_soti_ipow(sotinum_t* num1, uint8_t exp, sotinum_t* res, directionHelper* p_dH){
    /*
    void c_soti_ipow(sotinum_t* num1, uint8_t exp, sotinum_t* res)
    
    Power a soti to an integer power. NOTE: This is  efficient for exponents lower or equal than 10!.


    INPUTS:

        -> num1:    Direction to compute Faa Di Bruno formula
        
        -> exp:     exponent. 

        ->  p_dH:   list of helpers.

    OUTPUTS:

        -> res:    Holder with the rresulting number.
       res = num1 ** exp          // Python syntax.

       // It actually performs the following

       res = num1*num1*...*num1   // exp times

    */

    
    // uint64_t* indxOrder = NULL;
    // uint64_t* multIndx  = NULL; // Index to be multiplied
    // uint8_t order = num1->order;
    // uint8_t orderSum = 0;

    uint64_t   i = 0;
    uint8_t flag = 0;

    sotinum_t numr[2];


    // indxOrder = (uint64_t*)malloc(num1->size*sizeof(uint64_t));
    // if (indxOrder == NULL){
    //     printf("--- MemoryError ---\n");
    //     exit(1);
    // }

    // for (i=0; i<num1->size; i++){
    //     indxOrder[i] = c_sumUI8(&p_dH[order-1].p_expA[(num1->p_indx[i]-1)*order],order);
    // }

    // orderSum = (exp-1)*indxOrder[0];

    c_soti_copy( &numr[0], num1); // Copy initial value

    for( i=1; i<exp; i++){

        if (flag == 0 ){

            c_soti_mul(&numr[0], num1, &numr[1], p_dH);
            c_soti_free(&numr[0]);
            flag = 1;

        } else{

            c_soti_mul(&numr[1], num1, &numr[0], p_dH);
            c_soti_free(&numr[1]);
            flag = 0;

        }
        
    }

    if (flag == 0 ){
        
        *res = numr[0];

    } else{
        
        *res = numr[1];

    }
    // 
    // c_soti_copy( res, num1);
    

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void c_soti_neg( sotinum_t* num1, sotinum_t* res){
    /*
    void c_soti_copy(sotinum_t* num1, sotinum_t* res)

    negate soti.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        
        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = -num1.copy()    

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    c_soti_createEmpty(res, num1->size, num1->order);

    if (num1->size != 0){

        // memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
        memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 
        
        for (i=0; i<num1->size; i++){

            res->p_coefs[i] = -num1->p_coefs[i];
        
        }

    }    

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_copy(sotinum_t* res, sotinum_t* num1){
    /*
    void c_soti_copy(sotinum_t* res, sotinum_t* num1)

    Copy soti.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        
        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1.copy()     

    */ 
    // ************************************************************************************************
    

    c_soti_createEmpty(res, num1->size, num1->order);

    if (num1->size != 0){

        memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
        memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 

    }    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_fsub(sotinum_t* num1, double num2, sotinum_t* res){
    /*
    void c_soti_subf(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    subtract oti and real numbers.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    real.

        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 - num2

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    uint8_t order = num1->order;

    

    // check if num1 or num2 are zero
    if (num1->size == 0 && num2 == 0.0){

        c_soti_createEmpty(res, 0, order);

    } else if(num1->size == 0) {

        c_soti_createEmpty(res, 1, order);

        res->p_coefs[0] = num2;
        res->p_indx[0]  = 0   ;  
 

    } else {    

        if (num1->p_indx[0] == 0){

            c_soti_createEmpty(res, num1->size, order);
            memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 

            for (i=0; i<num1->size;i++){

                res->p_coefs[i] = -num1->p_coefs[i];

            }

            res->p_coefs[0] += num2;

        } else {

            c_soti_createEmpty(res, num1->size+1, order);
            memcpy(&res->p_indx[1], num1->p_indx ,num1->size*sizeof(uint64_t)); 

            for (i=0; i<num1->size;i++){

                res->p_coefs[i+1] = -num1->p_coefs[i];

            }

            res->p_coefs[0] = num2;
            res->p_indx[0]  = 0;

        }
        
    }
    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_subf(sotinum_t* num1, double num2, sotinum_t* res){
    /*
    void c_soti_subf(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    subtract oti and real numbers.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    real.

        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 - num2

    */ 
    // ************************************************************************************************
    

    uint8_t order = num1->order;

    

    // check if num1 or num2 are zero
    if (num1->size == 0 && num2 == 0.0){

        c_soti_createEmpty(res, 0, order);

    } else if(num1->size == 0) {

        c_soti_createEmpty(res, 1, order);

        res->p_coefs[0] = -num2;
        res->p_indx[0]  = 0   ;  
 

    } else {    

        if (num1->p_indx[0] == 0){

            c_soti_createEmpty(res, num1->size, order);
            memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
            memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 
            res->p_coefs[0] -= num2;

        } else {

            c_soti_createEmpty(res, num1->size+1, order);
            memcpy(&res->p_coefs[1],num1->p_coefs,num1->size*sizeof(double)  );
            memcpy(&res->p_indx[1], num1->p_indx ,num1->size*sizeof(uint64_t)); 
            res->p_coefs[0] = -num2;
            res->p_indx[0]  = 0;

        }
        
    }
    
    

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_sub(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH){
    /*
    void c_soti_sub(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    subtract two oti numbers

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    Address of the other operand.

        ->res:     Address of the result holder. Must not come allocated. 
                   Cannot be the same address as num1 or num2

        -> p_dH:   List of helpers

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 - num2

    */ 
    // ************************************************************************************************
    uint64_t i, i1=0, i2=0, size_res=0;
    uint8_t order = num1->order;

    double*   p_tmpcoefs = p_dH[num1->order-1].p_coefs;
    uint64_t*  p_tmpindx = p_dH[num1->order-1].p_indx ;
    uint64_t     ndirmax = p_dH[num1->order-1].Ndir   ;

    // Find the maximum number of coefficients in 
    uint64_t niter_max  = MIN(num1->size+num2->size, ndirmax); // Maximum number of iterations

    // check if num1 or num2 are zero
    if (num1->size == 0 && num2->size == 0){

        c_soti_createEmpty(res, size_res, order);

    } else if(num1->size == 0) {

        c_soti_createEmpty(res, num2->size, order);
        memcpy(res->p_coefs,num2->p_coefs,num2->size*sizeof(double)  );
        memcpy(res->p_indx, num2->p_indx ,num2->size*sizeof(uint64_t));  

    } else if(num2->size == 0) {

        c_soti_createEmpty(res, num1->size, order);
        memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
        memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 

    } else {    

        for( i = 0; i < niter_max; i++){

            if(i1 >= num1->size &&   i2 >= num2->size){
                break;
            }

            if(i1 >= num1->size){

                // All remaining elements are not in num1.
                
                p_tmpcoefs[i] = -num2->p_coefs[i2];
                p_tmpindx[i]  = num2->p_indx[i2];
                i2++;
                size_res++;

            } else if(i2 >= num2->size){

                // All remaining elements are not in num2.
                
                p_tmpcoefs[i] = num1->p_coefs[i1];
                p_tmpindx[i]  = num1->p_indx[i1];
                i1++;
                size_res++;


            } else {

                // Here i1 and i2 are looking for some value.
                
                if (num1->p_indx[i1] == num2->p_indx[i2]){


                    p_tmpcoefs[i] = num1->p_coefs[i1]-num2->p_coefs[i2];
                    p_tmpindx[i]  = num2->p_indx[i2];

                    i1++;
                    i2++;
                    size_res++;

                } else {

                    if (num1->p_indx[i1] < num2->p_indx[i2]){  // index of num1 goes first.

                        p_tmpcoefs[i] = num1->p_coefs[i1];
                        p_tmpindx[i]  = num1->p_indx[i1];
                        i1++;
                        size_res++;

                    } else {

                        p_tmpcoefs[i] = -num2->p_coefs[i2];
                        p_tmpindx[i]  = num2->p_indx[i2];
                        i2++;
                        size_res++;

                    }

                }

            }

                     
        }
        // Create new sprotinum
        
        c_soti_createEmpty(res, size_res, order);
        
        if (size_res>0){
            memcpy(res->p_coefs,p_tmpcoefs,size_res*sizeof(double)  );
            memcpy(res->p_indx, p_tmpindx ,size_res*sizeof(uint64_t));    
        }
    }


}    
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void c_soti_sumf(sotinum_t* num1, double num2, sotinum_t* res){
    /*
    void c_soti_suml(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    sum oti and real numbers.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    real.

        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 + num2

    */ 
    // ************************************************************************************************
    

    uint8_t order = num1->order;

    // check if num1 or num2 are zero
    if (num1->size == 0 && num2 == 0.0){

        c_soti_createEmpty(res, 0, order);

    } else if(num1->size == 0) {

        c_soti_createEmpty(res, 1, order);

        res->p_coefs[0] = num2;
        res->p_indx[0]  = 0   ;  
 

    } else {    

        if (num1->p_indx[0] == 0){

            c_soti_createEmpty(res, num1->size, order);
            memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
            memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 
            res->p_coefs[0] += num2;

        } else {

            c_soti_createEmpty(res, num1->size+1, order);
            memcpy(&res->p_coefs[1],num1->p_coefs,num1->size*sizeof(double)  );
            memcpy(&res->p_indx[1], num1->p_indx ,num1->size*sizeof(uint64_t)); 
            res->p_coefs[0] = num2;
            res->p_indx[0]  = 0;

        }
        
    }
    
    

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_smulf(sotinum_t* num1, double num2){
    /*
    void c_soti_smulf(otinum_t* num1, double num2, otinum_t* res, directionHelper* p_dH)

    Self multiply an oti number times a real coefficient.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    real.

        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 * num2

    */ 
    // ************************************************************************************************
    uint64_t i;
    
    // c_soti_createEmpty(res, num1->size, num1->order);

    if(num1->size!= 0 && num2 != 0.0){

        for( i = 0; i < num1->size; i++){
            
            num1->p_coefs[i]*=num2;
        }    

    } else {

        c_soti_free(num1);

    }
    
    

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_mulf(sotinum_t* num1, double num2, sotinum_t* res){
    /*
    void c_soti_mulf(otinum_t* num1, double num2, otinum_t* res, directionHelper* p_dH)

    multiply an oti number times a real coefficient.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    real.

        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 * num2

    */ 
    // ************************************************************************************************
    uint64_t i;
    
    

    if(num1->size != 0 && num2 != 0.0){

        c_soti_createEmpty(res, num1->size, num1->order);

        // Initialize the result holder.
        memcpy(res->p_coefs,num1->p_coefs,res->size*sizeof(double)  );
        memcpy(res->p_indx ,num1->p_indx ,res->size*sizeof(uint64_t));


        for( i = 0; i < res->size; i++){
            
            res->p_coefs[i]*=num2;
        }    

    } else {
        
        c_soti_createEmpty(res, 0, num1->order);

    }
    
    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_mul(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH){
    /*
    void c_soti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    multiply two oti numbers

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    Address of the other operand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions. Cannot be the same address as num1 or num2

        -> p_dH:   List of helpers

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 * num2

    */ 
    // ************************************************************************************************
    uint64_t i, j, ii, jj, indx;
    uint64_t ncoefs; // Always considers real to be present.
    uint8_t err=1, order = num1->order;

    double*   p_tmpcoefs = p_dH[num1->order-1].p_coefs;
    uint64_t*  p_tmpindx = p_dH[num1->order-1].p_indx ;
    uint64_t     ndirmax = MIN(p_dH[num1->order-1].Ndir,num1->size*num2->size);

    // printf("tmpIndx ptr: %x, tmpCoefs Ptr: %x \n",p_tmpindx, p_tmpcoefs);
    // printf("number of directions %llu\n",ndirmax);
    // printf("Received num1 with size %llu and order %hhu\n",num1->size,num1->order);
    // printf("Received num2 with size %llu and order %hhu\n",num2->size,num2->order);
    
    if( num1->size == 0 || num2->size == 0){
        
        ncoefs = 0;

    }else{

        ncoefs = 0;
        // Initialize in zero the result holder
        memset(p_tmpcoefs, 0, ndirmax*sizeof(double)  );
        memset(p_tmpindx , 0, ndirmax*sizeof(uint64_t));

        for( ii = 0; ii < num1->size; ii++){
            
            for( jj = 0; jj < num2->size; jj++){

                // Multiply directions.
                i = num1->p_indx[ii];
                j = num2->p_indx[jj];
                indx = c_helper_multIndxFast(i,j,order,p_dH,&err);

                if (err == 0){   // If error flag is off
                    //printf("i = %llu, j = %llu, indx = %llu\n",i,j,indx);
                    c_helper_insertIndx(p_tmpindx,indx,&ncoefs, 
                        p_tmpcoefs,
                        num1->p_coefs[ii] * num2->p_coefs[jj]);
                                                                            
                    // p_tmpcoefs[indx] += num1->p_coefs[ii] * num2->p_coefs[jj];

                }

            }
                     
        }
    }
    
    // Create new sprotinum
    
    c_soti_createEmpty(res, ncoefs, order);
    
    if (ncoefs != 0){

        // Copy all indices
        memcpy(res->p_coefs, p_tmpcoefs, ncoefs*sizeof(double)  );
        memcpy(res->p_indx , p_tmpindx,  ncoefs*sizeof(uint64_t));
        // for (ii = 0;ii<ncoefs;ii++){
        //     res->p_coefs[ii] = p_tmpcoefs[p_tmpindx[ii]];
        // }

    }

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_sum(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH){
    /*
    void c_soti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    sum two oti numbers

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    Address of the other operand.

        ->res:     Address of the result holder. Must not come allocated. 
                   Cannot be the same address as num1 or num2

        -> p_dH:   List of helpers

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 + num2

    */ 
    // ************************************************************************************************
    uint64_t i, i1=0, i2=0, size_res=0;
    uint8_t order = num1->order;

    double*   p_tmpcoefs = p_dH[num1->order-1].p_coefs;
    uint64_t*  p_tmpindx = p_dH[num1->order-1].p_indx ;
    uint64_t     ndirmax = p_dH[num1->order-1].Ndir   ;

    // Find the maximum number of coefficients in 
    uint64_t niter_max  = MIN(num1->size+num2->size, ndirmax); // Maximum number of iterations

    // check if num1 or num2 are zero
    if (num1->size == 0 && num2->size == 0){

        c_soti_createEmpty(res, size_res, order);

    } else if(num1->size == 0) {

        c_soti_createEmpty(res, num2->size, order);
        memcpy(res->p_coefs,num2->p_coefs,num2->size*sizeof(double)  );
        memcpy(res->p_indx, num2->p_indx ,num2->size*sizeof(uint64_t));  

    } else if(num2->size == 0) {

        c_soti_createEmpty(res, num1->size, order);
        memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
        memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 

    } else {    
        // printf("Adding two elements here!\n");
        for( i = 0; i < niter_max; i++){

            if(i1 >= num1->size &&   i2 >= num2->size){
                break;
            }

            if(i1 >= num1->size){

                // All remaining elements are not in num1.
                
                p_tmpcoefs[i] = num2->p_coefs[i2];
                p_tmpindx[i]  = num2->p_indx[i2];
                i2++;
                size_res++;

            } else if(i2 >= num2->size){

                // All remaining elements are not in num2.
                
                p_tmpcoefs[i] = num1->p_coefs[i1];
                p_tmpindx[i]  = num1->p_indx[i1];
                i1++;
                size_res++;


            } else {

                // Here i1 and i2 are looking for some value.
                
                if (num1->p_indx[i1] == num2->p_indx[i2]){


                    p_tmpcoefs[i] = num2->p_coefs[i2]+num1->p_coefs[i1];
                    p_tmpindx[i]  = num2->p_indx[i2];

                    i1++;
                    i2++;
                    size_res++;

                } else {

                    if (num1->p_indx[i1] < num2->p_indx[i2]){  // index of num1 goes first.

                        p_tmpcoefs[i] = num1->p_coefs[i1];
                        p_tmpindx[i]  = num1->p_indx[i1];
                        i1++;
                        size_res++;

                    } else {

                        p_tmpcoefs[i] = num2->p_coefs[i2];
                        p_tmpindx[i]  = num2->p_indx[i2];
                        i2++;
                        size_res++;

                    }

                }

            }

                     
        }
        // Create new sprotinum
        
        c_soti_createEmpty(res, size_res, order);
        
        if (size_res>0){
            memcpy(res->p_coefs,p_tmpcoefs,size_res*sizeof(double)  );
            memcpy(res->p_indx, p_tmpindx ,size_res*sizeof(uint64_t));    
        }
    }


}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void c_soti_free(sotinum_t* numHolder){
    /*
    c_freeOti(numHolder)

    Frees an allocated oti number

    INPUTS:

        ->numHolder:    Address of the number to be freed.
        

    */ 
    // ************************************************************************************************

    if (numHolder->p_coefs != NULL){

        free(numHolder->p_coefs); 
        numHolder->p_coefs = NULL;

    }

    if (numHolder->p_indx != NULL){

        free(numHolder->p_indx); 
        numHolder->p_indx = NULL;

    }
    numHolder->size = 0;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_createFromReal(double num, sotinum_t* numHolder, uint8_t order){
    /*
    c_soti_createFromReal( num, numHolder,  order)

    C-level memory allocation for a real-only oti number.

    INPUTS:
        -> num:         Real coefficient.

        ->numHolder:    Address of the number to be allocated.
        
        ->    order:    Order to be loaded in memory.
            Example: 3

        

    OUTPUTS:
        -> The result is the numHolder with the memory allocated and with the structure set up.
    */ 
    // ************************************************************************************************
    
    c_soti_createEmpty( numHolder, 1, order);

    numHolder->p_coefs[0] = num;
    numHolder->p_indx[0] = 0;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_createEmpty(sotinum_t* numHolder,   uint64_t ncoefs, uint8_t order){
    /*
    c_oti_createEmpty(numHolder, ndir, order)

    C-level memory allocation of a dense oti number a direction array from a file

    INPUTS:

        ->numHolder:    Address of the number to be allocated.
        
        ->    order:    Order to be loaded in memory.
            Example: 3

        ->     coefs:    Number of nonzero coefficients in the number.
            Example: 100

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    if (ncoefs == 0){

        numHolder->p_indx  = NULL ;
        numHolder->p_coefs = NULL ;

    } else{

        numHolder->p_indx = (uint64_t*)c_malloc_ptr(ncoefs,sizeof(uint64_t));
        
        numHolder->p_coefs = (double*)c_malloc_ptr(ncoefs ,sizeof(double) );

    }

    
    numHolder->size  = ncoefs;
    numHolder->order = order;
}
// ----------------------------------------------------------------------------------------------------










// ----------------------------------------------------------------------------------------------------
// -----------------------------     END SPROTINUM FUNCTIONS     --------------------------------------
// ----------------------------------------------------------------------------------------------------






















// ----------------------------------------------------------------------------------------------------
// ---------------------------------     OTINUM FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_atan2(otinum_t* numx, otinum_t* numy, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Tangent function counting all quadrants for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[numx->order-1].p_fder; // holder for the derivatives in the helper.
    double x0    ;
    uint8_t i;
    otinum_t tmp;


    // first perform the division of the numbers

    // 1/y
    c_oti_pow(numy,-1.0,p_dH, res);

    // Allocate memory for the result:
    tmp.p_coefs = (double* )malloc(numx->Ndir*sizeof(double)) ;
    if( tmp.p_coefs == NULL ){
        printf("---- MemoryError ----\n");
        exit(-1);
    }
    tmp.order = numx->order;
    tmp.Ndir = numx->Ndir;
    //x*(1/y) 
    c_oti_mul(numx, res, &tmp, p_dH);
    free(res->p_coefs);
    res->p_coefs = NULL;

    x0 = tmp.p_coefs[0];

    for( i=0; i<(numx->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0] =  atan2(numx->p_coefs[0],numy->p_coefs[0]);

            case 1:
                derivs[1] =  1.0/(pow(x0, 2) + 1);

            case 2:
                derivs[2] =  -2*x0/pow(pow(x0, 2) + 1, 2);
                // -2*x1/(x1**2 + 1)**2
            case 3:
                derivs[3] =  2*(4*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 2);
                // 2*(4*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**2
            case 4:
                derivs[4] =  24*x0*(-2*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 3);
                // 24*x1*(-2*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3
            case 5:
                derivs[5] =  24*(16*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 12*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 3);
                // 24*(16*x1**4/(x1**2 + 1)**2 - 12*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3 
            case 6:
                derivs[6] = 240*x0*(-16*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 16*pow(x0, 2)/(pow(x0, 2) + 1) - 3)/pow(pow(x0, 2) + 1, 4);
                // 240*x1*(-16*x1**4/(x1**2 + 1)**2 + 16*x1**2/(x1**2 + 1) - 3)/(x1**2 + 1)**4
            case 7:
                derivs[7] = 720*(64*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 80*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 24*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 4);
                // 720*(64*x1**6/(x1**2 + 1)**3 - 80*x1**4/(x1**2 + 1)**2 + 24*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**4
            case 8:
                derivs[8] = 40320*x0*(-16*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 24*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 10*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 5);
                // 40320*x1*(-16*x1**6/(x1**2 + 1)**3 + 24*x1**4/(x1**2 + 1)**2 - 10*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 9:
                derivs[9] = 40320*(256*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) - 448*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 240*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 40*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 5);
                // 40320*(256*x1**8/(x1**2 + 1)**4 - 448*x1**6/(x1**2 + 1)**3 + 240*x1**4/(x1**2 + 1)**2 - 40*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 10:
                derivs[10] =725760*x0*(-256*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) + 512*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 336*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 80*pow(x0, 2)/(pow(x0, 2) + 1) - 5)/pow(pow(x0, 2) + 1, 6);
                // 725760*x1*(-256*x1**8/(x1**2 + 1)**4 + 512*x1**6/(x1**2 + 1)**3 - 336*x1**4/(x1**2 + 1)**2 + 80*x1**2/(x1**2 + 1) - 5)/(x1**2 + 1)**6
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, &tmp, p_dH, res);
    free(tmp.p_coefs);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_logb(otinum_t* num, int base, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  logarithm of base b function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  log(x0)/log(base);

            case 1:
                derivs[1]  =  1/(x0*log(base));

            case 2:
                derivs[2]  =  -1/(pow(x0, 2)*log(base));
                
            case 3:
                derivs[3]  =  2/(pow(x0, 3)*log(base));
                
            case 4:
                derivs[4]  =  -6/(pow(x0, 4)*log(base));
                
            case 5:
                derivs[5]  =  24/(pow(x0, 5)*log(base));
                
            case 6:
                derivs[6]  =  -120/(pow(x0, 6)*log(base));
                            
            case 7:
                derivs[7]  =  720/(pow(x0, 7)*log(base));
                
            case 8:
                derivs[8]  =  -5040/(pow(x0, 8)*log(base));
                
            case 9:
                derivs[9]  =  40320/(pow(x0, 9)*log(base));
                
            case 10:
                derivs[10] =  -362880/(pow(x0, 10)*log(base));
                
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_oti_log10(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  logarithm of base 10 function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  log(x0)/log(10);

            case 1:
                derivs[1]  =  1/(x0*log(10));

            case 2:
                derivs[2]  =  -1/(pow(x0, 2)*log(10));
                
            case 3:
                derivs[3]  =  2/(pow(x0, 3)*log(10));
                
            case 4:
                derivs[4]  =  -6/(pow(x0, 4)*log(10));
                
            case 5:
                derivs[5]  =  24/(pow(x0, 5)*log(10));
                
            case 6:
                derivs[6]  =  -120/(pow(x0, 6)*log(10));
                            
            case 7:
                derivs[7]  =  720/(pow(x0, 7)*log(10));
                
            case 8:
                derivs[8]  =  -5040/(pow(x0, 8)*log(10));
                
            case 9:
                derivs[9]  =  40320/(pow(x0, 9)*log(10));
                
            case 10:
                derivs[10] =  -362880/(pow(x0, 10)*log(10));
                
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_atanh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Hyperbolic tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  atanh(x0);

            case 1:
                derivs[1]  =  1.0/(-pow(x0, 2) + 1);

            case 2:
                derivs[2]  =  2*x0/pow(pow(x0, 2) - 1, 2);
                
            case 3:
                derivs[3]  =  2*(-4*pow(x0, 2)/(pow(x0, 2) - 1) + 1)/pow(pow(x0, 2) - 1, 2);
                
            case 4:
                derivs[4]  =  24*x0*(2*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 3);
                
            case 5:
                derivs[5]  =  24*(-16*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) + 12*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 3);
                
            case 6:
                derivs[6]  =  240*x0*(16*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) - 16*pow(x0, 2)/(pow(x0, 2) - 1) + 3)/pow(pow(x0, 2) - 1, 4);
                            
            case 7:
                derivs[7]  =  720*(-64*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) + 80*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) - 24*pow(x0, 2)/(pow(x0, 2) - 1) + 1)/pow(pow(x0, 2) - 1, 4);
                
            case 8:
                derivs[8]  =  40320*x0*(16*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) - 24*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) + 10*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 5);
                
            case 9:
                derivs[9]  =  40320*(-256*pow(x0, 8)/pow(pow(x0, 2) - 1, 4) + 448*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) - 240*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) + 40*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 5);
                
            case 10:
                derivs[10] =  725760*x0*(256*pow(x0, 8)/pow(pow(x0, 2) - 1, 4) - 512*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) + 336*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) - 80*pow(x0, 2)/(pow(x0, 2) - 1) + 5)/pow(pow(x0, 2) - 1, 6);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_asinh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Hyperbolic sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  acosh(x0);

            case 1:
                derivs[1]  =  pow(pow(x0, 2) + 1, -1.0L/2.0L);

            case 2:
                derivs[2]  =  -x0/pow(pow(x0, 2) + 1, 3.0L/2.0L);
                
            case 3:
                derivs[3]  =  (3*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 3.0L/2.0L);
                //            (3*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 3.0L/2.0L)
                
            case 4:
                derivs[4]  =  3*x0*(-5*pow(x0, 2)/(pow(x0, 2) + 1) + 3)/pow(pow(x0, 2) + 1, 5.0L/2.0L);
                //             3*x0*(-5*pow(x0, 2)/(pow(x0, 2) + 1) + 3)/pow(pow(x0, 2) + 1, 5.0L/2.0L)
                
            case 5:
                derivs[5]  =  3*(35*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 30*pow(x0, 2)/(pow(x0, 2) + 1) + 3)/pow(pow(x0, 2) + 1, 5.0L/2.0L);
                
            case 6:
                derivs[6]  =  15*x0*(-63*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 70*pow(x0, 2)/(pow(x0, 2) + 1) - 15)/pow(pow(x0, 2) + 1, 7.0L/2.0L);
                            
            case 7:
                derivs[7]  =  45*(231*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 315*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 105*pow(x0, 2)/(pow(x0, 2) + 1) - 5)/pow(pow(x0, 2) + 1, 7.0L/2.0L);
                
            case 8:
                derivs[8]  =  315*x0*(-429*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 693*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 315*pow(x0, 2)/(pow(x0, 2) + 1) + 35)/pow(pow(x0, 2) + 1, 9.0L/2.0L);
                
            case 9:
                derivs[9]  =  315*(6435*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) - 12012*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 6930*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 1260*pow(x0, 2)/(pow(x0, 2) + 1) + 35)/pow(pow(x0, 2) + 1, 9.0L/2.0L);
                
            case 10:
                derivs[10] =  2835*x0*(-12155*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) + 25740*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 18018*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 4620*pow(x0, 2)/(pow(x0, 2) + 1) - 315)/pow(pow(x0, 2) + 1, 11.0L/2.0L);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_acosh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Hyperbolic inverse cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    double x2m1 = pow(x0, 2.) - 1.;
    double sqx2m1 = pow(x2m1, 0.5);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  acosh(x0);

            case 1:
                derivs[1]  =  pow(sqx2m1, -1.0);

            case 2:
                derivs[2]  =  -x0/pow(sqx2m1, 3.0);
                
            case 3:
                derivs[3]  =  (3.*pow(x0, 2.)/(x2m1) - 1.)/pow(sqx2m1, 3.0);
                
            case 4:
                derivs[4]  =  3.*x0*(-5.*pow(x0, .2)/(x2m1) + 3.)/pow(sqx2m1, 5.0);
                
            case 5:
                derivs[5]  =  3.*(35.*pow(x0, 4.)/pow(x2m1, 2.) - 30*pow(x0, 2.)/(x2m1) + 3.)/pow(sqx2m1, 5.0);
                
            case 6:
                derivs[6]  =  15.*x0*(-63.*pow(x0, 4.)/pow(x2m1, 2.) + 70.*pow(x0, 2.)/(x2m1) - 15.)/pow(sqx2m1, 7.0);
                            
            case 7:
                derivs[7]  =  45.*(231.*pow(x0, 6.)/pow(x2m1, 3.) - 315.*pow(x0, 4.)/pow(x2m1, 2.) + 105.*pow(x0, 2.)/(x2m1) - 5.)/pow(sqx2m1, 7.0);
                
            case 8:
                derivs[8]  =  315.*x0*(-429.*pow(x0, 6.)/pow(x2m1, 3.) + 693.*pow(x0, 4.)/pow(x2m1, 2.) - 315.*pow(x0, 2.)/(x2m1) + 35.)/pow(sqx2m1, 9.0);
                
            case 9:
                derivs[9]  =  315.*(6435.*pow(x0, 8.)/pow(x2m1, 4.) - 12012.*pow(x0, 6.)/pow(x2m1, 3.) + 6930.*pow(x0, 4.)/pow(x2m1, 2.) - 1260.*pow(x0, 2.)/(x2m1) + 35.)/pow(sqx2m1, 9.0);
                
            case 10:
                derivs[10] =  2835.*x0*(-12155.*pow(x0, 8.)/pow(x2m1, 4.) + 25740.*pow(x0, 6.)/pow(x2m1, 3.) - 18018.*pow(x0, 4.)/pow(x2m1, 2.) + 4620.*pow(x0, 2.)/(x2m1) - 315.)/pow(sqx2m1, 11.0);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_tanh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Hyperbolic tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    double tanhx0 = tanh(x0);
    double tanh2  = pow(tanhx0, 2); 
    double tanh2m1 = tanh2 - 1;
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  tanhx0;

            case 1:
                derivs[1]  =  -tanh2m1;

            case 2:
                derivs[2]  =  2.*(tanh2m1)*tanhx0;
                
            case 3:
                derivs[3]  =  -2.*(tanh2m1)*(3.*tanh2 - 1.);
                
            case 4:
                derivs[4]  =  8.*(tanh2m1)*(3.*tanh2 - 2.)*tanhx0;
                
            case 5:
                derivs[5]  =  -8.*(tanh2m1)*(2.*pow(tanh2m1, 2.) + 11.*(tanh2m1)*tanh2 + 2.*pow(tanhx0, 4.));
                
            case 6:
                derivs[6]  =  16.*(tanh2m1)*(17.*pow(tanh2m1, 2.) + 26.*(tanh2m1)*tanh2 + 2.*pow(tanhx0, 4.))*tanhx0;
                            
            case 7:
                derivs[7]  =  -16.*(tanh2m1)*(17.*pow(tanh2m1, 3.) + 180.*pow(tanh2m1, 2.)*tanh2 + 114.*(tanh2m1)*pow(tanh(x0), 4.) + 4*pow(tanhx0, 6.));
                
            case 8:
                derivs[8]  =  128.*(tanh2m1)*(62.*pow(tanh2m1, 3.) + 192.*pow(tanh2m1, 2.)*tanh2 + 60.*(tanh2m1)*pow(tanh(x0), 4.) + pow(tanhx0, 6.))*tanhx0;
                
            case 9:
                derivs[9]  =  -128.*(tanh2m1)*(62.*pow(tanh2m1, 4.) + 1072.*pow(tanh2m1, 3.)*tanh2 + 1452.*pow(tanh2m1, 2.)*pow(tanhx0, 4.) + 247.*(tanh2m1)*pow(tanhx0, 6.) + 2.*pow(tanhx0, 8.));
                
            case 10:
                derivs[10] =  256.*(tanh2m1)*(1382.*pow(tanh2m1, 4.) + 7192.*pow(tanh2m1, 3.)*tanh2 + 5097.*pow(tanh2m1, 2.)*pow(tanhx0, 4.) + 502.*(tanh2m1)*pow(tanhx0, 6.) + 2.*pow(tanhx0, 8.))*tanhx0;
                
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_sqrt(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Square root function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    // double x0 = num->p_coefs[0];
    double sqx = sqrt(num->p_coefs[0]);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  sqx;

            case 1:
                derivs[1]  =  (0.5)/sqx;

            case 2:
                derivs[2]  =  -0.25/pow(sqx, 3.0);
                
            case 3:
                derivs[3]  =  (0.375)/pow(sqx, 5.0);
                
            case 4:
                derivs[4]  =  -0.9375/pow(sqx, 7.0);
                
            case 5:
                derivs[5]  =  (3.28125)/pow(sqx, 9.0);
                
            case 6:
                derivs[6]  =  -14.765625/pow(sqx, 11.0);
                            
            case 7:
                derivs[7]  =  (81.2109375)/pow(sqx, 13.0);
                
            case 8:
                derivs[8]  =  -527.87109375/pow(sqx, 15.0);
                
            case 9:
                derivs[9]  =  (3959.033203125)/pow(sqx, 17.0);
                
            case 10:
                derivs[10] =  (-33651.7822265625)/pow(sqx, 19.0);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_cosh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Hyperbolic Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    double ch = cosh(x0);
    double sh = sinh(x0);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  ch;

            case 1:
                derivs[1]  =  sh;

            case 2:
                derivs[2]  =  ch;
                
            case 3:
                derivs[3]  =  sh;
                
            case 4:
                derivs[4]  =  ch;
                
            case 5:
                derivs[5]  =  sh;
                
            case 6:
                derivs[6]  =  ch;
                            
            case 7:
                derivs[7]  =  sh;
                
            case 8:
                derivs[8]  =  ch;
                
            case 9:
                derivs[9]  =  sh;
                
            case 10:
                derivs[10] =  ch;
                
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_sinh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Hyperbolic Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    double ch = cosh(x0);
    double sh = sinh(x0);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  sh;

            case 1:
                derivs[1]  =  ch;

            case 2:
                derivs[2]  =  sh;
                
            case 3:
                derivs[3]  =  ch;
                
            case 4:
                derivs[4]  =  sh;
                
            case 5:
                derivs[5]  =  ch;
                
            case 6:
                derivs[6]  =  sh;
                            
            case 7:
                derivs[7]  =  ch;
                
            case 8:
                derivs[8]  =  sh;
                
            case 9:
                derivs[9]  =  ch;
                
            case 10:
                derivs[10] =  sh;
                
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_oti_asin(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  asin(x0);

            case 1:
                derivs[1]  =  pow(-pow(x0, 2.) + 1., -1.0/2.0);

            case 2:
                derivs[2]  =  x0/pow(-pow(x0, 2.0) + 1., 3.0/2.0);
                
            case 3:
                derivs[3]  =  (3.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 1.)/pow(-pow(x0, 2.) + 1., 3.0/2.0);
                
            case 4:
                derivs[4]  =  3.*x0*(5.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 3.)/pow(-pow(x0, 2.) + 1., 5.0/2.0);
                
            case 5:
                derivs[5]  =  3.*(35.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 30.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 3.)/pow(-pow(x0, 2.) + 1., 5.0/2.0);
                
            case 6:
                derivs[6]  = 15.*x0*(63.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 70.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 15.)/pow(-pow(x0, 2.) + 1., 7.0/2.0);
                            
            case 7:
                derivs[7]  = 45.*(231.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 315.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 105.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 5.)/pow(-pow(x0, 2.) + 1., 7.0/2.0);
                
            case 8:
                derivs[8]  = 315.*x0*(429.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 693.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 315.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 35.)/pow(-pow(x0, 2.) + 1., 9.0/2.0);
                
            case 9:
                derivs[9]  = 315.*(6435.*pow(x0, 8.)/pow(-pow(x0, 2.) + 1., 4.) + 12012.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 6930.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 1260.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 35.)/pow(-pow(x0, 2.) + 1., 9.0/2.0);
                
            case 10:
                derivs[10] =2835.*x0*(12155.*pow(x0, 8.)/pow(-pow(x0, 2.) + 1., 4.) + 25740.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 18018.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 4620.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 315.)/pow(-pow(x0, 2.) + 1., 11.0/2.0);
                

        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_oti_acos(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  acos(x0);

            case 1:
                derivs[1]  =  -1.0/sqrt(-pow(x0, 2.0) + 1.0);

            case 2:
                derivs[2]  =  -x0/pow(-pow(x0, 2.0) + 1.0, 3.0/2.0);
                
            case 3:
                derivs[3]  =  -(3.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 1.0)/pow(-pow(x0, 2.0) + 1.0, 3.0/2.0);
                
            case 4:
                derivs[4]  =  -3.0*x0*(5.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 3.0)/pow(-pow(x0, 2.0) + 1.0, 5.0/2.0);
                
            case 5:
                derivs[5]  =  -3.0*(35.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 30.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 3.0)/pow(-pow(x0, 2.0) + 1.0, 5.0/2.0);
                
            case 6:
                derivs[6]  = -15.0*x0*(63.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 70.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 15.0)/pow(-pow(x0, 2.0) + 1.0, 7.0/2.0);
                            
            case 7:
                derivs[7]  = -45.0*(231.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 315.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 105.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 5.0)/pow(-pow(x0, 2.0) + 1.0, 7.0/2.0);
                
            case 8:
                derivs[8]  = -315.0*x0*(429.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 693.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 315.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 35.0)/pow(-pow(x0, 2.0) + 1.0, 9.0/2.0);
                
            case 9:
                derivs[9]  = -315.0*(6435.0*pow(x0, 8.0)/pow(-pow(x0, 2.0) + 1.0, 4.0) + 12012.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 6930.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 1260.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 35.0)/pow(-pow(x0, 2.0) + 1.0, 9.0/2.0);
                
            case 10:
                derivs[10] =-2835.0*x0*(12155.0*pow(x0, 8.0)/pow(-pow(x0, 2.0) + 1.0, 4.0) + 25740.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 18018.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 4620.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 315)/pow(-pow(x0, 2.0) + 1.0, 11.0/2.0);
                

        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_oti_atan(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    double x02   = pow(x0,2.0);
    double x02p1 = x02+1.0;
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0] =  atan(x0);

            case 1:
                derivs[1] =  1.0/(x02p1);

            case 2:
                derivs[2] =  -2.0 * x0 / ( pow( x02p1 , 2.0 ) );
                // -2*x1/(x1**2 + 1)**2
            case 3:
                derivs[3] =  2.0*(4.0*x02/(x02p1) - 1.0)/(pow(x02p1,2.0));
                // 2*(4*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**2
            case 4:
                derivs[4] =  24.0*x0*(-2.0*x02/(x02p1) + 1.0)/( pow( x02p1, 3) );
                // 24*x1*(-2*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3
            case 5:
                derivs[5] =  24.0*(16.0*pow( x0 ,4.0 )/( pow( x02p1, 2.0 ) ) - 12.0 * x02/(x02p1) + 1.0)/( pow( x02p1, 3.0) );
                // 24*(16*x1**4/(x1**2 + 1)**2 - 12*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3 
            case 6:
                derivs[6] = 240.0*x0*(-16.0*pow(x0,4.0)/pow(x02p1,2.0) + 16.0*x02/(x02p1) - 3.0 )/( pow(x02p1,4.0) );
                // 240*x1*(-16*x1**4/(x1**2 + 1)**2 + 16*x1**2/(x1**2 + 1) - 3)/(x1**2 + 1)**4
            case 7:
                derivs[7] = 720.0*(64.0*pow(x0,6.0)/pow(x02p1,3.0) - 80.0*pow(x0,4.0)/pow(x02p1,2.0) + 24.0*x02/(x02p1) - 1.0)/(pow(x02p1,4.0));
                // 720*(64*x1**6/(x1**2 + 1)**3 - 80*x1**4/(x1**2 + 1)**2 + 24*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**4
            case 8:
                derivs[8] = 40320.0*x0*(-16*pow(x0,6.0)/pow(x02p1,3.0) + 24.0*pow(x0,4.0)/pow(x02p1,2.0) - 10.0*x02/(x02p1) + 1.0)/(pow(x02p1,5.0));
                // 40320*x1*(-16*x1**6/(x1**2 + 1)**3 + 24*x1**4/(x1**2 + 1)**2 - 10*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 9:
                derivs[9] = 40320.0*(256.0*pow(x0,8.0)/(pow(x02p1,4.0)) - 448.0*pow(x0,6.0)/(pow(x02p1,3.0)) + 240.0*pow(x0,4.0)/(pow(x02p1,2.0)) - 40.0*x02/x02p1 + 1.0)/(pow(x02p1,5.0));
                // 40320*(256*x1**8/(x1**2 + 1)**4 - 448*x1**6/(x1**2 + 1)**3 + 240*x1**4/(x1**2 + 1)**2 - 40*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 10:
                derivs[10] =725760.0*x0*(-256*pow(x0,8.0)/(pow(x02p1,4.0)) + 512*pow(x0,6.0)/(pow(x02p1,3.0)) - 336*pow(x0,4.0)/(pow(x02p1,2.0)) + 80*x02/x02p1 - 5.0)/(pow(x02p1,6.0));
                // 725760*x1*(-256*x1**8/(x1**2 + 1)**4 + 512*x1**6/(x1**2 + 1)**3 - 336*x1**4/(x1**2 + 1)**2 + 80*x1**2/(x1**2 + 1) - 5)/(x1**2 + 1)**6
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_tan(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
    double tanx0 = tan(x0);
    double tanx02p1 = pow(tanx0,2.0) + 1.0 ;
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0] =  tan(x0);
            case 1:
                derivs[1] =  tanx02p1; 
                // tan(g)**2 + 1
            case 2:
                derivs[2] =  2.*(tanx02p1)*tanx0 ; 
                // 2*(tan(g)**2 + 1)*tan(g)
            case 3:
                derivs[3] =  2.*(tanx02p1)*(3.*pow(tanx0,2.0) + 1.);
                // 2*(tan(g)**2 + 1)*(3*tan(g)**2 + 1)
            case 4:
                derivs[4] =  8.*(tanx02p1)*(3.*pow(tanx0,2.0) + 2.)*tanx0;
                // 8*(tan(g)**2 + 1)*(3*tan(g)**2 + 2)*tan(g)
            case 5:
                derivs[5] =  8.*(tanx02p1)*(2.*pow((tanx02p1),2.0) + 
                    11.*(tanx02p1)*pow(tanx0,2.0) + 2.*pow(tanx0,4.0));
                //8*(tan(g)**2 + 1)*(2*(tan(g)**2 + 1)**2 + 11*(tan(g)**2 + 1)*tan(g)**2 + 2*tan(g)**4)
            case 6:
                derivs[6] = 16.*(tanx02p1)*(17*pow((tanx02p1),2.) + 
                    26.*(tanx02p1)*pow(tanx0,2.0) + 
                    2.*pow(tanx0,4.0))*tanx0;
                // 16*(tan(g)**2 + 1)*(17*(tan(g)**2 + 1)**2 + 26*(tan(g)**2 + 1)*tan(g)**2 + 2*tan(g)**4)*tan(g)
            case 7:
                derivs[7] = 16.*(tanx02p1)*(17.*pow((tanx02p1),3.) 
                    + 180.*pow((tanx02p1),2.)*pow(tanx0,2.0)
                    + 114.*(tanx02p1)*pow(tanx0,4.0) + 4.*pow(tanx0,6.0));
                //  16*(tan(g)**2 + 1)*(17*(tan(g)**2 + 1)**3 + 180*(tan(g)**2 + 1)**2*tan(g)**2 +
                // 114*(tan(g)**2 + 1)*tan(g)**4 + 4*tan(g)**6)
            case 8:
                derivs[8] = 128.*(tanx02p1)*(62.*pow((tanx02p1),3.) +
                    192.*pow((tanx02p1),2.0)*pow(tanx0,2.0) +
                     60.*(tanx02p1)*pow(tanx0,4.0)+ pow(tanx0,6.0))*tanx0;
                // 128*(tan(g)**2 + 1)*(62*(tan(g)**2 + 1)**3 + 192*(tan(g)**2 + 1)**2*tan(g)**2 +
                //  60*(tan(g)**2 + 1)*tan(g)**4 + tan(g)**6)*tan(g)
            case 9:
                derivs[9] = 128.*(pow(tanx0,2.0) + 1.)*(
                    62*pow((tanx02p1),4) + 
                    1072.*pow((tanx02p1),3.)*pow(tanx0,2.0) + 
                    1452.*pow((tanx02p1),2.)*pow(tanx0,4.0) + 
                    247. *    (tanx02p1)    *pow(tanx0,6.0) +
                    2.*(pow(tanx0,8.0))
                    );
                // Too many calls to pow(tanx0,2.0) +1.
                // 128*
                // (tan(x1)**2 + 1)*
                // (
                //     62*(tan(x1)**2 + 1)**4 + 
                //     1072*(tan(x1)**2 + 1)**3*tan(x1)**2 + 
                //     1452*(tan(x1)**2 + 1)**2*tan(x1)**4 + 
                //     247 *(tan(x1)**2 + 1)   *tan(x1)**6 + 
                //     2*tan(x1)**8
                // )
            case 10:

                derivs[10] =256.*(tanx02p1)*(
                    1382.*pow((tanx02p1),4.) + 
                    7192.*pow((tanx02p1),3.)*pow(tanx0,2.0) + 
                    5097.*pow((tanx02p1),2.)*pow(tanx0,4.0) + 
                    502. *(tanx02p1)*pow(tanx0,6.0) + 
                    2.*pow(tanx0,8.0)
                    )*tanx0;
                // 256*
                // (tan(x1)**2 + 1)*
                // (
                //     1382*(tan(x1)**2 + 1)**4 + 
                //     7192*(tan(x1)**2 + 1)**3*tan(x1)**2 + 
                //     5097*(tan(x1)**2 + 1)**2*tan(x1)**4 + 
                //     502 *(tan(x1)**2 + 1)   *tan(x1)**6 + 
                //     2*tan(x1)**8
                // ) * tan(x1)
        }
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_oti_cos(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = num->p_coefs[0];
    uint8_t i;
    uint8_t s = 0;
    double sign = 1.;
    
    for( i=0; i<(num->order+1); i++){
    
        if (s == 0){
        
            derivs[i]=sign*cos(x0);
        
        }else{
        
            sign = sign * (-1.0);
            derivs[i]=sign*sin(x0);
    
        }
    
        s = (s+1)%2;
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_sin(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = num->p_coefs[0];
    uint8_t i;
    uint8_t s = 1;
    double sign = -1.;
    
    for( i=0; i<(num->order+1); i++){
    
        if (s == 0){
        
            derivs[i]=sign*cos(x0);
        
        }else{
        
            sign = sign * (-1.0);
            derivs[i]=sign*sin(x0);
    
        }
    
        s = (s+1)%2;
     
    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_oti_log(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Natural logarithm function for OTI numbers. 

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = num->p_coefs[0];
    double sign = -1.;
    double factor = 1.;
    uint8_t i;    

    for (i=0; i<(num->order+1); i++){

        
        if (i == 0){
        
            derivs[i]=log(x0);
        
        }else{
         
            derivs[i] = factor * pow(sign,(i+1)) * (1.0/pow(x0,i) );
            factor    = factor * i;
    
        }

    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_oti_exp(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Exponential function for OTI numbers. -> e**x, x is otinum

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double value = exp(num->p_coefs[0]);
    uint8_t i;    

    for (i=0; i<(num->order+1); i++){

        derivs[i]=value;

    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void c_oti_pow(otinum_t* num, double exponent, directionHelper* p_dH,otinum_t* res){
    /*
    PURPOSE:  Power function for OTI numbers, for non integer exponents.

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double power_i = exponent;
    double x0 = num->p_coefs[0];
    uint8_t flag = 0;
    double factor = 1.;
    uint8_t i;
    

    for (i=0; i<(num->order+1); i++){

        if( power_i != 0.0){
            
            derivs[i]=factor*pow(x0,power_i);
            factor = factor*power_i;
            power_i -= 1.;

        }else{

            if (i==0){

                derivs[i] = x0; // not sure if 1.0 or if coefs[0]
                flag = 1;

            } else if (flag == 0 ){

                derivs[i]=factor;
                flag = 1;

            }else{ 

                derivs[i] = 0.;

            }            

        }

    }
  
  // Compute all the derivatives 
  c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_oti_collapseDirA(uint16_t* array, uint8_t order, uint16_t* dirA, uint8_t* expA){



    uint16_t oldValue = array[0];
    uint8_t  count = 0;
    uint8_t  iDir  = 0;
    uint8_t  i;

    for (i=0; i<order; i++ ){   // TODO: Check when it is in collapse if
                                // if array.size is order.

        if( array[i] == 0){

            continue;

        }else if (array[i] == oldValue){
          
            count++;

        }else{
          
            expA[iDir] = count;
            dirA[iDir] = oldValue;
            iDir += 1;
            oldValue = array[i];
            count = 1;

        }

    }

    expA[iDir] = count;
    dirA[iDir] = oldValue;
    iDir++;

    // Put zeros in all other values of the array, if it is the case:

    if (iDir != order){// Check size of dirA
        
        for(i=iDir; i<order; i++){

          expA[i] = 0;
          dirA[i] = 0;

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_oti_expandDirA(uint16_t* p_dirA,uint8_t* p_expA, uint8_t order, uint16_t* p_expandArr){


    
    uint8_t i=0, count = 0, idir = 0;

    for (;i<order;i++){
        
        p_expandArr[i] = p_dirA[idir];
        count++;

        if (count == p_expA[idir]){

            count = 0;
            idir++;

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
double c_oti_FaaDiBruno(uint64_t indx, double* fder, otinum_t* g, directionHelper* p_dH){
    /*
    double c_oti_FaaDiBruno(uint64_t indx, double* fder, otinum_t* g, directionHelper* p_dH)
    
    Apply the Faa di Bruno formula to find the coefficient that corresponds to a specific partial
    derivative of f.

    To differentiate a function f that depends on another function
    g which depends on several variables. 

    i.e. f( g(x1,...,xn) )

    g comes evaluated and it is represented by an OTI number.

    INPUTS:

        -> indx:    Direction to compute Faa di Bruno formula
        
        ->  fder:   Array of values holding all the derivatives of f with respect to g up to 
                    g.order. 
        
        ->  g:      oti number that represents g(x1,...,xn).

        ->  p_dH:  list of helpers.

  
    WARNING:    This is a very rudimentary implementation. If you have time to
                contribute, this is a function that might be very crucial to 
                optimize.

    */

    double sum_ = 0.;
    double mult ;
    uint8_t orderg = g->order;
    uint16_t* dirA  = c_helper_getDirA(indx,orderg,p_dH);  // 
    uint8_t* expA   = c_helper_getExpA(indx,orderg,p_dH);  // 
    uint16_t* dirA_ = c_helper_getUDirA(orderg,0,p_dH);    // It is expensive to create arrays
    uint8_t* expA_  = c_helper_getUExpA(orderg,0,p_dH);    // at each iteration. Consider 
    uint64_t i, j, k, el, count, nsets;                    // inputing the allocated arrays  
    uint16_t seti;
    uint8_t order = c_sumUI8(expA,orderg);
    uint16_t* expandedArray = c_helper_getUDirA(orderg,1,p_dH);
    uint16_t* mdir          = c_helper_getUDirA(orderg,2,p_dH);  
    double factor = 1.0;
    uint64_t index;
    uint64_t nevals = c_helper_getNParts(order,p_dH);



    // printf("IN FAADIBRUNO\n");
    // Expand the directions according to the exponents
    c_oti_expandDirA(dirA, expA, order, expandedArray);

    // for part in partition.Partition( expandArray(dirA,expA) )
    for(i=0;i<nevals; i++ ){ 

        mult = 1.0;
        nsets = 0;

        for (j=0;j<order;j++){ // Subpart j


            seti = c_helper_getSet(order,i,j,p_dH); // get the j'th set of the partition i.

            if (seti == 0){ //if partition is == 0 set is full of zeros, therefore avoid computation.
                continue;
            }

            nsets++; //counts the number of sets in the partition.

            el = 0;      // gets the element  at which 
            count = 0;

            while (seti != 0){    // values of the sets are stored in the bits of seti

                if( seti & 1){

                    mdir[count] = expandedArray[el];
                    count+=1;

                }
                

                seti = (seti>>1);
                el++;

            }

            // fill up the other values as zeros:

            for (k=count;k<orderg;k++){

                mdir[k] = 0;

            }

            c_oti_collapseDirA(mdir, orderg, dirA_, expA_);

            index = c_helper_findIndex(dirA_,expA_,orderg,p_dH);
            factor = 1.;

            for( k =0; k<orderg; k++){
          
                if( expA_[k] != 0){ // Not a necessary check
                
                    factor *= c_fastfact(expA_[k]);

                }

            }

            mult *= g->p_coefs[index]*factor;

        }

        sum_ +=  fder[nsets]  *  mult;

    }
    
    factor = 1.0;

    for( k =0; k<orderg; k++){
          
        if( expA[k] != 0){ // not a necessary check
        
            factor *= c_fastfact(expA[k]);

        }

    }

    // printf("sum -> %g\n",sum_);
    // printf("factor -> %g\n",factor);

    return sum_/factor;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_derivFunc(double* fder, otinum_t* g, directionHelper* p_dH, otinum_t* feval){
    /*
    void c_oti_derivFunc(double* fder, otinum_t* g, otinum_t* feval)
    
    Given the derivatives of a function f(g) with respect to g, finds the evaluation of the function 
    when g is an oti number.

    To differentiate a function f that depends on another function
    g which depends on several variables. 

    i.e. f( g(x1,...,xn) )

    g comes evaluated and it is represented by an OTI number.

    INPUTS:
        
        ->  fder:   Array of values holding all the derivatives of f with respect to g up to 
                    g.order. 
        
        ->  g:      oti number that represents g(x1,...,xn).

        ->  feval:  Evaluated function f(g) where g is an oti number.

  
    WARNING:    This is a very rudimentary implementation. If you have time to
                contribute, this is a function that might be very crucial to 
                optimize.

    */
    uint8_t order = g->order;
    uint64_t Ndir = g->Ndir;
    uint8_t i = 0;
    // uint16_t nval = c_helper_findMaxDir(Ndir-1,order,p_dH);
    // uint64_t max_i = c_helper_getNels(nval, order, p_dH); 

    // Allocate memory for the result:
    feval->p_coefs = (double* )malloc(Ndir*sizeof(double)) ;
    if( feval->p_coefs == NULL ){
        printf("---- MemoryError ----\n");
        exit(-1);
    }
    feval->order = order;
    feval->Ndir = Ndir;

    // Assign real component:
    feval->p_coefs[0] = fder[0];

    for (i=1; i<Ndir; i++){
        if (order == 1){
            feval->p_coefs[i] = fder[1]*g->p_coefs[i];
        } else {
            feval->p_coefs[i] = c_oti_FaaDiBruno(i,fder,g,p_dH);
        }
    }




}
// ----------------------------------------------------------------------------------------------------

// typedef struct{
//     uint64_t*     p_data;
//     uint64_t*     p_cols;
//     uint64_t*     p_rows;
//     uint64_t       sizex;
//     uint64_t       nrows;
//     uint64_t     nonzero;
// } coomat_ui64_t;


// ****************************************************************************************************
coomat_ui64_t c_oti_matform( uint64_t nvar, uint8_t order, directionHelper* p_dH){
    /*
    uint64_t* c_oti_matform(otinum_t* num, uint64_t size, directionHelper* p_dH)

    Obtain the dense matrix representation of the oti number num.

    INPUTS:

        -> nvar:   Number of independent variables.

        -> order:  Order of derivatives.

        -> p_dH:   List of helpers.

    OUTPUTS:

        The operation gives a uint64_t* such that it contains the matrix form of the oti number.

        Each non zero element in the matrix is the index of the OTI number coefficient that should
        be placed in that position.

        The shape of the matrix is (size x size)

    */ 
    // ************************************************************************************************
    uint64_t i,j,k,ii,Ndir;
    coomat_ui64_t mat;     // matrix pointer, Coo format
    uint8_t error;
    uint64_t nnonzero = c_ndir(2*nvar, order);

    
    // Allocate memory to hold the results:
    mat.p_data = (uint64_t*)malloc(nnonzero*sizeof(uint64_t));
    if (mat.p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    mat.p_cols = (uint64_t*)malloc(nnonzero*sizeof(uint64_t));
    if (mat.p_cols == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    mat.p_rows = (uint64_t*)malloc(nnonzero*sizeof(uint64_t));
    if (mat.p_rows == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    
    // Initialize in zero.
    memset(mat.p_data, 0, nnonzero*sizeof(uint64_t));

    Ndir = c_ndir(nvar, order);
        
    mat.sizex   = Ndir;
    mat.sizey   = Ndir;
    mat.nonzero = nnonzero;


    // Holder of the position of the coefficient vectors
    ii=0;
    for( i = 0; i < Ndir; i++){

        for( j = 0; j < Ndir; j++){
            
            k = c_helper_multIndxFast( i, j, order, p_dH, &error);
            
            if (k>Ndir){

                break;

            }

            if (error == 0){
                // k*size+j
                mat.p_data[ii] = i+1;  // +1 because a 0 can be accounted for errors in sparse matrix
                mat.p_rows[ii] = k;
                mat.p_cols[ii] = j;
                ii++;
                
            }

        }

    }
    
    return mat;

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
double* c_oti_num2mat(otinum_t* num, uint64_t size, directionHelper* p_dH){
    /*
    void c_oti_num2mat(otinum_t* num, uint64_t size, directionHelper* p_dH)

    Obtain the dense matrix representation of the oti number num.

    INPUTS:

        ->num:    Address of the number to be created. 

        ->size:    Size of the matrix (can be different to the num.Ndir).

        -> p_dH:   List of helpers

    OUTPUTS:

        The operation gives a double* such that it contains the matrix form of the oti number.

        The shape of the matrix is (size x size)

    */ 
    // ************************************************************************************************
    uint64_t i,j,k,Ndir = num->Ndir;
    double * mat;   // matrix pointer
    uint8_t error,order = num->order;

    
    // Allocate memory to hold the results:
    mat = (double*)malloc(size*size*sizeof(double));
    if (mat == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }
    
    // Initialize in zero.
    memset(mat, 0, size*size*sizeof(double));
    

    for( i = 0; i < Ndir; i++){

        for( j = 0; j < size; j++){
            
            k = c_helper_multIndxFast( i, j, order, p_dH, &error);

            
            if (k>size){
                
                break;

            }

            if (error == 0){

                mat[k*size+j] = num->p_coefs[i];
                
            }

        }

    }
    
    return mat;

}    
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_oti_mulf(otinum_t* num1, double num2, otinum_t* res){
    /*
    void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    multiply an oti number times a real coefficient.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    Address of the other operand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions. Cannot be the same address as num1.

        -> p_dH:   List of helpers

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 * num2

    */ 
    // ************************************************************************************************
    uint64_t i;
    
    // Initialize the result holder.
    if (res->p_coefs!=num1->p_coefs){
        
        memcpy(res->p_coefs,num1->p_coefs,res->Ndir*sizeof(double));
            
    }
    

    for( i = 0; i < res->Ndir; i++){
        
        res->p_coefs[i]*=num2;
    }
    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH){
    /*
    void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    multiply two oti numbers

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    Address of the other operand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions. Cannot be the same address as num1 or num2

        -> p_dH:   List of helpers

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 * num2

    */ 
    // ************************************************************************************************
    uint64_t i, j, indx;
    uint8_t err=1, order = num1->order;
    
    // Initialize in zeros the result holder.
    for( i = 0; i < res->Ndir;  i++ ){

        res->p_coefs[i] = 0.0;

    }

    for( i = 0; i < num1->Ndir; i++){
        
        for( j = 0; j < num2->Ndir; j++){

            // Multiply directions.

            indx = c_helper_multIndxFast(i,j,order,p_dH,&err);

            if (err == 0){   // If error flag is off

                res->p_coefs[indx] += num1->p_coefs[i] * num2->p_coefs[j];
            }

        }
                 
    }
    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void c_oti_free(otinum_t* numHolder){
    /*
    c_freeOti(numHolder)

    Frees an allocated oti number

    INPUTS:

        ->numHolder:    Address of the number to be freed.
        

    */ 
    // ************************************************************************************************

    if (numHolder->p_coefs != NULL){

        free(numHolder->p_coefs); 

    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_createEmpty(otinum_t* numHolder,   uint64_t ndir, uint8_t order){
    /*
    c_oti_createEmpty(numHolder, ndir, order)

    C-level memory allocation of a dense oti number a direction array from a file

    INPUTS:

        ->numHolder:    Address of the number to be allocated.
        
        ->    order:    Order to be loaded in memory.
            Example: 3

        ->     ndir:    Number of directions of the number.
            Example: 100

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    numHolder->p_coefs = (double*)malloc(ndir*sizeof(double));
    if (numHolder->p_coefs == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }
    numHolder->Ndir  = ndir;
    numHolder->order = order;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_changeOrderToNew(otinum_t* num, uint8_t neword, directionHelper* p_dH , otinum_t* res){
    /*
    c_otiChangeOrder(num1, neword, p_dH)
    
    Change the order of num to neword without changing the original number.
    

    INPUTS:

        ->num:      Address of the number to be changedOrder. 
                                                
        ->neword:   New Order.

        ->p_dH:     Address of the helper stack. 
    
    OUTPUTS:

        The operation will replace the data in num.

    */ 
    // ************************************************************************************************

    uint16_t* oldDirA;
    uint16_t* newDirA;
    uint8_t*  oldExpA;
    uint8_t*  newExpA;
    uint64_t newIndx;
    uint64_t m_max, newSizeOfCoefs;
    uint64_t i,k, Ndir = num->Ndir;
    uint8_t j, order = num->order;
    double*  newCoefs;


    if (neword != order){

        m_max = c_helper_findMaxDir(Ndir-1,order,p_dH);
        newSizeOfCoefs = c_helper_getNels(m_max,neword,p_dH);
        newCoefs = (double*)malloc(newSizeOfCoefs*sizeof(double));

        if (neword>order){

            
            // WARNING: THE VALUES IN COEFS HAVE NOT BEEN INITIALIZED!!!
            k=0;


            newDirA = c_helper_getUDirA(neword,0,p_dH);
            newExpA = c_helper_getUExpA(neword,0,p_dH);

            for (i = 0; i < Ndir; i++ ){

                oldDirA = c_helper_getDirA(i,order,p_dH);
                oldExpA = c_helper_getExpA(i,order,p_dH);
                
                 

                // Fill the values of new DirA
                memcpy(newDirA,oldDirA,order*sizeof(double));            
                memcpy(newExpA,oldExpA,order*sizeof(double));

                // Fill the rest with zeros
                for (j=order; j<neword;j++){
                    
                    newDirA[j] = 0;
                    newExpA[j] = 0;

                }

                newIndx = c_helper_findIndex(newDirA,newExpA,neword,p_dH);
                newCoefs[newIndx] = num->p_coefs[i];

                
                if (k != newIndx){
                    // Set all the values between the last value placed and newIndx -> 0.0

                    for (;k<newIndx;k++){

                        newCoefs[k] = 0.0;

                    }

                    // k leaves this loop with the same value as newIndx.
                    

                }

                k++;


                
            }

            // Set all other numbers to zero.

            for (;k<newSizeOfCoefs;k++){
                newCoefs[k] = 0.0;
            }


            
            res->p_coefs = newCoefs;
            res->order = neword;
            res->Ndir = newSizeOfCoefs;

        } else {  // neworder<order

            oldDirA = c_helper_getUDirA( order, 0, p_dH);
            oldExpA = c_helper_getUExpA( order, 0, p_dH); 

            for (i = 0; i < newSizeOfCoefs; i++ ){

                newDirA = c_helper_getDirA(i, neword, p_dH);
                newExpA = c_helper_getExpA(i, neword, p_dH);

                memcpy( oldDirA, newDirA, neword*sizeof(double));            
                memcpy( oldExpA, newExpA, neword*sizeof(double));

                // Fill the rest with zeros
                for (j=neword; j<order;j++){
                    
                    oldDirA[j] = 0;
                    oldExpA[j] = 0;

                }

                newIndx = c_helper_findIndex(oldDirA,oldExpA,order,p_dH);
                newCoefs[i] = num->p_coefs[newIndx];
                
                
            }


            num->p_coefs = newCoefs;
            num->order = neword;
            num->Ndir = newSizeOfCoefs;

        }

    }


}


void c_oti_changeOrder(otinum_t* num, uint8_t neword, directionHelper* p_dH ){
    /*
    c_otiChangeOrder(num1, neword, p_dH)
    
    Change the order of num to neword.
    

    INPUTS:

        ->num:      Address of the number to be changedOrder. 
                                                
        ->neword:   New Order.

        ->p_dH:     Address of the helper stack. 
    
    OUTPUTS:

        The operation will replace the data in num.

    */ 
    // ************************************************************************************************

    uint16_t* oldDirA;
    uint16_t* newDirA;
    uint8_t*  oldExpA;
    uint8_t*  newExpA;
    uint64_t newIndx;
    uint64_t m_max, newSizeOfCoefs;
    uint64_t i,k, Ndir = num->Ndir;
    uint8_t j, order = num->order;
    double*  newCoefs;


    if (neword != order){

        m_max = c_helper_findMaxDir(Ndir-1,order,p_dH);
        newSizeOfCoefs = c_helper_getNels(m_max,neword,p_dH);


        if (neword>order){

            newCoefs = (double*)malloc(newSizeOfCoefs*sizeof(double));
            // WARNING: THE VALUES IN COEFS HAVE NOT BEEN INITIALIZED!!!
            k=0;


            newDirA = c_helper_getUDirA(neword,0,p_dH);
            newExpA = c_helper_getUExpA(neword,0,p_dH);

            for (i = 0; i < Ndir; i++ ){

                oldDirA = c_helper_getDirA(i,order,p_dH);
                oldExpA = c_helper_getExpA(i,order,p_dH);
                
                 

                // Fill the values of new DirA
                memcpy(newDirA,oldDirA,order*sizeof(double));            
                memcpy(newExpA,oldExpA,order*sizeof(double));

                // Fill the rest with zeros
                for (j=order; j<neword;j++){
                    
                    newDirA[j] = 0;
                    newExpA[j] = 0;

                }

                newIndx = c_helper_findIndex(newDirA,newExpA,neword,p_dH);
                newCoefs[newIndx] = num->p_coefs[i];

                
                if (k != newIndx){
                    // Set all the values between the last value placed and newIndx -> 0.0

                    for (;k<newIndx;k++){

                        newCoefs[k] = 0.0;

                    }

                    // k leaves this loop with the same value as newIndx.
                    

                }

                k++;


                
            }

            // Set all other numbers to zero.

            for (;k<newSizeOfCoefs;k++){
                newCoefs[k] = 0.0;
            }


            free(num->p_coefs);
            num->p_coefs = newCoefs;
            num->order = neword;
            num->Ndir = newSizeOfCoefs;

        } else {  // neworder<order

            oldDirA = c_helper_getUDirA( order, 0, p_dH);
            oldExpA = c_helper_getUExpA( order, 0, p_dH); 

            for (i = 0; i < newSizeOfCoefs; i++ ){

                newDirA = c_helper_getDirA(i, neword, p_dH);
                newExpA = c_helper_getExpA(i, neword, p_dH);

                memcpy( oldDirA, newDirA, neword*sizeof(double));            
                memcpy( oldExpA, newExpA, neword*sizeof(double));

                // Fill the rest with zeros
                for (j=neword; j<order;j++){
                    
                    oldDirA[j] = 0;
                    oldExpA[j] = 0;

                }

                newIndx = c_helper_findIndex(oldDirA,oldExpA,order,p_dH);
                num->p_coefs[i] = num->p_coefs[newIndx];
                
                
            }

            // Realloc to new size.
            num->p_coefs = (double* )realloc(num->p_coefs,newSizeOfCoefs*sizeof(double));
            num->order = neword;
            num->Ndir = newSizeOfCoefs;

        }

    }


}



// ****************************************************************************************************
void c_oti_e(double real,uint16_t basis, uint8_t order, uint16_t nbasis, 
            directionHelper* p_dH, otinum_t* res){
    /*
    void c_oti_e(double real,uint16_t basis, uint8_t order, otinum_t* res)

    Create an oti number with real coefficient "real" and with unitary perturbation in imaginary 
    direction "basis".

    INPUTS:

        -> double real:     Real coefficient.

        -> uint16_t basis:  Number that represents the imaginary direction to hold the perturbation.

        -> uint8_t order:   Order of the OTI number desired

        -> uint16_t nbasis: Number of basis(determines the size of the oti number).
        
        -> directionHelper* p_dH: 

        -> otinum_t* res:   Pointer to the oti number result. Must not come allocated!
    
    OUTPUTS:

        The operation allocates memory and sets the corresponding values of the oti number.

    */ 
    // ************************************************************************************************
    


    

}    
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline void c_oti_sumf(otinum_t* num1, double other){
    /*
    void c_oti_sumf(otinum_t* num1, otinum_t* num2, otinum_t* res)

    Sum an oti number with a float (double).

    INPUTS:

        ->num1:    Address of the summand. 
                                                Both must have the same order.
        ->num2:    Address of the summand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions.

    OUTPUTS:

        The operation is equivalent to:

        res = num1 + num2

    */ 
    // ************************************************************************************************
    

    num1->p_coefs[0] += other;

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res){
    /*
    void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res)

    Sum two oti numbers

    INPUTS:

        ->num1:    Address of the summand. 
                                                Both must have the same order.
        ->num2:    Address of the summand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions.

    OUTPUTS:

        The operation is equivalent to:

        res = num1 + num2

    */ 
    // ************************************************************************************************


    // c_minUI64(num1->Ndir, num2->Ndir, &minNdir,&maxNdir);


    for(uint64_t i = 0; i< res->Ndir; i++){
        
        if( i < num1->Ndir){
            
            res->p_coefs[i] = num1->p_coefs[i];

        }else{
            
            res->p_coefs[i] = 0.0;

        }

        if( i < num2->Ndir){
            
            res->p_coefs[i] += num2->p_coefs[i];

        }

    }
    

}    
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_sub(otinum_t* num1, otinum_t* num2, otinum_t* res){
    /*
    void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res)

    Subtract two oti numbers

    INPUTS:

        ->num1:    Address of the summand. 
                                                Both must have the same order.
        ->num2:    Address of the summand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions.

    OUTPUTS:

        The operation is equivalent to:

        res = num1 - num2

    */ 
    // ************************************************************************************************


    // c_minUI64(num1->Ndir, num2->Ndir, &minNdir,&maxNdir);


    for(uint64_t i = 0; i< res->Ndir; i++){
        
        if( i < num1->Ndir){
            
            res->p_coefs[i] = num1->p_coefs[i];

        }else{
            
            res->p_coefs[i] = 0.0;

        }

        if( i < num2->Ndir){
            
            res->p_coefs[i] -= num2->p_coefs[i];

        }

    }
    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_oti_neg(otinum_t* num1){
    /*
    void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res)

    Sum two oti numbers

    INPUTS:

        ->num1:    Address of the summand. 
                                                Both must have the same order.
        ->num2:    Address of the summand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions.

    OUTPUTS:

        The operation is equivalent to:

        - num1 

    */ 
    // ************************************************************************************************


    for(uint64_t i = 0; i< num1->Ndir; i++){
        
        num1->p_coefs[i] *= -1.0;
                 
    }
    

}    
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
inline void c_oti_copy(otinum_t* numDest, otinum_t* numSrc){
    /*
    void c_oti_copy(otinum_t* numDest, otinum_t* numSrc)

    Copies the information from numSrc to numDest

    INPUTS:

        ->numHolder:    Address of the number to be freed.

    */ 
    // ************************************************************************************************

    numDest->p_coefs = (double*)malloc(numSrc->Ndir*sizeof(double));
    
    if (numDest->p_coefs == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    memcpy(numDest->p_coefs ,numSrc->p_coefs ,numSrc->Ndir*sizeof(double));
    numDest->Ndir  = numSrc->Ndir;
    numDest->order = numSrc->order;
}    
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
// -------------------------------     END OTINUM FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------































// ----------------------------------------------------------------------------------------------------
// ---------------------------------     HELPER FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_helper_insertIndx(uint64_t* p_indxArray,uint64_t indx,uint64_t *size,
    double * p_coefArray, double coef){
    /*
    void c_helper_insertIndx(uint64_t* p_indxArray,uint64_t indx,uint64_t *size)

    Function to insert a direction index to a stack of directions.

    INPUTS:      
              - uint64_t* p_indxArray: Array of the directions.

              - uint64_t         indx: Index to be added. 

              - uint64_t*        size: Number of elements in p_indxArray

    EXAMPLE:

        >>> c_helper_insertIndx([], 5, 0);
           // Modifies the following.
        -> p_indxArray = [5]
        -> size        = 1


        >>> c_helper_insertIndx([1, 3, 17, 25], 17, 4);
        -> p_indxArray = [1, 3, 17, 25]
        -> size        = 4


        >>> c_helper_insertIndx([1, 3, 17, 25], 2, 4);
        -> p_indxArray = [1, 2, 3, 17, 25]
        -> size        = 5


    */   
    // ************************************************************************************************

    uint64_t pos;
    // printf("before: \n");
    // c_printArrayUI64(p_indxArray,size[0]);
    if (size[0] == 0){
        
        // No need to check what coefficients are
        
        p_indxArray[0] = indx;
        p_coefArray[0] = coef;
        size[0] = 1;

    } else {
    
        pos = c_binarySearchUI64( p_indxArray, indx, size[0]); //
        

        // printf("\nPosition found: %llu\n",pos);

        if (p_indxArray[pos] != indx){

            // printf("Array of %llu els. to be moved:\n");
            // c_printArrayUI64(&p_indxArray[pos],size[0]-pos);

            // move all items to make space for new index
            memmove(  &p_indxArray[pos+1],               // Destination
                      &p_indxArray[pos],                 // Source
                      (size[0]-pos)*sizeof(uint64_t));   // Number of bytes
            memmove(  &p_coefArray[pos+1],               // Destination
                      &p_coefArray[pos],                 // Source
                      (size[0]-pos)*sizeof(double)  );   // Number of bytes
            size[0] += 1 ;
            p_indxArray[pos] = indx;
            p_coefArray[pos] = coef;

        } else {

            p_coefArray[pos] += coef;

        }
        

    }
    // printf("after: \n");
    // c_printArrayUI64(p_indxArray,size[0]);
    // printf("\n\n");


}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_helper_ordDirExpA(uint16_t* p_dirA, uint8_t* multiple, uint8_t order, 
                        uint16_t* p_ndirA, uint8_t* p_nexpA){
    /*
    void c_helper_ordDirExpA(uint16_t* p_dirA, uint8_t* multiple, uint16_t* p_ndirA)

    Function to organize a direction array according to one obtained multiple.

    INPUTS:      
              - uint16_t* p_dirA:     Array of the directions.

              - uint8_t* multiple:    1D array with the multiple information of the exponents. 

              - uint8_t order:        Maximum order of the direction

              - uint16_t* p_ndirA:    Holder for the organized direction exponents

              - uint8_t*  p_nexpA:    Holder for the organized direction exponents

    EXAMPLE:

        >>> c_helper_ordDirExpA([1,3,5,0,0], [0,1,4,0,0], 5, p_ndirA, p_nexpA);

        >>> print(p_ndirA)
        [3,5,0,0,0]

        >>> print(p_nexpA)
        [1,4,0,0,0]

    */   
    // ************************************************************************************************

    uint8_t i = 0;
    uint8_t j = 0;

    for (;i<order;i++){

        if (multiple[i] != 0){ // If this exponent exists in the solution

            p_ndirA[j] = p_dirA[i];
            p_nexpA[j] = multiple[i];
            j++;

        }

    }

    // Fill up the rest with zeros.
    for (;j<order;j++){
        p_ndirA[j] = 0;
        p_nexpA[j] = 0;
    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_helper_getMultpl(uint8_t* p_expA, uint8_t order, directionHelper* p_dH, uint64_t* Nmultpl){
    /*
    void c_helper_getMultpl(uint8_t* p_expA expArray, directionHelper* p_dH, uint64_t* Nmultpl)

    function to get the multiples of a direction. (it only depends of the exponent vector.)

    INPUTS:      
              - uint8_t* p_expA:       Array of the exponents 

              - uint8_t order:         Maximum order of the direction

              - directionHelper* p_dH: Address of the list of helpers

              - uint64_t* Nmultpl:     Number of multiples computed.

    RESULT: 
            p_dH[order-1].p_multpl will contain the multiples of the direction.

    EXAMPLE:

        >>> c_helper_getMultpl([1,2,0], 3, p_dH, &Nmultpl);
        >>> print(p_dH[3-1].p_multpl)
        [0,0,0]
        [1,0,0]
        [0,1,0]
        [1,1,0]
        [0,2,0]
        [1,2,0]
        [-,-,-] # not relevant
        [-,-,-] # not relevant
        >>> print(Nmultpl)
        6


    */   
    // ************************************************************************************************
    uint64_t i=0, k=0;
    uint8_t passed;
    uint8_t* multiple = p_dH[order-1].p_mexpA;
    uint8_t* multiples = p_dH[order-1].p_multpl;
    
    *Nmultpl = 1;
    for(; i<order; i++ ){
        // Multiply by the number of possible values of each basis exponent.
        *Nmultpl *= p_expA[i]+1;

        // Initialize the multiple holder's values.
        multiple[i] = 0;  // First multiple is real (all exps zero).
        multiples[i] = 0; // Initialize first row in zeros
    }

    for ( i = 1; i < (*Nmultpl); i++){

        passed = 0; // termination flag off.
        k=0;        // Set the counter to the initial position

        while(passed == 0){

            // Check if the current exponent can be summed 1 and still meet the 
            // exponent array limits.
            if( (multiple[k]+1) > p_expA[k]){ 
                
                // This means that if the current k'th exponent + 1 will not meet 
                // the conditions.
                multiple[k] = 0; // reset the current exponent
                k++;             // go to next position.

            } else {

                // the exponent can be summed 1.
                multiple[k] += 1;
                passed = 1;        // rise the flag.

            }
        }

        for(k=0;k<order;k++){

            multiples[i*order+k] = multiple[k];

        }

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
uint16_t c_maxUI16(uint64_t a,uint64_t b){
    /* 
    uint16_t c_maxUI16(uint64_t a,uint64_t b)

    PURPOSE:     Computation of maximum of two integers

    INPUTS:      
              - uint64_t a: Integer to be compared.

              - uint64_t b: Integer to be compared

    RESULT: 
            Maximum of the two nmbers
              
    */
    // ************************************************************************************************

    if (a>b){
        
        return a;

    } else {
        
        return b;

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_minUI64(uint64_t a,uint64_t b,uint64_t* minnum,uint64_t* maxnum ){
    /* 
    uint64_t c_minUI64(uint64_t a,uint64_t b,uint64_t minnum,uint64_t maxnum )

    PURPOSE:     Computation of maximum and minimum of two integers

    INPUTS:      
              - uint64_t a: Integer to be compared.

              - uint64_t b: Integer to be compared

              - uint64_t* minnun: Address of minimum output.

              - uint64_t* maxnum: Address of maximum output.
              
    */
    // ************************************************************************************************

    if (a<b){
        *minnum = a;
        *maxnum = b;
    } else {
        *minnum = b;
        *maxnum = a;
    }

}
// ----------------------------------------------------------------------------------------------------









// ****************************************************************************************************
uint64_t c_helper_multMultiIndxFast(uint64_t* indx, uint8_t nindx, uint8_t order, 
                                directionHelper* p_dH, uint8_t* error){
    /* 
    uint64_t c_helper_multMultiIndxFast(uint64_t* indx, uint8_t nindx, uint8_t order, 
                                directionHelper* p_dH, uint8_t* error)

    PURPOSE:     Fast function that multiply multiple oti directions given by its indices. The idea is to send
                 the indices to a pure c-function in order to get the results.

    INPUTS:      
              - uint64_t* indx: List of Indices that represent the directions to be multiplied.

              - uint8_t nindx: Number of elements in indx

    OUTPUTS:
              - uint64_t indx: Resulting index that has the multiplication of the two numbers.
              
              - uint8_t* error: Error flag indicating viable multiplication or not.

                            error = 0:   -> Operation results in a viable direction.

                            error = 1:   -> Operation results in a not viable direction, and 
                                            indx should not be used. 
                                            e.g. the two directions result in a direction with 
                                            order greater than the maximum allowed order.
              
    */
    // ************************************************************************************************

    uint64_t minI, maxI;
    uint64_t indx1, indx2;
    uint8_t i, ord;

    
    {
        
        // -> Assuming values are not zero.
        // -> The number of indices is t
        
        ord = 0; // Find the order of the terms.
        for (i=0; i<nindx; i++){

            ord += c_sumUI8(&p_dH[order-1].p_expA[(indx[i]-1)*order],order);

            if (ord>order){

                *error = 1;
                return 0;

            }

        }
        
        // We know that the result is valid. It must exist.
        indx1 = indx[0]; 

        for(i=1 ; i<nindx; i++ ){
            
            indx2 = indx[i];
            
            c_minUI64(indx1,indx2,&minI,&maxI);
            // printf("IN MULTINDX: min %llu\n",minI);
            // printf("IN MULTINDX: max %llu\n",maxI);

            minI = (maxI-1)*((maxI-1)+1)/2 + (minI-1);
            //(i-1)*((i-1)+1)//2+(j-1)

            // Binary Search the Multiplication index to obtain the multiplication result.
            maxI =  c_binarySearchUI64(  p_dH[order-1].p_multInd, minI, p_dH[order-1].Nmult);
            // printf("IN MULTINDX: Index %llu\n",minI);
            // printf("IN MULTINDX: position %llu\n",maxI);
            // printf("IN MULTINDX: Found item %llu\n",p_dH[order-1].p_multInd[maxI]);
            // printf("IN MULTINDX: Found multResult %llu\n",p_dH[order-1].p_multRes[maxI]);

            if (p_dH[order-1].p_multInd[maxI] == minI){

                
                indx1 = p_dH[order-1].p_multRes[maxI];

            } else {

                *error = 1;
                return 0;

            }
        }

        *error = 0;
        return indx1;

    }
     

    

}
// ----------------------------------------------------------------------------------------------------




























// ****************************************************************************************************
uint64_t c_helper_multIndxFast(uint64_t indx1, uint64_t indx2, uint8_t order, directionHelper* p_dH, 
                               uint8_t* error){
    /* 
    uint64_t c_helper_multIndx(uint64_t indx1, uint64_t indx2, uint8_t order, directionHelper* p_dH, 
                           uint8_t error)

    PURPOSE:     Fast function that multiply two dual directions given by its indices. The idea is to send
                 the indices to a pure c-function in order to get the results.

    INPUTS:      
              - uint64_t indx1, indx2: Indices that represent the directions to be multiplied.

    OUTPUTS:
              - uint64_t indx: Resulting index that has the multiplication of the two numbers.
              
              - uint8_t* error: Error flag indicating viable multiplication or not.

                            error = 0:   -> Operation results in a viable direction.

                            error = 1:   -> Operation results in a not viable direction, and 
                                            indx should not be used. 
                                            e.g. the two directions result in a direction with 
                                            order greater than the maximum allowed order.
              
    */
    // ************************************************************************************************

    uint64_t minI, maxI;
    uint8_t ord1, ord2;

    

    if (order == 1){

        if (indx1 == 0 || indx2 == 0){
            
            c_minUI64(indx1,indx2,&minI,&maxI);
            *error = 0;
            return  maxI;

        } else {

            *error = 1;
            return 0;
        }


    }else{

        // First check if values are zero
        c_minUI64(indx1,indx2,&minI,&maxI);

        if (minI == 0){

            *error = 0;
            return maxI;

        }

        //First check orders... then do binary search
        ord1 = c_sumUI8(&p_dH[order-1].p_expA[(indx1-1)*order],order);
        ord2 = c_sumUI8(&p_dH[order-1].p_expA[(indx2-1)*order],order);

        if ((ord1+ord2)<=order){
            // printf("IN MULTINDX: i1 %llu\n",indx1);
            // printf("IN MULTINDX: i2 %llu\n",indx2);
            

            // printf("IN MULTINDX: min %llu\n",minI);
            // printf("IN MULTINDX: max %llu\n",maxI);

            minI = (maxI-1)*((maxI-1)+1)/2 + (minI-1);
            //(i-1)*((i-1)+1)//2+(j-1)

            // Binary Search the Multiplication index to obtain the multiplication result.
            maxI =  c_binarySearchUI64(  p_dH[order-1].p_multInd, minI, p_dH[order-1].Nmult);
            // printf("IN MULTINDX: Index %llu\n",minI);
            // printf("IN MULTINDX: position %llu\n",maxI);
            // printf("IN MULTINDX: Found item %llu\n",p_dH[order-1].p_multInd[maxI]);
            // printf("IN MULTINDX: Found multResult %llu\n",p_dH[order-1].p_multRes[maxI]);

            if (p_dH[order-1].p_multInd[maxI] == minI){

                *error = 0;
                return p_dH[order-1].p_multRes[maxI];

            } else {

                *error = 1;
                return 0;

            }
        }else{

            *error = 1;
            return 0;

        }

    }
     

    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_helper_findIndex(uint16_t* p_dirA,  uint8_t* p_expA, uint8_t order, directionHelper* p_dH){
    /*
    uint64_t c_helper_findIndex(uint16_t* dirA,  uint8_t* expA, uint8_t order, directionHelper* p_dH)

    PURPOSE:      Implements a binary search so that it can find the given pair (dirA,expA) in
                  (p_dH.p_dirA,p_dH.p_expA)
     
    DESCRIPTION:  The condition that this satisfies is that it will return i such that

                  >>> (self.dirA[i,:],self.expA[i,:]) == (dirA,expA)
                  True

    INPUTS:      
              - uint16_t* dirA: Direction array with the basis of the direction to search.

              - uint8_t*  expA: Exponent array with the exponents of the basis that 
                                are present in the direction to search.

              - directionHelper* p_dH: List of all direction helpers

    OUTPUTS: 
              - uint64_t indx : position of the pair 

                        (dirA[:],expA[:]) in (p_dH.dirA[:,:],p_dH.expA[:,:])
              
    */
    //*************************************************************************************************

    uint64_t indx = 0;

    if (p_dirA[0] == 0){     // Case where dirA and expA are all zeros
    
        return indx;
    }
    

    if (order == 1){
          
        indx = p_dirA[0];
    
    }else{
          
        indx = c_binarySearch_dH( p_dirA, p_expA, &p_dH[order-1]) + 1;
    
    }

    return indx;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_helper_multIndx(uint64_t indx1, uint64_t indx2, uint8_t order, directionHelper* p_dH, 
                           uint8_t* error){
    /*
    uint64_t c_helper_multIndx(uint64_t indx1, uint64_t indx2, uint8_t order, directionHelper* p_dH, 
                           uint8_t error)

    PURPOSE:     Function that multiply two dual directions given by its indices. The idea is to send
                 the indices to a pure c-function in order to get the results.

    INPUTS:      
              - uint64_t indx1, indx2: Indices that represent the directions to be multiplied.

    OUTPUTS:
              - uint64_t indx: Resulting index that has the multiplication of the two numbers.
              
              - uint8_t* error: Error flag indicating viable multiplication or not.

                            error = 0:   -> Operation results in a viable direction.

                            error = 1:   -> Operation results in a not viable direction, and 
                                            indx should not be used. 
                                            e.g. the two directions result in a direction with 
                                            order greater than the maximum allowed order.
              
    */
    // ************************************************************************************************

    uint64_t indx = 0;  

    if (order == 1){
        
        // Order 1 multiplication is very easy and fast.
        if (indx1 == 0 ){
        
            error[0] = 0;
            return indx2;

        }else if(indx2 == 0){

            error[0] = 0;
            return indx1;

        }else{

            error[0] = 1;
            indx  = 0;
            return indx;

        }

    } else {
      
        // Check first if the given indices are zero.
  
        if (indx1 == 0 ){
          
            error[0] = 0;
            return indx2;
  
        }else if(indx2 == 0){
  
            error[0] = 0;
            return indx1;
  
        }
        
        // If necessary, multiply using the direction helper.
        indx = c_multDirections_dH( indx1-1, indx2-1, &p_dH[order-1], error);

    } 

    return indx + 1;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint8_t*  c_helper_getExpA(uint64_t indx, uint8_t order, directionHelper* p_dH){
    /*
    uint8_t* c_helper_getExpA(uint64_t indx, uint8_t order)

    PURPOSE:    Return the corresponding exponent array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] expA: Array containing the exponents of direction indx.

    TODO: Make output constant.
              
    */
    //*************************************************************************************************

    uint8_t i;
      
    if (indx != 0){

        return &p_dH[order-1].p_expA[(indx-1)*order];

    }else{

        for (i=0; i<order; i++){

            p_dH[order-1].p_mexpA[i] = 0; // Use only the first user array.

        }

        return p_dH[order-1].p_mexpA;
    }


}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint16_t*  c_helper_getDirA(uint64_t indx, uint8_t order, directionHelper* p_dH){
    /*
    uint8_t* c_helper_getDirA(uint64_t indx, uint8_t order)

    PURPOSE:    Return the corresponding direction array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] dirA: Array containing the basis of direction indx.

    TODO: Make output constant.
              
    */
    //*************************************************************************************************

    uint8_t i;
      
    if (indx != 0){

        return &p_dH[order-1].p_dirA[(indx-1)*order];

    }else{

        for (i=0; i<order; i++){

            p_dH[order-1].p_mdirA[i] = 0; // Use only the first user array.

        }

        return p_dH[order-1].p_mdirA;
    }


}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline uint8_t*   c_helper_getUExpA( uint8_t order, uint8_t n, directionHelper* p_dH){
    /*
    uint8_t* c_helper_getUExpA( uint8_t order, uint8_t n, directionHelper* p_dH)

    PURPOSE:  Return the n'th user exponent array.  
     
    INPUTS:      
              - uint8_t order: Order that indicates which helper to use.

              - uint8_t n:     Number of helper to use. Be careful to use a number less than
                               p_dH[order-1].nn

    OUTPUTS:
              - uint8_t[:] uexpA: n'th user array.
              
    */
    //*************************************************************************************************
      
    return &p_dH[order-1].p_uexpA[n*order];

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline uint16_t* c_helper_getUDirA( uint8_t order, uint8_t n, directionHelper* p_dH){
    /*
    uint16_t* c_helper_getUDirA( uint8_t order, uint8_t n, directionHelper* p_dH)

    PURPOSE:  Return the n'th user exponent array.  
     
    INPUTS:      
              - uint8_t order: Order that indicates which helper to use.

              - uint8_t n:     Number of helper to use. Be careful to use a number less than
                               p_dH[order-1].nn

    OUTPUTS:
              - uint8_t[:] udirA: n'th user array.
              
    */
    //*************************************************************************************************

    return &p_dH[order-1].p_udirA[n*order];
  
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_helper_findMaxDir(uint64_t index, uint8_t order, directionHelper* p_dH){
    /*
    uint64_t c_helper_findMaxDir(uint64_t index, uint8_t order, directionHelper* p_dH)

    PURPOSE:    Return the maximum direction of count.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint64_t The maximum basis of said direction.
              
    */
    // ************************************************************************************************

    uint64_t res = 0 ;       // Variable that has the maximum direction

    if (order == 1){
      
        res = index;

    } else {
      
        res = c_binarySearchUI64( p_dH[order-1].p_countOTI, index + 1 , p_dH[order-1].Nbasis );

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_helper_getNels( uint64_t m, uint8_t order, directionHelper* p_dH){
    /*
    uint64_t c_helper_getNels( uint64_t m, uint8_t order, directionHelper* p_dH)

    PURPOSE:    Return the number of total elements for m basis and maxorder.  
     
    INPUTS:      
              - uint64_t m: Number of directions.

    OUTPUTS:
              - uint64_t Number of elements.
              
    */
    // ************************************************************************************************

    uint64_t res = 0;  // Variable that has the maximum direction

    if (order == 1){
      
      res = m + 1;

    }else{
      
      res = p_dH[order-1].p_countOTI[m]; // TODO: Check when m > countOTI.size

    } 

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline uint64_t c_helper_getNParts( uint8_t order, directionHelper* p_dH){
    /*
    uint64_t c_helper_getNParts( uint8_t order, directionHelper* p_dH)

    PURPOSE:    Return the number of partition sets for the given size of set.
     
    INPUTS:      
              - uint8_t n: number of elements of the set.

    OUTPUTS:
              - uint64_t: number of partitions for a set of n elements.
              
    */
    // ************************************************************************************************
    
    return p_dH[order-1].Npart;

}
// ---------------------------------------------------------------------------------------------------- 



// ****************************************************************************************************
inline uint16_t c_helper_getSet( uint8_t order,uint64_t i,uint64_t j, directionHelper* p_dH){
    /*
    uint16_t c_helper_getSet( uint8_t order,uint64_t i,uint64_t j, directionHelper* p_dH)

    PURPOSE:    Return the set, in binary format, for the given partition i and subset j.
     
    INPUTS:      
              - uint8_t  maxorder: number of elements of the set.

              - uint64_t i: Number of partition to look for.

              - uint64_t j: subset of the partition to look for.

    OUTPUTS:
              - uint16_t: number in which the high bits correspond to the position of the elements
                          that belong to the asked partition.
              
    */
    // ************************************************************************************************

    return p_dH[order-1].p_part[ i*order + j ];

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_helper_load(  uint8_t maxorder, char* strLocation, directionHelper** p_dH){          
    /*
    directionHelper* c_loadHelpers(  uint8_t maxorder )

    Load a set of helpers from order 1 until maxorder with specified number of  basis for each order.

    INPUTS:
        
        -> maxorder:    Maximum order of helper to be loaded.
            Example: 3

    OUTPUTS:
        -> The result is an array of helpers of length = order with the loaded data.
    */ 
    // ************************************************************************************************

    
    // uint16_t ndir[]   = {65535, // ------------------   1 -> Probably not necessary
    //                       1000, // ------------------   2
    //                        100, // ------------------   3
    //                         10, // ------------------   4
    //                         10, // ------------------   5
    //                         10, // ------------------   6
    //                         10, // ------------------   7 
    //                         10, // ------------------   8
    //                         10, // ------------------   9
    //                         10  // ------------------  10
    // };

    uint16_t ndir[]   = {65535, // ------------------   1 -> Probably not necessary
                          1000, // ------------------   2
                           100, // ------------------   3
                            10, // ------------------   4
                            10, // ------------------   5
                            10, // ------------------   6
                            10, // ------------------   7 
                            10, // ------------------   8
                            10, // ------------------   9
                            10  // ------------------  10
    };

    uint8_t  nhelps =  3;

    p_dH[0] = (directionHelper* )malloc(maxorder*sizeof(directionHelper));

    if (p_dH == NULL){
      printf("Error. Not enough memory for helper array. Exiting\n");
      exit(-1);
    }
    
    for( int i = 1; i<=maxorder; i++){
        
      c_loadDirHelper(strLocation,i,ndir[i-1], nhelps, &(*p_dH)[i-1]);

    }

#ifdef VERB // Indicator of verbosity from compiler.
    printf("Successfully loaded  %d helpers.\n",maxorder);
#endif

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_helper_free(directionHelper* p_dH , uint8_t maxorder ){          
    /*
    void c_freeHelpers(directionHelper* p_dH , uint8_t maxorder )

    Free all helpers that where loaded.

    INPUTS:
        -> p_dH:        Array of helpers
        -> maxorder:    Maximum order of helper to be loaded.
            Example: 3

    OUTPUTS:
        -> The result is an array of helpers of length = order with the loaded data.
    */ 
    // ************************************************************************************************

    
    
    for( int i = 1; i<=maxorder; i++){
        
      c_freeDirHelper(&p_dH[i-1]);
    }

    free(p_dH);

#ifdef VERB // Indicator of verbosity from compiler.
    printf("Successfully freed  %d helpers.\n",maxorder);
#endif
}
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// -------------------------------     END HELPER FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------







// ----------------------------------------------------------------------------------------------------
// -------------------------------------     FUNCTIONS     --------------------------------------------
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_loadDirA(char* strLocation, uint8_t order,   uint16_t ndir, uint16_t** dirA, uint64_t* Ndir){
    /*
    loadDirA( order,  ndir)

    Loads a direction array from a file

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  ndir:    Number of directions to load.
            Example: 100

    OUTPUTS:
        -> The result is the direction array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0,shapey=0;
    


    // Malloc memory for strings:
    filename = (char *)malloc(256*sizeof(char));
    holder   = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc(16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD DIRECTION ARRAY:


        strcpy(filename,strLocation);
        strcat(filename,basename);
        strcat(filename,"dir_n");
        sprintf(holder, "%hhu", order);

        strcat(filename,holder);
        strcat(filename,"_m");

        sprintf(holder, "%hu", ndir);
        strcat(filename,holder);

        strcat(filename,".npy");
    
#ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Filename: %s\n", filename);
#endif

        if ((cfPtr = fopen( filename, "rb" )) != NULL){



            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';



            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);



            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';



            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);

#ifdef VERB // Indicator of verbosity from compiler.
            printf("shape: %llu, %llu \n",shapex,shapey);
#endif
            Ndir[0] = shapex;
            shapex *= shapey;
            
            // Allocate memory
            
            dirA[0] = (uint16_t* )malloc(shapex*sizeof(uint16_t));

            if (dirA[0] != NULL){

                fread(dirA[0], sizeof(uint16_t), shapex, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for direction array.\n Exiting\n");
                exit(-1);

            }

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filename);
#endif

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }



        fclose(cfPtr);


        // free memory
        free(filename);
        free(holder); 
        free(holderSmall); 
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_loadExpA(char* strLocation,uint8_t order,   uint16_t ndir, uint8_t** expA, uint64_t* Ndir){
    /*
    loadExpA( order,  ndir)

    Loads a direction array from a file

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  ndir:    Number of directions to load.
            Example: 100

    OUTPUTS:
        -> The result is the exponent array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0,shapey=0;

    // Malloc memory for strings:
    filename =      (char *)malloc(256*sizeof(char));
    holder   =      (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc( 16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD DIRECTION ARRAY:
        strcpy(filename,strLocation);
        strcat(filename,basename);
        strcat(filename,"exp_n");
        sprintf(holder, "%hhu", order);

        strcat(filename,holder);
        strcat(filename,"_m");

        sprintf(holder, "%hu", ndir);
        strcat(filename,holder);

        strcat(filename,".npy");
    
#ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Filename: %s\n", filename);
#endif

        if ((cfPtr = fopen( filename, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';



            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);



            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';



            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);

#ifdef VERB // Indicator of verbosity from compiler.
            printf("shape: %llu, %llu \n",shapex,shapey);
#endif

            Ndir[0] = shapex;
            shapex *= shapey;
            
            // Allocate memory
            expA[0] = (uint8_t* )malloc(shapex*sizeof(uint8_t));

            if (expA[0] != NULL){

                fread(expA[0], sizeof(uint8_t), shapex, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for direction array.\n Exiting\n");
                exit(-1);

            }

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filename);
#endif

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }
        fclose(cfPtr);


        // free memory
        free(filename);
        free(holder); 
        free(holderSmall); 
    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_loadCount(char* strLocation,uint8_t order,   uint16_t ndir, uint64_t** count){
    /*
    loadDirA( order,  ndir)

    Loads a direction array from a file

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  ndir:    Number of directions to load.
            Example: 100

    OUTPUTS:
        -> The result is the exponent array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0;

    // Malloc memory for strings:
    filename = (char *)malloc(256*sizeof(char));
    holder   = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc(16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD DIRECTION ARRAY:
        strcpy(filename,strLocation);
        strcat(filename,basename);
        strcat(filename,"count_n");
        sprintf(holder, "%hhu", order);

        strcat(filename,holder);
        strcat(filename,"_m");

        sprintf(holder, "%hu", ndir);
        strcat(filename,holder);

        strcat(filename,".npy");
    
#ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading File: %s\n", filename);
#endif

        if ((cfPtr = fopen( filename, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';


            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,), }",
                holderSmall, holderSmall, &shapex);

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Array shape: %llu\n",shapex);
#endif
            
            // Allocate memory
            count[0] = (uint64_t* )malloc(shapex*sizeof(uint64_t));

            if (count[0] != NULL){

                fread(count[0], sizeof(uint64_t), shapex, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for direction array.\n Exiting\n");
                exit(-1);

            }

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filename);
#endif

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }

        fclose(cfPtr);


        // free memory
        free(filename);
        free(holder); 
        free(holderSmall); 
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_loadMult(char* strLocation,uint8_t order, uint16_t ndir, uint64_t** multRes, uint64_t** multInd, uint64_t* Nmult){
    /*
    loadDirA( order,  ndir)

    Loads a direction array from a file

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  ndir:    Number of directions to load.
            Example: 100

    OUTPUTS:
        -> The result is the exponent array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char *filename2 ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr  = NULL; //  file pointer
    FILE *cfPtr2 = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0;
    uint64_t shapey=0;



    // Malloc memory for strings:
    filename = (char *)malloc(256*sizeof(char));
    filename2 = (char *)malloc(256*sizeof(char));
    holder   = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc(16*sizeof(char));
    
    if(filename != NULL && holder != NULL && filename2 != NULL){
        // LOAD DIRECTION ARRAY:
        strcpy(filename,strLocation);
        strcat(filename,basename);
        strcat(filename,"multres_n");
        strcpy(filename2,strLocation);
        strcat(filename2,basename);
        strcat(filename2,"multind_n");
        sprintf(holder, "%hhu", order);

        strcat(filename,holder);
        strcat(filename2,holder);

        strcat(filename,"_m");
        strcat(filename2,"_m");

        sprintf(holder, "%hu", ndir);
        strcat(filename,holder);
        strcat(filename2,holder);

        strcat(filename,".npy");
        strcat(filename2,".npy");
        
#ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Files: %s, %s\n", filename, filename2);
#endif

        if ((cfPtr = fopen( filename, "rb" )) != NULL  && (cfPtr2 = fopen( filename2, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';


            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,), }",
                holderSmall, holderSmall, &shapex);
            
               
            Nmult[0] = shapex;

            if (shapex==0){

                multRes[0] = NULL;

            } else {

                // Allocate memory
                multRes[0] = (uint64_t* )malloc(shapex*sizeof(uint64_t));

                if (multRes[0] != NULL ){

                    fread(multRes[0], sizeof(uint64_t), shapex, cfPtr);

                }else{

                    printf("\nERROR1: Not enough memory for direction array.\n Exiting\n");
                    exit(-1);

                }

            }


            fread(holder, sizeof(char), 8, cfPtr2);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr2);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr2);
            holder[header_size] = '\0';


            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,), }",
                holderSmall, holderSmall, &shapey);

            if (shapex != shapey){
                printf("found different shapes: %llu     ---   %llu\n", shapex, shapey);
            }

            if (shapey==0){

                multInd[0] = NULL;

            } else {

                // Allocate memory
                multInd[0] = (uint64_t* )malloc(shapey*sizeof(uint64_t));

                if ( multInd[0] != NULL){

                    fread(multInd[0], sizeof(uint64_t), shapex, cfPtr2);

                }else{

                    printf("\nERROR2: Not enough memory for direction array.\n Exiting\n");
                    exit(-1);

                }

            }



                

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filename);
#endif

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }

        fclose(cfPtr);
        fclose(cfPtr2);


        // free memory
        free(filename);
        free(filename2);
        free(holder); 
        free(holderSmall); 
    }
    
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_loadParts(char* strLocation,uint8_t order,   uint16_t ndir, uint16_t** p_parts, uint64_t* Nparts){
    /*
    loadParts( order,  ndir, count)

    Loads a direction array from a file

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  ndir:    Number of directions to load.
            Example: 100

    OUTPUTS:
        -> The result is the partition array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0,shapey=0;

    // Malloc memory for strings:
    filename = (char *)malloc(256*sizeof(char));
    holder   = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc(16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD DIRECTION ARRAY:
        strcpy(filename,strLocation);
        strcat(filename,basename);
        strcat(filename,"part_n");
        sprintf(holder, "%hhu", order);
        strcat(filename,holder);
        strcat(filename,".npy");
    
#ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading File: %s\n", filename);
#endif

        if ((cfPtr = fopen( filename, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';



            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);



            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';


            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Array shape: %llu, %llu \n",shapex,shapey);
#endif

            Nparts[0] = shapex; 
            shapex   *= shapey;
            
            // Allocate memory
            
            p_parts[0] = (uint16_t* )malloc(shapex*sizeof(uint16_t));

            if (p_parts[0] != NULL){

                fread(p_parts[0], sizeof(uint16_t), shapex, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for partition array.\n Exiting\n");
                exit(-1);

            }

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filename);
#endif

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }



        fclose(cfPtr);


        // free memory
        free(filename);
        free(holder); 
        free(holderSmall); 
    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_loadDirHelper( char* strLocation, uint8_t order,   uint16_t nbasis, uint8_t nhelps, directionHelper* dHelp){          
    /*
    loadDirHelper( order,  ndir,  dHelp)

    Loads a direction helper from a file.Applies the binary search to find what is the position at which the 
    pair dirs,exps exist on an array of size N that contains it.

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  nbasis:    Number of basis directions to load.
            Example: 100

        ->nhelps:   Number of help arrays to be allocated in the array.

        ->dHelp:    Adress of the helper to be loaded.

    OUTPUTS:
        -> The result is the direction helper with the loaded data.
    */ 
    // ************************************************************************************************

    // Initialize known values

    c_loadDirA( strLocation, order, nbasis, &dHelp->p_dirA, &dHelp->Ndir  );
    c_loadExpA( strLocation, order, nbasis, &dHelp->p_expA, &dHelp->Ndir  );
    c_loadParts(strLocation, order, nbasis, &dHelp->p_part, &dHelp->Npart );
    c_loadCount(strLocation, order, nbasis, &dHelp->p_countOTI);
    c_loadMult( strLocation, order, nbasis, &dHelp->p_multRes, &dHelp->p_multInd, &dHelp->Nmult);

    dHelp->Nbasis = nbasis;
    dHelp->order  =  order;
    dHelp->nn     = nhelps;
    
    dHelp->p_udirA  = (uint16_t*)malloc(  nhelps*order*sizeof(uint16_t)    ); 
    dHelp->p_uexpA  = (uint8_t* )malloc(  nhelps*order*sizeof(uint8_t )    ); 
    dHelp->p_rdirA  = (uint16_t*)malloc(  nhelps*order*sizeof(uint16_t)    ); 
    dHelp->p_rexpA  = (uint8_t* )malloc(  nhelps*order*sizeof(uint8_t )    ); 
    dHelp->p_mdirA  = (uint16_t*)malloc(  nhelps*order*sizeof(uint16_t)    ); 
    dHelp->p_mexpA  = (uint8_t* )malloc(  nhelps*order*sizeof(uint8_t )    ); 
    dHelp->p_mapder = (uint16_t*)malloc(2*nhelps*order*sizeof(uint16_t)    ); 
    dHelp->p_multpl = (uint8_t* )malloc( c_fastpow(2,order)*order*sizeof(uint8_t )); 
    dHelp->p_fder   = (double*  )malloc( (order+1    )*sizeof(double  )    );
    dHelp->p_coefs  = (double*  )malloc( (dHelp->Ndir)*sizeof(double  )    );
    dHelp->p_indx   = (uint64_t*)malloc( (dHelp->Ndir)*sizeof(uint64_t)    );

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_freeDirHelper(  directionHelper* dHelp){          
    /*
    freeDirHelper( dHelp)

    Frees all arrays in dHelp struct.

    INPUTS:
        
        -> dHelp:   Allocated direction helper.
    */ 
    // ************************************************************************************************

    // Initialize known values
    if (dHelp->p_dirA != NULL){
        free(dHelp->p_dirA    );
    }

    if (dHelp->p_expA != NULL){
        free(dHelp->p_expA    );
    }

    if (dHelp->p_part != NULL){
        free(dHelp->p_part    );
    }

    if (dHelp->p_countOTI != NULL){
        free(dHelp->p_countOTI);
    }

    if (dHelp->p_udirA != NULL){
        free(dHelp->p_udirA   );
    }
    
    if (dHelp->p_uexpA != NULL){
        free(dHelp->p_uexpA   );
    }
    
    if (dHelp->p_rdirA != NULL){
        free(dHelp->p_rdirA   );
    }

    if (dHelp->p_rexpA != NULL){
        free(dHelp->p_rexpA   );
    }
    
    if (dHelp->p_mdirA != NULL){
        free(dHelp->p_mdirA   );
    }
    
    if (dHelp->p_mexpA    != NULL){
        free(dHelp->p_mexpA   );
    }
    
    if (dHelp->p_mapder   != NULL){
        free(dHelp->p_mapder  );
    }

    if (dHelp->p_multRes   != NULL){
        free(dHelp->p_multRes  );
    }

    if (dHelp->p_multInd   != NULL){
        free(dHelp->p_multInd  );
    }

    if (dHelp->p_multpl   != NULL){
        free(dHelp->p_multpl  );
    }

    if (dHelp->p_fder    != NULL){
        free(dHelp->p_fder   );
    }

    if (dHelp->p_coefs   != NULL){
        free(dHelp->p_coefs  );
    }

    if (dHelp->p_indx    != NULL){
        free(dHelp->p_indx   );
    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
uint64_t c_fastpow(uint64_t b,uint16_t exp){
    /*
    fastpow( b,exp ):

    Function that returns the power of a positive integer "base" to a positive integer "exp", both 
    bounded in value from 0 to 10. It is meant to be much faster than math.h pow(), which is defined
    for double inputs.

    INPUTS:
        
        -> b   : Base of exponentiation.         0 < b    < 10

        -> exp : exponent of the exponentiation. 0 < exp  < 10

    OUTPUTS:

        -> The result is b^exp :

            Example: fastpow(3,2) --> 9

    */
    // ************************************************************************************************

    static uint64_t ndir = 11;

    static uint64_t pows[] = {
        1,  0,   0,    0,     0,      0,       0,        0,         0,          0,           0, 
        1,  1,   1,    1,     1,      1,       1,        1,         1,          1,           1, 
        1,  2,   4,    8,    16,     32,      64,      128,       256,        512,        1024, 
        1,  3,   9,   27,    81,    243,     729,     2187,      6561,      19683,       59049, 
        1,  4,  16,   64,   256,   1024,    4096,    16384,     65536,     262144,     1048576, 
        1,  5,  25,  125,   625,   3125,   15625,    78125,    390625,    1953125,     9765625, 
        1,  6,  36,  216,  1296,   7776,   46656,   279936,   1679616,   10077696,    60466176, 
        1,  7,  49,  343,  2401,  16807,  117649,   823543,   5764801,   40353607,   282475249, 
        1,  8,  64,  512,  4096,  32768,  262144,  2097152,  16777216,  134217728,  1073741824, 
        1,  9,  81,  729,  6561,  59049,  531441,  4782969,  43046721,  387420489,  3486784401, 
        1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000,
        1, 11, 121, 1331, 14641, 161051, 1771561, 19487171, 214358881, 2357947691, 25937424601};
    
    return pows[b*ndir+exp];

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_fastfact(uint8_t exp){
    /*
    fastfact( exp ):

    Function that returns the factorial of a positive integer value from 0 until 10.

    INPUTS:
        -> exp : value to compute the factorial. 0 < exp < 10

    OUTPUTS:
        -> The result is exp! :

            Example: fastfact(3) --> 6

    */
    // ************************************************************************************************
    static double facts[] = {1., 1., 2., 6., 24., 120., 720., 5040., 40320., 362880., 3628800.};
    
    return facts[exp];

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_ndir(uint64_t nvar,uint8_t order){
    /*
    c_ndir(m, n):

    Function that returns the binomial coefficient :   /  nvar + order  \
                                                      (                  )
                                                       \      nvar      /
    INPUTS:
        -> nvar  : Number of variables to compute derivatives
        -> order : Order of derivatives

    OUTPUTS:
        -> The result is exp! :

            Example: c_ndir(3,5) --> 6

    */
    // ************************************************************************************************
    uint8_t n = order;
    uint64_t num = 1;
    uint64_t den = 1;

    for (int i=0; i<order; i++){
        num*=(nvar+n);
        den*=(n);
        n = n-1;
    }
    
    return num/den;

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_orderDirExpArray(uint16_t* dirA,    uint8_t*    multExpA , uint8_t pos,
             uint16_t* newDirA, uint8_t* newExpA, uint8_t order){
    /*
    c_orderDirExpArray( dirA, multExpA, newDirA, pos, newExpA,  maxorder)

    */
    // ************************************************************************************************
    
    uint8_t i;
    uint8_t j = 0 ;
    

    

    for (i=0; i<order; i++){
    
        if (multExpA[ i+ pos*order] != 0){          // the exponent exist in the solution.
                  
            newDirA[j] = dirA[i];
            newExpA[j] = multExpA[i + pos*order];
            j += 1;
        
        }
    
    }
    if (j != order){
        for(i = j; i<order; i++){
            newDirA[j] = 0;
            newExpA[j] = 0;
        }
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_mapPartition(uint16_t part,  uint16_t*  ptr_dir,  uint8_t  order, 
                    uint16_t*  ptr_map){
    /*
    c_mapPartition(  part,  ptr_dir,  order,  ptr_map)

    */
    // ************************************************************************************************
    
    uint8_t i = 0 ;                     // Counter of the element that belongs to 
    uint8_t pos = 0;                    // Holds position to write in ptr_map (set with the partition)
    uint16_t seti = part;               // This number contains in its bits the elements of the full 
                                        // that belong to the current partition.
    while(seti != 0){

        if(seti & 1){

            ptr_map[pos] = ptr_dir[i];  // Bit of position i is high, therefore the element i exist in 
            pos += 1;                   // the set.

        }

        i += 1;                         // update the counter for i.
        seti = seti >> 1;               // Move number one element to the right to ask if next 
                                        // element exist in the set.
    }

    for (i = pos; i<order; i++){

        ptr_map[i] = 0;                 // Fill the remaining elements with zeros.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mapDirArrayNoMapderFast( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,
                    uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2) {
    /*
    mapDirArrayNoMapderFast( ptr_dirA1 , ptr_dirA2,       order,
                   ptr_mdirA2, ptr_mdirA2):

    Function that maps two direction arrays to a consecutive ordered 
    direction arrays starting from 1.

    INPUTS:
        -> ptr_dirA1 (order): Array of values that represent the directions of a number
            Example: [ 3, 8, 0, 0]

        -> ptr_dirA2 (order): Array of values that represent the exponents of those directions
            Example: [ 7,10, 0, 0]

        -> order:    Order of the OTI number that is being used.
            Example: 4 


    OUTPUTS:
        -> The result are 3 arrays:

            -> ptr_mdirA1 (order): Array of values with the corresponding mapped directions of array 
            dirA1.
            Example: [1, 3, 0, 0]

            -> ptr_mdirA2 (order): Array of values that represent the exponents of those directions
            Example: [2, 4, 0, 0]


    
    Note: All arrays must come already allocated.

    */
    // ************************************************************************************************
    
    uint8_t  k=1;
    uint8_t  i=0,  j=0;

    uint16_t dir1, dir2 ;    

    while (i < order && j < order){
        
        dir1 = ptr_dirA1[i];        
        dir2 = ptr_dirA2[j];
        
        if (dir1 == 0 || dir2 == 0){
            
            if (dir1 == 0){
                ptr_mdirA1[i] = 0;
                i++;
            } else {
                ptr_mdirA1[i] = k;
                i++;
                k++;
            }
            
            if (dir2 == 0){
                ptr_mdirA2[j] = 0;
                j++;
            } else {
                ptr_mdirA2[j] = k;
                j++;
                k++;
            }

        }else {

            if (dir1 == dir2){
                ptr_mdirA1[i] = k;
                ptr_mdirA2[j] = k;
                i++;
                j++;
                k++;
            }else if (dir1 < dir2){
                ptr_mdirA1[i] = k;
                i++;
                k++;
            }else{
                ptr_mdirA2[j] = k;
                j++;
                k++;
            }

        }

    }
    for (;i < order; i++) {
        dir1 = ptr_dirA1[i];
        if (dir1 == 0){
            ptr_mdirA1[i] = 0;
            i++;
        } else {
            ptr_mdirA1[i] = k;
            i++;
            k++;
        }
    }
    for (;j < order; j++) {
        dir2 = ptr_dirA2[j];
        if (dir2 == 0){
            ptr_mdirA2[j] = 0;
            j++;
        } else {
            ptr_mdirA2[j] = k;
            j++;
            k++;
        }
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_mapDirArrayNoMapder( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,
                    uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2) {
    /*
    c_mapDirArray( ptr_dirA1 , ptr_dirA2,       order,
                   ptr_mdirA2, ptr_mdirA2):

    Function that maps two direction arrays to a consecutive ordered 
    direction arrays starting from 1.

    INPUTS:
        -> ptr_dirA1 (order): Array of values that represent the directions of a number
            Example: [ 3, 8, 0, 0]

        -> ptr_dirA2 (order): Array of values that represent the exponents of those directions
            Example: [ 7,10, 0, 0]

        -> order:    Order of the OTI number that is being used.
            Example: 4 


    OUTPUTS:
        -> The result are 3 arrays:

            -> ptr_mdirA1 (order): Array of values with the corresponding mapped directions of array 
            dirA1.
            Example: [1, 3, 0, 0]

            -> ptr_mdirA2 (order): Array of values that represent the exponents of those directions
            Example: [2, 4, 0, 0]


    
    Note: All arrays must come already allocated.

    */
    // ************************************************************************************************
    
    uint8_t k = 0;
    uint8_t i;
    uint8_t j;
    uint8_t l;
    uint8_t n = 0;
    uint16_t m;

    for (i = 0; i<order ; i++){
        
        if(ptr_dirA1[i]!=0){

            m = i+1;
            ptr_mdirA1[i] = m;


        } else{
          
            ptr_mdirA1[i] = 0;

        }

    }

    // Check if the second array has some values that can improve the 
    // performance

    for(i = 0; i<order ; i++){

        if(ptr_dirA2[i]!=0){

            // Loop in the elements of dirA1
            for(l=n; l<order; l++){
                
                if (ptr_dirA1[l]!=0){

                    if(ptr_dirA2[i] < ptr_dirA1[l]){


                        k = ptr_mdirA1[l];

                        // Sum 1 to all elements in ptr_mdirA1 except the zeros
                        for(j = l; j<order ; j++){
                            
                            if(ptr_dirA1[j]!=0){
                      
                                ptr_mdirA1[j] += 1;
                            
                            } else{
                                
                                break;

                            }

                        }

                        n = l;
                        ptr_mdirA2[i] = k;
                        m += 1;
                        break;

                    }else if(ptr_dirA2[i] == ptr_dirA1[l]){
                      
                        k = ptr_mdirA1[l];
                        ptr_mdirA2[i] = k;
                        break;

                    }

                }else{
            
                    ptr_mdirA2[i] = m+1;
                    m+=1;
                    break;
                    
                }

                if (l==order-1){
                    ptr_mdirA2[i] = m+1;
                    m+=1;
                }

            }

        }else{

            ptr_mdirA2[i] = 0;

        }



    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_multDirections(uint16_t* ptr_dirArray, uint8_t* ptr_expArray,
                        uint16_t* ptr_dirA1,  uint8_t* ptr_expA1,
                        uint16_t* ptr_dirA2,  uint8_t* ptr_expA2, 
                        uint16_t* ptr_mdirA1, uint8_t* ptr_mexpA1,
                        uint16_t* ptr_mdirA2, uint16_t* ptr_mdirA3, 
                        uint16_t* ptr_mapder, 
                        uint8_t order, uint64_t N, uint8_t* error ){
    /*
    c_multDirections(ptr_dirA1, ptr_expA2, ptr_dirA1, ptr_expA2, order):

    Function that multiplies two directions i,j.

    INPUTS:

        -> ptr_dirArray[N,order]:   Array of all possible combinations of directions 
                                    for m number of base directions.
            Example: [1,0,   
                      1,0,
                      2,0,
                      1,2,
                      2,0,
                      3,0,   // for m=3
                      1,3,
                      2,3,
                      3,0]

        -> ptr_expArray[N,order]:   Array of all possible combinations of exponents, 
                                    associated to those directions.
            Example: [1,0,
                      2,0,   
                      1,0,
                      1,1,   // the sum of each row should always be \leq order.
                      2,0,
                      1,0,
                      1,1,
                      1,1,
                      2,0]


        ->  ptr_dirA<1,2>: Array of values that represent the directions of a number
            Example: ptr_dirA1 [3,0] , ptr_dirA2 [2,0] 

        ->  ptr_expA<1,2>: Array of values that represent the exponents of those directions
            Example: ptr_expA1 [1,0] , ptr_expA2 [1,0]

        ->  order:    Order of the OTI number that is being used.
            Example: 2

        -> ptr_mdirA<1,2,3>: Allocated arrays to handle the algorithm.

        -> ptr_mexpA1: Allocated array to handle the exponent of the algorithm.

        -> N:         Number of rows of the dirArray and expArray.
            Example: 9 
        -> error: Indicator to show if the result is valid or not.


    OUTPUTS:
        ->  The result is an uint64_t which corresponds to the index of the 
            multiplied indices.

            Example: 7 = c_multDirections(...)


    */
    // ************************************************************************************************

    // check thee order of the numbers
    uint64_t index = 0;

    uint8_t newOrder = c_sumUI8(ptr_expA1,order) + c_sumUI8(ptr_expA2,order);
    uint64_t index_1;
    uint64_t index_2;

    if( newOrder <= order ){

        // no notification required.
        (*error) = 0;

        // Map the direction arrays.

        c_mapDirArray( ptr_dirA1, ptr_dirA2, order, ptr_mdirA1, ptr_mdirA2, ptr_mapder);

        // Find index values

        index_1 =  c_convToIndex(ptr_mdirA1,ptr_expA1, order);
        index_2 =  c_convToIndex(ptr_mdirA2,ptr_expA2, order);

        // Find the resulting direction after multiplication

        index_1 +=  index_2; 

        // Retrieve the directions of the multiplied index.
        c_convToDirExp(index_1, order, ptr_mdirA1, ptr_mexpA1); 
        
        // remap the array to the original directions.
        c_reMapDirArray( ptr_mdirA1, ptr_mapder,  order,  ptr_mdirA1);

        // find the corresponding index of the result:
        index = c_binarySearch(  ptr_dirArray,  ptr_expArray,
                                   ptr_mdirA1,    ptr_mexpA1,  order,
                               N,  ptr_mdirA2,    ptr_mdirA3);

    }else{

        // Send back a signal to know the multiplication is not possible between this 
        // two directions.

        (*error) = 1;
    }

    return index;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_mapDirArray( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,
                    uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2, uint16_t* ptr_mapder) {
    /*
    c_mapDirArray( ptr_dirA1 , ptr_dirA2,       order,
                   ptr_mdirA2, ptr_mdirA2, ptr_mapder):

    Function that maps two direction arrays to a consecutive ordered 
    direction arrays starting from 1.

    INPUTS:
        -> ptr_dirA1 (order): Array of values that represent the directions of a number
            Example: [ 3, 8, 0, 0]

        -> ptr_dirA2 (order): Array of values that represent the exponents of those directions
            Example: [ 7,10, 0, 0]

        -> order:    Order of the OTI number that is being used.
            Example: 4 


    OUTPUTS:
        -> The result are 3 arrays:

            -> ptr_mdirA1 (order): Array of values with the corresponding mapped directions of array 
            dirA1.
            Example: [1, 3, 0, 0]

            -> ptr_mdirA2 (order): Array of values that represent the exponents of those directions
            Example: [2, 4, 0, 0]

            -> ptr_mapder (2 * order): Array of the corresponding (real) directions that correlates the mapped
            directions
            Example: [3,7,8,10,0,0,0,0]
    
    Note: All arrays must come already allocated.

    */
    // ************************************************************************************************

    uint8_t k = 0;
    uint8_t i;
    uint8_t j;
    uint8_t l;
    uint8_t n = 0;
    uint16_t m;

    // printArray16(ptr_dirA1,order);
    // Initialize the first mapped dirA

    for (i = 0; i<order ; i++){
        
        if(ptr_dirA1[i]!=0){

            m = i+1;
            ptr_mdirA1[i] = m;


        } else{
          
            ptr_mdirA1[i] = 0;

        }

    }

    // Check if the second array has some values that can improve the 
    // performance

    for(i = 0; i<order ; i++){

        if(ptr_dirA2[i]!=0){

            // Loop in the elements of dirA1
            for(l=n; l<order; l++){
                
                if (ptr_dirA1[l]!=0){

                    if(ptr_dirA2[i] < ptr_dirA1[l]){


                        k = ptr_mdirA1[l];

                        // Sum 1 to all elements in ptr_mdirA1 except the zeros
                        for(j = l; j<order ; j++){
                            
                            if(ptr_dirA1[j]!=0){
                      
                                ptr_mdirA1[j] += 1;
                            
                            } else{
                                
                                break;

                            }

                        }

                        n = l;
                        ptr_mdirA2[i] = k;
                        m += 1;
                        break;

                    }else if(ptr_dirA2[i] == ptr_dirA1[l]){
                      
                        k = ptr_mdirA1[l];
                        ptr_mdirA2[i] = k;
                        break;

                    }

                }else{
            
                    ptr_mdirA2[i] = m+1;
                    m+=1;
                    break;
                    
                }

                if (l==order-1){
                    ptr_mdirA2[i] = m+1;
                    m+=1;
                }

            }

        }else{

            ptr_mdirA2[i] = 0;

        }

    }


    // Find the equivalent mapder array:

    for(i = 0; i<order ; i++){
        
        if(ptr_dirA1[i]!=0){

            ptr_mapder[ptr_mdirA1[i]-1] = ptr_dirA1[i];

        }else{

            break;

        }

    }

    for(i = 0; i<order ; i++){
        
        if(ptr_dirA2[i]!=0){

            ptr_mapder[ptr_mdirA2[i]-1] = ptr_dirA2[i];

        }else{

            break;
            
        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint8_t c_sumUI8(uint8_t* ptr_,uint8_t n){
    /*

    c_sumUI8( ptr_, size):

    Function that sums all elements of array of unsigned integers of 8 bits of size n.

    */
    // ************************************************************************************************

    uint8_t sum_ = 0;
    uint8_t val;

    for (int i = 0; i<n ; i++){
        
        val = ptr_[i];

        if (val == 0){
            break;
        } else {
            sum_ += val;    
        }
        
    }

    return sum_;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_printArrayDBL(double* ptr_,uint64_t n){
    /*

    c_printArrayUI16( ptr_, size):

    Function that prints an array of unsigned integers of 64 bits of size n.

    */
    // ************************************************************************************************

    printf("[");

    for (uint64_t i = 0; i<n ; i++){

        printf(" %g,",ptr_[i]);
    }

    printf("]");

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_printArrayUI64(uint64_t* ptr_,uint64_t n){
    /*

    c_printArrayUI16( ptr_, size):

    Function that prints an array of unsigned integers of 64 bits of size n.

    */
    // ************************************************************************************************

    printf("[");

    for (uint64_t i = 0; i<n ; i++){

        printf(" %llu,",ptr_[i]);
    }

    printf("]");

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_printArrayUI16(uint16_t* ptr_,uint8_t n){
    /*

    c_printArrayUI16( ptr_, size):

    Function that prints an array of unsigned integers of 16 bits of size n.

    */
    // ************************************************************************************************

    printf("[");

    for (int i = 0; i<n ; i++){

        printf(" %hu,",ptr_[i]);
    }

    printf("]");

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_printArrayUI8(uint8_t* ptr_,uint8_t n){
    /*

    c_printArrayUI16( ptr_, size):

    Function that prints an array of unsigned integers of 16 bits of size n.

    */

    printf("[");

    for (int i = 0; i<n ; i++){

        printf(" %hhu,",ptr_[i]);
    }

    printf("]");

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_reMapDirArray( uint16_t*  ptr_mdirA1, uint16_t* ptr_mapder, uint8_t order,
                      uint16_t* ptr_dirA1) {

    /*
    c_reMapDirArray( ptr_mdirA1 , ptr_mdirA2, ptr_mapder,
                   ptr_dir1, ptr_dirA2 ):

    Function that maps two direction arrays to a consecutive ordered 
    direction arrays starting from 1.

    INPUTS:
        -> ptr_mdirA1 (order): Array of values with the corresponding mapped directions of array 
            dirA1.
            Example: [1, 3, 0, 0]

            -> ptr_mdirA2 (order): Array of values with the corresponding mapped directions of array 
            dirA2.
            Example: [2, 4, 0, 0]

        -> ptr_mapder (2 * order): Array of the corresponding (real) directions that correlates the mapped
            directions
            Example: [3,7,8,10,0,0,0,0]

        -> order:    Order of the OTI number that is being used.
            Example: 4 



    OUTPUTS:
        -> The result are 3 arrays:

            -> ptr_dirA1 (order): Array of values that represent the directions of a number
            Example: [ 3, 8, 0, 0]

            -> ptr_dirA2 (order): Array of values that represent the directions of a number
            Example: [ 7,10, 0, 0]

            
    
    Note: All arrays must come already allocated.

    */
    // ************************************************************************************************

    int i;

    for(i =0; i<order; i++){
        
        if( ptr_mdirA1[i]!= 0 ) {

            ptr_dirA1[i] = ptr_mapder[ptr_mdirA1[i]-1];

        }else{

            ptr_dirA1[i] = 0;

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_convToIndex(uint16_t* ptr_dirA,uint8_t* ptr_expA, uint8_t order) {
    /*
    c_convToIndex( ptr_dirA, ptr_expA, order):

    Function that converts a set of exponents and directions to a corresponding 
    integer value.

    INPUTS:
        -> ptr_dirA: Array of values that represent the directions of a number
            Example: [3,4]

        -> ptr_expA: Array of values that represent the exponents of those directions
            Example: [1,2]

        -> order:    Order of the OTI number that is being used.
            Example: 3 


    OUTPUTS:
        -> The result is an uint64_t with the following formula

                \sum{expA[i]*(order+1)^(dirA[i]-1)}

            Example: 144 = c_convToIndex([3,4],[1,2], 3)


    */
    // ************************************************************************************************

    uint64_t index = 0;
    uint64_t base = order+1;
    uint64_t multiple;

    for (uint8_t i = 0; i<order ; i++){

        multiple = ptr_expA[i];

        if (multiple != 0){

            index += multiple*c_fastpow(base,ptr_dirA[i]-1);

        }else{

            break;

        }

    }

    return index;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_convToDirExp(uint64_t index, uint8_t order, uint16_t* ptr_dirA, uint8_t* ptr_expA) {
    /*
    c_convToDirExp( ptr_dirA, ptr_expA, order):

    Function that converts a set of exponents and directions to a corresponding 
    integer value.

    INPUTS:
        -> index:    Integer form of the sets of directions and exponents.
            Example: 24

        -> order:    Order of the OTI number that is being used.
            Example: 3 

        -> ptr_expA: Array of values that represent the exponents of those directions
            Example: [1,2]

        


    OUTPUTS:
        -> The result is an uint64_t with the following formula

                \sum{expA[i]*(order+1)^(dirA[i]-1)}

            Example: 144 = c_convToIndex([3,4],[1,2], 3)


    */
    // ************************************************************************************************

    uint64_t indx = index;

    uint8_t  i = 0;
    uint8_t  dir = 1;
    uint8_t  exp;
    

    while (indx != 0){

        exp  = indx%(order+1);
        indx = indx/(order+1);

        if(exp!=0){

            ptr_dirA[i] = dir;
            ptr_expA[i] = exp;
            i++; 

        }

        dir++;  

    }
    if (i<order){
        ptr_dirA[i] = 0;
        ptr_expA[i] = 0;
    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_binarySearchUI64(  uint64_t* ptr_indxArray, uint64_t indx,uint64_t  N){          
    /*
    c_binarySearchUI64( ptr_indxArray, indx, N):

    Function that applies binary search to find what is the position at which the 
    indx belongs in indxArray. However, if indx does not belong to indxArray, it will tell 
    at which position it must be inserted.

    INPUTS:
        
        -> ptr_indxArray[N]:   Array with indices, in ascending order. 
            Example: [1,  
                      4,
                      5,
                      6,
                      9,
                      20,
                      25,
                      45,
                      50]

        -> indx:    Value to seek in indxArray 
            Example: 5

        -> N:       Number of elements in indxArray
            Example: 9

    OUTPUTS:
        -> The result is the index that indicates where the indx value exist in indxArray,
        or where should it be inserted
            Example: 2 = c_binarySearchUI64( ptr_indxArray, indx, N)

    */ 
    // ************************************************************************************************

    
    uint64_t min_i = 0;
    uint64_t max_i = N;
    uint64_t pos = min_i+(max_i-min_i)/2; // Automatically truncates the result.

    // Case length 0.
    if(min_i==max_i){

        return 0;

    }
    
    // !!!!! Not robust enough to handle order 1!!!!
    if (indx <= ptr_indxArray[min_i]){
        
        return min_i;

    }else if (indx > ptr_indxArray[max_i-1]){

        return max_i;
    }
    
    while(  (max_i-min_i)>2  ){

        
        if (indx>ptr_indxArray[pos]){

            min_i = pos;

        }else{

            max_i = pos+1;

        }
        // Convert both arrays to 

        pos = min_i+(max_i-min_i)/2 ;

    }

    return pos;


}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
uint64_t c_multDirections_dH(uint64_t indx1m1, uint64_t indx2m1, directionHelper* p_dH, 
                             uint8_t* error ){
    /*
    c_multDirections(ptr_dirA1, ptr_expA2, ptr_dirA1, ptr_expA2, order):

    Function that multiplies two directions i,j.

    INPUTS:

        -> indx1m1:   Index of direction that will be multiplied

        -> indx2m1:   Index of direction that will be multiplied

        ->  p_dH:     Address of the direction helper for indx1m1 and indx2xm1.
            Example: 2

        -> error: Address of error flag to get the multiplication validity. 0:   valid multiplication.
                                                                            1: invalid multiplication.


    OUTPUTS:
        ->  The result is an uint64_t which corresponds to the index of the 
            multiplied indices.


    */
    // ************************************************************************************************

    // check thee order of the numbers
    uint64_t index = 0;
    
    // Get once the pointers
    uint8_t  order = p_dH->order;
    uint16_t* ptr_dirA1 = &p_dH->p_dirA[indx1m1*order];
    uint8_t*  ptr_expA1 = &p_dH->p_expA[indx1m1*order];
    uint16_t* ptr_dirA2 = &p_dH->p_dirA[indx2m1*order];
    uint8_t*  ptr_expA2 = &p_dH->p_expA[indx2m1*order];
    uint16_t* ptr_mdirA1= p_dH->p_mdirA;
    uint8_t*  ptr_mexpA1= p_dH->p_mexpA;
    uint16_t* ptr_mdirA2= &p_dH->p_mdirA[order];
    uint16_t* ptr_mdirA3= &p_dH->p_mdirA[2*order];
    uint16_t* ptr_mapder= p_dH->p_mapder;


    uint8_t newOrder = c_sumUI8(ptr_expA1,order) + c_sumUI8(ptr_expA2,order);
    uint64_t index_1;
    uint64_t index_2;

    if( newOrder <= order ){

        // no notification required.
        (*error) = 0;

        // Map the direction arrays.

        c_mapDirArray( ptr_dirA1, ptr_dirA2, order, ptr_mdirA1, ptr_mdirA2, ptr_mapder);

        // Find index values

        index_1 =  c_convToIndex(ptr_mdirA1,ptr_expA1, order);
        index_2 =  c_convToIndex(ptr_mdirA2,ptr_expA2, order);

        // Find the resulting direction after multiplication

        index_1 +=  index_2;

        // Retrieve the directions of the multiplied index.
        c_convToDirExp(index_1, order, ptr_mdirA1, ptr_mexpA1); 

        // remap the array to the original directions.
        c_reMapDirArray( ptr_mdirA1, ptr_mapder,  order,  ptr_mdirA1);

        // find the corresponding index of the result:
        index = c_binarySearch(  p_dH->p_dirA,  p_dH->p_expA,
                                   ptr_mdirA1,    ptr_mexpA1,  order,
                      p_dH->Ndir,  ptr_mdirA2,    ptr_mdirA3);

    }else{

        // Send back a signal to know the multiplication is not possible between this 
        // two directions.

        (*error) = 1;
    }

    return index;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
uint64_t c_binarySearch_dH(  uint16_t* p_dirA,   uint8_t* p_expA,  directionHelper* p_dH){          
    /*
    dirBinarySearch( c_binarySearch( ptr_dirA, ptr_expA, dHelp):

    Applies the binary search to find what is the position at which the 
    pair dirs,exps exist on an array of size N that contains it.

    INPUTS:
        
        -> ptr_dirA:    Array of values that represent the directions of a number
            Example: [3,0]

        -> ptr_expA:    Array of values that represent the exponents of those directions
            Example: [1,0]

        -> dHelp:     Address of direction helper.


    OUTPUTS:
        -> The result is the index that indicates the sequential order at which the dirA, expA occurs
        

            Example: For the values shown as examples in inputs (order 2),

                >> 5 = dirBinarySearch(...)

    NOTE: All arrays must come allocated.
    */ 
    // ************************************************************************************************

    
    uint64_t min_i = 0 ;
    uint64_t max_i = p_dH->Ndir;
    uint64_t pos = min_i+(max_i-min_i)/2 ; // Automatically truncates the result.

    uint64_t index_look;
    uint64_t index_array;

    uint8_t order = p_dH->order;
    uint16_t* p_mdirA1 = &p_dH->p_mdirA[    0];
    // uint16_t*  p_dirAh;   // view of helper's direction array
    // uint8_t*   p_expAh;   // view of helper's exponent array
    uint16_t* p_mdirA2 = &p_dH->p_mdirA[order];


    // Map the direction arrays.
    mapDirArrayNoMapderFast( p_dH->p_dirA, p_dirA, order, 
                        p_mdirA1, p_mdirA2);

    // ptr_mdirA2 -> The arrays to be looked into dirArray
    index_look  = c_convToIndex(p_mdirA2, p_expA, order);
    
    // !!!!! Not robust enough to handle order 1!!!!
    if (index_look == 1){
        
        return 0;

    }
    
    while(  (max_i-min_i)>2  ){

        // Map the direction arrays.
        mapDirArrayNoMapderFast( &p_dH->p_dirA[pos*order], p_dirA, order, 
                                p_mdirA1, p_mdirA2); 

        // ptr_mdirA1 -> Global array
        index_array = c_convToIndex(p_mdirA1, &p_dH->p_expA[pos*order], order);

        // ptr_mdirA2 -> The arrays to be looked into dirArray
        index_look  = c_convToIndex(p_mdirA2, p_expA, order);

        if (index_look > index_array){

            min_i = pos;

        }else{

            max_i = pos+1;

        }
        
        pos = min_i+ (max_i-min_i) /2 ;
    }

    return pos;


}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
uint64_t c_binarySearch(  uint16_t* ptr_dirArray, uint8_t* ptr_expArray,
                          uint16_t* ptr_dirA,     uint8_t* ptr_expA,     uint8_t order,
                          uint64_t  N, uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2){          
    /*
    c_binarySearch( c_binarySearch(  ptr_dirArray, ptr_expArray,
                                     ptr_dirA,     ptr_expA,      order,
                                     N,            ptr_mdirA1,    ptr_mdirA2):

    Function applies the binary search to find what is the position at which the 
    pair dirs,exps exist on an array of size N that contains it.

    INPUTS:
        
        -> ptr_dirArray[N,order]:   Array of all possible combinations of directions 
                                    for m number of base directions.
            Example: [1,0,   
                      1,0,
                      2,0,
                      1,2,
                      2,0,
                      3,0,   // for m=3
                      1,3,
                      2,3,
                      3,0]

        -> ptr_expArray[N,order]:   Array of all possible combinations of exponents, 
                                    associated to those directions.
            Example: [1,0,
                      2,0,   
                      1,0,
                      1,1,   // the sum of each row should always be \leq order.
                      2,0,
                      1,0,
                      1,1,
                      1,1,
                      2,0]


        -> ptr_dirA:    Array of values that represent the directions of a number
            Example: [3,0]

        -> ptr_expA:    Array of values that represent the exponents of those directions
            Example: [1,0]

        -> order:       Order of the OTI number that is being used.
            Example: 2 (as in the example) 

        -> N:           number of columns of the dirArray and expArray.
            Example: 9 

        -> ptr_mdirA1,ptr_mdirA2: Allocated arrays to handle the algorithm.


    OUTPUTS:
        -> The result is the index that indicates where the combination dirA,expA occurs:

            Example: For the values shown as examples in inputs,

                >> 5 = c_binarySearch(...)

    NOTE: All arrays must come allocated.
    */ 
    // ************************************************************************************************

    
    uint64_t min_i = 0 ;
    uint64_t max_i = N;
    uint64_t pos = min_i+(max_i-min_i)/2 ; // Automatically truncates the result.

    uint64_t index_look;
    uint64_t index_array;

    // Map the direction arrays.
    c_mapDirArrayNoMapder( &ptr_dirArray[0], ptr_dirA, order, ptr_mdirA1, ptr_mdirA2);

    // ptr_mdirA2 -> The arrays to be looked into dirArray
    index_look  = c_convToIndex(ptr_mdirA2, ptr_expA, order);

    
    // !!!!! Not robust enough to handle order 1!!!!
    if (index_look == 1){
        
        return 0;

    }
    
    while(  (max_i-min_i)>2  ){

        // Map the direction arrays.
        c_mapDirArrayNoMapder( &ptr_dirArray[pos*order], ptr_dirA, order, ptr_mdirA1, ptr_mdirA2);

        // ptr_mdirA1 -> Global array
        index_array = c_convToIndex(ptr_mdirA1, &ptr_expArray[pos*order], order);

        // ptr_mdirA2 -> The arrays to be looked into dirArray
        index_look  = c_convToIndex(ptr_mdirA2, ptr_expA, order);

        if (index_look>index_array){

            min_i = pos;

        }else{

            max_i = pos+1;

        }
        // Convert both arrays to 

        pos = min_i+(max_i-min_i)/2 ;

    }

    return pos;


}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void* c_malloc_ptr(uint64_t numberOfElements, uint64_t sizeOfElement){
  /*
    c_malloc_ptr( nelems,  sizeOfElement):

    Function that allocates memory in the system according to the given data.

    INPUTS:
        
        -> numberOfElements Number of elements to be allocated.

        -> sizeOfElement:  Size in bytes of each element to be allocated.

    OUTPUTS:
        -> pointer with the memory allocated

    NOTE: If the memory is not allocated, then the program exits and prints an error message in console.
    */ 
    // ************************************************************************************************
    
    void* res;

    res = malloc( numberOfElements * sizeOfElement);
    
    if (res == NULL){
        printf("-MemoryError-: Can not allocate %llu elements of size %llu for a total of %llu bytes.\n",
            numberOfElements, sizeOfElement, numberOfElements*sizeOfElement );
        exit(1);
    }

    return res;

}  
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_free_ptr(void** ptrAddress){
  /*
    cc_free_ptr( ptr ):

    Frees memory and sets the value of the pointer to NULL.

    INPUTS:
        
        -> ptrAddress: Address of the pointer.

    
    */ 
    // ************************************************************************************************
    
    if(*ptrAddress != NULL){

        free( *ptrAddress );
        *ptrAddress = NULL; 

    }    

}  
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// -----------------------------------     END FUNCTIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------


#endif