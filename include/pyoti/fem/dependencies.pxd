
# Include the calls from C interface.
from pyoti.c_otilib cimport *

# Import real dependencies
from pyoti.real   import dmat
from pyoti.real  cimport dmat, darr_2_npy

import  pyoti.real as r
cimport pyoti.real as r

# Import dense dependencies.
from pyoti.dense  import omat
from pyoti.dense cimport omat

# Import sparse dependencies
from pyoti.sparse  import e as se

from pyoti.sparse  import sotife, matsofe, sotinum, matso
from pyoti.sparse cimport sotife, matsofe, sotinum, matso


# from pyoti.otimat  cimport otimat
# from pyoti.ndarray cimport ndarray
# from pyoti.sndarray cimport sndarray

# Import numpy
cimport numpy as np

# from pyoti.otimat import otimat