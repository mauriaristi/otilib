

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "mdnum4/include.pxi"

#      SCALAR.
# Base functions.
include "mdnum4/scalar/base.pxi"

# Utilities.
include "mdnum4/scalar/utils.pxi"

# Math functions.
include "mdnum4/scalar/math.pxi"

# Gauss array
include "mdnum4/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "mdnum4/array/base.pxi"

# Math operations.
include "mdnum4/array/math.pxi"

include "mdnum4/array/math_to.pxi"

# Utilities.
include "mdnum4/array/utils.pxi"

# Gauss capabilities.
include "mdnum4/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "mdnum4/generic.pxi"

#     mdnum4 ARRAY
# Append base class.
include "mdnum4/sprarray/lil/base.pxi"

include "mdnum4/sprarray/csr/base.pxi"

include "mdnum4/sprarray/csc/base.pxi"

# Common functions.
include "mdnum4/creators.pxi"

include "mdnum4/utils.pxi"

include "mdnum4/math.pxi"

include "mdnum4/linalg.pxi"

include "mdnum4/algebra.pxi"

# FEM helper
include "mdnum4/fem/base.pxi"
