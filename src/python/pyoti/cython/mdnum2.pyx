

# Append directives
include "common/directives.pxi"

# Append included libraries
include "mdnum2/include.pxi"

#      SCALAR.
# Base functions.
include "mdnum2/scalar/base.pxi"

# Utilities.
include "mdnum2/scalar/utils.pxi"

# Math functions.
include "mdnum2/scalar/math.pxi"

# Gauss array
include "mdnum2/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "mdnum2/array/base.pxi"

# Math operations.
include "mdnum2/array/math.pxi"

include "mdnum2/array/math_to.pxi"

# Utilities.
include "mdnum2/array/utils.pxi"

# Gauss capabilities.
include "mdnum2/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "mdnum2/generic.pxi"

#     mdnum2 ARRAY
# Append base class.
include "mdnum2/sprarray/lil/base.pxi"

include "mdnum2/sprarray/csr/base.pxi"

include "mdnum2/sprarray/csc/base.pxi"

# Common functions.
include "mdnum2/creators.pxi"

include "mdnum2/utils.pxi"

include "mdnum2/math.pxi"

include "mdnum2/linalg.pxi"

include "mdnum2/algebra.pxi"
