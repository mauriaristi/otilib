

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm1n8/include.pxi"

#      SCALAR.
# Base functions.
include "onumm1n8/scalar/base.pxi"

# Utilities.
include "onumm1n8/scalar/utils.pxi"

# Math functions.
include "onumm1n8/scalar/math.pxi"

# Gauss array
include "onumm1n8/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm1n8/array/base.pxi"

# Math operations.
include "onumm1n8/array/math.pxi"

include "onumm1n8/array/math_to.pxi"

# Utilities.
include "onumm1n8/array/utils.pxi"

# Gauss capabilities.
include "onumm1n8/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm1n8/generic.pxi"

#     onumm1n8 ARRAY
# Append base class.
include "onumm1n8/sprarray/lil/base.pxi"

include "onumm1n8/sprarray/csr/base.pxi"

include "onumm1n8/sprarray/csc/base.pxi"

# Common functions.
include "onumm1n8/creators.pxi"

include "onumm1n8/utils.pxi"

include "onumm1n8/math.pxi"

include "onumm1n8/linalg.pxi"

include "onumm1n8/algebra.pxi"

# FEM helper
include "onumm1n8/fem/base.pxi"
