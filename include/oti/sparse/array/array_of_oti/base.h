#ifndef OTI_SPARSE_ARRAY_BASE_H
#define OTI_SPARSE_ARRAY_BASE_H


/**************************************************************************************************//**
@brief Copy an existing array. Data is copied to the new memory.

@param[in] arr    Address of array from which to get data.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
void arrso_copy_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);
arrso_t arrso_copy(arrso_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Setter functions. These functions sets the specified elements of an array given a real number.

******************************************************************************************************/ 
void arrso_set_all_r( coeff_t num, arrso_t* arr, dhelpl_t dhl);
void arrso_set_item_i_r( coeff_t num, uint64_t i, arrso_t* arr, dhelpl_t dhl);
void arrso_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Setter functions. These functions sets the specified elements of an array given an OTI number.

******************************************************************************************************/ 
void arrso_set_all_o( sotinum_t* src, arrso_t* arr, dhelpl_t dhl);
void arrso_set_item_i_o( sotinum_t* num, uint64_t i, arrso_t* arr, dhelpl_t dhl);
void arrso_set_item_ij_o( sotinum_t* num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Getter functions. These functions extract a member of the array.

******************************************************************************************************/ 
sotinum_t arrso_get_item_i(arrso_t* arr, uint64_t i, dhelpl_t dhl);
sotinum_t arrso_get_item_ij(arrso_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Initialization of the arrso_t type. In this case, all pointers are initialized to NULL to avoid
       unwanted segmentation faults.

       Usage is as follows:
       arrso_t myArray = arrso_init();

******************************************************************************************************/ 
arrso_t arrso_init(void);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of the arrso_t type. In this case, all pointers are initialized to NULL to avoid
       unwanted segmentation faults.

       Usage is as follows:
       arrso_t myArray = arrso_init();

******************************************************************************************************/ 
void arrso_free(arrso_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an empty array similar in order, allocation size and shape from the given array.

@param[in] arr    Address of array from which to get the allocation information.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrso_t arrso_empty_like(arrso_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an identity array, all zeros and diagonal all ones. All members defined as sparse oti 
       numbers. This is allocated given the number of imagianary directions per order in p_nnz.

@param[in] nrows  Number of rows of the array (This array is square).
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrso_t arrso_eye(uint64_t nrows, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
arrso_t arrso_eye_bases(uint64_t nrows, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an array filled with ones, defined as sparse oti numbers. This is allocated given the
       number of imagianry directions per order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrso_t arrso_ones(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
arrso_t arrso_ones_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

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
arrso_t arrso_zeros_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
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
arrso_t arrso_createEmpty_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
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

#endif