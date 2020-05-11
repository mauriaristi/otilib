#ifndef OTI_CORE_FILEIO_H
#define OTI_CORE_FILEIO_H

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
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Print a progress bar in the command line.

@param[in] i     Double representing current development.
@param[in] imax  Double representing the maximum (or target) value to reach.
******************************************************************************************************/ 
void print_progressbar(double i, double imax);
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ---------------------------------   LOADNPY FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif