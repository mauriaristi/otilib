#ifndef OTI_{module_name_upper}_SCALAR_FUNCTIONS_H
#define OTI_{module_name_upper}_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_atanh({num_type}* num);
void {num_func}_atanh_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_asinh({num_type}* num);
void {num_func}_asinh_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_acosh({num_type}* num);
void {num_func}_acosh_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_tanh({num_type}* num);
void {num_func}_tanh_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_sqrt({num_type}* num);
void {num_func}_sqrt_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_cbrt({num_type}* num);
void {num_func}_cbrt_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_cosh({num_type}* num);
void {num_func}_cosh_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_sinh({num_type}* num);
void {num_func}_sinh_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_asin({num_type}* num);
void {num_func}_asin_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_acos({num_type}* num);
void {num_func}_acos_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_atan({num_type}* num);
void {num_func}_atan_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_tan({num_type}* num);
void {num_func}_tan_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_cos({num_type}* num);
void {num_func}_cos_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_sin({num_type}* num );
void {num_func}_sin_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_logb({num_type}* num, double base);
void {num_func}_logb_to({num_type}* num, double base, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_log10({num_type}* num);
void {num_func}_log10_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_log({num_type}* num);
void {num_func}_log_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_exp({num_type}* num);
void {num_func}_exp_to({num_type}* num, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
{num_type} {num_func}_pow({num_type}* num, double e);
void {num_func}_pow_to({num_type}* num, coeff_t e, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

#endif