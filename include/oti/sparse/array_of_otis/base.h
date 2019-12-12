


// ****************************************************************************************************

arrso_t arrso_eye_bases(uint64_t nrows, bases_t nbases, ord_t order, dhelpl_t dhl);
arrso_t arrso_ones_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
arrso_t arrso_zeros_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);

void arrso_set_all_r( coeff_t num, arrso_t* arr, dhelpl_t dhl);
void arrso_set_item_i_r( coeff_t num, uint64_t i, arrso_t* arr, dhelpl_t dhl);
void arrso_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl);

void arrso_set_all_o( sotinum_t* src, arrso_t* arr, dhelpl_t dhl);
void arrso_set_item_i_o( sotinum_t* num, uint64_t i, arrso_t* arr, dhelpl_t dhl);
void arrso_set_item_ij_o( sotinum_t* num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl);

sotinum_t arrso_get_item_i(arrso_t* arr, uint64_t i, dhelpl_t dhl);
sotinum_t arrso_get_item_ij(arrso_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl);



arrso_t arrso_init(void);
void arrso_free(arrso_t* arr);



arrso_t arrso_eye(uint64_t nrows, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
arrso_t arrso_ones(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);

/**************************************************************************************************//**
@brief Create an array filled with zeros, defined as sparse oti numbers. This is allocated given the
       number of imagianry directions per order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrso_t arrso_zeros(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
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
arrso_t arrso_createEmpty_predef(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
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
size_t arrso_memory_size( uint64_t size, const ndir_t* p_nnz, ord_t order);
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
void arrso_distribute_memory(void* mem, uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, 
    flag_t flag, arrso_t* res);
// ----------------------------------------------------------------------------------------------------
