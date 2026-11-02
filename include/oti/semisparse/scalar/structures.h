#ifndef OTI_SEMISPARSE_SCALAR_STRUCTURES_H
#define OTI_SEMISPARSE_SCALAR_STRUCTURES_H

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Semi-sparse OTI number: dense coefficients over a sorted list of active bases.
 *
 * With k = nbases, the imaginary coefficients of orders 1..trc_order are stored back to back in
 * @p p_im, and order p starts at sshelp_order_offset(k, p) = C(k+p-1, p-1) - 1. Directions are
 * numbered locally (see include/oti/core/semisparse.h): local base u is global base p_bases[u].
 * Every order up to trc_order has its slots, so orders above act_order hold zeros.
 *
 * The buffers hold at least cap_bases bases at trc_order: p_bases holds cap_bases labels and p_im
 * at least sshelp_ndir_total(cap_bases, trc_order) coefficients. Order offsets depend only on
 * (k, p), so growing the capacity or the truncation order keeps the layout; growing k within the
 * capacity moves the order blocks in place (ssoti_add_bases()).
 *
 * k = 0 is a real number; p_im and p_bases may then be NULL.
 */
typedef struct {
    coeff_t          re; ///< Real coefficient.
    coeff_t*       p_im; ///< Orders 1..trc_order back to back; order p at C(k+p-1, p-1) - 1.
    bases_t*    p_bases; ///< Sorted active global bases, length nbases.
    bases_t      nbases; ///< Number of active bases (k).
    bases_t   cap_bases; ///< Allocated capacity of p_bases and p_im, in bases.
    ord_t     act_order; ///< Highest order that may hold nonzeros (<= trc_order).
    ord_t     trc_order; ///< Truncation order.
    flag_t         flag; ///< Memory flag: 1 if the number owns p_im and p_bases, 0 for a view.
} ssotinum_t;           ///< Semi-sparse OTI number type.

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------

#endif
