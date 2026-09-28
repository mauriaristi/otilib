#ifndef OTI_CORE_PRECOMPUTE_H
#define OTI_CORE_PRECOMPUTE_H

/**************************************************************************************************//**
@brief Multiply two imaginary directions.

@param dir1: Array of bases forming the first direction
@param ord1: Order of the first direction
@param dir2: Array of bases forming the second direction
@param ord2: Order of the second direction
@param dhl: Direction helper list with the loaded data.
******************************************************************************************************/ 
imdir_t dhelp_precompute_multiply(bases_t* dir1,ord_t ord1, bases_t* dir2,ord_t ord2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set up the multiplication tables of an order without building them (after precomputing ndirs
and fulldir of all orders up to `order`). Each table gets its shape and orders, and `p_arr = NULL`;
the table is built on first use by dhelp_get_multtabl.

@param order: Truncation order to be set up.
@param nbases: number of bases of this order.
@param dhl: Addres of a direction helper list.
******************************************************************************************************/ 
void dhelp_init_multtabls(ord_t order, bases_t nbases, dhelpl_t* dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate and fill one multiplication table. The table itself is not modified: the caller
publishes the returned array (see dhelp_get_multtabl).

@param order: Order of the resulting directions.
@param table: Index of the table (0-based, the order of the row directions minus one).
@param dhl: Direction helper list, with ndirs, fulldir and the table shapes set.
@return Newly allocated array with shape `p_multtabls[table].shape`.
******************************************************************************************************/ 
imdir_t* dhelp_fill_multtabl(ord_t order, ord_t table, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Precompute full directions (after precomputing ndirs)

@param order: Truncation order to be loaded.
@param nbases: number of bases to be loaded.
@param dhl: Addres of a direction helper list.
******************************************************************************************************/ 
void dhelp_precompute_fulldir(ord_t order, bases_t nbases, dhelpl_t* dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Precompute the number of directions array.

@param order: Truncation order to be loaded.
@param nbases: number of bases to be loaded.
@param dhl: Addres of a direction helper list.
******************************************************************************************************/ 
void dhelp_precompute_ndirs(ord_t order, bases_t nbases, dhelpl_t* dhl);
// ----------------------------------------------------------------------------------------------------


#endif