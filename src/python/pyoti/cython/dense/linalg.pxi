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

    if A.arr.nrows != A.arr.ncols:

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
        Solution, or None when ``out`` is given.

    Raises
    ------
    ValueError
        If the right-hand side has a different number of rows.
    """

    cdef oarr_t result = oarr_init()

    if lu_and_piv.factor.A.nrows != b.arr.nrows:

        raise ValueError("lu_solve: incompatible right-hand-side rows")

    # end if

    _soa_ok("lu_solve", oarr_lu_solve(&lu_and_piv.factor, &b.arr, &result, _dhl), &result)
    return _finish(omat.wrap(result), out)

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
        Solution, or None when ``out`` is given.

    Raises
    ------
    TypeError
        If the operands are not two arrays of the same dense layout.
    ValueError
        If the matrix is not square or does not match the right-hand side.
    numpy.linalg.LinAlgError
        If the real part of the matrix is singular.
    """

    cdef oarr_t result = oarr_init()
    cdef arro_t aos_result = arro_init()
    cdef omat soa_matrix, soa_rhs
    cdef arro aos_matrix, aos_rhs

    if isinstance(K_in, csr_matrix):

        return _csr_solve(K_in, b_in, out, solver, solver_args)

    # end if

    if out is not None:

        return _finish(solve(K_in, b_in), out)

    # end if

    if isinstance(K_in, arro) and isinstance(b_in, arro):

        aos_matrix = K_in
        aos_rhs = b_in

        if aos_matrix.arr.nrows != aos_matrix.arr.ncols or (
            aos_matrix.arr.nrows != aos_rhs.arr.nrows
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

    soa_matrix = K_in
    soa_rhs = b_in

    if soa_matrix.arr.nrows != soa_matrix.arr.ncols or soa_matrix.arr.nrows != soa_rhs.arr.nrows:

        raise ValueError("solve: matrix must be square and match the right-hand-side rows")

    # end if

    _soa_ok("solve", oarr_solve_to(&soa_matrix.arr, &soa_rhs.arr, &result, _dhl), &result)
    return omat.wrap(result)

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
        Inverse matrix, or None when ``out`` is given.

    Raises
    ------
    TypeError
        If ``arr`` is not a dense array.
    ValueError
        If the matrix is not square.
    numpy.linalg.LinAlgError
        If the real part is singular.
    """

    if isinstance(arr, _dnfe):

        return _fe_inv(arr, out)

    # end if

    cdef oarr_t result = oarr_init()
    cdef arro_t aos_result = arro_init()
    cdef omat soa_matrix
    cdef arro aos_matrix

    if isinstance(arr, arro):

        aos_matrix = arr

        if aos_matrix.arr.nrows != aos_matrix.arr.ncols:

            raise ValueError("inv: matrix must be square")

        # end if

        _aos_ok("inv", arro_inv_to(&aos_matrix.arr, &aos_result, _dhl), &aos_result)
        return _finish(arro.wrap(aos_result), out)

    # end if

    if not isinstance(arr, omat):

        raise TypeError("inv expects a dense array")

    # end if

    soa_matrix = arr

    if soa_matrix.arr.nrows != soa_matrix.arr.ncols:

        raise ValueError("inv: matrix must be square")

    # end if

    _soa_ok("inv", oarr_inv_to(&soa_matrix.arr, &result, _dhl), &result)
    return _finish(omat.wrap(result), out)

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
        Determinant, or None when ``out`` is given.

    Raises
    ------
    TypeError
        If ``arr`` is not a dense array.
    ValueError
        If the matrix is not square.
    numpy.linalg.LinAlgError
        If the real part is singular.
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

        if aos_matrix.arr.nrows != aos_matrix.arr.ncols:

            raise ValueError("det: matrix must be square")

        # end if

        status = arro_det_to(&aos_matrix.arr, &result, _dhl)

    elif isinstance(arr, omat):

        soa_matrix = arr

        if soa_matrix.arr.nrows != soa_matrix.arr.ncols:

            raise ValueError("det: matrix must be square")

        # end if

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
