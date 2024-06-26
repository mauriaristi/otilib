



// ****************************************************************************************************
void der_c_atan2(zcoeff_t x, zcoeff_t y, ord_t order, zcoeff_t* derivs){
    
    zcoeff_t x0;
    uint8_t i;
    
    x0 = x/y;

    for( i=0; i<(order+1); i++){
    switch(i){
    case 0:
    derivs[0]=atan2(x,y);
    case 1:
    derivs[1]=1./(-pow(x0,2)+1);
    case 2:
    derivs[2]=2.*x0/pow(pow(x0,2)-1,2);
    case 3:
    derivs[3]=2.*(-4*pow(x0,2)/(pow(x0,2)-1)+1)/pow(pow(x0,2)-1,2);
    case 4:
    derivs[4]=24.*x0*(2*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,3);
    case 5:
    derivs[5]=
    24.*(-16.*pow(x0,4)/pow(pow(x0,2)-1,2)+12.*pow(x0,2)/(pow(x0,2)-1)-
        1)/pow(pow(x0,2)-1,3);
    case 6:
    derivs[6]=
    240.*x0*(16*pow(x0,4)/pow(pow(x0,2)-1,2)-16.*pow(x0,2)/(pow(x0,2)-1)+
        3)/pow(pow(x0,2)-1,4);
    case 7:
    derivs[7]=
    720.*(-64.*pow(x0,6)/pow(pow(x0,2)-1,3)+80.*pow(x0,4)/pow(pow(x0,2)-1,2)-
        24.*pow(x0,2)/(pow(x0,2)-1)+1)/pow(pow(x0,2)-1,4);
    case 8:
    derivs[8]=
    40320.*x0*(16.*pow(x0,6)/pow(pow(x0,2)-1,3)-24.*pow(x0,4)/pow(pow(x0,2)-1,2)+
        10.*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,5);
    case 9:
    derivs[9]=
    40320.*(-256.*pow(x0,8)/pow(pow(x0,2)-1,4)+448.*pow(x0,6)/pow(pow(x0,2)-1,3)-
        240.*pow(x0,4)/pow(pow(x0,2)-1,2)+40.*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,5);
    case 10:
    derivs[10]=
    725760.*x0*(256.*pow(x0,8)/pow(pow(x0,2)-1,4)-512.*pow(x0,6)/pow(pow(x0,2)-1,3)+
        336.*pow(x0,4)/pow(pow(x0,2)-1,2)-80.*pow(x0,2)/(pow(x0,2)-1)+5)/pow(pow(x0,2)-1,6);
    }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_logb(zcoeff_t x0, zcoeff_t base, ord_t order, zcoeff_t* derivs){
    
    uint8_t i;
    zcoeff_t lbase = log(base);

    for( i=0; i<(order+1); i++){    
        switch(i){
            case 0:
                derivs[0]  =  log(x0)/lbase;
            case 1:
                derivs[1]  =  1./(x0*lbase);
            case 2:
                derivs[2]  =  -1./(pow(x0, 2)*lbase);                
            case 3:
                derivs[3]  =  2./(pow(x0, 3)*lbase);                
            case 4:
                derivs[4]  =  -6./(pow(x0, 4)*lbase);                
            case 5:
                derivs[5]  =  24./(pow(x0, 5)*lbase);                
            case 6:
                derivs[6]  =  -120./(pow(x0, 6)*lbase);                            
            case 7:
                derivs[7]  =  720./(pow(x0, 7)*lbase);                
            case 8:
                derivs[8]  =  -5040./(pow(x0, 8)*lbase);                
            case 9:
                derivs[9]  =  40320./(pow(x0, 9)*lbase);                
            case 10:
                derivs[10] =  -362880./(pow(x0, 10)*lbase);                
        }     
    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void der_c_log10(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    uint8_t i;
    for( i=0; i<(order+1); i++){
        switch(i){
            case 0:
                derivs[0]  =  log(x0)/log(10.);
            case 1:
                derivs[1]  =  1./(x0*log(10.));
            case 2:
                derivs[2]  =  -1./(pow(x0,2)*log(10.));                
            case 3:
                derivs[3]  =  2./(pow(x0,3)*log(10.));                
            case 4:
                derivs[4]  =  -6./(pow(x0,4)*log(10.));                
            case 5:
                derivs[5]  =  24./(pow(x0,5)*log(10.));                
            case 6:
                derivs[6]  =  -120./(pow(x0,6)*log(10.));                            
            case 7:
                derivs[7]  =  720./(pow(x0,7)*log(10.));                
            case 8:
                derivs[8]  =  -5040./(pow(x0,8)*log(10.));                
            case 9:
                derivs[9]  =  40320./(pow(x0,9)*log(10.));                
            case 10:
                derivs[10] =  -362880./(pow(x0,10)*log(10.));                
        }
    }
  
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_atanh(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    uint8_t i;

    for( i=0; i<(order+1); i++){
    switch(i){
    case 0:
    derivs[0]=atanh(x0);
    case 1:
    derivs[1]=1./(-pow(x0,2)+1);
    case 2:
    derivs[2]=2.*x0/pow(pow(x0,2)-1,2);
    case 3:
    derivs[3]=2.*(-4*pow(x0,2)/(pow(x0,2)-1)+1)/pow(pow(x0,2)-1,2);
    case 4:
    derivs[4]=24.*x0*(2*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,3);
    case 5:
    derivs[5]=
    24.*(-16.*pow(x0,4)/pow(pow(x0,2)-1,2)+12.*pow(x0,2)/(pow(x0,2)-1)-
        1)/pow(pow(x0,2)-1,3);
    case 6:
    derivs[6]=
    240.*x0*(16*pow(x0,4)/pow(pow(x0,2)-1,2)-16.*pow(x0,2)/(pow(x0,2)-1)+
        3)/pow(pow(x0,2)-1,4);
    case 7:
    derivs[7]=
    720.*(-64.*pow(x0,6)/pow(pow(x0,2)-1,3)+80.*pow(x0,4)/pow(pow(x0,2)-1,2)-
        24.*pow(x0,2)/(pow(x0,2)-1)+1)/pow(pow(x0,2)-1,4);
    case 8:
    derivs[8]=
    40320.*x0*(16.*pow(x0,6)/pow(pow(x0,2)-1,3)-24.*pow(x0,4)/pow(pow(x0,2)-1,2)+
        10.*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,5);
    case 9:
    derivs[9]=
    40320.*(-256.*pow(x0,8)/pow(pow(x0,2)-1,4)+448.*pow(x0,6)/pow(pow(x0,2)-1,3)-
        240.*pow(x0,4)/pow(pow(x0,2)-1,2)+40.*pow(x0,2)/(pow(x0,2)-1)-1)/pow(pow(x0,2)-1,5);
    case 10:
    derivs[10]=
    725760.*x0*(256.*pow(x0,8)/pow(pow(x0,2)-1,4)-512.*pow(x0,6)/pow(pow(x0,2)-1,3)+
        336.*pow(x0,4)/pow(pow(x0,2)-1,2)-80.*pow(x0,2)/(pow(x0,2)-1)+5)/pow(pow(x0,2)-1,6);
    }     
    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void der_c_asinh(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    uint8_t i;

    for( i=0; i<(order+1); i++){    
    switch(i){
    case 0:
    derivs[0]  =  asinh(x0);
    case 1:
    derivs[1]  =  pow(pow(x0, 2) + 1., -1.0L/2.0L);
    case 2:
    derivs[2]  =  -x0/pow(pow(x0, 2) + 1., 3.0L/2.0L);                
    case 3:
    derivs[3]  =  (3.*pow(x0, 2)/(pow(x0, 2) + 1.) - 1.)/pow(pow(x0, 2.) + 1., 3.0L/2.0L);                
    case 4:
    derivs[4]  =  3.*x0*(-5.*pow(x0, 2)/(pow(x0, 2) + 1.) + 3.)/pow(pow(x0, 2.) + 1.,5.0L/2.0L);                
    case 5:
    derivs[5]  =  
    3.*(35.*pow(x0,4)/pow(pow(x0,2)+1,2)-30*pow(x0,2)/(pow(x0,2)+1)+3)/pow(pow(x0,2)+1,5.0L/2.0L);                
    case 6:
    derivs[6]  =  
    15*x0*(-63.*pow(x0,4)/pow(pow(x0,2)+1.,2)+70.*pow(x0,2)/(pow(x0,2)+1.)-15.)/pow(pow(x0,2)+1.,7.0L/2.0L);           
    case 7:
    derivs[7]  =  
    45.*(231.*pow(x0,6)/pow(pow(x0,2)+1,3)-315.*pow(x0,4)/pow(pow(x0,2)+1.,2)+
        105.*pow(x0,2)/(pow(x0,2)+1.)-5.)/pow(pow(x0,2)+1.,7.0L/2.0L);
    case 8:
    derivs[8]  =  
    315.*x0*(-429.*pow(x0,6)/pow(pow(x0,2)+1,3)+693.*pow(x0,4)/pow(pow(x0,2)+1.,2)-
        315.*pow(x0,2)/(pow(x0,2)+1.)+35.)/pow(pow(x0,2)+1.,9.0L/2.0L);    
    case 9:
    derivs[9]  =  
    315*(6435.*pow(x0,8)/pow(pow(x0,2)+1,4)-12012.*pow(x0,6)/pow(pow(x0,2)+1.,3)+
        6930.*pow(x0,4)/pow(pow(x0,2)+1,2)-1260.*pow(x0,2)/(pow(x0,2)+1)+35.)/pow(pow(x0,2)+1,9.0L/2.0L);    
    case 10:
    derivs[10] =  
    2835.*x0*(-12155.*pow(x0,8)/pow(pow(x0,2)+1.,4)+25740.*pow(x0,6)/pow(pow(x0,2)+1.,3)-
        18018.*pow(x0,4)/pow(pow(x0,2)+1.,2)+4620.*pow(x0,2)/(pow(x0,2)+1)-315.)/pow(pow(x0,2)+1.,11.0L/2.0L);
    }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_acosh(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    zcoeff_t x2m1 = pow(x0, 2.) - 1.;
    zcoeff_t sqx2m1 = pow(x2m1, 0.5);
    uint8_t i;

    for( i=0; i<(order+1); i++){
    
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

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_tanh(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    zcoeff_t tanhx0 = tanh(x0);
    zcoeff_t tanh2  = pow(tanhx0, 2); 
    zcoeff_t tanh2m1 = tanh2 - 1;
    uint8_t i;

    for( i=0; i<(order+1); i++){
    
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
    derivs[7]  =  -16.*(tanh2m1)*(17.*pow(tanh2m1, 3.) + 180.*pow(tanh2m1, 2.)*tanh2 + 
        114.*(tanh2m1)*pow(tanh(x0), 4.) + 4*pow(tanhx0, 6.));
    case 8:
    derivs[8]  =  128.*(tanh2m1)*(62.*pow(tanh2m1, 3.) + 192.*pow(tanh2m1, 2.)*tanh2 + 
        60.*(tanh2m1)*pow(tanh(x0), 4.) + pow(tanhx0, 6.))*tanhx0;
    case 9:
    derivs[9]  =  -128.*(tanh2m1)*(62.*pow(tanh2m1, 4.) + 1072.*pow(tanh2m1, 3.)*tanh2 + 
        1452.*pow(tanh2m1, 2.)*pow(tanhx0, 4.) + 247.*(tanh2m1)*pow(tanhx0, 6.) + 2.*pow(tanhx0, 8.));
    case 10:
    derivs[10] =  256.*(tanh2m1)*(1382.*pow(tanh2m1, 4.) + 7192.*pow(tanh2m1, 3.)*tanh2 + 
        5097.*pow(tanh2m1, 2.)*pow(tanhx0, 4.) + 502.*(tanh2m1)*pow(tanhx0, 6.) + 2.*pow(tanhx0, 8.))*tanhx0;
    }
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_sqrt(zcoeff_t x, ord_t order, zcoeff_t* derivs){
    
    der_c_pow( x, 0.5, order, derivs);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_cosh(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    zcoeff_t ch = cosh(x0);
    zcoeff_t sh = sinh(x0);
    uint8_t i;

    for( i=0; i<(order+1); i+=2){
        derivs[i] = ch;
    }

    for( i=1; i<(order+1); i+=2){
        derivs[i] = sh;
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_sinh(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    zcoeff_t ch = cosh(x0);
    zcoeff_t sh = sinh(x0);
    uint8_t i;

    for( i=0; i<(order+1); i+=2){
        derivs[i] = sh;
    }

    for( i=1; i<(order+1); i+=2){
        derivs[i] = ch;
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void der_c_asin(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    uint8_t i;

    for( i=0; i<(order+1); i++){
    
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
                derivs[5]  =  3.*(35.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 
                    30.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 3.)/pow(-pow(x0, 2.) + 1., 5.0/2.0);
                
            case 6:
                derivs[6]  = 15.*x0*(63.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 
                    70.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 15.)/pow(-pow(x0, 2.) + 1., 7.0/2.0);
                            
            case 7:
                derivs[7]  = 45.*(231.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 
                    315.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 105.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 
                    5.)/pow(-pow(x0, 2.) + 1., 7.0/2.0);
                
            case 8:
                derivs[8]  = 315.*x0*(429.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 
                    693.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 315.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 
                    35.)/pow(-pow(x0, 2.) + 1., 9.0/2.0);
                
            case 9:
                derivs[9]  = 315.*(6435.*pow(x0, 8.)/pow(-pow(x0, 2.) + 1., 4.) + 
                    12012.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 6930.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 
                    1260.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 35.)/pow(-pow(x0, 2.) + 1., 9.0/2.0);
                
            case 10:
                derivs[10] =2835.*x0*(12155.*pow(x0, 8.)/pow(-pow(x0, 2.) + 1., 4.) + 
                    25740.*pow(x0, 6.)/pow(-pow(x0, 2.) + 1., 3.) + 18018.*pow(x0, 4.)/pow(-pow(x0, 2.) + 1., 2.) + 
                    4620.*pow(x0, 2.)/(-pow(x0, 2.) + 1.) + 315.)/pow(-pow(x0, 2.) + 1., 11.0/2.0);
                

        }
     
    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void der_c_acos(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    uint8_t i;

    for( i=0; i<(order+1); i++){
    
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
                derivs[5]  =  -3.0*(35.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 
                    30.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 3.0)/pow(-pow(x0, 2.0) + 1.0, 5.0/2.0);
                
            case 6:
                derivs[6]  = -15.0*x0*(63.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 
                    70.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 15.0)/pow(-pow(x0, 2.0) + 1.0, 7.0/2.0);
                            
            case 7:
                derivs[7]  = -45.0*(231.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 
                    315.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 
                    105.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 5.0)/pow(-pow(x0, 2.0) + 1.0, 7.0/2.0);
                
            case 8:
                derivs[8]  = -315.0*x0*(429.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 
                    693.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 
                    315.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 35.0)/pow(-pow(x0, 2.0) + 1.0, 9.0/2.0);
                
            case 9:
                derivs[9]  = -315.0*(6435.0*pow(x0, 8.0)/pow(-pow(x0, 2.0) + 1.0, 4.0) + 
                    12012.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 
                    6930.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 
                    1260.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 35.0)/pow(-pow(x0, 2.0) + 1.0, 9.0/2.0);
                
            case 10:
                derivs[10] =-2835.0*x0*(12155.0*pow(x0, 8.0)/pow(-pow(x0, 2.0) + 1.0, 4.0) + 
                    25740.0*pow(x0, 6.0)/pow(-pow(x0, 2.0) + 1.0, 3.0) + 
                    8018.0*pow(x0, 4.0)/pow(-pow(x0, 2.0) + 1.0, 2.0) + 
                    4620.0*pow(x0, 2.0)/(-pow(x0, 2.0) + 1.0) + 315)/pow(-pow(x0, 2.0) + 1.0, 11.0/2.0);
                

        }
     
    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void der_c_atan(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    zcoeff_t x02   = pow(x0,2.0);
    zcoeff_t x02p1 = x02+1.0;
    uint8_t i;

    for( i=0; i<(order+1); i++){
    
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
                derivs[8] = 40320.0*x0*(-16.0*pow(x0,6.0)/pow(x02p1,3.0) + 24.0*pow(x0,4.0)/pow(x02p1,2.0) - 10.0*x02/(x02p1) + 1.0)/(pow(x02p1,5.0));
                // 40320*x1*(-16*x1**6/(x1**2 + 1)**3 + 24*x1**4/(x1**2 + 1)**2 - 10*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 9:
                derivs[9] = 40320.0*(256.0*pow(x0,8.0)/(pow(x02p1,4.0)) - 448.0*pow(x0,6.0)/(pow(x02p1,3.0)) + 240.0*pow(x0,4.0)/(pow(x02p1,2.0)) - 40.0*x02/x02p1 + 1.0)/(pow(x02p1,5.0));
                // 40320*(256*x1**8/(x1**2 + 1)**4 - 448*x1**6/(x1**2 + 1)**3 + 240*x1**4/(x1**2 + 1)**2 - 40*x1**2/(x1**2 + 1) + 1)/(x1**2 + 1)**5
            case 10:
                derivs[10] =725760.0*x0*(-256.0*pow(x0,8.0)/(pow(x02p1,4.0)) + 512.0*pow(x0,6.0)/(pow(x02p1,3.0)) - 336.0*pow(x0,4.0)/(pow(x02p1,2.0)) + 80.0*x02/x02p1 - 5.0)/(pow(x02p1,6.0));
                // 725760*x1*(-256*x1**8/(x1**2 + 1)**4 + 512*x1**6/(x1**2 + 1)**3 - 336*x1**4/(x1**2 + 1)**2 + 80*x1**2/(x1**2 + 1) - 5)/(x1**2 + 1)**6
        }
     
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_tan(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    zcoeff_t tanx0 = tan(x0);
    zcoeff_t tanx02p1 = pow(tanx0,2.0) + 1.0 ;
    uint8_t i;

    for( i=0; i<(order+1); i++){
    
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

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_cos(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    uint8_t i;
    uint8_t s = 0;
    zcoeff_t sign = 1.;
    
    for( i=0; i<(order+1); i++){
    
        if (s == 0){
        
            derivs[i]=sign*cos(x0);
        
        }else{
        
            sign = sign * (-1.0);
            derivs[i]=sign*sin(x0);
    
        }
    
        s = (s+1)%2;
     
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_sin(zcoeff_t x0, ord_t order, zcoeff_t* derivs){
    
    uint8_t i;
    uint8_t s = 1;
    zcoeff_t sign = -1.;
    
    for( i=0; i<(order+1); i++){
    
        if (s == 0){
        
            derivs[i]=sign*cos(x0);
        
        }else{
        
            sign = sign * (-1.0);
            derivs[i]=sign*sin(x0);
    
        }
    
        s = (s+1)%2;
     
    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void der_c_log(zcoeff_t x , ord_t order, zcoeff_t* derivs){
      
    zcoeff_t sign = -1.;
    zcoeff_t factor = 1.;
    uint8_t i;    

    derivs[0]=log(x); 

    for (i=1; i<(order+1); i++){    
                 
        derivs[i] = factor * pow(sign,(i+1)) * (1.0/pow(x,i) );
        factor    = factor * i;    
        
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_exp(zcoeff_t x,ord_t order, zcoeff_t* derivs){
    
    zcoeff_t value = exp(x);
    uint8_t i;    

    for (i=0; i<(order+1); i++){
        derivs[i]=value;
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_c_pow(zcoeff_t x, zcoeff_t e, ord_t order, zcoeff_t* derivs){
    
    zcoeff_t power_i = e;
    zcoeff_t x0 = x;
    uint8_t flag = 0;
    zcoeff_t factor = 1.;
    uint8_t i;
    
    for (i=0; i<(order+1); i++){
        if( power_i != 0.0){            
            derivs[i] = factor * pow(x0,power_i);
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
}
// ----------------------------------------------------------------------------------------------------

