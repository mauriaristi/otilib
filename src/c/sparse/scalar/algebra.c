




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
sotinum_t soti_sum_or(sotinum_t* num, coeff_t val, dhelpl_t dhl){
    
    return soti_sum_ro(val, num, dhl);

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
    ord_t res_ord = MAX(num1->trc_order,num2->trc_order);
    ord_t ordi;

    // Create a sotinum with no elements in imaginary directions.
    tmp = soti_get_rtmp(7, res_ord, dhl);

    tmp.re = num1->re + num2->re; 

    res_ord = MAX(num1->act_order,num2->act_order);
    tmp.act_order = res_ord;

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
        
        if (ordi < num1->act_order && ordi < num2->act_order){
            
            dhelp_sparse_add_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
                                  num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);

        } else if (ordi < num1->act_order){

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
    ord_t res_ord = MAX(num1->trc_order,num2->trc_order);
    ord_t ordi;

    tmp = soti_get_rtmp(7,res_ord,dhl); // creates a sotinum with no elements in imaginary directions.

    tmp.re = num1->re - num2->re;

    res_ord = MAX(num1->act_order,num2->act_order);
    tmp.act_order = res_ord;

    for(ordi = 0; ordi < res_ord; ordi++){

        
        if (ordi < num1->act_order && ordi < num2->act_order){
            
            dhelp_sparse_sub_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
                                  num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);

        } else if (ordi < num1->act_order){

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
sotinum_t soti_mul_or(sotinum_t* num, coeff_t val, dhelpl_t dhl){

    return soti_mul_ro(val, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_mul_ro(coeff_t val, sotinum_t* num, dhelpl_t dhl){
    
    ord_t i;
    ndir_t j;

    sotinum_t res = soti_copy(num,dhl);

    res.re *= val;

    for ( i=0; i<res.act_order; i++){
        
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
    coeff_t*   p_im_swap;
    imdir_t*  p_idx_swap;
    ndir_t    p_nnz_swap;
    ord_t res_ord = MAX(num1->trc_order,num2->trc_order);
    ord_t ordlim1, ordlim2;
    ord_t ordi1, ordi2,ordires;

    // #pragma omp critical 
    // {
    // printf("INFO: In multiplication: thread_id %d\n",omp_get_thread_num());
    
    // Retreive sotinum temporals.
    // All tmps are created with no elements in imaginary directions (but fully allocated).
    tmp = soti_get_rtmp(3,res_ord,dhl); // will hold the final result.
    tmp2= soti_get_rtmp(4,res_ord,dhl); // Will hold the temporary result.
    tmp3= soti_get_rtmp(5,res_ord,dhl); // Will hold the temporary result.
    
    // }

    // Multiply real coefficients.
    tmpdest->re = num1->re * num2->re;

    // Set source with the same real value.
    tmpsrc->re  = tmpdest->re;

    // Estimate the resulting order (Maximum order from operations)
    res_ord = MIN(tmp.trc_order,num1->act_order+num2->act_order);

    tmp.act_order =res_ord;
    tmp2.act_order=res_ord;
    tmp3.act_order=res_ord;

    // printf("Multiplying lhs(ord:%hhu) by rhs(ord:%hhu)\n",num1->order,num2->order);
    // printf("Multiply lhs.re:%g x im of rhs ========= \n", num1->re);
    // soti_print(num2,dhl);

    if (num1->re != 0.0 && num2->act_order > 0 ){
        
        // Swap pointers
        tmpswap = tmpsrc; 
        tmpsrc  = tmpdest; 
        tmpdest = tmpswap;

        for (ordi1 = 0; ordi1<num2->act_order; ordi1++){

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
    
    // printf("\n//////////////////////////////////////\n");
    // printf("\nMultiply rhs.re:%g x im of lhs =========  \n", num2->re);
    // soti_print(num1,dhl);


    if (num2->re != 0.0 && num1->act_order > 0 ){

        // Swap pointers
        tmpswap = tmpsrc; 
        tmpsrc  = tmpdest; 
        tmpdest = tmpswap;

        for (ordi1 = 0; ordi1<num1->act_order; ordi1++){

            // Perform multiplication
            dhelp_sparse_mult_real(num2->re,
                               num1->p_im[ordi1], num1->p_idx[ordi1],  num1->p_nnz[ordi1],
                                tmp2.p_im[ordi1],  tmp2.p_idx[ordi1],  &tmp2.p_nnz[ordi1],       
                               dhl);  

            dhelp_sparse_add_dirs(    tmp2.p_im[ordi1],     tmp2.p_idx[ordi1],      tmp2.p_nnz[ordi1],
                                   tmpsrc->p_im[ordi1],  tmpsrc->p_idx[ordi1],   tmpsrc->p_nnz[ordi1],
                                  tmpdest->p_im[ordi1], tmpdest->p_idx[ordi1], &tmpdest->p_nnz[ordi1], dhl);

        }

        for (ordi2 = ordi1; ordi2<res_ord; ordi2++){

            // // Perform multiplication
            // dhelp_sparse_add_dirs(                NULL,                  NULL,                      0,
            //                        tmpsrc->p_im[ordi2],  tmpsrc->p_idx[ordi2],   tmpsrc->p_nnz[ordi2],
            //                       tmpdest->p_im[ordi2], tmpdest->p_idx[ordi2], &tmpdest->p_nnz[ordi2], dhl);

            // // Swap 

            p_im_swap  = tmpsrc->p_im[ordi2] ;
            p_idx_swap = tmpsrc->p_idx[ordi2];
            p_nnz_swap = tmpsrc->p_nnz[ordi2];

            tmpsrc->p_im[ordi2]  = tmpdest->p_im[ordi2] ;
            tmpsrc->p_idx[ordi2] = tmpdest->p_idx[ordi2];
            tmpsrc->p_nnz[ordi2] = tmpdest->p_nnz[ordi2];

            tmpdest->p_im[ordi2]  = p_im_swap ;
            tmpdest->p_idx[ordi2] = p_idx_swap;
            tmpdest->p_nnz[ordi2] = p_nnz_swap;

        }
        // printf("\n -- \n");
        // soti_print(tmpdest,dhl);

    }
    
    if ( num1->act_order > 0 && num2->act_order > 0 ){
        

        // Start with both temporals with the same values.
        soti_copy_nomemchk_to(tmpdest,tmpsrc,dhl);
        
        // Assign order 1 elements to src.
        tmpsrc->p_im[0]  = tmpdest->p_im[0] ;
        tmpsrc->p_idx[0] = tmpdest->p_idx[0];
        tmpsrc->p_nnz[0] = tmpdest->p_nnz[0];  
        
        

        ordlim1 = MIN( num1->act_order, res_ord - 1 );
        
        for(ordi1=0; ordi1<ordlim1; ordi1++){

            ordlim2 = MIN( num2->act_order, res_ord - (ordi1+1) );

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
    
    // printf("INFO: Finished multiplication, thread_id %d\n",omp_get_thread_num());
    
    // This returns whatever temporal is selected at this time.
    return *tmpdest;

}
// ----------------------------------------------------------------------------------------------------












// ****************************************************************************************************
sotinum_t soti_mul_old(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    // WARNING: This function was implemented before the order_split conversion.
    // Therefore, this function does not comply to this specification.
    // If you want to use it again, please you will have to adapt it to the 
    // trc_order / act_order convention
    

    sotinum_t res, tmp, tmp2, tmp3;
    sotinum_t* tmpsrc= &tmp ;
    sotinum_t* tmpdest=&tmp3;
    sotinum_t* tmpswap;
    ord_t res_ord = MAX(num1->trc_order,num2->trc_order);
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
        if ( order <= num2->act_order && num1->re != 0.0){
            
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
        if ( order <= num1->act_order && num2->re != 0.0){
            
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

            if ( ord_mul1 <= num1->act_order && ord_mul2 <= num2->act_order){
                
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
                
                if ( ord_mul2 <= num1->act_order && ord_mul1 <= num2->act_order){
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















// ****************************************************************************************************
inline sotinum_t soti_base_trunc_sum(ord_t ord, sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t tmp;
    ord_t res_ord = MAX(num1->trc_order,num2->trc_order);
    ord_t ordi;

    // Create a sotinum with no elements in imaginary directions.
    tmp = soti_get_rtmp(7, res_ord, dhl);

    soti_set_r(0.0, &tmp, dhl);
    res_ord = MAX(num1->act_order,num2->act_order);
    tmp.act_order = res_ord;

    if (ord == 0){
    
        tmp.re = num1->re + num2->re; 
    
    } else {

        ordi = ord - 1;

        if ( ordi < num1->act_order && ordi < num2->act_order ){
            
            dhelp_sparse_add_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
                                  num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);

        } else if ( ordi < num1->act_order ){

            dhelp_sparse_add_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
                                  NULL, NULL, 0,
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);

        } else if ( ordi < num2->act_order ){

            dhelp_sparse_add_dirs(num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
                                  NULL, NULL, 0,
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);            

        }

    }
    

    return tmp;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline sotinum_t soti_base_trunc_sub(ord_t ord, sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t tmp;
    ord_t res_ord = MAX(num1->trc_order,num2->trc_order);
    ord_t ordi;

    // Create a sotinum with no elements in imaginary directions.
    tmp = soti_get_rtmp(7, res_ord, dhl);

    soti_set_r(0.0, &tmp, dhl);
    res_ord = MAX(num1->act_order,num2->act_order);
    tmp.act_order = res_ord;

    if (ord == 0){
    
        tmp.re = num1->re - num2->re; 
    
    } else {

        ordi = ord - 1;

        if ( ordi < num1->act_order && ordi < num2->act_order ){
            
            dhelp_sparse_sub_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
                                  num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);

        } else if ( ordi < num1->act_order ){

            dhelp_sparse_sub_dirs(num1->p_im[ordi], num1->p_idx[ordi], num1->p_nnz[ordi],
                                  NULL, NULL, 0,
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);

        } else if ( ordi < num2->act_order ){

            dhelp_sparse_sub_dirs(NULL, NULL, 0,
                                  num2->p_im[ordi], num2->p_idx[ordi], num2->p_nnz[ordi],                                  
                                  tmp.p_im[ordi], tmp.p_idx[ordi], &tmp.p_nnz[ordi], dhl);            

        }

    }
    

    return tmp;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline sotinum_t soti_base_trunc_mul(ord_t ord1, sotinum_t* num1, ord_t ord2, sotinum_t* num2, dhelpl_t dhl){

    sotinum_t tmp, tmp2, tmp3;

    sotinum_t* tmpsrc  = &tmp ;
    sotinum_t* tmpdest = &tmp3;
    sotinum_t* tmpswap;
    ord_t res_ord = MAX(num1->trc_order,num2->trc_order);
    
    ord_t ordi1, ordi2, ordires;

    // Retreive sotinum temporals.
    // All tmps are created with no elements in imaginary directions (but fully allocated).
    tmp = soti_get_rtmp(3,res_ord,dhl); // will hold the final result.
    tmp2= soti_get_rtmp(4,res_ord,dhl); // Will hold the temporary result.
    tmp3= soti_get_rtmp(5,res_ord,dhl); // Will hold the temporary result.

    // Multiply real coefficients.
    soti_set_r(0.0,  tmpsrc, dhl);
    soti_set_r(0.0, tmpdest, dhl);
    soti_set_r(0.0,   &tmp2, dhl);

    res_ord = MIN(res_ord,ord1+ord2);
    tmp.act_order =res_ord;
    tmp2.act_order=res_ord;
    tmp3.act_order=res_ord;




    // printf("In soti_base_trunc_mul lhs:"_PORDT",rhs"_PORDT"\n", ord1, ord2);
    // printf("num1:\n");
    // soti_print(num1,dhl);
    // printf("num2:\n");
    // soti_print(num2,dhl);

    // printf("TMP2 previously:\n");
    // soti_print(&tmp2,dhl);

    if (ord1 == 0 && ord2 == 0){
        
        tmpdest->re = num1->re * num2->re;

    } else if (ord1 == 0) {

        if (num1->re != 0.0 && num2->act_order >= ord2 ){
        
            // Swap pointers
            tmpswap = tmpsrc; 
            tmpsrc  = tmpdest; 
            tmpdest = tmpswap;

            ordi1 = ord2-1;
            // Perform multiplication
            dhelp_sparse_mult_real(num1->re,
                               num2->p_im[ordi1], num2->p_idx[ordi1], num2->p_nnz[ordi1],
                                tmp2.p_im[ordi1],  tmp2.p_idx[ordi1], &tmp2.p_nnz[ordi1],       
                               dhl);              

            dhelp_sparse_add_dirs(    tmp2.p_im[ordi1],     tmp2.p_idx[ordi1],      tmp2.p_nnz[ordi1],
                                   tmpsrc->p_im[ordi1],  tmpsrc->p_idx[ordi1],   tmpsrc->p_nnz[ordi1],
                                  tmpdest->p_im[ordi1], tmpdest->p_idx[ordi1], &tmpdest->p_nnz[ordi1], dhl);



        }

    } else if (ord2 == 0) {

        if (num2->re != 0.0 && num1->act_order >= ord1 ){

            // Swap pointers
            tmpswap = tmpsrc; 
            tmpsrc  = tmpdest; 
            tmpdest = tmpswap;

            ordi1 = ord1-1;
        
            dhelp_sparse_mult_real(num2->re,
                                   num1->p_im[ordi1], num1->p_idx[ordi1],  num1->p_nnz[ordi1],
                                   tmp2.p_im[ordi1],  tmp2.p_idx[ordi1],  &tmp2.p_nnz[ordi1],       
                                   dhl);  

            dhelp_sparse_add_dirs(    tmp2.p_im[ordi1],     tmp2.p_idx[ordi1],      tmp2.p_nnz[ordi1],
                                   tmpsrc->p_im[ordi1],  tmpsrc->p_idx[ordi1],   tmpsrc->p_nnz[ordi1],
                                  tmpdest->p_im[ordi1], tmpdest->p_idx[ordi1], &tmpdest->p_nnz[ordi1], dhl);
            
        }

    } else {

        if ( num1->act_order >= ord1 && num2->act_order >= ord2 ){
        
            // ord_t ordlim1 = MIN( num1->act_order, res_ord - 1 );
            ordi1 = ord1-1;
            ordi2 = ord2-1;    

            ordires = ordi1 + ordi2 + 1;
            if (ordires < res_ord){
                // printf("Here!1\n");
                // printf("ord1: "_PORDT" ord2: "_PORDT" ord3: "_PORDT"\n",ord1,ord2,ordires+1);
                dhelp_sparse_mult( num1->p_im[ordi1],   num1->p_idx[ordi1],    num1->p_nnz[ordi1],  ordi1+1,
                                   num2->p_im[ordi2],   num2->p_idx[ordi2],    num2->p_nnz[ordi2],  ordi2+1,
                                    tmp2.p_im[ordires],  tmp2.p_idx[ordires],  &tmp2.p_nnz[ordires],         dhl);
    
                // printf("Here!2\n");
                // soti_print(&tmp2,dhl);
                dhelp_sparse_add_dirs(    tmp2.p_im[ordires],     tmp2.p_idx[ordires],      tmp2.p_nnz[ordires],
                                       tmpsrc->p_im[ordires],  tmpsrc->p_idx[ordires],   tmpsrc->p_nnz[ordires],
                                      tmpdest->p_im[ordires], tmpdest->p_idx[ordires], &tmpdest->p_nnz[ordires], dhl);
    
                // printf("Here!3\n");
            }
            
        }

    }

    // This returns whatever temporal is selected at this time.
    return *tmpdest;

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

    
    sotinum_t inv = soti_get_rtmp(7,den->trc_order,dhl);
    soti_pow_to(den,-1.0, &inv,dhl);
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
inline sotinum_t soti_feval(coeff_t* feval_re, sotinum_t* num , dhelpl_t dhl){
    
    
    sotinum_t res;
    sotinum_t tmp = soti_base_feval(feval_re, num, dhl);
    
    // copy ....
    res = soti_copy( &tmp, dhl); // Newly allocated.

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline sotinum_t soti_base_feval(coeff_t* feval_re, sotinum_t* num , dhelpl_t dhl){
    
    ord_t i ;

    coeff_t factor = 1.0, val = 0.0;

    sotinum_t tmp1 = soti_get_rtmp( 7,num->trc_order,dhl);
    sotinum_t tmp2 = soti_get_rtmp( 8,num->trc_order,dhl);
    sotinum_t tmp3 = soti_get_rtmp( 9,num->trc_order,dhl);

    soti_set_o( num, &tmp2, dhl);
    
    for ( i = 1; i < num->trc_order; i++){
        
        factor *= i;

        val = feval_re[i]/factor;

        // tmp2 = tmp1
        soti_set_o(&tmp2 , &tmp1, dhl);
        
        // tmp2 = tmp2 * val
        soti_trunc_smul_real( val, i, &tmp2, dhl);
        
        // tmp3 += tmp2;
        soti_trunc_ssum( &tmp2, i, &tmp3, dhl );

        
        // update
        soti_set_r( 0.0, &tmp2, dhl);
        soti_trunc_mul(&tmp1, i, num, 1, &tmp2, dhl );

    }

    for (; i <= num->trc_order; i++){
        
        factor *= i;
        val = feval_re[i]/factor;        

        // tmp1 = tmp2;
        soti_set_o(&tmp2 , &tmp1, dhl);

        // tmp2 = tmp2 * val;
        soti_trunc_smul_real( val, i, &tmp2, dhl);

        // tmp3 += tmp2;
        soti_trunc_ssum( &tmp2, i, &tmp3, dhl );

    }

    // Set real value.
    tmp3.re = feval_re[0];
    
    return tmp3;

}
// ----------------------------------------------------------------------------------------------------
