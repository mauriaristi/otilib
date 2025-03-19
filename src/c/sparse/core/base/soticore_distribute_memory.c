#ifndef OTI_SPARSE_CORE_BASE_SOTICORE_DISTRIBUTE_MEMORY_C
#define OTI_SPARSE_CORE_BASE_SOTICORE_DISTRIBUTE_MEMORY_C
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