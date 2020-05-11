#ifndef OTI_CORE_UTILS_H
#define OTI_CORE_UTILS_H


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



/**************************************************************************************************//**
@brief Printing functions. These functions are helpers to print 1D arrays in the command line.

@param[in] ptr_ Array of values to be printed.
@param[in] n: Number of elements in the array.
******************************************************************************************************/ 
void printArrayDBL(    double* ptr_, uint64_t n );
void printArrayUI64( uint64_t* ptr_, uint64_t n );
void printArrayUI16( uint16_t* ptr_, uint8_t  n );
void printArrayUI8(   uint8_t* ptr_, uint8_t  n );
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief 2D array getter function. Given a 2D array, extract the element at i,j.

@param[in] arr   Array with data.
@param[in] ncols Number of columns of the array.
@param[in] i     Row index.
@param[in] j     Column index.
******************************************************************************************************/ 
uint8_t  array2d_getel_ui8_t(  uint8_t*  arr,uint64_t ncols, uint64_t i, uint64_t j );
uint16_t array2d_getel_ui16_t( uint16_t* arr,uint64_t ncols, uint64_t i, uint64_t j );
uint32_t array2d_getel_ui32_t( uint32_t* arr,uint64_t ncols, uint64_t i, uint64_t j );
uint64_t array2d_getel_ui64_t( uint64_t* arr,uint64_t ncols, uint64_t i, uint64_t j );
double   array2d_getel_f64_t(  double*   arr,uint64_t ncols, uint64_t i, uint64_t j );
float    array2d_getel_f32_t(  float*    arr,uint64_t ncols, uint64_t i, uint64_t j );
// ----------------------------------------------------------------------------------------------------


#endif