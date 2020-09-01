

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm5n5/include.pxi"

#      SCALAR.
# Base functions.
include "onumm5n5/scalar/base.pxi"

# Utilities.
include "onumm5n5/scalar/utils.pxi"

# Math functions.
include "onumm5n5/scalar/math.pxi"

# Gauss array
include "onumm5n5/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm5n5/array/base.pxi"

# Math operations.
include "onumm5n5/array/math.pxi"

include "onumm5n5/array/math_to.pxi"

# Utilities.
include "onumm5n5/array/utils.pxi"

# Gauss capabilities.
include "onumm5n5/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm5n5/generic.pxi"

#     onumm5n5 ARRAY
# Append base class.
include "onumm5n5/sprarray/lil/base.pxi"

include "onumm5n5/sprarray/csr/base.pxi"

include "onumm5n5/sprarray/csc/base.pxi"

# Common functions.
include "onumm5n5/creators.pxi"

include "onumm5n5/utils.pxi"

include "onumm5n5/math.pxi"

include "onumm5n5/linalg.pxi"

include "onumm5n5/algebra.pxi"

# FEM helper
include "onumm5n5/fem/base.pxi"
