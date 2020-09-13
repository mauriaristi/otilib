

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "mdnum8/include.pxi"

#      SCALAR.
# Base functions.
include "mdnum8/scalar/base.pxi"

# Utilities.
include "mdnum8/scalar/utils.pxi"

# Math functions.
include "mdnum8/scalar/math.pxi"

# Gauss array
include "mdnum8/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "mdnum8/array/base.pxi"

# Math operations.
include "mdnum8/array/math.pxi"

include "mdnum8/array/math_to.pxi"

# Utilities.
include "mdnum8/array/utils.pxi"

# Gauss capabilities.
include "mdnum8/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "mdnum8/generic.pxi"

#     mdnum8 ARRAY
# Append base class.
include "mdnum8/sprarray/lil/base.pxi"

include "mdnum8/sprarray/csr/base.pxi"

include "mdnum8/sprarray/csc/base.pxi"

# Common functions.
include "mdnum8/creators.pxi"

include "mdnum8/utils.pxi"

include "mdnum8/math.pxi"

include "mdnum8/linalg.pxi"

include "mdnum8/algebra.pxi"

# FEM helper
include "mdnum8/fem/base.pxi"
