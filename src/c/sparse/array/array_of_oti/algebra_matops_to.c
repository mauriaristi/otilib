

// 2. Array operations.
// 2.1. Inner product.
// 2.2. Transpose.
// 2.3. Inversion.
// 2.4. Determinant.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
void arrso_matmul_OO_to(arrso_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){

    uint64_t i, j, k;
    sotinum_t tmp;

    // check for dimensions.
    arrso_dimCheck_OO_matmul(arr1, arr2, res);

    // Extract temporal 5.
    tmp = soti_get_tmp( 5, dhl);

    for ( i = 0; i < arr1->nrows; i++){
        
        for( j = 0; j < arr2->ncols; j++){

            soti_setFromReal( 0.0, &tmp, dhl);

            for( k = 0; k < arr1->ncols; k++){

                soti_gem_oo_to( &arr1->p_data[ k + i * arr1->ncols ],
                                &arr2->p_data[ j + k * arr2->ncols ],
                                &tmp, &tmp, dhl);
                   
            }

            arrso_set_item_ij_o( &tmp, i, j, res, dhl);

        }

    }
    

}
// ----------------------------------------------------------------------------------------------------


// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
void arrso_matmul_OR(arrso_t* arr1, darr_t* arr2, arrso_t* res, dhelpl_t dhl){
        
    uint64_t i, j, k;
    sotinum_t tmp;

    // check for dimensions.
    arrso_dimCheck_RO_matmul(arr1, arr2, res);

    // Extract temporal 5.
    tmp = soti_get_tmp( 5, dhl);

    for ( i = 0; i < arr1->nrows; i++){
        
        for( j = 0; j < arr2->ncols; j++){

            soti_setFromReal( 0.0, &tmp, dhl);

            for( k = 0; k < arr1->ncols; k++){

                soti_gem_ro_to(  arr2->p_data[ j + k * arr2->ncols ],
                                &arr1->p_data[ k + i * arr1->ncols ],
                                &tmp, dhl);
                   
            }

            arrso_set_item_ij_o( &tmp, i, j, res, dhl);

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
void arrso_matmul_RO_to(darr_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
        
    

}
// ----------------------------------------------------------------------------------------------------

















// // 2.2. Transpose.
// // ****************************************************************************************************
// void arrso_transpose(arrso_t* arr1, arrso_t* aRes){
    
//     uint64_t i, j ;



//     for (i=0; i<arr1->nrows; i++){

//         for (j=0; j<arr1->ncols; j++){
            
//             soti_copy(
//                 &tmp, 
//                 &arr1->p_data[  j + i*arr1->ncols  ]);

//             arrso_setItemOTI( &tmp, j, i, aRes);

//         }

//     }
    

// }
// // ----------------------------------------------------------------------------------------------------























// // 2.3. Inversion.
// // ****************************************************************************************************
// void arrso_invert(arrso_t* arr1, arrso_t* aRes, dhelpl_t dhl){
    
//     sotinum_t detInv,tmp1, tmp2, tmp;
//     arrso_t tmpA1;

//     if (arr1->ncols != arr1->nrows){
//         printf("--- DimensionError in matrix inverse. Only square matrices are invertible. ---\n");
//         exit(1);
//     }

//     if        (arr1->ncols == 1){

//         if (aRes->p_data == NULL){
    
//             arrso_zeros( aRes, arr1->ncols, arr1->nrows, arr1->order);

//         }

//         soti_pow(&arr1->p_data[0], -1.0, dhl, &tmp);

//         arrso_setItemOTI_indx(&tmp,0,aRes);


//     } else if (arr1->ncols == 2){

//         if (aRes->p_data == NULL){
    
//             arrso_zeros( aRes, arr1->ncols, arr1->nrows, arr1->order);

//         }

//         arrso_det( arr1, &tmp1, dhl); // Get determinant.
//         soti_pow(&tmp1, -1.0, dhl,&detInv);
//         soti_free(&tmp1);

//         // Set position 0,0
//         soti_mul(
//             &arr1->p_data[3],
//             &detInv,
//             &tmp,
//             dhl);
//         arrso_setItemOTI_indx(&tmp,0,aRes);


//         // Set position 0,1
//         soti_neg(&arr1->p_data[1],&tmp1);
//         soti_mul(
//             &tmp1,
//             &detInv,
//             &tmp,
//             dhl);
//         soti_free(&tmp1);
//         arrso_setItemOTI_indx(&tmp,1,aRes);

        
//         // Set position 1,0
//         soti_neg(&arr1->p_data[2],&tmp1);
//         soti_mul(
//             &tmp1,
//             &detInv,
//             &tmp,
//             dhl);
//         soti_free(&tmp1);
//         arrso_setItemOTI_indx(&tmp,2,aRes);


//         // Set position 1,1
//         soti_mul(
//             &arr1->p_data[0],
//             &detInv,
//             &tmp,
//             dhl);
//         arrso_setItemOTI_indx(&tmp,3,aRes);

//         soti_free(&detInv);
        


//     } else if (arr1->ncols == 3){

//         arrso_zeros( &tmpA1, 2, 2, arr1->order);

//         if (aRes->p_data == NULL){
//             arrso_zeros( aRes, arr1->ncols, arr1->nrows, arr1->order);
//         }

//         arrso_det( arr1, &tmp1, dhl); // Get determinant.
//         soti_pow(&tmp1, -1.0, dhl, &detInv);
//         soti_free(&tmp1);



//         // Set position 0,0
//         tmpA1.p_data[0] = arr1->p_data[4];
//         tmpA1.p_data[1] = arr1->p_data[5];
//         tmpA1.p_data[2] = arr1->p_data[7];
//         tmpA1.p_data[3] = arr1->p_data[8];
//         arrso_det( &tmpA1, &tmp2, dhl);
//         soti_mul(
//             &tmp2,
//             &detInv,
//             &tmp,
//             dhl);
//         soti_free(&tmp2);
//         arrso_setItemOTI_indx(&tmp,0,aRes);

//         // Set position 0,1
//         tmpA1.p_data[0] = arr1->p_data[2];
//         tmpA1.p_data[1] = arr1->p_data[1];
//         tmpA1.p_data[2] = arr1->p_data[8];
//         tmpA1.p_data[3] = arr1->p_data[7];
//         arrso_det( &tmpA1, &tmp2, dhl);
//         soti_mul(
//             &tmp2,
//             &detInv,
//             &tmp,
//             dhl);
//         soti_free(&tmp2);
//         arrso_setItemOTI_indx(&tmp,1,aRes);

//         // Set position 0,2
//         tmpA1.p_data[0] = arr1->p_data[1];
//         tmpA1.p_data[1] = arr1->p_data[2];
//         tmpA1.p_data[2] = arr1->p_data[4];
//         tmpA1.p_data[3] = arr1->p_data[5];
//         arrso_det( &tmpA1, &tmp2, dhl);
//         soti_mul(
//             &tmp2,
//             &detInv,
//             &tmp,
//             dhl);
//         soti_free(&tmp2);
//         arrso_setItemOTI_indx(&tmp,2,aRes);




//         // Set position 1,0
//         tmpA1.p_data[0] = arr1->p_data[5];
//         tmpA1.p_data[1] = arr1->p_data[3];
//         tmpA1.p_data[2] = arr1->p_data[8];
//         tmpA1.p_data[3] = arr1->p_data[6];
//         arrso_det( &tmpA1, &tmp2, dhl);
//         soti_mul(
//             &tmp2,
//             &detInv,
//             &tmp,
//             dhl);
//         soti_free(&tmp2);
//         arrso_setItemOTI_indx(&tmp,3,aRes);

//         // Set position 1,1
//         tmpA1.p_data[0] = arr1->p_data[0];
//         tmpA1.p_data[1] = arr1->p_data[2];
//         tmpA1.p_data[2] = arr1->p_data[6];
//         tmpA1.p_data[3] = arr1->p_data[8];
//         arrso_det( &tmpA1, &tmp2, dhl);
//         soti_mul(
//             &tmp2,
//             &detInv,
//             &tmp,
//             dhl);
//         soti_free(&tmp2);
//         arrso_setItemOTI_indx(&tmp,4,aRes);

//         // Set position 1,2
//         tmpA1.p_data[0] = arr1->p_data[2];
//         tmpA1.p_data[1] = arr1->p_data[0];
//         tmpA1.p_data[2] = arr1->p_data[5];
//         tmpA1.p_data[3] = arr1->p_data[3];
//         arrso_det( &tmpA1, &tmp2, dhl);
//         soti_mul(
//             &tmp2,
//             &detInv,
//             &tmp,
//             dhl);
//         soti_free(&tmp2);
//         arrso_setItemOTI_indx(&tmp,5,aRes);




//         // Set position 2,0
//         tmpA1.p_data[0] = arr1->p_data[3];
//         tmpA1.p_data[1] = arr1->p_data[4];
//         tmpA1.p_data[2] = arr1->p_data[6];
//         tmpA1.p_data[3] = arr1->p_data[7];
//         arrso_det( &tmpA1, &tmp2, dhl);
//         soti_mul(
//             &tmp2,
//             &detInv,
//             &tmp,
//             dhl);
//         soti_free(&tmp2);
//         arrso_setItemOTI_indx(&tmp,6,aRes);

//         // Set position 2,1
//         tmpA1.p_data[0] = arr1->p_data[1];
//         tmpA1.p_data[1] = arr1->p_data[0];
//         tmpA1.p_data[2] = arr1->p_data[7];
//         tmpA1.p_data[3] = arr1->p_data[6];
//         arrso_det( &tmpA1, &tmp2, dhl);
//         soti_mul(
//             &tmp2,
//             &detInv,
//             &tmp,
//             dhl);
//         soti_free(&tmp2);
//         arrso_setItemOTI_indx(&tmp,7,aRes);

//         // Set position 2,2
//         tmpA1.p_data[0] = arr1->p_data[0];
//         tmpA1.p_data[1] = arr1->p_data[1];
//         tmpA1.p_data[2] = arr1->p_data[3];
//         tmpA1.p_data[3] = arr1->p_data[4];
//         arrso_det( &tmpA1, &tmp2, dhl);
//         soti_mul(
//             &tmp2,
//             &detInv,
//             &tmp,
//             dhl);
//         soti_free(&tmp2);
//         arrso_setItemOTI_indx(&tmp,8,aRes);


//         soti_free(&detInv);
//         free(tmpA1.p_data);


//     }
    

// }
// // ----------------------------------------------------------------------------------------------------






















// // 2.4. Determinant.

// // ****************************************************************************************************
// void arrso_det(arrso_t* arr1, sotinum_t* p_res, dhelpl_t dhl){
    
//     uint64_t i, j ;
//     sotinum_t tmp1, tmp2, tmp3;

//     if (arr1->ncols != arr1->nrows){
//         printf("--- DimensionError in matrix determinant. Only square matrices are valid. ---\n");
//         exit(1);
//     }



//     if ( arr1->ncols == 1 ){

//         soti_copy(p_res, &arr1->p_data[0]);

//     } else if (arr1->ncols == 2){



//         soti_mul(
//             &arr1->p_data[0],
//             &arr1->p_data[3],
//             &tmp1,
//             dhl   ); 

//         soti_mul(
//             &arr1->p_data[1],
//             &arr1->p_data[2],
//             &tmp2,
//             dhl   ); 

//         soti_sub(
//             &tmp1,
//             &tmp2,
//             p_res,
//             dhl);

//         soti_free(&tmp1);
//         soti_free(&tmp2);

//     } else if (arr1->ncols == 3){

//         soti_createEmpty(p_res,0,arr1->order); // Initialize as zero.

//         for (j=0; j<arr1->ncols; j++){
            
//             soti_copy(&tmp1,&arr1->p_data[j]);
            
            
//             for (i=1; i<arr1->nrows; i++){        
                
//                 tmp2 = tmp1;
                
//                 soti_mul(
//                     &arr1->p_data[ ( (i+j)%arr1->ncols ) + i*arr1->ncols],
//                     &tmp2,
//                     &tmp1,
//                     dhl   );  

//                 soti_free(&tmp2);

//             }

//             tmp3 = *p_res;
//             soti_sum(&tmp3,&tmp1,p_res,dhl);
            
//             soti_free(&tmp1);
//             soti_free(&tmp3);

//         }

//         for (j=0; j<arr1->ncols; j++){
            
//             soti_copy(&tmp1,&arr1->p_data[arr1->ncols-1-j]);
            
//             for (i=1; i<arr1->nrows; i++){        
                
//                 tmp2 = tmp1;
                
//                 soti_mul(
//                     &arr1->p_data[ (arr1->ncols-1 - (i+j)%arr1->ncols ) + i*arr1->ncols],
//                     &tmp2,
//                     &tmp1,
//                     dhl   );    

//                 soti_free(&tmp2);

//             }

//             tmp3 = *p_res;
//             soti_sub(&tmp3,&tmp1,p_res,dhl);
            
//             soti_free(&tmp1);
//             soti_free(&tmp3);

//         }
//     }
// }
// // ----------------------------------------------------------------------------------------------------














