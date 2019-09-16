// This file contains the "to" functions: Functions made to support dense oti operations 
// where a result holder has already been allocated. 



// void oti_sum_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
// void oti_sum_real_to(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl);
// void oti_neg_to(otinum_t* num1, otinum_t* res, dhelpl_t dhl);
// void oti_sub_otireal_to(otinum_t* num1, coeff_t a, otinum_t* res, dhelpl_t dhl);
// void oti_sub_realoti_to(coeff_t a, otinum_t* num2, dhelpl_t dhl);
// void oti_sub_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
// void oti_mul_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
// void oti_mul_real(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl);
// void oti_div_otireal_to(otinum_t* num, coeff_t den, otinum_t* res, dhelpl_t dhl );
// void oti_div_realoti_to(coeff_t num, otinum_t* den, otinum_t* res, dhelpl_t dhl );
// void oti_div_to(otinum_t* num, otinum_t* den, otinum_t* res, dhelpl_t dhl );
// void oti_feval_to(coeff_t* feval_re, otinum_t* num, otinum_t* res, dhelpl_t dhl );



// Algebra operations:



// Addition

// ****************************************************************************************************
void oti_sum_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl){

    ord_t ordi;
    ndir_t i;
    bases_t nbases = MAX(num1->nbases,num2->nbases);
    ord_t    order = MAX(num1->order, num2->order);
    coeff_t *p_res, *p_num;

    oti_setup( res,  nbases, order, dhl ); // Setup the p_ndpo values and ndir to corresponding values.
    oti_setFromReal(0.0, res, dhl); // Set all elements in res as 0.0.
    oti_copy_to( num1, res, dhl);
    
    // TODO: Add check of general memory allocation requirements.
    
    res->re += num2->re;

    for ( ordi = 0; ordi < num2->order; ordi++){

        p_res = res->p_im[ordi];
        p_num = num2->p_im[ordi];

        for (i=0; i < num2->p_ndpo[ordi]; i++){
            
            p_res[i] += p_num[i];

        }

    }


}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void oti_sum_ro_to(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl){

    // Setup the p_ndpo values and ndir to corresponding values.
    oti_setup( res,  num1->nbases, num1->order, dhl ); 

    oti_copy_to(num1, res, dhl);
    
    res->re += a;

}
// ----------------------------------------------------------------------------------------------------
















// Negation

// ****************************************************************************************************
void oti_neg_to(otinum_t* num1, otinum_t* res, dhelpl_t dhl){

    ord_t ordi;
    ndir_t i;
    
    // Setup the p_ndpo values and ndir to corresponding values.
    oti_setup( res,  num1->nbases, num1->order, dhl ); 
    oti_copy_to( num1, res, dhl);
    
    // Self neg....
    res->re *= -1;


    for ( ordi = 0; ordi < res->order; ordi++){

        for ( i=0; i < res->p_ndpo[ordi]; i++){
            
            res->p_im[ordi][i] *= -1;

        }

    }


}
// ----------------------------------------------------------------------------------------------------

















// Subtraction

// ****************************************************************************************************
void oti_sub_or_to(otinum_t* num1, coeff_t a, otinum_t* res, dhelpl_t dhl){
    
    // Setup the p_ndpo values and ndir to corresponding values.
    oti_setup( res,  num1->nbases, num1->order, dhl ); 
    oti_copy_to(num1,res,dhl);;
    
    res->re -= a;

}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_sub_ro_to(coeff_t a, otinum_t* num2, otinum_t* res, dhelpl_t dhl){
    
    oti_neg_to(num2,res,dhl);
    
    res->re += a;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void oti_sub_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl){


    ord_t ordi;
    ndir_t i;
    bases_t nbases = MAX(num1->nbases,num2->nbases);
    ord_t    order = MAX(num1->order, num2->order);
    coeff_t *p_res, *p_num;

    oti_setup( res,  nbases, order, dhl ); // Setup the p_ndpo values and ndir to corresponding values.
    oti_setFromReal(0.0, res, dhl); // Set all elements in res as 0.0.
    oti_copy_to( num1, res, dhl);
    
    res->re -= num2->re;

    for ( ordi = 0; ordi < num2->order; ordi++){

        p_res = res->p_im[ordi];
        p_num = num2->p_im[ordi];

        for (i=0; i < num2->p_ndpo[ordi]; i++){
            
            p_res[i] -= p_num[i];

        }

    }

}
// ----------------------------------------------------------------------------------------------------























// Multiplication


// ****************************************************************************************************
void oti_mul_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl){

    // The resulting order is given by the minimum between adding the two orders from the inputs
    // and the global truncation order
    ord_t    order_result = MIN( num1->order+num2->order, dhl.order[0]);
    bases_t nbases_result = MAX( num1->nbases,            num2->nbases);

    // Assummes memory already allocated.
    oti_setup(res, nbases_result, order_result, dhl );
    oti_setFromReal(0.0,res,dhl);

    ord_t ord_res ;
    ord_t ord_mul1, ord_mul2;


    //  0 X 0
    res->re = num1->re * num2->re;
    // printf("Order num1 %hhu\n", num1->order);
    // printf("Order num2 %hhu\n", num2->order);
    // printf("Order res  %hhu\n", res->order);
    
    // Multiply num1.re times all imaginary directions from num2 (until resulting order is achieved)
    for (ord_res = 1; ord_res<= MIN( res->order, num2->order); ord_res++){

        // printf()
        // First multiply  re x ord_res        
        dhelp_dense_mult_real(num2->p_im[ord_res-1],num2->p_ndpo[ord_res-1],
            num1->re,
            res->p_im[ord_res-1],res->p_ndpo[ord_res-1],
            dhl);

    }

    // Multiply num2.re times all imaginary directions from num1 (until resulting order is achieved)
    for (ord_res = 1; ord_res<= MIN( res->order, num1->order); ord_res++){

         // Then multiply   ord_res x re
        dhelp_dense_mult_real(num1->p_im[ord_res-1],num1->p_ndpo[ord_res-1],
            num2->re,
            res->p_im[ord_res-1],res->p_ndpo[ord_res-1],
            dhl);

    }

    // Multiply imaginary directions.
    for ( ord_mul1 = 1; ord_mul1 <= MIN(res->order,num1->order); ord_mul1++){
        // printf("Multiplying orders\n ");
        for ( ord_mul2 = 1; ord_mul2 <= MIN(res->order-ord_mul1, num2->order) ; ord_mul2++){

            ord_res = ord_mul1 + ord_mul2;  

            // printf("%hhu x %hhu \n", ord_mul1, ord_mul2);

            dhelp_dense_mult( num1->p_im[ord_mul1-1], num1->p_ndpo[ord_mul1-1], ord_mul1, 
                              num2->p_im[ord_mul2-1], num2->p_ndpo[ord_mul2-1], ord_mul2,
                              res->p_im[ord_res-1],    res->p_ndpo[ord_res-1],
                              dhl);

        }
        

    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void oti_mul_ro_to(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl){

    ord_t ordi;
    ndir_t i;
    
    oti_setup( res,  num1->nbases, num1->order, dhl );     
    oti_copy_to( num1, res, dhl);
    
    res->re *= a;

    for (  ordi = 0; ordi < res->order; ordi++){

        for ( i=0; i<res->p_ndpo[ordi]; i++){
            
            res->p_im[ordi][i] *= a;

        }

    }

}
// ----------------------------------------------------------------------------------------------------













// Division

// ****************************************************************************************************
void oti_div_or_to(otinum_t* num, coeff_t den, otinum_t* res, dhelpl_t dhl ){

    oti_mul_ro_to(1.0/den, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_div_ro_to(coeff_t num, otinum_t* den, otinum_t* res, dhelpl_t dhl ){
    
    otinum_t tmp1 = oti_get_rtmp( 0, den->order, den->nbases, dhl);

    oti_pow_to(den , -1.0, &tmp1, dhl);
    
    oti_mul_ro_to(num, &tmp1, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_div_oo_to(otinum_t* num, otinum_t* den, otinum_t* res, dhelpl_t dhl ){
    
    ord_t i;

    coeff_t y = num->re, x = den->re;
    coeff_t deriv_x, deriv_y;

    oti_setFromReal( 0.0, res, dhl);

    otinum_t tmp1 = oti_get_rtmp( 0, num->order, num->nbases, dhl);
    otinum_t tmp2 = oti_get_rtmp( 1, num->order, num->nbases, dhl);
    otinum_t tmp3 = oti_get_rtmp( 2, num->order, num->nbases, dhl);

    oti_copy_to( den, &tmp2, dhl); // x
    oti_copy_to( num, &tmp3, dhl); // y
    
    // Set real value of result.
    res->re = y/x;
    deriv_x = y/x;

    for ( i = 1; i<=num->order; i++){
    
        
        // do the part for y.
        deriv_y = deriv_x / y ;
        oti_copy_to( &tmp3 , &tmp1 , dhl);
        oti_trunc_smul_real( deriv_y, i, &tmp3, dhl); 
        oti_trunc_ssum( &tmp3, i, res, dhl );

        if (1 != num->order ){

            oti_setFromReal( 0.0, &tmp3, dhl);
            oti_trunc_mul(&tmp1, i, den, 1, &tmp3, dhl );
            // oti_copy_to(&tmp3, &tmp1, dhl);

        }
        
        // do the part for x.
        deriv_x = -deriv_x / x ;
        oti_copy_to( &tmp2 , &tmp1 , dhl); 
        oti_trunc_smul_real( deriv_x, i, &tmp2, dhl); 
        oti_trunc_ssum( &tmp2, i, res, dhl );

        if (1 != num->order ){

            oti_setFromReal( 0.0, &tmp2, dhl);
            oti_trunc_mul(&tmp1, i, den, 1, &tmp2, dhl );
            // oti_copy_to(&tmp2 , &tmp1, dhl);

        }

    }

}
// ----------------------------------------------------------------------------------------------------












// Function Evaluation.

// ****************************************************************************************************
void oti_feval_to(coeff_t* feval_re, otinum_t* num, otinum_t* res, dhelpl_t dhl ){
    
    ord_t i;

    coeff_t factor = 1.0, val = 0.0;

    oti_setFromReal( 0.0, res, dhl);
    
    otinum_t tmp1 = oti_get_rtmp( 0, num->order, num->nbases, dhl);
    otinum_t tmp2 = oti_get_rtmp( 1, num->order, num->nbases, dhl);


    oti_copy_to( num, &tmp2, dhl);
    
    // Set real value of result.
    res->re = feval_re[0];

    for ( i = 1; i < num->order; i++){

        factor *= i;

        val = feval_re[i]/factor;
        
        oti_copy_to(&tmp2 , &tmp1, dhl);
        oti_trunc_smul_real( val, i, &tmp2, dhl);
        oti_trunc_ssum( &tmp2, i, res, dhl );
        
        // update
        // if (i != num->order ){
        oti_setFromReal( 0.0, &tmp2, dhl);
        oti_trunc_mul(&tmp1, i, num, 1, &tmp2, dhl );
        oti_copy_to(&tmp2 , &tmp1, dhl);
        // }

    }

    for (; i<=num->order; i++){

        factor *= i;

        val = feval_re[i]/factor;
        
        oti_copy_to(&tmp2 , &tmp1, dhl);
        oti_trunc_smul_real( val, i, &tmp2, dhl);
        oti_trunc_ssum( &tmp2, i, res, dhl );

    }

}
// ----------------------------------------------------------------------------------------------------










