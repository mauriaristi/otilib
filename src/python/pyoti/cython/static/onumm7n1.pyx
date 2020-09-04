

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm7n1/include.pxi"

#      SCALAR.
# Base functions.
include "onumm7n1/scalar/base.pxi"

# Utilities.
include "onumm7n1/scalar/utils.pxi"

# Math functions.
include "onumm7n1/scalar/math.pxi"

# Gauss array
include "onumm7n1/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm7n1/array/base.pxi"

# Math operations.
include "onumm7n1/array/math.pxi"

include "onumm7n1/array/math_to.pxi"

# Utilities.
include "onumm7n1/array/utils.pxi"

# Gauss capabilities.
include "onumm7n1/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm7n1/generic.pxi"

#     onumm7n1 ARRAY
# Append base class.
include "onumm7n1/sprarray/lil/base.pxi"

include "onumm7n1/sprarray/csr/base.pxi"

include "onumm7n1/sprarray/csc/base.pxi"

# Common functions.
include "onumm7n1/creators.pxi"

include "onumm7n1/utils.pxi"

include "onumm7n1/math.pxi"

include "onumm7n1/linalg.pxi"

include "onumm7n1/algebra.pxi"

# FEM helper
include "onumm7n1/fem/base.pxi"
