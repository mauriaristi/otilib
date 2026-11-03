#ifndef OTI_ONUMM3N2_SCALAR_GAUSS_STRUCTURES_H
#define OTI_ONUMM3N2_SCALAR_GAUSS_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    onumm3n2_t*  p_data;   ///< Data array
    uint64_t    nip;      ///< Number of integration points.
} feonumm3n2_t;

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
OTI_STATIC_LAYOUT_ASSERT(sizeof(feonumm3n2_t) == sizeof(onumm3n2_t*) + 1 * sizeof(uint64_t),
                         "feonumm3n2_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feonumm3n2_t, p_data) == 0, "feonumm3n2_t.p_data offset");
OTI_STATIC_LAYOUT_ASSERT(offsetof(feonumm3n2_t, nip) == sizeof(onumm3n2_t*) + 0 * sizeof(uint64_t),
                         "feonumm3n2_t.nip offset");
// END LAYOUT ASSERTS

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif