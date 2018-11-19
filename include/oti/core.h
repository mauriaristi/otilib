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
// ---------------------------------------      DEFINES         ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

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
    double*          p_fder;  // Preallocated array for general function evaluation. size: order+1
    double*         p_coefs;  // Preallocated array for general multiplication coefs. Shape: (Ndir,1)
    uint64_t*        p_indx;  // Preallocated array for general multiplication indx.  Shape: (Ndir,1)
    uint64_t           Ndir;  // Number of directions in the helper.
    uint64_t          Npart;  // Number of partitions in the helper.
    uint64_t          Nmult;  // Size of the multiplication vectors.
    uint16_t         Nbasis;  // Maximum number of basis in the helper.
    uint8_t              nn;  // Number of user arrays  
    uint8_t           order;  // Order of all directions in this set. 

} directionHelper;



typedef struct {
    uint16_t*     p_fulldir;  // 2D Array with explicit                     Shape: (    Ndir,   order)
    uint64_t**  p_multtabls;  // 1D Array of 2D multiplication tables       Shape: (       1,   Nmult)
    uint64_t*       p_ndirs;  // 1D Array with the Ndir given a m <= Nbases Shape: (       1,  Nbasis)
    uint16_t*       p_mdirA;  // Temporal direction array. Shape: (      nn,   order) -> nn: number of 
    uint8_t*        p_mexpA;  // Temporal exponent array.  Shape: (      nn,   order)        temp els
    uint16_t*      p_mapder;  // Temporal mapping array.   Shape: (      nn, 2*order)   
    uint8_t*       p_multpl;  // Array to hold multiples.  Shape: ( 2^order,   order)
    double*          p_fder;  // Preallocated array for general function evaluation. size: order+1
    double*         p_coefs;  // Preallocated array for general multiplication coefs. Shape: (Ndir,1)
    uint64_t*        p_indx;  // Preallocated array for general multiplication indx.  Shape: (Ndir,1)
    uint64_t           Ndir;  // Number of directions in the helper..
    uint16_t          Nmult;  // Number of multiplication tables.
    uint16_t         Nbasis;  // Maximum number of basis in the helper.
    uint8_t           order;  // Order of all directions in this set. 

} directionHelper2;

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

// Enumerators to assign a code to FEM constants
enum c_oti_errors {  
  // Define operations identifiers.
  OTI_success      =     0,   // Success
  OTI_OutOfMemory  =    -1,   // Out of memory.
  OTI_BadIndx      =    -2,   // indexing error.
  OTI_NonPreComp   =    -3,   // No precomputed data is available.

  OTI_FEM_InvalidBaseId = -100,         // invalid base Id. It pops up when for example 
                                        // for P0 elements that only have 1 basis function
                                        // you ask for basis 2 (that does not exist).

  OTI_FEM_InvalidElementType = -101,    // Invalid basic element type 
                                        // (elLine, elTria, elQuad, elTetr, elHexa).

  OTI_FEM_NotImplemented     = -102,    // Operation not yet implemented.

  OTI_undetErr     = -20000             // Undetermined error.
  
};

// ----------------------------------------------------------------------------------------------------
// ----------------------------------------    END ENUMS      -----------------------------------------
// ----------------------------------------------------------------------------------------------------









// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd

void      load_npy(char* filename, void** data, uint8_t* ndim, uint64_t* shape);

void      c_loadDirHelper2( char* strLocation, uint8_t order,   uint16_t nbasis, uint8_t nhelps, 
    directionHelper2* dHelp);

void      c_loadMulttabls( char* strLocation, uint8_t order, uint16_t nbasis, directionHelper2* p_dH);

void      c_loadNdirs( char* strLocation, uint8_t order, uint16_t nbasis, directionHelper2* p_dH);

void      c_loadFulldir( char* strLocation, uint8_t order, uint16_t nbasis, directionHelper2* p_dH);

void      c_freeDirHelper2(  directionHelper2* p_dH);

void      c_helper_free2(directionHelper2** p_dH, uint8_t nhelpers);

void      c_helper_load2( char* strLocation, directionHelper2** p_dH);


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
