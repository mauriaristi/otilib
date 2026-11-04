
// ****************************************************************************************************
// Number of elements of the range start, start + step, ... before stop (Python's
// len(range(start, stop, step))); 0 for an empty range. Same rule and arithmetic as slice_size() in
// src/c/core/utils.c (kept as a copy: this legacy unit does not include oti/core/utils.h).
// W4 fix round 2 (critic F11): the old (stop - start - 1) / step + 1 gave 1 for start == stop with
// |step| >= 2 and 0 or a negative size for a reversed range, and -step overflowed for INT64_MIN. The
// distance and the step's magnitude are taken in uint64_t (no overflow for any int64_t input); a count
// above INT64_MAX (a range wider than INT64_MAX with |step| <= 2) saturates to INT64_MAX.
inline int64_t get_slice_size(int64_t start, int64_t stop, int64_t step){

    uint64_t dist, mag, size;

    if (step > 0){

        if (stop <= start){
            return 0;
        }
        dist = (uint64_t)stop - (uint64_t)start;
        mag  = (uint64_t)step;

    } else if (step < 0){

        if (start <= stop){
            return 0;
        }
        dist = (uint64_t)start - (uint64_t)stop;
        mag  = (uint64_t)0 - (uint64_t)step;

    } else {

        printf("ERROR: Slice step cannot be zero.");
        exit(OTI_BadIndx);

    }

    size = (dist - 1) / mag + 1;

    return size > (uint64_t)INT64_MAX ? INT64_MAX : (int64_t)size;
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

