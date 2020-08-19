#ifndef OTI_{module_name_upper}_ARRAY_GAUSS_ALGEBRA_H
#define OTI_{module_name_upper}_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_neg(    {fearr_type}* arr);
void      {fearr_func}_neg_to( {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_sum_FF(   {fearr_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_sum_FF_to({fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sum_fF(    {fenum_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_sum_fF_to( {fenum_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sum_OF(     {arr_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_sum_OF_to(  {arr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sum_RF(      darr_t* lhs, {fearr_type}* rhs);
void      {fearr_func}_sum_RF_to(   darr_t* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sum_oF(   {num_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_sum_oF_to({num_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sum_rF(     coeff_t  lhs, {fearr_type}* rhs);
void      {fearr_func}_sum_rF_to(  coeff_t  lhs, {fearr_type}* rhs, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_sub_FF(    {fearr_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_sub_FF_to( {fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sub_fF(    {fenum_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_sub_fF_to( {fenum_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sub_Ff(    {fearr_type}* lhs, {fenum_type}* rhs);
void      {fearr_func}_sub_Ff_to( {fearr_type}* lhs, {fenum_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sub_OF(      {arr_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_sub_OF_to(   {arr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sub_FO(    {fearr_type}* lhs,   {arr_type}* rhs);
void      {fearr_func}_sub_FO_to( {fearr_type}* lhs,   {arr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sub_RF(       darr_t* lhs, {fearr_type}* rhs);
void      {fearr_func}_sub_RF_to(    darr_t* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sub_FR(    {fearr_type}* lhs,    darr_t* rhs);
void      {fearr_func}_sub_FR_to( {fearr_type}* lhs,    darr_t* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sub_oF(    {num_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_sub_oF_to( {num_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sub_Fo(    {fearr_type}* lhs, {num_type}* rhs);
void      {fearr_func}_sub_Fo_to( {fearr_type}* lhs, {num_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sub_rF(      coeff_t  lhs, {fearr_type}* rhs);
void      {fearr_func}_sub_rF_to(    coeff_t lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_sub_Fr(    {fearr_type}* lhs,   coeff_t  rhs);
void      {fearr_func}_sub_Fr_to( {fearr_type}* lhs,   coeff_t  rhs, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_mul_FF(   {fearr_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_mul_FF_to({fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_mul_fF(    {fenum_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_mul_fF_to( {fenum_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_mul_OF(     {arr_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_mul_OF_to(  {arr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_mul_RF(      darr_t* lhs, {fearr_type}* rhs);
void      {fearr_func}_mul_RF_to(   darr_t* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_mul_oF(   {num_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_mul_oF_to({num_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_mul_rF(     coeff_t  lhs, {fearr_type}* rhs);
void      {fearr_func}_mul_rF_to(  coeff_t  lhs, {fearr_type}* rhs, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_div_FF(    {fearr_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_div_FF_to( {fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_div_fF(     {fenum_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_div_fF_to(  {fenum_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_div_Ff(    {fearr_type}* lhs,  {fenum_type}* rhs);
void      {fearr_func}_div_Ff_to( {fearr_type}* lhs,  {fenum_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_div_OF(      {arr_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_div_OF_to(   {arr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_div_FO(    {fearr_type}* lhs,   {arr_type}* rhs);
void      {fearr_func}_div_FO_to( {fearr_type}* lhs,   {arr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_div_RF(       darr_t* lhs, {fearr_type}* rhs);
void      {fearr_func}_div_RF_to(    darr_t* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_div_FR(    {fearr_type}* lhs,    darr_t* rhs);
void      {fearr_func}_div_FR_to( {fearr_type}* lhs,    darr_t* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_div_oF(    {num_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_div_oF_to( {num_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_div_Fo(    {fearr_type}* lhs, {num_type}* rhs);
void      {fearr_func}_div_Fo_to( {fearr_type}* lhs, {num_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_div_rF(      coeff_t  lhs, {fearr_type}* rhs);
void      {fearr_func}_div_rF_to(    coeff_t lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_div_Fr(    {fearr_type}* lhs,   coeff_t  rhs);
void      {fearr_func}_div_Fr_to( {fearr_type}* lhs,   coeff_t  rhs, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
{arr_type} {fearr_func}_integrate(    {fearr_type}* arr, {fenum_type}* w);
void    {fearr_func}_integrate_to( {fearr_type}* arr, {fenum_type}* w, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

// VECTOR ALGEBRA

/**************************************************************************************************//**
@brief Dot product between two vectors

RES = DOT_PRODUCT( LHS, RHS )

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res result
@param[in] dhl Direction helper list
******************************************************************************************************/
{fenum_type} {fearr_func}_dotproduct_FF(    {fearr_type}* lhs, {fearr_type}* rhs);
void     {fearr_func}_dotproduct_FF_to( {fearr_type}* lhs, {fearr_type}* rhs, {fenum_type}* res);

{fenum_type} {fearr_func}_dotproduct_OF(      {arr_type}* lhs, {fearr_type}* rhs);
void     {fearr_func}_dotproduct_OF_to(   {arr_type}* lhs, {fearr_type}* rhs, {fenum_type}* res);

{fenum_type} {fearr_func}_dotproduct_RF(       darr_t* lhs, {fearr_type}* rhs);
void     {fearr_func}_dotproduct_RF_to(    darr_t* lhs, {fearr_type}* rhs, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

// MATRIX ALGEBRA.

/**************************************************************************************************//**
@brief Matrix multiplication

RES = MATMUL( LHS, RHS )

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res result
@param[in] dhl Direction helper list
******************************************************************************************************/
{fearr_type} {fearr_func}_matmul_FF(    {fearr_type}* lhs, {fearr_type}* rhs);
void      {fearr_func}_matmul_FF_to( {fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_matmul_OF(    {arr_type}*   lhs, {fearr_type}* rhs);
void      {fearr_func}_matmul_OF_to( {arr_type}*   lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_matmul_FO(    {fearr_type}* lhs, {arr_type}*   rhs);
void      {fearr_func}_matmul_FO_to( {fearr_type}* lhs, {arr_type}*   rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_matmul_RF(    darr_t*    lhs, {fearr_type}* rhs);
void      {fearr_func}_matmul_RF_to( darr_t*    lhs, {fearr_type}* rhs, {fearr_type}* res);

{fearr_type} {fearr_func}_matmul_FR(    {fearr_type}* lhs, darr_t*    rhs);
void      {fearr_func}_matmul_FR_to( {fearr_type}* lhs, darr_t*    rhs, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
{fenum_type} {fearr_func}_det(   {fearr_type}* arr);
void     {fearr_func}_det_to({fearr_type}* arr, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fenum_type} {fearr_func}_norm(     {fearr_type}* arr);
void     {fearr_func}_norm_to(  {fearr_type}* arr, {fenum_type}* res);

{fenum_type} {fearr_func}_pnorm(    {fearr_type}* arr, coeff_t p);
void     {fearr_func}_pnorm_to( {fearr_type}* arr, coeff_t p, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
{fearr_type}   {fearr_func}_invert(    {fearr_type}* arr);
void        {fearr_func}_invert_to( {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
{fearr_type}   {fearr_type}ranspose(   {fearr_type}* arr);
void        {fearr_type}ranspose_to({fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

#endif