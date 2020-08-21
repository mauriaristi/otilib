#ifndef OTI_{module_name_upper}_SCALAR_GAUSS_BASE_H
#define OTI_{module_name_upper}_SCALAR_GAUSS_BASE_H

void     {fenum_func}_get_order_im_to( ord_t order, {fenum_type}* num, {fenum_type}* res);
{fenum_type} {fenum_func}_get_order_im(    ord_t order, {fenum_type}* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific imaginary direction from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
{fenum_type} {fenum_func}_get_im(    imdir_t idx, ord_t order, {fenum_type}* num);
void     {fenum_func}_get_im_to( imdir_t idx, ord_t order, {fenum_type}* num, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific derivative from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
{fenum_type} {fenum_func}_get_deriv(    imdir_t idx, ord_t order, {fenum_type}* num);
void     {fenum_func}_get_deriv_to( imdir_t idx, ord_t order, {fenum_type}* num, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void {fenum_func}_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, {fenum_type}* num);
void {fenum_func}_set_im_o( {num_type}* val, imdir_t idx, ord_t order, {fenum_type}* num);
void {fenum_func}_set_im_f(  {fenum_type}* val, imdir_t idx, ord_t order, {fenum_type}* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void {fenum_func}_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, {fenum_type}* num);
void {fenum_func}_set_deriv_o( {num_type}* val, imdir_t idx, ord_t order, {fenum_type}* num);
void {fenum_func}_set_deriv_f(  {fenum_type}* val, imdir_t idx, ord_t order, {fenum_type}* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
{fenum_type} {fenum_func}_extract_im(    imdir_t idx, ord_t order, {fenum_type}* num);
void     {fenum_func}_extract_im_to( imdir_t idx, ord_t order, {fenum_type}* num, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
{fenum_type} {fenum_func}_extract_deriv(    imdir_t idx, ord_t order, {fenum_type}* num);
void     {fenum_func}_extract_deriv_to( imdir_t idx, ord_t order, {fenum_type}* num, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate by given imaginary direction.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
{fenum_type} {fenum_func}_truncate_im(    imdir_t idx, ord_t order, {fenum_type}* num);
void     {fenum_func}_truncate_im_to( imdir_t idx, ord_t order, {fenum_type}* num, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
{fenum_type} {fenum_func}_copy(    {fenum_type}* src);
void     {fenum_func}_copy_to( {fenum_type}* src, {fenum_type}* dst);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
void {fenum_func}_set_r(    coeff_t num, {fenum_type}* res);
void {fenum_func}_set_o( {num_type}* num, {fenum_type}* res);
void {fenum_func}_set_f(  {fenum_type}* num, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num OTI number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
@param[in] dhl Direction helper list
******************************************************************************************************/
void {fenum_func}_set_item_k_r(   coeff_t  num, uint64_t k, {fenum_type}* res);
void {fenum_func}_set_item_k_o( {num_type}* num, uint64_t k, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
@param[in] dhl Direction helper list
******************************************************************************************************/
{num_type} {fenum_func}_get_item_k(   {fenum_type}* num, uint64_t k);
void      {fenum_func}_get_item_k_to({fenum_type}* num, uint64_t k, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
{fenum_type} {fenum_func}_zeros(uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
{fenum_type} {fenum_func}_createEmpty(uint64_t nIntPts);
{fenum_type} {fenum_func}_empty_like({fenum_type}* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse oti number.

@param[in] num FE{num_func} to free
******************************************************************************************************/
void {fenum_func}_free({fenum_type}* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get OTI truncation order.

@param[in] num FE{num_func}
******************************************************************************************************/
ord_t {fenum_func}_get_order( {fenum_type}* num );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a {fenum_func} structure.

******************************************************************************************************/
{fenum_type} {fenum_func}_init(void);
// ----------------------------------------------------------------------------------------------------

#endif