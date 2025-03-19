// *******************************************************************************************************
size_t soticore_memory_size( ndir_t nimdir, bases_t nbases, ord_t order){

    size_t mem_size = 0;
    
    mem_size = ( (size_t)  nimdir    ) * sizeof(imdir_t) +
               ( (size_t)  nbases    ) * sizeof(bases_t) +
               ( (size_t)  (order+2) ) * sizeof(ndir_t)  ;

    return mem_size;

}
// -------------------------------------------------------------------------------------------------------