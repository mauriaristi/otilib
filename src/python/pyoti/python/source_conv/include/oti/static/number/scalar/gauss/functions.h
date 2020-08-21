#ifndef OTI_{module_name_upper}_SCALAR_GAUSS_FUNCTIONS_H
#define OTI_{module_name_upper}_SCALAR_GAUSS_FUNCTIONS_H

/**************************************************************************************************//**
@brief Hyperbolic functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fenum_type} {fenum_func}_atanh(    {fenum_type}* num);
void     {fenum_func}_atanh_to( {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_asinh(    {fenum_type}* num);
void     {fenum_func}_asinh_to( {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_acosh(    {fenum_type}* num);
void     {fenum_func}_acosh_to( {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_tanh(     {fenum_type}* num);
void     {fenum_func}_tanh_to(  {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_cosh(     {fenum_type}* num);
void     {fenum_func}_cosh_to(  {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_sinh(     {fenum_type}* num);
void     {fenum_func}_sinh_to(  {fenum_type}* num, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Trigonometric functions.

@param[in] num Value to evaluate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fenum_type} {fenum_func}_asin(     {fenum_type}* num);
void     {fenum_func}_asin_to(  {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_acos(     {fenum_type}* num);
void     {fenum_func}_acos_to(  {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_atan(     {fenum_type}* num);
void     {fenum_func}_atan_to(  {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_tan(      {fenum_type}* num);
void     {fenum_func}_tan_to(   {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_cos(      {fenum_type}* num);
void     {fenum_func}_cos_to(   {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_sin(      {fenum_type}* num);
void     {fenum_func}_sin_to(   {fenum_type}* num, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Logarithm and exponential functions

@param[in] num Value to evaluate.
@param[in] base Log base.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fenum_type} {fenum_func}_logb(     {fenum_type}* num, double base);
void     {fenum_func}_logb_to(  {fenum_type}* num, double base, {fenum_type}* res);

{fenum_type} {fenum_func}_log10(    {fenum_type}* num);
void     {fenum_func}_log10_to( {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_log(      {fenum_type}* num);
void     {fenum_func}_log_to(   {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_exp(      {fenum_type}* num);
void     {fenum_func}_exp_to(   {fenum_type}* num, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Power fuctions

@param[in] num Value to evaluate.
@param[in] e   Exponent
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{fenum_type} {fenum_func}_cbrt(     {fenum_type}* num);
void     {fenum_func}_cbrt_to(  {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_sqrt(     {fenum_type}* num);
void     {fenum_func}_sqrt_to(  {fenum_type}* num, {fenum_type}* res);

{fenum_type} {fenum_func}_pow(      {fenum_type}* num, double e);
void     {fenum_func}_pow_to(   {fenum_type}* num, double e, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration. Performs

res = \sum_{{i=1}}^{{i=nip}} w[i] * num[i]

@param[in] num Gauss scalar to integrate.
@param[in] w   Integration weights.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
{num_type} {fenum_func}_integrate(       {fenum_type}* num, {fenum_type}* w);
void      {fenum_func}_integrate_to(    {fenum_type}* num, {fenum_type}* w, {num_type}* res);

{num_type} {fenum_func}_integrate_f(     {fenum_type}* num, {fenum_type}* w);
void      {fenum_func}_integrate_f_to(  {fenum_type}* num, {fenum_type}* w, {num_type}* res);

{num_type} {fenum_func}_integrate_r(       coeff_t num, {fenum_type}* w);
void      {fenum_func}_integrate_r_to(    coeff_t num, {fenum_type}* w, {num_type}* res);

{num_type} {fenum_func}_integrate_o(    {num_type}* num, {fenum_type}* w);
void      {fenum_func}_integrate_o_to( {num_type}* num, {fenum_type}* w, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

#endif