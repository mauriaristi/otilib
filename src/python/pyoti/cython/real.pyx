
# Append directives
include "common/directives.pxi"

# Append included libraries
include "real/include.pxi"

# ndarray interop (PLAN-ndarray.md, Phase 4): nd_from_object / nd_to_numpy and the private _ndtest.
include "real/ndarray/base.pxi"
include "real/ndarray/key2d.pxi"
include "real/ndarray/ndtest.pxi"

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

# FEM Helper
include "real/fem/base.pxi"