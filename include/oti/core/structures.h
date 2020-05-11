#ifndef OTI_CORE_STRUCTURES_H
#define OTI_CORE_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct {
  imdir_t*    p_arr;  ///< Array of imaginary directions
  uint64_t shape[2];  ///< Shape of the array.
} imdir2d_t;          ///< imaginary direction array type.


typedef struct{
    imdir_t*        p_im; ///< Imaginary direction indices array (nonzero).
    ord_t*         p_ord; ///< Order of imaginary direction array (nonzero).
    uint64_t*     p_cols; ///< Array with corresponding col location of im,ord pair.
    uint64_t*     p_rows; ///< Array with corresponding row location of im,ord pair.
    uint64_t       sizex; ///< Total number of rows in the matrix.
    uint64_t       sizey; ///< Total number of cols in the matrix.
    uint64_t     nonzero; ///< Number of non-zero elements in the matrix form.
} matrix_form_t;          ///< Cauchy Riemann matrix form index type.


typedef struct {
  // Arrays
    bases_t*      p_fulldir;  ///< 2D Array with explicit                     Shape: (    Ndir,   order)
    imdir2d_t*   p_multtabls; ///< 1D Array of 2D multiplication tables       Shape: (       1,   Nmult)
    ndir_t*         p_ndirs;  ///< 1D Array with the Ndir given a m <= Nbases Shape: (       1,  Nbasis)
    coeff_t**          p_im;  ///< Preallocated array for general multiplication coefs. Shape: (Ntmps,Ndir)
    imdir_t**         p_idx;  ///< Preallocated array for general multiplication indx.  Shape: (Ntmps,Ndir)
  //   
    coeff_t***        p_ims;  ///< Array for temporal oti nums. Shape: (1, order)
    imdir_t***        p_ids;  ///< Array for temporal oti nums. Shape: (1, order)
    ndir_t**          p_nnz;  ///< Array for temporal oti nums. Shape: (1, order)
    ndir_t**         p_size;  ///< Array for temporal oti nums. Shape: (1, order)
  
  // Integer elements
    ndir_t        allocSize;  ///< Allocation size of arrays for this order. (useful for sotinum)
    ndir_t            Ntmps;  ///< Number of temporal arrays in the helper.
    ndir_t             Ndir;  ///< Number of directions in the helper.
    ord_t             Nmult;  ///< Number of multiplication tables. (Usually, it's order/2 )
    bases_t          Nbasis;  ///< Maximum number of basis in the helper.
    ord_t             order;  ///< Order of all directions in this set. 

} dhelp_t; ///< Direction Helper type.

typedef struct {
   dhelp_t* p_dh; ///< Array of direction helpers. Shape: (1 , ndh)
   ndh_t     ndh; ///< Number of direction helpers.
   ord_t*  order; ///< Global truncation order.
} dhelpl_t;       ///< Direction Helper list type.

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif