

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm0n0/include.pxi"

#      SCALAR.
# Base functions.
include "onumm0n0/scalar/base.pxi"

# Utilities.
include "onumm0n0/scalar/utils.pxi"

# Math functions.
include "onumm0n0/scalar/math.pxi"

# Gauss array
include "onumm0n0/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm0n0/array/base.pxi"

# Math operations.
include "onumm0n0/array/math.pxi"

include "onumm0n0/array/math_to.pxi"

# Utilities.
include "onumm0n0/array/utils.pxi"

# Gauss capabilities.
include "onumm0n0/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm0n0/generic.pxi"

#     onumm0n0 ARRAY
# Append base class.
include "onumm0n0/sprarray/lil/base.pxi"

include "onumm0n0/sprarray/csr/base.pxi"

include "onumm0n0/sprarray/csc/base.pxi"

# Common functions.
include "onumm0n0/creators.pxi"

include "onumm0n0/utils.pxi"

include "onumm0n0/math.pxi"

include "onumm0n0/linalg.pxi"

include "onumm0n0/algebra.pxi"

# FEM helper
include "onumm0n0/fem/base.pxi"
