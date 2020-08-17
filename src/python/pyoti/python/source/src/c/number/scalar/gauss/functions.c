
// ****************************************************************************************************
{fenum_type} {fenum_func}_atanh({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);

    {fenum_func}_atanh_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_asinh({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);

    {fenum_func}_asinh_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_acosh({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);

    {fenum_func}_acosh_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_type}_tanh({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);

    {fenum_type}_tanh_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_cosh({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_cosh_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_sinh({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_sinh_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_asin({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_asin_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_acos({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_acos_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_atan({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_atan_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_type}_tan({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_type}_tan_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_cos({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_cos_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_sin({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_sin_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_logb({fenum_type}* num, double base){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_logb_to(num, base, &res, dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_log10({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_log10_to(num, &res, dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_log({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_log_to(num, &res, dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_exp({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_exp_to(num, &res, dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_cbrt({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);

    {fenum_func}_cbrt_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_sqrt({fenum_type}* num){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);
    
    {fenum_func}_sqrt_to(num, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_pow({fenum_type}* num, double e){{

    {fenum_type} res = {fenum_func}_init();

    res = {fenum_func}_createEmpty(num->nip);

    {fenum_func}_pow_to(num, e, &res, dhl);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_atanh_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_atanh_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_asinh_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_asinh_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_acosh_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_acosh_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_type}_tanh_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_tanh_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_cosh_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_cosh_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_sinh_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_sinh_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_asin_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_asin_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_acos_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_acos_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_atan_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_atan_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_type}_tan_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_tan_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_cos_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_cos_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_sin_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_sin_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_logb_to({fenum_type}* num, double base, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_logb_to(&num->p_data[i], base, &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_log10_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_log10_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_log_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_log_to(&num->p_data[i], &res->p_data[i], dhl);

    }} 

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_exp_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_exp_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_cbrt_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_cbrt_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_sqrt_to({fenum_type}* num, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_sqrt_to(&num->p_data[i], &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_pow_to({fenum_type}* num, double e, {fenum_type}* res){{

    uint64_t i;

    {fenum_func}_dimCheck(num,res);

    for( i = 0; i<num->nip; i++){{
        
        {num_func}_pow_to(&num->p_data[i], e, &res->p_data[i], dhl);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_type} {fenum_func}_integrate_r(coeff_t num, {fenum_type}* w){{

    {num_type}  res = {num_func}_init(); // res = 0.0

    {fenum_func}_integrate_r_to(num, w, &res,  dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_integrate_r_to(coeff_t num, {fenum_type}* w, {num_type}* res){{

    uint64_t i = 0;

    {num_type} tmp;

    // res may not come as zero, Modify this?
    {num_func}_set_r(0,&tmp,dhl);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){{
        {num_func}_sum_oo_to(  &tmp, &w->p_data[i], &tmp, dhl);
    }}

    {num_func}_mul_ro_to( num, &tmp, res, dhl);


}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_type} {fenum_func}_integrate_o({num_type}* num, {fenum_type}* w){{

    {num_type}  res = {num_func}_init(); // res = 0.0

    {fenum_func}_integrate_o_to(num, w, &res,  dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_integrate_o_to({num_type}* num, {fenum_type}* w, {num_type}* res){{

    uint64_t i = 0;

    {num_type} tmp;
    // res may not come as zero, Modify this?
    {num_func}_set_r(0, &tmp, dhl);

    // The loop for every element in num.
    for (i = 0; i < w->nip; i++){{
        {num_func}_sum_oo_to(  &tmp, &w->p_data[i], &tmp, dhl);
    }}

    {num_func}_mul_oo_to( num, &tmp, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
{num_type} {fenum_func}_integrate_f({fenum_type}* num, {fenum_type}* w){{

    {num_type}  res = {num_func}_init(); // res = 0.0

    {fenum_func}_integrate_to(num, w, &res,  dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_integrate_f_to({fenum_type}* num, {fenum_type}* w, {num_type}* res){{

    uint64_t i = 0;
    {num_type} tmp;

    // Check dimensions.
    {fenum_func}_dimCheck( num, w);

    // res may not come as zero, Modify this?
    {num_func}_set_r(0,&tmp,dhl);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){{
        {num_func}_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp, dhl);
    }}

    {num_func}_set_o(&tmp, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_type} {fenum_func}_integrate({fenum_type}* num, {fenum_type}* w){{

    {num_type}  res = {num_func}_init(); // res = 0.0

    {fenum_func}_integrate_to(num, w, &res,  dhl);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_integrate_to({fenum_type}* num, {fenum_type}* w, {num_type}* res){{

    uint64_t i = 0;
    {num_type} tmp;

    // Check dimensions.
    {fenum_func}_dimCheck( num, w);

    // res may not come as zero, Modify this?
    {num_func}_set_r(0,&tmp,dhl);

    // The loop for every element in num.
    for (i = 0; i < num->nip; i++){{        
        {num_func}_gem_oo_to( &w->p_data[i], &num->p_data[i], &tmp, &tmp, dhl);
    }}

    {num_func}_set_o(&tmp, res, dhl);
}}
// ----------------------------------------------------------------------------------------------------