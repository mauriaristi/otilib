// C wrappers of the BLAS / LAPACK routines used by otilib (Phase 3; PLAN-ndarray-contracts.md 8.6,
// 8.7). Each wrapper calls the routine through the provider table (lapack_provider.c) with the exact
// prototype of the provider's hidden string-length convention: OTI_STRLEN_END_SIZE_T appends one
// size_t 1 per CHARACTER argument, in argument order (R's FCONE pattern); OTI_STRLEN_NONE
// (Accelerate's $NEWLAPACK interface) has no hidden lengths. Routines without CHARACTER arguments
// have one prototype. Generic pointers are never called through their declared type.
//
// File-static helpers carry the ol_ prefix. No XERBLA is reachable: callers pass only legal
// arguments, which debug builds (OTI_LAPACK_DEBUG) assert here.

#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#if defined(OTI_LAPACK_DEBUG)
#include <assert.h>
#endif

#include "oti/core/lapack.h"

// Hidden length of a CHARACTER*1 argument.
#define OL_L1 ((size_t)1)

// 1 when the provider takes hidden lengths at the end.
#define OL_FC(p) ((p)->strlen_convention == OTI_STRLEN_END_SIZE_T)

#if defined(OTI_LAPACK_DEBUG)
#define OL_REQUIRE(c) assert(c)
#else
#define OL_REQUIRE(c) ((void)0)
#endif

#define OL_MAX1(v) ((v) > 1 ? (v) : 1)
#define OL_FLAG(c, a, b) ((c) == (a) || (c) == (b))

// Prototypes, by routine: _fc with trailing hidden lengths (END_SIZE_T), _c without (NONE).
typedef void (*ol_dgetrf_t)(const int*, const int*, double*, const int*, int*, int*);
typedef void (*ol_dgetrs_fc)(const char*, const int*, const int*, const double*, const int*,
                             const int*, double*, const int*, int*, size_t);
typedef void (*ol_dgetrs_c)(const char*, const int*, const int*, const double*, const int*,
                            const int*, double*, const int*, int*);
typedef void (*ol_dtrxm_fc)(const char*, const char*, const char*, const char*, const int*,
                            const int*, const double*, const double*, const int*, double*, const int*,
                            size_t, size_t, size_t, size_t);
typedef void (*ol_dtrxm_c)(const char*, const char*, const char*, const char*, const int*,
                           const int*, const double*, const double*, const int*, double*, const int*);
typedef void (*ol_dgemm_fc)(const char*, const char*, const int*, const int*, const int*,
                            const double*, const double*, const int*, const double*, const int*,
                            const double*, double*, const int*, size_t, size_t);
typedef void (*ol_dgemm_c)(const char*, const char*, const int*, const int*, const int*,
                           const double*, const double*, const int*, const double*, const int*,
                           const double*, double*, const int*);
typedef double (*ol_ddot_t)(const int*, const double*, const int*, const double*, const int*);
typedef void (*ol_daxpy_t)(const int*, const double*, const double*, const int*, double*, const int*);
typedef void (*ol_dscal_t)(const int*, const double*, double*, const int*);
typedef double (*ol_dnrm2_t)(const int*, const double*, const int*);
typedef void (*ol_dcopy_t)(const int*, const double*, const int*, double*, const int*);
typedef void (*ol_dswap_t)(const int*, double*, const int*, double*, const int*);
typedef int (*ol_idamax_t)(const int*, const double*, const int*);
typedef void (*ol_dgemv_fc)(const char*, const int*, const int*, const double*, const double*,
                            const int*, const double*, const int*, const double*, double*, const int*,
                            size_t);
typedef void (*ol_dgemv_c)(const char*, const int*, const int*, const double*, const double*,
                           const int*, const double*, const int*, const double*, double*, const int*);
typedef void (*ol_dger_t)(const int*, const int*, const double*, const double*, const int*,
                          const double*, const int*, double*, const int*);
typedef void (*ol_dsyrk_fc)(const char*, const char*, const int*, const int*, const double*,
                            const double*, const int*, const double*, double*, const int*, size_t,
                            size_t);
typedef void (*ol_dsyrk_c)(const char*, const char*, const int*, const int*, const double*,
                           const double*, const int*, const double*, double*, const int*);
typedef void (*ol_dgesv_t)(const int*, const int*, double*, const int*, int*, double*, const int*,
                           int*);
typedef void (*ol_dgetri_t)(const int*, double*, const int*, const int*, double*, const int*, int*);
typedef void (*ol_dpotrf_fc)(const char*, const int*, double*, const int*, int*, size_t);
typedef void (*ol_dpotrf_c)(const char*, const int*, double*, const int*, int*);
typedef void (*ol_dpotrs_fc)(const char*, const int*, const int*, const double*, const int*, double*,
                             const int*, int*, size_t);
typedef void (*ol_dpotrs_c)(const char*, const int*, const int*, const double*, const int*, double*,
                            const int*, int*);
typedef void (*ol_dtrtrs_fc)(const char*, const char*, const char*, const int*, const int*,
                             const double*, const int*, double*, const int*, int*, size_t, size_t,
                             size_t);
typedef void (*ol_dtrtrs_c)(const char*, const char*, const char*, const int*, const int*,
                            const double*, const int*, double*, const int*, int*);
typedef void (*ol_dgeqrf_t)(const int*, const int*, double*, const int*, double*, double*,
                            const int*, int*);
typedef void (*ol_dorgqr_t)(const int*, const int*, const int*, double*, const int*, const double*,
                            double*, const int*, int*);
typedef void (*ol_dgelsd_t)(const int*, const int*, const int*, double*, const int*, double*,
                            const int*, double*, const double*, int*, double*, const int*, int*,
                            int*);
typedef void (*ol_dsyevd_fc)(const char*, const char*, const int*, double*, const int*, double*,
                             double*, const int*, int*, const int*, int*, size_t, size_t);
typedef void (*ol_dsyevd_c)(const char*, const char*, const int*, double*, const int*, double*,
                            double*, const int*, int*, const int*, int*);
typedef void (*ol_dgeev_fc)(const char*, const char*, const int*, double*, const int*, double*,
                            double*, double*, const int*, double*, const int*, double*, const int*,
                            int*, size_t, size_t);
typedef void (*ol_dgeev_c)(const char*, const char*, const int*, double*, const int*, double*,
                           double*, double*, const int*, double*, const int*, double*, const int*,
                           int*);
typedef void (*ol_dgesdd_fc)(const char*, const int*, const int*, double*, const int*, double*,
                             double*, const int*, double*, const int*, double*, const int*, int*, int*,
                             size_t);
typedef void (*ol_dgesdd_c)(const char*, const int*, const int*, double*, const int*, double*,
                            double*, const int*, double*, const int*, double*, const int*, int*, int*);

// Test limit of oti_lapack_int_limit(); 0 means INT_MAX.
static int64_t ol_int_limit = 0;


// *******************************************************************************************************
int oti_lapack_lwork(double query, int64_t min_lwork, int* lwork){

    double v;

    if (lwork == NULL){
        return OTI_ERR_ARGUMENT;
    }
    if (!isfinite(query) || query < 0.0){
        return OTI_ERR_SIZE;
    }

    v = ceil(query);

    if (v < (double)min_lwork){
        v = (double)min_lwork;
    }
    if (v < 1.0){
        v = 1.0;
    }
    if (v > (double)INT_MAX){
        return OTI_ERR_SIZE;
    }

    *lwork = (int)v;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int64_t oti_lapack_int_limit(void){

    int64_t v = __atomic_load_n(&ol_int_limit, __ATOMIC_RELAXED);

    return v > 0 ? v : (int64_t)INT_MAX;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_lapack_test_set_int_limit(int64_t limit){

    if (limit <= 0 || limit > (int64_t)INT_MAX){
        limit = 0;
    }

    __atomic_store_n(&ol_int_limit, limit, __ATOMIC_RELAXED);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dgetrf(int m, int n, double* a, int lda, int* ipiv, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(m >= 0 && n >= 0 && lda >= OL_MAX1(m));
    ((ol_dgetrf_t)p->dgetrf)(&m, &n, a, &lda, ipiv, info);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dgetrs(char trans, int n, int nrhs, const double* a, int lda, const int* ipiv,
                double* b, int ldb, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(OL_FLAG(trans, 'N', 'T') && n >= 0 && nrhs >= 0);
    OL_REQUIRE(lda >= OL_MAX1(n) && ldb >= OL_MAX1(n));

    if (OL_FC(p)){
        ((ol_dgetrs_fc)p->dgetrs)(&trans, &n, &nrhs, a, &lda, ipiv, b, &ldb, info, OL_L1);
    } else {
        ((ol_dgetrs_c)p->dgetrs)(&trans, &n, &nrhs, a, &lda, ipiv, b, &ldb, info);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Shared body of dtrsm and dtrmm (same argument list).
static inline void ol_dtrxm(oti_lapack_fn fn, int fc, char side, char uplo, char transa, char diag,
                            int m, int n, double alpha, const double* a, int lda, double* b,
                            int ldb){

    OL_REQUIRE(OL_FLAG(side, 'L', 'R') && OL_FLAG(uplo, 'L', 'U'));
    OL_REQUIRE(OL_FLAG(transa, 'N', 'T') && OL_FLAG(diag, 'N', 'U'));
    OL_REQUIRE(m >= 0 && n >= 0 && ldb >= OL_MAX1(m));
    OL_REQUIRE(lda >= OL_MAX1(side == 'L' ? m : n));

    if (fc){
        ((ol_dtrxm_fc)fn)(&side, &uplo, &transa, &diag, &m, &n, &alpha, a, &lda, b, &ldb, OL_L1,
                          OL_L1, OL_L1, OL_L1);
    } else {
        ((ol_dtrxm_c)fn)(&side, &uplo, &transa, &diag, &m, &n, &alpha, a, &lda, b, &ldb);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dtrsm(char side, char uplo, char transa, char diag, int m, int n, double alpha,
               const double* a, int lda, double* b, int ldb){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    ol_dtrxm(p->dtrsm, OL_FC(p), side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dtrmm(char side, char uplo, char transa, char diag, int m, int n, double alpha,
               const double* a, int lda, double* b, int ldb){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    ol_dtrxm(p->dtrmm, OL_FC(p), side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dgemm(char transa, char transb, int m, int n, int k, double alpha, const double* a,
               int lda, const double* b, int ldb, double beta, double* c, int ldc){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(OL_FLAG(transa, 'N', 'T') && OL_FLAG(transb, 'N', 'T'));
    OL_REQUIRE(m >= 0 && n >= 0 && k >= 0 && ldc >= OL_MAX1(m));
    OL_REQUIRE(lda >= OL_MAX1(transa == 'N' ? m : k) && ldb >= OL_MAX1(transb == 'N' ? k : n));

    if (OL_FC(p)){
        ((ol_dgemm_fc)p->dgemm)(&transa, &transb, &m, &n, &k, &alpha, a, &lda, b, &ldb, &beta, c,
                                &ldc, OL_L1, OL_L1);
    } else {
        ((ol_dgemm_c)p->dgemm)(&transa, &transb, &m, &n, &k, &alpha, a, &lda, b, &ldb, &beta, c,
                               &ldc);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
double oti_ddot(int n, const double* x, int incx, const double* y, int incy){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(n <= 0 || (incx != 0 && incy != 0));

    return ((ol_ddot_t)p->ddot)(&n, x, &incx, y, &incy);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_daxpy(int n, double alpha, const double* x, int incx, double* y, int incy){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(n <= 0 || (incx != 0 && incy != 0));
    ((ol_daxpy_t)p->daxpy)(&n, &alpha, x, &incx, y, &incy);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dscal(int n, double alpha, double* x, int incx){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(n <= 0 || incx > 0);
    ((ol_dscal_t)p->dscal)(&n, &alpha, x, &incx);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
double oti_dnrm2(int n, const double* x, int incx){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(n <= 0 || incx > 0);

    return ((ol_dnrm2_t)p->dnrm2)(&n, x, &incx);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dcopy(int n, const double* x, int incx, double* y, int incy){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(n <= 0 || (incx != 0 && incy != 0));
    ((ol_dcopy_t)p->dcopy)(&n, x, &incx, y, &incy);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dswap(int n, double* x, int incx, double* y, int incy){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(n <= 0 || (incx != 0 && incy != 0));
    ((ol_dswap_t)p->dswap)(&n, x, &incx, y, &incy);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
double oti_dasum(int n, const double* x, int incx){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(n <= 0 || incx > 0);

    return ((ol_dnrm2_t)p->dasum)(&n, x, &incx);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_idamax(int n, const double* x, int incx){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    if (n < 1 || incx <= 0){
        return 0;
    }

    return ((ol_idamax_t)p->idamax)(&n, x, &incx);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dgemv(char trans, int m, int n, double alpha, const double* a, int lda, const double* x,
               int incx, double beta, double* y, int incy){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(OL_FLAG(trans, 'N', 'T') && m >= 0 && n >= 0 && lda >= OL_MAX1(m));
    OL_REQUIRE(incx > 0 && incy > 0);

    if (OL_FC(p)){
        ((ol_dgemv_fc)p->dgemv)(&trans, &m, &n, &alpha, a, &lda, x, &incx, &beta, y, &incy, OL_L1);
    } else {
        ((ol_dgemv_c)p->dgemv)(&trans, &m, &n, &alpha, a, &lda, x, &incx, &beta, y, &incy);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dger(int m, int n, double alpha, const double* x, int incx, const double* y, int incy,
              double* a, int lda){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(m >= 0 && n >= 0 && lda >= OL_MAX1(m) && incx > 0 && incy > 0);
    ((ol_dger_t)p->dger)(&m, &n, &alpha, x, &incx, y, &incy, a, &lda);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dsyrk(char uplo, char trans, int n, int k, double alpha, const double* a, int lda,
               double beta, double* c, int ldc){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(OL_FLAG(uplo, 'U', 'L') && OL_FLAG(trans, 'N', 'T') && n >= 0 && k >= 0);
    OL_REQUIRE(lda >= OL_MAX1(trans == 'N' ? n : k) && ldc >= OL_MAX1(n));

    if (OL_FC(p)){
        ((ol_dsyrk_fc)p->dsyrk)(&uplo, &trans, &n, &k, &alpha, a, &lda, &beta, c, &ldc, OL_L1,
                                OL_L1);
    } else {
        ((ol_dsyrk_c)p->dsyrk)(&uplo, &trans, &n, &k, &alpha, a, &lda, &beta, c, &ldc);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dgesv(int n, int nrhs, double* a, int lda, int* ipiv, double* b, int ldb, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(n >= 0 && nrhs >= 0 && lda >= OL_MAX1(n) && ldb >= OL_MAX1(n));
    ((ol_dgesv_t)p->dgesv)(&n, &nrhs, a, &lda, ipiv, b, &ldb, info);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dgetri(int n, double* a, int lda, const int* ipiv, double* work, int lwork, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(n >= 0 && lda >= OL_MAX1(n) && (lwork == -1 || lwork >= OL_MAX1(n)));
    ((ol_dgetri_t)p->dgetri)(&n, a, &lda, ipiv, work, &lwork, info);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dpotrf(char uplo, int n, double* a, int lda, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(OL_FLAG(uplo, 'U', 'L') && n >= 0 && lda >= OL_MAX1(n));

    if (OL_FC(p)){
        ((ol_dpotrf_fc)p->dpotrf)(&uplo, &n, a, &lda, info, OL_L1);
    } else {
        ((ol_dpotrf_c)p->dpotrf)(&uplo, &n, a, &lda, info);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dpotrs(char uplo, int n, int nrhs, const double* a, int lda, double* b, int ldb, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(OL_FLAG(uplo, 'U', 'L') && n >= 0 && nrhs >= 0);
    OL_REQUIRE(lda >= OL_MAX1(n) && ldb >= OL_MAX1(n));

    if (OL_FC(p)){
        ((ol_dpotrs_fc)p->dpotrs)(&uplo, &n, &nrhs, a, &lda, b, &ldb, info, OL_L1);
    } else {
        ((ol_dpotrs_c)p->dpotrs)(&uplo, &n, &nrhs, a, &lda, b, &ldb, info);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dtrtrs(char uplo, char trans, char diag, int n, int nrhs, const double* a, int lda,
                double* b, int ldb, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    OL_REQUIRE(OL_FLAG(uplo, 'U', 'L') && OL_FLAG(trans, 'N', 'T') && OL_FLAG(diag, 'N', 'U'));
    OL_REQUIRE(n >= 0 && nrhs >= 0 && lda >= OL_MAX1(n) && ldb >= OL_MAX1(n));

    if (OL_FC(p)){
        ((ol_dtrtrs_fc)p->dtrtrs)(&uplo, &trans, &diag, &n, &nrhs, a, &lda, b, &ldb, info, OL_L1,
                                  OL_L1, OL_L1);
    } else {
        ((ol_dtrtrs_c)p->dtrtrs)(&uplo, &trans, &diag, &n, &nrhs, a, &lda, b, &ldb, info);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dgeqrf(int m, int n, double* a, int lda, double* tau, double* work, int lwork, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    if (p->dgeqrf == NULL){
        *info = INT_MIN;
        return;
    }

    OL_REQUIRE(m >= 0 && n >= 0 && lda >= OL_MAX1(m));
    ((ol_dgeqrf_t)p->dgeqrf)(&m, &n, a, &lda, tau, work, &lwork, info);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dorgqr(int m, int n, int k, double* a, int lda, const double* tau, double* work, int lwork,
                int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    if (p->dorgqr == NULL){
        *info = INT_MIN;
        return;
    }

    OL_REQUIRE(m >= n && n >= k && k >= 0 && lda >= OL_MAX1(m));
    ((ol_dorgqr_t)p->dorgqr)(&m, &n, &k, a, &lda, tau, work, &lwork, info);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dgelsd(int m, int n, int nrhs, double* a, int lda, double* b, int ldb, double* s,
                double rcond, int* rank, double* work, int lwork, int* iwork, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    if (p->dgelsd == NULL){
        *info = INT_MIN;
        return;
    }

    OL_REQUIRE(m >= 0 && n >= 0 && nrhs >= 0 && lda >= OL_MAX1(m));
    OL_REQUIRE(ldb >= OL_MAX1(m > n ? m : n));
    ((ol_dgelsd_t)p->dgelsd)(&m, &n, &nrhs, a, &lda, b, &ldb, s, &rcond, rank, work, &lwork, iwork,
                             info);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dsyevd(char jobz, char uplo, int n, double* a, int lda, double* w, double* work, int lwork,
                int* iwork, int liwork, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    if (p->dsyevd == NULL){
        *info = INT_MIN;
        return;
    }

    OL_REQUIRE(OL_FLAG(jobz, 'N', 'V') && OL_FLAG(uplo, 'U', 'L') && n >= 0 && lda >= OL_MAX1(n));

    if (OL_FC(p)){
        ((ol_dsyevd_fc)p->dsyevd)(&jobz, &uplo, &n, a, &lda, w, work, &lwork, iwork, &liwork, info,
                                  OL_L1, OL_L1);
    } else {
        ((ol_dsyevd_c)p->dsyevd)(&jobz, &uplo, &n, a, &lda, w, work, &lwork, iwork, &liwork, info);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dgeev(char jobvl, char jobvr, int n, double* a, int lda, double* wr, double* wi,
               double* vl, int ldvl, double* vr, int ldvr, double* work, int lwork, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    if (p->dgeev == NULL){
        *info = INT_MIN;
        return;
    }

    OL_REQUIRE(OL_FLAG(jobvl, 'N', 'V') && OL_FLAG(jobvr, 'N', 'V') && n >= 0);
    OL_REQUIRE(lda >= OL_MAX1(n) && ldvl >= 1 && ldvr >= 1);

    if (OL_FC(p)){
        ((ol_dgeev_fc)p->dgeev)(&jobvl, &jobvr, &n, a, &lda, wr, wi, vl, &ldvl, vr, &ldvr, work,
                                &lwork, info, OL_L1, OL_L1);
    } else {
        ((ol_dgeev_c)p->dgeev)(&jobvl, &jobvr, &n, a, &lda, wr, wi, vl, &ldvl, vr, &ldvr, work,
                               &lwork, info);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_dgesdd(char jobz, int m, int n, double* a, int lda, double* s, double* u, int ldu,
                double* vt, int ldvt, double* work, int lwork, int* iwork, int* info){

    const oti_lapack_provider_t* p = oti_lapack_provider();

    if (p->dgesdd == NULL){
        *info = INT_MIN;
        return;
    }

    OL_REQUIRE((OL_FLAG(jobz, 'A', 'S') || OL_FLAG(jobz, 'O', 'N')) && m >= 0 && n >= 0);
    OL_REQUIRE(lda >= OL_MAX1(m) && ldu >= 1 && ldvt >= 1);

    if (OL_FC(p)){
        ((ol_dgesdd_fc)p->dgesdd)(&jobz, &m, &n, a, &lda, s, u, &ldu, vt, &ldvt, work, &lwork, iwork,
                                  info, OL_L1);
    } else {
        ((ol_dgesdd_c)p->dgesdd)(&jobz, &m, &n, a, &lda, s, u, &ldu, vt, &ldvt, work, &lwork, iwork,
                                 info);
    }

}
// -------------------------------------------------------------------------------------------------------
