// This file contains the base operations to support OTI manipulation.







// ****************************************************************************************************
void oti_copy_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    ord_t ord;
    res->re = num->re;
    
    // Copy information from num1 to res.
    for( ord = 0; ord<num->order; ord++){

        memcpy( res->p_im[ord], num->p_im[ord], res->p_ndpo[ord]*sizeof(coeff_t) );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_copy(otinum_t* num, dhelpl_t dhl){
    
    ord_t ord;
    otinum_t res;
        
    // Allocate num1.
    res = oti_createEmpty( num->nbases, num->order, dhl);

    res.re = num->re;
    
    // Copy information from num1 to res.
    for( ord = 0; ord<num->order; ord++){

        res.p_ndpo[ord] = num->p_ndpo[ord];

        memcpy( res.p_im[ord], num->p_im[ord], res.p_ndpo[ord]*sizeof(coeff_t) );

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
otinum_t oti_get_rtmp( ndir_t ntmp, ord_t order, bases_t nbases, dhelpl_t dhl){
    
    otinum_t res;

    ord_t i=0;
    
    if (order == 0){
        res = oti_createEmpty( nbases, order, dhl);
        return res;
    }
    
    // Get possible errors.
    if (order > dhl.ndh){
        printf("ERROR: Maximum order not allowed in soti_get_tmp.\n");
        exit(OTI_undetErr);
    }
    if (ntmp >= dhl.p_dh[order-1].Ntmps){
        printf("ERROR: Trying to get a temporal that does not exist.\n");
        exit(OTI_undetErr);   
    }

    res.p_im   = dhl.p_dh[order-1].p_ims[ntmp]; 
    res.p_ndpo  = dhl.p_dh[order-1].p_nnz[ntmp];

    // set the values
    res.order  = order;
    res.nbases = nbases;
    res.ndir   = 0; // Excludes the real direction.
    res.re     = 0;

    for (i=0; i<order; i++){

        // Set the pointers according to the ntemp.
        res.p_im[i]   = dhl.p_dh[i].p_im[ntmp];
        res.p_ndpo[i] = dhelp_extract_ndirOrder( res.nbases, i+1, dhl );
        
        // Initialize imaginary coefficients in res as 0.
        memset( res.p_im[i], 0, res.p_ndpo[i]*sizeof(coeff_t) );

        res.ndir += res.p_ndpo[i];

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
otinum_t oti_get_tmp( ndir_t ntmp, ord_t order, bases_t nbases, dhelpl_t dhl){
    
    otinum_t res;

    ord_t i=0;
    
    if (order == 0){
        res = oti_createEmpty( nbases, order, dhl);
        return res;
    }
    
    // Get possible errors.
    if (order > dhl.ndh){
        printf("ERROR: Maximum order not allowed in soti_get_tmp.\n");
        exit(OTI_undetErr);
    }
    if (ntmp >= (dhl.p_dh[order-1].Ntmps-10) ){
        printf("ERROR: Trying to get a temporal that does not exist.\n");
        exit(OTI_undetErr);   
    }

    res.p_im   = dhl.p_dh[order-1].p_ims[ntmp+10]; 
    res.p_ndpo  = dhl.p_dh[order-1].p_nnz[ntmp+10];

    // set the values
    res.order  = order;
    res.nbases = nbases;
    res.ndir   = 0; // Excludes the real direction.
    res.re     = 0;

    for (i=0; i<order; i++){

        // Set the pointers according to the ntemp.
        res.p_im[i]   = dhl.p_dh[i].p_im[ntmp+10];
        res.p_ndpo[i] = dhelp_extract_ndirOrder( res.nbases, i+1, dhl );
        
        // Initialize imaginary coefficients in res as 0.
        memset( res.p_im[i], 0, res.p_ndpo[i]*sizeof(coeff_t) );

        res.ndir += res.p_ndpo[i];

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
coeff_t oti_get( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl){
    
    coeff_t res = 0.0;

    if (order == 0){
    
        res = num->re;
    
    } else if (order <= num->order)  {

        if (idx < num->p_ndpo[order-1]){ // Only if the index is within the available memory.

            res = num->p_im[ order-1 ][ idx ];

        }
        
    }

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
coeff_t oti_get_deriv( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl){

    coeff_t coef = oti_get(idx,order,num,dhl);
    coeff_t factor = 1.0;
    bases_t* dirs;
    bases_t dir_prev;
    ord_t i, j =2;
    // compute the factor 
    if (coef != 0.0){
        dirs = dhelp_get_imdir(idx,order,dhl);
        dir_prev = dirs[0];
        for (i=1; i<order; i++){
            if (dirs[i] == dir_prev){
                factor *= j;
                j+=1;
            } else{
                j=2;
                dir_prev = dirs[i];
            }
        }
    }

    return coef*factor;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_setIm_IdxOrd( coeff_t a, imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl){

    if (order == 0){
    
        num->re = a;
    
    } else if (order <= num->order)  {

        if (idx < num->p_ndpo[order-1]){ // Only if the index is within the available memory.

            num->p_im[ order-1 ][ idx ] = a;

        } else {

            printf("ERROR: Assignment of elements that require reallocation is not yet supported.");
            printf(" Sorry.\n Error code: %d\n", OTI_undetErr);
            exit(OTI_undetErr);

        }
        
    } else {

        printf("ERROR: Can't assign a number of greater order than the truncation order of the ");
        printf("number. Sorry.\n Error code: %d\n", OTI_undetErr);
        exit(OTI_undetErr);

    }

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void oti_print( otinum_t* num, dhelpl_t dhl){
    ord_t ord ;
    ndir_t dir;
    // char* string = NULL;
    printf("  Order: %hhu, nbases: %hu, ndir: %lu, re: %11.4e\n",
        num->order, num->nbases, num->ndir, num->re);
    printf("  ORD ,    IMDIR  ,   VALUE   \n");

    printf("    0 ,         0 ,%11.4e\n",num->re);

    for( ord = 0; ord<num->order; ord++){

        ndir_t ndir_i = num->p_ndpo[ord];

        for ( dir=0; dir< ndir_i; dir++){

            printf(" %4hhu , %9lu ,%11.4e\n",ord+1, dir, num->p_im[ord][dir]);

        }

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void oti_free( otinum_t* num ){
    
    ord_t ordi ;
    if (num->p_im != NULL){


        for ( ordi = 0; ordi<num->order; ordi++){

            free( num->p_im[ordi] );

        }

        free(num->p_ndpo);
        free(num->p_im);

        num->p_im = NULL;

    }

    // Set all other values as 0.
    num->ndir   = 0;
    num->re     = 0;
    num->nbases = 0;
    num->order  = 0;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_createZero( bases_t nbases, ord_t order, dhelpl_t dhl){
    
    otinum_t res = oti_createEmpty(nbases,order,dhl);

    oti_setFromReal(0.0, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_setFromReal( coeff_t a, otinum_t* num, dhelpl_t dhl){
    ord_t ordi;
    num->re = a;
    
    // Set all imaginary directions to 0
    if (num->order != 0){
        
        for ( ordi = 0; ordi < num->order; ordi++){
            
            memset( num->p_im[ordi], 0, num->p_ndpo[ordi]*sizeof(coeff_t) );
        
        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline otinum_t oti_createEmpty(  bases_t nbases, ord_t order, dhelpl_t dhl ){
    
    otinum_t num;
    ord_t ordi; 
    
    // Get the number of imaginary directions for nbases and order.
    num.ndir = 0; // Excludes the real direction.

    // Set the values of the number first.
    num.order  = order;
    num.nbases = nbases;

    
    if (num.order != 0){
            
        // Allocate memory.
        num.p_im   = ( coeff_t** ) malloc( num.order*sizeof(coeff_t*) );
        num.p_ndpo = (  ndir_t*  ) malloc( num.order*sizeof(ndir_t) );

        if (num.p_im == NULL  || num.p_ndpo == NULL ){
            printf("--- ERROR: Out of memory\n");
            exit(OTI_OutOfMemory);
        }

        for (ordi = 0; ordi<num.order; ordi++){

            num.p_ndpo[ordi] = dhelp_extract_ndirOrder( num.nbases, ordi+1, dhl );
            // num.p_ndpo[ordi] = dhelp_ndirOrder( num.nbases, ordi+1 );
            num.p_im[ordi]   = ( coeff_t* ) malloc( num.p_ndpo[ordi]*sizeof(coeff_t) );
            num.ndir += num.p_ndpo[ordi];


            if ( num.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

        }

    } else {

        // Set pointer to null
        num.p_im = NULL;   
        num.p_ndpo = NULL;     
    }

    return num;
    
}
// ----------------------------------------------------------------------------------------------------

