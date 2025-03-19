// *******************************************************************************************************
void soti_free(sotinum_t* num){

    flag_t memory_flag = soticore_get_memory_ownership( &num->_oti);

    if ( memory_flag != OTI_memory_not_owned ){
        // Memory contained in a single memory block within p_coeff
        free(num->p_coeff);
    }
    
    // Re-initialize number for safety.
    soti_initialize(num);
    
    
}
// -------------------------------------------------------------------------------------------------------