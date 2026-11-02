#ifndef OTI_FORTRAN_SHIM_H
#define OTI_FORTRAN_SHIM_H

// -------------------------------------------------------------------------------------------------------
// Fortran C-descriptor shim of the ndarray module (PLAN-ndarray.md "Fortran interoperability", Phase
// F2; decision 24). Distributed as source and compiled PER FORTRAN VENDOR with only that vendor's
// ISO_Fortran_binding.h visible (a build-directory copy of that one header, or -idirafter on the
// vendor's include directory; never a plain -I on a GCC / flang resource directory, which shadows the
// C compiler's stddef.h / stdint.h). The two vendors' headers differ in field order, type codes,
// attribute codes and error codes: a shim built against the wrong header is rejected at the first
// call (its type check fails) instead of corrupting memory. liboti itself never includes this header.
//
// Mapping (no copy): Fortran index (i1, ..., iN) of the array is ndarray index (i1-lb1, ..., iN-lbN);
// ndarray axis k is Fortran axis k + 1; element strides are dim[k].sm / elem_len; data is base_addr.
// The descriptor is validated here, never through the CFI_* functions (gfortran's check nothing unless
// the main program was built with -fcheck=bounds):
//   - rank 0 .. 15 (OTI_ERR_SHAPE), type CFI_type_double and elem_len 8 (OTI_ERR_DTYPE), a known
//     attribute (OTI_ERR_ARGUMENT), extents >= 0 (assumed-size: OTI_ERR_SHAPE), and the product of the
//     non-zero extents and its byte count in int64_t (checked arithmetic, OTI_ERR_SIZE);
//   - size 0 first: an empty array becomes a compact empty descriptor with data NULL, before any
//     stride logic (flang sends sm = 0 in non-empty dimensions and lower_bound = 1 there);
//   - sm % elem_len != 0 (-fpack-derived components) and a base_addr not aligned for double
//     (c_f_pointer from an offset address) are rejected with OTI_ERR_LAYOUT;
//   - contiguity is computed here (CFI_is_contiguous misbehaves on rank 0 in libgfortran).
// A wrapped array is a TEMPORARY descriptor (buf NULL): it borrows the Fortran memory for one call.
// -------------------------------------------------------------------------------------------------------

#include <stdint.h>

#include <ISO_Fortran_binding.h>

#include "oti/real/ndarray.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Largest Fortran rank accepted at the edge (the Fortran 2018 limit, decision 4). */
#define OTI_FORTRAN_MAXRANK 15

/**
 * @brief Wraps a Fortran array descriptor as a borrowed, temporary ndarr_t (no copy).
 *
 * The result is valid only while the Fortran array is alive, not reallocated and not moved; it must
 * not be retained (nd_view_retain() fails on it, buf is NULL) or exported.
 *
 * @param[in]  d         Descriptor of a real(c_double) array of rank 0 .. 15: an ordinary dummy, an
 *                       allocated allocatable or an associated pointer.
 * @param[in]  writeable 1 to set ND_WRITEABLE (the caller guarantees the array may be written).
 * @param[out] out       Temporary descriptor. Must be empty or a temporary on entry.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (NULL, unknown attribute, unallocated or disassociated array);
 *         OTI_ERR_SHAPE (rank > 15, assumed size); OTI_ERR_SIZE (the product of the non-zero extents,
 *         or its byte count, overflows int64_t; checked before any stride is built);
 *         OTI_ERR_DTYPE (type or elem_len); OTI_ERR_LAYOUT
 *         (sm not a multiple of elem_len, misaligned base_addr). Failures are recorded as the calling
 *         thread's last error (oti_ctx_last_error(NULL, ...)).
 */
int oti_fortran_wrap(const CFI_cdesc_t* d, int32_t writeable, ndarr_t* out);

/**
 * @brief Contiguity of a Fortran array descriptor in Fortran (column-major) order.
 *
 * Computed from the extents and sm, never through CFI_is_contiguous(). Rank 0 and size 0 are
 * contiguous; dimensions of extent 1 are ignored.
 *
 * @param[in] d Descriptor (any type; elem_len is the element size).
 *
 * @return 1 if contiguous, 0 if not; OTI_ERR_ARGUMENT for NULL or a rank outside 0 .. 15;
 *         OTI_ERR_SHAPE for a negative extent; OTI_ERR_SIZE when a compact stride would overflow
 *         int64_t (checked arithmetic; the last dimension's product is not formed).
 */
int oti_fortran_is_contiguous(const CFI_cdesc_t* d);

#ifdef __cplusplus
}
#endif

#endif
