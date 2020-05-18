
# Append directives
include "common/directives.pxi"

# Append included libraries
include "dense/include.pxi"

# Append scalar code.
include "dense/num.pxi"

# Append array code.
include "dense/array.pxi"

# Append easy creators.
include "dense/utils.pxi"

# Append math functions.
include "dense/math.pxi"

# Append math functions.
include "dense/sparse_array.pxi"

# Append base OTI class. - > Base to create OTI number with other characteristics.
include "dense/generic.pxi"


include "dense/oti_n2m2.pxi"

