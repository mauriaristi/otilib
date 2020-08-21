#ifndef OTI_{module_name_upper}_ARRAY_GAUSS_FUNCTIONS_H
#define OTI_{module_name_upper}_ARRAY_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Inverse hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_atanh(    {fearr_type}* arr);
void      {fearr_func}_atanh_to( {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_asinh(    {fearr_type}* arr);
void      {fearr_func}_asinh_to( {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_acosh(    {fearr_type}* arr);
void      {fearr_func}_acosh_to( {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief hyperbolic functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_tanh(     {fearr_type}* arr);
void      {fearr_func}_tanh_to(  {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_sinh(     {fearr_type}* arr);
void      {fearr_func}_sinh_to(  {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_cosh(     {fearr_type}* arr);
void      {fearr_func}_cosh_to(  {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Inverse trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_atan(     {fearr_type}* arr);
void      {fearr_func}_atan_to(  {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_asin(     {fearr_type}* arr);
void      {fearr_func}_asin_to(  {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_acos(     {fearr_type}* arr);
void      {fearr_func}_acos_to(  {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] arr Matrix
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_tan(      {fearr_type}* arr);
void      {fearr_func}_tan_to(   {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_sin(      {fearr_type}* arr);
void      {fearr_func}_sin_to(   {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_cos(      {fearr_type}* arr);
void      {fearr_func}_cos_to(   {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithmic/exponential functions.

@param[in] arr  Matrix
@param[in] base Base.
@param[in] res  Result
@param[in] dhl  Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_logb(     {fearr_type}* arr, double base);
void      {fearr_func}_logb_to(  {fearr_type}* arr, double base, {fearr_type}* res);
{fearr_type} {fearr_func}_log10(    {fearr_type}* arr);
void      {fearr_func}_log10_to( {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_log(      {fearr_type}* arr);
void      {fearr_func}_log_to(   {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_exp(      {fearr_type}* arr);
void      {fearr_func}_exp_to(   {fearr_type}* arr, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power functions.

@param[in] arr Matrix
@param[in] e   Exponent
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fearr_type} {fearr_func}_cbrt(     {fearr_type}* arr);
void      {fearr_func}_cbrt_to(  {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_sqrt(     {fearr_type}* arr);
void      {fearr_func}_sqrt_to(  {fearr_type}* arr, {fearr_type}* res);
{fearr_type} {fearr_func}_pow(      {fearr_type}* arr, double e);
void      {fearr_func}_pow_to(   {fearr_type}* arr, double e, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

#endif