

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm1n9/include.pxi"

#      SCALAR.
# Base functions.
include "onumm1n9/scalar/base.pxi"

# Utilities.
include "onumm1n9/scalar/utils.pxi"

# Math functions.
include "onumm1n9/scalar/math.pxi"

# Gauss array
include "onumm1n9/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm1n9/array/base.pxi"

# Math operations.
include "onumm1n9/array/math.pxi"

include "onumm1n9/array/math_to.pxi"

# Utilities.
include "onumm1n9/array/utils.pxi"

# Gauss capabilities.
include "onumm1n9/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm1n9/generic.pxi"

#     onumm1n9 ARRAY
# Append base class.
include "onumm1n9/sprarray/lil/base.pxi"

include "onumm1n9/sprarray/csr/base.pxi"

include "onumm1n9/sprarray/csc/base.pxi"

# Common functions.
include "onumm1n9/creators.pxi"

include "onumm1n9/utils.pxi"

include "onumm1n9/math.pxi"

include "onumm1n9/linalg.pxi"

include "onumm1n9/algebra.pxi"

# FEM helper
include "onumm1n9/fem/base.pxi"
