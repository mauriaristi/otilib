

# Append directives
include "common/directives.pxi"

# Append included libraries
include "sparse/include.pxi"





#      SCALAR.
# Base functions.
include "sparse/scalar/base.pxi"

# Utilities.
include "sparse/scalar/utils.pxi"

# Math functions.
include "sparse/scalar/math.pxi"

# Gauss array
include "sparse/scalar/gauss.pxi"






#           ARRAY
# Append base class.
include "sparse/array/base.pxi"

# Math operations.
include "sparse/array/math.pxi"
include "sparse/array/math_to.pxi"


# Utilities.
include "sparse/array/utils.pxi"

# Gauss capabilities.
include "sparse/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "sparse/generic.pxi"













#     SPARSE ARRAY
# Append base class.
include "sparse/sprarray/lil/base.pxi"
include "sparse/sprarray/csr/base.pxi"
include "sparse/sprarray/csc/base.pxi"












# Common functions.
include "sparse/utils.pxi"

include "sparse/math.pxi"

include "sparse/linalg.pxi"
