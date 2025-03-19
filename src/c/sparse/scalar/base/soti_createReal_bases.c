// *******************************************************************************************************
sotinum_t soti_createReal_bases(coeff_t num, const bases_t* bases, bases_t nbases, ord_t order, 
    dhelpl_t dhl){

sotinum_t res = soti_createEmpty_bases(bases, nbases, order, dhl);

res.p_coeff[0] = num;

// set all imaginary coeffs as 0.
memset( &res.p_coeff[1], 0, ( res._oti.ncoeff - 1 )*sizeof(coeff_t) );

return res;
}
// -------------------------------------------------------------------------------------------------------