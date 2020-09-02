

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_FF_samesize(feoarrm0n0_t* arr1,feoarrm0n0_t* arr2,feonumm0n0_t* res){

     if( arr1->size != arr2->size || arr1->nip != arr2->nip || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm0n0 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_OF_samesize(oarrm0n0_t* arr1,feoarrm0n0_t* arr2, feonumm0n0_t* res){

     if( arr1->size != arr2->size || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm0n0 and real arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_RF_samesize(darr_t* arr1, feoarrm0n0_t* arr2, feonumm0n0_t* res){

    if( arr1->size != arr2->size || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm0n0 and real arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_FF_elementwise(feoarrm0n0_t* arr1,feoarrm0n0_t* arr2,feoarrm0n0_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm0n0 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_fF_elementwise(feonumm0n0_t* arr1,feoarrm0n0_t* arr2,feoarrm0n0_t* res){

     if( arr2->size !=  res->size || arr2->ncols !=  res->ncols || arr2->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm0n0 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_Ff_elementwise(feoarrm0n0_t* arr1,feonumm0n0_t* arr2,feoarrm0n0_t* res){

     if( arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm0n0 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_OF_elementwise(oarrm0n0_t* arr1,feoarrm0n0_t* arr2, feoarrm0n0_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr2->nip !=  res->nip   ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm0n0 and real arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_RF_elementwise(darr_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res){

    if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
        arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
        arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm0n0 and real arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_FfO_integrate(feoarrm0n0_t* arr,feonumm0n0_t* num,oarrm0n0_t* res){

     if( arr->size !=  res->size || arr->ncols != res->ncols || arr->nrows != res->nrows ||
         arr->nip != num->nip   ){
        printf("ERROR: Wrong dimensions in integration operation between two feoarrm0n0 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_FF_matmul( feoarrm0n0_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip || 
        arr2->nip !=  res->nip      ){
       printf("ERROR: Wrong dimensions in matmul-like operation between two feoarrm0n0 arrays.\n");
       exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_OF_matmul( oarrm0n0_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and feoarrm0n0 arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_RF_matmul( darr_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and feoarrm0n0 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_FO_matmul( feoarrm0n0_t* arr1, oarrm0n0_t* arr2, feoarrm0n0_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip    ){
        printf("ERROR: Wrong dimensions in matmul-like operation between feoarrm0n0 and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_FR_matmul( feoarrm0n0_t* arr1, darr_t* arr2, feoarrm0n0_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip     ){
        printf("ERROR: Wrong dimensions in matmul-like operation between feoarrm0n0 and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_F_squareness( feoarrm0n0_t* arr1, feoarrm0n0_t* res){

    if( arr1->ncols != arr1->nrows ||
        arr1->nrows !=  res->nrows || 
        arr1->ncols !=  res->ncols ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: feoarrm0n0 array not square.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm0n0_dimCheck_F_transpose( feoarrm0n0_t* arr1, feoarrm0n0_t* res){

    if( arr1->nrows !=  res->ncols || 
        arr1->ncols !=  res->nrows ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: feoarrm0n0 array not compliant with transpose operation.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm0n0_get_active_bases(feoarrm0n0_t* arr, imdir_t* list_vals){
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<arr->nip; i++ ){
        
        oarrm0n0_get_active_bases( &arr->p_data[i], list_vals);
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

