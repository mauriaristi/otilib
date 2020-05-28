# Include definition of basis functions
# Point element.
include "basis_functions/point1_iso.pxi"

# Line element.
include "basis_functions/line1_iso.pxi"
include "basis_functions/line2_iso.pxi"
include "basis_functions/line3_iso.pxi"

# Triangle element.
include "basis_functions/tri1_iso.pxi"
include "basis_functions/tri3_iso.pxi"
include "basis_functions/tri4_iso.pxi"
include "basis_functions/tri6_iso.pxi"

# Quad element.
include "basis_functions/quad1_iso.pxi"
include "basis_functions/quad4_iso.pxi"
include "basis_functions/quad8_iso.pxi"
include "basis_functions/quad9_iso.pxi"

# Tetrahedron element.
include "basis_functions/tet1_iso.pxi"
include "basis_functions/tet4_iso.pxi"

# Brick element (Hexahedron).
include "basis_functions/hex1_iso.pxi"
include "basis_functions/hex8_iso.pxi"
include "basis_functions/hex20_iso.pxi"