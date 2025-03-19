// *******************************************************************************************************
void* soti_distribute_memory( void* mem, sotinum_t* res ){

    ord_t i;
    void* memory = mem;

    // Distribute memory among the different pointers.
    res->p_coeff  = (coeff_t*)memory;
    memory    += res->_oti.ncoeff * sizeof(coeff_t);

    memory = soticore_distribute_memory( memory, &res->_oti );

    // If necessary, returns end of memory.
    return memory;

}
// -------------------------------------------------------------------------------------------------------