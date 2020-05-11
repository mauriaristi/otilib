#ifndef OTI_CORE_DENSE_H
#define OTI_CORE_DENSE_H

/**************************************************************************************************//**
@brief Multiplies A set of oti coefficients for a given pair of orders.

@param[in] p_im1    Coefficients to be multiplied.
@param[in] ndir1    Number of directions in p_im1.
@param[in] ord1     Order of directions in p_im1.
@param[in] p_im2    Coefficients to be multiplied.
@param[in] ndir2    Number of directions in p_im2.
@param[in] ord2     Order of directions in p_im2.
@param[in] p_imres  Resulting coefficients.
@param[in] ndirres  Number of directions in result.
@param[in] dhl      Direction helper list
******************************************************************************************************/ 
void dhelp_dense_mult(coeff_t* p_im1, ndir_t ndir1, ord_t ord1, // Input 1
                      coeff_t* p_im2, ndir_t ndir2, ord_t ord2, // Input 2
                      coeff_t* p_imres, ndir_t ndirres,         // Result
                      dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiplies a set of coefficients by a real number for the case of a dense oti number.

@param[in] p_im1    Coefficients to be multiplied.
@param[in] ndir1    Number of directions in p_im1.
@param[in] a        Coefficient to be multiplied
@param[in] p_imres  Coefficients to be multiplied.
@param[in] ndirres  Number of directions in result.
@param[in] dhl      Direction helper list
******************************************************************************************************/ 
void dhelp_dense_mult_real(coeff_t* p_im1, ndir_t ndir1, // Input 1
                      coeff_t a,                         // Input 2
                      coeff_t* p_imres, ndir_t ndirres,  // Result
                      dhelpl_t dhl);                     // Helper  
// ----------------------------------------------------------------------------------------------------

#endif