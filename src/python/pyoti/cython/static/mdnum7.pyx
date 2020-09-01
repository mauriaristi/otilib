

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "mdnum7/include.pxi"

#      SCALAR.
# Base functions.
include "mdnum7/scalar/base.pxi"

# Utilities.
include "mdnum7/scalar/utils.pxi"

# Math functions.
include "mdnum7/scalar/math.pxi"

# Gauss array
include "mdnum7/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "mdnum7/array/base.pxi"

# Math operations.
include "mdnum7/array/math.pxi"

include "mdnum7/array/math_to.pxi"

# Utilities.
include "mdnum7/array/utils.pxi"

# Gauss capabilities.
include "mdnum7/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "mdnum7/generic.pxi"

#     mdnum7 ARRAY
# Append base class.
include "mdnum7/sprarray/lil/base.pxi"

include "mdnum7/sprarray/csr/base.pxi"

include "mdnum7/sprarray/csc/base.pxi"

# Common functions.
include "mdnum7/creators.pxi"

include "mdnum7/utils.pxi"

include "mdnum7/math.pxi"

include "mdnum7/linalg.pxi"

include "mdnum7/algebra.pxi"

# FEM helper
include "mdnum7/fem/base.pxi"
