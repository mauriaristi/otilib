// Error codes
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
// ----------------------------------------------------------------------------------------------------
// -----------------------------------------      ENUMS        ----------------------------------------
// ----------------------------------------------------------------------------------------------------

/// Enumerators to assign a code to constants
enum oti_errors {  
  // Define operations identifiers.
  OTI_success         =     0,          ///< Success
  OTI_OutOfMemory     =    -1,          ///< Out of memory.
  OTI_BadIndx         =    -2,          ///< indexing error.
  OTI_NonPreComp      =    -3,          ///< No precomputed data is available.
  OTI_NotImplemented  =    -4,          ///< Not implemented.
  OTI_NotInitialized  =    -5,          ///< Not initialized.
  OTI_BadDimensions   =    -6,          ///< Bad dimensions.

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




string printError(int error){
	string out;

	out = "\nError code: " + to_string(error);

	return out;

}