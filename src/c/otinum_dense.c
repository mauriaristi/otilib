#include "oti/otinum_dense.h"

// ----------------------------------------------------------------------------------------------------
// ---------------------------------     OTINUM FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_atan2(otinum_t* numx, otinum_t* numy, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Tangent function counting all quadrants for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[numx->order-1].p_fder; // holder for the derivatives in the helper.
    double x0    ;
    uint8_t i;
    otinum_t tmp;


    // first perform the division of the numbers

    // 1/y
    c_oti_pow(numy,-1.0,p_dH, res);

    // Allocate memory for the result:
    tmp.p_coefs = (double* )malloc(numx->Ndir*sizeof(double)) ;
    if( tmp.p_coefs == NULL ){
        printf("---- MemoryError ----\n");
        exit(-1);
    }
    tmp.order = numx->order;
    tmp.Ndir = numx->Ndir;
    //x*(1/y) 
    c_oti_mul(numx, res, &tmp, p_dH);
    free(res->p_coefs);
    res->p_coefs = NULL;

    x0 = tmp.p_coefs[0];

    for( i=0; i<(numx->order+1); i++){
    
        switch(i){
            case 0:
                derivs[0] =  atan2(numx->p_coefs[0],numy->p_coefs[0]);

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
    c_oti_derivFunc(derivs, &tmp, p_dH, res);
    free(tmp.p_coefs);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_logb(otinum_t* num, int base, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  logarithm of base b function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_oti_log10(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  logarithm of base 10 function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_atanh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Hyperbolic tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_asinh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Hyperbolic sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_acosh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Hyperbolic inverse cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_tanh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Hyperbolic tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_sqrt(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Square root function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    // double x0 = num->p_coefs[0];
    double sqx = sqrt(num->p_coefs[0]);
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_cosh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Hyperbolic Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_sinh(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Hyperbolic Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_oti_asin(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_oti_acos(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_oti_atan(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Inverse Tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_tan(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Tangent function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder; // holder for the derivatives in the helper.
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_oti_cos(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Cosine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_sin(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Sine function for OTI numbers.

    */
    //*************************************************************************************************
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_oti_log(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Natural logarithm function for OTI numbers. 

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double x0 = num->p_coefs[0];
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
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_oti_exp(otinum_t* num, directionHelper* p_dH, otinum_t* res){
    /*
    PURPOSE:  Exponential function for OTI numbers. -> e**x, x is otinum

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double value = exp(num->p_coefs[0]);
    uint8_t i;    

    for (i=0; i<(num->order+1); i++){

        derivs[i]=value;

    }
  
    // Compute all the derivatives 
    c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void c_oti_pow(otinum_t* num, double exponent, directionHelper* p_dH,otinum_t* res){
    /*
    PURPOSE:  Power function for OTI numbers, for non integer exponents.

    */
    //*************************************************************************************************
    
    double* derivs = p_dH[num->order-1].p_fder;
    double power_i = exponent;
    double x0 = num->p_coefs[0];
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
  c_oti_derivFunc(derivs, num, p_dH, res);

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_oti_collapseDirA(uint16_t* array, uint8_t order, uint16_t* dirA, uint8_t* expA){



    uint16_t oldValue = array[0];
    uint8_t  count = 0;
    uint8_t  iDir  = 0;
    uint8_t  i;

    for (i=0; i<order; i++ ){   // TODO: Check when it is in collapse if
                                // if array.size is order.

        if( array[i] == 0){

            continue;

        }else if (array[i] == oldValue){
          
            count++;

        }else{
          
            expA[iDir] = count;
            dirA[iDir] = oldValue;
            iDir += 1;
            oldValue = array[i];
            count = 1;

        }

    }

    expA[iDir] = count;
    dirA[iDir] = oldValue;
    iDir++;

    // Put zeros in all other values of the array, if it is the case:

    if (iDir != order){// Check size of dirA
        
        for(i=iDir; i<order; i++){

          expA[i] = 0;
          dirA[i] = 0;

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_oti_expandDirA(uint16_t* p_dirA,uint8_t* p_expA, uint8_t order, uint16_t* p_expandArr){


    
    uint8_t i=0, count = 0, idir = 0;

    for (;i<order;i++){
        
        p_expandArr[i] = p_dirA[idir];
        count++;

        if (count == p_expA[idir]){

            count = 0;
            idir++;

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
double c_oti_FaaDiBruno(uint64_t indx, double* fder, otinum_t* g, directionHelper* p_dH){
    /*
    double c_oti_FaaDiBruno(uint64_t indx, double* fder, otinum_t* g, directionHelper* p_dH)
    
    Apply the Faa di Bruno formula to find the coefficient that corresponds to a specific partial
    derivative of f.

    To differentiate a function f that depends on another function
    g which depends on several variables. 

    i.e. f( g(x1,...,xn) )

    g comes evaluated and it is represented by an OTI number.

    INPUTS:

        -> indx:    Direction to compute Faa di Bruno formula
        
        ->  fder:   Array of values holding all the derivatives of f with respect to g up to 
                    g.order. 
        
        ->  g:      oti number that represents g(x1,...,xn).

        ->  p_dH:  list of helpers.

  
    WARNING:    This is a very rudimentary implementation. If you have time to
                contribute, this is a function that might be very crucial to 
                optimize.

    */

    double sum_ = 0.;
    double mult ;
    uint8_t orderg = g->order;
    uint16_t* dirA  = c_helper_getDirA(indx,orderg,p_dH);  // 
    uint8_t* expA   = c_helper_getExpA(indx,orderg,p_dH);  // 
    uint16_t* dirA_ = c_helper_getUDirA(orderg,0,p_dH);    // It is expensive to create arrays
    uint8_t* expA_  = c_helper_getUExpA(orderg,0,p_dH);    // at each iteration. Consider 
    uint64_t i, j, k, el, count, nsets;                    // inputing the allocated arrays  
    uint16_t seti;
    uint8_t order = c_sumUI8(expA,orderg);
    uint16_t* expandedArray = c_helper_getUDirA(orderg,1,p_dH);
    uint16_t* mdir          = c_helper_getUDirA(orderg,2,p_dH);  
    double factor = 1.0;
    uint64_t index;
    uint64_t nevals = c_helper_getNParts(order,p_dH);



    // printf("IN FAADIBRUNO\n");
    // Expand the directions according to the exponents
    c_oti_expandDirA(dirA, expA, order, expandedArray);

    // for part in partition.Partition( expandArray(dirA,expA) )
    for(i=0;i<nevals; i++ ){ 

        mult = 1.0;
        nsets = 0;

        for (j=0;j<order;j++){ // Subpart j


            seti = c_helper_getSet(order,i,j,p_dH); // get the j'th set of the partition i.

            if (seti == 0){ //if partition is == 0 set is full of zeros, therefore avoid computation.
                continue;
            }

            nsets++; //counts the number of sets in the partition.

            el = 0;      // gets the element  at which 
            count = 0;

            while (seti != 0){    // values of the sets are stored in the bits of seti

                if( seti & 1){

                    mdir[count] = expandedArray[el];
                    count+=1;

                }
                

                seti = (seti>>1);
                el++;

            }

            // fill up the other values as zeros:

            for (k=count;k<orderg;k++){

                mdir[k] = 0;

            }

            c_oti_collapseDirA(mdir, orderg, dirA_, expA_);

            index = c_helper_findIndex(dirA_,expA_,orderg,p_dH);
            factor = 1.;

            for( k =0; k<orderg; k++){
          
                if( expA_[k] != 0){ // Not a necessary check
                
                    factor *= c_fastfact(expA_[k]);

                }

            }

            mult *= g->p_coefs[index]*factor;

        }

        sum_ +=  fder[nsets]  *  mult;

    }
    
    factor = 1.0;

    for( k =0; k<orderg; k++){
          
        if( expA[k] != 0){ // not a necessary check
        
            factor *= c_fastfact(expA[k]);

        }

    }

    // printf("sum -> %g\n",sum_);
    // printf("factor -> %g\n",factor);

    return sum_/factor;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_derivFunc(double* fder, otinum_t* g, directionHelper* p_dH, otinum_t* feval){
    /*
    void c_oti_derivFunc(double* fder, otinum_t* g, otinum_t* feval)
    
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

        ->  feval:  Evaluated function f(g) where g is an oti number.

  
    WARNING:    This is a very rudimentary implementation. If you have time to
                contribute, this is a function that might be very crucial to 
                optimize.

    */
    uint8_t order = g->order;
    uint64_t Ndir = g->Ndir;
    uint8_t i = 0;
    // uint16_t nval = c_helper_findMaxDir(Ndir-1,order,p_dH);
    // uint64_t max_i = c_helper_getNels(nval, order, p_dH); 

    // Allocate memory for the result:
    feval->p_coefs = (double* )malloc(Ndir*sizeof(double)) ;
    if( feval->p_coefs == NULL ){
        printf("---- MemoryError ----\n");
        exit(-1);
    }
    feval->order = order;
    feval->Ndir = Ndir;

    // Assign real component:
    feval->p_coefs[0] = fder[0];

    for (i=1; i<Ndir; i++){
        if (order == 1){
            feval->p_coefs[i] = fder[1]*g->p_coefs[i];
        } else {
            feval->p_coefs[i] = c_oti_FaaDiBruno(i,fder,g,p_dH);
        }
    }




}
// ----------------------------------------------------------------------------------------------------

// typedef struct{
//     uint64_t*     p_data;
//     uint64_t*     p_cols;
//     uint64_t*     p_rows;
//     uint64_t       sizex;
//     uint64_t       nrows;
//     uint64_t     nonzero;
// } coomat_ui64_t;


// ****************************************************************************************************
coomat_ui64_t c_oti_matform( uint64_t nvar, uint8_t order, directionHelper* p_dH){
    /*
    uint64_t* c_oti_matform(otinum_t* num, uint64_t size, directionHelper* p_dH)

    Obtain the dense matrix representation of the oti number num.

    INPUTS:

        -> nvar:   Number of independent variables.

        -> order:  Order of derivatives.

        -> p_dH:   List of helpers.

    OUTPUTS:

        The operation gives a uint64_t* such that it contains the matrix form of the oti number.

        Each non zero element in the matrix is the index of the OTI number coefficient that should
        be placed in that position.

        The shape of the matrix is (size x size)

    */ 
    // ************************************************************************************************
    uint64_t i,j,k,ii,Ndir;
    coomat_ui64_t mat;     // matrix pointer, Coo format
    uint8_t error;
    uint64_t nnonzero = c_ndir(2*nvar, order);

    
    // Allocate memory to hold the results:
    mat.p_data = (uint64_t*)malloc(nnonzero*sizeof(uint64_t));
    if (mat.p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    mat.p_cols = (uint64_t*)malloc(nnonzero*sizeof(uint64_t));
    if (mat.p_cols == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    mat.p_rows = (uint64_t*)malloc(nnonzero*sizeof(uint64_t));
    if (mat.p_rows == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    
    // Initialize in zero.
    memset(mat.p_data, 0, nnonzero*sizeof(uint64_t));

    Ndir = c_ndir(nvar, order);
        
    mat.sizex   = Ndir;
    mat.sizey   = Ndir;
    mat.nonzero = nnonzero;


    // Holder of the position of the coefficient vectors
    ii=0;
    for( i = 0; i < Ndir; i++){

        for( j = 0; j < Ndir; j++){
            
            k = c_helper_multIndxFast( i, j, order, p_dH, &error);
            
            if (k>Ndir){

                break;

            }

            if (error == 0){
                // k*size+j
                mat.p_data[ii] = i+1;  // +1 because a 0 can be accounted for errors in sparse matrix
                mat.p_rows[ii] = k;
                mat.p_cols[ii] = j;
                ii++;
                
            }

        }

    }
    
    return mat;

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
double* c_oti_num2mat(otinum_t* num, uint64_t size, directionHelper* p_dH){
    /*
    void c_oti_num2mat(otinum_t* num, uint64_t size, directionHelper* p_dH)

    Obtain the dense matrix representation of the oti number num.

    INPUTS:

        ->num:    Address of the number to be created. 

        ->size:    Size of the matrix (can be different to the num.Ndir).

        -> p_dH:   List of helpers

    OUTPUTS:

        The operation gives a double* such that it contains the matrix form of the oti number.

        The shape of the matrix is (size x size)

    */ 
    // ************************************************************************************************
    uint64_t i,j,k,Ndir = num->Ndir;
    double * mat;   // matrix pointer
    uint8_t error,order = num->order;

    
    // Allocate memory to hold the results:
    mat = (double*)malloc(size*size*sizeof(double));
    if (mat == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }
    
    // Initialize in zero.
    memset(mat, 0, size*size*sizeof(double));
    

    for( i = 0; i < Ndir; i++){

        for( j = 0; j < size; j++){
            
            k = c_helper_multIndxFast( i, j, order, p_dH, &error);

            
            if (k>size){
                
                break;

            }

            if (error == 0){

                mat[k*size+j] = num->p_coefs[i];
                
            }

        }

    }
    
    return mat;

}    
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_oti_mulf(otinum_t* num1, double num2, otinum_t* res){
    /*
    void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

    multiply an oti number times a real coefficient.

    INPUTS:

        ->num1:    Address of one operand. 
                                                Both must have the same order.
        ->num2:    Address of the other operand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions. Cannot be the same address as num1.

        -> p_dH:   List of helpers

    OUTPUTS:

        The operation is equivalent to:

        - res = num1 * num2

    */ 
    // ************************************************************************************************
    uint64_t i;
    
    // Initialize the result holder.
    if (res->p_coefs!=num1->p_coefs){
        
        memcpy(res->p_coefs,num1->p_coefs,res->Ndir*sizeof(double));
            
    }
    

    for( i = 0; i < res->Ndir; i++){
        
        res->p_coefs[i]*=num2;
    }
    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH){
    /*
    void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH)

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
    uint64_t i, j, indx;
    uint8_t err=1, order = num1->order;
    
    // Initialize in zeros the result holder.
    for( i = 0; i < res->Ndir;  i++ ){

        res->p_coefs[i] = 0.0;

    }

    for( i = 0; i < num1->Ndir; i++){
        
        for( j = 0; j < num2->Ndir; j++){

            // Multiply directions.

            indx = c_helper_multIndxFast(i,j,order,p_dH,&err);

            if (err == 0){   // If error flag is off

                res->p_coefs[indx] += num1->p_coefs[i] * num2->p_coefs[j];
            }

        }
                 
    }
    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void c_oti_free(otinum_t* numHolder){
    /*
    c_freeOti(numHolder)

    Frees an allocated oti number

    INPUTS:

        ->numHolder:    Address of the number to be freed.
        

    */ 
    // ************************************************************************************************

    if (numHolder->p_coefs != NULL){

        free(numHolder->p_coefs); 

    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_createEmpty(otinum_t* numHolder,   uint64_t ndir, uint8_t order){
    /*
    c_oti_createEmpty(numHolder, ndir, order)

    C-level memory allocation of a dense oti number a direction array from a file

    INPUTS:

        ->numHolder:    Address of the number to be allocated.
        
        ->    order:    Order to be loaded in memory.
            Example: 3

        ->     ndir:    Number of directions of the number.
            Example: 100

    OUTPUTS:
        -> The result is the numHolder with the memory allocated.
    */ 
    // ************************************************************************************************
    numHolder->p_coefs = (double*)malloc(ndir*sizeof(double));
    if (numHolder->p_coefs == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }
    numHolder->Ndir  = ndir;
    numHolder->order = order;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_changeOrderToNew(otinum_t* num, uint8_t neword, directionHelper* p_dH , otinum_t* res){
    /*
    c_otiChangeOrder(num1, neword, p_dH)
    
    Change the order of num to neword without changing the original number.
    

    INPUTS:

        ->num:      Address of the number to be changedOrder. 
                                                
        ->neword:   New Order.

        ->p_dH:     Address of the helper stack. 
    
    OUTPUTS:

        The operation will replace the data in num.

    */ 
    // ************************************************************************************************

    uint16_t* oldDirA;
    uint16_t* newDirA;
    uint8_t*  oldExpA;
    uint8_t*  newExpA;
    uint64_t newIndx;
    uint64_t m_max, newSizeOfCoefs;
    uint64_t i,k, Ndir = num->Ndir;
    uint8_t j, order = num->order;
    double*  newCoefs;


    if (neword != order){

        m_max = c_helper_findMaxDir(Ndir-1,order,p_dH);
        newSizeOfCoefs = c_helper_getNels(m_max,neword,p_dH);
        newCoefs = (double*)malloc(newSizeOfCoefs*sizeof(double));

        if (neword>order){

            
            // WARNING: THE VALUES IN COEFS HAVE NOT BEEN INITIALIZED!!!
            k=0;


            newDirA = c_helper_getUDirA(neword,0,p_dH);
            newExpA = c_helper_getUExpA(neword,0,p_dH);

            for (i = 0; i < Ndir; i++ ){

                oldDirA = c_helper_getDirA(i,order,p_dH);
                oldExpA = c_helper_getExpA(i,order,p_dH);
                
                 

                // Fill the values of new DirA
                memcpy(newDirA,oldDirA,order*sizeof(double));            
                memcpy(newExpA,oldExpA,order*sizeof(double));

                // Fill the rest with zeros
                for (j=order; j<neword;j++){
                    
                    newDirA[j] = 0;
                    newExpA[j] = 0;

                }

                newIndx = c_helper_findIndex(newDirA,newExpA,neword,p_dH);
                newCoefs[newIndx] = num->p_coefs[i];

                
                if (k != newIndx){
                    // Set all the values between the last value placed and newIndx -> 0.0

                    for (;k<newIndx;k++){

                        newCoefs[k] = 0.0;

                    }

                    // k leaves this loop with the same value as newIndx.
                    

                }

                k++;


                
            }

            // Set all other numbers to zero.

            for (;k<newSizeOfCoefs;k++){
                newCoefs[k] = 0.0;
            }


            
            res->p_coefs = newCoefs;
            res->order = neword;
            res->Ndir = newSizeOfCoefs;

        } else {  // neworder<order

            oldDirA = c_helper_getUDirA( order, 0, p_dH);
            oldExpA = c_helper_getUExpA( order, 0, p_dH); 

            for (i = 0; i < newSizeOfCoefs; i++ ){

                newDirA = c_helper_getDirA(i, neword, p_dH);
                newExpA = c_helper_getExpA(i, neword, p_dH);

                memcpy( oldDirA, newDirA, neword*sizeof(double));            
                memcpy( oldExpA, newExpA, neword*sizeof(double));

                // Fill the rest with zeros
                for (j=neword; j<order;j++){
                    
                    oldDirA[j] = 0;
                    oldExpA[j] = 0;

                }

                newIndx = c_helper_findIndex(oldDirA,oldExpA,order,p_dH);
                newCoefs[i] = num->p_coefs[newIndx];
                
                
            }


            num->p_coefs = newCoefs;
            num->order = neword;
            num->Ndir = newSizeOfCoefs;

        }

    }


}


void c_oti_changeOrder(otinum_t* num, uint8_t neword, directionHelper* p_dH ){
    /*
    c_otiChangeOrder(num1, neword, p_dH)
    
    Change the order of num to neword.
    

    INPUTS:

        ->num:      Address of the number to be changedOrder. 
                                                
        ->neword:   New Order.

        ->p_dH:     Address of the helper stack. 
    
    OUTPUTS:

        The operation will replace the data in num.

    */ 
    // ************************************************************************************************

    uint16_t* oldDirA;
    uint16_t* newDirA;
    uint8_t*  oldExpA;
    uint8_t*  newExpA;
    uint64_t newIndx;
    uint64_t m_max, newSizeOfCoefs;
    uint64_t i,k, Ndir = num->Ndir;
    uint8_t j, order = num->order;
    double*  newCoefs;


    if (neword != order){

        m_max = c_helper_findMaxDir(Ndir-1,order,p_dH);
        newSizeOfCoefs = c_helper_getNels(m_max,neword,p_dH);


        if (neword>order){

            newCoefs = (double*)malloc(newSizeOfCoefs*sizeof(double));
            // WARNING: THE VALUES IN COEFS HAVE NOT BEEN INITIALIZED!!!
            k=0;


            newDirA = c_helper_getUDirA(neword,0,p_dH);
            newExpA = c_helper_getUExpA(neword,0,p_dH);

            for (i = 0; i < Ndir; i++ ){

                oldDirA = c_helper_getDirA(i,order,p_dH);
                oldExpA = c_helper_getExpA(i,order,p_dH);
                
                 

                // Fill the values of new DirA
                memcpy(newDirA,oldDirA,order*sizeof(double));            
                memcpy(newExpA,oldExpA,order*sizeof(double));

                // Fill the rest with zeros
                for (j=order; j<neword;j++){
                    
                    newDirA[j] = 0;
                    newExpA[j] = 0;

                }

                newIndx = c_helper_findIndex(newDirA,newExpA,neword,p_dH);
                newCoefs[newIndx] = num->p_coefs[i];

                
                if (k != newIndx){
                    // Set all the values between the last value placed and newIndx -> 0.0

                    for (;k<newIndx;k++){

                        newCoefs[k] = 0.0;

                    }

                    // k leaves this loop with the same value as newIndx.
                    

                }

                k++;


                
            }

            // Set all other numbers to zero.

            for (;k<newSizeOfCoefs;k++){
                newCoefs[k] = 0.0;
            }


            free(num->p_coefs);
            num->p_coefs = newCoefs;
            num->order = neword;
            num->Ndir = newSizeOfCoefs;

        } else {  // neworder<order

            oldDirA = c_helper_getUDirA( order, 0, p_dH);
            oldExpA = c_helper_getUExpA( order, 0, p_dH); 

            for (i = 0; i < newSizeOfCoefs; i++ ){

                newDirA = c_helper_getDirA(i, neword, p_dH);
                newExpA = c_helper_getExpA(i, neword, p_dH);

                memcpy( oldDirA, newDirA, neword*sizeof(double));            
                memcpy( oldExpA, newExpA, neword*sizeof(double));

                // Fill the rest with zeros
                for (j=neword; j<order;j++){
                    
                    oldDirA[j] = 0;
                    oldExpA[j] = 0;

                }

                newIndx = c_helper_findIndex(oldDirA,oldExpA,order,p_dH);
                num->p_coefs[i] = num->p_coefs[newIndx];
                
                
            }

            // Realloc to new size.
            num->p_coefs = (double* )realloc(num->p_coefs,newSizeOfCoefs*sizeof(double));
            num->order = neword;
            num->Ndir = newSizeOfCoefs;

        }

    }


}



// ****************************************************************************************************
void c_oti_e(double real,uint16_t basis, uint8_t order, uint16_t nbasis, 
            directionHelper* p_dH, otinum_t* res){
    /*
    void c_oti_e(double real,uint16_t basis, uint8_t order, otinum_t* res)

    Create an oti number with real coefficient "real" and with unitary perturbation in imaginary 
    direction "basis".

    INPUTS:

        -> double real:     Real coefficient.

        -> uint16_t basis:  Number that represents the imaginary direction to hold the perturbation.

        -> uint8_t order:   Order of the OTI number desired

        -> uint16_t nbasis: Number of basis(determines the size of the oti number).
        
        -> directionHelper* p_dH: 

        -> otinum_t* res:   Pointer to the oti number result. Must not come allocated!
    
    OUTPUTS:

        The operation allocates memory and sets the corresponding values of the oti number.

    */ 
    // ************************************************************************************************
    


    

}    
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline void c_oti_sumf(otinum_t* num1, double other){
    /*
    void c_oti_sumf(otinum_t* num1, otinum_t* num2, otinum_t* res)

    Sum an oti number with a float (double).

    INPUTS:

        ->num1:    Address of the summand. 
                                                Both must have the same order.
        ->num2:    Address of the summand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions.

    OUTPUTS:

        The operation is equivalent to:

        res = num1 + num2

    */ 
    // ************************************************************************************************
    

    num1->p_coefs[0] += other;

}    
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res){
    /*
    void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res)

    Sum two oti numbers

    INPUTS:

        ->num1:    Address of the summand. 
                                                Both must have the same order.
        ->num2:    Address of the summand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions.

    OUTPUTS:

        The operation is equivalent to:

        res = num1 + num2

    */ 
    // ************************************************************************************************


    // c_minUI64(num1->Ndir, num2->Ndir, &minNdir,&maxNdir);


    for(uint64_t i = 0; i< res->Ndir; i++){
        
        if( i < num1->Ndir){
            
            res->p_coefs[i] = num1->p_coefs[i];

        }else{
            
            res->p_coefs[i] = 0.0;

        }

        if( i < num2->Ndir){
            
            res->p_coefs[i] += num2->p_coefs[i];

        }

    }
    

}    
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_oti_sub(otinum_t* num1, otinum_t* num2, otinum_t* res){
    /*
    void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res)

    Subtract two oti numbers

    INPUTS:

        ->num1:    Address of the summand. 
                                                Both must have the same order.
        ->num2:    Address of the summand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions.

    OUTPUTS:

        The operation is equivalent to:

        res = num1 - num2

    */ 
    // ************************************************************************************************


    // c_minUI64(num1->Ndir, num2->Ndir, &minNdir,&maxNdir);


    for(uint64_t i = 0; i< res->Ndir; i++){
        
        if( i < num1->Ndir){
            
            res->p_coefs[i] = num1->p_coefs[i];

        }else{
            
            res->p_coefs[i] = 0.0;

        }

        if( i < num2->Ndir){
            
            res->p_coefs[i] -= num2->p_coefs[i];

        }

    }
    

}    
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_oti_neg(otinum_t* num1){
    /*
    void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res)

    Sum two oti numbers

    INPUTS:

        ->num1:    Address of the summand. 
                                                Both must have the same order.
        ->num2:    Address of the summand.

        ->res:     Address of the result holder. Must come allocated with the maximum number of 
                   directions.

    OUTPUTS:

        The operation is equivalent to:

        - num1 

    */ 
    // ************************************************************************************************


    for(uint64_t i = 0; i< num1->Ndir; i++){
        
        num1->p_coefs[i] *= -1.0;
                 
    }
    

}    
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
inline void c_oti_copy(otinum_t* numDest, otinum_t* numSrc){
    /*
    void c_oti_copy(otinum_t* numDest, otinum_t* numSrc)

    Copies the information from numSrc to numDest

    INPUTS:

        ->numHolder:    Address of the number to be freed.

    */ 
    // ************************************************************************************************

    numDest->p_coefs = (double*)malloc(numSrc->Ndir*sizeof(double));
    
    if (numDest->p_coefs == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    memcpy(numDest->p_coefs ,numSrc->p_coefs ,numSrc->Ndir*sizeof(double));
    numDest->Ndir  = numSrc->Ndir;
    numDest->order = numSrc->order;
}    
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
// -------------------------------     END OTINUM FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------



