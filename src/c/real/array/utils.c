
// ****************************************************************************************************
inline int64_t get_slice_size(int64_t start, int64_t stop, int64_t step){
    
    uint64_t size;

    if (step > 0){      

        size =  ( ( stop - start - 1 ) / step + 1);

    } else if (step < 0){

        size =  ( ( start - stop - 1 ) / ( - step ) + 1);

    } else {

        printf("ERROR: Slice step cannot be zero.");
        exit(OTI_BadIndx);

    }

    return size;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void darr_dimCheck_RR_samesize(darr_t* arr1,darr_t* arr2){

     if( arr1->size != arr2->size ){
        printf("ERROR: Wrong dimensions in dot product operation between two darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darr_dimCheck_RR_elementwise(darr_t* arr1,darr_t* arr2,darr_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows   ){
        printf("ERROR: Wrong dimensions in elementwise operation between two darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darr_dimCheck_RR_matmul( darr_t* arr1, darr_t* arr2, darr_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols   ){
       printf("ERROR: Wrong dimensions in matmul-like operation between two darr arrays.\n");
       exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darr_dimCheck_R_squareness( darr_t* arr1, darr_t* res){

    if( arr1->ncols != arr1->nrows ||
        arr1->nrows !=  res->nrows || 
        arr1->ncols !=  res->ncols   ){
        printf("ERROR: darr array not square.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void darr_dimCheck_F_transpose( darr_t* arr1, darr_t* res){

    if( arr1->nrows !=  res->ncols || 
        arr1->ncols !=  res->nrows   ){
        printf("ERROR: darr array not compliant with transpose operation.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

