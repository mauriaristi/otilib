

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm2n3/include.pxi"

#      SCALAR.
# Base functions.
include "onumm2n3/scalar/base.pxi"

# Utilities.
include "onumm2n3/scalar/utils.pxi"

# Math functions.
include "onumm2n3/scalar/math.pxi"

# Gauss array
include "onumm2n3/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm2n3/array/base.pxi"

# Math operations.
include "onumm2n3/array/math.pxi"

include "onumm2n3/array/math_to.pxi"

# Utilities.
include "onumm2n3/array/utils.pxi"

# Gauss capabilities.
include "onumm2n3/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm2n3/generic.pxi"

#     onumm2n3 ARRAY
# Append base class.
include "onumm2n3/sprarray/lil/base.pxi"

include "onumm2n3/sprarray/csr/base.pxi"

include "onumm2n3/sprarray/csc/base.pxi"

# Common functions.
include "onumm2n3/creators.pxi"

include "onumm2n3/utils.pxi"

include "onumm2n3/math.pxi"

include "onumm2n3/linalg.pxi"

include "onumm2n3/algebra.pxi"

# FEM helper
include "onumm2n3/fem/base.pxi"
