#ifndef OTI_ONUMM1N10_ARRAY_GAUSS_STRUCTURES_H
#define OTI_ONUMM1N10_ARRAY_GAUSS_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    oarrm1n10_t*      p_data; ///< Data array
    uint64_t      nrows;  ///< Number of rows.
    uint64_t      ncols;  ///< Number of cols.
    uint64_t       size;  ///< size of the array
    uint64_t        nip;  ///< Number of integration points.
} feoarrm1n10_t;

// Layout checks (generated): no padding.
// BEGIN LAYOUT ASSERTS
#include <stddef.h>
#ifndef OTI_STATIC_LAYOUT_ASSERT
#if defined(__cplusplus)
#define OTI_STATIC_LAYOUT_ASSERT(c, m) static_assert(c, m)
#else
#define OTI_STATIC_LAYOUT_ASSERT(c, m) _Static_assert(c, m)
#endif
#endif
OTI_STATIC_LAYOUT_ASSERT(sizeof(feoarrm1n10_t) == sizeof(oarrm1n10_t*) + 4 * sizeof(uint64_t),
                         "feoarrm1n10_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm1n10_t, p_data) == 0, "feoarrm1n10_t.p_data offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm1n10_t, nrows) == sizeof(oarrm1n10_t*) + 0 * sizeof(uint64_t),
                         "feoarrm1n10_t.nrows offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm1n10_t, ncols) == sizeof(oarrm1n10_t*) + 1 * sizeof(uint64_t),
                         "feoarrm1n10_t.ncols offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm1n10_t, size) == sizeof(oarrm1n10_t*) + 2 * sizeof(uint64_t),
                         "feoarrm1n10_t.size offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm1n10_t, nip) == sizeof(oarrm1n10_t*) + 3 * sizeof(uint64_t),
                         "feoarrm1n10_t.nip offset");
// END LAYOUT ASSERTS

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif