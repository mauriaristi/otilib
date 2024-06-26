

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm1n30/include.pxi"

#      SCALAR.
# Base functions.
include "onumm1n30/scalar/base.pxi"

# Utilities.
include "onumm1n30/scalar/utils.pxi"

# Math functions.
include "onumm1n30/scalar/math.pxi"

# Gauss array
include "onumm1n30/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm1n30/array/base.pxi"

# Math operations.
include "onumm1n30/array/math.pxi"

include "onumm1n30/array/math_to.pxi"

# Utilities.
include "onumm1n30/array/utils.pxi"

# Gauss capabilities.
include "onumm1n30/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm1n30/generic.pxi"

#     onumm1n30 ARRAY
# Append base class.
include "onumm1n30/sprarray/lil/base.pxi"

include "onumm1n30/sprarray/csr/base.pxi"

include "onumm1n30/sprarray/csc/base.pxi"

# Common functions.
include "onumm1n30/creators.pxi"

include "onumm1n30/utils.pxi"

include "onumm1n30/math.pxi"

include "onumm1n30/linalg.pxi"

include "onumm1n30/algebra.pxi"

# FEM helper
include "onumm1n30/fem/base.pxi"
