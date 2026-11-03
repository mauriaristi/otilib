#ifndef OTI_ONUMM1N3_SCALAR_GAUSS_STRUCTURES_H
#define OTI_ONUMM1N3_SCALAR_GAUSS_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    onumm1n3_t*  p_data;   ///< Data array
    uint64_t    nip;      ///< Number of integration points.
} feonumm1n3_t;

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
OTI_STATIC_LAYOUT_ASSERT(sizeof(feonumm1n3_t) == sizeof(onumm1n3_t*) + 1 * sizeof(uint64_t),
                         "feonumm1n3_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feonumm1n3_t, p_data) == 0, "feonumm1n3_t.p_data offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feonumm1n3_t, nip) == sizeof(onumm1n3_t*) + 0 * sizeof(uint64_t),
                         "feonumm1n3_t.nip offset");
// END LAYOUT ASSERTS

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif