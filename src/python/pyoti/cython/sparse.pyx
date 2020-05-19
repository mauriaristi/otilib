

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
include "sparse/scalar/math_to.pxi"






#     ARRAY    .

# Append base class.
include "sparse/array/base.pxi"

# Math operations.
include "sparse/array/math.pxi"
include "sparse/array/math_to.pxi"

# Utilities.
include "sparse/array/utils.pxi"


# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "sparse/generic.pxi"


# Common functions.
include "sparse/math.pxi"
