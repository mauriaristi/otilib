#ifndef OTI_ONUMM2N3_ARRAY_GAUSS_STRUCTURES_H
#define OTI_ONUMM2N3_ARRAY_GAUSS_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    oarrm2n3_t*      p_data; ///< Data array
    uint64_t      nrows;  ///< Number of rows.
    uint64_t      ncols;  ///< Number of cols.
    uint64_t       size;  ///< size of the array
    uint64_t        nip;  ///< Number of integration points.
} feoarrm2n3_t;

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
OTI_STATIC_LAYOUT_ASSERT(sizeof(feoarrm2n3_t) == sizeof(oarrm2n3_t*) + 4 * sizeof(uint64_t),
                         "feoarrm2n3_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm2n3_t, p_data) == 0, "feoarrm2n3_t.p_data offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm2n3_t, nrows) == sizeof(oarrm2n3_t*) + 0 * sizeof(uint64_t),
                         "feoarrm2n3_t.nrows offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm2n3_t, ncols) == sizeof(oarrm2n3_t*) + 1 * sizeof(uint64_t),
                         "feoarrm2n3_t.ncols offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm2n3_t, size) == sizeof(oarrm2n3_t*) + 2 * sizeof(uint64_t),
                         "feoarrm2n3_t.size offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm2n3_t, nip) == sizeof(oarrm2n3_t*) + 3 * sizeof(uint64_t),
                         "feoarrm2n3_t.nip offset");
// END LAYOUT ASSERTS

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif