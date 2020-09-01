

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm5n1/include.pxi"

#      SCALAR.
# Base functions.
include "onumm5n1/scalar/base.pxi"

# Utilities.
include "onumm5n1/scalar/utils.pxi"

# Math functions.
include "onumm5n1/scalar/math.pxi"

# Gauss array
include "onumm5n1/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm5n1/array/base.pxi"

# Math operations.
include "onumm5n1/array/math.pxi"

include "onumm5n1/array/math_to.pxi"

# Utilities.
include "onumm5n1/array/utils.pxi"

# Gauss capabilities.
include "onumm5n1/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm5n1/generic.pxi"

#     onumm5n1 ARRAY
# Append base class.
include "onumm5n1/sprarray/lil/base.pxi"

include "onumm5n1/sprarray/csr/base.pxi"

include "onumm5n1/sprarray/csc/base.pxi"

# Common functions.
include "onumm5n1/creators.pxi"

include "onumm5n1/utils.pxi"

include "onumm5n1/math.pxi"

include "onumm5n1/linalg.pxi"

include "onumm5n1/algebra.pxi"

# FEM helper
include "onumm5n1/fem/base.pxi"
