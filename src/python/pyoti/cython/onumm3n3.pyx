

# Append directives
include "common/directives.pxi"

# Append included libraries
include "onumm3n3/include.pxi"

#      SCALAR.
# Base functions.
include "onumm3n3/scalar/base.pxi"

# Utilities.
include "onumm3n3/scalar/utils.pxi"

# Math functions.
include "onumm3n3/scalar/math.pxi"

# Gauss array
include "onumm3n3/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm3n3/array/base.pxi"

# Math operations.
include "onumm3n3/array/math.pxi"

include "onumm3n3/array/math_to.pxi"

# Utilities.
include "onumm3n3/array/utils.pxi"

# Gauss capabilities.
include "onumm3n3/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm3n3/generic.pxi"

#     onumm3n3 ARRAY
# Append base class.
include "onumm3n3/sprarray/lil/base.pxi"

include "onumm3n3/sprarray/csr/base.pxi"

include "onumm3n3/sprarray/csc/base.pxi"

# Common functions.
include "onumm3n3/creators.pxi"

include "onumm3n3/utils.pxi"

include "onumm3n3/math.pxi"

include "onumm3n3/linalg.pxi"

include "onumm3n3/algebra.pxi"
