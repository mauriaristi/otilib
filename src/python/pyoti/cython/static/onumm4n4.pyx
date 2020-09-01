

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm4n4/include.pxi"

#      SCALAR.
# Base functions.
include "onumm4n4/scalar/base.pxi"

# Utilities.
include "onumm4n4/scalar/utils.pxi"

# Math functions.
include "onumm4n4/scalar/math.pxi"

# Gauss array
include "onumm4n4/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm4n4/array/base.pxi"

# Math operations.
include "onumm4n4/array/math.pxi"

include "onumm4n4/array/math_to.pxi"

# Utilities.
include "onumm4n4/array/utils.pxi"

# Gauss capabilities.
include "onumm4n4/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm4n4/generic.pxi"

#     onumm4n4 ARRAY
# Append base class.
include "onumm4n4/sprarray/lil/base.pxi"

include "onumm4n4/sprarray/csr/base.pxi"

include "onumm4n4/sprarray/csc/base.pxi"

# Common functions.
include "onumm4n4/creators.pxi"

include "onumm4n4/utils.pxi"

include "onumm4n4/math.pxi"

include "onumm4n4/linalg.pxi"

include "onumm4n4/algebra.pxi"

# FEM helper
include "onumm4n4/fem/base.pxi"
