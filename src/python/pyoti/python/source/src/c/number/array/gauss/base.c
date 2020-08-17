// ****************************************************************************************************
ord_t {fearr_func}_get_order({fearr_type}* arr){{

    ord_t ord = 0;
    uint64_t i;

    for( i = 0; i < arr->nip; i++){{

        ord = MAX( ord, {arr_func}_get_order( &arr->p_data[i]) );

    }}

    return ord;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_get_order_im_to( ord_t order, {fearr_type}* arr, {fearr_type}* res){{
    
    uint64_t i;

    // check memory;
    {fearr_func}_dimCheck_FF_elementwise(arr, res, res);

    for (i = 0; i<arr->nip; i++ ){{
        
        {arr_func}_get_order_im_to( order, &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_get_order_im( ord_t order, {fearr_type}* arr){{
    
    {fearr_type} res;

    res = {fearr_func}_zeros( arr->nrows, arr->ncols, arr->nip);

    {fearr_func}_get_order_im_to( order, arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_copy_to({fearr_type}* src, {fearr_type}* dst){{

    uint64_t i;

    // check memory;
    {fearr_func}_dimCheck_FF_elementwise(src, dst, dst);

    for( i = 0; i < src->nip; i++){{

        {arr_func}_copy_to( &src->p_data[i], &dst->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_copy({fearr_type}* src){{

    {fearr_type} res = {fearr_func}_createEmpty( src->nrows, src->ncols, src->nip);
    
    {fearr_func}_copy_to( src, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_type}_truncate_im_to(imdir_t idx, ord_t order, {fearr_type}* arr, {fearr_type}* res){{

    uint64_t i;

    // check memory;
    {fearr_func}_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){{

        {arr_type}_truncate_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_type}_truncate_im(imdir_t idx, ord_t order, {fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    {fearr_type}_truncate_im_to( idx, order, arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_extract_deriv_to(imdir_t idx, ord_t order, {fearr_type}* arr, {fearr_type}* res){{

    uint64_t i;

    // check memory;
    {fearr_func}_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){{

        {arr_func}_extract_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_extract_deriv( imdir_t idx, ord_t order, {fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_extract_deriv_to( idx, order, arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_get_deriv_to(imdir_t idx, ord_t order, {fearr_type}* arr, {fearr_type}* res){{

    uint64_t i;

    // check memory;
    {fearr_func}_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){{

        {arr_func}_get_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_get_deriv(imdir_t idx, ord_t order, {fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_get_deriv_to( idx, order, arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_get_im_to(imdir_t idx, ord_t order, {fearr_type}* arr, {fearr_type}* res){{

    uint64_t i;

    // check memory;
    {fearr_func}_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){{

        {arr_func}_get_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_get_im(imdir_t idx, ord_t order, {fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_get_im_to( idx, order, arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_extract_im_to(imdir_t idx, ord_t order, {fearr_type}* arr, {fearr_type}* res){{

    uint64_t i;

    // check memory;
    {fearr_func}_dimCheck_FF_elementwise(arr, res, res);

    for( i = 0; i < arr->nip; i++){{

        {arr_func}_extract_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_extract_im(imdir_t idx, ord_t order, {fearr_type}* arr){{

    {fearr_type} res = {fearr_func}_createEmpty( arr->nrows, arr->ncols, arr->nip);
    
    {fearr_func}_extract_im_to( idx, order, arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------








// ****************************************************************************************************
{arr_type} {fearr_func}_get_item_k({fearr_type}* arr, uint64_t k){{
    
    {arr_type} res;
    // TODO: Add bound checks.
    
    res = {arr_func}_zeros(arr->nrows, arr->ncols);

    {fearr_func}_get_item_k_to(arr, k, &res);

    return res;    

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
{fenum_type} {fearr_func}_get_item_ij({fearr_type}* arr, uint64_t i, uint64_t j){{
        
    {fenum_type} res = {fenum_func}_init();
    // TODO: Add bound checks.
    
    res = {fenum_func}_zeros(arr->nip);

    {fearr_func}_get_item_ij_to(arr, i, j, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_type} {fearr_func}_get_item_ijk({fearr_type}* arr, uint64_t i, uint64_t j, uint64_t k){{
    
    {num_type} res;
    
    res = {arr_func}_get_item_ij(&arr->p_data[k], i, j);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_get_slice({fearr_type}* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj){{
    
    int64_t ncols, nrows;
    {fearr_type} res = {fearr_func}_init();

    // TODO: Add bound checks.
    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    res = {fearr_func}_zeros( nrows, ncols, arr->nip);

    {fearr_func}_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_get_item_k_to({fearr_type}* arr, uint64_t k, {arr_type}* res){{
    
    // TODO: Add bound checks.

    {arr_func}_copy_to( &arr->p_data[k], res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_get_item_ij_to({fearr_type}* arr, uint64_t i, uint64_t j, {fenum_type}* res){{
        
    uint64_t k;
    
    {fearr_func}_dimCheck_fF_elementwise(res,arr,arr);

    for (k = 0; k < arr->nip; k++){{
        
        {arr_func}_get_item_ij_to( &arr->p_data[k], i, j, &res->p_data[k]);
    
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_get_item_ijk_to({fearr_type}* arr, uint64_t i, uint64_t j, uint64_t k, {num_type}* res){{
    
    // TODO: Add bound checks.
    if ( k < arr->nip && i < arr->nrows && j < arr->ncols){{

        {arr_func}_get_item_ij_to(&arr->p_data[k], i, j, res);

    }} else {{

        printf("Error: Bad index \n");
        exit(OTI_BadIndx);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_get_slice_to({fearr_type}* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          {fearr_type}* res){{
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols != ncols) || (res->nrows != nrows) || (res->nip != arr->nip)){{

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }}

    for (k = 0; k < arr->nip; k++){{
        
        {arr_func}_get_slice_to( &arr->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_slice_r( coeff_t val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          {fearr_type}* res){{
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols < ncols) || (res->nrows < nrows) ){{

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }}

    for (k = 0; k < res->nip; k++){{
        
        {arr_func}_set_slice_r( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_slice_o( {num_type}* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          {fearr_type}* res){{
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){{
        
        {arr_func}_set_slice_o( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_slice_f( {fenum_type}* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          {fearr_type}* res){{
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->nip != val->nip) ){{

        printf("ERROR: Wrong number of integration points.\n");
        exit(OTI_BadIndx);

    }}

    for (k = 0; k < res->nip; k++){{
        
        {arr_func}_set_slice_o( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_slice_O( {arr_type}* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          {fearr_type}* res){{
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    for (k = 0; k < res->nip; k++){{
        
        {arr_func}_set_slice_O( val, starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_slice_F( {fearr_type}* val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          {fearr_type}* res){{
        
    uint64_t k;
    int64_t ncols, nrows;

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->nip != val->nip) ){{

        printf("ERROR: Wrong number of integration points.\n");
        exit(OTI_BadIndx);

    }}

    for (k = 0; k < res->nip; k++){{
        
        {arr_func}_set_slice_O( &val->p_data[k], starti, stopi, stepi, startj, stopj, stepj, &res->p_data[k]);
    
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_item_k( {arr_type}* arr , uint64_t k, {fearr_type}* res){{
    
    // No new allocation needed.
    {arr_func}_copy_to( arr, &res->p_data[k]);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_item_ij_f({fenum_type}* num, uint64_t i, uint64_t j, {fearr_type}* res){{
    
    uint64_t k;

    //Check
    {fearr_func}_dimCheck_fF_elementwise(num,res,res);

    for (k = 0; k < num->nip; k++){{
        
        {arr_func}_set_item_ij_o( &num->p_data[k], i, j, &res->p_data[k] );

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_item_ij_o( {num_type}* num, uint64_t i, uint64_t j, {fearr_type}* res){{
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){{
        
        {arr_func}_set_item_ij_o( num, i, j, &res->p_data[k] );

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, {fearr_type}* res){{
    
    uint64_t k;

    //Check
    for (k = 0; k < res->nip; k++){{
        
        {arr_func}_set_item_ij_r( num, i, j, &res->p_data[k] );

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_item_ijk({num_type}* num, uint64_t i, uint64_t j, uint64_t k, 
        {fearr_type}* res){{

    {arr_func}_set_item_ij_o( num, i, j, &res->p_data[k]);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_f_to( {fenum_type}* num, {fearr_type}* res ){{ 
    
    uint64_t i;
    
    {fearr_func}_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){{

        {arr_func}_set_o_to( &num->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_o_to( {num_type}* num, {fearr_type}* res ){{ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){{

        {arr_func}_set_o_to( num, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_r_to( coeff_t num, {fearr_type}* res ){{ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){{

        {arr_func}set_r_to( num, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void {fearr_func}_set_f_to( {fenum_type}* num, {fearr_type}* res ){{ 
    
    uint64_t i;
    
    {fearr_func}_dimCheck_fF_elementwise(num,res,res);

    for( i = 0; i < res->nip; i++){{

        {arr_func}_set_o_to( &num->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_set_o_to( {num_type}* num, {fearr_type}* res ){{ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){{

        {arr_func}_set_o_to( num, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}set_r_to( coeff_t num, {fearr_type}* res ){{ 
    
    uint64_t i;
    
    for( i = 0; i < res->nip; i++){{

        {arr_func}set_r_to( num, &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_eye( uint64_t size, uint64_t nip){{ 
    
    uint64_t i,k;

    {fearr_type} res = {fearr_func}_createEmpty( size, size, nip);
    
    for( k = 0; k < res.nip; k++){{
        {arr_func}set_r_to( 0.0, &res.p_data[k]);
    }}
    
    for( i = 0; i < res.nrows; i++){{    
        for( k = 0; k < res.nip; k++){{
            {arr_func}_set_item_ij_r( 1.0, i, i, &res.p_data[k]);
        }}
    }}

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_zeros( uint64_t nrows,   uint64_t ncols, uint64_t nip ){{ 
    
    uint64_t i;

    {fearr_type} res = {fearr_func}_createEmpty( nrows, ncols, nip);
    
    for( i = 0; i < res.nip; i++){{
        {arr_func}set_r_to( 0.0, &res.p_data[i]);
    }}

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip  ){{ 
    
    uint64_t i;

    {fearr_type} res = {fearr_func}_createEmpty( nrows, ncols, nip);
    
    for( i = 0; i < res.nip; i++){{
        {arr_func}_set_r_to( 1.0, &res.p_data[i]);
    }}

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t nip){{  
    
    uint64_t i;

    {fearr_type} res = {fearr_func}_init();

    res.nrows    =  nrows;
    res.ncols    =  ncols;
    res.size     =  nrows*ncols;
    
    res.nip  =  nip;

    // Allocate memory.
    res.p_data   = ({arr_type}*) malloc( res.nip * sizeof({arr_type}) );

    if (res.p_data == NULL){{
        printf("--- MemoryError ---\n");
        exit(1);
    }}

    for( i = 0; i < res.nip; i++){{
        res.p_data[i] = {arr_func}_createEmpty( nrows, ncols);
    }}

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fearr_func}_free({fearr_type}* arr){{
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (arr->p_data != NULL){{
        // Free all arrays.
        for (i = 0; i<arr->nip; i++){{        
            {arr_func}_free(&arr->p_data[i]); 
        }}
        // Free pointer 
        free(arr->p_data);
    }}

    *arr = {fearr_func}_init();
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{fearr_type} {fearr_func}_init(void){{
    
    {fearr_type} res;
    
    res.p_data  = NULL;  
    res.nrows   = 0;   
    res.ncols   = 0;   
    res.size    = 0;    
    res.nip     = 0; 

    return res;

}}
// ----------------------------------------------------------------------------------------------------