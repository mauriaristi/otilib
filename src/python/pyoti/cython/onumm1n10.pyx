

# Append directives
include "common/directives.pxi"

# Append included libraries
include "onumm1n10/include.pxi"

#      SCALAR.
# Base functions.
include "onumm1n10/scalar/base.pxi"

# Utilities.
include "onumm1n10/scalar/utils.pxi"

# Math functions.
include "onumm1n10/scalar/math.pxi"

# Gauss array
include "onumm1n10/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm1n10/array/base.pxi"

# Math operations.
include "onumm1n10/array/math.pxi"

include "onumm1n10/array/math_to.pxi"

# Utilities.
include "onumm1n10/array/utils.pxi"

# Gauss capabilities.
include "onumm1n10/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm1n10/generic.pxi"

#     onumm1n10 ARRAY
# Append base class.
include "onumm1n10/sprarray/lil/base.pxi"

include "onumm1n10/sprarray/csr/base.pxi"

include "onumm1n10/sprarray/csc/base.pxi"

# Common functions.
include "onumm1n10/creators.pxi"

include "onumm1n10/utils.pxi"

include "onumm1n10/math.pxi"

include "onumm1n10/linalg.pxi"

include "onumm1n10/algebra.pxi"
