// *******************************************************************************************************
inline soticore_t soticore_init(void){

    soticore_t res;

    res.flags[2] = 0;  // Memory ownership set to false.
    
    res.p_imidx   = NULL;
    res.p_bases   = NULL;
    res.p_ordptr  = NULL;

    return res;

}
// -------------------------------------------------------------------------------------------------------