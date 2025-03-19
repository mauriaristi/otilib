// *******************************************************************************************************
sotinum_t soti_createEmpty_bases( const bases_t* bases, bases_t nbases, ord_t order, dhelpl_t dhl){
    
    sotinum_t res;
    
    res = soti_allocateEmpty_predef(nbases, order, dhl);

    // Set imaginary directions according to nbases, order and the list of bases.
    
    soticore_set_all_imidx( bases, &res._oti,  dhl);
       
    return res;

}
// -------------------------------------------------------------------------------------------------------