
# Dependencies
include "c_otilib/dependencies.pxi"
include "c_otilib/types.pxi"

# Library version.
include "c_otilib/version.pxi"

# include "c_otilib/enums.pxi"

include "c_otilib/core.pxi"
include "c_otilib/real.pxi"
include "c_otilib/sparse.pxi"
include "c_otilib/semisparse.pxi"
include "c_otilib/semisparse_utils.pxi"
include "c_otilib/semisparse_io.pxi"
include "c_otilib/semisparse_gauss.pxi"
include "c_otilib/semisparse_csr.pxi"

# Dense (PLAN-dense-update.md): after sparse and semi-sparse, whose types its declarations use.
# Generated from include/oti/dense/**/*.h by tools/gen_dense_pxi.py.
include "c_otilib/dense.pxi"
include "c_otilib/dense_utils.pxi"
include "c_otilib/dense_io.pxi"
include "c_otilib/dense_gauss.pxi"
include "c_otilib/dense_csr.pxi"

# Static algebras.
include "c_otilib/static.pxi"


# FEM
include "c_otilib/fem.pxi"
