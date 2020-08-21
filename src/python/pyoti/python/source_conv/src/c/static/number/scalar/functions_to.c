

// ****************************************************************************************************
void {num_func}_atanh_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_asinh_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_acosh_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_tanh_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_cbrt_to({num_type}* num, {num_type}* res){{

    {num_func}_pow_to(num, 1./3., res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_sqrt_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_cosh_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_sinh_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_asin_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_acos_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_atan_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_tan_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_cos_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_sin_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_logb_to({num_type}* num, double base, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->{real_str}, base, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_log10_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_log_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_exp_to({num_type}* num, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->{real_str}, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {num_func}_pow_to({num_type}* num, double e, {num_type}* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->{real_str}, e, {oti_order}, derivs);

    {num_func}_feval_to(derivs, num, res);

}}
// ----------------------------------------------------------------------------------------------------

