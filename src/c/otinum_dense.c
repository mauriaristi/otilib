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

    coeff_t derivs[10];

    der_r_atanh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_asinh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_asinh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_acosh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_acosh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_tanh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_tanh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sqrt(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_sqrt(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_cosh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_cosh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sinh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_sinh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_asin(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_asin(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_acos(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_acos(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_atan(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_atan(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_tan(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_tan(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_cos(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_cos(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sin(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_sin(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_logb(otinum_t* num, double base, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_logb(num->re, base, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_log10(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_log10(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_log(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_log(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_exp(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[10];

    der_r_exp(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_pow(otinum_t* num, double e, dhelpl_t dhl){

    coeff_t derivs[10];

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
otinum_t oti_div(otinum_t* num, otinum_t* den, dhelpl_t dhl ){
    
    coeff_t factor = 1.0, factor_prev, val_x, val_y, y = num->re, x = den->re;
    coeff_t deriv_x, deriv_y, sign = 1.0;
    otinum_t res  = oti_createZero( num->nbases, num->order, dhl);
    otinum_t tmp1 = oti_createZero( num->nbases, num->order, dhl);
    otinum_t tmp2 = oti_createZero( num->nbases, num->order, dhl);
    otinum_t tmp3 = oti_createZero( num->nbases, num->order, dhl);

    oti_set( num, &tmp2_x, dhl);
    oti_set( den, &tmp2_y, dhl);
    
    // Set real value of result.
    res.re = y/x;

    deriv_x = y/x;

    for (ord_t i = 1; i<=num->order; i++){
        
        factor_prev = factor;
        factor *= i;
        
        sign *= -1.0;
        
        deriv_y = deriv_x / y ;

        deriv_x = sign*factor*deriv_x / x ;

        val_x = deriv_x/factor;
        val_y = deriv_y/factor_prev;
        
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
            printf("Multiplying %hhu X %hhu\n",ord_mul1,ord_mul2);

            dhelp_dense_mult( num1->p_im[ord_mul1-1], num1->p_ndpo[ord_mul1-1], ord_mul1, 
                      num2->p_im[ord_mul2-1], num2->p_ndpo[ord_mul2-1], ord_mul2,
                      res.p_im[ord_res-1], res.p_ndpo[ord_res]-1,
                      dhl);

            if (ord_mul1 != ord_mul2){
                
                printf("Multiplying %hhu X %hhu\n",ord_mul2,ord_mul1);                

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





































































// // ****************************************************************************************************
// void c_oti_collapseDirA(uint16_t* array, uint8_t order, uint16_t* dirA, uint8_t* expA){



//     uint16_t oldValue = array[0];
//     uint8_t  count = 0;
//     uint8_t  iDir  = 0;
//     uint8_t  i;

//     for (i=0; i<order; i++ ){   // TODO: Check when it is in collapse if
//                                 // if array.size is order.

//         if( array[i] == 0){

//             continue;

//         }else if (array[i] == oldValue){
          
//             count++;

//         }else{
          
//             expA[iDir] = count;
//             dirA[iDir] = oldValue;
//             iDir += 1;
//             oldValue = array[i];
//             count = 1;

//         }

//     }

//     expA[iDir] = count;
//     dirA[iDir] = oldValue;
//     iDir++;

//     // Put zeros in all other values of the array, if it is the case:

//     if (iDir != order){// Check size of dirA
        
//         for(i=iDir; i<order; i++){

//           expA[i] = 0;
//           dirA[i] = 0;

//         }

//     }

// }
// // ----------------------------------------------------------------------------------------------------


// // ****************************************************************************************************
// void c_oti_expandDirA(uint16_t* p_dirA,uint8_t* p_expA, uint8_t order, uint16_t* p_expandArr){


    
//     uint8_t i=0, count = 0, idir = 0;

//     for (;i<order;i++){
        
//         p_expandArr[i] = p_dirA[idir];
//         count++;

//         if (count == p_expA[idir]){

//             count = 0;
//             idir++;

//         }

//     }

// }
// // ----------------------------------------------------------------------------------------------------


// // ****************************************************************************************************
// double c_oti_FaaDiBruno(uint64_t indx, double* fder, otinum_t* g, directionHelper* p_dH){
//     /*
//     double c_oti_FaaDiBruno(uint64_t indx, double* fder, otinum_t* g, directionHelper* p_dH)
    
//     Apply the Faa di Bruno formula to find the coefficient that corresponds to a specific partial
//     derivative of f.

//     To differentiate a function f that depends on another function
//     g which depends on several variables. 

//     i.e. f( g(x1,...,xn) )

//     g comes evaluated and it is represented by an OTI number.

//     INPUTS:

//         -> indx:    Direction to compute Faa di Bruno formula
        
//         ->  fder:   Array of values holding all the derivatives of f with respect to g up to 
//                     g.order. 
        
//         ->  g:      oti number that represents g(x1,...,xn).

//         ->  p_dH:  list of helpers.

  
//     WARNING:    This is a very rudimentary implementation. If you have time to
//                 contribute, this is a function that might be very crucial to 
//                 optimize.

//     */

//     double sum_ = 0.;
//     double mult ;
//     uint8_t orderg = g->order;
//     uint16_t* dirA  = c_helper_getDirA(indx,orderg,p_dH);  // 
//     uint8_t* expA   = c_helper_getExpA(indx,orderg,p_dH);  // 
//     uint16_t* dirA_ = c_helper_getUDirA(orderg,0,p_dH);    // It is expensive to create arrays
//     uint8_t* expA_  = c_helper_getUExpA(orderg,0,p_dH);    // at each iteration. Consider 
//     uint64_t i, j, k, el, count, nsets;                    // inputing the allocated arrays  
//     uint16_t seti;
//     uint8_t order = c_sumUI8(expA,orderg);
//     uint16_t* expandedArray = c_helper_getUDirA(orderg,1,p_dH);
//     uint16_t* mdir          = c_helper_getUDirA(orderg,2,p_dH);  
//     double factor = 1.0;
//     uint64_t index;
//     uint64_t nevals = c_helper_getNParts(order,p_dH);



//     // printf("IN FAADIBRUNO\n");
//     // Expand the directions according to the exponents
//     c_oti_expandDirA(dirA, expA, order, expandedArray);

//     // for part in partition.Partition( expandArray(dirA,expA) )
//     for(i=0;i<nevals; i++ ){ 

//         mult = 1.0;
//         nsets = 0;

//         for (j=0;j<order;j++){ // Subpart j


//             seti = c_helper_getSet(order,i,j,p_dH); // get the j'th set of the partition i.

//             if (seti == 0){ //if partition is == 0 set is full of zeros, therefore avoid computation.
//                 continue;
//             }

//             nsets++; //counts the number of sets in the partition.

//             el = 0;      // gets the element  at which 
//             count = 0;

//             while (seti != 0){    // values of the sets are stored in the bits of seti

//                 if( seti & 1){

//                     mdir[count] = expandedArray[el];
//                     count+=1;

//                 }
                

//                 seti = (seti>>1);
//                 el++;

//             }

//             // fill up the other values as zeros:

//             for (k=count;k<orderg;k++){

//                 mdir[k] = 0;

//             }

//             c_oti_collapseDirA(mdir, orderg, dirA_, expA_);

//             index = c_helper_findIndex(dirA_,expA_,orderg,p_dH);
//             factor = 1.;

//             for( k =0; k<orderg; k++){
          
//                 if( expA_[k] != 0){ // Not a necessary check
                
//                     factor *= c_fastfact(expA_[k]);

//                 }

//             }

//             mult *= g->p_coefs[index]*factor;

//         }

//         sum_ +=  fder[nsets]  *  mult;

//     }
    
//     factor = 1.0;

//     for( k =0; k<orderg; k++){
          
//         if( expA[k] != 0){ // not a necessary check
        
//             factor *= c_fastfact(expA[k]);

//         }

//     }

//     // printf("sum -> %g\n",sum_);
//     // printf("factor -> %g\n",factor);

//     return sum_/factor;

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void c_oti_derivFunc(double* fder, otinum_t* g, directionHelper* p_dH, otinum_t* feval){
//     /*
//     void c_oti_derivFunc(double* fder, otinum_t* g, otinum_t* feval)
    
//     Given the derivatives of a function f(g) with respect to g, finds the evaluation of the function 
//     when g is an oti number.

//     To differentiate a function f that depends on another function
//     g which depends on several variables. 

//     i.e. f( g(x1,...,xn) )

//     g comes evaluated and it is represented by an OTI number.

//     INPUTS:
        
//         ->  fder:   Array of values holding all the derivatives of f with respect to g up to 
//                     g.order. 
        
//         ->  g:      oti number that represents g(x1,...,xn).

//         ->  feval:  Evaluated function f(g) where g is an oti number.

  
//     WARNING:    This is a very rudimentary implementation. If you have time to
//                 contribute, this is a function that might be very crucial to 
//                 optimize.

//     */
//     uint8_t order = g->order;
//     uint64_t Ndir = g->Ndir;
//     uint8_t i = 0;
//     // uint16_t nval = c_helper_findMaxDir(Ndir-1,order,p_dH);
//     // uint64_t max_i = c_helper_getNels(nval, order, p_dH); 

//     // Allocate memory for the result:
//     feval->p_coefs = (double* )malloc(Ndir*sizeof(double)) ;
//     if( feval->p_coefs == NULL ){
//         printf("---- MemoryError ----\n");
//         exit(-1);
//     }
//     feval->order = order;
//     feval->Ndir = Ndir;

//     // Assign real component:
//     feval->p_coefs[0] = fder[0];

//     for (i=1; i<Ndir; i++){
//         if (order == 1){
//             feval->p_coefs[i] = fder[1]*g->p_coefs[i];
//         } else {
//             feval->p_coefs[i] = c_oti_FaaDiBruno(i,fder,g,p_dH);
//         }
//     }




// }
// // ----------------------------------------------------------------------------------------------------

// // typedef struct{
// //     uint64_t*     p_data;
// //     uint64_t*     p_cols;
// //     uint64_t*     p_rows;
// //     uint64_t       sizex;
// //     uint64_t       nrows;
// //     uint64_t     nonzero;
// // } coomat_ui64_t;


// // ****************************************************************************************************
// coomat_ui64_t c_oti_matform( uint64_t nvar, uint8_t order, directionHelper* p_dH){
//     /*
//     uint64_t* c_oti_matform(otinum_t* num, uint64_t size, directionHelper* p_dH)

//     Obtain the dense matrix representation of the oti number num.

//     INPUTS:

//         -> nvar:   Number of independent variables.

//         -> order:  Order of derivatives.

//         -> p_dH:   List of helpers.

//     OUTPUTS:

//         The operation gives a uint64_t* such that it contains the matrix form of the oti number.

//         Each non zero element in the matrix is the index of the OTI number coefficient that should
//         be placed in that position.

//         The shape of the matrix is (size x size)

//     */ 
//     // ************************************************************************************************
//     uint64_t i,j,k,ii,Ndir;
//     coomat_ui64_t mat;     // matrix pointer, Coo format
//     uint8_t error;
//     uint64_t nnonzero = c_ndir(2*nvar, order);

    
//     // Allocate memory to hold the results:
//     mat.p_data = (uint64_t*)malloc(nnonzero*sizeof(uint64_t));
//     if (mat.p_data == NULL){
//         printf("--- MemoryError ---\n");
//         exit(1);
//     }

//     mat.p_cols = (uint64_t*)malloc(nnonzero*sizeof(uint64_t));
//     if (mat.p_cols == NULL){
//         printf("--- MemoryError ---\n");
//         exit(1);
//     }

//     mat.p_rows = (uint64_t*)malloc(nnonzero*sizeof(uint64_t));
//     if (mat.p_rows == NULL){
//         printf("--- MemoryError ---\n");
//         exit(1);
//     }

    
//     // Initialize in zero.
//     memset(mat.p_data, 0, nnonzero*sizeof(uint64_t));

//     Ndir = c_ndir(nvar, order);
        
//     mat.sizex   = Ndir;
//     mat.sizey   = Ndir;
//     mat.nonzero = nnonzero;


//     // Holder of the position of the coefficient vectors
//     ii=0;
//     for( i = 0; i < Ndir; i++){

//         for( j = 0; j < Ndir; j++){
            
//             k = c_helper_multIndxFast( i, j, order, p_dH, &error);
            
//             if (k>Ndir){

//                 break;

//             }

//             if (error == 0){
//                 // k*size+j
//                 mat.p_data[ii] = i+1;  // +1 because a 0 can be accounted for errors in sparse matrix
//                 mat.p_rows[ii] = k;
//                 mat.p_cols[ii] = j;
//                 ii++;
                
//             }

//         }

//     }
    
//     return mat;

// }    
// // ----------------------------------------------------------------------------------------------------



// // ****************************************************************************************************
// double* c_oti_num2mat(otinum_t* num, uint64_t size, directionHelper* p_dH){
//     /*
//     void c_oti_num2mat(otinum_t* num, uint64_t size, directionHelper* p_dH)

//     Obtain the dense matrix representation of the oti number num.

//     INPUTS:

//         ->num:    Address of the number to be created. 

//         ->size:    Size of the matrix (can be different to the num.Ndir).

//         -> p_dH:   List of helpers

//     OUTPUTS:

//         The operation gives a double* such that it contains the matrix form of the oti number.

//         The shape of the matrix is (size x size)

//     */ 
//     // ************************************************************************************************
//     uint64_t i,j,k,Ndir = num->Ndir;
//     double * mat;   // matrix pointer
//     uint8_t error,order = num->order;

    
//     // Allocate memory to hold the results:
//     mat = (double*)malloc(size*size*sizeof(double));
//     if (mat == NULL){
//         printf("--- MemoryError ---\n");
//         exit(1);
//     }
    
//     // Initialize in zero.
//     memset(mat, 0, size*size*sizeof(double));
    

//     for( i = 0; i < Ndir; i++){

//         for( j = 0; j < size; j++){
            
//             k = c_helper_multIndxFast( i, j, order, p_dH, &error);

            
//             if (k>size){
                
//                 break;

//             }

//             if (error == 0){

//                 mat[k*size+j] = num->p_coefs[i];
                
//             }

//         }

//     }
    
//     return mat;

// }    
// // ----------------------------------------------------------------------------------------------------




// // ****************************************************************************************************
// void c_oti_mulf(otinum_t* num1, double num2, otinum_t* res){
//     /*
//     void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

//     multiply an oti number times a real coefficient.

//     INPUTS:

//         ->num1:    Address of one operand. 
//                                                 Both must have the same order.
//         ->num2:    Address of the other operand.

//         ->res:     Address of the result holder. Must come allocated with the maximum number of 
//                    directions. Cannot be the same address as num1.

//         -> p_dH:   List of helpers

//     OUTPUTS:

//         The operation is equivalent to:

//         - res = num1 * num2

//     */ 
//     // ************************************************************************************************
//     uint64_t i;
    
//     // Initialize the result holder.
//     if (res->p_coefs!=num1->p_coefs){
        
//         memcpy(res->p_coefs,num1->p_coefs,res->Ndir*sizeof(double));
            
//     }
    

//     for( i = 0; i < res->Ndir; i++){
        
//         res->p_coefs[i]*=num2;
//     }
    

// }    
// // ----------------------------------------------------------------------------------------------------


// // ****************************************************************************************************
// void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH){
//     /*
//     void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

//     multiply two oti numbers

//     INPUTS:

//         ->num1:    Address of one operand. 
//                                                 Both must have the same order.
//         ->num2:    Address of the other operand.

//         ->res:     Address of the result holder. Must come allocated with the maximum number of 
//                    directions. Cannot be the same address as num1 or num2

//         -> p_dH:   List of helpers

//     OUTPUTS:

//         The operation is equivalent to:

//         - res = num1 * num2

//     */ 
//     // ************************************************************************************************
//     uint64_t i, j, indx;
//     uint8_t err=1, order = num1->order;
    
//     // Initialize in zeros the result holder.
//     for( i = 0; i < res->Ndir;  i++ ){

//         res->p_coefs[i] = 0.0;

//     }

//     for( i = 0; i < num1->Ndir; i++){
        
//         for( j = 0; j < num2->Ndir; j++){

//             // Multiply directions.

//             indx = c_helper_multIndxFast(i,j,order,p_dH,&err);

//             if (err == 0){   // If error flag is off

//                 res->p_coefs[indx] += num1->p_coefs[i] * num2->p_coefs[j];
//             }

//         }
                 
//     }
    

// }    
// // ----------------------------------------------------------------------------------------------------


// // ****************************************************************************************************
// inline void c_oti_free(otinum_t* numHolder){
//     /*
//     c_freeOti(numHolder)

//     Frees an allocated oti number

//     INPUTS:

//         ->numHolder:    Address of the number to be freed.
        

//     */ 
//     // ************************************************************************************************

//     if (numHolder->p_coefs != NULL){

//         free(numHolder->p_coefs); 

//     }
// }
// // ----------------------------------------------------------------------------------------------------



// // ****************************************************************************************************
// void c_oti_changeOrderToNew(otinum_t* num, uint8_t neword, directionHelper* p_dH , otinum_t* res){
//     /*
//     c_otiChangeOrder(num1, neword, p_dH)
    
//     Change the order of num to neword without changing the original number.
    

//     INPUTS:

//         ->num:      Address of the number to be changedOrder. 
                                                
//         ->neword:   New Order.

//         ->p_dH:     Address of the helper stack. 
    
//     OUTPUTS:

//         The operation will replace the data in num.

//     */ 
//     // ************************************************************************************************

//     uint16_t* oldDirA;
//     uint16_t* newDirA;
//     uint8_t*  oldExpA;
//     uint8_t*  newExpA;
//     uint64_t newIndx;
//     uint64_t m_max, newSizeOfCoefs;
//     uint64_t i,k, Ndir = num->Ndir;
//     uint8_t j, order = num->order;
//     double*  newCoefs;


//     if (neword != order){

//         m_max = c_helper_findMaxDir(Ndir-1,order,p_dH);
//         newSizeOfCoefs = c_helper_getNels(m_max,neword,p_dH);
//         newCoefs = (double*)malloc(newSizeOfCoefs*sizeof(double));

//         if (neword>order){

            
//             // WARNING: THE VALUES IN COEFS HAVE NOT BEEN INITIALIZED!!!
//             k=0;


//             newDirA = c_helper_getUDirA(neword,0,p_dH);
//             newExpA = c_helper_getUExpA(neword,0,p_dH);

//             for (i = 0; i < Ndir; i++ ){

//                 oldDirA = c_helper_getDirA(i,order,p_dH);
//                 oldExpA = c_helper_getExpA(i,order,p_dH);
                
                 

//                 // Fill the values of new DirA
//                 memcpy(newDirA,oldDirA,order*sizeof(double));            
//                 memcpy(newExpA,oldExpA,order*sizeof(double));

//                 // Fill the rest with zeros
//                 for (j=order; j<neword;j++){
                    
//                     newDirA[j] = 0;
//                     newExpA[j] = 0;

//                 }

//                 newIndx = c_helper_findIndex(newDirA,newExpA,neword,p_dH);
//                 newCoefs[newIndx] = num->p_coefs[i];

                
//                 if (k != newIndx){
//                     // Set all the values between the last value placed and newIndx -> 0.0

//                     for (;k<newIndx;k++){

//                         newCoefs[k] = 0.0;

//                     }

//                     // k leaves this loop with the same value as newIndx.
                    

//                 }

//                 k++;


                
//             }

//             // Set all other numbers to zero.

//             for (;k<newSizeOfCoefs;k++){
//                 newCoefs[k] = 0.0;
//             }


            
//             res->p_coefs = newCoefs;
//             res->order = neword;
//             res->Ndir = newSizeOfCoefs;

//         } else {  // neworder<order

//             oldDirA = c_helper_getUDirA( order, 0, p_dH);
//             oldExpA = c_helper_getUExpA( order, 0, p_dH); 

//             for (i = 0; i < newSizeOfCoefs; i++ ){

//                 newDirA = c_helper_getDirA(i, neword, p_dH);
//                 newExpA = c_helper_getExpA(i, neword, p_dH);

//                 memcpy( oldDirA, newDirA, neword*sizeof(double));            
//                 memcpy( oldExpA, newExpA, neword*sizeof(double));

//                 // Fill the rest with zeros
//                 for (j=neword; j<order;j++){
                    
//                     oldDirA[j] = 0;
//                     oldExpA[j] = 0;

//                 }

//                 newIndx = c_helper_findIndex(oldDirA,oldExpA,order,p_dH);
//                 newCoefs[i] = num->p_coefs[newIndx];
                
                
//             }


//             num->p_coefs = newCoefs;
//             num->order = neword;
//             num->Ndir = newSizeOfCoefs;

//         }

//     }


// }


// void c_oti_changeOrder(otinum_t* num, uint8_t neword, directionHelper* p_dH ){
//     /*
//     c_otiChangeOrder(num1, neword, p_dH)
    
//     Change the order of num to neword.
    

//     INPUTS:

//         ->num:      Address of the number to be changedOrder. 
                                                
//         ->neword:   New Order.

//         ->p_dH:     Address of the helper stack. 
    
//     OUTPUTS:

//         The operation will replace the data in num.

//     */ 
//     // ************************************************************************************************

//     uint16_t* oldDirA;
//     uint16_t* newDirA;
//     uint8_t*  oldExpA;
//     uint8_t*  newExpA;
//     uint64_t newIndx;
//     uint64_t m_max, newSizeOfCoefs;
//     uint64_t i,k, Ndir = num->Ndir;
//     uint8_t j, order = num->order;
//     double*  newCoefs;


//     if (neword != order){

//         m_max = c_helper_findMaxDir(Ndir-1,order,p_dH);
//         newSizeOfCoefs = c_helper_getNels(m_max,neword,p_dH);


//         if (neword>order){

//             newCoefs = (double*)malloc(newSizeOfCoefs*sizeof(double));
//             // WARNING: THE VALUES IN COEFS HAVE NOT BEEN INITIALIZED!!!
//             k=0;


//             newDirA = c_helper_getUDirA(neword,0,p_dH);
//             newExpA = c_helper_getUExpA(neword,0,p_dH);

//             for (i = 0; i < Ndir; i++ ){

//                 oldDirA = c_helper_getDirA(i,order,p_dH);
//                 oldExpA = c_helper_getExpA(i,order,p_dH);
                
                 

//                 // Fill the values of new DirA
//                 memcpy(newDirA,oldDirA,order*sizeof(double));            
//                 memcpy(newExpA,oldExpA,order*sizeof(double));

//                 // Fill the rest with zeros
//                 for (j=order; j<neword;j++){
                    
//                     newDirA[j] = 0;
//                     newExpA[j] = 0;

//                 }

//                 newIndx = c_helper_findIndex(newDirA,newExpA,neword,p_dH);
//                 newCoefs[newIndx] = num->p_coefs[i];

                
//                 if (k != newIndx){
//                     // Set all the values between the last value placed and newIndx -> 0.0

//                     for (;k<newIndx;k++){

//                         newCoefs[k] = 0.0;

//                     }

//                     // k leaves this loop with the same value as newIndx.
                    

//                 }

//                 k++;


                
//             }

//             // Set all other numbers to zero.

//             for (;k<newSizeOfCoefs;k++){
//                 newCoefs[k] = 0.0;
//             }


//             free(num->p_coefs);
//             num->p_coefs = newCoefs;
//             num->order = neword;
//             num->Ndir = newSizeOfCoefs;

//         } else {  // neworder<order

//             oldDirA = c_helper_getUDirA( order, 0, p_dH);
//             oldExpA = c_helper_getUExpA( order, 0, p_dH); 

//             for (i = 0; i < newSizeOfCoefs; i++ ){

//                 newDirA = c_helper_getDirA(i, neword, p_dH);
//                 newExpA = c_helper_getExpA(i, neword, p_dH);

//                 memcpy( oldDirA, newDirA, neword*sizeof(double));            
//                 memcpy( oldExpA, newExpA, neword*sizeof(double));

//                 // Fill the rest with zeros
//                 for (j=neword; j<order;j++){
                    
//                     oldDirA[j] = 0;
//                     oldExpA[j] = 0;

//                 }

//                 newIndx = c_helper_findIndex(oldDirA,oldExpA,order,p_dH);
//                 num->p_coefs[i] = num->p_coefs[newIndx];
                
                
//             }

//             // Realloc to new size.
//             num->p_coefs = (double* )realloc(num->p_coefs,newSizeOfCoefs*sizeof(double));
//             num->order = neword;
//             num->Ndir = newSizeOfCoefs;

//         }

//     }


// }



// // ****************************************************************************************************
// void c_oti_e(double real,uint16_t basis, uint8_t order, uint16_t nbasis, 
//             directionHelper* p_dH, otinum_t* res){
//     /*
//     void c_oti_e(double real,uint16_t basis, uint8_t order, otinum_t* res)

//     Create an oti number with real coefficient "real" and with unitary perturbation in imaginary 
//     direction "basis".

//     INPUTS:

//         -> double real:     Real coefficient.

//         -> uint16_t basis:  Number that represents the imaginary direction to hold the perturbation.

//         -> uint8_t order:   Order of the OTI number desired

//         -> uint16_t nbasis: Number of basis(determines the size of the oti number).
        
//         -> directionHelper* p_dH: 

//         -> otinum_t* res:   Pointer to the oti number result. Must not come allocated!
    
//     OUTPUTS:

//         The operation allocates memory and sets the corresponding values of the oti number.

//     */ 
//     // ************************************************************************************************
    


    

// }    
// // ----------------------------------------------------------------------------------------------------




// // ****************************************************************************************************
// inline void c_oti_sumf(otinum_t* num1, double other){
//     /*
//     void c_oti_sumf(otinum_t* num1, otinum_t* num2, otinum_t* res)

//     Sum an oti number with a float (double).

//     INPUTS:

//         ->num1:    Address of the summand. 
//                                                 Both must have the same order.
//         ->num2:    Address of the summand.

//         ->res:     Address of the result holder. Must come allocated with the maximum number of 
//                    directions.

//     OUTPUTS:

//         The operation is equivalent to:

//         res = num1 + num2

//     */ 
//     // ************************************************************************************************
    

//     num1->p_coefs[0] += other;

// }    
// // ----------------------------------------------------------------------------------------------------



// // ****************************************************************************************************
// void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res){
//     /*
//     void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res)

//     Sum two oti numbers

//     INPUTS:

//         ->num1:    Address of the summand. 
//                                                 Both must have the same order.
//         ->num2:    Address of the summand.

//         ->res:     Address of the result holder. Must come allocated with the maximum number of 
//                    directions.

//     OUTPUTS:

//         The operation is equivalent to:

//         res = num1 + num2

//     */ 
//     // ************************************************************************************************


//     // c_minUI64(num1->Ndir, num2->Ndir, &minNdir,&maxNdir);


//     for(uint64_t i = 0; i< res->Ndir; i++){
        
//         if( i < num1->Ndir){
            
//             res->p_coefs[i] = num1->p_coefs[i];

//         }else{
            
//             res->p_coefs[i] = 0.0;

//         }

//         if( i < num2->Ndir){
            
//             res->p_coefs[i] += num2->p_coefs[i];

//         }

//     }
    

// }    
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void c_oti_sub(otinum_t* num1, otinum_t* num2, otinum_t* res){
//     /*
//     void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res)

//     Subtract two oti numbers

//     INPUTS:

//         ->num1:    Address of the summand. 
//                                                 Both must have the same order.
//         ->num2:    Address of the summand.

//         ->res:     Address of the result holder. Must come allocated with the maximum number of 
//                    directions.

//     OUTPUTS:

//         The operation is equivalent to:

//         res = num1 - num2

//     */ 
//     // ************************************************************************************************


//     // c_minUI64(num1->Ndir, num2->Ndir, &minNdir,&maxNdir);


//     for(uint64_t i = 0; i< res->Ndir; i++){
        
//         if( i < num1->Ndir){
            
//             res->p_coefs[i] = num1->p_coefs[i];

//         }else{
            
//             res->p_coefs[i] = 0.0;

//         }

//         if( i < num2->Ndir){
            
//             res->p_coefs[i] -= num2->p_coefs[i];

//         }

//     }
    

// }    
// // ----------------------------------------------------------------------------------------------------


// // ****************************************************************************************************
// void c_oti_neg(otinum_t* num1){
//     /*
//     void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res)

//     Sum two oti numbers

//     INPUTS:

//         ->num1:    Address of the summand. 
//                                                 Both must have the same order.
//         ->num2:    Address of the summand.

//         ->res:     Address of the result holder. Must come allocated with the maximum number of 
//                    directions.

//     OUTPUTS:

//         The operation is equivalent to:

//         - num1 

//     */ 
//     // ************************************************************************************************


//     for(uint64_t i = 0; i< num1->Ndir; i++){
        
//         num1->p_coefs[i] *= -1.0;
                 
//     }
    

// }    
// // ----------------------------------------------------------------------------------------------------





// // ****************************************************************************************************
// inline void c_oti_copy(otinum_t* numDest, otinum_t* numSrc){
//     /*
//     void c_oti_copy(otinum_t* numDest, otinum_t* numSrc)

//     Copies the information from numSrc to numDest

//     INPUTS:

//         ->numHolder:    Address of the number to be freed.

//     */ 
//     // ************************************************************************************************

//     numDest->p_coefs = (double*)malloc(numSrc->Ndir*sizeof(double));
    
//     if (numDest->p_coefs == NULL){
//         printf("--- MemoryError ---\n");
//         exit(1);
//     }

//     memcpy(numDest->p_coefs ,numSrc->p_coefs ,numSrc->Ndir*sizeof(double));
//     numDest->Ndir  = numSrc->Ndir;
//     numDest->order = numSrc->order;
// }    
// // ----------------------------------------------------------------------------------------------------




