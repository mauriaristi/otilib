// OTI linear algebra on LAPACK: LU factorization and linear solves (see oti/sparse/array/algebra_lu.h).
//
// 1. Internal helpers.
// 2. Packing helpers.
// 3. Solvers: solve, lu_factor, lu_solve.

// The pivot arrays are int32_t in the API and int in the LAPACK wrappers.
typedef char oti_lu_int_is_int32[(sizeof(int) == sizeof(int32_t)) ? 1 : -1];

// Temporal used to rebuild entries in arrso_set_order_colmajor. Must not collide with the temporals
// used by arrso_matmul_OO_to (5) and by the scalar operations (reserved ones).
#define _OTI_LU_TMP 15


// 1. Internal helpers.
// ****************************************************************************************************
static ndir_t lu_max_ndir(bases_t nbases, ord_t order){
    // Largest number of directions of a single order, 1 .. order (1 if the arrays are real).

    ndir_t nmax = 1, nd;
    ord_t p;

    if (nbases == 0){
        return nmax;
    }

    for (p = 1; p <= order; p++){
        nd = dhelp_ndirOrder(nbases, p);
        nmax = MAX(nmax, nd);
    }

    return nmax;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
static int lu_work_size(uint64_t n, uint64_t m, ndir_t nd, uint64_t* size){
    // Size of an n x (m*nd) work buffer. Returns 0 if a LAPACK dimension (n, m*nd) does not fit in
    // an int, or if the buffer size overflows.

    uint64_t cols;

    if ( !oti_lapack_fits(n) || !oti_lapack_fits(m) ){
        return 0;
    }

    if ( nd != 0 && m > UINT64_MAX / nd ){
        return 0;
    }

    cols = m * nd;

    if ( !oti_lapack_fits(cols) ){
        return 0;
    }

    if ( n != 0 && cols > ( SIZE_MAX / sizeof(coeff_t) ) / n ){
        return 0;
    }

    *size = n * cols;

    return 1;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
static int lu_buffer_bytes(uint64_t n1, uint64_t n2, uint64_t n2_count, uint64_t nint, size_t* bytes){
    // Bytes of one buffer holding n1 + n2_count*n2 coefficients followed by nint int32_t values.
    // Returns 0 if the size overflows.

    uint64_t ncoef;

    if ( n2_count != 0 && n2 > ( UINT64_MAX - n1 ) / n2_count ){
        return 0;
    }

    ncoef = n1 + n2_count * n2;

    if ( ncoef > SIZE_MAX / sizeof(coeff_t) ){
        return 0;
    }

    if ( nint > ( SIZE_MAX - ncoef*sizeof(coeff_t) ) / sizeof(int32_t) ){
        return 0;
    }

    *bytes = ncoef*sizeof(coeff_t) + nint*sizeof(int32_t);

    return 1;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
static void lu_set_real_colmajor(coeff_t* buf, arrso_t* arr, dhelpl_t dhl){
    // arr[i,j] = buf[i + j*nrows], clearing every imaginary coefficient.

    uint64_t i, j;

    for (i = 0; i < arr->nrows; i++){
        for (j = 0; j < arr->ncols; j++){
            soti_set_r( buf[ i + j*arr->nrows ], &arr->p_data[ j + i*arr->ncols ], dhl);
        }
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
static void lu_apply_mask(arrso_t* arr, int mask, dhelpl_t dhl){
    // Keeps the strictly lower part (OTI_MASK_STRICT_LOWER), the upper part (OTI_MASK_UPPER) or
    // everything (OTI_MASK_FULL) of arr, in place.

    if ( mask == OTI_MASK_STRICT_LOWER ){
        arrso_tril_to( arr, 1, arr, dhl);
    } else if ( mask == OTI_MASK_UPPER ){
        arrso_triu_to( arr, 0, arr, dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
static void lu_sub_matmul(arrso_t* lhs_src, ord_t ord_lhs, int mask_lhs,
                          arrso_t* rhs_src, ord_t ord_rhs, int mask_rhs,
                          arrso_t* lhs, arrso_t* rhs, arrso_t* prod, arrso_t* acc, dhelpl_t dhl){
    // acc = acc - M_lhs([lhs_src]_ord_lhs) M_rhs([rhs_src]_ord_rhs), M a mask (lu_apply_mask).
    // lhs, rhs and prod are work arrays allocated at the truncation order of the computation, so the
    // product keeps the order ord_lhs + ord_rhs.

    arrso_get_order_im_to( ord_lhs, lhs_src, lhs, dhl);
    lu_apply_mask( lhs, mask_lhs, dhl);

    arrso_get_order_im_to( ord_rhs, rhs_src, rhs, dhl);
    lu_apply_mask( rhs, mask_rhs, dhl);

    arrso_matmul_OO_to( lhs, rhs, prod, dhl);
    arrso_sub_OO_to( acc, prod, acc, dhl);

}
// ----------------------------------------------------------------------------------------------------





// 2. Packing helpers.
// ****************************************************************************************************
bases_t arrso_get_nbases(arrso_t* arr, dhelpl_t dhl){

    imdir_t   maxidx[_MAXORDER_OTI];
    uint8_t    found[_MAXORDER_OTI];
    bases_t   nbases = 0;
    bases_t*  dirs;
    sotinum_t* num;
    uint64_t  i;
    ndir_t    k, nnz;
    ord_t     o, maxord = 0, l;

    memset(found, 0, sizeof(found));

    // Largest direction index per order. Directions with bases <= m are exactly the indices
    // < dhelp_ndirOrder(m, o), so the largest index gives the highest basis.
    for (i = 0; i < arr->size; i++){

        num = &arr->p_data[i];

        for (o = 0; o < num->act_order; o++){

            nnz = num->p_nnz[o];

            for (k = 0; k < nnz; k++){

                if ( !found[o] || num->p_idx[o][k] > maxidx[o] ){
                    maxidx[o] = num->p_idx[o][k];
                    found[o]  = 1;
                }

            }

            if (found[o]){
                maxord = MAX(maxord, o + 1);
            }

        }

    }

    for (o = 0; o < maxord; o++){

        if ( found[o] ){

            dirs = dhelp_get_imdir( maxidx[o], o + 1, dhl);

            for (l = 0; l <= o; l++){
                nbases = MAX(nbases, dirs[l]);
            }

        }

    }

    return nbases;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_get_real_colmajor(arrso_t* arr, coeff_t* buf){

    uint64_t i, j;

    for (i = 0; i < arr->nrows; i++){
        for (j = 0; j < arr->ncols; j++){
            buf[ i + j*arr->nrows ] = arr->p_data[ j + i*arr->ncols ].re;
        }
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_get_order_colmajor(arrso_t* arr, ord_t ord, bases_t nbases, coeff_t* buf){

    uint64_t   i, j, nrows = arr->nrows, ncols = arr->ncols;
    ndir_t     k, nd;
    imdir_t    d;
    sotinum_t* num;

    if ( nbases == 0 || ord == 0 ){
        return;
    }

    nd = dhelp_ndirOrder(nbases, ord);

    memset(buf, 0, nrows * ncols * nd * sizeof(coeff_t));

    for (i = 0; i < nrows; i++){
        for (j = 0; j < ncols; j++){

            num = &arr->p_data[ j + i*ncols ];

            if ( num->act_order < ord ){
                continue;
            }

            for (k = 0; k < num->p_nnz[ord-1]; k++){

                d = num->p_idx[ord-1][k];

                if ( d < nd ){
                    buf[ i + ( d*ncols + j )*nrows ] = num->p_im[ord-1][k];
                }

            }

        }
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_set_order_colmajor(coeff_t* buf, ord_t ord, bases_t nbases, int mask, arrso_t* arr,
                              dhelpl_t dhl){

    uint64_t   i, j, nrows = arr->nrows, ncols = arr->ncols;
    ndir_t     d, nd, nnz;
    ord_t      trc, o;
    coeff_t    val;
    sotinum_t  tmp;
    sotinum_t* num;

    if ( ord == 0 ){
        return;
    }

    nd = ( nbases == 0 ) ? 0 : dhelp_ndirOrder(nbases, ord);

    for (i = 0; i < nrows; i++){
        for (j = 0; j < ncols; j++){

            if ( ( mask == OTI_MASK_STRICT_LOWER && i <= j ) ||
                 ( mask == OTI_MASK_UPPER        && i >  j ) ){
                continue;
            }

            num = &arr->p_data[ j + i*ncols ];

            // Rebuild the entry in a temporal: it has room for every direction of every order.
            trc = MAX(num->trc_order, ord);
            tmp = soti_get_tmp( _OTI_LU_TMP, trc, dhl);
            soti_set_o( num, &tmp, dhl);

            nnz = 0;

            for (d = 0; d < nd; d++){

                val = buf[ i + ( d*ncols + j )*nrows ];

                if ( val != 0.0 ){
                    tmp.p_idx[ord-1][nnz] = d;
                    tmp.p_im[ ord-1][nnz] = val;
                    nnz++;
                }

            }

            tmp.p_nnz[ord-1] = nnz;

            // Actual order: highest order with nonzero coefficients.
            tmp.act_order = 0;
            for (o = trc; o > 0; o--){
                if ( tmp.p_nnz[o-1] > 0 ){
                    tmp.act_order = o;
                    break;
                }
            }

            soti_copy_to( &tmp, num, dhl);

        }
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_permute_rows_to(arrso_t* arr, int32_t* ipiv, arrso_t* res, dhelpl_t dhl){

    uint64_t  k, r, j, ncols = arr->ncols;
    sotinum_t swap;

    if ( arr != res ){
        arrso_copy_to( arr, res, dhl);
    }

    // Entries own their memory, so swapping the structures swaps the numbers.
    for (k = 0; k < res->nrows; k++){

        r = (uint64_t)( ipiv[k] - 1 );

        if ( r != k ){

            for (j = 0; j < ncols; j++){
                swap                          = res->p_data[ j + k*ncols ];
                res->p_data[ j + k*ncols ]    = res->p_data[ j + r*ncols ];
                res->p_data[ j + r*ncols ]    = swap;
            }

        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_tril_to(arrso_t* arr, int strict, arrso_t* res, dhelpl_t dhl){

    uint64_t i, j, idx;
    int      keep;

    arrso_dimCheck_OO_elementwise( arr, res, res);

    for (i = 0; i < arr->nrows; i++){
        for (j = 0; j < arr->ncols; j++){

            idx  = j + i*arr->ncols;
            keep = strict ? ( i > j ) : ( i >= j );

            if ( !keep ){
                soti_set_r( 0.0, &res->p_data[idx], dhl);
            } else if ( arr != res ){
                soti_copy_to( &arr->p_data[idx], &res->p_data[idx], dhl);
            }

        }
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_triu_to(arrso_t* arr, int strict, arrso_t* res, dhelpl_t dhl){

    uint64_t i, j, idx;
    int      keep;

    arrso_dimCheck_OO_elementwise( arr, res, res);

    for (i = 0; i < arr->nrows; i++){
        for (j = 0; j < arr->ncols; j++){

            idx  = j + i*arr->ncols;
            keep = strict ? ( i < j ) : ( i <= j );

            if ( !keep ){
                soti_set_r( 0.0, &res->p_data[idx], dhl);
            } else if ( arr != res ){
                soti_copy_to( &arr->p_data[idx], &res->p_data[idx], dhl);
            }

        }
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_set_nan(arrso_t* arr, dhelpl_t dhl){

    uint64_t i;

    for (i = 0; i < arr->size; i++){
        soti_set_r( NAN, &arr->p_data[i], dhl);
    }

}
// ----------------------------------------------------------------------------------------------------





// 3. Solvers.
// 3.1. Block solver.
// ****************************************************************************************************
int arrso_solve_to(arrso_t* K, arrso_t* b, arrso_t* x, dhelpl_t dhl){

    uint64_t n, m, ksize, wsize;
    size_t   bytes;
    ord_t    order, p, q;
    bases_t  nbases;
    ndir_t   nmax, nd;
    int      info = 0;
    int32_t* ipiv = NULL;
    coeff_t* mem  = NULL;
    coeff_t *kr, *work;
    arrso_t  xtmp = arrso_init(), Kq = arrso_init(), Xq = arrso_init();
    arrso_t  prod = arrso_init(), acc = arrso_init();
    arrso_t* xw = x;

    arrso_dimCheck_O_squareness( K, K);
    arrso_dimCheck_OO_matmul( K, b, x);

    n = K->nrows;
    m = b->ncols;

    if ( n == 0 || m == 0 ){
        return 0;
    }

    order  = MAX( arrso_get_order(K), arrso_get_order(b) );
    nbases = MAX( arrso_get_nbases(K, dhl), arrso_get_nbases(b, dhl) );
    nmax   = lu_max_ndir( nbases, order);

    if ( !lu_work_size(n, n, 1, &ksize) || !lu_work_size(n, m, nmax, &wsize) ||
         !lu_buffer_bytes(ksize, wsize, 1, n, &bytes) ){
        info = OTI_LINALG_ERR_SIZE;
        goto fail;
    }

    // One buffer: real factor, work, pivots.
    mem = (coeff_t*)malloc( bytes );
    if ( mem == NULL ){
        info = OTI_LINALG_ERR_MEMORY;
        goto fail;
    }
    kr   = mem;
    work = kr + ksize;
    ipiv = (int32_t*)( work + wsize );

    // Real part: K_r = P L U, x_0 = K_r^-1 b_0.
    arrso_get_real_colmajor( K, kr);
    oti_dgetrf( (int)n, (int)n, kr, (int)n, ipiv, &info);
    if ( info != 0 ){
        goto fail;
    }

    arrso_get_real_colmajor( b, work);
    oti_dgetrs( 'N', (int)n, (int)m, kr, (int)n, ipiv, work, (int)n, &info);
    if ( info != 0 ){
        goto fail;
    }

    // The result is written order by order while K and b are still read: do not alias them.
    if ( x == K || x == b ){
        xtmp = arrso_zeros_bases( n, m, 0, 0, dhl);
        xw   = &xtmp;
    }

    lu_set_real_colmajor( work, xw, dhl);

    if ( nbases > 0 && order > 0 ){

        // Work arrays at the truncation order (products of order parts keep their order).
        Kq   = arrso_zeros_bases( n, n, nbases, order, dhl);
        Xq   = arrso_zeros_bases( n, m, nbases, order, dhl);
        prod = arrso_zeros_bases( n, m, nbases, order, dhl);
        acc  = arrso_zeros_bases( n, m, nbases, order, dhl);

        for (p = 1; p <= order; p++){

            // acc = [b]_p - sum_{q=1..p} [K]_q x_{p-q}
            arrso_get_order_im_to( p, b, &acc, dhl);

            for (q = 1; q <= p; q++){
                lu_sub_matmul( K, q, OTI_MASK_FULL, xw, p - q, OTI_MASK_FULL, &Kq, &Xq, &prod, &acc, dhl);
            }

            // x_p = K_r^-1 acc, every direction of order p at once.
            nd = dhelp_ndirOrder( nbases, p);
            arrso_get_order_colmajor( &acc, p, nbases, work);
            oti_dgetrs( 'N', (int)n, (int)(m*nd), kr, (int)n, ipiv, work, (int)n, &info);
            if ( info != 0 ){
                goto fail;
            }
            arrso_set_order_colmajor( work, p, nbases, OTI_MASK_FULL, xw, dhl);

        }

    }

    if ( xw != x ){
        arrso_copy_to( xw, x, dhl);
    }

    goto cleanup;

fail:
    arrso_set_nan( x, dhl);

cleanup:
    free(mem);
    arrso_free(&xtmp);
    arrso_free(&Kq);
    arrso_free(&Xq);
    arrso_free(&prod);
    arrso_free(&acc);

    return info;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_solve(arrso_t* K, arrso_t* b, int* status, dhelpl_t dhl){

    arrso_t res = arrso_zeros_bases( K->nrows, b->ncols, 0, 0, dhl);
    int     info;

    info = arrso_solve_to( K, b, &res, dhl);

    if ( status != NULL ){
        *status = info;
    }

    return res;

}
// ----------------------------------------------------------------------------------------------------



// 3.2. LU factorization.
// ****************************************************************************************************
int arrso_lu_factor_to(arrso_t* A, arrso_t* LU, int32_t* ipiv, dhelpl_t dhl){

    uint64_t n, i, j, d, rsize, wsize, blk;
    size_t   bytes;
    ord_t    order, p, q;
    bases_t  nbases;
    ndir_t   nmax, nd;
    int      info = 0, ni;
    coeff_t* mem = NULL;
    coeff_t *lr, *X, *Lb;
    arrso_t  LUtmp = arrso_init(), PA = arrso_init(), Tl = arrso_init(), Tu = arrso_init();
    arrso_t  prod = arrso_init(), acc = arrso_init();
    arrso_t* LUw = LU;

    arrso_dimCheck_O_squareness( A, LU);

    n = A->nrows;

    if ( n == 0 ){
        return 0;
    }

    order  = arrso_get_order(A);
    nbases = arrso_get_nbases(A, dhl);
    nmax   = lu_max_ndir( nbases, order);

    if ( !lu_work_size(n, n, 1, &rsize) || !lu_work_size(n, n, nmax, &wsize) ||
         !lu_buffer_bytes(rsize, wsize, 2, 0, &bytes) ){
        return OTI_LINALG_ERR_SIZE;
    }

    // One buffer: real factors, X (upper part / U), Lb (strictly lower part / L).
    mem = (coeff_t*)malloc( bytes );
    if ( mem == NULL ){
        return OTI_LINALG_ERR_MEMORY;
    }
    lr = mem;
    X  = lr + rsize;
    Lb = X  + wsize;

    ni  = (int)n;
    blk = n*n;

    // Real part: A_r = P L_r U_r.
    arrso_get_real_colmajor( A, lr);
    oti_dgetrf( ni, ni, lr, ni, (int*)ipiv, &info);
    if ( info < 0 ){
        goto cleanup;
    }

    // A is read order by order while the factors are written: do not alias them.
    if ( LU == A ){
        LUtmp = arrso_zeros_bases( n, n, 0, 0, dhl);
        LUw   = &LUtmp;
    }

    lu_set_real_colmajor( lr, LUw, dhl);

    if ( info == 0 && nbases > 0 && order > 0 ){

        // Work arrays at the truncation order (products of order parts keep their order).
        PA   = arrso_zeros_bases( n, n, nbases, order, dhl);
        Tl   = arrso_zeros_bases( n, n, nbases, order, dhl);
        Tu   = arrso_zeros_bases( n, n, nbases, order, dhl);
        prod = arrso_zeros_bases( n, n, nbases, order, dhl);
        acc  = arrso_zeros_bases( n, n, nbases, order, dhl);

        arrso_permute_rows_to( A, ipiv, &PA, dhl);

        for (p = 1; p <= order; p++){

            // R_p = [P^T A]_p - sum_{q=1..p-1} [L]_q [U]_{p-q}
            arrso_get_order_im_to( p, &PA, &acc, dhl);

            for (q = 1; q < p; q++){
                lu_sub_matmul( LUw, q,     OTI_MASK_STRICT_LOWER,
                               LUw, p - q, OTI_MASK_UPPER, &Tl, &Tu, &prod, &acc, dhl);
            }

            // X = L_r^-1 R_p U_r^-1
            nd = dhelp_ndirOrder( nbases, p);
            arrso_get_order_colmajor( &acc, p, nbases, X);

            oti_dtrsm( 'L', 'L', 'N', 'U', ni, (int)(n*nd), 1.0, lr, ni, X, ni);
            for (d = 0; d < nd; d++){
                oti_dtrsm( 'R', 'U', 'N', 'N', ni, ni, 1.0, lr, ni, X + d*blk, ni);
            }

            // Split: X keeps triu(X), Lb receives stril(X).
            for (d = 0; d < nd; d++){
                for (j = 0; j < n; j++){
                    for (i = 0; i < n; i++){
                        if ( i > j ){
                            Lb[ d*blk + i + j*n ] = X[ d*blk + i + j*n ];
                            X[  d*blk + i + j*n ] = 0.0;
                        } else {
                            Lb[ d*blk + i + j*n ] = 0.0;
                        }
                    }
                }
            }

            // [U]_p = triu(X) U_r, [L]_p = L_r stril(X)
            for (d = 0; d < nd; d++){
                oti_dtrmm( 'R', 'U', 'N', 'N', ni, ni, 1.0, lr, ni, X + d*blk, ni);
            }
            oti_dtrmm( 'L', 'L', 'N', 'U', ni, (int)(n*nd), 1.0, lr, ni, Lb, ni);

            arrso_set_order_colmajor( X,  p, nbases, OTI_MASK_UPPER,        LUw, dhl);
            arrso_set_order_colmajor( Lb, p, nbases, OTI_MASK_STRICT_LOWER, LUw, dhl);

        }

    }

    if ( LUw != LU ){
        arrso_copy_to( LUw, LU, dhl);
    }

cleanup:
    free(mem);
    arrso_free(&LUtmp);
    arrso_free(&PA);
    arrso_free(&Tl);
    arrso_free(&Tu);
    arrso_free(&prod);
    arrso_free(&acc);

    return info;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_lu_factor(arrso_t* A, int32_t* ipiv, int* status, dhelpl_t dhl){

    arrso_t res = arrso_zeros_bases( A->nrows, A->ncols, 0, 0, dhl);
    int     info;

    info = arrso_lu_factor_to( A, &res, ipiv, dhl);

    if ( status != NULL ){
        *status = info;
    }

    return res;

}
// ----------------------------------------------------------------------------------------------------



// 3.3. Solve with the LU factors.
// ****************************************************************************************************
int arrso_lu_solve_to(arrso_t* LU, int32_t* ipiv, arrso_t* b, arrso_t* x, dhelpl_t dhl){

    uint64_t n, m, k, rsize, wsize;
    size_t   bytes;
    ord_t    order, p, q;
    bases_t  nbases;
    ndir_t   nmax, nd;
    int      info = 0, ni;
    coeff_t* mem = NULL;
    coeff_t *lr, *work;
    arrso_t  xtmp = arrso_init(), Pb = arrso_init(), Y = arrso_init(), Tq = arrso_init();
    arrso_t  Vq = arrso_init(), prod = arrso_init(), acc = arrso_init();
    arrso_t* xw = x;

    arrso_dimCheck_O_squareness( LU, LU);
    arrso_dimCheck_OO_matmul( LU, b, x);

    n = LU->nrows;
    m = b->ncols;

    if ( n == 0 || m == 0 ){
        return 0;
    }

    for (k = 0; k < n; k++){
        if ( ipiv[k] < 1 || (uint64_t)ipiv[k] > n ){
            info = OTI_LINALG_ERR_PIVOT;
            goto fail;
        }
    }

    order  = MAX( arrso_get_order(LU), arrso_get_order(b) );
    nbases = MAX( arrso_get_nbases(LU, dhl), arrso_get_nbases(b, dhl) );
    nmax   = lu_max_ndir( nbases, order);

    if ( !lu_work_size(n, n, 1, &rsize) || !lu_work_size(n, m, nmax, &wsize) ||
         !lu_buffer_bytes(rsize, wsize, 1, 0, &bytes) ){
        info = OTI_LINALG_ERR_SIZE;
        goto fail;
    }

    mem = (coeff_t*)malloc( bytes );
    if ( mem == NULL ){
        info = OTI_LINALG_ERR_MEMORY;
        goto fail;
    }
    lr   = mem;
    work = lr + rsize;
    ni   = (int)n;

    arrso_get_real_colmajor( LU, lr);

    // A zero pivot in Re(U) would divide by zero in the triangular solves.
    for (k = 0; k < n; k++){
        if ( lr[ k + k*n ] == 0.0 ){
            info = (int)(k + 1);
            goto fail;
        }
    }

    // The result is written order by order while LU and b are still read: do not alias them.
    if ( x == LU || x == b ){
        xtmp = arrso_zeros_bases( n, m, 0, 0, dhl);
        xw   = &xtmp;
    }

    Pb = arrso_zeros_bases( n, m, 0, 0, dhl);
    Y  = arrso_zeros_bases( n, m, 0, 0, dhl);
    arrso_permute_rows_to( b, ipiv, &Pb, dhl);

    // Real part: y_0 = L_r^-1 [P^T b]_0, x_0 = U_r^-1 y_0.
    arrso_get_real_colmajor( &Pb, work);
    oti_dtrsm( 'L', 'L', 'N', 'U', ni, (int)m, 1.0, lr, ni, work, ni);
    lu_set_real_colmajor( work, &Y, dhl);
    oti_dtrsm( 'L', 'U', 'N', 'N', ni, (int)m, 1.0, lr, ni, work, ni);
    lu_set_real_colmajor( work, xw, dhl);

    if ( nbases > 0 && order > 0 ){

        // Work arrays at the truncation order (products of order parts keep their order).
        Tq   = arrso_zeros_bases( n, n, nbases, order, dhl);
        Vq   = arrso_zeros_bases( n, m, nbases, order, dhl);
        prod = arrso_zeros_bases( n, m, nbases, order, dhl);
        acc  = arrso_zeros_bases( n, m, nbases, order, dhl);

        for (p = 1; p <= order; p++){

            nd = dhelp_ndirOrder( nbases, p);

            // y_p = L_r^-1 ( [P^T b]_p - sum_{q=1..p} [L]_q y_{p-q} )
            arrso_get_order_im_to( p, &Pb, &acc, dhl);
            for (q = 1; q <= p; q++){
                lu_sub_matmul( LU, q, OTI_MASK_STRICT_LOWER, &Y, p - q, OTI_MASK_FULL,
                               &Tq, &Vq, &prod, &acc, dhl);
            }
            arrso_get_order_colmajor( &acc, p, nbases, work);
            oti_dtrsm( 'L', 'L', 'N', 'U', ni, (int)(m*nd), 1.0, lr, ni, work, ni);
            arrso_set_order_colmajor( work, p, nbases, OTI_MASK_FULL, &Y, dhl);

            // x_p = U_r^-1 ( y_p - sum_{q=1..p} [U]_q x_{p-q} )
            arrso_get_order_im_to( p, &Y, &acc, dhl);
            for (q = 1; q <= p; q++){
                lu_sub_matmul( LU, q, OTI_MASK_UPPER, xw, p - q, OTI_MASK_FULL,
                               &Tq, &Vq, &prod, &acc, dhl);
            }
            arrso_get_order_colmajor( &acc, p, nbases, work);
            oti_dtrsm( 'L', 'U', 'N', 'N', ni, (int)(m*nd), 1.0, lr, ni, work, ni);
            arrso_set_order_colmajor( work, p, nbases, OTI_MASK_FULL, xw, dhl);

        }

    }

    if ( xw != x ){
        arrso_copy_to( xw, x, dhl);
    }

    goto cleanup;

fail:
    arrso_set_nan( x, dhl);

cleanup:
    free(mem);
    arrso_free(&xtmp);
    arrso_free(&Pb);
    arrso_free(&Y);
    arrso_free(&Tq);
    arrso_free(&Vq);
    arrso_free(&prod);
    arrso_free(&acc);

    return info;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_lu_solve(arrso_t* LU, int32_t* ipiv, arrso_t* b, int* status, dhelpl_t dhl){

    arrso_t res = arrso_zeros_bases( LU->nrows, b->ncols, 0, 0, dhl);
    int     info;

    info = arrso_lu_solve_to( LU, ipiv, b, &res, dhl);

    if ( status != NULL ){
        *status = info;
    }

    return res;

}
// ----------------------------------------------------------------------------------------------------
