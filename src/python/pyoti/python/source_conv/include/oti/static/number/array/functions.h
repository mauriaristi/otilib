#ifndef OTI_{module_name_upper}_ARRAY_FUNCTIONS_H
#define OTI_{module_name_upper}_ARRAY_FUNCTIONS_H

{arr_type} {arr_func}_atanh(   {arr_type}* arr);
void    {arr_func}_atanh_to({arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_asinh(   {arr_type}* arr);
void    {arr_func}_asinh_to({arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_acosh(   {arr_type}* arr);
void    {arr_func}_acosh_to({arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_tanh(    {arr_type}* arr);
void    {arr_func}_tanh_to( {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_cbrt(    {arr_type}* arr);
void    {arr_func}_cbrt_to( {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_sqrt(    {arr_type}* arr);
void    {arr_func}_sqrt_to( {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_cosh(    {arr_type}* arr);
void    {arr_func}_cosh_to( {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_sinh(    {arr_type}* arr);
void    {arr_func}_sinh_to( {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_asin(    {arr_type}* arr);
void    {arr_func}_asin_to( {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_acos(    {arr_type}* arr);
void    {arr_func}_acos_to( {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_atan(    {arr_type}* arr);
void    {arr_func}_atan_to( {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_tan(     {arr_type}* arr);
void    {arr_func}_tan_to(  {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_cos(     {arr_type}* arr);
void    {arr_func}_cos_to(  {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_sin(     {arr_type}* arr);
void    {arr_func}_sin_to(  {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_logb(    {arr_type}* arr, double base);
void    {arr_func}_logb_to( {arr_type}* arr, double base, {arr_type}* res);

{arr_type} {arr_func}_log10(   {arr_type}* arr);
void    {arr_func}_log10_to({arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_log(     {arr_type}* arr);
void    {arr_func}_log_to(  {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_exp(     {arr_type}* arr);
void    {arr_func}_exp_to(  {arr_type}* arr, {arr_type}* res);

{arr_type} {arr_func}_pow(     {arr_type}* arr, double e);
void    {arr_func}_pow_to(  {arr_type}* arr, double e, {arr_type}* res);

#endif