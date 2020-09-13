

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "mdnum9/include.pxi"

#      SCALAR.
# Base functions.
include "mdnum9/scalar/base.pxi"

# Utilities.
include "mdnum9/scalar/utils.pxi"

# Math functions.
include "mdnum9/scalar/math.pxi"

# Gauss array
include "mdnum9/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "mdnum9/array/base.pxi"

# Math operations.
include "mdnum9/array/math.pxi"

include "mdnum9/array/math_to.pxi"

# Utilities.
include "mdnum9/array/utils.pxi"

# Gauss capabilities.
include "mdnum9/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "mdnum9/generic.pxi"

#     mdnum9 ARRAY
# Append base class.
include "mdnum9/sprarray/lil/base.pxi"

include "mdnum9/sprarray/csr/base.pxi"

include "mdnum9/sprarray/csc/base.pxi"

# Common functions.
include "mdnum9/creators.pxi"

include "mdnum9/utils.pxi"

include "mdnum9/math.pxi"

include "mdnum9/linalg.pxi"

include "mdnum9/algebra.pxi"

# FEM helper
include "mdnum9/fem/base.pxi"
