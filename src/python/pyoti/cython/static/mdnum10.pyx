

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "mdnum10/include.pxi"

#      SCALAR.
# Base functions.
include "mdnum10/scalar/base.pxi"

# Utilities.
include "mdnum10/scalar/utils.pxi"

# Math functions.
include "mdnum10/scalar/math.pxi"

# Gauss array
include "mdnum10/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "mdnum10/array/base.pxi"

# Math operations.
include "mdnum10/array/math.pxi"

include "mdnum10/array/math_to.pxi"

# Utilities.
include "mdnum10/array/utils.pxi"

# Gauss capabilities.
include "mdnum10/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "mdnum10/generic.pxi"

#     mdnum10 ARRAY
# Append base class.
include "mdnum10/sprarray/lil/base.pxi"

include "mdnum10/sprarray/csr/base.pxi"

include "mdnum10/sprarray/csc/base.pxi"

# Common functions.
include "mdnum10/creators.pxi"

include "mdnum10/utils.pxi"

include "mdnum10/math.pxi"

include "mdnum10/linalg.pxi"

include "mdnum10/algebra.pxi"

# FEM helper
include "mdnum10/fem/base.pxi"
