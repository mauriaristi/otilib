#ifndef OTI_SPARSE_CORE_BASE_SOTICORE_INITIALIZE_C
#define OTI_SPARSE_CORE_BASE_SOTICORE_INITIALIZE_C
// *******************************************************************************************************
inline void soticore_initialize(soticore_t* res){

    int8_t i;
    
    res->nbases    = 0;   // No actual bases, this p_bases = NULL.
    res->ncoeff    = 1;   // Only 1 coefficient.
    
    // TODO: Consider memset?
    // Set all flags to 0.
    for (i=0; i<8; i++){
        // res.flags[0]  = 0;   // Truncation order.
        // res.flags[1]  = 0;   // actual order.
        // res.flags[2]  = 0;   // Memory ownership.
       res->flags[i] = 0; 
    }

    res->p_imidx   = &res->nbases; // Address of nbases. Gets p_imdir[0]=0.
    res->p_bases   = NULL;
    res->p_ordptr  = &res->nbases; // Picks up p_ordptr[0] = 0, p_ordptr[1]=1

}
// -------------------------------------------------------------------------------------------------------
#endif
