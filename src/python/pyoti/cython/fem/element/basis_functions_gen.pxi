# Include definition of basis functions
# Point element.
include "basis_functions_gen/point1_iso.pxi"

# Line element.
include "basis_functions_gen/line1_iso.pxi"
include "basis_functions_gen/line2_iso.pxi"
include "basis_functions_gen/line3_iso.pxi"

# Triangle element.
include "basis_functions_gen/tri1_iso.pxi"
include "basis_functions_gen/tri3_iso.pxi"
include "basis_functions_gen/tri4_iso.pxi"
include "basis_functions_gen/tri6_iso.pxi"

# Quad element.
include "basis_functions_gen/quad1_iso.pxi"
include "basis_functions_gen/quad4_iso.pxi"
include "basis_functions_gen/quad8_iso.pxi"
include "basis_functions_gen/quad9_iso.pxi"

# Tetrahedron element.
include "basis_functions_gen/tet1_iso.pxi"
include "basis_functions_gen/tet4_iso.pxi"
include "basis_functions_gen/tet10_iso.pxi"

# Brick element (Hexahedron).
include "basis_functions_gen/hex1_iso.pxi"
include "basis_functions_gen/hex8_iso.pxi"
include "basis_functions_gen/hex20_iso.pxi"

# Wedge elements (prisms)
include "basis_functions_gen/wedge1_iso.pxi"
include "basis_functions_gen/wedge6_iso.pxi"
include "basis_functions_gen/wedge15_iso.pxi"
