


// Algebra operations:

// Addition

// ****************************************************************************************************
otinum_t oti_sum_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl){

    // This function supports different nbases and order operation.
    bases_t nbases = MAX(num1->nbases,num2->nbases);
    ord_t    order = MAX(num1->order, num2->order);

    otinum_t res = oti_createEmpty( nbases, order, dhl); 

    oti_sum_oo_to(num1, num2, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
otinum_t oti_sum_ro(coeff_t a, otinum_t* num1, dhelpl_t dhl){

    otinum_t res = oti_copy(num1, dhl);
    // preserve inital 
    
    res.re += a;

    return res;

}
// ----------------------------------------------------------------------------------------------------



// Negation

// ****************************************************************************************************
otinum_t oti_neg(otinum_t* num1, dhelpl_t dhl){

    ord_t ordi;
    ndir_t i;

    otinum_t res = oti_copy( num1, dhl);
    
    res.re *= -1;

    for (  ordi = 0; ordi < res.order; ordi++){

        for ( i=0; i < res.p_ndpo[ordi]; i++){
            
            res.p_im[ordi][i] *= -1;

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

















// Subtraction

// ****************************************************************************************************
otinum_t oti_sub_or(otinum_t* num1, coeff_t a, dhelpl_t dhl){
    
    otinum_t res = oti_copy(num1,dhl);;
    res.re -= a;
    return res;

}   
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sub_ro(coeff_t a, otinum_t* num2, dhelpl_t dhl){
    
    otinum_t res = oti_neg(num2,dhl);;
    res.re += a;
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sub_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl){

    // This function supports different nbases and order operation.
    bases_t nbases = MAX(num1->nbases,num2->nbases);
    ord_t    order = MAX(num1->order, num2->order);

    otinum_t res = oti_createEmpty( nbases, order, dhl);

    oti_sub_oo_to(num1, num2, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------























// Multiplication


// ****************************************************************************************************
otinum_t oti_mul_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl){

    // The resulting order is given by the minimum between adding the two orders from the inputs
    // and the global truncation order
    ord_t    order_result = MIN( num1->order+num2->order, dhl.order[0]);
    bases_t nbases_result = MAX( num1->nbases,            num2->nbases);

    otinum_t res = oti_createEmpty( nbases_result, order_result, dhl);
    // ord_t ord_res ;
    // ord_t ord_mul1, ord_mul2;

    oti_mul_oo_to(num1, num2, &res, dhl);
    // //  0 X 0
    // res.re = num1->re * num2->re;
    // // printf("Order num1 %hhu\n", num1->order);
    // // printf("Order num2 %hhu\n", num2->order);
    // // printf("Order res  %hhu\n", res.order);
    
    // // Multiply num1.re times all imaginary directions from num2 (until resulting order is achieved)
    // for (ord_res = 1; ord_res<= MIN( res.order, num2->order); ord_res++){

    //     // printf()
    //     // First multiply  re x ord_res        
    //     dhelp_dense_mult_real(num2->p_im[ord_res-1],num2->p_ndpo[ord_res-1],
    //         num1->re,
    //         res.p_im[ord_res-1],res.p_ndpo[ord_res-1],
    //         dhl);

    // }

    // // Multiply num2.re times all imaginary directions from num1 (until resulting order is achieved)
    // for (ord_res = 1; ord_res<= MIN( res.order, num1->order); ord_res++){

    //      // Then multiply   ord_res x re
    //     dhelp_dense_mult_real(num1->p_im[ord_res-1],num1->p_ndpo[ord_res-1],
    //         num2->re,
    //         res.p_im[ord_res-1],res.p_ndpo[ord_res-1],
    //         dhl);

    // }

    // // Multiply imaginary directions.
    // for ( ord_mul1 = 1; ord_mul1 <= MIN(res.order,num1->order); ord_mul1++){
    //     // printf("Multiplying orders\n ");
    //     for ( ord_mul2 = 1; ord_mul2 <= MIN(res.order-ord_mul1, num2->order) ; ord_mul2++){

    //         ord_res = ord_mul1 + ord_mul2;  

    //         // printf("%hhu x %hhu \n", ord_mul1, ord_mul2);

    //         dhelp_dense_mult( num1->p_im[ord_mul1-1], num1->p_ndpo[ord_mul1-1], ord_mul1, 
    //                           num2->p_im[ord_mul2-1], num2->p_ndpo[ord_mul2-1], ord_mul2,
    //                           res.p_im[ord_res-1],    res.p_ndpo[ord_res-1],
    //                           dhl);

    //     }
        

    // }

    return res;

}
// ----------------------------------------------------------------------------------------------------




// // ****************************************************************************************************
// otinum_t oti_mul_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl){

//     otinum_t res = oti_createZero( nbases_result, order_result, dhl);
//     ord_t ord_res ;
//     ord_t ord_mul1, ord_mul2;

//     //  0 X 0
//     res.re = num1->re * num2->re;

//     // Iterate over the orders 
//     for (  ord_res = 1; ord_res <= res.order; ord_res++){


//         // First multiply  re x ord_res        
//         dhelp_dense_mult_real(num2->p_im[ord_res-1],num2->p_ndpo[ord_res-1],
//             num1->re,
//             res.p_im[ord_res-1],res.p_ndpo[ord_res-1],
//             dhl);

//         // Then multiply   ord_res x re
//         dhelp_dense_mult_real(num1->p_im[ord_res-1],num1->p_ndpo[ord_res-1],
//             num2->re,
//             res.p_im[ord_res-1],res.p_ndpo[ord_res-1],
//             dhl);



//         for ( ord_mul1 = 1; ord_mul1 <= ord_res/2; ord_mul1++){

//             ord_t ord_mul2 = ord_res - ord_mul1;
//             // printf("Multiplying %hhu X %hhu\n",ord_mul1,ord_mul2);

//             dhelp_dense_mult( num1->p_im[ord_mul1-1], num1->p_ndpo[ord_mul1-1], ord_mul1, 
//                       num2->p_im[ord_mul2-1], num2->p_ndpo[ord_mul2-1], ord_mul2,
//                       res.p_im[ord_res-1], res.p_ndpo[ord_res]-1,
//                       dhl);

//             if (ord_mul1 != ord_mul2){
                
//                 // printf("Multiplying %hhu X %hhu\n",ord_mul2,ord_mul1);                

//                 dhelp_dense_mult( num1->p_im[ord_mul2-1], num1->p_ndpo[ord_mul2-1], ord_mul2, 
//                           num2->p_im[ord_mul1-1], num2->p_ndpo[ord_mul1-1], ord_mul1,
//                           res.p_im[ord_res-1], res.p_ndpo[ord_res]-1,
//                           dhl);

//             }  

//         }
        

//     }

//     return res;

// }
// // ----------------------------------------------------------------------------------------------------








// ****************************************************************************************************
otinum_t oti_mul_ro(coeff_t a, otinum_t* num1, dhelpl_t dhl){

    ord_t ordi;
    ndir_t i;
    otinum_t res = oti_copy( num1, dhl);
    
    res.re *= a;

    for (  ordi = 0; ordi < res.order; ordi++){

        for ( i=0; i<res.p_ndpo[ordi]; i++){
            
            res.p_im[ordi][i] *= a;

        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------
































// Division

// ****************************************************************************************************
otinum_t oti_div_or(otinum_t* num, coeff_t den, dhelpl_t dhl ){

    return oti_mul_ro(1.0/den, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_div_ro(coeff_t num, otinum_t* den, dhelpl_t dhl ){
    otinum_t tmp1 = oti_pow(den , -1.0, dhl);
    otinum_t res = oti_mul_ro(num, &tmp1, dhl);
    oti_free(&tmp1);
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_div_oo(otinum_t* num, otinum_t* den, dhelpl_t dhl ){
    
    ord_t i;

    coeff_t y = num->re, x = den->re;
    coeff_t deriv_x, deriv_y;
    otinum_t res  = oti_createZero( num->nbases, num->order, dhl);

    otinum_t tmp1 = oti_get_rtmp( 0, num->order, num->nbases, dhl);
    otinum_t tmp2 = oti_get_rtmp( 1, num->order, num->nbases, dhl);
    otinum_t tmp3 = oti_get_rtmp( 2, num->order, num->nbases, dhl);

    oti_copy_to( den, &tmp2, dhl); // x
    oti_copy_to( num, &tmp3, dhl); // y
    
    // Set real value of result.
    res.re = y/x;
    deriv_x = y/x;

    // if (num->order >= 1){

    for ( i = 1; i<=num->order; i++){
    
        
        // do the part for y.
        deriv_y = deriv_x / y ;
        oti_copy_to( &tmp3 , &tmp1 , dhl);
        oti_trunc_smul_real( deriv_y, i, &tmp3, dhl); 
        oti_trunc_ssum( &tmp3, i, &res, dhl );

        if (1 != num->order ){

            oti_setFromReal( 0.0, &tmp3, dhl);
            oti_trunc_mul(&tmp1, i, den, 1, &tmp3, dhl );
            // oti_copy_to(&tmp3, &tmp1, dhl);

        }
        
        // do the part for x.
        deriv_x = -deriv_x / x ;
        oti_copy_to( &tmp2 , &tmp1 , dhl); 
        oti_trunc_smul_real( deriv_x, i, &tmp2, dhl); 
        oti_trunc_ssum( &tmp2, i, &res, dhl );

        if (1 != num->order ){

            oti_setFromReal( 0.0, &tmp2, dhl);
            oti_trunc_mul(&tmp1, i, den, 1, &tmp2, dhl );
            // oti_copy_to(&tmp2 , &tmp1, dhl);

        }

    }

    
    
    // }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


















// Function Evaluation.

// ****************************************************************************************************
otinum_t oti_feval(coeff_t* feval_re, otinum_t* num, dhelpl_t dhl ){
    
    ord_t i;

    coeff_t factor = 1.0, val = 0.0;
    otinum_t res  = oti_createZero( num->nbases, num->order, dhl);
    // otinum_t tmp1 = oti_createZero( num->nbases, num->order, dhl);
    // otinum_t tmp2 = oti_createZero( num->nbases, num->order, dhl);
    otinum_t tmp1 = oti_get_rtmp( 0, num->order, num->nbases, dhl);
    otinum_t tmp2 = oti_get_rtmp( 1, num->order, num->nbases, dhl);


    oti_copy_to( num, &tmp2, dhl);
    
    // Set real value of result.
    res.re = feval_re[0];

    for ( i = 1; i < num->order; i++){

        factor *= i;

        val = feval_re[i]/factor;
        
        oti_copy_to(&tmp2 , &tmp1, dhl);
        oti_trunc_smul_real( val, i, &tmp2, dhl);
        oti_trunc_ssum( &tmp2, i, &res, dhl );
        
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
        oti_trunc_ssum( &tmp2, i, &res, dhl );

    }

    // oti_free(&tmp1); oti_free(&tmp2);

    return res;

}
// ----------------------------------------------------------------------------------------------------










