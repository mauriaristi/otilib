
// // ====================================================================================================
// // ====================================================================================================
// // =============================        TAYLOR INTEGRATOR FUNCTIONS       =============================
// // ====================================================================================================
// // ====================================================================================================

// // ****************************************************************************************************
// semiotin_t ssoti_taylor_integrate(coeff_t* deltas, semiotin_t* num, dhelpl_t dhl){
    
//     semiotin_t res = ssoti_createEmpty( 0, dhl); 
    
//     ssoti_taylor_integrate_to( deltas, num, &res, dhl);

//     return res;

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_taylor_integrate_to(coeff_t* deltas, semiotin_t* num, semiotin_t* res, dhelpl_t dhl){
    
//     ord_t   ordi;
//     ndir_t  ndir_ordi, diri;
//     coeff_t val = 0.0, delta;
    
//     val = num->re;
    
//     for(ordi = 0; ordi < num->act_order ; ordi++ ){

//         // 
//         ndir_ordi = num->p_nnz[ordi];

//         for ( diri = 0; diri< ndir_ordi; diri++){ 
            
//             delta  = dhelp_compute_delta( num->p_idx[ordi][diri], ordi + 1, deltas, dhl);
//             val   += num->p_im[ordi][diri] * delta;

//         }

//     }
    
//     ssoti_set_r(val,res,dhl);

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// semiotin_t ssoti_get_order_im( ord_t order, semiotin_t* num, dhelpl_t dhl){

//     semiotin_t res = ssoti_createEmpty( 0, dhl);

//     // Set imaginary direction.
//     ssoti_get_order_im_to( order, num, &res, dhl);
    
//     return res;

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_get_order_im_to( ord_t order, semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

//     uint8_t reallocate = 0;

//     // Copy real coefficient
//     if (order == 0){
    
//         ssoti_set_r(0.0,res,dhl);
//         res->re = num->re;
    
//     } else if ( order > num->act_order ){
        
//         ssoti_set_r(0.0,res,dhl);

//     } else {

//         // Check if reallocation is necessary
//         if (res->trc_order < order ){
//             reallocate = 0xFF; // True
//         } else {
//             if ( num->p_nnz[order-1] > res->p_size[order-1] ){
//                 reallocate = 0xFF; // True
//             }
//         }

//         // TODO: Add check to wheather dest has not been initialized.
//         // TODO: Add case when the two elements have different orders.
//         // TODO: Add check if dest is a tmp function.

//         if( reallocate ){
//             // Reallocation IS required.
//             // Easiest way: Free current memory in dest and allocate new memory.
//             if (res->flag != 0){
//                 ssoti_free(res);  
//                 (*res) = ssoti_createEmpty_like( num, dhl);
//             } else {
//                 // TODO: What happens if this is a tmp value?
//                 printf("ERROR: Cant change memory of the given number (in function ssoti_get_order_im_to(...) ) \n");
//                 exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
//             }
//         }

//         // Set as zero, as well as all non-zero counters. Sets res->act_order to 0.
//         ssoti_set_r(0.0,res,dhl);

        
//         // Only copy in the case num->act_order <= order
//         // Copy only order.
//         memcpy(res->p_im[order-1], num->p_im[order-1],  num->p_nnz[order-1]*sizeof(coeff_t) );
//         memcpy(res->p_idx[order-1],num->p_idx[order-1], num->p_nnz[order-1]*sizeof(imdir_t) );

//         res->p_nnz[order-1] = num->p_nnz[order-1]; 

//         // The actual order must be the actual order being set.
//         res->act_order = order;

//     }

// }
// // ----------------------------------------------------------------------------------------------------

































// // Setter.

// // ****************************************************************************************************
// void ssoti_insert_item( ndir_t pos, coeff_t val, imdir_t idx, ord_t order, semiotin_t* num, 
//     dhelpl_t dhl){
    
//     coeff_t* p_tmpim  = NULL;
//     imdir_t* p_tmpidx = NULL;


//     if ( num->p_nnz[order-1] == num->p_size[order-1] ){
//         // Reallocation in memory is necessary.

//         num->p_nnz[order-1] += _REALLOC_SIZE;

//         semiotin_t tmp = ssoti_createEmpty_like(num,dhl);

//         num->p_nnz[order-1] -= _REALLOC_SIZE;
        
//         ssoti_copy_to( num, &tmp, dhl);
        
//         ssoti_free(num);
        
//         *num = tmp;

//     }

//     if (pos < num->p_nnz[order-1]){
//         // Memory copy is necesary

//         //get temporal pointers
//         p_tmpim = dhl.p_dh[order-1].p_im[0];
//         p_tmpidx= dhl.p_dh[order-1].p_idx[0];

//         // copy to pointer:
//         memcpy(p_tmpim ,&num->p_im[order-1][pos] ,(num->p_nnz[order-1]-pos)*sizeof(coeff_t));
//         memcpy(p_tmpidx,&num->p_idx[order-1][pos],(num->p_nnz[order-1]-pos)*sizeof(imdir_t));

//         // copy back to new position
//         memcpy(&num->p_im[order-1][pos+1] ,p_tmpim ,(num->p_nnz[order-1]-pos)*sizeof(coeff_t));
//         memcpy(&num->p_idx[order-1][pos+1],p_tmpidx,(num->p_nnz[order-1]-pos)*sizeof(imdir_t));        
        
//     }

//     // Set the new position.
//     num->p_im[order-1][pos] = val;
//     num->p_idx[order-1][pos] = idx;
//     num->p_nnz[order-1] += 1;

//     // Reset the new order.
//     num->act_order = MAX(num->act_order, order);
    
// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_set_item(coeff_t val, imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl){
    
//     ssoti_set_im_r( val, idx, order, num, dhl);

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_set_im_r(coeff_t val, imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl){
    
//     flag_t flag;
//     imdir_t pos;
//     bases_t* imdir_bases;
//     bases_t max_idx_base;
//     semiotin_t tmp;

//     if (order == 0){
        
//         num->re = val;

//     } else {

//         if ( order <= num->act_order ){
            
//             // TODO: Check if (idx,order) is within precomputed-data.
//             imdir_bases = dhelp_get_imdir( idx, order, dhl);
//             max_idx_base = imdir_bases[order-1];


//             if (max_idx_base <= num->act_nbases){
                
//                 num->p_im[order-1][idx] = val;

//             } else if (max_idx_base <= num->tot_nbases){

//                 // Set all new bases directions to 0.
//                 ssoti_reset_nbases(num->act_nbases, max_idx_base, num, dhl);
//                 num->act_nbases = max_idx_base; // change the number of bases.
//                 num->p_im[order-1][idx] = val;


//             } else { 
                
//                 // Reallocation is required.
//                 tmp = ssoti_createEmpty_like(,dhl);
//             }

//         } else if (order <= num->trc_order){
        
//             // Be sure that the nnz for all orders up to the new order are zero. 
//             // TODO: Overkill? Necesary?
//             ssoti_reset_orders(num->act_order+1, order, num, dhl);
            
//             // Insert the given coefficient. This function updates the number's order.            
//             ssoti_insert_item( 0, val, idx, order, num, dhl);
            
//         }// TODO: what happens if the order is greater than the number?
//         // Change order and add one element to the specified order.

//     } 

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_set_deriv_o(semiotin_t* val, imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl){
    
//     imdir_t idxr;
//     ndir_t diri;
//     semiotin_t tmp;
//     coeff_t factornum, factorden, value;
//     ord_t res_order, ordi, ordr, ord_iter;
    
//     if (order == 0){
        
//         ssoti_set_o( val, num, dhl);

//     }else{

//         // TODO: Determine what is the required order: Actual or Truncation...
//         res_order = MIN( dhl.ndh, MAX(num->trc_order, order + val->trc_order) );
        
//         tmp = ssoti_get_tmp(0, res_order, dhl);

        
//         tmp.re = num->re; //  Set real coefficient.
        
//         // Initiall, copy all data from num to the result.
//         ord_iter = MIN( num->act_order, res_order);
//         tmp.act_order = ord_iter;
        
//         for ( ordi = 0; ordi < tmp.act_order; ordi++){
            
//             // Copy memory to dest number. Only copy non zeros.
//             memcpy(tmp.p_im[ordi], num->p_im[ordi], num->p_nnz[ordi]*sizeof(coeff_t) );
//             memcpy(tmp.p_idx[ordi],num->p_idx[ordi],num->p_nnz[ordi]*sizeof(imdir_t) );

//             tmp.p_nnz[ordi] = num->p_nnz[ordi]; 

//         }            


//         if (order <= dhl.ndh){


//             factorden = dhelp_get_deriv_factor(idx, order, dhl);            
//             ssoti_set_im_r(val->re/factorden, idx, order, &tmp, dhl);

//             ord_iter = MIN( val->act_order, res_order - val->act_order);
//             tmp.act_order = MAX( ord_iter + order, tmp.act_order );

//             for ( ordi = 0; ordi < ord_iter; ordi++){

//                 for (diri = 0; diri < val->p_nnz[ordi]; diri++){

//                     dhelp_multDir( idx, order, val->p_idx[ordi][diri], ordi+1, &idxr, &ordr, dhl);

//                     factorden = dhelp_get_deriv_factor(idxr, ordr, dhl);
//                     factornum = dhelp_get_deriv_factor(val->p_idx[ordi][diri], ordi+1, dhl);
                    
//                     value = val->p_im[ordi][diri] * factornum / factorden;
                    
//                     ssoti_set_im_r( value, idxr, ordr, &tmp, dhl);
                    
//                 }
                
//             }

//         }

//         // Copy back to number.
//         ssoti_set_o( &tmp, num, dhl);

//     }

// }
// // ----------------------------------------------------------------------------------------------------


// // ****************************************************************************************************
// void ssoti_set_im_o(semiotin_t* val, imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl){
    
//     imdir_t idxr;
//     ndir_t diri;
//     semiotin_t tmp;

//     ord_t res_order, ordi, ordr, ord_iter;
    
//     if (order == 0){
        
//         ssoti_set_o( val, num, dhl);

//     }else{

//         // TODO: Determine what is the required order: Actual or Truncation...
//         res_order = MIN( dhl.ndh, MAX(num->trc_order, order + val->trc_order) );
        
//         tmp = ssoti_get_tmp(0, res_order, dhl);

        
//         tmp.re = num->re; //  Set real coefficient.
        
//         // Initiall, copy all data from num to the result.
//         ord_iter = MIN( num->act_order, res_order);
//         tmp.act_order = ord_iter;
        
//         for ( ordi = 0; ordi < tmp.act_order; ordi++){
            
//             // Copy memory to dest number. Only copy non zeros.
//             memcpy(tmp.p_im[ordi], num->p_im[ordi], num->p_nnz[ordi]*sizeof(coeff_t) );
//             memcpy(tmp.p_idx[ordi],num->p_idx[ordi],num->p_nnz[ordi]*sizeof(imdir_t) );

//             tmp.p_nnz[ordi] = num->p_nnz[ordi]; 

//         }            


//         if (order <= dhl.ndh){
        
//             // Set given OTI number val as coefficients for the imaginary direction (idx,order)
//             ssoti_set_im_r(val->re, idx, order, &tmp, dhl);

//             // ord_iter = MIN( val->act_order, res_order - order );
//             ord_iter = MIN( val->act_order, res_order - val->act_order);

//             tmp.act_order = MAX( ord_iter + order, tmp.act_order );

//             for ( ordi = 0; ordi < ord_iter; ordi++) {

//                 for (diri = 0; diri < val->p_nnz[ordi]; diri++){

//                     dhelp_multDir( idx, order, val->p_idx[ordi][diri], ordi+1, &idxr, &ordr, dhl);
                    
//                     ssoti_set_im_r(val->p_im[ordi][diri], idxr, ordr, &tmp, dhl);                
                    
//                 }
                
//             }

//         }

//         ssoti_set_o( &tmp, num, dhl);

//     }

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_set_r( coeff_t a, semiotin_t* num, dhelpl_t dhl){
    
//     ord_t i;
    
//     num->re = a;
//     num->act_order = 0;

//     for ( i = 0; i < num->trc_order; i++){
//         // Set number of non-zero and allocated size to 0.
//         num->p_nnz[i] = 0;
//     }

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_set_o( semiotin_t* src, semiotin_t* dest, dhelpl_t dhl){
    
//     // This function sets an oti number from another OTI number.
//     uint8_t reallocate = ssoti_requiresrealloc(src, dest);
//     ord_t i;

//     // TODO: Add check to wheather dest has not been initialized.
//     // TODO: Add case when the two elements have different orders.
//     // TODO: Add check if dest is a tmp function.

//     if( reallocate ){
//         // Reallocation IS required.
//         // Easiest way: Free current memory in dest and allocate new memory.
        
//         if (dest->flag != 0){

//             ssoti_free(dest);  
//             *dest = ssoti_createEmpty_like( src, dhl);        

//         } else {

//             // TODO: What happens if this is a tmp value?
//             printf("ERROR: Cant change memory of given OTI number.\n");
//             exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.

//         }

//     }

//     // Copy real coefficient
//     dest->re = src->re;
//     dest->act_order = src->act_order;

//     // Copy imaginary coefficients
//     for ( i = 0; i < src->act_order; i++){

//         // Copy memory to dest number. Only copy non zeros.
//         memcpy(dest->p_im[i], src->p_im[i], src->p_nnz[i]*sizeof(coeff_t) );
//         memcpy(dest->p_idx[i],src->p_idx[i],src->p_nnz[i]*sizeof(imdir_t) );

//         dest->p_nnz[i] = src->p_nnz[i]; 

//     }

//     // Set all other elements in the imaginary directions to zero.
//     for (; i<dest->trc_order;i++){

//         dest->p_nnz[i] = 0;

//     }

// }
// // ----------------------------------------------------------------------------------------------------

// // ====================================================================================================
// // ====================================================================================================
// // =====================        IMAGINARY DIR. EXTRACTOR FUNCTIONS         ============================
// // ====================================================================================================
// // ====================================================================================================

// // ****************************************************************************************************
// coeff_t ssoti_get_item(imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl){
    
//     coeff_t res = 0.0; // Default answer.
//     flag_t flag;
//     imdir_t pos;
    
//     if (order == 0){
        
//         res = num->re;

//     } else {

//         if ( order<=num->act_order ){            
//             if(num->p_nnz[order-1] != 0){
//                 pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );
//                 if (flag != 0){
//                     res = num->p_im[order-1][pos];
//                 }
//             }
//         }

//     }

//     return res;

// }
// // ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
coeff_t ssoti_get_im(imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl){
    
    coeff_t res = 0.0; // Default answer.
    bases_t* imdir_bases;
    bases_t max_idx_base;

    if (order == 0){
        
        res = num->re;

    } else {

        imdir_bases = dhelp_get_imdir( idx, order, dhl);
        max_idx_base = imdir_bases[order-1];
        
        if ( order <= num->act_order || order <= num->act_nbases ){ 
                
            res = num->p_im[order-1][idx];
                
        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// semiotin_t ssoti_get_im_o(imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl){
    
//     semiotin_t res = ssoti_init();
//     coeff_t rres = ssoti_get_im(idx, order, num, dhl);

//     res.re = rres;

//     return res;

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_get_im_to_o(imdir_t idx, ord_t order, semiotin_t* num, semiotin_t* res, dhelpl_t dhl){
    
//     coeff_t rres = ssoti_get_im(idx, order, num, dhl);

//     ssoti_set_r(rres,res, dhl);

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_get_im_to_r(imdir_t idx, ord_t order, semiotin_t* num, coeff_t* res, dhelpl_t dhl){
    
//     *res = ssoti_get_im(idx, order, num, dhl);

// }
// // ----------------------------------------------------------------------------------------------------


// // ****************************************************************************************************
// semiotin_t ssoti_extract_im(imdir_t idx, ord_t order, semiotin_t* num,  dhelpl_t dhl){

//     semiotin_t res = ssoti_init();

//     ssoti_extract_im_to(idx, order, num, &res, dhl);

//     return res;
// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_extract_im_to(imdir_t idx, ord_t order, semiotin_t* num, semiotin_t* res, dhelpl_t dhl){
    
//     int  success;
//     ord_t   resord, ordi, ordj;
//     imdir_t residx;
//     ndir_t ndir_ordi, diri;
//     semiotin_t tmp;
    
//     if (order == 0){
        
//         // If getting the "real" part, it is the same number.
//         ssoti_set_o(num,res,dhl);

//     } else if (order > num->act_order){

//         // If the requested order is greater, it will be zero.
//         ssoti_set_r(0.0, res, dhl);

//     } else {

//         // use temporal 0.
//         tmp = ssoti_get_tmp(0, num->trc_order - order, dhl);
        
//         // Get real part.
//         tmp.re = ssoti_get_item(idx, order, num, dhl);

//         // Set new order
//         tmp.act_order = num->act_order - order;

//         // loop for the remaining orders:
//         for(ordi = order; ordi<num->act_order; ordi++){

//             // Divide the remaining directions in the number by the requested direction
//             // 
//             ndir_ordi = num->p_nnz[ordi];

//             for ( diri = 0; diri< ndir_ordi; diri++){ 

//                 dhelp_div_imdir( num->p_idx[ordi][diri], ordi + 1, 
//                                  idx, order, &residx, &resord, &success, dhl);
//                 // if derivative is possible:
//                 if (success == 0){

//                     ordj = resord-1;
                    
//                     tmp.p_idx[ordj][tmp.p_nnz[ordj]] = residx;
//                     tmp.p_im[ ordj][tmp.p_nnz[ordj]] = num->p_im[ordi][diri] ;
//                     tmp.p_nnz[ordj]++;

//                 }

//             }

//         }
        
//         ssoti_copy_to(&tmp,res,dhl);

//     }

// }
// // ----------------------------------------------------------------------------------------------------

// // ====================================================================================================
// // ====================================================================================================
// // ===================================      TRUNCATOR FUNCTIONS      ==================================
// // ====================================================================================================
// // ====================================================================================================

// // ****************************************************************************************************
// semiotin_t ssoti_truncate_im(imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl){
    
//     semiotin_t res = ssoti_init();

//     ssoti_truncate_im_to( idx, order, num, &res, dhl);

//     return res;

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_truncate_im_to(imdir_t idx, ord_t order, semiotin_t* num, semiotin_t* res, dhelpl_t dhl){
    
//     int  success;
//     ord_t   resord, ordi;
//     imdir_t residx;
//     ndir_t ndir_ordi, diri;
//     semiotin_t tmp;
//     // bases_t* imdir_bases;
    
    
//     if (order == 0){
        
//         // All the number is truncated zero.
//         ssoti_set_r( 0.0, res, dhl);
//         return;

//     } else if (order > num->act_order){
        
//         // no need to truncate anything
//         ssoti_set_o(num,res,dhl);
//         return;

//     } else {

//         // use temporal 0.
//         tmp = ssoti_get_tmp( 0, num->trc_order, dhl);
        
//         // Set real part.
//         tmp.re = num->re;
//         tmp.act_order = num->act_order;

//         // First, copy all elements up to order - 1 .
//         for( ordi = 0; ordi < (order-1); ordi++ ){
            
//             memcpy(tmp.p_im[ordi], num->p_im[ordi], num->p_nnz[ordi]*sizeof(coeff_t) );
//             memcpy(tmp.p_idx[ordi],num->p_idx[ordi],num->p_nnz[ordi]*sizeof(imdir_t) );

//             tmp.p_nnz[ordi] = num->p_nnz[ordi]; 

//         }
        
//         // Then, set all other imaginary directions according to truncation.
//         for(ordi = order-1; ordi< num->act_order; ordi++){

//             // Divide the remaining directions in the number by the requested direction
//             // 
//             ndir_ordi = num->p_nnz[ordi];

//             for ( diri = 0; diri< ndir_ordi; diri++){ 

//                 dhelp_div_imdir( num->p_idx[ordi][diri], ordi + 1, idx, order, &residx, &resord, &success, dhl);
                
//                 // if derivative is not possible, number is preserved.
//                 if (success != 0){
                    
//                     tmp.p_idx[ordi][tmp.p_nnz[ordi]] = num->p_idx[ordi][diri];
//                     tmp.p_im [ordi][tmp.p_nnz[ordi]] = num->p_im[ ordi][diri];
//                     tmp.p_nnz[ordi]++;

//                 }

//             }

//         }
        
//         ssoti_copy_to(&tmp,res,dhl);

//     }  

// }
// // ----------------------------------------------------------------------------------------------------

// // ====================================================================================================
// // ====================================================================================================
// // ============================        DERIVATIVE EXTRACTOR FUNCTIONS       ===========================
// // ====================================================================================================
// // ====================================================================================================

// // ****************************************************************************************************
// void ssoti_set_deriv_r( coeff_t coef, imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl){
    
//     coeff_t factor = dhelp_get_deriv_factor(idx, order, dhl);

//     ssoti_set_im_r( coef/factor, idx, order, num, dhl);

// }
// // ----------------------------------------------------------------------------------------------------


// // ****************************************************************************************************
// coeff_t ssoti_get_deriv( imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl){

//     coeff_t coef   = ssoti_get_item(idx,order,num,dhl);
//     coeff_t factor = dhelp_get_deriv_factor(idx, order, dhl);

//     return coef*factor;
// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// semiotin_t ssoti_get_deriv_o( imdir_t idx, ord_t order, semiotin_t* num, dhelpl_t dhl){

//     semiotin_t res = ssoti_init();

//     // Set imaginary direction.
//     ssoti_get_deriv_to( idx, order, num, &res, dhl);
    
//     return res;

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_get_deriv_to( imdir_t idx, ord_t order, semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

//     coeff_t coef   = ssoti_get_item(idx,order,num,dhl);
//     coeff_t factor = dhelp_get_deriv_factor(idx, order, dhl);

//     ssoti_set_r( coef * factor, res, dhl);

// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// semiotin_t ssoti_extract_deriv(imdir_t idx, ord_t order, semiotin_t* num,  dhelpl_t dhl){

//     semiotin_t res = ssoti_init();

//     ssoti_extract_deriv_to(idx, order, num, &res, dhl);

//     return res;
// }
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void ssoti_extract_deriv_to(imdir_t idx, ord_t order, semiotin_t* num, semiotin_t* res, dhelpl_t dhl){
    
//     int  success;
//     ord_t   resord, ordi, ordj;
//     imdir_t residx;
//     coeff_t factornum, factorden;
//     ndir_t ndir_ordi, diri;
//     semiotin_t tmp;
    
//     if (order == 0){
        
//         // If getting the "real" part, it is the same number.
//         ssoti_set_o(num,res,dhl);
//         return;

//     } else if (order > num->act_order){

//         // If the requested order is greater, it will be zero.
//         ssoti_set_r(0.0, res, dhl);
//         return;

//     // Add another check to see if the number of bases is greater than the act_nbases from the number. 

//     } else {

//         // use temporal 0.
//         tmp = ssoti_get_tmp(0, num->trc_order - order, dhl);
        
//         // Get real part.
//         tmp.re = ssoti_get_item(idx, order, num, dhl) * dhelp_get_deriv_factor(idx, order, dhl);

//         // Set new order
//         tmp.act_order = num->act_order - order;

//         // loop for the remaining orders:
//         for( ordi = order; ordi < num->act_order; ordi++ ){

//             // Divide the remaining directions in the number by the requested direction            
//             ndir_ordi = num->p_nnz[ordi];

//             for ( diri = 0; diri< ndir_ordi; diri++){ 

//                 dhelp_div_imdir( num->p_idx[ordi][diri], ordi + 1, idx, order, &residx, &resord, &success, dhl);

//                 // if division was possible:
//                 if (success == 0){

//                     ordj = resord - 1;

//                     factornum = dhelp_get_deriv_factor(num->p_idx[ordi][diri], ordi+1, dhl);
//                     factorden = dhelp_get_deriv_factor(residx, resord, dhl);

//                     tmp.p_idx[ordj][tmp.p_nnz[ordj]] = residx;
//                     tmp.p_im[ ordj][tmp.p_nnz[ordj]] = num->p_im[ordi][diri] * (factornum/factorden);
//                     tmp.p_nnz[ordj]++;

//                 }

//             }

//         }

//         ssoti_copy_to(&tmp,res,dhl);
//     }    

// }
// // ----------------------------------------------------------------------------------------------------

// ====================================================================================================
// ====================================================================================================
// ===================================        HELPER FUNCTIONS       ==================================
// ====================================================================================================
// ====================================================================================================

// ****************************************************************************************************
inline void ssoti_reset_orders(ord_t ord_start, ord_t ord_end, semiotin_t* num, dhelpl_t dhl){
    
    ord_t ordi = 0;
    ord_t o_start = MIN(num->trc_order,ord_start);
    ord_t o_end   = MIN(num->trc_order,ord_end  );
    ndir_t ndir;

    if ( o_start == 0 ) {

        num->re = 0.0;
        o_start = 1;

    }

    // Loop among all orders in num to be reset.
    for (ordi = o_start-1; ordi < o_end; ordi++){
        
        ndir = dhl.p_dh[ordi].p_ndirs[num->act_nbases];
        
        memset( num->p_im[ordi], 0, ndir*sizeof(coeff_t) );

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void ssoti_reset_nbases(bases_t base_start, bases_t base_end, semiotin_t* num, dhelpl_t dhl){
    
    ord_t ordi = 0;
    bases_t b_start = MIN(num->tot_nbases,base_start);
    bases_t b_end   = MIN(num->tot_nbases,base_end  );
    ndir_t ndirs,ndire;

    // Loop among all orders in num.
    for (ordi = 0; ordi < num->act_order; ordi++){
        
        ndirs = dhl.p_dh[ordi].p_ndirs[base_start];
        ndire = dhl.p_dh[ordi].p_ndirs[base_end];
        
        memset( &num->p_im[ordi][ndirs], 0, (ndire-ndirs)*sizeof(coeff_t) );
        
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_print(semiotin_t* num, dhelpl_t dhl){

    imdir_t imdir;
    ndir_t ndirp,ndir=0;
    ord_t ordi;
    bases_t* imdir_bases;

    printf("<semiotin, ");
    printf("act_nbases: "_PBASEST", ",num->act_nbases);
    printf("act_order: "_PORDT", ",num->act_order); 
    printf("tot_nbases: "_PBASEST", ",num->tot_nbases); 
    printf("trc_order: "_PORDT",\n",num->trc_order); 
    
    // Print real direction:
    printf("    "_PCOEFFT" \n", num->re);

    // loop over active orders:
    for( ordi = 0; ordi < num->act_order; ordi++){
        ndirp = ndir;
        ndir = dhl.p_dh[ordi].p_ndirs[num->act_nbases];
        // printf("TOTAL NDIR: "_PNDIRT"\n", ndir );
        // printf("ADDRESS: %p and previous %p\n", num->p_im[ordi], num->p_im[ordi] - ndirp*sizeof(coeff_t) );

        // loop over active imaginary directions:
        for ( imdir = 0; imdir < ndir; imdir++){
            
            printf("  + " _PCOEFFT " * e(",  num->p_im[ordi][imdir]);

            imdir_bases = dhelp_get_imdir( imdir, ordi+1, dhl);
            
            printArrayUI16( imdir_bases, ordi+1 );

            printf(")\n");

        }

    }
    printf(">\n");

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline semiotin_t ssoti_get_rtmp(ndir_t ntmp, ord_t trc_order, dhelpl_t dhl){
    
    semiotin_t res=ssoti_init();
    ord_t ordi = 0;

    if (trc_order != 0){
        
        if (trc_order > dhl.ndh){
            printf("ERROR: Maximum order not allowed in ssoti_get_rtmp.\n");
            exit(OTI_undetErr);
        }
        if (ntmp >= dhl.p_dh[trc_order-1].Ntmps){
            printf("ERROR: Trying to get a temporal that does not exist.\n");
            exit(OTI_undetErr);   
        }
        res.re     = 0.0; // Set real value to zero.
        res.p_im   = dhl.p_dh[trc_order-1].p_ims[ntmp]; 
        res.act_nbases = 0; // Actual bases = 0, so "no imagianry direction..."
        res.tot_nbases = dhl.p_dh[trc_order-1].Nbasis;
        res.act_order = 0;
        res.trc_order = trc_order; 
        res.flag      = 0; // Memory is not owned by this number.

        for ( ordi = 0; ordi<trc_order; ordi++ ){

            res.p_im[ordi]  = dhl.p_dh[ordi].p_im[ntmp];

        }

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_get_tmp(ndir_t ntmp, ord_t trc_order, dhelpl_t dhl){
    
    return ssoti_get_rtmp( ntmp + 10, trc_order, dhl );

}
// ----------------------------------------------------------------------------------------------------

// ====================================================================================================
// ====================================================================================================
// ===================================        MEMORY MANAGEMENT      ==================================
// ====================================================================================================
// ====================================================================================================

// ****************************************************************************************************
void* ssoti_read_from_mem_to(void* mem, semiotin_t* dst, dhelpl_t dhl){

    // Mem must come allocated.
    ord_t ordi;
    ndir_t ndir;
    void* read_mem = mem;
    coeff_t re = 0.0;
    ord_t act_order = 0;
    ord_t trc_order = 0;
    bases_t act_nbases = 0;
    semiotin_t tmp;

    // read real coefficient:
    memcpy( &re, read_mem, sizeof(coeff_t) );
    read_mem += sizeof(coeff_t);

    // read truncation order:
    memcpy( &trc_order, read_mem, sizeof(ord_t) );
    read_mem += sizeof(ord_t);

    // read number of arrays order:
    memcpy( &act_order, read_mem, sizeof(ord_t) );
    read_mem += sizeof(ord_t);

    // read number of bases
    memcpy( &act_nbases, read_mem, sizeof(bases_t) );
    read_mem += sizeof(bases_t);

    // TODO: CHeck for compatibility of read values and data.
    tmp = ssoti_createEmpty( act_nbases, trc_order, dhl);
    tmp.re = re; // Set real coefficient.
    tmp.act_order = act_order;

    // Add the standard allocation sizes:
    for ( ordi = 0; ordi < tmp.act_order; ordi++){

        // Read number of directions.
        memcpy(  &ndir, read_mem, sizeof(ndir_t) );
        read_mem += sizeof(ndir_t);

        // read array of coefficients (if any):
        memcpy( tmp.p_im[ordi], read_mem, ndir*sizeof(coeff_t) );

        read_mem += ndir*sizeof(coeff_t);

    }

    // Copy to result. 
    // TODO: Avoid copying information, but only checking that it is possible to use memory in dst.
    ssoti_copy_to( &tmp, dst, dhl);
    return read_mem;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void ssoti_save_to_mem(semiotin_t* num, void* mem, dhelpl_t dhl){

    // Mem must come allocated.
    ord_t ordi;
    ndir_t ndir;
    void* write_mem = mem;

    // Write real coefficient:
    memcpy( write_mem, &num->re, sizeof(coeff_t) );
    write_mem += sizeof(coeff_t);

    // Write truncation order:
    memcpy( write_mem, &num->trc_order, sizeof(ord_t) );
    write_mem += sizeof(ord_t);

    // Write number of arrays:
    memcpy( write_mem, &num->act_order, sizeof(ord_t) );
    write_mem += sizeof(ord_t);

    // Write number of bases:
    memcpy( write_mem, &num->act_nbases, sizeof(bases_t) );
    write_mem += sizeof(bases_t);

    // Add the standard allocation sizes:
    for ( ordi = 0; ordi < num->act_order ; ordi++){

        ndir = dhl.p_dh[ordi].p_ndirs[num->act_nbases];

        // Write number of arrays order:
        // TODO: Can this be avoided to save a bit of space saving?
        memcpy( write_mem, &ndir, sizeof(ndir_t) );
        write_mem += sizeof(ndir_t);

        // Write array of coefficients:
        memcpy( write_mem, num->p_im[ordi], ndir*sizeof(coeff_t) );
        write_mem += ndir*sizeof(coeff_t);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
uint64_t ssoti_get_memsize_save(semiotin_t* num, dhelpl_t dhl){

    uint64_t mem_size = 0;
    ord_t i;
    ndir_t ndir;
    
    mem_size = sizeof(coeff_t) + // Real coefficient  
               sizeof(ord_t) +   // Actual order
               sizeof(ord_t) +   // Truncation order
               sizeof(bases_t);  // Actual number of bases.
                       

    // Add the standard allocation sizes:
    for ( i = 0 ; i < num->act_order ; i++){

        ndir = dhl.p_dh[i].p_ndirs[num->act_nbases];

        mem_size += sizeof(ndir_t) + ndir*( sizeof(coeff_t) ) ;

    }
    
    return mem_size;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
uint64_t ssoti_get_min_memsize(semiotin_t* num, dhelpl_t dhl){

    uint64_t allocation_size = 0;
    ord_t ordi;
    ndir_t ndir;
    
    // Get the allocation size of the OTI number:
    allocation_size = num->trc_order * ( 
        sizeof(coeff_t*)   // imaginary coefficients.
    );

    // Add only number of non zero.:
    for ( ordi = 0; ordi < num->act_order ; ordi++){
        
        ndir = dhl.p_dh[ordi].p_ndirs[num->act_nbases];

        allocation_size += ndir * ( sizeof(coeff_t) );

    }

    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
uint64_t ssoti_get_total_memsize(semiotin_t* num, dhelpl_t dhl){

    uint64_t allocation_size = 0;
    ord_t ordi;
    ndir_t ndir;

    // Get the allocation size of the OTI number:
    allocation_size = num->trc_order * (
        sizeof(coeff_t*) // imaginary coefficients.
    );

    // Add total allocation per order:
    for ( ordi = 0; ordi < num->trc_order; ordi++){
        
        ndir = dhl.p_dh[ordi].p_ndirs[num->tot_nbases];

        allocation_size += ndir * ( sizeof(coeff_t) );

    }

    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
uint8_t ssoti_requiresrealloc(semiotin_t* src, semiotin_t* dest){
    
    uint8_t reallocate = 0; // False

    // Check if reallocation is necessary
    if (src->act_order > dest->trc_order || src->act_nbases > dest->tot_nbases ) {
       
        reallocate = 0xFF; // True

    }

    return reallocate;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_copy_to(semiotin_t* src, semiotin_t* dest, dhelpl_t dhl){
        
    uint8_t reallocate = ssoti_requiresrealloc(src, dest);

    // TODO: Add check to wheather dest has not been initialized.
    // TODO: Add case when the two elements have different orders.
    // TODO: Add check if dest is a tmp function.

    if( reallocate ){
        // Reallocation IS required.
        // Easiest way: Free current memory in dest and allocate new memory.       

        if (dest->flag != 0){

            ssoti_free(dest);            
            (*dest) = ssoti_createEmpty_like( src, dhl );

        } else {

            // TODO: What happens if this is a tmp value?
            printf("ERROR: Cant change memory of the given number (function ssoti_copy_to(...) ) \n");
            exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.

        }

    }

    // At this point, both inputs must have same trc_order.
    ssoti_copy_nomemchk_to( src, dest, dhl);


}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void ssoti_copy_nomemchk_to(semiotin_t* src, semiotin_t* dest, dhelpl_t dhl){
    
    // Only recommended to use when using temporals.
    // when memory is guaranteed to be allocated.
    // Also, in this case, truncation order is not changed to the dest element.
    ord_t ordi;
    ndir_t ndir;

    // Copy real coefficient
    dest->re         = src->re;    
    dest->act_nbases = src->act_nbases; 
    dest->act_order  = src->act_order;

    // Copy imaginary coefficients
    for ( ordi = 0; ordi < src->act_order; ordi++){
        
        ndir = dhl.p_dh[ordi].p_ndirs[src->act_nbases];

        // Copy memory to dest number. Only copy non zeros.
        memcpy(dest->p_im[ordi], src->p_im[ordi], ndir*sizeof(coeff_t) );

    }  

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_copy(semiotin_t* num, dhelpl_t dhl){

    semiotin_t res = ssoti_createEmpty_like( num, dhl);

    ssoti_copy_nomemchk_to( num, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline semiotin_t ssoti_init(void){

    semiotin_t res;

    res.re        = 0.0;
    
    res.p_im      = NULL;

    res.act_nbases= 0;
    res.tot_nbases= 0;
    res.act_order = 0;
    res.trc_order = 0;

    res.flag=1;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_free(semiotin_t* num){
                
    if (num->p_im != NULL && num->flag != 0){
        free(num->p_im);
    }

    (*num) = ssoti_init();
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
semiotin_t ssoti_createReal(coeff_t num, bases_t tot_nbases, ord_t trc_order, dhelpl_t dhl){
    
    semiotin_t res = ssoti_createEmpty(tot_nbases, trc_order,dhl);

    res.re = num;

    return res;
}
// ----------------------------------------------------------------------------------------------------
 
// ****************************************************************************************************
semiotin_t ssoti_createEmpty( bases_t tot_nbases, ord_t trc_order, dhelpl_t dhl){
    
    semiotin_t res = ssoti_init();
    ord_t ordi;
    ndir_t ndir;
    ndir_t p_nnz[_MAXORDER_OTI]; 

    uint64_t allocation_size = 0;
    void * memory = NULL;
    
    res.tot_nbases= tot_nbases;
    res.trc_order = trc_order;

    
    // Get the number of *imaginary* directions for nbases and order.
    ndir = dhelp_extract_ndirTotal( tot_nbases, trc_order, dhl) - 1; // Excludes the real direction.
    // If this passes, it is safe to avoid function call dhelp_extract_ndirOrder.

    if (res.trc_order != 0 && res.tot_nbases != 0){

        // Get the allocation size of the OTI number:
        allocation_size  = res.trc_order*(sizeof(coeff_t*));


        // Add the standard allocation sizes:
        for ( ordi = 0; ordi<res.trc_order; ordi++){
            
            // dhl.p_dh[order-1].p_ndirs[nbases] <-- Location of nbases. Macro?
            p_nnz[ordi] = dhl.p_dh[ordi].p_ndirs[tot_nbases]; //dhelp_extract_ndirOrder( res.nbases,ordi+1,dhl);
            
            allocation_size += p_nnz[ordi]*(sizeof(coeff_t));

        }

        // Allocate memory and check if correctly allocated.
        memory = malloc(allocation_size);
        if ( memory == NULL ){
            printf("ERROR: Not enough memory to handle oti number.\n Exiting...\n");
            exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
        }

        // Distribute memory among the different pointers.
        res.p_im  = (coeff_t**)memory;
        memory   += res.trc_order * sizeof(coeff_t*);
        
        for ( ordi = 0; ordi < res.trc_order; ordi++){
            
            // Distribute memory.
            res.p_im[ordi] = (coeff_t*)memory;
            memory += p_nnz[ordi]*sizeof(coeff_t); 
            
        }

    } 

    // Raise memory ownership flag for OTI number.
    res.flag = 1;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_createEmpty_like( semiotin_t* other, dhelpl_t dhl){
    
    // This function assumes that 'other' is correctly allocated.
    semiotin_t res = ssoti_createEmpty(other->tot_nbases, other->trc_order, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_createEmpty_predef( bases_t nbases, ord_t trc_order, dhelpl_t dhl){
    
    semiotin_t res = ssoti_createEmpty(nbases, trc_order, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------
