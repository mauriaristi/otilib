
// ====================================================================================================
// ====================================================================================================
// =============================        TAYLOR INTEGRATOR FUNCTIONS       =============================
// ====================================================================================================
// ====================================================================================================

// ****************************************************************************************************
sotinum_t soti_taylor_integrate(coeff_t* deltas, sotinum_t* num, dhelpl_t dhl){
    
    
    sotinum_t res = soti_createEmpty( 0, dhl); 
    
    soti_taylor_integrate_to( deltas, num, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_taylor_integrate_to(coeff_t* deltas, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    
    ord_t   ordi;
    ndir_t  ndir_ordi, diri;
    coeff_t val = 0.0, delta;
    
    val = num->re;
    
    for(ordi = 0; ordi < num->order ; ordi++ ){

        // 
        ndir_ordi = num->p_nnz[ordi];

        for ( diri = 0; diri< ndir_ordi; diri++){ 
            
            delta  = dhelp_compute_delta( num->p_idx[ordi][diri], ordi + 1, deltas, dhl);
            val   += num->p_im[ordi][diri] * delta;

        }

    }
    
    soti_set_r(val,res,dhl);

}
// ----------------------------------------------------------------------------------------------------








// ****************************************************************************************************
sotinum_t soti_get_order_im( ord_t order, sotinum_t* num, dhelpl_t dhl){

    sotinum_t res = soti_createEmpty( 0, dhl);

    // Set imaginary direction.
    soti_get_order_im_to( order, num, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_get_order_im_to( ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    uint8_t reallocate = 0;

    // Copy real coefficient
    if (order == 0){
    
        soti_set_r(0.0,res,dhl);
        res->re = num->re;
    
    } else if (num->order < order ){
        
        soti_set_r(0.0,res,dhl);

    } else {

        // Check if reallocation is necessary
        if (res->order < order ){
            reallocate = 0xFF; // True
        } else {
            if ( num->p_nnz[order-1] > res->p_size[order-1] ){
                reallocate = 0xFF; // True
            }
        }

        // TODO: Add check to wheather dest has not been initialized.
        // TODO: Add case when the two elements have different orders.
        // TODO: Add check if dest is a tmp function.

        if( reallocate ){
            // Reallocation IS required.
            // Easiest way: Free current memory in dest and allocate new memory.
            if (res->flag != 0){
                soti_free(res);  
                (*res) = soti_createEmpty_like( num, dhl);
            } else {
                // TODO: What happens if this is a tmp value?
                printf("ERROR: Cant change memory of the given number (function soti_copy_to(...) ) \n");
                exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
            }
        }

        // Set as zero, as well as all non-zero counters
        soti_set_r(0.0,res,dhl);

        if (order <= num->order){
            
            // Copy only order.
            memcpy(res->p_im[order-1], num->p_im[order-1],  num->p_nnz[order-1]*sizeof(coeff_t) );
            memcpy(res->p_idx[order-1],num->p_idx[order-1], num->p_nnz[order-1]*sizeof(imdir_t) );

            res->p_nnz[order-1] = num->p_nnz[order-1]; 

        }

    }

}
// ----------------------------------------------------------------------------------------------------

































// Setter.

// ****************************************************************************************************
void soti_insert_item( ndir_t pos, coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, 
    dhelpl_t dhl){
    
    coeff_t* p_tmpim  = NULL;
    imdir_t* p_tmpidx = NULL;


    if ( num->p_nnz[order-1] == num->p_size[order-1] ){
        // Reallocation in memory is necessary.

        num->p_nnz[order-1] += _REALLOC_SIZE;

        sotinum_t tmp = soti_createEmpty_like(num,dhl);

        num->p_nnz[order-1] -= _REALLOC_SIZE;
        
        soti_copy_to( num, &tmp, dhl);
        
        soti_free(num);
        
        *num = tmp;

    }

    if (pos < num->p_nnz[order-1]){
        // Memory copy is necesary

        //get temporal pointers
        p_tmpim = dhl.p_dh[order-1].p_im[0];
        p_tmpidx= dhl.p_dh[order-1].p_idx[0];

        // copy to pointer:
        memcpy(p_tmpim ,&num->p_im[order-1][pos] ,(num->p_nnz[order-1]-pos)*sizeof(coeff_t));
        memcpy(p_tmpidx,&num->p_idx[order-1][pos],(num->p_nnz[order-1]-pos)*sizeof(imdir_t));

        // copy back to new position
        memcpy(&num->p_im[order-1][pos+1] ,p_tmpim ,(num->p_nnz[order-1]-pos)*sizeof(coeff_t));
        memcpy(&num->p_idx[order-1][pos+1],p_tmpidx,(num->p_nnz[order-1]-pos)*sizeof(imdir_t));        
        
    }

    // Set the new position.
    num->p_im[order-1][pos] = val;
    num->p_idx[order-1][pos] = idx;
    num->p_nnz[order-1] += 1;

    // Reset the new order.
    num->order = MAX(num->order,order);
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_set_item(coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    flag_t flag;
    imdir_t pos;
    uint64_t i;
    
    if (order == 0){
        
        num->re = val;

    }else{

        if ( order <= num->order ){

            pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );

            if ( flag != 0 ){

                // pos exists within num and already contains a value.
                num->p_im[order-1][pos] = val;

            } else {

                // pos is not contained within num, thus has to be inserted.
                soti_insert_item( pos, val, idx, order, num, dhl);

            }

        } else {

            if ( order <= num->torder ){

                // Be sure that the other nnz are zero. 
                // TODO: Maybe overkill.
                for (i=order+1; i<= num->torder; i++){
                    num->p_nnz[i-1] = 0;
                }

                num->order = order;

                pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );

                if ( flag != 0 ){

                    // pos exists within num and already contains a value.
                    num->p_im[order-1][pos] = val;

                } else {

                    // pos is not contained within num, thus has to be inserted.
                    soti_insert_item( pos, val, idx, order, num, dhl);

                }

            } // what happens if the order is greater than the truncation order of the number?
            // Change order? and add one element to the specified order.
        } 

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_set_im_r(coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    flag_t flag;
    imdir_t pos;
    
    if (order == 0){
        
        num->re = val;

    }else{

        if ( order <= num->order ){

            pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );

            if ( flag != 0 ){

                // pos exists within num and already contains a value.
                num->p_im[order-1][pos] = val;

            } else {

                // pos is not contained within num, thus has to be inserted.
                soti_insert_item( pos, val, idx, order, num, dhl);

            }

        } else if (order <= num->torder){
        
            // Be sure that the nnz for all orders up to the new order are zero. 
            // TODO: Overkill? Necesary?
            soti_reset_orders(num->order+1, order, num, dhl);
            
            soti_insert_item( 0, val, idx, order, num, dhl);

        }// TODO: what happens if the order is greater than the number?
        // Change order and add one element to the specified order.

    } 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_set_deriv_o(sotinum_t* val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    imdir_t idxr;
    ndir_t i;
    sotinum_t tmp;
    coeff_t factornum, factorden, value;
    ord_t res_order, ordi, ordr, ord_iter;
    
    if (order == 0){
        
        soti_set_o( val, num, dhl);

    }else{

        res_order = MIN( dhl.ndh, MAX(num->torder, order + val->torder) );
        
        tmp = soti_get_tmp(0, res_order, dhl);

        soti_set_r(0.0, &tmp, dhl);

        // Copy to number. (TODO: Try to avoid this directly.)
        // soti_set_o(num, &tmp, dhl);
        ord_iter = MIN(num->order,res_order);
        
        tmp.re = num->re;
        tmp.order = ord_iter;

        for ( ordi = 0; ordi < ord_iter; ordi++){
            
            // Copy memory to dest number. Only copy non zeros.
            memcpy(tmp.p_im[ordi], num->p_im[ordi], num->p_nnz[ordi]*sizeof(coeff_t) );
            memcpy(tmp.p_idx[ordi],num->p_idx[ordi],num->p_nnz[ordi]*sizeof(imdir_t) );

            tmp.p_nnz[ordi] = num->p_nnz[ordi];

        }

        factorden = dhelp_get_deriv_factor(idx, order, dhl);
        
        soti_set_im_r(val->re/factorden, idx, order, &tmp, dhl);

        ord_iter = MIN( val->order, res_order - val->order);


        for ( ordi = 0; ordi < ord_iter; ordi++){

            for (i = 0; i < val->p_nnz[ordi]; i++){

                dhelp_multDir( idx, order, val->p_idx[ordi][i], ordi+1, &idxr, &ordr, dhl);

                if (ordr > tmp.order){
                    // re-check that all nnz are zero.
                    tmp.order = ordr;
                } 

                factorden = dhelp_get_deriv_factor(idxr, ordr, dhl);
                factornum = dhelp_get_deriv_factor(val->p_idx[ordi][i], ordi+1, dhl);
                
                value = val->p_im[ordi][i] * factornum / factorden;
                
                soti_set_im_r( value, idxr, ordr, &tmp, dhl);
                
            }
            
        }

        // Copy back to number.
        soti_set_o( &tmp, num, dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_set_im_o(sotinum_t* val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    imdir_t idxr;
    ndir_t i;
    sotinum_t tmp;

    ord_t res_order, ordi, ordr, ord_iter;
    
    if (order == 0){
        
        soti_set_o( val, num, dhl);

    }else{

        res_order = MIN( dhl.ndh, MAX(num->order, order + val->order) );
        
        tmp = soti_get_tmp(0, res_order, dhl);

        // soti_set_o(num, &tmp, dhl);
        tmp.re = num->re;
        ord_iter = MIN(num->order,res_order);
        
        for ( ordi = 0; ordi < ord_iter; ordi++){
            
            // Copy memory to dest number. Only copy non zeros.
            memcpy(tmp.p_im[ordi], num->p_im[ordi], num->p_nnz[ordi]*sizeof(coeff_t) );
            memcpy(tmp.p_idx[ordi],num->p_idx[ordi],num->p_nnz[ordi]*sizeof(imdir_t) );

            tmp.p_nnz[ordi] = num->p_nnz[ordi]; 

        }            

        soti_set_im_r(val->re, idx, order, &tmp, dhl);

        ord_iter = MIN(val->order,res_order);

        for ( ordi = 0; ordi < ord_iter; ordi++) {

            for (i =0; i<val->p_nnz[ordi]; i++){

                dhelp_multDir( idx, order, val->p_idx[ordi][i], ordi+1, &idxr, &ordr, dhl);
                
                soti_set_im_r(val->p_im[ordi][i], idxr, ordr, &tmp, dhl);                
                
            }
            
        }

        soti_set_o( &tmp, num, dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_set_r( coeff_t a, sotinum_t* num, dhelpl_t dhl){
    
    ord_t i;
    
    num->re = a;
    num->order = 0;

    for ( i = 0; i < num->torder; i++){
        // Set number of non-zero and allocated size to 0.
        num->p_nnz[i] = 0;
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_set_o( sotinum_t* src, sotinum_t* dest, dhelpl_t dhl){
    
    // This function sets an oti number from another OTI number.
    uint8_t reallocate = soti_requiresrealloc(src, dest);
    ord_t i;

    // TODO: Add check to wheather dest has not been initialized.
    // TODO: Add case when the two elements have different orders.
    // TODO: Add check if dest is a tmp function.

    if( reallocate ){
        // Reallocation IS required.
        // Easiest way: Free current memory in dest and allocate new memory.
        
        if (dest->flag != 0){

            soti_free(dest);  
            *dest = soti_createEmpty_like( src, dhl);        

        } else {

            // TODO: What happens if this is a tmp value?
            printf("ERROR: Cant change memory of given OTI number.\n");
            exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.

        }

    }

    // Copy real coefficient
    dest->re = src->re;
    dest->order = src->order;

    // Copy imaginary coefficients
    for ( i = 0; i < src->order; i++){
        // Copy memory to dest number. Only copy non zeros.
        memcpy(dest->p_im[i], src->p_im[i], src->p_nnz[i]*sizeof(coeff_t) );
        memcpy(dest->p_idx[i],src->p_idx[i],src->p_nnz[i]*sizeof(imdir_t) );

        dest->p_nnz[i] = src->p_nnz[i]; 
    }

    // Set all other elements in the imaginary directions to zero.
    for (; i<dest->torder;i++){
        dest->p_nnz[i] = 0;
    }

}
// ----------------------------------------------------------------------------------------------------

// ====================================================================================================
// ====================================================================================================
// =====================        IMAGINARY DIR. EXTRACTOR FUNCTIONS         ============================
// ====================================================================================================
// ====================================================================================================

// ****************************************************************************************************
coeff_t soti_get_item(imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    coeff_t res = 0.0; // Default answer.
    flag_t flag;
    imdir_t pos;
    
    if (order == 0){
        
        res = num->re;

    } else {

        if ( order<=num->order ){            
            if(num->p_nnz[order-1] != 0){
                pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );
                if (flag != 0){
                    res = num->p_im[order-1][pos];
                }
            }
        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
coeff_t soti_get_im(imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    coeff_t res = 0.0; // Default answer.
    flag_t flag;
    imdir_t pos;
    
    if (order == 0){
        
        res = num->re;

    } else {

        if ( order<=num->order ){            
            if(num->p_nnz[order-1] != 0){
                pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );
                if (flag != 0){
                    res = num->p_im[order-1][pos];
                }
            }
        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_get_im_o(imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    sotinum_t res = soti_init();
    coeff_t rres = soti_get_im(idx, order, num, dhl);

    res.re = rres;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_get_im_to_o(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    
    coeff_t rres = soti_get_im(idx, order, num, dhl);

    soti_set_r(rres,res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_get_im_to_r(imdir_t idx, ord_t order, sotinum_t* num, coeff_t* res, dhelpl_t dhl){
    
    *res = soti_get_im(idx, order, num, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_extract_im(imdir_t idx, ord_t order, sotinum_t* num,  dhelpl_t dhl){

    sotinum_t res = soti_init();

    soti_extract_im_to(idx, order, num, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_extract_im_to(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    
    int  success;
    ord_t   resord, i, j;
    imdir_t residx;
    ndir_t ndir_ordi, diri;
    sotinum_t tmp;
    
    if (order == 0){
        
        // If getting the "real" part, it is the same number.
        soti_set_o(num,res,dhl);

    } else if (order > num->order){

        // If the requested order is greater, it will be zero.
        soti_set_r(0.0, res, dhl);

    } else {

        // use temporal 0.
        tmp = soti_get_tmp(0, num->torder-order, dhl);
        
        // Get real part.
        tmp.re = soti_get_item(idx, order, num, dhl);

        // Set new order
        tmp.order = num->order - order;

        // loop for the remaining orders:
        for(i = order; i<num->order; i++){

            // Divide the remaining directions in the number by the requested direction
            // 
            ndir_ordi = num->p_nnz[i];

            for ( diri = 0; diri< ndir_ordi; diri++){ 

                dhelp_div_imdir( num->p_idx[i][diri], i + 1, idx, order, &residx, &resord, &success, dhl);
                // if derivative is possible:
                if (success == 0){

                    j = resord-1;
                    
                    tmp.p_idx[j][tmp.p_nnz[j]] = residx;
                    tmp.p_im[ j][tmp.p_nnz[j]] = num->p_im[i][diri] ;
                    tmp.p_nnz[j]++;

                }

            }

        }
        
        soti_copy_to(&tmp,res,dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ====================================================================================================
// ====================================================================================================
// ===================================      TRUNCATOR FUNCTIONS      ==================================
// ====================================================================================================
// ====================================================================================================

// ****************************************************************************************************
sotinum_t soti_truncate_im(imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    sotinum_t res = soti_init();

    soti_truncate_im_to( idx, order, num, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_truncate_im_to(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    
    int  success;
    ord_t   resord, i;
    imdir_t residx;
    ndir_t ndir_ordi, diri;
    sotinum_t tmp;
    // bases_t* imdir_bases;
    
    
    if (order == 0){
        
        // All the number is truncated zero.
        soti_set_r( 0.0, res, dhl);
        return;

    } else if (order > num->order){
        
        // no need to truncate anything
        soti_set_o(num,res,dhl);
        return;

    } else {

        // use temporal 0.
        tmp = soti_get_tmp( 0, num->torder, dhl);
        
        // Set real part.
        tmp.re = num->re;
        tmp.order = num->order;

        // First, copy all elements up to order - 1 .
        for(i = 0; i<order-1; i++){
            
            memcpy(tmp.p_im[i], num->p_im[i], num->p_nnz[i]*sizeof(coeff_t) );
            memcpy(tmp.p_idx[i],num->p_idx[i],num->p_nnz[i]*sizeof(imdir_t) );

            tmp.p_nnz[i] = num->p_nnz[i]; 

        }
        
        for(i = order-1; i< num->order ; i++){

            // Divide the remaining directions in the number by the requested direction
            // 
            ndir_ordi = num->p_nnz[i];

            for ( diri = 0; diri< ndir_ordi; diri++){ 

                dhelp_div_imdir( num->p_idx[i][diri], i + 1, idx, order, &residx, &resord, &success, dhl);
                
                // if derivative is not possible, number is preserved.
                if (success != 0){
                    
                    tmp.p_idx[i][tmp.p_nnz[i]] = num->p_idx[i][diri];
                    tmp.p_im [i][tmp.p_nnz[i]] = num->p_im[i] [diri];
                    tmp.p_nnz[i]++;

                }

            }

        }
        
        soti_copy_to(&tmp,res,dhl);

    }  

}
// ----------------------------------------------------------------------------------------------------

// ====================================================================================================
// ====================================================================================================
// ============================        DERIVATIVE EXTRACTOR FUNCTIONS       ===========================
// ====================================================================================================
// ====================================================================================================

// ****************************************************************************************************
void soti_set_deriv_r( coeff_t coef, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    coeff_t factor = dhelp_get_deriv_factor(idx, order, dhl);

    soti_set_im_r( coef/factor, idx, order, num, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
coeff_t soti_get_deriv( imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){

    coeff_t coef   = soti_get_item(idx,order,num,dhl);
    coeff_t factor = dhelp_get_deriv_factor(idx, order, dhl);

    return coef*factor;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_get_deriv_o( imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){

    sotinum_t res = soti_init();

    // Set imaginary direction.
    soti_get_deriv_to( idx, order, num, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_get_deriv_to( imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t coef   = soti_get_item(idx,order,num,dhl);
    coeff_t factor = dhelp_get_deriv_factor(idx, order, dhl);

    soti_set_r( coef * factor, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_extract_deriv(imdir_t idx, ord_t order, sotinum_t* num,  dhelpl_t dhl){

    sotinum_t res = soti_init();

    soti_extract_deriv_to(idx, order, num, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_extract_deriv_to(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl){
    
    int  success;
    ord_t   resord, i, j;
    imdir_t residx;
    coeff_t factornum, factorden;
    ndir_t ndir_ordi, diri;
    sotinum_t tmp;
    
    if (order == 0){
        
        // If getting the "real" part, it is the same number.
        soti_set_o(num,res,dhl);
        return;

    } else if (order > num->order){

        // If the requested order is greater, it will be zero.
        soti_set_r(0.0, res, dhl);
        return;

    } else {

        // use temporal 0.
        tmp = soti_get_tmp(0, num->torder - order, dhl);
        
        // Get real part.
        tmp.re = soti_get_item(idx, order, num, dhl) * dhelp_get_deriv_factor(idx, order, dhl);

        // Set new order
        tmp.order = num->order - order;

        // loop for the remaining orders:
        for(i = order; i<num->order; i++){

            // Divide the remaining directions in the number by the requested direction
            
            ndir_ordi = num->p_nnz[i];

            for ( diri = 0; diri< ndir_ordi; diri++){ 

                dhelp_div_imdir( num->p_idx[i][diri], i + 1, idx, order, &residx, &resord, &success, dhl);
                // if derivative is possible:
                if (success == 0){

                    j = resord-1;

                    factornum = dhelp_get_deriv_factor(num->p_idx[i][diri], i+1, dhl);
                    factorden = dhelp_get_deriv_factor(residx, resord, dhl);

                    tmp.p_idx[j][tmp.p_nnz[j]] = residx;
                    tmp.p_im[ j][tmp.p_nnz[j]] = num->p_im[i][diri] * (factornum/factorden);
                    tmp.p_nnz[j]++;

                }

            }

        }

        soti_copy_to(&tmp,res,dhl);
    }    

}
// ----------------------------------------------------------------------------------------------------

// ====================================================================================================
// ====================================================================================================
// ===================================        HELPER FUNCTIONS       ==================================
// ====================================================================================================
// ====================================================================================================

inline void soti_reset_orders(ord_t ord_start, ord_t ord_end, sotinum_t* num, dhelpl_t dhl){
    
    ord_t ordi = 0;
    ord_t o_start = MIN(num->torder,ord_start);
    ord_t o_end = MIN(num->torder,ord_end);

    // Loop among all orders in num to be reset.
    for (ordi = o_start-1; ordi < o_end; ordi++){
        num->p_nnz[ordi] = 0;    
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_print(sotinum_t* num, dhelpl_t dhl){

    ndir_t nnz_total = 1, dir;
    ord_t ordi,ord;
    bases_t* imdir_bases;
    
    for( ordi = 0; ordi<num->torder; ordi++){
        nnz_total += num->p_nnz[ordi];
    }

    printf("  Order: "_PORDT", non_zero: "_PNDIRT", re: %11.4e\n",
        num->order, nnz_total, num->re);
    // printf("  ORD ,    IMDIR  ,   VALUE   \n");
    printf("      VALUE   ,    IMDIR  \n");

    // printf("    0 ,         0 , "_PCOEFFT"\n",num->re);
    printf("  " _PCOEFFT " , [0]\n",num->re);

    for( ord = 1; ord <= num->torder; ord++){

        ndir_t ndir_i = num->p_nnz[ord-1];

        for ( dir=0; dir< ndir_i; dir++){
            
            // printf(" " _PORDT " , " _PNDIRT " ," _PCOEFFT "\n",
            printf("  " _PCOEFFT " , ",  num->p_im[ord-1][dir]);

            imdir_bases = dhelp_get_imdir( num->p_idx[ord-1][dir], ord, dhl);
            
            printArrayUI16( imdir_bases, ord);

            printf("\n");

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_get_rtmp(ndir_t ntmp, ord_t torder, dhelpl_t dhl){
    
    sotinum_t res;
    ord_t i=0;

    if (torder == 0){
        // In case order==0, no allocated array exists.
        res = soti_createEmpty(0,dhl);
        return res;
    }
    if (torder > dhl.ndh){
        printf("ERROR: Maximum order not allowed in soti_get_rtmp.\n");
        exit(OTI_undetErr);
    }
    if (ntmp >= dhl.p_dh[torder-1].Ntmps){
        printf("ERROR: Trying to get a temporal that does not exist.\n");
        exit(OTI_undetErr);   
    }
    res.re     = 0.0; // Set real value to zero.
    res.p_im   = dhl.p_dh[torder-1].p_ims[ntmp]; 
    res.p_idx  = dhl.p_dh[torder-1].p_ids[ntmp]; 
    res.p_nnz  = dhl.p_dh[torder-1].p_nnz[ntmp]; 
    res.p_size = dhl.p_dh[torder-1].p_size[ntmp]; 
    res.order  = 0;
    res.torder = torder; 
    res.flag   = 0; // Memory is not owned by this number.

    for (i=0; i<torder; i++){

        res.p_im[i]  = dhl.p_dh[i].p_im[ntmp];
        res.p_idx[i] = dhl.p_dh[i].p_idx[ntmp];
        res.p_nnz[i] = 0; // Initialize to zero elements.
        res.p_size[i]= dhl.p_dh[i].Ndir;

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_get_tmp(ndir_t ntmp, ord_t torder, dhelpl_t dhl){
    
    sotinum_t res;
    ord_t i=0;

    if (torder == 0){
        // In case order==0, no allocated array exists.
        res = soti_createEmpty(0,dhl);
        return res;
    }
    if (torder > dhl.ndh){
        printf("ERROR: Maximum order not allowed in soti_get_tmp.\n");
        exit(OTI_undetErr);
    }
    if (ntmp >= (dhl.p_dh[torder-1].Ntmps - 10) ){
        printf("ERROR: Trying to get a temporal that does not exist.\n");
        exit(OTI_undetErr);   
    }

    res.p_im   = dhl.p_dh[torder-1].p_ims[ ntmp+10]; 
    res.p_idx  = dhl.p_dh[torder-1].p_ids[ ntmp+10]; 
    res.p_nnz  = dhl.p_dh[torder-1].p_nnz[ ntmp+10]; 
    res.p_size = dhl.p_dh[torder-1].p_size[ntmp+10]; 
    res.order  = 0; 
    res.torder = torder; 
    res.flag   = 0; 

    for (i=0; i<torder; i++){

        res.p_im[i]  = dhl.p_dh[i].p_im[ntmp+10];
        res.p_idx[i] = dhl.p_dh[i].p_idx[ntmp+10];
        res.p_nnz[i] = 0; // Initialize to zero elements.
        res.p_size[i]= dhl.p_dh[i].Ndir;

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ====================================================================================================
// ====================================================================================================
// ===================================        MEMORY MANAGEMENT      ==================================
// ====================================================================================================
// ====================================================================================================

// ****************************************************************************************************
void* soti_read_from_mem_to(void* mem, sotinum_t* dst, dhelpl_t dhl){

    // Mem must come allocated.
    ord_t i;
    void* read_mem = mem;
    coeff_t re = 0.;
    ord_t order = 0;
    ord_t torder = 0;
    sotinum_t tmp;

    // read real coefficient:
    memcpy( &re, read_mem, sizeof(coeff_t) );
    read_mem += sizeof(coeff_t);

    // read truncation order:
    memcpy( &torder, read_mem, sizeof(ord_t) );
    read_mem += sizeof(ord_t);

    // read number of arrays order:
    memcpy( &order, read_mem, sizeof(ord_t) );
    read_mem += sizeof(ord_t);

    tmp = soti_get_tmp( 0, torder, dhl);
    soti_set_r( re, &tmp, dhl);
    tmp.order = order;

    // Add the standard allocation sizes:
    for ( i = 0; i < tmp.torder; i++){

        // read number of non zeros for this order:
        memcpy( &tmp.p_nnz[i], read_mem, sizeof(ndir_t) );
        read_mem += sizeof(ndir_t);

        // read array of coefficients (if any):
        memcpy( tmp.p_im[i], read_mem, tmp.p_nnz[i]*sizeof(coeff_t) );
        read_mem += tmp.p_nnz[i]*sizeof(coeff_t);

        // read array of im dirs (if any):
        memcpy( tmp.p_idx[i], read_mem, tmp.p_nnz[i]*sizeof(imdir_t) );
        read_mem += tmp.p_nnz[i]*sizeof(imdir_t);

    }

    // Copy to result.
    soti_copy_to( &tmp, dst, dhl);
    return read_mem;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_save_to_mem(sotinum_t* num, void* mem, dhelpl_t dhl){

    // Mem must come allocated.
    ord_t i;
    void* write_mem = mem;

    // Write real coefficient:
    memcpy( write_mem, &num->re, sizeof(coeff_t) );
    write_mem += sizeof(coeff_t);

    // Write truncation order:
    memcpy( write_mem, &num->torder, sizeof(ord_t) );
    write_mem += sizeof(ord_t);

    // Write number of arrays:
    memcpy( write_mem, &num->order, sizeof(ord_t) );
    write_mem += sizeof(ord_t);

    // Add the standard allocation sizes:
    for ( i =0; i < num->order ; i++){

        // Write number of arrays order:
        memcpy( write_mem, &num->p_nnz[i], sizeof(ndir_t) );
        write_mem += sizeof(ndir_t);

        // Write array of coefficients:
        memcpy( write_mem, num->p_im[i], num->p_nnz[i]*sizeof(coeff_t) );
        write_mem += num->p_nnz[i]*sizeof(coeff_t);

        // Write array of im dirs:
        memcpy( write_mem, num->p_idx[i], num->p_nnz[i]*sizeof(imdir_t) );
        write_mem += num->p_nnz[i]*sizeof(imdir_t);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
uint64_t soti_get_memsize_save(sotinum_t* num, dhelpl_t dhl){

    uint64_t mem_size = 0;
    ord_t i;
    
    // Get the size of    re  coeff           order            torder     :
    mem_size =         sizeof(coeff_t)  +  sizeof(ord_t)  +  sizeof(ord_t);

    // Add the standard allocation sizes:
    for ( i =0; i < num->order ; i++){
        
        mem_size += sizeof(ndir_t) + num->p_nnz[i]*( sizeof(coeff_t) + sizeof(imdir_t) ) ;

    }
    
    return mem_size;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
uint64_t soti_get_min_memsize(sotinum_t* num, dhelpl_t dhl){

    uint64_t allocation_size = 0;
    ord_t i;
    
    // Get the allocation size of the OTI number:
    allocation_size = num->torder*(sizeof(coeff_t*)+sizeof(imdir_t*)+sizeof(ndir_t)+sizeof(ndir_t));

    // Add the standard allocation sizes:
    for ( i =0; i < num->order ; i++){
        
        allocation_size += num->p_nnz[i]*(sizeof(coeff_t)+sizeof(imdir_t));

    }

    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
uint64_t soti_get_total_memsize(sotinum_t* num, dhelpl_t dhl){

    uint64_t allocation_size = 0;
    ord_t i;

    // Get the allocation size of the OTI number:
    allocation_size = num->torder*( sizeof(coeff_t*)+sizeof(imdir_t*)+sizeof(ndir_t)+sizeof(ndir_t));

    // Add the standard allocation sizes:
    for ( i = 0; i<num->torder; i++){
        
        allocation_size += num->p_size[i]*( sizeof(coeff_t) + sizeof(imdir_t) );

    }

    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
uint8_t soti_requiresrealloc(sotinum_t* src, sotinum_t* dest){
    
    uint8_t reallocate = 0; // False
    ord_t i;

    // Check if reallocation is necessary
    if (src->torder > dest->torder ){

        reallocate = 0xFF; // True

    } else {
       
        for ( i = 0; i < src->order; i++){

            // Check if the number of non zeros is greater to the size allocated
            // in destination.
            if ( src->p_nnz[i] > dest->p_size[i] ){

                reallocate = 0xFF; // True
                break;

            }
        }

    }

    return reallocate;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_copy_to(sotinum_t* src, sotinum_t* dest, dhelpl_t dhl){
        
    uint8_t reallocate = soti_requiresrealloc(src, dest);
    ord_t i;

    // TODO: Add check to wheather dest has not been initialized.
    // TODO: Add case when the two elements have different orders.
    // TODO: Add check if dest is a tmp function.

    if( reallocate ){
        // Reallocation IS required.
        // Easiest way: Free current memory in dest and allocate new memory.       

        if (dest->flag != 0){

            soti_free(dest);            
            (*dest) = soti_createEmpty_like( src, dhl);

        } else {
            // TODO: What happens if this is a tmp value?
            printf("ERROR: Cant change memory of the given number (function soti_copy_to(...) ) \n");
            exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
        }

    }

    // At this point, both inputs must have same torder.

    // Copy real coefficient
    dest->re = src->re;

    // Set the same number order
    dest->order = src->order;

    // Copy imaginary coefficients
    for ( i = 0; i < src->order; i++){
        
        // Copy memory to dest number. Only copy non zeros.
        memcpy(dest->p_im[i], src->p_im[i], src->p_nnz[i]*sizeof(coeff_t) );
        memcpy(dest->p_idx[i],src->p_idx[i],src->p_nnz[i]*sizeof(imdir_t) );

        dest->p_nnz[i] = src->p_nnz[i]; 

    }  

    // Set all other elements in the imaginary directions to zero.
    // TODO: With 'order' is this still necessary?
    for (; i<dest->torder;i++){

        dest->p_nnz[i] = 0;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void soti_copy_nomemchk_to(sotinum_t* src, sotinum_t* dest, dhelpl_t dhl){
    // Only recommended to use when using temporals.
    // when memory is guaranteed to be allocated.
    ord_t i;

    // Copy real coefficient
    dest->re = src->re;

    // Copy imaginary coefficients
    for ( i = 0; i < src->order; i++){
        
        // Copy memory to dest number. Only copy non zeros.
        memcpy(dest->p_im[i], src->p_im[i], src->p_nnz[i]*sizeof(coeff_t) );
        memcpy(dest->p_idx[i],src->p_idx[i],src->p_nnz[i]*sizeof(imdir_t) );

        dest->p_nnz[i] = src->p_nnz[i]; 

    }  

    // Set all other elements in the imaginary directions to zero.
    for (; i<dest->torder;i++){

        dest->p_nnz[i] = 0;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_copy(sotinum_t* num, dhelpl_t dhl){

    ord_t i;
    sotinum_t res = soti_createEmpty_like( num, dhl);

    res.re    = num->re;
    res.order = num->order;

    for ( i = 0; i < res.torder; i++){
        
        // Set number of non-zero and allocated size to 0.
        res.p_nnz[i]  = num->p_nnz[i]; // Just use nnz.
        
        if ( res.p_nnz[i] != 0 ){

            // copy data.
            memcpy(res.p_im[i], num->p_im[i], res.p_nnz[i]*sizeof(coeff_t));
            memcpy(res.p_idx[i],num->p_idx[i],res.p_nnz[i]*sizeof(imdir_t));

        }
    
    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline sotinum_t soti_init(void){

    sotinum_t res;

    res.p_im  = NULL;
    res.p_idx = NULL;
    res.p_nnz = NULL;
    res.p_size= NULL;
    
    res.order  = 0;
    res.torder = 0;
    res.flag   = 1; 

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_free(sotinum_t* num){
                
    if (num->p_im != NULL && num->flag != 0){
        free(num->p_im);
    }

    (*num) = soti_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_createReal_bases(coeff_t num, bases_t nbases, ord_t torder, dhelpl_t dhl){
    
    sotinum_t res = soti_createEmpty_bases(nbases,torder,dhl);

    res.re = num;

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_createEmpty_bases( bases_t nbases, ord_t torder, dhelpl_t dhl){
    
    sotinum_t res;
    
    ndir_t p_nnz[_MAXORDER_OTI]; 
    ord_t i;
    
    // Define allocation sizes.
    for ( i = 0; i < torder; i++){

        p_nnz[i] = dhelp_ndirOrder( nbases, i + 1 );

    }
    
    res = soti_createEmpty_predef(p_nnz, torder, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_createReal(coeff_t num, ord_t torder, dhelpl_t dhl){
    
    sotinum_t res = soti_createEmpty(torder,dhl);

    res.re = num;

    return res;
}
// ----------------------------------------------------------------------------------------------------
 
// ****************************************************************************************************
sotinum_t soti_createEmpty( ord_t torder, dhelpl_t dhl){
    
    sotinum_t res;
    
    ndir_t p_nnz[_MAXORDER_OTI]; 

    ord_t i;
    
    // Define allocation sizes.
    for ( i = 0; i < torder; i++){
        p_nnz[i] = dhl.p_dh[i].allocSize; // Get standard allocation sizes.
    }
    
    res = soti_createEmpty_predef(p_nnz, torder, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_createEmpty_like( sotinum_t* other, dhelpl_t dhl){
    
    // This function assumes that 'other' is correctly allocated.
    // Defines a new memory space from the p_nnz (not p_size) of the input sparse number.
    sotinum_t res = soti_createEmpty_predef(other->p_nnz, other->torder, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline sotinum_t soti_createEmpty_predef(ndir_t* p_nnz, ord_t torder, dhelpl_t dhl){
    
    sotinum_t res = soti_init(); // Initialize pointer values.

    void * memory = NULL;
    uint64_t allocation_size = 0;
    ord_t i;

    res.torder = torder;
    
    if (res.torder != 0){

        // Get the allocation size of the OTI number:
        allocation_size = res.torder*(sizeof(coeff_t*)+sizeof(imdir_t*)+sizeof(ndir_t)+sizeof(ndir_t));

        // Add the standard allocation sizes:
        for ( i = 0; i<res.torder; i++){
            
            allocation_size += p_nnz[i]*(sizeof(coeff_t)+sizeof(imdir_t));

        }

        // Allocate memory and check if correctly allocated.
        memory = malloc(allocation_size);
        if ( memory == NULL ){
            printf("ERROR: Not enough memory to handle oti number.\n Exiting...\n");
            exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
        }

        // Distribute memory among the different pointers.
        res.p_im  = (coeff_t**)memory;
        memory    += res.torder * sizeof(coeff_t*);

        res.p_idx = (imdir_t**)memory;
        memory    += res.torder * sizeof(imdir_t*);

        res.p_nnz = (ndir_t*  )memory;
        memory    += res.torder * sizeof(ndir_t);

        res.p_size= (ndir_t*  )memory;
        memory    += res.torder * sizeof(ndir_t);
        
        for ( i = 0; i < res.torder; i++){
            
            // Distribute memory.
            res.p_im[i] = (coeff_t*)memory;
            memory += p_nnz[i]*sizeof(coeff_t); 

            res.p_idx[i]= (imdir_t*)memory;
            memory += p_nnz[i]*sizeof(imdir_t); 

            // Set number of non-zero and allocated size to 0.
            res.p_size[i] = p_nnz[i]; 
            res.p_nnz[i]  = 0; 

        }

    } 
    // Raise memory ownership flag for OTI number.
    res.flag = 1;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
size_t soti_memory_size( const ndir_t* p_nnz, ord_t order){

    size_t allocation_size = 0;
    ord_t i = 0;

    if (order != 0){
        
        // Get the allocation size of the OTI number:
        allocation_size = order * (sizeof(coeff_t*)+sizeof(imdir_t*)+sizeof(ndir_t)+sizeof(ndir_t));

        // Add the standard allocation sizes:
        for ( i = 0; i < order; i++){
            
            allocation_size += p_nnz[i]*(sizeof(coeff_t)+sizeof(imdir_t));

        }
    }

    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void* soti_distribute_memory(void* mem, const ndir_t* p_nnz, ord_t torder, flag_t flag, sotinum_t* res){

    ord_t i;
    void* memory = mem;

    res->torder = torder;

    // Distribute memory among the different pointers.
    res->p_im  = (coeff_t**)memory;
    memory    += res->torder * sizeof(coeff_t*);

    res->p_idx = (imdir_t**)memory;
    memory    += res->torder * sizeof(imdir_t*);

    res->p_nnz = (ndir_t*  )memory;
    memory    += res->torder * sizeof(ndir_t);

    res->p_size= (ndir_t*  )memory;
    memory    += res->torder * sizeof(ndir_t);
    
    for ( i = 0; i < res->torder; i++){
        
        // Distribute memory.
        res->p_im[i] = (coeff_t*)memory;
        memory += p_nnz[i]*sizeof(coeff_t); 

        res->p_idx[i]= (imdir_t*)memory;
        memory += p_nnz[i]*sizeof(imdir_t); 

        // Set number of non-zero and allocated size to 0.
        res->p_size[i] = p_nnz[i]; 
        res->p_nnz[i]  = 0; 

    }

    // Raise flag for OTI number.
    res->flag = flag;

    // If necessary, returns end of memory.
    return memory;

}
// ----------------------------------------------------------------------------------------------------