#ifndef OTI_CORE_STATUS_H
#define OTI_CORE_STATUS_H

// -------------------------------------------------------------------------------------------------------
// Library-wide status codes (PLAN-ndarray.md "Status codes"; PLAN-ndarray-contracts.md section 4).
//
// Rules:
//   - Every function that can fail returns int: OTI_OK (0), a negative OTI_ERR_* code, or, for
//     LAPACK-backed linear algebra only, a positive LAPACK info whose meaning the function documents
//     (getrf: U(info, info) exactly zero; trtrs: a zero diagonal entry). dpotrf's positive info is
//     returned as OTI_ERR_NOTPD instead.
//   - The values never change. -6 .. -19 are unassigned and stay reserved; new codes take the next
//     free value below -27.
//   - Aliases: DN_ERR_* (include/oti/dense/scalar/structures.h) become `#define DN_ERR_SIZE
//     OTI_ERR_SIZE` and so on in Phase 7a; OTI_LINALG_ERR_* (include/oti/sparse/array/algebra_lu.h)
//     in Phase 9. The CSR (CSRO_*, CSRSS_*) and I/O (DNIO_*, SSIO_*) families keep their own codes
//     until they are touched, and are then moved onto these names.
//   - The legacy `enum oti_errors` of include/oti/comm.h (OTI_success, OTI_OutOfMemory = -1, ...)
//     is a different, older family; its values must never be returned as, or compared with, these.
//   - A failing public function also records the status in its context's last-error slot
//     (oti_ctx_set_error(), include/oti/core/exec.h). Success never clears it.
//   - After a failure every output is valid (safe to release) but its value is unspecified.
//
// Python mapping (one place, the Cython `_status` helper of each module):
//   OTI_ERR_SIZE, OTI_ERR_PIVOT, OTI_ERR_ARGUMENT, OTI_ERR_SHAPE, OTI_ERR_LAYOUT,
//   OTI_ERR_READONLY  -> ValueError
//   OTI_ERR_MEMORY    -> MemoryError
//   OTI_ERR_INDEX     -> IndexError
//   OTI_ERR_BUSY      -> BufferError (message names the remedy: reserve(), nbases= / order=)
//   OTI_ERR_DTYPE     -> TypeError
//   OTI_ERR_CONVERGE, OTI_ERR_NOTPD, info > 0 -> numpy.linalg.LinAlgError
//   OTI_ERR_BACKEND   -> RuntimeError
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/** @name Library-wide status values
 * Fixed values; see the rules above. Statuses travel as C `int` (32 bits on every supported platform).
 * @{
 */
#define OTI_OK               0  ///< Success.
#define OTI_ERR_SIZE       (-1) ///< A size or count overflows, or does not fit LAPACK's 32-bit integers.
#define OTI_ERR_MEMORY     (-2) ///< An allocation failed, or a request exceeds the context's byte budget.
#define OTI_ERR_PIVOT      (-3) ///< Invalid pivot indices (LU solve).
#define OTI_ERR_INDEX      (-4) ///< Index, axis, direction or order out of range.
#define OTI_ERR_ARGUMENT   (-5) ///< Invalid argument (NULL pointer, bad flag value, unsupported device).
#define OTI_ERR_SHAPE     (-20) ///< Incompatible shapes, broadcast failure, ndim > OTI_ND_MAXDIM.
#define OTI_ERR_BUSY      (-21) ///< Growth / relayout refused: live views or exports, borrowed buffer.
#define OTI_ERR_DTYPE     (-22) ///< Unsupported or mismatched dtype or buffer format.
#define OTI_ERR_LAYOUT    (-23) ///< Internal overlap of an output, unsupported strides, span violation.
#define OTI_ERR_CONVERGE  (-24) ///< Eigenvalue / SVD iteration did not converge (tier 2).
#define OTI_ERR_NOTPD     (-25) ///< Cholesky: the matrix is not positive definite.
#define OTI_ERR_BACKEND   (-26) ///< The requested parallel backend is not compiled in.
#define OTI_ERR_READONLY  (-27) ///< Write into a destination that is not ND_WRITEABLE.
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief DLPack kDLCPU: the only device accepted (oti_ctx.device_type, oti_view.dl.device).
 *
 * Defined once, here, because every core and ndarray header includes this one.
 */
#define OTI_DEVICE_CPU 1
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Compile-time checks of the status representation.
 *
 * Statuses are returned as `int` and mapped to `integer(c_int)` / `int32` by the bindings, so `int`
 * must be 32 bits wide.
 */
#if defined(__cplusplus)
static_assert(sizeof(int) == 4, "otilib statuses require a 32-bit int");
#else
_Static_assert(sizeof(int) == 4, "otilib statuses require a 32-bit int");
#endif
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Tells whether a status is a LAPACK "singular" info (a positive value).
 *
 * @param[in] status A status returned by an otilib function.
 *
 * @return 1 if @p status > 0, 0 otherwise.
 */
static inline int oti_status_is_singular(int status){
    return status > 0;
}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Static text for a status, "<NAME>: <meaning>".
 *
 * Never allocates; thread-safe. Unknown negative values give "OTI_ERR_UNKNOWN: unknown status";
 * positive values give "LAPACK_INFO: singular matrix (exactly zero pivot)".
 *
 * @param[in] status Any status value.
 *
 * @return Pointer to a static, NUL-terminated string. The caller must not free it.
 */
const char* oti_status_string(int status);
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
