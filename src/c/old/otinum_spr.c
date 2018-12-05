#include "oti/otinum_spr.h"

// ----------------------------------------------------------------------------------------------------
// -------------------------------     SPROTINUM FUNCTIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_printf(sotinum_t* num){
    /*
    c_soti_printf(sotinum_t* num)

    Function that prints an sparse oti in c..

    INPUTS:

        ->   p_arr1:    Array

        ->   elem:      Element with the information of the solution.
        
        -> p_arrRes:    Result of operation.

        ->     p_dH:    Direction helper

    */ 
    // ************************************************************************************************

    printf("soti(o: %hhu, sz: %llu, ",num->order,num->size);
    // printf("coefs at %p \n",num->p_coefs);
    c_printArrayDBL(num->p_coefs,num->size);
    printf(", ");
    // printf("indx at %p \n",num->p_indx);
    c_printArrayUI64(num->p_indx,num->size);
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_fdiv(double numx, sotinum_t* numy, sotinum_t* res, directionHelper* p_dH){
    /*
    PURPOSE:  Inverse Tangent function counting all quadrants for OTI numbers.

    */
    //*************************************************************************************************

    sotinum_t tmp;

    c_soti_pow(numy,-1.0, p_dH, &tmp); // 1 / y

    c_soti_mulf(&tmp,numx,res); 
    
    c_soti_free(&tmp);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_divf(sotinum_t* numx, double numy, sotinum_t* res){
    /*
    PURPOSE:  Inverse Tangent function counting all quadrants for OTI numbers.

    */
    //*************************************************************************************************

    c_soti_mulf(numx,(1.0/numy),res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_div(sotinum_t* numx, sotinum_t* numy, sotinum_t* res, directionHelper* p_dH){
    /*
    PURPOSE:  Inverse Tangent function counting all quadrants for OTI numbers.

    */
    //*************************************************************************************************
    
    sotinum_t tmp;

    c_soti_pow(numy,-1.0,p_dH, &tmp); // 1 / y

    c_soti_mul(numx,&tmp,res,p_dH); 
    
    c_soti_free(&tmp);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_atan2(sotinum_t* numx, sotinum_t* numy, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Tangent function counting all quadrants for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[numx->order-1].p_fder; // holder for the derivatives in the helper.
    double x0    ;
    uint8_t i;
    sotinum_t tmp;


    // first perform the division of the numbers

    // 1/y
    c_soti_pow(numy,-1.0,p_dH, res);

    
    //x*(1/y) 
    c_soti_mul(numx, res, &tmp, p_dH);
    c_soti_free(res);

    x0 = c_soti_getReal(&tmp);

    for( i=0; i<(numx->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0] =  atan2(c_soti_getReal(numx),c_soti_getReal(numy));

            case 1:
                derivs[1] =  1.0/(pow(x0, 2) + 1);

            case 2:
                derivs[2] =  -2*x0/pow(pow(x0, 2) + 1, 2);
                // -2*x1/(x1**2 + 1)**2
            case 3:
                derivs[3] =  2*(4*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 2);
                // 2*(4*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**2
            case 4:
                derivs[4] =  24*x0*(-2*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 3);
                // 24*x1*(-2*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3
            case 5:
                derivs[5] =  24*(16*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 12*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 3);
                // 24*(16*x1**4/(x1**2 + 1)**2 - 12*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3 
            case 6:
                derivs[6] = 240*x0*(-16*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 16*pow(x0, 2)/(pow(x0, 2) + 1) - 3)/pow(pow(x0, 2) + 1, 4);
                // 240*x1*(-16*x1**4/(x1**2 + 1)**2 + 16*x1**2/(x1**2 + 1) - 3)/(x1**2 + 1)**4
            case 7:
                derivs[7] = 720*(64*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 80*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 24*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 4);
                // 720*(64*x1**6/(x1**2 + 1)**3 - 80*x1**4/(x1**2 + 1)**2 + 24*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**4
            case 8:
                derivs[8] = 40320*x0*(-16*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 24*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 10*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 5);
                // 40320*x1*(-16*x1**6/(x1**2 + 1)**3 + 24*x1**4/(x1**2 + 1)**2 - 10*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 9:
                derivs[9] = 40320*(256*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) - 448*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 240*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 40*pow(x0, 2)/(pow(x0, 2) + 1) + 1)/pow(pow(x0, 2) + 1, 5);
                // 40320*(256*x1**8/(x1**2 + 1)**4 - 448*x1**6/(x1**2 + 1)**3 + 240*x1**4/(x1**2 + 1)**2 - 40*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 10:
                derivs[10] =725760*x0*(-256*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) + 512*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 336*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 80*pow(x0, 2)/(pow(x0, 2) + 1) - 5)/pow(pow(x0, 2) + 1, 6);
                // 725760*x1*(-256*x1**8/(x1**2 + 1)**4 + 512*x1**6/(x1**2 + 1)**3 - 336*x1**4/(x1**2 + 1)**2 + 80*x1**2/(x1**2 + 1) - 5)/(x1**2 + 1)**6
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, &tmp, p_dH, res);
    c_soti_free(&tmp);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_logb(sotinum_t* num, int base, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  logarithm of base b function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  log(x0)/log(base);

            case 1:
                derivs[1]  =  1/(x0*log(base));

            case 2:
                derivs[2]  =  -1/(pow(x0, 2)*log(base));
                
            case 3:
                derivs[3]  =  2/(pow(x0, 3)*log(base));
                
            case 4:
                derivs[4]  =  -6/(pow(x0, 4)*log(base));
                
            case 5:
                derivs[5]  =  24/(pow(x0, 5)*log(base));
                
            case 6:
                derivs[6]  =  -120/(pow(x0, 6)*log(base));
                            
            case 7:
                derivs[7]  =  720/(pow(x0, 7)*log(base));
                
            case 8:
                derivs[8]  =  -5040/(pow(x0, 8)*log(base));
                
            case 9:
                derivs[9]  =  40320/(pow(x0, 9)*log(base));
                
            case 10:
                derivs[10] =  -362880/(pow(x0, 10)*log(base));
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_log10(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  logarithm of base 10 function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  log(x0)/log(10);

            case 1:
                derivs[1]  =  1/(x0*log(10));

            case 2:
                derivs[2]  =  -1/(pow(x0, 2)*log(10));
                
            case 3:
                derivs[3]  =  2/(pow(x0, 3)*log(10));
                
            case 4:
                derivs[4]  =  -6/(pow(x0, 4)*log(10));
                
            case 5:
                derivs[5]  =  24/(pow(x0, 5)*log(10));
                
            case 6:
                derivs[6]  =  -120/(pow(x0, 6)*log(10));
                            
            case 7:
                derivs[7]  =  720/(pow(x0, 7)*log(10));
                
            case 8:
                derivs[8]  =  -5040/(pow(x0, 8)*log(10));
                
            case 9:
                derivs[9]  =  40320/(pow(x0, 9)*log(10));
                
            case 10:
                derivs[10] =  -362880/(pow(x0, 10)*log(10));
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_atanh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Hyperbolic tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  atanh(x0);

            case 1:
                derivs[1]  =  1.0/(-pow(x0, 2) + 1);

            case 2:
                derivs[2]  =  2*x0/pow(pow(x0, 2) - 1, 2);
                
            case 3:
                derivs[3]  =  2*(-4*pow(x0, 2)/(pow(x0, 2) - 1) + 1)/pow(pow(x0, 2) - 1, 2);
                
            case 4:
                derivs[4]  =  24*x0*(2*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 3);
                
            case 5:
                derivs[5]  =  24*(-16*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) + 12*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 3);
                
            case 6:
                derivs[6]  =  240*x0*(16*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) - 16*pow(x0, 2)/(pow(x0, 2) - 1) + 3)/pow(pow(x0, 2) - 1, 4);
                            
            case 7:
                derivs[7]  =  720*(-64*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) + 80*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) - 24*pow(x0, 2)/(pow(x0, 2) - 1) + 1)/pow(pow(x0, 2) - 1, 4);
                
            case 8:
                derivs[8]  =  40320*x0*(16*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) - 24*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) + 10*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 5);
                
            case 9:
                derivs[9]  =  40320*(-256*pow(x0, 8)/pow(pow(x0, 2) - 1, 4) + 448*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) - 240*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) + 40*pow(x0, 2)/(pow(x0, 2) - 1) - 1)/pow(pow(x0, 2) - 1, 5);
                
            case 10:
                derivs[10] =  725760*x0*(256*pow(x0, 8)/pow(pow(x0, 2) - 1, 4) - 512*pow(x0, 6)/pow(pow(x0, 2) - 1, 3) + 336*pow(x0, 4)/pow(pow(x0, 2) - 1, 2) - 80*pow(x0, 2)/(pow(x0, 2) - 1) + 5)/pow(pow(x0, 2) - 1, 6);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_asinh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Hyperbolic sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  acosh(x0);

            case 1:
                derivs[1]  =  pow(pow(x0, 2) + 1, -1.0L/2.0L);

            case 2:
                derivs[2]  =  -x0/pow(pow(x0, 2) + 1, 3.0L/2.0L);
                
            case 3:
                derivs[3]  =  (3*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 3.0L/2.0L);
                //            (3*pow(x0, 2)/(pow(x0, 2) + 1) - 1)/pow(pow(x0, 2) + 1, 3.0L/2.0L)
                
            case 4:
                derivs[4]  =  3*x0*(-5*pow(x0, 2)/(pow(x0, 2) + 1) + 3)/pow(pow(x0, 2) + 1, 5.0L/2.0L);
                //             3*x0*(-5*pow(x0, 2)/(pow(x0, 2) + 1) + 3)/pow(pow(x0, 2) + 1, 5.0L/2.0L)
                
            case 5:
                derivs[5]  =  3*(35*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 30*pow(x0, 2)/(pow(x0, 2) + 1) + 3)/pow(pow(x0, 2) + 1, 5.0L/2.0L);
                
            case 6:
                derivs[6]  =  15*x0*(-63*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 70*pow(x0, 2)/(pow(x0, 2) + 1) - 15)/pow(pow(x0, 2) + 1, 7.0L/2.0L);
                            
            case 7:
                derivs[7]  =  45*(231*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 315*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 105*pow(x0, 2)/(pow(x0, 2) + 1) - 5)/pow(pow(x0, 2) + 1, 7.0L/2.0L);
                
            case 8:
                derivs[8]  =  315*x0*(-429*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 693*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 315*pow(x0, 2)/(pow(x0, 2) + 1) + 35)/pow(pow(x0, 2) + 1, 9.0L/2.0L);
                
            case 9:
                derivs[9]  =  315*(6435*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) - 12012*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) + 6930*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) - 1260*pow(x0, 2)/(pow(x0, 2) + 1) + 35)/pow(pow(x0, 2) + 1, 9.0L/2.0L);
                
            case 10:
                derivs[10] =  2835*x0*(-12155*pow(x0, 8)/pow(pow(x0, 2) + 1, 4) + 25740*pow(x0, 6)/pow(pow(x0, 2) + 1, 3) - 18018*pow(x0, 4)/pow(pow(x0, 2) + 1, 2) + 4620*pow(x0, 2)/(pow(x0, 2) + 1) - 315)/pow(pow(x0, 2) + 1, 11.0L/2.0L);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_acosh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Hyperbolic inverse cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double x2m1 = pow(x0, 2.) - 1.;
    double sqx2m1 = pow(x2m1, 0.5);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  acosh(x0);

            case 1:
                derivs[1]  =  pow(sqx2m1, -1.0);

            case 2:
                derivs[2]  =  -x0/pow(sqx2m1, 3.0);
                
            case 3:
                derivs[3]  =  (3.*pow(x0, 2.)/(x2m1) - 1.)/pow(sqx2m1, 3.0);
                
            case 4:
                derivs[4]  =  3.*x0*(-5.*pow(x0, .2)/(x2m1) + 3.)/pow(sqx2m1, 5.0);
                
            case 5:
                derivs[5]  =  3.*(35.*pow(x0, 4.)/pow(x2m1, 2.) - 30*pow(x0, 2.)/(x2m1) + 3.)/pow(sqx2m1, 5.0);
                
            case 6:
                derivs[6]  =  15.*x0*(-63.*pow(x0, 4.)/pow(x2m1, 2.) + 70.*pow(x0, 2.)/(x2m1) - 15.)/pow(sqx2m1, 7.0);
                            
            case 7:
                derivs[7]  =  45.*(231.*pow(x0, 6.)/pow(x2m1, 3.) - 315.*pow(x0, 4.)/pow(x2m1, 2.) + 105.*pow(x0, 2.)/(x2m1) - 5.)/pow(sqx2m1, 7.0);
                
            case 8:
                derivs[8]  =  315.*x0*(-429.*pow(x0, 6.)/pow(x2m1, 3.) + 693.*pow(x0, 4.)/pow(x2m1, 2.) - 315.*pow(x0, 2.)/(x2m1) + 35.)/pow(sqx2m1, 9.0);
                
            case 9:
                derivs[9]  =  315.*(6435.*pow(x0, 8.)/pow(x2m1, 4.) - 12012.*pow(x0, 6.)/pow(x2m1, 3.) + 6930.*pow(x0, 4.)/pow(x2m1, 2.) - 1260.*pow(x0, 2.)/(x2m1) + 35.)/pow(sqx2m1, 9.0);
                
            case 10:
                derivs[10] =  2835.*x0*(-12155.*pow(x0, 8.)/pow(x2m1, 4.) + 25740.*pow(x0, 6.)/pow(x2m1, 3.) - 18018.*pow(x0, 4.)/pow(x2m1, 2.) + 4620.*pow(x0, 2.)/(x2m1) - 315.)/pow(sqx2m1, 11.0);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_tanh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Hyperbolic tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double tanhx0 = tanh(x0);
    double tanh2  = pow(tanhx0, 2); 
    double tanh2m1 = tanh2 - 1;
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  tanhx0;

            case 1:
                derivs[1]  =  -tanh2m1;

            case 2:
                derivs[2]  =  2.*(tanh2m1)*tanhx0;
                
            case 3:
                derivs[3]  =  -2.*(tanh2m1)*(3.*tanh2 - 1.);
                
            case 4:
                derivs[4]  =  8.*(tanh2m1)*(3.*tanh2 - 2.)*tanhx0;
                
            case 5:
                derivs[5]  =  -8.*(tanh2m1)*(2.*pow(tanh2m1, 2.) + 11.*(tanh2m1)*tanh2 + 2.*pow(tanhx0, 4.));
                
            case 6:
                derivs[6]  =  16.*(tanh2m1)*(17.*pow(tanh2m1, 2.) + 26.*(tanh2m1)*tanh2 + 2.*pow(tanhx0, 4.))*tanhx0;
                            
            case 7:
                derivs[7]  =  -16.*(tanh2m1)*(17.*pow(tanh2m1, 3.) + 180.*pow(tanh2m1, 2.)*tanh2 + 114.*(tanh2m1)*pow(tanh(x0), 4.) + 4*pow(tanhx0, 6.));
                
            case 8:
                derivs[8]  =  128.*(tanh2m1)*(62.*pow(tanh2m1, 3.) + 192.*pow(tanh2m1, 2.)*tanh2 + 60.*(tanh2m1)*pow(tanh(x0), 4.) + pow(tanhx0, 6.))*tanhx0;
                
            case 9:
                derivs[9]  =  -128.*(tanh2m1)*(62.*pow(tanh2m1, 4.) + 1072.*pow(tanh2m1, 3.)*tanh2 + 1452.*pow(tanh2m1, 2.)*pow(tanhx0, 4.) + 247.*(tanh2m1)*pow(tanhx0, 6.) + 2.*pow(tanhx0, 8.));
                
            case 10:
                derivs[10] =  256.*(tanh2m1)*(1382.*pow(tanh2m1, 4.) + 7192.*pow(tanh2m1, 3.)*tanh2 + 5097.*pow(tanh2m1, 2.)*pow(tanhx0, 4.) + 502.*(tanh2m1)*pow(tanhx0, 6.) + 2.*pow(tanhx0, 8.))*tanhx0;
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_sqrt(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Square root function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    // double x0 = num->p_coefs[0];
    double sqx = sqrt(c_soti_getReal(num));
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  sqx;

            case 1:
                derivs[1]  =  (0.5)/sqx;

            case 2:
                derivs[2]  =  -0.25/pow(sqx, 3.0);
                
            case 3:
                derivs[3]  =  (0.375)/pow(sqx, 5.0);
                
            case 4:
                derivs[4]  =  -0.9375/pow(sqx, 7.0);
                
            case 5:
                derivs[5]  =  (3.28125)/pow(sqx, 9.0);
                
            case 6:
                derivs[6]  =  -14.765625/pow(sqx, 11.0);
                            
            case 7:
                derivs[7]  =  (81.2109375)/pow(sqx, 13.0);
                
            case 8:
                derivs[8]  =  -527.87109375/pow(sqx, 15.0);
                
            case 9:
                derivs[9]  =  (3959.033203125)/pow(sqx, 17.0);
                
            case 10:
                derivs[10] =  (-33651.7822265625)/pow(sqx, 19.0);
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_cosh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Hyperbolic Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double ch = cosh(x0);
    double sh = sinh(x0);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  ch;

            case 1:
                derivs[1]  =  sh;

            case 2:
                derivs[2]  =  ch;
                
            case 3:
                derivs[3]  =  sh;
                
            case 4:
                derivs[4]  =  ch;
                
            case 5:
                derivs[5]  =  sh;
                
            case 6:
                derivs[6]  =  ch;
                            
            case 7:
                derivs[7]  =  sh;
                
            case 8:
                derivs[8]  =  ch;
                
            case 9:
                derivs[9]  =  sh;
                
            case 10:
                derivs[10] =  ch;
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_sinh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Hyperbolic Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double ch = cosh(x0);
    double sh = sinh(x0);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  sh;

            case 1:
                derivs[1]  =  ch;

            case 2:
                derivs[2]  =  sh;
                
            case 3:
                derivs[3]  =  ch;
                
            case 4:
                derivs[4]  =  sh;
                
            case 5:
                derivs[5]  =  ch;
                
            case 6:
                derivs[6]  =  sh;
                            
            case 7:
                derivs[7]  =  ch;
                
            case 8:
                derivs[8]  =  sh;
                
            case 9:
                derivs[9]  =  ch;
                
            case 10:
                derivs[10] =  sh;
                
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_asin(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  asin(x0);

            case 1:
                derivs[1]  =  pow(-pow(x0, 2.) + 1., -1.0/2.0);

            case 2:
                derivs[2]  =  x0/pow(-pow(x0, 2.0) + 1., 3.0/2.0);
                
            case 3:
                derivs[3]  =  (3.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 1.)/pow(-pow(x0, 2.) + 1., 3.0/2.0);
                
            case 4:
                derivs[4]  =  3.*x0*(5.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 3.)/pow(-pow(x0, 2.) + 1., 5.0/2.0);
                
            case 5:
                derivs[5]  =  3.*(35.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 30.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 3.)/pow(-pow(x0, 2.) + 1., 5.0/2.0);
                
            case 6:
                derivs[6]  = 15.*x0*(63.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 70.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 15.)/pow(-pow(x0, 2.) + 1., 7.0/2.0);
                            
            case 7:
                derivs[7]  = 45.*(231.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 315.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 105.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 5.)/pow(-pow(x0, 2.) + 1., 7.0/2.0);
                
            case 8:
                derivs[8]  = 315.*x0*(429.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 693.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 315.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 35.)/pow(-pow(x0, 2.) + 1., 9.0/2.0);
                
            case 9:
                derivs[9]  = 315.*(6435.*pow(x0, 8.)/pow(-pow(x0, 2.) + 1., 4.) + 12012.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 6930.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 1260.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 35.)/pow(-pow(x0, 2.) + 1., 9.0/2.0);
                
            case 10:
                derivs[10] =2835.*x0*(12155.*pow(x0, 8.)/pow(-pow(x0, 2.) + 1., 4.) + 25740.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 18018.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 4620.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 315.)/pow(-pow(x0, 2.) + 1., 11.0/2.0);
                

        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_acos(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0]  =  acos(x0);

            case 1:
                derivs[1]  =  -1.0/sqrt(-pow(x0, 2.0) + 1.0);

            case 2:
                derivs[2]  =  -x0/pow(-pow(x0, 2.0) + 1.0, 3.0/2.0);
                
            case 3:
                derivs[3]  =  -(3.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 1.0)/pow(-pow(x0, 2.0) + 1.0, 3.0/2.0);
                
            case 4:
                derivs[4]  =  -3.0*x0*(5.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 3.0)/pow(-pow(x0, 2.0) + 1.0, 5.0/2.0);
                
            case 5:
                derivs[5]  =  -3.0*(35.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 30.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 3.0)/pow(-pow(x0, 2.0) + 1.0, 5.0/2.0);
                
            case 6:
                derivs[6]  = -15.0*x0*(63.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 70.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 15.0)/pow(-pow(x0, 2.0) + 1.0, 7.0/2.0);
                            
            case 7:
                derivs[7]  = -45.0*(231.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 315.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 105.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 5.0)/pow(-pow(x0, 2.0) + 1.0, 7.0/2.0);
                
            case 8:
                derivs[8]  = -315.0*x0*(429.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 693.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 315.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 35.0)/pow(-pow(x0, 2.0) + 1.0, 9.0/2.0);
                
            case 9:
                derivs[9]  = -315.0*(6435.0*pow(x0, 8.0)/pow(-pow(x0, 2.0) + 1.0, 4.0) + 12012.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 6930.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 1260.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 35.0)/pow(-pow(x0, 2.0) + 1.0, 9.0/2.0);
                
            case 10:
                derivs[10] =-2835.0*x0*(12155.0*pow(x0, 8.0)/pow(-pow(x0, 2.0) + 1.0, 4.0) + 25740.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 18018.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 4620.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 315)/pow(-pow(x0, 2.0) + 1.0, 11.0/2.0);
                

        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_soti_atan(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Inverse Tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double x02   = pow(x0,2.0);
    double x02p1 = x02+1.0;
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0] =  atan(x0);

            case 1:
                derivs[1] =  1.0/(x02p1);

            case 2:
                derivs[2] =  -2.0 * x0 / ( pow( x02p1 , 2.0 ) );
                // -2*x1/(x1**2 + 1)**2
            case 3:
                derivs[3] =  2.0*(4.0*x02/(x02p1) - 1.0)/(pow(x02p1,2.0));
                // 2*(4*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**2
            case 4:
                derivs[4] =  24.0*x0*(-2.0*x02/(x02p1) + 1.0)/( pow( x02p1, 3) );
                // 24*x1*(-2*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3
            case 5:
                derivs[5] =  24.0*(16.0*pow( x0 ,4.0 )/( pow( x02p1, 2.0 ) ) - 12.0 * x02/(x02p1) + 1.0)/( pow( x02p1, 3.0) );
                // 24*(16*x1**4/(x1**2 + 1)**2 - 12*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**3 
            case 6:
                derivs[6] = 240.0*x0*(-16.0*pow(x0,4.0)/pow(x02p1,2.0) + 16.0*x02/(x02p1) - 3.0 )/( pow(x02p1,4.0) );
                // 240*x1*(-16*x1**4/(x1**2 + 1)**2 + 16*x1**2/(x1**2 + 1) - 3)/(x1**2 + 1)**4
            case 7:
                derivs[7] = 720.0*(64.0*pow(x0,6.0)/pow(x02p1,3.0) - 80.0*pow(x0,4.0)/pow(x02p1,2.0) + 24.0*x02/(x02p1) - 1.0)/(pow(x02p1,4.0));
                // 720*(64*x1**6/(x1**2 + 1)**3 - 80*x1**4/(x1**2 + 1)**2 + 24*x1**2/(x1**2 + 1) - 1)/(x1**2 + 1)**4
            case 8:
                derivs[8] = 40320.0*x0*(-16*pow(x0,6.0)/pow(x02p1,3.0) + 24.0*pow(x0,4.0)/pow(x02p1,2.0) - 10.0*x02/(x02p1) + 1.0)/(pow(x02p1,5.0));
                // 40320*x1*(-16*x1**6/(x1**2 + 1)**3 + 24*x1**4/(x1**2 + 1)**2 - 10*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 9:
                derivs[9] = 40320.0*(256.0*pow(x0,8.0)/(pow(x02p1,4.0)) - 448.0*pow(x0,6.0)/(pow(x02p1,3.0)) + 240.0*pow(x0,4.0)/(pow(x02p1,2.0)) - 40.0*x02/x02p1 + 1.0)/(pow(x02p1,5.0));
                // 40320*(256*x1**8/(x1**2 + 1)**4 - 448*x1**6/(x1**2 + 1)**3 + 240*x1**4/(x1**2 + 1)**2 - 40*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 10:
                derivs[10] =725760.0*x0*(-256*pow(x0,8.0)/(pow(x02p1,4.0)) + 512*pow(x0,6.0)/(pow(x02p1,3.0)) - 336*pow(x0,4.0)/(pow(x02p1,2.0)) + 80*x02/x02p1 - 5.0)/(pow(x02p1,6.0));
                // 725760*x1*(-256*x1**8/(x1**2 + 1)**4 + 512*x1**6/(x1**2 + 1)**3 - 336*x1**4/(x1**2 + 1)**2 + 80*x1**2/(x1**2 + 1) - 5)/(x1**2 + 1)**6
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_tan(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = c_soti_getReal(num);
    double tanx0 = tan(x0);
    double tanx02p1 = pow(tanx0,2.0) + 1.0 ;
    uint8_t i;

    for( i=0; i<(num->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0] =  tan(x0);
            case 1:
                derivs[1] =  tanx02p1; 
                // tan(g)**2 + 1
            case 2:
                derivs[2] =  2.*(tanx02p1)*tanx0 ; 
                // 2*(tan(g)**2 + 1)*tan(g)
            case 3:
                derivs[3] =  2.*(tanx02p1)*(3.*pow(tanx0,2.0) + 1.);
                // 2*(tan(g)**2 + 1)*(3*tan(g)**2 + 1)
            case 4:
                derivs[4] =  8.*(tanx02p1)*(3.*pow(tanx0,2.0) + 2.)*tanx0;
                // 8*(tan(g)**2 + 1)*(3*tan(g)**2 + 2)*tan(g)
            case 5:
                derivs[5] =  8.*(tanx02p1)*(2.*pow((tanx02p1),2.0) + 
                    11.*(tanx02p1)*pow(tanx0,2.0) + 2.*pow(tanx0,4.0));
                //8*(tan(g)**2 + 1)*(2*(tan(g)**2 + 1)**2 + 11*(tan(g)**2 + 1)*tan(g)**2 + 2*tan(g)**4)
            case 6:
                derivs[6] = 16.*(tanx02p1)*(17*pow((tanx02p1),2.) + 
                    26.*(tanx02p1)*pow(tanx0,2.0) + 
                    2.*pow(tanx0,4.0))*tanx0;
                // 16*(tan(g)**2 + 1)*(17*(tan(g)**2 + 1)**2 + 26*(tan(g)**2 + 1)*tan(g)**2 + 2*tan(g)**4)*tan(g)
            case 7:
                derivs[7] = 16.*(tanx02p1)*(17.*pow((tanx02p1),3.) 
                    + 180.*pow((tanx02p1),2.)*pow(tanx0,2.0)
                    + 114.*(tanx02p1)*pow(tanx0,4.0) + 4.*pow(tanx0,6.0));
                //  16*(tan(g)**2 + 1)*(17*(tan(g)**2 + 1)**3 + 180*(tan(g)**2 + 1)**2*tan(g)**2 +
                // 114*(tan(g)**2 + 1)*tan(g)**4 + 4*tan(g)**6)
            case 8:
                derivs[8] = 128.*(tanx02p1)*(62.*pow((tanx02p1),3.) +
                    192.*pow((tanx02p1),2.0)*pow(tanx0,2.0) +
                     60.*(tanx02p1)*pow(tanx0,4.0)+ pow(tanx0,6.0))*tanx0;
                // 128*(tan(g)**2 + 1)*(62*(tan(g)**2 + 1)**3 + 192*(tan(g)**2 + 1)**2*tan(g)**2 +
                //  60*(tan(g)**2 + 1)*tan(g)**4 + tan(g)**6)*tan(g)
            case 9:
                derivs[9] = 128.*(pow(tanx0,2.0) + 1.)*(
                    62*pow((tanx02p1),4) + 
                    1072.*pow((tanx02p1),3.)*pow(tanx0,2.0) + 
                    1452.*pow((tanx02p1),2.)*pow(tanx0,4.0) + 
                    247. *    (tanx02p1)    *pow(tanx0,6.0) +
                    2.*(pow(tanx0,8.0))
                    );
                // Too many calls to pow(tanx0,2.0) +1.
                // 128*
                // (tan(x1)**2 + 1)*
                // (
                //     62*(tan(x1)**2 + 1)**4 + 
                //     1072*(tan(x1)**2 + 1)**3*tan(x1)**2 + 
                //     1452*(tan(x1)**2 + 1)**2*tan(x1)**4 + 
                //     247 *(tan(x1)**2 + 1)   *tan(x1)**6 + 
                //     2*tan(x1)**8
                // )
            case 10:

                derivs[10] =256.*(tanx02p1)*(
                    1382.*pow((tanx02p1),4.) + 
                    7192.*pow((tanx02p1),3.)*pow(tanx0,2.0) + 
                    5097.*pow((tanx02p1),2.)*pow(tanx0,4.0) + 
                    502. *(tanx02p1)*pow(tanx0,6.0) + 
                    2.*pow(tanx0,8.0)
                    )*tanx0;
                // 256*
                // (tan(x1)**2 + 1)*
                // (
                //     1382*(tan(x1)**2 + 1)**4 + 
                //     7192*(tan(x1)**2 + 1)**3*tan(x1)**2 + 
                //     5097*(tan(x1)**2 + 1)**2*tan(x1)**4 + 
                //     502 *(tan(x1)**2 + 1)   *tan(x1)**6 + 
                //     2*tan(x1)**8
                // ) * tan(x1)
        }
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_soti_cos(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = c_soti_getReal(num);
    uint8_t i;
    uint8_t s = 0;
    double sign = 1.;
    
    for( i=0; i<(num->order+1); i++){
    
        if (s == 0){
        
            derivs[i]=sign*cos(x0);
        
        }else{
        
            sign = sign * (-1.0);
            derivs[i]=sign*sin(x0);
    
        }
    
        s = (s+1)%2;
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_sin(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = c_soti_getReal(num);
    uint8_t i;
    uint8_t s = 1;
    double sign = -1.;
    
    for( i=0; i<(num->order+1); i++){
    
        if (s == 0){
        
            derivs[i]=sign*cos(x0);
        
        }else{
        
            sign = sign * (-1.0);
            derivs[i]=sign*sin(x0);
    
        }
    
        s = (s+1)%2;
     
    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_log(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Natural logarithm function for OTI numbers. 

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = c_soti_getReal(num);
    double sign = -1.;
    double factor = 1.;
    uint8_t i;    

    for (i=0; i<(num->order+1); i++){

        
        if (i == 0){
        
            derivs[i]=log(x0);
        
        }else{
         
            derivs[i] = factor * pow(sign,(i+1)) * (1.0/pow(x0,i) );
            factor    = factor * i;
    
        }

    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_exp(sotinum_t* num, directionHelper* p_dH, sotinum_t* res){
    /*
    PURPOSE:  Exponential function for OTI numbers. -> e**x, x is otinum

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double value = exp(c_soti_getReal(num));
    uint8_t i;    

    for (i=0; i<(num->order+1); i++){

        derivs[i]=value;

    }
  
    // Compute all the derivatives 
    c_soti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_pow(sotinum_t* num, double exponent, directionHelper* p_dH,sotinum_t* res){
    /*
    PURPOSE:  Power function for OTI numbers, for non integer exponents.

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double power_i = exponent;
    double x0 = c_soti_getReal(num);
    uint8_t flag = 0;
    double factor = 1.;
    uint8_t i;
    

    for (i=0; i<(num->order+1); i++){

        if( power_i != 0.0){
            
            derivs[i]=factor*pow(x0,power_i);
            factor = factor*power_i;
            power_i -= 1.;

        }else{

            if (i==0){

                derivs[i] = x0; // not sure if 1.0 or if coefs[0]
                flag = 1;

            } else if (flag == 0 ){

                derivs[i]=factor;
                flag = 1;

            }else{ 

                derivs[i] = 0.;

            }            

        }

    }
  
  // Compute all the derivatives 
  c_soti_derivFunc(derivs, num,  p_dH, res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_derivFunc(double* fder, sotinum_t* g, directionHelper* p_dH, sotinum_t* feval){
    /*
    void c_soti_derivFunc(double* fder, otinum_t* g, otinum_t* feval)
    
    Given the derivatives of a function f(g) with respect to g, finds the evaluation of the function 
    when g is an oti number.

    To differentiate a function f that depends on another function
    g which depends on several variables. 

    i.e. f( g(x1,...,xn) )

    g comes evaluated and it is represented by an OTI number.

    INPUTS:
        
        ->  fder:   Array of values holding all the derivatives of f with respect to g up to 
                    g.order. 
        
        ->  g:      oti number that represents g(x1,...,xn).

        -> iter:   Number of iterations to be evaluated. Best for exponentiation evaluation.

        ->  feval:  Evaluated function f(g) where g is an oti number.

    */

    uint8_t order = g->order;
    uint8_t i=0;

    sotinum_t tmp1, tmp2, tmp3;
    sotinum_t gp1, gp2, gp4, gp8;

    // Prepare for the evaluation
    
    if(g->size >= 1){

        gp1 = *g;

        if (gp1.p_indx[0]==0){

            // forget about real part
            gp1.p_indx = &gp1.p_indx[1];
            gp1.p_coefs = &gp1.p_coefs[1];
            gp1.size -= 1;

        }

        if (fder[0] == 0.0){

            c_soti_createEmpty(feval, 0, order);

        } else {

            c_soti_createEmpty(feval, 1, order);
            feval->p_coefs[0] = fder[0];
            feval->p_indx[0]  = 0;

        }

        c_soti_createEmpty(&gp2 , 0, order);
        c_soti_createEmpty(&gp4 , 0, order);
        c_soti_createEmpty(&gp8 , 0, order);
        
        // printf("C: Order Given: %hhu\n",order);

        for (i=1; i<=order; i++){

            if (i ==  1){
                
                if (fder[1]!=0.0){
                    c_soti_copy(  &tmp1, &gp1    );
                    c_soti_smulf( &tmp1, fder[1] );
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  2){
                
                // printf("C: i=2\n");
                c_soti_mul(&gp1, &gp1, &gp2, p_dH);

                if (fder[2]!=0.0){
                    
                    c_soti_copy(&tmp1,&gp2);
                    c_soti_smulf(&tmp1,fder[2]/2.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval, p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  3){

                if (fder[3]!=0.0){
                    c_soti_mul(&gp2, &gp1, &tmp1, p_dH);
                    c_soti_smulf(&tmp1,fder[3]/6.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }


            } else if (i ==  4){

                c_soti_mul(&gp2, &gp2, &gp4, p_dH);

                if (fder[3]!=0.0){
                    c_soti_copy(&tmp1,&gp4);
                    c_soti_smulf(&tmp1,fder[4]/24.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  5){

                if (fder[5]!=0.0){

                    c_soti_mul(&gp4, &gp1, &tmp1, p_dH);
                    c_soti_smulf(&tmp1,fder[5]/120.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  6){


                if (fder[6]!=0.0){
                    c_soti_mul(&gp4, &gp2, &tmp1, p_dH);
                    c_soti_smulf(&tmp1,fder[6]/720.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  7){

                if (fder[7]!=0.0){
                    c_soti_mul(&gp4, &gp2, &tmp2, p_dH);
                    c_soti_mul(&tmp2, &gp1, &tmp1, p_dH);
                    c_soti_smulf(&tmp1,fder[7]/5040.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp2);
                    c_soti_free(&tmp3);
                }


            } else if (i ==  8){


                c_soti_mul(&gp4, &gp4, &gp8, p_dH);

                if (fder[8]!=0.0){
                    c_soti_copy(&tmp1,&gp8);
                    c_soti_smulf(&tmp1, fder[8]/40320.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i ==  9){

                if (fder[9]!=0.0){
                    c_soti_mul(&gp8, &gp1, &tmp1, p_dH);
                    c_soti_smulf(&tmp1, fder[9]/362880.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            } else if (i == 10){

                if (fder[10]!=0.0){
                    c_soti_mul(&gp8, &gp1, &tmp1, p_dH);
                    c_soti_smulf(&tmp1, fder[10]/3628800.0);
                    tmp3 = *feval;
                    c_soti_sum(&tmp3, &tmp1, feval,p_dH);
                    c_soti_free(&tmp1);
                    c_soti_free(&tmp3);
                }

            }

        }
        
        c_soti_free(&gp2);
        c_soti_free(&gp4);
        c_soti_free(&gp8);

    } else {

        if(fder[0]!=0.0){

            // Create number without internal derivatives (because all are zero)
            c_soti_createEmpty(feval,1,g->order);
            feval->p_coefs[0] = fder[0];
            feval->p_indx[0]  =       0;

        } else {

            // create empty number
            c_soti_createEmpty(feval,0,g->order);

        }
        
    }
    


}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
double c_soti_getReal(sotinum_t* num){
    /*
    PURPOSE:  Get the real coefficient of the given  sparse otinum.

    */
    //*************************************************************************************************
    
    double res = 0.0;

    if (num->size > 0){

        if( num->p_indx[0] == 0){

            res = num->p_coefs[0];
        
        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_ipowfast(sotinum_t* num1, uint8_t exp, sotinum_t* res, directionHelper* p_dH){
    /*
    void c_soti_ipowfast(sotinum_t* num1, uint8_t exp, sotinum_t* res)
    
    Fast Power of soti to an integer power. NOTE: This is  efficient for 
    positive exponents lower or equal than 10!.


    INPUTS:

        -> num1:    Direction to compute Faa Di Bruno formula
        
        -> exp:     exponent. 

        ->  p_dH:   list of helpers.

    OUTPUTS:

        -> res:    Holder with the rresulting number.
       res = num1 ** exp          // Python syntax.

       // It actually performs the following

       res = num1*num1*...*num1   // exp times

    */



    uint8_t flag = 0;

    sotinum_t numr[4];


    // printf(" ---> C: exp received: %hhu \n\n",exp);

    if (exp == 0){

        // printf(" ---> C: Case 0 \n");
        // Result is 1. 
        c_soti_createEmpty(&numr[0],1,num1->order);
        numr[0].p_coefs[0] = 1;
        numr[0].p_indx[0]  = 0;
        flag = 0;

    } else if (exp ==  1){

        // printf(" ---> C: Case 1 \n");
        // Result is the same number 
        c_soti_copy(&numr[0],num1); 
        flag = 0;

    } else if (exp ==  2){

        // printf(" ---> C: Case 2 \n");
        // The square of the number num1 x num1
        c_soti_mul(num1, num1, &numr[0], p_dH);
        flag = 0;

    } else if (exp ==  3){

        // printf(" ---> C: Case 3 \n");
        // The third power of num1: (num1 x num1) x num1
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], num1, &numr[1], p_dH);
        c_soti_free(&numr[0]);
        flag = 1;

    } else if (exp ==  4){

        // printf(" ---> C: Case 4 \n");
        // The fourth power of num1: (num1 x num1) x (num1 x num1)
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_free(&numr[0]);
        flag = 1;

    } else if (exp ==  5){

        // printf(" ---> C: Case 5 \n");
        // The fifth power of num1: (num1 x num1) x (num1 x num1) x num1
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_free(&numr[0]);
        c_soti_mul(&numr[1], num1, &numr[2], p_dH);
        c_soti_free(&numr[1]);
        flag = 2;

    } else if (exp ==  6){

        // printf(" ---> C: Case 6 \n");
        // The sixth power of num1: (num1 x num1) x (num1 x num1) x (num1 x num1)
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_mul(&numr[1], &numr[0], &numr[2], p_dH);
        c_soti_free(&numr[0]);
        c_soti_free(&numr[1]);
        flag = 2;

    } else if (exp ==  7){

        // printf(" ---> C: Case 7 \n");
        // The seventh power of num1: (num1 x num1) x (num1 x num1) x (num1 x num1) x num1
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_mul(&numr[1], &numr[0], &numr[2], p_dH);
        c_soti_mul(&numr[2], num1, &numr[3], p_dH);
        c_soti_free(&numr[0]);
        c_soti_free(&numr[1]);
        c_soti_free(&numr[2]);
        flag = 3;


    } else if (exp ==  8){

        // printf(" ---> C: Case 8 \n");
        // The eigth power of num1: (num1 x num1) x (num1 x num1) x (num1 x num1) x (num1 x num1)
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_mul(&numr[1], &numr[1], &numr[2], p_dH);
        c_soti_free(&numr[0]);
        c_soti_free(&numr[1]);
        flag = 2;

    } else if (exp ==  9){

        // printf(" ---> C: Case 9 \n");
        // The ninth power of num1: (num1 x num1) x (num1 x num1) x (num1 x num1) x (num1 x num1)
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_mul(&numr[1], &numr[1], &numr[2], p_dH);
        c_soti_mul(&numr[2], num1, &numr[3], p_dH);
        c_soti_free(&numr[0]);
        c_soti_free(&numr[1]);
        c_soti_free(&numr[2]);        
        flag = 3;

    } else if (exp == 10){

        // printf(" ---> C: Case 10 \n");

        // The seventh power of num1: (num1 x num1) x (num1 x num1) x (num1 x num1) x (num1 x num1)
        c_soti_mul(num1, num1, &numr[0], p_dH);
        c_soti_mul(&numr[0], &numr[0], &numr[1], p_dH);
        c_soti_mul(&numr[1], &numr[1], &numr[2], p_dH);
        c_soti_mul(&numr[2], &numr[0], &numr[3], p_dH);
        c_soti_free(&numr[0]);
        c_soti_free(&numr[1]);
        c_soti_free(&numr[2]);        
        flag = 3;
    }
           
    *res = numr[flag];

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_soti_ipow(sotinum_t* num1, uint8_t exp, sotinum_t* res, directionHelper* p_dH){
    /*
    void c_soti_ipow(sotinum_t* num1, uint8_t exp, sotinum_t* res)
    
    Power a soti to an integer power. NOTE: This is  efficient for exponents lower or equal than 10!.


    INPUTS:

        -> num1:    Direction to compute Faa Di Bruno formula
        
        -> exp:     exponent. 

        ->  p_dH:   list of helpers.

    OUTPUTS:

        -> res:    Holder with the rresulting number.
       res = num1 ** exp          // Python syntax.

       // It actually performs the following

       res = num1*num1*...*num1   // exp times

    */

    
    // uint64_t* indxOrder = NULL;
    // uint64_t* multIndx  = NULL; // Index to be multiplied
    // uint8_t order = num1->order;
    // uint8_t orderSum = 0;

    uint64_t   i = 0;
    uint8_t flag = 0;

    sotinum_t numr[2];


    // indxOrder = (uint64_t*)malloc(num1->size*sizeof(uint64_t));
    // if (indxOrder == NULL){
    //     printf("--- MemoryError ---\n");
    //     exit(1);
    // }

    // for (i=0; i<num1->size; i++){
    //     indxOrder[i] = c_sumUI8(&p_dH[order-1].p_expA[(num1->p_indx[i]-1)*order],order);
    // }

    // orderSum = (exp-1)*indxOrder[0];

    c_soti_copy( &numr[0], num1); // Copy initial value

    for( i=1; i<exp; i++){

        if (flag == 0 ){

            c_soti_mul(&numr[0], num1, &numr[1], p_dH);
            c_soti_free(&numr[0]);
            flag = 1;

        } else{

            c_soti_mul(&numr[1], num1, &numr[0], p_dH);
            c_soti_free(&numr[1]);
            flag = 0;

        }
        
    }

    if (flag == 0 ){
        
        *res = numr[0];

    } else{
        
        *res = numr[1];

    }
    // 
    // c_soti_copy( res, num1);
    

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void c_soti_neg( sotinum_t* num1, sotinum_t* res){
    /*
    void c_soti_copy(sotinum_t* num1, sotinum_t* res)

    negate soti.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        
        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = -num1.copy()    

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    c_soti_createEmpty(res, num1->size, num1->order);

    if (num1->size != 0){

        // memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
        memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 
        
        for (i=0; i<num1->size; i++){

            res->p_coefs[i] = -num1->p_coefs[i];
        
        }

    }    

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_copy(sotinum_t* res, sotinum_t* num1){
    /*
    void c_soti_copy(sotinum_t* res, sotinum_t* num1)

    Copy soti.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        
        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1.copy()     

    */ 
    // ************************************************************************************************
    

    c_soti_createEmpty(res, num1->size, num1->order);

    if (num1->size != 0){

        memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
        memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 

    }    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_fsub(sotinum_t* num1, double num2, sotinum_t* res){
    /*
    void c_soti_subf(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    subtract oti and real numbers.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    real.

        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 - num2

    */ 
    // ************************************************************************************************
    
    uint64_t i;
    uint8_t order = num1->order;

    

    // check if num1 or num2 are zero
    if (num1->size == 0 && num2 == 0.0){

        c_soti_createEmpty(res, 0, order);

    } else if(num1->size == 0) {

        c_soti_createEmpty(res, 1, order);

        res->p_coefs[0] = num2;
        res->p_indx[0]  = 0   ;  
 

    } else {    

        if (num1->p_indx[0] == 0){

            c_soti_createEmpty(res, num1->size, order);
            memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 

            for (i=0; i<num1->size;i++){

                res->p_coefs[i] = -num1->p_coefs[i];

            }

            res->p_coefs[0] += num2;

        } else {

            c_soti_createEmpty(res, num1->size+1, order);
            memcpy(&res->p_indx[1], num1->p_indx ,num1->size*sizeof(uint64_t)); 

            for (i=0; i<num1->size;i++){

                res->p_coefs[i+1] = -num1->p_coefs[i];

            }

            res->p_coefs[0] = num2;
            res->p_indx[0]  = 0;

        }
        
    }
    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_subf(sotinum_t* num1, double num2, sotinum_t* res){
    /*
    void c_soti_subf(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    subtract oti and real numbers.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    real.

        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 - num2

    */ 
    // ************************************************************************************************
    

    uint8_t order = num1->order;

    

    // check if num1 or num2 are zero
    if (num1->size == 0 && num2 == 0.0){

        c_soti_createEmpty(res, 0, order);

    } else if(num1->size == 0) {

        c_soti_createEmpty(res, 1, order);

        res->p_coefs[0] = -num2;
        res->p_indx[0]  = 0   ;  
 

    } else {    

        if (num1->p_indx[0] == 0){

            c_soti_createEmpty(res, num1->size, order);
            memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
            memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 
            res->p_coefs[0] -= num2;

        } else {

            c_soti_createEmpty(res, num1->size+1, order);
            memcpy(&res->p_coefs[1],num1->p_coefs,num1->size*sizeof(double)  );
            memcpy(&res->p_indx[1], num1->p_indx ,num1->size*sizeof(uint64_t)); 
            res->p_coefs[0] = -num2;
            res->p_indx[0]  = 0;

        }
        
    }
    
    

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_sub(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH){
    /*
    void c_soti_sub(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    subtract two oti numbers

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    Address of the other operand.

        ->res:     Address of the result holder. Must not come allocated. 
                   Cannot be the same address as num1 or num2

        -> p_dH:   List of helpers

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 - num2

    */ 
    // ************************************************************************************************
    uint64_t i, i1=0, i2=0, size_res=0;
    uint8_t order = num1->order;

    double*   p_tmpcoefs = p_dH[num1->order-1].p_coefs;
    uint64_t*  p_tmpindx = p_dH[num1->order-1].p_indx ;
    uint64_t     ndirmax = p_dH[num1->order-1].Ndir   ;

    // Find the maximum number of coefficients in 
    uint64_t niter_max  = MIN(num1->size+num2->size, ndirmax); // Maximum number of iterations

    // check if num1 or num2 are zero
    if (num1->size == 0 && num2->size == 0){

        c_soti_createEmpty(res, size_res, order);

    } else if(num1->size == 0) {

        c_soti_createEmpty(res, num2->size, order);
        memcpy(res->p_coefs,num2->p_coefs,num2->size*sizeof(double)  );
        memcpy(res->p_indx, num2->p_indx ,num2->size*sizeof(uint64_t));  

    } else if(num2->size == 0) {

        c_soti_createEmpty(res, num1->size, order);
        memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
        memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 

    } else {    

        for( i = 0; i < niter_max; i++){

            if(i1 >= num1->size &&   i2 >= num2->size){
                break;
            }

            if(i1 >= num1->size){

                // All remaining elements are not in num1.
                
                p_tmpcoefs[i] = -num2->p_coefs[i2];
                p_tmpindx[i]  = num2->p_indx[i2];
                i2++;
                size_res++;

            } else if(i2 >= num2->size){

                // All remaining elements are not in num2.
                
                p_tmpcoefs[i] = num1->p_coefs[i1];
                p_tmpindx[i]  = num1->p_indx[i1];
                i1++;
                size_res++;


            } else {

                // Here i1 and i2 are looking for some value.
                
                if (num1->p_indx[i1] == num2->p_indx[i2]){


                    p_tmpcoefs[i] = num1->p_coefs[i1]-num2->p_coefs[i2];
                    p_tmpindx[i]  = num2->p_indx[i2];

                    i1++;
                    i2++;
                    size_res++;

                } else {

                    if (num1->p_indx[i1] < num2->p_indx[i2]){  // index of num1 goes first.

                        p_tmpcoefs[i] = num1->p_coefs[i1];
                        p_tmpindx[i]  = num1->p_indx[i1];
                        i1++;
                        size_res++;

                    } else {

                        p_tmpcoefs[i] = -num2->p_coefs[i2];
                        p_tmpindx[i]  = num2->p_indx[i2];
                        i2++;
                        size_res++;

                    }

                }

            }

                     
        }
        // Create new sprotinum
        
        c_soti_createEmpty(res, size_res, order);
        
        if (size_res>0){
            memcpy(res->p_coefs,p_tmpcoefs,size_res*sizeof(double)  );
            memcpy(res->p_indx, p_tmpindx ,size_res*sizeof(uint64_t));    
        }
    }


}    
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void c_soti_sumf(sotinum_t* num1, double num2, sotinum_t* res){
    /*
    void c_soti_suml(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    sum oti and real numbers.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    real.

        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 + num2

    */ 
    // ************************************************************************************************
    

    uint8_t order = num1->order;

    // check if num1 or num2 are zero
    if (num1->size == 0 && num2 == 0.0){

        c_soti_createEmpty(res, 0, order);

    } else if(num1->size == 0) {

        c_soti_createEmpty(res, 1, order);

        res->p_coefs[0] = num2;
        res->p_indx[0]  = 0   ;  
 

    } else {    

        if (num1->p_indx[0] == 0){

            c_soti_createEmpty(res, num1->size, order);
            memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
            memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 
            res->p_coefs[0] += num2;

        } else {

            c_soti_createEmpty(res, num1->size+1, order);
            memcpy(&res->p_coefs[1],num1->p_coefs,num1->size*sizeof(double)  );
            memcpy(&res->p_indx[1], num1->p_indx ,num1->size*sizeof(uint64_t)); 
            res->p_coefs[0] = num2;
            res->p_indx[0]  = 0;

        }
        
    }
    
    

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_smulf(sotinum_t* num1, double num2){
    /*
    void c_soti_smulf(otinum_t* num1, double num2, otinum_t* res, directionHelper* p_dH)

    Self multiply an oti number times a real coefficient.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    real.

        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 * num2

    */ 
    // ************************************************************************************************
    uint64_t i;
    
    // c_soti_createEmpty(res, num1->size, num1->order);

    if(num1->size!= 0 && num2 != 0.0){

        for( i = 0; i < num1->size; i++){
            
            num1->p_coefs[i]*=num2;
        }    

    } else {

        c_soti_free(num1);

    }
    
    

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_soti_mulf(sotinum_t* num1, double num2, sotinum_t* res){
    /*
    void c_soti_mulf(otinum_t* num1, double num2, otinum_t* res, directionHelper* p_dH)

    multiply an oti number times a real coefficient.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    real.

        ->res:     Address of the result holder. The result is allocated in this function.

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 * num2

    */ 
    // ************************************************************************************************
    uint64_t i;
    
    

    if(num1->size != 0 && num2 != 0.0){

        c_soti_createEmpty(res, num1->size, num1->order);

        // Initialize the result holder.
        memcpy(res->p_coefs,num1->p_coefs,res->size*sizeof(double)  );
        memcpy(res->p_indx ,num1->p_indx ,res->size*sizeof(uint64_t));


        for( i = 0; i < res->size; i++){
            
            res->p_coefs[i]*=num2;
        }    

    } else {
        
        c_soti_createEmpty(res, 0, num1->order);

    }
    
    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_mul(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH){
    /*
    void c_soti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    multiply two oti numbers

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    Address of the other operand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions. Cannot be the same address as num1 or num2

        -> p_dH:   List of helpers

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 * num2

    */ 
    // ************************************************************************************************
    uint64_t i, j, ii, jj, indx;
    uint64_t ncoefs; // Always considers real to be present.
    uint8_t err=1, order = num1->order;

    double*   p_tmpcoefs = p_dH[num1->order-1].p_coefs;
    uint64_t*  p_tmpindx = p_dH[num1->order-1].p_indx ;
    uint64_t     ndirmax = MIN(p_dH[num1->order-1].Ndir,num1->size*num2->size);

    // printf("tmpIndx ptr: %x, tmpCoefs Ptr: %x \n",p_tmpindx, p_tmpcoefs);
    // printf("number of directions %llu\n",ndirmax);
    // printf("Received num1 with size %llu and order %hhu\n",num1->size,num1->order);
    // printf("Received num2 with size %llu and order %hhu\n",num2->size,num2->order);
    
    if( num1->size == 0 || num2->size == 0){
        
        ncoefs = 0;

    }else{

        ncoefs = 0;
        // Initialize in zero the result holder
        memset(p_tmpcoefs, 0, ndirmax*sizeof(double)  );
        memset(p_tmpindx , 0, ndirmax*sizeof(uint64_t));

        for( ii = 0; ii < num1->size; ii++){
            
            for( jj = 0; jj < num2->size; jj++){

                // Multiply directions.
                i = num1->p_indx[ii];
                j = num2->p_indx[jj];
                indx = c_helper_multIndxFast(i,j,order,p_dH,&err);

                if (err == 0){   // If error flag is off
                    //printf("i = %llu, j = %llu, indx = %llu\n",i,j,indx);
                    c_helper_insertIndx(p_tmpindx,indx,&ncoefs, 
                        p_tmpcoefs,
                        num1->p_coefs[ii] * num2->p_coefs[jj]);
                                                                            
                    // p_tmpcoefs[indx] += num1->p_coefs[ii] * num2->p_coefs[jj];

                }

            }
                     
        }
    }
    
    // Create new sprotinum
    
    c_soti_createEmpty(res, ncoefs, order);
    
    if (ncoefs != 0){

        // Copy all indices
        memcpy(res->p_coefs, p_tmpcoefs, ncoefs*sizeof(double)  );
        memcpy(res->p_indx , p_tmpindx,  ncoefs*sizeof(uint64_t));
        // for (ii = 0;ii<ncoefs;ii++){
        //     res->p_coefs[ii] = p_tmpcoefs[p_tmpindx[ii]];
        // }

    }

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_sum(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH){
    /*
    void c_soti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    sum two oti numbers

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    Address of the other operand.

        ->res:     Address of the result holder. Must not come allocated. 
                   Cannot be the same address as num1 or num2

        -> p_dH:   List of helpers

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 + num2

    */ 
    // ************************************************************************************************
    uint64_t i, i1=0, i2=0, size_res=0;
    uint8_t order = num1->order;

    double*   p_tmpcoefs = p_dH[num1->order-1].p_coefs;
    uint64_t*  p_tmpindx = p_dH[num1->order-1].p_indx ;
    uint64_t     ndirmax = p_dH[num1->order-1].Ndir   ;

    // Find the maximum number of coefficients in 
    uint64_t niter_max  = MIN(num1->size+num2->size, ndirmax); // Maximum number of iterations

    // check if num1 or num2 are zero
    if (num1->size == 0 && num2->size == 0){

        c_soti_createEmpty(res, size_res, order);

    } else if(num1->size == 0) {

        c_soti_createEmpty(res, num2->size, order);
        memcpy(res->p_coefs,num2->p_coefs,num2->size*sizeof(double)  );
        memcpy(res->p_indx, num2->p_indx ,num2->size*sizeof(uint64_t));  

    } else if(num2->size == 0) {

        c_soti_createEmpty(res, num1->size, order);
        memcpy(res->p_coefs,num1->p_coefs,num1->size*sizeof(double)  );
        memcpy(res->p_indx, num1->p_indx ,num1->size*sizeof(uint64_t)); 

    } else {    
        // printf("Adding two elements here!\n");
        for( i = 0; i < niter_max; i++){

            if(i1 >= num1->size &&   i2 >= num2->size){
                break;
            }

            if(i1 >= num1->size){

                // All remaining elements are not in num1.
                
                p_tmpcoefs[i] = num2->p_coefs[i2];
                p_tmpindx[i]  = num2->p_indx[i2];
                i2++;
                size_res++;

            } else if(i2 >= num2->size){

                // All remaining elements are not in num2.
                
                p_tmpcoefs[i] = num1->p_coefs[i1];
                p_tmpindx[i]  = num1->p_indx[i1];
                i1++;
                size_res++;


            } else {

                // Here i1 and i2 are looking for some value.
                
                if (num1->p_indx[i1] == num2->p_indx[i2]){


                    p_tmpcoefs[i] = num2->p_coefs[i2]+num1->p_coefs[i1];
                    p_tmpindx[i]  = num2->p_indx[i2];

                    i1++;
                    i2++;
                    size_res++;

                } else {

                    if (num1->p_indx[i1] < num2->p_indx[i2]){  // index of num1 goes first.

                        p_tmpcoefs[i] = num1->p_coefs[i1];
                        p_tmpindx[i]  = num1->p_indx[i1];
                        i1++;
                        size_res++;

                    } else {

                        p_tmpcoefs[i] = num2->p_coefs[i2];
                        p_tmpindx[i]  = num2->p_indx[i2];
                        i2++;
                        size_res++;

                    }

                }

            }

                     
        }
        // Create new sprotinum
        
        c_soti_createEmpty(res, size_res, order);
        
        if (size_res>0){
            memcpy(res->p_coefs,p_tmpcoefs,size_res*sizeof(double)  );
            memcpy(res->p_indx, p_tmpindx ,size_res*sizeof(uint64_t));    
        }
    }


}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void c_soti_free(sotinum_t* numHolder){
    /*
    c_freeOti(numHolder)

    Frees an allocated oti number

    INPUTS:

        ->numHolder:    Address of the number to be freed.
        

    */ 
    // ************************************************************************************************

    if (numHolder->p_coefs != NULL){

        free(numHolder->p_coefs); 
        numHolder->p_coefs = NULL;

    }

    if (numHolder->p_indx != NULL){

        free(numHolder->p_indx); 
        numHolder->p_indx = NULL;

    }
    numHolder->size = 0;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_soti_createFromReal(double num, sotinum_t* numHolder, uint8_t order){
    /*
    c_soti_createFromReal( num, numHolder,  order)

    C-level memory allocation for a real-only oti number.

    INPUTS:
        -> num:         Real coefficient.

        ->numHolder:    Address of the number to be allocated.
        
        ->    order:    Order to be loaded in memory.
            Example: 3

        

    OUTPUTS:
        -> The result is the numHolder with the memory allocated and with the structure set up.
    */ 
    // ************************************************************************************************
    
    c_soti_createEmpty( numHolder, 1, order);

    numHolder->p_coefs[0] = num;
    numHolder->p_indx[0] = 0;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_soti_createEmpty(sotinum_t* numHolder,   uint64_t ncoefs, uint8_t order){
    /*
    c_oti_createEmpty(numHolder, ndir, order)

    C-level memory allocation of a dense oti number a direction array from a file

    INPUTS:

        ->numHolder:    Address of the number to be allocated.
        
        ->    order:    Order to be loaded in memory.
            Example: 3

        ->     coefs:    Number of nonzero coefficients in the number.
            Example: 100

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    
    if (ncoefs == 0){

        numHolder->p_indx  = NULL ;
        numHolder->p_coefs = NULL ;

    } else{

        numHolder->p_indx = (uint64_t*)c_malloc_ptr(ncoefs,sizeof(uint64_t));
        
        numHolder->p_coefs = (double*)c_malloc_ptr(ncoefs ,sizeof(double) );

    }

    
    numHolder->size  = ncoefs;
    numHolder->order = order;
}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// -----------------------------     END SPROTINUM FUNCTIONS     --------------------------------------
// ----------------------------------------------------------------------------------------------------
















