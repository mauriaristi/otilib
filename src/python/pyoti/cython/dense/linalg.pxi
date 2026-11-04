# LU factorization, solve, inv and det of dense matrices (SoA and AoS).
#
# Every native call goes through its status: a failed call frees the C result and raises through
# _status (info > 0, a singular real part, is numpy.linalg.LinAlgError). No global truncation order
# is read: none of these functions needs set_trunc_order.


# ********************************************************************************************************
def lu_factor(omat A, out=None):
    """
    Factor a square SoA matrix for repeated solves.

    Parameters
    ----------
    A : omat
        Square coefficient matrix.
    out : omat, optional
        Holder that receives a copy of the factored matrix (the real block holds the LAPACK LU
        factors).

    Returns
    -------
    _LU
        Owned opaque factorization.

    Raises
    ------
    ValueError
        If the matrix is not square.
    numpy.linalg.LinAlgError
        If the real part is singular.
    """

    cdef _LU factor = _LU()
    cdef oarr_t copy

    if A.ndim != 2 or oarr_nrows(&A.arr) != oarr_ncols(&A.arr):

        raise ValueError("lu_factor: matrix must be square")

    # end if

    _status("lu_factor", oarr_lu_factor(&A.arr, &factor.factor))

    if out is not None:

        copy = oarr_init()
        _soa_ok("lu_factor", oarr_copy_to(&factor.factor.A, &copy), &copy)
        _assign_out(out, omat.wrap(copy))

    # end if

    return factor

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def lu_solve(_LU lu_and_piv, omat b, out=None):
    """
    Solve a system using a reusable SoA LU factorization.

    Parameters
    ----------
    lu_and_piv : _LU
        Factorization from lu_factor.
    b : omat
        Right-hand sides.
    out : omat, optional
        Holder for the solution.

    Returns
    -------
    omat
        Solution (``out`` itself when it is given).

    Raises
    ------
    ValueError
        If the right-hand side has a different number of rows.
    """

    cdef omat result
    cdef omat rhs = b[:, None] if b.ndim == 1 else b
    cdef omat x

    if rhs.ndim != 2 or oarr_nrows(&lu_and_piv.factor.A) != oarr_shape(&rhs.arr, 0):

        raise ValueError("lu_solve: incompatible right-hand-side rows")

    # end if

    result = omat.__new__(omat)
    _soa_ok("lu_solve", oarr_lu_solve(&lu_and_piv.factor, &rhs.arr, &result.arr, _dhl), &result.arr)
    x = result

    if b.ndim == 1:

        _soa_relabel(x, b.shape)

    # end if

    return _finish(x, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def solve(K_in, b_in, out=None, solver='SuperLU', solver_args=None):
    """
    Solve a dense matrix system.

    Same call as ``pyoti.sparse.solve``. A ``csr_matrix`` goes to the sparse block solver
    (``_csr_solve``, dense/csr/base.pxi).

    Parameters
    ----------
    K_in : omat or arro or csr_matrix
        Square coefficient matrix.
    b_in : omat or arro
        Right-hand-side columns.
    out : omat or arro, optional
        Holder for the solution.
    solver : str
        Real sparse solver for a ``csr_matrix``: 'SuperLU', 'spilu', 'cholesky' or 'umfpack'.
    solver_args : dict, optional
        Keyword arguments of the sparse factorization (``csr_matrix`` only).

    Returns
    -------
    omat or arro
        Solution (``out`` itself when it is given).

    Raises
    ------
    TypeError
        If the operands are not two arrays of the same dense layout.
    ValueError
        If the matrix is not square or does not match the right-hand side.
    numpy.linalg.LinAlgError
        If the real part of the matrix is singular.
    """

    cdef arro_t aos_result
    cdef arro aos_matrix, aos_rhs

    # The common case first: two SoA arrays, no holder (one C-level call; shapes read in C).
    if out is None and isinstance(K_in, omat) and isinstance(b_in, omat):

        return _soa_solve(K_in, b_in)

    # end if

    if isinstance(K_in, csr_matrix):

        return _csr_solve(K_in, b_in, out, solver, solver_args)

    # end if

    if out is not None:

        return _finish(solve(K_in, b_in), out)

    # end if

    if isinstance(K_in, arro) and isinstance(b_in, arro):

        aos_matrix = K_in
        aos_rhs = b_in
        aos_result = arro_init()

        if arro_nrows(&aos_matrix.arr) != arro_ncols(&aos_matrix.arr) or (
            arro_nrows(&aos_matrix.arr) != arro_nrows(&aos_rhs.arr)
        ):

            raise ValueError("solve: matrix must be square and match the right-hand-side rows")

        # end if

        _aos_ok("solve", arro_solve_to(&aos_matrix.arr, &aos_rhs.arr, &aos_result, _dhl),
                &aos_result)
        return arro.wrap(aos_result)

    # end if

    if not isinstance(K_in, omat) or not isinstance(b_in, omat):

        raise TypeError("solve expects two arrays of the same dense layout")

    # end if

    # NumPy 2's linalg.solve rule: 1-D b is one vector; batch axes broadcast (contracts 11.3).
    return _soa_solve(K_in, b_in)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _square_check(str operation, int32_t ndim, int64_t nrows, int64_t ncols) except -1:
    """
    The shape checks of inv / det, with NumPy's exception (numpy.linalg.LinAlgError, a ValueError).

    Parameters
    ----------
    operation : str
        Name of the operation (not in the message: NumPy's texts carry none).
    ndim : int
        Number of dimensions of the array.
    nrows, ncols : int
        Extents of the matrix.

    Raises
    ------
    numpy.linalg.LinAlgError
        An array of fewer than two dimensions (NumPy's text, W4 fix round 2) or a non-square matrix.
    """

    # NumPy's texts, the same in every algebra (agreed with py-ss and py, W4 fix round 2).
    if ndim < 2:

        raise np.linalg.LinAlgError("{}-dimensional array given. Array must be at least "
                                    "two-dimensional".format(ndim))

    # end if

    if nrows != ncols:

        raise np.linalg.LinAlgError("Last 2 dimensions of the array must be square")

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def inv(arr, out=None):
    """
    Invert a nonsingular dense square matrix.

    Parameters
    ----------
    arr : omat or arro
        Square coefficient matrix.
    out : omat or arro, optional
        Holder for the inverse.

    Returns
    -------
    omat or arro
        Inverse matrix (``out`` itself when it is given).

    Raises
    ------
    TypeError
        If ``arr`` is not a dense array.
    numpy.linalg.LinAlgError
        If ``arr`` has fewer than two dimensions, the matrix is not square (both a ValueError, as
        in NumPy) or the real part is singular.
    """

    if isinstance(arr, _dnfe):

        return _fe_inv(arr, out)

    # end if

    cdef omat result
    cdef arro_t aos_result
    cdef omat soa_matrix
    cdef arro aos_matrix

    if isinstance(arr, arro):

        aos_matrix = arr
        aos_result = arro_init()

        _square_check("inv", arro_ndim(&aos_matrix.arr), arro_nrows(&aos_matrix.arr),
                      arro_ncols(&aos_matrix.arr))

        _aos_ok("inv", arro_inv_to(&aos_matrix.arr, &aos_result, _dhl), &aos_result)
        return _finish(arro.wrap(aos_result), out)

    # end if

    if not isinstance(arr, omat):

        raise TypeError("inv expects a dense array")

    # end if

    soa_matrix = arr

    _square_check("inv", oarr_ndim(&soa_matrix.arr), oarr_nrows(&soa_matrix.arr),
                  oarr_ncols(&soa_matrix.arr))

    result = omat.__new__(omat)
    _soa_ok("inv", oarr_inv_to(&soa_matrix.arr, &result.arr, _dhl), &result.arr)
    return _finish(result, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def det(arr, out=None):
    """
    Compute the dense determinant of a square matrix.

    Parameters
    ----------
    arr : omat or arro
        Square coefficient matrix.
    out : otinum, optional
        Holder for the determinant.

    Returns
    -------
    otinum
        Determinant (``out`` itself when it is given).

    Raises
    ------
    TypeError
        If ``arr`` is not a dense array.
    numpy.linalg.LinAlgError
        If ``arr`` has fewer than two dimensions, the matrix is not square (both a ValueError, as
        in NumPy) or the real part is singular.
    """

    if isinstance(arr, _dnfe):

        return _fe_det(arr, out)

    # end if

    cdef otinum_t result = oti_init()
    cdef omat soa_matrix
    cdef arro aos_matrix
    cdef int status

    if isinstance(arr, arro):

        aos_matrix = arr

        _square_check("det", arro_ndim(&aos_matrix.arr), arro_nrows(&aos_matrix.arr),
                      arro_ncols(&aos_matrix.arr))

        status = arro_det_to(&aos_matrix.arr, &result, _dhl)

    elif isinstance(arr, omat):

        soa_matrix = arr

        _square_check("det", oarr_ndim(&soa_matrix.arr), oarr_nrows(&soa_matrix.arr),
                      oarr_ncols(&soa_matrix.arr))

        status = oarr_det_to(&soa_matrix.arr, &result, _dhl)

    else:

        raise TypeError("det expects a dense array")

    # end if

    if status != DN_OK:

        oti_free(&result)
        _status("det", status)

    # end if

    return _finish(otinum.wrap(result), out)

# end function
# --------------------------------------------------------------------------------------------------------
