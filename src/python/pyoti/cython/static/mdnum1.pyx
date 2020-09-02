

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "mdnum1/include.pxi"

#      SCALAR.
# Base functions.
include "mdnum1/scalar/base.pxi"

# Utilities.
include "mdnum1/scalar/utils.pxi"

# Math functions.
include "mdnum1/scalar/math.pxi"

# Gauss array
include "mdnum1/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "mdnum1/array/base.pxi"

# Math operations.
include "mdnum1/array/math.pxi"

include "mdnum1/array/math_to.pxi"

# Utilities.
include "mdnum1/array/utils.pxi"

# Gauss capabilities.
include "mdnum1/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "mdnum1/generic.pxi"

#     mdnum1 ARRAY
# Append base class.
include "mdnum1/sprarray/lil/base.pxi"

include "mdnum1/sprarray/csr/base.pxi"

include "mdnum1/sprarray/csc/base.pxi"

# Common functions.
include "mdnum1/creators.pxi"

include "mdnum1/utils.pxi"

include "mdnum1/math.pxi"

include "mdnum1/linalg.pxi"

include "mdnum1/algebra.pxi"

# FEM helper
include "mdnum1/fem/base.pxi"
