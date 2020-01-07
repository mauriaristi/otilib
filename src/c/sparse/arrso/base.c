
// typedef struct {
//     coeff_t          re; ///< Real coefficient.
//     coeff_t**      p_im; ///< Array with all imaginary coefficients per order.
//     imdir_t**     p_idx; ///< Directions associated to each coefficient per order.
//     ndir_t*       p_nnz; ///< Number of non zero coefficients per order.
//     ndir_t*      p_size; ///< Allocated size per order.
//     ord_t         order; ///< Truncation order of the number.
//     flag_t         flag; ///< Memory flag.
// } sotinum_t;             ///< Sparse OTI number type

// typedef struct {
//     sotinum_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
// } sarr_t;                ///< Array of OTIs type.








// Copy operations.
// ****************************************************************************************************
void sarr_copy_to(sarr_t* arr, sarr_t* res, dhelpl_t dhl){

    sotinum_t* dummy_src, *dummy_dest;
    ord_t ordi;
    uint64_t i;
    // TODO: add allocation check.
    if(res->nrows != arr->nrows || res->ncols != arr->ncols || res->order != arr->order){
        printf("ERROR: Assignment mismatch in dimensions. Check destination.\n");
        exit(OTI_undetErr);
    }

    for (i=0; i<arr->size; i++){

        dummy_src      = &arr->p_data[i];
        dummy_dest     = &res->p_data[i];
        dummy_dest->re = dummy_src->re;

        for (ordi=0; ordi<arr->order; ordi++){
            memcpy(dummy_dest->p_im[ordi], dummy_src->p_im[ordi], dummy_src->p_nnz[ordi]*sizeof(coeff_t));
            memcpy(dummy_dest->p_idx[ordi],dummy_src->p_idx[ordi],dummy_src->p_nnz[ordi]*sizeof(imdir_t));
            dummy_dest->p_nnz[ordi] = dummy_src->p_nnz[ordi];
        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sarr_t sarr_copy(sarr_t* arr, dhelpl_t dhl){

    sarr_t res = sarr_empty_like(arr,dhl);

    sarr_copy_to(arr,&res,dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------








// Setters.
// Setter by one index.
// ****************************************************************************************************
void sarr_set_all_r( coeff_t num, sarr_t* arr, dhelpl_t dhl){
    
    uint64_t i;

    for (i = 0; i<arr->size; i++ ){        
        sarr_set_item_i_r( num, i, arr, dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void sarr_set_item_i_r( coeff_t num, uint64_t i, sarr_t* arr, dhelpl_t dhl){

    sotinum_t* dummy_sonum;
        
    dummy_sonum     = &arr->p_data[ i ];
    dummy_sonum->re = num;
    
    // Remove all imaginary directions.
    memset( dummy_sonum->p_nnz, 0, arr->order * sizeof(ndir_t) );

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void sarr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, sarr_t* arr, dhelpl_t dhl){

    sarr_set_item_i_r( num, j + i*arr->ncols, arr,  dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void sarr_set_all_o( sotinum_t* num, sarr_t* arr, dhelpl_t dhl){

    uint64_t i;

    // check first the requirement of reallocation.
    // If reallocation necessary, then  reallocate array.
    // if (src->order > arr->order){
    //     printf("ERROR: Unsupported operation (Array should be allocated correctly beforehand.)\nExiting.\n");
    //     exit( OTI_NotImplemented );
    // }
    for (i = 0; i<arr->size; i++ ){
        sarr_set_item_i_o( num, i, arr, dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void sarr_set_item_i_o( sotinum_t* src, uint64_t i, sarr_t* arr, dhelpl_t dhl){
    
    sotinum_t* dummy_sonum;
    ord_t ordi;    

    dummy_sonum     = &arr->p_data[ i ];
    dummy_sonum->re = src->re;

    // Copy imaginary coefficients
    for ( ordi = 0; ordi < src->order; ordi++){
        // Copy memory to dest number. Only copy non zeros.
        memcpy(dummy_sonum->p_im[ordi], src->p_im[ordi], src->p_nnz[ordi]*sizeof(coeff_t) );
        memcpy(dummy_sonum->p_idx[ordi],src->p_idx[ordi],src->p_nnz[ordi]*sizeof(imdir_t) );

        dummy_sonum->p_nnz[ordi] = src->p_nnz[ordi]; 
    }

    // Set all other elements in the imaginary directions to zero.
    for ( ; ordi<arr->order; ordi++ ){
        dummy_sonum->p_nnz[ordi] = 0;
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void sarr_set_item_ij_o( sotinum_t* num, uint64_t i, uint64_t j, sarr_t* arr, dhelpl_t dhl){

    sarr_set_item_i_o( num, j + i*arr->ncols, arr, dhl);

}
// ----------------------------------------------------------------------------------------------------











// Getters.
// ****************************************************************************************************
inline sotinum_t sarr_get_item_i(sarr_t* arr, uint64_t i, dhelpl_t dhl){
    
    sotinum_t res;
    sotinum_t* dummy_sonum;

    // Check boundness
    if (i < arr->size){

        dummy_sonum = &arr->p_data[i];

        res.re     = dummy_sonum->re;
        res.p_im   = dummy_sonum->p_im;
        res.p_idx  = dummy_sonum->p_idx;
        res.p_nnz  = dummy_sonum->p_nnz;
        res.p_size = arr->p_size;
        res.order  = arr->order;
        res.flag   = 0; // No ownership of memory.

    } else {

        res = soti_init();

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t sarr_get_item_ij(sarr_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl){

    sotinum_t res = sarr_get_item_i(arr, j + i*arr->ncols, dhl );

    return res;

}
// ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void oarr_get_item_i_to(oarr_t* arr, uint64_t i,  otinum_t* res, dhelpl_t dhl)
// // ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
// void oarr_get_item_ij_to(oarr_t* arr, uint64_t i, uint64_t j, otinum_t* res, dhelpl_t dhl)
// // ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
sarr_t sarr_eye_bases(uint64_t nrows, bases_t nbases, ord_t order, dhelpl_t dhl){

    ndir_t p_nnz[_MAXORDER_OTI];
    sarr_t  res;
    uint64_t i;
    ord_t ordi;

    for (ordi=0; ordi<order; ordi++){
        p_nnz[ordi] = dhelp_ndirOrder(nbases,ordi+1);
    }

    res = sarr_zeros( nrows, nrows, p_nnz, order, dhl);
    
    for (i=0; i<res.nrows; i++ ){
        res.p_data[ i + i*res.ncols ].re = 1.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sarr_t sarr_ones_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl){

    ndir_t p_nnz[_MAXORDER_OTI];
    sarr_t  res;
    uint64_t i;
    ord_t ordi;

    for (ordi=0; ordi<order; ordi++){
        p_nnz[ordi] = dhelp_ndirOrder(nbases,ordi+1);
    }

    res = sarr_createEmpty_predef(nrows, ncols, p_nnz, order, dhl);

    for (i=0; i<res.size; i++ ){
        res.p_data[i].re = 1.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sarr_t sarr_zeros_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl){

    ndir_t p_nnz[_MAXORDER_OTI];
    sarr_t  res;
    uint64_t i;
    ord_t ordi;

    for (ordi=0; ordi<order; ordi++){
        p_nnz[ordi] = dhelp_ndirOrder(nbases,ordi+1);
    }

    res = sarr_createEmpty_predef(nrows, ncols, p_nnz, order, dhl);

    for (i=0; i<res.size; i++ ){
        res.p_data[i].re = 0.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
sarr_t sarr_eye(uint64_t nrows, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl){

    sarr_t  res = sarr_zeros( nrows, nrows, p_nnz, order, dhl);
    uint64_t i;
    
    for (i=0; i<res.nrows; i++ ){
        
        res.p_data[ i + i*res.ncols ].re = 1.0;

    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sarr_t sarr_ones(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl){

    sarr_t  res = sarr_createEmpty_predef(nrows, ncols, p_nnz, order, dhl);
    uint64_t i;
    
    for (i=0; i<res.size; i++ ){
        res.p_data[i].re = 1.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sarr_t sarr_zeros(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl){

    sarr_t  res = sarr_createEmpty_predef(nrows, ncols, p_nnz, order, dhl);
    uint64_t i;
    
    for (i=0; i<res.size; i++ ){
        res.p_data[i].re = 0.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline sarr_t sarr_init(void){

    sarr_t res;

    res.p_data = NULL;
    res.p_size = NULL;
    res.nrows = 0;
    res.ncols = 0;
    res.size  = 0;
    res.flag  = 0;
    res.order = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void sarr_free(sarr_t* arr){
    
    if (arr->flag && 1){
        free(arr->p_data);
    }

    (*arr) = sarr_init();

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline sarr_t sarr_empty_like(sarr_t* arr, dhelpl_t dhl){

    sarr_t  res;
    res = sarr_createEmpty_predef(arr->nrows, arr->ncols, arr->p_size, arr->order, dhl);
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline sarr_t sarr_createEmpty_predef(uint64_t nrows, uint64_t ncols, 
                        const ndir_t* p_nnz, ord_t order, dhelpl_t dhl){

    sarr_t  res = sarr_init();
    void*    memory = NULL;
    size_t   allocation_size;

    allocation_size = sarr_memory_size( nrows * ncols, p_nnz, order);

    // Allocate memory and check if correctly allocated.
    memory = malloc(allocation_size);
    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of sparse otis.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }

    sarr_distribute_memory(memory, nrows, ncols, p_nnz, order, 1, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
size_t sarr_memory_size( uint64_t size, const ndir_t* p_nnz, ord_t order){

    size_t allocation_size = 0 ;
    ord_t  i = 0;


    allocation_size += size  * sizeof(sotinum_t); //  Memory for p_data.
    allocation_size += order * sizeof(ndir_t);  //  Memory for p_size.
    
    if (order != 0){
        
        // Get the allocation size of the OTI number:
        allocation_size += size * order * (sizeof(coeff_t*)+ // for p_im
                                          sizeof(imdir_t*)+ // for p_idx
                                          sizeof(ndir_t)    // for p_nnz
                                          );
                
        // Add the standard allocation sizes:
        for ( i = 0; i < order; i++){
            
            allocation_size += size * p_nnz[i] * ( sizeof(coeff_t)+ // for p_im[i]
                                                   sizeof(imdir_t)  // for p_idx[i]
                                                 );

        }
        
    }
    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void sarr_distribute_memory(void* mem, uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, 
    flag_t flag, sarr_t* res){
    // size_t allocation_size=0;
    uint64_t i;
    ord_t ordi;
    void* memory = mem;
    sotinum_t* dummy_sonum;

    // Set static elements accordingly.
    res->order = order;
    res->flag  = flag;
    res->nrows = nrows;
    res->ncols = ncols; 
    res->size  = nrows * ncols;

    // Distribute memory among the structur pointers.
    res->p_data  = (sotinum_t* )memory;
    memory    += res->size * sizeof(sotinum_t); // Move memory pointer.
    
    res->p_size  = (ndir_t*  )memory;
    memory    += res->order * sizeof(ndir_t);
    
    for ( ordi = 0; ordi < res->order; ordi++){
        // Set number allocated size.
        res->p_size[ordi] = p_nnz[ordi]; 
    }

    if (res->order != 0){
        // Loop to distribute memory through all elements of the array.
        for (i = 0; i < res->size; i++){
            dummy_sonum = &res->p_data[i];
            dummy_sonum->p_im  = (coeff_t**)memory;
            memory    += res->order * sizeof(coeff_t*);
            
            dummy_sonum->p_idx = (imdir_t**)memory;
            memory    += res->order * sizeof(imdir_t*);
            
            dummy_sonum->p_nnz = (ndir_t*  )memory;
            memory    += res->order * sizeof(ndir_t);
            
            for ( ordi = 0; ordi < res->order; ordi++){
            
                // Distribute memory.
                dummy_sonum->p_im[ordi] = (coeff_t*)memory;
                memory += p_nnz[ordi]*sizeof(coeff_t);                 

                dummy_sonum->p_idx[ordi]= (imdir_t*)memory;
                memory += p_nnz[ordi]*sizeof(imdir_t);                 

                // Set number of non-zero to 0.
                dummy_sonum->p_nnz[ordi]  = 0; 
            }

        }

    } else {

        // Loop to distribute memory through all elements of the array.
        for (i = 0; i < res->size; i++){

            res->p_data[i].p_im  = NULL;
            res->p_data[i].p_idx = NULL;
            res->p_data[i].p_nnz = NULL;

        }

    }

}
// ----------------------------------------------------------------------------------------------------

