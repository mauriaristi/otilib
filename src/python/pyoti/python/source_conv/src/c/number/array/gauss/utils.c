

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_FF_samesize({fearr_type}* arr1,{fearr_type}* arr2,{fenum_type}* res){{

     if( arr1->size != arr2->size || arr1->nip != arr2->nip || arr2->nip != res->nip ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two {fearr_func} arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_OF_samesize({arr_type}* arr1,{fearr_type}* arr2, {fenum_type}* res){{

     if( arr1->size != arr2->size || arr2->nip != res->nip ){{
        printf("ERROR: Wrong dimensions in elementwise operation between {fearr_func} and real arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_RF_samesize(darr_t* arr1, {fearr_type}* arr2, {fenum_type}* res){{

    if( arr1->size != arr2->size || arr2->nip != res->nip ){{
        printf("ERROR: Wrong dimensions in elementwise operation between {fearr_func} and real arrays.\n");
        exit(OTI_BadDim);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_FF_elementwise({fearr_type}* arr1,{fearr_type}* arr2,{fearr_type}* res){{

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two {fearr_func} arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_fF_elementwise({fenum_type}* arr1,{fearr_type}* arr2,{fearr_type}* res){{

     if( arr2->size !=  res->size || arr2->ncols !=  res->ncols || arr2->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two {fearr_func} arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_Ff_elementwise({fearr_type}* arr1,{fenum_type}* arr2,{fearr_type}* res){{

     if( arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two {fearr_func} arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_OF_elementwise({arr_type}* arr1,{fearr_type}* arr2, {fearr_type}* res){{

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr2->nip !=  res->nip   ){{
        printf("ERROR: Wrong dimensions in elementwise operation between {fearr_func} and real arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_RF_elementwise(darr_t* arr1, {fearr_type}* arr2, {fearr_type}* res){{

    if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
        arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
        arr2->nip != res->nip                         ){{
        printf("ERROR: Wrong dimensions in elementwise operation between {fearr_func} and real arrays.\n");
        exit(OTI_BadDim);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_FfO_integrate({fearr_type}* arr,{fenum_type}* num,{arr_type}* res){{

     if( arr->size !=  res->size || arr->ncols != res->ncols || arr->nrows != res->nrows ||
         arr->nip != num->nip   ){{
        printf("ERROR: Wrong dimensions in integration operation between two {fearr_func} arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_FF_matmul( {fearr_type}* arr1, {fearr_type}* arr2, {fearr_type}* res){{

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip || 
        arr2->nip !=  res->nip      ){{
       printf("ERROR: Wrong dimensions in matmul-like operation between two {fearr_func} arrays.\n");
       exit(OTI_BadDim);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_OF_matmul( {arr_type}* arr1, {fearr_type}* arr2, {fearr_type}* res){{

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and {fearr_func} arrays.\n");
        exit(OTI_BadDim);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_RF_matmul( darr_t* arr1, {fearr_type}* arr2, {fearr_type}* res){{

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and {fearr_func} arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_FO_matmul( {fearr_type}* arr1, {arr_type}* arr2, {fearr_type}* res){{

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip    ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between {fearr_func} and darr arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_FR_matmul( {fearr_type}* arr1, darr_t* arr2, {fearr_type}* res){{

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip     ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between {fearr_func} and darr arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_F_squareness( {fearr_type}* arr1, {fearr_type}* res){{

    if( arr1->ncols != arr1->nrows ||
        arr1->nrows !=  res->nrows || 
        arr1->ncols !=  res->ncols ||
        arr1->nip !=  res->nip   ){{
        printf("ERROR: {fearr_func} array not square.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {fearr_func}_dimCheck_F_transpose( {fearr_type}* arr1, {fearr_type}* res){{

    if( arr1->nrows !=  res->ncols || 
        arr1->ncols !=  res->nrows ||
        arr1->nip !=  res->nip   ){{
        printf("ERROR: {fearr_func} array not compliant with transpose operation.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_get_active_bases({fearr_type}* arr, imdir_t* list_vals){{
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<arr->nip; i++ ){{
        
        {arr_func}_get_active_bases( &arr->p_data[i], list_vals);
    
    }}
    
}}
// ----------------------------------------------------------------------------------------------------

