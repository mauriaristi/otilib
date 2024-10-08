

// ****************************************************************************************************
void {arr_type}_taylor_integrate_to( coeff_t* deltas, {arr_type}* arr, {arr_type}* res){{
    
    uint64_t i;

    {arr_func}_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){{
        
        {num_type}_taylor_integrate_to( deltas, &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_type}_taylor_integrate( coeff_t* deltas, {arr_type}* arr){{
    
    {arr_type} res;

    res = {arr_func}_zeros( arr->nrows, arr->ncols);

    {arr_type}_taylor_integrate_to( deltas, arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void {arr_func}_get_order_im_to( ord_t order, {arr_type}* arr, {arr_type}* res){{
    
    uint64_t i;

    {arr_func}_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){{
        
        {num_func}_get_order_im_to( order, &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_get_order_im( ord_t order, {arr_type}* arr){{
    
    {arr_type} res;

    res = {arr_func}_zeros( arr->nrows, arr->ncols);

    {arr_func}_get_order_im_to( order, arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void {arr_type}_truncate_im_to( imdir_t idx, ord_t order, {arr_type}* arr, {arr_type}* res){{
    
    uint64_t i;

    {arr_func}_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){{
        
        {num_type}_truncate_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_type}_truncate_im( imdir_t idx, ord_t order, {arr_type}* arr){{
    
    {arr_type} res;

    res = {arr_func}_zeros( arr->nrows, arr->ncols);

    {arr_type}_truncate_im_to( idx, order, arr, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------





// Copy operations.
// ****************************************************************************************************
void {arr_func}_copy_to({arr_type}* arr, {arr_type}* res){{

    uint64_t i;
    // TODO: add allocation check.
    if(res->nrows != arr->nrows || res->ncols != arr->ncols || res->size != arr->size){{
        printf("ERROR: Assignment mismatch in dimensions. Check destination.\n");
        exit(OTI_undetErr);
    }} 

    for (i=0; i<arr->size; i++){{

        {num_func}_set_o_to(&arr->p_data[i],&res->p_data[i]);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_copy({arr_type}* arr){{

    {arr_type} res = {arr_func}_empty_like(arr);

    {arr_func}_copy_to(arr,&res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------








// Setters.
// Setter by one index.

// ****************************************************************************************************
inline void {arr_func}_set_r_to( coeff_t num, {arr_type}* arr){{
    
    uint64_t i;

    for (i = 0; i<arr->size; i++ ){{
        {arr_func}_set_item_i_r( num, i, arr);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_set_item_i_r( coeff_t num, uint64_t i, {arr_type}* arr){{
        
    if( i<arr->size ){{
        
        {num_func}_set_r_to( num, &arr->p_data[i]);

    }} else {{

        // res = {num_func}_init();
        
        printf("ERROR: Index out of bounds in {arr_func}_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, {arr_type}* arr){{

    {arr_func}_set_item_i_r( num, j + i*arr->ncols, arr);

}}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
inline void {arr_func}_set_o_to( {num_func}num_t* num, {arr_type}* arr){{

    uint64_t i;

    for (i = 0; i<arr->size; i++ ){{
        {arr_func}_set_item_i_o( num, i, arr);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_set_o_to( {num_func}num_t* num, {arr_type}* arr){{

    uint64_t i;

    for (i = 0; i<arr->size; i++ ){{
        {arr_func}_set_item_i_o( num, i, arr);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_set_item_i_o( {num_func}num_t* src, uint64_t i, {arr_type}* arr){{
    
    if (i < arr->size){{

        {num_func}_set_o_to(src, &arr->p_data[i]);

    }}  else {{
        
        printf("ERROR: Index out of bounds in {arr_func}_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }}
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_set_item_ij_o( {num_func}num_t* num, uint64_t i, uint64_t j, {arr_type}* arr){{

    if ( i < arr->nrows && j < arr->ncols ){{

        {arr_func}_set_item_i_o( num, j + i*arr->ncols, arr);

    }} else {{

        printf("ERROR: Index out of bounds in {arr_func}_get_item_ij(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }}

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void {arr_func}_set_slice_O( {arr_type}* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         {arr_type}* res){{

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // printf("nrows: %lld, ncols %lld \n",nrows, ncols);

    // printf("i: (%lld, %lld, %lld) \n", starti, stopi, stepi);
    // printf("j: (%lld, %lld, %lld) \n", startj, stopj, stepj);

    // Check dimensions:
    if ( (arr->ncols != ncols) ||
         (arr->nrows != nrows)    ){{

        printf("ERROR: Wrong dimensions for input array.\n");
        exit(OTI_BadIndx);

    }}
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){{

        jj = startj;
        
        for ( j = 0; j < ncols; j++){{

            // printf("Setting result ( i, j) (%lld,%lld) from source (ii,jj) (%lld,%lld) \n", i, j, ii, jj);
            // printf("( i, j) (%lld,%lld) equates: %lld\n",  i,  j,  j +  i * res->ncols );
            // printf("(ii,jj) (%lld,%lld) equates: %lld\n", ii, jj, jj + ii * arr->ncols );

            {num_func}_set_o_to( &arr->p_data[  j +  i * arr->ncols ], 
                          &res->p_data[ jj + ii * res->ncols ]);

            jj += stepj;
        
        }}   

        ii += stepi;

    }}



}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_set_slice_o( {num_func}num_t* num, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         {arr_type}* res){{

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?
    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols < ncols) ||
         (res->nrows < nrows)    ){{

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }}
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){{

        jj = startj;
        
        for ( j = 0; j < ncols; j++){{

            {num_func}_set_o_to( num, &res->p_data[ jj + ii * res->ncols ]);

            jj += stepj;
        
        }}   

        ii += stepi;

    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_set_slice_r( coeff_t val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         {arr_type}* res){{

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?
    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols < ncols) || (res->nrows < nrows)    ){{
        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);
    }}
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){{

        jj = startj;
        
        for ( j = 0; j < ncols; j++){{

            {num_func}_set_r_to( val, &res->p_data[ jj + ii * res->ncols ]);
            jj += stepj;
        
        }}   

        ii += stepi;

    }}



}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_set_O( {arr_type}* arrin, {arr_type}* arr){{

    {arr_func}_copy_to( arrin, arr);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
darr_t {arr_func}_get_im(imdir_t idx, ord_t order, {arr_type}* arr){{
    
    darr_t res = darr_zeros( arr->nrows, arr->ncols);
    uint64_t i;
    
    for( i = 0; i < arr->size ; i++ ){{
        
        darr_set_item_i(  
            {num_func}_get_item( idx, order, &arr->p_data[i]), 
            i, &res);

    }}

    return res;
    
}}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
{arr_type} {arr_func}_extract_im(imdir_t idx, ord_t order, {arr_type}* arr){{
    
    {arr_type} res = {arr_func}_zeros( arr->nrows, arr->ncols);
    
    {arr_func}_extract_im_to( idx, order, arr, &res);

    return res;
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_extract_im_to(imdir_t idx, ord_t order, {arr_type}* arr, {arr_type}* res){{
    
    uint64_t i;
    
    // Check first dimensions.
    {arr_func}_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){{
                
        {num_func}_extract_im_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }}
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
darr_t {arr_func}_get_deriv(imdir_t idx, ord_t order, {arr_type}* arr){{
    
    darr_t res = darr_zeros( arr->nrows, arr->ncols);
    uint64_t i;
    
    for( i = 0; i < arr->size ; i++ ){{
        
        darr_set_item_i(  
            {num_func}_get_deriv( idx, order, &arr->p_data[i]), 
            i, &res);

    }}

    return res;
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_get_im_o(imdir_t idx, ord_t order, {arr_type}* arr){{
    
    {arr_type} res = {arr_func}_zeros( arr->nrows, arr->ncols);
    
    {arr_func}_get_im_to( idx, order, arr, &res);

    return res;
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_get_im_to(imdir_t idx, ord_t order, {arr_type}* arr, {arr_type}* res){{
    
    uint64_t i;
    
    // Check first dimensions.
    {arr_func}_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){{
        
        {num_func}_get_im_to_o( idx, order, &arr->p_data[i], &res->p_data[i]);

    }}
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_get_deriv_o(imdir_t idx, ord_t order, {arr_type}* arr){{
    
    {arr_type} res = {arr_func}_zeros( arr->nrows, arr->ncols);
    
    {arr_func}_get_deriv_to( idx, order, arr, &res);

    return res;
    
}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void {arr_func}_get_deriv_to(imdir_t idx, ord_t order, {arr_type}* arr, {arr_type}* res){{
    
    uint64_t i;
    
    // Check first dimensions.
    {arr_func}_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){{
        
        {num_func}_get_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }}
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_extract_deriv(imdir_t idx, ord_t order, {arr_type}* arr){{
    
    {arr_type} res = {arr_func}_zeros( arr->nrows, arr->ncols);
    
    {arr_func}_extract_deriv_to( idx, order, arr, &res);

    return res;
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_extract_deriv_to(imdir_t idx, ord_t order, {arr_type}* arr, {arr_type}* res){{
    
    uint64_t i;
    
    // Check first dimensions.
    {arr_func}_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){{
                
        {num_func}_extract_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i]);

    }}
    
}}
// ----------------------------------------------------------------------------------------------------



















// Getters.
// ****************************************************************************************************
inline {num_func}num_t {arr_func}_get_item_i({arr_type}* arr, uint64_t i){{
    
    {num_func}num_t res;

    // Check boundness
    if (i < arr->size){{

        res = arr->p_data[i];
        
    }} else {{

        // res = {num_func}_init();
        
        printf("ERROR: Index out of bounds in {arr_func}_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }}

    return res;
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_func}num_t {arr_func}_get_item_ij({arr_type}* arr, uint64_t i, uint64_t j){{

    {num_func}num_t res = {arr_func}_get_item_i(arr, j + i*arr->ncols );

    return res;

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void {arr_func}_get_item_i_to({arr_type}* arr, uint64_t i, {num_func}num_t* res){{
    
    // Check boundness
    if (i < arr->size){{

        {num_func}_set_o_to( &arr->p_data[i], res);
        
    }} else {{
        // Raise error?
        printf("ERROR: Index out of bounds in {arr_func}_get_item_i_to(...)\n");
        exit(OTI_BadIndx);
    }}
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_get_item_ij_to({arr_type}* arr, uint64_t i, uint64_t j, {num_func}num_t* res){{

    {arr_func}_get_item_i_to(arr, j + i*arr->ncols, res);

}}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
{arr_type} {arr_func}_get_slice( {arr_type}* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj){{

    uint64_t ncols, nrows; // Resulting number of rows and columns
    {arr_type} res = {arr_func}_init();

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);
    
    res = {arr_func}_zeros( nrows, ncols);

    {arr_func}_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void {arr_func}_get_slice_to( {arr_type}* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         {arr_type}* res){{

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols != ncols) || (res->nrows != nrows) ){{

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }}
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){{

        jj = startj;
        
        for ( j = 0; j < ncols; j++){{

            // printf("Setting result ( i, j) (%lld,%lld) from source (ii,jj) (%lld,%lld) \n", i, j, ii, jj);
            // printf("( i, j) (%lld,%lld) equates: %lld\n",  i,  j,  j +  i * res->ncols );
            // printf("(ii,jj) (%lld,%lld) equates: %lld\n", ii, jj, jj + ii * arr->ncols );

            {num_func}_set_o_to( &arr->p_data[ jj + ii * arr->ncols ], &res->p_data[  j +  i * res->ncols ]);

            jj += stepj;
        
        }}   

        ii += stepi;

    }}

}}
// ----------------------------------------------------------------------------------------------------

// Memory management.
// ****************************************************************************************************
{arr_type} {arr_func}_eye(uint64_t nrows){{

    {arr_type}  res = {arr_func}_zeros( nrows, nrows, p_nnz, order);
    uint64_t i;
    
    for (i=0; i<res.nrows; i++ ){{
        
        res.p_data[ i + i*res.ncols ] = {num_func}_create_r(1.0);

    }}
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_ones(uint64_t nrows, uint64_t ncols){{

    {arr_type}  res = {arr_func}_createEmpty(nrows, ncols);
    uint64_t i;
    
    for (i=0; i<res.size; i++ ){{
        res.p_data[i] = {num_func}_create_r(1.0);
    }}
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{arr_type} {arr_func}_zeros(uint64_t nrows, uint64_t ncols){{

    {arr_type}  res = {arr_func}_createEmpty(nrows, ncols);
    uint64_t i;
    
    for (i=0; i<res.size; i++ ){{
        res.p_data[i] = {num_func}_create_r(0.0);
    }}
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline {arr_type} {arr_func}_empty_like({arr_type}* arr){{

    {arr_type}  res = {arr_func}_createEmpty(arr->nrows, arr->ncols);    
    
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline {arr_type} {arr_func}_createEmpty(uint64_t nrows, uint64_t ncols){{

    {arr_type}  res = {arr_func}_init();
    void*    memory = NULL;
    size_t   allocation_size;
    uint64_t i, size = nrows * ncols;
    
    allocation_size = size * sizeof({num_func}num_t); ;

    // Allocate memory and check if correctly allocated.
    res.p_data = ({num_func}num_t*) malloc(allocation_size);

    if ( memory == NULL ){{
        printf("ERROR: Not enough memory to handle array of sparse otis.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }}

    // This is returned uninitialized.
    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_free({arr_type}* arr){{
    
    uint64_t i;

    if ( arr->p_data!= NULL ){{        
        free(arr->p_data);
    }}

    (*arr) = {arr_func}_init();

}}
// ----------------------------------------------------------------------------------------------------

// Initialization
// ****************************************************************************************************
inline {arr_type} {arr_func}_init(void){{

    {arr_type} res;

    res.p_data = NULL;
    res.nrows = 0;
    res.ncols = 0;
    res.size  = 0;

    return res;

}}
// ----------------------------------------------------------------------------------------------------