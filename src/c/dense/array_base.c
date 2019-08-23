// void oarr_set_all_r( coeff_t num, oarr_t* arr, dhelpl_t dhl);
// void oarr_set_item_i_r( coeff_t num, uint64_t i, oarr_t* arr, dhelpl_t dhl);
// void oarr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl);
// void oarr_set_all_o( otinum_t* num, oarr_t* arr, dhelpl_t dhl);
// void oarr_set_item_i_o( otinum_t* num, uint64_t i, oarr_t* arr, dhelpl_t dhl);
// void oarr_set_item_ij_o( otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl);
// otinum_t oarr_get_item_i(oarr_t* arr, uint64_t i, dhelpl_t dhl);
// otinum_t oarr_get_item_ij(oarr_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl);
// void oarr_get_item_i_to(oarr_t* p_array, uint64_t i, uint64_t j, otinum_t* res, dhelpl_t dhl);
// void oarr_get_item_ij_to(oarr_t* p_array, uint64_t i, uint64_t j, otinum_t* res, dhelpl_t dhl);
// oarr_t oarr_copy_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_copy(oarr_t* arr, dhelpl_t dhl);
// oarr_t oarr_ones(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order);
// oarr_t oarr_zeros(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order);
// void oarr_free(oarr_t* arr);
// oarr_t oarr_createEmpty( uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order);




// Setters.

// Setter by one index.

// ****************************************************************************************************
void oarr_set_all_r( coeff_t num, oarr_t* arr, dhelpl_t dhl){
    
    darr_t tmp_arr;

    ord_t ordi;
    uint64_t k;

    // Initialize common properties.
    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;

    // Set real part
    tmp_arr.p_data = arr->re;

    // Set the coefficient to the array.
    darr_set_all(num, &tmp_arr);
    
    for (ordi = 0; ordi < arr->order; ordi++){

        for( k = 0; k < arr->p_ndpo[ordi]; k++){

            // Extract the imaginary coefficient from num.

            tmp_arr.p_data = arr->p_im[ordi][k];

            // Set the item to the array.
            darr_set_all(0.0, &tmp_arr);

        }

    }
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void oarr_set_item_i_r( coeff_t num, uint64_t i, oarr_t* arr, dhelpl_t dhl){
    
    darr_t tmp_arr;

    ord_t ordi;
    uint64_t k;

    // Initialize common properties.
    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;

    // Set real part
    tmp_arr.p_data = arr->re;

    // Set the coefficient to the array.
    darr_set_item_i(num, i, &tmp_arr);
    
    for (ordi = 0; ordi < arr->order; ordi++){

        for( k = 0; k < arr->p_ndpo[ordi]; k++){

            tmp_arr.p_data = arr->p_im[ordi][k];

            // Set the item to the array.
            darr_set_item_i(0.0, i, &tmp_arr);

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void oarr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl){
    
    darr_t tmp_arr;
    
    ord_t ordi;
    uint64_t k;

    // Initialize common properties.
    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;

    // Set real part
    tmp_arr.p_data = arr->re;

    // Set the coefficient to the array.
    darr_set_item_ij(num, i, j, &tmp_arr);
    
    for (ordi = 0; ordi < arr->order; ordi++){

        for( k = 0; k < arr->p_ndpo[ordi]; k++){

            tmp_arr.p_data = arr->p_im[ordi][k];

            // Set the item to the array.
            darr_set_item_ij(0.0, i, j, &tmp_arr);

        }

    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void oarr_set_all_o( otinum_t* num, oarr_t* arr, dhelpl_t dhl){
    
    darr_t tmp_arr;
    coeff_t  val;

    ord_t ordi;
    uint64_t k;

    // Initialize common properties.
    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;

    // Set real part
    tmp_arr.p_data = arr->re;

    // Extract the imaginary coefficient from num.
    val = oti_get( 0,0, num, dhl);

    // Set the coefficient to the array.
    darr_set_all(val, &tmp_arr);
    
    for (ordi = 0; ordi < arr->order; ordi++){

        for( k = 0; k < arr->p_ndpo[ordi]; k++){

            // Extract the imaginary coefficient from num.
            val = oti_get( k, ordi+1, num, dhl);

            tmp_arr.p_data = arr->p_im[ordi][k];

            // Set the item to the array.
            darr_set_all(val, &tmp_arr);

        }

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_set_item_i_o( otinum_t* num, uint64_t i, oarr_t* arr, dhelpl_t dhl){
    
    darr_t tmp_arr;
    coeff_t  val;

    ord_t ordi;
    uint64_t k;

    // Initialize common properties.
    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;

    // Set real part
    tmp_arr.p_data = arr->re;

    // Extract the imaginary coefficient from num.
    val = oti_get( 0,0, num, dhl);

    // Set the coefficient to the array.
    darr_set_item_i(val, i, &tmp_arr);
    
    for (ordi = 0; ordi < arr->order; ordi++){

        for( k = 0; k < arr->p_ndpo[ordi]; k++){

            // Extract the imaginary coefficient from num.
            val = oti_get( k, ordi+1, num, dhl);

            tmp_arr.p_data = arr->p_im[ordi][k];

            // Set the item to the array.
            darr_set_item_i(val, i, &tmp_arr);

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void oarr_set_item_ij_o( otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl){
    
    darr_t tmp_arr;
    coeff_t  val;

    ord_t ordi;
    uint64_t k;

    // Initialize common properties.
    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;

    // Set real part
    tmp_arr.p_data = arr->re;

    // Extract the imaginary coefficient from num.
    val = oti_get( 0,0, num, dhl);

    // Set the coefficient to the array.
    darr_set_item_ij(val, i, j, &tmp_arr);
    
    for (ordi = 0; ordi < arr->order; ordi++){

        for( k = 0; k < arr->p_ndpo[ordi]; k++){

            // Extract the imaginary coefficient from num.
            val = oti_get( k, ordi+1, num, dhl);

            tmp_arr.p_data = arr->p_im[ordi][k];

            // Set the item to the array.
            darr_set_item_ij(val, i, j, &tmp_arr);

        }

    }

}
// ----------------------------------------------------------------------------------------------------


















// Getters.


// ****************************************************************************************************
otinum_t oarr_get_item_i(oarr_t* arr, uint64_t i, dhelpl_t dhl){
    
    otinum_t res = oti_createEmpty(  arr->nbases, arr->order, dhl );
    darr_t tmp_arr;
    coeff_t  val;

    ord_t ordi;
    uint64_t k;

    // Initialize common properties.
    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;

    // Set real part
    tmp_arr.p_data = arr->re;
    val = darr_get_item_i(&tmp_arr, i);
    oti_setIm_IdxOrd( val, 0, 0, &res, dhl);

    for (ordi = 0; ordi < arr->order; ordi++){

        for( k = 0; k < arr->p_ndpo[ordi]; k++){

            tmp_arr.p_data = arr->p_im[ordi][k];

            val = darr_get_item_i(&tmp_arr, i);

            oti_setIm_IdxOrd( val, k, ordi+1, &res, dhl);

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oarr_get_item_ij(oarr_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl){
    
    otinum_t res = oti_createEmpty(  arr->nbases, arr->order, dhl );
    darr_t tmp_arr;
    coeff_t  val;

    ord_t ordi;
    uint64_t k;

    // Initialize common properties.
    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;

    // Set real part
    tmp_arr.p_data = arr->re;
    val = darr_get_item_ij(&tmp_arr, i, j);
    oti_setIm_IdxOrd( val, 0, 0, &res, dhl);

    for (ordi = 0; ordi < arr->order; ordi++){

        for( k = 0; k < arr->p_ndpo[ordi]; k++){

            tmp_arr.p_data = arr->p_im[ordi][k];

            val = darr_get_item_ij(&tmp_arr, i, j);

            oti_setIm_IdxOrd( val, k, ordi+1, &res, dhl);

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void oarr_get_item_i_to(oarr_t* arr, uint64_t i,  otinum_t* res, dhelpl_t dhl){
    
    // Reset all coefficients in res.
    oti_setFromReal( 0.0, res, dhl );

    darr_t tmp_arr;
    coeff_t  val;

    ord_t ordi;
    uint64_t k;

    // Initialize common properties.
    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;

    // Set real part
    tmp_arr.p_data = arr->re;
    val = darr_get_item_i(&tmp_arr, i);
    oti_setIm_IdxOrd( val, 0, 0, res, dhl);

    for (ordi = 0; ordi < arr->order; ordi++){

        for( k = 0; k < arr->p_ndpo[ordi]; k++){

            tmp_arr.p_data = arr->p_im[ordi][k];

            val = darr_get_item_i(&tmp_arr, i );

            oti_setIm_IdxOrd( val, k, ordi+1, res, dhl);

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_get_item_ij_to(oarr_t* arr, uint64_t i, uint64_t j, otinum_t* res, dhelpl_t dhl){
    
    // Reset all coefficients in res.
    oti_setFromReal( 0.0, res, dhl );

    darr_t tmp_arr;
    coeff_t  val;

    ord_t ordi;
    uint64_t k;

    // Initialize common properties.
    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;

    // Set real part
    tmp_arr.p_data = arr->re;
    val = darr_get_item_ij(&tmp_arr, i, j);
    oti_setIm_IdxOrd( val, 0, 0, res, dhl);

    for (ordi = 0; ordi < arr->order; ordi++){

        for( k = 0; k < arr->p_ndpo[ordi]; k++){

            tmp_arr.p_data = arr->p_im[ordi][k];

            val = darr_get_item_ij(&tmp_arr, i, j);

            oti_setIm_IdxOrd( val, k, ordi+1, res, dhl);

        }

    }

}
// ----------------------------------------------------------------------------------------------------

























// Copy operations.

// ****************************************************************************************************
void oarr_copy_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl){
    
    uint64_t i;

    darr_t tmp_arr1, tmp_arr2; // Temporal real array.
    ord_t ordi; 

    tmp_arr1.ncols = arr->ncols;
    tmp_arr1.nrows = arr->nrows;
    tmp_arr1.size  = arr->size ;

    tmp_arr2.ncols = arr->ncols;
    tmp_arr2.nrows = arr->nrows;
    tmp_arr2.size  = arr->size ;

    // TODO: Check memory.

    // Initialize real direction.
    tmp_arr1.p_data = arr->re;
    tmp_arr2.p_data = res->re;

    darr_copy_to( &tmp_arr1, &tmp_arr2 );
    
    if (res->order != 0){
            
        for (ordi = 0; ordi<res->order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res->p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr->p_im[ordi][i];
                tmp_arr2.p_data = res->p_im[ordi][i];

                darr_copy_to( &tmp_arr1, &tmp_arr2 );

            }

        }

    } else {

        // Set pointer to null
        res->p_im = NULL;   
        res->p_ndpo = NULL;     
    }
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
oarr_t oarr_copy(oarr_t* arr, dhelpl_t dhl){
    
    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr->ncols;
    res.nrows  = arr->nrows;
    res.size   = arr->size ;



    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr->order;
    res.nbases = arr->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr->re;
    tmp_arr2 =  darr_copy(&tmp_arr1);
    res.re = tmp_arr2.p_data; //  Comes newly allocated.
    
    if (res.order != 0){
            
        // Allocate memory.
        res.p_im   = ( arr_t** ) malloc( res.order*sizeof(arr_t*) );
        res.p_ndpo = (  ndir_t*  ) malloc( res.order*sizeof(ndir_t) );

        if (res.p_im == NULL  || res.p_ndpo == NULL ){
            printf("--- ERROR: Out of memory\n");
            exit(OTI_OutOfMemory);
        }

        for (ordi = 0; ordi<res.order; ordi++){

            res.p_ndpo[ordi] = arr->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr->p_im[ordi][i];
                tmp_arr2 = darr_copy( &tmp_arr1);

                res.p_im[ordi][i] = tmp_arr2.p_data;

            }

        }

    } else {

        // Set pointer to null
        res.p_im = NULL;   
        res.p_ndpo = NULL;     
    }
    
    return res;
    
}
// ----------------------------------------------------------------------------------------------------































// Helpers.

















// Memory management.

// ****************************************************************************************************
oarr_t oarr_ones(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl){
    
    uint64_t i;
    oarr_t res;

    darr_t tmp_arr; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    // Array specific attributes: arr
    res.ncols  = ncols;
    res.nrows  = nrows;
    res.size   = ncols * nrows;

    // Get the number of imaginary directions for nbases and order.
    res.ndir = 0; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = order;
    res.nbases = nbases;


    // Initialize real direction.
    tmp_arr = darr_ones(res.nrows,res.ncols);
    res.re = tmp_arr.p_data;
    
    if (res.order != 0){
            
        // Allocate memory.
        res.p_im   = ( arr_t** ) malloc( res.order*sizeof(arr_t*) );
        res.p_ndpo = (  ndir_t*  ) malloc( res.order*sizeof(ndir_t) );

        if (res.p_im == NULL  || res.p_ndpo == NULL ){
            printf("--- ERROR: Out of memory\n");
            exit(OTI_OutOfMemory);
        }

        for (ordi = 0; ordi<res.order; ordi++){

            res.p_ndpo[ordi] = dhelp_extract_ndirOrder( res.nbases, ordi+1, dhl );
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );

            res.ndir += res.p_ndpo[ordi];

            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr = darr_zeros(res.nrows,res.ncols);

                res.p_im[ordi][i] = tmp_arr.p_data;

            }

        }

    } else {

        // Set pointer to null
        res.p_im = NULL;   
        res.p_ndpo = NULL;     
    }
    
    return res;
    
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
oarr_t oarr_zeros(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl){
    
    uint64_t i;
    oarr_t res;

    darr_t tmp_arr; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    // Array specific attributes: arr
    res.ncols  = ncols;
    res.nrows  = nrows;
    res.size   = ncols * nrows;

    // Get the number of imaginary directions for nbases and order.
    res.ndir = 0; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = order;
    res.nbases = nbases;


    // Initialize real direction.
    tmp_arr = darr_zeros(res.nrows,res.ncols);
    res.re = tmp_arr.p_data;
    
    if (res.order != 0){
            
        // Allocate memory.
        res.p_im   = ( arr_t** ) malloc( res.order*sizeof(arr_t*) );
        res.p_ndpo = (  ndir_t*  ) malloc( res.order*sizeof(ndir_t) );

        if (res.p_im == NULL  || res.p_ndpo == NULL ){
            printf("--- ERROR: Out of memory\n");
            exit(OTI_OutOfMemory);
        }

        for (ordi = 0; ordi<res.order; ordi++){

            res.p_ndpo[ordi] = dhelp_extract_ndirOrder( res.nbases, ordi+1, dhl );
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );

            res.ndir += res.p_ndpo[ordi];

            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr = darr_zeros(res.nrows,res.ncols);

                res.p_im[ordi][i] = tmp_arr.p_data;

            }

        }

    } else {

        // Set pointer to null
        res.p_im = NULL;   
        res.p_ndpo = NULL;     
    }
    
    return res;
    
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void oarr_free(oarr_t* arr){
    
    uint64_t i;

    ord_t ordi ;
    darr_t tmp_arr; // Temporal real array.

    // Free real direction
    tmp_arr.p_data = arr->re;
    darr_free(&tmp_arr);


    if (arr->p_im != NULL){


        for ( ordi = 0; ordi<arr->order; ordi++){

            // Free each array memory.
            for( i = 0; i < arr->p_ndpo[ordi]; i++){

                tmp_arr.p_data = arr->p_im[ordi][i];

                darr_free(&tmp_arr);

            }

            free( arr->p_im[ordi] );

        }

        free(arr->p_ndpo);
        free(arr->p_im);

        arr->p_im = NULL;

    }

    // Set all other values as 0.
    arr->ndir   = 0;
    arr->re     = 0;
    arr->nbases = 0;
    arr->order  = 0;

    arr->ncols  = 0;
    arr->nrows  = 0;
    arr->size   = 0;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_createEmpty( uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl){
    
    oarr_t res;
    darr_t tmp_arr; // Temporal real array.
    ord_t ordi; 
    uint64_t i;


    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = ncols;
    res.nrows  = nrows;
    res.size   = ncols*nrows;

    // Get the number of imaginary directions for nbases and order.
    res.ndir = 0; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = order;
    res.nbases = nbases;


    // Initialize real direction.
    tmp_arr =  darr_createEmpty(res.nrows, res.ncols);
    res.re = tmp_arr.p_data;
    
    if (res.order != 0){
            
        // Allocate memory.
        res.p_im   = ( arr_t** ) malloc( res.order*sizeof(arr_t*) );
        res.p_ndpo = (  ndir_t*  ) malloc( res.order*sizeof(ndir_t) );

        if (res.p_im == NULL  || res.p_ndpo == NULL ){
            printf("--- ERROR: Out of memory\n");
            exit(OTI_OutOfMemory);
        }

        for (ordi = 0; ordi<res.order; ordi++){

            res.p_ndpo[ordi] = dhelp_extract_ndirOrder( res.nbases, ordi+1, dhl );
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );
            
            res.ndir += res.p_ndpo[ordi];


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr =  darr_createEmpty(res.nrows, res.ncols);

                res.p_im[ordi][i] = tmp_arr.p_data;

            }

        }

    } else {

        // Set pointer to null
        res.p_im = NULL;   
        res.p_ndpo = NULL;     
    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


