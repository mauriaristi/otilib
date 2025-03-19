// *******************************************************************************************************
inline sotinum_t soti_allocateEmpty_predef(bases_t nbases, ord_t order, dhelpl_t dhl ){
    
    char fnName[] = "soti_allocateEmpty_predef"; // Function Name for error management.

    ndir_t ncoeff;
    sotinum_t res;

    // Get the total number of coefficients for this number.
    // TODO: Use dhl's mehtod to get ndirtotal (significantly faster)
    
    ncoeff = dhelp_ndirTotal( nbases, order );
    
    res = soti_allocateEmpty_ndirtot( ncoeff, nbases, order, dhl );

    return res;

}
// -------------------------------------------------------------------------------------------------------