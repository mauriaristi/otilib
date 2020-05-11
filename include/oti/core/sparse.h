#ifndef OTI_CORE_SPARSE_H
#define OTI_CORE_SPARSE_H

void dhelp_add_coeff( coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres, 
    coeff_t im, imdir_t idx );



/**************************************************************************************************//**
@brief Copies coefficients and directions. Must be already allocated.

@param[in] p_im1    Coefficients to be multiplied.
@param[in] p_idx1   Imaginary directions to be multiplied.
@param[in] ndir1    Number of directions in p_im1.
@param[in] p_imres  Resulting coefficients.
@param[in] p_idxres Resulting imaginary directions.
@param[in] ndirres  Number of directions in result.
@param[in] dhl      Direction helper list
******************************************************************************************************/ 
void dhelp_sparse_copy(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,
                       dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Adds two sets of coefficients. Must be of same order.

@param[in] p_im1    Coefficients to be multiplied.
@param[in] p_idx1   Imaginary directions to be multiplied.
@param[in] ndir1    Number of directions in p_im1.
@param[in] p_im2    Coefficients to be multiplied.
@param[in] p_idx2   Imaginary directions to be multiplied.
@param[in] ndir2    Number of directions in p_im2.
@param[in] p_imres  Resulting coefficients.
@param[in] p_idxres Resulting imaginary directions.
@param[in] ndirres  Number of directions in result.
@param[in] dhl      Direction helper list
******************************************************************************************************/ 
void dhelp_add_sparse(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,  
                      coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2,  
                      coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,          
                      dhelpl_t dhl);                                                 
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Subtract two sets of coefficients.

@param[in] p_im1    Coefficients.
@param[in] p_idx1   Imaginary directions.
@param[in] ndir1    Number of directions in p_im1.
@param[in] p_im2    Coefficients.
@param[in] p_idx2   Imaginary directions.
@param[in] ndir2    Number of directions in p_im2.
@param[in] p_imres  Resulting coefficients.
@param[in] p_idxres Resulting imaginary directions.
@param[in] ndirres  Number of directions in result.
@param[in] dhl      Direction helper list
******************************************************************************************************/ 
void dhelp_sparse_sub_dirs(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,   // Input 1
                           coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2,   // Input 2
                           coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres, // Result 
                           dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Adds two sets of coefficients.

@param[in] p_im1    Coefficients.
@param[in] p_idx1   Imaginary directions.
@param[in] ndir1    Number of directions in p_im1.
@param[in] p_im2    Coefficients.
@param[in] p_idx2   Imaginary directions.
@param[in] ndir2    Number of directions in p_im2.
@param[in] p_imres  Resulting coefficients.
@param[in] p_idxres Resulting imaginary directions.
@param[in] ndirres  Number of directions in result.
@param[in] dhl      Direction helper list
******************************************************************************************************/ 
void dhelp_sparse_add_dirs(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,    // Input 1
                           coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2,    // Input 2
                           coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,  // Result 
                           dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Multiplies A set of oti coefficients for a given pair of orders.

This function uses the following temporals: 3,4,5.

@param[in] p_im1    Coefficients to be multiplied.
@param[in] p_idx1   Imaginary directions to be multiplied.
@param[in] ndir1    Number of directions in p_im1.
@param[in] ord1     Order of directions in p_im1.
@param[in] p_im2    Coefficients to be multiplied.
@param[in] p_idx2   Imaginary directions to be multiplied.
@param[in] ndir2    Number of directions in p_im2.
@param[in] ord2     Order of directions in p_im2.
@param[in] p_imres  Resulting coefficients.
@param[in] p_idxres Resulting imaginary directions.
@param[in] ndirres  Number of directions in result.
@param[in] dhl      Direction helper list
******************************************************************************************************/ 
void dhelp_sparse_mult(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1,  // Input 1
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2,  // Input 2
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,            // Result 
                       dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiplies A set of oti coefficients for a given pair of orders.

@param[in] p_im1    Coefficients to be multiplied.
@param[in] p_idx1   Imaginary directions to be multiplied.
@param[in] ndir1    Number of directions in p_im1.
@param[in] ord1     Order of directions in p_im1.
@param[in] p_im2    Coefficients to be multiplied.
@param[in] p_idx2   Imaginary directions to be multiplied.
@param[in] ndir2    Number of directions in p_im2.
@param[in] ord2     Order of directions in p_im2.
@param[in] p_imres  Resulting coefficients.
@param[in] p_idxres Resulting imaginary directions.
@param[in] ndirres  Number of directions in result.
@param[in] dhl      Direction helper list
******************************************************************************************************/ 
void dhelp_sparse_mult_real(coeff_t val,
                            coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                            coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,          
                            dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Helper function to the sparse multiplication function dhelp_mult_sparse. This searches for
directions such that the result of multiplying other items in im1 and im2 result in a direction with
an index smaller than next_idx but larger than prev_idx.

@param[in] p_im1        Coefficients to be multiplied.
@param[in] p_idx1       Imaginary directions to be multiplied.
@param[in] ndir1        Number of directions in p_im1.
@param[in] ord1         Order of directions in p_im1.
@param[in] p_im2        Coefficients to be multiplied.
@param[in] p_idx2       Imaginary directions to be multiplied.
@param[in] ndir2        Number of directions in p_im2.
@param[in] ord2         Order of directions in p_im2.
@param[in] p_imres      Resulting coefficients.
@param[in] p_idxres     Resulting imaginary directions.
@param[in] ndirres      Number of directions in result.
@param[in] prev_idx     Directions to determine the lower bound of the search.
@param[in] next_idx     Directions to determine the upper bound of the search.
@param[in] curr_i1      Current index associated to i1.
@param[in] curr_i2      Current index associated to i2.
@param[in] tmp_multtabl Multiplication table for order ord1 x ord2
******************************************************************************************************/ 
void dhelp_search_prev_dir( coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1,
                            coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2,
                            coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,          
                            imdir_t prev_idx, imdir_t next_idx, ndir_t curr_i1, ndir_t curr_i2,
                            imdir2d_t tmp_multtabl);
// ----------------------------------------------------------------------------------------------------


#endif