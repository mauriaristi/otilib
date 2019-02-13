#ifndef OTICORE_H
#define OTICORE_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------





// ----------------------------------------------------------------------------------------------------
// --------------------------------------       TYPEDEFS         --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef double     coeff_t; ///< Coefficient type.
typedef uint64_t   imdir_t; ///< Imaginary direction type.
typedef uint64_t    ndir_t; ///< Number of Imaginary directions type.
typedef uint16_t   bases_t; ///< Imaginary bases type. 
typedef uint8_t      ord_t; ///< Order type.
typedef uint8_t      ndh_t; ///< Number of direction helpers type.
typedef uint8_t     flag_t; ///< Flag type.

// ----------------------------------------------------------------------------------------------------
// --------------------------------------     END TYPEDEFS       --------------------------------------
// ----------------------------------------------------------------------------------------------------




// ----------------------------------------------------------------------------------------------------
// ---------------------------------------      DEFINES         ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

#define _PCOEFFT "%11.4e" // Print format of coeff_t
#define _PIMDIRT "%lu"    // Print format of imdir_t
#define _PNDIRT  "%lu"    // Print format of ndir_t
#define _PBASEST "%hu"    // Print format of bases_t
#define _PORDT   "%hhu"   // Print format of ord_t
#define _PNDHT   "%hhu"   // Print format of ndh_t
#define _PFLAGT  "%hhu"   // Print format of flag_t

#define _PUINT64T "%lu"
#define _PUINT32T "%u"
#define _PUINT16T "%hu"
#define _PUINT8T  "%hhu"

#define _PINT64T "%ld"
#define _PINT32T "%d"
#define _PINT    "%d"
#define _PINT16T "%hd"
#define _PINT8T  "%hhd"

#define _ENDL "\n"
// ----------------------------------------------------------------------------------------------------
// ----------------------------------      END DEFINES         ----------------------------------------
// ----------------------------------------------------------------------------------------------------





// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct {
    uint16_t*        p_dirA;  // Array with all basis      Shape: (    Ndir,   order)
    uint8_t*         p_expA;  // Array with all exponents. Shape: (    Ndir,   order)
    uint16_t*        p_part;  // Array with all partitions Shape: (   Npart,   order)
    uint64_t*     p_multRes;  // Array with the multiplication results.
    uint64_t*     p_multInd;  // Array with the multiplication indices.
    uint64_t*    p_countOTI;  // Array with the number of elements for each number of variables possible.
    uint16_t*       p_udirA;  // User direction array.     Shape: (      nn,   order)
    uint8_t*        p_uexpA;  // User exponent  array.     Shape: (      nn,   order)
    uint16_t*       p_rdirA;  // Result direction array.   Shape: (      nn,   order)
    uint8_t*        p_rexpA;  // Result exponent  array.   Shape: (      nn,   order)
    uint16_t*       p_mdirA;  // Temporal direction array. Shape: (      nn,   order) -> nn: number of 
    uint8_t*        p_mexpA;  // Temporal exponent array.  Shape: (      nn,   order)        temp els
    uint16_t*      p_mapder;  // Temporal mapping array.   Shape: (      nn, 2*order)   
    uint8_t*       p_multpl;  // Array to hold multiples.  Shape: ( 2^order,   order)
    coeff_t*         p_fder;  // Preallocated array for general function evaluation. size: order+1
    coeff_t*        p_coefs;  // Preallocated array for general multiplication coefs. Shape: (Ndir,1)
    uint64_t*        p_indx;  // Preallocated array for general multiplication indx.  Shape: (Ndir,1)
    uint64_t           Ndir;  // Number of directions in the helper.
    uint64_t          Npart;  // Number of partitions in the helper.
    uint64_t          Nmult;  // Size of the multiplication vectors.
    uint16_t         Nbasis;  // Maximum number of basis in the helper.
    uint8_t              nn;  // Number of user arrays  
    uint8_t           order;  // Order of all directions in this set. 

} directionHelper;




typedef struct {
   imdir_t* p_arr;     ///< Array of imaginary directions
   uint64_t shape[2];  ///< Shape of the array.
} imdir2d_t;           ///< imaginary direction array type.


typedef struct {
   // Arrays
    bases_t*      p_fulldir;  ///< 2D Array with explicit                     Shape: (    Ndir,   order)
    imdir2d_t*   p_multtabls; ///< 1D Array of 2D multiplication tables       Shape: (       1,   Nmult)
    ndir_t*         p_ndirs;  ///< 1D Array with the Ndir given a m <= Nbases Shape: (       1,  Nbasis)
    coeff_t*         p_fder;  ///< Preallocated array for general function evaluation. size: order+1
    coeff_t*        p_coefs;  ///< Preallocated array for general multiplication coefs. Shape: (Ndir,1)
    imdir_t*         p_indx;  ///< Preallocated array for general multiplication indx.  Shape: (Ndir,1)

  // Integer elements
    ndir_t             Ndir;  ///< Number of directions in the helper.
    ord_t             Nmult;  ///< Number of multiplication tables. (Usually, it's order/2 )
    ndir_t           Nbasis;  ///< Maximum number of basis in the helper.
    ord_t             order;  ///< Order of all directions in this set. 

} dhelp_t; ///< Direction Helper type.

typedef struct {
   dhelp_t* p_dh; ///< Array of direction helpers. Shape: (1 , ndh)
   ndh_t ndh;     ///< Number of direction helpers.
} dhelpl_t;       ///< Direction Helper list type.



typedef struct{
    uint64_t*     p_data; // Data Array.
    uint64_t*     p_cols; // Array of corresponding column index of the data array.
    uint64_t*     p_rows; // Array of corresponding row index of the data array.
    uint64_t       sizex; // Number of rows.
    uint64_t       sizey; // Number of cols.
    uint64_t     nonzero; // Number of non zero elements in the matrix.
} coomat_ui64_t;

typedef struct{
    uint64_t*     p_data; // Data array
    uint64_t*  p_indices; // Array of column indices of each data entry.
    uint64_t*   p_indptr; // Array pointing the range of data values per matrix row.
    uint64_t       sizex; // Number of rows.
    uint64_t       nrows; // Number of cols.
    uint64_t     nonzero; // Number of non zero elements.
} csrmat_ui64_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------





// ----------------------------------------------------------------------------------------------------
// -----------------------------------------      ENUMS        ----------------------------------------
// ----------------------------------------------------------------------------------------------------

/// Enumerators to assign a code to constants
enum oti_errors {  
  // Define operations identifiers.
  OTI_success         =     0,   ///< Success
  OTI_OutOfMemory     =    -1,   ///< Out of memory.
  OTI_BadIndx         =    -2,   ///< indexing error.
  OTI_NonPreComp      =    -3,   ///< No precomputed data is available.
  OTI_NotImplemented  =    -4,   ///< Not implemented.

  OTI_FEM_InvalidBaseId = -100,         ///< invalid base Id. It pops up when for example 
                                        /// for P0 elements that only have 1 basis function
                                        /// you ask for basis 2 (that does not exist).

  OTI_FEM_InvalidElementType = -101,    ///< Invalid basic element type 
                                        // (elLine, elTria, elQuad, elTetr, elHexa).

  OTI_FEM_NotImplemented     = -102,    ///< Operation not yet implemented.

  OTI_undetErr     = -20000             ///< Undetermined error.
  
};

// ----------------------------------------------------------------------------------------------------
// ----------------------------------------    END ENUMS      -----------------------------------------
// ----------------------------------------------------------------------------------------------------









// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd


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
@brief Loads the multiplication tables. Given the corresponding order and number of basis, it loads the
file located at the given folder.

@param[in] strLocation String with the folder that contains the npy file with fulldir.    
@param[in] order Order to be loaded. Example: 3.
@param[in] nbasis Number of basis. Example: 10
@param[out] p_dH Address of the helper to be loaded. Memory is allocated in this function.
******************************************************************************************************/ 
void loadnpy_multtabls( char* strLocation, ord_t order, ndir_t nbasis, dhelp_t* p_dH);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Loads the number of directions array. Given the truncation order and number of basis, it loads 
the file from the given folder.

@param[in] strLocation String with the folder that contains the *.npy file with fulldir.
@param[in] order Order to be loaded. Example: 3.
@param[in] nbasis Number of basis. Example: 10.
@param[out] p_dH Address of the helper to be loaded. Memory is allocated in this function.
******************************************************************************************************/ 
void loadnpy_ndirs( char* strLocation, ord_t order, ndir_t nbasis, dhelp_t* p_dH);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Loads the full direction matrix. Given the truncation order and number of basis, it loads the  
file from the given folder.

@param[in] strLocation String with the folder that contains the *.npy file with fulldir.
@param[in] order Order to be loaded. Example: 3.
@param[in] nbasis Number of basis. Example: 10.
@param[out] p_dH Address of the helper to be loaded. Memory is allocated in this function.
******************************************************************************************************/ 
void loadnpy_fulldir( char* strLocation, ord_t order, ndir_t nbasis, dhelp_t* p_dH);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ---------------------------------   LOADNPY FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------






// ----------------------------------------------------------------------------------------------------
// ---------------------------------     DHELP FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Multiplies A set of oti coefficients for a given pair of orders.

@param[in] p_im1    Coefficients to be multiplied.
@param[in] ndir1    Number of directions in p_im1.
@param[in] ord1     Order of directions in p_im1.
@param[in] p_im2    Coefficients to be multiplied.
@param[in] ndir2    Number of directions in p_im1.
@param[in] ord2     Order of directions in p_im1.
@param[in] p_imres  Coefficients to be multiplied.
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
                      dhelpl_t dhl);                     // Helper                                      // Helper
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
void dhelp_load_singl( char* strLoc, ord_t order, ndir_t nbasis, uint8_t nhelps, dhelp_t* p_dH);
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
@brief Print the data of a direction helper.

@param p_dH: Pointer to a Direction helper
******************************************************************************************************/ 
void dhelp_print( dhelp_t* p_dH);

/**************************************************************************************************//**
@brief Print the list of direction helpers.

@param dhl: Direction helper list with the loaded data.
******************************************************************************************************/ 
void dhelp_printList( const dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ---------------------------------     DHELP FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------



// added to c_otilib.pxd

uint64_t  c_helper_multMultiIndxFast( uint64_t* indx, uint8_t nindx, uint8_t order, 
                                      directionHelper* p_dH, uint8_t* error);

void      c_helper_ordDirExpA( uint16_t* p_dirA, uint8_t* multiple, uint8_t order, 
                               uint16_t* p_ndirA, uint8_t* p_nexpA);

void      c_helper_getMultpl( uint8_t* p_expA, uint8_t order, directionHelper* p_dH, 
                              uint64_t* Nmultpl);

uint64_t  c_helper_multIndxFast( uint64_t indx1, uint64_t indx2, uint8_t order, 
                                 directionHelper* p_dH, uint8_t* error);

void      c_helper_load( uint8_t maxorder, char* strLocation, directionHelper** p_dH);

void      c_helper_free( directionHelper* p_dH , uint8_t maxorder );

uint64_t  c_helper_findIndex( uint16_t* p_dirA,  uint8_t* p_expA, uint8_t order, 
                              directionHelper* p_dH);

uint64_t  c_helper_multIndx( uint64_t indx1, uint64_t indx2, uint8_t order, 
                             directionHelper* p_dH, uint8_t* error);

uint16_t* c_helper_getDirA( uint64_t indx, uint8_t order, directionHelper* p_dH);

uint8_t*  c_helper_getExpA( uint64_t indx, uint8_t order, directionHelper* p_dH);

uint8_t*  c_helper_getUExpA( uint8_t order, uint8_t n, directionHelper* p_dH); // inline

uint16_t* c_helper_getUDirA( uint8_t order, uint8_t n, directionHelper* p_dH); // inline

uint64_t  c_helper_findMaxDir(uint64_t index, uint8_t order, directionHelper* p_dH);

uint64_t  c_helper_getNels( uint64_t m, uint8_t order, directionHelper* p_dH);

uint64_t  c_helper_getNParts( uint8_t order, directionHelper* p_dH); // inline

uint16_t  c_helper_getSet( uint8_t order,uint64_t i,uint64_t j, directionHelper* p_dH); // inline

void      c_helper_insertIndx( uint64_t* p_indxArray,uint64_t indx,uint64_t *size,
                               double * p_coefArray, double coef);

uint64_t  c_ndir( uint64_t nvar,uint8_t order);

uint16_t  c_maxUI16( uint64_t a,uint64_t b);

void      c_printArrayDBL( double* ptr_,uint64_t n);

void      c_printArrayUI64( uint64_t* ptr_,uint64_t n);

void      c_minUI64( uint64_t a,uint64_t b,uint64_t* minnum,uint64_t* maxnum );

uint64_t  c_multDirections_dH( uint64_t indx1m1, uint64_t indx2m1, directionHelper* p_dH, 
                               uint8_t* error );

uint64_t c_binarySearch_dH( uint16_t*  ptr_dirA, uint8_t*  ptr_expA, directionHelper* p_dH);

void     c_loadDirA( char* strLocation,uint8_t order, uint16_t ndir, uint16_t** dirA, 
                     uint64_t* Ndir);

void     c_loadExpA( char* strLocation,uint8_t order, uint16_t ndir, uint8_t** expA, 
                     uint64_t* Ndir);

void     c_loadCount( char* strLocation,uint8_t order, uint16_t ndir, uint64_t** count);

void     c_loadParts( char* strLocation,uint8_t order, uint16_t ndir, uint16_t** p_parts, 
                      uint64_t* Nparts);

void     c_loadDirHelper( char* strLocation, uint8_t order, uint16_t ndir, uint8_t nhelps, 
                          directionHelper* dirHelp);

void     c_freeDirHelper(  directionHelper* dirHelp);

uint64_t c_fastpow( uint64_t b,uint16_t exp);

uint64_t c_fastfact( uint8_t exp);

uint64_t c_convToIndex( uint16_t* ptr_dirA,uint8_t* ptr_expA, uint8_t order);

void     c_printArrayUI16( uint16_t* ptr_,uint8_t size);

void     c_printArrayUI8( uint8_t* ptr_,uint8_t size);

void     c_mapDirArray( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,
                        uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2, uint16_t* ptr_mapder);

void     c_mapDirArrayNoMapder( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,
                                uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2);

uint64_t c_binarySearch( uint16_t* ptr_dirArray, uint8_t* ptr_expArray,
                         uint16_t* ptr_dirA,     uint8_t* ptr_expA,     uint8_t order,
                         uint64_t  N, uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2);

void     c_convToDirExp( uint64_t index, uint8_t order, uint16_t* ptr_dirA, uint8_t* ptr_expA);

void     c_reMapDirArray( uint16_t*  ptr_mdirA1, uint16_t* ptr_mapder, uint8_t order,
                      uint16_t* ptr_dirA1);

uint8_t  c_sumUI8( uint8_t* ptr_,uint8_t n);

uint64_t c_multDirections( uint16_t* ptr_dirArray, uint8_t* ptr_expArray,
                           uint16_t* ptr_dirA1,  uint8_t* ptr_expA1,
                           uint16_t* ptr_dirA2,  uint8_t* ptr_expA2, 
                           uint16_t* ptr_mdirA1, uint8_t* ptr_mexpA1,
                           uint16_t* ptr_mdirA2, uint16_t* ptr_mdirA3, 
                           uint16_t* ptr_mapder, 
                           uint8_t order, uint64_t N, uint8_t* error );

uint64_t c_binarySearchUI64( uint64_t* ptr_indxArray, uint64_t indx,uint64_t  N);

void     c_mapPartition( uint16_t part,  uint16_t*  ptr_dir,  uint8_t  order, 
                         uint16_t*  ptr_map);

void     c_orderDirExpArray( uint16_t* dirA,    uint8_t*    multExpA ,uint8_t pos,
                             uint16_t* newDirA, uint8_t* newExpA, uint8_t order);

void*    c_malloc_ptr( uint64_t numberOfElements, uint64_t sizeOfElement);

void     c_free_ptr( void** ptrAddress);


// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------


#endif
