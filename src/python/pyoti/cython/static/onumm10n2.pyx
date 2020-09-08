

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "onumm10n2/include.pxi"

#      SCALAR.
# Base functions.
include "onumm10n2/scalar/base.pxi"

# Utilities.
include "onumm10n2/scalar/utils.pxi"

# Math functions.
include "onumm10n2/scalar/math.pxi"

# Gauss array
include "onumm10n2/scalar/gauss.pxi"

#           ARRAY
# Append base class.
include "onumm10n2/array/base.pxi"

# Math operations.
include "onumm10n2/array/math.pxi"

include "onumm10n2/array/math_to.pxi"

# Utilities.
include "onumm10n2/array/utils.pxi"

# Gauss capabilities.
include "onumm10n2/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "onumm10n2/generic.pxi"

#     onumm10n2 ARRAY
# Append base class.
include "onumm10n2/sprarray/lil/base.pxi"

include "onumm10n2/sprarray/csr/base.pxi"

include "onumm10n2/sprarray/csc/base.pxi"

# Common functions.
include "onumm10n2/creators.pxi"

include "onumm10n2/utils.pxi"

include "onumm10n2/math.pxi"

include "onumm10n2/linalg.pxi"

include "onumm10n2/algebra.pxi"

# FEM helper
include "onumm10n2/fem/base.pxi"
