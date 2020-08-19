#ifndef OTI_{module_name_upper}_SCALAR_GAUSS_ALGEBRA_H
#define OTI_{module_name_upper}_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fenum_type} {fenum_func}_neg(   {fenum_type}* num);
void     {fenum_func}_neg_to({fenum_type}* num, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fenum_type} {fenum_func}_sum_ff(   {fenum_type}* lhs, {fenum_type}* rhs);
void     {fenum_func}_sum_ff_to({fenum_type}* lhs, {fenum_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_sum_of(   {num_type}* lhs, {fenum_type}* rhs);
void     {fenum_func}_sum_of_to({num_type}* lhs, {fenum_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_sum_rf(   coeff_t lhs, {fenum_type}* rhs);
void     {fenum_func}_sum_rf_to(coeff_t lhs, {fenum_type}* rhs, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fenum_type} {fenum_func}_sub_ff(     {fenum_type}* lhs,  {fenum_type}* rhs);
void     {fenum_func}_sub_ff_to(  {fenum_type}* lhs,  {fenum_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_sub_of(    {num_type}* lhs,  {fenum_type}* rhs);
void     {fenum_func}_sub_of_to( {num_type}* lhs,  {fenum_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_sub_fo(     {fenum_type}* lhs, {num_type}* rhs);
void     {fenum_func}_sub_fo_to(  {fenum_type}* lhs, {num_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_sub_rf(       coeff_t lhs,  {fenum_type}* rhs);
void     {fenum_func}_sub_rf_to(    coeff_t lhs,  {fenum_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_sub_fr(     {fenum_type}* lhs,    coeff_t rhs);
void     {fenum_func}_sub_fr_to(  {fenum_type}* lhs,    coeff_t rhs, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fenum_type} {fenum_func}_mul_ff(   {fenum_type}* lhs, {fenum_type}* rhs);
void     {fenum_func}_mul_ff_to({fenum_type}* lhs, {fenum_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_mul_of(   {num_type}* lhs, {fenum_type}* rhs);
void     {fenum_func}_mul_of_to({num_type}* lhs, {fenum_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_mul_rf(   coeff_t lhs, {fenum_type}* rhs);
void     {fenum_func}_mul_rf_to(coeff_t lhs, {fenum_type}* rhs, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fenum_type} {fenum_func}_div_ff(     {fenum_type}* lhs,  {fenum_type}* rhs);
void     {fenum_func}_div_ff_to(  {fenum_type}* lhs,  {fenum_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_div_of(    {num_type}* lhs,  {fenum_type}* rhs);
void     {fenum_func}_div_of_to( {num_type}* lhs,  {fenum_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_div_fo(     {fenum_type}* lhs, {num_type}* rhs);
void     {fenum_func}_div_fo_to(  {fenum_type}* lhs, {num_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_div_rf(       coeff_t lhs,  {fenum_type}* rhs);
void     {fenum_func}_div_rf_to(    coeff_t lhs,  {fenum_type}* rhs, {fenum_type}* res);

{fenum_type} {fenum_func}_div_fr(     {fenum_type}* lhs,    coeff_t rhs);
void     {fenum_func}_div_fr_to(  {fenum_type}* lhs,    coeff_t rhs, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

#endif