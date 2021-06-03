
// ****************************************************************************************************
void soti_trunc_smul_real(coeff_t a, ord_t ord, sotinum_t* res, dhelpl_t dhl){
    
    ord_t ordi;
    ndir_t i;

    if (a == 0.0){
        
        for (  ordi = ord-1; ordi < res->order; ordi++){

            res->p_nnz[ordi]=0.0;

        }

    } else {

        for (  ordi = ord-1; ordi < res->order; ordi++){

            for ( i=0; i<res->p_nnz[ordi]; i++){
                
                res->p_im[ordi][i] *= a;

            }

        }

    }    

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_trunc_ssum(sotinum_t* num1, ord_t ord, sotinum_t* res, dhelpl_t dhl ){
    
    // Initialize
    ord_t ordi;

    // TODO: Add check to the resulting value.
    sotinum_t tmpres = soti_get_rtmp(6,res->torder,dhl); 
    
    soti_set_o(res, &tmpres, dhl);

    tmpres.order = MAX(tmpres.order, num1->order);
    
    for (  ordi = ord-1; ordi < num1->order; ordi++){

        dhelp_sparse_add_dirs(num1->p_im[ordi],  num1->p_idx[ordi],   num1->p_nnz[ordi],
                               res->p_im[ordi],   res->p_idx[ordi],    res->p_nnz[ordi],
                             tmpres.p_im[ordi], tmpres.p_idx[ordi], &tmpres.p_nnz[ordi], dhl);

    }

    soti_set_trunc( &tmpres, ord, res, dhl);
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_trunc_mul(sotinum_t* num1, ord_t ord1, 
                    sotinum_t* num2, ord_t ord2, 
                    sotinum_t* dest, dhelpl_t dhl ){

    sotinum_t tmp, tmp2, tmp3;
    sotinum_t* tmpsrc=  &tmp ;
    sotinum_t* tmpdest= &tmp3;
    sotinum_t* tmpswap;
    ord_t res_ord = MAX(num1->torder,num2->torder);
    ord_t ordlim1, ordlim2;
    ord_t ordi1, ordi2, ordires;

    // Retreive sotinum temporals.
    // All tmps are created with no elements in imaginary directions (but allocated).
    tmp = soti_get_rtmp(3,res_ord,dhl); // will hold the final result.
    tmp2= soti_get_rtmp(4,res_ord,dhl); // Will hold the temporary result.
    tmp3= soti_get_rtmp(5,res_ord,dhl); // Will hold the temporary result.    
    
    res_ord = MIN(num1->order + num2->order, res_ord );
    tmp.order = res_ord;
    tmp2.order= res_ord;
    tmp3.order= res_ord;


    ordlim1 = MIN(num1->order, res_ord - 1);
    
    for(ordi1=ord1-1; ordi1<ordlim1; ordi1++){

        ordlim2 = MIN(num2->order, res_ord - (ordi1+1) );

        tmpswap = tmpsrc; tmpsrc=tmpdest; tmpdest=tmpswap;

        // printf("Lim ord2: %hhu\n",ordlim2);
        for (ordi2=ord2-1; ordi2<ordlim2; ordi2++){

            ordires = ordi1 + ordi2 + 1;

            dhelp_sparse_mult(num1->p_im[ordi1  ], num1->p_idx[ordi1  ], num1->p_nnz[ordi1  ], ordi1+1,
                              num2->p_im[ordi2  ], num2->p_idx[ordi2  ], num2->p_nnz[ordi2  ], ordi2+1,
                               tmp2.p_im[ordires],  tmp2.p_idx[ordires], &tmp2.p_nnz[ordires],     dhl );
            
            dhelp_sparse_add_dirs(    tmp2.p_im[ordires],     tmp2.p_idx[ordires],      tmp2.p_nnz[ordires],
                                   tmpsrc->p_im[ordires],  tmpsrc->p_idx[ordires],   tmpsrc->p_nnz[ordires],
                                  tmpdest->p_im[ordires], tmpdest->p_idx[ordires], &tmpdest->p_nnz[ordires], dhl);
            
        }

        ordires = ordi1+ord2;

        tmpsrc->p_im[ ordires] = tmpdest->p_im[ ordires];
        tmpsrc->p_idx[ordires] = tmpdest->p_idx[ordires];
        tmpsrc->p_nnz[ordires] = tmpdest->p_nnz[ordires];

    }
    

    soti_set_trunc( tmpdest, ord1+ord2-1, dest, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_set_trunc( sotinum_t* src, ord_t ord, sotinum_t* dest, dhelpl_t dhl){
    
    // Assumes both have the space allocated and both have the same truncation order
    ord_t i;
    
    dest->order = MAX(src->order,dest->order);

    for ( i = ord-1; i<src->order; i++){
        
        // Set number of non-zero and allocated size to 0.
        dest->p_nnz[i]  = src->p_nnz[i];

        memcpy(dest->p_im[i], src->p_im[i], dest->p_nnz[i]*sizeof(coeff_t));
        memcpy(dest->p_idx[i],src->p_idx[i],dest->p_nnz[i]*sizeof(imdir_t));

    }

}
// ----------------------------------------------------------------------------------------------------