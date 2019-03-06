#include "oti/otinum_dense.h"

// ----------------------------------------------------------------------------------------------------
// ---------------------------------     OTINUM FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************

// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
// otinum_t oti_atan2(otinum_t* num, otinum_t* y, dhelpl_t dhl){
//     coeff_t derivs[10];



//     return oti_feval(derivs, num, dhl);
// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_atanh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_asinh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_acosh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_tanh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sqrt(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_cosh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sinh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_asin(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_acos(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_atan(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_tan(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_cos(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sin(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_logb(otinum_t* num, double base, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->re, base, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_log10(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_log(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_exp(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_pow(otinum_t* num, double e, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->re, e, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_trunc_smul_real(coeff_t a, ord_t ord, otinum_t* res, dhelpl_t dhl){

    for ( ord_t ordi = ord-1; ordi < res->order; ordi++){

        for (ndir_t i=0; i<res->p_ndpo[ordi]; i++){
            
            res->p_im[ordi][i] *= a;

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_trunc_ssum(otinum_t* num1, 
                    ord_t ord, otinum_t* res, dhelpl_t dhl ){
    
    // Initialize

    for ( ord_t ordi = ord-1; ordi < res->order; ordi++){

        for (ndir_t i=0; i < res->p_ndpo[ordi]; i++){
            
            res->p_im[ordi][i] += num1->p_im[ordi][i];

        }

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_trunc_mul(otinum_t* num1, ord_t ord1, 
                   otinum_t* num2, ord_t ord2, 
                   otinum_t* res, dhelpl_t dhl ){
    
    
    // // Initialize
    // oti_setFromReal( 0.0, res, dhl);

    // printf("Finding combinations for order "_PORDT _ENDL, res->order);

    for (ord_t ord_mul1 =ord1; ord_mul1 <= res->order; ord_mul1++){

        for (ord_t ord_mul2 = res->order-ord_mul1; ord_mul2 >= ord2; ord_mul2--){

            // printf("Multiplying order "_PORDT" times "_PORDT _ENDL, ord_mul1,ord_mul2);
            ord_t ord_res = ord_mul1 + ord_mul2;

            dhelp_dense_mult( num1->p_im[ord_mul1-1], num1->p_ndpo[ord_mul1-1], ord_mul1, 
                      num2->p_im[ord_mul2-1], num2->p_ndpo[ord_mul2-1], ord_mul2,
                      res->p_im[ord_res-1], res->p_ndpo[ord_res]-1,
                      dhl);

        }   

    }
    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_div_otireal(otinum_t* num, coeff_t den, dhelpl_t dhl ){

    return oti_mul_real(1.0/den, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_div_realoti(coeff_t num, otinum_t* den, dhelpl_t dhl ){
    otinum_t tmp1 = oti_pow(den , -1.0, dhl);
    otinum_t res = oti_mul_real(num, &tmp1, dhl);
    oti_free(&tmp1);
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_div(otinum_t* num, otinum_t* den, dhelpl_t dhl ){
    
    coeff_t y = num->re, x = den->re;
    coeff_t deriv_x, deriv_y;
    otinum_t res  = oti_createZero( num->nbases, num->order, dhl);
    otinum_t tmp1 = oti_createZero( num->nbases, num->order, dhl);
    otinum_t tmp2 = oti_createZero( num->nbases, num->order, dhl);
    otinum_t tmp3 = oti_createZero( num->nbases, num->order, dhl);
    // otinum_t tmp4 = oti_createZero( num->nbases, num->order, dhl);

    oti_set( den, &tmp2, dhl); // x
    oti_set( num, &tmp3, dhl); // y
    
    // Set real value of result.
    res.re = y/x;
    deriv_x = y/x;

    // if (num->order >= 1){

    for (ord_t i = 1; i<=num->order; i++){
    
        
        // do the part for y.
        deriv_y = deriv_x / y ;
        oti_set( &tmp3 , &tmp1 , dhl);
        oti_trunc_smul_real( deriv_y, i, &tmp3, dhl); 
        oti_trunc_ssum( &tmp3, i, &res, dhl );

        if (1 != num->order ){

            oti_setFromReal( 0.0, &tmp3, dhl);
            oti_trunc_mul(&tmp1, i, den, 1, &tmp3, dhl );
            // oti_set(&tmp3, &tmp1, dhl);

        }
        
        // do the part for x.
        deriv_x = -deriv_x / x ;
        oti_set( &tmp2 , &tmp1 , dhl); 
        oti_trunc_smul_real( deriv_x, i, &tmp2, dhl); 
        oti_trunc_ssum( &tmp2, i, &res, dhl );

        if (1 != num->order ){

            oti_setFromReal( 0.0, &tmp2, dhl);
            oti_trunc_mul(&tmp1, i, den, 1, &tmp2, dhl );
            // oti_set(&tmp2 , &tmp1, dhl);

        }

    }

    oti_free(&tmp1); oti_free(&tmp2); oti_free(&tmp3); 
    
    // }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
otinum_t oti_feval(coeff_t* feval_re, otinum_t* num, dhelpl_t dhl ){
    
    coeff_t factor = 1.0, val = 0.0;
    otinum_t res  = oti_createZero( num->nbases, num->order, dhl);
    otinum_t tmp1 = oti_createZero( num->nbases, num->order, dhl);
    otinum_t tmp2 = oti_createZero( num->nbases, num->order, dhl);

    oti_set( num, &tmp2, dhl);
    
    // Set real value of result.
    res.re = feval_re[0];

    for (ord_t i = 1; i<=num->order; i++){

        factor *= i;

        val = feval_re[i]/factor;
        
        oti_set(&tmp2 , &tmp1, dhl);

        oti_trunc_smul_real( val, i, &tmp2, dhl);

        oti_trunc_ssum( &tmp2, i, &res, dhl );

        // update
        if (i != num->order ){

            oti_setFromReal( 0.0, &tmp2, dhl);
            oti_trunc_mul(&tmp1, i, num, 1, &tmp2, dhl );
            oti_set(&tmp2 , &tmp1, dhl);

        }

    }

    oti_free(&tmp1); oti_free(&tmp2);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sub_otireal(otinum_t* num1, coeff_t a, dhelpl_t dhl){
    
    otinum_t res = oti_copy(num1,dhl);;
    res.re -= a;
    return res;

}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sub_realoti(coeff_t a, otinum_t* num2, dhelpl_t dhl){
    
    otinum_t res = oti_neg(num2,dhl);;
    res.re += a;
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_neg(otinum_t* num1, dhelpl_t dhl){

    otinum_t res = oti_copy( num1, dhl);
    
    res.re *= -1;

    if (num1->order != 0){

        for ( ord_t ordi = 0; ordi < res.order; ordi++){

            for (ndir_t i=0; i < res.p_ndpo[ordi]; i++){
                
                res.p_im[ordi][i] *= -1;

            }

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sub(otinum_t* num1, otinum_t* num2, dhelpl_t dhl){

    otinum_t res = oti_copy( num1, dhl);
    
    res.re -= num2->re;

    if (num1->nbases == num2->nbases && num1->order == num2->order){

        for ( ord_t ordi = 0; ordi < res.order; ordi++){

            for (ndir_t i=0; i < res.p_ndpo[ordi]; i++){
                
                res.p_im[ordi][i] -= num2->p_im[ordi][i];

            }

        }

    } else {

        printf("Error: Addition of oti numbers with different bases or orders not yet supported.\n");
        exit(OTI_undetErr);
    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
otinum_t oti_mul(otinum_t* num1, otinum_t* num2, dhelpl_t dhl){

    otinum_t res = oti_createZero( num1->nbases, num1->order, dhl);
    
    //  0 X 0
    res.re = num1->re * num2->re;

    for ( ord_t ord_res = 1; ord_res <= res.order; ord_res++){


        // First multiply  re x ord_res        
        dhelp_dense_mult_real(num2->p_im[ord_res-1],num2->p_ndpo[ord_res-1],
            num1->re,
            res.p_im[ord_res-1],res.p_ndpo[ord_res-1],
            dhl);

        // Then multiply   ord_res x re
        dhelp_dense_mult_real(num1->p_im[ord_res-1],num1->p_ndpo[ord_res-1],
            num2->re,
            res.p_im[ord_res-1],res.p_ndpo[ord_res-1],
            dhl);

        for (ord_t ord_mul1 = 1; ord_mul1 <= ord_res/2; ord_mul1++){

            ord_t ord_mul2 = ord_res - ord_mul1;
            // printf("Multiplying %hhu X %hhu\n",ord_mul1,ord_mul2);

            dhelp_dense_mult( num1->p_im[ord_mul1-1], num1->p_ndpo[ord_mul1-1], ord_mul1, 
                      num2->p_im[ord_mul2-1], num2->p_ndpo[ord_mul2-1], ord_mul2,
                      res.p_im[ord_res-1], res.p_ndpo[ord_res]-1,
                      dhl);

            if (ord_mul1 != ord_mul2){
                
                // printf("Multiplying %hhu X %hhu\n",ord_mul2,ord_mul1);                

                dhelp_dense_mult( num1->p_im[ord_mul2-1], num1->p_ndpo[ord_mul2-1], ord_mul2, 
                          num2->p_im[ord_mul1-1], num2->p_ndpo[ord_mul1-1], ord_mul1,
                          res.p_im[ord_res-1], res.p_ndpo[ord_res]-1,
                          dhl);

            }  

        }
        

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
otinum_t oti_mul_real(coeff_t a, otinum_t* num1, dhelpl_t dhl){

    otinum_t res = oti_copy( num1, dhl);
    
    res.re *= a;

    for ( ord_t ordi = 0; ordi < res.order; ordi++){

        for (ndir_t i=0; i<res.p_ndpo[ordi]; i++){
            
            res.p_im[ordi][i] *= a;

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sum(otinum_t* num1, otinum_t* num2, dhelpl_t dhl){

    otinum_t res = oti_copy( num1, dhl);
    
    res.re += num2->re;

    if (num1->nbases == num2->nbases && num1->order == num2->order){

        for ( ord_t ordi = 0; ordi < res.order; ordi++){

            for (ndir_t i=0; i < res.p_ndpo[ordi]; i++){
                
                res.p_im[ordi][i] += num2->p_im[ordi][i];

            }

        }

    } else {

        printf("Error: Addition of oti numbers with different bases or orders not yet supported.\n");
        exit(OTI_undetErr);
    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sum_real(coeff_t a, otinum_t* num1, dhelpl_t dhl){

    otinum_t res = oti_copy(num1, dhl);
    
    res.re += a;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_set(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    res->re = num->re;
    
    // Copy information from num1 to res.
    for(ord_t ord = 0; ord<num->order; ord++){

        memcpy( res->p_im[ord], num->p_im[ord], res->p_ndpo[ord]*sizeof(coeff_t) );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_copy(otinum_t* num, dhelpl_t dhl){
    
    otinum_t res;
        
    // Allocate num1.
    res = oti_createEmpty( num->nbases, num->order, dhl);

    res.re = num->re;
    
    // Copy information from num1 to res.
    for(ord_t ord = 0; ord<num->order; ord++){

        res.p_ndpo[ord] = num->p_ndpo[ord];

        memcpy( res.p_im[ord], num->p_im[ord], res.p_ndpo[ord]*sizeof(coeff_t) );

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
    ord_t i, j =1;
    // compute the factor 
    if (coef != 0.0){
        dirs = dhelp_get_imdir(idx,order,dhl);
        dir_prev = dirs[0];
        for (i=0; i<order; i++){
            if (dirs[i] == dir_prev){
                factor *= j;
                j+=1;
            } else{
                j=1;
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

    // char* string = NULL;
    printf("  Order: %hhu, nbases: %hu, ndir: %lu, re: %11.4e\n",
        num->order, num->nbases, num->ndir, num->re);
    printf("  ORD ,    IMDIR  ,   VALUE   \n");

    printf("    0 ,         0 ,%11.4e\n",num->re);

    for(ord_t ord = 0; ord<num->order; ord++){

        ndir_t ndir_i = num->p_ndpo[ord];

        for (ndir_t dir=0; dir< ndir_i; dir++){

            printf(" %4hhu , %9lu ,%11.4e\n",ord+1, dir, num->p_im[ord][dir]);

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_free( otinum_t* num ){
    
    if (num->p_im != NULL){


        for (ord_t ordi = 0; ordi<num->order; ordi++){

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
    
    num->re = a;
    
    // Set all imaginary directions to 0
    if (num->order != 0){
        
        for (ord_t ordi = 0; ordi < num->order; ordi++){
            
            memset( num->p_im[ordi], 0, num->p_ndpo[ordi]*sizeof(coeff_t) );
        
        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_createEmpty(  bases_t nbases, ord_t order, dhelpl_t dhl ){
    
    otinum_t num; 
    
    // Get the number of imaginary directions for nbases and order.
    num.ndir = 0; // Excludes the real direction.

    // Set the values of the number first.
    num.order  = order;
    num.nbases = nbases;

    
    if (num.order != 0){
            
        // Allocate memory.
        num.p_im   = ( coeff_t** ) malloc( num.order*sizeof(coeff_t*) );
        num.p_ndpo = ( ndir_t* ) malloc( num.order*sizeof(ndir_t) );

        if (num.p_im == NULL  || num.p_ndpo == NULL ){
            printf("--- ERROR: Out of memory\n");
            exit(OTI_OutOfMemory);
        }

        for (ord_t ordi = 0; ordi<num.order; ordi++){

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



// ----------------------------------------------------------------------------------------------------
// -------------------------------     END OTINUM FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------