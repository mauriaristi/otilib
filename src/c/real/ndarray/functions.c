// ndarray elementwise math functions: nd_unary_to() / nd_unary() over the ND_FN_* codes
// (include/oti/real/ndarray/elementwise.h, Phase 1; PLAN-ndarray-contracts.md 5.4). Unity-included
// from src/c/real_ndarray.c after elementwise.c, whose driver (nde_apply_to, nde_apply_new), unary
// kernels (neg, abs, square, sqrt, reciprocal) and NDE_UNARY_KERNEL macro it reuses; static helpers
// carry the ndf_ prefix.
//
// Determinism (5.4): each element is one libm call (or one IEEE operation) on its own value, with no
// vector math library and no FMA contraction (-ffp-contract=off on the unity), so results do not
// depend on the traversal, the chunking or the thread count. No `omp simd` around libm calls.
// ND_FN_NOT (a mask operator) is Phase 2: OTI_ERR_ARGUMENT until then.

#include <math.h>

#include "oti/real/ndarray.h"


// *******************************************************************************************************
// numpy.sign: -1.0 below zero, +1.0 above, NaN for NaN, and +0.0 for both zeros ([cH3]).
static inline double ndf_sign(double x){

    if (x > 0.0){
        return 1.0;
    }

    if (x < 0.0){
        return -1.0;
    }

    return (x == 0.0) ? 0.0 : x;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// libm kernels (one call per element) and numpy.sign.
NDE_UNARY_KERNEL(ndf_k_cbrt, cbrt(x_))
NDE_UNARY_KERNEL(ndf_k_exp, exp(x_))
NDE_UNARY_KERNEL(ndf_k_exp2, exp2(x_))
NDE_UNARY_KERNEL(ndf_k_expm1, expm1(x_))
NDE_UNARY_KERNEL(ndf_k_log, log(x_))
NDE_UNARY_KERNEL(ndf_k_log2, log2(x_))
NDE_UNARY_KERNEL(ndf_k_log10, log10(x_))
NDE_UNARY_KERNEL(ndf_k_log1p, log1p(x_))
NDE_UNARY_KERNEL(ndf_k_sin, sin(x_))
NDE_UNARY_KERNEL(ndf_k_cos, cos(x_))
NDE_UNARY_KERNEL(ndf_k_tan, tan(x_))
NDE_UNARY_KERNEL(ndf_k_asin, asin(x_))
NDE_UNARY_KERNEL(ndf_k_acos, acos(x_))
NDE_UNARY_KERNEL(ndf_k_atan, atan(x_))
NDE_UNARY_KERNEL(ndf_k_sinh, sinh(x_))
NDE_UNARY_KERNEL(ndf_k_cosh, cosh(x_))
NDE_UNARY_KERNEL(ndf_k_tanh, tanh(x_))
NDE_UNARY_KERNEL(ndf_k_asinh, asinh(x_))
NDE_UNARY_KERNEL(ndf_k_acosh, acosh(x_))
NDE_UNARY_KERNEL(ndf_k_atanh, atanh(x_))
NDE_UNARY_KERNEL(ndf_k_floor, floor(x_))
NDE_UNARY_KERNEL(ndf_k_ceil, ceil(x_))
NDE_UNARY_KERNEL(ndf_k_trunc, trunc(x_))
NDE_UNARY_KERNEL(ndf_k_rint, rint(x_))
NDE_UNARY_KERNEL(ndf_k_sign, ndf_sign(x_))
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Kernel of an ND_FN_* code, or NULL (unknown, or the Phase 2 ND_FN_NOT).
static nd_inner_fn ndf_kernel(int32_t fn){

    switch (fn){
    case ND_FN_NEG:
        return nde_u_neg;
    case ND_FN_ABS:
        return nde_u_abs;
    case ND_FN_SQRT:
        return nde_u_sqrt;
    case ND_FN_CBRT:
        return ndf_k_cbrt;
    case ND_FN_EXP:
        return ndf_k_exp;
    case ND_FN_EXP2:
        return ndf_k_exp2;
    case ND_FN_EXPM1:
        return ndf_k_expm1;
    case ND_FN_LOG:
        return ndf_k_log;
    case ND_FN_LOG2:
        return ndf_k_log2;
    case ND_FN_LOG10:
        return ndf_k_log10;
    case ND_FN_LOG1P:
        return ndf_k_log1p;
    case ND_FN_SIN:
        return ndf_k_sin;
    case ND_FN_COS:
        return ndf_k_cos;
    case ND_FN_TAN:
        return ndf_k_tan;
    case ND_FN_ASIN:
        return ndf_k_asin;
    case ND_FN_ACOS:
        return ndf_k_acos;
    case ND_FN_ATAN:
        return ndf_k_atan;
    case ND_FN_SINH:
        return ndf_k_sinh;
    case ND_FN_COSH:
        return ndf_k_cosh;
    case ND_FN_TANH:
        return ndf_k_tanh;
    case ND_FN_ASINH:
        return ndf_k_asinh;
    case ND_FN_ACOSH:
        return ndf_k_acosh;
    case ND_FN_ATANH:
        return ndf_k_atanh;
    case ND_FN_FLOOR:
        return ndf_k_floor;
    case ND_FN_CEIL:
        return ndf_k_ceil;
    case ND_FN_TRUNC:
        return ndf_k_trunc;
    case ND_FN_RINT:
        return ndf_k_rint;
    case ND_FN_SQUARE:
        return nde_u_square;
    case ND_FN_RECIPROCAL:
        return nde_u_reciprocal;
    case ND_FN_SIGN:
        return ndf_k_sign;
    default:
        return NULL;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Argument checks of the unary entry points: operands present, function known, OTI_F64 (out is NULL
// for the allocating variant).
static int ndf_unary_check(nd_inner_fn kernel, const ndarr_t* a, const ndarr_t* out){

    if (a == NULL || kernel == NULL){
        return OTI_ERR_ARGUMENT;
    }

    nde_debug_input(a);
    nde_debug_input(out);

    return (a->dtype != OTI_F64 || (out != NULL && out->dtype != OTI_F64)) ? OTI_ERR_DTYPE : OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_unary_to(oti_ctx* ctx, int32_t fn, const ndarr_t* a, ndarr_t* out){

    nd_inner_fn kernel = ndf_kernel(fn);
    int status = oti_ctx_check(ctx);

    if (status == OTI_OK){
        status = (out == NULL) ? OTI_ERR_ARGUMENT : ndf_unary_check(kernel, a, out);
    }

    if (status == OTI_OK){
        status = nde_apply_to(ctx, kernel, 1, a, NULL, out);
    }

    if (status != OTI_OK){
        oti_ctx_set_error(ctx, status, "nd_unary_to", NULL);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_unary(oti_ctx* ctx, int32_t fn, const ndarr_t* a, ndarr_t* res){

    nd_inner_fn kernel = ndf_kernel(fn);
    const ndarr_t* ins[1];
    int status;

    if (res == NULL){
        status = OTI_ERR_ARGUMENT;
    } else {

        nde_debug_res(res);
        status = oti_ctx_check(ctx);

        if (status == OTI_OK){
            status = ndf_unary_check(kernel, a, NULL);
        }

        if (status == OTI_OK){
            ins[0] = a;
            status = nde_apply_new(ctx, kernel, 1, ins, 0, res);
        } else {
            nd_init_empty(res);
        }

    }

    if (status != OTI_OK){
        oti_ctx_set_error(ctx, status, "nd_unary", NULL);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------
