#ifndef READ_NPY_H
#define READ_NPY_H
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

typedef struct {
    

} otinum2_t


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


#endif