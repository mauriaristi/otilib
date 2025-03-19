// *******************************************************************************************************
void soticore_set_all_imidx( const bases_t* bases, soticore_t* obj,  dhelpl_t dhl){

    
    ord_t ordi, order;
    ndir_t ndir, st_pos;
    imdir_t idx, idx_map;

    order = obj->flags[1]; // Actual order
    
    // This needs a temporal array with the total number of bases. This might need to be created via an
    // allocation call.
    
    obj->p_ordptr[0] = 0; // Starting point of all components (dummy?).
    obj->p_imidx[0]  = 0; // Real direction.
    
    obj->p_ordptr[1] = 1;
    
    for ( ordi = 1; ordi <= order; ordi++){
        
        ndir = dhelp_ndirOrder( obj->nbases, ordi);
        st_pos = obj->p_ordptr[ordi]; // Starting point of all elements of order ordi.
        obj->p_ordptr[ordi+1] = st_pos + ndir;

        // Loop to set all indices to the corresponding values from bases.
        // Maybe use some parallelism here.
        for (idx = 0; idx<ndir; idx ++ ){
            
            // This map index function must be as efficient as possible.
            idx_map = dhelp_map_index( idx, ordi, bases, dhl);
            obj->p_imidx[st_pos+idx] = idx_map;

        }

    }

    
}
// -------------------------------------------------------------------------------------------------------