#include "oti/otinum_spr.h"

// ----------------------------------------------------------------------------------------------------
// -------------------------------     SPROTINUM FUNCTIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************

// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************

// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_trunc_smul_real(coeff_t a, ord_t ord, sotinum_t* res, dhelpl_t dhl){

    for ( ord_t ordi = ord-1; ordi < res->order; ordi++){

        for (ndir_t i=0; i<res->p_nnz[ordi]; i++){
            
            res->p_im[ordi][i] *= a;

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_trunc_mul(sotinum_t* num1, ord_t ord1, 
                   sotinum_t* num2, ord_t ord2, 
                   sotinum_t* res, dhelpl_t dhl ){
    
    sotinum_t tmp, tmp2, tmp3;
    sotinum_t* tmpsrc= &tmp ;
    sotinum_t* tmpdest=&tmp3;
    sotinum_t* tmpswap;
    ord_t ordi;

    ord_t res_ord = MAX(num1->order,num2->order);
    
    tmp = soti_get_tmp(0,res_ord,dhl); // will hold the final result.
    tmp2= soti_get_tmp(1,res_ord,dhl); // Will hold the temporary result.
    tmp3= soti_get_tmp(2,res_ord,dhl); // Will hold the temporary result.

    for (ord_t ord_mul1 =ord1; ord_mul1 <= res->order; ord_mul1++){

        for (ord_t ord_mul2 = res_ord-ord_mul1; ord_mul2 >= ord2; ord_mul2--){

            // printf("Multiplying order "_PORDT" times "_PORDT _ENDL, ord_mul1,ord_mul2);
            ord_t ord_res = ord_mul1 + ord_mul2;
            ordi = ord_res -1;

            dhelp_sparse_mult(num1->p_im[ord_mul1-1], num1->p_idx[ord_mul1-1], num1->p_nnz[ord_mul1-1],ord_mul1,
                              num2->p_im[ord_mul2-1], num2->p_idx[ord_mul2-1], num2->p_nnz[ord_mul2-1],ord_mul2,
                              tmp2.p_im[ordi],  tmp2.p_idx[ordi], &tmp2.p_nnz[ordi], dhl);

            tmpswap = tmpsrc; tmpsrc=tmpdest; tmpdest=tmpswap;

            dhelp_sparse_add_dirs(tmp2.p_im[ordi], tmp2.p_idx[ordi], tmp2.p_nnz[ordi],
                                  tmpsrc->p_im[ordi], tmpsrc->p_idx[ordi], tmpsrc->p_nnz[ordi],
                                  tmpdest->p_im[ordi], tmpdest->p_idx[ordi], &tmpdest->p_nnz[ordi], dhl);

        }   

    }

    // reset the size values of the tmp number    
    for(ordi=0; ordi<res_ord; ordi++){

        tmpdest->p_size[ordi] = MAX(dhl.p_dh[ordi].allocSize,tmpdest->p_nnz[ordi]);
    }

    // res = soti_copy(tmpdest, dhl);

    // return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void soti_copy_to(sotinum_t* src, sotinum_t* dest, dhelpl_t dhl){
    
    ndir_t i;
    ord_t ordi;
    // TODO: Add case when the two elements have different orders.
    // TODO: Add memory management when needed in this copy function.
    if (src->order > dest->order){
        printf("ERROR: Currently copy function of sotinum  is not implemented for order change.\n");
    }

    // Reset sizes for dest:
    for (ordi=0; ordi<dest->order; ordi++){

        dest->p_nnz[ordi] = 0;

    }

    for (ordi=0; ordi<src->order; ordi++){

        memcpy(dest->p_im[ordi], src->p_im[ordi], src->p_nnz[ordi]*sizeof(coeff_t) );
        memcpy(dest->p_idx[ordi],src->p_idx[ordi],src->p_nnz[ordi]*sizeof(imdir_t) );

        dest->p_nnz[ordi] = src->p_nnz[ordi];

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_get_tmp(ndir_t ntmp, ord_t order, dhelpl_t dhl){
    
    sotinum_t res;
    ord_t i=0;

    if (order > dhl.ndh){
        printf("ERROR: Maximum order not allowed in soti_get_tmp.\n");
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
        res.p_nnz[i] = 0;
        res.p_size[i]= dhl.p_dh[i].Ndir;

    }


    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_mul(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t res, tmp, tmp2, tmp3;
    sotinum_t* tmpsrc= &tmp ;
    sotinum_t* tmpdest=&tmp3;
    sotinum_t* tmpswap;
    ord_t res_ord = MAX(num1->order,num2->order);
    ord_t ordi;

    // Retreive sotinum temporals.
    // All tmps are created with no elements in imaginary directions (but allocated).
    tmp = soti_get_tmp(0,res_ord,dhl); // will hold the final result.
    tmp2= soti_get_tmp(1,res_ord,dhl); // Will hold the temporary result.
    tmp3= soti_get_tmp(2,res_ord,dhl); // Will hold the temporary result.
    

    // Multiply real coefficients.
    tmpdest->re = num1->re * num2->re;
    tmpsrc->re  = tmpdest->re;

    // printf("Multiplying order %hhu x %hhu\n", num1->order, num2->order);

    for(ord_t order=1; order<=res_ord; order++){

        ordi = order-1;

        // First multiply  re x ordi         
        if ( order <= num2->order){
            
            // Perform multiplication
            dhelp_sparse_mult_real(num1->re,
                               num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
                               tmp2.p_im[ordi], tmp2.p_idx[ordi], &tmp2.p_nnz[ordi],       
                               dhl);  
            
            
            // Swap pointers
            tmpswap = tmpsrc; tmpsrc=tmpdest; tmpdest=tmpswap;

            dhelp_sparse_add_dirs(tmp2.p_im[ordi], tmp2.p_idx[ordi], tmp2.p_nnz[ordi],
                                  tmpsrc->p_im[ordi], tmpsrc->p_idx[ordi], tmpsrc->p_nnz[ordi],
                                  tmpdest->p_im[ordi], tmpdest->p_idx[ordi], &tmpdest->p_nnz[ordi], dhl);

        }


        // Then multiply   ordi x re
        if ( order <= num1->order){
            
            // Perform multiplication
            dhelp_sparse_mult_real(num2->re,
                               num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
                               tmp2.p_im[ordi], tmp2.p_idx[ordi], &tmp2.p_nnz[ordi],       
                               dhl);  
            
            
            // Swap pointers
            tmpswap = tmpsrc; tmpsrc=tmpdest;tmpdest=tmpswap;
            
            dhelp_sparse_add_dirs(tmp2.p_im[ordi], tmp2.p_idx[ordi], tmp2.p_nnz[ordi],
                                  tmpsrc->p_im[ordi], tmpsrc->p_idx[ordi], tmpsrc->p_nnz[ordi],
                                  tmpdest->p_im[ordi], tmpdest->p_idx[ordi], &tmpdest->p_nnz[ordi], dhl);

        }

        for (ord_t ord_mul1 = 1; ord_mul1 <= order/2; ord_mul1++){

            ord_t ord_mul2 = order - ord_mul1;
            // printf("Multiplying %hhu X %hhu\n",ord_mul1,ord_mul2);

            if ( ord_mul1 <= num1->order && ord_mul2 <= num2->order){
                
                dhelp_sparse_mult(num1->p_im[ord_mul1-1], num1->p_idx[ord_mul1-1], num1->p_nnz[ord_mul1-1],ord_mul1,
                                  num2->p_im[ord_mul2-1], num2->p_idx[ord_mul2-1], num2->p_nnz[ord_mul2-1],ord_mul2,
                                  tmp2.p_im[ordi],  tmp2.p_idx[ordi], &tmp2.p_nnz[ordi], dhl);
                                
                // Swap pointers
                tmpswap = tmpsrc; tmpsrc=tmpdest; tmpdest=tmpswap;
                
                dhelp_sparse_add_dirs(tmp2.p_im[ordi], tmp2.p_idx[ordi], tmp2.p_nnz[ordi],
                                      tmpsrc->p_im[ordi], tmpsrc->p_idx[ordi], tmpsrc->p_nnz[ordi],
                                      tmpdest->p_im[ordi], tmpdest->p_idx[ordi], &tmpdest->p_nnz[ordi], dhl);

            }
            

            if (ord_mul1 != ord_mul2){
                
                if ( ord_mul2 <= num1->order && ord_mul1 <= num2->order){
                    dhelp_sparse_mult(num1->p_im[ord_mul2-1], num1->p_idx[ord_mul2-1], num1->p_nnz[ord_mul2-1],ord_mul2,
                                      num2->p_im[ord_mul1-1], num2->p_idx[ord_mul1-1], num2->p_nnz[ord_mul1-1],ord_mul1,
                                      tmp2.p_im[ordi],  tmp2.p_idx[ordi], &tmp2.p_nnz[ordi], dhl);
                    
                    
                    // Swap pointers
                    tmpswap = tmpsrc; tmpsrc=tmpdest;tmpdest=tmpswap;
                    
                    dhelp_sparse_add_dirs(tmp2.p_im[ordi], tmp2.p_idx[ordi], tmp2.p_nnz[ordi],
                                          tmpsrc->p_im[ordi], tmpsrc->p_idx[ordi], tmpsrc->p_nnz[ordi],
                                          tmpdest->p_im[ordi], tmpdest->p_idx[ordi], &tmpdest->p_nnz[ordi], dhl);
                }

            }  

        }

    }

    // reset the size values of the tmp number    
    for(ordi=0; ordi<res_ord; ordi++){

        tmpdest->p_size[ordi] = MAX(dhl.p_dh[ordi].allocSize,tmpdest->p_nnz[ordi]);
    }

    res = soti_copy(tmpdest, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_sum(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t res, tmp;
    ord_t res_ord = MAX(num1->order,num2->order);
    ord_t ordi;

    tmp = soti_get_tmp(0,res_ord,dhl); // creates a sotinum with no elements in imaginary directions.

    tmp.re = num1->re + num2->re;

    for(ordi=0; ordi<res_ord; ordi++){
        
        if (ordi < num1->order && ordi < num2->order){
            
            dhelp_sparse_add_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
                                  num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);

        } else if (ordi < num1->order){

            dhelp_sparse_add_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
                                  NULL, NULL, 0,
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);

        } else {

            dhelp_sparse_add_dirs(num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
                                  NULL, NULL, 0,
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);            

        }

    }

    // reset the size values of the tmp number    
    for(ordi=0; ordi<res_ord; ordi++){

        tmp.p_size[ordi] = MAX(dhl.p_dh[ordi].allocSize,tmp.p_nnz[ordi]);
    }

    res = soti_copy(&tmp, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sub(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t res, tmp;
    ord_t res_ord = MAX(num1->order,num2->order);
    ord_t ordi;

    tmp = soti_get_tmp(0,res_ord,dhl); // creates a sotinum with no elements in imaginary directions.

    tmp.re = num1->re - num2->re;

    for(ordi=0; ordi<res_ord; ordi++){

        
        if (ordi < num1->order && ordi < num2->order){
            
            dhelp_sparse_sub_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
                                  num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);

        } else if (ordi < num1->order){

            dhelp_sparse_sub_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
                                  NULL, NULL, 0,
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);

        } else {

            dhelp_sparse_sub_dirs(NULL, NULL, 0,
                                  num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);            

        }

    }

    // reset the size values of the tmp number    
    for(ordi=0; ordi<res_ord; ordi++){

        tmp.p_size[ordi] = MAX(dhl.p_dh[ordi].allocSize,tmp.p_nnz[ordi]);
    }

    res = soti_copy(&tmp, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_div_otireal(sotinum_t* num, coeff_t val, dhelpl_t dhl){

    return soti_mul_real(1.0/val,num,dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sub_realoti( coeff_t val, sotinum_t* num, dhelpl_t dhl){

    sotinum_t res = soti_neg(num,dhl);
    
    res.re += val;

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sub_otireal(sotinum_t* num, coeff_t val, dhelpl_t dhl){

    return soti_sum_real(-val,num,dhl);
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_neg(sotinum_t* num, dhelpl_t dhl){
    
    return soti_mul_real(-1.0,num,dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_mul_real(coeff_t val, sotinum_t* num, dhelpl_t dhl){
    
    sotinum_t res = soti_copy(num,dhl);

    res.re *= val;

    for (ord_t i=0; i<res.order; i++){
        
        for (ndir_t j = 0; j<res.p_nnz[i]; j++){

            res.p_im[i][j] *= val;

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sum_real(coeff_t val, sotinum_t* num, dhelpl_t dhl){
    
    sotinum_t res = soti_copy(num,dhl);

    res.re += val;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_copy(sotinum_t* num, dhelpl_t dhl){

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

        for (ord_t i = 0; i<res.order; i++){
            
            // Set number of non-zero and allocated size to 0.
            res.p_nnz[i]  = num->p_nnz[i]; 
            res.p_size[i] = num->p_size[i];

            if (num->p_size[i] != 0){
            
                res.p_im[i] = (coeff_t*)malloc(num->p_size[i]*sizeof(coeff_t)); 
                res.p_idx[i]= (imdir_t*)malloc(num->p_size[i]*sizeof(imdir_t)); 

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

// ****************************************************************************************************
void soti_insert_item( ndir_t pos, coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, 
    dhelpl_t dhl){
    
    coeff_t* p_newim;
    imdir_t* p_newidx;
    coeff_t* p_tmpim;
    imdir_t* p_tmpidx;

    // check feasability
    if (order > dhl.ndh){
        printf("ERROR: Not possible to set an element of order greaer than the helpers\n");
        exit(OTI_BadIndx);
    }

    if (num->p_nnz[order-1] == num->p_size[order-1]){
        
        // reallocation is needed
        
        p_newim  = (coeff_t*)realloc(num->p_im[order-1] , (num->p_size[order-1]+_REALLOC_SIZE)*sizeof(coeff_t));
        p_newidx = (imdir_t*)realloc(num->p_idx[order-1], (num->p_size[order-1]+_REALLOC_SIZE)*sizeof(imdir_t));
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

        if ( order<=num->order ){
            
            

            pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );

            if (flag != 0){

                num->p_im[order-1][pos] = val;

            } else {

                soti_insert_item( pos, val, idx, order, num, dhl);

            }

        // } else {
            
        //     // Change truncation order before setting an element of higher order

        //     printf("ERROR: Order change is not yet implemented\n");
        //     exit(OTI_NotImplemented);
        }

    }

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

// ****************************************************************************************************
void soti_print(sotinum_t* num, dhelpl_t dhl){

    ndir_t nnz_total = 1;
    for(ord_t ordi = 0; ordi<num->order; ordi++){
        nnz_total += num->p_nnz[ordi];
    }

    printf("  Order: "_PORDT", non_zero: "_PNDIRT", re: %11.4e\n",
        num->order, nnz_total, num->re);
    printf("  ORD ,    IMDIR  ,   VALUE   \n");

    printf("    0 ,         0 ,%11.4e\n",num->re);

    for(ord_t ord = 0; ord<num->order; ord++){

        ndir_t ndir_i = num->p_nnz[ord];

        for (ndir_t dir=0; dir< ndir_i; dir++){

            printf(" %4hhu , %9lu ,%11.4e\n",ord+1, num->p_idx[ord][dir], num->p_im[ord][dir]);

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_free(sotinum_t* num){
    
    if( num->order != 0 ){
        
        for (ord_t i=0; i<num->order; i++){
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
        res.p_nnz = (ndir_t*)malloc( res.order * sizeof(ndir_t) );
        res.p_size= (ndir_t*)malloc( res.order * sizeof(ndir_t) );

        if (res.p_im  == NULL || res.p_idx == NULL || res.p_nnz == NULL || res.p_size == NULL ){

            printf("ERROR: Not enough memory to handle oti number.\n Exiting...\n");
            exit(OTI_OutOfMemory);

        }

        for (ord_t i =0; i<res.order; i++){
            
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

// ----------------------------------------------------------------------------------------------------
// -----------------------------     END SPROTINUM FUNCTIONS     --------------------------------------
// ----------------------------------------------------------------------------------------------------