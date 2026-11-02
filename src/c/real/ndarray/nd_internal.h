#ifndef OTI_REAL_NDARRAY_ND_INTERNAL_H
#define OTI_REAL_NDARRAY_ND_INTERNAL_H

// Internal helpers shared by the ndarray sources (included once, from src/c/real_ndarray.c).
//
// Checked int64 arithmetic (PLAN-ndarray-contracts.md 2.3): every product or sum of extents,
// strides, offsets, element counts and byte counts goes through these. Each returns non-zero on
// overflow and stores the (wrapped) result in *r. GCC >= 5 and clang; an MSVC fallback is a later
// portability item.

#include <stdint.h>

#define oti_ckd_mul_i64(a, b, r) __builtin_mul_overflow((int64_t)(a), (int64_t)(b), (r))
#define oti_ckd_add_i64(a, b, r) __builtin_add_overflow((int64_t)(a), (int64_t)(b), (r))

#endif // OTI_REAL_NDARRAY_ND_INTERNAL_H
