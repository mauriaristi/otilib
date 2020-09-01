

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "mdnum5/include.pxi"

#      SCALAR.
# Base functions.
include "mdnum5/scalar/base.pxi"

# Utilities.
include "mdnum5/scalar/utils.pxi"

# Math functions.
include "mdnum5/scalar/math.pxi"

# Gauss array
include "mdnum5/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "mdnum5/array/base.pxi"

# Math operations.
include "mdnum5/array/math.pxi"

include "mdnum5/array/math_to.pxi"

# Utilities.
include "mdnum5/array/utils.pxi"

# Gauss capabilities.
include "mdnum5/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "mdnum5/generic.pxi"

#     mdnum5 ARRAY
# Append base class.
include "mdnum5/sprarray/lil/base.pxi"

include "mdnum5/sprarray/csr/base.pxi"

include "mdnum5/sprarray/csc/base.pxi"

# Common functions.
include "mdnum5/creators.pxi"

include "mdnum5/utils.pxi"

include "mdnum5/math.pxi"

include "mdnum5/linalg.pxi"

include "mdnum5/algebra.pxi"

# FEM helper
include "mdnum5/fem/base.pxi"
