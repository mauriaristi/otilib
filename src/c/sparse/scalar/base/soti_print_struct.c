// *******************************************************************************************************
void soti_print_struct(sotinum_t* num, dhelpl_t dhl){

    printf(" sotinum_t.re:           %11.4e <at %p> \n", num->re, &num->re);
    printf(" sotinum_t.p_coeff:      %p \n", num->p_coeff  );
    printf(" sotinum_t._oti:         <at %p> \n", &num->_oti );
    printf(" sotinum_t._oti.nbases:  "_PNDIRT" <at %p> \n", num->_oti.nbases, &num->_oti.nbases );
    printf(" sotinum_t._oti.ncoeff:  "_PNDIRT" <at %p> \n", num->_oti.ncoeff, &num->_oti.ncoeff );
    printf(" sotinum_t._oti.flags:   <at %p> ", &num->_oti.flags);
        printArrayUI8( num->_oti.flags, 8); 
        printf("\n");
    printf(" sotinum_t._oti.p_imidx:  %p, ", num->_oti.p_imidx);
        printArrayUI64( num->_oti.p_imidx, num->_oti.ncoeff); 
        printf("\n");
    printf(" sotinum_t._oti.p_bases:  %p, ", num->_oti.p_bases);
        printArrayUI64( num->_oti.p_bases, num->_oti.nbases);  
        printf("\n");
    printf(" sotinum_t._oti.p_ordptr: %p, ", num->_oti.p_ordptr);
        printArrayUI64( num->_oti.p_ordptr, num->_oti.flags[0]+2);  
        printf("\n");
}
// -------------------------------------------------------------------------------------------------------