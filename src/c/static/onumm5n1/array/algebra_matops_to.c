

// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
void oarrm5n1_dotproduct_OO_to(oarrm5n1_t* arr1, oarrm5n1_t* arr2, onumm5n1_t* res){

    uint64_t i;
    onumm5n1_t tmp;

    // check for dimensions.
    oarrm5n1_dimCheck_OO_samesize( arr1, arr2 );

    onumm5n1_set_r( 0.0, &tmp);

    for ( i = 0; i < arr1->size; i++){

        onumm5n1_gem_oo_to( &arr1->p_data[ i ], &arr2->p_data[ i ], &tmp, &tmp);
                   
    }

    onumm5n1_set_o(&tmp, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm5n1_dotproduct_RO_to(darr_t* arr1, oarrm5n1_t* arr2, onumm5n1_t* res){

    uint64_t i;
    onumm5n1_t tmp;

    // check for dimensions.
    oarrm5n1_dimCheck_RO_samesize( arr1, arr2 );

    onumm5n1_set_r( 0.0, &tmp);

    for ( i = 0; i < arr1->size; i++){

        onumm5n1_gem_ro_to( arr1->p_data[ i ], &arr2->p_data[ i ], &tmp, &tmp);
                   
    }

    onumm5n1_set_o(&tmp, res);

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
void oarrm5n1_matmul_OO_to(oarrm5n1_t* arr1, oarrm5n1_t* arr2, oarrm5n1_t* res){

    uint64_t i, j, k;
    onumm5n1_t tmp;

    // check for dimensions.
    oarrm5n1_dimCheck_OO_matmul(arr1, arr2, res);

    for ( i = 0; i < arr1->nrows; i++){
        
        for( j = 0; j < arr2->ncols; j++){

            // tmp = 0
            onumm5n1_set_r( 0.0, &tmp);

            for( k = 0; k < arr1->ncols; k++){

                // tmp = arr1[i,k] * arr2[k,j] + tmp

                onumm5n1_gem_oo_to( &arr1->p_data[ k + i * arr1->ncols ],
                                &arr2->p_data[ j + k * arr2->ncols ],
                                &tmp, &tmp);
                   
            }

            oarrm5n1_set_item_ij_o( &tmp, i, j, res);

        }

    }
    

}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
void oarrm5n1_matmul_OR_to(oarrm5n1_t* arr1, darr_t* arr2, oarrm5n1_t* res){
        
    uint64_t i, j, k;
    onumm5n1_t tmp;

    // check for dimensions.
    oarrm5n1_dimCheck_OR_matmul(arr1, arr2, res);
    

    for ( i = 0; i < arr1->nrows; i++){
        
        for( j = 0; j < arr2->ncols; j++){

            onumm5n1_set_r( 0.0, &tmp);

            for( k = 0; k < arr1->ncols; k++){

                onumm5n1_gem_ro_to(  arr2->p_data[ j + k * arr2->ncols ],
                                &arr1->p_data[ k + i * arr1->ncols ],
                                &tmp ,&tmp);
                   
            }

            oarrm5n1_set_item_ij_o( &tmp, i, j, res);

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
void oarrm5n1_matmul_RO_to(darr_t* arr1, oarrm5n1_t* arr2, oarrm5n1_t* res){
        
    uint64_t i, j, k;
    onumm5n1_t tmp;

    // check for dimensions.
    oarrm5n1_dimCheck_RO_matmul(arr1, arr2, res);

    for ( i = 0; i < arr1->nrows; i++){
        
        for( j = 0; j < arr2->ncols; j++){

            onumm5n1_set_r( 0.0, &tmp);

            for( k = 0; k < arr1->ncols; k++){

                onumm5n1_gem_ro_to(  arr1->p_data[ k + i * arr1->ncols ],
                                &arr2->p_data[ j + k * arr2->ncols ],
                                &tmp ,&tmp);
                   
            }

            oarrm5n1_set_item_ij_o( &tmp, i, j, res);

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
void oarrm5n1_transpose_to(oarrm5n1_t* arr1, oarrm5n1_t* res){
    
    uint64_t i, j;

    for ( i = 0; i<arr1->nrows; i++){

        for ( j = 0; j<arr1->ncols; j++){
            
            oarrm5n1_set_item_ij_o( &arr1->p_data[  j + i*arr1->ncols  ], 
                                 j, i, res);

        }

    }
    
}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
void oarrm5n1_invert_to(oarrm5n1_t* arr1, oarrm5n1_t* res){

    oarrm5n1_t tmpA1 = oarrm5n1_init();
    onumm5n1_t tmp1, det;

    // Check dimensions.
    oarrm5n1_dimCheck_O_squareness( arr1, res);

    if(arr1->ncols == 1){

        onumm5n1_pow_to(&arr1->p_data[0],-1.0,&res->p_data[0]);

    } else if (arr1->ncols == 2){

        oarrm5n1_det_to( arr1, &det); // Get determinant.

        // res->p_data[0] =  arr1->p_data[3]/det;
        onumm5n1_div_oo_to(&arr1->p_data[3],&det,&tmp1);
        onumm5n1_set_o( &tmp1, &res->p_data[0]);

        // res->p_data[1] = -arr1->p_data[1]/det;
        onumm5n1_div_oo_to(&arr1->p_data[1],&det,&tmp1);
        onumm5n1_set_o( &tmp1, &res->p_data[1]);
        onumm5n1_neg_to(&res->p_data[1],&res->p_data[1]);

        // res->p_data[2] = -arr1->p_data[2]/det;
        onumm5n1_div_oo_to(&arr1->p_data[2],&det,&tmp1);
        onumm5n1_set_o( &tmp1, &res->p_data[2]);
        onumm5n1_neg_to(&res->p_data[2],&res->p_data[2]);

        // res->p_data[3] =  arr1->p_data[0]/det;
        onumm5n1_div_oo_to(&arr1->p_data[0],&det,&tmp1);
        onumm5n1_set_o( &tmp1, &res->p_data[3]);

    } else if (arr1->ncols == 3){
        
        tmpA1 = oarrm5n1_zeros( 2, 2 );
        
        oarrm5n1_det_to( arr1, &det); // Get determinant.
        
        // Set position 0,0
        // tmpA1.p_data[0] = arr1->p_data[4];
        onumm5n1_set_o( &arr1->p_data[4], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[5];
        onumm5n1_set_o( &arr1->p_data[5], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[7];
        onumm5n1_set_o( &arr1->p_data[7], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[8];
        onumm5n1_set_o( &arr1->p_data[8], &tmpA1.p_data[3]);
        
        
        
        
        // res->p_data[0] = darr_det( &tmpA1 )/det;
        oarrm5n1_det_to(  &tmpA1, &tmp1);
        onumm5n1_div_oo_to( &tmp1,  &det, &res->p_data[0]);

        

        // Set position 0,1
        // tmpA1.p_data[0] = arr1->p_data[2];
        onumm5n1_set_o( &arr1->p_data[2], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[1];
        onumm5n1_set_o( &arr1->p_data[1], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[8];
        onumm5n1_set_o( &arr1->p_data[8], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[7];
        onumm5n1_set_o( &arr1->p_data[7], &tmpA1.p_data[3]);

        
        // res->p_data[1] = darr_det( &tmpA1 )/det;
        oarrm5n1_det_to(  &tmpA1, &tmp1);
        onumm5n1_div_oo_to( &tmp1,  &det, &res->p_data[1]);

        // Set position 0,2
        // tmpA1.p_data[0] = arr1->p_data[1];
        onumm5n1_set_o( &arr1->p_data[1], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[2];
        onumm5n1_set_o( &arr1->p_data[2], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[4];
        onumm5n1_set_o( &arr1->p_data[4], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[5];
        onumm5n1_set_o( &arr1->p_data[5], &tmpA1.p_data[3]);
        
        // res->p_data[2] = darr_det( &tmpA1 )/det;
        oarrm5n1_det_to(  &tmpA1, &tmp1);
        onumm5n1_div_oo_to( &tmp1,  &det, &res->p_data[2]);

        // Set position 1,0
        // tmpA1.p_data[0] = arr1->p_data[5];
        onumm5n1_set_o( &arr1->p_data[5], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[3];
        onumm5n1_set_o( &arr1->p_data[3], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[8];
        onumm5n1_set_o( &arr1->p_data[8], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[6];
        onumm5n1_set_o( &arr1->p_data[6], &tmpA1.p_data[3]);
        
        // res->p_data[3] = darr_det( &tmpA1 )/det;
        oarrm5n1_det_to(  &tmpA1, &tmp1);
        onumm5n1_div_oo_to( &tmp1,  &det, &res->p_data[3]);

        // Set position 1,1
        // tmpA1.p_data[0] = arr1->p_data[0];
        onumm5n1_set_o( &arr1->p_data[0], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[2];
        onumm5n1_set_o( &arr1->p_data[2], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[6];
        onumm5n1_set_o( &arr1->p_data[6], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[8];
        onumm5n1_set_o( &arr1->p_data[8], &tmpA1.p_data[3]);
        

        // res->p_data[4] = darr_det( &tmpA1 )/det;
        oarrm5n1_det_to(  &tmpA1, &tmp1);
        onumm5n1_div_oo_to( &tmp1,  &det, &res->p_data[4]);

        // Set position 1,2
        // tmpA1.p_data[0] = arr1->p_data[2];
        onumm5n1_set_o( &arr1->p_data[2], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[0];
        onumm5n1_set_o( &arr1->p_data[0], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[5];
        onumm5n1_set_o( &arr1->p_data[5], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[3];
        onumm5n1_set_o( &arr1->p_data[3], &tmpA1.p_data[3]);
        
        // res->p_data[5] = darr_det( &tmpA1 )/det;
        oarrm5n1_det_to(  &tmpA1, &tmp1);
        onumm5n1_div_oo_to( &tmp1,  &det, &res->p_data[5]);

        // Set position 2,0
        // tmpA1.p_data[0] = arr1->p_data[3];
        onumm5n1_set_o( &arr1->p_data[3], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[4];
        onumm5n1_set_o( &arr1->p_data[4], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[6];
        onumm5n1_set_o( &arr1->p_data[6], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[7];
        onumm5n1_set_o( &arr1->p_data[7], &tmpA1.p_data[3]);
        
        // res->p_data[6] = darr_det( &tmpA1 )/det;
        oarrm5n1_det_to(  &tmpA1, &tmp1);
        onumm5n1_div_oo_to( &tmp1,  &det, &res->p_data[6]);

        // Set position 2,1
        // tmpA1.p_data[0] = arr1->p_data[1];
        onumm5n1_set_o( &arr1->p_data[1], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[0];
        onumm5n1_set_o( &arr1->p_data[0], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[7];
        onumm5n1_set_o( &arr1->p_data[7], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[6];
        onumm5n1_set_o( &arr1->p_data[6], &tmpA1.p_data[3]);
        
        // res->p_data[7] = darr_det( &tmpA1 )/det;
        oarrm5n1_det_to(  &tmpA1, &tmp1);
        onumm5n1_div_oo_to( &tmp1,  &det, &res->p_data[7]);

        // Set position 2,2
        // tmpA1.p_data[0] = arr1->p_data[0];
        onumm5n1_set_o( &arr1->p_data[0], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[1];
        onumm5n1_set_o( &arr1->p_data[1], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[3];
        onumm5n1_set_o( &arr1->p_data[3], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[4];
        onumm5n1_set_o( &arr1->p_data[4], &tmpA1.p_data[3]);

        // res->p_data[8] = darr_det( &tmpA1 )/det;
        oarrm5n1_det_to(  &tmpA1, &tmp1);
        onumm5n1_div_oo_to( &tmp1,  &det, &res->p_data[8]);

        oarrm5n1_free(&tmpA1);

    } 

}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.

// ****************************************************************************************************
void oarrm5n1_det_to(oarrm5n1_t* arr1, onumm5n1_t* res){
    
    uint64_t i, j;
    onumm5n1_t tmp1, tmp2, tmp3;
    // printf("Here 1\n");

    // Check dimensions.
    oarrm5n1_dimCheck_O_squareness( arr1, arr1);
    

    if ( arr1->ncols == 1 ){

        onumm5n1_copy_to(&arr1->p_data[0], res);

    } else if (arr1->ncols == 2){

        onumm5n1_mul_oo_to(
            &arr1->p_data[0],
            &arr1->p_data[3],
            &tmp1   ); 

        onumm5n1_mul_oo_to(
            &arr1->p_data[1],
            &arr1->p_data[2],
            &tmp2   ); 

        onumm5n1_sub_oo_to(
            &tmp1,
            &tmp2,
            res);

    } else if (arr1->ncols >= 3){
        
        // tmp3 = 0
        onumm5n1_set_r( 0.0, &tmp3);

        for (j=0; j<arr1->ncols; j++){
            
            // tmp1 = arr1->p_data[j]
            onumm5n1_set_o(&arr1->p_data[j], &tmp1);

            for (i=1; i<arr1->nrows; i++){        
                
                //tmp2 = tmp1 * arr1->p_data[ ( (i+j)%arr1->ncols ) + i*arr1->ncols];
                onumm5n1_mul_oo_to(
                    &tmp1,
                    &arr1->p_data[ ( (i+j)%arr1->ncols ) + i*arr1->ncols],
                    &tmp2   ); 

                onumm5n1_set_o( &tmp2, &tmp1);

            }

            // tmp2 = tmp3 + tmp1;
            onumm5n1_sum_oo_to(
                &tmp1,
                &tmp3,
                &tmp2   );

            // tmp3 = tmp2;
            onumm5n1_set_o( &tmp2, &tmp3);             

        }
        
        for ( j = 0; j<arr1->ncols; j++){
            
            // tmp1 = arr1->p_data[arr1->ncols-1-j];
            onumm5n1_set_o(&arr1->p_data[arr1->ncols-1-j], &tmp1);
            
            for ( i = 1; i<arr1->nrows; i++){        
                
                // tmp1 *= arr1->p_data[ (arr1->ncols-1 - (i+j)%arr1->ncols ) + i*arr1->ncols];
                onumm5n1_mul_oo_to(
                    &tmp1,
                    &arr1->p_data[ (arr1->ncols-1 - (i+j)%arr1->ncols ) + i*arr1->ncols],
                    &tmp2   ); 

                onumm5n1_set_o( &tmp2, &tmp1);

            }

            // tmp2 = tmp3 - tmp1;
            onumm5n1_sub_oo_to(
                &tmp3,
                &tmp1,
                &tmp2   );

            // tmp3 = tmp2;
            onumm5n1_set_o( &tmp2, &tmp3);  

        }

        // res = tmp3
        onumm5n1_set_o(&tmp3, res);

    }

}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm

// ****************************************************************************************************
void oarrm5n1_norm_to(oarrm5n1_t* arr1, onumm5n1_t* res){
    
    
    uint64_t i;
    onumm5n1_t tmp1, tmp2, tmp3;
    
    onumm5n1_set_r( 0.0, &tmp3);    
    // 
    for( i = 0; i<arr1->size; i++){

        // tmp1 = (arr1->p_data[i])^2.0;
        onumm5n1_pow_to( &arr1->p_data[i], 2.0, &tmp1);
        
        // tmp2 = tmp3 + tmp1;
        onumm5n1_sum_oo_to( &tmp1, &tmp3, &tmp2);

        // tmp3 = tmp2;
        onumm5n1_set_o( &tmp2, &tmp3);
    
    }

    // res = sqrt(tmp3);
    onumm5n1_sqrt_to(&tmp3, res);
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm5n1_pnorm_to(oarrm5n1_t* arr1, coeff_t p, onumm5n1_t* res){
    
    
    uint64_t i;
    onumm5n1_t tmp1, tmp2, tmp3;
    
    onumm5n1_set_r( 0.0, &tmp3);    
    // 
    for( i = 0; i<arr1->size; i++){

        // tmp1 = (arr1->p_data[i])^p;
        onumm5n1_abs_to( &arr1->p_data[i], &tmp2);
        onumm5n1_pow_to( &tmp2, p, &tmp1);
        
        // tmp2 = tmp3 + tmp1;
        onumm5n1_sum_oo_to( &tmp1, &tmp3, &tmp2);

        // tmp3 = tmp2;
        onumm5n1_set_o( &tmp2, &tmp3);
    
    }

    // res = (tmp3)^(1/p);
    onumm5n1_pow_to(&tmp3, 1.0/p, res);
    
}
// ----------------------------------------------------------------------------------------------------
