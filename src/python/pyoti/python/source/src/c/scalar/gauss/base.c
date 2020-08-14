
// ****************************************************************************************************
void {fenum_func}_get_order_im_to( ord_t order, {fenum_type}* num, {fenum_type}* res){{
    
    uint64_t k;

    {fenum_func}_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){{        
        {num_func}_get_order_im_to( order, &num->p_data[k], &res->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_get_order_im( ord_t order, {fenum_type}* num){{
    
    {fenum_type} res;

    res = {fenum_func}_zeros( num->nip);
    {fenum_func}_get_order_im_to( order, num, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_extract_im_to( imdir_t idx, ord_t order, {fenum_type}* num, {fenum_type}* res){{
    
    uint64_t k;

    {fenum_func}_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){{        
        {num_func}_extract_im_to( idx, order, &num->p_data[k], &res->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_extract_im( imdir_t idx, ord_t order, {fenum_type}* num){{
    
    {fenum_type} res = {fenum_func}_zeros( num->nip);

    {fenum_func}_extract_im_to( idx, order, num, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_extract_deriv_to( imdir_t idx, ord_t order, {fenum_type}* num, {fenum_type}* res){{
    
    uint64_t k;

    {fenum_func}_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){{        
        {num_func}_extract_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_extract_deriv( imdir_t idx, ord_t order, {fenum_type}* num){{
    
    {fenum_type} res;

    res = {fenum_func}_zeros( num->nip);

    {fenum_func}_extract_deriv_to( idx, order, num, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_get_deriv_to( imdir_t idx, ord_t order, {fenum_type}* num, {fenum_type}* res){{
    
    uint64_t k;

    {fenum_func}_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){{        
        {num_func}_get_deriv_to( idx, order, &num->p_data[k], &res->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_get_deriv( imdir_t idx, ord_t order, {fenum_type}* num){{
    
    {fenum_type} res;

    res = {fenum_func}_zeros( num->nip);

    {fenum_func}_get_deriv_to( idx, order, num, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_get_im_to( imdir_t idx, ord_t order, {fenum_type}* num, {fenum_type}* res){{
    
    uint64_t k;

    {fenum_func}_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){{       
        {num_func}_get_im_to_o( idx, order, &num->p_data[k], &res->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_get_im( imdir_t idx, ord_t order, {fenum_type}* num){{
    
    {fenum_type} res;

    res = {fenum_func}_zeros( num->nip);

    {fenum_func}_get_im_to( idx, order, num, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_type}_truncate_im_to( imdir_t idx, ord_t order, {fenum_type}* num,  {fenum_type}* res){{
    
    uint64_t k;

    {fenum_func}_dimCheck(num,res);

    for (k = 0; k<num->nip; k++ ){{        
        {num_func}_truncate_im_to( idx, order, &num->p_data[k], &res->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_type}_truncate_im( imdir_t idx, ord_t order, {fenum_type}* num){{
    
    {fenum_type} res;

    res = {fenum_func}_zeros( num->nip);

    {fenum_type}_truncate_im_to( idx, order, num, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_set_im_r( coeff_t val, imdir_t idx, ord_t order, {fenum_type}* num){{
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){{        
        {num_func}_set_im_r( val, idx, order, &num->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_set_im_o( {num_type}* val, imdir_t idx, ord_t order, {fenum_type}* num){{
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){{        
        {num_func}_set_im_o( val, idx, order, &num->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_set_im_f( {fenum_type}* val, imdir_t idx, ord_t order, {fenum_type}* num){{
    
    uint64_t k;

    {fenum_func}_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){{        
        {num_func}_set_im_o( &val->p_data[k], idx, order, &num->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_set_deriv_r( coeff_t val, imdir_t idx, ord_t order, {fenum_type}* num){{
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){{        
        {num_func}_set_deriv_r( val, idx, order, &num->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_set_deriv_o( {num_type}* val, imdir_t idx, ord_t order, {fenum_type}* num){{
    
    uint64_t k;

    for (k = 0; k<num->nip; k++ ){{        
        {num_func}_set_deriv_o( val, idx, order, &num->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_set_deriv_f( {fenum_type}* val, imdir_t idx, ord_t order, {fenum_type}* num){{
    
    uint64_t k;

    {fenum_func}_dimCheck(val,num);

    for (k = 0; k<num->nip; k++ ){{        
        {num_func}_set_deriv_o( &val->p_data[k], idx, order, &num->p_data[k]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_copy( {fenum_type}* src){{
    
    {fenum_type} res = {fenum_func}_createEmpty(src->nip);

    {fenum_func}_copy_to( src, &res);
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_copy_to( {fenum_type}* src, {fenum_type}* dst){{
    
    uint64_t i;

    {fenum_func}_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){{        
        {num_func}_set_o_to( &src->p_data[i], &dst->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_set_f_to( {fenum_type}* num, {fenum_type}* res){{
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){{        
        {num_func}_set_o_to( &num->p_data[i], &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_set_o_to( {num_type}* num, {fenum_type}* res){{
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){{        
        {num_func}_set_o_to( num, &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_set_r_to( coeff_t num, {fenum_type}* res){{
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){{        
        {num_func}_set_r_to( num, &res->p_data[i]);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_set_item_k_o( {num_type}* num, uint64_t k, {fenum_type}* res){{
    
    if (k < res->nip){{
        {num_func}_set_o_to(num, &res->p_data[k]); 
    }} else {{
        printf("ERROR: Index out of bounds in {fenum_func}_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_set_item_k_r(   coeff_t  num, uint64_t k, {fenum_type}* res){{

    if (k < res->nip){{
        {num_func}_set_r_to(num, &res->p_data[k]); 
    }} else {{
        printf("ERROR: Index out of bounds in {fenum_func}_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_type} {fenum_func}_get_item_k({fenum_type}* num, uint64_t k){{

    {num_type}  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){{
        res = num->p_data[k];   
    }} else {{
        printf("ERROR: Index out of bounds in {fenum_func}_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.
    }}

    // This is returned uninitialized.
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_get_item_k_to({fenum_type}* num, uint64_t k, {num_type}* res){{
    
    if (k < num->nip){{
        {num_func}_set_o_to( &num->p_data[k], res);
    }} else {{
        printf("ERROR: Index out of bounds in {fenum_func}_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fenum_type} {fenum_func}_zeros(uint64_t nip){{

    {fenum_type}  res  = {fenum_func}_createEmpty(nip);    
    {fenum_func}_set_r_to( 0.0, &res);
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline {fenum_type} {fenum_func}_createEmpty( uint64_t nip ){{

    {fenum_type}  res;
    uint64_t i;    

    // Allocate memory and check if correctly allocated.
    res.p_data = ({num_type}*) malloc( nip * sizeof( {num_type} ) );

    if ( res.p_data == NULL ){{
        printf("ERROR: Not enough memory to handle {fenum_func}.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }}
    
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_free({fenum_type}* num){{
    
    uint64_t i;

    if (num->p_data != NULL){{
        free(num->p_data);
    }}

    *num = {fenum_func}_init();
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline {fenum_type} {fenum_func}_init(void){{
    
    {fenum_type} res;
    
    res.p_data  = NULL;    
    res.nip = 0;

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline {fenum_type} {fenum_func}_empty_like({fenum_type}* arr){{

    return {fenum_func}_createEmpty(arr->nip);

}}
// ----------------------------------------------------------------------------------------------------
