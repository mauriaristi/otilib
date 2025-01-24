#ifndef OTI_SPARSE_CORE_BASE_C
#define OTI_SPARSE_CORE_BASE_C

// MEMORY MANAGEMENT 

// *******************************************************************************************************
inline soticore_t soticore_init(void){

    soticore_t res;

    soticore_initialize(&res);

    return res;

}
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
inline void soticore_initialize(soticore_t* res){

    int8_t i;

    
    res->nbases    = 0;   // No actual bases, this p_bases = NULL.
    res->ncoeff    = 1;   // Only 1 coefficient.
    
    // Set all flags to 0.
    for (i=0; i<8; i++){
        // res.flags[0]  = 0;   // Truncation order.
        // res.flags[1]  = 0;   // actual order.
        // res.flags[2]  = 0;   // Memory ownership.
       res->flags[i] = 0; 
    }

    res->p_imidx   = &res->nbases; // Address of  nbases. Gets p_imdir[0]=0.
    res->p_bases   = NULL;
    res->p_ordptr  = &res->nbases; // Picks up p_ordptr[0] = 0, p_ordptr[1] = 1

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
inline flag_t soticore_get_memory_ownership( soticore_t* num ){

    return num->flags[2] ;

}
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
inline void soticore_set_memory_ownership( soticore_t* num ){

    num->flags[2] =  OTI_memory_is_owned;

}
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
inline void soticore_unset_memory_ownership( soticore_t* num ){

    num->flags[2] =  OTI_memory_not_owned;

}
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void soticore_set_all_imidx( const bases_t* bases, soticore_t* obj,  dhelpl_t dhl){

    
    ord_t ordi, order;
    ndir_t ndir;
    imdir_t idx, idx_map;

    order = obj->flags[1]; // Actual order
    
    // This needs a temporal array with the total number of bases. This might need to be created via an
    // allocation call.
    
    obj->p_ordptr[0] = 0;
    
    for ( ordi = 1; ordi <= order+1; ordi++){
        
        ndir = dhelp_ndirOrder( obj->nbases, ordi);

        obj->p_ordptr[ordi] = obj->p_ordptr[ordi-1] + ndir;

        // Loop to set all indices to the corresponding values from bases.
        // Maybe use some parallelism here.
        for (idx = 0; idx<ndir; idx ++ ){
            
            // This map index function must be as efficient as possible.
            idx_map = dhelp_map_index( idx, ordi, bases, dhl);
            obj->p_imidx[idx] = idx_map;

        }



    }

}
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
size_t soticore_memory_size( ndir_t nimdir, bases_t nbases, ord_t order){

    size_t mem_size = 0;
    
    mem_size = ( (size_t)  nimdir    ) * sizeof(imdir_t) +
               ( (size_t)  nbases    ) * sizeof(imdir_t) +
               ( (size_t)  (order+1) ) * sizeof(imdir_t)  ;

    return mem_size;

}
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void* soticore_distribute_memory( void* mem, soticore_t* res ){

    ord_t order = res->flags[1]; // Extract order
    void* memory = mem;

    // // Distribute memory among the different pointers.
    // res->p_coeff  = (coeff_t* ) memory;
    // memory    += res->ncoeff * sizeof(coeff_t*);

    res->p_imidx = (imdir_t*  ) memory;
    memory    += res->ncoeff * sizeof(imdir_t);

    res->p_bases = (bases_t*  ) memory;
    memory    += res->nbases * sizeof(bases_t);

    res->p_ordptr= (ndir_t*   ) memory;
    memory    += ( order + 1  ) * sizeof(ndir_t); // This must reach the end of the memory block.

    // If necessary, returns end of memory.
    return memory;

}
// -------------------------------------------------------------------------------------------------------
#endif