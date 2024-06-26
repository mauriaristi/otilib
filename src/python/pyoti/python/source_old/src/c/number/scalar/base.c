
// ****************************************************************************************************
sotinum_t soti_taylor_integrate(coeff_t* deltas, sotinum_t* num){{
    
    
    sotinum_t res = soti_createEmpty( 0, dhl); 
    
    soti_taylor_integrate_to( deltas, num, &res, dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_taylor_integrate_to(coeff_t* deltas, sotinum_t* num, sotinum_t* res){{
    
    ord_t   ordi;
    ndir_t  ndir_ordi, diri;
    coeff_t val = 0.0, delta;
    
    val = num->re;
    
    for(ordi = 0; ordi < num->order ; ordi++ ){{

        // 
        ndir_ordi = num->p_nnz[ordi];

        for ( diri = 0; diri< ndir_ordi; diri++){{ 
            
            delta  = dhelp_compute_delta( num->p_idx[ordi][diri], ordi + 1, deltas, dhl);
            val   += num->p_im[ordi][diri] * delta;

        }}

    }}
    
    soti_set_r(val,res,dhl);

}}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
sotinum_t soti_get_order_im( ord_t order, sotinum_t* num){{

    sotinum_t res = soti_createEmpty( 0, dhl);

    // Set imaginary direction.
    soti_get_order_im_to( order, num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_get_order_im_to( ord_t order, sotinum_t* num, sotinum_t* res){{

    uint8_t reallocate = 0;

    // Copy real coefficient
    if (order == 0){{
    
        soti_set_r(0.0,res,dhl);
        res->re = num->re;
    
    }} else {{

        // Check if reallocation is necessary
        if (res->order < order ){{
            reallocate = 0xFF; // True
        }} else {{
            if ( num->p_nnz[order-1] > res->p_size[order-1] ){{
                reallocate = 0xFF; // True
            }}
        }}

        // TODO: Add check to wheather dest has not been initialized.
        // TODO: Add case when the two elements have different orders.
        // TODO: Add check if dest is a tmp function.

        if( reallocate ){{
            // Reallocation IS required.
            // Easiest way: Free current memory in dest and allocate new memory.
            if (res->flag != 0){{
                soti_free(res);  
                (*res) = soti_createEmpty_like( num, dhl);
            }} else {{
                // TODO: What happens if this is a tmp value?
                printf("ERROR: Cant change memory of the given number (function soti_copy_to(...) ) \n");
                exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
            }}
        }}

        // Set as zero, as well as all non-zero counters
        soti_set_r(0.0,res,dhl);

        if (order <= num->order){{
            
            // Copy only order.
            memcpy(res->p_im[order-1], num->p_im[order-1],  num->p_nnz[order-1]*sizeof(coeff_t) );
            memcpy(res->p_idx[order-1],num->p_idx[order-1], num->p_nnz[order-1]*sizeof(imdir_t) );

            res->p_nnz[order-1] = num->p_nnz[order-1]; 

        }}

    }}

}}
// ----------------------------------------------------------------------------------------------------


























// Setter.

// ****************************************************************************************************
void soti_insert_item( ndir_t pos, coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, 
    dhelpl_t dhl){{
    
    

    coeff_t* p_tmpim  = NULL;
    imdir_t* p_tmpidx = NULL;

    if ( num->p_nnz[order-1] == num->p_size[order-1] ){{
        // Reallocation in memory is necessary.

        num->p_nnz[order-1] += _REALLOC_SIZE;

        sotinum_t tmp = soti_createEmpty_like(num,dhl);

        num->p_nnz[order-1] -= _REALLOC_SIZE;
        
        soti_copy_to( num, &tmp, dhl);
        
        soti_free(num);
        
        *num = tmp;

    }}

    if (pos < num->p_nnz[order-1]){{
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
        
    }}

    // Set the new position.
    num->p_im[order-1][pos] = val;
    num->p_idx[order-1][pos] = idx;
    num->p_nnz[order-1] += 1;
    

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_set_item(coeff_t val, imdir_t idx, ord_t order, sotinum_t* num){{
    
    flag_t flag;
    imdir_t pos;
    
    if (order == 0){{
        
        num->re = val;

    }}else{{

        if ( order <= num->order ){{

            pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );

            if ( flag != 0 ){{

                // pos exists within num and already contains a value.
                num->p_im[order-1][pos] = val;

            }} else {{

                // pos is not contained within num, thus has to be inserted.
                soti_insert_item( pos, val, idx, order, num, dhl);

            }}

        }} // what happens if the order is greater than the number?
        // Change order and add one element to the specified order.

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_set_im_r(coeff_t val, imdir_t idx, ord_t order, sotinum_t* num){{
    
    flag_t flag;
    imdir_t pos;
    
    if (order == 0){{
        
        num->re = val;

    }}else{{

        if ( order <= num->order ){{

            pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );

            if ( flag != 0 ){{

                // pos exists within num and already contains a value.
                num->p_im[order-1][pos] = val;

            }} else {{

                // pos is not contained within num, thus has to be inserted.
                soti_insert_item( pos, val, idx, order, num, dhl);

            }}

        }} // what happens if the order is greater than the number?
        // Change order and add one element to the specified order.

    }}

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_set_deriv_o(sotinum_t* val, imdir_t idx, ord_t order, sotinum_t* num){{
    
    imdir_t idxr;
    ndir_t i;
    sotinum_t tmp;
    coeff_t factornum, factorden, value;
    ord_t res_order, ordi, ordr, ord_iter;
    
    if (order == 0){{
        
        soti_set_o( val, num, dhl);

    }}else{{

        res_order = MIN( dhl.ndh, MAX(num->order, order + val->order) );
        
        tmp = soti_get_tmp(0, res_order, dhl);

        // Copy to number. (TODO: Try to avoid this directly.)

        // soti_set_o(num, &tmp, dhl);
        ord_iter = MIN(num->order,res_order);
        
        for ( ordi = 0; ordi < ord_iter; ordi++){{
            
            // Copy memory to dest number. Only copy non zeros.
            memcpy(tmp.p_im[ordi], num->p_im[ordi], num->p_nnz[ordi]*sizeof(coeff_t) );
            memcpy(tmp.p_idx[ordi],num->p_idx[ordi],num->p_nnz[ordi]*sizeof(imdir_t) );

            tmp.p_nnz[ordi] = num->p_nnz[ordi];

        }}

        factorden = dhelp_get_deriv_factor(idx, order, dhl);
        
        soti_set_im_r(val->re/factorden, idx, order, &tmp, dhl);

        ord_iter = MIN(val->order,res_order-val->order);

        for ( ordi = 0; ordi < ord_iter; ordi++){{

            for (i = 0; i < val->p_nnz[ordi]; i++){{

                dhelp_multDir( idx, order, val->p_idx[ordi][i], ordi+1, &idxr, &ordr, dhl);

                factorden = dhelp_get_deriv_factor(idxr, ordr, dhl);
                factornum = dhelp_get_deriv_factor(val->p_idx[ordi][i], ordi+1, dhl);
                
                value = val->p_im[ordi][i] * factornum / factorden;
                
                soti_set_im_r( value, idxr, ordr, &tmp, dhl);
                
            }}
            
        }}

        // Copy back to number.
        soti_set_o( &tmp, num, dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_set_im_o(sotinum_t* val, imdir_t idx, ord_t order, sotinum_t* num){{
    
    imdir_t idxr;
    ndir_t i;
    sotinum_t tmp;

    ord_t res_order, ordi, ordr, ord_iter;
    
    if (order == 0){{
        
        soti_set_o( val, num, dhl);

    }}else{{

        res_order = MIN( dhl.ndh, MAX(num->order, order + val->order) );
        
        tmp = soti_get_tmp(0, res_order, dhl);

        // soti_set_o(num, &tmp, dhl);
        ord_iter = MIN(num->order,res_order);
        
        for ( ordi = 0; ordi < ord_iter; ordi++){{
            
            // Copy memory to dest number. Only copy non zeros.
            memcpy(tmp.p_im[ordi], num->p_im[ordi], num->p_nnz[ordi]*sizeof(coeff_t) );
            memcpy(tmp.p_idx[ordi],num->p_idx[ordi],num->p_nnz[ordi]*sizeof(imdir_t) );

            tmp.p_nnz[ordi] = num->p_nnz[ordi]; 

        }}            

        soti_set_im_r(val->re, idx, order, &tmp, dhl);

        ord_iter = MIN(val->order,res_order);

        for ( ordi = 0; ordi < ord_iter; ordi++) {{

            for (i =0; i<val->p_nnz[ordi]; i++){{

                dhelp_multDir( idx, order, val->p_idx[ordi][i], ordi+1, &idxr, &ordr, dhl);
                
                soti_set_im_r(val->p_im[ordi][i], idxr, ordr, &tmp, dhl);                
                
            }}
            
        }}

        soti_set_o( &tmp, num, dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_set_r( coeff_t a, sotinum_t* num){{
    
    ord_t i;
    num->re = a;

    for ( i = 0; i<num->order; i++){{
        // Set number of non-zero and allocated size to 0.
        num->p_nnz[i] = 0;
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_set_o( sotinum_t* src, sotinum_t* dest){{
    
    // This function sets an oti number from another OTI number.
    uint8_t reallocate = soti_requiresrealloc(src, dest);
    ord_t i;

    // TODO: Add check to wheather dest has not been initialized.
    // TODO: Add case when the two elements have different orders.
    // TODO: Add check if dest is a tmp function.

    if( reallocate ){{
        // Reallocation IS required.
        // Easiest way: Free current memory in dest and allocate new memory.
        
        if (dest->flag != 0){{

            soti_free(dest);  
            *dest = soti_createEmpty_like( src, dhl);        

        }} else {{

            // TODO: What happens if this is a tmp value?
            printf("ERROR: Cant change memory of given OTI number.\n");
            exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.

        }}

    }}

    // Copy real coefficient
    dest->re = src->re;

    // Copy imaginary coefficients
    for ( i = 0; i < src->order; i++){{
        // Copy memory to dest number. Only copy non zeros.
        memcpy(dest->p_im[i], src->p_im[i], src->p_nnz[i]*sizeof(coeff_t) );
        memcpy(dest->p_idx[i],src->p_idx[i],src->p_nnz[i]*sizeof(imdir_t) );

        dest->p_nnz[i] = src->p_nnz[i]; 
    }}

    // Set all other elements in the imaginary directions to zero.
    for (; i<dest->order;i++){{
        dest->p_nnz[i] = 0;
    }}

}}
// ----------------------------------------------------------------------------------------------------





























// Getters.
// Coefficient extractors.
// ****************************************************************************************************
coeff_t soti_get_item(imdir_t idx, ord_t order, sotinum_t* num){{
    
    coeff_t res = 0.0; // Default answer.
    flag_t flag;
    imdir_t pos;
    
    if (order == 0){{
        
        res = num->re;

    }} else {{

        if ( order<=num->order ){{            
            if(num->p_nnz[order-1] != 0){{
                pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );
                if (flag != 0){{
                    res = num->p_im[order-1][pos];
                }}
            }}
        }}

    }}

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
coeff_t soti_get_im(imdir_t idx, ord_t order, sotinum_t* num){{
    
    coeff_t res = 0.0; // Default answer.
    flag_t flag;
    imdir_t pos;
    
    if (order == 0){{
        
        res = num->re;

    }} else {{

        if ( order<=num->order ){{            
            if(num->p_nnz[order-1] != 0){{
                pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );
                if (flag != 0){{
                    res = num->p_im[order-1][pos];
                }}
            }}
        }}

    }}

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_get_im_o(imdir_t idx, ord_t order, sotinum_t* num){{
    
    sotinum_t res = soti_init();
    coeff_t rres = soti_get_im(idx, order, num, dhl);

    res.re = rres;

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_get_im_to_o(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res){{
    
    coeff_t rres = soti_get_im(idx, order, num, dhl);

    soti_set_r(rres,res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_get_im_to_r(imdir_t idx, ord_t order, sotinum_t* num, coeff_t* res){{
    
    *res = soti_get_im(idx, order, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_extract_im(imdir_t idx, ord_t order, sotinum_t* num,  dhelpl_t dhl){{

    sotinum_t res = soti_init();

    soti_extract_im_to(idx, order, num, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_extract_im_to(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res){{
    
    int  success;
    ord_t   resord, i, j;
    imdir_t residx;
    ndir_t ndir_ordi, diri;
    sotinum_t tmp;
    
    if (order == 0){{
        
        // If getting the "real" part, it is the same number.
        soti_set_o(num,res,dhl);

    }} else if (order > num->order){{

        // If the requested order is greater, it will be zero.
        soti_set_r(0.0, res, dhl);

    }} else {{

        // use temporal 0.
        tmp = soti_get_tmp(0, num->order-order, dhl);
        
        // Get real part.
        tmp.re = soti_get_item(idx, order, num, dhl);

        // loop for the remaining orders:
        for(i = order; i<num->order; i++){{

            // Divide the remaining directions in the number by the requested direction
            // 
            ndir_ordi = num->p_nnz[i];

            for ( diri = 0; diri< ndir_ordi; diri++){{ 

                dhelp_div_imdir( num->p_idx[i][diri], i + 1, idx, order, &residx, &resord, &success, dhl);
                // if derivative is possible:
                if (success == 0){{

                    j = resord-1;
                    
                    tmp.p_idx[j][tmp.p_nnz[j]] = residx;
                    tmp.p_im[ j][tmp.p_nnz[j]] = num->p_im[i][diri] ;
                    tmp.p_nnz[j]++;

                }}

            }}

        }}
        
        soti_copy_to(&tmp,res,dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_truncate_im(imdir_t idx, ord_t order, sotinum_t* num){{
    
    sotinum_t res = soti_init();

    soti_truncate_im_to( idx, order, num, &res, dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_truncate_im_to(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res){{
    
    int  success;
    ord_t   resord, i;
    imdir_t residx;
    ndir_t ndir_ordi, diri;
    sotinum_t tmp;
    // bases_t* imdir_bases;
    
    
    if (order == 0){{
        
        // All the number is truncated zero.
        soti_set_r( 0.0, res, dhl);
        return;

    }} else if (order > num->order){{
        
        // no need to truncate anything
        soti_set_o(num,res,dhl);
        return;

    }} else {{

        // use temporal 0.
        tmp = soti_get_tmp( 0, num->order, dhl);
        
        // Set real part.
        tmp.re = num->re;

        // First, copy all elements up to order - 1 .

        for(i = 0; i<order-1; i++){{
            
            memcpy(tmp.p_im[i], num->p_im[i], num->p_nnz[i]*sizeof(coeff_t) );
            memcpy(tmp.p_idx[i],num->p_idx[i],num->p_nnz[i]*sizeof(imdir_t) );

            tmp.p_nnz[i] = num->p_nnz[i]; 

        }}
        
        for(i = order-1; i< num->order ; i++){{

            // Divide the remaining directions in the number by the requested direction
            // 
            ndir_ordi = num->p_nnz[i];

            for ( diri = 0; diri< ndir_ordi; diri++){{ 

                dhelp_div_imdir( num->p_idx[i][diri], i + 1, idx, order, &residx, &resord, &success, dhl);
                
                // if derivative is not possible, number is preserved.
                if (success != 0){{
                    
                    tmp.p_idx[i][tmp.p_nnz[i]] = num->p_idx[i][diri];
                    tmp.p_im [i][tmp.p_nnz[i]] = num->p_im[i] [diri];
                    tmp.p_nnz[i]++;

                }}

            }}

        }}
        
        soti_copy_to(&tmp,res,dhl);

    }}  

}}
// ----------------------------------------------------------------------------------------------------


// Derivative extractors
// ****************************************************************************************************
void soti_set_deriv_r( coeff_t coef, imdir_t idx, ord_t order, sotinum_t* num){{
    
    coeff_t factor = dhelp_get_deriv_factor(idx, order, dhl);

    soti_set_im_r( coef/factor, idx, order, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
coeff_t soti_get_deriv( imdir_t idx, ord_t order, sotinum_t* num){{

    coeff_t coef   = soti_get_item(idx,order,num,dhl);
    coeff_t factor = dhelp_get_deriv_factor(idx, order, dhl);

    return coef*factor;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_get_deriv_o( imdir_t idx, ord_t order, sotinum_t* num){{

    sotinum_t res = soti_init();

    // Set imaginary direction.
    soti_get_deriv_to( idx, order, num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_get_deriv_to( imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res){{

    coeff_t coef   = soti_get_item(idx,order,num,dhl);
    coeff_t factor = dhelp_get_deriv_factor(idx, order, dhl);

    soti_set_r( coef * factor, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------
















// ****************************************************************************************************
sotinum_t soti_extract_deriv(imdir_t idx, ord_t order, sotinum_t* num,  dhelpl_t dhl){{

    sotinum_t res = soti_init();

    soti_extract_deriv_to(idx, order, num, &res, dhl);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_extract_deriv_to(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res){{
    
    int  success;
    ord_t   resord, i, j;
    imdir_t residx;
    coeff_t factornum, factorden;
    ndir_t ndir_ordi, diri;
    sotinum_t tmp;
    
    if (order == 0){{
        
        // If getting the "real" part, it is the same number.
        soti_set_o(num,res,dhl);
        return;

    }} else if (order > num->order){{

        // If the requested order is greater, it will be zero.
        soti_set_r(0.0, res, dhl);
        return;

    }} else {{

        // use temporal 0.
        tmp = soti_get_tmp(0, num->order-order, dhl);
        
        // Get real part.
        tmp.re = soti_get_item(idx, order, num, dhl) * dhelp_get_deriv_factor(idx, order, dhl);

        // loop for the remaining orders:
        for(i = order; i<num->order; i++){{

            // Divide the remaining directions in the number by the requested direction
            
            ndir_ordi = num->p_nnz[i];

            for ( diri = 0; diri< ndir_ordi; diri++){{ 

                dhelp_div_imdir( num->p_idx[i][diri], i + 1, idx, order, &residx, &resord, &success, dhl);
                // if derivative is possible:
                if (success == 0){{

                    j = resord-1;

                    factornum = dhelp_get_deriv_factor(num->p_idx[i][diri], i+1, dhl);
                    factorden = dhelp_get_deriv_factor(residx, resord, dhl);

                    tmp.p_idx[j][tmp.p_nnz[j]] = residx;
                    tmp.p_im[ j][tmp.p_nnz[j]] = num->p_im[i][diri] * (factornum/factorden);
                    tmp.p_nnz[j]++;

                }}

            }}

        }}
        soti_copy_to(&tmp,res,dhl);
    }}

    

}}
// ----------------------------------------------------------------------------------------------------





// Copy operations.

// ****************************************************************************************************
void soti_copy_to(sotinum_t* src, sotinum_t* dest){{
        
    uint8_t reallocate = soti_requiresrealloc(src, dest);
    ord_t i;

    // TODO: Add check to wheather dest has not been initialized.
    // TODO: Add case when the two elements have different orders.
    // TODO: Add check if dest is a tmp function.

    if( reallocate ){{
        // Reallocation IS required.
        // Easiest way: Free current memory in dest and allocate new memory.       

        if (dest->flag != 0){{

            soti_free(dest);            
            (*dest) = soti_createEmpty_like( src, dhl);

        }} else {{
            // TODO: What happens if this is a tmp value?
            printf("ERROR: Cant change memory of the given number (function soti_copy_to(...) ) \n");
            exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
        }}

    }}

    // Is it required to copy the order?
    // dest->order = src->order;

    // Copy real coefficient
    dest->re = src->re;

    // Copy imaginary coefficients
    for ( i = 0; i < src->order; i++){{
        
        // Copy memory to dest number. Only copy non zeros.
        memcpy(dest->p_im[i], src->p_im[i], src->p_nnz[i]*sizeof(coeff_t) );
        memcpy(dest->p_idx[i],src->p_idx[i],src->p_nnz[i]*sizeof(imdir_t) );

        dest->p_nnz[i] = src->p_nnz[i]; 

    }}  

    // Set all other elements in the imaginary directions to zero.
    for (; i<dest->order;i++){{
        dest->p_nnz[i] = 0;
    }}

}}
// ----------------------------------------------------------------------------------------------------







// ****************************************************************************************************
sotinum_t soti_copy(sotinum_t* num){{

    ord_t i;
    sotinum_t res = soti_createEmpty_like( num, dhl);

    res.re    = num->re;

    for ( i = 0; i < res.order; i++){{
        
        // Set number of non-zero and allocated size to 0.
        res.p_nnz[i]  = num->p_nnz[i]; // Just use nnz.
        
        if ( res.p_nnz[i] != 0 ){{

            // copy data.
            memcpy(res.p_im[i], num->p_im[i], res.p_nnz[i]*sizeof(coeff_t));
            memcpy(res.p_idx[i],num->p_idx[i],res.p_nnz[i]*sizeof(imdir_t));

        }}
    
    }}

    return res;

}}
// ----------------------------------------------------------------------------------------------------



// Helpers

// ****************************************************************************************************
void soti_print(sotinum_t* num){{

    ndir_t nnz_total = 1, dir;
    ord_t ordi,ord;
    bases_t* imdir_bases;
    
    for( ordi = 0; ordi<num->order; ordi++){{
        nnz_total += num->p_nnz[ordi];
    }}

    printf("  Order: "_PORDT", non_zero: "_PNDIRT", re: %11.4e\n",
        num->order, nnz_total, num->re);
    // printf("  ORD ,    IMDIR  ,   VALUE   \n");
    printf("      VALUE   ,    IMDIR  \n");

    // printf("    0 ,         0 , "_PCOEFFT"\n",num->re);
    printf("  " _PCOEFFT " , [0]\n",num->re);

    for( ord = 1; ord<=num->order; ord++){{

        ndir_t ndir_i = num->p_nnz[ord-1];

        for ( dir=0; dir< ndir_i; dir++){{
            
            // printf(" " _PORDT " , " _PNDIRT " ," _PCOEFFT "\n",
            printf("  " _PCOEFFT " , ",  num->p_im[ord-1][dir]);

            imdir_bases = dhelp_get_imdir( num->p_idx[ord-1][dir], ord, dhl);
            
            printArrayUI16( imdir_bases, ord);

            printf("\n");

        }}

    }}

}}
// ----------------------------------------------------------------------------------------------------






















// Memory management.

// ****************************************************************************************************
inline sotinum_t soti_init(void){{

    sotinum_t res;

    res.p_im  = NULL;
    res.p_idx = NULL;
    res.p_nnz = NULL;
    res.p_size= NULL;
    
    res.order  = 0;
    res.torder = 0;
    res.flag   = 1; 

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_createReal(coeff_t num, ord_t order){{
    
    sotinum_t res = soti_createEmpty(order,dhl);

    res.re = num;

    return res;
}}
// ----------------------------------------------------------------------------------------------------
 
// ****************************************************************************************************
sotinum_t soti_createEmpty( ord_t order){{
    
    sotinum_t res;
    
    ndir_t p_nnz[_MAXORDER_OTI]; 

    ord_t i;
    
    // Define allocation sizes.
    for ( i = 0; i < order; i++){{
        p_nnz[i] = dhl.p_dh[i].allocSize; // Get standard allocation sizes.
    }}
    
    res = soti_createEmpty_predef(p_nnz, order, dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
sotinum_t soti_createEmpty_like( sotinum_t* other){{
    
    // This function assumes that 'other' is correctly allocated.
    // Defines a new memory space from the p_nnz (not p_size) of the input sparse number.
    sotinum_t res = soti_createEmpty_predef(other->p_nnz, other->order, dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline sotinum_t soti_createEmpty_predef(ndir_t* p_nnz, ord_t order){{
    
    sotinum_t res = soti_init(); // Initialize pointer values.

    void * memory = NULL;
    uint64_t allocation_size = 0;
    ord_t i;

    res.order = order;
    
    if (res.order != 0){{

        // Get the allocation size of the OTI number:
        allocation_size = res.order*(sizeof(coeff_t*)+sizeof(imdir_t*)+sizeof(ndir_t)+sizeof(ndir_t));

        // Add the standard allocation sizes:
        for ( i = 0; i<res.order; i++){{
            
            allocation_size += p_nnz[i]*(sizeof(coeff_t)+sizeof(imdir_t));

        }}

        // Allocate memory and check if correctly allocated.
        memory = malloc(allocation_size);
        if ( memory == NULL ){{
            printf("ERROR: Not enough memory to handle oti number.\n Exiting...\n");
            exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
        }}

        // Distribute memory among the different pointers.
        res.p_im  = (coeff_t**)memory;
        memory    += res.order * sizeof(coeff_t*);

        res.p_idx = (imdir_t**)memory;
        memory    += res.order * sizeof(imdir_t*);

        res.p_nnz = (ndir_t*  )memory;
        memory    += res.order * sizeof(ndir_t);

        res.p_size= (ndir_t*  )memory;
        memory    += res.order * sizeof(ndir_t);
        
        for ( i = 0; i < res.order; i++){{
            
            // Distribute memory.
            res.p_im[i] = (coeff_t*)memory;
            memory += p_nnz[i]*sizeof(coeff_t); 

            res.p_idx[i]= (imdir_t*)memory;
            memory += p_nnz[i]*sizeof(imdir_t); 

            // Set number of non-zero and allocated size to 0.
            res.p_size[i] = p_nnz[i]; 
            res.p_nnz[i]  = 0; 

        }}

        // Raise flag for OTI number.
        res.flag = 1;

    }} 
    // Raise flag for OTI number.
    res.flag = 1;

    return res;

}}
// ----------------------------------------------------------------------------------------------------
