#include "oti/otinum_spr.h"

// ----------------------------------------------------------------------------------------------------
// -------------------------------     SPROTINUM FUNCTIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************

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
sotinum_t soti_sum(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t res, tmp;
    ord_t res_ord = MAX(num1->order,num2->order);
    ord_t ordi;
    ndir_t j1,j2, jres;
    imdir_t dir1, dir2;

    tmp = soti_get_tmp(0,res_ord,dhl); // creates a sotinum with no elements in imaginary directions.

    tmp.re = num1->re + num2->re;

    for(ordi=0; ordi<res_ord; ordi++){

        
        if (ordi < num1->order && ordi < num2->order){
            
            j1   = 0; 
            j2   = 0;
            jres = 0;
            
            while( 1 ){
            
                if (j1<num1->p_nnz[ordi] && j2<num2->p_nnz[ordi]){
                    
                    dir1 = num1->p_idx[ordi][j1];
                    dir2 = num2->p_idx[ordi][j2];
                    
                    if (dir1 == dir2){
                        
                        tmp.p_im[ordi][jres] = num1->p_im[ordi][j1]+num2->p_im[ordi][j2];
                        tmp.p_idx[ordi][jres] = dir1;
                        tmp.p_nnz[ordi]++;
                        j1++; j2++; jres++;

                    }else if(dir1<dir2){

                        tmp.p_im[ordi][jres] = num1->p_im[ordi][j1];
                        tmp.p_idx[ordi][jres] = dir1;
                        tmp.p_nnz[ordi]++;
                        jres++; j1++;

                    } else{

                        tmp.p_im[ordi][jres] = num2->p_im[ordi][j2];
                        tmp.p_idx[ordi][jres] = dir2;
                        tmp.p_nnz[ordi]++;  
                        jres++; j2++;
                    }

                } else if(j1<num1->p_nnz[ordi]){

                    // faster if  the cycle is performed here.
                    tmp.p_im[ordi][jres]  = num1->p_im[ordi][j1];
                    tmp.p_idx[ordi][jres] = num1->p_idx[ordi][j1];
                    tmp.p_nnz[ordi]++;
                    jres++; j1++;

                } else if(j2<num2->p_nnz[ordi]){   

                    // faster if  the cycle is performed here.
                    tmp.p_im[ordi][jres]  = num2->p_im[ordi][j2];
                    tmp.p_idx[ordi][jres] = num2->p_idx[ordi][j2];
                    tmp.p_nnz[ordi]++;
                    jres++; j2++;

                } else {

                    break;

                }
            
            }


        } else if (ordi < num1->order){

            j1   = 0; 
            jres = 0;
            
            for(j1=0;j1 < num1->p_nnz[ordi]; j1++){

                tmp.p_im[ordi][jres]  = num1->p_im[ordi][j1];
                tmp.p_idx[ordi][jres] = num1->p_idx[ordi][j1];
                tmp.p_nnz[ordi]++;
                jres++; j1++;

            }

        } else {

            j2   = 0;
            jres = 0;
            
            for(j2=0;j2 < num2->p_nnz[ordi]; j2++){

                tmp.p_im[ordi][jres]  = num2->p_im[ordi][j2];
                tmp.p_idx[ordi][jres] = num2->p_idx[ordi][j2];
                tmp.p_nnz[ordi]++;
                jres++; j2++;
                
            }

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