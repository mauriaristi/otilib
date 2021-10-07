

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm1n20/include.pxi"

#      SCALAR.
# Base functions.
include "onumm1n20/scalar/base.pxi"

# Utilities.
include "onumm1n20/scalar/utils.pxi"

# Math functions.
include "onumm1n20/scalar/math.pxi"

# Gauss array
include "onumm1n20/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm1n20/array/base.pxi"

# Math operations.
include "onumm1n20/array/math.pxi"

include "onumm1n20/array/math_to.pxi"

# Utilities.
include "onumm1n20/array/utils.pxi"

# Gauss capabilities.
include "onumm1n20/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm1n20/generic.pxi"

#     onumm1n20 ARRAY
# Append base class.
include "onumm1n20/sprarray/lil/base.pxi"

include "onumm1n20/sprarray/csr/base.pxi"

include "onumm1n20/sprarray/csc/base.pxi"

# Common functions.
include "onumm1n20/creators.pxi"

include "onumm1n20/utils.pxi"

include "onumm1n20/math.pxi"

include "onumm1n20/linalg.pxi"

include "onumm1n20/algebra.pxi"

# FEM helper
include "onumm1n20/fem/base.pxi"
