

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm5n2/include.pxi"

#      SCALAR.
# Base functions.
include "onumm5n2/scalar/base.pxi"

# Utilities.
include "onumm5n2/scalar/utils.pxi"

# Math functions.
include "onumm5n2/scalar/math.pxi"

# Gauss array
include "onumm5n2/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm5n2/array/base.pxi"

# Math operations.
include "onumm5n2/array/math.pxi"

include "onumm5n2/array/math_to.pxi"

# Utilities.
include "onumm5n2/array/utils.pxi"

# Gauss capabilities.
include "onumm5n2/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm5n2/generic.pxi"

#     onumm5n2 ARRAY
# Append base class.
include "onumm5n2/sprarray/lil/base.pxi"

include "onumm5n2/sprarray/csr/base.pxi"

include "onumm5n2/sprarray/csc/base.pxi"

# Common functions.
include "onumm5n2/creators.pxi"

include "onumm5n2/utils.pxi"

include "onumm5n2/math.pxi"

include "onumm5n2/linalg.pxi"

include "onumm5n2/algebra.pxi"

# FEM helper
include "onumm5n2/fem/base.pxi"
