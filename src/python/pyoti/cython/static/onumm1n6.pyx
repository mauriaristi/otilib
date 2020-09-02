

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm1n6/include.pxi"

#      SCALAR.
# Base functions.
include "onumm1n6/scalar/base.pxi"

# Utilities.
include "onumm1n6/scalar/utils.pxi"

# Math functions.
include "onumm1n6/scalar/math.pxi"

# Gauss array
include "onumm1n6/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm1n6/array/base.pxi"

# Math operations.
include "onumm1n6/array/math.pxi"

include "onumm1n6/array/math_to.pxi"

# Utilities.
include "onumm1n6/array/utils.pxi"

# Gauss capabilities.
include "onumm1n6/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm1n6/generic.pxi"

#     onumm1n6 ARRAY
# Append base class.
include "onumm1n6/sprarray/lil/base.pxi"

include "onumm1n6/sprarray/csr/base.pxi"

include "onumm1n6/sprarray/csc/base.pxi"

# Common functions.
include "onumm1n6/creators.pxi"

include "onumm1n6/utils.pxi"

include "onumm1n6/math.pxi"

include "onumm1n6/linalg.pxi"

include "onumm1n6/algebra.pxi"

# FEM helper
include "onumm1n6/fem/base.pxi"
