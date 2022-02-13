// ****************************************************************************************************
void soti_get_active_bases(sotinum_t* num, imdir_t* list, dhelpl_t dhl){
    
    ord_t ordi, ordj;
    bases_t* imdir;
    uint64_t i;

    for( ordi = 0; ordi < num->act_order; ordi++){

        for ( i = 0; i< num->p_nnz[ordi]; i++){

            imdir = dhelp_get_imdir( num->p_idx[ordi][i], ordi+1, dhl);

            for( ordj = 0; ordj<ordi+1; ordj++){

                // Activate the imaginary direction.
                list[imdir[ordj]-1] = 1;

            }

        }

    }

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
bases_t soti_get_max_basis(sotinum_t* num, dhelpl_t dhl){
    
    ord_t ordi, ordj;
    bases_t* basisDir;
    bases_t max_basis = 0;
    uint64_t i;

    for( ordi = 0; ordi < num->act_order; ordi++){

        // Only check when there are some imaginary directions for the specific order.
        if (num->p_nnz[ordi]!=0){

            basisDir  = dhelp_get_imdir( num->p_idx[ordi][num->p_nnz[ordi]-1], ordi+1, dhl);    
            max_basis = MAX( basisDir[ordi], max_basis );

        }

    }

    return max_basis;

}
// ----------------------------------------------------------------------------------------------------

