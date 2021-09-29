


// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
void arrsso_dotproduct_OO_to(arrsso_t* arr1, arrsso_t* arr2, semiotin_t* res, dhelpl_t dhl){

    uint64_t i;
    ord_t order;
    semiotin_t tmp;

    // check for dimensions.
    arrsso_dimCheck_OO_samesize( arr1, arr2 );

    // Extract temporal 5.
    order = MAX(arrsso_get_order( arr1 ), arrsso_get_order( arr2 ));
    tmp = ssoti_get_tmp( 5, order ,dhl);

    ssoti_set_r( 0.0, &tmp, dhl);

    for ( i = 0; i < arr1->size; i++){

        ssoti_gem_oo_to( &arr1->p_data[ i ], &arr2->p_data[ i ], &tmp, &tmp, dhl);
                   
    }

    ssoti_set_o(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_dotproduct_RO_to(darr_t* arr1, arrsso_t* arr2, semiotin_t* res, dhelpl_t dhl){

    uint64_t i;
    ord_t order;
    semiotin_t tmp;

    // check for dimensions.
    arrsso_dimCheck_RO_samesize( arr1, arr2 );

    // Extract temporal 5.
    order =  arrsso_get_order( arr2 );
    tmp = ssoti_get_tmp( 5, order ,dhl);

    ssoti_set_r( 0.0, &tmp, dhl);

    for ( i = 0; i < arr1->size; i++){

        ssoti_gem_ro_to( arr1->p_data[ i ], &arr2->p_data[ i ], &tmp, &tmp, dhl);
                   
    }

    ssoti_set_o(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------



// 2. Array operations.
// 2.1. Inner product.
// 2.2. Transpose.
// 2.3. Inversion.
// 2.4. Determinant.
// 2.5. Norm.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
void arrsso_matmul_OO_to(arrsso_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){

    uint64_t i, j, k;
    ord_t order;
    semiotin_t tmp;

    // check for dimensions.
    arrsso_dimCheck_OO_matmul(arr1, arr2, res);

    // Extract temporal 5.
    order = MAX(arrsso_get_order( arr1 ), arrsso_get_order( arr2 ));
    
    tmp = ssoti_get_tmp( 5, order ,dhl);

    for ( i = 0; i < arr1->nrows; i++){
        
        for( j = 0; j < arr2->ncols; j++){

            // tmp = 0
            ssoti_set_r( 0.0, &tmp, dhl);

            for( k = 0; k < arr1->ncols; k++){

                // tmp = arr1[i,k] * arr2[k,j] + tmp

                ssoti_gem_oo_to( &arr1->p_data[ k + i * arr1->ncols ],
                                &arr2->p_data[ j + k * arr2->ncols ],
                                &tmp, &tmp, dhl);
                   
            }

            arrsso_set_item_ij_o( &tmp, i, j, res, dhl);

        }

    }
    

}
// ----------------------------------------------------------------------------------------------------


// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
void arrsso_matmul_OR_to(arrsso_t* arr1, darr_t* arr2, arrsso_t* res, dhelpl_t dhl){
        
    uint64_t i, j, k;
    ord_t order;
    semiotin_t tmp;

    // check for dimensions.
    arrsso_dimCheck_OR_matmul(arr1, arr2, res);

    order = arrsso_get_order( arr1 );
    
    // Extract temporal 5.
    tmp = ssoti_get_tmp( 5, order, dhl);

    for ( i = 0; i < arr1->nrows; i++){
        
        for( j = 0; j < arr2->ncols; j++){

            ssoti_set_r( 0.0, &tmp, dhl);

            for( k = 0; k < arr1->ncols; k++){

                ssoti_gem_ro_to(  arr2->p_data[ j + k * arr2->ncols ],
                                &arr1->p_data[ k + i * arr1->ncols ],
                                &tmp ,&tmp, dhl);
                   
            }

            arrsso_set_item_ij_o( &tmp, i, j, res, dhl);

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
void arrsso_matmul_RO_to(darr_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl){
        
    uint64_t i, j, k;
    ord_t order;
    semiotin_t tmp;

    // check for dimensions.
    arrsso_dimCheck_RO_matmul(arr1, arr2, res);

    order = arrsso_get_order( arr2 );

    // Extract temporal 5.
    tmp = ssoti_get_tmp( 5, order, dhl);

    for ( i = 0; i < arr1->nrows; i++){
        
        for( j = 0; j < arr2->ncols; j++){

            ssoti_set_r( 0.0, &tmp, dhl);

            for( k = 0; k < arr1->ncols; k++){

                ssoti_gem_ro_to(  arr1->p_data[ k + i * arr1->ncols ],
                                &arr2->p_data[ j + k * arr2->ncols ],
                                &tmp ,&tmp, dhl);
                   
            }

            arrsso_set_item_ij_o( &tmp, i, j, res, dhl);

        }

    }

}
// ----------------------------------------------------------------------------------------------------

















// 2.2. Transpose.
// ****************************************************************************************************
void arrsso_transpose_to(arrsso_t* arr1, arrsso_t* res, dhelpl_t dhl){
    
    uint64_t i, j;

    for ( i = 0; i<arr1->nrows; i++){

        for ( j = 0; j<arr1->ncols; j++){
            
            arrsso_set_item_ij_o( &arr1->p_data[  j + i*arr1->ncols  ], 
                                 j, i, res, dhl);

        }

    }
    
}
// ----------------------------------------------------------------------------------------------------























// 2.3. Inversion.
// ****************************************************************************************************
void arrsso_invert_to(arrsso_t* arr1, arrsso_t* res, dhelpl_t dhl){

    arrsso_t tmpA1 = arrsso_init();
    ord_t order;
    semiotin_t tmp1, tmp2, tmp3, det;

    // Check dimensions.
    arrsso_dimCheck_O_squareness( arr1, res);

    order = arrsso_get_order( arr1 );

    tmp1 = ssoti_get_tmp( 5, order, dhl);
    tmp2 = ssoti_get_tmp( 6, order, dhl);
    tmp3 = ssoti_get_tmp( 7, order, dhl);
    det  = ssoti_get_tmp( 8, order, dhl);

    if(arr1->ncols == 1){

        ssoti_pow_to(&arr1->p_data[0],-1.0,&res->p_data[0],dhl);

    } else if (arr1->ncols == 2){

        arrsso_det_to( arr1, &det, dhl); // Get determinant.

        // res->p_data[0] =  arr1->p_data[3]/det;
        ssoti_div_oo_to(&arr1->p_data[3],&det,&tmp1,dhl);
        ssoti_set_o( &tmp1, &res->p_data[0],dhl);

        // res->p_data[1] = -arr1->p_data[1]/det;
        ssoti_div_oo_to(&arr1->p_data[1],&det,&tmp1,dhl);
        ssoti_set_o( &tmp1, &res->p_data[1],dhl);
        ssoti_neg_to(&res->p_data[1],&res->p_data[1],dhl);

        // res->p_data[2] = -arr1->p_data[2]/det;
        ssoti_div_oo_to(&arr1->p_data[2],&det,&tmp1,dhl);
        ssoti_set_o( &tmp1, &res->p_data[2],dhl);
        ssoti_neg_to(&res->p_data[2],&res->p_data[2],dhl);

        // res->p_data[3] =  arr1->p_data[0]/det;
        ssoti_div_oo_to(&arr1->p_data[0],&det,&tmp1,dhl);
        ssoti_set_o( &tmp1, &res->p_data[3],dhl);

    } else if (arr1->ncols == 3){
        
        tmpA1 = arrsso_zeros_bases( 2, 2, 0, 0,dhl );
        tmpA1.p_data[0] = ssoti_get_tmp(  9, order, dhl);
        tmpA1.p_data[1] = ssoti_get_tmp( 10, order, dhl);
        tmpA1.p_data[2] = ssoti_get_tmp( 11, order, dhl);
        tmpA1.p_data[3] = ssoti_get_tmp( 12, order, dhl);
        
        arrsso_det_to( arr1, &det, dhl); // Get determinant.
        
        // Set position 0,0
        // tmpA1.p_data[0] = arr1->p_data[4];
        ssoti_set_o( &arr1->p_data[4], &tmpA1.p_data[0],dhl);
        // tmpA1.p_data[1] = arr1->p_data[5];
        ssoti_set_o( &arr1->p_data[5], &tmpA1.p_data[1],dhl);
        // tmpA1.p_data[2] = arr1->p_data[7];
        ssoti_set_o( &arr1->p_data[7], &tmpA1.p_data[2],dhl);
        // tmpA1.p_data[3] = arr1->p_data[8];
        ssoti_set_o( &arr1->p_data[8], &tmpA1.p_data[3],dhl);
        
        
        
        
        // res->p_data[0] = darr_det( &tmpA1 )/det;
        arrsso_det_to(  &tmpA1, &tmp1,                  dhl);
        ssoti_div_oo_to( &tmp1,  &det, &res->p_data[0], dhl);

        

        // Set position 0,1
        // tmpA1.p_data[0] = arr1->p_data[2];
        ssoti_set_o( &arr1->p_data[2], &tmpA1.p_data[0],dhl);
        // tmpA1.p_data[1] = arr1->p_data[1];
        ssoti_set_o( &arr1->p_data[1], &tmpA1.p_data[1],dhl);
        // tmpA1.p_data[2] = arr1->p_data[8];
        ssoti_set_o( &arr1->p_data[8], &tmpA1.p_data[2],dhl);
        // tmpA1.p_data[3] = arr1->p_data[7];
        ssoti_set_o( &arr1->p_data[7], &tmpA1.p_data[3],dhl);

        
        // res->p_data[1] = darr_det( &tmpA1 )/det;
        arrsso_det_to(  &tmpA1, &tmp1,                  dhl);
        ssoti_div_oo_to( &tmp1,  &det, &res->p_data[1], dhl);




        // Set position 0,2
        // tmpA1.p_data[0] = arr1->p_data[1];
        ssoti_set_o( &arr1->p_data[1], &tmpA1.p_data[0],dhl);
        // tmpA1.p_data[1] = arr1->p_data[2];
        ssoti_set_o( &arr1->p_data[2], &tmpA1.p_data[1],dhl);
        // tmpA1.p_data[2] = arr1->p_data[4];
        ssoti_set_o( &arr1->p_data[4], &tmpA1.p_data[2],dhl);
        // tmpA1.p_data[3] = arr1->p_data[5];
        ssoti_set_o( &arr1->p_data[5], &tmpA1.p_data[3],dhl);
        
        // res->p_data[2] = darr_det( &tmpA1 )/det;
        arrsso_det_to(  &tmpA1, &tmp1,                  dhl);
        ssoti_div_oo_to( &tmp1,  &det, &res->p_data[2], dhl);



        // Set position 1,0
        // tmpA1.p_data[0] = arr1->p_data[5];
        ssoti_set_o( &arr1->p_data[5], &tmpA1.p_data[0],dhl);
        // tmpA1.p_data[1] = arr1->p_data[3];
        ssoti_set_o( &arr1->p_data[3], &tmpA1.p_data[1],dhl);
        // tmpA1.p_data[2] = arr1->p_data[8];
        ssoti_set_o( &arr1->p_data[8], &tmpA1.p_data[2],dhl);
        // tmpA1.p_data[3] = arr1->p_data[6];
        ssoti_set_o( &arr1->p_data[6], &tmpA1.p_data[3],dhl);
        
        // res->p_data[3] = darr_det( &tmpA1 )/det;
        arrsso_det_to(  &tmpA1, &tmp1,                  dhl);
        ssoti_div_oo_to( &tmp1,  &det, &res->p_data[3], dhl);



        // Set position 1,1
        // tmpA1.p_data[0] = arr1->p_data[0];
        ssoti_set_o( &arr1->p_data[0], &tmpA1.p_data[0],dhl);
        // tmpA1.p_data[1] = arr1->p_data[2];
        ssoti_set_o( &arr1->p_data[2], &tmpA1.p_data[1],dhl);
        // tmpA1.p_data[2] = arr1->p_data[6];
        ssoti_set_o( &arr1->p_data[6], &tmpA1.p_data[2],dhl);
        // tmpA1.p_data[3] = arr1->p_data[8];
        ssoti_set_o( &arr1->p_data[8], &tmpA1.p_data[3],dhl);
        

        // res->p_data[4] = darr_det( &tmpA1 )/det;
        arrsso_det_to(  &tmpA1, &tmp1,                  dhl);
        ssoti_div_oo_to( &tmp1,  &det, &res->p_data[4], dhl);




        // Set position 1,2
        // tmpA1.p_data[0] = arr1->p_data[2];
        ssoti_set_o( &arr1->p_data[2], &tmpA1.p_data[0],dhl);
        // tmpA1.p_data[1] = arr1->p_data[0];
        ssoti_set_o( &arr1->p_data[0], &tmpA1.p_data[1],dhl);
        // tmpA1.p_data[2] = arr1->p_data[5];
        ssoti_set_o( &arr1->p_data[5], &tmpA1.p_data[2],dhl);
        // tmpA1.p_data[3] = arr1->p_data[3];
        ssoti_set_o( &arr1->p_data[3], &tmpA1.p_data[3],dhl);
        
        // res->p_data[5] = darr_det( &tmpA1 )/det;
        arrsso_det_to(  &tmpA1, &tmp1,                  dhl);
        ssoti_div_oo_to( &tmp1,  &det, &res->p_data[5], dhl);





        // Set position 2,0
        // tmpA1.p_data[0] = arr1->p_data[3];
        ssoti_set_o( &arr1->p_data[3], &tmpA1.p_data[0],dhl);
        // tmpA1.p_data[1] = arr1->p_data[4];
        ssoti_set_o( &arr1->p_data[4], &tmpA1.p_data[1],dhl);
        // tmpA1.p_data[2] = arr1->p_data[6];
        ssoti_set_o( &arr1->p_data[6], &tmpA1.p_data[2],dhl);
        // tmpA1.p_data[3] = arr1->p_data[7];
        ssoti_set_o( &arr1->p_data[7], &tmpA1.p_data[3],dhl);
        
        // res->p_data[6] = darr_det( &tmpA1 )/det;
        arrsso_det_to(  &tmpA1, &tmp1,                  dhl);
        ssoti_div_oo_to( &tmp1,  &det, &res->p_data[6], dhl);




        // Set position 2,1
        // tmpA1.p_data[0] = arr1->p_data[1];
        ssoti_set_o( &arr1->p_data[1], &tmpA1.p_data[0],dhl);
        // tmpA1.p_data[1] = arr1->p_data[0];
        ssoti_set_o( &arr1->p_data[0], &tmpA1.p_data[1],dhl);
        // tmpA1.p_data[2] = arr1->p_data[7];
        ssoti_set_o( &arr1->p_data[7], &tmpA1.p_data[2],dhl);
        // tmpA1.p_data[3] = arr1->p_data[6];
        ssoti_set_o( &arr1->p_data[6], &tmpA1.p_data[3],dhl);
        
        // res->p_data[7] = darr_det( &tmpA1 )/det;
        arrsso_det_to(  &tmpA1, &tmp1,                  dhl);
        ssoti_div_oo_to( &tmp1,  &det, &res->p_data[7], dhl);




        // Set position 2,2
        // tmpA1.p_data[0] = arr1->p_data[0];
        ssoti_set_o( &arr1->p_data[0], &tmpA1.p_data[0],dhl);
        // tmpA1.p_data[1] = arr1->p_data[1];
        ssoti_set_o( &arr1->p_data[1], &tmpA1.p_data[1],dhl);
        // tmpA1.p_data[2] = arr1->p_data[3];
        ssoti_set_o( &arr1->p_data[3], &tmpA1.p_data[2],dhl);
        // tmpA1.p_data[3] = arr1->p_data[4];
        ssoti_set_o( &arr1->p_data[4], &tmpA1.p_data[3],dhl);

        // res->p_data[8] = darr_det( &tmpA1 )/det;
        arrsso_det_to(  &tmpA1, &tmp1,                  dhl);
        ssoti_div_oo_to( &tmp1,  &det, &res->p_data[8], dhl);

        arrsso_free(&tmpA1);

    } 

}
// ----------------------------------------------------------------------------------------------------






















// 2.4. Determinant.

// ****************************************************************************************************
void arrsso_det_to(arrsso_t* arr1, semiotin_t* res, dhelpl_t dhl){
    
    uint64_t i, j;

    ord_t order;
    semiotin_t tmp1, tmp2, tmp3;
    // printf("Here 1\n");

    // Check dimensions.
    arrsso_dimCheck_O_squareness( arr1, arr1);
    
    order = arrsso_get_order( arr1 );

    // Extract temporal 5.
    tmp1 = ssoti_get_tmp( 5, order, dhl);
    tmp2 = ssoti_get_tmp( 6, order, dhl);
    tmp3 = ssoti_get_tmp( 7, order, dhl);

    if ( arr1->ncols == 1 ){

        ssoti_copy_to(&arr1->p_data[0], res, dhl);

    } else if (arr1->ncols == 2){

        ssoti_mul_oo_to(
            &arr1->p_data[0],
            &arr1->p_data[3],
            &tmp1,
            dhl   ); 

        ssoti_mul_oo_to(
            &arr1->p_data[1],
            &arr1->p_data[2],
            &tmp2,
            dhl   ); 

        ssoti_sub_oo_to(
            &tmp1,
            &tmp2,
            res,
            dhl);

    } else if (arr1->ncols >= 3){
        
        // tmp3 = 0
        ssoti_set_r( 0.0, &tmp3, dhl);

        for (j=0; j<arr1->ncols; j++){
            
            // tmp1 = arr1->p_data[j]
            ssoti_set_o(&arr1->p_data[j], &tmp1, dhl);

            for (i=1; i<arr1->nrows; i++){        
                
                //tmp2 = tmp1 * arr1->p_data[ ( (i+j)%arr1->ncols ) + i*arr1->ncols];
                ssoti_mul_oo_to(
                    &tmp1,
                    &arr1->p_data[ ( (i+j)%arr1->ncols ) + i*arr1->ncols],
                    &tmp2,
                    dhl   ); 

                ssoti_set_o( &tmp2, &tmp1, dhl);

            }

            // tmp2 = tmp3 + tmp1;
            ssoti_sum_oo_to(
                &tmp1,
                &tmp3,
                &tmp2,
                dhl   );

            // tmp3 = tmp2;
            ssoti_set_o( &tmp2, &tmp3, dhl);             

        }
        
        for ( j = 0; j<arr1->ncols; j++){
            
            // tmp1 = arr1->p_data[arr1->ncols-1-j];
            ssoti_set_o(&arr1->p_data[arr1->ncols-1-j], &tmp1, dhl);
            
            for ( i = 1; i<arr1->nrows; i++){        
                
                // tmp1 *= arr1->p_data[ (arr1->ncols-1 - (i+j)%arr1->ncols ) + i*arr1->ncols];
                ssoti_mul_oo_to(
                    &tmp1,
                    &arr1->p_data[ (arr1->ncols-1 - (i+j)%arr1->ncols ) + i*arr1->ncols],
                    &tmp2,
                    dhl   ); 

                ssoti_set_o( &tmp2, &tmp1, dhl);

            }

            // tmp2 = tmp3 - tmp1;
            ssoti_sub_oo_to(
                &tmp3,
                &tmp1,
                &tmp2,
                dhl   );

            // tmp3 = tmp2;
            ssoti_set_o( &tmp2, &tmp3, dhl);  

        }

        // res = tmp3
        ssoti_set_o(&tmp3, res, dhl);

    }

}
// ----------------------------------------------------------------------------------------------------





// 2.5. Norm

// ****************************************************************************************************
void arrsso_norm_to(arrsso_t* arr1, semiotin_t* res, dhelpl_t dhl){
    
    
    uint64_t i;
    ord_t order;
    semiotin_t tmp1, tmp2, tmp3;

    order = arrsso_get_order( arr1 );

    tmp1 = ssoti_get_tmp( 5, order, dhl);
    tmp2 = ssoti_get_tmp( 6, order, dhl);
    tmp3 = ssoti_get_tmp( 7, order, dhl);
    
    ssoti_set_r( 0.0, &tmp3, dhl);    
    // 
    for( i = 0; i<arr1->size; i++){

        // tmp1 = (arr1->p_data[i])^2.0;
        ssoti_pow_to( &arr1->p_data[i], 2.0, &tmp1, dhl);
        
        // tmp2 = tmp3 + tmp1;
        ssoti_sum_oo_to( &tmp1, &tmp3, &tmp2, dhl);

        // tmp3 = tmp2;
        ssoti_set_o( &tmp2, &tmp3, dhl);
    
    }

    // res = sqrt(tmp3);
    ssoti_sqrt_to(&tmp3, res, dhl);
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrsso_pnorm_to(arrsso_t* arr1, coeff_t p, semiotin_t* res, dhelpl_t dhl){
    
    
    uint64_t i;
    ord_t order;
    semiotin_t tmp1, tmp2, tmp3;

    order = arrsso_get_order( arr1 );

    tmp1 = ssoti_get_tmp( 5, order, dhl);
    tmp2 = ssoti_get_tmp( 6, order, dhl);
    tmp3 = ssoti_get_tmp( 7, order, dhl);
    
    ssoti_set_r( 0.0, &tmp3, dhl);    
    // 
    for( i = 0; i<arr1->size; i++){

        // tmp1 = (arr1->p_data[i])^p;
        ssoti_abs_to( &arr1->p_data[i], &tmp2, dhl);
        ssoti_pow_to( &tmp2, p, &tmp1, dhl);
        
        // tmp2 = tmp3 + tmp1;
        ssoti_sum_oo_to( &tmp1, &tmp3, &tmp2, dhl);

        // tmp3 = tmp2;
        ssoti_set_o( &tmp2, &tmp3, dhl);
    
    }

    // res = (tmp3)^(1/p);
    ssoti_pow_to(&tmp3, 1.0/p, res, dhl);
    
}
// ----------------------------------------------------------------------------------------------------








