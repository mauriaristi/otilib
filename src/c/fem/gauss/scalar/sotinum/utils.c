



// ****************************************************************************************************
inline void fesoti_dimCheck(fesoti_t* arr1,fesoti_t* arr2){

     if( arr1->nIntPts  != arr2->nIntPts ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fesoti arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------




