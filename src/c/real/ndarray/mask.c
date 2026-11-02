// ndarray comparisons and mask operators (include/oti/real/ndarray/elementwise.h, Phase 2):
// ND_OP_EQ .. ND_OP_GE (OTI_F64 x OTI_F64 -> OTI_U8), ND_OP_AND / OR / XOR (OTI_U8 x OTI_U8 ->
// OTI_U8) and ND_FN_NOT (OTI_U8 -> OTI_U8). Unity-included from src/c/real_ndarray.c after
// functions.c; elementwise.c dispatches through ndm_binary_info() and functions.c through ndm_k_not
// (both forward-declared there). Static helpers carry the ndm_ prefix.
//
// Semantics (NumPy): comparisons are IEEE: every comparison with a NaN is false except !=, which is
// true; -0.0 == +0.0. A mask value is true when its byte is nonzero; results are always 0 or 1 (as
// NumPy bool). The scalar variants pass a logical operation's scalar as its truth value (NaN is
// true, as bool(nan)); see nde_scalar_operand().

#include "oti/real/ndarray.h"


// *******************************************************************************************************
// Comparison kernels: OTI_F64 operands, OTI_U8 result. Variables inside EXPR: a_ and b_. Bodies for
// all-contiguous runs, a broadcast (stride 0) operand and a strided fallback.
#define NDM_CMP_KERNEL(NAME, EXPR)                                                                   \
static int NAME(void* arg, int64_t n, char* const* p, const int64_t* bs){                           \
    const nde_karg_t* k = (const nde_karg_t*)arg;                                                    \
    uint8_t* po = (uint8_t*)p[k->io];                                                                \
    const char* pa = p[k->i0];                                                                       \
    const char* pb = p[k->i1];                                                                       \
    int64_t so = bs[k->io], sa = bs[k->i0], sb = bs[k->i1], i;                                       \
    if (so == 1 && sa == 8 && sb == 8){                                                              \
        const double* x = (const double*)pa;                                                         \
        const double* y = (const double*)pb;                                                         \
        for (i = 0; i < n; i++){ double a_ = x[i], b_ = y[i]; po[i] = (uint8_t)(EXPR); }             \
    } else if (so == 1 && sa == 8 && sb == 0){                                                       \
        const double* x = (const double*)pa;                                                         \
        const double b_ = *(const double*)pb;                                                        \
        for (i = 0; i < n; i++){ double a_ = x[i]; po[i] = (uint8_t)(EXPR); }                        \
    } else if (so == 1 && sa == 0 && sb == 8){                                                       \
        const double a_ = *(const double*)pa;                                                        \
        const double* y = (const double*)pb;                                                         \
        for (i = 0; i < n; i++){ double b_ = y[i]; po[i] = (uint8_t)(EXPR); }                        \
    } else {                                                                                         \
        for (i = 0; i < n; i++){                                                                     \
            double a_ = *(const double*)(pa + i * sa), b_ = *(const double*)(pb + i * sb);           \
            po[i * so] = (uint8_t)(EXPR);                                                            \
        }                                                                                            \
    }                                                                                                \
    return OTI_OK;                                                                                   \
}

// Logical kernels: OTI_U8 operands read as truth values (a_, b_ are 0 or 1), OTI_U8 result.
#define NDM_LOGIC_KERNEL(NAME, EXPR)                                                                 \
static int NAME(void* arg, int64_t n, char* const* p, const int64_t* bs){                           \
    const nde_karg_t* k = (const nde_karg_t*)arg;                                                    \
    uint8_t* po = (uint8_t*)p[k->io];                                                                \
    const uint8_t* pa = (const uint8_t*)p[k->i0];                                                    \
    const uint8_t* pb = (const uint8_t*)p[k->i1];                                                    \
    int64_t so = bs[k->io], sa = bs[k->i0], sb = bs[k->i1], i;                                       \
    if (so == 1 && sa == 1 && sb == 1){                                                              \
        for (i = 0; i < n; i++){                                                                     \
            unsigned a_ = (pa[i] != 0), b_ = (pb[i] != 0); po[i] = (uint8_t)(EXPR);                  \
        }                                                                                            \
    } else if (so == 1 && sa == 1 && sb == 0){                                                       \
        const unsigned b_ = (*pb != 0);                                                              \
        for (i = 0; i < n; i++){ unsigned a_ = (pa[i] != 0); po[i] = (uint8_t)(EXPR); }              \
    } else if (so == 1 && sa == 0 && sb == 1){                                                       \
        const unsigned a_ = (*pa != 0);                                                              \
        for (i = 0; i < n; i++){ unsigned b_ = (pb[i] != 0); po[i] = (uint8_t)(EXPR); }              \
    } else {                                                                                         \
        for (i = 0; i < n; i++){                                                                     \
            unsigned a_ = (pa[i * sa] != 0), b_ = (pb[i * sb] != 0);                                 \
            po[i * so] = (uint8_t)(EXPR);                                                            \
        }                                                                                            \
    }                                                                                                \
    return OTI_OK;                                                                                   \
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Comparison and logical kernels.
NDM_CMP_KERNEL(ndm_k_eq, a_ == b_)
NDM_CMP_KERNEL(ndm_k_ne, a_ != b_)
NDM_CMP_KERNEL(ndm_k_lt, a_ < b_)
NDM_CMP_KERNEL(ndm_k_le, a_ <= b_)
NDM_CMP_KERNEL(ndm_k_gt, a_ > b_)
NDM_CMP_KERNEL(ndm_k_ge, a_ >= b_)
NDM_LOGIC_KERNEL(ndm_k_and, a_ & b_)
NDM_LOGIC_KERNEL(ndm_k_or, a_ | b_)
NDM_LOGIC_KERNEL(ndm_k_xor, a_ ^ b_)
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// numpy.logical_not of an OTI_U8 mask: 1 where the byte is zero, else 0.
static int ndm_k_not(void* arg, int64_t n, char* const* p, const int64_t* bs){

    const nde_karg_t* k = (const nde_karg_t*)arg;
    uint8_t* po = (uint8_t*)p[k->io];
    const uint8_t* pa = (const uint8_t*)p[k->i0];
    int64_t so = bs[k->io], sa = bs[k->i0], i;

    if (so == 1 && sa == 1){

        for (i = 0; i < n; i++){
            po[i] = (uint8_t)(pa[i] == 0);
        }

        return OTI_OK;

    }

    for (i = 0; i < n; i++){
        po[i * so] = (uint8_t)(pa[i * sa] == 0);
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Kernel, dtypes and cost of a comparison or logical operation (nde_binary_info()); 0 for an
// unknown operation.
static int ndm_binary_info(int32_t op, nde_opinfo_t* info){

    info->in_dtype  = OTI_F64;
    info->out_dtype = OTI_U8;
    info->ns        = NDE_NS_ARITH;

    switch (op){
    case ND_OP_EQ:
        info->fn = ndm_k_eq;
        return 1;
    case ND_OP_NE:
        info->fn = ndm_k_ne;
        return 1;
    case ND_OP_LT:
        info->fn = ndm_k_lt;
        return 1;
    case ND_OP_LE:
        info->fn = ndm_k_le;
        return 1;
    case ND_OP_GT:
        info->fn = ndm_k_gt;
        return 1;
    case ND_OP_GE:
        info->fn = ndm_k_ge;
        return 1;
    default:
        break;
    }

    info->in_dtype = OTI_U8;

    switch (op){
    case ND_OP_AND:
        info->fn = ndm_k_and;
        return 1;
    case ND_OP_OR:
        info->fn = ndm_k_or;
        return 1;
    case ND_OP_XOR:
        info->fn = ndm_k_xor;
        return 1;
    default:
        info->fn = NULL;
        return 0;
    }

}
// -------------------------------------------------------------------------------------------------------
