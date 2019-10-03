// Take a look at: sympy.geometry.util.idiff

// ****************************************************************************************************
void der_r_pow(coeff_t x0, coeff_t exponent, ord_t order, coeff_t* derivs){

    ord_t i;
    coeff_t base = x0;
    coeff_t factor = 1.0;

    derivs[0] = factor*pow(base,exponent);

    for(i=1;i<=order;i++){
        
        factor = factor*exponent;
        exponent = exponent - 1.0;

        derivs[i] = factor*pow(base,exponent);
        
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_sqrt(coeff_t x0, ord_t order, coeff_t* derivs){

    coeff_t exponent = 1.0/2.0;
    der_r_pow(x0, exponent, order, derivs);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_cbrt(coeff_t x0, ord_t order, coeff_t* derivs){


    coeff_t exponent = 1.0/3.0;
    der_r_pow(x0, exponent, order, derivs);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_sin(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    coeff_t sx = sin(x0);
    coeff_t cx = cos(x0);
    int factor;
    
    derivs[0] = sx;

    // Compute odd derivatives.
    factor = 1;
    for(i=1;i<=order; i=i+2){
        
        derivs[i] = factor*cx;
        factor    = -factor; //  Change sign of factor.
        
    }

    // Compute even derivatives.
    factor = -1;
    for(i=2;i<=order;i=i+2){
        
        derivs[i] = factor*sx;
        factor    = -factor; //  Change sign of factor.
        
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_cos(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    coeff_t sx = sin(x0);
    coeff_t cx = cos(x0);
    int factor;
    
    derivs[0] = cx;

    // Compute odd derivatives.
    factor = -1;
    for(i=1;i<=order; i=i+2){
        
        derivs[i] = factor*sx;
        factor = -factor;
        
    }

    // Compute even derivatives.
    factor = -1;
    for(i=2;i<=order;i=i+2){
        
        derivs[i] = factor*cx;
        factor = -factor;
        
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_log(coeff_t x0, ord_t order, coeff_t* derivs){

    derivs[0]=log(x0);

    if( order >=1 ){

        // Perform as if f(x0) = 1/x0. for the next derivatives.
        der_r_pow(x0, -1.0, order-1, &derivs[1]);

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_logb(coeff_t x0, coeff_t base, ord_t order, coeff_t* derivs){

    ord_t i;
    der_r_log(x0, order, derivs);
    coeff_t log_base = log(base);

    for( i=1; i<=order; i++ ){

        derivs[i] = derivs[i]/log_base;

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_exp(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    coeff_t expx = exp(x0);

    derivs[0] = expx;

    for(i=1;i<=order;i++){

        derivs[i] = expx;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_expb(coeff_t x0, coeff_t base, ord_t order, coeff_t* derivs){

    ord_t i;
    coeff_t b_power_x = pow(base,x);
    coeff_t logb   = log(base);
    coeff_t factor = 1.0;

    derivs[0] = b_power_x;

    for(i=1;i<=order;i++){
        
        factor = factor*logb;
        derivs[i] = b_power_x*factor;
        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_sinh(coeff_t x0, ord_t order, coeff_t* derivs){

    ord_t i;
    coeff_t shx = sinh(x);
    coeff_t chx = cosh(x);
    
    // Even derivatives.
    for(i=0;i<=order;i=i+2){
        derivs[i]=shx;
    }

    // Odd derivatives.
    for(i=1;i<=order;i=i+2){
        derivs[i]=chx;
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void der_r_cosh(coeff_t x0, ord_t order, coeff_t* derivs){

    
    ord_t i;
    coeff_t shx = sinh(x);
    coeff_t chx = cosh(x);
    
    // Even derivatives.
    for(i=0;i<=order;i=i+2){
        derivs[i]=chx;
    }
    
    // Odd derivatives.
    for(i=1;i<=order;i=i+2){
        derivs[i]=shx;
    }

}
// ----------------------------------------------------------------------------------------------------
