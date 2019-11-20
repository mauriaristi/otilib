

# Append directives
include "common/directives.pxi"

# Append included libraries
include "sparse/include.pxi"

# # Append array code.
# include "sparse/array.pxi"

# Append scalar code.
include "sparse/num.pxi"



# Append easy creators.
include "sparse/utils.pxi"

# Append math functions.
include "sparse/math.pxi"


# # Append math functions.
# include "sparse/sparse_array.pxi"

# # Append base OTI class. - > Base to create OTI number with other characteristics.
# include "sparse/generic.pxi"
