// *******************************************************************************************************
inline void soti_initialize(sotinum_t* res){
    
    // NOTE: This assumes that the res structure comes initializied with soti_init().

    // Real part not modified.
    res->p_coeff   = &res->re;     // Address of the real coefficient. This corresponds to the starting 
                                  // memory for all the memory for OTI number. 
    soticore_initialize(&res->_oti);

}
// -------------------------------------------------------------------------------------------------------