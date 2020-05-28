#ifndef OTI_FEM_elemsoENT_BASE_H
#define OTI_FEM_elemsoENT_BASE_H





/**************************************************************************************************//**
@brief Function to check wether an elemsoent object is started.

@param[in] elemso: Address of the elemsoent.
******************************************************************************************************/
uint8_t elemso_is_started(   elemso_t* elemso );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Function to check wether an elemsoent object is allocated.

@param[in] elemso: Address of the elemsoent.
******************************************************************************************************/
uint8_t elemso_is_allocated( elemso_t* elemso );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Rise and clear functions of the 'start' flag.

@param[in] elemso: Address of the elemsoent.
******************************************************************************************************/
void elemso_clear_flag_start(elemso_t* elemso );
void elemso_raise_flag_start(elemso_t* elemso );
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Rise and clear functions of the 'allocation' flag.  

@param[in] elemso: Address of the elemsoent.
******************************************************************************************************/
void elemso_clear_flag_alloc(elemso_t* elemso );
void elemso_raise_flag_alloc(elemso_t* elemso );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Frees memory of elemsoent. Does not frees all values of elemsoents nor re-initialize.

@param[in] elemso: Address of the elemsoent.
******************************************************************************************************/
int64_t elemso_end(elemso_t* elemso);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief  Frees memory of an elemsoent structure.

@param[in] Address of the elemsoent. This elemsoent structure then results with ponters set to NULL and 
values set to 0.
******************************************************************************************************/
int64_t elemso_free( elemso_t* elemso );
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief  Initialize the structure of an elemsoent. Sets pointers to NULL and values to 0.

******************************************************************************************************/ 
elemso_t  elemso_init( void );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief  Setup of an elemsoent structure. This defines the interpolation function, and other parameters
to be used.

@param[inout] elemso:     Address of the elemsoent structure (Must come after a call to elemso_init().
@param[in]  nbasis:   Number of basis of the elemsoent (Equivalent to the number of DOFs of the elemsoent)
@param[in]  geomBase: Defines the basic geometry of the elemsoent (Line, Triangle, quad, tetrahedra,etc).
@param[in]  kind:     Defines the kind of elemsoent Isoparametric or Affine.
@param[in]  ndim:     Number of dimensions of the elemsoent.
@param[in]  basis_f:  Pointer to function that defines the interpolation functions and its derivatives.
                      (deprecated).
******************************************************************************************************/ 
// int64_t elemso_start(elemso_t* elemso, uint64_t nbasis, int64_t geomBase, int64_t  kind,   uint8_t  ndim,
//               int64_t (*basis_f)(int64_t,int64_t,darr_t*,void*,darr_t*));
int64_t elemso_start( elemso_t* elemso, uint64_t nbasis, int64_t geomBase,
                      int64_t kind, uint8_t ndim, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief  Allocates memory for the elemsoent structure.

@param[inout] elemso: Address of the elemsoent structure. Must come after a call to elemso_start(...).
@param[in] intorder: Integration order, defines number of integration points for numerical integration.
******************************************************************************************************/ 
int64_t elemso_allocate(elemso_t* elemso, uint64_t intorder, bases_t bases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



#endif