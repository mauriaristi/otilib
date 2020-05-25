



// ****************************************************************************************************
inline void fesoti_dimCheck(fesoti_t* num1,fesoti_t* num){

     if( num1->nip  != num->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fesoti arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------




