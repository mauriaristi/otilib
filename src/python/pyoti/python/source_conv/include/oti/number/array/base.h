#ifndef OTI_{module_name_upper}_ARRAY_BASE_H
#define OTI_{module_name_upper}_ARRAY_BASE_H

/**************************************************************************************************//**
@brief Perform taylor series evaluation given the array of deltas..

@param[in]    deltas Array of delta values for every imaginary basis.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
void    {arr_func}_taylor_integrate_to( coeff_t* deltas, {arr_type}* arr, {arr_type}* res);
{arr_type} {arr_func}_taylor_integrate(    coeff_t* deltas, {arr_type}* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get all imaginary coefficients of given order in {arr_func} object.

@param[in]    order  Order to get data from.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
void    {arr_func}_get_order_im_to( ord_t order, {arr_type}* arr, {arr_type}* res);
{arr_type} {arr_func}_get_order_im(    ord_t order, {arr_type}* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set slice to {arr_func} object.

@param[in]    val    Value to set in res array.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
void {arr_func}_set_slice_r( coeff_t val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         {arr_type}* res);
void {arr_func}_set_slice_O( {arr_type}* val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         {arr_type}* res);
void {arr_func}_set_slice_o( {num_type}* val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get slice from {arr_func} object.

@param[in]    arr    Address of array from which to get data.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_get_slice( {arr_type}* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                        dhelpl_t dhl);
void {arr_func}_get_slice_to( {arr_type}* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate imaginary direction in {arr_func} object.

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_truncate_im(    imdir_t idx, ord_t order, {arr_type}* arr);
void    {arr_func}_truncate_im_to( imdir_t idx, ord_t order, {arr_type}* arr, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Imaignary direction extractor from {arr_func} object..

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_extract_im(   imdir_t idx, ord_t order, {arr_type}* arr);
void    {arr_func}_extract_im_to(imdir_t idx, ord_t order, {arr_type}* arr, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get derivative from {arr_func} object..

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
darr_t  {arr_func}_get_deriv(    imdir_t idx, ord_t order, {arr_type}* arr);
void    {arr_func}_get_deriv_to( imdir_t idx, ord_t order, {arr_type}* arr, {arr_type}* res);
{arr_type} {arr_func}_get_deriv_o(  imdir_t idx, ord_t order, {arr_type}* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivative extractor from {arr_func} object.

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_extract_deriv(    imdir_t idx, ord_t order, {arr_type}* arr);
void    {arr_func}_extract_deriv_to( imdir_t idx, ord_t order, {arr_type}* arr, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get imaginary direction from {arr_func} object..

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
darr_t  {arr_func}_get_im(   imdir_t idx, ord_t order, {arr_type}* arr);
{arr_type} {arr_func}_get_im_o( imdir_t idx, ord_t order, {arr_type}* arr);
void    {arr_func}_get_im_to(imdir_t idx, ord_t order, {arr_type}* arr, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy an existing array. Data is copied to the new memory.

@param[in] arr    Address of array from which to get data.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
void    {arr_func}_copy_to({arr_type}* arr, {arr_type}* res);
{arr_type} {arr_func}_copy({arr_type}* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Setter functions. These functions sets the specified elements of an array given a real number.

******************************************************************************************************/ 
void {arr_func}_set_all_r( coeff_t num, {arr_type}* arr);
void {arr_func}_set_item_i_r( coeff_t num, uint64_t i, {arr_type}* arr);
void {arr_func}_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, {arr_type}* arr);
// ----------------------------------------------------------------------------------------------------

void {arr_func}_set_r(   coeff_t  num,   {arr_type}* arr);
void {arr_func}_set_o( {num_type}* num,   {arr_type}* arr);
void {arr_func}_set_O(   {arr_type}* arrin, {arr_type}* arr);

/**************************************************************************************************//**
@brief Setter functions. These functions sets the specified elements of an array given an OTI number.

******************************************************************************************************/ 
void {arr_func}_set_all_o( {num_type}* src, {arr_type}* arr);
void {arr_func}_set_item_i_o( {num_type}* num, uint64_t i, {arr_type}* arr);
void {arr_func}_set_item_ij_o( {num_type}* num, uint64_t i, uint64_t j, {arr_type}* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Getter functions. These functions extract a member of the array.

******************************************************************************************************/ 
{num_type} {arr_func}_get_item_i(    {arr_type}* arr, uint64_t i);
void      {arr_func}_get_item_i_to( {arr_type}* arr, uint64_t i,             {num_type}* res);
{num_type} {arr_func}_get_item_ij(   {arr_type}* arr, uint64_t i, uint64_t j);
void      {arr_func}_get_item_ij_to({arr_type}* arr, uint64_t i, uint64_t j, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of the {arr_type} type. In this case, all pointers are initialized to NULL to avoid
       unwanted segmentation faults.

       Usage is as follows:
       {arr_type} myArray = {arr_func}_init();

******************************************************************************************************/ 
{arr_type} {arr_func}_init(void);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of the {arr_type} type. In this case, all pointers are initialized to NULL to avoid
       unwanted segmentation faults.

       Usage is as follows:
       {arr_type} myArray = {arr_func}_init();

******************************************************************************************************/ 
void {arr_func}_free({arr_type}* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an empty array similar in order, allocation size and shape from the given array.

@param[in] arr    Address of array from which to get the allocation information.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_empty_like({arr_type}* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an identity array, all zeros and diagonal all ones. All members defined as sparse oti 
       numbers. This is allocated given the number of imagianary directions per order in p_nnz.

@param[in] nrows  Number of rows of the array (This array is square).
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_eye(uint64_t nrows);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an array filled with ones, defined as sparse oti numbers. This is allocated given the
       number of imagianry directions per order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_ones(uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an array filled with zeros, defined as sparse oti numbers. This is allocated given the
       number of imagianry directions per order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_zeros(uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an empty array of sparse oti numbers. This is allocated given the
       number of imagianry directions per order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_createEmpty(uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

#endif