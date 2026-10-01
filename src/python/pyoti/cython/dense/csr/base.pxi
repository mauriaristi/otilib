# OTI sparse matrices csr_matrix / lil_matrix and _csr_solve (C lilo_t / csro_t,
# include/oti/dense/csr/csr.h). Owner: WP10 (dense-core). Template:
# src/python/pyoti/cython/semisparse/csr/base.pxi.
#
# csr_matrix holds one sparsity pattern (int64 NumPy index arrays, read-only, SciPy's layout) and one
# nnz x 1 SoA array of values: one nact for the whole matrix and one real nnz-vector per direction, so
# ``.real`` is a SciPy CSR matrix sharing the real block (no copy). lil_matrix keeps the pyoti.sparse
# assembly API (``K[i, j]`` get and set, ``tocsr``) over the C triplet builder lilo_t. solve() factors
# the real part once with SciPy (or scikit-sparse, scikit-umfpack) and builds the right-hand side of
# every order in C (csro_solve_rhs). Every C call returns a CSRO_* status (_csr_status).

import operator as _operator
import scipy.sparse as _sci_spr


# ********************************************************************************************************
cdef csro_t _csr_view(csr_matrix K) except *:
    """
    Build the native read-only view of a CSR matrix.

    Checks in O(1) that the pattern and the values agree (indptr has nrows + 1 entries, ends at
    nnz, and nnz is the number of values), so no kernel can read past the value array.

    Parameters
    ----------
    K : csr_matrix
        Matrix; the view is valid while it is alive and unchanged.

    Returns
    -------
    csro_t
        View of the values and the pattern.
    """

    cdef csro_t view
    cdef np.ndarray indptr = K._indptr

    if (K._val is None or indptr is None or K._indices is None
            or <uint64_t>indptr.shape[0] != K._nrows + 1 or indptr[K._nrows] != <int64_t>K._val.arr.size
            or <uint64_t>len(K._indices) != K._val.arr.size):

        raise ValueError("csr_matrix: inconsistent pattern and values")

    # end if

    view.p_val = &K._val.arr
    view.p_indices = <const int64_t *>np.PyArray_DATA(<np.ndarray>K._indices)
    view.p_indptr = <const int64_t *>np.PyArray_DATA(<np.ndarray>K._indptr)
    view.nrows = K._nrows
    view.ncols = K._ncols
    return view

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _csr_status(str operation, int status) except *:
    """
    Translate a native CSR status into a Python exception.

    Parameters
    ----------
    operation : str
        Name of the failing operation.
    status : int
        CSRO_* status.
    """

    if status == CSRO_OK:

        return

    elif status == CSRO_ERR_SIZE:

        raise ValueError("{}: incompatible shapes".format(operation))

    elif status == CSRO_ERR_MEMORY:

        raise MemoryError("{}: allocation failed or the size is too large".format(operation))

    elif status == CSRO_ERR_INDEX:

        raise ValueError("{}: invalid CSR pattern or index out of range".format(operation))

    elif status == CSRO_ERR_NACT:

        raise ValueError("{}: the matrix's nact is larger than the array's".format(operation))

    elif status == CSRO_ERR_ORDER:

        raise ValueError("{}: order out of range".format(operation))

    # end if

    raise RuntimeError("{}: native status {}".format(operation, status))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef otinum _csr_copy_value(const otinum_t *value):
    """
    Copy a stored C value into a new Python scalar.

    Parameters
    ----------
    value : const otinum_t *
        Stored value (valid until the next insertion into its builder).

    Returns
    -------
    otinum
        Independent copy.
    """

    cdef otinum_t res = oti_init()
    cdef int status = oti_copy_to(value, &res)

    if status != DN_OK:

        oti_free(&res)
        _status("copy", status)

    # end if

    return otinum.wrap(res)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _csr_immutable(np.ndarray values):
    """
    Copy a contiguous int64 array into an array backed by an immutable ``bytes`` buffer.

    Parameters
    ----------
    values : numpy.ndarray
        One-dimensional contiguous int64 array.

    Returns
    -------
    numpy.ndarray
        Read-only copy whose WRITEABLE flag cannot be set again, so the pattern the native kernels
        read cannot change after csro_check().
    """

    return np.frombuffer(values.tobytes(), dtype=np.int64)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _csr_index_array(object values, bint share):
    """
    Return a read-only contiguous int64 index array.

    Parameters
    ----------
    values : array_like
        Indices.
    share : bool
        Keep ``values`` itself when it already is a read-only contiguous int64 array (arrays of
        another csr_matrix); otherwise copy.

    Returns
    -------
    numpy.ndarray
        One-dimensional int64 array backed by an immutable buffer (not writeable, and the flag
        cannot be turned back on).
    """

    if (share and isinstance(values, np.ndarray) and values.dtype == np.int64 and values.ndim == 1
            and values.flags.c_contiguous and isinstance(values.base, bytes)):

        return values

    # end if

    return _csr_immutable(np.ascontiguousarray(values, dtype=np.int64).reshape(-1))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _csr_shape(object nrows, object ncols, str operation):
    """
    Validate the dimensions of a sparse matrix as Python integers.

    The int64 index arrays hold nrows + 1 row starts and column indices below ncols, so both must be
    nonnegative and nrows + 1 must fit in int64.

    Parameters
    ----------
    nrows : int
        Number of rows.
    ncols : int
        Number of columns.
    operation : str
        Name of the caller, for the message.

    Returns
    -------
    tuple
        (nrows, ncols) as Python integers.
    """

    nrows = _operator.index(nrows)
    ncols = _operator.index(ncols)

    if nrows < 0 or ncols < 0:

        raise ValueError("{}: shape must be nonnegative".format(operation))

    # end if

    if nrows > 2**63 - 2 or ncols > 2**63 - 1:

        raise ValueError("{}: shape ({}, {}) is too large for int64 indices".format(
            operation, nrows, ncols))

    # end if

    return (nrows, ncols)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef csr_matrix _csr_new(omat val, object indices, object indptr, uint64_t nrows, uint64_t ncols):
    """
    Wrap values and a pattern into a CSR matrix without checking them.

    Parameters
    ----------
    val : omat
        Values, nnz x 1 (owned by the result from now on).
    indices : array_like
        Column of each entry.
    indptr : array_like
        Row starts, length nrows + 1.
    nrows : int
        Number of rows.
    ncols : int
        Number of columns.

    Returns
    -------
    csr_matrix
        New matrix.
    """

    cdef csr_matrix result = csr_matrix.__new__(csr_matrix)

    result._val = val
    result._indices = _csr_index_array(indices, True)
    result._indptr = _csr_index_array(indptr, True)
    result._nrows = nrows
    result._ncols = ncols
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef csr_matrix _csr_like(csr_matrix K, object val):
    """
    Build a CSR matrix with the pattern of another one and new values.

    Parameters
    ----------
    K : csr_matrix
        Matrix whose pattern (shared, read-only) is reused.
    val : omat
        Values, nnz x 1.

    Returns
    -------
    csr_matrix
        New matrix.
    """

    return _csr_new(val, K._indices, K._indptr, K._nrows, K._ncols)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _csr_fill_from_lil(csr_matrix K, lil_matrix lil):
    """
    Fill a CSR matrix from a triplet builder (the builder is left unchanged).

    Parameters
    ----------
    K : csr_matrix
        Matrix to fill.
    lil : lil_matrix
        Source.
    """

    cdef omat val = omat.__new__(omat)
    cdef np.ndarray indices = np.empty(int(lil.lil.nnz), dtype=np.int64)
    cdef np.ndarray indptr = np.empty(int(lil.lil.nrows) + 1, dtype=np.int64)

    _csr_status("tocsr", lilo_to_csr(&lil.lil, &val.arr, <int64_t *>np.PyArray_DATA(indices),
                                     <int64_t *>np.PyArray_DATA(indptr)))

    K._val = val
    K._indices = _csr_immutable(indices)
    K._indptr = _csr_immutable(indptr)
    K._nrows = lil.lil.nrows
    K._ncols = lil.lil.ncols

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _csr_values(object data, uint64_t nnz):
    """
    Convert the values of a (data, indices, indptr) triple into an nnz x 1 SoA array.

    Parameters
    ----------
    data : omat or arro or matso or sequence
        Values: an array with nnz elements in one row or one column, or a sequence of reals and OTI
        scalars.
    nnz : int
        Expected number of values.

    Returns
    -------
    omat
        New nnz x 1 array.
    """

    cdef omat result
    cdef uint64_t t
    cdef object values

    if isinstance(data, matso):

        data = omat.from_sparse(data)

    elif isinstance(data, arro):

        data = data.to_soa()

    # end if

    if isinstance(data, omat):

        if data.shape == (nnz, 1):

            return data.copy()

        elif data.shape == (1, nnz):

            return data.T

        # end if

        raise ValueError("csr_matrix: data has shape {}, expected ({}, 1)".format(data.shape, nnz))

    # end if

    values = list(data)

    if <uint64_t>len(values) != nnz:

        raise ValueError("csr_matrix: {} values for {} indices".format(len(values), nnz))

    # end if

    if all(isinstance(value, Real) for value in values):

        return omat.from_real(np.asarray(values, dtype=np.float64).reshape(-1, 1))

    # end if

    result = omat.zeros((nnz, 1))

    for t in range(nnz):

        result[t, 0] = values[t]

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _csr_operand(object value, str operation):
    """
    Convert the dense operand of a CSR product or solve into a SoA array.

    Parameters
    ----------
    value : omat or arro or matso or array_like
        Operand; a real one-dimensional array becomes a column.
    operation : str
        Name of the calling operation, for error messages.

    Returns
    -------
    omat
        The operand itself when it already is one, otherwise a new array.
    """

    cdef np.ndarray real

    if isinstance(value, omat):

        return value

    elif isinstance(value, arro):

        return value.to_soa()

    elif isinstance(value, matso):

        return omat.from_sparse(value)

    elif isinstance(value, (np.ndarray, list, tuple)):

        try:

            real = np.asarray(value, dtype=np.float64)

        except (TypeError, ValueError):

            # Nested lists holding OTI scalars, as pyoti.sparse accepts: the dense array creator.
            return _csr_operand(array(value), operation)

        # end try

        if real.ndim == 1:

            real = real.reshape(-1, 1)

        # end if

        return omat.from_real(real)

    # end if

    raise TypeError("{}: unsupported operand type {}".format(operation, type(value).__name__))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _csr_matmul(csr_matrix K, object other):
    """
    Multiply a CSR matrix by a dense operand.

    Parameters
    ----------
    K : csr_matrix
        Left factor.
    other : omat or arro or matso or array_like
        Right factor, ncols(K) rows.

    Returns
    -------
    omat
        Product, over nact = max(nact_K, nact_x) at the larger truncation order.
    """

    cdef omat x = _csr_operand(other, "matmul")
    cdef omat result = omat.__new__(omat)
    cdef csro_t view = _csr_view(K)

    _csr_status("matmul", csro_matmul_to(&view, &x.arr, &result.arr, _dhl))
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef csr_matrix _csr_combine(csr_matrix lhs, csr_matrix rhs):
    """
    Add two CSR matrices of the same shape over the union of their patterns.

    Parameters
    ----------
    lhs : csr_matrix
        First term.
    rhs : csr_matrix
        Second term.

    Returns
    -------
    csr_matrix
        Sum; explicit zeros are kept, as in pyoti.sparse.
    """

    cdef lil_matrix lil
    cdef csr_matrix result
    cdef otinum_t tmp
    cdef csr_matrix term
    cdef const int64_t *ptr
    cdef const int64_t *idx
    cdef uint64_t r
    cdef int64_t t
    cdef int status

    if lhs.shape != rhs.shape:

        raise ValueError("Matrices must have the same dimensions in addition operation: {0} x {1}"
                         .format(lhs.shape, rhs.shape))

    # end if

    if np.array_equal(lhs._indptr, rhs._indptr) and np.array_equal(lhs._indices, rhs._indices):

        return _csr_like(lhs, lhs._val + rhs._val)

    # end if

    lil = lil_matrix(lhs.shape)
    tmp = oti_init()

    for term in (lhs, rhs):

        ptr = <const int64_t *>np.PyArray_DATA(<np.ndarray>term._indptr)
        idx = <const int64_t *>np.PyArray_DATA(<np.ndarray>term._indices)

        for r in range(term._nrows):

            for t in range(ptr[r], ptr[r + 1]):

                status = oarr_get_item_to(<uint64_t>t, 0, &term._val.arr, &tmp)

                if status != DN_OK:

                    oti_free(&tmp)
                    _status("add", status)

                # end if

                status = lilo_add(&lil.lil, r, <uint64_t>idx[t], &tmp, _dhl)

                if status != CSRO_OK:

                    oti_free(&tmp)
                    _csr_status("add", status)

                # end if

            # end for

        # end for

    # end for

    oti_free(&tmp)
    result = csr_matrix.__new__(csr_matrix)
    _csr_fill_from_lil(result, lil)
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _csr_factor(csr_matrix K, object solver, dict solver_args):
    """
    Factor the real part of a CSR matrix once and return its solve function.

    Same solver names as ``pyoti.sparse.solve``.

    Parameters
    ----------
    K : csr_matrix
        Square matrix.
    solver : str
        'SuperLU' (also 'LU', 'lu', 'splu'), 'spilu' (also 'ILU', 'ilu'), 'cholesky' (also 'ch',
        'CH'; scikit-sparse) or 'umfpack' (also 'UMFPACK', 'luumf'; scikit-umfpack).
    solver_args : dict
        Keyword arguments of the factorization.

    Returns
    -------
    callable
        Function solving the real system for a two-dimensional right-hand side.
    """

    real = K.real.tocsc()

    if solver in ('SuperLU', 'LU', 'lu', 'splu'):

        from scipy.sparse.linalg import splu
        return splu(real, **solver_args).solve

    elif solver in ('ILU', 'ilu', 'spilu'):

        from scipy.sparse.linalg import spilu
        return spilu(real, **solver_args).solve

    elif solver in ('cholesky', 'ch', 'CH'):

        from sksparse.cholmod import cholesky
        return cholesky(real, **solver_args)

    elif solver in ('UMFPACK', 'umfpack', 'luumf'):

        from scikits.umfpack import splu as umfpack_splu
        real.indices = real.indices.astype(np.int64)
        real.indptr = real.indptr.astype(np.int64)
        return umfpack_splu(real, **solver_args).solve

    # end if

    raise ValueError("Unsupported solver. Try solver = 'SuperLU', solver = 'cholesky' or "
                     "solver = 'umfpack'")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _csr_solve_blocks(object solve_fn, object blocks, uint64_t nrows, uint64_t ncols) except *:
    """
    Solve the real system for consecutive coefficient blocks in place.

    Parameters
    ----------
    solve_fn : callable
        Real solve (from ``_csr_factor``).
    blocks : numpy.ndarray
        Writable (nblocks, nrows * ncols) view of column-major blocks; solved in place.
    nrows : int
        Rows of each block.
    ncols : int
        Columns of each block.
    """

    cdef uint64_t width = blocks.shape[0] * ncols
    cdef object rhs

    # (nrows, nblocks * ncols) view: every column of every block side by side.
    rhs = blocks.reshape(width, nrows).T

    if not rhs.any():

        return

    # end if

    rhs[...] = np.asarray(solve_fn(rhs), dtype=np.float64).reshape(nrows, width)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _csr_solve(K_in, b_in, out=None, solver='SuperLU', solver_args=None):
    """
    Solve K u = b for a CSR matrix of OTI numbers (the CSR branch of ``solve``).

    The real part of K is factored once; the right-hand side of every order n,
    b_n - sum_{p=1..n} [K_p u_(n-p)]_n, is built in C for all the order-n directions at once and solved
    with the same factors. The solution has nact = max(nact_K, nact_b) and the larger truncation order.

    Parameters
    ----------
    K_in : csr_matrix
        Square matrix.
    b_in : omat or arro or matso or array_like
        Right-hand side.
    out : omat, optional
        Holder for the solution.
    solver : str
        Real solver, as in ``pyoti.sparse.solve``: 'SuperLU', 'spilu', 'cholesky', 'umfpack'.
    solver_args : dict, optional
        Keyword arguments of the factorization.

    Returns
    -------
    omat
        Solution, or None when ``out`` is given.
    """

    cdef csr_matrix K = K_in
    cdef omat b = _csr_operand(b_in, "solve")
    cdef omat u
    cdef csro_t view = _csr_view(K)
    cdef ord_t n
    cdef uint64_t start, count
    cdef object solve_fn, blocks

    if K._nrows != K._ncols:

        raise ValueError("solve: the matrix must be square, got shape {}".format(K.shape))

    # end if

    if b.arr.nrows != K._nrows:

        raise ValueError("solve: right-hand side has {} rows, expected {}".format(b.arr.nrows,
                                                                                  K._nrows))

    # end if

    # The solution layout first: a size overflow raises before a possibly expensive factorization.
    u = omat.__new__(omat)
    _csr_status("solve", csro_solve_init(&view, &b.arr, &u.arr))
    solve_fn = _csr_factor(K, solver, {} if solver_args is None else dict(solver_args))

    if u.arr.size > 0:

        blocks = _soa_blocks(u)
        _csr_solve_blocks(solve_fn, blocks[0:1], u.arr.nrows, u.arr.ncols)

        for n in range(1, u.arr.trc_order + 1):

            _csr_status("solve", csro_solve_rhs(&view, &u.arr, n, _dhl))
            start = 1 + sshelp_order_offset(u.arr.nact, n)
            count = sshelp_ndir_order(u.arr.nact, n)
            _csr_solve_blocks(solve_fn, blocks[start:start + count], u.arr.nrows, u.arr.ncols)

        # end for

    # end if

    return _finish(u, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _csr_extract(omat val, object hum_dir, bint deriv):
    """
    Extract, in every element of a value array, the coefficients that contain a direction.

    Parameters
    ----------
    val : omat
        Values (not modified).
    hum_dir : object
        Direction in any pyoti.sparse format, or a rawdir.
    deriv : bool
        True for derivatives (extract_deriv), False for coefficients (extract_im).

    Returns
    -------
    omat
        Extracted values, same shape.
    """

    cdef tuple pair = _direction(hum_dir)
    cdef oarr_t res = oarr_init()
    cdef int status

    if deriv:

        status = oarr_extract_deriv_to(pair[0], pair[1], &val.arr, &res)

    else:

        status = oarr_extract_im_to(pair[0], pair[1], &val.arr, &res)

    # end if

    _soa_ok("extract", status, &res)

    return omat.wrap(res)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class csr_matrix:
    """
    Compressed sparse row matrix of dense OTI numbers, like ``pyoti.sparse.csr_matrix``.

    One sparsity pattern (``indices``, ``indptr``: read-only int64 arrays, SciPy's layout) and one
    nnz x 1 SoA array of values: one nact for the whole matrix, one real nnz-vector per
    direction. ``real`` is a SciPy CSR matrix that shares the real block (no copy).
    """

    # ****************************************************************************************************
    def __init__(self, arg1, shape=None, copy=True, preserve_in=False):
        """
        Create a CSR matrix.

        Parameters
        ----------
        arg1 : lil_matrix or csr_matrix or tuple or scipy sparse matrix or pyoti.sparse matrix
            Source: a ``lil_matrix`` (converted; emptied unless ``preserve_in``, as in pyoti.sparse),
            another ``csr_matrix`` (copied), ``(data, indices, indptr)`` (data: an OTI array with nnz
            elements or a sequence of reals and OTI scalars), ``(nrows, ncols)`` (empty), a SciPy
            sparse matrix (real values), or a ``pyoti.sparse`` ``csr_matrix`` / ``lil_matrix``.
        shape : tuple of int, optional
            Shape for ``(data, indices, indptr)``; inferred from the indices when omitted.
        copy : bool
            Unused, for compatibility with pyoti.sparse (inputs are always copied).
        preserve_in : bool
            Keep the entries of a source ``lil_matrix`` (default False: it is emptied to save memory,
            as ``pyoti.sparse`` does).
        """

        import pyoti.sparse as sparse_module

        cdef lil_matrix lil = None
        cdef csr_matrix other
        cdef csr_matrix new = csr_matrix.__new__(csr_matrix)
        cdef object nrows, ncols
        cdef csro_t view

        # Everything is built into `new` and committed only after every check has passed, so a
        # failure leaves a live matrix (a second __init__ call) unchanged.
        if isinstance(arg1, lil_matrix):

            lil = arg1
            _csr_fill_from_lil(new, lil)

        elif isinstance(arg1, csr_matrix):

            other = arg1
            new._val = other._val.copy()
            new._indices = other._indices
            new._indptr = other._indptr
            new._nrows = other._nrows
            new._ncols = other._ncols

        elif _sci_spr.issparse(arg1):

            real = arg1.tocsr()
            nrows, ncols = _csr_shape(real.shape[0], real.shape[1], "csr_matrix")
            new._val = omat.from_real(np.asarray(real.data, dtype=np.float64).reshape(-1, 1))
            new._indices = _csr_index_array(real.indices, False)
            new._indptr = _csr_index_array(real.indptr, False)
            new._nrows, new._ncols = nrows, ncols

        elif isinstance(arg1, sparse_module.csr_matrix):

            nrows, ncols = _csr_shape(arg1.shape[0], arg1.shape[1], "csr_matrix")
            new._val = omat.from_sparse(arg1.data)
            new._indices = _csr_index_array(arg1.indices, False)
            new._indptr = _csr_index_array(arg1.indptr, False)
            new._nrows, new._ncols = nrows, ncols

        elif isinstance(arg1, sparse_module.lil_matrix):

            # As for a dense lil_matrix, the sparse builder is emptied unless preserve_in.
            other = csr_matrix(sparse_module.csr_matrix(arg1, preserve_in=preserve_in))
            new._val = other._val
            new._indices = other._indices
            new._indptr = other._indptr
            new._nrows = other._nrows
            new._ncols = other._ncols

        elif (isinstance(arg1, tuple) and len(arg1) == 2 and isinstance(arg1[0], (int, np.integer))
                and isinstance(arg1[1], (int, np.integer))):

            nrows, ncols = _csr_shape(arg1[0], arg1[1], "csr_matrix")
            new._nrows, new._ncols = nrows, ncols
            new._val = omat.zeros((0, 1))
            new._indices = _csr_index_array(np.zeros(0, dtype=np.int64), False)
            new._indptr = _csr_index_array(np.zeros(nrows + 1, dtype=np.int64), False)

        elif isinstance(arg1, tuple) and len(arg1) == 3:

            data, indices, indptr = arg1
            new._indices = _csr_index_array(indices, False)
            new._indptr = _csr_index_array(indptr, False)

            if shape is None:

                nrows = len(new._indptr) - 1
                ncols = (int(new._indices.max()) + 1) if len(new._indices) else 0

            else:

                nrows, ncols = shape

            # end if

            nrows, ncols = _csr_shape(max(nrows, 0), ncols, "csr_matrix")
            new._nrows = nrows
            new._ncols = ncols
            new._val = _csr_values(data, len(new._indices))

        elif isinstance(arg1, tuple) and len(arg1) == 2 and isinstance(arg1[1], tuple):

            raise ValueError(" ( data, (rows, cols) ) input format not currently implemented for CSR "
                             "matrix.")

        else:

            raise ValueError("Wrong imput format to create CSR matrix.")

        # end if

        if len(new._indptr) != new._nrows + 1:

            raise ValueError("csr_matrix: indptr has length {}, expected {}".format(
                len(new._indptr), new._nrows + 1))

        # end if

        if new._indptr[new._nrows] != new._val.arr.size or len(new._indices) != new._val.arr.size:

            raise ValueError("csr_matrix: indptr[nrows] = {} and {} indices for {} values".format(
                int(new._indptr[new._nrows]), len(new._indices), new._val.arr.size))

        # end if

        view = _csr_view(new)
        _csr_status("csr_matrix", csro_check(&view))

        # Commit.
        self._val = new._val
        self._indices = new._indices
        self._indptr = new._indptr
        self._nrows = new._nrows
        self._ncols = new._ncols

        if lil is not None and not preserve_in:

            lilo_free(&lil.lil)

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def nnz(self):
        """
        Return the number of stored elements.

        Returns
        -------
        int
            Stored elements (explicit zeros included).
        """

        return len(self._indices)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def shape(self):
        """
        Return the matrix dimensions.

        Returns
        -------
        tuple
            Number of rows and columns.
        """

        return (self._nrows, self._ncols)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def data(self):
        """
        Return a copy of the stored values.

        Returns
        -------
        omat
            nnz x 1 array, in CSR order.
        """

        return self._val.copy()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def indices(self):
        """
        Return the column of every stored element.

        Returns
        -------
        numpy.ndarray
            Read-only int64 array of length nnz (shared with the matrix).
        """

        return self._indices

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def indptr(self):
        """
        Return the row starts.

        Returns
        -------
        numpy.ndarray
            Read-only int64 array of length nrows + 1 (shared with the matrix).
        """

        return self._indptr

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def order(self):
        """
        Return the truncation order.

        Returns
        -------
        int
            Truncation order of the values.
        """

        return self._val.arr.trc_order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def active_bases(self):
        """
        Return the active global bases shared by every element, [1, ..., nact].

        Returns
        -------
        list of int
            Basis labels.
        """

        return self._val.active_bases

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def real(self):
        """
        Return the real part as a SciPy CSR matrix sharing memory with this matrix.

        Writing into its ``data`` changes the real part of this matrix; the index arrays are
        read-only. The SciPy matrix keeps this one alive. It is a view for reading and writing
        values only: SciPy calls that change the structure or need writable indices
        (``eliminate_zeros``, ``sort_indices``, ``sum_duplicates``, ``spsolve`` through
        scikit-umfpack, which rejects read-only int64 indices) need ``K.real.copy()``.

        Returns
        -------
        scipy.sparse.csr_matrix
            Real part, no copy.
        """

        real = _sci_spr.csr_matrix((self._nrows, self._ncols), dtype=np.float64)
        real.data = _soa_blocks(self._val)[0]
        real.indices = self._indices
        real.indptr = self._indptr
        return real

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __repr__(self):
        """
        Return the representation of the matrix.

        Returns
        -------
        str
            Shape and number of stored elements.
        """

        out = "<{0} sparse matrix of OTI numbers with \n".format(self.shape)
        out += "         {0} stored elements in Compressed Sparse Row format>".format(self.nnz)
        return out

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __str__(self):
        """
        List every stored element as ``(row, col) value``.

        Returns
        -------
        str
            One line per stored element.
        """

        cdef uint64_t r
        cdef int64_t t
        cdef const int64_t *ptr = <const int64_t *>np.PyArray_DATA(<np.ndarray>self._indptr)
        cdef const int64_t *idx = <const int64_t *>np.PyArray_DATA(<np.ndarray>self._indices)
        cdef otinum value

        out = ""

        for r in range(self._nrows):

            for t in range(ptr[r], ptr[r + 1]):

                value = otinum.__new__(otinum)
                _status("str", oarr_get_item_to(<uint64_t>t, 0, &self._val.arr, &value.num))
                out += "({0:3d},{1:3d}) {2}\n".format(r, idx[t], str(value))

            # end for

        # end for

        return out

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def toarray(self):
        """
        Return a dense copy (duplicate entries added up).

        Returns
        -------
        omat
            Dense matrix with the same nact and orders.
        """

        cdef omat result = omat.__new__(omat)
        cdef csro_t view = _csr_view(self)

        _csr_status("toarray", csro_to_dense(&view, &result.arr))
        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def todense(self):
        """
        Return a dense copy; same as ``toarray``.

        Returns
        -------
        omat
            Dense matrix.
        """

        return self.toarray()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def copy(self):
        """
        Copy the matrix (the read-only pattern is shared).

        Returns
        -------
        csr_matrix
            Independent values, same pattern.
        """

        return _csr_like(self, self._val.copy())

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __copy__(self):
        """
        Support ``copy.copy``: an independent copy of the values (the read-only pattern is shared).

        Returns
        -------
        csr_matrix
            Same as ``copy()``.
        """

        return self.copy()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __deepcopy__(self, memo):
        """
        Support ``copy.deepcopy``: an independent copy of the values (the read-only pattern is shared).

        Parameters
        ----------
        memo : dict
            Memo of ``copy.deepcopy`` (unused: the matrix holds no references to other objects).

        Returns
        -------
        csr_matrix
            Same as ``copy()``.
        """

        return self.copy()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def zeros_like(self):
        """
        Return a matrix with the same pattern and real zero values.

        Returns
        -------
        csr_matrix
            Zero values (order 0, no bases), same pattern.
        """

        return _csr_like(self, omat.zeros((self.nnz, 1)))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def tolil(self):
        """
        Convert to a ``lil_matrix``; duplicate entries add up, as in ``toarray``, ``@`` and ``solve``
        (``to_sparse`` passes them on to pyoti.sparse, whose ``toarray`` keeps the last one).

        Returns
        -------
        lil_matrix
            Builder holding every stored element.
        """

        cdef lil_matrix result = lil_matrix(self.shape)
        cdef otinum_t tmp = oti_init()
        cdef uint64_t r
        cdef int64_t t
        cdef const int64_t *ptr = <const int64_t *>np.PyArray_DATA(<np.ndarray>self._indptr)
        cdef const int64_t *idx = <const int64_t *>np.PyArray_DATA(<np.ndarray>self._indices)
        cdef int status

        for r in range(self._nrows):

            for t in range(ptr[r], ptr[r + 1]):

                status = oarr_get_item_to(<uint64_t>t, 0, &self._val.arr, &tmp)

                if status != DN_OK:

                    oti_free(&tmp)
                    _status("tolil", status)

                # end if

                status = lilo_add(&result.lil, r, <uint64_t>idx[t], &tmp, _dhl)

                if status != CSRO_OK:

                    oti_free(&tmp)
                    _csr_status("tolil", status)

                # end if

            # end for

        # end for

        oti_free(&tmp)
        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def to_sparse(self):
        """
        Convert to a ``pyoti.sparse.csr_matrix`` with the same pattern and values.

        Returns
        -------
        pyoti.sparse.csr_matrix
            Sparse-type matrix.
        """

        import pyoti.sparse as sparse_module

        return sparse_module.csr_matrix((self._val.to_sparse(), self._indices.astype(np.uint64),
                                         self._indptr.astype(np.uint64)), shape=self.shape)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __neg__(self):
        """
        Negate every stored element.

        Returns
        -------
        csr_matrix
            Negated matrix, same pattern.
        """

        return _csr_like(self, -self._val)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __add__(self, other):
        """
        Add two CSR matrices (union of the patterns).

        Parameters
        ----------
        other : csr_matrix
            Second term.

        Returns
        -------
        csr_matrix or NotImplemented
            Sum.
        """

        if not isinstance(other, csr_matrix):

            return NotImplemented

        # end if

        return _csr_combine(self, other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __sub__(self, other):
        """
        Subtract two CSR matrices (union of the patterns).

        Parameters
        ----------
        other : csr_matrix
            Subtrahend.

        Returns
        -------
        csr_matrix or NotImplemented
            Difference.
        """

        if not isinstance(other, csr_matrix):

            return NotImplemented

        # end if

        return _csr_combine(self, -other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __mul__(self, other):
        """
        Multiply every stored element by a scalar.

        Parameters
        ----------
        other : float or otinum or sotinum
            Scalar factor.

        Returns
        -------
        csr_matrix or NotImplemented
            Scaled matrix, same pattern.
        """

        if isinstance(other, sotinum):

            other = otinum(other)

        # end if

        if not isinstance(other, (Real, otinum)):

            return NotImplemented

        # end if

        return _csr_like(self, self._val * other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rmul__(self, other):
        """
        Multiply every stored element by a scalar from the left.

        Parameters
        ----------
        other : float or otinum or sotinum
            Scalar factor.

        Returns
        -------
        csr_matrix or NotImplemented
            Scaled matrix, same pattern.
        """

        return self.__mul__(other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __truediv__(self, other):
        """
        Divide every stored element by a scalar.

        Parameters
        ----------
        other : float or otinum or sotinum
            Scalar divisor.

        Returns
        -------
        csr_matrix or NotImplemented
            Scaled matrix, same pattern.
        """

        if isinstance(other, sotinum):

            other = otinum(other)

        # end if

        if not isinstance(other, (Real, otinum)):

            return NotImplemented

        # end if

        return _csr_like(self, self._val / other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __pow__(self, exponent, modulus=None):
        """
        Raise every stored element to a power.

        Parameters
        ----------
        exponent : float
            Exponent.
        modulus : None
            Unused.

        Returns
        -------
        csr_matrix
            Matrix of powers, same pattern.
        """

        return _csr_like(self, self._val ** exponent)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __matmul__(self, other):
        """
        Multiply by a dense OTI matrix, K @ x.

        Parameters
        ----------
        other : omat or arro or matso or array_like
            Right factor.

        Returns
        -------
        omat
            Product, nact = max(nact_K, nact_x).
        """

        return _csr_matmul(self, other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def dot(self, other, out=None):
        """
        Multiply by a dense OTI matrix; same as ``K @ other``.

        Parameters
        ----------
        other : omat or arro or matso or array_like
            Right factor.
        out : omat, optional
            Holder for the product.

        Returns
        -------
        omat
            Product, or None when ``out`` is given.
        """

        return _finish(_csr_matmul(self, other), out)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_deriv(self, hum_dir):
        """
        Return the derivative along a direction of every stored element, as a real matrix.

        Parameters
        ----------
        hum_dir : int or list or tuple or rawdir
            Direction.

        Returns
        -------
        csr_matrix
            Real matrix (order 0), same pattern.
        """

        return _csr_like(self, omat.from_real(self._val.get_deriv(hum_dir)))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_im(self, hum_dir):
        """
        Return the coefficient of a direction of every stored element, as a real matrix.

        Parameters
        ----------
        hum_dir : int or list or tuple or rawdir
            Direction.

        Returns
        -------
        csr_matrix
            Real matrix (order 0), same pattern.
        """

        return _csr_like(self, omat.from_real(self._val.get_im(hum_dir)))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def extract_im(self, hum_dir):
        """
        Extract, in every stored element, the coefficients that contain a direction.

        Parameters
        ----------
        hum_dir : int or list or tuple or rawdir
            Direction.

        Returns
        -------
        csr_matrix
            Extracted values (see ``extract_im``), same pattern.
        """

        return _csr_like(self, _csr_extract(self._val, hum_dir, False))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def extract_deriv(self, hum_dir):
        """
        Extract, in every stored element, the derivatives that contain a direction.

        Parameters
        ----------
        hum_dir : int or list or tuple or rawdir
            Direction.

        Returns
        -------
        csr_matrix
            Extracted values (see ``extract_deriv``), same pattern.
        """

        return _csr_like(self, _csr_extract(self._val, hum_dir, True))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_order_im(self, order):
        """
        Keep one order of every stored element.

        Parameters
        ----------
        order : int
            Order to keep (0: the real part).

        Returns
        -------
        csr_matrix
            Order-``order`` part, same pattern.
        """

        return _csr_like(self, self._val.get_order_im(order))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate(self, hum_dir):
        """
        Remove a direction (and its multiples) from every stored element.

        Parameters
        ----------
        hum_dir : int or list or tuple or rawdir
            Direction.

        Returns
        -------
        csr_matrix
            Truncated values, same pattern.
        """

        return _csr_like(self, self._val.truncate(hum_dir))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_active_bases(self):
        """
        List the active bases of the matrix, [1, ..., nact].

        Returns
        -------
        list of int
            Basis labels.
        """

        return self._val.get_active_bases()

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class lil_matrix:
    """
    Sparse matrix builder of dense OTI numbers, with the ``pyoti.sparse.lil_matrix`` API.

    ``K[i, j]`` reads a copy of an element (a real zero when it is not stored) and ``K[i, j] = v``
    stores a copy of ``v`` (overwriting), so ``K[i, j] = K[i, j] + Ke[a, b]`` accumulates. Each
    element keeps its own nact and order until ``tocsr``, which lays them out over the largest ones.
    Backed by a C triplet builder with a hash table.
    """

    # ****************************************************************************************************
    def __cinit__(self, *args, **kwargs):
        """
        Initialize an empty native builder.
        """

        self.lil = lilo_init(0, 0)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __init__(self, shape):
        """
        Create an empty builder.

        Parameters
        ----------
        shape : tuple of int
            (nrows, ncols).
        """

        if not (isinstance(shape, tuple) and len(shape) == 2):

            raise ValueError("Wrong shape format. Only 2x2 matrix are supported.")

        # end if

        nrows, ncols = _csr_shape(shape[0], shape[1], "lil_matrix")
        lilo_free(&self.lil)
        self.lil = lilo_init(nrows, ncols)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __dealloc__(self):
        """
        Release every stored element.
        """

        lilo_free(&self.lil)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def nnz(self):
        """
        Return the number of stored elements.

        Returns
        -------
        int
            Stored elements (explicit zeros included).
        """

        return self.lil.nnz

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def shape(self):
        """
        Return the matrix dimensions.

        Returns
        -------
        tuple
            Number of rows and columns.
        """

        return (self.lil.nrows, self.lil.ncols)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def size(self):
        """
        Return the number of positions, nrows * ncols.

        Returns
        -------
        int
            Matrix size.
        """

        return int(self.lil.nrows) * int(self.lil.ncols)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def order(self):
        """
        Return the largest truncation order of the stored elements.

        Returns
        -------
        int
            Order (0 when empty).
        """

        return lilo_trc_order(&self.lil)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def rows(self):
        """
        Return the sorted columns of the stored elements of every row, like pyoti.sparse.

        Returns
        -------
        numpy.ndarray
            Object array of nrows lists of column indices.
        """

        return self._lists(False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def data(self):
        """
        Return copies of the stored elements of every row, like pyoti.sparse.

        Returns
        -------
        numpy.ndarray
            Object array of nrows lists of otinum, in column order.
        """

        return self._lists(True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def _lists(self, values):
        """
        Build the per-row lists of columns or values.

        Parameters
        ----------
        values : bool
            True for copies of the values, False for the columns.

        Returns
        -------
        numpy.ndarray
            Object array of nrows lists.
        """

        cdef np.ndarray perm = np.empty(int(self.lil.nnz), dtype=np.uint64)
        cdef np.ndarray indptr = np.empty(int(self.lil.nrows) + 1, dtype=np.int64)
        cdef uint64_t *p_perm = <uint64_t *>np.PyArray_DATA(perm)
        cdef int64_t *p_ptr = <int64_t *>np.PyArray_DATA(indptr)
        cdef np.ndarray result = np.empty(self.lil.nrows, dtype=object)
        cdef uint64_t r, e
        cdef int64_t t
        cdef list row

        _csr_status("sorted", lilo_sorted(&self.lil, p_perm, p_ptr))

        for r in range(self.lil.nrows):

            row = []

            for t in range(p_ptr[r], p_ptr[r + 1]):

                e = p_perm[t]

                if values:

                    row.append(_csr_copy_value(&self.lil.p_val[e]))

                else:

                    row.append(self.lil.p_col[e])

                # end if

            # end for

            result[r] = row

        # end for

        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def real(self):
        """
        Return the real parts as a SciPy LIL matrix, like pyoti.sparse.

        Returns
        -------
        scipy.sparse.lil_matrix
            Real part (a copy).
        """

        cdef uint64_t n = self.lil.nnz, e
        cdef np.ndarray[np.float64_t, ndim=1] data = np.empty(n, dtype=np.float64)
        cdef np.ndarray[np.int64_t, ndim=1] rows = np.empty(n, dtype=np.int64)
        cdef np.ndarray[np.int64_t, ndim=1] cols = np.empty(n, dtype=np.int64)

        for e in range(n):

            data[e] = self.lil.p_val[e].re
            rows[e] = self.lil.p_row[e]
            cols[e] = self.lil.p_col[e]

        # end for

        return _sci_spr.csr_matrix((data, (rows, cols)), shape=self.shape).tolil()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __repr__(self):
        """
        Return the representation of the builder.

        Returns
        -------
        str
            Shape and number of stored elements.
        """

        out = "<{0} sparse matrix of OTI numbers with \n".format(self.shape)
        out += "         {0} stored elements in LInked List format>".format(self.nnz)
        return out

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __str__(self):
        """
        List every stored element as ``(row, col) value``, by row and column.

        Returns
        -------
        str
            One line per stored element.
        """

        cdef np.ndarray rows = self._lists(False)
        cdef np.ndarray data = self._lists(True)
        cdef uint64_t r, t

        out = ""

        for r in range(self.lil.nrows):

            for t in range(len(rows[r])):

                out += "({0:3d},{1:3d}) {2}\n".format(r, rows[r][t], data[r][t])

            # end for

        # end for

        return out

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __getitem__(self, key):
        """
        Read a copy of an element.

        Parameters
        ----------
        key : tuple of int
            (row, column).

        Returns
        -------
        otinum
            Copy of the stored element, or a real zero (order 0) when it is not stored.
        """

        cdef Py_ssize_t i, j
        cdef const otinum_t *p_val

        if type(key) is not tuple or len(<tuple>key) != 2:

            raise IndexError("Only integer pair ( , ) is suported for element indexing.")

        # end if

        i = (<tuple>key)[0]
        j = (<tuple>key)[1]

        if i < 0 or j < 0 or <uint64_t>i >= self.lil.nrows or <uint64_t>j >= self.lil.ncols:

            raise IndexError("Index out of bounds {0} for shape {1}.".format(key, self.shape))

        # end if

        p_val = lilo_get(&self.lil, <uint64_t>i, <uint64_t>j)

        if p_val == NULL:

            return otinum.wrap(oti_create_r(0.0, 0))

        # end if

        return _csr_copy_value(p_val)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __setitem__(self, key, value):
        """
        Store a copy of a value at a position, overwriting any stored element.

        Parameters
        ----------
        key : tuple of int
            (row, column).
        value : float or otinum or sotinum
            Value; a real is stored as an order-0 number.
        """

        cdef Py_ssize_t i, j
        cdef otinum num

        if type(key) is not tuple or len(<tuple>key) != 2:

            raise IndexError("Only ( , ) integer tuples allowed for setting an element in the matrix.")

        # end if

        i = (<tuple>key)[0]
        j = (<tuple>key)[1]

        if i < 0 or j < 0 or <uint64_t>i >= self.lil.nrows or <uint64_t>j >= self.lil.ncols:

            raise IndexError("Index out of bounds {0} for shape {1}.".format(key, self.shape))

        # end if

        if type(value) is otinum:

            _csr_status("setitem", lilo_set(&self.lil, <uint64_t>i, <uint64_t>j,
                                            &(<otinum>value).num))

        elif type(value) is float or type(value) is int or isinstance(value, Real):

            _csr_status("setitem", lilo_set_r(&self.lil, <uint64_t>i, <uint64_t>j, <coeff_t>value))

        elif isinstance(value, (otinum, sotinum)):

            num = otinum(value)
            _csr_status("setitem", lilo_set(&self.lil, <uint64_t>i, <uint64_t>j, &num.num))

        else:

            raise TypeError("lil_matrix: unsupported element type {}".format(type(value).__name__))

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def add(self, i, j, value):
        """
        Add a value to an element in place (a missing element starts at zero).

        Same result as ``K[i, j] = K[i, j] + value`` without the temporaries (semi-sparse and dense
        extra).

        Parameters
        ----------
        i : int
            Row.
        j : int
            Column.
        value : float or otinum or sotinum
            Value to add.
        """

        cdef Py_ssize_t ii = i, jj = j
        cdef otinum num

        if ii < 0 or jj < 0 or <uint64_t>ii >= self.lil.nrows or <uint64_t>jj >= self.lil.ncols:

            raise IndexError("Index out of bounds {0} for shape {1}.".format((i, j), self.shape))

        # end if

        num = value if type(value) is otinum else otinum(value)
        _csr_status("add", lilo_add(&self.lil, <uint64_t>ii, <uint64_t>jj, &num.num, _dhl))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def add_block(self, rows, cols, block):
        """
        Add a dense block in place: ``K[rows[a], cols[b]] += block[a, b]`` for every a, b.

        The scatter of a finite-element matrix in one call, with the same result as the loops of
        ``K[i, j] = K[i, j] + block[a, b]``. Repeated rows or columns add up. Nothing changes when an
        index is out of range or the block has the wrong shape.

        Parameters
        ----------
        rows : array_like of int
            Global row of each block row.
        cols : array_like of int
            Global column of each block column.
        block : omat or arro or matso or array_like
            Values, len(rows) x len(cols).

        Examples
        --------
        >>> import pyoti.dense as oti
        >>> K = oti.lil_matrix((4, 4))
        >>> K.add_block([0, 2], [0, 2], oti.array([[1.0, 2.0], [3.0, 4.0]]) * oti.e(1, order=1))
        >>> K.add_block([0], [0], oti.array([[10.0]]))
        >>> K[0, 0].real, K[2, 0].get_deriv([1])
        (10.0, 3.0)
        """

        cdef np.ndarray r = np.ascontiguousarray(rows, dtype=np.int64).reshape(-1)
        cdef np.ndarray c = np.ascontiguousarray(cols, dtype=np.int64).reshape(-1)
        cdef omat blk = _csr_operand(block, "lil_matrix.add_block")
        cdef int status

        if (r.size and r.min() < 0) or (c.size and c.min() < 0):

            raise IndexError("lil_matrix.add_block: negative index")

        # end if

        # Nonnegative int64 indices read as uint64 unchanged.
        status = lilo_add_block(&self.lil, <const uint64_t *>np.PyArray_DATA(r), r.size,
                                 <const uint64_t *>np.PyArray_DATA(c), c.size, &blk.arr, _dhl)

        if status == CSRO_ERR_INDEX:

            raise IndexError("lil_matrix.add_block: index out of bounds for shape {}".format(
                self.shape))

        elif status == CSRO_ERR_SIZE:

            raise ValueError("lil_matrix.add_block: block shape {} does not match ({}, {})".format(
                blk.shape, r.size, c.size))

        # end if

        _csr_status("lil_matrix.add_block", status)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def copy(self):
        """
        Deep copy of the builder.

        Returns
        -------
        lil_matrix
            Independent copy.
        """

        cdef lil_matrix result = lil_matrix(self.shape)

        _csr_status("copy", lilo_copy_to(&self.lil, &result.lil))
        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __copy__(self):
        """
        Support ``copy.copy``: a deep copy of every stored element.

        Returns
        -------
        lil_matrix
            Same as ``copy()``.
        """

        return self.copy()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __deepcopy__(self, memo):
        """
        Support ``copy.deepcopy``: a deep copy of every stored element.

        Parameters
        ----------
        memo : dict
            Memo of ``copy.deepcopy`` (unused: the builder holds no references to other objects).

        Returns
        -------
        lil_matrix
            Same as ``copy()``.
        """

        return self.copy()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def zeros_like(self):
        """
        Return a builder with the same stored positions holding real zeros.

        Returns
        -------
        lil_matrix
            Zeros at the stored positions.
        """

        cdef lil_matrix result = lil_matrix(self.shape)
        cdef uint64_t e

        for e in range(self.lil.nnz):

            _csr_status("zeros_like", lilo_set_r(&result.lil, self.lil.p_row[e], self.lil.p_col[e],
                                                 0.0))

        # end for

        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def _map(self, function):
        """
        Apply a scalar function to every stored element.

        Parameters
        ----------
        function : callable
            Maps an otinum to an otinum or a real.

        Returns
        -------
        lil_matrix
            Builder of the results, same positions.
        """

        cdef lil_matrix result = lil_matrix(self.shape)
        cdef uint64_t e

        for e in range(self.lil.nnz):

            result[self.lil.p_row[e], self.lil.p_col[e]] = function(
                _csr_copy_value(&self.lil.p_val[e]))

        # end for

        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_deriv(self, hum_dir):
        """
        Return the derivative along a direction of every stored element.

        Parameters
        ----------
        hum_dir : int or list or tuple or rawdir
            Direction.

        Returns
        -------
        lil_matrix
            Real values, same positions.
        """

        return self._map(lambda value: float(value.get_deriv(hum_dir)))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_im(self, hum_dir):
        """
        Return the coefficient of a direction of every stored element.

        Parameters
        ----------
        hum_dir : int or list or tuple or rawdir
            Direction.

        Returns
        -------
        lil_matrix
            Real values, same positions.
        """

        return self._map(lambda value: float(value.get_im(hum_dir)))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def extract_im(self, hum_dir):
        """
        Extract, in every stored element, the coefficients that contain a direction.

        Parameters
        ----------
        hum_dir : int or list or tuple or rawdir
            Direction.

        Returns
        -------
        lil_matrix
            Extracted values, same positions.
        """

        return self._map(lambda value: value.extract_im(hum_dir))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def extract_deriv(self, hum_dir):
        """
        Extract, in every stored element, the derivatives that contain a direction.

        Parameters
        ----------
        hum_dir : int or list or tuple or rawdir
            Direction.

        Returns
        -------
        lil_matrix
            Extracted values, same positions.
        """

        return self._map(lambda value: value.extract_deriv(hum_dir))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_order_im(self, order):
        """
        Keep one order of every stored element.

        Parameters
        ----------
        order : int
            Order to keep.

        Returns
        -------
        lil_matrix
            Order-``order`` parts, same positions.
        """

        return self._map(lambda value: value.get_order_im(order))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate(self, hum_dir):
        """
        Remove a direction (and its multiples) from every stored element.

        Parameters
        ----------
        hum_dir : int or list or tuple or rawdir
            Direction.

        Returns
        -------
        lil_matrix
            Truncated values, same positions.
        """

        return self._map(lambda value: value.truncate(hum_dir))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_active_bases(self):
        """
        List the active bases of the builder: [1, ..., largest nact of the stored elements].

        Returns
        -------
        list of int
            Basis labels.
        """

        cdef bases_t nact = 0
        cdef uint64_t e

        for e in range(self.lil.nnz):

            if self.lil.p_val[e].nact > nact:

                nact = self.lil.p_val[e].nact

            # end if

        # end for

        return list(range(1, nact + 1))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def tocsr(self, preserve_in=False):
        """
        Convert to CSR, like ``pyoti.sparse``: the builder is emptied unless ``preserve_in``.

        Parameters
        ----------
        preserve_in : bool
            Keep the stored elements (default False frees them, as pyoti.sparse does).

        Returns
        -------
        csr_matrix
            Matrix over the largest nact and order of the elements.
        """

        return csr_matrix(self, preserve_in=preserve_in)

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------
