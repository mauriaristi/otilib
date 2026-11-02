#ifndef OTI_DENSE_SCALAR_STRUCTURES_H
#define OTI_DENSE_SCALAR_STRUCTURES_H

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     STATUS CODES     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

// Every dense function that can allocate returns one of these (never exit()). The negative codes
// share their values with OTI_LINALG_ERR_* (include/oti/sparse/array/algebra_lu.h), so a linear
// algebra status and a memory status are read the same way; linear algebra adds info > 0 from dgetrf
// when the real part is singular.

#define DN_OK              0  ///< Success.
#define DN_ERR_SIZE      (-1) ///< Incompatible shapes, or a dimension too large for LAPACK integers.
#define DN_ERR_MEMORY    (-2) ///< An allocation failed, or a coefficient count overflows.
#define DN_ERR_PIVOT     (-3) ///< Invalid pivot indices (LU solve).
#define DN_ERR_INDEX     (-4) ///< Index, direction or order out of range.
#define DN_ERR_ARGUMENT  (-5) ///< Invalid argument (NULL pointer, bad value).


// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Dense OTI number: dense coefficients over the global bases 1..nact.
 *
 * With k = nact, the imaginary coefficients of orders 1..trc_order are stored back to back in
 * @p p_im, and order p starts at sshelp_order_offset(k, p) = C(k+p-1, p-1) - 1. By the colex prefix
 * property (include/oti/core/semisparse.h), the order-p directions over bases 1..k are exactly the
 * global order-p indices 0 .. N_p(k)-1, so local and global numbering coincide: the global direction
 * (idx, p) is p_im[sshelp_order_offset(k, p) + idx] when idx < sshelp_ndir_order(k, p), and is
 * structurally zero otherwise. Every order up to trc_order has its slots; orders above act_order
 * hold zeros.
 *
 * @p p_im holds at least sshelp_ndir_total(nbases, trc_order) coefficients, with nbases >= nact the
 * capacity in bases at the current trc_order (the allocation may be larger; nbases never overstates
 * it, see oti_reserve()). Order offsets depend only on (k, p), so raising trc_order appends orders
 * and growing k within the capacity moves the order blocks in place, highest order first
 * (oti_add_bases()).
 *
 * There is no ownership flag: every otinum_t owns its p_im and oti_free() always releases it (the
 * Python wrapper keeps its own FLAGS). nact = 0 is a real number; p_im may then be NULL.
 */
typedef struct {
    coeff_t          re; ///< Real coefficient.
    coeff_t*       p_im; ///< Orders 1..trc_order back to back; order p at C(nact+p-1, p-1) - 1.
    bases_t      nbases; ///< Capacity of p_im, in bases (at trc_order); nbases >= nact.
    bases_t        nact; ///< Number of active bases k: the number is dense over bases 1..k.
    ord_t     trc_order; ///< Truncation order.
    ord_t     act_order; ///< Highest order that may hold nonzeros (<= trc_order).
} otinum_t;             ///< Dense OTI number type.

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------

#endif
