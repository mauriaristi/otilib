#ifndef OTI_REAL_NDARRAY_BUFFER_H
#define OTI_REAL_NDARRAY_BUFFER_H

// -------------------------------------------------------------------------------------------------------
// ndarray memory: lifecycle, the control block's state word, validation, overlap, import (PEP 3118 /
// DLPack format table) and the oti_view mapping (PLAN-ndarray-contracts.md sections 1, 2, 3 and 6).
// Implemented in src/c/real/ndarray/buffer.c (lifecycle) and validate.c (the rest), Phase 1.
//
// Control block (private to buffer.c):
//     struct nd_buffer_s {
//         uint64_t      state;        // atomic state word, see ND_STATE_* (__atomic_* builtins)
//         void*         base;         // start of the allocation span (NULL for a zero-byte span)
//         int64_t       nbytes;       // span length in bytes; -1 when unknown (foreign, unchecked)
//         nd_release_fn release;      // called exactly once when refs reach 0; may be NULL
//         void*         release_ctx;  // argument of release
//         void*         inl;          // inline data of the block (small arrays), or NULL
//         void*         extra;        // the caller's zone (nd_alloc_extra()), or NULL
//         int64_t       extra_bytes;  // size of the zone
//         void*         arena;        // the scratch arena of a ND_ALLOC_SCRATCH block, or NULL
//     };
//   Destruction (refs 1 -> 0, exactly one thread): free(base) if OWNS and base is not the block's
//   inline data; then release(release_ctx) if set; then the control block (to its arena for a
//   scratch array). Library allocations are 64-byte aligned (posix_memalign) and at
//   least one element long, so library arrays never have data == NULL.
//
// State word transitions (each one CAS loop on the whole word; acquire on success unless noted):
//   retain    : fail OTI_ERR_BUSY if GROWING; fail OTI_ERR_SIZE if refs == max; refs += 1.
//   export    : as retain, and exports += 1 (fail OTI_ERR_SIZE at max).
//   release   : refs -= 1 (release order; an acquire fence before destruction when it reaches 0).
//   unexport  : refs -= 1 and exports -= 1 in one CAS (release order), destruction as release.
//   lock      : (refs == 1, exports == 0, GROWING clear) -> set GROWING, else OTI_ERR_BUSY.
//               Not reentrant. Growth also needs OWNS | GROWABLE (else OTI_ERR_BUSY: a borrowed or
//               caller-allocated buffer is never regrown).
//   unlock    : clear GROWING (release order).
// Concurrent reads are safe. Concurrent mutation of one array from several host threads is not
// supported; the CAS only makes the export/growth race fail cleanly instead of using freed memory.
// -------------------------------------------------------------------------------------------------------

#include "oti/core/exec.h"
#include "oti/real/ndarray/structures.h"

#ifdef __cplusplus
extern "C" {
#endif

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      CONSTANTS         -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name State word layout (nd_buffer_state())
 * bits 0..31 refs, bits 32..55 exports (each export also holds one ref), bits 56..60 flags,
 * bits 61..63 reserved (zero).
 * @{
 */
#define ND_STATE_REFS_MASK      0x00000000FFFFFFFFull ///< Retained descriptors (exports included).
#define ND_STATE_EXPORTS_SHIFT  32                    ///< Shift of the export count.
#define ND_STATE_EXPORTS_MASK   0x00FFFFFF00000000ull ///< Live exports (NumPy bases, DLPack capsules).
#define ND_STATE_OWNS           (1ull << 56)          ///< The library allocated base and frees it.
#define ND_STATE_GROWABLE       (1ull << 57)          ///< May be reallocated (only with OWNS).
#define ND_STATE_WRITEABLE      (1ull << 58)          ///< The memory may be written.
#define ND_STATE_GROWING        (1ull << 59)          ///< Growth or relayout in progress (exclusive).
#define ND_STATE_SCRATCH        (1ull << 60)          ///< Call-local (ND_ALLOC_SCRATCH): never exported.
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Allocation flags (nd_alloc())
 * @{
 */
#define ND_ALLOC_ZERO       0x1 ///< Zero-fill.
#define ND_ALLOC_GROWABLE   0x2 ///< Accepted, no effect: every library buffer is GROWABLE (S25).
#define ND_ALLOC_SCRATCH    0x4 ///< Call-local array: control block, extra zone and data from the
                                ///< calling thread's scratch arena (see nd_alloc_extra()).
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Extra zone (nd_alloc_extra())
 * @{
 */
#define ND_EXTRA_ALIGN      16       ///< Alignment of the extra zone.
#define ND_EXTRA_MAX_BYTES  65536    ///< Largest extra zone.
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Validation flags (nd_validate())
 * @{
 */
#define ND_V_SPAN      0x1 ///< The allocation span is known: check the accessed span against it.
#define ND_V_OUTPUT    0x2 ///< Used as an output: needs ND_WRITEABLE and no internal overlap.
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Overlap results (nd_may_share_memory())
 * @{
 */
#define ND_SHARE_NONE    0 ///< The accessed byte spans are disjoint.
#define ND_SHARE_MAYBE   1 ///< The spans intersect and the layouts differ: go through a temporary.
#define ND_SHARE_EXACT   2 ///< Same data, dtype, ndim, shape and strides (axes of extent > 1).
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Foreign element kinds (nd_srctype_t.kind)
 * @{
 */
#define ND_SRC_BOOL      1 ///< 1-byte boolean.
#define ND_SRC_INT       2 ///< Signed integer of itemsize 1, 2, 4 or 8.
#define ND_SRC_UINT      3 ///< Unsigned integer of itemsize 1, 2, 4 or 8.
#define ND_SRC_FLOAT     4 ///< IEEE float of itemsize 4 or 8.
#define ND_SRC_COMPLEX   5 ///< Complex (always rejected).
#define ND_SRC_OTHER     6 ///< Anything else (always rejected).
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Import flags (nd_import())
 * @{
 */
#define ND_IMPORT_WRITEABLE 0x1 ///< The result is written (out=): zero-copy only, never a converted copy.
#define ND_IMPORT_COPY      0x2 ///< Always copy into a new library array.
/** @} */
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Release callback of a buffer: invoked exactly once, when its references reach zero.
 *
 * Runs on the thread that drops the last reference (never on a library worker thread). It must not
 * touch the buffer it releases; it may release other buffers. Python callbacks take the GIL
 * (PyGILState_Ensure) and leak instead when Py_IsFinalizing() is true.
 *
 * @param[in,out] release_ctx The pointer given to nd_wrap() / nd_import().
 */
typedef void (*nd_release_fn)(void* release_ctx);

/**
 * @brief Element type of a foreign buffer, from the format table.
 */
typedef struct {
    int32_t kind;     ///< ND_SRC_*.
    int32_t itemsize; ///< Bytes per element.
    int32_t swapped;  ///< 1 if the byte order is not the host's.
    int32_t reserved; ///< Zero.
} nd_srctype_t;

/**
 * @brief A foreign strided buffer to import (filled from a Py_buffer or a DLTensor).
 */
typedef struct {
    void*           data;         ///< Element (0, ..., 0). May be NULL only when an extent is 0.
    int32_t         ndim;         ///< Number of dimensions (> OTI_ND_MAXDIM is rejected).
    int32_t         readonly;     ///< 1 if the exporter forbids writes.
    const int64_t*  shape;        ///< ndim extents.
    const int64_t*  byte_strides; ///< ndim strides in BYTES, or NULL for C-contiguous.
    nd_srctype_t    src;          ///< From nd_pep3118_classify() or nd_dlpack_classify().
    int32_t         device_type;  ///< OTI_DEVICE_CPU, else rejected.
    int32_t         reserved;     ///< Zero.
} nd_import_t;

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------


/**
 * @name Lifecycle
 * Who frees what: PLAN-ndarray-contracts.md table 1.4. On every failure the output is left empty
 * (nd_init_empty()) and no reference or allocation remains.
 * @{
 */

/**
 * @brief Makes a descriptor the empty temporary: shape (0,), F64, C and F contiguous, writeable,
 *        data NULL, buf NULL.
 *
 * Never fails; releasing it is a no-op. Does not release what @p a held before.
 *
 * @param[out] a Descriptor to reset.
 */
void nd_init_empty(ndarr_t* a);

/**
 * @brief Allocates a new array in C or F layout.
 *
 * The buffer is OWNS | GROWABLE (every library buffer, S25), WRITEABLE, 64-byte aligned, at least one
 * element long. The byte count is computed with checked arithmetic and checked against the context's
 * max_alloc_bytes before allocating.
 *
 * @param[in,out] ctx         Context, or NULL.
 * @param[in]     dtype       OTI_F64, OTI_U8 or OTI_I64.
 * @param[in]     ndim        0 .. OTI_ND_MAXDIM.
 * @param[in]     shape       ndim extents, >= 0 (ignored when ndim is 0).
 * @param[in]     layout      ND_LAYOUT_C or ND_LAYOUT_F.
 * @param[in]     alloc_flags ND_ALLOC_ZERO | ND_ALLOC_GROWABLE | ND_ALLOC_SCRATCH.
 * @param[out]    res         New retained array (refs 1). Overwritten without being released.
 *
 * @return OTI_OK; OTI_ERR_SHAPE (ndim or a negative extent), OTI_ERR_DTYPE, OTI_ERR_ARGUMENT
 *         (layout, flags, NULL), OTI_ERR_SIZE (overflow), OTI_ERR_MEMORY (budget or malloc).
 *         Caller owns the reference on success and must release it via nd_release().
 */
int nd_alloc(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape, int32_t layout,
             int32_t alloc_flags, ndarr_t* res);

/**
 * @brief Allocates a new array with the given element strides (contracts S24).
 *
 * As nd_alloc(), but the layout is @p strides: they must be compact and injective (no internal
 * overlap, nd_internal_overlap() == 0, and the span is exactly size elements), as for the dense SoA
 * block layout (nblocks, nrows, ncols) with strides (nrows*ncols, 1, nrows). Strides of axes of
 * extent <= 1 are kept as given.
 *
 * @param[in,out] ctx         Context, or NULL.
 * @param[in]     dtype       OTI_F64, OTI_U8 or OTI_I64.
 * @param[in]     ndim        0 .. OTI_ND_MAXDIM.
 * @param[in]     shape       ndim extents, >= 0.
 * @param[in]     strides     ndim element strides, >= 0 for axes of extent > 1.
 * @param[in]     alloc_flags ND_ALLOC_ZERO | ND_ALLOC_GROWABLE | ND_ALLOC_SCRATCH.
 * @param[out]    res         New retained array (refs 1). Overwritten without being released.
 *
 * @return As nd_alloc(); OTI_ERR_LAYOUT when the strides are not compact and injective.
 *         Caller owns the reference on success and must release it via nd_release().
 */
int nd_alloc_strided(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape,
                     const int64_t* strides, int32_t alloc_flags, ndarr_t* res);

/**
 * @brief Allocates a new array whose control block also carries @p extra_bytes of caller storage.
 *
 * As nd_alloc() (strides NULL: @p layout C or F) or nd_alloc_strided() (strides given: compact and
 * injective; @p layout ignored). The extra zone is zero-filled, ND_EXTRA_ALIGN-aligned, part of the
 * control block's allocation, and lives exactly as long as the buffer (freed after the release of
 * the last reference); growth moves the data, never the control block or the zone. Small arrays
 * (data <= 4096 bytes) take one allocation for control block, zone and data (data still 64-byte
 * aligned); every nd_alloc() / nd_alloc_strided() array does too (extra_bytes 0).
 *
 * ND_ALLOC_SCRATCH: a call-local array. Control block, zone and data come from the calling thread's
 * scratch arena (a LIFO bump region, reused between calls; heap fallback when it is full or the
 * block is large). The arena starts at 16 KiB and, when it is next empty, grows to the peak demand it
 * could not serve (at most 1 MiB per thread); blocks above 256 KiB always come from the heap. Same
 * contracts as a heap array (refs, retain, views, layout lock, growth: the grown data goes to the
 * heap) except: nd_export() fails with OTI_ERR_BUSY (state ND_STATE_SCRATCH), and the last reference
 * must be released on the allocating thread, before that thread's nd_scratch_release() (debug builds
 * assert the thread). Budgets: max_alloc_bytes and max_temp_bytes both apply to the data bytes.
 * nd_test_fail_alloc(): one allocation event per array (two for heap data above 4096 bytes).
 *
 * @param[in,out] ctx         Context, or NULL.
 * @param[in]     dtype       OTI_F64, OTI_U8 or OTI_I64.
 * @param[in]     ndim        0 .. OTI_ND_MAXDIM.
 * @param[in]     shape       ndim extents, >= 0.
 * @param[in]     strides     ndim element strides (compact, injective), or NULL for @p layout.
 * @param[in]     layout      ND_LAYOUT_C or ND_LAYOUT_F (strides NULL).
 * @param[in]     alloc_flags ND_ALLOC_ZERO | ND_ALLOC_GROWABLE | ND_ALLOC_SCRATCH.
 * @param[in]     extra_bytes 0 .. ND_EXTRA_MAX_BYTES.
 * @param[out]    extra       Start of the zone (NULL when extra_bytes is 0); may be NULL. NULL on
 *                            failure.
 * @param[out]    res         New retained array (refs 1). Overwritten without being released.
 *
 * @return As nd_alloc() / nd_alloc_strided(); OTI_ERR_ARGUMENT for extra_bytes out of range.
 *         Caller owns the reference on success and must release it via nd_release().
 */
int nd_alloc_extra(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape,
                   const int64_t* strides, int32_t layout, int32_t alloc_flags, int64_t extra_bytes,
                   void** extra, ndarr_t* res);

/**
 * @brief Wraps foreign memory in a validated, retained array, taking over a release callback.
 *
 * Ownership of (@p release, @p release_ctx) passes to the library ON ENTRY: on success the callback
 * runs exactly once when the references reach zero; on ANY failure it runs exactly once before this
 * function returns. The caller never calls it after this call. The buffer is neither OWNS nor
 * GROWABLE; it is WRITEABLE iff desc->flags has ND_WRITEABLE.
 *
 * @param[in,out] ctx         Context, or NULL.
 * @param[in]     desc        data, ndim, shape, strides (elements), dtype and ND_WRITEABLE of the view;
 *                            desc->buf is ignored.
 * @param[in]     span_lo     Start of the allocation the view may access, or NULL if unknown.
 * @param[in]     span_nbytes Length of that allocation in bytes, or -1 if unknown (no span check).
 * @param[in]     release     Callback, or NULL (the memory outlives every reference by contract).
 * @param[in,out] release_ctx Callback argument.
 * @param[out]    res         New retained array (refs 1). Overwritten without being released.
 *
 * @return OTI_OK; the nd_validate() statuses; OTI_ERR_MEMORY (control block). Caller owns the reference
 *         on success and must release it via nd_release().
 */
int nd_wrap(oti_ctx* ctx, const ndarr_t* desc, const void* span_lo, int64_t span_nbytes,
            nd_release_fn release, void* release_ctx, ndarr_t* res);

/**
 * @brief Builds a temporary over trusted in-library memory (buf NULL, no span check, no allocation).
 *
 * Structural checks still run (ndim, extents, checked arithmetic, alignment). For in-library
 * temporaries only: the caller guarantees the memory outlives every use of @p out.
 *
 * @param[in]  data      Element (0, ..., 0); NULL only if an extent is 0.
 * @param[in]  dtype     OTI_F64, OTI_U8 or OTI_I64.
 * @param[in]  ndim      0 .. OTI_ND_MAXDIM.
 * @param[in]  shape     ndim extents.
 * @param[in]  strides   ndim strides in elements, or NULL for C-contiguous.
 * @param[in]  writeable 1 to set ND_WRITEABLE.
 * @param[out] out       Temporary descriptor (ND_RETAINED clear). Must be empty or a temporary on
 *                       entry (it is overwritten without being released).
 *
 * @return OTI_OK, OTI_ERR_SHAPE, OTI_ERR_DTYPE, OTI_ERR_SIZE or OTI_ERR_LAYOUT (misaligned data).
 */
int nd_wrap_trusted(void* data, int32_t dtype, int32_t ndim, const int64_t* shape,
                    const int64_t* strides, int32_t writeable, ndarr_t* out);

/**
 * @brief Turns any descriptor with a control block (temporary or retained) into a new retained one.
 *
 * Same data, shape, strides, dtype and ND_WRITEABLE; adds one reference.
 *
 * @param[in]  src Descriptor with src->buf != NULL.
 * @param[out] res Retained descriptor. Overwritten without being released.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT if src->buf is NULL (a trusted span cannot be pinned); OTI_ERR_BUSY
 *         while the buffer is GROWING; OTI_ERR_SIZE at the reference limit. Caller must release @p res
 *         via nd_release().
 */
int nd_view_retain(const ndarr_t* src, ndarr_t* res);

/**
 * @brief Copies a descriptor, keeping its kind: a retained source gives a retained copy (one more
 *        reference), a temporary gives a temporary (plain copy).
 *
 * An exported source gives a retained, non-exported copy.
 *
 * @param[in]  src Descriptor.
 * @param[out] res Copy. Overwritten without being released.
 *
 * @return OTI_OK, OTI_ERR_BUSY or OTI_ERR_SIZE (as nd_view_retain()). If @p res is retained, the caller
 *         must release it via nd_release().
 */
int nd_clone(const ndarr_t* src, ndarr_t* res);

/**
 * @brief Moves a descriptor: @p dst receives @p src and @p src becomes empty. No atomic operation.
 *
 * @param[in,out] src Descriptor to move from; empty afterwards.
 * @param[out]    dst Destination. Overwritten without being released.
 */
void nd_move(ndarr_t* src, ndarr_t* dst);

/**
 * @brief Exports a descriptor: a retained reference that also counts as an export (layout pinned).
 *
 * Used by nd_to_numpy() (the NumPy base object) and DLPack exports. ND_WRITEABLE of the result is
 * @p writeable; asking for a writeable export of a read-only source fails.
 *
 * @param[in]  src       Descriptor with src->buf != NULL.
 * @param[in]  writeable 1 for a writeable export, 0 for read-only.
 * @param[out] res       Retained, exported descriptor (ND_RETAINED | ND_EXPORTED).
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (no buf); OTI_ERR_READONLY; OTI_ERR_BUSY (GROWING); OTI_ERR_SIZE.
 *         Caller must release @p res via nd_release(), which also ends the export.
 */
int nd_export(const ndarr_t* src, int32_t writeable, ndarr_t* res);

/**
 * @brief Releases a descriptor and resets it to empty.
 *
 * Retained: drops one reference (and one export if ND_EXPORTED); the thread that drops the last one
 * destroys the buffer (free if OWNS, then the callback, then the control block). Temporary: only
 * resets. Never fails. Debug builds (OTI_ND_DEBUG) assert that refs > 0 before the decrement.
 *
 * @param[in,out] a Descriptor; empty afterwards. NULL is allowed (no-op).
 */
void nd_release(ndarr_t* a);

/**
 * @name Growth
 * On success every temporary derived from @p root is INVALID: its data points into the freed
 * allocation. Rebuild views after the call. Debug builds poison the old allocation before freeing it.
 * @{
 */

/**
 * @brief Reallocates the buffer of an unshared, growable root array (takes the layout lock).
 *
 * Takes the layout lock (refs == 1, exports == 0, OWNS | GROWABLE), then does nd_grow_locked() and
 * unlocks on every path. Shape and strides are not changed: the caller relayouts afterwards. Must not
 * be called while the caller holds the lock (it is not reentrant): use nd_grow_locked() then.
 *
 * @param[in,out] ctx        Context, or NULL.
 * @param[in,out] root       Retained descriptor, the only reference to its buffer.
 * @param[in]     nbytes     New allocation size in bytes, >= 0.
 * @param[in]     keep_bytes Bytes copied from the old allocation, <= min(old, new).
 *
 * @return OTI_OK; OTI_ERR_BUSY (shared, exported, growing or locked, borrowed or not GROWABLE);
 *         OTI_ERR_MEMORY (budget or malloc; the buffer is unchanged); OTI_ERR_ARGUMENT.
 */
int nd_grow(oti_ctx* ctx, ndarr_t* root, int64_t nbytes, int64_t keep_bytes);

/**
 * @brief Reallocates the buffer of a root array whose layout lock the caller already holds.
 *
 * For one relayout transaction under one lock (oti_meta_layout_begin(), nd_grow_locked(), block
 * moves, oti_meta_layout_end()). Checks OWNS | GROWABLE and the budget, allocates @p nbytes, copies
 * the first @p keep_bytes, frees the old allocation and moves data to the same offset from the new
 * base. The lock stays held on every path.
 *
 * @param[in,out] ctx        Context, or NULL.
 * @param[in,out] root       Retained descriptor whose buffer's layout lock the caller holds.
 * @param[in]     nbytes     New allocation size in bytes, >= 0.
 * @param[in]     keep_bytes Bytes copied from the old allocation, <= min(old, new).
 *
 * @return OTI_OK; OTI_ERR_BUSY (borrowed or not GROWABLE); OTI_ERR_MEMORY (budget or malloc; the
 *         buffer is unchanged); OTI_ERR_ARGUMENT (lock not held, in debug builds).
 */
int nd_grow_locked(oti_ctx* ctx, ndarr_t* root, int64_t nbytes, int64_t keep_bytes);

/**
 * @brief Sets the shape and strides of a root after growth, checked (critic W1 finding 12).
 *
 * Validates the new descriptor against the buffer's span (nd_validate() with ND_V_SPAN over
 * [base, base + nbytes)) and recomputes the flags. @p root is unchanged on failure.
 *
 * @param[in,out] root    Retained root (ND_RETAINED, buf != NULL, OWNS).
 * @param[in]     ndim    0 .. OTI_ND_MAXDIM.
 * @param[in]     shape   ndim extents, >= 0.
 * @param[in]     strides ndim element strides.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (NULL, not a retained owning root); the statuses of
 *         nd_validate() (OTI_ERR_SHAPE, OTI_ERR_SIZE, OTI_ERR_LAYOUT for a span violation).
 */
int nd_set_layout(ndarr_t* root, int32_t ndim, const int64_t* shape, const int64_t* strides);

/** @} */

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Control-block queries and the layout lock
 * The queries are for tests and assertions (a racing thread may change the value right after).
 * @{
 */

/**
 * @brief Raw state word (acquire load).
 *
 * @param[in] buf Control block, not NULL.
 *
 * @return The 64-bit state; decode with ND_STATE_*.
 */
uint64_t nd_buffer_state(const nd_buffer_t* buf);

/**
 * @brief Number of retained references (exports included).
 *
 * @param[in] buf Control block, not NULL.
 *
 * @return refs.
 */
int64_t nd_buffer_refs(const nd_buffer_t* buf);

/**
 * @brief Number of live exports.
 *
 * @param[in] buf Control block, not NULL.
 *
 * @return exports.
 */
int64_t nd_buffer_exports(const nd_buffer_t* buf);

/**
 * @brief Start of the allocation span.
 *
 * @param[in] buf Control block, not NULL.
 *
 * @return base (not owned by the caller).
 */
const void* nd_buffer_base(const nd_buffer_t* buf);

/**
 * @brief Length of the allocation span.
 *
 * @param[in] buf Control block, not NULL.
 *
 * @return nbytes, or -1 if unknown.
 */
int64_t nd_buffer_nbytes(const nd_buffer_t* buf);

/** @brief Extra zone of a buffer (nd_alloc_extra()), or NULL if it has none. buf not NULL. */
void* nd_buffer_extra(const nd_buffer_t* buf);

/** @brief Size of the extra zone in bytes (0 if none). buf not NULL. */
int64_t nd_buffer_extra_bytes(const nd_buffer_t* buf);

/**
 * @brief Frees the calling thread's scratch arena (also done at thread exit).
 *
 * @return OTI_OK; OTI_ERR_BUSY while a scratch array of this thread holds arena memory (a scratch
 *         array that overflowed to the heap does not count); nothing is freed then.
 */
int nd_scratch_release(void);

/**
 * @brief Takes the exclusive layout lock (refs == 1, exports == 0, GROWING clear -> GROWING).
 *
 * Used by oti_meta_layout_begin() before an OTI relayout that keeps the allocation (compact,
 * add_bases within capacity) and by nd_grow().
 *
 * @param[in,out] buf Control block, not NULL.
 *
 * @return OTI_OK, or OTI_ERR_BUSY when other references or exports exist or another lock is held.
 */
int nd_buffer_lock_layout(nd_buffer_t* buf);

/**
 * @brief Releases the layout lock (clears GROWING, release order).
 *
 * @param[in,out] buf Control block whose lock the caller holds.
 */
void nd_buffer_unlock_layout(nd_buffer_t* buf);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Validation and flags
 * Checked arithmetic: every product and sum of extents, strides, offsets and byte counts uses
 * overflow-checked int64 operations (__builtin_mul_overflow / __builtin_add_overflow behind the
 * oti_ckd_* macros); a byte count becomes size_t only after it passed the budget.
 * @{
 */

/**
 * @brief Validates a descriptor.
 *
 * Checks in this order (PLAN-ndarray-contracts.md 2.1, normative) and returns the first failure:
 *   1. 0 <= ndim <= OTI_ND_MAXDIM and shape[k] >= 0 (OTI_ERR_SHAPE);
 *   2. dtype known (OTI_ERR_DTYPE);
 *   3. flags bits 5..31 and reserved zero, ND_EXPORTED only with ND_RETAINED (OTI_ERR_ARGUMENT);
 *   4. the element count and the lowest / highest accessed element offsets fit int64, also in bytes
 *      (OTI_ERR_SIZE);
 *   5. non-empty arrays only: data != NULL (OTI_ERR_ARGUMENT), aligned to the itemsize
 *      (OTI_ERR_LAYOUT), and with ND_V_SPAN the accessed byte span lies inside [span_lo, span_hi)
 *      without pointer wrap-around (OTI_ERR_LAYOUT);
 *   6. with ND_V_OUTPUT: ND_WRITEABLE, also for an empty array (OTI_ERR_READONLY); then, non-empty
 *      arrays only, no internal overlap (OTI_ERR_LAYOUT).
 *
 * @param[in] a       Descriptor.
 * @param[in] span_lo Allocation start (used with ND_V_SPAN).
 * @param[in] span_hi Allocation end, one past the last byte (used with ND_V_SPAN).
 * @param[in] vflags  ND_V_SPAN | ND_V_OUTPUT.
 *
 * @return OTI_OK or the first failing status above.
 */
int nd_validate(const ndarr_t* a, const void* span_lo, const void* span_hi, int32_t vflags);

/**
 * @brief Recomputes ND_C_CONTIG and ND_F_CONTIG (NumPy 2 rules); keeps the other flags.
 *
 * @param[in,out] a Well-formed descriptor.
 */
void nd_update_flags(ndarr_t* a);

/**
 * @brief Element offsets, relative to data, of the lowest and highest accessed elements.
 *
 * @param[in]  a  Well-formed descriptor with at least one element.
 * @param[out] lo Sum of (shape[k]-1)*strides[k] over negative strides (<= 0).
 * @param[out] hi Sum of (shape[k]-1)*strides[k] over positive strides (>= 0).
 *
 * @return OTI_OK, or OTI_ERR_SHAPE for an empty array (no element is accessed).
 */
int nd_extent(const ndarr_t* a, int64_t* lo, int64_t* hi);

/**
 * @brief Conservative internal-overlap test (two indices that may map to one address).
 *
 * Bounded O(ndim log ndim): axes of extent > 1 are sorted by |stride|; the layout is accepted as
 * injective when every |stride_k| > sum over the smaller axes of (shape_j - 1) * |stride_j|. A zero
 * stride on an axis of extent > 1 always overlaps. Every slice, transpose or diagonal of a
 * contiguous array is accepted.
 *
 * @param[in] a Well-formed descriptor.
 *
 * @return 0 if proven free of internal overlap, 1 otherwise.
 */
int nd_internal_overlap(const ndarr_t* a);

/**
 * @brief Conservative test of memory shared by two descriptors (byte-span intersection).
 *
 * @param[in] a Well-formed descriptor.
 * @param[in] b Well-formed descriptor.
 *
 * @return ND_SHARE_NONE, ND_SHARE_EXACT or ND_SHARE_MAYBE. Empty arrays share nothing.
 */
int nd_may_share_memory(const ndarr_t* a, const ndarr_t* b);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Import: the format table (PLAN-ndarray-contracts.md section 2.2)
 * @{
 */

/**
 * @brief Classifies a PEP 3118 format string.
 *
 * Accepts an optional byte-order prefix ('@', '=', '<', '>', '!') followed by exactly one type
 * character; NULL means "B". The kind comes from the character ('?' bool; 'b' 'h' 'i' 'l' 'q' 'n'
 * signed; 'B' 'H' 'I' 'L' 'Q' 'N' unsigned; 'f' 'd' float; 'Zf' 'Zd' complex; others OTHER), the size
 * from @p itemsize, which must be valid for the kind (bool 1; integers 1, 2, 4, 8; float 4, 8).
 * swapped is set for '>' / '!' on a little-endian host (and '<' on a big-endian one).
 *
 * @param[in]  format   Py_buffer.format (requested with PyBUF_FORMAT), or NULL.
 * @param[in]  itemsize Py_buffer.itemsize.
 * @param[out] st       Element type.
 *
 * @return OTI_OK, or OTI_ERR_DTYPE (repeat counts, structs, several fields, a size that does not
 *         match the kind). COMPLEX and OTHER are returned with OTI_OK and rejected by nd_import().
 */
int nd_pep3118_classify(const char* format, int64_t itemsize, nd_srctype_t* st);

/**
 * @brief Classifies a DLPack DLDataType (native byte order).
 *
 * @param[in]  code  DLDataTypeCode.
 * @param[in]  bits  Bits per lane.
 * @param[in]  lanes Lanes (must be 1).
 * @param[out] st    Element type.
 *
 * @return OTI_OK, or OTI_ERR_DTYPE (lanes != 1, bits not a multiple of 8, bfloat, unknown code).
 */
int nd_dlpack_classify(int32_t code, int32_t bits, int32_t lanes, nd_srctype_t* st);

/**
 * @brief Imports a foreign buffer as a retained array: zero-copy when possible, else a converted copy.
 *
 * Zero-copy when src->src is exactly the wanted type (F64: FLOAT 8 native; I64: INT 8 native; U8:
 * BOOL 1), every byte stride is a multiple of the itemsize and data is aligned to it: the result
 * wraps the memory and keeps (@p release, @p release_ctx) until its references reach zero. Otherwise
 * the values are converted into a new library array (F64 from BOOL / INT / UINT / FLOAT 4 / swapped
 * or unaligned FLOAT 8; I64 from INT / UINT, a UINT value above INT64_MAX failing with
 * OTI_ERR_INDEX; U8 from BOOL only) and the callback is invoked before returning. Ownership of the
 * callback passes ON ENTRY, as for nd_wrap(): it runs exactly once on every path.
 *
 * @param[in,out] ctx         Context, or NULL.
 * @param[in]     src         Foreign buffer description.
 * @param[in]     want        OTI_F64, OTI_I64, OTI_U8, or 0 for the natural type (U8 for BOOL, I64 for
 *                            INT / UINT, F64 for FLOAT).
 * @param[in]     iflags      ND_IMPORT_WRITEABLE | ND_IMPORT_COPY.
 * @param[in]     release     Callback that ends the foreign export, or NULL.
 * @param[in,out] release_ctx Callback argument.
 * @param[out]    res         New retained array; ND_WRITEABLE iff zero-copy over a writeable source or a
 *                            library copy. Overwritten without being released.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (device not the CPU, NULL); OTI_ERR_SHAPE (ndim > OTI_ND_MAXDIM,
 *         negative extent); OTI_ERR_DTYPE (COMPLEX, OTHER, float16, bool as I64, float as I64 or U8,
 *         or a conversion with ND_IMPORT_WRITEABLE); OTI_ERR_LAYOUT (misaligned or non-multiple
 *         strides with ND_IMPORT_WRITEABLE); OTI_ERR_READONLY (read-only source with
 *         ND_IMPORT_WRITEABLE); OTI_ERR_SIZE; OTI_ERR_MEMORY; OTI_ERR_INDEX. Caller must release @p res
 *         via nd_release().
 */
int nd_import(oti_ctx* ctx, const nd_import_t* src, int32_t want, int32_t iflags,
              nd_release_fn release, void* release_ctx, ndarr_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name The oti_view mapping (PLAN-ndarray-contracts.md section 6)
 * @{
 */

/**
 * @brief Describes an array as an OTI_KIND_REAL oti_view (no copy, no reference).
 *
 * dl.data = a->data, byte_offset 0, dl.shape / dl.strides point INTO @p a (valid while @p a is alive
 * and unchanged), device CPU / 0, dtype F64 {2, 64, 1}, U8 {6, 8, 1}, I64 {0, 64, 1}; flags
 * OTI_VIEW_READONLY iff ND_WRITEABLE is clear; OTI fields and reserved zero. Only the first
 * v->struct_size bytes are written.
 *
 * @param[in]     a Well-formed descriptor.
 * @param[in,out] v View; v->struct_size must be set by the caller (in), at least
 *                  offsetof(oti_view, reserved).
 *
 * @return OTI_OK, or OTI_ERR_ARGUMENT (NULL, struct_size too small).
 */
int nd_to_view(const ndarr_t* a, oti_view* v);

/**
 * @brief Describes an OTI_KIND_REAL oti_view as a temporary descriptor (buf NULL, no copy).
 *
 * strides NULL means compact row-major; data + byte_offset must be aligned to the itemsize. The view
 * carries no ownership: the caller keeps the memory alive while @p out is used. No conversion is
 * done (use nd_import() for that).
 *
 * @param[in]  v      View, kind OTI_KIND_REAL, struct_size set.
 * @param[in]  vflags ND_V_OUTPUT to require a writeable, non-overlapping layout.
 * @param[out] out    Temporary descriptor; ND_WRITEABLE iff OTI_VIEW_READONLY is clear. Must be empty
 *                    or a temporary on entry.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (struct_size, kind, device); OTI_ERR_SHAPE (ndim > OTI_ND_MAXDIM);
 *         OTI_ERR_DTYPE (not exactly f64 / bool8 / int64); OTI_ERR_LAYOUT; OTI_ERR_READONLY;
 *         OTI_ERR_SIZE.
 */
int nd_from_view(const oti_view* v, int32_t vflags, ndarr_t* out);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Test hooks
 * For tests/c only; never called by the library or the Python layer.
 * @{
 */

/**
 * @brief Makes the @p countdown-th allocation made by nd_* code from now on fail (malloc, aligned
 *        malloc, control blocks, temporaries); 0 disables. Process-wide, thread-safe (atomic).
 *
 * @param[in] countdown 1 fails the next allocation, 2 the one after, ...; 0 disables.
 */
void nd_test_fail_alloc(int64_t countdown);

/** @} */
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
