// ****************************************************************************************************
sotmpl_t sotmpl_setup_sodhl( dhelpl_t dhl){
    
    sodhl_t res;
    ndir_t ntmp, i;
    ord_t ndhl, ordi, trc_order;

    res.p_data = NULL;
    res.nTmps  = 0;

    // Get the number of direction helpers
    if( dhl.ndh > 1){
        
        ntmp = dhl.p_dh[0].Ntmps; // Extract the number of temporals.
        trc_order = dhl.ndh;
        res.p_data = (sotinum_t*)malloc(ntmp*sizeof(sotinum_t));

        for (i=0;i<nTmps;i++){
            
            // Get the temporals for every element and organize t
            res.p_im   = dhl.p_dh[trc_order-1].p_ims[i]; 
            res.p_idx  = dhl.p_dh[trc_order-1].p_ids[i]; 
            res.p_nnz  = dhl.p_dh[trc_order-1].p_nnz[i]; 
            res.p_size = dhl.p_dh[trc_order-1].p_size[i]; 
            res.act_order = 0;
            res.trc_order = trc_order; 
            res.flag      = 0; // Memory is not owned by this number.

            for ( ordi = 0; ordi<trc_order; ordi++ ){

                res.p_im[ordi]  = dhl.p_dh[ordi].p_im[i];
                res.p_idx[ordi] = dhl.p_dh[ordi].p_idx[i];
                res.p_nnz[ordi] = 0                  ; // Initialize to zero elements.
                res.p_size[ordi]= dhl.p_dh[ordi].Ndir;

            }
        }
    }

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotmpl_t sotmpl_free( sotmpl_t* sotmpl){
    
    
    if (sotmpl->p_data != NULL){
        free(sotmpl->p_data);
    }
    sotmpl->p_data = NULL;
    res->nTmps  = 0;
    
}
// ----------------------------------------------------------------------------------------------------