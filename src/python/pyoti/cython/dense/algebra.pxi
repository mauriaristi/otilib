# Elementwise and matrix algebra functions: dot, matmul, sum, sub, mul, div, neg, abs, norm, transpose,
# and the derivative accessors that work on scalars and arrays alike (dense types).
#
# The names sum, abs (and pow, in math.pxi) shadow the Python builtins inside this extension module;
# module code that needs the builtin must call _builtins.sum / _builtins.abs.


# ********************************************************************************************************
def dot(lhs, rhs, out=None):
    """
    Multiply two dense matrices.

    Parameters
    ----------
    lhs : omat or arro
        Left factor.
    rhs : omat or arro
        Right factor.
    out : omat or arro, optional
        Holder for the product.

    Returns
    -------
    omat or arro
        Matrix product, or None when ``out`` is given.
    """

    if isinstance(lhs, _dnfe) or isinstance(rhs, _dnfe):

        return _fe_dot(lhs, rhs, out)

    # end if

    return _finish(lhs @ rhs, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def matmul(lhs, rhs, out=None):
    """
    Multiply two dense matrices.

    Parameters
    ----------
    lhs : omat or arro
        Left factor.
    rhs : omat or arro
        Right factor.
    out : omat or arro, optional
        Holder for the product.

    Returns
    -------
    omat or arro
        Matrix product, or None when ``out`` is given.
    """

    if isinstance(lhs, _dnfe) or isinstance(rhs, _dnfe):

        return _fe_dot(lhs, rhs, out)

    # end if

    return _finish(lhs @ rhs, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def sum(lhs, rhs, out=None):
    """
    Add two operands (scalars, arrays or reals); the elementwise addition of ``pyoti.sparse``.

    Parameters
    ----------
    lhs : object
        Left operand.
    rhs : object
        Right operand.
    out : otinum or omat or arro, optional
        Holder for the sum.

    Returns
    -------
    object
        Sum, or None when ``out`` is given.
    """

    if isinstance(lhs, _dnfe) or isinstance(rhs, _dnfe):

        return _fe_arith("add", lhs, rhs, out)

    # end if

    return _finish(lhs + rhs, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def sub(lhs, rhs, out=None):
    """
    Subtract two operands (scalars, arrays or reals).

    Parameters
    ----------
    lhs : object
        Left operand.
    rhs : object
        Right operand.
    out : otinum or omat or arro, optional
        Holder for the difference.

    Returns
    -------
    object
        Difference, or None when ``out`` is given.
    """

    if isinstance(lhs, _dnfe) or isinstance(rhs, _dnfe):

        return _fe_arith("sub", lhs, rhs, out)

    # end if

    return _finish(lhs - rhs, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def mul(lhs, rhs, out=None):
    """
    Multiply two operands elementwise (scalars, arrays or reals).

    Parameters
    ----------
    lhs : object
        Left operand.
    rhs : object
        Right operand.
    out : otinum or omat or arro, optional
        Holder for the product.

    Returns
    -------
    object
        Product, or None when ``out`` is given.
    """

    if isinstance(lhs, _dnfe) or isinstance(rhs, _dnfe):

        return _fe_arith("mul", lhs, rhs, out)

    # end if

    return _finish(lhs * rhs, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def div(lhs, rhs, out=None):
    """
    Divide two operands elementwise (scalars, arrays or reals).

    Parameters
    ----------
    lhs : object
        Numerator.
    rhs : object
        Denominator.
    out : otinum or omat or arro, optional
        Holder for the quotient.

    Returns
    -------
    object
        Quotient, or None when ``out`` is given.
    """

    if isinstance(lhs, _dnfe) or isinstance(rhs, _dnfe):

        return _fe_arith("div", lhs, rhs, out)

    # end if

    return _finish(lhs / rhs, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def neg(val, out=None):
    """
    Negate a scalar or array.

    Parameters
    ----------
    val : otinum or omat or arro
        Operand.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    otinum or omat or arro
        Negated operand, or None when ``out`` is given.
    """

    return _finish(-val, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def abs(val, out=None):
    """
    Take the absolute value of a scalar or array, negating what has a negative real part.

    Parameters
    ----------
    val : otinum or omat or arro
        Operand.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    otinum or omat or arro
        Absolute value, or None when ``out`` is given.
    """

    return _finish(_builtins.abs(val), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def norm(arr, p=2.0, out=None):
    """
    Compute the p-norm ``(sum(|a|**p))**(1/p)`` of an array as an OTI scalar.

    Parameters
    ----------
    arr : omat or arro
        Array.
    p : float
        Norm order.
    out : otinum, optional
        Holder for the norm.

    Returns
    -------
    otinum
        Norm, or None when ``out`` is given.

    Raises
    ------
    TypeError
        If ``arr`` is not a dense array.
    """

    cdef omat soa

    if isinstance(arr, arro):

        arr = arr.to_soa()

    # end if

    if not isinstance(arr, omat):

        raise TypeError("norm expects a dense array")

    # end if

    soa = arr.__abs__() ** p
    return _finish(_soa_sum_all(soa) ** (1.0 / p), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def transpose(arr, out=None):
    """
    Transpose an array.

    Parameters
    ----------
    arr : omat or arro
        Array.
    out : omat or arro, optional
        Holder for the transpose.

    Returns
    -------
    omat or arro
        Transposed copy, or None when ``out`` is given.
    """

    if isinstance(arr, _dnfe):

        return _fe_transpose(arr, out)

    # end if

    if not isinstance(arr, (omat, arro)):

        raise TypeError("Unsupported types at transpose operation.")

    # end if

    return _finish(arr.T, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def get_active_bases(obj_in):
    """
    List the active bases of a scalar or array: 1 .. nact.

    Parameters
    ----------
    obj_in : otinum or omat or arro
        Operand.

    Returns
    -------
    list of int
        Basis labels 1, ..., nact.
    """

    return obj_in.get_active_bases()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def truncate(humdir, val, out=None):
    """
    Zero a direction and every direction that contains it.

    Parameters
    ----------
    humdir : int or list or tuple
        Direction in any pyoti.sparse format, or a rawdir.
    val : otinum or omat or arro
        Operand.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    otinum or omat or arro
        Truncated copy, or None when ``out`` is given.
    """

    return _finish(val.truncate(humdir), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def get_im(humdir, val, out=None):
    """
    Read the coefficient along a direction as an OTI number of order 0 (an OTI array for arrays).

    Parameters
    ----------
    humdir : int or list or tuple
        Direction in any pyoti.sparse format, or a rawdir.
    val : otinum or omat or arro
        Operand.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    otinum or omat or arro
        Coefficient as the real part of the result, or None when ``out`` is given.
    """

    return _finish(_direction_holder(val, val.get_im(humdir)), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def get_deriv(humdir, val, out=None):
    """
    Read the derivative along a direction as an OTI number of order 0 (an OTI array for arrays).

    Parameters
    ----------
    humdir : int or list or tuple
        Direction in any pyoti.sparse format, or a rawdir.
    val : otinum or omat or arro
        Operand.
    out : otinum or omat or arro, optional
        Holder for the result.

    Returns
    -------
    otinum or omat or arro
        Derivative as the real part of the result, or None when ``out`` is given.
    """

    return _finish(_direction_holder(val, val.get_deriv(humdir)), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _direction_holder(object val, object values):
    """
    Wrap the real values read from a direction in an order-0 holder of the operand's kind.

    Parameters
    ----------
    val : otinum or omat or arro
        Operand the values were read from.
    values : float or numpy.ndarray
        Real coefficients or derivatives.

    Returns
    -------
    otinum or omat or arro
        Holder of the same kind as ``val`` with the values as real parts.

    Raises
    ------
    TypeError
        If ``val`` is not a dense scalar or array.
    """

    if isinstance(val, otinum):

        return otinum(values, order=0)

    # end if

    if isinstance(val, omat):

        return omat.from_real(values, order=0)

    # end if

    if isinstance(val, arro):

        return omat.from_real(values, order=0).to_aos()

    # end if

    raise TypeError("expected a dense scalar or array")

# end function
# --------------------------------------------------------------------------------------------------------
