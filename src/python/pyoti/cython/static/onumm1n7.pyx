

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm1n7/include.pxi"

#      SCALAR.
# Base functions.
include "onumm1n7/scalar/base.pxi"

# Utilities.
include "onumm1n7/scalar/utils.pxi"

# Math functions.
include "onumm1n7/scalar/math.pxi"

# Gauss array
include "onumm1n7/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm1n7/array/base.pxi"

# Math operations.
include "onumm1n7/array/math.pxi"

include "onumm1n7/array/math_to.pxi"

# Utilities.
include "onumm1n7/array/utils.pxi"

# Gauss capabilities.
include "onumm1n7/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm1n7/generic.pxi"

#     onumm1n7 ARRAY
# Append base class.
include "onumm1n7/sprarray/lil/base.pxi"

include "onumm1n7/sprarray/csr/base.pxi"

include "onumm1n7/sprarray/csc/base.pxi"

# Common functions.
include "onumm1n7/creators.pxi"

include "onumm1n7/utils.pxi"

include "onumm1n7/math.pxi"

include "onumm1n7/linalg.pxi"

include "onumm1n7/algebra.pxi"

# FEM helper
include "onumm1n7/fem/base.pxi"
