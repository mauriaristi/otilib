

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "mdnum3/include.pxi"

#      SCALAR.
# Base functions.
include "mdnum3/scalar/base.pxi"

# Utilities.
include "mdnum3/scalar/utils.pxi"

# Math functions.
include "mdnum3/scalar/math.pxi"

# Gauss array
include "mdnum3/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "mdnum3/array/base.pxi"

# Math operations.
include "mdnum3/array/math.pxi"

include "mdnum3/array/math_to.pxi"

# Utilities.
include "mdnum3/array/utils.pxi"

# Gauss capabilities.
include "mdnum3/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "mdnum3/generic.pxi"

#     mdnum3 ARRAY
# Append base class.
include "mdnum3/sprarray/lil/base.pxi"

include "mdnum3/sprarray/csr/base.pxi"

include "mdnum3/sprarray/csc/base.pxi"

# Common functions.
include "mdnum3/creators.pxi"

include "mdnum3/utils.pxi"

include "mdnum3/math.pxi"

include "mdnum3/linalg.pxi"

include "mdnum3/algebra.pxi"

# FEM helper
include "mdnum3/fem/base.pxi"
