
# Append directives
include "common/directives.pxi"

# Append included libraries
include "fem/include.pxi"

# Utils
include "fem/utils.pxi"

# Append Element functions.
include "fem/elbase.pxi"

# Append Real FEM array.
include "fem/gauss_array.pxi"

# Include Mesh.
include "fem/mesh.pxi"

# # FE functions.
include "fem/space.pxi"

include "fem/elemental_operation.pxi"


# include "fem/feproblem.pxi" 






# # Append Gauss capabilities.
# include "fem/gauss.pxi"
