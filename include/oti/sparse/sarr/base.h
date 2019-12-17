


// ****************************************************************************************************
sarr_t sarr_empty_like(sarr_t* arr, dhelpl_t dhl);
void sarr_copy_to(sarr_t* arr, sarr_t* res, dhelpl_t dhl);
sarr_t sarr_copy(sarr_t* arr, dhelpl_t dhl);

sarr_t sarr_eye_bases(uint64_t nrows, bases_t nbases, ord_t order, dhelpl_t dhl);
sarr_t sarr_ones_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
sarr_t sarr_zeros_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);

void sarr_set_all_r( coeff_t num, sarr_t* arr, dhelpl_t dhl);
void sarr_set_item_i_r( coeff_t num, uint64_t i, sarr_t* arr, dhelpl_t dhl);
void sarr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, sarr_t* arr, dhelpl_t dhl);

void sarr_set_all_o( sotinum_t* src, sarr_t* arr, dhelpl_t dhl);
void sarr_set_item_i_o( sotinum_t* num, uint64_t i, sarr_t* arr, dhelpl_t dhl);
void sarr_set_item_ij_o( sotinum_t* num, uint64_t i, uint64_t j, sarr_t* arr, dhelpl_t dhl);

sotinum_t sarr_get_item_i(sarr_t* arr, uint64_t i, dhelpl_t dhl);
sotinum_t sarr_get_item_ij(sarr_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl);



sarr_t sarr_init(void);
void sarr_free(sarr_t* arr);



sarr_t sarr_eye(uint64_t nrows, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
sarr_t sarr_ones(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);

/**************************************************************************************************//**
@brief Create an array filled with zeros, defined as sparse oti numbers. This is allocated given the
       number of imagianry directions per order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
sarr_t sarr_zeros(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an empty array of sparse oti numbers. This is allocated given the
       number of imagianry directions per order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
sarr_t sarr_createEmpty_predef(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an array filled with zeros, defined as sparse oti numbers. This is allocated given
       ammount of memory to allocate for each order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
size_t sarr_memory_size( uint64_t size, const ndir_t* p_nnz, ord_t order);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Create an array filled with zeros, defined as sparse oti numbers. This is allocated given
       ammount of memory to allocate for each order, in p_nnz.

@param[in] mem   Number of rows of the array.
@param[in] ncols Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order Truncation order of the array.
@param[in] dhl   Direction helper list object.
******************************************************************************************************/ 
void sarr_distribute_memory(void* mem, uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, 
    flag_t flag, sarr_t* res);
// ----------------------------------------------------------------------------------------------------
