// *******************************************************************************************************
size_t soti_memory_size( ndir_t nimdir, bases_t nbases, ord_t order){

    size_t allocation_size = 0;
    
    allocation_size =   ((size_t)  nimdir    ) * ( sizeof(coeff_t) )  +
                        soticore_memory_size( nimdir, nbases, order); // From the _oti structure.
                        

    return allocation_size;

}
// -------------------------------------------------------------------------------------------------------