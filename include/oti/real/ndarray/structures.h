#ifndef OTI_REAL_NDARRAY_STRUCTURES_H
#define OTI_REAL_NDARRAY_STRUCTURES_H

// -------------------------------------------------------------------------------------------------------
// n-dimensional double array of the real module: types and constants (PLAN-ndarray.md "Core type and
// ownership"; PLAN-ndarray-contracts.md sections 1, 2 and 6).
//
// Conventions for the whole ndarray API (nd_*):
//   - Descriptors. An ndarr_t is either a TEMPORARY (ND_RETAINED clear: it holds no reference and is
//     valid only while the array it was derived from, or the trusted memory it wraps, stays alive) or
//     a RETAINED descriptor (ND_RETAINED set: it holds one reference on its nd_buffer_t and must be
//     released exactly once with nd_release()). Copying a retained descriptor by struct assignment
//     is a contract violation: use nd_clone() or nd_move().
//   - Well-formed inputs. Public functions assume their descriptor arguments are well formed: built
//     by an nd_* function, or checked by nd_validate() / nd_import() / nd_wrap_trusted(). They check
//     the semantic conditions (dtype, shapes, writeability, overlap). Debug builds (OTI_ND_DEBUG)
//     run nd_validate() on every input.
//   - Outputs. A parameter named `out` of a `_to` operation is an existing array written in place
//     (shape, dtype and writeability are checked; its references are not changed; it may be
//     retained). A parameter named `res` receives a NEW retained array, and the `out` of a view
//     function (nd_view_*, nd_wrap_trusted, nd_from_view) receives a temporary: both are overwritten
//     without being released, so they must be empty (nd_init_empty()) or a temporary on entry; debug
//     builds (OTI_ND_DEBUG) assert it. On any failure `res` is left empty and `out` holds unspecified
//     values; both stay safe to release.
//   - Statuses: OTI_OK or a negative OTI_ERR_* (include/oti/core/status.h); LAPACK-backed linear
//     algebra may also return a positive info. Never exit(), never print.
//   - Contexts: every function that allocates, parallelizes or calls BLAS takes an `oti_ctx *ctx`
//     first; NULL means the default context (include/oti/core/exec.h). Allocations are checked
//     against the context's byte budgets before they are made.
//   - Strides are in ELEMENTS (DLPack convention) and may be negative or zero. `data` points at the
//     element of index (0, ..., 0). An array with zero elements may have data == NULL.
//   - Sizes, shapes, strides and indices are int64_t; codes, flags, axes and counts of axes int32_t.
//   - Unity build: src/c/real/ndarray/*.c are included from their own translation unit
//     src/c/real_ndarray.c (compiled with -ffp-contract=off); file-static helpers carry a per-file
//     prefix (buffer ndb_, validate ndv_, create ndc_, views ndw_, iter ndi_, elementwise
//     nde_, functions ndf_, reduce ndr_, mask ndm_, index ndx_, blas ndbl_, linalg ndl_,
//     compat_darr ndd_).
// -------------------------------------------------------------------------------------------------------

#include <stddef.h>
#include <stdint.h>

#include "oti/core/status.h"

#ifdef OTI_ND_DEBUG
#include <assert.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      CONSTANTS         -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/** @brief Maximum number of dimensions of an ndarr_t (decision 4). Rejected above it on every path. */
#define OTI_ND_MAXDIM 32

/**
 * @name Element types (ndarr_t.dtype)
 * Only OTI_F64 arrays take part in arithmetic. 0 is never a valid dtype.
 * @{
 */
#define OTI_F64  1 ///< double (IEEE binary64, native byte order).
#define OTI_U8   2 ///< uint8 boolean mask, 0 = false, nonzero = true (comparisons, mask indexing).
#define OTI_I64  3 ///< int64 index (advanced indexing, argmin / argmax results).
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Descriptor flags (ndarr_t.flags)
 * ND_C_CONTIG and ND_F_CONTIG follow NumPy 2 (axes of extent 1 are ignored; an array with at most one
 * element is both). They are recomputed by nd_update_flags(). Bits 5..31 are reserved and zero.
 * @{
 */
#define ND_C_CONTIG   0x01 ///< Row-major contiguous.
#define ND_F_CONTIG   0x02 ///< Column-major contiguous.
#define ND_WRITEABLE  0x04 ///< Writes allowed (never set over a read-only buffer).
#define ND_RETAINED   0x08 ///< The descriptor holds one reference on `buf` (release with nd_release()).
#define ND_EXPORTED   0x10 ///< The reference is also an export (nd_export()); implies ND_RETAINED.
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Memory layouts (creators, copies, reshape)
 * The memory-layout keyword is `layout=` in Python (decision 9); `order=` stays the truncation order.
 * @{
 */
#define ND_LAYOUT_C  0 ///< Row-major.
#define ND_LAYOUT_F  1 ///< Column-major.
#define ND_LAYOUT_A  2 ///< F if the source is F-contiguous and not C-contiguous, else C.
#define ND_LAYOUT_K  3 ///< Keep the source's axis memory order as closely as possible (copies only).
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name ABI view kinds (oti_view.kind)
 * @{
 */
#define OTI_KIND_REAL            0 ///< A plain real array: dl describes the array itself.
#define OTI_KIND_DENSE_SOA       1 ///< Dense SoA: dl is (nblocks, *S); bases NULL (1..nbases).
#define OTI_KIND_SEMISPARSE_SOA  2 ///< Semi-sparse OTI SoA: dl is (nblocks, *S); bases holds the labels.
#define OTI_KIND_DIAGONAL_SOA    3 ///< Reserved: the diagonal-OTI pilot (multilang Phase 2).
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name DLPack constants used by the ABI view
 * Values of DLPack's DLDeviceType, DLDataTypeCode and DLManagedTensorVersioned flags.
 * @{
 */
// OTI_DEVICE_CPU (kDLCPU, 1) is defined in oti/core/status.h.
#define OTI_DL_INT            0 ///< kDLInt.
#define OTI_DL_UINT           1 ///< kDLUInt.
#define OTI_DL_FLOAT          2 ///< kDLFloat.
#define OTI_DL_BFLOAT         4 ///< kDLBfloat (always rejected).
#define OTI_DL_COMPLEX        5 ///< kDLComplex (always rejected).
#define OTI_DL_BOOL           6 ///< kDLBool.
#define OTI_VIEW_READONLY     1 ///< oti_view.flags bit 0, same as DLPACK_FLAG_BITMASK_READ_ONLY.
/** @} */
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Opaque control block of an array's memory (PLAN-ndarray-contracts.md section 1.2).
 *
 * Holds the allocation span, the optional exactly-once release callback and one atomic 64-bit state
 * word (references, exports, OWNS, GROWABLE, WRITEABLE, GROWING). Its definition is private to
 * src/c/real/ndarray/buffer.c; use the functions of include/oti/real/ndarray/buffer.h.
 */
typedef struct nd_buffer_s nd_buffer_t;

/**
 * @brief n-dimensional strided array descriptor (544 bytes; passed by pointer).
 *
 * Element (i_0, ..., i_{ndim-1}) is at `(T*)data + sum_k i_k * strides[k]` with T the dtype's C type.
 * Entries of shape/strides at index >= ndim are unspecified and never read. A rank-0 array has one
 * element. Kernels copy only the first ndim entries.
 */
typedef struct {
    void*         data;                    ///< Element (0, ..., 0); typed by dtype. NULL only if size 0.
    int64_t       shape[OTI_ND_MAXDIM];    ///< Extents, >= 0.
    int64_t       strides[OTI_ND_MAXDIM];  ///< Strides in ELEMENTS; may be < 0 or 0.
    int32_t       ndim;                    ///< 0 .. OTI_ND_MAXDIM.
    int32_t       dtype;                   ///< OTI_F64, OTI_U8 or OTI_I64.
    int32_t       flags;                   ///< ND_C_CONTIG | ND_F_CONTIG | ND_WRITEABLE | ...
    int32_t       reserved;                ///< Zero.
    nd_buffer_t*  buf;                     ///< Control block; NULL only for a trusted borrowed span.
} ndarr_t;

/**
 * @brief DLPack DLDevice, bit-compatible.
 */
typedef struct {
    int32_t device_type; ///< DLDeviceType; OTI_DEVICE_CPU is the only accepted value.
    int32_t device_id;   ///< Device ordinal; 0 for the CPU.
} oti_dldevice_t;

/**
 * @brief DLPack DLDataType, bit-compatible.
 *
 * Its unsigned fields are kept so that the struct is bit-identical to DLPack; Fortran reads them as
 * integer(c_int8_t) / integer(c_int16_t) bit patterns (every value used is below 128). The ABI rule
 * "no unsigned types" applies to function signatures, which never take this type by value.
 */
typedef struct {
    uint8_t  code;  ///< DLDataTypeCode (OTI_DL_*).
    uint8_t  bits;  ///< Bits per lane: 64 for f64 and i64, 8 for bool.
    uint16_t lanes; ///< Always 1.
} oti_dldtype_t;

/**
 * @brief DLPack DLTensor, bit-compatible: the real-layout part of oti_view.
 *
 * strides are in elements; strides == NULL means compact row-major. byte_offset is added to data.
 */
typedef struct {
    void*           data;        ///< Base pointer (the element of index 0 is at data + byte_offset).
    oti_dldevice_t  device;      ///< Device.
    int32_t         ndim;        ///< Number of dimensions (no MAXDIM limit at the ABI).
    oti_dldtype_t   dtype;       ///< Element type.
    int64_t*        shape;       ///< ndim extents.
    int64_t*        strides;     ///< ndim strides in elements, or NULL (compact row-major).
    uint64_t        byte_offset; ///< Offset in bytes from data to the element of index 0.
} oti_dltensor_t;

/**
 * @brief Public ABI view: a DLTensor plus the OTI fields (PLAN-ndarray-contracts.md section 6).
 *
 * POD, versioned by struct_size (first field). For OTI_KIND_REAL the OTI fields are zero. For the
 * SoA OTI kinds dl describes the (nblocks, *S) block array (axis 0 = direction block, block 0 = real
 * part) and the OTI fields describe the blocks. A view never owns memory.
 */
typedef struct {
    int32_t         struct_size; ///< sizeof(oti_view) as compiled by the caller. Set before every call.
    int32_t         kind;        ///< OTI_KIND_*.
    oti_dltensor_t  dl;          ///< Real layout.
    int32_t         flags;       ///< OTI_VIEW_READONLY; other bits zero.
    int32_t         trc_order;   ///< OTI kinds: truncation order. 0 for OTI_KIND_REAL.
    int32_t         act_order;   ///< OTI kinds: highest order that may hold nonzeros (<= trc_order).
    int32_t         reserved0;   ///< Zero.
    int64_t         nbases;      ///< OTI kinds: nact (dense) or number of labels in bases (semi-sparse).
    const int64_t*  bases;       ///< NULL for dense (labels 1..nbases); sorted labels for semi-sparse.
    int64_t         reserved[6]; ///< Zero.
} oti_view;

#if defined(__cplusplus)
#define OTI_ND_STATIC_ASSERT(c, m) static_assert(c, m)
#else
#define OTI_ND_STATIC_ASSERT(c, m) _Static_assert(c, m)
#endif

OTI_ND_STATIC_ASSERT(sizeof(oti_dldtype_t) == 4, "oti_dldtype_t must match DLDataType");
OTI_ND_STATIC_ASSERT(offsetof(oti_dltensor_t, device) == sizeof(void*), "DLTensor.device offset");
OTI_ND_STATIC_ASSERT(offsetof(oti_dltensor_t, ndim) == sizeof(void*) + 8, "DLTensor.ndim offset");
OTI_ND_STATIC_ASSERT(offsetof(oti_dltensor_t, dtype) == sizeof(void*) + 12, "DLTensor.dtype offset");
OTI_ND_STATIC_ASSERT(offsetof(oti_dltensor_t, shape) == sizeof(void*) + 16, "DLTensor.shape offset");

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Size in bytes of one element of a dtype.
 *
 * @param[in] dtype OTI_F64, OTI_U8 or OTI_I64.
 *
 * @return 8, 1 or 8; 0 for an unknown dtype.
 */
static inline int64_t nd_itemsize(int32_t dtype){
    return dtype == OTI_F64 ? 8 : dtype == OTI_I64 ? 8 : dtype == OTI_U8 ? 1 : 0;
}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Number of elements of a well-formed descriptor (product of the extents; 1 for rank 0).
 *
 * @param[in] a Well-formed descriptor: the product of its non-zero extents fits int64_t (checked when
 *              it was built or validated; review W1 finding 2). Any zero extent gives 0.
 *
 * @return The number of elements.
 */
static inline int64_t nd_size(const ndarr_t* a){
    int64_t n = 1;
    int32_t k;
    for (k = 0; k < a->ndim; k++){
        if (a->shape[k] == 0){
            return 0;   // an empty array: the other extents may not multiply within int64
        }
    }
    for (k = 0; k < a->ndim; k++){
        n *= a->shape[k];
    }
    return n;
}
// -------------------------------------------------------------------------------------------------------


/**
 * @name Typed data accessors
 * Return `data` as the dtype's C type. Debug builds (OTI_ND_DEBUG) assert the dtype.
 * @{
 */

/**
 * @brief Data of an OTI_F64 array.
 *
 * @param[in] a Descriptor with dtype OTI_F64.
 *
 * @return `a->data` as double*. Not owned by the caller.
 */
static inline double* nd_f64(const ndarr_t* a){
#ifdef OTI_ND_DEBUG
    assert(a->dtype == OTI_F64);
#endif
    return (double*)a->data;
}

/**
 * @brief Data of an OTI_U8 mask.
 *
 * @param[in] a Descriptor with dtype OTI_U8.
 *
 * @return `a->data` as uint8_t*. Not owned by the caller.
 */
static inline uint8_t* nd_u8(const ndarr_t* a){
#ifdef OTI_ND_DEBUG
    assert(a->dtype == OTI_U8);
#endif
    return (uint8_t*)a->data;
}

/**
 * @brief Data of an OTI_I64 index array.
 *
 * @param[in] a Descriptor with dtype OTI_I64.
 *
 * @return `a->data` as int64_t*. Not owned by the caller.
 */
static inline int64_t* nd_i64(const ndarr_t* a){
#ifdef OTI_ND_DEBUG
    assert(a->dtype == OTI_I64);
#endif
    return (int64_t*)a->data;
}

/** @} */
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
