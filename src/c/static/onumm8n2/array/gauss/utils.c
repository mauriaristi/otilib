

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_FF_samesize(feoarrm8n2_t* arr1,feoarrm8n2_t* arr2,feonumm8n2_t* res){

     if( arr1->size != arr2->size || arr1->nip != arr2->nip || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm8n2 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_OF_samesize(oarrm8n2_t* arr1,feoarrm8n2_t* arr2, feonumm8n2_t* res){

     if( arr1->size != arr2->size || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm8n2 and real arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_RF_samesize(darr_t* arr1, feoarrm8n2_t* arr2, feonumm8n2_t* res){

    if( arr1->size != arr2->size || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm8n2 and real arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_FF_elementwise(feoarrm8n2_t* arr1,feoarrm8n2_t* arr2,feoarrm8n2_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm8n2 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_fF_elementwise(feonumm8n2_t* arr1,feoarrm8n2_t* arr2,feoarrm8n2_t* res){

     if( arr2->size !=  res->size || arr2->ncols !=  res->ncols || arr2->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm8n2 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_Ff_elementwise(feoarrm8n2_t* arr1,feonumm8n2_t* arr2,feoarrm8n2_t* res){

     if( arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feoarrm8n2 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_OF_elementwise(oarrm8n2_t* arr1,feoarrm8n2_t* arr2, feoarrm8n2_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr2->nip !=  res->nip   ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm8n2 and real arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_RF_elementwise(darr_t* arr1, feoarrm8n2_t* arr2, feoarrm8n2_t* res){

    if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
        arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
        arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between feoarrm8n2 and real arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_FfO_integrate(feoarrm8n2_t* arr,feonumm8n2_t* num,oarrm8n2_t* res){

     if( arr->size !=  res->size || arr->ncols != res->ncols || arr->nrows != res->nrows ||
         arr->nip != num->nip   ){
        printf("ERROR: Wrong dimensions in integration operation between two feoarrm8n2 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_FF_matmul( feoarrm8n2_t* arr1, feoarrm8n2_t* arr2, feoarrm8n2_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip || 
        arr2->nip !=  res->nip      ){
       printf("ERROR: Wrong dimensions in matmul-like operation between two feoarrm8n2 arrays.\n");
       exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_OF_matmul( oarrm8n2_t* arr1, feoarrm8n2_t* arr2, feoarrm8n2_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and feoarrm8n2 arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_RF_matmul( darr_t* arr1, feoarrm8n2_t* arr2, feoarrm8n2_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and feoarrm8n2 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_FO_matmul( feoarrm8n2_t* arr1, oarrm8n2_t* arr2, feoarrm8n2_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip    ){
        printf("ERROR: Wrong dimensions in matmul-like operation between feoarrm8n2 and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_FR_matmul( feoarrm8n2_t* arr1, darr_t* arr2, feoarrm8n2_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip     ){
        printf("ERROR: Wrong dimensions in matmul-like operation between feoarrm8n2 and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_F_squareness( feoarrm8n2_t* arr1, feoarrm8n2_t* res){

    if( arr1->ncols != arr1->nrows ||
        arr1->nrows !=  res->nrows || 
        arr1->ncols !=  res->ncols ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: feoarrm8n2 array not square.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void feoarrm8n2_dimCheck_F_transpose( feoarrm8n2_t* arr1, feoarrm8n2_t* res){

    if( arr1->nrows !=  res->ncols || 
        arr1->ncols !=  res->nrows ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: feoarrm8n2 array not compliant with transpose operation.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feoarrm8n2_get_active_bases(feoarrm8n2_t* arr, imdir_t* list_vals){
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<arr->nip; i++ ){
        
        oarrm8n2_get_active_bases( &arr->p_data[i], list_vals);
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

