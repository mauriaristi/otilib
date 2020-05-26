



// 2. Array operations.


// 2.1. Inner product.

// ****************************************************************************************************
darr_t darr_matmul(darr_t* arr1, darr_t* arr2 ){

    darr_t aRes;
    uint64_t i, j, k;
    coeff_t tmp1;

    // Check correctness of dimensions:
    if( (arr1->ncols != arr2->nrows) ){
        printf("--- DimensionError in matrix sum ---\n");
        exit(1);
    }

    aRes = darr_createEmpty( arr1->nrows, arr2->ncols);

    for (i=0; i<arr1->nrows; i++){
        
        for(j=0; j<arr2->ncols; j++){
                
            tmp1 = 0;

            for(k=0; k<arr1->ncols; k++){

                tmp1 += arr1->p_data[k+i*arr1->ncols] * arr2->p_data[j+k*arr2->ncols];

            }

            darr_set_item_ij( tmp1, i, j, &aRes);

        }

    }
    
    return aRes;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darr_matmul_to(darr_t* arr1, darr_t* arr2, darr_t* aRes ){

    uint64_t i, j, k;
    coeff_t tmp1;

    // Check correctness of dimensions:
    // if( (arr1->ncols != arr2->nrows) ){
    //     printf("--- DimensionError in matrix sum ---\n");
    //     exit(1);
    // }
    // if (aRes->p_data == NULL){
    //     soarr_zeros( aRes, arr1->nrows, arr2->ncols, arr2->order);
    // }
    for (i = 0; i<arr1->nrows; i++){
        
        for(j = 0; j<arr2->ncols; j++){
                
            tmp1 = 0;

            for(k=0; k<arr1->ncols; k++){

                tmp1 += arr1->p_data[k+i*arr1->ncols] * arr2->p_data[j+k*arr2->ncols];

            }

            darr_set_item_ij( tmp1, i, j, aRes);

        }

    }    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darr_matmul_and_selfsum_RR_to(darr_t* arr1, darr_t* arr2, darr_t* res ){

    uint64_t i, j, k;
    coeff_t tmp1;

    for (i = 0; i<arr1->nrows; i++){
        
        for(j = 0; j<arr2->ncols; j++){
                
            tmp1 = 0;

            for(k=0; k<arr1->ncols; k++){

                tmp1 += arr1->p_data[k+i*arr1->ncols] * arr2->p_data[j+k*arr2->ncols];

            }

            res->p_data[ j + i * res->ncols] += tmp1;

        }

    }    

}
// ----------------------------------------------------------------------------------------------------




// 2.2. Transpose.
// ****************************************************************************************************
darr_t darr_transpose(darr_t* arr1){
    
    uint64_t i, j;

    darr_t aRes = darr_createEmpty( arr1->ncols, arr1->nrows);

    for (i=0; i<arr1->nrows; i++){

        for (j=0; j<arr1->ncols; j++){
            
            darr_set_item_ij( darr_get_item_ij(arr1, i, j), j, i, &aRes);

        }

    }

    return aRes;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void darr_transpose_to(darr_t* arr1, darr_t* aRes){
    
    uint64_t i, j;

    // if (aRes->p_data == NULL){
    //     soarr_zeros( aRes, arr1->nrows, arr1->ncols, arr1->order);
    // }

    for (i=0; i<arr1->nrows; i++){

        for (j=0; j<arr1->ncols; j++){
            
            darr_set_item_ij( darr_get_item_ij(arr1, i, j), j, i, aRes);

        }

    }

}
// ----------------------------------------------------------------------------------------------------







// 2.3. Inversion.

// ****************************************************************************************************
darr_t darr_invert(darr_t* arr1){
    
    darr_t aRes;
    coeff_t det;
    
    darr_t tmpA1;


    if (arr1->ncols != arr1->nrows){
        printf("--- DimensionError in matrix inverse. Only square matrices are invertible. ---\n");
        exit(1);
    }

    aRes = darr_createEmpty(arr1->nrows, arr1->ncols);

    if(arr1->ncols == 1){

        aRes.p_data[0] = 1.0/arr1->p_data[0];

    } else if (arr1->ncols == 2){

        det = darr_det(arr1) ; // Get determinant.
        
        aRes.p_data[0] =  arr1->p_data[3]/det;
        aRes.p_data[1] = -arr1->p_data[1]/det;
        aRes.p_data[2] = -arr1->p_data[2]/det;
        aRes.p_data[3] =  arr1->p_data[0]/det;

    } else if (arr1->ncols == 3){
        
        // Create temporal.

        tmpA1 = darr_zeros( 2, 2 );
        
        det = darr_det( arr1 ); // Get determinant.
        

        // Set position 0,0
        tmpA1.p_data[0] = arr1->p_data[4];
        tmpA1.p_data[1] = arr1->p_data[5];
        tmpA1.p_data[2] = arr1->p_data[7];
        tmpA1.p_data[3] = arr1->p_data[8];

        aRes.p_data[0] = darr_det( &tmpA1 )/det;

        

        // Set position 0,1
        tmpA1.p_data[0] = arr1->p_data[2];
        tmpA1.p_data[1] = arr1->p_data[1];
        tmpA1.p_data[2] = arr1->p_data[8];
        tmpA1.p_data[3] = arr1->p_data[7];
        
        aRes.p_data[1] = darr_det( &tmpA1 )/det;




        // Set position 0,2
        tmpA1.p_data[0] = arr1->p_data[1];
        tmpA1.p_data[1] = arr1->p_data[2];
        tmpA1.p_data[2] = arr1->p_data[4];
        tmpA1.p_data[3] = arr1->p_data[5];
        
        aRes.p_data[2] = darr_det( &tmpA1 )/det;



        // Set position 1,0
        tmpA1.p_data[0] = arr1->p_data[5];
        tmpA1.p_data[1] = arr1->p_data[3];
        tmpA1.p_data[2] = arr1->p_data[8];
        tmpA1.p_data[3] = arr1->p_data[6];
        
        aRes.p_data[3] = darr_det( &tmpA1 )/det;

        // Set position 1,1
        tmpA1.p_data[0] = arr1->p_data[0];
        tmpA1.p_data[1] = arr1->p_data[2];
        tmpA1.p_data[2] = arr1->p_data[6];
        tmpA1.p_data[3] = arr1->p_data[8];
        

        aRes.p_data[4] = darr_det( &tmpA1 )/det;

        // Set position 1,2
        tmpA1.p_data[0] = arr1->p_data[2];
        tmpA1.p_data[1] = arr1->p_data[0];
        tmpA1.p_data[2] = arr1->p_data[5];
        tmpA1.p_data[3] = arr1->p_data[3];
        
        aRes.p_data[5] = darr_det( &tmpA1 )/det;



        // Set position 2,0
        tmpA1.p_data[0] = arr1->p_data[3];
        tmpA1.p_data[1] = arr1->p_data[4];
        tmpA1.p_data[2] = arr1->p_data[6];
        tmpA1.p_data[3] = arr1->p_data[7];
        
        aRes.p_data[6] = darr_det( &tmpA1 )/det;



        // Set position 2,1
        tmpA1.p_data[0] = arr1->p_data[1];
        tmpA1.p_data[1] = arr1->p_data[0];
        tmpA1.p_data[2] = arr1->p_data[7];
        tmpA1.p_data[3] = arr1->p_data[6];
        
        aRes.p_data[7] = darr_det( &tmpA1 )/det;



        // Set position 2,2
        tmpA1.p_data[0] = arr1->p_data[0];
        tmpA1.p_data[1] = arr1->p_data[1];
        tmpA1.p_data[2] = arr1->p_data[3];
        tmpA1.p_data[3] = arr1->p_data[4];
        

        aRes.p_data[8] = darr_det( &tmpA1 )/det;

        darr_free(&tmpA1);

    }    

    return aRes;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void darr_invert_to(darr_t* arr1, darr_t* aRes){
    
    coeff_t det;
    
    darr_t tmpA1;


    if (arr1->ncols != arr1->nrows){
        printf("--- DimensionError in matrix inverse. Only square matrices are invertible. ---\n");
        exit(1);
    }

    if(arr1->ncols == 1){

        aRes->p_data[0] = 1.0/arr1->p_data[0];

    } else if (arr1->ncols == 2){

        det = darr_det(arr1) ; // Get determinant.
        
        aRes->p_data[0] =  arr1->p_data[3]/det;
        aRes->p_data[1] = -arr1->p_data[1]/det;
        aRes->p_data[2] = -arr1->p_data[2]/det;
        aRes->p_data[3] =  arr1->p_data[0]/det;

    } else if (arr1->ncols == 3){
    	
    	tmpA1 = darr_zeros( 2, 2 );
        
        det = darr_det( arr1 ); // Get determinant.
        

        // Set position 0,0
        tmpA1.p_data[0] = arr1->p_data[4];
        tmpA1.p_data[1] = arr1->p_data[5];
        tmpA1.p_data[2] = arr1->p_data[7];
        tmpA1.p_data[3] = arr1->p_data[8];

        aRes->p_data[0] = darr_det( &tmpA1 )/det;

        

        // Set position 0,1
        tmpA1.p_data[0] = arr1->p_data[2];
        tmpA1.p_data[1] = arr1->p_data[1];
        tmpA1.p_data[2] = arr1->p_data[8];
        tmpA1.p_data[3] = arr1->p_data[7];
        
        aRes->p_data[1] = darr_det( &tmpA1 )/det;




        // Set position 0,2
        tmpA1.p_data[0] = arr1->p_data[1];
        tmpA1.p_data[1] = arr1->p_data[2];
        tmpA1.p_data[2] = arr1->p_data[4];
        tmpA1.p_data[3] = arr1->p_data[5];
        
        aRes->p_data[2] = darr_det( &tmpA1 )/det;



        // Set position 1,0
        tmpA1.p_data[0] = arr1->p_data[5];
        tmpA1.p_data[1] = arr1->p_data[3];
        tmpA1.p_data[2] = arr1->p_data[8];
        tmpA1.p_data[3] = arr1->p_data[6];
        
        aRes->p_data[3] = darr_det( &tmpA1 )/det;

        // Set position 1,1
        tmpA1.p_data[0] = arr1->p_data[0];
        tmpA1.p_data[1] = arr1->p_data[2];
        tmpA1.p_data[2] = arr1->p_data[6];
        tmpA1.p_data[3] = arr1->p_data[8];
        

        aRes->p_data[4] = darr_det( &tmpA1 )/det;

        // Set position 1,2
        tmpA1.p_data[0] = arr1->p_data[2];
        tmpA1.p_data[1] = arr1->p_data[0];
        tmpA1.p_data[2] = arr1->p_data[5];
        tmpA1.p_data[3] = arr1->p_data[3];
        
        aRes->p_data[5] = darr_det( &tmpA1 )/det;



        // Set position 2,0
        tmpA1.p_data[0] = arr1->p_data[3];
        tmpA1.p_data[1] = arr1->p_data[4];
        tmpA1.p_data[2] = arr1->p_data[6];
        tmpA1.p_data[3] = arr1->p_data[7];
        
        aRes->p_data[6] = darr_det( &tmpA1 )/det;



        // Set position 2,1
        tmpA1.p_data[0] = arr1->p_data[1];
        tmpA1.p_data[1] = arr1->p_data[0];
        tmpA1.p_data[2] = arr1->p_data[7];
        tmpA1.p_data[3] = arr1->p_data[6];
        
        aRes->p_data[7] = darr_det( &tmpA1 )/det;



        // Set position 2,2
        tmpA1.p_data[0] = arr1->p_data[0];
        tmpA1.p_data[1] = arr1->p_data[1];
        tmpA1.p_data[2] = arr1->p_data[3];
        tmpA1.p_data[3] = arr1->p_data[4];
        

        aRes->p_data[8] = darr_det( &tmpA1 )/det;

        darr_free(&tmpA1);

    }    

}
// ----------------------------------------------------------------------------------------------------






















// 2.4. Determinant.

// ****************************************************************************************************
coeff_t darr_det( darr_t* arr1 ){
    
    uint64_t i, j ;
    coeff_t tmp1, res = 0.0;

    if (arr1->ncols != arr1->nrows){
        printf("--- DimensionError in matrix determinant. Only square matrices are valid. ---\n");
        exit(1);
    }

    if ( arr1->ncols == 1 ){

        res = arr1->p_data[0];

    } else if (arr1->ncols == 2){

		res = arr1->p_data[0]*arr1->p_data[3] - arr1->p_data[1]*arr1->p_data[2];

    } else if (arr1->ncols >= 3){

        for (j=0; j<arr1->ncols; j++){
            
            tmp1 = arr1->p_data[j];

            for (i=1; i<arr1->nrows; i++){        
                
                tmp1 *= arr1->p_data[ ( (i+j)%arr1->ncols ) + i*arr1->ncols];

            }

            res += tmp1;

        }

        for (j=0; j<arr1->ncols; j++){
            
            tmp1 = arr1->p_data[arr1->ncols-1-j];
            
            for (i=1; i<arr1->nrows; i++){        
                
                tmp1 *= arr1->p_data[ (arr1->ncols-1 - (i+j)%arr1->ncols ) + i*arr1->ncols];

            }

            res -= tmp1;

        }

    }
    return res;
}
// ----------------------------------------------------------------------------------------------------













// 2.4. Determinant.

// ****************************************************************************************************
coeff_t darr_pnorm( darr_t* arr1, coeff_t p ){
    
    uint64_t i;
    coeff_t res = 0.0;

    for ( i = 0; i < arr1->size; i++){

        res += pow( arr1->p_data[i], p );

    }

    res = pow(res,1.0/p);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
coeff_t darr_norm( darr_t* arr1 ){
    
    return darr_pnorm( arr1, 2.0 );
}
// ----------------------------------------------------------------------------------------------------


