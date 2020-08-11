

// ****************************************************************************************************
inline void fednum_dimCheck(fednum_t* num1,fednum_t* num){

     if( num1->nip  != num->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fesoti arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------
