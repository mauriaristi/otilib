

# Append directives
include "../common/directives.pxi"

# Append included libraries
include "<<<module_name>>>/include.pxi"





#      SCALAR.
# Base functions.
include "<<<module_name>>>/scalar/base.pxi"

# Utilities.
include "<<<module_name>>>/scalar/utils.pxi"

# Math functions.
include "<<<module_name>>>/scalar/math.pxi"

# Gauss array
include "<<<module_name>>>/scalar/gauss.pxi"






#           ARRAY
# Append base class.
include "<<<module_name>>>/array/base.pxi"

# Math operations.
include "<<<module_name>>>/array/math.pxi"

include "<<<module_name>>>/array/math_to.pxi"


# Utilities.
include "<<<module_name>>>/array/utils.pxi"

# Gauss capabilities.
include "<<<module_name>>>/array/gauss.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "<<<module_name>>>/generic.pxi"













#     <<<module_name>>> ARRAY
# Append base class.
include "<<<module_name>>>/sprarray/lil/base.pxi"

include "<<<module_name>>>/sprarray/csr/base.pxi"

include "<<<module_name>>>/sprarray/csc/base.pxi"












# Common functions.
include "<<<module_name>>>/creators.pxi"

include "<<<module_name>>>/utils.pxi"

include "<<<module_name>>>/math.pxi"

include "<<<module_name>>>/linalg.pxi"

include "<<<module_name>>>/algebra.pxi"


# FEM helper
include "<<<module_name>>>/fem/base.pxi"
