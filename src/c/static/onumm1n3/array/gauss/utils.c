

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_FF_samesize(feoarrm1n3_t* arr1,feoarrm1n3_t* arr2,feonumm1n3_t* res){

     if( arr1->size != arr2->size || arr1->nip != arr2->nip || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm1n3 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_OF_samesize(oarrm1n3_t* arr1,feoarrm1n3_t* arr2, feonumm1n3_t* res){

     if( arr1->size != arr2->size || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm1n3 and real arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_RF_samesize(darr_t* arr1, feoarrm1n3_t* arr2, feonumm1n3_t* res){

    if( arr1->size != arr2->size || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm1n3 and real arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_FF_elementwise(feoarrm1n3_t* arr1,feoarrm1n3_t* arr2,feoarrm1n3_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm1n3 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_fF_elementwise(feonumm1n3_t* arr1,feoarrm1n3_t* arr2,feoarrm1n3_t* res){

     if( arr2->size !=  res->size || arr2->ncols !=  res->ncols || arr2->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm1n3 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_Ff_elementwise(feoarrm1n3_t* arr1,feonumm1n3_t* arr2,feoarrm1n3_t* res){

     if( arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm1n3 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_OF_elementwise(oarrm1n3_t* arr1,feoarrm1n3_t* arr2, feoarrm1n3_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr2->nip !=  res->nip   ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm1n3 and real arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_RF_elementwise(darr_t* arr1, feoarrm1n3_t* arr2, feoarrm1n3_t* res){

    if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
        arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
        arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm1n3 and real arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_FfO_integrate(feoarrm1n3_t* arr,feonumm1n3_t* num,oarrm1n3_t* res){

     if( arr->size !=  res->size || arr->ncols != res->ncols || arr->nrows != res->nrows ||
         arr->nip != num->nip   ){
        printf("ERROR: Wrong dimensions in integration operation between two feoarrm1n3 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_FF_matmul( feoarrm1n3_t* arr1, feoarrm1n3_t* arr2, feoarrm1n3_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip || 
        arr2->nip !=  res->nip      ){
       printf("ERROR: Wrong dimensions in matmul-like operation between two feoarrm1n3 arrays.\n");
       exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_OF_matmul( oarrm1n3_t* arr1, feoarrm1n3_t* arr2, feoarrm1n3_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and feoarrm1n3 arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_RF_matmul( darr_t* arr1, feoarrm1n3_t* arr2, feoarrm1n3_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and feoarrm1n3 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_FO_matmul( feoarrm1n3_t* arr1, oarrm1n3_t* arr2, feoarrm1n3_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip    ){
        printf("ERROR: Wrong dimensions in matmul-like operation between feoarrm1n3 and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_FR_matmul( feoarrm1n3_t* arr1, darr_t* arr2, feoarrm1n3_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip     ){
        printf("ERROR: Wrong dimensions in matmul-like operation between feoarrm1n3 and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_F_squareness( feoarrm1n3_t* arr1, feoarrm1n3_t* res){

    if( arr1->ncols != arr1->nrows ||
        arr1->nrows !=  res->nrows || 
        arr1->ncols !=  res->ncols ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: feoarrm1n3 array not square.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm1n3_dimCheck_F_transpose( feoarrm1n3_t* arr1, feoarrm1n3_t* res){

    if( arr1->nrows !=  res->ncols || 
        arr1->ncols !=  res->nrows ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: feoarrm1n3 array not compliant with transpose operation.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm1n3_get_active_bases(feoarrm1n3_t* arr, imdir_t* list_vals){
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<arr->nip; i++ ){
        
        oarrm1n3_get_active_bases( &arr->p_data[i], list_vals);
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

