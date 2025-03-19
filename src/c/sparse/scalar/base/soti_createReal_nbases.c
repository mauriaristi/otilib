// *******************************************************************************************************
sotinum_t soti_createReal_nbases(coeff_t num, bases_t nbases, ord_t order, dhelpl_t dhl){
    
    sotinum_t res = soti_allocateEmpty_predef( nbases, order, dhl);

    ord_t ordi;

    // set truncation order.
    res._oti.flags[0] = order; // truncation order.
    res._oti.flags[1] = 0; // Actual order

    res.p_coeff[0] = num;
    res._oti.p_imidx[0] = 0; // Imdir 0
    
    
    res._oti.p_ordptr[0] = 0; //  0
    res._oti.p_ordptr[1] = 1;
    
    return res;
}
// -------------------------------------------------------------------------------------------------------