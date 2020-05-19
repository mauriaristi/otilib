





// 2. Array operations.
// 2.1. Inner product.
// 2.2. Transpose.
// 2.3. Inversion.
// 2.4. Determinant.
// 2.5. Norm.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
void arrso_matmul_OO_to(arrso_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){

    uint64_t i, j, k;
    ord_t order;
    sotinum_t tmp;

    // check for dimensions.
    arrso_dimCheck_OO_matmul(arr1, arr2, res);

    // Extract temporal 5.
    order = MAX(arrso_get_order( arr1 ), arrso_get_order( arr2 ));
    tmp = soti_get_tmp( 5, order ,dhl);

    for ( i = 0; i < arr1->nrows; i++){
        
        for( j = 0; j < arr2->ncols; j++){

            // tmp = 0
            soti_set_r( 0.0, &tmp, dhl);

            for( k = 0; k < arr1->ncols; k++){

                // tmp = arr1[i,k] * arr2[k,j] + tmp

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
void arrso_matmul_OR_to(arrso_t* arr1, darr_t* arr2, arrso_t* res, dhelpl_t dhl){
        
    uint64_t i, j, k;
    ord_t order;
    sotinum_t tmp;

    // check for dimensions.
    arrso_dimCheck_OR_matmul(arr1, arr2, res);

    order = arrso_get_order( arr1 );
    // Extract temporal 5.
    tmp = soti_get_tmp( 5,arr1->p_data[0].order ,dhl);

    for ( i = 0; i < arr1->nrows; i++){
        
        for( j = 0; j < arr2->ncols; j++){

            soti_set_r( 0.0, &tmp, dhl);

            for( k = 0; k < arr1->ncols; k++){

                soti_gem_ro_to(  arr2->p_data[ j + k * arr2->ncols ],
                                &arr1->p_data[ k + i * arr1->ncols ],
                                &tmp ,&tmp, dhl);
                   
            }

            arrso_set_item_ij_o( &tmp, i, j, res, dhl);

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
void arrso_matmul_RO_to(darr_t* arr1, arrso_t* arr2, arrso_t* res, dhelpl_t dhl){
        
    uint64_t i, j, k;
    ord_t order;
    sotinum_t tmp;

    // check for dimensions.
    arrso_dimCheck_RO_matmul(arr1, arr2, res);

    order = arrso_get_order( arr2 );

    // Extract temporal 5.
    tmp = soti_get_tmp( 5, order, dhl);

    for ( i = 0; i < arr1->nrows; i++){
        
        for( j = 0; j < arr2->ncols; j++){

            soti_set_r( 0.0, &tmp, dhl);

            for( k = 0; k < arr1->ncols; k++){

                soti_gem_ro_to(  arr1->p_data[ k + i * arr1->ncols ],
                                &arr2->p_data[ j + k * arr2->ncols ],
                                &tmp ,&tmp, dhl);
                   
            }

            arrso_set_item_ij_o( &tmp, i, j, res, dhl);

        }

    }

}
// ----------------------------------------------------------------------------------------------------

















// 2.2. Transpose.
// ****************************************************************************************************
void arrso_transpose_to(arrso_t* arr1, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i, j;

    for ( i = 0; i<arr1->nrows; i++){

        for ( j = 0; j<arr1->ncols; j++){
            
            arrso_set_item_ij_o( &arr1->p_data[  j + i*arr1->ncols  ], 
                                 j, i, res, dhl);

        }

    }
    
}
// ----------------------------------------------------------------------------------------------------























// 2.3. Inversion.
// ****************************************************************************************************
void arrso_invert_to(arrso_t* arr1, arrso_t* res, dhelpl_t dhl){
    
   

}
// ----------------------------------------------------------------------------------------------------






















// 2.4. Determinant.

// ****************************************************************************************************
void arrso_det_to(arrso_t* arr1, sotinum_t* res, dhelpl_t dhl){
    
    uint64_t i, j;

    ord_t order;
    sotinum_t tmp1, tmp2, tmp3;

    // Check dimensions.
    arrso_dimCheck_O_squareness( arr1, arr1);

    res = 0;
    soti_set_r( 0.0, res, dhl);

    order = arrso_get_order( arr1 );

    // Extract temporal 5.
    tmp1 = soti_get_tmp( 5, order, dhl);
    tmp2 = soti_get_tmp( 6, order, dhl);
    tmp3 = soti_get_tmp( 7, order, dhl);

    if ( arr1->ncols == 1 ){

        soti_copy_to(&arr1->p_data[0], res, dhl);

    } else if (arr1->ncols >= 2){

        soti_mul_oo_to(
            &arr1->p_data[0],
            &arr1->p_data[3],
            &tmp1,
            dhl   ); 

        soti_mul_oo_to(
            &arr1->p_data[1],
            &arr1->p_data[2],
            &tmp2,
            dhl   ); 

        soti_sub_oo_to(
            &tmp1,
            &tmp2,
            res,
            dhl);

    } else if (arr1->ncols >= 3){

        // tmp3 = 0
        soti_set_r( 0.0, &tmp3, dhl);

        for (j=0; j<arr1->ncols; j++){
            
            // tmp1 = arr1->p_data[j]
            soti_set_o(&arr1->p_data[j], &tmp1, dhl);

            for (i=1; i<arr1->nrows; i++){        
                
                //tmp2 = tmp1 * arr1->p_data[ ( (i+j)%arr1->ncols ) + i*arr1->ncols];
                soti_mul_oo_to(
                    &tmp1,
                    &arr1->p_data[ ( (i+j)%arr1->ncols ) + i*arr1->ncols],
                    &tmp2,
                    dhl   ); 

                soti_set_o( &tmp2, &tmp1, dhl);

            }

            // tmp2 = tmp3 + tmp1;
            soti_sum_oo_to(
                &tmp1,
                &tmp3,
                &tmp2,
                dhl   );

            // tmp3 = tmp2;
            soti_set_o( &tmp2, &tmp3, dhl);             

        }

        for ( j = 0; j<arr1->ncols; j++){
            
            // tmp1 = arr1->p_data[arr1->ncols-1-j];
            soti_set_o(&arr1->p_data[arr1->ncols-1-j], &tmp1, dhl);
            
            for ( i = 1; i<arr1->nrows; i++){        
                
                // tmp1 *= arr1->p_data[ (arr1->ncols-1 - (i+j)%arr1->ncols ) + i*arr1->ncols];
                soti_mul_oo_to(
                    &tmp1,
                    &arr1->p_data[ (arr1->ncols-1 - (i+j)%arr1->ncols ) + i*arr1->ncols],
                    &tmp2,
                    dhl   ); 

                soti_set_o( &tmp2, &tmp1, dhl);

            }

            // tmp2 = tmp3 - tmp1;
            soti_sub_oo_to(
                &tmp3,
                &tmp1,
                &tmp2,
                dhl   );

            // tmp3 = tmp2;
            soti_set_o( &tmp2, &tmp3, dhl);  

        }

        soti_set_o(&tmp3, res, dhl);

    }

}
// ----------------------------------------------------------------------------------------------------





// 2.5. Norm

// ****************************************************************************************************
void arrso_norm_to(arrso_t* arr1, sotinum_t* res, dhelpl_t dhl){
    
    
    uint64_t i;
    ord_t order;
    sotinum_t tmp1, tmp2, tmp3;

    order = arrso_get_order( arr1 );

    tmp1 = soti_get_tmp( 5, order, dhl);
    tmp2 = soti_get_tmp( 6, order, dhl);
    tmp3 = soti_get_tmp( 7, order, dhl);
    
    soti_set_r( 0.0, &tmp3, dhl);    
    // 
    for( i = 0; i<arr1->size; i++){

        // tmp1 = (arr1->p_data[i])^2.0;
        soti_pow_to( &arr1->p_data[i], 2.0, &tmp1, dhl);
        
        // tmp2 = tmp3 + tmp1;
        soti_sum_oo_to( &tmp1, &tmp3, &tmp2, dhl);

        // tmp3 = tmp2;
        soti_set_o( &tmp2, &tmp3, dhl);
    
    }

    // res = sqrt(tmp3);
    soti_sqrt_to(&tmp3, res, dhl);
    
}
// ----------------------------------------------------------------------------------------------------








