#ifndef OTI_CORE_SEMISPARSE_H
#define OTI_CORE_SEMISPARSE_H

// Index helpers for semi-sparse OTI numbers (PLAN-semisparse.md, Section 4.1).
//
// A semi-sparse number stores a sorted list of k active global bases and is dense over them. Its
// directions are numbered locally: local base u (0-based, u < k) stands for global base
// p_bases[u]. An order-p direction is a nondecreasing tuple u_0 <= ... <= u_{p-1}, and its local
// index is the colex rank
//
//     rank(u) = sum_i C(u_i + i, i + 1),
//
// the same formula the global numbering uses with u_i = global base - 1. Because of that:
//   - the order-p directions over k bases are exactly local indices 0 .. N_p(k)-1, with
//     N_p(k) = C(k+p-1, p);
//   - for k <= Nbasis(p+q) the local product index of an (order p, order q) pair is read from the
//     global multiplication table sub-block (sshelp_get_pair);
//   - a local direction maps to a global one by mapping each u_i and ranking, with no sorting.
//
// Coefficients of orders 1..n are stored back to back; order p starts at C(k+p-1, p-1) - 1.

#include <stddef.h>
#include <stdint.h>


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     STATUS CODES     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

#define SSHELP_OK              0  ///< Success.
#define SSHELP_ERR_OVERFLOW  (-1) ///< A direction count or allocation size overflows.
#define SSHELP_ERR_MEMORY    (-2) ///< An allocation failed.
#define SSHELP_ERR_RANGE     (-3) ///< An argument is out of range (order, base label, index).

/// Saturated result of sshelp_comb() when C(a, b) does not fit in 64 bits.
#define SSHELP_COMB_OVERFLOW UINT64_MAX

/// Default total memory budget (MiB) for sshelp_get_pair()'s local product-table cache; overridden
/// by the OTI_SS_TABLE_CACHE_MB environment variable (read once, on the first table build).
#define SSHELP_CACHE_DEFAULT_MB 256


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------     STRUCTURES     -------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Product-index source for one (order p, order q) pair over k local bases.
 *
 * Built once per order pair by sshelp_get_pair(), outside the coefficient loops. When @p p_tab is
 * not NULL the product of local directions i (order p) and j (order q) is
 * `p_tab[i*stride + j]` (or `p_tab[j*stride + i]` when @p transpose is set). When it is NULL the
 * table does not cover k bases and the caller ranks the merged tuples (sshelp_prod_rank()).
 */
typedef struct {
    const imdir_t*   p_tab; ///< Global multiplication table data, or NULL for the rank fallback.
    uint64_t        stride; ///< Row length of the full table (its shape[1]).
    int          transpose; ///< Nonzero when the order-p operand indexes the table columns (p > q).
} sshelp_pair_t;

/**
 * @brief Binomial table for fast local ranks: `p_c[i*k + u] = C(u + i, i + 1)`.
 *
 * Covers tuple positions i < n and local bases u < k, which is every term of sshelp_rank() for
 * directions up to order n over k bases.
 */
typedef struct {
    ndir_t*  p_c; ///< Table data, n*k entries. NULL when k == 0 or n == 0.
    bases_t    k; ///< Number of local bases.
    ord_t      n; ///< Highest order covered.
} sshelp_rank_tab_t;

/**
 * @brief Growable scratch buffers for one thread.
 *
 * Kernels never use the dhelp p_im scratch arrays (PLAN-lazy-nbasis.md, step 1); they take one of
 * these per thread and grow it with sshelp_ws_reserve().
 */
typedef struct {
    coeff_t*  p_coef; ///< Coefficient scratch.
    ndir_t*    p_map; ///< Index scratch (remap maps, index lists).
    bases_t* p_bases; ///< Base scratch (unions, positions, tuples).
    size_t     ncoef; ///< Capacity of p_coef, in elements.
    size_t      nmap; ///< Capacity of p_map, in elements.
    size_t    nbases; ///< Capacity of p_bases, in elements.
} sshelp_ws_t;


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------     INLINE HELPERS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Binomial coefficient C(a, b), saturating on overflow.
 *
 * @param[in] a Size of the set.
 * @param[in] b Size of the subsets.
 *
 * @return C(a, b); 0 when b > a; SSHELP_COMB_OVERFLOW when the value does not fit in 64 bits.
 */
static inline uint64_t sshelp_comb(uint64_t a, uint64_t b){

    unsigned __int128 c = 1;
    uint64_t i;

    if (b > a){
        return 0;
    }

    if (b > a - b){
        b = a - b;
    }

    // Small sets (every block-offset call of the kernels): each product c * (a-b+i+1) equals
    // C(a-b+i+1, i+1) (i+1) <= 62 C(61, 30) < 2^64, so 64-bit arithmetic is exact and avoids the
    // software 128-bit division.
    if (a <= 62){

        uint64_t c64 = 1;

        for (i = 0; i < b; i++){
            c64 = c64 * (a - b + i + 1) / (i + 1);
        }

        return c64;

    }

    // c = C(a-b+i+1, i+1) after step i: exact at every step.
    for (i = 0; i < b; i++){

        c = c * (a - b + i + 1) / (i + 1);

        if (c >= (unsigned __int128)SSHELP_COMB_OVERFLOW){
            return SSHELP_COMB_OVERFLOW;
        }

    }

    return (uint64_t)c;

}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Number of order-p directions over k bases, N_p(k) = C(k+p-1, p).
 *
 * @param[in] k Number of bases.
 * @param[in] p Order (0 gives 1, the real part).
 *
 * @return N_p(k). Saturates to SSHELP_COMB_OVERFLOW (see sshelp_ndir_total_checked()).
 */
static inline ndir_t sshelp_ndir_order(bases_t k, ord_t p){

    if (p == 0){
        return 1;
    }

    if (k == 0){
        return 0;
    }

    return sshelp_comb((uint64_t)k + p - 1, p);

}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Offset of the order-p block in a coefficient buffer holding orders 1..n back to back.
 *
 * Equals sum_{q<p} N_q(k) (q >= 1) = C(k+p-1, p-1) - 1.
 *
 * @param[in] k Number of bases.
 * @param[in] p Order, p >= 1. p = n+1 gives the buffer length.
 *
 * @return Offset in coefficients.
 */
static inline ndir_t sshelp_order_offset(bases_t k, ord_t p){

    if (k == 0){
        return 0;
    }

    return sshelp_comb((uint64_t)k + p - 1, p - 1) - 1;

}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Number of imaginary coefficients of orders 1..n over k bases, C(k+n, n) - 1.
 *
 * @param[in] k Number of bases.
 * @param[in] n Truncation order.
 *
 * @return Coefficient count, without the real part. Unchecked: use sshelp_ndir_total_checked()
 *         before allocating.
 */
static inline ndir_t sshelp_ndir_total(bases_t k, ord_t n){

    return sshelp_order_offset(k, n + 1);

}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Tells whether a position map from sshelp_union_bases() is the identity prefix.
 *
 * When it is, the operand's bases are the first @p n bases of the union and its coefficients only
 * need zero-extension (colex prefix property), not a remap.
 *
 * @param[in] pos Position of each operand base in the union, length @p n.
 * @param[in] n   Number of operand bases.
 *
 * @return 1 if pos[i] == i for all i, else 0.
 */
static inline int sshelp_is_leading(const bases_t* pos, bases_t n){

    return n == 0 || pos[n - 1] == n - 1;

}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Advances a local direction tuple to the next one in colex order.
 *
 * Starting from (0, ..., 0) and calling this N_p(k) - 1 times visits every order-p direction over
 * k bases in local index order.
 *
 * @param[in,out] u Nondecreasing tuple of local bases, length @p p.
 * @param[in]     p Order (tuple length), p >= 1.
 * @param[in]     k Number of bases.
 *
 * @return 1 if advanced, 0 if @p u was the last direction (left unchanged).
 */
static inline int sshelp_next_dir(bases_t* u, ord_t p, bases_t k){

    ord_t i, j;
    bases_t lim;

    for (i = 0; i < p; i++){

        lim = (i + 1 < p) ? u[i + 1] : (bases_t)(k - 1);

        if (u[i] < lim){

            u[i]++;

            for (j = 0; j < i; j++){
                u[j] = 0;
            }

            return 1;

        }

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Local index of a direction tuple, using a binomial table.
 *
 * @param[in] u   Nondecreasing tuple of local bases, length @p p, all < tab->k.
 * @param[in] p   Order, p <= tab->n.
 * @param[in] tab Binomial table from sshelp_rank_tab_init().
 *
 * @return Local index within order p.
 */
static inline ndir_t sshelp_rank(const bases_t* u, ord_t p, const sshelp_rank_tab_t* tab){

    ndir_t r = 0;
    ord_t i;

    for (i = 0; i < p; i++){
        r += tab->p_c[(size_t)i * tab->k + u[i]];
    }

    return r;

}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Local index of the product of two local directions (rank fallback of sshelp_pair_t).
 *
 * Merges the two sorted tuples and ranks the result, like dhelp_precompute_multiply() does with
 * global bases.
 *
 * @param[in] ui  First tuple, length @p p.
 * @param[in] p   Order of the first direction.
 * @param[in] uj  Second tuple, length @p q.
 * @param[in] q   Order of the second direction.
 * @param[in] tab Binomial table with tab->n >= p + q.
 *
 * @return Local index of the order-(p+q) product.
 */
static inline ndir_t sshelp_prod_rank(const bases_t* ui, ord_t p, const bases_t* uj, ord_t q,
                                      const sshelp_rank_tab_t* tab){

    ndir_t r = 0;
    ord_t a = 0, b = 0, i = 0;
    bases_t v;

    while (a < p || b < q){

        if (b == q || (a < p && ui[a] <= uj[b])){
            v = ui[a++];
        } else {
            v = uj[b++];
        }

        r += tab->p_c[(size_t)i * tab->k + v];
        i++;

    }

    return r;

}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Product index of local directions i (order p) and j (order q) from a table pair.
 *
 * Only valid when pair->p_tab is not NULL. Kernels should branch on p_tab and transpose once per
 * order pair and index the table directly in the inner loop; this is the reference form.
 *
 * @param[in] pair Pair from sshelp_get_pair().
 * @param[in] i    Local index of the order-p direction.
 * @param[in] j    Local index of the order-q direction.
 *
 * @return Local index of the order-(p+q) product.
 */
static inline ndir_t sshelp_pair_idx(const sshelp_pair_t* pair, ndir_t i, ndir_t j){

    if (pair->transpose){
        return pair->p_tab[j * pair->stride + i];
    }

    return pair->p_tab[i * pair->stride + j];

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------     DECLARATIONS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Checks that a semi-sparse coefficient buffer over k bases to order n can be indexed and
 * allocated.
 *
 * Checks that C(k+n, n) fits in ndir_t and that C(k+n, n) * sizeof(coeff_t) fits in size_t.
 *
 * @param[in]  k      Number of bases.
 * @param[in]  n      Truncation order.
 * @param[out] p_nimag Number of imaginary coefficients, C(k+n, n) - 1. May be NULL.
 *
 * @return SSHELP_OK, or SSHELP_ERR_OVERFLOW.
 */
int sshelp_ndir_total_checked(bases_t k, ord_t n, ndir_t* p_nimag);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sorted union of two sorted base lists, with the position of each input base.
 *
 * Branchless merge. Both inputs must be strictly increasing. @p res needs room for na + nb bases.
 *
 * @param[in]  a     First base list, length @p na.
 * @param[in]  na    Length of @p a.
 * @param[in]  b     Second base list, length @p nb.
 * @param[in]  nb    Length of @p b.
 * @param[out] res   Union, strictly increasing. Must not alias @p a or @p b.
 * @param[out] pos_a Index in @p res of each base of @p a, length @p na. May be NULL.
 * @param[out] pos_b Index in @p res of each base of @p b, length @p nb. May be NULL.
 *
 * @return Length of the union.
 */
bases_t sshelp_union_bases(const bases_t* a, bases_t na, const bases_t* b, bases_t nb,
                           bases_t* res, bases_t* pos_a, bases_t* pos_b);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Allocates the binomial table used by sshelp_rank() and sshelp_prod_rank().
 *
 * @param[out] tab Table to fill.
 * @param[in]  k   Number of local bases.
 * @param[in]  n   Highest order to cover.
 *
 * @return SSHELP_OK, SSHELP_ERR_OVERFLOW or SSHELP_ERR_MEMORY. On success the caller owns
 *         tab->p_c and releases it with sshelp_rank_tab_free().
 */
int sshelp_rank_tab_init(sshelp_rank_tab_t* tab, bases_t k, ord_t n);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases a binomial table from sshelp_rank_tab_init().
 *
 * @param[in,out] tab Table to free; left empty. Safe on an empty table.
 */
void sshelp_rank_tab_free(sshelp_rank_tab_t* tab);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Direction tuple of a local index (inverse of sshelp_rank()).
 *
 * @param[in]  idx Local index within order p, idx < N_p(k).
 * @param[in]  p   Order.
 * @param[out] u   Nondecreasing tuple of local bases, length @p p.
 */
void sshelp_unrank(ndir_t idx, ord_t p, bases_t* u);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Lists every order-p direction over k bases in local index order.
 *
 * @param[in]  k   Number of bases.
 * @param[in]  p   Order, p >= 1.
 * @param[out] out Row-major N_p(k) x p array of tuples.
 */
void sshelp_local_dirs(bases_t k, ord_t p, bases_t* out);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Remap from a source set's local directions to a destination set's local directions.
 *
 * The source set has @p k_src bases and its base u sits at position pos[u] in the destination set
 * (from sshelp_union_bases()). map[j] is the destination local index of source direction j.
 * Costs O(N_p(k_src) * p).
 *
 * @param[in]  k_src   Number of source bases.
 * @param[in]  pos     Destination position of each source base, strictly increasing, length k_src.
 * @param[in]  p       Order, p >= 1.
 * @param[in]  tab_dst Binomial table of the destination set (tab_dst->n >= p).
 * @param[out] map     Remap, length N_p(k_src).
 * @param[out] u       Scratch tuple, length @p p.
 */
void sshelp_remap_order(bases_t k_src, const bases_t* pos, ord_t p,
                        const sshelp_rank_tab_t* tab_dst, ndir_t* map, bases_t* u);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Global index of a direction given by its sorted global base labels.
 *
 * @param[in] g Nondecreasing global base labels (1-based), length @p p.
 * @param[in] p Order.
 *
 * @return Global index within order p, as used by sotinum_t, or SSHELP_COMB_OVERFLOW if it does
 *         not fit in imdir_t.
 */
imdir_t sshelp_global_rank(const bases_t* g, ord_t p);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Global base labels of a global direction index (inverse of sshelp_global_rank()).
 *
 * Does not depend on the dhelp tables, so it covers every label up to 65535.
 *
 * @param[in]  idx Global index within order p.
 * @param[in]  p   Order.
 * @param[out] g   Nondecreasing global base labels (1-based), length @p p.
 *
 * @return SSHELP_OK, or SSHELP_ERR_RANGE if a label would exceed the bases_t range.
 */
int sshelp_global_unrank(imdir_t idx, ord_t p, bases_t* g);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Global index of a local direction.
 *
 * @param[in]  idx   Local index within order p.
 * @param[in]  p     Order, p <= 255.
 * @param[in]  bases Active global bases, strictly increasing, length @p k.
 * @param[in]  k     Number of active bases.
 * @param[out] p_idx Global index within order p.
 *
 * @return SSHELP_OK, SSHELP_ERR_RANGE if idx >= N_p(k), or SSHELP_ERR_OVERFLOW if the global index
 *         does not fit in imdir_t.
 */
int sshelp_local_to_global(ndir_t idx, ord_t p, const bases_t* bases, bases_t k, imdir_t* p_idx);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Local index of a global direction.
 *
 * @param[in]  idx   Global index within order p.
 * @param[in]  p     Order.
 * @param[in]  bases Active global bases, strictly increasing, length @p k.
 * @param[in]  k     Number of active bases.
 * @param[out] p_idx Local index within order p (set only when found).
 *
 * @return 1 if every base of the direction is active, 0 if one is not, or SSHELP_ERR_RANGE if the
 *         index is not a valid global direction.
 */
int sshelp_global_to_local(imdir_t idx, ord_t p, const bases_t* bases, bases_t k, ndir_t* p_idx);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Chooses the product-index source for an (order p, order q) pair over k local bases.
 *
 * Uses the global multiplication table of order p+q (built on first use by dhelp_get_multtabl())
 * when p+q <= dhl.ndh and k <= Nbasis(p+q); every row and column index of the local sub-block is
 * then inside the table, which avoids the out-of-range read of PLAN-lazy-nbasis.md.
 *
 * Otherwise (k beyond the global table's reach, the common case at high k and mid orders) looks up
 * or lazily builds a local table for (k, min(p,q), max(p,q)), cached for the process: entries are
 * `T[i*Nq + j]` = local index of the product of the order-min(p,q) direction i and the
 * order-max(p,q) direction j, `stride` = N_max(p,q)(k), `transpose` set when p > q -- the same
 * indexing contract as the global sub-block. The table is built once per distinct (k, p, q) with
 * the rank method (sshelp_prod_rank()) and reused by every later call; building is skipped, and
 * p_tab stays NULL (the caller falls back to sshelp_prod_rank() per pair, as before), once the
 * cache's total size would exceed its memory budget (SSHELP_CACHE_DEFAULT_MB, overridden by the
 * OTI_SS_TABLE_CACHE_MB environment variable, in MiB). Thread-safe: double-checked, atomic
 * acquire/release per cache entry, building under a named omp critical section, like
 * dhelp_get_multtabl() (include/oti/core/dhelp_inline.h).
 *
 * @param[in] k   Number of local bases.
 * @param[in] p   Order of the first operand, p >= 1.
 * @param[in] q   Order of the second operand, q >= 1.
 * @param[in] dhl Direction helper list.
 *
 * @return The pair.
 */
sshelp_pair_t sshelp_get_pair(bases_t k, ord_t p, ord_t q, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases sshelp_get_pair()'s local product-table cache.
 *
 * Called from dhelp_free(). Safe to call when the cache is empty (never built).
 */
void sshelp_cache_free(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Empty workspace (no buffers).
 *
 * @return Workspace with NULL buffers and zero capacities.
 */
sshelp_ws_t sshelp_ws_init(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Grows a workspace to at least the given capacities. Existing contents are not kept.
 *
 * @param[in,out] ws     Workspace.
 * @param[in]     ncoef  Required coefficient capacity.
 * @param[in]     nmap   Required index capacity.
 * @param[in]     nbases Required base capacity.
 *
 * @return SSHELP_OK, SSHELP_ERR_OVERFLOW or SSHELP_ERR_MEMORY. The workspace owns its buffers;
 *         release them with sshelp_ws_free().
 */
int sshelp_ws_reserve(sshelp_ws_t* ws, size_t ncoef, size_t nmap, size_t nbases);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases the buffers of a workspace and leaves it empty.
 *
 * @param[in,out] ws Workspace.
 */
void sshelp_ws_free(sshelp_ws_t* ws);
// -------------------------------------------------------------------------------------------------------

#endif
