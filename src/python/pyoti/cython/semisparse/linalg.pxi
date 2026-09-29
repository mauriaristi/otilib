# LU factorization, solve, inv and det.


# ********************************************************************************************************
cdef class _LU:
    """
    Opaque owned factorization of the real block of a SoA matrix.
    """

    # ****************************************************************************************************
    def __cinit__(self):
        """
        Initialize native factor storage before construction.
        """

        self.factor.A = oarrss_init()
        self.factor.p_ipiv = NULL

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __dealloc__(self):
        """
        Release the factorized matrix and pivot buffer.
        """

        oarrss_lu_free(&self.factor)

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def lu_factor(oarrss A, out=None):
    """
    Factor a square SoA matrix for repeated solves.

    Parameters
    ----------
    A : oarrss
        Square coefficient matrix.
    out : oarrss, optional
        Holder that receives a copy of the factored matrix (the real block holds the LAPACK LU factors).

    Returns
    -------
    _LU
        Owned opaque factorization.
    """

    cdef _LU factor = _LU()

    if A.arr.nrows != A.arr.ncols:

        raise ValueError("lu_factor: matrix must be square")

    # end if

    _status("lu_factor", oarrss_lu_factor(&A.arr, &factor.factor))

    if out is not None:

        _assign_out(out, oarrss.wrap(oarrss_copy(&factor.factor.A)))

    # end if

    return factor

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def lu_solve(_LU lu_and_piv, oarrss b, out=None):
    """
    Solve a system using a reusable SoA LU factorization.

    Parameters
    ----------
    lu_and_piv : _LU
        Factorization from lu_factor.
    b : oarrss
        Right-hand sides.
    out : oarrss, optional
        Holder for the solution.

    Returns
    -------
    oarrss
        Solution, or None when ``out`` is given.
    """

    cdef oarrss_t result = oarrss_init()
    cdef int status

    if lu_and_piv.factor.A.nrows != b.arr.nrows:

        raise ValueError("lu_solve: incompatible right-hand-side rows")

    # end if

    status = oarrss_lu_solve(&lu_and_piv.factor, &b.arr, &result, _dhl)

    if status != 0:

        oarrss_free(&result)
        _status("lu_solve", status)

    # end if

    return _finish(oarrss.wrap(result), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def solve(K_in, b_in, out=None, solver='SuperLU', solver_args=None):
    """
    Solve a semi-sparse matrix system.

    Same call as ``pyoti.sparse.solve``. A ``csr_matrix`` goes to the sparse block solver
    (``_csr_solve``, semisparse/csr/base.pxi).

    Parameters
    ----------
    K_in : oarrss or arrss or csr_matrix
        Square coefficient matrix.
    b_in : oarrss or arrss
        Right-hand-side columns.
    out : oarrss or arrss, optional
        Holder for the solution.
    solver : str
        Real sparse solver for a ``csr_matrix``: 'SuperLU', 'spilu', 'cholesky' or 'umfpack'.
    solver_args : dict, optional
        Keyword arguments of the sparse factorization (``csr_matrix`` only).

    Returns
    -------
    oarrss or arrss
        Solution, or None when ``out`` is given.
    """

    cdef oarrss_t result = oarrss_init()
    cdef arrss_t aos_result = arrss_init()
    cdef oarrss soa_matrix, soa_rhs
    cdef arrss aos_matrix, aos_rhs
    cdef int status

    if isinstance(K_in, csr_matrix):

        return _csr_solve(K_in, b_in, out, solver, solver_args)

    # end if

    if out is not None:

        return _finish(solve(K_in, b_in), out)

    # end if

    if isinstance(K_in, arrss) and isinstance(b_in, arrss):

        aos_matrix = K_in
        aos_rhs = b_in

        if aos_matrix.arr.nrows != aos_matrix.arr.ncols or (
            aos_matrix.arr.nrows != aos_rhs.arr.nrows
        ):

            raise ValueError("solve: matrix must be square and match the right-hand-side rows")

        # end if

        status = arrss_solve_to(&aos_matrix.arr, &aos_rhs.arr, &aos_result, _dhl)

        if status != 0:

            arrss_free(&aos_result)
            _status("solve", status)

        # end if

        return arrss.wrap(aos_result)

    # end if

    if not isinstance(K_in, oarrss) or not isinstance(b_in, oarrss):

        raise TypeError("solve expects two arrays of the same semi-sparse layout")

    # end if

    soa_matrix = K_in
    soa_rhs = b_in

    if soa_matrix.arr.nrows != soa_matrix.arr.ncols or soa_matrix.arr.nrows != soa_rhs.arr.nrows:

        raise ValueError("solve: matrix must be square and match the right-hand-side rows")

    # end if

    status = oarrss_solve_to(&soa_matrix.arr, &soa_rhs.arr, &result, _dhl)

    if status != 0:

        oarrss_free(&result)
        _status("solve", status)

    # end if

    return oarrss.wrap(result)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def inv(arr, out=None):
    """
    Invert a nonsingular semi-sparse square matrix.

    Parameters
    ----------
    arr : oarrss or arrss
        Square coefficient matrix.
    out : oarrss or arrss, optional
        Holder for the inverse.

    Returns
    -------
    oarrss or arrss
        Inverse matrix, or None when ``out`` is given.
    """

    if isinstance(arr, _ssfe):

        return _fe_inv(arr, out)

    # end if

    cdef oarrss_t result = oarrss_init()
    cdef arrss_t aos_result = arrss_init()
    cdef oarrss soa_matrix
    cdef arrss aos_matrix
    cdef int status

    if isinstance(arr, arrss):

        aos_matrix = arr

        if aos_matrix.arr.nrows != aos_matrix.arr.ncols:

            raise ValueError("inv: matrix must be square")

        # end if

        status = arrss_inv_to(&aos_matrix.arr, &aos_result, _dhl)

        if status != 0:

            arrss_free(&aos_result)
            _status("inv", status)

        # end if

        return _finish(arrss.wrap(aos_result), out)

    # end if

    if not isinstance(arr, oarrss):

        raise TypeError("inv expects a semi-sparse array")

    # end if

    soa_matrix = arr

    if soa_matrix.arr.nrows != soa_matrix.arr.ncols:

        raise ValueError("inv: matrix must be square")

    # end if

    status = oarrss_inv_to(&soa_matrix.arr, &result, _dhl)

    if status != 0:

        oarrss_free(&result)
        _status("inv", status)

    # end if

    return _finish(oarrss.wrap(result), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def det(arr, out=None):
    """
    Compute the semi-sparse determinant of a square matrix.

    Parameters
    ----------
    arr : oarrss or arrss
        Square coefficient matrix.
    out : ssotinum, optional
        Holder for the determinant.

    Returns
    -------
    ssotinum
        Determinant, or None when ``out`` is given.
    """

    if isinstance(arr, _ssfe):

        return _fe_det(arr, out)

    # end if

    cdef ssotinum_t result = ssoti_init()
    cdef oarrss soa_matrix
    cdef arrss aos_matrix
    cdef int status

    if isinstance(arr, arrss):

        aos_matrix = arr

        if aos_matrix.arr.nrows != aos_matrix.arr.ncols:

            raise ValueError("det: matrix must be square")

        # end if

        status = arrss_det_to(&aos_matrix.arr, &result, _dhl)

    elif isinstance(arr, oarrss):

        soa_matrix = arr

        if soa_matrix.arr.nrows != soa_matrix.arr.ncols:

            raise ValueError("det: matrix must be square")

        # end if

        status = oarrss_det_to(&soa_matrix.arr, &result, _dhl)

    else:

        raise TypeError("det expects a semi-sparse array")

    # end if

    if status != 0:

        ssoti_free(&result)
        _status("det", status)

    # end if

    return _finish(ssotinum.wrap(result), out)

# end function
# --------------------------------------------------------------------------------------------------------
