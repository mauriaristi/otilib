#ifndef OTI_CORE_BASE_H
#define OTI_CORE_BASE_H





// ----------------------------------------------------------------------------------------------------
// ---------------------------------     DHELP FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------
coeff_t dhelp_compute_delta(imdir_t  idx, ord_t  ord, coeff_t* deltas, dhelpl_t dhl);
imdir_t dhelp_map_index(imdir_t idx, ord_t order, const bases_t* bases, dhelpl_t dhl );

void dhelp_div_imdir(imdir_t  numidx, ord_t  numord, 
                     imdir_t  denidx, ord_t  denord,
                     imdir_t* residx, ord_t* resord, 
                        int* success, dhelpl_t dhl);

void dhelp_get_idx_ord(bases_t* dir, ord_t len, imdir_t* residx, ord_t* resord, dhelpl_t dhl);


/**************************************************************************************************//**
@brief Returns the matrix form of an OTI number given the number of bases and the order.

@param[in] 
@param[in] dhl    Direction helper list
******************************************************************************************************/
matrix_form_t dhelp_matrix_form_indices( bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Returns the factor to multiply a given coefficient by (idx,order) imaginary direction, such that 
the corresponding derivative is retreived.

@param[in] idx Index of the imaginary direction.
@param[in] order Order of the imaginary direction.
@param[in] dhl    Direction helper list
******************************************************************************************************/
coeff_t dhelp_get_deriv_factor(imdir_t idx, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Returns the number of directions of a certain order given the number of bases from the 
precomputed data.

@param[in] nbases Total number of bases
@param[in] order  Truncation order
@param[in] dhl    Direction helper list
******************************************************************************************************/ 
ndir_t dhelp_extract_ndirOrder(bases_t nbases, ord_t order,dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Returns the total number of directions given the number of bases and truncation order from the
precomputed data

@param[in] nbases Total number of bases
@param[in] order  Truncation order
@param[in] dhl    Direction helper list
******************************************************************************************************/ 
ndir_t dhelp_extract_ndirTotal(bases_t nbases, ord_t order,dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Returns the number of possible combinations of a elements into subsets of size b.

@param[in] a Size of whole set.
@param[in] b Size of subsets.
******************************************************************************************************/ 
int64_t dhelp_comb(int64_t a, int64_t b);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Returns the total number of directions given the number of bases and truncation order

@param[in] nbases Total number of bases
@param[in] order  Truncation order
******************************************************************************************************/ 
ndir_t dhelp_ndirTotal(bases_t nbases, ord_t order);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Returns the number of directions of a certain truncation order given the number of bases.

@param[in] nbases Total number of bases
@param[in] order  Truncation order
******************************************************************************************************/ 
ndir_t dhelp_ndirOrder(bases_t nbases, ord_t order);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Loads a direction helper from a set of files within the specified folder. 
     
@param strLocation String with the folder where the data is located. Example "../../data"
@param order Order to be loaded in memory. Example: 3
@param nbasis Number of basis directions to load. Example: 100
@param nhelps Number of help arrays to be allocated in the array.
@param[out] p_dH Address of the helper to be loaded.
******************************************************************************************************/ 
void dhelp_load_singl( char* strLoc, ord_t order, uint64_t nhelps, ndir_t allocSize,
  dhelp_t* p_dH);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiplies 2 imaginary directions and gives the corresponding result.

@param[in]  indx1  Index of imaginary direction. 
@param[in]  ord1   Order of imaginary direction.
@param[in]  indx2  Index of imaginary direction. 
@param[in]  ord2   Order of imaginary direction.
@param[out] p_ixres Index of the resulting imaginary direction.
@param[out] p_ores  Order of the resulting imaginary direction.
@param dhl  Direction helper list.
******************************************************************************************************/ 
void dhelp_multDir(imdir_t indx1, ord_t ord1, imdir_t indx2, ord_t ord2, 
    imdir_t* p_ixres, ord_t* p_ores, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Frees all arrays in the given dhelp_t.

@param p_dH  Allocated direction helper.
******************************************************************************************************/ 
void dhelp_freeItem(  dhelp_t* p_dH);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get the full imaginary direction of corresponding the the given index and order.

@param idx    Index of the imaginary direction
@param order  Order of the index direction.
@param dhl    List of helpers
******************************************************************************************************/ 
bases_t* dhelp_get_imdir( imdir_t idx, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Free all helpers that where loaded.

@param dhl List of helpers
******************************************************************************************************/ 
void dhelp_free( dhelpl_t* dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Load a set of 10 helpers from order 1 until order 10 with 10 bases.
    
@param strLocation: Path to the folder that contains the files to load.
@param[out] dhl: Direction helper list with the loaded data.
******************************************************************************************************/ 
void dhelp_load( char* strLocation, dhelpl_t* dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Load the temporal arrays from the helper.

@param p_dH: Pointer to a Direction helper
******************************************************************************************************/ 
void dhelp_load_tmps( dhelp_t* p_dH);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Print the data of a direction helper.

@param p_dH: Pointer to a Direction helper
******************************************************************************************************/ 
void dhelp_print( dhelp_t* p_dH);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Print an imaginary direction given by its index and order.

@param indx: Direction index.
@param order: Direction order.
@param dhl: Direction helper list with the loaded data.
******************************************************************************************************/ 
void dhelp_printImdir(imdir_t indx, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Print the list of direction helpers.

@param dhl: Direction helper list with the loaded data.
******************************************************************************************************/ 
void dhelp_printList( const dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------- END DHELP FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif