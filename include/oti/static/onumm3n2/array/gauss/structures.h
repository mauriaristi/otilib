#ifndef OTI_ONUMM3N2_ARRAY_GAUSS_STRUCTURES_H
#define OTI_ONUMM3N2_ARRAY_GAUSS_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    oarrm3n2_t*      p_data; ///< Data array
    uint64_t      nrows;  ///< Number of rows.
    uint64_t      ncols;  ///< Number of cols.
    uint64_t       size;  ///< size of the array
    uint64_t        nip;  ///< Number of integration points.
} feoarrm3n2_t;

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
OTI_STATIC_LAYOUT_ASSERT(sizeof(feoarrm3n2_t) == sizeof(oarrm3n2_t*) + 4 * sizeof(uint64_t),
                         "feoarrm3n2_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm3n2_t, p_data) == 0, "feoarrm3n2_t.p_data offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm3n2_t, nrows) == sizeof(oarrm3n2_t*) + 0 * sizeof(uint64_t),
                         "feoarrm3n2_t.nrows offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm3n2_t, ncols) == sizeof(oarrm3n2_t*) + 1 * sizeof(uint64_t),
                         "feoarrm3n2_t.ncols offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm3n2_t, size) == sizeof(oarrm3n2_t*) + 2 * sizeof(uint64_t),
                         "feoarrm3n2_t.size offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feoarrm3n2_t, nip) == sizeof(oarrm3n2_t*) + 3 * sizeof(uint64_t),
                         "feoarrm3n2_t.nip offset");
// END LAYOUT ASSERTS

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif