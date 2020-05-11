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
@brief Precompute multiplication tables (after precomputing ndirs and fulldir)

@param order: Truncation order to be loaded.
@param nbases: number of bases to be loaded.
@param dhl: Addres of a direction helper list.
******************************************************************************************************/ 
void dhelp_precompute_multtabls(ord_t order, bases_t nbases, dhelpl_t* dhl);
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

/**************************************************************************************************//**
@brief Save full direction array.

@param directory: String with the folder where the data is to be stored.
@param base: number of bases to be saved
@param order: Truncation order to be saved.
@param dhl: Direction helper list.
******************************************************************************************************/ 
void dhelp_save_fulldir(char* directory, bases_t base, ord_t order, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Save number of directions array.

@param directory: String with the folder where the data is to be stored.
@param base: number of bases to be saved
@param order: Truncation order to be saved.
@param dhl: Direction helper list.
******************************************************************************************************/ 
void dhelp_save_ndirs(char* directory, bases_t base, ord_t order,  dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Save full multiplication tables.

@param directory: String with the folder where the data is to be stored.
@param base: number of bases to be saved
@param order: Truncation order to be saved.
@param dhl: Direction helper list.
******************************************************************************************************/ 
void dhelp_save_multtabls(char* directory, bases_t base, ord_t order,  dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Precompute data

@param directory: String with the folder where the data is to be stored.
@param max_basis_k: Array with the maximum number of bases to be generated (per order)
@param maxorder: Defines the length of max_basis_k array. Also correspond to the maximum order to be
generated.
******************************************************************************************************/ 
void dhelp_precompute(char* directory, bases_t* max_basis_k, ord_t maxorder );
// ----------------------------------------------------------------------------------------------------



#endif