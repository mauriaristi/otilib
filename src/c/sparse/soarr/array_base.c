
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
// } soarr_t;                ///< SOTI array type.





// ****************************************************************************************************
size_t soarr_memory_size( uint64_t size, ndir_t* p_nnz, ord_t order){

    size_t allocation_size = 0 ;
    ord_t i = 0;


    allocation_size += order * sizeof(ndir_t);    //  Memory for common size array.
    allocation_size += size  * sizeof(sotinum_t); //  Memory for all elements .

    if (order != 0){
        
        // Get the allocation size of the OTI number:
        allocation_size = size * order * (sizeof(coeff_t*)+ // for p_im
                                          sizeof(imdir_t*)+ // for p_idx
                                          sizeof(ndir_t)+   // for p_nnz
                                          );

        // Add the standard allocation sizes:
        for ( i = 0; i < order; i++){
            
            allocation_size += size * p_nnz[i] * ( sizeof(coeff_t)+
                                                   sizeof(imdir_t)
                                                 );

        }

    }

    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_distribute_memory(void* memory, ndir_t* p_nnz, ord_t order, flag_t flag, sotinum_t* res){

    ord_t i;

    res->order = order;

    // Distribute memory among the different pointers.
    res->p_im  = (coeff_t**)memory;
    memory    += res->order * sizeof(coeff_t*);

    res->p_idx = (imdir_t**)memory;
    memory    += res->order * sizeof(imdir_t*);

    res->p_nnz = (ndir_t*  )memory;
    memory    += res->order * sizeof(ndir_t);

    res->p_size= (ndir_t*  )memory;
    memory    += res->order * sizeof(ndir_t);
    
    for ( i = 0; i < res->order; i++){
        
        // Distribute memory.
        res->p_im[i] = (coeff_t*)memory;
        memory += p_nnz[i]*sizeof(coeff_t); 

        res->p_idx[i]= (imdir_t*)memory;
        memory += p_nnz[i]*sizeof(imdir_t); 

        // Set number of non-zero and allocated size to 0.
        res->p_size[i] = p_nnz[i]; 
        res->p_nnz[i]  = 0; 

    }

    // Raise flag for OTI number.
    res->flag = flag;

}
// ----------------------------------------------------------------------------------------------------
























































































// Setters.
// Setter by one index.
// ****************************************************************************************************
void oarr_set_all_r( coeff_t num, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_set_item_i_r( coeff_t num, uint64_t i, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_set_all_o( otinum_t* num, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_set_item_i_o( otinum_t* num, uint64_t i, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_set_item_ij_o( otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------


// Getters.
// ****************************************************************************************************
otinum_t oarr_get_item_i(oarr_t* arr, uint64_t i, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oarr_get_item_ij(oarr_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_get_item_i_to(oarr_t* arr, uint64_t i,  otinum_t* res, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_get_item_ij_to(oarr_t* arr, uint64_t i, uint64_t j, otinum_t* res, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------


// Copy operations.
// ****************************************************************************************************
void oarr_copy_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_copy(oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// Helpers.

// Memory management.
// ****************************************************************************************************
soarr_t oarr_eye(uint64_t size, bases_t nbases, ord_t order, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
soarr_t oarr_ones(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
soarr_t oarr_zeros(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_free(soarr_t* arr)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
soarr_t oarr_createEmpty( uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------





