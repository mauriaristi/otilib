

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm5n4/include.pxi"

#      SCALAR.
# Base functions.
include "onumm5n4/scalar/base.pxi"

# Utilities.
include "onumm5n4/scalar/utils.pxi"

# Math functions.
include "onumm5n4/scalar/math.pxi"

# Gauss array
include "onumm5n4/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm5n4/array/base.pxi"

# Math operations.
include "onumm5n4/array/math.pxi"

include "onumm5n4/array/math_to.pxi"

# Utilities.
include "onumm5n4/array/utils.pxi"

# Gauss capabilities.
include "onumm5n4/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm5n4/generic.pxi"

#     onumm5n4 ARRAY
# Append base class.
include "onumm5n4/sprarray/lil/base.pxi"

include "onumm5n4/sprarray/csr/base.pxi"

include "onumm5n4/sprarray/csc/base.pxi"

# Common functions.
include "onumm5n4/creators.pxi"

include "onumm5n4/utils.pxi"

include "onumm5n4/math.pxi"

include "onumm5n4/linalg.pxi"

include "onumm5n4/algebra.pxi"

# FEM helper
include "onumm5n4/fem/base.pxi"
