// *******************************************************************************************************
void soti_pprint(sotinum_t* num, dhelpl_t dhl){

    ndir_t ncoeffs, i;
    imdir_t dir;
    ord_t ordi, act_order, trc_order;
    bases_t* imdir_bases;

    if (num->p_coeff != NULL ) {
        
        trc_order = num->_oti.flags[0];
        act_order = num->_oti.flags[1];

        ncoeffs = num->_oti.ncoeff;
        
        printf("  act_ord: "_PORDT", trc_ord: "_PORDT", non_zero: "_PNDIRT", re: %11.4e\n",
            act_order, trc_order, ncoeffs, num->p_coeff[0]);
        
        

        if (num->_oti.p_ordptr != NULL && num->_oti.p_imidx != NULL){
            
            printf("      VALUE   ,    IMDIR  \n");

            // loop over active orders:
            for( ordi = 0; ordi <= act_order; ordi++){

                // loop over active imaginary directions:
                for ( i = num->_oti.p_ordptr[ordi]; i< num->_oti.p_ordptr[ordi+1]; i++){
                    
                    printf("  " _PCOEFFT " , ",  num->p_coeff[i]);
                    dir = num->_oti.p_imidx[i];

                    // printf(" ("_PIMDIRT","_PORDT")",dir,ordi);
                    imdir_bases = dhelp_get_imdir( dir, ordi, dhl);
                    
                    printArrayUI16( imdir_bases, ordi);

                    printf("\n");

                }

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------