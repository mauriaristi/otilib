#ifndef OTICORE_H
#define OTICORE_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "oti/comm.h"

#include <math.h>

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------






// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct {
  imdir_t* p_arr;     ///< Array of imaginary directions
  uint64_t shape[2];  ///< Shape of the array.
} imdir2d_t;           ///< imaginary direction array type.


typedef struct{
    imdir_t*        p_im;
    ord_t*         p_ord;
    uint64_t*     p_cols;
    uint64_t*     p_rows;
    uint64_t       sizex;
    uint64_t       sizey;
    uint64_t     nonzero;
} matrix_form_t;



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









// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd


matrix_form_t dhelp_matrix_form_indices( bases_t nbases, ord_t order, dhelpl_t dhl);



// ----------------------------------------------------------------------------------------------------
// ---------------------------------   ARRAY FUNCTIONS    ---------------------------------------------
// ----------------------------------------------------------------------------------------------------
uint8_t  array2d_getel_ui8_t( uint8_t*  arr,uint64_t ncols, uint64_t i, uint64_t j );

uint16_t array2d_getel_ui16_t(uint16_t* arr,uint64_t ncols, uint64_t i, uint64_t j );

uint32_t array2d_getel_ui32_t(uint32_t* arr,uint64_t ncols, uint64_t i, uint64_t j );

uint64_t array2d_getel_ui64_t(uint64_t* arr,uint64_t ncols, uint64_t i, uint64_t j );

double   array2d_getel_f64_t( double*   arr,uint64_t ncols, uint64_t i, uint64_t j );

float    array2d_getel_f32_t( float*    arr,uint64_t ncols, uint64_t i, uint64_t j );
// ----------------------------------------------------------------------------------------------------
// ---------------------------------   ARRAY FUNCTIONS    ---------------------------------------------
// ----------------------------------------------------------------------------------------------------



coeff_t dhelp_get_deriv_factor(imdir_t idx, ord_t order, dhelpl_t dhl);




void dhelp_add_coeff( coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres, 
    coeff_t im, imdir_t idx );



// ----------------------------------------------------------------------------------------------------
// ---------------------------------   LOADNPY FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Loads a '.npy' array to C format.

@param[in] filename String with the filename of to load. Must contain the path.
@param[out] data Address of the pointer that will hold the data. Will be allocated in this function.
@param[out] ndim Number of dimensions of the array.
@param[out] shape Address to the pointer that will hold the array.
******************************************************************************************************/ 
void loadnpy(char* filename, void** data, uint8_t* ndim, uint64_t* shape);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Saves a 1 or 2d array in *.npy (v1.0) format

@param[in] filename String with the filename of to load. Must contain the path.
@param[in] dtype Data type id: 0:uint8_t, 2: uint16_t, 3: uint32_t, 4: uint64_t
@param[in] data Address of the pointer that holds the data. 
@param[in] shapex Number of elements in first dimension
@param[in] shapey Number of elements in second dimension. If 1d, this should be 1.
******************************************************************************************************/ 
void savenpy(char* filename, uint8_t dtype, void* data, uint64_t shapex, uint64_t shapey);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Loads the multiplication tables. Given the corresponding order and number of basis, it loads the
file located at the given folder.

@param[in] strLocation String with the folder that contains the npy file with fulldir.    
@param[in] order Order to be loaded. Example: 3.
@param[in] nbasis Number of basis. Example: 10
@param[out] p_dH Address of the helper to be loaded. Memory is allocated in this function.
******************************************************************************************************/ 
void loadnpy_multtabls( char* strLocation, ord_t order, dhelp_t* p_dH);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Loads the number of directions array. Given the truncation order and number of basis, it loads 
the file from the given folder.

@param[in] strLocation String with the folder that contains the *.npy file with fulldir.
@param[in] order Order to be loaded. Example: 3.
@param[in] nbasis Number of basis. Example: 10.
@param[out] p_dH Address of the helper to be loaded. Memory is allocated in this function.
******************************************************************************************************/ 
void loadnpy_ndirs( char* strLocation, ord_t order, dhelp_t* p_dH);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Loads the full direction matrix. Given the truncation order and number of basis, it loads the  
file from the given folder.

@param[in] strLocation String with the folder that contains the *.npy file with fulldir.
@param[in] order Order to be loaded. Example: 3.
@param[in] nbasis Number of basis. Example: 10.
@param[out] p_dH Address of the helper to be loaded. Memory is allocated in this function.
******************************************************************************************************/ 
void loadnpy_fulldir( char* strLocation, ord_t order, dhelp_t* p_dH);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Concatenate the filename for the pre-computed data cases.

@param[in] strLocation String with the folder that contains the *.npy file with fulldir.
@param[in] base_name String with the base name of the precomputed data. Example "fulldir"
@param[in] order Order to be loaded. Example: 3.
@param[out] filename Full name of the file. Example "multtabl_n20_0.npy"
******************************************************************************************************/ 
void concat_filename(const char* strLocation, const char* base_name, 
    ord_t after, ord_t order, char* filename);
void print_progressbar(double i, double imax);
// ----------------------------------------------------------------------------------------------------
// ---------------------------------   LOADNPY FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------






// ----------------------------------------------------------------------------------------------------
// ---------------------------------     DHELP FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------



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
void dhelp_sparse_sub_dirs(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                           coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, 
                           coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           
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
void dhelp_sparse_add_dirs(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                           coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, 
                           coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           
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
void dhelp_sparse_mult(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1,
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2,
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,          
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


// ----------------------------------------------------------------------------------------------------
// --------------------------------- END DHELP FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Function that searches the index of a given element in an ordered array. If the element is not 
in the array, the algorithm outputs a flag that tells the item must be inserted at the given position
to preserve order.

@param[in] elem Element to be sought.
@param[in] p_arr Array (uint64_t).
@param[in] size Dimension of the array.
******************************************************************************************************/ 
uint64_t binSearchUI64(  uint64_t elem, uint64_t* p_arr, uint64_t size, flag_t* flag);
// ----------------------------------------------------------------------------------------------------

void printArrayDBL(double* ptr_,uint64_t n);
void printArrayUI64(uint64_t* ptr_,uint64_t n);
void printArrayUI16(uint16_t* ptr_,uint8_t n);
void printArrayUI8(uint8_t* ptr_,uint8_t n);



// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

// #include "c/core.c"

#endif
