
// ****************************************************************************************************
{fearr_type} {fearr_func}_atanh({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);

    {fearr_func}_atanh_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_asinh({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);

    {fearr_func}_asinh_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_acosh({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);

    {fearr_func}_acosh_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_tanh({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);

    {fearr_type}anh_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_cbrt({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);

    {fearr_func}_cbrt_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sqrt({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_sqrt_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_cosh({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_cosh_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sinh({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_sinh_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_asin({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_asin_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_acos({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_acos_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_atan({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_atan_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_type}an({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_type}an_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_cos({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_cos_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_sin({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_sin_to(arr, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_logb({fearr_type}* arr, double base){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_logb_to(arr, base, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_log10({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_log10_to(arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_log({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_log_to(arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_exp({fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_exp_to(arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
{fearr_type} {fearr_func}_pow({fearr_type}* arr, double e){{

    {fearr_type} res = {fearr_func}_init();

    res = {fearr_func}_zeros(arr->nrows, arr->ncols, arr->nip);

    {fearr_func}_pow_to(arr, e, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------



















































// ****************************************************************************************************
void {fearr_func}_atanh_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_atanh_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_asinh_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_asinh_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_acosh_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_acosh_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_tanh_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_tanh_to(&arr->p_data[i], &res->p_data[i]);

    }}



}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_cbrt_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_cbrt_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sqrt_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_sqrt_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_cosh_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_cosh_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sinh_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_sinh_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_asin_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_asin_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_acos_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_acos_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_atan_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_atan_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_type}an_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_tan_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_cos_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_cos_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_sin_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_sin_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_logb_to({fearr_type}* arr, double base, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_logb_to(&arr->p_data[i], base, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_log10_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_log10_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_log_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_log_to(&arr->p_data[i], &res->p_data[i]);

    }} 

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_exp_to({fearr_type}* arr, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_exp_to(&arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void {fearr_func}_pow_to({fearr_type}* arr, double e, {fearr_type}* res){{

    uint64_t k;

    {fearr_func}_dimCheck_FF_elementwise(arr, arr, res);

    for( k = 0; k<arr->nip; k++){{
        
        {arr_func}_pow_to(&arr->p_data[i], e, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------