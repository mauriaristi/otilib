
# Append directives
include "common/directives.pxi"

# Append included libraries
include "real/include.pxi"

# Append real array structure.
include "real/array/base.pxi"

# Gauss scalar.
include "real/scalar/gauss/base.pxi"

# Gauss Array.
include "real/array/gauss/base.pxi"









# Append real array math operations.
include "real/math.pxi"
include "real/algebra.pxi"
include "real/creators.pxi"
include "real/linalg.pxi"

# Append real array utils.
include "real/utils.pxi"


#     SPARSE ARRAY
# Append base class.
include "real/sprarray/lil/base.pxi"