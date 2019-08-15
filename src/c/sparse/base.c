





// Temporal number extractors.

// ****************************************************************************************************
sotinum_t soti_get_rtmp(ndir_t ntmp, ord_t order, dhelpl_t dhl){
    
    sotinum_t res;
    ord_t i=0;

    if (order == 0){
        // In case order==0, no allocated array exists.
        res = soti_createEmpty(0,dhl);
        return res;
    }
    if (order > dhl.ndh){
        printf("ERROR: Maximum order not allowed in soti_get_rtmp.\n");
        exit(OTI_undetErr);
    }
    if (ntmp >= dhl.p_dh[order-1].Ntmps){
        printf("ERROR: Trying to get a temporal that does not exist.\n");
        exit(OTI_undetErr);   
    }

    res.p_im   = dhl.p_dh[order-1].p_ims[ntmp]; 
    res.p_idx  = dhl.p_dh[order-1].p_ids[ntmp]; 
    res.p_nnz  = dhl.p_dh[order-1].p_nnz[ntmp]; 
    res.p_size = dhl.p_dh[order-1].p_size[ntmp]; 
    res.order  = order; 

    for (i=0; i<order; i++){

        res.p_im[i]  = dhl.p_dh[i].p_im[ntmp];
        res.p_idx[i] = dhl.p_dh[i].p_idx[ntmp];
        res.p_nnz[i] = 0; // Initialize to zero elements.
        res.p_size[i]= dhl.p_dh[i].Ndir;

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_get_tmp(ndir_t ntmp, ord_t order, dhelpl_t dhl){
    
    sotinum_t res;
    ord_t i=0;

    if (order == 0){
        // In case order==0, no allocated array exists.
        res = soti_createEmpty(0,dhl);
        return res;
    }
    if (order > dhl.ndh){
        printf("ERROR: Maximum order not allowed in soti_get_tmp.\n");
        exit(OTI_undetErr);
    }
    if (ntmp >= (dhl.p_dh[order-1].Ntmps - 10) ){
        printf("ERROR: Trying to get a temporal that does not exist.\n");
        exit(OTI_undetErr);   
    }

    res.p_im   = dhl.p_dh[order-1].p_ims[ ntmp+10]; 
    res.p_idx  = dhl.p_dh[order-1].p_ids[ ntmp+10]; 
    res.p_nnz  = dhl.p_dh[order-1].p_nnz[ ntmp+10]; 
    res.p_size = dhl.p_dh[order-1].p_size[ntmp+10]; 
    res.order  = order; 

    for (i=0; i<order; i++){

        res.p_im[i]  = dhl.p_dh[i].p_im[ntmp+10];
        res.p_idx[i] = dhl.p_dh[i].p_idx[ntmp+10];
        res.p_nnz[i] = 0; // Initialize to zero elements.
        res.p_size[i]= dhl.p_dh[i].Ndir;

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------



















// Setter.

// ****************************************************************************************************
void soti_insert_item( ndir_t pos, coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, 
    dhelpl_t dhl){
    
    coeff_t* p_newim;
    imdir_t* p_newidx;
    coeff_t* p_tmpim;
    imdir_t* p_tmpidx;

    // check feasability
    if (order > dhl.ndh){
        printf("ERROR: Not possible to set an element of order greater than the helpers\n");
        exit(OTI_BadIndx);
    }

    if (num->p_nnz[order-1] == num->p_size[order-1]){
        
        // reallocation is needed
        
        p_newim  = (coeff_t*)realloc(num->p_im[order-1] , 
            (num->p_size[order-1]+_REALLOC_SIZE)*sizeof(coeff_t));

        p_newidx = (imdir_t*)realloc(num->p_idx[order-1], 
            (num->p_size[order-1]+_REALLOC_SIZE)*sizeof(imdir_t));

        if (p_newim==NULL || p_newidx==NULL){
            printf("ERROR: Not enough memory for reallocation of sparse oti number.\n");
            exit(OTI_OutOfMemory);
        }
        
        num->p_im[order-1]  = p_newim;
        num->p_idx[order-1] = p_newidx;
        
        num->p_size[order-1] += _REALLOC_SIZE;

    } 

    if (pos < num->p_nnz[order-1]){
        // Memory copy is necesary

        //get temporal pointers
        p_tmpim =dhl.p_dh[order-1].p_im[0];
        p_tmpidx=dhl.p_dh[order-1].p_idx[0];

        // copy to pointer:
        memcpy(p_tmpim ,&num->p_im[order-1][pos] ,(num->p_nnz[order-1]-pos)*sizeof(coeff_t));
        memcpy(p_tmpidx,&num->p_idx[order-1][pos],(num->p_nnz[order-1]-pos)*sizeof(imdir_t));

        // copy back to new position
        memcpy(&num->p_im[order-1][pos+1] ,p_tmpim ,(num->p_nnz[order-1]-pos)*sizeof(coeff_t));
        memcpy(&num->p_idx[order-1][pos+1],p_tmpidx,(num->p_nnz[order-1]-pos)*sizeof(imdir_t));        
        
    }

    num->p_im[order-1][pos] = val;
    num->p_idx[order-1][pos] = idx;
    num->p_nnz[order-1] += 1;
    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_set_item(coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    flag_t flag;
    imdir_t pos;
    
    if (order == 0){
        
        num->re = val;

    }else{

        if ( order <= num->order ){

            pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );

            if (flag != 0){

                num->p_im[order-1][pos] = val;

            } else {

                soti_insert_item( pos, val, idx, order, num, dhl);

            }

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_setFromReal( coeff_t a, sotinum_t* num, dhelpl_t dhl){
    
    ord_t i;
    num->re = a;

    for ( i =0; i<num->order; i++){

        // Set number of non-zero and allocated size to 0.
        num->p_nnz[i]  = 0;

    }


}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_set( sotinum_t* src, sotinum_t* dest, dhelpl_t dhl){
    
    // Assumes both have the space allocated and both have the same truncation order
    ord_t i;
    dest->re = src->re;
    
    memcpy(dest->p_nnz, src->p_nnz, src->order*sizeof(ndir_t));

    for ( i =0; i<src->order; i++){
        
        // Set number of non-zero and allocated size to 0.
        // dest->p_nnz[i]  = src->p_nnz[i];

        memcpy( dest->p_im[i],  src->p_im[i],  dest->p_nnz[i]*sizeof(coeff_t) );
        memcpy( dest->p_idx[i], src->p_idx[i], dest->p_nnz[i]*sizeof(imdir_t) );

    }

}
// ----------------------------------------------------------------------------------------------------





























// Getters.

// ****************************************************************************************************
coeff_t soti_get_deriv( imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){

    coeff_t coef = soti_get_item(idx,order,num,dhl);
    coeff_t factor = 1.0;
    bases_t* dirs;
    bases_t dir_prev;
    ord_t i, j = 1;
    
    // compute the factor 
    if (coef != 0.0){
        dirs = dhelp_get_imdir(idx,order,dhl);
        dir_prev = dirs[0];
        for (i=0; i<order; i++){
            if (dirs[i] == dir_prev){
                factor *= j;
                j+=1;
            } else{
                j =2;
                dir_prev = dirs[i];
            }
        }
    }

    return coef*factor;
}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
coeff_t soti_get_item(imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    coeff_t res =0.0;
    flag_t flag;
    imdir_t pos;
    
    if (order == 0){
        
        res = num->re;

    }else{

        if ( order<=num->order ){
            
            if(num->p_nnz[order-1] != 0){

                pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );

                if (flag != 0){

                    res = num->p_im[order-1][pos];

                }

            }

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------











// Copy operations.

// ****************************************************************************************************
void soti_copy_to(sotinum_t* src, sotinum_t* dest, dhelpl_t dhl){
    
    ndir_t i;
    ord_t ordi;

    // TODO: Add check to wheather dest has not been initialized.
    // TODO: Add case when the two elements have different orders.
    // TODO: Add memory management when needed in this copy function.

    for (ordi=0; ordi<src->order; ordi++){
        
        if (src->p_nnz[ordi] > dest->p_size[ordi]){
            
            // Realloc memory only if the number of elements exceeds the number
            // of non zeros to be copied
            dest->p_im[ordi]  =(coeff_t*)realloc(dest->p_im[ordi], src->p_nnz[ordi]*sizeof(coeff_t) );
            dest->p_idx[ordi] =(imdir_t*)realloc(dest->p_idx[ordi],src->p_nnz[ordi]*sizeof(imdir_t) );
            dest->p_size[ordi]=src->p_nnz[ordi];
            
            if (dest->p_im[ordi]==NULL || dest->p_idx[ordi]==NULL){
                printf("ERROR: Not enough memory to handle oti number.\n Exiting...\n");
                exit(OTI_OutOfMemory);
            }

        }

        // Copy memory to dest number.
        memcpy(dest->p_im[ordi], src->p_im[ordi], src->p_nnz[ordi]*sizeof(coeff_t) );
        memcpy(dest->p_idx[ordi],src->p_idx[ordi],src->p_nnz[ordi]*sizeof(imdir_t) );

        dest->p_nnz[ordi] = src->p_nnz[ordi];

    }

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
sotinum_t soti_copy(sotinum_t* num, dhelpl_t dhl){

    ord_t i;
    sotinum_t res;

    res.order = num->order;
    res.re    = num->re;

    if (res.order != 0){

        res.p_im  = (coeff_t**)malloc( res.order * sizeof(coeff_t*) );
        res.p_idx = (imdir_t**)malloc( res.order * sizeof(imdir_t*) );
        res.p_nnz = (ndir_t*)malloc( res.order * sizeof(ndir_t) );
        res.p_size= (ndir_t*)malloc( res.order * sizeof(ndir_t) );

        if (res.p_im  == NULL || res.p_idx == NULL || res.p_nnz == NULL || res.p_size == NULL ){

            printf("ERROR: Not enough memory to handle oti number.\n Exiting...\n");
            exit(OTI_OutOfMemory);

        }

        for ( i = 0; i<res.order; i++){
            
            // Set number of non-zero and allocated size to 0.
            res.p_nnz[i]  = num->p_nnz[i]; // Just use  nnz.
            res.p_size[i] = num->p_nnz[i];

            if (num->p_size[i] != 0){
            
                res.p_im[i] = (coeff_t*)malloc(num->p_nnz[i]*sizeof(coeff_t)); 
                res.p_idx[i]= (imdir_t*)malloc(num->p_nnz[i]*sizeof(imdir_t)); 

                if (res.p_im[i] == NULL || res.p_idx[i] == NULL ){

                    printf("ERROR: Not enough memory to handle oti number.\n Exiting...\n");
                    exit(OTI_OutOfMemory);

                }

                if ( res.p_nnz[i]!=0 ){

                    // copy data.
                    memcpy(res.p_im[i], num->p_im[i], res.p_nnz[i]*sizeof(coeff_t));
                    memcpy(res.p_idx[i],num->p_idx[i],res.p_nnz[i]*sizeof(imdir_t));

                }
            
            } else {

                res.p_im[i]  = NULL;
                res.p_idx[i] = NULL;

            }
        
        }

    } else {

        res.p_im  = NULL;
        res.p_idx = NULL;
        res.p_nnz = NULL;
        res.p_size= NULL;

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------
















// Helpers

// ****************************************************************************************************
void soti_print(sotinum_t* num, dhelpl_t dhl){

    ndir_t nnz_total = 1,dir;
    ord_t ordi,ord;
    for( ordi = 0; ordi<num->order; ordi++){
        nnz_total += num->p_nnz[ordi];
    }

    printf("  Order: "_PORDT", non_zero: "_PNDIRT", re: %11.4e\n",
        num->order, nnz_total, num->re);
    printf("  ORD ,    IMDIR  ,   VALUE   \n");

    printf("    0 ,         0 , %11.4e\n",num->re);

    for( ord = 0; ord<num->order; ord++){

        ndir_t ndir_i = num->p_nnz[ord];

        for ( dir=0; dir< ndir_i; dir++){

            printf(" %4hhu , %9lu ,%11.4e\n",ord+1, num->p_idx[ord][dir], num->p_im[ord][dir]);

        }

    }

}
// ----------------------------------------------------------------------------------------------------






















// Memory management.

// ****************************************************************************************************
void soti_free(sotinum_t* num){
    
    if( num->order != 0 ){
        ord_t i;
        for ( i=0; i<num->order; i++){
            if (num->p_im[i]  != NULL ){
                free(num->p_im[i]);
            }                
            if (num->p_idx[i] != NULL){
                free(num->p_idx[i]);
            }
        }

        free(num->p_im);
        free(num->p_idx);
        free(num->p_size);
        free(num->p_nnz);

        num->order = 0;
    } 

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_createReal(coeff_t num, ord_t order, dhelpl_t dhl){
    
    sotinum_t res = soti_createEmpty(order,dhl);

    res.re = num;

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_createEmpty( ord_t order, dhelpl_t dhl){
    
    sotinum_t res;

    res.order = order;

    if (order != 0){

        res.p_im  = (coeff_t**)malloc( res.order * sizeof(coeff_t*) );
        res.p_idx = (imdir_t**)malloc( res.order * sizeof(imdir_t*) );
        res.p_nnz = (ndir_t*  )malloc( res.order * sizeof(ndir_t) );
        res.p_size= (ndir_t*  )malloc( res.order * sizeof(ndir_t) );

        if (res.p_im  == NULL || res.p_idx == NULL || res.p_nnz == NULL || res.p_size == NULL ){

            printf("ERROR: Not enough memory to handle oti number.\n Exiting...\n");
            exit(OTI_OutOfMemory);

        }
        ord_t i;
        for ( i =0; i<res.order; i++){
            
            if (dhl.p_dh[i].allocSize != 0){
            
                res.p_im[i] = (coeff_t*)malloc(dhl.p_dh[i].allocSize*sizeof(coeff_t)); 
                res.p_idx[i]= (imdir_t*)malloc(dhl.p_dh[i].allocSize*sizeof(imdir_t)); 

                if (res.p_im[i] == NULL || res.p_idx[i] == NULL ){

                    printf("ERROR: Not enough memory to handle oti number.\n Exiting...\n");
                    exit(OTI_OutOfMemory);

                }
            
            } else {

                res.p_im[i]  = NULL;
                res.p_idx[i] = NULL;

            }

            // Set number of non-zero and allocated size to 0.
            res.p_nnz[i]  = 0; 
            res.p_size[i] = 0; 

        
        }

    } else {

        res.p_im  = NULL;
        res.p_idx = NULL;
        res.p_nnz = NULL;
        res.p_size= NULL;

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

