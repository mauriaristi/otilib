
// ****************************************************************************************************
inline void fedarr_dimCheck_FF_elementwise(fedarr_t* arr1,fedarr_t* arr2,fedarr_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fedarr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fedarr_dimCheck_fF_elementwise(fednum_t* arr1,fedarr_t* arr2,fedarr_t* res){

     if( arr2->size !=  res->size || arr2->ncols !=  res->ncols || arr2->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fedarr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fedarr_dimCheck_Ff_elementwise(fedarr_t* arr1,fednum_t* arr2,fedarr_t* res){

     if( arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fedarr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fedarr_dimCheck_RF_elementwise(darr_t* arr1, fedarr_t* arr2, fedarr_t* res){

    if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
        arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
        arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between fedarr and real arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
inline void fedarr_dimCheck_FfR_integrate(fedarr_t* arr,fednum_t* num, darr_t* res){

     if( arr->size !=  res->size || arr->ncols != res->ncols || arr->nrows != res->nrows ||
         arr->nip != num->nip   ){
        printf("ERROR: Wrong dimensions in integration operation between two fedarr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void fedarr_dimCheck_FF_matmul( fedarr_t* arr1, fedarr_t* arr2, fedarr_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip || 
        arr2->nip !=  res->nip      ){
       printf("ERROR: Wrong dimensions in matmul-like operation between two fedarr arrays.\n");
       exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fedarr_dimCheck_RF_matmul( darr_t* arr1, fedarr_t* arr2, fedarr_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and fedarr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fedarr_dimCheck_FR_matmul( fedarr_t* arr1, darr_t* arr2, fedarr_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip     ){
        printf("ERROR: Wrong dimensions in matmul-like operation between fedarr and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------












// ****************************************************************************************************
inline void fedarr_dimCheck_F_squareness( fedarr_t* arr1, fedarr_t* res){

    if( arr1->ncols != arr1->nrows ||
        arr1->nrows !=  res->nrows || 
        arr1->ncols !=  res->ncols ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: fedarr array not square.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline void fedarr_dimCheck_F_transpose( fedarr_t* arr1, fedarr_t* res){

    if( arr1->nrows !=  res->ncols || 
        arr1->ncols !=  res->nrows ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: fedarr array not compliant with transpose operation.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

