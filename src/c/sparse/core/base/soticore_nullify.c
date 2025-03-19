#ifndef OTI_SPARSE_CORE_BASE_SOTICORE_NULLIFY_C
#define OTI_SPARSE_CORE_BASE_SOTICORE_NULLIFY_C
// *******************************************************************************************************
inline soticore_t soticore_nullify(void){

    soticore_t res;

    res.flags[2] = 0;  // Memory ownership set to false.
    
    res.p_imidx   = NULL;
    res.p_bases   = NULL;
    res.p_ordptr  = NULL;

    return res;

}
// -------------------------------------------------------------------------------------------------------
#endif