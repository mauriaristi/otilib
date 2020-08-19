
// ****************************************************************************************************
inline void {fenum_func}_dimCheck({fenum_type}* num1,{fenum_type}* num){{

     if( num1->nip  != num->nip ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two {fenum_func} numbers.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------
