
// oarr_t oarr_neg( oarr_t* arr1  dhelpl_t dhl);
// void oarr_neg_to(oarr_t* arr1, oarr_t* res, dhelpl_t dhl);

// oarr_t oarr_sum_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
// void oarr_sum_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_sum_oO(otinum_t num, oarr_t* arr1, dhelpl_t dhl);
// void oarr_sum_oO_to(otinum_t num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_sum_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
// void oarr_sum_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_sum_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
// void oarr_sum_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);

// oarr_t oarr_sub_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
// void oarr_sub_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_sub_oO(otinum_t num, oarr_t* arr1, dhelpl_t dhl);
// void oarr_sub_oO_to(otinum_t num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_sub_Oo(oarr_t* arr1, otinum_t num, dhelpl_t dhl);
// void oarr_sub_Oo_to(oarr_t* arr1, otinum_t num, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_sub_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
// void oarr_sub_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_sub_OR(oarr_t* arr1, darr_t* arr2, dhelpl_t dhl);
// void oarr_sub_OR_to(oarr_t* arr1, darr_t* arr2, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_sub_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
// void oarr_sub_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_sub_Or( oarr_t* arr1, coeff_t num, dhelpl_t dhl);
// void oarr_sub_Or_to( oarr_t* arr1, coeff_t num, oarr_t* res, dhelpl_t dhl);

// oarr_t oarr_mul_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
// void oarr_mul_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_mul_oO(otinum_t num, oarr_t* arr1, dhelpl_t dhl);
// void oarr_mul_oO_to(otinum_t num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_mul_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
// void oarr_mul_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_mul_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
// void oarr_mul_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);

// oarr_t oarr_div_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
// void oarr_div_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_div_oO(otinum_t num, oarr_t* arr1, dhelpl_t dhl);
// void oarr_div_oO_to(otinum_t num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_div_Oo(oarr_t* arr1, otinum_t num, dhelpl_t dhl);
// void oarr_div_Oo_to(oarr_t* arr1, otinum_t num, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_div_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
// void oarr_div_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_div_OR(oarr_t* arr1, darr_t* arr2, dhelpl_t dhl);
// void oarr_div_OR_to(oarr_t* arr1, darr_t* arr2, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_div_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
// void oarr_div_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
// oarr_t oarr_div_Or( oarr_t* arr1, coeff_t num, dhelpl_t dhl);
// void oarr_div_Or_to( oarr_t* arr1, coeff_t num, oarr_t* res, dhelpl_t dhl);






// 1. Elementwise operations.
// 1.1. Negation.

// ****************************************************************************************************
oarr_t oarr_neg(oarr_t* arr,   dhelpl_t dhl){ 

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
    tmp_arr2 =  darr_neg(&tmp_arr1);
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
                tmp_arr2 = darr_neg( &tmp_arr1);

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

// ****************************************************************************************************
void oarr_neg_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl){ 

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

    darr_neg_to( &tmp_arr1, &tmp_arr2 );
    
    if (res->order != 0){
            
        for (ordi = 0; ordi<res->order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res->p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr->p_im[ordi][i];
                tmp_arr2.p_data = res->p_im[ordi][i];

                darr_neg_to( &tmp_arr1, &tmp_arr2 );

            }

        }

    } else {

        // Set pointer to null
        res->p_im = NULL;   
        res->p_ndpo = NULL;     
    }

}
// ----------------------------------------------------------------------------------------------------



// 1.2. Addition.
// 1.2.1. OTI Array - OTI Array.
// 1.2.2. OTI Array - Real Array.
// 1.2.3. OTI Array - OTI Scalar.
// 1.2.3. OTI Array - Real Scalar.

// ****************************************************************************************************
oarr_t oarr_sum_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2, tmp_arr3; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr1->ncols;
    res.nrows  = arr1->nrows;
    res.size   = arr1->size ;


    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr1->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr1->order;
    res.nbases = arr1->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    tmp_arr3.ncols = res.ncols;
    tmp_arr3.nrows = res.nrows;
    tmp_arr3.size  = res.size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr1->re;
    tmp_arr3.p_data = arr2->re;
    tmp_arr2 =  darr_sum_RR(&tmp_arr1,&tmp_arr3);
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

            res.p_ndpo[ordi] = arr1->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr1->p_im[ordi][i];
                tmp_arr3.p_data = arr2->p_im[ordi][i];

                tmp_arr2 = darr_sum_RR(&tmp_arr1,&tmp_arr3);

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


// ****************************************************************************************************
void oarr_sum_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl){

    uint64_t i;

    darr_t tmp_arr1 , tmp_arr2, tmp_arr3; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    tmp_arr1.ncols = res->ncols;
    tmp_arr1.nrows = res->nrows;
    tmp_arr1.size  = res->size ;

    tmp_arr3.ncols = res->ncols;
    tmp_arr3.nrows = res->nrows;
    tmp_arr3.size  = res->size ;

    tmp_arr3.ncols = res->ncols;
    tmp_arr3.nrows = res->nrows;
    tmp_arr3.size  = res->size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr1->re;
    tmp_arr3.p_data = arr2->re;
    tmp_arr2.p_data = res->re;
    darr_sum_RR_to(&tmp_arr1,&tmp_arr3, &tmp_arr2);
    
    if (res->order != 0){
        
        for (ordi = 0; ordi<res->order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res->p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr1->p_im[ordi][i];
                tmp_arr3.p_data = arr2->p_im[ordi][i];
                tmp_arr2.p_data = res->p_im[ordi][i];

                darr_sum_RR_to(&tmp_arr1,&tmp_arr3,&tmp_arr2);

            }

        }

    } 


}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
oarr_t oarr_sum_oO(otinum_t* num, oarr_t* arr, dhelpl_t dhl){

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
    tmp_arr2 =  darr_sum_rR(num->re,&tmp_arr1);
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
                tmp_arr2 = darr_sum_rR(num->p_im[ordi][i], &tmp_arr1);

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


// ****************************************************************************************************
void oarr_sum_oO_to(otinum_t* num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl){
    
    uint64_t i;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    tmp_arr1.ncols = arr1->ncols;
    tmp_arr1.nrows = arr1->nrows;
    tmp_arr1.size  = arr1->size ;

    tmp_arr2.ncols = res->ncols;
    tmp_arr2.nrows = res->nrows;
    tmp_arr2.size  = res->size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr->re;
    tmp_arr2.p_data = res->re;
    darr_sum_rR_to( num->re, &tmp_arr1, &tmp_arr2);
    
    if (res->order != 0){

        for (ordi = 0; ordi < res->order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res->p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr->p_im[ordi][i];
                tmp_arr2.p_data = res->p_im[ordi][i];
                darr_sum_rR_to(num->p_im[ordi][i], &tmp_arr1,&tmp_arr2);

                

            }

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
oarr_t oarr_sum_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // TODO: Add checks for operations.

    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr2->ncols;
    res.nrows  = arr2->nrows;
    res.size   = arr2->size ;



    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr2->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr2->order;
    res.nbases = arr2->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    // Initialize real direction.
    
    tmp_arr1.p_data = arr2->re;
    tmp_arr2 =  darr_sum_RR(arr1, &tmp_arr1);
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

            res.p_ndpo[ordi] = arr2->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr2->p_im[ordi][i];
                tmp_arr2 = darr_copy(&tmp_arr1);

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


// ****************************************************************************************************
void oarr_sum_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl){

    uint64_t i;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    tmp_arr1.ncols = arr2->ncols;
    tmp_arr1.nrows = arr2->nrows;
    tmp_arr1.size  = arr2->size ;

    tmp_arr2.ncols = res->ncols;
    tmp_arr2.nrows = res->nrows;
    tmp_arr2.size  = res->size ;
    // Initialize real direction.
    
    tmp_arr1.p_data = arr2->re;
    tmp_arr2.p_data =  res->re;
    darr_sum_RR_to(arr1, &tmp_arr1, &tmp_arr2);
    
    if (res.order != 0){
            
        for (ordi = 0; ordi<res.order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr2->p_im[ordi][i];
                tmp_arr2.p_data =  res->p_im[ordi][i];
                
                darr_copy_to(&tmp_arr1,&tmp_arr2);

            }

        }

    } 

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
oarr_t oarr_sum_rO(coeff_t num,  oarr_t* arr2, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // TODO: Add checks for operations.

    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr2->ncols;
    res.nrows  = arr2->nrows;
    res.size   = arr2->size ;

    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr2->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr2->order;
    res.nbases = arr2->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    // Initialize real direction.
    
    tmp_arr1.p_data = arr2->re;
    tmp_arr2 =  darr_sum_rR(num, &tmp_arr1);
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

            res.p_ndpo[ordi] = arr2->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr2->p_im[ordi][i];
                tmp_arr2 = darr_copy(&tmp_arr1);

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


// ****************************************************************************************************
void oarr_sum_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    tmp_arr1.ncols = arr2->ncols;
    tmp_arr1.nrows = arr2->nrows;
    tmp_arr1.size  = arr2->size ;

    tmp_arr2.ncols =  res->ncols;
    tmp_arr2.nrows =  res->nrows;
    tmp_arr2.size  =  res->size ;

    // Initialize real direction.
    
    tmp_arr1.p_data = arr2->re;
    tmp_arr2.p_data =  res->re;

    darr_sum_rR_to(num, &tmp_arr1, &tmp_arr2);
    
    
    if (res.order != 0){

        for (ordi = 0; ordi<res.order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr2->p_im[ordi][i];
                tmp_arr2 = darr_copy(&tmp_arr1);

                res.p_im[ordi][i] = tmp_arr2.p_data;

            }

        }

    }

}
// ----------------------------------------------------------------------------------------------------



















































// 1.3. Subtraction.
// 1.3.1. OTI Array   - OTI Array.
// 1.3.5. OTI Scalar  - OTI Array.
// 1.3.4. OTI Array   - OTI Scalar.
// 1.3.3. Real Array  - OTI Array.
// 1.3.2. OTI Array   - Real Array.
// 1.3.5. Real Scalar - OTI Array.
// 1.3.4. OTI Array   - Real Scalar.



// ****************************************************************************************************
oarr_t oarr_sub_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl){
    
    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2, tmp_arr3; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr1->ncols;
    res.nrows  = arr1->nrows;
    res.size   = arr1->size ;


    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr1->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr1->order;
    res.nbases = arr1->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    tmp_arr3.ncols = res.ncols;
    tmp_arr3.nrows = res.nrows;
    tmp_arr3.size  = res.size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr1->re;
    tmp_arr3.p_data = arr2->re;
    tmp_arr2 =  darr_sub_RR(&tmp_arr1,&tmp_arr3);
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

            res.p_ndpo[ordi] = arr1->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr1->p_im[ordi][i];
                tmp_arr3.p_data = arr2->p_im[ordi][i];

                tmp_arr2 = darr_sub_RR(&tmp_arr1,&tmp_arr3);

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

// ****************************************************************************************************
void oarr_sub_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl){


    uint64_t i;

    darr_t tmp_arr1 , tmp_arr2, tmp_arr3; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes
    tmp_arr1.ncols = arr1->ncols;
    tmp_arr1.nrows = arr1->nrows;
    tmp_arr1.size  = arr1->size ;

    tmp_arr3.ncols = arr2->ncols;
    tmp_arr3.nrows = arr2->nrows;
    tmp_arr3.size  = arr2->size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr1->re;
    tmp_arr3.p_data = arr2->re;
    tmp_arr2.p_data = res->re; 
    darr_sub_RR_to(&tmp_arr1,&tmp_arr3,&tmp_arr2);
    
    if (res->order != 0){

        for (ordi = 0; ordi<res->order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res->p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr1->p_im[ordi][i];
                tmp_arr3.p_data = arr2->p_im[ordi][i];
                tmp_arr2.p_data = res->p_im[ordi][i];

                darr_sub_RR_to(&tmp_arr1,&tmp_arr3, &tmp_arr2);

            }

        }

    }


}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_sub_oO(otinum_t* num, oarr_t* arr, dhelpl_t dhl){

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
    tmp_arr2 =  darr_sub_rR(num->re,&tmp_arr1);
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
                tmp_arr2 = darr_sub_rR(num->p_im[ordi][i], &tmp_arr1);

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

// ****************************************************************************************************
void oarr_sub_oO_to(otinum_t num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

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
    tmp_arr2.p_data = res->re;
    darr_sub_rR_to(num->re,&tmp_arr1,&tmp_arr2);
    
    if (res.order != 0){
            
        for (ordi = 0; ordi<res.order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr->p_im[ordi][i];
                tmp_arr2.p_data = res->p_im[ordi][i];
                darr_sub_rR_to(num->p_im[ordi][i], &tmp_arr1, &tmp_arr2);

            }

        }

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_sub_Oo(oarr_t* arr, otinum_t* num, dhelpl_t dhl){

       
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
    tmp_arr2 =  darr_sub_Rr(&tmp_arr1,num->re);
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
                tmp_arr2 = darr_sub_Rr( &tmp_arr1, num->p_im[ordi][i]);

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

// ****************************************************************************************************
void oarr_sub_Oo_to(oarr_t* arr1, otinum_t num, oarr_t* res, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 

    tmp_arr1.ncols = arr1->ncols;
    tmp_arr1.nrows = arr1->nrows;
    tmp_arr1.size  = arr1->size ;

    tmp_arr2.ncols = res->ncols;
    tmp_arr2.nrows = res->nrows;
    tmp_arr2.size  = res->size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr1->re;
    tmp_arr2.p_data = res->re;
    darr_sub_Rr_to(&tmp_arr1,num->re,&tmp_arr2);
    
    if (res->order != 0){

        for (ordi = 0; ordi<res->order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res->p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr1->p_im[ordi][i];
                tmp_arr2.p_data =  res->p_im[ordi][i];
                darr_sub_Rr_to( &tmp_arr1, num->p_im[ordi][i], &tmp_arr2);

            }

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_sub_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // TODO: Add checks for operations.

    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr2->ncols;
    res.nrows  = arr2->nrows;
    res.size   = arr2->size ;



    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr2->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr2->order;
    res.nbases = arr2->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    // Initialize real direction.
    
    tmp_arr1.p_data = arr2->re;
    tmp_arr2 =  darr_sub_RR(arr1, &tmp_arr1);
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

            res.p_ndpo[ordi] = arr2->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr2->p_im[ordi][i];
                tmp_arr2 = darr_neg(&tmp_arr1);

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

// ****************************************************************************************************
void oarr_sub_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 

    tmp_arr1.ncols = arr2->ncols;
    tmp_arr1.nrows = arr2->nrows;
    tmp_arr1.size  = arr2->size ;

    tmp_arr2.ncols = res->ncols;
    tmp_arr2.nrows = res->nrows;
    tmp_arr2.size  = res->size ;

    // Initialize real direction.
    
    tmp_arr1.p_data = arr2->re;
    tmp_arr2.p_data =  res->re;

    darr_sub_RR_to(arr1, &tmp_arr1, &tmp_arr2);
    
    if (res->order != 0){

        for (ordi = 0; ordi<res->order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res->p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr2->p_im[ordi][i];
                tmp_arr2.p_data =  res->p_im[ordi][i];
                
                tmp_arr2 = darr_neg_to(&tmp_arr1);

            }

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_sub_OR(oarr_t* arr1, darr_t* arr2, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // TODO: Add checks for operations.

    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr1->ncols;
    res.nrows  = arr1->nrows;
    res.size   = arr1->size ;



    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr1->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr1->order;
    res.nbases = arr1->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    // Initialize real direction.
    
    tmp_arr1.p_data = arr1->re;
    tmp_arr2 =  darr_sub_RR( &tmp_arr1, arr2);
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

            res.p_ndpo[ordi] = arr1->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr1->p_im[ordi][i];
                tmp_arr2 = darr_copy(&tmp_arr1);

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

// ****************************************************************************************************
void oarr_sub_OR_to(oarr_t* arr1, darr_t* arr2, oarr_t* res, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 

    tmp_arr1.ncols = arr1->ncols;
    tmp_arr1.nrows = arr1->nrows;
    tmp_arr1.size  = arr1->size ;

    tmp_arr2.ncols =  res->ncols;
    tmp_arr2.nrows =  res->nrows;
    tmp_arr2.size  =  res->size ;

    // Initialize real direction.
    
    tmp_arr1.p_data = arr1->re;
    tmp_arr2.p_data =  res->re;
    darr_sub_RR_to( &tmp_arr1, arr2, &tmp_arr2);
    
    if (res->order != 0){

        for (ordi = 0; ordi<res->order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res->p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr1->p_im[ordi][i];
                tmp_arr2.p_data =  res->p_im[ordi][i];
                darr_copy_to(&tmp_arr1, &tmp_arr2);

            }

        }

    }


}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_sub_rO(coeff_t num,  oarr_t* arr2, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // TODO: Add checks for operations.

    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr2->ncols;
    res.nrows  = arr2->nrows;
    res.size   = arr2->size ;

    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr2->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr2->order;
    res.nbases = arr2->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    // Initialize real direction.
    
    tmp_arr1.p_data = arr2->re;
    tmp_arr2 =  darr_sub_rR(num, &tmp_arr1);
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

            res.p_ndpo[ordi] = arr2->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr2->p_im[ordi][i];
                tmp_arr2 = darr_neg(&tmp_arr1);

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

// ****************************************************************************************************
void oarr_sub_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    uint64_t i;


    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 

    tmp_arr1.ncols = arr1->ncols;
    tmp_arr1.nrows = arr1->nrows;
    tmp_arr1.size  = arr1->size ;

    tmp_arr2.ncols = res->ncols;
    tmp_arr2.nrows = res->nrows;
    tmp_arr2.size  = res->size ;

    // Initialize real direction.
    
    tmp_arr1.p_data = arr1->re;
    tmp_arr2.p_data =  res->re;

    darr_sub_rR_to(num, &tmp_arr1, &tmp_arr2);
    
    if (res->order != 0){
        
        for (ordi = 0; ordi<res->order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res->p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr1->p_im[ordi][i];
                tmp_arr1.p_data =  res->p_im[ordi][i];

                darr_neg_to(&tmp_arr1,&tmp_arr2);

            }

        }

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_sub_Or( oarr_t* arr2, coeff_t num, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // TODO: Add checks for operations.

    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr2->ncols;
    res.nrows  = arr2->nrows;
    res.size   = arr2->size ;

    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr2->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr2->order;
    res.nbases = arr2->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    // Initialize real direction.
    
    tmp_arr1.p_data = arr2->re;
    tmp_arr2 =  darr_sub_Rr(&tmp_arr1, num);
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

            res.p_ndpo[ordi] = arr2->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr2->p_im[ordi][i];
                tmp_arr2 = darr_copy(&tmp_arr1);

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

// ****************************************************************************************************
// void oarr_sub_Or_to( oarr_t* arr1, coeff_t num, oarr_t* res, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------


































// 1.4. Multiplication.
// 1.4.1. OTI Array - OTI Array.
// 1.4.2. OTI Array - Real Array.
// 1.4.3. OTI Array - OTI Scalar.
// 1.4.3. OTI Array - Real Scalar.
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_mul_OO(oarr_t* lhs, oarr_t* rhs, dhelpl_t dhl){

    oarr_t res = oarr_zeros(lhs->nrows, lhs->ncols,  lhs->nbases, lhs->order, dhl);    

    ord_t ord_res, ord_mul1;
    
    // First multiply both real parts.

    // lhs real part times rhs real part.
    dhelp_oarr_mul_RR(lhs, rhs, &res, dhl);

    // Loop to get each resulting order.

    for (  ord_res = 1; ord_res <= res.order; ord_res++){

        // Multiply  lhs(re) x rhs(ord_res)
        dhelp_oarr_mul_RI( lhs, rhs, ord_res, &res, dhl);

        // Multiply  lhs(ord_res) x rhs(re)
        dhelp_oarr_mul_RI( rhs, lhs, ord_res, &res, dhl);


        // Loop for every combination of orders such that the resulting order is ord_res.
        for ( ord_mul1 = 1; ord_mul1 <= ord_res/2; ord_mul1++){

            ord_t ord_mul2 = ord_res - ord_mul1;

            dhelp_oarr_mul_II(lhs, ord_mul1, rhs, ord_mul2, &res, dhl);

            // In the case that the orders are the same, the operation is not the same.
            // It might be different in the case of matmul.
            if (ord_mul1 != ord_mul2){

                dhelp_oarr_mul_II(rhs, ord_mul1, lhs, ord_mul2, &res, dhl);

            }  

        }
        

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_mul_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl){


    oarr_set_all_r(0.0, res, dhl);    

    ord_t ord_res, ord_mul1;
    
    // First multiply both real parts.

    // lhs real part times rhs real part.
    dhelp_oarr_mul_RR(lhs, rhs, res, dhl);

    // Loop to get each resulting order.

    for (  ord_res = 1; ord_res <= res->order; ord_res++){

        // Multiply  lhs(re) x rhs(ord_res)
        dhelp_oarr_mul_RI( lhs, rhs, ord_res, res, dhl);

        // Multiply  lhs(ord_res) x rhs(re)
        dhelp_oarr_mul_RI( rhs, lhs, ord_res, res, dhl);


        // Loop for every combination of orders such that the resulting order is ord_res.
        for ( ord_mul1 = 1; ord_mul1 <= ord_res/2; ord_mul1++){

            ord_t ord_mul2 = ord_res - ord_mul1;

            dhelp_oarr_mul_II(lhs, ord_mul1, rhs, ord_mul2, res, dhl);

            // In the case that the orders are the same, the operation is not the same.
            // It might be different in the case of matmul.
            if (ord_mul1 != ord_mul2){

                dhelp_oarr_mul_II(rhs, ord_mul1, lhs, ord_mul2, res, dhl);

            }  

        }
        

    }


}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_mul_oO(otinum_t* lhs, oarr_t* rhs, dhelpl_t dhl){

    oarr_t res = oarr_zeros(rhs->nrows, rhs->ncols,  rhs->nbases, rhs->order, dhl);    

    ord_t ord_res, ord_mul1;
    
    // First multiply both real parts.

    // lhs real part times rhs real part.
    dhelp_oarr_mul_rR(lhs, rhs, &res, dhl);

    // Loop to get each resulting order.

    for (  ord_res = 1; ord_res <= res.order; ord_res++){

        // Multiply  lhs(re) x rhs(ord_res)
        dhelp_oarr_mul_rI( lhs, rhs, ord_res, &res, dhl);

        // Multiply  lhs(ord_res) x rhs(re)
        dhelp_oarr_mul_Ri( rhs, lhs, ord_res, &res, dhl);


        // Loop for every combination of orders such that the resulting order is ord_res.
        for ( ord_mul1 = 1; ord_mul1 <= ord_res/2; ord_mul1++){

            ord_t ord_mul2 = ord_res - ord_mul1;

            dhelp_oarr_mul_iI(lhs, ord_mul1, rhs, ord_mul2, &res, dhl);

            // In the case that the orders are the same, the operation is not the same.
            // It might be different in the case of matmul.
            if (ord_mul1 != ord_mul2){

                dhelp_oarr_mul_iI(lhs, ord_mul2, rhs, ord_mul1, &res, dhl);

            }  

        }        

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_mul_oO_to(otinum_t* num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    oarr_set_all_r(0.0, res, dhl);    

    ord_t ord_res, ord_mul1;
    
    // First multiply both real parts.

    // lhs real part times rhs real part.
    dhelp_oarr_mul_rR(lhs, rhs, res, dhl);

    // Loop to get each resulting order.

    for (  ord_res = 1; ord_res <= res->order; ord_res++){

        // Multiply  lhs(re) x rhs(ord_res)
        dhelp_oarr_mul_rI( lhs, rhs, ord_res, res, dhl);

        // Multiply  lhs(ord_res) x rhs(re)
        dhelp_oarr_mul_Ri( rhs, lhs, ord_res, res, dhl);


        // Loop for every combination of orders such that the resulting order is ord_res.
        for ( ord_mul1 = 1; ord_mul1 <= ord_res/2; ord_mul1++){

            ord_t ord_mul2 = ord_res - ord_mul1;

            dhelp_oarr_mul_iI(lhs, ord_mul1, rhs, ord_mul2, res, dhl);

            // In the case that the orders are the same, the operation is not the same.
            // It might be different in the case of matmul.
            if (ord_mul1 != ord_mul2){

                dhelp_oarr_mul_iI(lhs, ord_mul2, rhs, ord_mul1, res, dhl);

            }  

        }        

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_mul_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr2->ncols;
    res.nrows  = arr2->nrows;
    res.size   = arr2->size ;


    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr2->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr2->order;
    res.nbases = arr2->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr2->re;
    tmp_arr2 =  darr_mul_RR(arr1,&tmp_arr1);
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

            res.p_ndpo[ordi] = arr2->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr2->p_im[ordi][i];

                tmp_arr2 = darr_mul_RR(arr1,&tmp_arr1);

                res.p_im[ordi][i] = tmp_arr2.p_data;

            }

        }

    } else {

        // Set pointer to null
        res.p_im   = NULL;   
        res.p_ndpo = NULL;     
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_mul_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl){



    uint64_t i;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.


    tmp_arr1.ncols = arr2->ncols;
    tmp_arr1.nrows = arr2->nrows;
    tmp_arr1.size  = arr2->size ;

    tmp_arr2.ncols = res->ncols;
    tmp_arr2.nrows = res->nrows;
    tmp_arr2.size  = res->size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr2->re;
    tmp_arr2.p_data =  res->re;
    darr_mul_RR_to(arr1,&tmp_arr1,&tmp_arr2);
    
    if (res.order != 0){

        for (ordi = 0; ordi<res->order; ordi++){

            

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr2->p_im[ordi][i];
                tmp_arr2.p_data =  res->p_im[ordi][i];

                darr_mul_RR( arr1, &tmp_arr1, &tmp_arr2 );

            }

        }

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_mul_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr1->ncols;
    res.nrows  = arr1->nrows;
    res.size   = arr1->size ;


    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr1->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr1->order;
    res.nbases = arr1->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr1->re;
    tmp_arr2 =  darr_mul_rR( num, &tmp_arr1 );
    res.re = tmp_arr2.p_data; //  Comes newly allocated. arr2
    
    if (res.order != 0){
            
        // Allocate memory.
        res.p_im   = ( arr_t** ) malloc( res.order*sizeof(arr_t*) );
        res.p_ndpo = (  ndir_t*  ) malloc( res.order*sizeof(ndir_t) );

        if (res.p_im == NULL  || res.p_ndpo == NULL ){
            printf("--- ERROR: Out of memory\n");
            exit(OTI_OutOfMemory);
        }

        for (ordi = 0; ordi<res.order; ordi++){

            res.p_ndpo[ordi] = arr1->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr1->p_im[ordi][i];

                tmp_arr2 = darr_mul_rR( num, &tmp_arr1 );

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

// ****************************************************************************************************
// void oarr_mul_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------
















































// 1.5. Division
// 1.3.1. OTI Array   - OTI Array.
// 1.3.2. OTI Array   - Real Array.
// 1.3.3. Real Array  - OTI Array.
// 1.3.4. OTI Array   - OTI Scalar.
// 1.3.4. OTI Array   - Real Scalar.
// 1.3.5. OTI Scalar  - OTI Array.
// 1.3.5. Real Scalar - OTI Array.

// ****************************************************************************************************
// oarr_t oarr_div_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
// void oarr_div_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
// oarr_t oarr_div_oO(otinum_t num, oarr_t* arr1, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
// void oarr_div_oO_to(otinum_t num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
// oarr_t oarr_div_Oo(oarr_t* arr1, otinum_t* num, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
// void oarr_div_Oo_to(oarr_t* arr1, otinum_t* num, oarr_t* res, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
// oarr_t oarr_div_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
// void oarr_div_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_div_OR(oarr_t* arr1, darr_t* arr2, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr1->ncols;
    res.nrows  = arr1->nrows;
    res.size   = arr1->size ;


    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr1->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr1->order;
    res.nbases = arr1->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr1->re;
    tmp_arr2 =  darr_div_RR(&tmp_arr1, arr2 );
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

            res.p_ndpo[ordi] = arr1->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr1->p_im[ordi][i];

                tmp_arr2 = darr_div_RR( &tmp_arr1, arr2 );

                res.p_im[ordi][i] = tmp_arr2.p_data;

            }

        }

    } else {

        // Set pointer to null
        res.p_im   = NULL;   
        res.p_ndpo = NULL;     
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
// void oarr_div_OR_to(oarr_t* arr1, darr_t* arr2, oarr_t* res, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
// oarr_t oarr_div_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl){

// }

// void oarr_div_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_div_Or( oarr_t* arr1, coeff_t num, dhelpl_t dhl){

    uint64_t i;
    oarr_t res;

    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    // Array specific attributes:
    res.ncols  = arr1->ncols;
    res.nrows  = arr1->nrows;
    res.size   = arr1->size ;


    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr1->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr1->order;
    res.nbases = arr1->nbases;

    tmp_arr1.ncols = res.ncols;
    tmp_arr1.nrows = res.nrows;
    tmp_arr1.size  = res.size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr1->re;
    tmp_arr2 =  darr_div_Rr( &tmp_arr1, num );
    res.re = tmp_arr2.p_data; //  Comes newly allocated. arr2
    
    if (res.order != 0){
            
        // Allocate memory.
        res.p_im   = ( arr_t** ) malloc( res.order*sizeof(arr_t*) );
        res.p_ndpo = (  ndir_t*  ) malloc( res.order*sizeof(ndir_t) );

        if (res.p_im == NULL  || res.p_ndpo == NULL ){
            printf("--- ERROR: Out of memory\n");
            exit(OTI_OutOfMemory);
        }

        for (ordi = 0; ordi<res.order; ordi++){

            res.p_ndpo[ordi] = arr1->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr1->p_im[ordi][i];

                tmp_arr2 = darr_div_Rr( &tmp_arr1, num );

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

// ****************************************************************************************************
// void oarr_div_Or_to( oarr_t* arr1, coeff_t num, oarr_t* res, dhelpl_t dhl){

// }
// ----------------------------------------------------------------------------------------------------

















// Function Evaluation.

// ****************************************************************************************************
oarr_t oarr_feval(darr_t* feval_re, oarr_t* arr, dhelpl_t dhl ){
    
    ord_t i;

    coeff_t factor = 1.0;
    darr_t val = darr_zeros( arr->nrows, arr->ncols );

    darr_t tmp_arr;

    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;
    
    oarr_t res  = oarr_zeros(arr->nrows, arr->ncols, arr->nbases, arr->order, dhl);
    
    // Create temporal arrays.
    oarr_t tmp1  = oarr_zeros(arr->nrows, arr->ncols, arr->nbases, arr->order, dhl);
    oarr_t tmp2  = oarr_zeros(arr->nrows, arr->ncols, arr->nbases, arr->order, dhl);

    oarr_copy_to( arr, &tmp2, dhl);

    // Set real value of result.

    
    tmp_arr.p_data = res.re;
    darr_copy_to( &feval_re[0] , &tmp_arr); 

    for ( i = 1; i < arr->order; i++){

        factor *= i;

        // val = feval_re[i]/factor;
        darr_div_Rr_to(&feval_re[i],factor,&val);
        
        oarr_copy_to(&tmp2 , &tmp1, dhl);
        oarr_trc_self_mul_r( &val, i, &tmp2, dhl);
        oarr_trc_self_sum( &tmp2, i, &res, dhl );
        
        // update
        oarr_set_all_r( 0.0, &tmp2, dhl);
        oarr_trc_mul(&tmp1, i, &res, 1, &tmp2, dhl );
        oarr_copy_to(&tmp2 , &tmp1, dhl);

    }

    for (; i <= arr->order; i++){

        factor *= i;

        // val = feval_re[i]/factor;
        darr_div_Rr_to(&feval_re[i],factor,&val);
        
        oarr_copy_to(&tmp2 , &tmp1, dhl);
        oarr_trc_self_mul_r( &val, i, &tmp2, dhl);
        oarr_trc_self_sum( &tmp2, i, &res, dhl );

    }

    // Free temporals
    oarr_free(&tmp1); oarr_free(&tmp2); darr_free(&val);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void oarr_feval_to(darr_t* feval_re, oarr_t* arr, oarr_t* res, dhelpl_t dhl ){
    
    ord_t i;

    coeff_t factor = 1.0;
    darr_t val = darr_zeros( arr->nrows, arr->ncols );

    darr_t tmp_arr;

    tmp_arr.ncols = arr->ncols;
    tmp_arr.nrows = arr->nrows;
    tmp_arr.size  = arr->size ;
    
    oarr_set_all_r( 0.0, res, dhl);
    
    // Create temporal arrays.
    oarr_t tmp1  = oarr_zeros(arr->nrows, arr->ncols, arr->nbases, arr->order, dhl);
    oarr_t tmp2  = oarr_zeros(arr->nrows, arr->ncols, arr->nbases, arr->order, dhl);

    oarr_copy_to( arr, &tmp2, dhl);
    
    // Set real value of result.
    
    tmp_arr.p_data = res->re;
    darr_copy_to( &feval_re[0] , &tmp_arr); 

    for ( i = 1; i < arr->order; i++){

        factor *= i;

        // val = feval_re[i]/factor;
        darr_div_Rr_to(&feval_re[i],factor,&val);
        
        oarr_copy_to(&tmp2 , &tmp1, dhl);
        oarr_trc_self_mul_r( &val, i, &tmp2, dhl);
        oarr_trc_self_sum( &tmp2, i, res, dhl );
        
        // update
        oarr_set_all_r( 0.0, &tmp2, dhl);
        oarr_trc_mul(&tmp1, i, res, 1, &tmp2, dhl );
        oarr_copy_to(&tmp2 , &tmp1, dhl);

    }

    for (; i <= arr->order; i++){

        factor *= i;

        // val = feval_re[i]/factor;
        darr_div_Rr_to(&feval_re[i],factor,&val);
        
        oarr_copy_to(&tmp2 , &tmp1, dhl);
        oarr_trc_self_mul_r( &val, i, &tmp2, dhl);
        oarr_trc_self_sum( &tmp2, i, res, dhl );

    }

    // Free temporals
    oarr_free(&tmp1); oarr_free(&tmp2); darr_free(&val);

}
// ----------------------------------------------------------------------------------------------------



