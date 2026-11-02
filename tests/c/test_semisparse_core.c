/* Independent checks of the semi-sparse core index helpers (include/oti/core/semisparse.h,
 * src/c/core/semisparse_helper.c, PLAN-semisparse.md Sections 2 and 4.1). Exhaustive for k <= 4
 * bases and order <= 5, plus the extra edge cases from the task list (overflow, labels near
 * 65535, table sub-block limits). References are built from scratch in this file (a Pascal
 * triangle for sshelp_comb, brute-force tuple enumeration for counts, dhelp's own
 * dhelp_get_idx_ord / dhelp_precompute_multiply for global indices) rather than by re-deriving
 * the tested formulas. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <oti/oti.h>

#ifdef _OPENMP
#include <omp.h>
#endif

#define UNIV_N 6
#define CACHE_MAX_THREADS 64

static int n_failed = 0;

static const bases_t g_univ[UNIV_N] = {1, 2, 3, 4, 5, 6};


// *******************************************************************************************************
static void check(int cond, const char* name){

    if (!cond){
        fprintf(stderr, "FAILED: %s\n", name);
        n_failed++;
    } else {
        printf("passed: %s\n", name);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Bases of a bitmask over g_univ (bit i <-> label i+1), in strictly increasing order. */
static bases_t mask_to_bases(unsigned mask, bases_t* out){

    bases_t k = 0;
    unsigned i;

    for (i = 0; i < UNIV_N; i++){
        if (mask & (1u << i)){
            out[k++] = g_univ[i];
        }
    }

    return k;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ------------------------     PART 1: sshelp_comb / ndir_order / ndir_total     ------------------------
// -------------------------------------------------------------------------------------------------------

#define PMAX 206
static uint64_t g_pascal[PMAX][PMAX];


// *******************************************************************************************************
/* Additive Pascal triangle, independent of sshelp_comb's multiplicative saturating loop. Every
 * entry saturates to SSHELP_COMB_OVERFLOW instead of overflowing, since C(200,100) alone needs far
 * more than 64 bits and the recurrence is monotonic. */
static void build_pascal(void){

    uint64_t a, b;

    memset(g_pascal, 0, sizeof(g_pascal));

    for (a = 0; a < PMAX; a++){

        for (b = 0; b <= a && b < PMAX; b++){

            if (b == 0 || b == a){

                g_pascal[a][b] = 1;

            } else {

                uint64_t x = g_pascal[a - 1][b - 1];
                uint64_t y = g_pascal[a - 1][b];

                if (x == SSHELP_COMB_OVERFLOW || y == SSHELP_COMB_OVERFLOW
                    || x > UINT64_MAX - y){
                    g_pascal[a][b] = SSHELP_COMB_OVERFLOW;
                } else {
                    g_pascal[a][b] = x + y;
                }

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static uint64_t naive_comb(uint64_t a, uint64_t b){

    if (b > a){
        return 0;
    }

    return g_pascal[a][b];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_comb_vs_pascal(void){

    uint64_t a, b;
    char name[64];

    for (a = 0; a <= 12; a++){

        for (b = 0; b <= a + 2; b++){

            uint64_t expected = (b <= a) ? naive_comb(a, b) : 0;

            snprintf(name, sizeof(name), "comb(%llu,%llu) vs pascal triangle",
                (unsigned long long)a, (unsigned long long)b);
            check(sshelp_comb(a, b) == expected, name);

        }

    }

    check(sshelp_comb(5, 0) == 1, "comb(5,0) == 1");
    check(sshelp_comb(0, 0) == 1, "comb(0,0) == 1");
    check(sshelp_comb(3, 7) == 0, "comb(3,7) == 0 (b > a)");
    check(sshelp_comb(9, 10) == 0, "comb(9,10) == 0 (b > a, adjacent)");
    check(sshelp_comb(200, 100) == SSHELP_COMB_OVERFLOW, "comb(200,100) saturates to OVERFLOW");
    check(naive_comb(200, 100) == SSHELP_COMB_OVERFLOW, "pascal(200,100) also saturates");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Recursive brute-force count of nondecreasing tuples of length p over k bases (0-based), the
 * textbook "stars and bars" enumeration, independent of the comb-based closed form. */
static uint64_t brute_ndir_order_rec(ord_t p, ord_t pos, bases_t k, bases_t start){

    uint64_t total = 0;
    bases_t u;

    if (pos == p){
        return 1;
    }

    for (u = start; u < k; u++){
        total += brute_ndir_order_rec(p, (ord_t)(pos + 1), k, u);
    }

    return total;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static uint64_t brute_ndir_order(bases_t k, ord_t p){

    if (p == 0){
        return 1;
    }

    if (k == 0){
        return 0;
    }

    return brute_ndir_order_rec(p, 0, k, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_ndir_counts(void){

    bases_t k;
    ord_t p, q;
    char name[96];

    for (k = 0; k <= 4; k++){

        for (p = 0; p <= 5; p++){

            uint64_t expected = brute_ndir_order(k, p);

            snprintf(name, sizeof(name), "ndir_order(k=%u,p=%u) vs brute-force count",
                (unsigned)k, (unsigned)p);
            check(sshelp_ndir_order(k, p) == expected, name);

        }

    }

    for (k = 1; k <= 4; k++){

        for (p = 1; p <= 6; p++){

            uint64_t sum = 0;

            for (q = 1; q < p; q++){
                sum += brute_ndir_order(k, q);
            }

            snprintf(name, sizeof(name), "order_offset(k=%u,p=%u) vs sum of brute-force counts",
                (unsigned)k, (unsigned)p);
            check(sshelp_order_offset(k, p) == sum, name);

        }

    }

    check(sshelp_order_offset(0, 3) == 0, "order_offset(k=0, p=3) == 0");

    for (k = 1; k <= 4; k++){

        for (p = 1; p <= 5; p++){

            uint64_t sum = 0;

            for (q = 1; q <= p; q++){
                sum += brute_ndir_order(k, q);
            }

            snprintf(name, sizeof(name), "ndir_total(k=%u,n=%u) vs sum of brute-force counts",
                (unsigned)k, (unsigned)p);
            check(sshelp_ndir_total(k, p) == sum, name);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_ndir_total_checked(void){

    ndir_t nimag;
    uint64_t expected = 0;
    ord_t q;
    int rc;

    for (q = 1; q <= 5; q++){
        expected += brute_ndir_order(4, q);
    }

    rc = sshelp_ndir_total_checked(4, 5, &nimag);
    check(rc == SSHELP_OK, "ndir_total_checked(k=4,n=5) returns OK");
    check(nimag == expected, "ndir_total_checked(k=4,n=5) nimag vs brute-force sum");

    rc = sshelp_ndir_total_checked(65535, 10, &nimag);
    check(rc == SSHELP_ERR_OVERFLOW, "ndir_total_checked(k=65535,n=10) overflows");

    rc = sshelp_ndir_total_checked(0, 0, NULL);
    check(rc == SSHELP_OK, "ndir_total_checked(k=0,n=0) OK with NULL p_nimag");

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ------------------------------------     PART 2: sshelp_union_bases     -------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Every pair of subsets of {1..6}: union content, pos_a/pos_b consistency, is_leading. */
static void test_union_bases(void){

    unsigned mask_a, mask_b;

    for (mask_a = 0; mask_a < (1u << UNIV_N); mask_a++){

        for (mask_b = 0; mask_b < (1u << UNIV_N); mask_b++){

            bases_t a[UNIV_N], b[UNIV_N], res[2 * UNIV_N], expected[UNIV_N];
            bases_t pos_a[UNIV_N], pos_b[UNIV_N];
            bases_t na = mask_to_bases(mask_a, a);
            bases_t nb = mask_to_bases(mask_b, b);
            bases_t n_expected = mask_to_bases(mask_a | mask_b, expected);
            bases_t n, i;
            int leading_expected, leading_actual;
            char name[80];

            n = sshelp_union_bases(a, na, b, nb, res, pos_a, pos_b);

            snprintf(name, sizeof(name), "union(%u,%u) length", mask_a, mask_b);
            check(n == n_expected, name);

            snprintf(name, sizeof(name), "union(%u,%u) content", mask_a, mask_b);
            check(memcmp(res, expected, (size_t)n * sizeof(bases_t)) == 0, name);

            for (i = 0; i < na; i++){

                if (res[pos_a[i]] != a[i]){
                    snprintf(name, sizeof(name), "union(%u,%u) pos_a[%u] consistent",
                        mask_a, mask_b, (unsigned)i);
                    check(0, name);
                }

            }

            for (i = 0; i < nb; i++){

                if (res[pos_b[i]] != b[i]){
                    snprintf(name, sizeof(name), "union(%u,%u) pos_b[%u] consistent",
                        mask_a, mask_b, (unsigned)i);
                    check(0, name);
                }

            }

            leading_expected = (na == 0)
                || (memcmp(a, res, (size_t)na * sizeof(bases_t)) == 0);
            leading_actual = sshelp_is_leading(pos_a, na);

            snprintf(name, sizeof(name), "is_leading(%u,%u) matches prefix comparison",
                mask_a, mask_b);
            check((leading_actual != 0) == (leading_expected != 0), name);

        }

    }

    {
        bases_t a[3] = {2, 4, 6};
        bases_t b[2] = {1, 4};
        bases_t res[5];
        bases_t n = sshelp_union_bases(a, 3, b, 2, res, NULL, NULL);
        static const bases_t expected[4] = {1, 2, 4, 6};

        check(n == 4 && memcmp(res, expected, sizeof(expected)) == 0,
            "union with NULL pos_a/pos_b still computes the union");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_union_bases_large_labels(void){

    bases_t a1[2] = {65533, 65535};
    bases_t b1[2] = {65534, 65535};
    bases_t res1[4], pos_a1[2], pos_b1[2];
    bases_t n1;
    static const bases_t expected1[3] = {65533, 65534, 65535};

    bases_t a2[2] = {65533, 65534};
    bases_t b2[1] = {65535};
    bases_t res2[3], pos_a2[2], pos_b2[1];
    bases_t n2;
    static const bases_t expected2[3] = {65533, 65534, 65535};

    n1 = sshelp_union_bases(a1, 2, b1, 2, res1, pos_a1, pos_b1);
    check(n1 == 3 && memcmp(res1, expected1, sizeof(expected1)) == 0,
        "union near 65535: content");
    check(pos_a1[0] == 0 && pos_a1[1] == 2, "union near 65535: pos_a");
    check(pos_b1[0] == 1 && pos_b1[1] == 2, "union near 65535: pos_b");
    check(!sshelp_is_leading(pos_a1, 2), "union near 65535: a is not leading");

    n2 = sshelp_union_bases(a2, 2, b2, 1, res2, pos_a2, pos_b2);
    check(n2 == 3 && memcmp(res2, expected2, sizeof(expected2)) == 0,
        "union near 65535 (leading case): content");
    check(pos_a2[0] == 0 && pos_a2[1] == 1, "union near 65535 (leading case): pos_a");
    check(sshelp_is_leading(pos_a2, 2), "union near 65535 (leading case): a is leading");

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ------------------     PART 3: enumeration (next_dir / rank / unrank / local_dirs)     ----------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_enumeration(void){

    bases_t k;
    ord_t p;

    for (k = 1; k <= 4; k++){

        for (p = 1; p <= 5; p++){

            sshelp_rank_tab_t tab;
            bases_t u[8], u_prev[8];
            bases_t* dirs;
            ndir_t ndir = sshelp_ndir_order(k, p);
            ndir_t j;
            int rc;
            char name[112];

            rc = sshelp_rank_tab_init(&tab, k, p);
            check(rc == SSHELP_OK, "rank_tab_init ok (enumeration setup)");

            dirs = (bases_t*)malloc((size_t)ndir * p * sizeof(bases_t));
            sshelp_local_dirs(k, p, dirs);

            memset(u, 0, sizeof(u));

            for (j = 0; j < ndir; j++){

                bases_t u2[8];
                ord_t i;
                int nondecr = 1;

                for (i = 1; i < p; i++){
                    if (u[i - 1] > u[i]){
                        nondecr = 0;
                    }
                }

                snprintf(name, sizeof(name), "next_dir tuple %llu nondecreasing (k=%u,p=%u)",
                    (unsigned long long)j, (unsigned)k, (unsigned)p);
                check(nondecr, name);

                snprintf(name, sizeof(name), "rank(next_dir tuple %llu) == %llu (k=%u,p=%u)",
                    (unsigned long long)j, (unsigned long long)j, (unsigned)k, (unsigned)p);
                check(sshelp_rank(u, p, &tab) == j, name);

                sshelp_unrank(j, p, u2);
                snprintf(name, sizeof(name), "unrank(%llu) == next_dir tuple (k=%u,p=%u)",
                    (unsigned long long)j, (unsigned)k, (unsigned)p);
                check(memcmp(u, u2, (size_t)p * sizeof(bases_t)) == 0, name);

                snprintf(name, sizeof(name), "local_dirs row %llu matches next_dir (k=%u,p=%u)",
                    (unsigned long long)j, (unsigned)k, (unsigned)p);
                check(memcmp(u, &dirs[(size_t)j * p], (size_t)p * sizeof(bases_t)) == 0, name);

                memcpy(u_prev, u, sizeof(u));
                rc = sshelp_next_dir(u, p, k);

                if (j + 1 < ndir){
                    snprintf(name, sizeof(name), "next_dir advances at step %llu (k=%u,p=%u)",
                        (unsigned long long)j, (unsigned)k, (unsigned)p);
                    check(rc == 1, name);
                } else {
                    snprintf(name, sizeof(name), "next_dir stops at the last tuple (k=%u,p=%u)",
                        (unsigned)k, (unsigned)p);
                    check(rc == 0 && memcmp(u, u_prev, sizeof(u)) == 0, name);
                }

            }

            free(dirs);
            sshelp_rank_tab_free(&tab);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ------------------------------     PART 4: local <-> global round trips     ---------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Every active set S subset of {1..6} with |S| <= 4, every direction up to order 5: local_to_global
 * / global_to_local round trip, cross-checked against dhelp's own dhelp_get_idx_ord ranking. */
static void test_local_global(dhelpl_t dhl){

    unsigned mask;

    for (mask = 0; mask < (1u << UNIV_N); mask++){

        bases_t bases[UNIV_N];
        bases_t k = mask_to_bases(mask, bases);
        ord_t p;

        if (k > 4){
            continue;
        }

        for (p = 1; p <= 5; p++){

            ndir_t ndir = sshelp_ndir_order(k, p);
            ndir_t idx;
            char name[112];

            for (idx = 0; idx < ndir; idx++){

                bases_t u[8], g[8];
                ord_t i;
                imdir_t gidx, ref_idx;
                ord_t ref_ord;
                ndir_t lidx2;
                int rc;

                sshelp_unrank(idx, p, u);

                for (i = 0; i < p; i++){
                    g[i] = bases[u[i]];
                }

                dhelp_get_idx_ord(g, p, &ref_idx, &ref_ord, dhl);

                rc = sshelp_local_to_global(idx, p, bases, k, &gidx);
                snprintf(name, sizeof(name), "local_to_global(idx=%llu,p=%u,mask=%u) OK",
                    (unsigned long long)idx, (unsigned)p, mask);
                check(rc == SSHELP_OK, name);

                snprintf(name, sizeof(name),
                    "local_to_global(idx=%llu,p=%u,mask=%u) vs dhelp_get_idx_ord",
                    (unsigned long long)idx, (unsigned)p, mask);
                check(ref_ord == p && gidx == ref_idx, name);

                rc = sshelp_global_to_local(gidx, p, bases, k, &lidx2);
                snprintf(name, sizeof(name), "global_to_local round trip (idx=%llu,p=%u,mask=%u)",
                    (unsigned long long)idx, (unsigned)p, mask);
                check(rc == 1 && lidx2 == idx, name);

            }

        }

        if (k > 0 && k < UNIV_N){

            bases_t missing = 0, b;
            ndir_t dummy;
            int rc;

            for (b = 1; b <= UNIV_N; b++){

                int in_set = 0;
                bases_t ii;

                for (ii = 0; ii < k; ii++){
                    if (bases[ii] == b){
                        in_set = 1;
                    }
                }

                if (!in_set){
                    missing = b;
                    break;
                }

            }

            rc = sshelp_global_to_local((imdir_t)(missing - 1), 1, bases, k, &dummy);
            check(rc == 0, "global_to_local returns 0 for a base outside the active set");

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Direct closed-form reference for the colex rank formula, only for b in {1,2,3}: exact in 64 bits
 * even for labels up to 65535, independent of both sshelp_comb and the Pascal triangle above. */
static uint64_t small_b_comb(uint64_t a, uint64_t b){

    if (b == 1){
        return a;
    }

    if (b == 2){
        return a * (a - 1) / 2;
    }

    return a * (a - 1) * (a - 2) / 6;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static imdir_t reference_global_rank(const bases_t* g, ord_t p){

    uint64_t r = 0;
    ord_t i;

    for (i = 0; i < p; i++){
        r += small_b_comb((uint64_t)g[i] - 1 + i, (uint64_t)i + 1);
    }

    return (imdir_t)r;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* sshelp_global_rank / sshelp_global_unrank at labels up to 65535, orders 1..3 (dhelp's own tables
 * do not reach these labels, so the reference here is the closed-form small_b_comb sum instead). */
static void test_global_rank_large_labels(void){

    static const bases_t order1[3][1] = {{1}, {32768}, {65535}};
    static const bases_t order2[3][2] = {{1, 65535}, {65535, 65535}, {32768, 65535}};
    static const bases_t order3[2][3] = {{1, 2, 65535}, {65533, 65534, 65535}};
    size_t i;
    char name[96];

    for (i = 0; i < 3; i++){

        bases_t g2[1];
        imdir_t idx = sshelp_global_rank(order1[i], 1);
        int rc;

        snprintf(name, sizeof(name), "global_rank order1 label %u vs closed form",
            (unsigned)order1[i][0]);
        check(idx == reference_global_rank(order1[i], 1), name);

        rc = sshelp_global_unrank(idx, 1, g2);
        snprintf(name, sizeof(name), "global_unrank round trip order1 label %u",
            (unsigned)order1[i][0]);
        check(rc == SSHELP_OK && g2[0] == order1[i][0], name);

    }

    for (i = 0; i < 3; i++){

        bases_t g2[2];
        imdir_t idx = sshelp_global_rank(order2[i], 2);
        int rc;

        snprintf(name, sizeof(name), "global_rank order2 (%u,%u) vs closed form",
            (unsigned)order2[i][0], (unsigned)order2[i][1]);
        check(idx == reference_global_rank(order2[i], 2), name);

        rc = sshelp_global_unrank(idx, 2, g2);
        snprintf(name, sizeof(name), "global_unrank round trip order2 (%u,%u)",
            (unsigned)order2[i][0], (unsigned)order2[i][1]);
        check(rc == SSHELP_OK && memcmp(g2, order2[i], sizeof(g2)) == 0, name);

    }

    for (i = 0; i < 2; i++){

        bases_t g2[3];
        imdir_t idx = sshelp_global_rank(order3[i], 3);
        int rc;

        snprintf(name, sizeof(name), "global_rank order3 (%u,%u,%u) vs closed form",
            (unsigned)order3[i][0], (unsigned)order3[i][1], (unsigned)order3[i][2]);
        check(idx == reference_global_rank(order3[i], 3), name);

        rc = sshelp_global_unrank(idx, 3, g2);
        snprintf(name, sizeof(name), "global_unrank round trip order3 (%u,%u,%u)",
            (unsigned)order3[i][0], (unsigned)order3[i][1], (unsigned)order3[i][2]);
        check(rc == SSHELP_OK && memcmp(g2, order3[i], sizeof(g2)) == 0, name);

    }

    {
        bases_t g2[1];
        int rc = sshelp_global_unrank(65535, 1, g2);
        check(rc == SSHELP_ERR_RANGE, "global_unrank(idx=65535,p=1) needs label>65535: ERR_RANGE");
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -----------------------------------     PART 5: remap vs rank     -------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Every pair (S_src subset of S_dst subset of {1..6}), orders 1..5: sshelp_remap_order[j] must
 * equal the local index in S_dst of the source direction j, obtained independently by round
 * tripping through local_to_global (in S_src) and global_to_local (in S_dst). */
static void test_remap_vs_rank(void){

    unsigned dst_mask;

    for (dst_mask = 0; dst_mask < (1u << UNIV_N); dst_mask++){

        bases_t bases_dst[UNIV_N];
        bases_t k_dst = mask_to_bases(dst_mask, bases_dst);
        unsigned src_mask = dst_mask;

        for (;;){

            bases_t bases_src[UNIV_N];
            bases_t k_src = mask_to_bases(src_mask, bases_src);
            bases_t union_out[UNIV_N], pos[UNIV_N];
            bases_t n_union;
            ord_t p;
            char name[128];

            n_union = sshelp_union_bases(bases_src, k_src, bases_dst, k_dst, union_out, pos,
                NULL);

            snprintf(name, sizeof(name), "remap setup (src=%u,dst=%u): union == dst", src_mask,
                dst_mask);
            check(n_union == k_dst
                && memcmp(union_out, bases_dst, (size_t)k_dst * sizeof(bases_t)) == 0, name);

            for (p = 1; p <= 5; p++){

                ndir_t ndir_src = sshelp_ndir_order(k_src, p);
                sshelp_rank_tab_t tab_dst;
                ndir_t* map;
                bases_t u_scratch[8];
                ndir_t j;

                if (ndir_src == 0){
                    continue;
                }

                sshelp_rank_tab_init(&tab_dst, k_dst, p);
                map = (ndir_t*)malloc((size_t)ndir_src * sizeof(ndir_t));
                sshelp_remap_order(k_src, pos, p, &tab_dst, map, u_scratch);

                for (j = 0; j < ndir_src; j++){

                    imdir_t gidx;
                    ndir_t expected;
                    int rc;

                    sshelp_local_to_global(j, p, bases_src, k_src, &gidx);
                    rc = sshelp_global_to_local(gidx, p, bases_dst, k_dst, &expected);

                    snprintf(name, sizeof(name),
                        "remap_order(src=%u,dst=%u,p=%u)[%llu] vs local/global round trip",
                        src_mask, dst_mask, (unsigned)p, (unsigned long long)j);
                    check(rc == 1 && map[j] == expected, name);

                }

                free(map);
                sshelp_rank_tab_free(&tab_dst);

            }

            if (src_mask == 0){
                break;
            }

            src_mask = (src_mask - 1) & dst_mask;

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -----------------------------     PART 6: table sub-block vs precompute     ---------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Local index i (0-based, base set {0..k-1}) to a 1-based global tuple {1..k}, for dhelp_precompute
 * _multiply, which expects 1-based labels. */
static void unrank_to_1based(ndir_t idx, ord_t p, bases_t* out){

    ord_t i;

    sshelp_unrank(idx, p, out);

    for (i = 0; i < p; i++){
        out[i] = (bases_t)(out[i] + 1);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Merge + rank via sshelp_comb directly (not the tested sshelp_prod_rank / table), for use where
 * dhelp_precompute_multiply cannot be called (k beyond that order's Nbasis would read out of
 * range). ui/uj are 0-based local tuples, as sshelp_prod_rank itself takes. */
static ndir_t naive_merge_comb_rank(const bases_t* ui, ord_t p, const bases_t* uj, ord_t q){

    bases_t merged[16];
    ord_t a = 0, b = 0, i;
    uint64_t r = 0;

    for (i = 0; a < p || b < q; i++){

        bases_t v;

        if (b == q || (a < p && ui[a] <= uj[b])){
            v = ui[a++];
        } else {
            v = uj[b++];
        }

        merged[i] = v;

    }

    for (i = 0; i < (ord_t)(p + q); i++){
        r += sshelp_comb((uint64_t)merged[i] + i, (uint64_t)i + 1);
    }

    return (ndir_t)r;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* k <= Nbasis(p+q): pair.p_tab must be non-NULL, and every local product must agree with both
 * dhelp_precompute_multiply (on 1-based tuples over the same k) and sshelp_prod_rank. */
static void check_pair_table(bases_t k, ord_t p, ord_t q, dhelpl_t dhl){

    sshelp_pair_t pair = sshelp_get_pair(k, p, q, dhl);
    sshelp_rank_tab_t tab;
    ndir_t np = sshelp_ndir_order(k, p);
    ndir_t nq = sshelp_ndir_order(k, q);
    ndir_t i, j, n_mismatch = 0;
    const uint64_t max_reported = 5;
    char name[128];

    snprintf(name, sizeof(name), "get_pair(k=%u,p=%u,q=%u) has a table", (unsigned)k,
        (unsigned)p, (unsigned)q);
    check(pair.p_tab != NULL, name);

    if (pair.p_tab == NULL){
        return;
    }

    sshelp_rank_tab_init(&tab, k, (ord_t)(p + q));

    for (i = 0; i < np; i++){

        bases_t ui0[16], ui1[16];

        sshelp_unrank(i, p, ui0);
        unrank_to_1based(i, p, ui1);

        for (j = 0; j < nq; j++){

            bases_t uj0[16], uj1[16];
            ndir_t a1, a3;
            imdir_t a2;

            sshelp_unrank(j, q, uj0);
            unrank_to_1based(j, q, uj1);

            a1 = sshelp_pair_idx(&pair, i, j);
            a2 = dhelp_precompute_multiply(ui1, p, uj1, q, dhl);
            a3 = sshelp_prod_rank(ui0, p, uj0, q, &tab);

            if (a1 != (ndir_t)a2 || a1 != a3){

                if (n_mismatch < max_reported){
                    fprintf(stderr,
                        "  mismatch pair(k=%u,p=%u,q=%u)[i=%llu,j=%llu]: pair_idx=%llu, "
                        "precompute_multiply=%llu, prod_rank=%llu\n", (unsigned)k, (unsigned)p,
                        (unsigned)q, (unsigned long long)i, (unsigned long long)j,
                        (unsigned long long)a1, (unsigned long long)a2, (unsigned long long)a3);
                }
                n_mismatch++;

            }

        }

    }

    snprintf(name, sizeof(name), "get_pair(k=%u,p=%u,q=%u): %llu/%llu entries match",
        (unsigned)k, (unsigned)p, (unsigned)q, (unsigned long long)(np * nq - n_mismatch),
        (unsigned long long)(np * nq));
    check(n_mismatch == 0, name);

    sshelp_rank_tab_free(&tab);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* sshelp_prod_rank (the rank method that both the per-call fallback and the cache builder in PART 8
 * use) must agree with a from-scratch merge ranked through sshelp_comb, since
 * dhelp_precompute_multiply would read out of its own tables' range for a k this large. Independent
 * of sshelp_get_pair()/caching: this checks sshelp_prod_rank() itself. */
static void check_prod_rank_vs_naive(bases_t k, ord_t p, ord_t q){

    sshelp_rank_tab_t tab;
    ndir_t np = sshelp_ndir_order(k, p);
    ndir_t nq = sshelp_ndir_order(k, q);
    ndir_t i, j, n_mismatch = 0;
    const uint64_t max_reported = 5;
    char name[128];

    sshelp_rank_tab_init(&tab, k, (ord_t)(p + q));

    for (i = 0; i < np; i++){

        bases_t ui[16];
        sshelp_unrank(i, p, ui);

        for (j = 0; j < nq; j++){

            bases_t uj[16];
            ndir_t a3, a_ref;

            sshelp_unrank(j, q, uj);

            a3 = sshelp_prod_rank(ui, p, uj, q, &tab);
            a_ref = naive_merge_comb_rank(ui, p, uj, q);

            if (a3 != a_ref){

                if (n_mismatch < max_reported){
                    fprintf(stderr,
                        "  mismatch prod_rank(k=%u,p=%u,q=%u)[i=%llu,j=%llu]: got %llu, "
                        "expected %llu\n", (unsigned)k, (unsigned)p, (unsigned)q,
                        (unsigned long long)i, (unsigned long long)j, (unsigned long long)a3,
                        (unsigned long long)a_ref);
                }
                n_mismatch++;

            }

        }

    }

    snprintf(name, sizeof(name), "prod_rank fallback (k=%u,p=%u,q=%u): %llu/%llu entries match",
        (unsigned)k, (unsigned)p, (unsigned)q, (unsigned long long)(np * nq - n_mismatch),
        (unsigned long long)(np * nq));
    check(n_mismatch == 0, name);

    sshelp_rank_tab_free(&tab);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_pair_tables(dhelpl_t dhl){

    bases_t k;
    ord_t p, q;

    for (k = 1; k <= 4; k++){

        for (p = 1; p <= 4; p++){

            for (q = 1; q <= 4; q++){

                if (p + q > 5){
                    continue;
                }

                check_pair_table(k, p, q, dhl);

            }

        }

    }

    {
        static const struct { ord_t p, q; } combos[4] = {
            {5, 5}, {4, 6}, {1, 9}, {3, 7}
        };
        size_t c;

        for (c = 0; c < 4; c++){
            for (k = 1; k <= 4; k++){
                check_pair_table(k, combos[c].p, combos[c].q, dhl);
            }
        }

    }

    {
        static const struct { ord_t p, q; } combos5[2] = { {2, 3}, {1, 4} };
        static const struct { ord_t p, q; } combos6[3] = { {3, 3}, {2, 4}, {1, 5} };
        size_t c;

        for (c = 0; c < 2; c++){
            check_pair_table(10, combos5[c].p, combos5[c].q, dhl);
        }

        for (c = 0; c < 3; c++){
            check_pair_table(10, combos6[c].p, combos6[c].q, dhl);
        }

    }

    // (11, 2, 3) and (101, 1, 2) used to be check_pair_null_table() cases (pair.p_tab == NULL,
    // rank fallback only). Since the local product-table cache (PART 8 below) was added,
    // sshelp_get_pair() now lazily builds and caches a table for both -- they're well within its
    // default budget -- so pair.p_tab is no longer NULL there. check_pair_cached_table() in PART 8
    // covers them instead (built table == sshelp_prod_rank), and test_cache_budget_exceeded() (PART
    // 8) covers a k too large for the cache's budget, without an O(np*nq) exhaustive loop.
    //
    // sshelp_prod_rank() itself (independent of sshelp_get_pair()/caching) is still checked here.
    check_prod_rank_vs_naive(11, 2, 3);
    check_prod_rank_vs_naive(101, 1, 2);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     PART 7: workspace     -------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_workspace(void){

    sshelp_ws_t ws = sshelp_ws_init();
    int rc;

    check(ws.p_coef == NULL && ws.p_map == NULL && ws.p_bases == NULL, "ws_init: NULL buffers");
    check(ws.ncoef == 0 && ws.nmap == 0 && ws.nbases == 0, "ws_init: zero capacities");

    rc = sshelp_ws_reserve(&ws, 10, 20, 30);
    check(rc == SSHELP_OK, "ws_reserve: grow from empty OK");
    check(ws.p_coef != NULL && ws.p_map != NULL && ws.p_bases != NULL,
        "ws_reserve: grow from empty allocates buffers");
    check(ws.ncoef == 10 && ws.nmap == 20 && ws.nbases == 30,
        "ws_reserve: grow from empty sets capacities");

    rc = sshelp_ws_reserve(&ws, 5, 5, 5);
    check(rc == SSHELP_OK, "ws_reserve: smaller request OK");
    check(ws.ncoef == 10 && ws.nmap == 20 && ws.nbases == 30,
        "ws_reserve: smaller request keeps prior capacities");

    rc = sshelp_ws_reserve(&ws, 50, 60, 70);
    check(rc == SSHELP_OK, "ws_reserve: grow again OK");
    check(ws.ncoef == 50 && ws.nmap == 60 && ws.nbases == 70,
        "ws_reserve: grow again sets new capacities");

    sshelp_ws_free(&ws);
    check(ws.p_coef == NULL && ws.p_map == NULL && ws.p_bases == NULL,
        "ws_free: resets buffers to NULL");
    check(ws.ncoef == 0 && ws.nmap == 0 && ws.nbases == 0, "ws_free: resets capacities to zero");

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ------------------------     PART 8: LOCAL PRODUCT-TABLE CACHE (step 6)     ---------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* k genuinely beyond Nbasis(p+q) (dhelp_default_nbasis()) and within the cache's default budget:
 * pair.p_tab must now be a lazily built, cached table (not NULL), every served entry -- both ways
 * round, i.e. also via the (q, p) call -- must match an independently built sshelp_prod_rank
 * reference, and (q, p) must share the exact same pointer as (p, q) (one table serves both, via
 * `transpose`). */
static void check_pair_cached_table(bases_t k, ord_t p, ord_t q, dhelpl_t dhl){

    sshelp_pair_t pair = sshelp_get_pair(k, p, q, dhl);
    sshelp_pair_t pair_swapped = sshelp_get_pair(k, q, p, dhl);
    sshelp_rank_tab_t tab;
    ndir_t np = sshelp_ndir_order(k, p);
    ndir_t nq = sshelp_ndir_order(k, q);
    ndir_t i, j, n_mismatch = 0;
    const uint64_t max_reported = 5;
    char name[160];

    snprintf(name, sizeof(name), "get_pair(k=%u,p=%u,q=%u) cache is built (beyond Nbasis(%u)=%u)",
        (unsigned)k, (unsigned)p, (unsigned)q, (unsigned)(p + q),
        (unsigned)dhelp_default_nbasis((ord_t)(p + q)));
    check(pair.p_tab != NULL, name);

    if (pair.p_tab == NULL){
        return;
    }

    snprintf(name, sizeof(name), "get_pair(k=%u,p=%u,q=%u): swapped order shares the same table",
        (unsigned)k, (unsigned)p, (unsigned)q);
    check(pair_swapped.p_tab == pair.p_tab, name);

    sshelp_rank_tab_init(&tab, k, (ord_t)(p + q));

    for (i = 0; i < np; i++){

        bases_t ui[16];
        sshelp_unrank(i, p, ui);

        for (j = 0; j < nq; j++){

            bases_t uj[16];
            ndir_t a1, a2, a3;

            sshelp_unrank(j, q, uj);

            a1 = sshelp_pair_idx(&pair, i, j);
            a2 = sshelp_pair_idx(&pair_swapped, j, i);
            a3 = sshelp_prod_rank(ui, p, uj, q, &tab);

            if (a1 != a3 || a2 != a3){

                if (n_mismatch < max_reported){
                    fprintf(stderr,
                        "  mismatch cached pair(k=%u,p=%u,q=%u)[i=%llu,j=%llu]: pair_idx=%llu, "
                        "swapped_idx=%llu, prod_rank=%llu\n", (unsigned)k, (unsigned)p, (unsigned)q,
                        (unsigned long long)i, (unsigned long long)j, (unsigned long long)a1,
                        (unsigned long long)a2, (unsigned long long)a3);
                }
                n_mismatch++;

            }

        }

    }

    snprintf(name, sizeof(name), "cached pair(k=%u,p=%u,q=%u): %llu/%llu entries match prod_rank",
        (unsigned)k, (unsigned)p, (unsigned)q, (unsigned long long)(np * nq - n_mismatch),
        (unsigned long long)(np * nq));
    check(n_mismatch == 0, name);

    sshelp_rank_tab_free(&tab);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* One combo per order (2..5) that genuinely exceeds Nbasis(order): Nbasis is 1000 (order 2), 100
 * (order 3 and 4) and 10 (order 5) -- k = 12..15 from the original task description stays within
 * Nbasis(<=4) = 100, so it would hit the *global* table, not this cache; k = 101/1001 are the
 * smallest round numbers that actually cross each threshold, which is what these combos test.
 *
 * Sizes are kept well under the cache's default 256 MiB *total* budget, cumulatively: (101, 1, 3)
 * alone is already ~136 MiB (N_3(101) = C(103,3) = 176851), so (101, 2, 2) (~202 MiB, which would
 * push the running total over budget) is deliberately left out -- one order-4 combo is enough to
 * exercise that order, and test_cache_budget_exceeded() below covers the "actually over budget"
 * case on its own terms. */
static void test_cache_within_budget(dhelpl_t dhl){

    check_pair_cached_table(1001, 1, 1, dhl); // order 2, Nbasis(2) = 1000. (~7.6 MiB)
    check_pair_cached_table( 101, 1, 2, dhl); // order 3, Nbasis(3) = 100.  (~4.0 MiB)
    check_pair_cached_table( 101, 1, 3, dhl); // order 4, Nbasis(4) = 100.  (~136 MiB)
    check_pair_cached_table(  11, 1, 4, dhl); // order 5, Nbasis(5) = 10 (the measured case).
    check_pair_cached_table(  11, 2, 3, dhl); // order 5, Nbasis(5) = 10 (the measured case).

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_cache_repeated_pointer(dhelpl_t dhl){

    sshelp_pair_t first  = sshelp_get_pair(101, 1, 3, dhl);
    sshelp_pair_t second = sshelp_get_pair(101, 1, 3, dhl);

    check(first.p_tab != NULL && first.p_tab == second.p_tab,
        "get_pair(k=101,p=1,q=3): repeated calls return the same cached pointer");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* A (k, p, q) not touched by any earlier test: many OpenMP threads race to build it at once. Every
 * thread must observe the same pointer, and the table it points to must be correct -- like
 * tests/c/test_dhelp.c:test_parallel_first_touch, for dhelp_get_multtabl(). Kept small (~4 MiB,
 * order 3 rather than 4) so it stays comfortably within budget on top of test_cache_within_budget's
 * own ~148 MiB, without needing to assume anything about test execution order. */
static void test_cache_parallel_first_build(dhelpl_t dhl){

    bases_t k = 102;
    ord_t p = 1, q = 2;
    const imdir_t* ptrs[CACHE_MAX_THREADS];
    ndir_t stride = 0;
    ndir_t np = sshelp_ndir_order(k, p), nq = sshelp_ndir_order(k, q);
    ndir_t i, j, n_mismatch = 0;
    sshelp_rank_tab_t tab;
    int nt = 1, t;
    int same = 1;

    #ifdef _OPENMP
    nt = omp_get_max_threads();
    if (nt > CACHE_MAX_THREADS){
        nt = CACHE_MAX_THREADS;
    }
    if (nt < 2){
        nt = 2;
    }
    #endif

    #pragma omp parallel num_threads(nt)
    {
        int tid = 0;
        sshelp_pair_t pair;

        #ifdef _OPENMP
        tid = omp_get_thread_num();
        #endif

        pair = sshelp_get_pair(k, p, q, dhl);
        ptrs[tid] = pair.p_tab;

        if (tid == 0){
            stride = pair.stride;
        }

    }

    for (t = 1; t < nt; t++){

        if (ptrs[t] != ptrs[0]){
            same = 0;
        }

    }

    check(same && ptrs[0] != NULL,
        "cache parallel first build: every thread sees the same built table");

    if (ptrs[0] == NULL){
        return;
    }

    sshelp_rank_tab_init(&tab, k, (ord_t)(p + q));

    for (i = 0; i < np; i++){

        bases_t ui[16];
        sshelp_unrank(i, p, ui);

        for (j = 0; j < nq; j++){

            bases_t uj[16];
            ndir_t got = ptrs[0][i * stride + j];
            ndir_t exp;

            sshelp_unrank(j, q, uj);
            exp = sshelp_prod_rank(ui, p, uj, q, &tab);

            if (got != exp){

                if (n_mismatch < 5){
                    fprintf(stderr,
                        "  mismatch cache-parallel(k=%u,p=%u,q=%u)[i=%llu,j=%llu]: got %llu, "
                        "expected %llu\n", (unsigned)k, (unsigned)p, (unsigned)q,
                        (unsigned long long)i, (unsigned long long)j, (unsigned long long)got,
                        (unsigned long long)exp);
                }
                n_mismatch++;

            }

        }

    }

    check(n_mismatch == 0, "cache parallel first build: table matches prod_rank after concurrent build");

    sshelp_rank_tab_free(&tab);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Far beyond the cache's default 256 MiB budget (SSHELP_CACHE_DEFAULT_MB): must stay a rank
 * fallback (p_tab == NULL) rather than attempting a many-GB allocation. No exhaustive loop here --
 * np*nq is itself in the billions, by design. */
static void test_cache_budget_exceeded(dhelpl_t dhl){

    sshelp_pair_t pair = sshelp_get_pair(300, 2, 2, dhl);

    check(pair.p_tab == NULL,
        "get_pair(k=300,p=2,q=2): far over the cache budget, stays NULL (rank fallback)");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    dhelp_load(NULL, &dhl);
    build_pascal();

    test_comb_vs_pascal();
    test_ndir_counts();
    test_ndir_total_checked();

    test_union_bases();
    test_union_bases_large_labels();

    test_enumeration();

    test_local_global(dhl);
    test_global_rank_large_labels();

    test_remap_vs_rank();

    test_pair_tables(dhl);

    test_workspace();

    test_cache_within_budget(dhl);
    test_cache_repeated_pointer(dhl);
    test_cache_parallel_first_build(dhl);
    test_cache_budget_exceeded(dhl);

    dhelp_free(&dhl);

    if (n_failed != 0){
        fprintf(stderr, "%d semisparse core test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C semisparse core tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
