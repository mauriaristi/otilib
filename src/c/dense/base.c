// This file contains the base operations to support OTI manipulation.



// There should also be an extract derivative...

// // ****************************************************************************************************
// otinum_t oti_extract_deriv( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl){

//     coeff_t coef = oti_get(idx,order,num,dhl);
//     coeff_t factor = 1.0;
//     bases_t* dirs;
//     bases_t dir_prev;
//     ord_t i, j = 2;

//     // compute the factor 
    
//     if (coef != 0.0){
//         dirs = dhelp_get_imdir(idx,order,dhl);
//         dir_prev = dirs[0];
//         for (i=1; i<order; i++){
//             if (dirs[i] == dir_prev){
//                 factor *= j;
//                 j+=1;
//             } else{
//                 j=2;
//                 dir_prev = dirs[i];
//             }
//         }
//     }

//     return coef*factor;
// }
// // ----------------------------------------------------------------------------------------------------



// // ****************************************************************************************************
// otinum_t oti_extract_imdir( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl){
    
//     // This function extracts an OTI number out of the specified imaginary direction (idx,order). 
//     otinum_t res;
//     ord_t order_res;



//     // Check input possibilities:
//     // 1. Requested imdir has order 0                -> Return a copy of num.
//     // 2. Requested imdir has order > num.order      -> Return otinum 0.
//     // 3. Requested imdir has 0<order<num.order and index within bounds -> Extract numbers.
//     // 4. Requested imdir has 0<order<num.order but index out of bounds -> Return otinum 0.
    
//     // Case 1.
//     if ( order == 0 ){
    
//         res = oti_copy(num,dhl);
        
//     // Case 2.
//     } else if (order > num->order)  {

//         // Returns an otinum with truncation order equa to zero.
//         res = oti_createZero( 0, 0, dhl);

//     //Cases 3 & 4.
//     } else if (order <= num->order)  {

//         // Case 3.
//         if (idx < num->p_ndpo[order-1]){ // Only if the index is within the available memory.

//             // In this case, idx and order correspond to an imaginary direction within the number.

//             // coeff_t dhelp_get_deriv_factor(imdir_t idx, ord_t order, dhl);

//             // Get all directions with order greater to the imdir order and
//             // that contain the imaginary direction (idx,order) from input.

//             res = num->p_im[ order-1 ][ idx ];

//         } else {

//             // Case 4.
//             res  = oti_createZero( 0, 0, dhl);

//         }

        
        
//     }

//     return res;
// }
// // ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
darr_t oti_to_cr_dense(otinum_t* num,  dhelpl_t dhl){
    
    ord_t ordi, ordj, ord_res;
    imdir_t idx_i, idx_j, idx_res;
    ndir_t ndir = num->ndir+1; 
    ndir_t ndir_i, ndir_j; 
    coeff_t val;
    darr_t res;
    uint64_t i,ii,jj, k;
        
    res = darr_zeros(ndir,ndir);

    // set all diagonal coeffs to the real coefficient
    val = num->re;
    
    for(i = 0; i<ndir; i++){

        darr_set_item_ij(val,i,i,&res);

    }

    // set all first column coeffs to the imaginary directions
    k=1;
    for (ordi = 0; ordi<num->order; ordi++){
        
        for (idx_i = 0; idx_i < num->p_ndpo[ordi]; idx_i++){

            val = num->p_im[ordi][idx_i];
            darr_set_item_ij(val,k,0,&res);
            k++;

        }

    }

    // Put all other elements under the diagonal.
    for( ordi = 1; ordi < num->order ; ordi++){
        
        ndir_i = num->p_ndpo[ordi-1];

        for( ordj = 1; ordj <= (num->order-ordi) ; ordj++){
            
            ndir_j = num->p_ndpo[ordj-1];

            if (ordj == 1){
                
                jj = 1;

            } else {
                
                jj = num->p_ndpo[ordj-2];    

            }
            
            if(ordi+ordj-1 == 1){
                
                ii = 1;

            } else {
                
                ii = num->p_ndpo[ordi+ordj-2];

            }
            

            for (idx_i=0; idx_i<ndir_i; idx_i++){
                
                for (idx_j=0; idx_j<ndir_j; idx_j++){
                    
                    dhelp_multDir( idx_i, ordi, idx_j, ordj, &idx_res,&ord_res,dhl);
                    
                    val = num->p_im[ord_res-1][idx_res];
                    darr_set_item_ij(val, ii + idx_res, jj + idx_j ,&res);
                    
                }

            }            

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void oti_copy_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    ord_t ord;

    // Copy real information.
    res->re = num->re;
    
    // Copy imagiary information from num1 to res.
    for( ord = 0; ord<num->order; ord++){

        memcpy( res->p_im[ord], num->p_im[ord], num->p_ndpo[ord]*sizeof(coeff_t) );

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void oti_change_nbases(otinum_t* num, bases_t newnbases, dhelpl_t dhl){

    ord_t ordi;
    
    // Create new memory object
    otinum_t new_num = oti_init();

    if (newnbases != num->nbases) {

        new_num = oti_createZero( newnbases, num->order, dhl);
        
        new_num.re = num->re;

        // Copy information from num to new_num.
        // Only loop the minimym ammount of times necessary.
        for( ordi = 0; ordi< new_num.order; ordi++){

            memcpy( new_num.p_im[ordi], num->p_im[ordi], 
                MIN( new_num.p_ndpo[ordi], num->p_ndpo[ordi] ) * sizeof(coeff_t) );

        }

        // Free memory in num and then copy the contents of new num.
        oti_free(num);

        *num = new_num;

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void oti_change_order(otinum_t* num, ord_t neworder, dhelpl_t dhl){

    ord_t ordi;
    

    // Create new memory object
    otinum_t new_num = oti_init();

    if (neworder != num->order) {

        new_num = oti_createZero( num->nbases, neworder, dhl);
        
        new_num.re = num->re;

        // Copy information from num to new_num.
        // Only loop the minimym ammount of times necessary.
        for( ordi = 0; ordi< MIN( neworder, num->order); ordi++){

            memcpy( new_num.p_im[ordi], num->p_im[ordi], num->p_ndpo[ordi]*sizeof(coeff_t) );

        }

        // Free memory in num and then copy the contents of new num.
        oti_free(num);

        *num = new_num;


    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_copy(otinum_t* num, dhelpl_t dhl){
    
    ord_t ord;
    otinum_t res;
        
    // Allocate res.
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
    
    otinum_t res = oti_init();

    ord_t ordi=0;
    
    if (order != 0){
        
        // Get possible errors.
        if (order > dhl.ndh){
            printf("ERROR: Maximum order not allowed in soti_get_tmp.\n");
            exit(OTI_undetErr);
        }
        if (ntmp >= dhl.p_dh[order-1].Ntmps){
            printf("ERROR: Trying to get a temporal that does not exist.\n");
            exit(OTI_undetErr);   
        }

        res.p_im    = dhl.p_dh[order-1].p_ims[ntmp]; 
        res.p_ndpo  = dhl.p_dh[order-1].p_nnz[ntmp];

        // set the values
        res.order  = order;
        res.nbases = nbases;
        res.ndir   = 0; // Excludes the real direction.
        res.re     = 0;

        for (ordi=0; ordi<order; ordi++){

            // Set the pointers according to the ntemp.
            res.p_im[ordi]   = dhl.p_dh[ordi].p_im[ntmp];
            
            res.p_ndpo[ordi] = dhelp_extract_ndirOrder( res.nbases, ordi+1, dhl );
            
            // Initialize imaginary coefficients in res as 0.
            memset( res.p_im[ordi], 0, res.p_ndpo[ordi]*sizeof(coeff_t) );

            res.ndir += res.p_ndpo[ordi];

        }

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
otinum_t oti_get_tmp( ndir_t ntmp, ord_t order, bases_t nbases, dhelpl_t dhl){
    
    otinum_t res= oti_init();

    ord_t i=0;
    
    if (order != 0){
        
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
        res.p_ndpo = dhl.p_dh[order-1].p_nnz[ntmp+10];

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
    ord_t i, j = 2;

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
    printf("  Order: "_PORDT", nbases: "_PBASEST", ndir: "_PNDIRT", re: "_PCOEFFT"\n",
        num->order, num->nbases, num->ndir, num->re);
    printf("  ORD ,    IMDIR  ,   VALUE   \n");

    printf("    0 ,         0 ,"_PCOEFFT"\n",num->re);

    for( ord = 1; ord<=num->order; ord++){

        ndir_t ndir_i = num->p_ndpo[ord];

        for ( dir=0; dir< ndir_i; dir++){

            printf(" " _PORDT " , " _PNDIRT " ," _PCOEFFT "\n",
                ord, dir, num->p_im[ord-1][dir]);

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_init( void ){
    
    otinum_t num;
    
    // Get the number of imaginary directions for nbases and order.
    num.ndir = 0; // Excludes the real direction.

    // Set the values of the number first.
    num.order  = 0;
    num.nbases = 0;

    // Set pointer as null.
    num.p_im = NULL;   
    num.p_ndpo = NULL;     

    return num;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_free( otinum_t* num ){
    
    // ord_t ordi ;
    if (num->p_im != NULL){

        // for ( ordi = 0; ordi<num->order; ordi++){
        //     free( num->p_im[ordi] );
        // }

        // free(num->p_ndpo);
        free(num->p_im);

        num->p_im = NULL;

    }


    // Set all other values as 0.
    *num = oti_init();

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
inline void oti_setup(otinum_t* num,  bases_t nbases, ord_t order, dhelpl_t dhl ){
    
    
    ord_t ordi; 

    // Get the number of imaginary directions for nbases and order.

    num->ndir = 0; // Excludes the real direction.

    // Set the values of the number first.
    num->order  = order;
    num->nbases = nbases;

    for (ordi = 0; ordi < num->order; ordi++){

        num->p_ndpo[ordi] = dhelp_extract_ndirOrder( num->nbases, ordi+1, dhl );
        num->ndir += num->p_ndpo[ordi];

    }

    
}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline otinum_t oti_createEmpty(  bases_t nbases, ord_t order, dhelpl_t dhl ){
    
    otinum_t num = oti_init();
    ord_t ordi; 

    uint64_t total_memory = 0;
    void * memory = NULL;

    
    // Get the number of imaginary directions for nbases and order.
    num.ndir = dhelp_ndirTotal( nbases, order)-1; // Excludes the real direction.

    // Set the values of the number first.
    num.order  = order;
    num.nbases = nbases;


    if (num.ndir != 0){

        total_memory = num.order*sizeof(coeff_t*) + // Memory for p_im
                       num.order*sizeof( ndir_t ) + // Memory for p_ndpo
                       num.ndir *sizeof(coeff_t ) ; // Memory for imaginary direction coefficients.

        // Goal: Do only one malloc call.
        memory = malloc(total_memory);
        
        if (memory == NULL ){
            printf("--- ERROR: Out of memory to create oti number.\n");
            exit(OTI_OutOfMemory);
        }

        // Allocate memory.
        num.p_im   = ( coeff_t** ) memory; // First element is p_im

        // Shift memory.
        memory += num.order*sizeof(coeff_t*);

        num.p_ndpo = ( ndir_t*   ) memory;
        
        memory += num.order*sizeof(ndir_t);

        for (ordi = 0; ordi<num.order; ordi++){

            num.p_ndpo[ordi] = dhelp_extract_ndirOrder( num.nbases, ordi+1, dhl );
            num.p_im[ordi]   = ( coeff_t* ) memory;

            // Move memory:
            memory += num.p_ndpo[ordi]*sizeof(coeff_t );
            // num.ndir += num.p_ndpo[ordi];

        }
    
    } else {
            
        // Set pointers to null, no memory allocation required.

        num.p_im   = NULL;   
        num.p_ndpo = NULL;     

    } 

    return num;
    
}
// ----------------------------------------------------------------------------------------------------








// // ****************************************************************************************************
// inline otinum_t oti_createEmpty(  bases_t nbases, ord_t order, dhelpl_t dhl ){
    
//     otinum_t num;
//     ord_t ordi; 
    
//     // Get the number of imaginary directions for nbases and order.
//     num.ndir = 0; // Excludes the real direction.

//     // Set the values of the number first.
//     num.order  = order;
//     num.nbases = nbases;

    
//     if (num.order != 0){
            
//         // Allocate memory.
//         num.p_im   = ( coeff_t** ) malloc( num.order*sizeof(coeff_t*) );
//         num.p_ndpo = (  ndir_t*  ) malloc( num.order*sizeof(ndir_t) );

//         if (num.p_im == NULL  || num.p_ndpo == NULL ){
//             printf("--- ERROR: Out of memory\n");
//             exit(OTI_OutOfMemory);
//         }

//         for (ordi = 0; ordi<num.order; ordi++){

//             num.p_ndpo[ordi] = dhelp_extract_ndirOrder( num.nbases, ordi+1, dhl );
//             // num.p_ndpo[ordi] = dhelp_ndirOrder( num.nbases, ordi+1 );
//             num.p_im[ordi]   = ( coeff_t* ) malloc( num.p_ndpo[ordi]*sizeof(coeff_t) );
//             num.ndir += num.p_ndpo[ordi];


//             if ( num.p_im[ordi] == NULL ){
//                 printf("--- ERROR: Out of memory\n");
//                 exit(OTI_OutOfMemory);
//             }

//         }

//     } else {

//         // Set pointer to null
//         num.p_im = NULL;   
//         num.p_ndpo = NULL;     
//     }

//     return num;
    
// }
// // ----------------------------------------------------------------------------------------------------

