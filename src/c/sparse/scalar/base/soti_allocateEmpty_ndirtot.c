// *******************************************************************************************************
inline sotinum_t soti_allocateEmpty_ndirtot(ndir_t ncoeff, bases_t nbases, ord_t order, dhelpl_t dhl ){
    
    char fnName[] = "soti_allocateEmpty_ndirtot"; // Function Name for error management.

    sotinum_t res = soti_init(); // Initialize pointer values.

    void * memory = NULL;
    uint64_t allocation_size = 0;
        
        
    res._oti.flags[0] = order; // Truncation order
    res._oti.flags[1] = order; // Actual order

    res._oti.nbases = nbases;

    // Get the total number of coefficients for this number.
    res._oti.ncoeff = ncoeff;        

    // Get the allocation size of the OTI number:
    allocation_size = soti_memory_size( ncoeff, nbases, order);

    // Allocate memory and check if correctly allocated.
    memory = malloc(allocation_size);

    if ( memory == NULL ){

        printf("ERROR(%s): Not enough memory to handle OTI number.\n Exiting...\n",fnName);
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.

    }

    memory = soti_distribute_memory( memory, &res );
    
    // Set flag that memory is owned.
    soti_set_memory_ownership(&res);

    return res;

}
// -------------------------------------------------------------------------------------------------------