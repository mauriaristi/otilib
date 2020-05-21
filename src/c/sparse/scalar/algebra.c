




// Algebraic operations:


// Negation

// ****************************************************************************************************
sotinum_t soti_neg(sotinum_t* num, dhelpl_t dhl){
    
    return soti_mul_ro(-1.0,num,dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_abs(sotinum_t* num, dhelpl_t dhl){
    
    sotinum_t res;

    res = soti_copy(num,dhl);

    soti_abs_to( num, &res ,dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------








// Addition.

// ****************************************************************************************************
sotinum_t soti_sum_oo(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t res, tmp;

    tmp = soti_base_sum( num1, num2, dhl);

    res = soti_copy(&tmp, dhl); // Newly allocated.

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sum_ro(coeff_t val, sotinum_t* num, dhelpl_t dhl){
    
    sotinum_t res = soti_copy(num,dhl);

    res.re += val;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline sotinum_t soti_base_sum(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t tmp;
    ord_t res_ord = MAX(num1->order,num2->order);
    ord_t ordi;

    // Create a sotinum with no elements in imaginary directions.
    tmp = soti_get_rtmp(7, res_ord, dhl);

    tmp.re = num1->re + num2->re; 

    // TODO: divide in three for loops
    // ord_t min_ord = MIN(num1->order,num2->order);
    // for(ordi=0; ordi<min_ord; ordi++){ 
    //     dhelp_sparse_add_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
    //                           num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
    //                           tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);
    // }

    // for(ordi=min_ord; ordi< num1->order; ordi++){ 
    //     dhelp_sparse_add_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
    //                           NULL, NULL, 0,
    //                           tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);
    // }

    // for(ordi=min_ord; ordi< num2->order; ordi++){ 
    //     dhelp_sparse_add_dirs(num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
    //                           NULL, NULL, 0,
    //                           tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);    
    // }
    
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











// Subtraction.


// ****************************************************************************************************
sotinum_t soti_sub_oo(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t res, tmp;

    tmp = soti_base_sub( num1, num2, dhl);

    res = soti_copy(&tmp, dhl); // Newly allocated.

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sub_ro( coeff_t val, sotinum_t* num, dhelpl_t dhl){

    sotinum_t res = soti_neg(num,dhl);
    
    res.re += val;

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sub_or(sotinum_t* num, coeff_t val, dhelpl_t dhl){

    return soti_sum_ro(-val,num,dhl);
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











// Multiplication.

// ****************************************************************************************************
sotinum_t soti_mul_oo(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    
    sotinum_t res, tmp;

    tmp = soti_base_mul(num1,num2,dhl);

    res = soti_copy(&tmp, dhl); // Newly allocated.

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_mul_ro(coeff_t val, sotinum_t* num, dhelpl_t dhl){
    
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
inline sotinum_t soti_base_mul(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t tmp, tmp2, tmp3;

    sotinum_t* tmpsrc  = &tmp ;
    sotinum_t* tmpdest = &tmp3;
    sotinum_t* tmpswap;
    ord_t res_ord = MAX(num1->order,num2->order);
    ord_t ordlim1, ordlim2;
    ord_t ordi1, ordi2,ordires;

    // Retreive sotinum temporals.
    // All tmps are created with no elements in imaginary directions (but fully allocated).
    tmp = soti_get_rtmp(3,res_ord,dhl); // will hold the final result.
    tmp2= soti_get_rtmp(4,res_ord,dhl); // Will hold the temporary result.
    tmp3= soti_get_rtmp(5,res_ord,dhl); // Will hold the temporary result.

    // Multiply real coefficients.
    tmpdest->re = num1->re * num2->re;

    // Set source with the same real value.
    tmpsrc->re  = tmpdest->re;

    // printf("Multiplying lhs(ord:%hhu) by rhs(ord:%hhu)\n",num1->order,num2->order);
    // printf("Multiply lhs.re:%g x im of rhs ========= \n", num1->re);
    // soti_print(num2,dhl);

    if (num1->re != 0.0 && num2->order > 0 ){
        
        // Swap pointers
        tmpswap = tmpsrc; 
        tmpsrc  = tmpdest; 
        tmpdest = tmpswap;

        for (ordi1 = 0; ordi1<num2->order; ordi1++){

            // Perform multiplication
            dhelp_sparse_mult_real(num1->re,
                               num2->p_im[ordi1], num2->p_idx[ordi1], num2->p_nnz[ordi1],
                                tmp2.p_im[ordi1],  tmp2.p_idx[ordi1], &tmp2.p_nnz[ordi1],       
                               dhl);              

            dhelp_sparse_add_dirs(    tmp2.p_im[ordi1],     tmp2.p_idx[ordi1],      tmp2.p_nnz[ordi1],
                                   tmpsrc->p_im[ordi1],  tmpsrc->p_idx[ordi1],   tmpsrc->p_nnz[ordi1],
                                  tmpdest->p_im[ordi1], tmpdest->p_idx[ordi1], &tmpdest->p_nnz[ordi1], dhl);

        }
        
        // printf("\n -- \n");
        // soti_print(tmpdest,dhl);

    }
    
    // printf("\n\nMultiply rhs.re:%g x im of lhs =========  \n", num2->re);
    // soti_print(num1,dhl);


    if (num2->re != 0.0 && num1->order > 0 ){

        // Swap pointers
        tmpswap = tmpsrc; 
        tmpsrc  = tmpdest; 
        tmpdest = tmpswap;

        for (ordi1 = 0; ordi1<num1->order; ordi1++){

            // Perform multiplication
            dhelp_sparse_mult_real(num2->re,
                               num1->p_im[ordi1], num1->p_idx[ordi1],  num1->p_nnz[ordi1],
                                tmp2.p_im[ordi1],  tmp2.p_idx[ordi1],  &tmp2.p_nnz[ordi1],       
                               dhl);  

            dhelp_sparse_add_dirs(    tmp2.p_im[ordi1],     tmp2.p_idx[ordi1],      tmp2.p_nnz[ordi1],
                                   tmpsrc->p_im[ordi1],  tmpsrc->p_idx[ordi1],   tmpsrc->p_nnz[ordi1],
                                  tmpdest->p_im[ordi1], tmpdest->p_idx[ordi1], &tmpdest->p_nnz[ordi1], dhl);

        }
        // printf("\n -- \n");
        // soti_print(tmpdest,dhl);

    }
    
    if ( num1->order > 0 && num2->order > 0 ){
        

        // Start with both temporals with the same values.
        soti_copy_nomemchk_to(tmpdest,tmpsrc,dhl);
        
        // Assign order 1 elements to src.
        tmpsrc->p_im[0]  = tmpdest->p_im[0] ;
        tmpsrc->p_idx[0] = tmpdest->p_idx[0];
        tmpsrc->p_nnz[0] = tmpdest->p_nnz[0];  
        
        

        ordlim1 = MIN( num1->order, res_ord - 1 );
        
        for(ordi1=0; ordi1<ordlim1; ordi1++){

            ordlim2 = MIN( num2->order, res_ord - (ordi1+1) );

            tmpswap = tmpsrc; 
            tmpsrc  = tmpdest; 
            tmpdest = tmpswap;

            // Multiply elements of order ordi1 times all elements of order 
            for (ordi2=0; ordi2<ordlim2; ordi2++){

                ordires = ordi1 + ordi2 +1;

                dhelp_sparse_mult( num1->p_im[ordi1],   num1->p_idx[ordi1],    num1->p_nnz[ordi1],  ordi1+1,
                                   num2->p_im[ordi2],   num2->p_idx[ordi2],    num2->p_nnz[ordi2],  ordi2+1,
                                    tmp2.p_im[ordires],  tmp2.p_idx[ordires],  &tmp2.p_nnz[ordires],         dhl);

                dhelp_sparse_add_dirs(    tmp2.p_im[ordires],     tmp2.p_idx[ordires],      tmp2.p_nnz[ordires],
                                       tmpsrc->p_im[ordires],  tmpsrc->p_idx[ordires],   tmpsrc->p_nnz[ordires],
                                      tmpdest->p_im[ordires], tmpdest->p_idx[ordires], &tmpdest->p_nnz[ordires], dhl);

            }
            ordires = ordi1+1;
            
            tmpsrc->p_im[ ordires] = tmpdest->p_im[ ordires];
            tmpsrc->p_idx[ordires] = tmpdest->p_idx[ordires];
            tmpsrc->p_nnz[ordires] = tmpdest->p_nnz[ordires];

            // printf("\n -- \n");
            // printf("     Multiplying lhs(ord:%hhu) x rhs\n",ordi1+1);
            // soti_print(tmpdest,dhl);

        }

        // printf("\n -- \n");
        // soti_print(tmpdest,dhl);
    
    }
    
    // This returns whatever temporal is selected at this time.
    return *tmpdest;

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
    tmp = soti_get_rtmp(3,res_ord,dhl); // will hold the final result.
    tmp2= soti_get_rtmp(4,res_ord,dhl); // Will hold the temporary result.
    tmp3= soti_get_rtmp(5,res_ord,dhl); // Will hold the temporary result.
    

    // Multiply real coefficients.
    tmpdest->re = num1->re * num2->re;
    tmpsrc->re  = tmpdest->re;

    // printf("Multiplying order %hhu x %hhu\n", num1->order, num2->order);

    for( order = 1; order<=res_ord; order++){

        ordi = order - 1;

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







































// Division.

// ****************************************************************************************************
sotinum_t soti_div_ro(coeff_t num, sotinum_t* den, dhelpl_t dhl){

    
    sotinum_t inv = soti_pow(den,-1,dhl);
    sotinum_t res = soti_mul_ro(num,&inv,dhl);

    soti_free(&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_div_oo(sotinum_t* num, sotinum_t* den, dhelpl_t dhl){

    
    sotinum_t inv = soti_get_rtmp(7,den->order,dhl);
    soti_pow_to(den,-1,&inv,dhl);
    sotinum_t res = soti_mul_oo(num,&inv,dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_div_or(sotinum_t* num, coeff_t val, dhelpl_t dhl){

    return soti_mul_ro(1.0/val,num,dhl);

}
// ----------------------------------------------------------------------------------------------------




























// Function evaluation.

// ****************************************************************************************************
inline sotinum_t soti_feval(coeff_t* feval_re, sotinum_t* num, dhelpl_t dhl ){
    
    
    sotinum_t res;
    sotinum_t tmp = soti_base_feval(feval_re, num, dhl);
    
    // copy ....
    res = soti_copy( &tmp, dhl); // Newly allocated.

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline sotinum_t soti_base_feval(coeff_t* feval_re, sotinum_t* num, dhelpl_t dhl ){
    
    ord_t i ;

    coeff_t factor = 1.0, val = 0.0;

    sotinum_t tmp1 = soti_get_rtmp( 7,num->order,dhl);
    sotinum_t tmp2 = soti_get_rtmp( 8,num->order,dhl);
    sotinum_t tmp3 = soti_get_rtmp( 9,num->order,dhl);

    soti_set_o( num, &tmp2, dhl);

    for ( i = 1; i < num->order; i++){
        
        factor *= i;

        val = feval_re[i]/factor;
        
        soti_set_o(&tmp2 , &tmp1, dhl);
        soti_trunc_smul_real( val, i, &tmp2, dhl);
        soti_trunc_ssum( &tmp2, i, &tmp3, dhl );
        
        // update
        soti_set_r( 0.0, &tmp2, dhl);
        soti_trunc_mul(&tmp1, i, num, 1, &tmp2, dhl );

    }

    for (; i<=num->order; i++){
        
        factor *= i;
        val = feval_re[i]/factor;        
        soti_set_o(&tmp2 , &tmp1, dhl);
        soti_trunc_smul_real( val, i, &tmp2, dhl);
        soti_trunc_ssum( &tmp2, i, &tmp3, dhl );

    }

    // Set real value.
    tmp3.re = feval_re[0];
    
    return tmp3;

}
// ----------------------------------------------------------------------------------------------------
