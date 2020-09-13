

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "mdnum6/include.pxi"

#      SCALAR.
# Base functions.
include "mdnum6/scalar/base.pxi"

# Utilities.
include "mdnum6/scalar/utils.pxi"

# Math functions.
include "mdnum6/scalar/math.pxi"

# Gauss array
include "mdnum6/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "mdnum6/array/base.pxi"

# Math operations.
include "mdnum6/array/math.pxi"

include "mdnum6/array/math_to.pxi"

# Utilities.
include "mdnum6/array/utils.pxi"

# Gauss capabilities.
include "mdnum6/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "mdnum6/generic.pxi"

#     mdnum6 ARRAY
# Append base class.
include "mdnum6/sprarray/lil/base.pxi"

include "mdnum6/sprarray/csr/base.pxi"

include "mdnum6/sprarray/csc/base.pxi"

# Common functions.
include "mdnum6/creators.pxi"

include "mdnum6/utils.pxi"

include "mdnum6/math.pxi"

include "mdnum6/linalg.pxi"

include "mdnum6/algebra.pxi"

# FEM helper
include "mdnum6/fem/base.pxi"
