#ifndef OTI_ONUMM1N20_SCALAR_GAUSS_STRUCTURES_H
#define OTI_ONUMM1N20_SCALAR_GAUSS_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    onumm1n20_t*  p_data;   ///< Data array
    uint64_t    nip;      ///< Number of integration points.
} feonumm1n20_t;

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
OTI_STATIC_LAYOUT_ASSERT(sizeof(feonumm1n20_t) == sizeof(onumm1n20_t*) + 1 * sizeof(uint64_t),
                         "feonumm1n20_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feonumm1n20_t, p_data) == 0, "feonumm1n20_t.p_data offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feonumm1n20_t, nip) == sizeof(onumm1n20_t*) + 0 * sizeof(uint64_t),
                         "feonumm1n20_t.nip offset");
// END LAYOUT ASSERTS

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif