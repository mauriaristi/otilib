#ifndef OTI_COMM_H
#define OTI_COMM_H

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
// -----------------------------------------      ENUMS        ----------------------------------------
// ----------------------------------------------------------------------------------------------------

// Enumerators to assign a code to constants
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
// --------------------------------------       TYPEDEFS         --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef double     coeff_t; ///< Coefficient type.
typedef double*      arr_t; ///< Coefficient array type.
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

#define _REALLOC_SIZE 10

#define _MAXORDER_OTI 150
// ----------------------------------------------------------------------------------------------------
// ----------------------------------      END DEFINES         ----------------------------------------
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    uint64_t*     p_data; ///< Data Array.
    uint64_t*     p_cols; ///< Array of corresponding column index of the data array.
    uint64_t*     p_rows; ///< Array of corresponding row index of the data array.
    uint64_t       sizex; ///< Number of rows.
    uint64_t       sizey; ///< Number of cols.
    uint64_t     nonzero; ///< Number of non zero elements in the matrix.
} coomat_ui64_t;

typedef struct{
    uint64_t*     p_data; ///< Data array
    uint64_t*  p_indices; ///< Array of column indices of each data entry.
    uint64_t*   p_indptr; ///< Array pointing the range of data values per matrix row.
    uint64_t       sizex; ///< Number of rows.
    uint64_t       nrows; ///< Number of cols.
    uint64_t     nonzero; ///< Number of non zero elements.
} csrmat_ui64_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------



#endif