

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm3n1/include.pxi"

#      SCALAR.
# Base functions.
include "onumm3n1/scalar/base.pxi"

# Utilities.
include "onumm3n1/scalar/utils.pxi"

# Math functions.
include "onumm3n1/scalar/math.pxi"

# Gauss array
include "onumm3n1/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm3n1/array/base.pxi"

# Math operations.
include "onumm3n1/array/math.pxi"

include "onumm3n1/array/math_to.pxi"

# Utilities.
include "onumm3n1/array/utils.pxi"

# Gauss capabilities.
include "onumm3n1/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm3n1/generic.pxi"

#     onumm3n1 ARRAY
# Append base class.
include "onumm3n1/sprarray/lil/base.pxi"

include "onumm3n1/sprarray/csr/base.pxi"

include "onumm3n1/sprarray/csc/base.pxi"

# Common functions.
include "onumm3n1/creators.pxi"

include "onumm3n1/utils.pxi"

include "onumm3n1/math.pxi"

include "onumm3n1/linalg.pxi"

include "onumm3n1/algebra.pxi"

# FEM helper
include "onumm3n1/fem/base.pxi"
