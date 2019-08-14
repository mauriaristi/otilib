#include "oti/otinum_spr.h"

// ----------------------------------------------------------------------------------------------------
// -------------------------------     SPROTINUM FUNCTIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************

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












// ****************************************************************************************************
sotinum_t soti_atanh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_asinh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_acosh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_tanh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sqrt(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_cosh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sinh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_asin(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_acos(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_atan(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_tan(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_cos(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sin(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_logb(sotinum_t* num, double base, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->re, base, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_log10(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_log(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_exp(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_pow(sotinum_t* num, double e, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->re, e, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------











// ****************************************************************************************************
inline sotinum_t soti_feval(coeff_t* feval_re, sotinum_t* num, dhelpl_t dhl ){
    
    
    sotinum_t res;
    sotinum_t tmp = soti_base_feval(feval_re, num, dhl);
    
    // copy....
    res = soti_copy( &tmp, dhl); // Newly allocated.

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_mul(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    
    sotinum_t res, tmp;

    tmp = soti_base_mul(num1,num2,dhl);

    res = soti_copy(&tmp, dhl); // Newly allocated.

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sum(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t res, tmp;

    tmp = soti_base_sum( num1, num2, dhl);

    res = soti_copy(&tmp, dhl); // Newly allocated.

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sub(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t res, tmp;

    tmp = soti_base_sub( num1, num2, dhl);

    res = soti_copy(&tmp, dhl); // Newly allocated.

    return res;

}
// ----------------------------------------------------------------------------------------------------


















// ****************************************************************************************************
void soti_atanh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_asinh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_acosh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_tanh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sqrt_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_cosh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sinh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_asin_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_acos_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_atan_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_tan_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_cos_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sin_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_logb_to(sotinum_t* num, double base, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->re, base, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_log10_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_log_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_exp_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_pow_to(sotinum_t* num, double e, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->re, e, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------











// ****************************************************************************************************
inline void soti_feval_to(coeff_t* feval_re, sotinum_t* num, sotinum_t* res, dhelpl_t dhl ){
    
    
    sotinum_t tmp = soti_base_feval(feval_re, num, dhl);
    
    soti_copy_to( &tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void soti_mul_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl){

    
    sotinum_t  tmp;

    tmp = soti_base_mul(num1,num2,dhl);

    soti_copy_to(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void soti_sum_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl){

    sotinum_t tmp;

    tmp = soti_base_sum( num1, num2, dhl);

    soti_copy_to(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void soti_sub_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl){

    sotinum_t tmp;

    tmp = soti_base_sub( num1, num2, dhl);

    soti_copy_to(&tmp, res, dhl);

}
// ----------------------------------------------------------------------------------------------------



















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
inline sotinum_t soti_base_feval(coeff_t* feval_re, sotinum_t* num, dhelpl_t dhl ){
    
    ord_t i ;

    coeff_t factor = 1.0, val = 0.0;
    sotinum_t tmp1 = soti_get_rtmp( 7,num->order,dhl);
    sotinum_t tmp2 = soti_get_rtmp( 8,num->order,dhl);
    sotinum_t tmp3 = soti_get_rtmp( 9,num->order,dhl);

    soti_set( num, &tmp2, dhl);

    for ( i = 1; i < num->order; i++){
        
        factor *= i;

        val = feval_re[i]/factor;
        
        soti_set(&tmp2 , &tmp1, dhl);
        soti_trunc_smul_real( val, i, &tmp2, dhl);
        soti_trunc_ssum( &tmp2, i, &tmp3, dhl );
        
        // update
        soti_setFromReal( 0.0, &tmp2, dhl);
        soti_trunc_mul(&tmp1, i, num, 1, &tmp2, dhl );

    }

    for (; i<=num->order; i++){
        
        factor *= i;
        val = feval_re[i]/factor;        
        soti_set(&tmp2 , &tmp1, dhl);
        soti_trunc_smul_real( val, i, &tmp2, dhl);
        soti_trunc_ssum( &tmp2, i, &tmp3, dhl );

    }

    // Set real value.
    tmp3.re = feval_re[0];
    
    return tmp3;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline sotinum_t soti_base_mul(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t tmp, tmp2, tmp3;
    sotinum_t* tmpsrc = &tmp ;
    sotinum_t* tmpdest= &tmp3;
    sotinum_t* tmpswap;
    ord_t res_ord = MAX(num1->order,num2->order);
    ord_t ordlim1, ordlim2;
    ord_t ordi1, ordi2,ordires;

    // Retreive sotinum temporals.
    // All tmps are created with no elements in imaginary directions (but allocated).
    tmp = soti_get_rtmp(3,res_ord,dhl); // will hold the final result.
    tmp2= soti_get_rtmp(4,res_ord,dhl); // Will hold the temporary result.
    tmp3= soti_get_rtmp(5,res_ord,dhl); // Will hold the temporary result.

    // Multiply real coefficients.
    tmpdest->re = num1->re * num2->re;
    tmpsrc->re  = tmpdest->re;

    if (num1->re != 0.0 && num2->order > 0 ){

        // Swap pointers
        tmpswap=tmpsrc; 
        tmpsrc=tmpdest; 
        tmpdest=tmpswap;

        for (ordi1 = 0; ordi1<num2->order; ordi1++){

            // Perform multiplication
            dhelp_sparse_mult_real(num1->re,
                               num2->p_im[ordi1], num2->p_idx[ordi1], num2->p_nnz[ordi1],
                               tmp2.p_im[ordi1], tmp2.p_idx[ordi1], &tmp2.p_nnz[ordi1],       
                               dhl);              

            dhelp_sparse_add_dirs(tmp2.p_im[ordi1], tmp2.p_idx[ordi1], tmp2.p_nnz[ordi1],
                                  tmpsrc->p_im[ordi1], tmpsrc->p_idx[ordi1], tmpsrc->p_nnz[ordi1],
                                  tmpdest->p_im[ordi1], tmpdest->p_idx[ordi1], &tmpdest->p_nnz[ordi1], dhl);

        }

    }

    if (num2->re != 0.0 && num1->order > 0 ){

        // Swap pointers
        tmpswap = tmpsrc; tmpsrc=tmpdest; tmpdest=tmpswap;

        for (ordi1 = 0; ordi1<num1->order; ordi1++){

            // Perform multiplication
            dhelp_sparse_mult_real(num2->re,
                               num1->p_im[ordi1], num1->p_idx[ordi1], num1->p_nnz[ordi1],
                               tmp2.p_im[ordi1], tmp2.p_idx[ordi1], &tmp2.p_nnz[ordi1],       
                               dhl);  

            dhelp_sparse_add_dirs(tmp2.p_im[ordi1], tmp2.p_idx[ordi1], tmp2.p_nnz[ordi1],
                                  tmpsrc->p_im[ordi1], tmpsrc->p_idx[ordi1], tmpsrc->p_nnz[ordi1],
                                  tmpdest->p_im[ordi1], tmpdest->p_idx[ordi1], &tmpdest->p_nnz[ordi1], dhl);

        }

    }
    
    if ( num1->order > 0 && num1->order > 0 ){
        
        tmpsrc->p_im[0]  = tmpdest->p_im[0] ;
        tmpsrc->p_idx[0] = tmpdest->p_idx[0];
        tmpsrc->p_nnz[0] = tmpdest->p_nnz[0];

        ordlim1 = MIN(num1->order, res_ord - 1);
        
        for(ordi1=0; ordi1<ordlim1; ordi1++){

            ordlim2 = MIN(num2->order, res_ord - (ordi1+1) );

            tmpswap = tmpsrc; tmpsrc=tmpdest; tmpdest=tmpswap;

            // Multiply elements of order ordi1 times all elements of order 
            for (ordi2=0; ordi2<ordlim2; ordi2++){

                ordires = ordi1 + ordi2 +1;

                dhelp_sparse_mult(num1->p_im[ordi1], num1->p_idx[ordi1], num1->p_nnz[ordi1],ordi1+1,
                                  num2->p_im[ordi2], num2->p_idx[ordi2], num2->p_nnz[ordi2],ordi2+1,
                                  tmp2.p_im[ordires],tmp2.p_idx[ordires],&tmp2.p_nnz[ordires], dhl);

                dhelp_sparse_add_dirs(tmp2.p_im[ordires], tmp2.p_idx[ordires], tmp2.p_nnz[ordires],
                                      tmpsrc->p_im[ordires], tmpsrc->p_idx[ordires], tmpsrc->p_nnz[ordires],
                                      tmpdest->p_im[ordires], tmpdest->p_idx[ordires], &tmpdest->p_nnz[ordires], dhl);

            }

            tmpsrc->p_im[ ordi1+1] = tmpdest->p_im[ ordi1+1];
            tmpsrc->p_idx[ordi1+1] = tmpdest->p_idx[ordi1+1];
            tmpsrc->p_nnz[ordi1+1] = tmpdest->p_nnz[ordi1+1];

        }
    
    }
    
    // This returns whatever temporal is selected at this time.
    return *tmpdest;

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
inline sotinum_t soti_base_sum(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t tmp;
    ord_t res_ord = MAX(num1->order,num2->order);
    ord_t ordi;

    tmp = soti_get_rtmp(7,res_ord,dhl); // creates a sotinum with no elements in imaginary directions.

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

    return tmp;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline sotinum_t soti_base_sub(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t tmp;
    ord_t res_ord = MAX(num1->order,num2->order);
    ord_t ordi;

    tmp = soti_get_rtmp(7,res_ord,dhl); // creates a sotinum with no elements in imaginary directions.

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

    return tmp;

}
// ----------------------------------------------------------------------------------------------------








































// ****************************************************************************************************
void soti_trunc_smul_real(coeff_t a, ord_t ord, sotinum_t* res, dhelpl_t dhl){
    
    ord_t ordi;
    ndir_t i;

    if (a == 0.0){
        
        for (  ordi = ord-1; ordi < res->order; ordi++){

            res->p_nnz[ordi]=0.0;

        }

    } else {

        for (  ordi = ord-1; ordi < res->order; ordi++){

            for ( i=0; i<res->p_nnz[ordi]; i++){
                
                res->p_im[ordi][i] *= a;

            }

        }

    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_trunc_ssum(sotinum_t* num1, ord_t ord, sotinum_t* res, dhelpl_t dhl ){
    
    // Initialize
    ord_t ordi;

    sotinum_t tmpres = soti_get_rtmp(6,res->order,dhl); 
    
    soti_set(res, &tmpres, dhl);

    for (  ordi = ord-1; ordi < res->order; ordi++){

        dhelp_sparse_add_dirs(num1->p_im[ordi],  num1->p_idx[ordi],   num1->p_nnz[ordi],
                               res->p_im[ordi],   res->p_idx[ordi],    res->p_nnz[ordi],
                             tmpres.p_im[ordi], tmpres.p_idx[ordi], &tmpres.p_nnz[ordi], dhl);

    }

    soti_set_trunc( &tmpres, ord, res, dhl);
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_trunc_mul(sotinum_t* num1, ord_t ord1, 
                    sotinum_t* num2, ord_t ord2, 
                    sotinum_t* dest, dhelpl_t dhl ){

    sotinum_t res, tmp, tmp2, tmp3;
    sotinum_t* tmpsrc= &tmp ;
    sotinum_t* tmpdest=&tmp3;
    sotinum_t* tmpswap;
    ord_t res_ord = MAX(num1->order,num2->order);
    ord_t ordlim1, ordlim2;
    ord_t ordi1, ordi2,ordires;

    // Retreive sotinum temporals.
    // All tmps are created with no elements in imaginary directions (but allocated).
    tmp = soti_get_rtmp(3,res_ord,dhl); // will hold the final result.
    tmp2= soti_get_rtmp(4,res_ord,dhl); // Will hold the temporary result.
    tmp3= soti_get_rtmp(5,res_ord,dhl); // Will hold the temporary result.    
        
    ordlim1 = MIN(num1->order, res_ord - 1);
    
    for(ordi1=ord1-1; ordi1<ordlim1; ordi1++){

        ordlim2 = MIN(num2->order, res_ord - (ordi1+1) );

        tmpswap = tmpsrc; tmpsrc=tmpdest; tmpdest=tmpswap;

        // printf("Lim ord2: %hhu\n",ordlim2);
        for (ordi2=ord2-1; ordi2<ordlim2; ordi2++){

            ordires = ordi1 + ordi2 + 1;

            dhelp_sparse_mult(num1->p_im[ordi1  ], num1->p_idx[ordi1  ], num1->p_nnz[ordi1  ], ordi1+1,
                              num2->p_im[ordi2  ], num2->p_idx[ordi2  ], num2->p_nnz[ordi2  ], ordi2+1,
                               tmp2.p_im[ordires],  tmp2.p_idx[ordires], &tmp2.p_nnz[ordires],     dhl );
            
            dhelp_sparse_add_dirs(    tmp2.p_im[ordires],     tmp2.p_idx[ordires],      tmp2.p_nnz[ordires],
                                   tmpsrc->p_im[ordires],  tmpsrc->p_idx[ordires],   tmpsrc->p_nnz[ordires],
                                  tmpdest->p_im[ordires], tmpdest->p_idx[ordires], &tmpdest->p_nnz[ordires], dhl);
            
        }

        tmpsrc->p_im[ ordi1+ord2] = tmpdest->p_im[ ordi1+ord2];
        tmpsrc->p_idx[ordi1+ord2] = tmpdest->p_idx[ordi1+ord2];
        tmpsrc->p_nnz[ordi1+ord2] = tmpdest->p_nnz[ordi1+ord2];

    }
    

    soti_set_trunc( tmpdest, ord1+ord2-1, dest, dhl);

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
sotinum_t soti_div_realoti(coeff_t num, sotinum_t* den, dhelpl_t dhl){

    
    sotinum_t inv = soti_pow(den,-1,dhl);

    sotinum_t res = soti_mul_real(num,&inv,dhl);

    soti_free(&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_div(sotinum_t* num, sotinum_t* den, dhelpl_t dhl){

    
    sotinum_t inv = soti_pow(den,-1,dhl);
    sotinum_t res = soti_mul(num,&inv,dhl);
    soti_free(&inv);

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
    
    ord_t i;
    ndir_t j;

    sotinum_t res = soti_copy(num,dhl);

    res.re *= val;

    for ( i=0; i<res.order; i++){
        
        for ( j = 0; j<res.p_nnz[i]; j++){

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


// ****************************************************************************************************
void soti_set_trunc( sotinum_t* src, ord_t ord, sotinum_t* dest, dhelpl_t dhl){
    
    // Assumes both have the space allocated and both have the same truncation order
    ord_t i;

    for ( i =ord-1; i<src->order; i++){
        
        // Set number of non-zero and allocated size to 0.
        dest->p_nnz[i]  = src->p_nnz[i];

        memcpy(dest->p_im[i], src->p_im[i], dest->p_nnz[i]*sizeof(coeff_t));
        memcpy(dest->p_idx[i],src->p_idx[i],dest->p_nnz[i]*sizeof(imdir_t));

    }

}
// ----------------------------------------------------------------------------------------------------



























































// ****************************************************************************************************
sotinum_t soti_mul_old(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t res, tmp, tmp2, tmp3;
    sotinum_t* tmpsrc= &tmp ;
    sotinum_t* tmpdest=&tmp3;
    sotinum_t* tmpswap;
    ord_t res_ord = MAX(num1->order,num2->order);
    ord_t ordi, order;
    ord_t ord_mul1;

    // Retreive sotinum temporals.
    // All tmps are created with no elements in imaginary directions (but allocated).
    tmp = soti_get_rtmp(0,res_ord,dhl); // will hold the final result.
    tmp2= soti_get_rtmp(1,res_ord,dhl); // Will hold the temporary result.
    tmp3= soti_get_rtmp(2,res_ord,dhl); // Will hold the temporary result.
    

    // Multiply real coefficients.
    tmpdest->re = num1->re * num2->re;
    tmpsrc->re  = tmpdest->re;

    // printf("Multiplying order %hhu x %hhu\n", num1->order, num2->order);

    for( order=1; order<=res_ord; order++){

        ordi = order-1;

        // First multiply  re x ordi         
        if ( order <= num2->order && num1->re != 0.0){
            
            // Perform multiplication
            dhelp_sparse_mult_real(num1->re,
                               num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
                               tmp2.p_im[ordi], tmp2.p_idx[ordi], &tmp2.p_nnz[ordi],       
                               dhl);  
            
            
            // Swap pointers
            tmpswap=tmpsrc; tmpsrc=tmpdest; tmpdest=tmpswap;

            dhelp_sparse_add_dirs(tmp2.p_im[ordi], tmp2.p_idx[ordi], tmp2.p_nnz[ordi],
                                  tmpsrc->p_im[ordi], tmpsrc->p_idx[ordi], tmpsrc->p_nnz[ordi],
                                  tmpdest->p_im[ordi], tmpdest->p_idx[ordi], &tmpdest->p_nnz[ordi], dhl);

        }


        // Then multiply   ordi x re
        if ( order <= num1->order && num2->re != 0.0){
            
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

        for ( ord_mul1 = 1; ord_mul1 <= order/2; ord_mul1++){

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






// ----------------------------------------------------------------------------------------------------
// -----------------------------     END SPROTINUM FUNCTIONS     --------------------------------------
// ----------------------------------------------------------------------------------------------------