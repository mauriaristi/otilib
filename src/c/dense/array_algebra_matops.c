

// 2. Array operations.


// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarr_t oarr_matmul_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl){

    oarr_t res = oarr_zeros(lhs->nrows, lhs->ncols,  lhs->nbases, lhs->order, dhl);    

    ord_t ord_res, ord_mul1;
    
    // First multiply both real parts.

    // lhs real part times rhs real part.
    dhelp_oarr_matmul_RR(lhs, rhs, &res, dhl);

    // Loop to get each resulting order.
    for (  ord_res = 1; ord_res <= res.order; ord_res++){

        // Multiply  lhs(re) x rhs(ord_res)
        dhelp_oarr_matmul_RI( lhs, rhs, ord_res, &res, dhl);

        // Multiply  lhs(ord_res) x rhs(re)
        dhelp_oarr_matmul_IR( lhs, rhs, ord_res, &res, dhl);

        // Loop for every combination of orders such that the resulting order is ord_res.
        for ( ord_mul1 = 1; ord_mul1 <= ord_res/2; ord_mul1++){

            ord_t ord_mul2 = ord_res - ord_mul1;

            dhelp_oarr_matmul_II(lhs, ord_mul1, rhs, ord_mul2, &res, dhl);

            // In the case that the orders are the same, the operation is not the same.
            // It might be different in the case of matmul.
            if (ord_mul1 != ord_mul2){

                dhelp_oarr_matmul_II(lhs, ord_mul2, rhs, ord_mul1, &res, dhl);

            }  

        }
        

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
void oarr_matmul_OR(oarr_t* arr1, darray_t* arr2, oarr_t* aRes, 
                        dhelpl_t dhl){
        
    uint64_t i, j, k;
    otinum_t tmp1, tmp2, tmp3;
    // Check correctness of dimensions:
    if( (arr1->nrows!=arr2->ncols) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (aRes->p_data == NULL){
        oarr_zeros( aRes, arr1->nrows, arr2->ncols, arr1->order);
    }
    for (i=0; i<arr1->nrows; i++){
        
        for(j=0; j<arr2->ncols; j++){
            
            oti_createEmpty(&tmp1, 0, arr1->order);

            for(k=0; k<arr1->ncols; k++){

                oti_mulf(
                    &arr1->p_data[k+i*arr1->ncols]  ,
                     arr2->p_data[j+k*arr2->ncols]  ,
                    &tmp3);

                tmp2 = tmp1; // Copy all information between elements
                
                // Sum
                oti_sum(&tmp2,&tmp3,&tmp1,dhl);

                // Free memory ...
                oti_free(&tmp2);
                oti_free(&tmp3);

            }

            oarr_setItemOTI( &tmp1, i, j, aRes);

        }

    }
    

}
// ----------------------------------------------------------------------------------------------------


// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
void oarr_matmul_RO(darray_t* arr1, oarr_t* arr2, oarr_t* aRes, 
                        dhelpl_t dhl){
        
    uint64_t i, j, k;
    otinum_t tmp1, tmp2, tmp3;
    // Check correctness of dimensions:
    if( (arr1->ncols!=arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }
    if (aRes->p_data == NULL){
        oarr_zeros( aRes, arr1->nrows, arr2->ncols, arr2->order);
    }
    for (i=0; i<arr1->nrows; i++){
        
        for(j=0; j<arr2->ncols; j++){
            
            oti_createEmpty(&tmp1, 0, arr2->order);

            for(k=0; k<arr1->ncols; k++){

                oti_mulf(
                    &arr2->p_data[k+i*arr1->ncols]  ,
                     arr1->p_data[j+k*arr2->ncols]  ,
                    &tmp3);

                tmp2 = tmp1; // Copy all information between elements
                
                // Sum
                oti_sum(&tmp2,&tmp3,&tmp1,dhl);

                // Free memory ...
                oti_free(&tmp2);
                oti_free(&tmp3);

            }
            
            oarr_setItemOTI( &tmp1, i, j, aRes);

        }

    }
    

}
// ----------------------------------------------------------------------------------------------------

















// 2.2. Transpose.
// ****************************************************************************************************
void oarr_transpose(oarr_t* arr1, oarr_t* aRes){
    
    uint64_t i, j ;
    otinum_t tmp;

    if (aRes->p_data == NULL){
        oarr_zeros( aRes, arr1->nrows, arr1->ncols, arr1->order);
    }

    for (i=0; i<arr1->nrows; i++){

        for (j=0; j<arr1->ncols; j++){
            
            oti_copy(
                &tmp, 
                &arr1->p_data[  j + i*arr1->ncols  ]);

            oarr_setItemOTI( &tmp, j, i, aRes);

        }

    }
    

}
// ----------------------------------------------------------------------------------------------------























// 2.3. Inversion.
// ****************************************************************************************************
void oarr_invert(oarr_t* arr1, oarr_t* aRes, dhelpl_t dhl){
    
    otinum_t detInv,tmp1, tmp2, tmp;
    oarr_t tmpA1;

    if (arr1->ncols != arr1->nrows){
        printf("--- DimensionError in matrix inverse. Only square matrices are invertible. ---\n");
        exit(1);
    }

    if        (arr1->ncols == 1){

        if (aRes->p_data == NULL){
    
            oarr_zeros( aRes, arr1->ncols, arr1->nrows, arr1->order);

        }

        oti_pow(&arr1->p_data[0], -1.0, dhl, &tmp);

        oarr_setItemOTI_indx(&tmp,0,aRes);


    } else if (arr1->ncols == 2){

        if (aRes->p_data == NULL){
    
            oarr_zeros( aRes, arr1->ncols, arr1->nrows, arr1->order);

        }

        oarr_det( arr1, &tmp1, dhl); // Get determinant.
        oti_pow(&tmp1, -1.0, dhl,&detInv);
        oti_free(&tmp1);

        // Set position 0,0
        oti_mul(
            &arr1->p_data[3],
            &detInv,
            &tmp,
            dhl);
        oarr_setItemOTI_indx(&tmp,0,aRes);


        // Set position 0,1
        oti_neg(&arr1->p_data[1],&tmp1);
        oti_mul(
            &tmp1,
            &detInv,
            &tmp,
            dhl);
        oti_free(&tmp1);
        oarr_setItemOTI_indx(&tmp,1,aRes);

        
        // Set position 1,0
        oti_neg(&arr1->p_data[2],&tmp1);
        oti_mul(
            &tmp1,
            &detInv,
            &tmp,
            dhl);
        oti_free(&tmp1);
        oarr_setItemOTI_indx(&tmp,2,aRes);


        // Set position 1,1
        oti_mul(
            &arr1->p_data[0],
            &detInv,
            &tmp,
            dhl);
        oarr_setItemOTI_indx(&tmp,3,aRes);

        oti_free(&detInv);
        


    } else if (arr1->ncols == 3){

        oarr_zeros( &tmpA1, 2, 2, arr1->order);

        if (aRes->p_data == NULL){
            oarr_zeros( aRes, arr1->ncols, arr1->nrows, arr1->order);
        }

        oarr_det( arr1, &tmp1, dhl); // Get determinant.
        oti_pow(&tmp1, -1.0, dhl, &detInv);
        oti_free(&tmp1);



        // Set position 0,0
        tmpA1.p_data[0] = arr1->p_data[4];
        tmpA1.p_data[1] = arr1->p_data[5];
        tmpA1.p_data[2] = arr1->p_data[7];
        tmpA1.p_data[3] = arr1->p_data[8];
        oarr_det( &tmpA1, &tmp2, dhl);
        oti_mul(
            &tmp2,
            &detInv,
            &tmp,
            dhl);
        oti_free(&tmp2);
        oarr_setItemOTI_indx(&tmp,0,aRes);

        // Set position 0,1
        tmpA1.p_data[0] = arr1->p_data[2];
        tmpA1.p_data[1] = arr1->p_data[1];
        tmpA1.p_data[2] = arr1->p_data[8];
        tmpA1.p_data[3] = arr1->p_data[7];
        oarr_det( &tmpA1, &tmp2, dhl);
        oti_mul(
            &tmp2,
            &detInv,
            &tmp,
            dhl);
        oti_free(&tmp2);
        oarr_setItemOTI_indx(&tmp,1,aRes);

        // Set position 0,2
        tmpA1.p_data[0] = arr1->p_data[1];
        tmpA1.p_data[1] = arr1->p_data[2];
        tmpA1.p_data[2] = arr1->p_data[4];
        tmpA1.p_data[3] = arr1->p_data[5];
        oarr_det( &tmpA1, &tmp2, dhl);
        oti_mul(
            &tmp2,
            &detInv,
            &tmp,
            dhl);
        oti_free(&tmp2);
        oarr_setItemOTI_indx(&tmp,2,aRes);




        // Set position 1,0
        tmpA1.p_data[0] = arr1->p_data[5];
        tmpA1.p_data[1] = arr1->p_data[3];
        tmpA1.p_data[2] = arr1->p_data[8];
        tmpA1.p_data[3] = arr1->p_data[6];
        oarr_det( &tmpA1, &tmp2, dhl);
        oti_mul(
            &tmp2,
            &detInv,
            &tmp,
            dhl);
        oti_free(&tmp2);
        oarr_setItemOTI_indx(&tmp,3,aRes);

        // Set position 1,1
        tmpA1.p_data[0] = arr1->p_data[0];
        tmpA1.p_data[1] = arr1->p_data[2];
        tmpA1.p_data[2] = arr1->p_data[6];
        tmpA1.p_data[3] = arr1->p_data[8];
        oarr_det( &tmpA1, &tmp2, dhl);
        oti_mul(
            &tmp2,
            &detInv,
            &tmp,
            dhl);
        oti_free(&tmp2);
        oarr_setItemOTI_indx(&tmp,4,aRes);

        // Set position 1,2
        tmpA1.p_data[0] = arr1->p_data[2];
        tmpA1.p_data[1] = arr1->p_data[0];
        tmpA1.p_data[2] = arr1->p_data[5];
        tmpA1.p_data[3] = arr1->p_data[3];
        oarr_det( &tmpA1, &tmp2, dhl);
        oti_mul(
            &tmp2,
            &detInv,
            &tmp,
            dhl);
        oti_free(&tmp2);
        oarr_setItemOTI_indx(&tmp,5,aRes);




        // Set position 2,0
        tmpA1.p_data[0] = arr1->p_data[3];
        tmpA1.p_data[1] = arr1->p_data[4];
        tmpA1.p_data[2] = arr1->p_data[6];
        tmpA1.p_data[3] = arr1->p_data[7];
        oarr_det( &tmpA1, &tmp2, dhl);
        oti_mul(
            &tmp2,
            &detInv,
            &tmp,
            dhl);
        oti_free(&tmp2);
        oarr_setItemOTI_indx(&tmp,6,aRes);

        // Set position 2,1
        tmpA1.p_data[0] = arr1->p_data[1];
        tmpA1.p_data[1] = arr1->p_data[0];
        tmpA1.p_data[2] = arr1->p_data[7];
        tmpA1.p_data[3] = arr1->p_data[6];
        oarr_det( &tmpA1, &tmp2, dhl);
        oti_mul(
            &tmp2,
            &detInv,
            &tmp,
            dhl);
        oti_free(&tmp2);
        oarr_setItemOTI_indx(&tmp,7,aRes);

        // Set position 2,2
        tmpA1.p_data[0] = arr1->p_data[0];
        tmpA1.p_data[1] = arr1->p_data[1];
        tmpA1.p_data[2] = arr1->p_data[3];
        tmpA1.p_data[3] = arr1->p_data[4];
        oarr_det( &tmpA1, &tmp2, dhl);
        oti_mul(
            &tmp2,
            &detInv,
            &tmp,
            dhl);
        oti_free(&tmp2);
        oarr_setItemOTI_indx(&tmp,8,aRes);


        oti_free(&detInv);
        free(tmpA1.p_data);


    }
    

}
// ----------------------------------------------------------------------------------------------------






















// 2.4. Determinant.

// ****************************************************************************************************
void oarr_det(oarr_t* arr1, otinum_t* p_res, dhelpl_t dhl){
    
    uint64_t i, j ;
    otinum_t tmp1, tmp2, tmp3;

    if (arr1->ncols != arr1->nrows){
        printf("--- DimensionError in matrix determinant. Only square matrices are valid. ---\n");
        exit(1);
    }



    if ( arr1->ncols == 1 ){

        oti_copy(p_res, &arr1->p_data[0]);

    } else if (arr1->ncols == 2){



        oti_mul(
            &arr1->p_data[0],
            &arr1->p_data[3],
            &tmp1,
            dhl   ); 

        oti_mul(
            &arr1->p_data[1],
            &arr1->p_data[2],
            &tmp2,
            dhl   ); 

        oti_sub(
            &tmp1,
            &tmp2,
            p_res,
            dhl);

        oti_free(&tmp1);
        oti_free(&tmp2);

    } else if (arr1->ncols == 3){

        oti_createEmpty(p_res,0,arr1->order); // Initialize as zero.

        for (j=0; j<arr1->ncols; j++){
            
            oti_copy(&tmp1,&arr1->p_data[j]);
            
            
            for (i=1; i<arr1->nrows; i++){        
                
                tmp2 = tmp1;
                
                oti_mul(
                    &arr1->p_data[ ( (i+j)%arr1->ncols ) + i*arr1->ncols],
                    &tmp2,
                    &tmp1,
                    dhl   );  

                oti_free(&tmp2);

            }

            tmp3 = *p_res;
            oti_sum(&tmp3,&tmp1,p_res,dhl);
            
            oti_free(&tmp1);
            oti_free(&tmp3);

        }

        for (j=0; j<arr1->ncols; j++){
            
            oti_copy(&tmp1,&arr1->p_data[arr1->ncols-1-j]);
            
            for (i=1; i<arr1->nrows; i++){        
                
                tmp2 = tmp1;
                
                oti_mul(
                    &arr1->p_data[ (arr1->ncols-1 - (i+j)%arr1->ncols ) + i*arr1->ncols],
                    &tmp2,
                    &tmp1,
                    dhl   );    

                oti_free(&tmp2);

            }

            tmp3 = *p_res;
            oti_sub(&tmp3,&tmp1,p_res,dhl);
            
            oti_free(&tmp1);
            oti_free(&tmp3);

        }
    }
}
// ----------------------------------------------------------------------------------------------------














