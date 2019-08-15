





// ****************************************************************************************************
void oti_trunc_smul_real(coeff_t a, ord_t ord, otinum_t* res, dhelpl_t dhl){

    ord_t ordi;
    ndir_t i;  

    for ( ordi = ord-1; ordi < res->order; ordi++){

        for ( i=0; i<res->p_ndpo[ordi]; i++){
            
            res->p_im[ordi][i] *= a;

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_trunc_ssum(otinum_t* num1, 
                    ord_t ord, otinum_t* res, dhelpl_t dhl ){
    
    // Initialize
    ord_t ordi;
    ndir_t i; 

    for (  ordi = ord-1; ordi < res->order; ordi++){

        for ( i=0; i < res->p_ndpo[ordi]; i++){
            
            res->p_im[ordi][i] += num1->p_im[ordi][i];

        }

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_trunc_mul(otinum_t* num1, ord_t ord1, 
                   otinum_t* num2, ord_t ord2, 
                   otinum_t* res, dhelpl_t dhl ){
    
    ord_t ord_mul1, ord_mul2;
    // // Initialize
    // oti_setFromReal( 0.0, res, dhl);

    // printf("Finding combinations for order "_PORDT _ENDL, res->order);

    for ( ord_mul1 =ord1; ord_mul1 <= res->order; ord_mul1++){

        for ( ord_mul2 = res->order-ord_mul1; ord_mul2 >= ord2; ord_mul2--){

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
