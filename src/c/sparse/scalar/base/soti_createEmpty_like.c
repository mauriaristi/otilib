// *******************************************************************************************************
sotinum_t soti_createEmpty_like( sotinum_t* other, dhelpl_t dhl){
    
    // This function assumes that 'other' is correctly allocated.
    // Defines a new memory space from the p_nnz (not p_size) of the input sparse number.

    sotinum_t res = soti_allocateEmpty_ndirtot(
        other->_oti.ncoeff, 
        other->_oti.nbases, 
        other->_oti.flags[1], 
        dhl
    );

    memcpy(res._oti.p_bases,other->_oti.p_bases,other->_oti.nbases);

    return res;

}
// -------------------------------------------------------------------------------------------------------
