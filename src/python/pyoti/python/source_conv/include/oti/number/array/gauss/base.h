#ifndef OTI_{module_name_upper}_ARRAY_GAUSS_BASE_H
#define OTI_{module_name_upper}_ARRAY_GAUSS_BASE_H

void      {fearr_func}_get_order_im_to( ord_t order, {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_get_order_im(    ord_t order, {fearr_type}* arr);

{fearr_type} {fearr_func}_get_deriv(   imdir_t idx, ord_t order, {fearr_type}* arr);
void      {fearr_func}_get_deriv_to(imdir_t idx, ord_t order, {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

{fearr_type} {fearr_func}_get_im(      imdir_t idx, ord_t order, {fearr_type}* arr);
void      {fearr_func}_get_im_to(   imdir_t idx, ord_t order, {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

{fearr_type} {fearr_func}_truncate_im(   imdir_t idx, ord_t order, {fearr_type}* arr);
void      {fearr_func}_truncate_im_to(imdir_t idx, ord_t order, {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy Gauss array.

@param[in] src. Item to copy.
@param[in] res  Result.
@param[in] dhl  Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_copy(   {fearr_type}* src);
void      {fearr_func}_copy_to({fearr_type}* src, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Imaginary direction getters.

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_get_im(    imdir_t idx, ord_t order, {fearr_type}* arr);
void      {fearr_func}_get_im_to( imdir_t idx, ord_t order, {fearr_type}* arr, {fearr_type}* res);

{fearr_type} {fearr_func}_get_deriv(    imdir_t idx, ord_t order, {fearr_type}* arr);
void      {fearr_func}_get_deriv_to( imdir_t idx, ord_t order, {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Imaginary derivative extractors.

@param[in] idx Imagianry index.
@param[in] order Imagianry index.
@param[in] arr Gauss array.
@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_extract_im(    imdir_t idx, ord_t order, {fearr_type}* arr);
void      {fearr_func}_extract_im_to( imdir_t idx, ord_t order, {fearr_type}* arr,  {fearr_type}* res);

{fearr_type} {fearr_func}_extract_deriv(    imdir_t idx, ord_t order, {fearr_type}* arr);
void      {fearr_func}_extract_deriv_to( imdir_t idx, ord_t order, {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Item getters.

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{arr_type}   {fearr_func}_get_item_k(  {fearr_type}* arr, uint64_t k);
{fenum_type}  {fearr_func}_get_item_ij( {fearr_type}* arr, uint64_t i, uint64_t j);
{num_type} {fearr_func}_get_item_ijk({fearr_type}* arr, uint64_t i, uint64_t j, uint64_t k);

void {fearr_func}_get_item_ij_to(  {fearr_type}* arr, uint64_t i, uint64_t j, 
                               {fenum_type}* res);

void {fearr_func}_get_item_k_to(   {fearr_type}* arr, uint64_t k, 
                                {arr_type}* res);

void {fearr_func}_get_item_ijk_to( {fearr_type}* arr, uint64_t i, uint64_t j, uint64_t k, 
                              {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get slice from {fearr_func} object.

@param[in]    arr    array to get slice.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder (if any)
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
{fearr_type} {fearr_func}_get_slice({fearr_type}* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                           dhelpl_t dhl);

void      {fearr_func}_get_slice_to({fearr_type}* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Item setters

@param[in] elm   Element to set
@param[in] i     Row.
@param[in] j     Column.
@param[in] k     Integration point.
@param[in] dhl   Direction helper list.
******************************************************************************************************/
void {fearr_func}_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                            {fearr_type}* res);

void {fearr_func}_set_item_ij_o(  {num_type}* elm, uint64_t i, uint64_t j,
                             {fearr_type}* res);

void {fearr_func}_set_item_ij_f(  {fenum_type}* elm, uint64_t i, uint64_t j,
                            {fearr_type}* res);

void {fearr_func}_set_item_k_r(    coeff_t  elm, uint64_t k, 
                            {fearr_type}* res);

void {fearr_func}_set_item_k_o(  {num_type}* elm, uint64_t k, 
                            {fearr_type}* res);

void {fearr_func}_set_item_k_R(    {arr_type}* elm, uint64_t k, 
                          {fearr_type}* res);

void {fearr_func}_set_item_k_O(    {arr_type}* elm, uint64_t k, 
                          {fearr_type}* res);

void {fearr_func}_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k, 
                             {fearr_type}* res);

void {fearr_func}_set_item_ijk_o( {num_type}* elm, uint64_t i, uint64_t j, uint64_t k, 
                             {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set slice to {fearr_func} object.

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
void {fearr_func}_set_slice_r( coeff_t val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          {fearr_type}* res);
void {fearr_func}_set_slice_o( {num_type}* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          {fearr_type}* res);
void {fearr_func}_set_slice_f( {fenum_type}* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          {fearr_type}* res);
void {fearr_func}_set_slice_O( {arr_type}* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          {fearr_type}* res);
void {fearr_func}_set_slice_F( {fearr_type}* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Broadcasted setter.

@param[in]
@param[in] dhl Direction helper list.
******************************************************************************************************/
void {fearr_func}_set_all_o( {num_type}* num, {fearr_type}* arr );
void {fearr_func}_set_all_r(   coeff_t  num, {fearr_type}* arr );
void {fearr_func}_set_all_f(  {fenum_type}* num, {fearr_type}* arr );

void {fearr_func}_set_r(    coeff_t src, {fearr_type}* res );
void {fearr_func}_set_o( {num_type}* src, {fearr_type}* res );
void {fearr_func}_set_f(  {fenum_type}* src, {fearr_type}* res );

void {fearr_func}_set_R(    darr_t* src, {fearr_type}* res );
void {fearr_func}_set_O(   {arr_type}* src, {fearr_type}* res );
void {fearr_func}_set_F( {fearr_type}* src, {fearr_type}* res );

// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss array as the identity matrix.

@param[in] size     Size of the matrix (final shape: <size,size>)
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_eye( uint64_t size,  uint64_t nip);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss array of Zeros.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss array of ones.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an empty gauss object.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory of Gauss array.

@param[in] arr. Gauss array to free memory.
******************************************************************************************************/
void {fearr_func}_free({fearr_type}* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of Gauss array

******************************************************************************************************/
{fearr_type} {fearr_func}_init(void);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get the max trunctation order of the OTI structure.

@param[in] arr. Gauss array.
@param[in] dhl. Direction helper list.
@param[out] ord. Maximum truncation order.
******************************************************************************************************/
ord_t {fearr_func}_get_order({fearr_type}* arr);
// ----------------------------------------------------------------------------------------------------

#endif