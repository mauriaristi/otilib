// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
void {arr_func}_dotproduct_OO_to({arr_type}* arr1, {arr_type}* arr2, {num_type}* res){{

    uint64_t i;
    
    {num_type} tmp;

    // check for dimensions.
    {arr_func}_dimCheck_OO_samesize( arr1, arr2 );

    {num_func}_set_r_to( 0.0, &tmp);

    for ( i = 0; i < arr1->size; i++){{

        {num_func}_gem_oo_to( &arr1->p_data[ i ], &arr2->p_data[ i ], &tmp, &tmp);
                   
    }}

    {num_func}_set_o_to(&tmp, res);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_dotproduct_RO_to(darr_t* arr1, {arr_type}* arr2, {num_type}* res){{

    uint64_t i;
    
    {num_type} tmp;

    // check for dimensions.
    {arr_func}_dimCheck_RO_samesize( arr1, arr2 );

    {num_func}_set_r_to( 0.0, &tmp);

    for ( i = 0; i < arr1->size; i++){{
        {num_func}_gem_ro_to( arr1->p_data[ i ], &arr2->p_data[ i ], &tmp, &tmp);                   
    }}

    {num_func}_set_o_to(&tmp, res);

}}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.
// 2.1. Inner product.
// 2.2. Transpose.
// 2.3. Inversion.
// 2.4. Determinant.
// 2.5. Norm.

// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
void {arr_func}_matmul_OO_to({arr_type}* arr1, {arr_type}* arr2, {arr_type}* res){{

    uint64_t i, j, k;
    
    {num_type} tmp;

    // check for dimensions.
    {arr_func}_dimCheck_OO_matmul(arr1, arr2, res);

    for ( i = 0; i < arr1->nrows; i++){{
        
        for( j = 0; j < arr2->ncols; j++){{

            // tmp = 0
            {num_func}_set_r_to( 0.0, &tmp);

            for( k = 0; k < arr1->ncols; k++){{

                // tmp = arr1[i,k] * arr2[k,j] + tmp

                {num_func}_gem_oo_to( &arr1->p_data[ k + i * arr1->ncols ],
                                &arr2->p_data[ j + k * arr2->ncols ],
                                &tmp, &tmp);
                   
            }}

            {arr_func}_set_item_ij_o( &tmp, i, j, res);

        }}

    }}
    

}}
// ----------------------------------------------------------------------------------------------------


// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
void {arr_func}_matmul_OR_to({arr_type}* arr1, darr_t* arr2, {arr_type}* res){{
        
    uint64_t i, j, k;
    
    {num_type} tmp;

    // check for dimensions.
    {arr_func}_dimCheck_OR_matmul(arr1, arr2, res);

    for ( i = 0; i < arr1->nrows; i++){{
        
        for( j = 0; j < arr2->ncols; j++){{

            {num_func}_set_r_to( 0.0, &tmp);

            for( k = 0; k < arr1->ncols; k++){{

                {num_func}_gem_ro_to(  arr2->p_data[ j + k * arr2->ncols ],
                                &arr1->p_data[ k + i * arr1->ncols ],
                                &tmp ,&tmp);
                   
            }}

            {arr_func}_set_item_ij_o( &tmp, i, j, res);

        }}

    }}

}}
// ----------------------------------------------------------------------------------------------------


// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
void {arr_func}_matmul_RO_to(darr_t* arr1, {arr_type}* arr2, {arr_type}* res){{
        
    uint64_t i, j, k;
    {num_type} tmp;

    // check for dimensions.
    {arr_func}_dimCheck_RO_matmul(arr1, arr2, res);

    for ( i = 0; i < arr1->nrows; i++){{
        
        for( j = 0; j < arr2->ncols; j++){{

            {num_func}_set_r_to( 0.0, &tmp);

            for( k = 0; k < arr1->ncols; k++){{

                {num_func}_gem_ro_to(  arr1->p_data[ k + i * arr1->ncols ], 
                                &arr2->p_data[ j + k * arr2->ncols ], &tmp ,&tmp);
                   
            }}

            {arr_func}_set_item_ij_o( &tmp, i, j, res);

        }}

    }}

}}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
void {arr_type}ranspose_to({arr_type}* arr1, {arr_type}* res){{
    
    uint64_t i, j;

    for ( i = 0; i<arr1->nrows; i++){{
        for ( j = 0; j<arr1->ncols; j++){{
            {arr_func}_set_item_ij_o( &arr1->p_data[  j + i*arr1->ncols  ],  j, i, res);
        }}
    }}
    
}}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
void {arr_func}_invert_to({arr_type}* arr1, {arr_type}* res){{

    {arr_type} tmpA1 = {arr_func}_init();
    
    {num_type} tmp1, tmp2, tmp3, det;

    // Check dimensions.
    {arr_func}_dimCheck_O_squareness( arr1, res);

    if(arr1->ncols == 1){{

        {num_func}_pow_to(&arr1->p_data[0],-1.0,&res->p_data[0]);

    }} else if (arr1->ncols == 2){{

        {arr_func}_det_to( arr1, &det); // Get determinant.

        // res->p_data[0] =  arr1->p_data[3]/det;
        {num_func}_div_oo_to(&arr1->p_data[3],&det,&tmp1);
        {num_func}_set_o_to( &tmp1, &res->p_data[0]);

        // res->p_data[1] = -arr1->p_data[1]/det;
        {num_func}_div_oo_to(&arr1->p_data[1],&det,&tmp1);
        {num_func}_set_o_to( &tmp1, &res->p_data[1]);
        {num_func}_neg_to(&res->p_data[1],&res->p_data[1]);

        // res->p_data[2] = -arr1->p_data[2]/det;
        {num_func}_div_oo_to(&arr1->p_data[2],&det,&tmp1);
        {num_func}_set_o_to( &tmp1, &res->p_data[2]);
        {num_func}_neg_to(&res->p_data[2],&res->p_data[2]);

        // res->p_data[3] =  arr1->p_data[0]/det;
        {num_func}_div_oo_to(&arr1->p_data[0],&det,&tmp1);
        {num_func}_set_o_to( &tmp1, &res->p_data[3]);

    }} else if (arr1->ncols == 3){{
        
        tmpA1 = {arr_func}_zeros( 2, 2 );
        
        {arr_func}_det_to( arr1, &det); // Get determinant.
        
        // Set position 0,0
        // tmpA1.p_data[0] = arr1->p_data[4];
        {num_func}_set_o_to( &arr1->p_data[4], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[5];
        {num_func}_set_o_to( &arr1->p_data[5], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[7];
        {num_func}_set_o_to( &arr1->p_data[7], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[8];
        {num_func}_set_o_to( &arr1->p_data[8], &tmpA1.p_data[3]);
        
        
        
        
        // res->p_data[0] = darr_det( &tmpA1 )/det;
        {arr_func}_det_to(  &tmpA1, &tmp1);
        {num_func}_div_oo_to( &tmp1,  &det, &res->p_data[0]);

        

        // Set position 0,1
        // tmpA1.p_data[0] = arr1->p_data[2];
        {num_func}_set_o_to( &arr1->p_data[2], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[1];
        {num_func}_set_o_to( &arr1->p_data[1], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[8];
        {num_func}_set_o_to( &arr1->p_data[8], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[7];
        {num_func}_set_o_to( &arr1->p_data[7], &tmpA1.p_data[3]);

        
        // res->p_data[1] = darr_det( &tmpA1 )/det;
        {arr_func}_det_to(  &tmpA1, &tmp1);
        {num_func}_div_oo_to( &tmp1,  &det, &res->p_data[1]);




        // Set position 0,2
        // tmpA1.p_data[0] = arr1->p_data[1];
        {num_func}_set_o_to( &arr1->p_data[1], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[2];
        {num_func}_set_o_to( &arr1->p_data[2], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[4];
        {num_func}_set_o_to( &arr1->p_data[4], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[5];
        {num_func}_set_o_to( &arr1->p_data[5], &tmpA1.p_data[3]);
        
        // res->p_data[2] = darr_det( &tmpA1 )/det;
        {arr_func}_det_to(  &tmpA1, &tmp1);
        {num_func}_div_oo_to( &tmp1,  &det, &res->p_data[2]);



        // Set position 1,0
        // tmpA1.p_data[0] = arr1->p_data[5];
        {num_func}_set_o_to( &arr1->p_data[5], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[3];
        {num_func}_set_o_to( &arr1->p_data[3], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[8];
        {num_func}_set_o_to( &arr1->p_data[8], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[6];
        {num_func}_set_o_to( &arr1->p_data[6], &tmpA1.p_data[3]);
        
        // res->p_data[3] = darr_det( &tmpA1 )/det;
        {arr_func}_det_to(  &tmpA1, &tmp1);
        {num_func}_div_oo_to( &tmp1,  &det, &res->p_data[3]);



        // Set position 1,1
        // tmpA1.p_data[0] = arr1->p_data[0];
        {num_func}_set_o_to( &arr1->p_data[0], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[2];
        {num_func}_set_o_to( &arr1->p_data[2], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[6];
        {num_func}_set_o_to( &arr1->p_data[6], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[8];
        {num_func}_set_o_to( &arr1->p_data[8], &tmpA1.p_data[3]);
        

        // res->p_data[4] = darr_det( &tmpA1 )/det;
        {arr_func}_det_to(  &tmpA1, &tmp1);
        {num_func}_div_oo_to( &tmp1,  &det, &res->p_data[4]);




        // Set position 1,2
        // tmpA1.p_data[0] = arr1->p_data[2];
        {num_func}_set_o_to( &arr1->p_data[2], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[0];
        {num_func}_set_o_to( &arr1->p_data[0], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[5];
        {num_func}_set_o_to( &arr1->p_data[5], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[3];
        {num_func}_set_o_to( &arr1->p_data[3], &tmpA1.p_data[3]);
        
        // res->p_data[5] = darr_det( &tmpA1 )/det;
        {arr_func}_det_to(  &tmpA1, &tmp1);
        {num_func}_div_oo_to( &tmp1,  &det, &res->p_data[5]);





        // Set position 2,0
        // tmpA1.p_data[0] = arr1->p_data[3];
        {num_func}_set_o_to( &arr1->p_data[3], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[4];
        {num_func}_set_o_to( &arr1->p_data[4], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[6];
        {num_func}_set_o_to( &arr1->p_data[6], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[7];
        {num_func}_set_o_to( &arr1->p_data[7], &tmpA1.p_data[3]);
        
        // res->p_data[6] = darr_det( &tmpA1 )/det;
        {arr_func}_det_to(  &tmpA1, &tmp1);
        {num_func}_div_oo_to( &tmp1,  &det, &res->p_data[6]);




        // Set position 2,1
        // tmpA1.p_data[0] = arr1->p_data[1];
        {num_func}_set_o_to( &arr1->p_data[1], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[0];
        {num_func}_set_o_to( &arr1->p_data[0], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[7];
        {num_func}_set_o_to( &arr1->p_data[7], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[6];
        {num_func}_set_o_to( &arr1->p_data[6], &tmpA1.p_data[3]);
        
        // res->p_data[7] = darr_det( &tmpA1 )/det;
        {arr_func}_det_to(  &tmpA1, &tmp1);
        {num_func}_div_oo_to( &tmp1,  &det, &res->p_data[7]);




        // Set position 2,2
        // tmpA1.p_data[0] = arr1->p_data[0];
        {num_func}_set_o_to( &arr1->p_data[0], &tmpA1.p_data[0]);
        // tmpA1.p_data[1] = arr1->p_data[1];
        {num_func}_set_o_to( &arr1->p_data[1], &tmpA1.p_data[1]);
        // tmpA1.p_data[2] = arr1->p_data[3];
        {num_func}_set_o_to( &arr1->p_data[3], &tmpA1.p_data[2]);
        // tmpA1.p_data[3] = arr1->p_data[4];
        {num_func}_set_o_to( &arr1->p_data[4], &tmpA1.p_data[3]);

        // res->p_data[8] = darr_det( &tmpA1 )/det;
        {arr_func}_det_to(  &tmpA1, &tmp1);
        {num_func}_div_oo_to( &tmp1,  &det, &res->p_data[8]);

        {arr_func}_free(&tmpA1);

    }} 

}}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.
// ****************************************************************************************************
void {arr_func}_det_to({arr_type}* arr1, {num_type}* res){{
    
    uint64_t i, j;

    
    {num_type} tmp1, tmp2, tmp3;

    // Check dimensions.
    {arr_func}_dimCheck_O_squareness( arr1, arr1);

    if ( arr1->ncols == 1 ){{

        {num_func}_set_o_to(&arr1->p_data[0], res);

    }} else if (arr1->ncols == 2){{

        {num_func}_mul_oo_to(
            &arr1->p_data[0],
            &arr1->p_data[3],
            &tmp1); 

        {num_func}_mul_oo_to(
            &arr1->p_data[1],
            &arr1->p_data[2],
            &tmp2); 

        {num_func}_sub_oo_to(
            &tmp1,
            &tmp2,
            res);

    }} else if (arr1->ncols >= 3){{
        
        // tmp3 = 0
        {num_func}_set_r_to( 0.0, &tmp3);

        for (j=0; j<arr1->ncols; j++){{
            
            // tmp1 = arr1->p_data[j]
            {num_func}_set_o_to(&arr1->p_data[j], &tmp1);

            for (i=1; i<arr1->nrows; i++){{        
                
                //tmp2 = tmp1 * arr1->p_data[ ( (i+j)%arr1->ncols ) + i*arr1->ncols];
                {num_func}_mul_oo_to(
                    &tmp1,
                    &arr1->p_data[ ( (i+j)%arr1->ncols ) + i*arr1->ncols],
                    &tmp2); 

                {num_func}_set_o_to( &tmp2, &tmp1);

            }}

            // tmp2 = tmp3 + tmp1;
            {num_func}_sum_oo_to( &tmp1, &tmp3, &tmp2 );

            // tmp3 = tmp2;
            {num_func}_set_o_to( &tmp2, &tmp3);             

        }}
        
        for ( j = 0; j<arr1->ncols; j++){{
            
            // tmp1 = arr1->p_data[arr1->ncols-1-j];
            {num_func}_set_o_to(&arr1->p_data[arr1->ncols-1-j], &tmp1);
            
            for ( i = 1; i<arr1->nrows; i++){{        
                
                // tmp1 *= arr1->p_data[ (arr1->ncols-1 - (i+j)%arr1->ncols ) + i*arr1->ncols];
                {num_func}_mul_oo_to(
                    &tmp1,
                    &arr1->p_data[ (arr1->ncols-1 - (i+j)%arr1->ncols ) + i*arr1->ncols],
                    &tmp2); 

                {num_func}_set_o_to( &tmp2, &tmp1);

            }}

            // tmp2 = tmp3 - tmp1;
            {num_func}_sub_oo_to( &tmp3, &tmp1, &tmp2);

            // tmp3 = tmp2;
            {num_func}_set_o_to( &tmp2, &tmp3);  

        }}

        // res = tmp3
        {num_func}_set_o_to(&tmp3, res);

    }}

}}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm
// ****************************************************************************************************
void {arr_func}_norm_to({arr_type}* arr1, {num_type}* res){{
    
    
    uint64_t i;
    {num_type} tmp1, tmp2, tmp3;
    
    {num_func}_set_r_to( 0.0, &tmp3);    
    // 
    for( i = 0; i<arr1->size; i++){{

        // tmp1 = (arr1->p_data[i])^2.0;
        {num_func}_pow_to( &arr1->p_data[i], 2.0, &tmp1);
        
        // tmp2 = tmp3 + tmp1;
        {num_func}_sum_oo_to( &tmp1, &tmp3, &tmp2);

        // tmp3 = tmp2;
        {num_func}_set_o_to( &tmp2, &tmp3);
    
    }}

    // res = sqrt(tmp3);
    {num_func}_sqrt_to(&tmp3, res);
    
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {arr_func}_pnorm_to({arr_type}* arr1, coeff_t p, {num_type}* res){{
        
    uint64_t i;
    {num_type} tmp1, tmp2, tmp3;
    
    {num_func}_set_r_to( 0.0, &tmp3);    
    // 
    for( i = 0; i<arr1->size; i++){{

        // tmp1 = (arr1->p_data[i])^p;
        {num_func}_abs_to( &arr1->p_data[i], &tmp2);
        {num_func}_pow_to( &tmp2, p, &tmp1);
        
        // tmp2 = tmp3 + tmp1;
        {num_func}_sum_oo_to( &tmp1, &tmp3, &tmp2);

        // tmp3 = tmp2;
        {num_func}_set_o_to( &tmp2, &tmp3);
    
    }}

    // res = (tmp3)^(1/p);
    {num_func}_pow_to(&tmp3, 1.0/p, res);
    
}}
// ----------------------------------------------------------------------------------------------------


// 1. Vector operations.
// 1.1.  Dot product.
// 1.1.1  dotproduct(O,O)
// ****************************************************************************************************
{num_type} {arr_func}_dotproduct_OO({arr_type}* arr1, {arr_type}* arr2){{
    
    {num_type} res = {num_func}_init();

    {arr_func}_dotproduct_OO_to( arr1, arr2, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_type} {arr_func}_dotproduct_RO(darr_t* arr1, {arr_type}* arr2){{

    {num_type} res = {num_func}_init();

    {arr_func}_dotproduct_RO_to( arr1, arr2, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// 2. Array operations.
// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
{arr_type} {arr_func}_matmul_OO({arr_type}* arr1, {arr_type}* arr2){{

    {arr_type} res = {arr_func}_init();

    res = {arr_func}_zeros(arr1->nrows, arr2->ncols);

    {arr_func}_matmul_OO_to( arr1, arr2, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
{arr_type} {arr_func}_matmul_OR({arr_type}* arr1, darr_t* arr2){{
        
    {arr_type} res = {arr_func}_init();

    res = {arr_func}_zeros(arr1->nrows, arr2->ncols);

    {arr_func}_matmul_OR_to( arr1, arr2, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
{arr_type} {arr_func}_matmul_RO(darr_t* arr1, {arr_type}* arr2){{
        
    {arr_type} res = {arr_func}_init();

    res = {arr_func}_zeros(arr1->nrows, arr2->ncols);

    {arr_func}_matmul_RO_to( arr1, arr2, &res);

    return res;
    
}}
// ----------------------------------------------------------------------------------------------------

// 2.2. Transpose.
// ****************************************************************************************************
{arr_type} {arr_type}ranspose({arr_type}* arr1){{
        
    {arr_type} res = {arr_func}_init();

    res = {arr_func}_zeros(arr1->ncols, arr1->nrows);

    {arr_type}ranspose_to( arr1, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// 2.3. Inversion.
// ****************************************************************************************************
{arr_type} {arr_func}_invert({arr_type}* arr1){{
    
    {arr_type} res = {arr_func}_init();

    res = {arr_func}_zeros(arr1->ncols, arr1->nrows);

    {arr_func}_invert_to(arr1, &res);

    return res;

}}
// ----------------------------------------------------------------------------------------------------

// 2.4. Determinant.
// ****************************************************************************************************
{num_type} {arr_func}_det({arr_type}* arr1){{
    
    {num_type} res = {num_func}_init();

    {arr_func}_det_to(arr1, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// 2.5. Norm.
// ****************************************************************************************************
{num_type} {arr_func}_norm({arr_type}* arr1){{
    
    {num_type} res = {num_func}_init();

    {arr_func}_norm_to(arr1, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
{num_type} {arr_func}_pnorm({arr_type}* arr1, coeff_t p){{
    
    {num_type} res = {num_func}_init();

    {arr_func}_pnorm_to(arr1, p, &res);

    return res;
}}
// ----------------------------------------------------------------------------------------------------
